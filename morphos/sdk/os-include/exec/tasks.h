#ifndef EXEC_TASKS_H
#define EXEC_TASKS_H

/*
	exec task definitions (V51)

	Copyright © 2002-2020 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_NODES_H
# include <exec/nodes.h>
#endif

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#pragma pack(2)


struct ETask;

struct Task
{
	struct Node    tc_Node;
	UBYTE          tc_Flags;
	UBYTE          tc_State;
	BYTE           tc_IDNestCnt;
	BYTE           tc_TDNestCnt;
	ULONG          tc_SigAlloc;
	ULONG          tc_SigWait;
	ULONG          tc_SigRecvd;
	ULONG          tc_SigExcept;
#if 0
	UWORD          tc_TrapAlloc;
	UWORD          tc_TrapAble;
#else
	struct ETask  *tc_ETask;
#endif
	APTR           tc_ExceptData;
	APTR           tc_ExceptCode;
	APTR           tc_TrapData;
	APTR           tc_TrapCode;
	APTR           tc_SPReg;
	APTR           tc_SPLower;
	APTR           tc_SPUpper;
	VOID         (*tc_Switch)(VOID);        /*** OBSOLETE ***/
	VOID         (*tc_Launch)(VOID);        /*** OBSOLETE ***/
	struct List    tc_MemEntry;
	APTR           tc_UserData;
};

/*
 * Please use these macros in the future to declare, define and reference
 * task codestarts. That way we can easily change the way SysBase is passed
 * to a task to avoid ABSEXECBASE.
 *
 * ABOX_TASKPROTO(void,TaskStart,void *);
 * ABOX_TASK(void,TaskStart,void *Arg1)
 * {
 *    ABOX_DEFTASKSYSBASE;
 * }
 *
 * NewCreateTask(TASKTAG_PC,ABOX_TASKREF(TaskStart),TASKTAG_PPC_ARG1,Arg1,...,TAG_DONE);
 */
#define	ABOX_TASKREF(n)			n##_start
#define	ABOX_TASKPROTO(t,n,...)	t n##_start(__VA_ARGS__)
#define	ABOX_TASK(t,n,...)		t n##_start(__VA_ARGS__)
#define ABOX_GETTASKSYSBASE		MyEmulHandle->SuperHandle->GlobalSysBase
#define ABOX_DEFTASKSYSBASE		struct ExecBase *SysBase=ABOX_GETTASKSYSBASE

#define TB_PROCTIME     0
#define TB_ETASK        3
#define TB_STACKCHK     4
#define TB_EXCEPT       5
#define TB_SWITCH       6
#define TB_LAUNCH       7

#define TF_PROCTIME     (1 << TB_PROCTIME)
#define TF_ETASK        (1 << TB_ETASK)
#define TF_STACKCHK     (1 << TB_STACKCHK)
#define TF_EXCEPT       (1 << TB_EXCEPT)
#define TF_SWITCH       (1 << TB_SWITCH)
#define TF_LAUNCH       (1 << TB_LAUNCH)

#define TS_INVALID      0
#define TS_ADDED        1
#define TS_RUN          2
#define TS_READY        3
#define TS_WAIT         4
#define TS_EXCEPT       5
#define TS_REMOVED      6

#define SIGB_ABORT      0
#define SIGB_CHILD      1
#define SIGB_BLIT       4
#define SIGB_SINGLE     4
#define SIGB_INTUITION  5
#define SIGB_NET        7
#define SIGB_DOS        8

#define SIGF_ABORT      (1 << SIGB_ABORT)
#define SIGF_CHILD      (1 << SIGB_CHILD)
#define SIGF_BLIT       (1 << SIGB_BLIT)
#define SIGF_SINGLE     (1 << SIGB_SINGLE)
#define SIGF_INTUITION  (1 << SIGB_INTUITION)
#define SIGF_NET        (1 << SIGB_NET)
#define SIGF_DOS        (1 << SIGB_DOS)


struct TaskTrapMessage
{
	struct Message  Message;        /* Message Header */
	struct Task    *Task;           /* connected Task */
	ULONG           Version;        /* version of the structure */
	ULONG           Type;           /* Exception Type */
	ULONG           DAR;            /* Exception Address Register */
	ULONG           DSISR;          /* Exception DSISR Reg */

	/* This is undiscovered land...
	 * never assume a size of this structure
	 */
};

#define VERSION_TASKTRAPMESSAGE  0x0

/* Added in exec 50.67 */
/*
 * Exec has now a more sophisticated 68k(emulation) trap management.
 * In reality it's just a new system wide traphandler who sends logserver
 * the msg and if this msg is replied it uses the new emulation state.
 */
struct TaskTrapMessage_68k
{
	struct Message          Message;        /* Message Header */
	struct Task             *Task;          /* connected Task */
	ULONG                   Version;        /* version of the structure */
	ULONG                   Type;           /* Exception Type */
	ULONG                   Format;         /* Exception Stackframe Format */
	void                    *Address;       /* Hit Address */
	ULONG                   FLSW;
	struct EmulHandle       *MyEmulHandle;
};

#define VERSION_TASKTRAPMESSAGE_68K     0x0


struct ETask
{
	struct Message          Message;
	struct Task            *Parent;
	ULONG                   UniqueID;
	struct MinList          Children;
	UWORD                   TrapAlloc;
	UWORD                   TrapAble;
	ULONG                   Result1;
	void                   *Result2;
	struct MsgPort          MsgPort;

	/* Don't touch!!!!!!!!!..there'll be an interface
	 * sooner than later.
	 * New Entries...most of the above entries
	 * are only there for structure compatability.
	 * They have no meaning as the OS never supported
	 * them.
	 */

	/* A Task Pool for the task.
	 */
	void                   *MemPool;

	/* PPC's Stack Lower Ptr
	 * The initial stack is allocated through
	 * AllocVec, so a FreeVec(ETask->PPCSPLower);
	 * would work.
	 * If you use PPCStackSwap you must allocate
	 * your stack block with AllocVec();
	 */
	void                   *PPCSPLower;

	/* PPC's Stack Upper Ptr
	 */
	void                   *PPCSPUpper;
	void                   *PPCRegFrame;
	void                   *PPCLibData;

	/* On a PPC exception this msgport
	 * is sent an exception msg....
	 * the task is stopped until somebody
	 * wakes it up again.
	 * (asynchron exception interface)
	 * If this Port is NULL the message is
	 * sent to SysBase->ex_PPCTrapMsgPort.
	 */
	struct MsgPort         *PPCTrapMsgPort;
	struct TaskTrapMessage *PPCTrapMessage;

	/* This is undiscovered land...
	 * never assume a size of this structure
	 */
};

struct TaskInitExtension
{
	/* Must be filled with TRAP_PPCTASK
	*/
	UWORD           Trap;
	UWORD           Extension;      /* Must be set to 0 */
	struct TagItem *Tags;
};

#define TASKTAG_DUMMY           (TAG_USER + 0x100000)

/* Ptr to an ULONG Errorfield where a better error description
 * can be stored.
 */
#define TASKTAG_ERROR           (TASKTAG_DUMMY + 0x0)

/* Code type
 * can be stored.
 */
#define TASKTAG_CODETYPE        (TASKTAG_DUMMY + 0x1)

/* Start PC
 * code must be of TASKTAG_CODETYPE
 */
#define TASKTAG_PC              (TASKTAG_DUMMY + 0x2)

/* Final PC
 * code must be of TASKTAG_CODETYPE
 */
#define TASKTAG_FINALPC         (TASKTAG_DUMMY + 0x3)

/* Stacksize...Default 8192
 */
#define TASKTAG_STACKSIZE       (TASKTAG_DUMMY + 0x4)

/* Std Stacksize...
 * Default(use the stack defined by tc_SPLower..tc_SPUpper)
 */
#define TASKTAG_STACKSIZE_M68K  (TASKTAG_DUMMY + 0x5)

/*
 * specify task name, name is copied
 */
#define TASKTAG_NAME            (TASKTAG_DUMMY + 0x6)

/*
 * tc_UserData
*/
#define TASKTAG_USERDATA        (TASKTAG_DUMMY + 0x7)

/*
 * Task priority
 */
#define TASKTAG_PRI             (TASKTAG_DUMMY + 0x8)

/* 
 * Pool's Puddlesize
 */
#define TASKTAG_POOLPUDDLE      (TASKTAG_DUMMY + 0x9)

/* 
 * Pool's ThreshSize
 */
#define TASKTAG_POOLTHRESH      (TASKTAG_DUMMY + 0xa)


/* PPC First Argument..gpr3
 */
#define TASKTAG_PPC_ARG1        (TASKTAG_DUMMY + 0x10)

/* PPC First Argument..gpr4
 */
#define TASKTAG_PPC_ARG2        (TASKTAG_DUMMY + 0x11)

/* PPC First Argument..gpr5
 */
#define TASKTAG_PPC_ARG3        (TASKTAG_DUMMY + 0x12)

/* PPC First Argument..gpr6
 */
#define TASKTAG_PPC_ARG4        (TASKTAG_DUMMY + 0x13)

/* PPC First Argument..gpr7
 */
#define TASKTAG_PPC_ARG5        (TASKTAG_DUMMY + 0x14)

/* PPC First Argument..gpr8
 */
#define TASKTAG_PPC_ARG6        (TASKTAG_DUMMY + 0x15)

/* PPC First Argument..gpr9
 */
#define TASKTAG_PPC_ARG7        (TASKTAG_DUMMY + 0x16)

/* PPC First Argument..gpr10
 */
#define TASKTAG_PPC_ARG8        (TASKTAG_DUMMY + 0x17)



/*
 * Startup message to be passed to task/process, ReplyMsg'd at RemTask()
 * ti_Data: struct Message *
 */
#define TASKTAG_STARTUPMSG      (TASKTAG_DUMMY + 0x18)

/*
 * Create internal MsgPort for task/process, deleted at RemTask()
 * ti_Data: struct MsgPort **, can be NULL
 */
#define TASKTAG_TASKMSGPORT     (TASKTAG_DUMMY + 0x19)

/*
 * Set unitial tc_Flags
 * ti_Data: UBYTE
 */
#define TASKTAG_FLAGS           (TASKTAG_DUMMY + 0x1a)


/*
 * Extra memory to allocate after task structure, the extra memory is
 * cleared
 * ti_Data: ULONG
 */
#define TASKTAG_TCBEXTRASIZE    (TASKTAG_DUMMY + 0x1c)




#define CODETYPE_M68K  0x0
/*
 * System V4 ABI
 */
#define CODETYPE_PPC   0x1


#define TASKERROR_OK        0
#define TASKERROR_NOMEMORY  1


/*
 * Stack swap structure as passed to StackSwap() and PPCStackSwap()
 */
struct StackSwapStruct
{
	APTR  stk_Lower;        /* Lowest byte of stack */
	ULONG stk_Upper;        /* Upper end of stack (size + Lowest) */
	APTR  stk_Pointer;      /* Stack pointer at switch point */
};

struct PPCStackSwapArgs
{
	ULONG Args[8];          /* The C register arguments from gpr3..gpr11 */
};



/*
 * NewGetTaskAttrsA(),  NewSetTaskAttrsA() tags
 */

#define TASKINFOTYPE_ALLTASK            0x0
#define TASKINFOTYPE_NAME               0x1
#define TASKINFOTYPE_PRI                0x2
#define TASKINFOTYPE_TYPE               0x3
#define TASKINFOTYPE_STATE              0x4
#define TASKINFOTYPE_FLAGS              0x5
#define TASKINFOTYPE_SIGALLOC           0x6
#define TASKINFOTYPE_SIGWAIT            0x7
#define TASKINFOTYPE_SIGRECVD           0x8
#define TASKINFOTYPE_SIGEXCEPT          0x9
#define TASKINFOTYPE_EXCEPTDATA         0xa
#define TASKINFOTYPE_EXCEPTCODE         0xb
#define TASKINFOTYPE_TRAPDATA           0xc
#define TASKINFOTYPE_TRAPCODE           0xd
#define TASKINFOTYPE_STACKSIZE_M68K     0xe
#define TASKINFOTYPE_STACKSIZE          0xf
#define TASKINFOTYPE_USEDSTACKSIZE_M68K 0x10
#define TASKINFOTYPE_USEDSTACKSIZE      0x11
#define TASKINFOTYPE_TRAPMSGPORT        0x12
#define TASKINFOTYPE_STARTUPMSG         0x13
#define TASKINFOTYPE_TASKMSGPORT        0x14
#define TASKINFOTYPE_POOLPTR            0x15
#define TASKINFOTYPE_POOLMEMFLAGS       0x16
#define TASKINFOTYPE_POOLPUDDLESIZE     0x17
#define TASKINFOTYPE_POOLTHRESHSIZE     0x18

/*
 * Task Scheduler statistics (exec 50.42)
 */
#define TASKINFOTYPE_NICE                  0x19
#define TASKINFOTYPE_AGETICKS              0x1a
#define TASKINFOTYPE_CPUTIME               0x1b
#define TASKINFOTYPE_LASTSECCPUTIME        0x1c
#define TASKINFOTYPE_RECENTCPUTIME         0x1d
#define TASKINFOTYPE_VOLUNTARYCSW          0x1e
#define TASKINFOTYPE_INVOLUNTARYCSW        0x1f
#define TASKINFOTYPE_LASTSECVOLUNTARYCSW   0x20
#define TASKINFOTYPE_LASTSECINVOLUNTARYCSW 0x21
/* Added in exec 50.45 */
#define TASKINFOTYPE_LAUNCHTIMETICKS       0x22
#define TASKINFOTYPE_LAUNCHTIMETICKS1978   0x23
#define TASKINFOTYPE_PID_CLI               0x24
/* Added in exec 50.54 */
#define TASKINFOTYPE_SPLOWER               0x26
#define TASKINFOTYPE_SPUPPER               0x27
#define TASKINFOTYPE_SPLOWER_M68K          0x28
#define TASKINFOTYPE_SPUPPER_M68K          0x29
#define TASKINFOTYPE_NAMECOPY              0x2a
/*
 * Get/Set task tc_UserData
 *     Data: ULONG start
 * DataSize: sizeof(ULONG)
 * Added in exec 50.63
 */
#define TASKINFOTYPE_USERDATA           0x2b
/*
 * Tag used to restart a suspended task
 *     Data: ULONG start
 * DataSize: sizeof(ULONG)
 * Set 'start' to nonzero to really start the task.
 * Returns sizeof(ULONG) if suspended task was successfully restarted.
 * NOTE: The task will get run immediately if it has higher priority
 * than the caller and the task switching has not been disabled.
 * Added in exec 50.63
 */
#define TASKINFOTYPE_RESURRECT_TASK     0x2c
/*
 * Get/Set task emulhandle
 *     Data: APTR emulhandle
 * DataSize: sizeof(APTR)
 * Added in exec 50.63
 */
#define TASKINFOTYPE_EMULHANDLE         0x2d
/*
 * Get task exception count
 *     Data: ULONG count
 * DataSize: sizeof(ULONG)
 * Added in exec 50.67
 */
#define TASKINFOTYPE_EXCEPTIONCOUNT     0x2e
/*
 * Get task hit count
 *     Data: ULONG count
 * DataSize: sizeof(ULONG)
 * Added in exec 50.67
 */
#define TASKINFOTYPE_HITCOUNT           0x2f
/*
 * Get/Set task max hit count.
 * If more hits happen the task is put to sleep.
 *     Data: ULONG count
 * DataSize: sizeof(ULONG)
 * Added in exec 51.3
 */
#define TASKINFOTYPE_MAXHITCOUNT        0x30
/*
 * Get task alert count
 *     Data: ULONG count
 * DataSize: sizeof(ULONG)
 * Added in exec 51.13
 */
#define TASKINFOTYPE_ALERTCOUNT         0x31
/*
 * Get/Set task max alert count.
 * If more alerts happen the task is put to sleep.
 *     Data: ULONG count
 * DataSize: sizeof(ULONG)
 * Added in exec 51.13
 */
#define TASKINFOTYPE_MAXALERTCOUNT      0x32

/*
 * Get task unique ID.
 * This ID is unique to every task.
 *     Data: ULONG id
 * DataSize: sizeof(ULONG)
 * Added in exec 51.14
 */
#define TASKINFOTYPE_PID                0x33


#define TASKINFOTYPE_68K_NEWFRAME       0x50

#define TASKINFOTYPE_PPC_SRR0           0x100
#define TASKINFOTYPE_PPC_SRR1           0x101
#define TASKINFOTYPE_PPC_LR             0x102
#define TASKINFOTYPE_PPC_CTR            0x103
#define TASKINFOTYPE_PPC_CR             0x104
#define TASKINFOTYPE_PPC_XER            0x105
#define TASKINFOTYPE_PPC_GPR            0x106
#define TASKINFOTYPE_PPC_FPR            0x107
#define TASKINFOTYPE_PPC_FPSCR          0x108
#define TASKINFOTYPE_PPC_VSCR           0x109
#define TASKINFOTYPE_PPC_VPR            0x10a
#define TASKINFOTYPE_PPC_VSAVE          0x10b
#define TASKINFOTYPE_PPC_FRAME          0x10c
#define TASKINFOTYPE_PPC_FRAMESIZE      0x10d
#define TASKINFOTYPE_PPC_NEWFRAME       0x10e

#define TASKINFOTAG_DUMMY       (TAG_USER + 0x110000)
/* Used with TASKINFOTYPE_ALLTASK
 */
#define TASKINFOTAG_HOOK        (TASKINFOTAG_DUMMY + 0x0)
/* Used with TASKINFOTYPE_PPC_GPR,TASKINFOTYPE_PPC_FPR,TASKINFOTYPE_PPC_VMX
 * to define the copy area
 */
#define TASKINFOTAG_REGSTART    (TASKINFOTAG_DUMMY + 0x1)
/* Used with TASKINFOTYPE_PPC_GPR,TASKINFOTYPE_PPC_FPR,TASKINFOTYPE_PPC_VMX
 * to define the copy area
 */
#define TASKINFOTAG_REGCOUNT    (TASKINFOTAG_DUMMY + 0x2)

/*
 * NewSetTaskAttrsA(..,&TaskFrame68k,sizeof(struct TaskFrame68k),TASKINFOTYPE_68K_NEWFRAME,...);
 *
 */
struct TaskFrame68k
{
	void  *PC;
	UWORD  SR;
	ULONG  Xn[15];
};


/*
 * Don't depend on these
 */
#define DEFAULT_PPCSTACKSIZE  32768
#define DEFAULT_M68KSTACKSIZE  2048
#define DEFAULT_TASKPUDDLESIZE 4096
#define DEFAULT_TASKTHRESHSIZE 4096

#define PID_CURRENT     0


/*
 * TLSAlloc (V51.46)
 */
#define TLS_INVALID_INDEX       (0xffffffff)

#define TLSTAG_DUMMY            (TAG_USER + 0x120000)
/* Destructor function to call on task termination if the TLS value
 * is non-NULL. The function is called with as:
 * VOID function(APTR value, APTR userdata);
 */
#define TLSTAG_DESTRUCTOR       (TLSTAG_DUMMY + 0x0)
/* Userdata for the destructor function. Defaults to NULL.
 */
#define TLSTAG_USERDATA         (TLSTAG_DUMMY + 0x1)


#pragma pack()

#endif
