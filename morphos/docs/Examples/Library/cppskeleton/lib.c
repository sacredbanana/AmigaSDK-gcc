#include "libdata.h"
#include "skeletoncpp.library.h"

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

struct LibInitStruct LibInitStruct=
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
	"skeletoncpp.library",
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


/*** De/constructor handling ***/

extern const void (*__ctrslist[])(void);
extern const void (*__dtrslist[])(void);

struct FuncSeg
{
	ULONG size;
	struct FuncSeg *next;
};

static void CallFuncArray(const void (*FuncArray[])(void))
{
	struct FuncSeg *seg;
	int i, num;

	seg = (struct FuncSeg *)(((IPTR)FuncArray) - sizeof(struct FuncSeg));
	num = (seg->size - sizeof(struct FuncSeg)) / sizeof(APTR);

	for (i=0; (i < num) && FuncArray[i]; i++)
	{
		if (FuncArray[i] != ((const void (*)(void))-1))
			(*FuncArray[i])();
	}
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

/*
 * Resident is a RTF_PPC one...that means it's called
 * natively with normal PPC SysV4 ABI argument order.
 */
struct Library* LIB_Init(struct LibBase  *MyLibBase,
                         BPTR            SegList,
                         struct ExecBase *sysBase)
{
	DEBUG_INIT(kprintf("LibInit: LibBase 0x%p SegList 0x%lx SysBase 0x%p\n",
	                   MyLibBase,
	                   SegList,
	                   sysBase));

	MyLibBase->SegList = SegList;
	MyLibBase->sysBase = sysBase;

	return(&MyLibBase->Lib);
#if 0
	/* If LIB_Init fails (return NULL), the library base must be released! */

	FreeMem(((UBYTE *)MyLibBase) - MyLibBase->Lib.lib_NegSize,
	        MyLibBase->Lib.lib_NegSize + MyLibBase->Lib.lib_PosSize);

	return NULL;
#endif
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

	DEBUG_EXPUNGE(kprintf("LIB_Expunge: LibBase 0x%p <%s> OpenCount %ld\n",
	                      MyLibBase,
	                      MyLibBase->Lib.lib_Node.ln_Name,
	                      MyLibBase->Lib.lib_OpenCnt));

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

	MySegment = MyLibBase->SegList;

	DEBUG_EXPUNGE(kprintf("LIB_Expunge: free the library\n"));
	FreeMem(((UBYTE *)MyLibBase) - MyLibBase->Lib.lib_NegSize,
	        MyLibBase->Lib.lib_NegSize + MyLibBase->Lib.lib_PosSize);

	DEBUG_EXPUNGE(kprintf("LIB_Expunge: return Segment 0x%lx to ramlib\n",
	              MySegment));

	return MySegment;
}

BPTR LIB_Expunge(void)
{
	struct LibBase *MyLibBase = (struct LibBase*)REG_A6;

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

struct Library*	LIB_Open(void)
{
	struct LibBase *MyLibBase = (struct LibBase*)REG_A6;

	DEBUG_OPEN(kprintf("LIB_Open: 0x%p <%s> OpenCount %ld\n",
	                   MyLibBase,
	                   MyLibBase->Lib.lib_Node.ln_Name,
	                   MyLibBase->Lib.lib_OpenCnt));

	Forbid();

	MyLibBase->Lib.lib_Flags &= ~LIBF_DELEXP;
	MyLibBase->Lib.lib_OpenCnt++;

	if (MyLibBase->Lib.lib_OpenCnt == 1)
	{
		Permit();

		DEBUG_OPEN(kprintf("LIB_Open: Calling constructors\n"));

		CallFuncArray(__ctrslist);
	}
	else
	{
		Permit();
	}

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

BPTR LIB_Close(void)
{
	struct LibBase *MyLibBase = (struct LibBase*)REG_A6;
	#undef SysBase
	struct ExecBase *SysBase = MyLibBase->sysBase;
	BPTR ret = 0;

	DEBUG_CLOSE(kprintf("LIB_Close: 0x%p <%s> OpenCount %ld\n",
	                    MyLibBase,
	                    MyLibBase->Lib.lib_Node.ln_Name,
	                    MyLibBase->Lib.lib_OpenCnt));

	Forbid();

	if ((--MyLibBase->Lib.lib_OpenCnt) > 0)
	{
		DEBUG_CLOSE(kprintf("LIB_Close: done\n"));
	}
	else
	{
		if (MyLibBase->Lib.lib_OpenCnt == 0)
		{
			DEBUG_CLOSE(kprintf("LIB_Close: Calling destructors\n"));

			CallFuncArray(__dtrslist);
		}

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
