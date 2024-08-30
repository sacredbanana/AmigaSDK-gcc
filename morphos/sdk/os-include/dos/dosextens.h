#ifndef DOS_DOSEXTENS_H
#define DOS_DOSEXTENS_H

/*
	dos.library extended structures include

	Copyright © 2002-2003 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TASKS_H
# include <exec/tasks.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef EXEC_SEMAPHORES_H
# include <exec/semaphores.h>
#endif

#ifndef DEVICES_TIMER_H
# include <devices/timer.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#pragma pack(2)


struct Process
{
	struct Task      pr_Task;
	struct MsgPort   pr_MsgPort;
	WORD             pr_Pad;
	BPTR             pr_SegList;
	LONG             pr_StackSize;
	APTR             pr_GlobVec;
	LONG             pr_TaskNum;
	BPTR             pr_StackBase;
	LONG             pr_Result2;
	BPTR             pr_CurrentDir;
	BPTR             pr_CIS;
	BPTR             pr_COS;
	APTR             pr_ConsoleTask;
	APTR             pr_FileSystemTask;
	BPTR             pr_CLI;
	APTR             pr_ReturnAddr;
	APTR             pr_PktWait;
	APTR             pr_WindowPtr;

	BPTR             pr_HomeDir;
	LONG             pr_Flags;
	VOID           (*pr_ExitCode)(VOID);
	LONG             pr_ExitData;
	STRPTR           pr_Arguments;
	struct MinList   pr_LocalVars;
	ULONG            pr_ShellPrivate;
	BPTR             pr_CES;
};


#define PRB_FREESEGLIST  0
#define PRF_FREESEGLIST  (1<<PRB_FREESEGLIST)

#define PRB_FREECURRDIR  1
#define PRF_FREECURRDIR  (1<<PRB_FREECURRDIR)

#define PRB_FREECLI      2
#define PRF_FREECLI      (1<<PRB_FREECLI)

#define PRB_CLOSEINPUT   3
#define PRF_CLOSEINPUT   (1<<PRB_CLOSEINPUT)

#define PRB_CLOSEOUTPUT  4
#define PRF_CLOSEOUTPUT  (1<<PRB_CLOSEOUTPUT)

#define PRB_FREEARGS     5
#define PRF_FREEARGS     (1<<PRB_FREEARGS)

#define PRB_CLOSEERROR   6
#define PRF_CLOSEERROR   (1<<PRB_CLOSEERROR)


struct FileHandle
{
	ULONG           fh_Flags;       /* Used to be struct Message *fh_Link; */
#	define          fh_Link fh_Flags

	LONG            fh_Interactive; /* Used to be struct MsgPort *fh_Port; */
#	define          fh_Port fh_Interactive

	struct MsgPort *fh_Type;
	LONG            fh_Buf;
	LONG            fh_Pos;
	LONG            fh_End;

	LONG            fh_Funcs;
#	define          fh_Func1 fh_Funcs

	LONG            fh_Func2;
	LONG            fh_Func3;

	LONG            fh_Args;
#	define          fh_Arg1 fh_Args

	LONG            fh_Arg2;

	/*** V50 (MorphOS) ***/

	LONG            fh_BufSize;
	LONG            fh_OrigBuf;
};


struct DosPacket
{
	struct Message *dp_Link;
	struct MsgPort *dp_Port;

	LONG            dp_Type;
#	define          dp_Action dp_Type

	LONG            dp_Res1;
#	define          dp_Status dp_Res1

	LONG            dp_Res2;
#	define          dp_Status2 dp_Res2


	LONG            dp_Arg1;
#	define          dp_BufAddr dp_Arg1

	LONG            dp_Arg2;
	LONG            dp_Arg3;
	LONG            dp_Arg4;
	LONG            dp_Arg5;
	LONG            dp_Arg6;
	LONG            dp_Arg7;
};


struct StandardPacket
{
	struct Message   sp_Msg;
	struct DosPacket sp_Pkt;
};


#define ACTION_NIL              0
#define ACTION_STARTUP          0
#define ACTION_GET_BLOCK        2       /*** OBSOLETE ***/
#define ACTION_SET_MAP          4
#define ACTION_DIE              5
#define ACTION_EVENT            6
#define ACTION_CURRENT_VOLUME   7
#define ACTION_LOCATE_OBJECT    8
#define ACTION_RENAME_DISK      9
#define ACTION_WRITE           'W'
#define ACTION_READ            'R'
#define ACTION_FREE_LOCK        15
#define ACTION_DELETE_OBJECT    16
#define ACTION_RENAME_OBJECT    17
#define ACTION_MORE_CACHE       18
#define ACTION_COPY_DIR         19
#define ACTION_WAIT_CHAR        20
#define ACTION_SET_PROTECT      21
#define ACTION_CREATE_DIR       22
#define ACTION_EXAMINE_OBJECT   23
#define ACTION_EXAMINE_NEXT     24
#define ACTION_DISK_INFO        25
#define ACTION_INFO             26
#define ACTION_FLUSH            27
#define ACTION_SET_COMMENT      28
#define ACTION_PARENT           29
#define ACTION_TIMER            30
#define ACTION_INHIBIT          31
#define ACTION_DISK_TYPE        32
#define ACTION_DISK_CHANGE      33
#define ACTION_SET_DATE         34

#define ACTION_SAME_LOCK        40

#define ACTION_SCREEN_MODE      994

#define ACTION_CHANGE_SIGNAL    995

#define ACTION_READ_RETURN      1001
#define ACTION_WRITE_RETURN     1002
#define ACTION_SEEK             1008
#define ACTION_FINDUPDATE       1004
#define ACTION_FINDINPUT        1005
#define ACTION_FINDOUTPUT       1006
#define ACTION_END              1007

#define ACTION_FORMAT           1020
#define ACTION_MAKE_LINK        1021

#define ACTION_SET_FILE_SIZE    1022
#define ACTION_WRITE_PROTECT    1023

#define ACTION_READ_LINK        1024
#define ACTION_FH_FROM_LOCK     1026
#define ACTION_IS_FILESYSTEM    1027
#define ACTION_CHANGE_MODE      1028

#define ACTION_COPY_DIR_FH      1030
#define ACTION_PARENT_FH        1031
#define ACTION_EXAMINE_ALL      1033
#define ACTION_EXAMINE_FH       1034

#define ACTION_EXAMINE_ALL_END  1035
#define ACTION_SET_OWNER        1036

#define ACTION_LOCK_RECORD      2008
#define ACTION_FREE_RECORD      2009

#define ACTION_ADD_NOTIFY       4097
#define ACTION_REMOVE_NOTIFY    4098

#define ACTION_SERIALIZE_DISK   4200

#define ACTION_GET_DISK_FSSM    4201
#define ACTION_FREE_DISK_FSSM   4202


/* 64bit DOS extensions - V51 */

/* Generic notes:
 *
 * - If large files are supported, normal ACTION_READ and ACTION_WRITE
 *   are used to access them. If ACTION_WRITE would grow the file to
 *   larger than the supported size, return code -1 and ioerr of
 *   ERROR_OBJECT_TOO_LARGE must be returned.
 * - Special attention is needed to make ACTION_SEEK not truncate
 *   various values when processing large files. If integer under/over-
 *   flow would occur, error should be returned and seek position left
 *   unchanged.
 * - For safety reasons ACTION_EXAMINE should return fib_Size of 0 for
 *   files larger than 2^31-1.
 */

/* ACTION_SEEK64
 * dp_Arg1 - LONG fh_Arg1
 * dp_Arg2 - QUAD *position
 * dp_Arg3 - LONG mode
 * dp_Arg4 - QUAD *oldposition
 *
 * dp_Res1 - DOSFALSE for error (*oldposition is undefined!), dp_Res2 set.
 *           DOSTRUE for success (*oldposition is the old seek position).
 *
 * Implementation notes
 * - Notice the different return value to ACTION_SEEK.
 * - ACTION_SEEK64 must work for all files.
 * - ACTION_SEEK should work for > 2^31-1 files aswell, as long as possible.
 *   Largefile ACTION_SEEK must fail with ERROR_SEEK_ERROR if:
 *   a) the current seek position before the call is > 2^31-1 or
 *   b) OFFSET_BEGINNING is used with position < 0 or
 *   c) OFFSET_END is used with position > 0 or
 *   d) the seek would result in having seek position in > 2^31-1 area.
 */
#define ACTION_SEEK64           26400

/* ACTION_SET_FILE_SIZE64
 * dp_Arg1 - LONG fh_Arg1
 * dp_Arg2 - QUAD *position
 * dp_Arg3 - LONG mode
 * dp_Arg4 - QUAD *newsize
 *
 * dp_Res1 - DOSFALSE for error (*newsize is undefined!), dp_Res2 set.
 *           DOSTRUE for success (*newsize is the new file size).
 *
 * Implementation notes
 * - ACTION_SET_FILE_SIZE64 must work for all files.
 * - ACTION_SET_FILE_SIZE should fail for > 2^31-1 files, for security
 *   reasons (dataloss is possible with old apps).
 * - If the caller tries to make the file larger than the largest
 *   supported size, ERROR_OBJECT_TOO_LARGE must be returned.
 */
#define ACTION_SET_FILE_SIZE64  26401

/* ACTION_LOCK_RECORD64
 * dp_Arg1 - LONG fh_Arg1
 * dp_Arg2 - UQUAD *offset
 * dp_Arg3 - UQUAD *length
 * dp_Arg4 - ULONG mode
 * dp_Arg5 - ULONG timeout
 *
 * dp_Res1 - DOSFALSE for error, dp_Res2 set.
 *           DOSTRUE for success.
 *
 * Implementation notes
 * - ACTION_LOCK_RECORD64 must work for all files .
 * - ACTION_LOCK_RECORD must work for > 2^31-1 files aswell,
 *   if offset and length are within 31bit range.
 * - Record locks are rarely used, so it's not fatal to return DOSFALSE
 *   with ERROR_ACTION_NOT_KNOWN.
 *
 */
#define ACTION_LOCK_RECORD64    26402

/* ACTION_FREE_RECORD64
 * dp_Arg1 - LONG fh_Arg1
 * dp_Arg2 - UQUAD *offset
 * dp_Arg3 - UQUAD *length
 *
 * dp_Res1 - DOSFALSE for error, dp_Res2 set.
 *           DOSTRUE for success.
 *
 * Implementation notes
 * - ACTION_FREE_RECORD64 must work for all files.
 * - ACTION_FREE_RECORD must work for > 2^31-1 files aswell,
 *   if offset and length are within 31bit range.
 * - Record locks are rarely used, so it's not fatal to return DOSFALSE
 *   with ERROR_ACTION_NOT_KNOWN.
 */
#define ACTION_FREE_RECORD64    26403

/* Reserved packet number - do not use
 */
#define ACTION_RESERVED_1       26404

/* Reserved packet number - do not use
 */
#define ACTION_RESERVED_2       26405

/* ACTION_NEW_READ_LINK
 * dp_Arg1 - BPTR lock, lock on directory that dp_Arg2 is relative to
 * dp_Arg2 - UBYTE *name, path and name of link (relative to dp_Arg1)
 * dp_Arg3 - UBYTE *buffer
 * dp_Arg4 - LONG buffersize
 *
 * dp_Res1 - Actual length of returned string, -2 if there isn't
 *           enough space in buffer, or -1 for other errors.
 *           0 return is error aswell (dp_Res2 is ERROR_ACTION_NOT_KNOWN likely)
 * dp_Res2 - 0 for successful return (dp_Res1 > 0), else ioerr code.
 *
 * Implementation notes
 * - ACTION_NEW_READ_LINK cause a linked object to be examined, and
 *   the path to the object linked to to be returned. It works both
 *   for soft and hard linked objects, as opposed to the original
 *   ACTION_READ_LINK packet which only works for soft linked
 *   objects.
 * - returns required buffer size in dp_Res1 if called with NULL
 *   buffer, including storage for string terminating '\0'.
 * - ACTION_NEW_READ_LINK should be well behaving, and handling all
 *   weird cases properly (see Olaf Barthel's docs and FFS2
 *   ACTION_READ_LINK for details).
 */
#define ACTION_NEW_READ_LINK    26406

/* ACTION_QUERY_ATTR
 * dp_Arg1 - LONG attr, which attribute you want to know about
 * dp_Arg2 - void *storage, memory to hold the return value
 * dp_Arg3 - LONG storagesize, size of storage reserved for
 *
 * dp_Res1 - DOSFALSE for error, dp_Res2 set.
 *           DOSTRUE for success.
 *
 * Implementation notes
 * - Unknown/unimplemented attributes must return DOSFALSE and dp_Res2
 *   of ERROR_BAD_NUMBER. This instructs dos.library GetFileSysAttr()
 *   to fall back to emulation code.
 * - If result doesn't fit the storage, must return DOSFALSE
 *   and dp_Res2 of ERROR_LINE_TOO_LONG.
 * - Largefile filesystems MUST support this packet and
 *   FQA_MaxFileSize attribute.
 * - Filesystems that can grow larger than 2TB (or actually fs where
 *   ACTION_DISK_INFO/ACTION_INFO NumBlocks and NumBlocksUsed can grow
 *   past 2^32-1) must implemented this packet and at least
 *   FQA_NumBlocks and FQA_NumBlocksUsed attributes.
 */
#define ACTION_QUERY_ATTR       26407

/* ACTION_EXAMINE_OBJECT64
 * dp_Arg1 - BPTR to lock to examine
 * dp_Arg2 - BPTR to struct FileInfoBlock (see <dos/dos.h>)
 *
 * dp_Res1 - DOSFALSE for error, dp_Res2 set.
 *           DOSTRUE for success.
 *
 * Implementation notes
 * - ACTION_EXAMINE_OBJECT and ACTION_EXAMINE_OBJECT64 must set
 *   fib_Size to 0 for files > 2^31-1.
 * - ACTION_EXAMINE_OBJECT64 must fill new fields: fib_Size64 and
 *   fib_NumBlocks64.
 * - Largefile filesystems MUST support this packet, aswell as
 *   ACTION_EXAMINE_NEXT64 and ACTION_EXAMINE_FH64.
 * - It is recommended that your implementation supports mixing
 *   ACTION_EXAMINE_OBJECT64 and ACTION_EXAMINE_NEXT.
 * - largefile filesystems must implement ACTION_EXAMINE_ALL with
 *   ED_SIZE64 (ed_Size64 field), and set ed_Size to 0 for files >
 *   2^31-1. Obviously ed_Size64 must be set for files < 2^31-1
 *   aswell.
 * - Early documentation incorrectly stated that dp_Arg3 would be
 *   a pointer to a tag list. This is not the case.
 */
#define ACTION_EXAMINE_OBJECT64 26408

/* ACTION_EXAMINE_NEXT64
 * dp_Arg1 - BPTR to directory lock to examine
 * dp_Arg2 - BPTR to struct FileInfoBlock (see <dos/dos.h>)
 *
 * dp_Res1 - DOSFALSE for error, dp_Res2 set.
 *           DOSTRUE for success.
 *
 * Implementation notes
 * - ACTION_EXAMINE_NEXT and ACTION_EXAMINE_NEXT64 must set
 *   fib_Size to 0 for files > 2^31-1.
 * - ACTION_EXAMINE_NEXT64 must fill a new fields: fib_Size64 and
 *   fib_NumBlocks64.
 * - Largefile filesystems MUST support this packet, aswell as
 *   ACTION_EXAMINE_OBJECT64 and ACTION_EXAMINE_FH64.
 * - It is recommended that your implementation supports mixing
 *   ACTION_EXAMINE_OBJECT and ACTION_EXAMINE_NEXT64.
 * - largefile filesystems must implement ACTION_EXAMINE_ALL with
 *   ED_SIZE64 (ed_Size64 field), and set ed_Size to 0 for files >
 *   2^31-1. Obviously ed_Size64 must be set for files < 2^31-1
 *   aswell.
 * - Early documentation incorrectly stated that dp_Arg3 would be
 *   a pointer to a tag list. This is not the case.
 */
#define ACTION_EXAMINE_NEXT64   26409

/* ACTION_EXAMINE_FH64
 * dp_Arg1 - LONG fh_Arg1
 * dp_Arg2 - BPTR to struct FileInfoBlock (see <dos/dos.h>)
 *
 * dp_Res1 - DOSFALSE for error, dp_Res2 set.
 *           DOSTRUE for success.
 *
 * Implementation notes
 * - ACTION_EXAMINE_FH and ACTION_EXAMINE_FH64 must set
 *   fib_Size to 0 for files > 2^31-1.
 * - ACTION_EXAMINE_FH64 must fill a new field: fib_Size64 and
 *   fib_NumBlocks64.
 * - Largefile filesystems MUST support this packet, aswell as
 *   ACTION_EXAMINE_OBJECT64 and ACTION_EXAMINE_NEXT64.
 * - largefile filesystems must implement ACTION_EXAMINE_ALL with
 *   ED_SIZE64 (ed_Size64 field), and set ed_Size to 0 for files >
 *   2^31-1. Obviously ed_Size64 must be set for files < 2^31-1
 *   aswell.
 * - Early documentation incorrectly stated that dp_Arg3 would be
 *   a pointer to a tag list. This is not the case.
 */
#define ACTION_EXAMINE_FH64     26410

/* GetFileSysAttr attribute types
 */

/* Return the maximum length of a file name (in characters),
 * excluding terminating '\0' char.
 *
 * type: LONG
 */
#define FQA_MaxFileNameLength   0

/* Return the maximum length of the volume name (in characters),
 * excluding terminating '\0' char.
 *
 * type: LONG
 */
#define FQA_MaxVolumeNameLength 1

/* Returns maximum size of the file the filesystem supports.
 * This attribute is meant to help system components/applications
 * to know if they can create large files or if they need to
 * resort to other means (split files). This attribute need not
 * account for currently available disk storage.
 *
 * type: QUAD
 */
#define FQA_MaxFileSize         2

/* If the filesystem names are case sensitive, this attribute must
 * return TRUE.
 *
 * If this attribute return FALSE or is not implemented, filesystem is
 * assumed to be case insensitive.
 *
 * type: LONG
 */
#define FQA_IsCaseSensitive     3

/* Return the type of the medium the filesystem is using, if known.
 * Value is one of DG_#? in devices/trackdisk.h.
 *
 * If this attribute return DG_UNKNOWN or is not implemented, no
 * assumption of the device type can be made. DG_COMMUNICATION
 * is networked drive.
 *
 * type: LONG
 */
#define FQA_DeviceType          4

/* This FQA attribute is reserved - do not use
 * In filesystem implementation return DOSFALSE with error ERROR_BAD_NUMBER
 * (as the filesystem doesn't know about this attribute).
 */
#define FQA_ReservedAttr1       5

/* Return the total number of blocks on the filesystem. The size of a
 * block is the filesystem natural block size, also returned in struct
 * InfoData id_BytesPerBlock. This allows reporting filesystem capacity
 * of over 2TB.
 *
 * type: QUAD
 */
#define FQA_NumBlocks           6

/* Return the total number of used blocks on the filesystem. The size of
 * a block is the filesystem natural block size, also returned in struct
 * InfoData id_BytesPerBlock. This allows reporting filesystem capacity
 * of over 2TB.
 *
 * type: QUAD
 */
#define FQA_NumBlocksUsed       7


/*
 * Packets to get and set filesystem options runtime
 */
#define ACTION_GET_PREFS_TEMPLATE 26500 /* arg1 - STRPTR dest_buff, arg2 - LONG buffer_size */
#define ACTION_GET_CURRENT_PREFS  26501 /* arg1 - STRPTR dest_buff, arg2 - LONG buffer_size */
#define ACTION_SET_PREFS          26502 /* arg1 - STRPTR prefs_string */

/*
 * TrashFS control packets
 */
#define ACTION_TRASH_FILE         26600 /* arg1 - BPTR lock to a file/directory to move to Trashcan: */
#define ACTION_RESTORE_FILE       26601 /* arg1 - STRPTR name of a file/directory *in* Trashcan: to be restored */
#define ACTION_RESTORE_PATH       26602 /* arg1 - STRPTR name of a file/directory *in* Trashcan:, arg2 - STRPTR dest_buf, arg3 - LONG buffer_size */
#define ACTION_EMPTY_TRASHCAN     26603
#define ACTION_IS_TRASHCAN_FS     26604

struct ErrorString
{
	LONG  *estr_Nums;
	UBYTE *estr_Strings;
};


struct DosLibrary
{
	struct Library      dl_lib;
	struct RootNode    *dl_Root;
	APTR                dl_GV;
	LONG                dl_A2;
	LONG                dl_A5;
	LONG                dl_A6;
	struct ErrorString *dl_Errors;
	struct timerequest *dl_TimeReq;
	struct Library     *dl_UtilityBase;
	struct Library     *dl_IntuitionBase;
};




struct RootNode
{
	BPTR               rn_TaskArray;
	BPTR               rn_ConsoleSegment;
	struct  DateStamp  rn_Time;
	LONG               rn_RestartSeg;
	BPTR               rn_Info;
	BPTR               rn_FileHandlerSegment;
	struct MinList     rn_CliList;
	struct MsgPort    *rn_BootProc;
	BPTR               rn_ShellSegment;
	LONG               rn_Flags;
}
#if __GNUC__ >= 3
__attribute__((deprecated))
#endif
;

#define RNB_WILDSTAR  24
#define RNF_WILDSTAR  (1<<RNB_WILDSTAR)

#define RNB_PRIVATE1  1
#define RNF_PRIVATE1  (1<<RNB_PRIVATE1)



struct CliProcList
{
	struct MinNode   cpl_Node;
	LONG             cpl_First;
	struct MsgPort **cpl_Array;
}
#if __GNUC__ >= 3
__attribute__((deprecated))
#endif
;


struct DosInfo
{
	BPTR                    di_McName;
#	define                  di_ResList di_McName

	BPTR                    di_DevInfo;
	BPTR                    di_Devices;
	BPTR                    di_Handlers;
	APTR                    di_NetHand;
	struct  SignalSemaphore di_DevLock;
	struct  SignalSemaphore di_EntryLock;
	struct  SignalSemaphore di_DeleteLock;
};

struct Segment
{
	BPTR  seg_Next;
	LONG  seg_UC;
	BPTR  seg_Seg;
	UBYTE seg_Name[4];
	/* seg_Name continues */
};


#define CMD_SYSTEM    -1
#define CMD_INTERNAL  -2
#define CMD_NOTLOADED -998
#define CMD_DISABLED  -999




struct CommandLineInterface
{
	LONG cli_Result2;
	BSTR cli_SetName;
	BPTR cli_CommandDir;
	LONG cli_ReturnCode;
	BSTR cli_CommandName;
	LONG cli_FailLevel;
	BSTR cli_Prompt;
	BPTR cli_StandardInput;
	BPTR cli_CurrentInput;
	BSTR cli_CommandFile;
	LONG cli_Interactive;
	LONG cli_Background;
	BPTR cli_CurrentOutput;
	LONG cli_DefaultStack;
	BPTR cli_StandardOutput;
	BPTR cli_Module;
};



struct DeviceList
{
	BPTR              dl_Next;
	LONG              dl_Type;
	struct MsgPort   *dl_Task;
	BPTR              dl_Lock;
	struct DateStamp  dl_VolumeDate;
	BPTR              dl_LockList;
	LONG              dl_DiskType;
	LONG              dl_unused;
	BSTR              dl_Name;
};


struct DevInfo
{
	BPTR dvi_Next;
	LONG dvi_Type;
	APTR dvi_Task;
	BPTR dvi_Lock;
	BSTR dvi_Handler;
	LONG dvi_StackSize;
	LONG dvi_Priority;
	LONG dvi_Startup;
	BPTR dvi_SegList;
	BPTR dvi_GlobVec;
	BSTR dvi_Name;
};


struct DosList
{
	BPTR            dol_Next;
	LONG            dol_Type;
	struct MsgPort *dol_Task;
	BPTR            dol_Lock;

	union
	{
		struct
		{
			BSTR  dol_Handler;
			LONG  dol_StackSize;
			LONG  dol_Priority;
			ULONG dol_Startup;
			BPTR  dol_SegList;
			BPTR  dol_GlobVec;
		} dol_handler;

		struct
		{
			struct DateStamp dol_VolumeDate;
			BPTR             dol_LockList;
			LONG             dol_DiskType;
		} dol_volume;

		struct
		{
			UBYTE             *dol_AssignName;
			struct AssignList *dol_List;
		} dol_assign;
	} dol_misc;

	BSTR            dol_Name;
};


struct AssignList
{
	struct AssignList *al_Next;
	BPTR               al_Lock;
};


#define DLT_DEVICE       0
#define DLT_DIRECTORY    1
#define DLT_VOLUME       2
#define DLT_LATE         3
#define DLT_NONBINDING   4
#define DLT_PRIVATE     -1
/*** V51 (MorphOS) ***/
#define DLT_FSCONTEXT    5


struct DevProc
{
	struct MsgPort *dvp_Port;
	BPTR            dvp_Lock;
	ULONG           dvp_Flags;
	struct DosList *dvp_DevNode;
};


#define DVPB_UNLOCK  0
#define DVPF_UNLOCK  (1<<DVPB_UNLOCK)

#define DVPB_ASSIGN  1
#define DVPF_ASSIGN  (1<<DVPB_ASSIGN)
/*** V51 (MorphOS) ***/
#define DVPB_FSCONTEXT	2
#define DVPF_FSCONTEXT	(1L << DVPB_FSCONTEXT)


#define LDB_READ     0
#define LDF_READ     (1<<LDB_READ)

#define LDB_WRITE    1
#define LDF_WRITE    (1<<LDB_WRITE)

#define LDB_DEVICES  2
#define LDF_DEVICES  (1<<LDB_DEVICES)

#define LDB_VOLUMES  3
#define LDF_VOLUMES  (1<<LDB_VOLUMES)

#define LDB_ASSIGNS  4
#define LDF_ASSIGNS  (1<<LDB_ASSIGNS)

#define LDB_ENTRY    5
#define LDF_ENTRY    (1<<LDB_ENTRY)

#define LDB_DELETE   6
#define LDF_DELETE   (1<<LDB_DELETE)

#define LDF_ALL      (LDF_DEVICES | LDF_VOLUMES | LDF_ASSIGNS)


struct FileLock
{
	BPTR            fl_Link;
	LONG            fl_Key;
	LONG            fl_Access;
	struct MsgPort *fl_Task;
	BPTR            fl_Volume;
};


#define REPORT_STREAM  0
#define REPORT_TASK    1
#define REPORT_LOCK    2
#define REPORT_VOLUME  3
#define REPORT_INSERT  4


#define ABORT_DISK_ERROR  296
#define ABORT_BUSY        288


#define RUN_EXECUTE        -1
#define RUN_SYSTEM         -2
#define RUN_SYSTEM_ASYNCH  -3


#define ST_ROOT       1
#define ST_USERDIR    2
#define ST_SOFTLINK   3
#define ST_LINKDIR    4
#define ST_FILE      -3
#define ST_LINKFILE  -4
#define ST_PIPEFILE  -5


struct CLIDataItem
{
	LONG  cdi_CLINum;        /* CLI number of the CLI */
	LONG  cdi_DefaultStack;  /* cli_DefaultStack of the CLI */
	LONG  cdi_GlobVec;       /* pr_GlobVec[0] of the CLI */
	ULONG cdi_Future;        /* For future expansion, 0 for now */
	BYTE  cdi_Pri;           /* CLI priority */
	UBYTE cdi_Flags;         /* If bit 0 is set cdi_command is valid */
	UBYTE cdi_Command[1];    /* 0-terminated command being executed */
};

struct CLIData
{
	ULONG               cd_NumCLIs; /* Number of entries in cd_cli array */
	struct CLIDataItem *cd_CLI[1];
};

#pragma pack()

#endif /* DOS_DOSEXTENS_H */
