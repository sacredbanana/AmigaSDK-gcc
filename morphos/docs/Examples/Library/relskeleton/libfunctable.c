#include "libdata.h"



void LIB_Open(void);
void LIB_Close(void);
void LIB_Expunge(void);
void LIB_Reserved(void);
void LIB_SetRelVariable(void);
void LIB_GetRelVariable(void);


ULONG LibFuncTable[]=
{
	FUNCARRAY_32BIT_NATIVE,
	(ULONG) &LIB_Open, /* Old ABOX Library ABI Function Block */
	(ULONG) &LIB_Close,
	(ULONG) &LIB_Expunge,
	(ULONG) &LIB_Reserved,

	(ULONG) &LIB_SetRelVariable,
	(ULONG) &LIB_GetRelVariable,
	0xffffffff,
};

