#include "libdata.h"



void LIB_Open(void);
void LIB_Close(void);
void LIB_Expunge(void);
void LIB_Reserved(void);
void LIB_TestSPrintf(void);
void LIB_TestAdd(void);
void LIB_TestSub(void);
void LIB_TestTagList(void);


ULONG LibFuncTable[]=
{
	FUNCARRAY_BEGIN,
		FUNCARRAY_32BIT_NATIVE,

		// basename SkeletonnewBase
		(ULONG) &LIB_Open,       /* Old ABOX Library ABI Function Block */
		(ULONG) &LIB_Close,
		(ULONG) &LIB_Expunge,
		(ULONG) &LIB_Reserved,
		0xffffffff,

		FUNCARRAY_32BIT_SYSTEMV, /* New SystemV ABI Function Block..can't be called from 68k anymore */

		// prefix LIB_
		// includefrom ./os-include/clib/skeletonnew_protos.h
		// comment The TestSPrintf function takes the library base as first argument.
		// comment and the varargs arguments are passed with the normal C systemv abi.
		// callmode base,sysv
		(ULONG) &LIB_TestSPrintf,
		// comment TestAdd doesn't need it at all.
		// callmode sysv
		(ULONG) &LIB_TestAdd,
		// comment Using (sysv,base) means that the base is the last argument.
		// callmode sysv,base
		(ULONG) &LIB_TestSub,
		// comment This routine expects a TagList and as there's also varargs proto
		// comment function entry while we haven't specified it as a real varargs here,
		// comment cvinclude creates a 2nd inline entry where the tag varargs are passed
		// comment as a linear stream like you need it for abox taglists
		// callmode base,sysv
		(ULONG) &LIB_TestTagList,
		0xffffffff,
	FUNCARRAY_END
};

