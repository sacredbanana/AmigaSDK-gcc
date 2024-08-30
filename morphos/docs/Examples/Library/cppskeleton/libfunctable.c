#include "libdata.h"



void LIB_Open(void);
void LIB_Close(void);
void LIB_Expunge(void);
void LIB_Reserved(void);

void __11SkeletonCPP(void);
void Add__11SkeletonCPPii(void);
void Add__11SkeletonCPPdd(void);
void SetVal__11SkeletonCPPi(void);
void GetVal__11SkeletonCPP(void);


ULONG LibFuncTable[]=
{
	FUNCARRAY_BEGIN,
		FUNCARRAY_32BIT_NATIVE,
		(ULONG) &LIB_Open,       /* Old ABOX Library ABI Function Block */
		(ULONG) &LIB_Close,
		(ULONG) &LIB_Expunge,
		(ULONG) &LIB_Reserved,
		0xffffffff,

		FUNCARRAY_32BIT_SYSTEMV, /* New SystemV ABI Function Block..can't be called from 68k anymore */
		(ULONG) &__11SkeletonCPP,
		(ULONG) &Add__11SkeletonCPPii,
		(ULONG) &Add__11SkeletonCPPdd,
		(ULONG) &SetVal__11SkeletonCPPi,
		(ULONG) &GetVal__11SkeletonCPP,
		0xffffffff,
	FUNCARRAY_END
};

