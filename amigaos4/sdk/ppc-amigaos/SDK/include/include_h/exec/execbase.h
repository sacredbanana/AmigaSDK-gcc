#ifndef EXEC_EXECBASE_H
#define EXEC_EXECBASE_H
/*
**    $VER: execbase.h 53.29 (10.8.2015)
**
**    Definition of the exec.library base structure.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef   EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef   EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef   EXEC_TASKS_H
#include <exec/tasks.h>
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
#elif defined(__SASC)
   #pragma msg 79 ignore push
#endif

/****************************************************************************/

/* Definition of the Exec library base structure (pointed to by location 4).
 * Most fields are not to be viewed or modified by user programs. Use
 * extreme caution.
 */

struct ExecBase
{
    struct Library LibNode; /* Standard library node */

/******** Static System Variables ********/

    UWORD   SoftVer;        /* kickstart release number (obs.) */
    WORD    LowMemChkSum;   /* checksum of 68000 trap vectors */
    ULONG   ChkBase;        /* system base pointer complement */
    APTR    ColdCapture;    /* coldstart soft capture vector */
    APTR    CoolCapture;    /* coolstart soft capture vector */
    APTR    WarmCapture;    /* warmstart soft capture vector */
    APTR    SysStkUpper;    /* system stack base   (upper bound) */
    APTR    SysStkLower;    /* top of system stack (lower bound) */
    ULONG   MaxLocMem;      /* top of chip memory */
    APTR    DebugEntry;     /* global debugger entry point */
    APTR    DebugData;      /* global debugger data segment */
    APTR    AlertData;      /* alert data segment */
    APTR    MaxExtMem;      /* top of extended mem, or null if none */

    UWORD   ChkSum;         /* for all of the above (minus 2) */

/****** Interrupt Related ***************************************/

    struct IntVector IntVects[16];

/****** Dynamic System Variables *************************************/

    struct Task *ThisTask;  /* pointer to current task (readable) */

    ULONG   IdleCount;      /* idle counter */
    ULONG   DispCount;      /* dispatch counter */
    UWORD   Quantum;        /* time slice quantum */
    UWORD   Elapsed;        /* current quantum ticks */
    UWORD   SysFlags;       /* misc internal system flags */
    BYTE    IDNestCnt;      /* interrupt disable nesting count */
    BYTE    TDNestCnt;      /* task disable nesting count */

    UWORD   AttnFlags;      /* special attention flags (readable) */

    UWORD   AttnResched;    /* rescheduling attention */
    APTR    ResModules;     /* resident module array pointer */
    APTR    TaskTrapCode;
    APTR    TaskExceptCode;
    APTR    TaskExitCode;
    ULONG   TaskSigAlloc;
    UWORD   TaskTrapAlloc;

/****** System Lists (private!) ********************************/

    struct List MemList;
    struct List ResourceList;
    struct List DeviceList;
    struct List IntrList;
    struct List LibList;
    struct List PortList;
    struct List TaskReady;
    struct List TaskWait;

    struct SoftIntList SoftInts[5];

/****** Other Globals *******************************************/

    LONG    LastAlert[4];

    /* these next two variables are provided to allow
       system developers to have a rough idea of the
       period of two externally controlled signals --
       the time between vertical blank interrupts and the
       external line rate (which is counted by CIA A's
       "time of day" clock).  In general these values
       will be 50 or 60, and may or may not track each
       other.  These values replace the obsolete AFB_PAL
       and AFB_50HZ flags. */
    UBYTE    VBlankFrequency;      /* (readable) */
    UBYTE    PowerSupplyFrequency; /* (readable) */

    struct List SemaphoreList;

    /* these next two are to be able to kickstart into user ram.
       KickMemPtr holds a singly linked list of MemLists which
       will be removed from the memory list via AllocAbs.  If
       all the AllocAbs's succeeded, then the KickTagPtr will
       be added to the rom tag list. */
    APTR    KickMemPtr;     /* ptr to queue of mem lists */
    APTR    KickTagPtr;     /* ptr to rom tag queue */
    APTR    KickCheckSum;   /* checksum for mem and tags */

/****** V36 Exec additions start here **************************************/

    UWORD   ex_Pad0;        /* Private internal use */
    ULONG   ex_LaunchPoint; /* Private to Launch/Switch */
    APTR    ex_RamLibPrivate;

    /* The next ULONG contains the system "E" clock frequency,
       expressed in Hertz.  The E clock is used as a timebase for
       the Amiga's 8520 I/O chips. (E is connected to "02").
       Typical values are 715909 for NTSC, or 709379 for PAL. */
    ULONG   ex_EClockFrequency; /* (readable) */
    ULONG   ex_CacheControl;    /* Private to CacheControl calls */
    ULONG   ex_TaskID;          /* Next available task ID */

    ULONG   ex_Reserved1[5];

    APTR    ex_MMULock;         /* private */

    ULONG   ex_Reserved2[3];

/****** V39 Exec additions start here **************************************/

    /* The following list and data element are used
       for V39 exec's low memory handler... */
    struct MinList ex_MemHandlers; /* The handler list */
    APTR           ex_MemHandler;  /* Private! handler pointer */

/****** V50 Exec additions start here **************************************/
    struct Interface *MainInterface; /* ExecLibrary's primary interface */
    APTR    Private01;
    uint32  Private02;
    APTR    Private03;
    APTR    Private04;
    APTR    Private05;
    struct List Private06;
    APTR    Private07;
    APTR    EmuWS;          /* Emulator Workspace. Legacy libraries might 
                               access this field */

/* Yes, there are more additions, but you don't need to know what it is */
};

/****** Bit defines for AttnFlags (see above) ******************************/

/*  Processors and Co-processors: */
enum enAttnFlagBits
{
    AFB_68010   =  0, /* also set for 68020 */
    AFB_68020   =  1, /* also set for 68030 */
    AFB_68030   =  2, /* also set for 68040 */
    AFB_68040   =  3, /* also set for 68060 */
    AFB_68881   =  4, /* also set for 68882 */
    AFB_68882   =  5,
    AFB_FPU40   =  6, /* Set if 68040 FPU */
    AFB_68060   =  7,

    /* The following flags are new to V50 */
    AFB_603     =  8,
    AFB_604     =  9,
    AFB_750     = 10,
    AFB_7400    = 11,
    AFB_ALTIVEC = 12,
    AFB_4XX     = 13,
    AFB_OTHER   = 14,

/*
 * The AFB_FPU40 bit is set when a working 68040 FPU
 * is in the system.  If this bit is set and both the
 * AFB_68881 and AFB_68882 bits are not set, then the 68040
 * math emulation code has not been loaded and only 68040
 * FPU instructions are available.  This bit is valid *ONLY*
 * if the AFB_68040 bit is set.
 *
 * Likewise, AFB_ALTIVEC identifies an existing AltiVec unit.
 */

    AFB_PRIVATE = 15 /* Just what it says */
};

enum enAttnFlags
{
    AFF_68010   = (1<< 0),
    AFF_68020   = (1<< 1),
    AFF_68030   = (1<< 2),
    AFF_68040   = (1<< 3),
    AFF_68881   = (1<< 4),
    AFF_68882   = (1<< 5),
    AFF_FPU40   = (1<< 6),
    AFF_68060   = (1<< 7),

    AFF_603     = (1<< 8),
    AFF_604     = (1<< 9),
    AFF_750     = (1<<10),
    AFF_7400    = (1<<11),
    AFF_ALTIVEC = (1<<12),
    AFF_4XX     = (1<<13),
    AFF_OTHER	= (1<<14),

    AFF_PRIVATE = (1<<15)
};

/****** Selected flag definitions for Cache manipulation calls **********/
#define CACRF_EnableI       (1UL<< 0) /* Enable instruction cache */
#define CACRF_FreezeI       (1UL<< 1) /* Freeze instruction cache */
#define CACRF_ClearI        (1UL<< 3) /* Clear instruction cache  */
#define CACRF_IBE           (1UL<< 4) /* Instruction burst enable */
#define CACRF_EnableD       (1UL<< 8) /* Enable data cache  */
#define CACRF_FreezeD       (1UL<< 9) /* Freeze data cache  */
#define CACRF_ClearD        (1UL<<11) /* Clear data cache
                                         (flush to memory first) */
#define CACRF_DBE           (1UL<<12) /* 68030 Data burst enable */
#define CACRF_WriteAllocate (1UL<<13) /* 68030 Write-Allocate mode
                                         (must always be set!) */
#define CACRF_InvalidateD   (1UL<<15) /* Invalidate data cache (no writeback) */
#define CACRF_EnableE       (1UL<<30) /* Master enable for external caches.
                                         External caches should track the
                                         state of the internal caches
                                         such that they do not cache anything
                                         that the internal cache turned off
                                         for. */
#define CACRF_CopyBack      (1UL<<31) /* Master enable for copyback caches */

enum enDMAFlags
{
    DMA_Continue     = (1<<1),      /* Continuation flag for CachePreDMA */
    DMAF_Continue    = DMA_Continue, 
    DMA_NoModify     = (1<<2),      /* Set if DMA does not update memory */
    DMAF_NoModify    = DMA_NoModify,
    DMA_ReadFromRAM  = (1<<3),      /* Set if DMA goes *FROM* RAM to device */
    DMAF_ReadFromRAM = DMA_ReadFromRAM,
};

/****************************************************************************/

/* The only fixed address in the Amiga memory space. */
#ifndef AbsExecBase
#define AbsExecBase (*(struct ExecBase **)4)
#endif

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


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_EXECBASE_H */
