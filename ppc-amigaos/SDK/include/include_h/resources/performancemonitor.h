/*
**    $VER: performancemonitor.h 53.29 (10.8.2015)
**
**    Performance monitor resource
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef _RESOURCES_PERFORMANCEMONITOR_H
#define _RESOURCES_PERFORMANCEMONITOR_H

/* Event items that can be counted by Performance Monitor counters */
enum enPerformanceMonitorItems
{
    PMCI_Hold           =   0, /* Hold current value (disable counter) */
    PMCI_CPUCycles      =   1, /* Number of CPU cycles */
    PMCI_Instr          =   2, /* Number of CPU finished instructions */
    PMCI_FPUInstr       =   3, /* Number of instructions completed by FPU */
    PMCI_Transition     =   4, /* Number of transitions of RTC bit from 0 to 1
                                */
    PMCI_InstrDisp      =   5, /* Number of CPU instructions dispatched */
    PMCI_EIEIO          =   6, /* Number of eieio instructions completed */
    PMCI_SYNC           =   7, /* Number of sync instructions completed */
    PMCI_L1DCacheHits   =   8, /* Number of L1 data cache hits */
    PMCI_L1ICacheHits   =   9, /* Number of L1 instruction cache hits */
    PMCI_L2DCacheHits   =  10, /* Number of L2 data cache hits */
    PMCI_L2ICacheHits   =  11, /* Number of L2 instruction cache hits */
    PMCI_L1DCacheMiss   =  12, /* Number of L1 data cache misses */
    PMCI_L1ICacheMiss   =  13, /* Number of L1 instruction cache misses */
    PMCI_L2DCacheMiss   =  14, /* Number of L2 data cache misses */
    PMCI_L2ICacheMiss   =  15, /* Number of L2 instruction cache misses */
    PMCI_L2Hits         =  16, /* Number of hits in L2 cache */
    PMCI_L1LoadThresh   =  17, /* Number of L1 loads that exceed the threshold
                                */
    PMCI_ValidEA        =  18, /* Number of valid virtual addresses delivered
                                  to the memory subsystem */
    PMCI_UnresolvedBra  =  19, /* Number of unresolved branches */
    PMCI_InstrBreak     =  20, /* Number of times an executed instruction's
                                  address matches the IABR */
    PMCI_DataBreak      =  21, /* Number of times a generated virtual address
                                  matches the DABR */
                                   
    PMCI_NumItems       =  22, 
    PMCI_INVALID        = 0x8000
};


/* Tag items for EventControl */
#define PMECT_Disable        (TAG_USER + 1) /* Disable event generation */
#define PMECT_Enable         (TAG_USER + 2) /* Enable even generation   */

/* Tag items for MonitorControl */
#define PMMCT_FreezeCounters (TAG_USER + 1) /* Define freeze count conditions
                                             */
#define PMMCT_RTCBitSelect   (TAG_USER + 3) /* Select bit for sampling */
#define PMMCT_Threshold      (TAG_USER + 4) /* Define threshold for events */
#define PMMCT_GetThreshold   (TAG_USER + 5) /* Get the currently active
                                               threshold */
#define PMMCT_Trigger        (TAG_USER + 6) /* Put Performance Monitor into
                                               triggered mode */


/* Values for PMMCT_Count[Enable|Disable] */
enum enPerformanceMonitorCountControl
{
    PMMC_Always   = 0x01, /* Always freeze */
    PMMC_Super    = 0x02, /* Freeze in supervisor mode */
    PMMC_User     = 0x04, /* Freeze in user mode */
    PMMC_Marked   = 0x08, /* Freeze if marked */
    PMMC_Unmarked = 0x10  /* Freeze if not marked */
};

/* Values for PMMCT_RTCBitSelect */
enum enPerformanceMonitorRTCBitSelect
{
    PMMC_BIT0  = 0, /* Pick bit 0 (i.e. the least significant bit) */
    PMMC_BIT8  = 1, /* Pick bit 8 */
    PMMC_BIT12 = 2, /* Pick bit 12 */
    PMMC_BIT16 = 3  /* Pick bit 16 */
};


/* Query items for Query() */
enum enPerformanceMonitorQueryItems
{
    PMQI_NumCounters    = 1, /* Number of counters available */
    PMQI_IBreakPoint    = 2, /* A boolean value determining whether an
                                instruction breakpoint register is available
                                or not. */
    PMQI_BreakPointMask = 3  /* A boolean value determining whether masking for
                                instruction or data breakpoints is available */
};

/* Predefined interrupt vectors */
#define PMIV_RTCEvent 0x80000001 /* Clock interrupt */
#define PMIV_Monitor  0x80000002 /* General monitor interrupt */

/* Values for SetBreakpoint */
enum enPerformanceMonitorBreakpointTypes
{
    PMBP_Data = 0,
    PMBP_Inst = 1
};


/* Values for EventControl */
enum enPerformanceMonitorEventControlItems
{
    PMEC_Timer           = 0x8001,
    PMEC_MasterInterrupt = 0x8002
};

/* Tag items for EventControl */
#define PMECT_Disable (TAG_USER + 1)
#define PMECT_Enable  (TAG_USER + 2)

#endif
