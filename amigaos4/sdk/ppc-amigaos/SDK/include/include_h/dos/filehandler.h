#ifndef DOS_FILEHANDLER_H
#define DOS_FILEHANDLER_H
/*
**    $VER: filehandler.h  54.102 (28.09.2021)
**
**    Device and file handler specific code for AmigaDOS
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

#ifndef DOS_DOSEXTENS_H
#include <dos/dosextens.h>
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
#endif

/****************************************************************************
**  The disk "environment" structure was a longword array that describes
**  the disk geometry.  It has traditionally been a variable sized array, 
**  with the number of 32 bit entries that follow de_TableSize in de_TableSize.  
**
**  It was not guaranteed to be the sizeof(struct DosEnvec), so check it.
**
**  New implementations should always allocate the full public structure size
**  regardless of how many fields are actually in use.
**  All unused fields shall be cleared to zero and de_TableSize=DE_BOOTSECS.
**
*/

struct DosEnvec
{
    uint32    de_TableSize;
              /* Number of 32 bit entries following this.
              ** Minimum value is 11, (includes DE_NUMBUFFERS) 
              */
    
    uint32    de_SectorSize;
              /* Specified in longwords - Physical disk sector size, std value is 128 (for 512 bytes)
              ** Used to be called de_SizeBlock in V40.
              */

    uint32    de_SecOrg;
              /* This has never been used AFAIK, must be 0 */

    uint32    de_Surfaces;
              /* Number of heads (surfaces). drive specific */

    uint32    de_SectorPerBlock;
              /* Not currently used, must be 1 -- de_SectorSize sectors per logical block */

    uint32    de_SectorPerTrack;
              /* Sectors per track. drive specific, used to be called de_BlocksPerTrack in V40 */

    uint32    de_Reserved;
              /* Number of reserved logical file system blocks at the beginning of the partition. */

    uint32    de_PreAlloc;
              /* Number of reserved logical file system blocks at the end of the partition. */

    uint32    de_Interleave;
              /* This has never been used, should be 0. */

    uint32    de_LowCyl;
              /* Starting cylinder. typically 0 */

    uint32    de_HighCyl;
              /* Max cylinder. drive specific */

    uint32    de_NumBuffers;
              /* Suggested initial # of buffers.  One buffer usually equals 512 bytes */

    uint32    de_BufMemType;
              /* Preferred type of memory to allocate for buffers */

    uint32    de_MaxTransfer;
              /* Max number of bytes to transfer at a time that is safe. */

    uint32    de_Mask;
              /* If read/writes are going to be made using buffer memory covered by this mask,
              ** I/O operations have to be made using buffers allocated with de_BufMemType.
              */
 
    int32     de_BootPri;
              /* Boot priority for autoboot, values -128 to +127 */

    uint32    de_DosType;
              /* ASCII (HEX) string showing filesystem signature type;
              ** eg:   0x444F5300 is old filesystem,  0x444F5301 is fast file system.
              */

    uint32    de_Baud;
              /* Baud rate for serial handler, usually for port-handler. */

    uint32    de_Control;
              /* Control information, also used by port-handler (BSTR) and others handlers. */

    uint32    de_BootSectors;
              /* Number of physical disk sectors at the beginning of the partition
              ** which contain bootstrapping code.  Used to be called de_BootBlocks.
              */
};

/* Some handy math examples;
** -- Sector size (in bytes)    =   de_SectorSize * 4;
** -- First partition sector    =   de_LowCyl * de_Surfaces * de_SectorPerTrack;
** -- Sectors in a partition    = ( de_HighCyl - de_LowCyl + 1) * de_Surfaces * de_SectorPerTrack;
** -- Partition size (in bytes) = ((de_HighCyl - de_LowCyl + 1) * de_Surfaces * de_SectorPerTrack / de_SectorPerBlock) *
**                                 (de_SectorPerBlock * de_SectorSize * 4); 
*/


/* The following are the offsets when DosEnvec was accessed as an array of longwords;
** DE_TABLESIZE is set to the number of fields in the array, minus 1,
** that is, NOT including the DE_TABLESIZE field itself. 
** So if de_DosType was the last valid entry, de_TableSize == DE_DOSTYPE.
*/

#define DE_TABLESIZE      0    /* minimum value is 11 (includes NumBuffers) */
#define DE_SECSIZE        1    /* in longwords: standard value is 128 */
#define DE_SECORG         2    /* not used; must be 0 */
#define DE_SURFACES       3    /* # of heads (surfaces). drive specific */
#define DE_SECSPERBLK     4    /* not used; must be 1 */
#define DE_SECSPERTRACK   5    /* sectors per track. drive specific */
#define DE_RESERVEDBLKS   6    /* unavailable blocks at start.     usually 2 */
#define DE_PREFAC         7    /* not used; must be 0 */
#define DE_INTERLEAVE     8    /* not used - usually 0 */
#define DE_LOWCYL         9    /* starting cylinder. typically 0 */
#define DE_UPPERCYL      10    /* max cylinder.  drive specific */
#define DE_NUMBUFFERS    11    /* suggested initial # of buffers.  typically 5 */

#define DE_BUFMEMTYPE    12    /* type of mem to allocate for buffers. */
                               /* 1 is public, 3 is chip, 5 is fast */
#define DE_MAXTRANSFER   13    /* Max number bytes to transfer at a time */
#define DE_MASK          14    /* Address Mask to block out certain memory */
#define DE_BOOTPRI       15    /* Boot priority for autoboot */
#define DE_DOSTYPE       16    /* ASCII (HEX) string showing filesystem type;
                                * 0x444F5300 is old filesystem,
                                * 0x444F5301 is fast file system */
#define DE_BAUD          17    /* Baud rate for serial handler */
#define DE_CONTROL       18    /* Control word for handler/filesystem */
#define DE_BOOTSECS      19    /* Number of sectors containing boot code */




/****************************************************************************
** The file system startup message is linked into a device node's startup
** field. It contains a pointer to the above environment, plus the
** information needed to do an exec OpenDevice(). 
*/

struct FileSysStartupMsg
{
    uint32    fssm_Unit;      /* exec unit number for this device */
    BSTR      fssm_Device;    /* null terminated bstring to the device name */
    BPTR      fssm_Environ;   /* ptr to environment table (see above) */
    uint32    fssm_Flags;     /* flags for OpenDevice() */
};



/****************************************************************************
** The public portion of the structure used for the new V50 functions; 
** GetDiskFileSystemData() and FreeDiskFileSystemData(). 
** Do not depend on the size of this structure to stay constant. 
*/


struct FileSystemData
{
    uint32             fsd_Size;           /* the size of this structure (currently 56 bytes) */
    STRPTR             fsd_FileSystemName; /* the DOS device name, eg: "DH0:" */
    STRPTR             fsd_DeviceName;     /* the EXEC device driver name, eg: "ide.device" */
    uint32             fsd_DeviceUnit;     /* the EXEC device unit number, eg: 0...63   */
    uint32             fsd_DeviceFlags;    /* the EXEC opendevice() flags */
    struct DosEnvec *  fsd_Environment;    /* WARNING: See (Note 1) below    */

    APTR               fsd_DosPrivate[4];  /* this really is dos private ! */  
    APTR               fsd_Reserved[4];    /* future struct expansion space.  */
};

/*  Note 1:
**  ======
**  The fsd_Environment is a pointer to variable size array of longword
**  entries that follow the de_TableSize field.  
**  You must not assume it is always sizeof(struct DosEnvec).
**  See struct DosEnvec for more information. (above).
*/








/****************************************************************************
** The new V53 struct FileSystemVectorPort includes follow.
**
** See the autodoc "dos.dospacket.doc"  (initial introductory section) for
** further information on the new style V53 filesystem vector-port calling method.
**
****************************************************************************/

#define FS_VECTORPORT_VERSION      53
#define FSVP                       FileSystemVectorPort   /* shortcut */

/****************************************************************************/

struct FileSystemVectorPort;       /* FWD reference */

#ifndef DOS_NOTIFY_H
  struct NotifyRequest;            /* FWD reference */
#endif /* DOS_NOTIFY_H */


/****************************************************************************
** For new vector-port filesystems, the following are the maximum lengths  
** that should be supported.  String buffers should also reflect these.
** Older ported filesystem designs may not be able to support these lengths
** due to internal structure limitations, so call IDOS->FileSystemAttr()
** to find out the actual filesystem specific values. See also; dos/dos.h
*/

#ifndef     MAX_VP_FILENAME
  #define   MAX_VP_FILENAME   MAX_DOS_FILENAME
#endif

#ifndef     MAX_VP_COMMENT
  #define   MAX_VP_COMMENT    MAX_DOS_COMMENT
#endif

#ifndef     MAX_VP_SOFTLINK_TARGET
  #define   MAX_VP_SOFTLINK_TARGET   MAX_DOS_SOFTLINK_TARGET
#endif


/****************************************************************************
**  This vector initialisation structure is defined as a constant static structure and initialised
**  by the filesystem with all of the mentioned sundry data and function pointers, 
**  a pointer to this structure is then passed as a parameter to IDOS->AllocDosObject() which will
**  copy it to the 'FSV' space of the allocated struct FileSystemVectorPort structure.
**
**  For unimplemented functions, a stub routine that returns 0 and ERROR_ACTION_NOT_KNOWN in result2
**  should be used instead of a NULL pointer, this prevents DOS from falling back and retrying the
**  same action with the equivalent DosPacket. See 'struct FileSystemVectorPort' info below for details.
*/ 

struct FileSystemVectors
{
    uint32         StructSize;  /* Filesystem must initialise this to; sizeof(struct FileSystemVectors) */
    uint32         Version;     /* Filesystem must initialise this to; FS_VECTORPORT_VERSION  */

    APTR           FSPrivate;   /* Private field for exclusive use by the filesystem, this is generally */
                                /* used to point to the filesystems private global data structure to    */
                                /* make it accessible from the vector-port functions.                   */
                                /* Optionally, the filesystem may just initialise this to zero and then */
                                /* after the AllocDosObject() call, place your required data in there.  */

    uint32         Reserved[3]; /* Filesystems initialise all of these to 0 - reserved expansion */

    APTR           DOSPrivate;  /* Filesystems initialise this to 0 - DOS private usage only. */

    void         (*DOSEmulatePacket)(struct FSVP *vp, struct DosPacket *dp);  
                  /* Filesystems shall initialise this to NULL.  */
                  /* AllocDosObject() will insert a function pointer here for the filesystem to use.  */
                  /* This function is to be called from the packet handler process of the filesystem  */
                  /* to provide legacy emulation support for old applications that send Dospackets    */
                  /* directly to the filesystem message port.                                         */
                  /* See; "dos.dospacket.doc" for further details and example source code for this.   */
                

    /***************************************************************************************************/

    struct Lock * (*FSLock)(struct FSVP *vp, int32 *res2, struct Lock *rel_lock, CONST_STRPTR obj, int32 mode);
                  /* Equivalent function for ACTION_LOCK.
                   * Always returns a SHARED_LOCK for directories no matter what 'mode' is requested.
                   * The EXCLUSIVE_LOCK mode is for files only.
                   */

    int32         (*FSUnLock)(struct FSVP *vp, int32 *res2, struct Lock *lock);
                  /* Equivalent function for ACTION_UNLOCK */

    struct Lock * (*FSDupLock)(struct FSVP *vp, int32 *res2, struct Lock *lock);
                  /* Equivalent function for ACTION_COPY_LOCK */

    struct Lock * (*FSCreateDir)(struct FSVP *vp, int32 *res2, struct Lock *rel_lock, CONST_STRPTR obj);
                  /* Equivalent function for ACTION_CREATE_DIR - always returns a SHARED_LOCK */

    struct Lock * (*FSParentDir)(struct FSVP *vp, int32 *res2, struct Lock *dirlock);
                  /* Equivalent function for ACTION_PARENT - always returns a SHARED_LOCK */

    struct Lock * (*FSDupLockFromFH)(struct FSVP *vp, int32 *res2, struct FileHandle *filehandle);
                  /* Equivalent function for ACTION_COPY_LOCK_FH */

    int32         (*FSOpenFromLock)(struct FSVP *vp, int32 *res2, struct FileHandle *file, struct Lock *lock);
                  /* Equivalent function for ACTION_FH_FROM_LOCK */

    struct Lock * (*FSParentOfFH)(struct FSVP *vp, int32 *res2, struct FileHandle *file);
                  /* Equivalent function for ACTION_PARENT_FH   */

    int32         (*FSOpen)(struct FSVP *vp, int32 *res2, struct FileHandle *fh, struct Lock *rel_dir, CONST_STRPTR obj, int32 mode);
                  /* Equivalent function for ACTION_FINDUPDATE, ACTION_FINDINPUT, ACTION_FINDOUTPUT */

    int32         (*FSClose)(struct FSVP *vp, int32 *res2, struct FileHandle *file);
                  /* Equivalent function for ACTION_END */

    int32         (*FSDelete)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR obj);
                  /* Equivalent function for ACTION_DELETE_OBJECT */

    int32         (*FSRead)(struct FSVP *vp, int32 *res2, struct FileHandle *file, STRPTR buffer, int32 numbytes);
                  /* Equivalent function for ACTION_READ */

    int32         (*FSWrite)(struct FSVP *vp, int32 *res2, struct FileHandle *file, STRPTR buffer, int32 numbytes);
                  /* Equivalent function for ACTION_WRITE */

    int32         (*FSFlush)(struct FSVP *vp, int32 *res2);
                  /* Equivalent function for ACTION_FLUSH  */

    int32         (*FSChangeFilePosition)(struct FSVP *vp, int32 *res2, struct FileHandle *file, int32 mode, int64 position);
                  /* Equivalent function for ACTION_CHANGE_FILE_POSITION64  */
 
    int32         (*FSChangeFileSize)(struct FSVP *vp, int32 *res2, struct FileHandle *file, int32 mode, int64 size);
                  /* Equivalent function for ACTION_CHANGE_FILE_SIZE64 */

    int64         (*FSGetFilePosition)(struct FSVP *vp, int32 *res2, struct FileHandle *file );
                  /* Equivalent function for ACTION_GET_FILE_POSITION64 */

    int64         (*FSGetFileSize)(struct FSVP *vp, int32 *res2, struct FileHandle *file );
                  /* Equivalent function for ACTION_GET_FILE_SIZE64 */

    int32         (*FSChangeLockMode)(struct FSVP *vp, int32 *res2, struct Lock *lock, int32 new_lock_mode);
                  /* Equivalent function for ACTION_CHANGE_MODE (LOCK) - never changes directories from a SHARED_LOCK */ 

    int32         (*FSChangeFileMode)(struct FSVP *vp, int32 *res2, struct FileHandle *fh, int32 new_lock_mode);
                  /* Equivalent function for ACTION_CHANGE_MODE (FILE) */


    int32         (*FSSetDate)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, const struct DateStamp *ds);
                  /* Equivalent function for ACTION_SET_DATE */

    int32         (*FSSetProtection)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, uint32 mask);
                  /* Equivalent function for ACTION_SET_PROTECT */

    int32         (*FSSetComment)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, CONST_STRPTR comment);
                  /* Equivalent function for ACTION_SET_COMMENT */

    int32         (*FSSetGroup)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, uint32 group);
                  /* Equivalent function for ACTION_SET_OWNER / ACTION_SET_OWNER_INFO */

    int32         (*FSSetUser)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, uint32 user);
                  /* Equivalent function for ACTION_SET_OWNER / ACTION_SET_OWNER_INFO */

    int32         (*FSRename)(struct FSVP *vp, int32 *res2, struct Lock *src_rel, CONST_STRPTR src, 
                              struct Lock *dst_rel, CONST_STRPTR dst);
                  /* Equivalent function for ACTION_RENAME_OBJECT */


    int32         (*FSCreateSoftLink)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, 
                                      CONST_STRPTR linkname, CONST_STRPTR dest_obj);
                  /* Equivalent function for ACTION_MAKE_LINK (SOFT) */

    int32         (*FSCreateHardLink)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, 
                                      CONST_STRPTR linkname, struct Lock *dest_obj);
                  /* Equivalent function for ACTION_MAKE_LINK (HARD) */

    int32         (*FSReadSoftLink)(struct FSVP *vp, int32 *res2, struct Lock *rel_dir, 
                                    CONST_STRPTR linkname, STRPTR buf, int32 bufsize);
                  /* Equivalent function for ACTION_READ_SOFT_LINK */


    int32         (*FSSameLock)(struct FSVP *vp, int32 *res2, struct Lock *lock1, struct Lock *lock2);
                  /* Equivalent function for ACTION_SAME_LOCK */

    int32         (*FSSameFile)(struct FSVP *vp, int32 *res2, struct FileHandle *fh1, struct FileHandle *fh2);
                  /* Equivalent function for ACTION_SAME_FH */


    int32         (*FSFileSystemAttr)(struct FSVP *vp, int32 *res2, struct TagItem *taglist);
                  /* Equivalent function for ACTION_FILESYSTEM_ATTR  */

    int32         (*FSVolumeInfoData)(struct FSVP *vp, int32 *res2, struct InfoData *info);
                  /* Equivalent function for ACTION_INFO. */

    int32         (*FSDeviceInfoData)(struct FSVP *vp, int32 *res2, struct InfoData *info);
                  /* Equivalent function for ACTION_HANDLER_INFO. */


    int32         (*FSReserved1)(struct FSVP *vp, int32 *res2);
                  /* Spare function slot, Filesystems initialise this to NULL */

  
    struct ExamineData * (*FSExamineObj)(struct FSVP *vp, int32 *res2, struct Lock *lock, CONST_STRPTR object);
                  /* Equivalent function for ACTION_EXAMINEDATA_OBJ */

    struct ExamineData * (*FSExamineLock)(struct FSVP *vp, int32 *res2, struct Lock *lock);
                  /* Equivalent function for ACTION_EXAMINEDATA */

    struct ExamineData * (*FSExamineFile)(struct FSVP *vp, int32 *res2, struct FileHandle *file);
                  /* Equivalent function for ACTION_EXAMINEDATA_FH */

    int32         (*FSExamineDir)(struct FSVP *vp, int32 *res2, struct PRIVATE_ExamineDirContext *ctx);
                  /* Equivalent function for ACTION_EXAMINEDATA_DIR */


    int32         (*FSInhibit)(struct FSVP *vp, int32 *res2, int32 inhibit_state);
                  /* Equivalent function for ACTION_INHIBIT  */

    int32         (*FSWriteProtect)(struct FSVP *vp, int32 *res2, int32 wp_state, uint32 passkey);
                  /* Equivalent function for ACTION_WRITE_PROTECT */

    int32         (*FSFormat)(struct FSVP *vp, int32 *res2, CONST_STRPTR new_volname, uint32 dostype, uint32 spare);
                  /* Equivalent function for ACTION_FORMAT */

    int32         (*FSSerialize)(struct FSVP *vp, int32 *res2);
                  /* Equivalent function for ACTION_SERIALIZE_DISK */

    int32         (*FSRelabel)(struct FSVP *vp, int32 *res2, CONST_STRPTR new_volumename);
                  /* Equivalent function for ACTION_RENAME_DISK */


    int32         (*FSReserved3)(struct FSVP *vp, int32 *res2);  
                  /* Spare function slot, Filesystems initialise this to NULL */



   /*************************************************************************
    **  OPTIONAL FUNCTIONS 
    **  ==================
    **  The following two notification functions are optional, the dos.library
    **  provides these functions internally when these functions return FALSE
    **  and Result2 = ERROR_ACTION_NOT_KNOWN.
    **  These vectors have been provided for remote filesystem implementations.
    */
  
    int32         (*FSAddNotify)(struct FSVP *vp, int32 *res2, struct NotifyRequest *nr);
                  /* Equivalent function for ACTION_ADD_NOTIFY */

    int32         (*FSRemoveNotify)(struct FSVP *vp, int32 *res2, struct NotifyRequest *nr);
                  /* Equivalent function for ACTION_REMOVE_NOTIFY */



  /*************************************************************************
    **  OPTIONAL FUNCTIONS 
    **  ==================
    **  The following two record locking functions are optional, the dos.library
    **  provides these functions internally when these vector functions return
    **  FALSE and Result2 = ERROR_ACTION_NOT_KNOWN.
    **  These vectors have been provided for remote filesystem implementations.
    */
 
    int32         (*FSLockRecord)(struct FSVP *vp, int32 *res2, struct FileHandle *file,
                                  int64 offset, int64 length, uint32 mode, uint32 timeout);
                  /* Equivalent function for ACTION_LOCK_RECORD64 */

    int32         (*FSUnLockRecord)(struct FSVP *vp, int32 *res2, struct FileHandle *file,
                                    int64 offset, int64 length);
                  /* Equivalent function for ACTION_FREE_RECORD64 */




    /*=== End of V53 vectors, - New V54+ vectors to be added after this line ===*/

    int32         End_Marker;  /* This must always be at vector table end, set to -1 */
};







/****************************************************************************
**
**  This is the structure returned from IDOS->AllocDosObject(DOS_FSVECTORPORT,...)
**  it is pre-initialised so that it is ready to be called by dos.library.
** 
**  The dos.library always validates this structure before every call to any
**  of the function vectors with the IDOS->GetFileSystemVectorPort() function
**  and a NULL pointer check after that.
**
**  So, to have a vector port function called by dos.library it must have;
**      1) The MP.mp_Node.ln_Type must have a value of NT_FILESYSTEM.
**      2) The FSV.Version must be 53 (or greater for later additions).
**      3) The actual function vector pointer must not be NULL.
**
**  Failure to validate any of these three tests will cause dos.library to 
**  fall back to sending a DosPacket to the handlers message port instead.
**
*/

struct FileSystemVectorPort
{
   struct MsgPort            MP;  
   struct FileSystemVectors  FSV;
};






#ifndef NO_VECTORPORT_FUNCTION_PROTOTYPES
/****************************************************************************/

void DOSEmulatePacket(struct FSVP *vp, struct DosPacket *dp);  

struct Lock *FSLock(struct FSVP *vp, int32 *res2, struct Lock *rel_lock, CONST_STRPTR obj, int32 mode);
int32  FSUnLock(struct FSVP *vp, int32 *res2, struct Lock *lock);
struct Lock * FSDupLock(struct FSVP *vp, int32 *res2, struct Lock *lock);
struct Lock * FSCreateDir(struct FSVP *vp, int32 *res2, struct Lock *rel_lock, CONST_STRPTR obj);
struct Lock * FSParentDir(struct FSVP *vp, int32 *res2, struct Lock *dirlock);
struct Lock * FSDupLockFromFH(struct FSVP *vp, int32 *res2, struct FileHandle *filehandle);
int32  FSOpenFromLock(struct FSVP *vp, int32 *res2, struct FileHandle *file, struct Lock *lock);
struct Lock * FSParentOfFH(struct FSVP *vp, int32 *res2, struct FileHandle *file);
int32  FSOpen(struct FSVP *vp, int32 *res2, struct FileHandle *fh, struct Lock *rel_dir, CONST_STRPTR obj, int32 mode);
int32  FSClose(struct FSVP *vp, int32 *res2, struct FileHandle *file);
int32  FSDelete(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR obj);
int32  FSRead(struct FSVP *vp, int32 *res2, struct FileHandle *file, STRPTR buffer, int32 numbytes);
int32  FSWrite(struct FSVP *vp, int32 *res2, struct FileHandle *file, STRPTR buffer, int32 numbytes);
int32  FSFlush(struct FSVP *vp, int32 *res2);
int32  FSChangeFilePosition(struct FSVP *vp, int32 *res2, struct FileHandle *file, int32 mode, int64 position);
int32  FSChangeFileSize(struct FSVP *vp, int32 *res2, struct FileHandle *file, int32 mode, int64 size);
int64  FSGetFilePosition(struct FSVP *vp, int32 *res2, struct FileHandle *file );
int64  FSGetFileSize(struct FSVP *vp, int32 *res2, struct FileHandle *file );
int32  FSChangeLockMode(struct FSVP *vp, int32 *res2, struct Lock *lock, int32 new_lock_mode);
int32  FSChangeFileMode(struct FSVP *vp, int32 *res2, struct FileHandle *fh, int32 new_lock_mode);
int32  FSSetDate(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, const struct DateStamp *ds);
int32  FSSetProtection(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, uint32 mask);
int32  FSSetComment(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, CONST_STRPTR comment);
int32  FSSetGroup(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, uint32 group);
int32  FSSetUser(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, uint32 user);
int32  FSRename(struct FSVP *vp, int32 *r2, struct Lock *srcl, CONST_STRPTR src, struct Lock *dstl, CONST_STRPTR dst);
int32  FSCreateSoftLink(struct FSVP *vp, int32 *res2, struct Lock *rel_dir, CONST_STRPTR linkname, CONST_STRPTR dest_obj);
int32  FSCreateHardLink(struct FSVP *vp, int32 *res2, struct Lock *rel_dir, CONST_STRPTR linkname, struct Lock *dest_obj);
int32  FSReadSoftLink(struct FSVP *vp, int32 *res2, struct Lock *rel_dir, CONST_STRPTR linkname, STRPTR buf, int32 bufsize);
int32  FSSameLock(struct FSVP *vp, int32 *res2, struct Lock *lock1, struct Lock *lock2);
int32  FSSameFile(struct FSVP *vp, int32 *res2, struct FileHandle *fh1, struct FileHandle *fh2);
int32  FSFileSystemAttr(struct FSVP *vp, int32 *res2, struct TagItem *taglist);
int32  FSVolumeInfoData(struct FSVP *vp, int32 *res2, struct InfoData *info);
int32  FSDeviceInfoData(struct FSVP *vp, int32 *res2, struct InfoData *info);
int32  FSReserved1(struct FSVP *vp, int32 *res2);
struct ExamineData * FSExamineObj(struct FSVP *vp, int32 *res2, struct Lock *lock, CONST_STRPTR object);
struct ExamineData * FSExamineLock(struct FSVP *vp, int32 *res2, struct Lock *lock);
struct ExamineData * FSExamineFile(struct FSVP *vp, int32 *res2, struct FileHandle *file);
int32  FSExamineDir(struct FSVP *vp, int32 *res2, struct PRIVATE_ExamineDirContext *ctx);
int32  FSInhibit(struct FSVP *vp, int32 *res2, int32 inhibit_state);
int32  FSWriteProtect(struct FSVP *vp, int32 *res2, int32 wp_state, uint32 passkey);
int32  FSFormat(struct FSVP *vp, int32 *res2, CONST_STRPTR new_volname, uint32 dostype, uint32 spare);
int32  FSSerialize(struct FSVP *vp, int32 *res2);
int32  FSRelabel(struct FSVP *vp, int32 *res2, CONST_STRPTR new_volumename);
int32  FSReserved3(struct FSVP *vp, int32 *res2);
int32  FSAddNotify(struct FSVP *vp, int32 *res2, struct NotifyRequest *nr);
int32  FSRemoveNotify(struct FSVP *vp, int32 *res2, struct NotifyRequest *nr);
int32  FSLockRecord(struct FSVP *vp, int32 *r2, struct FileHandle *f,int64 oset, int64 len, uint32 m, uint32 tot);
int32  FSUnLockRecord(struct FSVP *vp, int32 *res2, struct FileHandle *file, int64 offset, int64 length);

/****************************************************************************/
#endif /* NO_VECTORPORT_FUNCTION_PROTOTYPES */


/* Typo not picked up until V54 */
#define FSSetOwner FSSetUser







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

#endif    /* DOS_FILEHANDLER_H */
