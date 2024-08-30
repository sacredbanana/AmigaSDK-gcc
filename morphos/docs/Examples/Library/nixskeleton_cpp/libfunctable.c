#include "libdata.h"



void LIB_Open(void);
void LIB_Close(void);
void LIB_Expunge(void);
void LIB_Reserved(void);
void LIB_HelloWorld(void);


ULONG LibFuncTable[]=
{
	FUNCARRAY_BEGIN,
		FUNCARRAY_32BIT_NATIVE,
		(ULONG) &LIB_Open, /* Old ABOX Library ABI Function Block */
		(ULONG) &LIB_Close,
		(ULONG) &LIB_Expunge,
		(ULONG) &LIB_Reserved,
		0xffffffff,

		FUNCARRAY_32BIT_SYSTEMV,
		(ULONG) &LIB_HelloWorld,
		0xffffffff,
	FUNCARRAY_END
};

