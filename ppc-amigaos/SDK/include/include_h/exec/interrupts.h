#ifndef EXEC_INTERRUPTS_H
#define EXEC_INTERRUPTS_H
/*
**    $VER: interrupts.h 53.29 (10.8.2015)
**
**    Callback structures used by hardware & software interrupts
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

struct Interrupt
{
    struct Node is_Node;
    APTR        is_Data;    /* server data segment */
    VOID      (*is_Code)(); /* server code entry */
};

/****************************************************************************/

struct IntVector /* For EXEC use ONLY! */
{
    APTR         iv_Data;
    VOID       (*iv_Code)();
    struct Node *iv_Node;
};

/****************************************************************************/

struct SoftIntList /* For EXEC use ONLY! */
{
    struct List sh_List;
    UWORD       sh_Pad;
};

/****************************************************************************/

/*
** This structure holds volatile registers during an exception.
** They will be copied back to the appropriate registers after
** returning from the exception handler.
**
** Note: During exception processing, all other registers are considered
**       non-volatile. 
*/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

struct ExceptionContext
{
    uint32  Flags;    /* Flags, describing the context (READ-ONLY)*/
    uint32  Traptype; /* Type of trap (READ-ONLY) */
    uint32  msr;      /* Machine state */
    uint32  ip;       /* Return instruction pointer */
    uint32  gpr[32];  /* r0 - r31 */
    uint32  cr;       /* Condition code register */
    uint32  xer;      /* Extended exception register */
    uint32  ctr;      /* Count register */
    uint32  lr;       /* Link register */
    uint32  dsisr;    /* DSI status register. Only set when valid */
    uint32  dar;      /* Data address register. Only set when valid */
    float64 fpr[32];  /* Floating point registers */
    uint64  fpscr;    /* Floating point control and status register */
    /* The following are only used on AltiVec */
    uint8   vscr[16]; /* AltiVec vector status and control register */
    uint8   vr[512];  /* AltiVec vector register storage */
    uint32  vrsave;   /* AltiVec VRSAVE register */
};

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/* Flags for ExceptionContext */
enum enECFlags
{
    ECF_FULL_GPRS = 1<<0, /* Set if all register have been saved */
                          /* If this flag is not set, gpr[14] through */
                          /* gpr[31] are invalid */
    ECF_FPU       = 1<<1, /* Set if the FPU registers have been saved */
    ECF_FULL_FPU  = 1<<2, /* Set if all FPU registers have been saved */
    ECF_VECTOR    = 1<<3, /* Set if vector registers have been saved */
    ECF_VRSAVE    = 1<<4  /* Set if VRSAVE reflects state of vector */
                          /* registers saved */
};

/* Flags for ReadTaskContext/WriteTaskContext */
enum enRTCFlags
{
	RTCF_SPECIAL	= 1<<0,
	RTCF_STATE		= 1<<1,
	RTCF_GENERAL	= 1<<2,
	RTCF_FPU		= 1<<3,
	RTCF_VECTOR		= 1<<4,
	RTCF_INFO		= 1<<5,
};

#define SIH_PRIMASK (0xf0)

/****************************************************************************/

/* this is a fake INT definition, used only for AddIntServer and the like */
#define INTB_NMI 15
#define INTF_NMI (1<<INTB_NMI)

/* 
** These are used with AddIntServer/SetIntVector to install global
** trap handlers and with SetTaskTrap to install local task traps
** Note: Use of these global trap handlers should be
** restricted to system and debugger use. You should normally
** use the task's local trap handler.
*/

enum enTrapNumbers
{
    TRAPNUM_BUS_ERROR              = 0x01000000, /* Bus error exception/machine check */
    TRAPNUM_DATA_SEGMENT_VIOLATION = 0x02000000, /* Data segment violation */
    TRAPNUM_INST_SEGMENT_VIOLATION = 0x03000000, /* Instruction segment violation */
    TRAPNUM_ALIGNMENT              = 0x04000000, /* Alignment violation */
    TRAPNUM_ILLEGAL_INSTRUCTION    = 0x05000000, /* Illegal instruction */
    TRAPNUM_PRIVILEGE_VIOLATION    = 0x06000000, /* Privilege violation */
    TRAPNUM_TRAP                   = 0x07000000, /* Trap instruction */
    TRAPNUM_FPU                    = 0x08000000, /* Floating point related (FPU disabled, imprecise) */
    TRAPNUM_TRACE                  = 0x09000000, /* Single step trace exception */
    TRAPNUM_DATA_BREAKPOINT        = 0x0a000000, /* Data breakpoint */
    TRAPNUM_INST_BREAKPOINT        = 0x0b000000, /* Instruction breakpoint */
    TRAPNUM_PERFORMANCE            = 0x0c000000, /* Performance monitor (System use only) */
    TRAPNUM_THERMAL                = 0x0d000000, /* Thermal management (System use only) */
    TRAPNUM_RESERVED1		   = 0x0e000000, /* reserved */
    TRAPNUM_ALTIVEC_ASSIST         = 0x0f000000, /* AltiVec Assist */
    TRAPNUM_SMI			   = 0x10000000, /* System Management interrupt */

    TRAPNUM_NUMTRAPS               = 16          /* Number of hardware traps */
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_INTERRUPTS_H */
