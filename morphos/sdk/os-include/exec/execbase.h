#ifndef EXEC_EXECBASE_H
#define EXEC_EXECBASE_H

/*
	exec include (V50)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef EXEC_INTERRUPTS_H
# include <exec/interrupts.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef EXEC_TASKS_H
# include <exec/tasks.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif



#pragma pack(2)

#define CPUTBSTACKTRACECOUNT  16
struct ExecBase
{
	struct Library       LibNode;
	UWORD                SoftVer;
	WORD                 LowMemChkSum;
	ULONG                ChkBase;
	APTR                 ColdCapture;
	APTR                 CoolCapture;
	APTR                 WarmCapture;
	APTR                 SysStkUpper;
	APTR                 SysStkLower;
	ULONG                MaxLocMem;
	APTR                 DebugEntry;
	APTR                 DebugData;
	APTR                 AlertData;
	APTR                 MaxExtMem;
	UWORD                ChkSum;
	struct IntVector     IntVects[16];

	struct Task         *ThisTask;

	volatile ULONG       IdleCount;
	ULONG                DispCount;
	UWORD                Quantum;
	UWORD                Elapsed;
	volatile UWORD       SysFlags;
	BYTE                 IDNestCnt;
	BYTE                 TDNestCnt;

	UWORD                AttnFlags;

	volatile UWORD       AttnResched;
	APTR                 ResModules;
	APTR                 TaskTrapCode;
	APTR                 TaskExceptCode;
	APTR                 TaskExitCode;
	ULONG                TaskSigAlloc;
	UWORD                TaskTrapAlloc;

	struct List          MemList;
	struct List          ResourceList;
	struct List          DeviceList;
	struct List          IntrList;
	struct List          LibList;
	struct List          PortList;
	struct List          TaskReady;
	struct List          TaskWait;
	struct SoftIntList   SoftInts[5];

	LONG                 LastAlert[4];
	UBYTE                VBlankFrequency;
	UBYTE                PowerSupplyFrequency;
	struct List          SemaphoreList;
	APTR                 KickMemPtr;
	APTR                 KickTagPtr;
	APTR                 KickCheckSum;
	UWORD                ex_Pad0;
	ULONG                ex_LaunchPoint;
	APTR                 ex_RamLibPrivate;
	ULONG                ex_EClockFrequency;
	ULONG                ex_CacheControl;
	ULONG                ex_TaskID;

/* New ABox Emulation Entries
 */
	ULONG                ex_EmulHandleSize;	/* PPC EmulHandleSize..*private* */
	struct MsgPort      *ex_PPCTrapMsgPort;	/* PPC ABox Exception MsgPort..*private* */
	ULONG                ex_Reserved1[3];

	APTR                 ex_MMULock;

	APTR                 ex_PatchPool;	/* PatchPool Ptr needed by SetFunction..*private* */
	APTR                 ex_PPCTaskExitCode;	/* PPC Task exit function */
	ULONG                ex_DebugFlags;	/* Exec Debug Flags..*private* */

	struct MinList       ex_MemHandlers;
	APTR                 ex_MemHandler;

};

/*
 * Outdated 68k cpu informations
 *
 */
#define AFB_68010   0
#define AFB_68020   1
#define AFB_68030   2
#define AFB_68040   3
#define AFB_68881   4
#define AFB_68882   5
#define AFB_FPU40   6
#define AFB_68060   7
#define AFB_PRIVATE 15

#define AFF_68010   (1 << AFB_68010)
#define AFF_68020   (1 << AFB_68020)
#define AFF_68030   (1 << AFB_68030)
#define AFF_68040   (1 << AFB_68040)
#define AFF_68881   (1 << AFB_68881)
#define AFF_68882   (1 << AFB_68882)
#define AFF_FPU40   (1 << AFB_FPU40)
#define AFF_68060   (1 << AFB_68060)
#define AFF_PRIVATE (1 << AFB_PRIVATE)

/*
 * Outdated 68k cache functionality
 * Mostly without function.
 */

#define CACRF_EnableI       (1 << 0)
#define CACRF_FreezeI       (1 << 1)
#define CACRF_ClearI        (1 << 3)
#define CACRF_IBE           (1 << 4)
#define CACRF_EnableD       (1 << 8)
#define CACRF_FreezeD       (1 << 9)
#define CACRF_ClearD        (1 << 11)
#define CACRF_DBE           (1 << 12)
#define CACRF_WriteAllocate (1 << 13)
#define CACRF_EnableE       (1 << 30)
#define CACRF_CopyBack      (1 << 31)

#define DMA_Continue        (1 << 1)
#define DMA_NoModify        (1 << 2)
#define DMA_ReadFromRAM     (1 << 3)

#define SB_SAR  15
#define SB_TQE  14
#define SB_SINT 13

#define SF_SAR  (1 << SB_SAR)
#define SF_TQE  (1 << SB_TQE)
#define SF_SINT (1 << SB_SINT)

/****** Debug Flags...(don't depend on them) **********/

#define EXECDEBUGF_INITRESIDENT     0x1UL
#define EXECDEBUGF_INITCODE         0x2UL
#define EXECDEBUGF_FINDRESIDENT     0x4UL

#define EXECDEBUGF_CREATELIBRARY    0x10UL
#define EXECDEBUGF_SETFUNCTION      0x20UL
#define EXECDEBUGF_NEWSETFUNCTION   0x40UL
#define EXECDEBUGF_CHIPRAM          0x80UL

#define EXECDEBUGF_ADDTASK          0x100UL
#define EXECDEBUGF_REMTASK          0x200UL
#define EXECDEBUGF_GETTASKATTR      0x400UL
#define EXECDEBUGF_SETTASKATTR      0x800UL

#define EXECDEBUGF_EXCEPTHANDLER    0x1000UL
#define EXECDEBUGF_ADDDOSNODE       0x2000UL
#define EXECDEBUGF_PCI              0x4000UL
#define EXECDEBUGF_RAMLIB           0x8000UL

#define EXECDEBUGF_NOLOGSERVER      0x10000UL
#define EXECDEBUGF_NOLOGWINDOW      0x20000UL

/*
 * "env:MorphOS/LogPath" contains the logfile path,
 * If not specified it's using "ram:.morphoslog"
 */
#define EXECDEBUGF_LOGFILE          0x40000UL
#define EXECDEBUGF_LOGKPRINTF       0x80000UL


/* Memory Tracking Flags
 */

#define EXECDEBUGF_PERMMEMTRACK     0x100000UL
#define EXECDEBUGF_MEMTRACK         0x200000UL


/* CyberGuardPPC Flags
 */

#define EXECDEBUGF_CYBERGUARDDEADLY 0x400000UL

/*
 * extended logserver output flag
 */
#define EXECDEBUGF_LOGEXTENDED      0x800000UL


/* PPCLib Flags
 */

#define EXECDEBUGF_LOADSEG          0x01000000UL
#define EXECDEBUGF_UNLOADSEG        0x02000000UL
#define EXECDEBUGF_PPCSTART         0x04000000UL


/* UserFlags
 */

/*
 * Enables debug output for cybergraphx
 */
#define EXECDEBUGF_CGXDEBUG         0x08000000UL

/*
 * CyberGuard Zeropage protection
 */
#define EXECDEBUGF_INVZEROPAGE      0x10000000UL

/*
 * Should be used to control user LibInit/DevInit Debug output
 */
#define EXECDEBUGF_INIT             0x40000000UL

/*
 * Should be used to control logging
 */
#define EXECDEBUGF_LOG              0x80000000UL


/*
 * Execbase list IDs
 */
#define EXECLIST_DEVICE         0
#define EXECLIST_INTERRUPT      1
#define EXECLIST_LIBRARY        2
#define EXECLIST_MEMHANDLER     3
#define EXECLIST_MEMHEADER      4
#define EXECLIST_PORT           5
#define EXECLIST_RESOURCE       6
#define EXECLIST_SEMAPHORE      7
#define EXECLIST_TASK           8

/*
 * **** dos.library/RunCommand hook ****
 *
 * - Hook Object is BPTR seglist.
 * - ExecNotifyMessage.Extra points to:
 *   struct RunCommandExtra {
 *       BPTR        seglist;
 *       ULONG       stacksize;
 *       STRPTR      argptr;
 *       ULONG       argsize;
 *   };
 * - Before seglist is executed EXECNOTIFYF_POST is not set.
 * - After seglist execution is done EXECNOTIFYF_POST is set.
 * - EXECNOTIFYF_REMOVE has no meaning and is never set.
 */
#define EXECNOTIFY_RUNCOMMAND   9

/*
 * Execnotify hook message
 */
struct ExecNotifyMessage
{
	ULONG           Type;
	ULONG           Flags;
	ULONG           Extra;
	struct TagItem *Extension;
};

#define EXECNOTIFYF_REMOVE      (1 << 0)	/* if clear, is ADD */
#define EXECNOTIFYF_POST        (1 << 1)	/* if clear, is PRE */

/*
 * AddExecNodeTagList tags
 */
#define SAL_Dummy       (TAG_USER + 1000)
#define SAL_Type        (SAL_Dummy + 1)
#define SAL_Priority    (SAL_Dummy + 2)
#define SAL_Name        (SAL_Dummy + 3)



#pragma pack()

#endif
