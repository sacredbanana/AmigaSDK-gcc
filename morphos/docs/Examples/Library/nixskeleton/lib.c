#define AROS_ALMOST_COMPATIBLE	/* For ForeachNode macro */

#include "libdata.h"
#include "skeletonnix.library.h"

#include <stddef.h>

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
	"skeletonnix.library",
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
const ULONG __abox__ = 1;

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
extern ULONG __sdata_size, __sbss_size;

static __inline ULONG __dbsize(void)
{
	static const ULONG size[] = { (ULONG)&__sdata_size, (ULONG)&__sbss_size };
	return size[0] + size[1];
}

/* This function must preserve all registers except r13 */
asm(
"	.section  \".text\"\n"
"	.align 2\n"
"	.type  __restore_r13, @function\n"
"	.globl __restore_r13\n" // Remove this line if you want the function to be local (see libdata.c)
"__restore_r13:\n"
"	lwz 13, 36(12)\n"       // r13 = MyLibBase->DataSeg (our functions are sysv,r12base)
"	blr\n"
"__end__restore_r13:\n"
"	.size	__restore_r13, __end__restore_r13 - __restore_r13\n"
);

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

	NEWLIST(&MyLibBase->TaskContext.TaskList);

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

		Forbid();
		/* Expunge now? */
		if (MyLibChild->Lib.lib_OpenCnt)
		{
			/* Nope, do it later. */
			MyLibChild->Lib.lib_Flags |= LIBF_DELEXP;
			Permit();
			return 0;
		}

		REMOVE(&MyLibChild->TaskContext.TaskNode.Node);
		Permit();

		/* Uninit global data */
		UnInitData(MyLibChild);

		/* Free child */
		FreeVec((APTR)((IPTR)(MyLibChild) - (IPTR)(MyLibChild->Lib.lib_NegSize)));

		return 0;
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
	REMOVE(&MyLibBase->Lib.lib_Node);

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
	struct LibBase  *MyLibBase           = (struct LibBase *)REG_A6;
	ULONG            MyBaseSize          = MyLibBase->Lib.lib_NegSize + MyLibBase->Lib.lib_PosSize;
	struct LibBase  *NewLib, *MyLibChild = NULL;
	struct Task     *MyTask              = FindTask(NULL);
	struct TaskNode *MyChildNode;

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

	/* Has this task already opened a child? */
	ForeachNode(&MyLibBase->TaskContext.TaskList, MyChildNode)
	{
		if (MyChildNode->Task == MyTask)
		{
			/* Yep, return it */
			MyLibChild = (APTR)(((IPTR)MyChildNode) - offsetof(struct LibBase, TaskContext.TaskNode.Node));

			Forbid();
			MyLibChild->Lib.lib_Flags &= ~LIBF_DELEXP;
			MyLibChild->Lib.lib_OpenCnt++;
			Permit();

			return(&MyLibChild->Lib);
		}
	}

	Forbid();

	/* Make sure we don't get expunged when trying to allocate child */
	MyLibBase->Lib.lib_OpenCnt++;

	if ((NewLib = AllocVec(MyBaseSize + MyLibBase->DataSize + 15, MEMF_PUBLIC)))
	{
		MyLibBase->Lib.lib_Flags &= ~LIBF_DELEXP;

		/* Copy master library base */
		CopyMem((APTR)((IPTR)MyLibBase - (IPTR)MyLibBase->Lib.lib_NegSize), NewLib, MyBaseSize);

		/* Set child library base */
		MyLibChild = (APTR)((IPTR)NewLib + (IPTR)MyLibBase->Lib.lib_NegSize);

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
				/* Uninit any global data that may remain */
				UnInitData(MyLibChild);

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

		/* Register which task opened this child */
		MyLibChild->TaskContext.TaskNode.Task = MyTask;
		ADDTAIL(&MyLibBase->TaskContext.TaskList, &MyLibChild->TaskContext.TaskNode.Node);
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

		Forbid();

		/* Last close? */
		if (! ((--MyLibChild->Lib.lib_OpenCnt) > 0) )
		{
			/* Yep, expunge child! */
			ret = LibExpunge(MyLibChild);

			Permit();
			/* Fall through to parent */
		}
		else
		{
			Permit();
			return NULL;
		}
	}

	Forbid();

	if (! ((--MyLibBase->Lib.lib_OpenCnt) > 0) )
	{
		if (MyLibBase->Lib.lib_Flags & LIBF_DELEXP)
		{
			DEBUG_CLOSE(kprintf("LIB_Close: LIBF_DELEXP set\n"));

			ret = LibExpunge(MyLibBase);
		}
	}

	Permit();

	DEBUG_CLOSE(kprintf("LIB_Close: done\n"));

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
