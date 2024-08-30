#ifndef EMUL_EMULINTERFACE_H
#define EMUL_EMULINTERFACE_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif /* EXEC_TYPES_H */

struct ExecBase;

#define TRAP_MASK               0x00ff
#define TRAP_AREA_START         0xff00 /* 0xff00 .. 0xffff area */

/***********************************************************************************
 *      Trap: EmulLibEntry.Trap == TRAP_LIB
 *    Result: D0
 *  Function: Call a PPC Function with std SystemV4 register layout.
 *            The 68k frame is saved in the EmulHandle which
 *            is passed in gpr2 and MUST not be changed.
 *            The Result is passed in gpr3 and then moved to REG_D0.
 * Emulation: PC      = *REG_A7
 *            REG_A7 += 4;
 *      Note: Should be used with complex PPC functions
 */

#define TRAP_LIB                0xff00

/***********************************************************************************
 *      Trap: EmulLibEntry.Trap == TRAP_LIB_QUICK
 *    Result: D0
 *  Function: Call a PPC Function with 68k emulation register layout.
 *            See emulregs.h.
 *            You must not kill the REG_SR register.
 *            Only A7 and SR is saved to the EmulHandle because
 *            they may be needed for Emulation Calls out of the PPC.
 *            EmulHandle is passed in gpr2 and MUST not be changed
 *            The Result is passed in gpr3 and then moved to REG_D0.
 * Emulation: PC      = *REG_A7
 *            REG_A7 += 4;
 *      Note: Should be used with simple/quick PPC function which don't
 *            require many registers.
 */
#define TRAP_LIB_QUICK          0xff01


/***********************************************************************************
 *      Trap: EmulLibEntry.Trap == TRAP_LIBNR
 *    Result: None
 *  Function: Call a PPC Function with std SystemV4 register layout.
 *            The 68k frame is saved in the EmulHandle which
 *            is passed in gpr2 and MUST not be changed
 *            The PPC function doesn't return any result.
 * Emulation: PC      = *REG_A7
 *            REG_A7 += 4;
 *      Note: Should be used with complex PPC functions
 */
#define TRAP_LIBNR              0xff05

/***********************************************************************************
 *      Trap: EmulLibEntry.Trap == TRAP_LIBNR_QUICK
 *    Result: None
 *  Function: Call a PPC Function with 68k emulation register layout.
 *            See emulregs.h.
 *            You must not change the emul regs.
 *            Only A7 and SR is saved to the EmulHandle because
 *            they may be needed for Emulation Calls out of the PPC.
 *            EmulHandle is passed in gpr2 and MUST not be changed
 *            The PPC function doesn't return any result.
 * Emulation: PC      = *REG_A7
 *            REG_A7 += 4;
 *      Note: Should be used with simple/quick PPC function which don't
 *            require many registers.
 */
#define TRAP_LIBNR_QUICK        0xff06





/***********************************************************************************
 *      Trap: TRAP_ISYNC
 *  Function: Synchronize the instruction stream of the CPU.
 *            PPC's "isync".
 * Emulation: PC+=2
 */
#define TRAP_ISYNC              0xff0f

/***********************************************************************************
 *      Trap: TRAP_SYNC
 *  Function: Synchronize the instruction stream of the CPU.
 *            PPC's "sync".
 * Emulation: PC+=2
 */
#define TRAP_SYNC               0xff10


/***********************************************************************************
 *      Trap: TRAP_EIEIO
 *  Function: Orders the instruction stream of the CPU.
 *            PPC's "eieio".
 * Emulation: PC+=2
 */
#define TRAP_EIEIO              0xff11

/***********************************************************************************
 *      Trap: EmulLibEntry.Trap == TRAP_LIBSR
 *    Result: D0 , REG_SR <- MyEmulHandle->SR
 *  Function: Call a PPC Function with std SystemV4 register layout.
 *            The 68k frame is saved in the EmulHandle which
 *            is passed in gpr2 and MUST not be changed
 *            The Result is passed in gpr3 and then moved to REG_D0.
 *            REG_SR is updated with MyEmulHandle->SR so you're able
 *            to change it which may be useful for wrongly used
 *            exec memory functions where the result SR may be
 *            important.
 * Emulation: PC      = *REG_A7
 *            REG_A7 += 4;
 *      Note: Should be used with complex PPC functions
 */

#define TRAP_LIBSR              0xff12

/***********************************************************************************
 *      Trap: EmulLibEntry.Trap == TRAP_LIBSRNR
 *    Result: REG_SR <- MyEmulHandle->SR
 *  Function: Call a PPC Function with std SystemV4 register layout.
 *            The 68k frame is saved in the EmulHandle which
 *            is passed in gpr2 and MUST not be changed
 *            The PPC function doesn't return any result.
 *            REG_SR is updated with MyEmulHandle->SR so you're able
 *            to change it which may be useful for wrongly used
 *            exec memory functions where the result SR may be
 *            important.
 * Emulation: PC      = *REG_A7
 *            REG_A7 += 4;
 *      Note: Should be used with complex PPC functions
 */
#define TRAP_LIBSRNR            0xff13


/***********************************************************************************
 *      Trap: EmulLibEntry.Trap == TRAP_LIBD0_D1
 *    Result: D0 , REG_D1 <- MyEmulHandle->Dn[1]
 *  Function: Call a PPC Function with std SystemV4 register layout.
 *            The 68k frame is saved in the EmulHandle which
 *            is passed in gpr2 and MUST not be changed
 *            The Result is passed in gpr3 and then moved to REG_D0.
 *            REG_D1 is updated with MyEmulHandle->Dn[1] so you're able
 *            to change it which is needed for braindead LoadSeg
 *            and software using *Overlays*
 * Emulation: PC      = *REG_A7
 *            REG_A7 += 4;
 *      Note: Should be used with complex PPC functions
 */

#define TRAP_LIBD0_D1           0xff14

/***********************************************************************************
 *      Trap: EmulLibEntry.Trap == TRAP_LIBRESTORE
 *    Result: None
 *  Function: Call a PPC Function with std SystemV4 register layout.
 *            The 68k frame is saved in the EmulHandle which
 *            is passed in gpr2 and MUST not be changed
 *            The function copies the emulation context registers
 *            with the functions inside the EmulHandle.
 * Emulation: PC      = *REG_A7
 *            REG_A7 += 4;
 *      Note: Should only be used in special code. Setjmp/GetA4 inside PPC code.
 */

#define TRAP_LIBRESTORE         0xff15

/***********************************************************************************
 *      Trap: EmulLibEntry.Trap == TRAP_LIBD0_D1_SR
 *    Result: D0 , REG_D1 <- MyEmulHandle->Dn[1], REG_SR <- MyEmulHandle->SR
 *  Function: Call a PPC Function with std SystemV4 register layout.
 *            The 68k frame is saved in the EmulHandle which
 *            is passed in gpr2 and MUST not be changed
 *            The Result is passed in gpr3 and then moved to REG_D0.
 *            REG_D1 is updated with MyEmulHandle->Dn[1] so you're able
 *            to change it which is needed for braindead LoadSeg
 *            and software using *Overlays*
 *            SR is updated.
 * Emulation: PC      = *REG_A7
 *            REG_A7 += 4;
 *      Note: Should be used with complex PPC functions
 */

#define TRAP_LIBD0D1SR          0xff17

/***********************************************************************************
 *      Trap: EmulLibEntry.Trap == TRAP_LIBD0D1A0A1SR
 *    Result: D0 , REG_D1 <- MyEmulHandle->Dn[1], REG_A0 <- MyEmulHandle->An[0],
 *                 REG_A1 <- MyEmulHandle->An[1], REG_SR <- MyEmulHandle->SR
 *  Function: Call a PPC Function with std SystemV4 register layout.
 *            The 68k frame is saved in the EmulHandle which
 *            is passed in gpr2 and MUST not be changed
 *            The Result is passed in gpr3 and then moved to REG_D0.
 *            REG_D1, REG_A0, REG_A1 and REG_SR are updated too. 
 * Emulation: PC      = *REG_A7
 *            REG_A7 += 4;
 *      Note: Should be used with complex PPC functions
 */

#define TRAP_LIBD0D1A0A1SR      0xff18





#define EMULTAG_NAME            0x0 /* Gives back a Name Ptr */
#define EMULTAG_VERSION         0x1 /* Gives back a Version */
#define EMULTAG_REVISION        0x2 /* Gives back a Revision */
#define EMULTAG_OPCODETABLE     0x3 /* Gives back the 16 Bit Opcodetable Ptr or NULL */
#define EMULTAG_TYPE            0x4 /* Gives back the emulation type */
#define EMULTAG_EMULHANDLE      0x5 /* Gives back the EmulHandle Ptr */
#define EMULTAG_EMULHANDLESIZE  0x6 /* Gives back the EmulHandle Size */
#define EMULTAG_SUPERHANDLE     0x7 /* Gives back the SuperHandle Ptr */
#define EMULTAG_SUPERHANDLESIZE 0x8 /* Gives back the SuperHandle Size */


struct EmulCaos
{
	union
	{
		int  Offset;
		APTR Function;
	} caos_Un;
	ULONG reg_d0;
	ULONG reg_d1;
	ULONG reg_d2;
	ULONG reg_d3;
	ULONG reg_d4;
	ULONG reg_d5;
	ULONG reg_d6;
	ULONG reg_d7;
	ULONG reg_a0;
	ULONG reg_a1;
	ULONG reg_a2;
	ULONG reg_a3;
	ULONG reg_a4;
	ULONG reg_a5;
/*
 * here you have to put the LibBasePtr if you want
 * to call a Library.
 */
	ULONG reg_a6;
};

struct EmulLibEntry
{
	UWORD Trap;
	UWORD Extension; /* MUST be set to 0 if you create it by hand */
	void  (*Func)(void);
};

struct EmulFunc
{
	UWORD Trap; /* TRAP_FUNC */
	UWORD Extension;
	ULONG Address;
	/* Size 0 for no new Stack
	 */
	ULONG StackSize;
	ULONG Arg1;
	ULONG Arg2;
	ULONG Arg3;
	ULONG Arg4;
	ULONG Arg5;
	ULONG Arg6;
	ULONG Arg7;
	ULONG Arg8;
};



#define GETEMULHANDLE   register struct EmulHandle *MyEmulHandle __asm("r2");

#ifndef ROMEMUL

struct SuperHandle
{
	ULONG USP;  /* Userstack */
	ULONG SSP;  /* Supervisor Stack */
	ULONG VBR;  /* Exception Base Register */
	ULONG SFC;  /* SFC Register ...not really used */
	ULONG DFC;  /* DFC Register ...not really used */
	ULONG CACR; /* Cache Control Register ...not really used */
	ULONG TC;
	ULONG ITT0;
	ULONG ITT1;
	ULONG DTT0;
	ULONG DTT1;
	ULONG URP;
	ULONG SRP;
	ULONG BUSCR;
	ULONG PCR;
	ULONG Type; /* SuperHandle Type..not used yet */

/********************************************************************************************
 * Private
 * Don't touch
 */
	ULONG Private00;
	APTR  Private01;
	APTR  Private02;
	APTR  Private03;
	APTR  Private04;
	ULONG Private05;
	APTR  Private06;
	ULONG Private07;
	APTR  Private08;
	int   Private09;
	int   Private0A;
	int   Private0B;
	ULONG Private0C;

	ULONG PrivateXX[1024-29];

/********************************************************************************************
 * Public
 * Read only
 */
	struct ExecBase *GlobalSysBase; /* Global SysBase pointer */
	ULONG ROPrivateXX[1024-1];
};

struct Float96
{
	ULONG Data[3];
};

struct EmulHandle
{
	ULONG              Dn[8];                                 /* 0x00 */
	ULONG              An[8];                                 /* 0x20 */
	ULONG              *PC;                                   /* 0x40 Current PC */
	ULONG              SR;                                    /* 0x44 Statusregister */
	struct SuperHandle *SuperHandle;                          /* 0x48 Ptr to SuperHandle */
	ULONG              Type;                                  /* 0x4c EmulHandle Type */
	ULONG              Flags;                                 /* 0x50 Flags */

	void               (*EmulFunc)(void);                     /* 0x54 Here is the direct Emulation Jump..you have to setup the regframes*/
	ULONG              (*EmulCallOS)(struct EmulCaos*);       /* 0x58 Here is the Emulation Jump for a 68k OSLib Function*/
	ULONG              (*EmulCall68k)(struct EmulCaos*);      /* 0x5c Here is the Emulation Jump for a 68k Function*/
	ULONG              (*EmulCallQuick68k)(struct EmulCaos*); /* 0x60 Here is the Emulation Quick Jump for a 68k Function..r13..r31 are not saved!*/
	ULONG              (*EmulCallDirectOS)(LONG);             /* 0x64 Here is the Emulation Direct Jump for a 68k OSLib Function*/
	ULONG              (*EmulCallDirect68k)(APTR);            /* 0x68 Here is the Emulation Direct Jump for a 68k Function*/
	struct EmulHandle  *OldEmulHandle;                        /* 0x6c Here we record the previous EmulHandle*/
	struct Float96     FPU[8];                                /* 0x70 Not yet used...*/
	ULONG              FPCR;                                  /* 0xd0 Not yet used...*/
	ULONG              FPSR;                                  /* 0xd4 Not yet used...*/
	ULONG              FPIAR;                                 /* 0xd8 Not yet used...*/
	struct HashEntry   *HashEntry;                            /* 0xdc */
/********************************************************************************************
 * Private
 * Don't touch
 * 0xe0
 */

};

#define EMULFLAGSF_PPC       0x1 /* Set when the emulation runs in full native code */
#define EMULFLAGSF_QUICK     0x2 /* Set when the emulation runs quick native code..
                                  * which is basicly still the emul reg layout
                                  */
#define EMULFLAGSF_INTERRUPT 0x4 /* Set when the emulation runs in interrupt mode
                                  */

#endif


#endif
