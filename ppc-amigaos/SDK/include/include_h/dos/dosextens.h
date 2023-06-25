#ifndef DOS_DOSEXTENS_H
#define DOS_DOSEXTENS_H
/*
**    $VER: dosextens.h  54.103 (17.02.2021)
**
**    DOS structures not needed for the casual AmigaDOS user
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef EXEC_TASKS_H
#include <exec/tasks.h>
#endif
#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif
#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

#ifndef DOS_DOS_H
#include <dos/dos.h>
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
/* All DOS processes have this structure */

/* Notes for V50 DOS:-
 *
 * BCPL programs are no longer supported from V50 onwards,
 * if a BCPL program is launched, it will halt with a dead-end requester.
 *
 * Old BCPL register values & members marked as "do not access" must NOT be
 * accessed or assumed to contain any values whatsoever, they may even be 
 * intensionally reused in the future for completely incompatible purposes,
 * these are guaranteed to have indeterminant contents that can and will 
 * change without any notice.  So be warned !!!  Leave these alone.
 *
 * PRIVATE structure members should not be accessed by applications when
 * there is an API accessor function mentioned, use those instead. 
 * 
 * Most importantly, do not attempt to allocate these structures yourself,
 * they are guaranteed to grow and change in the future.
 */

struct Process
{
    /* original definitions from version 1.0 and earlier betas (v30 - 1984) */
    struct Task     pr_Task;           /* The exec task structure for this process */
    struct MsgPort  pr_MsgPort;        /* This process' message port structure */
    uint16          pr_Size;           /* Size of struct from V51.08+, previously 0 */
    BPTR            pr_SegArray;       /* -- PRIVATE - dos GetProcSegList() use only. */
    uint32          pr_StackSize;      /* The running process stack size, in bytes */
    int32           pr_gv;             /* -- OBSOLETE BCPL value - do not access this. */
    uint32          pr_CliNum;         /* CLI number, for DOS allocated cli processes. */
    BPTR            pr_sb;             /* -- OBSOLETE BCPL value - do not access this. */
    int32           pr_Result2;        /* Secondary result from last call, for IoErr() */
    BPTR            pr_CurrentDir;     /* Lock associated with current directory  */
    BPTR            pr_CIS;            /* Current Input Stream - See; Input() */
    BPTR            pr_COS;            /* Current Output Stream - See; Output() */
    struct MsgPort *pr_ConsolePort;    /* Console handler port, See; GetConsolePort() */
    struct MsgPort *pr_FileSystemPort; /* Filesystem for current drive, See; GetFileSysPort()*/
    BPTR            pr_CLI;            /* BCPL Ptr to struct CommandLineInterface, See; Cli()*/
    APTR            pr_ra;             /* -- OBSOLETE - do not access this. */
    APTR          (*pr_PktWait)();     /* Function to be called when awaiting packet */
    APTR            pr_WindowPtr;      /* Window for posting error requesters */

    /* following definitions are new with 2.0 (v36 - 1990) */
    BPTR            pr_ProgramDir;     /* Program's home directory lock, See; GetProgramDir() */
    uint32          pr_Flags;          /* Flags telling dos about this process */
    VOID          (*pr_ExitCode)();    /* Code to call on exit of process or NULL */
    int32           pr_ExitData;       /* Argument for pr_ExitCode func. See; GetExitData() */
    STRPTR          pr_Arguments;      /* Arguments passed to the process at start, See; GetArgStr() */
    struct MinList  pr_LocalVars;      /* Local environment variables */
    uint32          pr_ShellPrivate;   /* -- PRIVATE - Internal shell use only. */
    BPTR            pr_CES;            /* ErrorOutput() stream - If 0, use Output(). */

    /* following definitions are new from 4.0 (v50 - Apr,2004) */
    APTR            pr_PrData;         /* -- PRIVATE - internal dos access ONLY. */
    BPTR            pr_CurrentSeg;     /* Seglist of current running code. See; GetProcSegList() */
    uint32          pr_EmulPrivate;    /* -- PRIVATE - Flags for 68k JIT Emulator. */
    uint32          pr_68kPrivate;     /* -- PRIVATE - 68K control opts, OS access only */
    uint32          pr_ParentID;       /* ID# of parent process, 0 if a task, for GetPID() */
    uint32          pr_ProcessID;      /* ID# for this process, for GetPID() */
    uint32          pr_Reserved4;      /* -- reserved for dos expansion - leave alone */
    APTR            pr_OGLContextData; /* -- PRIVATE - ogl access only. */
    APTR            pr_Reserved5;      /* -- reserved for dos expansion - leave alone. */
    APTR            pr_CLibData;       /* -- PRIVATE - clib/newlib use, copied by CNP() */
    APTR            pr_Reserved6;      /* -- reserved for dos expansion - leave alone  */

    /* following definitions are new from (v51 - Jan,2006) */
    struct MinList  pr_RestoreList;    /* -- PRIVATE - used by DOS for process cleanup() */
    APTR            pr_DeathSigTask;   /* Process/task to signal when the process ends */
    uint32          pr_DeathSigBit;    /* Signal bit number for pr_DeathSigTask */
    APTR            pr_DeathMessage;   /* DeathMessage to ReplyMsg() to when process ends */
    VOID          (*pr_EntryCode)();   /* Code to call on startup of process, or NULL   */
    int32           pr_EntryData;      /* Passed as an argument to pr_EntryCode func. See; GetEntryData() */
    VOID          (*pr_FinalCode)();   /* Code to call on exit of the process, or NULL  */
    int32           pr_FinalData;      /* Passed as an argument to pr_FinalCode func.   */
	uint32          pr_DLNotifyData;   /* -- PRIVATE - dos NotifyDosListChange() data.  */
    uint32          pr_PLNotifyData;   /* -- PRIVATE - dos NotifyProcListChange() data. */

    /* following definitions are new from (v52 - Dec,2006) */
    uint32          pr_UID;            /* -- PRIVATE - dos Set/GetOwnerInfo() use only. */
    uint32          pr_GID;            /* -- PRIVATE - dos Set/GetOwnerInfo() use only. */
    int32           pr_Reserved3;      /* -- reserved for dos expansion - leave alone */
    int32           pr_Reserved2;      /* -- reserved for dos expansion - leave alone */
    int32           pr_Reserved1;      /* -- reserved for dos expansion - leave alone */
    int32           pr_Reserved0;      /* -- reserved for dos expansion - leave alone */
};
/* Process - 344 bytes */




/*
 * Flags for Process->pr_Flags for all DOS processes.
 * These bits control how the process works and also provide
 * statistical and historical information about the process
 * to allow other subsystems to interact appropriately.
 */
#define PRB_FREESEGLIST         0   /* NP_FreeSegList,TRUE sets this bit. */
#define PRB_FREECURRDIR         1   /* NP_CurrentDir will be UnLocked if set */
#define PRB_FREECLI             2   /* NP_Cli will be freed if this is set. */
#define PRB_CLOSEINPUT          3   /* NP_CloseInput,TRUE sets this bit. */
#define PRB_CLOSEOUTPUT         4   /* NP_CloseOutput,TRUE sets this bit.  */
#define PRB_FREEARGS_OBSOLETE   5   /* (V50) obsolete, args copy now on task memlist. */
#define PRB_CLOSEERROR          6   /* NP_CloseError,TRUE sets this bit. (V51) */
#define PRB_LOCKSTACK           7   /* NP_LockStack,TRUE sets this bit. (V52.10) */
#define PRB_spare08             8
#define PRB_spare09             9
#define PRB_spare10            10
#define PRB_spare11            11
#define PRB_spare12            12
#define PRB_spare13            13
#define PRB_spare14            14
#define PRB_spare15            15

#define PRB_spare16            16
#define PRB_spare17            17
#define PRB_spare18            18
#define PRB_spare19            19
#define PRB_spare20            20
#define PRB_spare21            21
#define PRB_spare22            22
#define PRB_WAITINGFORCHILD    23   /* (V54) WaitForChildExit() sets this while waiting. */
#define PRB_CHILDPROCESS       24   /* (V50) NP_Child,TRUE sets this for a dependant child. */
#define PRB_HADCHILDREN        25   /* (V51) Gets set if this process had created any children. */
#define PRB_HASDLNOTIFY        26   /* (V51) Set when doslist change signal notify is enabled. */
#define PRB_HASPLNOTIFY        27   /* (V51) Set when process list change signal notify is on. */
#define PRB_SERVERPROCESS      28   /* (V53) Set when process is one of the dos servers */
#define PRB_HANDLERPROCESS     29   /* (V52) Set to indicate if this is a handler/filesystem process */
#define PRB_SHELLPROCESS       30   /* (V51) Set to indicate if this is a shell handler process */
#define PRB_EXTENDED_FLAGS     31   /* (V51) Reserved for dos flags expansion use only. */


/* Mask definitions for above bits */
#define PRF_FREESEGLIST        (1 << PRB_FREESEGLIST)
#define PRF_FREECURRDIR        (1 << PRB_FREECURRDIR)
#define PRF_FREECLI            (1 << PRB_FREECLI)
#define PRF_CLOSEINPUT         (1 << PRB_CLOSEINPUT)
#define PRF_CLOSEOUTPUT        (1 << PRB_CLOSEOUTPUT)
#define PRF_FREEARGS_OBSOLETE  (1 << PRB_FREEARGS_OBSOLETE)
#define PRF_CLOSEERROR         (1 << PRB_CLOSEERROR)
#define PRF_LOCKSTACK          (1 << PRB_LOCKSTACK)    

#define PRF_WAITINGFORCHILD    (1 << PRB_WAITINGFORCHILD)
#define PRF_CHILDPROCESS       (1 << PRB_CHILDPROCESS)
#define PRF_HADCHILDREN        (1 << PRB_HADCHILDREN)
#define PRF_HASDLNOTIFY        (1 << PRB_HASDLNOTIFY)
#define PRF_HASPLNOTIFY        (1 << PRB_HASPLNOTIFY)
#define PRF_SERVERPROCESS      (1 << PRB_SERVERPROCESS)
#define PRF_HANDLERPROCESS     (1 << PRB_HANDLERPROCESS)
#define PRF_SHELLPROCESS       (1 << PRB_SHELLPROCESS)
#define PRF_EXTENDED_FLAGS     (1 << PRB_EXTENDED_FLAGS)





/****************************************************************************/
/* The long word address (BPTR) of this structure is returned by
 * Open() and other routines that return a filehandle.
 *
 * This structure is effectively READ-ONLY outside of dos.library & handlers.
 * Do not assume the size of this structure, it will expand at any time.
 * Do not access private members, their function can change at any time.
 * Do not allocate these structures other than through the DOS API,
 *  otherwise they will =NOT= work anymore, as validation data is now present.
 */
#ifndef dos_filehandle

struct FileHandle
{
    uint16     fh_StructSize;     /* Size of DOS structure allocation.    */
    uint16     fh_Flags;          /* --Private DOS use only.              */

    int32      fh_Interactive;    /* BOOLEAN; True if interactive handle  */
    struct MsgPort *fh_MsgPort;   /* MsgPort of the filesystem/handler.   */

    BPTR       fh_Buf;            /* --Private Bufferered stream members. */
    int32      fh_Pos;
    int32      fh_End;

    APTR       fh_Func1;          /* --Private function pointers to the   */
    APTR       fh_Func2;          /*   DOS i/o routines.                  */
    APTR       fh_Func3;

    BPTR       fh_Arg1;           /* --Private, dospacket handler use.    */
    APTR       fh_Arg2;           /* --Private, FSVP handler use.         */

    uint32     fh_OpenerPID;      /* The process ID of the opener. V52.16 */
    uint32     fh_OpenTime;       /* Time (seconds) when opened. V54.62   */
    int32      fh_Reserved1;      /* public expansion, leave alone.       */

    uint32     fh_DOSPrivate[18]; /* --Private DOS library fields.        */
}; 
/* FileHandle - 128 bytes */

#endif /* dos_filehandle */




/****************************************************************************/
/*   This is the message structure returned from AsyncIO() - 54.76
 */

struct AsyncInfoMsg
{
    struct Message Msg;   /* Internal message structure.      */
    
    int32  IoErr;         /* DOS Error code on error.         */
    int64  Result;        /* Bytes transfered or -1 on error. */
    
    /* These are all set by the supplied tags, otherwise 0.   */
    APTR   UserData;      /* Userdata.                        */
    APTR   ExtraUserData; /* Extra Userdata.                  */
    APTR   Buffer;        /* Buffer pointer.                  */
    int32  Length;        /* Length to Read/Write.            */
    BPTR   ReadFH;        /* Read  Filehandle.                */
    BPTR   WriteFH;       /* Write Filehandle.                */
    BPTR   AbortFH;       /* Abort Filehandle.                */
    int32  Priority;      /* Async process priority.          */
    int64  *ResultPtr;    /* Result ptr.                      */
    int32  *IoErrPtr;     /* IoErr ptr.                       */
    uint32 NotifyUpdateTicks;      /* Update hook period.     */
    struct Hook *NotifyUpdateHook; /* Notify update hook.     */
    struct MsgPort *NotifyPort;    /* Notify end port.        */
    struct Hook *NotifyHook;       /* Notify end hook.        */
    int32  *NotifyFlag;            /* Notify end flag.        */
    int32  *NotifyCounter;         /* Notify counter.         */
    struct Hook *ReadHook;    /* Read() substitute hook.      */
    struct Hook *WriteHook;   /* Write() substitute hook.     */
    
    uint32 DOSPrivate[4]; /* DOS use only.                    */
    uint64 DOSInternal;   /* DOS use only.                    */
};
/* AsyncInfoMsg - 120 bytes */



/****************************************************************************/
/* This is the standard extension to EXEC Messages used by DOS 
 */

struct DosPacket
{
    struct Message *dp_Link;    /* EXEC message          */
    struct MsgPort *dp_Port;    /* Reply port for the packet, */
                                /* this must be filled in for each send. */

    int32           dp_Type;    /* See ACTION_... below */

    int32           dp_Res1;    /* For file system calls, this is the result
                                   that would have been returned by the
                                   function, e.g. Write() returns actual
                                   length written */

    int32           dp_Res2;    /* For file system calls, this is what will
                                   be returned by IoErr() */
    int32           dp_Arg1;
    int32           dp_Arg2;
    int32           dp_Arg3;
    int32           dp_Arg4;
    int32           dp_Arg5;
    int32           dp_Arg6;
    int32           dp_Arg7;
};
/* DosPacket - 48 bytes */

/*  Device packets common equivalents */
#define dp_Action   dp_Type
#define dp_Status   dp_Res1
#define dp_Status2  dp_Res2
#define dp_BufAddr  dp_Arg1

/* A Packet does not require the Message to be before it in memory,
 * but for convenience it is useful to associate the two. 
 */

struct StandardPacket
{
    struct Message      sp_Msg;
    struct DosPacket    sp_Pkt;
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



/* This is the extended 64 bit style EXEC Messages used by DOS.
 * Only dp_Type packets between 8000-8999 range use this structure.
 * NB: #pragma pack() used here to obtain default alignment padding.
 */

struct DosPacket64
{
    struct Message *dp_Link;    /* EXEC message                    */
    struct MsgPort *dp_Port;    /* Reply port for the packet,      */
                                /* must be filled in on each send. */
    int32           dp_Type;    /* See ACTION_... below            */
    int32           dp_Res0;    /* Special compatibility field. [See below] */

    int32           dp_Res2;    /* This is returned for IoErr()    */
    int64           dp_Res1;    /* This is the 64 bit primary result */

    int32           dp_Arg1;    /* 32 bit argument */
    int64           dp_Arg2;    /* 64 bit argument */
    int32           dp_Arg3;    /* 32 bit argument */
    int32           dp_Arg4;    /* 32 bit argument */
    int64           dp_Arg5;    /* 64 bit argument */
};
/* DosPacket64 - 64 bytes */

/*--------------------------------------------------------------------------*/
/* NOTE: Old style handlers may not be prepared for this new dospacket,     */
/* so when sending these, dp_Res0 must be initialised to DP64_INIT.         */
/* This is used as a test value to differentiate unsupporting handlers.     */
/* This must be initialised for every send, just like the dp_Port member.   */
/*                                                                          */
/* DosPacket64 supporting handlers must NEVER touch the dp_Res0 member.     */
/*                                                                          */
/* Upon receiving the dospacket back, dp_Res0 MUST still equal DP64_INIT.   */
/* If this packet is returned by a non-supporting handler, this member will */
/* have been overwritten with some other value,  that value will actually   */
/* be the old 32 bit value corresponding to the 32 bit dospackets primary   */
/* result1 code and should be used as such.                                 */
/* dp_Res2 will always be the secondary error code regardless of support.   */
/*                                                                          */
/* The following test is required by the sender for the replied dospacket.  */
/*                                                                          */
/*   if( DP64_INIT == dp->dp_Res0 )                                         */
/*       result1 = dp->dp_Res1;          // supporting handler result.      */
/*   else                                                                   */
/*       result1 = (int64) dp->dp_Res0;  // un-supporting handler result.   */
/*                                                                          */
/*   result2 = dp->dp_Res2;              // always secondary error code.    */
/*--------------------------------------------------------------------------*/

struct StandardPacket64
{
    struct Message      sp_Msg;
    struct DosPacket64  sp_Pkt;
};


/* The DosPacket64 dp_Res0 member initialisation value. */
#define DP64_INIT       -3L




/****************************************************************************/
/* DEPRECATED PACKET TYPES; these must NOT be supported by new handlers or  */
/* filesystems from DOS release 53.87+  the respective functions are now    */
/* emulated by DOS using the new 3000 series (EXAMINEDATA) and the          */
/* 8000 series (64 BIT) packets and/or vector-port calls,                   */
/* your handler should only support those.                                  */
/*                                                                          */
/* Filesystems and handlers may still get probed by these old packets when  */
/* an old application calls a deprecated function, but you should only      */
/* return a primary result of 0 and a secondary result2 value set to the    */
/* error; ERROR_ACTION_NOT_KNOWN  so the DOS emulator will be invoked.      */
/*                                                                          */
/* For vector-port based filesystems, the DOSPacket emulator vector will    */
/* take care of all deprecated and probe dospackets for you.                */
/*                                                                          */
/* Note: ACTION_SEEK and ACTION_SET_FILE_SIZE will also accept -1 or 0 as   */
/*       the primary result code, providing the secondary result code is    */
/*       set to; ERROR_ACTION_NOT_KNOWN.                                    */
/*                                                                          */
/****************************************************************************/

#define ACTION_EXAMINE_OBJECT    23    /* DEPRECATED */
#define ACTION_EXAMINE_NEXT      24    /* DEPRECATED */
#define ACTION_SEEK            1008    /* DEPRECATED */
#define ACTION_SET_FILE_SIZE   1022    /* DEPRECATED */
#define ACTION_EXAMINE_ALL     1033    /* DEPRECATED */
#define ACTION_EXAMINE_FH      1034    /* DEPRECATED */
#define ACTION_EXAMINE_ALL_END 1035    /* DEPRECATED */
#define ACTION_SET_OWNER       1036    /* DEPRECATED */





/****************************************************************************/
/* Standard Packet types */

#define ACTION_NIL                0
#define ACTION_STARTUP            0
#define ACTION_EVENT              6     /* INTERNAL for CDFS and CrossDos commodity */
#define ACTION_CURRENT_VOLUME     7     /* DEPRECATED from DOS 53.100+ */   
#define ACTION_LOCATE_OBJECT      8
#define ACTION_RENAME_DISK        9
#define ACTION_FREE_LOCK         15
#define ACTION_DELETE_OBJECT     16
#define ACTION_RENAME_OBJECT     17
#define ACTION_MORE_CACHE        18     /* For IDOS->AddBuffers(), hardly anything uses it now. */
#define ACTION_COPY_LOCK         19
#define ACTION_WAIT_CHAR         20
#define ACTION_SET_PROTECT       21
#define ACTION_CREATE_DIR        22
#define ACTION_HANDLER_INFO      25     /* replaces ACTION_DISK_INFO definition */
#define ACTION_INFO              26
#define ACTION_FLUSH             27
#define ACTION_SET_COMMENT       28
#define ACTION_PARENT            29
#define ACTION_TIMER             30     /* INTERNAL */
#define ACTION_INHIBIT           31

#define ACTION_SET_DATE          34
#define ACTION_SAME_LOCK         40
#define ACTION_SAME_FH           53     /* Added 53.71 */

#define ACTION_READ              82     /* 'R' */
#define ACTION_WRITE             87     /* 'W' */

#define ACTION_SINGLE_CHARACTER_MODE  994
#define ACTION_CHANGE_SIGNAL     995

/* 3 Internal packets used by con-handler  */
#define ACTION_READ_RETURN       1001   /* INTERNAL con-handler */
#define ACTION_WRITE_RETURN      1002   /* INTERNAL con-handler */
#define ACTION_INT_WRITE_RETURN  1003   /* INTERNAL con-handler */

#define ACTION_FINDUPDATE        1004   /* aka MODE_READWRITE */
#define ACTION_FINDINPUT         1005   /* aka MODE_OLDFILE   */
#define ACTION_FINDOUTPUT        1006   /* aka MODE_NEWFILE   */
#define ACTION_END               1007

#define ACTION_ICONIFY           1009   /* INTERNAL */

#define ACTION_FORMAT            1020
#define ACTION_MAKE_LINK         1021
#define ACTION_WRITE_PROTECT     1023
#define ACTION_READ_SOFT_LINK    1024
#define ACTION_FH_FROM_LOCK      1026
#define ACTION_IS_FILESYSTEM     1027
#define ACTION_CHANGE_MODE       1028
#define ACTION_COPY_LOCK_FH      1030
#define ACTION_PARENT_FH         1031

/* Added V52.18 - SetOwnerInfo() - replaces old SetOwner() packet 1036. */
#define ACTION_SET_OWNER_INFO    1037

/* Internal packets used by dospacket based datatypes.library filehandler */
#define ACTION_NEWMEMFILE        1039   /* INTERNAL */
#define ACTION_NEWMEMLOCK        1040   /* INTERNAL */

/* New packet types for V50 */
#define ACTION_WAIT_FOR_DATA     1998
#define ACTION_SET_BLOCKING_MODE 1999


/*###########################################################################*/
/*  PACKETS 2050-2999 are reserved for use by third party applications.      */
/*###########################################################################*/


/****************************************************************************/
/* Similar functionality to ACTION_DIE, which was never properly documented.
   This replacement causes supporting filesystems to relinquish all active
   locks to the dos lockhandler process, remove the volume node (if added),
   and then end the filesystem process itself. 
   See; DismountDevice() for extensive information. (V51) */
#define ACTION_SHUTDOWN             3000

/* The following action exclusively controls the relinquishing of active
   filesystem objects to the dos lockhandler, the object identifer value
   (see below) is placed in dp_Arg1, the object is placed in dp_Arg2.
   The dp_Arg2 argument is always an APTR to the object being collected. */
#define ACTION_COLLECT              3001

/* The following are the ACTION_COLLECT object identifiers (in dp_Arg1)
   to identify the object that is placed in dp_Arg2. */
#define ID_COLLECT_LOCK                1
#define ID_COLLECT_FILEHANDLE          2
#define ID_COLLECT_NOTIFICATION        3


/****************************************************************************/

/* Obtain or Set filesystem specific attributes; FileSystemAttr()  51.46  */
#define ACTION_FILESYSTEM_ATTR        3005

/* Obtain information on a console window; you must pass an APTR to a
   'struct ConsoleWindowData' in dp_Arg1 and sizeof(struct ConsoleWindowData)
   in dp_Arg2; dp_Res1 will indicate success or failure. */
#define ACTION_OBTAIN_CON_INFO        3006

/* Release console information, as obtained through ACTION_OBTAIN_CON_INFO;
   you must pass the same parameters as with ACTION_OBTAIN_CON_INFO. */
#define ACTION_RELEASE_CON_INFO       3007

/* Packets for ExamineObject() and ExamineDir() functions. 51.104 */
#define ACTION_EXAMINEDATA            3030
#define ACTION_EXAMINEDATA_FH         3031   /* added @ 52.30 */
#define ACTION_EXAMINEDATA_OBJ        3032   /* added @ 54.54 */
#define ACTION_EXAMINEDATA_DIR        3040


/* DOS will emulate notifications from 52.33+ if you do not support these */ 
#define ACTION_ADD_NOTIFY             4097   /* optional */
#define ACTION_REMOVE_NOTIFY          4098   /* optional */


/* Tell a file system to serialize the current volume. This is typically
   done by changing the creation date of the disk. The date change MUST at least
   be reflected in the datestamp of the doslist volume node.
   This packet does not take any arguments.
   NOTE: be prepared to handle failure of this packet for V37 ROM filesystems. */
#define ACTION_SERIALIZE_DISK         4200


/* Obtain a disk's geometry data (struct FileSysStartupMsg) from a
   file system. This must be released again with ACTION_FREE_DISK_FSSM
   when no longer needed.  (V50: see function GetDiskFileSystemData() ) 
   NOTE: If this packet is unsupported by the handler, DOS will emulate
         this functionality by using startup data from the device node. */
#define ACTION_GET_DISK_FSSM          4201   /* DEPRECATED */

/* Release the disk's geometry data obtained through ACTION_GET_DISK_FSSM.
   (V50: see function FreeDiskFileSystemData() ) */
#define ACTION_FREE_DISK_FSSM         4202   /* DEPRECATED */


/* New dospacket to control dos.library long path handling code. (@ v53.23)
 * This dospacket has been introduced to be able to formally control the 
 * behaviour of the internal dos.library long path name handling code.
 *
 * When a dospacket based filesystem responds with DOSTRUE to this query,
 * which is only sent when dos.library encounters a long path name string
 * longer than 255 bytes, dos.library will inhibit the use of its internal
 * long path handling code and pass the full length string to the filesystem.
 * This string will be in the form of a nul-terminated extended BSTR. (XBSTR)
 *
 * If your filesystem is unprepared for extended BSTR's &/or path strings
 * longer than 255 bytes, then you must return FALSE to this dospacket.
 *
 * This dospacket is not used with Vector-Port based filesystems or
 * DOS handlers that do not identify as a filesystem.
 */ 
#define ACTION_INHIBIT_DOS_LONGPATH_HANDLING   5323


/****************************************************************************/
/* 64 Bit ACTION types, ONLY the 8000 series use struct DosPacket64.  51.62 */

#define ACTION_CHANGE_FILE_POSITION64  8001
#define ACTION_GET_FILE_POSITION64     8002
#define ACTION_CHANGE_FILE_SIZE64      8003
#define ACTION_GET_FILE_SIZE64         8004

#define ACTION_LOCK_RECORD64           8010   /* added 53.86 */
#define ACTION_FREE_RECORD64           8011   /* added 53.86 */

/*############################################################################*/
/* 64 bit PACKETS 8500-8999 are reserved for use by third party applications. */
/*############################################################################*/


/****************************************************************************/
/* These were used to convert UID & GID to/from names in usergroup.library. */

#define ACTION_USERNAME_TO_UID   20000
#define ACTION_GROUPNAME_TO_GID  20001
#define ACTION_UID_TO_USERINFO   20002
#define ACTION_GID_TO_GROUPINFO  20003







/****************************************************************************/
/* Data structure used by ACTION_OBTAIN_CON_INFO/ACTION_RELEASE_CON_INFO */

struct ConsoleWindowData
{
    uint32          Reserved[4];   /* For use by the console handler */
    struct Window * ConsoleWindow; /* Pointer to console window; this
                                      may be NULL for console handlers
                                      which are not bound to a window,
                                      or if that window is currently
                                      closed. */
    struct IORequest * ConsoleIO;  /* Pointer to console.device I/O
                                      request; this may be NULL for
                                      console handlers which are not
                                      bound to a window, or if that
                                      window is currently closed. */
    uint32          ConsoleType;   /* Identifies the type of console,
                                      e.g. ID_RAWCON or ID_CON */

    APTR            DOSPrivate[2]; /* Private fields for use by DOS only */ 
};


/****************************************************************************/
/* The following are used by the new V50 Address Tracking functions */

struct AddressAndSize
{
    uint32  aas_Address;
    uint32  aas_Size;
};

struct FindTrackedAddressMsg
{
    uint32                ftam_Size;
    STRPTR                ftam_Name;
    struct DateStamp      ftam_Date;
    BPTR                  ftam_SegList;
    uint32                ftam_SegmentNumber;
    uint32                ftam_SegmentOffset;
    APTR                  ftam_ExtraInfo;
    int32                 ftam_ExtraInfoSize;
/* -- 40 bytes @ V50 */
    struct AddressAndSize ftam_AAS; 
/* -- 48 bytes @ 53.118 */
};


/****************************************************************************/
/* The following is used by the new V50 pattern functions */

struct CapturedExpression
{
    struct CapturedExpression *
                          cape_Next;
    STRPTR                cape_Match;
    STRPTR                cape_Start;
    STRPTR                cape_End;
    APTR                  cape_Pool;   /* private */
};

/****************************************************************************/
/* The public structure for PseudoSegLists which are used by RunCommand(),
   LoadSeg(), Create[new]Proc(), AllocSegList(), etc..  to handle new formats.
   ==DO NOT== create these yourself if you can call AllocSegList() to do so,
   there are members omitted here, like the int32 segment size in front,
   however, this structure declaration does provide the required minimum size,
   due to ps_Data[4] being included as part of the public size definition.

   WARNING:  Alignment padding may change in future for segment alignments
   greater than 32 bytes, so, avoid accessing members past ps_Ikey yourself,
   instead, call the function; IDOS->GetSegListInfoTags() to obtain any
   information about a seglist/segment.

   Do not expect any loaded object code or data to be actually present within
   a segment memory allocation, especially for native loadables, these may
   only store a reference to this information, use IDOS->GetSegListInfoTags()
   to obtain pointers and sizes of the actual loaded code/data sections.

   Refer to IDOS->AllocSegList() documentation for further details.
   Refer to IDOS->GetSegListInfo() to access information from any seglist.

   Failure to observe this warning can and likely will render your software
   partially or completely non-functional in future DOS releases.
*/

struct PseudoSegList
{
    BPTR    ps_Next;       /* BPTR   - Pointer to next segment. Or 0.       */
    uint32  ps_Jump;       /* uint32 - Internal compatibility magic.        */
    APTR    ps_Entry;      /* APTR   - The function entry pointer.          */
    uint32  ps_Ikey;       /* uint32 - Identification key.                  */
    uint32  ps_DosPrivate; /* uint32 - DOS Private use only.                */
    uint32  ps_Reserved1;  /* uint32 - Block alignment - reserved.          */
    uint32  ps_Reserved2;  /* uint32 - Block alignment - reserved.          */
    uint8   ps_Data[4];    /* uint8  - First 4 bytes of data area.          */
};


/* This value is always initialised in the ps_Jump member. (PPC & 68K)      */

#define PSJUMP_MAGIC	 0x4e714ef9UL	/* NOP,JMP - 68k compatibility      */



/* These are the currently used values for use in the ps_Ikey member.       */

#define PSIKEY_INIT      0UL
    /* Set this value for normal native, data or 68k types.                 */
    /* UnLoadSeg() will perform the normal memory freeing on these.         */

#define PSIKEY_NOFREE    0x80000000UL
    /* Set this value if your seglist must not be UnLoadSeg()'ed.           */
    /* Not for hand made segments, see PSIKEY_NFSYS below.                  */

#define PSIKEY_ELF32     0x7F454C46UL        /* 7F 'E' 'L' 'F'              */
    /* This is set EXCLUSIVELY by LoadSeg() for ELF32 executables.          */

#define PSIKEY_NFSYS     0xFFFFFFFFUL
    /* This is set EXCLUSIVELY by components such as filesystems that       */
    /* create a device segment by hand, usually for situations where DOS    */
    /* is unavailable, these segments can reside in the data area of        */
    /* loaded modules and must not be freed if they also happen to be       */
    /* inadvertently passed to UnLoadSeg().                                 */
    /*                                                                      */
    /* A hand-made PPC segment MUST have at least the following members     */
    /* initialised exactly as shown, to be recognised by DOS.               */
    /*                                                                      */
    /*     SegSize >= sizeof(struct PseudoSegList);  //@ -4 byte offset     */
    /*     ps_Next  = 0;                             //@  0 byte offset     */
    /*     ps_Jump  = PSJUMP_MAGIC;                  //@ +4 byte offset     */
    /*     ps_Entry = ((*)());     //Address of the executable code.        */
    /*     ps_Ikey  = PSIKEY_NFSYS;                                         */
    /*     ps_DosPrivate =0;                                                */
    /*     ps_Reserved1  =0;                                                */
    /*     ps_Reserved2  =0;                                                */
    /*                                                                      */
    /* NB: The segment MUST start on a longword multiple address            */
    /*     as it will be converted to a BCPL pointer at ps_Next. (BPTR).    */
    /*                                                                      */
    /*     Only single segments are allowed to be created this way.         */
    /*                                                                      */
    /*     The 'SegSize' value MUST be rounded up to a 4 byte multiple      */
    /*     otherwise it will not validate and will be rejected.             */
    /*                                                                      */
    /*     The SegSize MUST also represent the actual byte size of          */
    /*     the whole memory space that incorporates the pseudo segment.     */
    /*     This value is used for segment scanning purposes and must        */
    /*     include all space that may be used to contain a resident         */
    /*     structure, stack cookie, or a nul-terminated version string      */
    /*     formatted as;   "$VER: name ver.rev (dd.mm.yyyy)\r\n"            */
    /*     or any other data that needs to be included in the segment.      */
    /*     See also; dos/AllocSegList() for more information.               */


/****************************************************************************/
/* The structure for the DOS resident list.  Do NOT allocate these manually,
   use AddSegment[taglist]() instead and heed the warnings in the autodocs! 
   For legacy reasons, the name string is in BCPL format, but is NOT a BPTR.
   The BCPL format means that the first byte holds the strlen() of the
   following bytes, it is also nul-terminated to be interoperable with
   standard C-Strings.
*/

struct DosResidentSeg
{
    BPTR    seg_Next;     /* BCPL pointer to next DosResidentSeg, or zero */
    int32   seg_UC;       /* Use Count */
    BPTR    seg_Seg;      /* BCPL pointer to seglist of command. */
    uint8   seg_Name[4];  /* First 4 bytes of BCPL style formatted name. */
};

#define CMD_SYSTEM      -1
#define CMD_INTERNAL    -2
#define CMD_DISABLED    -999


/****************************************************************************/
/* DOS Processes started from the CLI via RUN or NEWCLI have this additional
   set of data associated with them */

struct CommandLineInterface
{
    int32  cli_Result2;        /* Value of IoErr from last command          */
    BSTR   cli_CurrentDirName; /* BSTR name of current directory            */
    BPTR   cli_PathList;       /* BPTR to the first 'struct PathNode'       */
    int32  cli_ReturnCode;     /* Return code from last command             */
    BSTR   cli_CommandName;    /* BSTR name of current command              */
    int32  cli_FailLevel;      /* Fail level (set by FAILAT)                */
    BSTR   cli_Prompt;         /* BSTR prompt string (set by PROMPT)        */
    BPTR   cli_StandardInput;  /* Default (terminal) CLI input stream       */
    BPTR   cli_CurrentInput;   /* Current CLI input stream                  */
    BSTR   cli_CommandFile;    /* BSTR name of EXECUTE command file         */
    int32  cli_Interactive;    /* Boolean; Truth if prompts required        */
    int32  cli_RunBackground;  /* Boolean; Truth if CLI created by 'RUN'    */
    BPTR   cli_CurrentOutput;  /* Current CLI output                        */
    uint32 cli_DefaultStack;   /* Stack size to be obtained in long words   */
    BPTR   cli_StandardOutput; /* Default (terminal) CLI output             */
    BPTR   cli_Module;         /* SegList of currently loaded command       */
};

#define  cli_Background  cli_RunBackground   /* synonym */




/****************************************************************************/
/* DosList structures can take on different values depending on whether it 
   is a device, an assignment, or a volume.  Below is the structure
   reflecting volumes only, following that is the structure representing
   only devices, following that is the structure for assignments, 
   then following that is the unioned structure representing all types. */

struct VolumeNode   /* VOLUME structure; vn_Type==DLT_VOLUME */
{
    BPTR             vn_Next;        /* BPTR to next entry in the chain     */
    int32            vn_Type;        /* always DLT_VOLUME for dos "volumes" */
    struct MsgPort * vn_Port;        /* msg port for the handler process    */
    int32            vn_Reserved2;   /* -- reserved for use by DOS          */
    struct DateStamp vn_VolumeDate;  /* creation (formatted) date           */
    BPTR             vn_LockList;    /* generally unused, leave as 0        */
    int32            vn_DOSType;     /* ie; 'DOS\7' - 32 bit hex dostype    */
    int32            vn_FSPrivate;   /* private filesystem use only         */
    BSTR             vn_Name;        /* bstr name                           */
    int32            vn_StructSize;  /* FULL size of this structure         */
    int32            vn_Reserved[4]; /* -- reserved for use by DOS          */
};

#define vn_DiskType  vn_DOSType  /* synonym */


/****************************************************************************/


struct DeviceNode   /* DEVICE structure; dn_Type==DLT_DEVICE */
{
    BPTR             dn_Next;        /* BPTR to next entry in the chain     */
    int32            dn_Type;        /* always DLT_DEVICE for dos "devices" */
    struct MsgPort * dn_Port;        /* msg port to the handler process.    */
    int32            dn_Reserved1;   /* -- reserved for use by DOS          */
    BSTR             dn_Handler;     /* BSTR name to loadseg if seglist==0  */
    int32            dn_StackSize;   /* stacksize for the handler process   */
    int32            dn_Priority;    /* task priority for handler process   */
    BPTR             dn_Startup;     /* startupstr / FileSysStartupMsg /int */
    BPTR             dn_SegList;     /* segment for the handler process.    */
                                     /* if 0 then dn_Handler will be loaded */
    int32            dn_GlobVec;     /* Global vector locking method key to */
                                     /* use when starting the handler proc. */
                                     /* A value of -1 is used for standard  */
                                     /* C startup locking method.           */
                                     /* Only values -1 & -2 are valid now.  */
    BSTR             dn_Name;        /* BSTR device node name.              */
    int32            dn_StructSize;  /* FULL size of this structure.        */
    int32            dn_Reserved[4]; /* -- reserved for use by DOS          */
};

/*
**  NOTE: Accessing dn_Startup field can be dangerous if you are unprepared
**        when scanning the doslist, take care and expect any of the following;
**        1) A value of zero. 
**        2) A simple integer <= 64 for some handlers.
**        3) A BSTR to a BCPL formatted string for handlers & some filesystems.
**        4) A BPTR to a struct FileSysStartupMsg for disk based filesystems.
**
*/

#define DN_STARTUP_MAXINT  64


/****************************************************************************/


struct MultiAssign      /* For normal DLT_LOCK and DLT_NONBINDING(v54) multi-assigns */
{
    struct MultiAssign  *ma_Next;    /* next MultiAssign in chain, or NULL */
    union
    {
        BPTR             ma_lock;    /*  for DLT_LOCK multi-assigns */
        STRPTR           ma_path;    /*  for DLT_NONBINDING multi-assigns (v54) */
    }
    dat;
};

/* Shortcuts for union reference */
#define ma_Lock   dat.ma_lock
#define ma_Path   dat.ma_path

/* alias */
#define ma_Name   dat.ma_path


struct AssignNode       /* ASSIGN struct; DLT_LOCK, DLT_LATE, DLT_NONBINDING */
{
    BPTR                 an_Next;              /* BPTR to next entry in the chain */
    int32                an_Type;              /* DLT_LOCK,DLT_LATE,DLT_NONBINDING */
    struct MsgPort *     an_Port;              /* Ptr to handler port for DLT_LOCK types. */
    BPTR                 an_Lock;              /* Primary lock for DLT_LOCK assignments */
    STRPTR               an_AssignPath;        /* Primary dest path for non/late binding assigns */
    struct MultiAssign  *an_MultiAssignList;   /* Chain of DLT_LOCK type multi-assigns */
    struct MultiAssign  *an_NBMultiAssignList; /* Chain of DLT_NONBINDING type multi-assigns */
    int32                an_Unused[3];         /* -- reserved for type expansion by DOS. */
    BSTR                 an_Name;              /* BSTR assignment node name.  */
    int32                an_StructSize;        /* FULL allocated size of this structure. */
    int32                an_Reserved[4];       /* -- reserved for use by DOS. */
};

/* alias */
#define an_AssignName  an_AssignPath


/****************************************************************************/


struct DosList      /* COMBINED structure for all types. */
{
    BPTR            dol_Next;     /* BPTR to next entry in the chain */
    int32           dol_Type;     /* See DLT below */
    struct MsgPort *dol_Port;     /* Ptr to handler process port */

    union
    {
      struct
      {
        int32   dol_Reserved1;    /* -- Reserved for use by DOS.                 */
        BSTR    dol_Handler;      /* BSTR file name to LoadSeg if dol_Seglist==0.*/
        int32   dol_StackSize;    /* Stacksize to use when starting process.     */
        int32   dol_Priority;     /* Task priority when starting process.        */
        BPTR    dol_Startup;      /* Startup msg: FileSysStartupMsg for disks.   */
        BPTR    dol_SegList;      /* Already loaded seglist for new process.     */
        int32   dol_GlobVec;      /* Global vector locking method key (-1 or -2) */
      } 
      dol_device;

      struct
      {
        int32   dol_Reserved2;    /* -- Reserved for use by DOS.               */
        struct  DateStamp dol_VolumeDate;   /* Creation (formatted) date.      */
        BPTR    dol_LockList;     /* -- Reserved by DOS, leave as 0            */
        int32   dol_DOSType;      /* 32 bit hex identity, eg: 'DOS\0'          */
        int32   dol_FSPrivate;    /* Used privately by filesystems.            */
      }
      dol_volume;

      struct
      {
        BPTR    dol_Lock;         /* Used by DLT_LOCK assign type only.        */
        STRPTR  dol_AssignPath;   /* CSTR dest for non/late binding assign     */
        struct  MultiAssign *dol_MultiAssignList;   /* Chain of DLT_LOCK multi-assigns */
        struct  MultiAssign *dol_NBMultiAssignList; /* Chain of DLT_NONBINDING multi-assigns (V54) */
        int32   dol_Unused[3];    /* -- Reserved for new types, leave as 0     */
      }
      dol_assign;
    } 
    dol_misc;

    BSTR        dol_Name;         /* BSTR formatted name string */
    int32       dol_StructSize;   /* (See NOTES) FULL allocated size of struct */
    int32       dol_Reserved[4];  /* -- DOS reserved expansion space.             */
};


/*  NOTES: Please note that it is now required that you reflect the full size
 *         of any custom struct in the dol_StructSize member to allow new planned
 *         features to work.   This is initialised automatically when using
 *         DOS AllocDosObject() and MakeDosEntry() functions from V52.16+
 */


#define  dol_handler    dol_device
#define  dol_DiskType   dol_DOSType
#define  dol_AssignName dol_AssignPath


/****************************************************************************/
/* Definitions for dl_Type */

#define DLT_DEVICE       0
#define DLT_LOCK         1     /* normal assign */
#define DLT_VOLUME       2
#define DLT_LATE         3     /* late-binding assign */
#define DLT_NONBINDING   4     /* non-binding assign */
#define DLT_PRIVATE     -1     /* for internal dos use only */


/****************************************************************************/
/* Flags for Doslist functions */

#define LDB_READ         0
#define LDB_WRITE        1
#define LDB_DEVICES      2
#define LDB_VOLUMES      3
#define LDB_ASSIGNS      4
#define LDB_ENTRY        5
#define LDB_DELETE       6

/* Internal semaphore flags */
#define LDF_ENTRY       (1 << LDB_ENTRY)
#define LDF_DELETE      (1 << LDB_DELETE)


/* You MUST specify one of LDF_READ or LDF_WRITE */
#define LDF_READ        (1 << LDB_READ)
#define LDF_WRITE       (1 << LDB_WRITE)

/* Flags to be passed to LockDosList(), etc */
#define LDF_DEVICES     (1 << LDB_DEVICES)
#define LDF_VOLUMES     (1 << LDB_VOLUMES)
#define LDF_ASSIGNS     (1 << LDB_ASSIGNS)

/* Shortcut for all node types */
#define LDF_ALL         (LDF_DEVICES|LDF_VOLUMES|LDF_ASSIGNS)


/****************************************************************************/
/* Mode types for NonBlockingModifyDosEntry()   (v51.30) */

#define NBM_ADDDOSENTRY        (1<<0)
#define NBM_REMDOSENTRY        (1<<1)
#define NBM_RENAMEDOSENTRY     (1<<2)
#define NBM_CHANGESIGNAL       (1<<3)
#define NBM_REMFREEDOSENTRY    (1<<4)  /* added 53.67 */
#define NBM_DISKINSERTED       (1<<5)  /* added 53.73 */
#define NBM_DISKREMOVED        (1<<6)  /* added 53.73 */


/****************************************************************************/
/* A filesystem lock structure, as returned by Lock(), DupLock(), etc...    */
/* Most of this structure is private to the filesystem and dos.library.     */
/* Some filesystems do not play nicely with others, and may not share.      */
/* So, DO NOT ACCESS PRIVATE FIELDS - They may not even be used for the     */
/* purpose indicated by the labelled name or type declaration.              */
/****************************************************************************/

struct Lock
{
    BPTR             fl_Link;          /* PRIVATE - filesystem use only.    */
    int32            fl_Key;           /* PRIVATE - filesystem use only.    */
    int32            fl_Access;        /* PRIVATE - filesystem use only.    */

    struct MsgPort * fl_Port;          /* Handler process message port      */

    BPTR             fl_Volume;        /* BPTR to DLT_VOLUME DosList entry.
                                       ** This can be NULL for some special
                                       ** handlers, never assume otherwise.
                                       */

                                       /* -- V51 additions -- */
    APTR             fl_FSPrivate1;    /* PRIVATE - filesystem use only.    */
    APTR             fl_FSPrivate2;    /* PRIVATE - filesystem use only.    */

    uint32           fl_DOSType;       /* The DOSType of the filesystem,    */
                                       /*  initialised by AllocDosObject(). */

    uint32           fl_StructSize;    /* Full DOS allocated struct size,   */
                                       /*  initialised by AllocDosObject(). */

                                       /* -- V53 additions -- */
    int32            fl_DosPrivate;    /* PRIVATE - dos library use only.   */
    int32            fl_Reserved[2];   /* RESERVED for expansion. V53       */
};
/* Filesystem private data can extend past the end of this definition. */




/****************************************************************************/
/* The Public structure return by GetDeviceProc(), GetDeviceProcFlags()     */
#ifndef dos_devproc

struct DevProc
{
    struct MsgPort * dvp_Port;         /* Handler message port     */
    BPTR             dvp_Lock;         /* Reference lock (or ZERO) */
    uint32           dvp_Flags;        /* Flags fields.            */
};
/* DOS private data extends past the end of this definition. */

#endif /* dos_devproc */
/****************************************************************************/


/* Definitions for DevProc->dvp_Flags;  */

#define DVPB_UNLOCK         0    
  /* For DOS internal use. 
   * This currently means the lock is temporary and will be unlocked
   * on the next call to GetDeviceProcFlags() or FreeDeviceProc().
   * This is generally used for resolving assignments.
   */

#define DVPB_MULTIASSIGN    1
  /* The Lock refers to part of a multi-assignment, this flag bit indicates
   * there are more entries of a multi-directory assignment to come.
   * ie; The last part of a multi-assignment will have this cleared.
   * ( Note: This used to be called DVPB_ASSIGN.)
   */

/*
 * The following flags were added at V53.56 to provide additional
 * functionality for LockTags() and other internal subsystems. 
 */

#define DVPB_DEVICE         16
  /* The supplied path is a device relative specification. */
 
#define DVPB_VOLUME         17
  /* The supplied path is a volume relative specification. */
 
#define DVPB_ASSIGNMENT     18
  /* The supplied path is an assignment relative specification. */
 
#define DVPB_PROGDIR        19
  /* The supplied path is a PROGDIR: relative specification. */
 
#define DVPB_CURRDIR        20
  /* The supplied path is a CURRDIR: relative specification. */

#define DVPB_ROOTDIR        21
  /* The supplied path is a root directory relative specification. */

#define DVPB_CONSOLE        23
  /* The supplied path is a CONSOLE: handler specification. */

#define DVPB_FILESYS        24
  /* The supplied path returned the root of the default filesystem. */


/* Field definitions for above bits */ 
#define DVPF_UNLOCK         (1 << DVPB_UNLOCK)
#define DVPF_MULTIASSIGN    (1 << DVPB_MULTIASSIGN)
#define DVPF_DEVICE         (1 << DVPB_DEVICE)
#define DVPF_VOLUME         (1 << DVPB_VOLUME)
#define DVPF_ASSIGNMENT     (1 << DVPB_ASSIGNMENT)
#define DVPF_PROGDIR        (1 << DVPB_PROGDIR)
#define DVPF_CURRDIR        (1 << DVPB_CURRDIR)
#define DVPF_ROOTDIR        (1 << DVPB_ROOTDIR)
#define DVPF_CONSOLE        (1 << DVPB_CONSOLE)
#define DVPF_FILESYS        (1 << DVPB_FILESYS)


/****************************************************************************/
/* Error report types for ErrorReport() */

#define REPORT_STREAM        0    /* a stream */
#define REPORT_TASK          1    /* a process - currently unused */
#define REPORT_LOCK          2    /* a lock */
#define REPORT_VOLUME        3    /* a volume node */
#define REPORT_INSERT        4    /* "please insert volume..." */

/* Special error codes for ErrorReport() */
#define ABORT_DISK_ERROR    296   /* Read/write error */
#define ABORT_BUSY          288   /* "You MUST replace..." */

/****************************************************************************/
/* Types for initial packets to shells from run/newcli/execute/system.
   For shell-writers only */

#define RUN_EXECUTE          -1
#define RUN_SYSTEM           -2
#define RUN_SYSTEM_ASYNCH    -3


/****************************************************************************/
/* PRIVATE: THIS STRUCTURE IS EXCLUSIVELY DOS & FILESYSTEM ACCESS ONLY  !!!
 *
 * Application code is NOT permitted to access any members of this structure.
 * Application code MUST consider that this structure does not actually exist.
 *
 * If you can't think of a way for your application to avoid accessing any of
 * these structure members, think again, and then think again some more.
 * If you still find yourself at an impasse, read the relevant autodocs again
 * and finally contact developer support for help, if all else fails.
 *
 * The most asked questions to date are;
 *  
 * (Q) How do I access the reference directory lock without peeking in here. ? 
 * (A) Set EX_DoCurrentDir,TRUE in ObtainDirContext() and call GetCurrentDir().
 *     Refer to ObtainDirContext() autodoc for detailed information.
 *
 * (Q) How do I tell if this call is emulated by DOS using the old functions with
 *     an old filesystem, which can't return 64 bit file sizes or long names. ?
 * (A) From DOS 54.93+ there is a new macro in dos.h;  EXD_IS_EMULATED(), this will
 *     indicate whether the old ExAll() or ExNext() calls were used as fallbacks.
 */

struct PRIVATE_ExamineDirContext
{
    uint32              StructSize;
    struct MinList      FreshNodeList;
    struct MinList      StaleNodeList;
    uint32              DataRequestFlags;
    struct Lock *       ReferenceLock;
    struct MsgPort *    MessagePort;
    APTR                MemoryPool;
	uint32              reserved_spares[7];

    APTR                FSPrivateMemPtr;
    uint32              FSPrivate[8];
/* 108 bytes - v51.104 */

    BPTR                DOSPrivateCD;
    BPTR                DOSPrivateLock;
    STRPTR              DOSPrivateName;
    int32               DOSPrivateResult2;
    APTR                DOSPrivateFallback;
    struct Hook *       DOSPrivateMatchFunc;
    STRPTR              DOSPrivateMatchString;
	struct Trackable *  DOSPrivateResourceTracker;
/* 140 bytes - v54.114 */
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

#endif    /* DOS_DOSEXTENS_H */
