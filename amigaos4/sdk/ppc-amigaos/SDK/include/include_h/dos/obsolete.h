#ifndef DOS_OBSOLETE_H
#define DOS_OBSOLETE_H
/*
**    $VER: obsolete.h  54.100 (07.09.2020)
**
**    include file for obsolete dos compatibility. 
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/
/****************************************************************************
**
**                     ===========================
**                     DEVELOPERS PLEASE READ THIS 
**                     ===========================
**
**       Include this file ONLY for old source code compatibility.
**       Newer applications should be written using the latest methods. 
**
*****************************************************************************/


#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
 
#ifndef DOS_ANCHORPATH_H
#include <dos/anchorpath.h> 
#endif   /* For the FIB struct and ST_XXXX defines. */


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
/* Sundry obsolete definitions for old source code compatibility */

#define  MAXINT               MAXINT32
#define  MININT               MININT32

#define  id_NumSoftErrors     id_Reserved1
#define  id_UnitNumber        id_Reserved2

#define  pr_TaskNum           pr_CliNum 
#define  pr_OGLContextPtr     pr_OGLContextData
#define  pr_ConsoleTask       pr_ConsolePort
#define  pr_FileSystemTask    pr_FileSystemPort
#define  pr_HomeDir           pr_ProgramDir
#define  pr_ProgDir           pr_ProgramDir

#define  fh_Port              fh_Interactive
#define  fh_Type              fh_MsgPort
#define  fh_Args              fh_Arg1

#define  dl_Task              dl_Port
#define  dl_unused            dl_FSPrivate

#define  dvi_Task             dvi_Port

#define  dn_Task              dn_Port
#define  dn_GlobalVec         dn_GlobVec

#define  dol_Task             dol_Port
#define  dol_List             dol_MultiAssignList
#define  dol_Lock             dol_misc.dol_assign.dol_Lock

#define  AssignList           MultiAssign
#define  al_Next              ma_Next 
#define  al_Lock              ma_Lock

#define  Segment              DosResidentSeg

#define  cli_CommandDir       cli_PathList
#define  cli_SetName          cli_CurrentDirName

#define  DLT_DIRECTORY        DLT_LOCK

#define  fl_Task              fl_Port
#define  FileLock             Lock

#define  DVPB_ASSIGN          DVPB_MULTIASSIGN
#define  DVPF_ASSIGN          DVPF_MULTIASSIGN

#define  DOSPrivateStatus     DOSPrivateResult2
#define  PacketPort           MessagePort

#define  OWNER_ROOT           DOS_OWNER_ROOT
#define  OWNER_NONE           DOS_OWNER_NONE

#define  LOCK_SAME_HANDLER    LOCK_SAME_VOLUME

#define  DOS_FILELOCK         DOS_LOCK

#define  OFFSET_BEGINING      OFFSET_BEGINNING

#define  ID_WRITE_PROTECTED   ID_DISKSTATE_WRITE_PROTECTED
#define  ID_VALIDATING        ID_DISKSTATE_VALIDATING
#define  ID_VALIDATED         ID_DISKSTATE_VALIDATED

/* Semantical name changes in DosEnvec */
#define  DE_SIZEBLOCK         DE_SECSIZE
#define  de_SizeBlock         de_SectorSize 
 
#define  DE_BLKSPERTRACK      DE_SECSPERTRACK    
#define  de_BlocksPerTrack    de_SectorPerTrack

#define  DE_NUMHEADS          DE_SURFACES

#define  DE_BOOTBLOCKS        DE_BOOTSECS
#define  de_BootBlocks        de_BootSectors

#define  DE_MEMBUFTYPE        DE_BUFMEMTYPE



/* Early function source name change quick fix. */
#define  FSReadLink           FSReadSoftLink

#define  ftam_Segment         ftam_SegList


/* Synonym used in early source code, changed because of 'use' confusion. */
#define  EXF_USECOUNT         EXF_REFCOUNT
#define  UseCount             RefCount



/* Obsolete when APPDIR: became a real filesystem in 53.134+ */
#define  DVPB_APPDIR          22
#define  DVPF_APPDIR         (1L << DVPB_APPDIR)
#define  LOCKB_APPDIR         22
#define  LOCKF_APPDIR        (1L<<LOCKB_APPDIR)


/*
** Finally redefine the name to reflect the exact function 
** of these particular contradictory protection bits. 
*/
#define EXDB_READ            EXDB_NO_READ
#define EXDB_WRITE           EXDB_NO_WRITE
#define EXDB_EXECUTE         EXDB_NO_EXECUTE
#define EXDB_DELETE          EXDB_NO_DELETE

#define EXDF_READ            EXDF_NO_READ
#define EXDF_WRITE           EXDF_NO_WRITE 
#define EXDF_EXECUTE         EXDF_NO_EXECUTE
#define EXDF_DELETE          EXDF_NO_DELETE 


/* semantical name change */
#define PRF_HASCHILDREN      PRF_HADCHILDREN
#define PRB_HASCHILDREN      PRB_HADCHILDREN


/*********************/
/* Renamed functions */

/* this was changed in V50 */
#define Flush(x)                     FFlush(x) 

/* these were changed in V53 */
#define SetPrompt(x)                 SetCliPrompt(x)
#define GetPrompt(x,y)               GetCliPrompt(x,y)

#define SetCurrentDirName(x)         SetCliCurrentDirName(x)
#define GetCurrentDirName(x,y)       GetCliCurrentDirName(x,y)

#define SetProgramName(x)            SetCliProgramName(x)
#define GetProgramName(x,y)          GetCliProgramName(x,y)

#define DeleteFile(x)                Delete(x)
#define SetFileDate(x,y)             SetDate(x,y)

#define ReadLink(p,k,a,b,bs)         ReadSoftLink(p,k,a,b,bs)

#define GetFileSysTask               GetFileSysPort
#define SetFileSysTask(x)            SetFileSysPort(x)

#define GetConsoleTask               GetConsolePort
#define SetConsoleTask(x)            SetConsolePort(x)

#define CurrentDir(x)                SetCurrentDir(x)

/* these were changed in V54 */
#define UnGetC(x,y)                  FUnGetC(x,y)
#define ExAll(a,b,c,d,e)             OBSOLETEExAll(a,b,c,d,e)
#define ExAllEnd(a,b,c,d,e)          OBSOLETEExAllEnd(a,b,c,d,e)
#define Examine(a,b)                 OBSOLETEExamine(a,b)
#define ExamineFH(a,b)               OBSOLETEExamineFH(a,b)
#define ExNext(a,b)                  OBSOLETEExNext(a,b)
#define Execute(a,b,c)               OBSOLETEExecute(a,b,c)
#define Seek(a,b,c)                  OBSOLETESeek(a,b,c)
#define SetVBuf(a,b,c,d)             OBSOLETESetVBuf(a,b,c,d)
#define SetOwner(a,b)                OBSOLETESetOwner(a,b)
#define CreateProc(a,b,c,d)          OBSOLETECreateProc(a,b,c,d)
#define DeviceProc(a)                OBSOLETEDeviceProc(a)
#define SetFileSize(a,b,c)           OBSOLETESetFileSize(a,b,c)




/*********************/
/* Obsolete tags     */

#define ADO_FH_Mode      (ADO_Dummy + 1)       /* obsolete V50 */
#define ADO_DirLen       (ADO_Dummy + 2)       /* obsolete V50 */
#define ADO_CommNameLen  (ADO_Dummy + 3)       /* obsolete V50 */
#define ADO_CommFileLen  (ADO_Dummy + 4)       /* obsolete V50 */
#define ADO_PromptLen    (ADO_Dummy + 5)       /* obsolete V50 */

#define NP_ProgDir        NP_ProgramDir
#define NP_HomeDir        NP_ProgramDir




/*********************/
/* Obsolete macros   */

/* 
**  This assumes a BCPL pointer always has the two most significant bits cleared.
**  Unfortunately, this will only be true with 32 bit addressing.
*/
#define IS_VALID_BPTR(bptr)   ((((uint32)(bptr)) & 0xC0000000) == 0)








/****************************************************************************/
/* Obsolete structure definition,  although called a "devicelist" it was    */
/* actually used only for volume nodes, how quaint !.                       */

struct DeviceList
{
    BPTR             dl_Next;
    int32            dl_Type;
    struct MsgPort * dl_Port;
    BPTR             dl_Lock;
    struct DateStamp dl_VolumeDate;
    BPTR             dl_LockList;
    int32            dl_DiskType;
    int32            dl_FSPrivate;
    BSTR             dl_Name;
    int32            dl_StructSize;
    int32            dl_Reserved[4];
};



/****************************************************************************/
/* Obsolete device structure definition,  this structure has identical      */
/* members to a struct DeviceNode that used to be found in filehandler.h.   */
/* Moved this one here because it was pointless having two definitions.     */

struct DevInfo
{
    BPTR             dvi_Next;
    int32            dvi_Type;
    struct MsgPort * dvi_Port;
    BPTR             dvi_Lock;
    BSTR             dvi_Handler;
    int32            dvi_StackSize;
    int32            dvi_Priority;
    int32            dvi_Startup;
    BPTR             dvi_SegList;
    BPTR             dvi_GlobVec;
    BSTR             dvi_Name;
    int32            dvi_StructSize;
    int32            dvi_Reserved[4];
};



/****************************************************************************/
/* Old struct for the OBSOLETELockRecords()/OBSOLETEUnLockRecords()         */
/* Do NOT use this with the new functions, it is here only for the DOS      */
/* fallback code to reference.                                              */

struct RecordLock32
{
    BPTR     rec_FH;         /* filehandle */
    uint32   rec_Offset;     /* 32 bit offset in file */
    uint32   rec_Length;     /* 32 bit length of file to be locked */
    uint32   rec_Mode;       /* Type of lock */
};





/****************************************************************************/
/* FIB stands for FileInfoBlock - these are obsolete definitions.           */

/* FIBB are bit definitions, FIBF are field definitions */
/* Regular RWED bits are 0 == allowed. */
/* NOTE: GRP and OTR RWED permissions are 0 == not allowed! */
/* Group and Other permissions are not directly handled by the filesystem */

#define FIBB_OTR_READ         15    /* Other: file is readable */
#define FIBB_OTR_WRITE        14    /* Other: file is writable */
#define FIBB_OTR_EXECUTE      13    /* Other: file is executable */
#define FIBB_OTR_DELETE       12    /* Other: prevent file from being deleted */
#define FIBB_GRP_READ         11    /* Group: file is readable */
#define FIBB_GRP_WRITE        10    /* Group: file is writable */
#define FIBB_GRP_EXECUTE       9    /* Group: file is executable */
#define FIBB_GRP_DELETE        8    /* Group: prevent file from being deleted */

#define FIBB_HOLD              7    /* (V50) hold loaded program in cli resident list */ 
#define FIBB_SCRIPT            6    /* program is a script (execute) file */
#define FIBB_PURE              5    /* program is reentrant and rexecutable */
#define FIBB_ARCHIVE           4    /* cleared whenever file is changed */
#define FIBB_READ              3    /* ignored by old filesystem */
#define FIBB_WRITE             2    /* ignored by old filesystem */
#define FIBB_EXECUTE           1    /* ignored by system, used by Shell */
#define FIBB_DELETE            0    /* prevent file from being deleted */

#define FIBF_OTR_READ         (1L<<FIBB_OTR_READ)
#define FIBF_OTR_WRITE        (1L<<FIBB_OTR_WRITE)
#define FIBF_OTR_EXECUTE      (1L<<FIBB_OTR_EXECUTE)
#define FIBF_OTR_DELETE       (1L<<FIBB_OTR_DELETE)
#define FIBF_GRP_READ         (1L<<FIBB_GRP_READ)
#define FIBF_GRP_WRITE        (1L<<FIBB_GRP_WRITE)
#define FIBF_GRP_EXECUTE      (1L<<FIBB_GRP_EXECUTE)
#define FIBF_GRP_DELETE       (1L<<FIBB_GRP_DELETE)

#define FIBF_HOLD             (1L<<FIBB_HOLD)
#define FIBF_SCRIPT           (1L<<FIBB_SCRIPT)
#define FIBF_PURE             (1L<<FIBB_PURE)
#define FIBF_ARCHIVE          (1L<<FIBB_ARCHIVE)
#define FIBF_READ             (1L<<FIBB_READ)
#define FIBF_WRITE            (1L<<FIBB_WRITE)
#define FIBF_EXECUTE          (1L<<FIBB_EXECUTE)
#define FIBF_DELETE           (1L<<FIBB_DELETE)

/****************************************************************************/
/* Obsolete macros for checking what kind of object a FileInfoBlock
 * describes; Examine() / ExNext().
 */

#define FIB_IS_FILE(fib)      ((fib)->fib_DirEntryType <  0)

#define FIB_IS_DRAWER(fib)    ((fib)->fib_DirEntryType >= 0 && \
                               (fib)->fib_DirEntryType != ST_SOFTLINK)

#define FIB_IS_LINK(fib)      ((fib)->fib_DirEntryType == ST_SOFTLINK || \
                               (fib)->fib_DirEntryType == ST_LINKDIR || \
                               (fib)->fib_DirEntryType == ST_LINKFILE)

#define FIB_IS_SOFTLINK(fib)  ((fib)->fib_DirEntryType == ST_SOFTLINK)

#define FIB_IS_LINKDIR(fib)   ((fib)->fib_DirEntryType == ST_LINKDIR)





/****************************************************************************/
/* Obsolete ExAll() definitions.
   NOTE: V37 dos.library, when doing ExAll() emulation, and V37 filesystems
   will return an error if passed ED_OWNER.  If you get ERROR_BAD_NUMBER,
   retry with ED_COMMENT to get everything but owner info.  All filesystems
   supporting ExAll() must support through ED_COMMENT, and must check Type
   and return ERROR_BAD_NUMBER if they don't support the type. */

/* Values that can be passed for what data you want from ExAll() each higher
   value includes those below it (numerically) you MUST chose one of these values */

#define ED_NAME        1
#define ED_TYPE        2
#define ED_SIZE        3
#define ED_PROTECTION  4
#define ED_DATE        5
#define ED_COMMENT     6
#define ED_OWNER       7

/****************************************************************************/
/* Handy macros for checking what kind of object a ExAllData's ed_Type describes;  ExAll() */

#define EAD_IS_FILE(ead)    ((ead)->ed_Type <  0)

#define EAD_IS_DRAWER(ead)  ((ead)->ed_Type >= 0 && \
                             (ead)->ed_Type != ST_SOFTLINK)

#define EAD_IS_LINK(ead)    ((ead)->ed_Type == ST_SOFTLINK || \
                             (ead)->ed_Type == ST_LINKDIR || \
                             (ead)->ed_Type == ST_LINKFILE)

#define EAD_IS_SOFTLINK(ead) ((ead)->ed_Type == ST_SOFTLINK)

#define EAD_IS_LINKDIR(ead)  ((ead)->ed_Type == ST_LINKDIR)






/****************************************************************************/
/* Obsolete packet definitions */

#define ACTION_GET_BLOCK          2     /* OBSOLETE */
#define ACTION_SET_MAP            4     /* OBSOLETE */
#define ACTION_DIE                5     /* OBSOLETE use: ACTION_SHUTDOWN V51+ */
#define ACTION_COPY_DIR          19     /* OBSOLETE SYNONYM for ACTION_COPY_LOCK */
#define ACTION_DISK_INFO         25     /* OBSOLETE SYNONYM for ACTION_HANDLER_INFO */
#define ACTION_DISK_TYPE         32     /* OBSOLETE */
#define ACTION_DISK_CHANGE       33     /* OBSOLETE */
#define ACTION_SCREEN_MODE       994    /* OBSOLETE SYNONYM for ACTION_SINGLE_CHARACTER_MODE */
#define ACTION_READ_LINK         1024   /* OBSOLETE SYNONYM for ACTION_READ_SOFT_LINK */
#define ACTION_COPY_DIR_FH       1030   /* OBSOLETE SYNONYM for ACTION_COPY_LOCK_FH */
#define ACTION_LOCK_RECORD       2008   /* OBSOLETE use: ACTION_LOCK_RECORD64 instead */
#define ACTION_FREE_RECORD       2009   /* OBSOLETE use: ACTION_FREE_RECORD64 instead */

#define ID_COLLECT_FILELOCK      1      /* old source compatibility name for ID_COLLECT_LOCK */






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
#endif   /* DOS_OBSOLETE_H */
/****************************************************************************/




