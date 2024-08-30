#ifndef EXEC_EMULATION_H
#define EXEC_EMULATION_H
/*
**    $VER: emulation.h 53.29 (10.8.2015)
**
**    Emulator related constans and definitions.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

/* The following structure can be used to switch from 68k into PPC code,
 * in general its use is discouraging but necessary in a few places.
 */
struct EmuTrap
{
    uint32  Instruction;                 /* TRAPINST, see below    */
    uint16  Type;                        /* TRAPTYPE or TRAPTYPENR */
    uint32  (*Function)(uint32 *Reg68K); /* PPC function address,
                                          * also see "enRegConst" below
                                          * but watch out byteoffsets!
                                          */
};

#define TRAPINST   0x4ef80000  /* jmp.w 0, indicate switch            */
#define TRAPTYPE   0x0004      /* type of this trap (result in r3/d0) */
#define TRAPTYPENR 0x0005      /* same as above but no return value   */

/****************************************************************************/

enum enRegConst
{
    REG68K_D0  =   0,
    REG68K_D1  =   4,
    REG68K_D2  =   8,
    REG68K_D3  =  12,
    REG68K_D4  =  16,
    REG68K_D5  =  20,
    REG68K_D6  =  24,
    REG68K_D7  =  28,
    REG68K_A0  =  32,
    REG68K_A1  =  36,
    REG68K_A2  =  40,
    REG68K_A3  =  44,
    REG68K_A4  =  48,
    REG68K_A5  =  52,
    REG68K_A6  =  56,
    REG68K_A7  =  60,

    REG68K_FP0 =  64,
    REG68K_FP1 =  72,
    REG68K_FP2 =  80,
    REG68K_FP3 =  88,
    REG68K_FP4 =  96,
    REG68K_FP5 = 104,
    REG68K_FP6 = 112,
    REG68K_FP7 = 120
};

/****************************************************************************/

/*
 * Tag Items for Emulate() system call
 */
#define ET_RegisterD0     (TAG_USER +  1)
#define ET_RegisterD1     (TAG_USER +  2)
#define ET_RegisterD2     (TAG_USER +  3)
#define ET_RegisterD3     (TAG_USER +  4)
#define ET_RegisterD4     (TAG_USER +  5)
#define ET_RegisterD5     (TAG_USER +  6)
#define ET_RegisterD6     (TAG_USER +  7)
#define ET_RegisterD7     (TAG_USER +  8)

#define ET_RegisterA0     (TAG_USER +  9)
#define ET_RegisterA1     (TAG_USER + 10)
#define ET_RegisterA2     (TAG_USER + 11)
#define ET_RegisterA3     (TAG_USER + 12)
#define ET_RegisterA4     (TAG_USER + 13)
#define ET_RegisterA5     (TAG_USER + 14)
#define ET_RegisterA6     (TAG_USER + 15)
#define ET_RegisterA7     (TAG_USER + 16)

#define ET_NoJIT          (TAG_USER + 17)

#define ET_FPRegisters    (TAG_USER + 18)
#define ET_FPRegisterMask (TAG_USER + 19)

#define ET_SuperState     (TAG_USER + 20)

#define ET_Offset         (TAG_USER + 21)

#define ET_StackPtr       (TAG_USER + 22)

#define ET_SaveRegs       (TAG_USER + 23)
#define ET_SaveParamRegs  (TAG_USER + 24)

/****************************************************************************/

enum enEmulateFPFlags
{
    EFPF_FP0 = 1,
    EFPF_FP1 = 1<<1,
    EFPF_FP2 = 1<<2,
    EFPF_FP3 = 1<<3,
    EFPF_FP4 = 1<<4,
    EFPF_FP5 = 1<<5,
    EFPF_FP6 = 1<<6,
    EFPF_FP7 = 1<<7
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_EMULATION_H */
