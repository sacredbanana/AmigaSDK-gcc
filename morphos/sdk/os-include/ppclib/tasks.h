#ifndef POWERUP_PPCLIB_TASKS_H
#define POWERUP_PPCLIB_TASKS_H

/**************************************************
 *
 *
 *              PPCCreateTask() Tags
 *
 *
 **************************************************/

#define	PPCTASKTAG_DUMMY	(TAG_USER + 0x20000)

/* ElfObject which discribes the PPC program
 * Needed to start one.
 */
#define	PPCTASKTAG_ELFOBJECT	(PPCTASKTAG_DUMMY + 0x1)

/* Name of the new Task. */
#define	PPCTASKTAG_NAME		(PPCTASKTAG_DUMMY + 0x2)

/* First Argument..gpr3 */
#define	PPCTASKTAG_ARG1		(PPCTASKTAG_DUMMY + 0x3)

/* First Argument..gpr4 */
#define	PPCTASKTAG_ARG2		(PPCTASKTAG_DUMMY + 0x4)

/* First Argument..gpr5 */
#define	PPCTASKTAG_ARG3		(PPCTASKTAG_DUMMY + 0x5)

/* First Argument..gpr6 */
#define	PPCTASKTAG_ARG4		(PPCTASKTAG_DUMMY + 0x6)

/* First Argument..gpr7 */
#define	PPCTASKTAG_ARG5		(PPCTASKTAG_DUMMY + 0x7)

/* First Argument..gpr8 */
#define	PPCTASKTAG_ARG6		(PPCTASKTAG_DUMMY + 0x8)

/* First Argument..gpr9 */
#define	PPCTASKTAG_ARG7		(PPCTASKTAG_DUMMY + 0x9)

/* First Argument..gpr10 */
#define	PPCTASKTAG_ARG8		(PPCTASKTAG_DUMMY + 0xa)

/* Default=TRUE means that the cacheflush is handled automaticly
 * You need cacheflushs when you use OS functions to share data.
 * If you know it better than the stupid cacheflush routine you
 * can handle that yourself and optimize your routines.
 */

#define	PPCTASKTAG_CACHEFLUSH	(PPCTASKTAG_DUMMY + 0xb)

/* Ptr to an ULONG Errorfield where a better error description
 * can be stored.
 */

#define	PPCTASKTAG_ERROR	(PPCTASKTAG_DUMMY + 0xc)

/* PPC Stacksize...Default 8192
 * Supported by PowerUP's PPCGetTaskAttr() (V45)
 */
#define	PPCTASKTAG_STACKSIZE	(PPCTASKTAG_DUMMY + 0xd)

/* Task Priority..Default 0 */
#define	PPCTASKTAG_PRIORITY	(PPCTASKTAG_DUMMY + 0xe)

/* Input Handle..Default Open("Nil:")
 * The handle is closed when the PPC task completes
 */
#define	PPCTASKTAG_INPUTHANDLE	(PPCTASKTAG_DUMMY + 0xf)

/* Output Handle..Default Open("Nil:")
 * The handle is closed when the PPC task completes
 */
#define	PPCTASKTAG_OUTPUTHANDLE	(PPCTASKTAG_DUMMY + 0x10)

/* Error Handle..Default Open("Nil:")
 * The handle is closed when the PPC task completes
 */
#define	PPCTASKTAG_ERRORHANDLE	(PPCTASKTAG_DUMMY + 0x11)

/*
 * When you set this Tag the Task is stopped
 * before the first instruction is executed
 * Only useful for debuggers
 */
#define	PPCTASKTAG_STOPTASK	(PPCTASKTAG_DUMMY + 0x12)

/* ExceptionHook
 * The M68k Hook is called when a PPC TaskObject gets an
 * exception which can be processor or software(Kernel Msg)
 * related.
 * That`s the way the ppc.library calls the Hook:
 *
 * BOOL CallHookPkt(hook,TaskObject,ExceptionMsg);
 *
 * The Hook Function is NOT allowed to call PPCLibBase
 * functions to avoid deadlocks.
 * And after the Hook function returns the ExceptionMsg
 * contents IS NOT valid anymore.
 * So you should copy the ExceptionMsg contents to a private
 * buffer and then signal your debugger control task about
 * the event.
 * The Hook return BOOL should tell the ppc.library if all
 * worked fine.
 */

#define	PPCTASKTAG_EXCEPTIONHOOK	(PPCTASKTAG_DUMMY + 0x13)


/* If you want that the PPCTask gets a MsgPort you can tell
 * PPCCreateTask by a TRUE that you want one.
 * I made this optional because it may cause an initial speed
 * loss if you only need a ppc task for a quick run job where
 * the init latency may be a serious issue.
 * Supported by PowerUP's PPCGetTaskAttr()
 */
#define	PPCTASKTAG_MSGPORT		(PPCTASKTAG_DUMMY + 0x14)

/* If you wanna provide the ppc a startup msg. This msg will
 * be replied by the ppc.library after the PPC Task ends so
 * you can use this to know that the PPCTask is gone so a
 * PPCUnloadObject() is save now.
 * Supported by PowerUP's PPCGetTaskAttr()
 */
#define	PPCTASKTAG_STARTUP_MSG		(PPCTASKTAG_DUMMY + 0x15)

/* The Data field for the PPCMessage
 * Supported by PowerUP's PPCGetTaskAttr()
 */
#define	PPCTASKTAG_STARTUP_MSGDATA	(PPCTASKTAG_DUMMY + 0x16)
/* The Length field for the PPCMessage
 * Supported by PowerUP's PPCGetTaskAttr()
 */
#define	PPCTASKTAG_STARTUP_MSGLENGTH	(PPCTASKTAG_DUMMY + 0x17)
/* The MsgID field for the PPCMessage
 * Supported by PowerUP's PPCGetTaskAttr()
 */
#define	PPCTASKTAG_STARTUP_MSGID	(PPCTASKTAG_DUMMY + 0x18)
/* The flag to activate the CTRL-C;D;E;F gateway to
 * the PPC Task by PPCSignalTask();
 */
#define	PPCTASKTAG_BREAKSIGNAL		(PPCTASKTAG_DUMMY + 0x19)


/* The CPU number the task should start on.
 * This is only a hint and no gurantee.
 */
#define	PPCTASKTAG_CPUHINT		(PPCTASKTAG_DUMMY + 0x1a)

/* Ptr to ixemul UserData
 * ONLY supported by PowerUP's PPCGetTaskAttr(),PPCSetTaskAttr()
 */
#define	PPCTASKTAG_EXTUSERDATA		(PPCTASKTAG_DUMMY + 0x1b)



/* Run Task Synchron Flag which means that the PPCCreateTask
 * doesn`t return until the task completes and the return
 * value is not the TaskObject but the Task`s return value.
 * To check if the task runned correctly check out the
 * PPCTASKTAG_ERROR fieldptr.
 * With this Tag you can do the same what the old RunTaskObject
 * does which interface is a bit limited(compatibility to the
 * first ppc.library version)
 */

#define	PPCTASKTAG_WAITFINISH	(PPCTASKTAG_DUMMY + 0x31)

/* 
 * PPCTASKTAG_ERROR types
 */

#define	ERROR_OK		0
#define	ERROR_MEMORY		1
#define	ERROR_NOPC		2
#define	ERROR_CREATEMSGINTASK	3
#define	ERROR_INPUTHANDLE	4
#define	ERROR_OUTPUTHANDLE	5
#define	ERROR_ERRORHANDLE	6




/**************************************************
 *
 *
 * PPCGetTaskAttrs(), PPCSetTaskAttrs() Tags
 *
 *
 **************************************************/

/*
 * V45 adds the ti_Data data Set/Get passing if it`s possible
 */


#define	PPCTASKINFOTAG_DUMMY		(TAG_USER + 0x21000)
/* (Get) */
#define	PPCTASKINFOTAG_NAME		(PPCTASKINFOTAG_DUMMY + 0x1)
/* (Get/Set) */
#define	PPCTASKINFOTAG_PRIORITY		(PPCTASKINFOTAG_DUMMY + 0x2)
/* (Get/Set) */
#define	PPCTASKINFOTAG_CACHEFLUSH	(PPCTASKINFOTAG_DUMMY + 0x3)
/* (Get) */
#define	PPCTASKINFOTAG_STACKSIZE	(PPCTASKINFOTAG_DUMMY + 0x4)
/* (Get) */
#define	PPCTASKINFOTAG_STATE		(PPCTASKINFOTAG_DUMMY + 0x5)
/* (Get/Set) */
#define	PPCTASKINFOTAG_TASK		(PPCTASKINFOTAG_DUMMY + 0x6)

/* This means the HOOK function is called for every Task */
#define	PPCTASKINFOTAG_ALLTASK		(PPCTASKINFOTAG_DUMMY + 0x7)

/* Hook function which is called for a task so you can ask special fields
 * you may want to use.
 * Msg Parameter is NULL for now.
 * Object Parameter is the TaskObject
 *
 *    HookFunc(Hook, TaskObject, NULL)
 */
#define	PPCTASKINFOTAG_HOOK		(PPCTASKINFOTAG_DUMMY + 0x8)

/* (Get) */
#define	PPCTASKINFOTAG_SIGALLOC		(PPCTASKINFOTAG_DUMMY + 0x9)
/* (Get) */
#define	PPCTASKINFOTAG_SIGWAIT		(PPCTASKINFOTAG_DUMMY + 0xa)
/* (Get) */
#define	PPCTASKINFOTAG_SIGRECVD		(PPCTASKINFOTAG_DUMMY + 0xb)
/* (Get) */
#define	PPCTASKINFOTAG_USEDSTACKSIZE	(PPCTASKINFOTAG_DUMMY + 0xc)
/* (Get/Set) */
#define	PPCTASKINFOTAG_INPUTHANDLE	(PPCTASKINFOTAG_DUMMY + 0xd)
/* (Get/Set) */
#define	PPCTASKINFOTAG_OUTPUTHANDLE	(PPCTASKINFOTAG_DUMMY + 0xe)
/* (Get/Set) */
#define	PPCTASKINFOTAG_ERRORHANDLE	(PPCTASKINFOTAG_DUMMY + 0xf)

/* Return the ElfObject of a Task
 * (Get)
 * (V45)
 */

#define	PPCTASKINFOTAG_ELFOBJECT	(PPCTASKINFOTAG_DUMMY + 0x10)

/* See equal PPCTASKTAG_EXCEPTIONHOOK
 * (V45)
 * (Set)
 */

#define	PPCTASKINFOTAG_EXCEPTIONHOOK		(PPCTASKINFOTAG_DUMMY + 0x11)

/* Tell the task to stop at the first instruction.
 * Only allowed to be used when you get a TaskHookMsg
 * with the MethodID PPCTASKHOOKMETHOD_CREATE.
 * It must not be called while a PPC Task runs.
 * (V45)
 * (Set)
 */
#define	PPCTASKINFOTAG_STOPTASK			(PPCTASKINFOTAG_DUMMY + 0x12)


/* See equal PPCTASKTAG_MSGPORT
 * (V45)
 */
#define	PPCTASKINFOTAG_MSGPORT			(PPCTASKINFOTAG_DUMMY + 0x13)

/* See equal PPCTASKTAG_STARTUP_MSG
 * (V45)
 */
#define	PPCTASKINFOTAG_STARTUP_MSG		(PPCTASKINFOTAG_DUMMY + 0x14)

/* See equal PPCTASKTAG_STARTUP_MSGDATA
 * (V45)
 */
#define	PPCTASKINFOTAG_STARTUP_MSGDATA		(PPCTASKINFOTAG_DUMMY + 0x15)

/* See equal PPCTASKTAG_STARTUP_MSGLENGTH
 * (V45)
 */
#define	PPCTASKINFOTAG_STARTUP_MSGLENGTH	(PPCTASKINFOTAG_DUMMY + 0x16)

/* See equal PPCTASKTAG_STARTUP_MSGID
 * (V45)
 */
#define	PPCTASKINFOTAG_STARTUP_MSGID		(PPCTASKINFOTAG_DUMMY + 0x17)


/*
 * All Register Tags only accept Ptrs at ti_Data so I don`t have to
 * change the API when there`s a 64Bit PPC some time.
 */

/* SRR0=PC
 * Get/Set through ti_Data or PPCTASKINFOTAG_VALUEPTR
 * (Get/Set)
 */
#define	PPCTASKINFOTAG_PC		(PPCTASKINFOTAG_DUMMY + 0x20)

/* SRR1=MSR
 * Get/Set through ti_Data or PPCTASKINFOTAG_VALUEPTR
 * (Get/Set)
 */
#define	PPCTASKINFOTAG_MSR		(PPCTASKINFOTAG_DUMMY + 0x21)

/* 32bit value in function Result
 * Get/Set through ti_Data
 * (Get/Set)
 */
#define	PPCTASKINFOTAG_CR		(PPCTASKINFOTAG_DUMMY + 0x22)

/* 32bit value in function Result
 * Get/Set through ti_Data
 * (Get/Set)
 */
#define	PPCTASKINFOTAG_XER		(PPCTASKINFOTAG_DUMMY + 0x23)

/* Result by PPCTASKINFOTAG_VALUEPTR
 * Get/Set through ti_Data or PPCTASKINFOTAG_VALUEPTR
 * (Get/Set)
 */
#define	PPCTASKINFOTAG_LR		(PPCTASKINFOTAG_DUMMY + 0x24)

/* Result by PPCTASKINFOTAG_VALUEPTR
 * Get/Set through ti_Data or PPCTASKINFOTAG_VALUEPTR
 * (Get/Set)
 */
#define	PPCTASKINFOTAG_CTR		(PPCTASKINFOTAG_DUMMY + 0x25)

/* Result by PPCTASKINFOTAG_VALUEPTR
 * Get/Set through ti_Data or PPCTASKINFOTAG_VALUEPTR
 * (Get/Set)
 */
#define	PPCTASKINFOTAG_FPSCR		(PPCTASKINFOTAG_DUMMY + 0x26)

/* ti_Data=Register Number
 * Get/Set through PPCTASKINFOTAG_VALUEPTR
 * (Get/Set)
 */
#define	PPCTASKINFOTAG_GPR		(PPCTASKINFOTAG_DUMMY + 0x30)

/* ti_Data=Register Number
 * Get/Set through PPCTASKINFOTAG_VALUEPTR
 * (Get/Set)
 */
#define	PPCTASKINFOTAG_FPR		(PPCTASKINFOTAG_DUMMY + 0x31)

/* Address where to read/write the register value from.
 * I use a ptr to be size indepent with the registers
 * (Get/Set)
 */
#define	PPCTASKINFOTAG_VALUEPTR		(PPCTASKINFOTAG_DUMMY + 0x32)


/* With PPCTASKINFOTAG_WAITFINISHTASK
 * it returns the parent process in which you created
 * a synchron PPC Task. Synchron PPC Task`s are created
 * with the PPCTASKTAG_WAITINFISH,TRUE or outdated a
 * PPCRunObject.
 * The reason for this function is to find the shell
 * task easily and check for a CTRL-C for example.
 * (Get)
 * (V45)
 */
#define	PPCTASKINFOTAG_WAITFINISHTASK	(PPCTASKTAG_DUMMY + 0x33)



/**************************************************
 *
 *
 *           TaskObject ExceptionHook
 *
 *
 **************************************************/


struct	ExceptionMsg
{
	ULONG			Version;
	ULONG			Type;
	ULONG			GPR[32];
	DOUBLE			FPR[32];
	ULONG			SR[16];
	ULONG			CR;
	DOUBLE			FPSCR;
	ULONG			XER;
	ULONG			LR;
	ULONG			CTR;
	ULONG			PVR;
	ULONG			IBAT0U;
	ULONG			IBAT0L;
	ULONG			IBAT1U;
	ULONG			IBAT1L;
	ULONG			IBAT2U;
	ULONG			IBAT2L;
	ULONG			IBAT3U;
	ULONG			IBAT3L;

	ULONG			DBAT0U;
	ULONG			DBAT0L;
	ULONG			DBAT1U;
	ULONG			DBAT1L;
	ULONG			DBAT2U;
	ULONG			DBAT2L;
	ULONG			DBAT3U;
	ULONG			DBAT3L;

	ULONG			SDR1;
	ULONG			ASR;

	ULONG			DAR;
	ULONG			DSISR;
	ULONG			SRR0;
	ULONG			SRR1;

	ULONG			SPRG0;
	ULONG			SPRG1;
	ULONG			SPRG2;
	ULONG			SPRG3;

	ULONG			TBL;
	ULONG			TBU;
	ULONG			DEC;
	ULONG			DABR;

	/* 603 special registers */

	ULONG			DMISS;
	ULONG			DCMP;
	ULONG			HASH1;
	ULONG			HASH2;
	ULONG			IMISS;
	ULONG			ICMP;
	ULONG			RPA;

	/* 604e special registers */

	/* Version 0 ends here */

	ULONG			MSR;

	/* Version 1 ends here */

	/* Size depends on Version */
};

/* Current supported Version
 */

#define	EXCEPTIONMSG_VERSION	1

/*
 * Current supported Types
 */

/*
 * These are the processor exceptions
 */

#define	EXCEPTION_UNKNOWN		0	/* Won`t happen */
#define	EXCEPTION_RESET			1	/* Won`t happen */
#define	EXCEPTION_MACHINECHECK		2	/* Won`t happen */
#define	EXCEPTION_DATAACCESS		3
#define	EXCEPTION_INSTRUCTIONACCESS	4
#define	EXCEPTION_EXTERNALINTERRUPT	5	/* Won`t happen */
#define	EXCEPTION_ALIGNMENT		6
#define	EXCEPTION_PROGRAM		7
#define	EXCEPTION_FPUUNAVAILABLE	8
#define	EXCEPTION_DECREMENTER		9
#define	EXCEPTION_INTERFACEERROR	10
#define	EXCEPTION_RESERVED_B		11
#define	EXCEPTION_SYSTEMCALL		12
#define	EXCEPTION_TRACE			13
#define	EXCEPTION_FPUASSIST		14
#define	EXCEPTION_RESERVED_F		15
#define	EXCEPTION_IMISS			16
#define	EXCEPTION_DLOADMISS		17
#define	EXCEPTION_DSTOREMISS		18
#define	EXCEPTION_IADDRESSBREAK		19
#define	EXCEPTION_SYSTEMMANAGEMENTINT	20


/*
 * These are the kernel exceptions
 * to signal certain events
 */

#define	EXCEPTION_MSG			0x80000000

/*
 * You receive this exception type
 * when the Kernel could stop a Task
 * successfully after a Stop or Trace
 * operation.
 * Look at PPCTASKTAG_STOPTASK for example
 */

#define	EXCEPTION_STOPTASK		(EXCEPTION_MSG + 0x0)

/*
 * You receive this exception type
 * when the task completes.
 * In this case the ONLY valid fields in the
 * ExceptionMsg are the Version field and the
 * the Message type.
 */

#define	EXCEPTION_FINISHTASK		(EXCEPTION_MSG + 0x1)


/**************************************************
 *
 *
 *              PPCStartTask() Tags
 *
 *
 **************************************************/

#define	PPCTASKSTARTTAG_DUMMY		(TAG_USER + 0x22000)

/* Just run a Task again
 * ti_Data=BOOL
 */
#define	PPCTASKSTARTTAG_RUN		(PPCTASKSTARTTAG_DUMMY + 0x0)

/* Single Step the next instruction
 * ti_Data=BOOL
 */
#define	PPCTASKSTARTTAG_TRACE		(PPCTASKSTARTTAG_DUMMY + 0x1)

/* Branch until a Trace instruction
 * Processor dependent
 * ti_Data=BOOL
 * NOT SUPPORTED YET
 */
#define	PPCTASKSTARTTAG_BRANCHTRACE	(PPCTASKSTARTTAG_DUMMY + 0x2)

/* Run until Instruction hit
 * the Breakpoint Address
 * Processor dependent
 * ti_Data=BOOL
 * NOT SUPPORTED YET
 */
#define	PPCTASKSTARTTAG_IBREAK		(PPCTASKSTARTTAG_DUMMY + 0x3)

/* Run until DataAccess hit
 * the Breakpoint Address
 * Processor dependent
 * ti_Data=BOOL
 * NOT SUPPORTED YET
 */
#define	PPCTASKSTARTTAG_DBREAK		(PPCTASKSTARTTAG_DUMMY + 0x4)

#endif
