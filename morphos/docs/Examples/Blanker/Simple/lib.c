#include	"libdata.h"

#define	LIB_VERSION		1
#define	LIB_REVISION	1

#define	DEBUG_INIT(x)		;
#define	DEBUG_OPEN(x)		;
#define	DEBUG_CLOSE(x)		;
#define	DEBUG_EXPUNGE(x)	;
#define	DEBUG_NULL(x)		;

extern ULONG LibFuncTable[];

extern ULONG BlankerLibInit(void);
extern void	 BlankerLibFree(void);
extern char	BlankerLibName[];
extern char	BlankerVersionID[];
extern struct TagItem MyBlankerQueryTags[];

struct Library*	LIB_Init(struct LibBase	*MyLibBase,
						 BPTR SegList,
						 struct ExecBase *SBase);
struct LibInitStruct
{
	ULONG	LibSize;
	void	*FuncTable;
	void	*DataTable;
	void	(*InitFunc)(void);
};

struct LibInitStruct LibInitStruct=
{
	sizeof(struct LibBase),
	LibFuncTable,
	NULL,
	(void (*)(void)) &LIB_Init
};

static struct TagItem QueryTags[] =
{
	{QUERYINFOATTR_CODETYPE,MACHINE_PPC},
	{QUERYINFOATTR_SUBTYPE,QUERYSUBTYPE_LIBRARY},
	{QUERYINFOATTR_CLASS,QUERYCLASS_INTUITION},
	{QUERYINFOATTR_SUBCLASS,QUERYSUBCLASS_INTUITION_BLANKERAPI},
	{TAG_MORE,(ULONG)MyBlankerQueryTags}
};

struct Resident LibResident=
{
	RTC_MATCHWORD,
	&LibResident,
	&LibResident + 1,
	RTF_PPC | RTF_EXTENDED | RTF_AUTOINIT,
	LIB_VERSION,
	NT_LIBRARY,
	0,
	BlankerLibName,
	BlankerVersionID,
	&LibInitStruct,
	/* New Fields */
	LIB_REVISION,
	(struct TagItem *)QueryTags
};

/*
 * To tell the loader that this is a new abox elf and not
 * one for the ppc.library.
 * ** IMPORTANT **
 */
ULONG	__abox__=1;

#undef SysBase
struct ExecBase	*SysBase;

/* The lib execute init protection which simply returns
 */

ULONG NoExecute(void)
{
	return(0);
}

/*
 * Resident is a RTF_PPC one...that means it`s called
 * natively with normal PPC SysV4 ABI argument order.
 */
struct Library* LIB_Init(struct LibBase		*MyLibBase,
						 BPTR			SegList,
						 struct ExecBase	*SBase)
{
	DEBUG_INIT(dprintf("LibInit: LibBase 0x%p SegList 0x%lx SBase 0x%p\n",
	                   MyLibBase,
	                   SegList,
	                   SBase));
	MyLibBase->SegList = SegList;
	MyLibBase->SBase = SBase;
	SysBase = SBase;

	MyLibBase->Lib.lib_Flags |= LIBF_QUERYINFO;

	InitSemaphore(&MyLibBase->Semaphore);

	return(&MyLibBase->Lib);
}

#define	SysBase	MyLibBase->SBase


ULONG LibExpunge(struct LibBase *MyLibBase)
{
	BPTR MySegment;

	DEBUG_EXPUNGE(dprintf("LIB_Expunge: LibBase 0x%p <%s> OpenCount %ld\n",
	                      MyLibBase,
	                      MyLibBase->Lib.lib_Node.ln_Name,
	                      MyLibBase->Lib.lib_OpenCnt));

	MySegment =	MyLibBase->SegList;

	if (MyLibBase->Lib.lib_OpenCnt)
	{
		DEBUG_EXPUNGE(dprintf("LIB_Expunge: set LIBF_DELEXP\n"));
		MyLibBase->Lib.lib_Flags |= LIBF_DELEXP;
		return(NULL);
	}

/* We don`t need a forbid() because Expunge and Close
 * are called with a pending forbid.
 * But let`s do it for savety if somebody does it by hand.
 */
	Forbid();
	DEBUG_EXPUNGE(dprintf("LIB_Expunge: remove the library\n"));
	Remove(&MyLibBase->Lib.lib_Node);
	Permit();

	DEBUG_EXPUNGE(dprintf("LIB_Expunge: free the library\n"));
	FreeMem((APTR)((ULONG)(MyLibBase) - (ULONG)(MyLibBase->Lib.lib_NegSize)),
	        MyLibBase->Lib.lib_NegSize + MyLibBase->Lib.lib_PosSize);

	DEBUG_EXPUNGE(dprintf("LIB_Expunge: return Segment 0x%lx to ramlib\n",
	                      MySegment));
	return((ULONG) MySegment);
}

ULONG LIB_Expunge(void)
{
	struct LibBase *MyLibBase=(struct LibBase*) REG_A6;

	DEBUG_EXPUNGE(dprintf("LIB_Expunge:\n"));
	return(LibExpunge(MyLibBase));
}

struct Library*	LIB_Open(void)
{
	struct LibBase *MyLibBase=(struct LibBase*) REG_A6;
	struct Library *Result;

	DEBUG_OPEN(dprintf("LIB_Open: 0x%p <%s> OpenCount %ld\n",
	                   MyLibBase,
	                   MyLibBase->Lib.lib_Node.ln_Name,
	                   MyLibBase->Lib.lib_OpenCnt));


	ObtainSemaphore(&MyLibBase->Semaphore);

	MyLibBase->Lib.lib_Flags &= ~LIBF_DELEXP;
	MyLibBase->Lib.lib_OpenCnt++;

	Result = &MyLibBase->Lib;
	if (MyLibBase->Lib.lib_OpenCnt==1)
	{
		if (!MyLibBase->UtilBase) MyLibBase->UtilBase = OpenLibrary("utility.library",0);

		if(MyLibBase->UtilBase)
		{
			struct TagItem *ti;

			if((ti=(struct TagItem *)FindTagItem(QUERYINFOATTR_VERSION,MyBlankerQueryTags)))
			{
				MyLibBase->Lib.lib_Version = ti->ti_Data;
			}

			if((ti=(struct TagItem *)FindTagItem(QUERYINFOATTR_REVISION,MyBlankerQueryTags)))
			{
				MyLibBase->Lib.lib_Revision = ti->ti_Data;
			}
		}

		if (!BlankerLibInit())
		{
			Result = NULL;
		}
	}
	ReleaseSemaphore(&MyLibBase->Semaphore);
	return(Result);
}

ULONG LIB_Close(void)
{
	struct LibBase *MyLibBase=(struct LibBase*) REG_A6;

	DEBUG_CLOSE(dprintf("LIB_Close: 0x%p <%s> OpenCount %ld\n",
	                    MyLibBase,
	                    MyLibBase->Lib.lib_Node.ln_Name,
	                    MyLibBase->Lib.lib_OpenCnt));

	ObtainSemaphore(&MyLibBase->Semaphore);

	if ((--MyLibBase->Lib.lib_OpenCnt) > 0)
	{
		DEBUG_CLOSE(dprintf("LIB_Close: done\n"));
	}
	else
	{
		if (MyLibBase->UtilBase) CloseLibrary(MyLibBase->UtilBase);
		MyLibBase->UtilBase = NULL;

		BlankerLibFree();
		if (MyLibBase->Lib.lib_Flags & LIBF_DELEXP)
		{
			DEBUG_CLOSE(dprintf("LIB_Close: LIBF_DELEXP set\n"));
			return(LibExpunge(MyLibBase));
		}
	}
	ReleaseSemaphore(&MyLibBase->Semaphore);
	return(0);
}

ULONG LIB_Query(void)
{
	struct LibBase *MyLibBase=(struct LibBase*) REG_A6;
	ULONG *Data = (ULONG*)REG_A0;
	ULONG Attr = REG_D0;

	DEBUG_NULL(dprintf("LIB_Query:\n"));

	if (MyLibBase->UtilBase)
	{
		struct TagItem *ti;

		if ((ti = FindTagItem(Attr,QueryTags)))
		{
			*Data = ti->ti_Data;
			return TRUE;
		}
	}

	return FALSE;
}

