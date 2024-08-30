#ifndef EXEC_TASKS_H
#define EXEC_TASKS_H
/*
**    $VER: tasks.h 53.29 (10.8.2015)
**
**    Task Control Block, Signals, and Task flags.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef   EXEC_EXECTAGS_H
#include <exec/exectags.h>
#endif

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

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#elif defined(__SASC)
   #pragma msg 79 ignore push
#endif

/****************************************************************************/

/* Please use Exec functions to modify task structure fields,
 * where available.
 */
struct Task
{
    struct Node tc_Node;
    uint8       tc_Flags;
    uint8       tc_State;
    int8        tc_IDNestCnt;  /* intr disabled nesting*/
    int8        tc_TDNestCnt;  /* task disabled nesting*/
    uint32      tc_SigAlloc;   /* sigs allocated */
    uint32      tc_SigWait;    /* sigs we are waiting for */
    uint32      tc_SigRecvd;   /* sigs we have received */
    uint32      tc_SigExcept;  /* sigs we will take excepts for */

    /*
    ** The following field used to be this
    ** UWORD   tc_TrapAlloc;
    ** UWORD   tc_TrapAble;
    ** It was replaced by a pointer to an extended task structure.
    ** This structure is private, and must *NOT* be accessed.
    ** There's no guarantee that it's even there, or what exactly
    ** it points to... you have been warned..
    ** Note: Contrary to what V36 does, this fields is *always* a pointer.
    ** The appropriate flag is implicit in V50.
    */
    APTR        tc_ETask;      /* Extended task pointer */
    APTR        tc_ExceptData; /* points to except data */
    APTR        tc_ExceptCode; /* points to except code */
    APTR        tc_TrapData;   /* points to trap data */
    APTR        tc_TrapCode;   /* points to trap code */
    APTR        tc_SPReg;      /* stack pointer */
    APTR        tc_SPLower;    /* stack lower bound */
    APTR        tc_SPUpper;    /* stack upper bound + 2*/
    VOID      (*tc_Switch)();  /* task losing CPU */
    VOID      (*tc_Launch)();  /* task getting CPU */
    struct List tc_MemEntry;   /* Allocated memory. Freed by RemTask() */
    APTR        tc_UserData;   /* For use by the task; no restrictions! */
};


/****************************************************************************/

/*
 * Stack swap structure as passed to StackSwap()
 */
struct StackSwapStruct
{
    APTR   stk_Lower;   /* Lowest byte of stack */
    uint32 stk_Upper;   /* Upper end of stack (size + Lowest) */
    APTR   stk_Pointer; /* Stack pointer at switch point */
};

/****************************************************************************/

/*----- Flag Bits ------------------------------------------*/
enum enTaskFlagsBits
{
    TB_PROCTIME = 0,
    TB_ETASK    = 3,
    TB_STACKCHK = 4,
    TB_EXCEPT   = 5,
    TB_SWITCH   = 6,
    TB_LAUNCH   = 7
};

enum enTaskFlags
{
    TF_PROCTIME = (1<<0),
    TF_ETASK    = (1<<3),
    TF_STACKCHK = (1<<4),
    TF_EXCEPT   = (1<<5),
    TF_SWITCH   = (1<<6),
    TF_LAUNCH   = (1<<7)
};


/*----- Task States ----------------------------------------*/
enum enTaskState
{
    TS_INVALID   = 0,
    TS_ADDED     = 1,
    TS_RUN       = 2,
    TS_READY     = 3,
    TS_WAIT      = 4,
    TS_EXCEPT    = 5,
    TS_REMOVED   = 6,
    TS_CRASHED   = 7,
    TS_SUSPENDED = 8
};

/*----- Predefined Signals -------------------------------------*/
enum enTaskSignalBits
{
    SIGB_ABORT     = 0,
    SIGB_CHILD     = 1,
    SIGB_BLIT      = 4, /* Note: same as SINGLE */
    SIGB_SINGLE    = 4, /* Note: same as BLIT */
    SIGB_INTUITION = 5,
    SIGB_NET       = 7,
    SIGB_DOS       = 8
};

enum enTaskSignal
{
    SIGF_ABORT     = (1<<SIGB_ABORT),
    SIGF_CHILD     = (1<<SIGB_CHILD),
    SIGF_BLIT      = (1<<SIGB_BLIT),
    SIGF_SINGLE    = (1<<SIGB_SINGLE),
    SIGF_INTUITION = (1<<SIGB_INTUITION),
    SIGF_NET       = (1<<SIGB_NET),
    SIGF_DOS       = (1<<SIGB_DOS)
};


/****************************************************************************/

enum enSuspendBits
{
    STB_CRASHED = 0,
    STB_REMOVED = 1,
};

enum enSuspendFlags
{
    STF_CRASHED = (1<<STB_CRASHED),
    STF_REMOVED = (1<<STB_REMOVED)
};

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#elif defined(__SASC)
   #pragma msg 79 pop
#endif

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_TASKS_H */
