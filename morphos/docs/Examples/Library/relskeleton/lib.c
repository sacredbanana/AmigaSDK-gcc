#include "libdata.h"
#include "skeletonrel.library.h"

#define	DEBUG_INIT(x)    x;
#define	DEBUG_OPEN(x)    x;
#define	DEBUG_CLOSE(x)   x;
#define	DEBUG_EXPUNGE(x) x;
#define	DEBUG_NULL(x)    x;

extern ULONG LibFuncTable[];
struct Library*	LIB_Init(struct LibBase  *MyLibBase,
                         BPTR            SegList,
                         struct ExecBase *SBase);
struct LibInitStruct
{
	ULONG LibSize;
	void  *FuncTable;
	void  *DataTable;
	void  (*InitFunc)(void);
};

struct LibInitStruct LibInitStruct =
{
	sizeof(struct LibBase),
	LibFuncTable,
	NULL,
	(void (*)(void)) &LIB_Init
};


struct Resident LibResident=
{
	RTC_MATCHWORD,
	&LibResident,
	&LibResident + 1,
	RTF_PPC | RTF_EXTENDED | RTF_AUTOINIT,
	VERSION,
	NT_LIBRARY,
	0,
	"skeletonrel.library",
	VSTRING,
	&LibInitStruct,
	/* New Fields */
	REVISION,
	NULL /* No More Tags for now*/
};

/*
 * To tell the loader that this is a new abox elf and not
 * one for the ppc.library.
 * ** IMPORTANT **
 */
ULONG __abox__ = 1;

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

/* The lib execute init protection which simply returns
 */

LONG NoExecute(void)
{
	return -1;
}

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

/*** We must not access any globals here, since r13 hasn't been set up yet! ***/
#define	SysBase MyLibBase->SBase

#define R13_OFFSET	0x8000	/* Space for negative offset smalldata */

extern const char __r13_init;
extern int __datadata_relocs(void);

extern const ULONG __sdata_size, __sbss_size;
static __inline ULONG __dbsize(void)
{
	static const ULONG size[] = { (ULONG)&__sdata_size, (ULONG)&__sbss_size };
	return size[0] + size[1];
}

/* This function must preserve all registers except r13 */
asm("\n"
"	.section  \".text\"\n"
"	.align 2\n"
"	.type  __restore_r13, @function\n"
"	.globl __restore_r13	# Remove this line if you want the function to be local (see libdata.c)\n"
"__restore_r13:\n"
"	lwz 13, 56(2)	# MyEmulHandle->An[6] (REG_A6)\n"
"	lwz 13, 36(13)	# r13 = MyLibBase->DataSeg\n"
"	blr\n"
"__end__restore_r13:\n"
"	.size	__restore_r13, __end__restore_r13 - __restore_r13\n"
"\n");

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

/*
 * Resident is a RTF_PPC one...that means it's called
 * natively with normal PPC SysV4 ABI argument order.
 */
struct Library* LIB_Init(struct LibBase  *MyLibBase,
                         BPTR            SegList,
                         struct ExecBase *SBase)
{
	const char *r13 = &__r13_init;

	DEBUG_INIT(kprintf("LibInit: LibBase 0x%p SegList 0x%lx SBase 0x%p\n",
	                   MyLibBase,
	                   SegList,
	                   SBase));

	MyLibBase->SegList  = SegList;
	MyLibBase->SBase    = SBase;

	MyLibBase->DataSeg  = (char *)r13 - R13_OFFSET;
 	MyLibBase->DataSize = __dbsize();
	MyLibBase->Parent   = NULL;

	return &MyLibBase->Lib;
}

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

BPTR LibExpunge(struct LibBase *MyLibBase)
{
	BPTR MySegment;

	DEBUG_EXPUNGE(kprintf("LIB_Expunge: LibBase 0x%p <%s> OpenCount %ld Parent %p\n",
	                      MyLibBase,
	                      MyLibBase->Lib.lib_Node.ln_Name,
	                      MyLibBase->Lib.lib_OpenCnt,
	                      MyLibBase->Parent));

	/* Is it a child? */
	if (MyLibBase->Parent)
	{
		struct LibBase *MyLibChild = MyLibBase;

		/* Restore parent */
		MyLibBase = MyLibBase->Parent;

		/* Uninit global data */
		UnInitData(MyLibChild);

		/* Free child */
		FreeVec((APTR)((ULONG)(MyLibChild) - (ULONG)(MyLibChild->Lib.lib_NegSize)));
	}

	/* We don't need a forbid() because Expunge and Close
	 * are called with a pending forbid.
	 * But let's do it for safety if somebody does it by hand.
	 */
	Forbid();

	if (MyLibBase->Lib.lib_OpenCnt)
	{
		DEBUG_EXPUNGE(kprintf("LIB_Expunge: set LIBF_DELEXP\n"));

		MyLibBase->Lib.lib_Flags |= LIBF_DELEXP;

		Permit();

   		return 0;
	}

	DEBUG_EXPUNGE(kprintf("LIB_Expunge: remove the library\n"));
	Remove(&MyLibBase->Lib.lib_Node);

	Permit();

	MySegment =	  MyLibBase->SegList;

	DEBUG_EXPUNGE(kprintf("LIB_Expunge: free the library\n"));
	FreeMem(((UBYTE *)MyLibBase) - MyLibBase->Lib.lib_NegSize,
	        MyLibBase->Lib.lib_NegSize + MyLibBase->Lib.lib_PosSize);

	DEBUG_EXPUNGE(kprintf("LIB_Expunge: return Segment 0x%lx to ramlib\n",
	                      MySegment));
	return MySegment;
}

BPTR LIB_Expunge(void)
{
	struct LibBase *MyLibBase = (struct LibBase *)REG_A6;

	DEBUG_EXPUNGE(kprintf("LIB_Expunge:\n"));
	
	return LibExpunge(MyLibBase);
}

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

struct Library *LIB_Open(void)
{
	struct LibBase *MyLibBase           = (struct LibBase *)REG_A6;
	ULONG          MyBaseSize           = MyLibBase->Lib.lib_NegSize + MyLibBase->Lib.lib_PosSize;
	struct LibBase *NewLib, *MyLibChild = NULL;

	DEBUG_OPEN(kprintf("LIB_Open: 0x%p <%s> OpenCount %ld Parent %p DataSeg %p DataSize %lu\n",
	                   MyLibBase,
	                   MyLibBase->Lib.lib_Node.ln_Name,
	                   MyLibBase->Lib.lib_OpenCnt,
	                   MyLibBase->Parent,
	                   MyLibBase->DataSeg,
	                   MyLibBase->DataSize));

	/* Trying to use a child's LIB_Open? */
	if (MyLibBase->Parent)
	{
		/* Die, you nasty hacker! ;) */
		return NULL;
	}

	Forbid();

	/* Make sure we don't get expunged when trying to allocate child */
	MyLibBase->Lib.lib_OpenCnt++;

	if ((NewLib = AllocVec(MyBaseSize + MyLibBase->DataSize + 15, MEMF_PUBLIC)))
	{
		MyLibBase->Lib.lib_Flags &= ~LIBF_DELEXP;

		/* Copy master library base */
		CopyMem((APTR)((ULONG)MyLibBase - (ULONG)MyLibBase->Lib.lib_NegSize), NewLib, MyBaseSize);

		/* Set child library base */
		MyLibChild = (APTR)((ULONG)NewLib + (ULONG)MyLibBase->Lib.lib_NegSize);

		if (MyLibBase->DataSize)
		{
			char *origmem = MyLibBase->DataSeg;
			long *relocs  = (long *) __datadata_relocs;
			int mem       = ((int)NewLib + MyBaseSize + 15) & (unsigned int) ~15;

			/* Copy data segment */
			CopyMem(origmem, (char *)mem, MyLibBase->DataSize);

			/* Relocate */
			if (relocs[0] > 0)
			{
				int i, num_relocs = relocs[0];

				for (i=0, relocs++; i < num_relocs; ++i, ++relocs)
				{
					*(long *)(mem + *relocs) -= (int)origmem - mem;
				}
			}

			/* Save child's data segment base */
			MyLibChild->DataSeg = (char *)mem + R13_OFFSET;

			/* Init global data */
			if (!InitData(MyLibChild))
			{
				MyLibBase->Lib.lib_OpenCnt--;
				FreeVec(NewLib);
				Permit();

				return NULL;
			}
		}

		/* Flush JIT "cache" for the area */
		CacheClearE(NewLib, MyBaseSize + MyLibBase->DataSize + 15, CACRF_ClearI);

		/* Set child's parent library base */
		MyLibChild->Parent = MyLibBase;

		/* Reset the child's counter */
		MyLibChild->Lib.lib_OpenCnt = 1;
	}
	else
	{
		MyLibBase->Lib.lib_OpenCnt--;
	}

	Permit();

	return (struct Library *)MyLibChild;
}

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

BPTR LIB_Close(void)
{
	struct LibBase *MyLibBase = (struct LibBase *)REG_A6;
	#undef SysBase
	struct ExecBase *SysBase = MyLibBase->SBase;
	BPTR ret = 0;

	DEBUG_CLOSE(kprintf("LIB_Close: 0x%p <%s> OpenCount %ld Parent %p\n",
	                    MyLibBase,
	                    MyLibBase->Lib.lib_Node.ln_Name,
	                    MyLibBase->Lib.lib_OpenCnt,
	                    MyLibBase->Parent));

	/* Is it a child? */
	if (MyLibBase->Parent)
	{
		struct LibBase *MyLibChild = MyLibBase;

		/* Restore parent */
		MyLibBase = MyLibBase->Parent;

		/* Free child */
		FreeVec((APTR)((ULONG)(MyLibChild) - (ULONG)(MyLibChild->Lib.lib_NegSize)));
	}

	Forbid();

	if ((--MyLibBase->Lib.lib_OpenCnt) > 0)
	{
		DEBUG_CLOSE(kprintf("LIB_Close: done\n"));
	}
	else
	{
		if (MyLibBase->Lib.lib_Flags & LIBF_DELEXP)
		{
			DEBUG_CLOSE(kprintf("LIB_Close: LIBF_DELEXP set\n"));

			ret = LibExpunge(MyLibBase);
		}
	}

	Permit();

	return ret;
}

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

ULONG LIB_Reserved(void)
{
	DEBUG_NULL(kprintf("LIB_Reserved:\n"));

	return 0;
}

