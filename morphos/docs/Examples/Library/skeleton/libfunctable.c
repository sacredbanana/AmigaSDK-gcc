#include "libdata.h"



void LIB_Open(void);
void LIB_Close(void);
void LIB_Expunge(void); /* LIB_Expunge */
void LIB_Reserved(void);
void LIB_PPCPrintString(void);


#if 0

/*
 * The old way, if FUNCARRAY_32BIT_NATIVE is not used:
 *
 * All functions are executed in 68k mode.
 * You need to do the 68k->PPC switch yourself.
 */

struct EmulLibEntry	GATE_Open =
{
	TRAP_LIB, 0, (void (*)(void)) LIB_Open
};

struct EmulLibEntry	GATE_Close =
{
	TRAP_LIB, 0, (void (*)(void)) LIB_Close
};

struct EmulLibEntry	GATE_Expunge =
{
	TRAP_LIB, 0, (void (*)(void)) LIB_Expunge
};

struct EmulLibEntry	GATE_Reserved =
{
	TRAP_LIB, 0, (void (*)(void)) LIB_Reserved
};

struct EmulLibEntry	GATE_PPCPrintString =
{
	TRAP_LIB, 0, (void (*)(void)) LIB_PPCPrintString
};



void (*LibFuncTable[])(void)=
{
	(void (*)(void)) &GATE_Open,
	(void (*)(void)) &GATE_Close,
	(void (*)(void)) &GATE_Expunge,
	(void (*)(void)) &GATE_Reserved,
	(void (*)(void)) &GATE_PPCPrintString,
	0xffffffff
};

#else

/*
 * The new way, when FUNCARRAY_32BIT_NATIVE is used:
 *
 * MorphOS builds gates for you.
 * All functions are directly executed in PPC mode.
 */

ULONG	LibFuncTable[]=
{
	FUNCARRAY_32BIT_NATIVE,
	(ULONG) &LIB_Open,
	(ULONG) &LIB_Close,
	(ULONG) &LIB_Expunge,
	(ULONG) &LIB_Reserved,
	(ULONG) &LIB_PPCPrintString,
	0xffffffff
};

#endif
