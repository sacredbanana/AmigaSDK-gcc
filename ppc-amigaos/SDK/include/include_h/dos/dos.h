#ifndef DOS_DOS_H
#define DOS_DOS_H
/*
**    $VER: dos.h  54.112 (17.02.2021)
**
**    Standard C header for AmigaDOS
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef DOS_ERRORS_H
#include <dos/errors.h>
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

#define DOSNAME "dos.library"

/****************************************************************************/
/* These are the return codes used by convention by AmigaDOS commands.
 * See FAILAT and IF commands for relevance to EXECUTE files.
 * See RunCommand() and CreateNewProc() for relevance to all DOS processes. 
 */

#define RETURN_OK      0  /* No problems, success */
#define RETURN_WARN    5  /* A warning only, ie; for the shell 'IF' command */
#define RETURN_ERROR  10  /* Something caused a normal sort of error */
#define RETURN_FAIL   20  /* Severe failure, ie; missing system library */


/****************************************************************************/
/* Predefined Amiga DOS global constants */

#define DOSTRUE        (-1L)
#define DOSFALSE       (0L)

#define BITSPERBYTE     8
#define BYTESPERLONG    4
#define BITSPERLONG     32

#define MAXINT32        0x7FFFFFFF
#define MININT32        0x80000000

#define MAXUINT32       0xFFFFFFFF
#define MINUINT32       0

#define MAXINT64        0x7FFFFFFFFFFFFFFFLL
#define MININT64        0x8000000000000000LL

#define MAXUINT64       0xFFFFFFFFFFFFFFFFULL
#define MINUINT64       0ULL


/****************************************************************************/
/* AmigaDOS Strlen() constants that applications MUST be able to handle.
 *
 * Older DosPacket filesystem designs may not be able to support these lengths
 * but newer vector-port style filesystems certainly can and will. 
 *
 * Use IDOS->FileSystemAttr() to find out filesystem specific values.
 * Note that worst-case UTF-8 encodings can use 4 bytes per character.
 *
 * These values are the Strlen() and do not include the nul-terminator byte.
 */

/* Strlen() of the largest AmigaDOS UTF-8 name that can exist. (in bytes) */
#define   MAX_DOS_NAME                255

/* Minimum string length for any AmigaDOS UTF-8 path specification. (in bytes) */
#define   MAX_DOS_PATH                4000

/* Alias... */
#define   MAX_DOS_FILENAME            MAX_DOS_NAME
#define   MAX_DOS_DIRNAME             MAX_DOS_NAME
#define   MAX_DOS_COMMENT             MAX_DOS_NAME

#define   MAX_DOS_VOLUMENAME          MAX_DOS_NAME
#define   MAX_DOS_DEVICENAME          MAX_DOS_NAME
#define   MAX_DOS_ASSIGNNAME          MAX_DOS_NAME

#define   MAX_DOS_SOFTLINK_TARGET     MAX_DOS_PATH


/****************************************************************************/
/* ALL BCPL DATA MUST ALWAYS BE ALIGNED ON A LONG WORD (4 byte) ADDRESS. 
 * BCPL pointers are a long word address (i.e byte address divided by 4 (>>2))
 */

typedef int32 BPTR; /* Long word (BCPL) pointer - must be signed. */
typedef int32 BSTR; /* Long word pointer to BCPL string - must be signed. */

/* BCPL style 'NULL' */
#define ZERO         ((BPTR)0)

/* Convert BPTR to typical C pointer */
#define BADDR(x)     ((APTR)((uint32)(x) << 2))

/* Convert address into a BPTR */
#define MKBADDR(x)   ((BPTR)(((uint32)(x)) >> 2))

/*
 * README -- LEGACY BCPL STRINGS (BSTR):  
 * 
 * BSTR's were originally the BCPL address of a string that has the length
 * in the first byte with the actual string bytes following.  
 * For example, with the original BCPL implementation, the string "SYS"
 * was formatted as: s[0]=3  s[1]='S'  s[2]='Y'  s[3]='S'
 *
 * From V48+, BCPL strings MUST also have a '\0' nul-terminator byte
 * on the end, for safe interoperability with C-strings.
 * The additional nul-terminator byte is not counted in the length byte,
 * neither is the length byte itself.  For example, the same "SYS" string
 * shall now be formatted as: s[0]=3  s[1]='S'  s[2]='Y'  s[3]='S'  s[4]=0
 *
 * DOS library provides functions to handle new standard BSTR's correctly.
 *     IDOS->CopyStringCToBSTR() and IDOS->CopyStringBSTRToC(). 
 *
 * From V53.23+ the dos.library can also send dospackets to handlers with
 * longer strings in a compatibility format called XBSTR. (eXtended BSTR).
 * These strings are the same as new standard BSTR strings other than they
 * may extend to any length in excess of 255 bytes as per C-strings.
 * The legacy length byte of an XBSTR is correct only up to 255 bytes,
 * past that length, it will continue to read 255 (0xFF).
 * The use of XBSTR's in dos.library dospacket calls are always indicated
 * by a documented special validation parameter.  See; dos.dospackets.doc
 */


/****************************************************************************/
/* Handy macros for testing if a given task/process pointer is actually
 * an EXEC task or a DOS process.   V52.
 */

#define IS_PROCESS(x)     (NT_PROCESS==((struct Task *)x)->tc_Node.ln_Type)
#define IS_TASK(x)        (NT_TASK==((struct Task *)x)->tc_Node.ln_Type)


/****************************************************************************/
/* Macro for getting the byte offset of a structure member, usefull for 
 * determining if a newer member is present, given the structure size.  V54.
 */

#define BYTE_OFFSET_IN_STRUCT(structure, structmember) \
                ((uint32)&(((struct structure *)0)->structmember))

/* Example:
 *
 * uint32 offset = BYTE_OFFSET_IN_STRUCT(FindTrackedAddressMsg,ftam_AAS);
 *
 * if( f->ftam_Size > offset )
 * {
 *    struct_includes_member_and_can_be_accessed();
 * }
 */ 


/****************************************************************************/
/* Mode parameter to Open(), all files are positioned at beginning of file. */

#define MODE_OLDFILE        1005    /* Open existing file for read/write,
                                       fails if file doesn't exist. (shared)*/

#define MODE_NEWFILE        1006    /* Open freshly created file, read/write,
                                       deletes an old file. (exclusive)     */

#define MODE_READWRITE      1004    /* Open old file, read/write, creates
                                       file if it doesn't exist. (shared)   */

/****************************************************************************/
/* Relative position to Seek(obsolete) and ChangeFilePosition()  */

#define OFFSET_BEGINNING     -1     /* relative to Begining Of File */
#define OFFSET_CURRENT        0     /* relative to Current file position */
#define OFFSET_END            1     /* relative to End Of File      */


/****************************************************************************/
/* Passed as 'accessMode' to Lock() */

#define SHARED_LOCK     -2    /* Object is accessible by all others */
#define ACCESS_READ     -2    /* Somewhat misleading old synonym */

#define EXCLUSIVE_LOCK  -1    /* No other access is allowed */
#define ACCESS_WRITE    -1    /* Somewhat misleading old synonym */

/****************************************************************************/
/* Flags for the bitmasks returned by LockTags() when using LK_InfoMask tag.
 * These provide detailed information on the string being resolved.  V53.57 
 */

#define  LOCKB_SOFTLINK_MIDPART   8  
  /* One or more soft links were found in the middle of the path */
  /* but none of these formed the last component of the path.    */

#define  LOCKB_SOFTLINK_ENDPART   9
  /* One soft link exists as the last component of the path. */
 
#define  LOCKB_DEVICE            16
  /* The supplied path is a device relative specification. */
 
#define  LOCKB_VOLUME            17
  /* The supplied path is a volume relative specification. */
 
#define  LOCKB_ASSIGNMENT        18
  /* The supplied path is an assignment relative specification. */
 
#define  LOCKB_PROGDIR           19
  /* The supplied path is a PROGDIR: relative specification. */
 
#define  LOCKB_CURRDIR           20
  /* The supplied path is a CURRDIR: relative specification. */

#define  LOCKB_ROOTDIR           21
  /* The supplied path is a root directory relative specification. */

#define  LOCKB_FILESYS           24
  /* The supplied path returned the root of the default filesystem. */

/* Field definitions of the above. */
#define  LOCKF_SOFTLINK_MIDPART    (1L<<LOCKB_SOFTLINK_MIDPART)  
#define  LOCKF_SOFTLINK_ENDPART    (1L<<LOCKB_SOFTLINK_ENDPART)
#define  LOCKF_DEVICE              (1L<<LOCKB_DEVICE)
#define  LOCKF_VOLUME              (1L<<LOCKB_VOLUME)
#define  LOCKF_ASSIGNMENT          (1L<<LOCKB_ASSIGNMENT)
#define  LOCKF_PROGDIR             (1L<<LOCKB_PROGDIR)
#define  LOCKF_CURRDIR             (1L<<LOCKB_CURRDIR)
#define  LOCKF_ROOTDIR             (1L<<LOCKB_ROOTDIR)
#define  LOCKF_FILESYS             (1L<<LOCKB_FILESYS)

/****************************************************************************/
/* Result flags for WaitForData(). */

#define WFDB_READ     0  /* Stream has data ready to be read */
#define WFDB_WRITE    1  /* Stream is ready to accept more data to be written.*/

#define WFDF_READ    (1<<WFDB_READ)
#define WFDF_WRITE   (1<<WFDB_WRITE)

/****************************************************************************/
/* NotifyProcListChange(), NotifyDosListChange(), termination signal value. */

#define NPLC_END     0xFFFFFFFFUL
#define NDLC_END     0xFFFFFFFFUL

/****************************************************************************/
/* SetBlockingMode() mode values which define whether read/write access to a
   stream will block until a request is satisfied or will return immediately.*/

#define SBM_BLOCKING        1
#define SBM_NON_BLOCKING    2

/****************************************************************************/
/* GetPID() function, this flag determins which PID is returned.     53.58  */

#define   GPID_PROCESS      1
#define   GPID_PARENT       2

/****************************************************************************/

struct DateStamp
{
    int32   ds_Days;     /* Number of days since 1 Jan 1978 */
    int32   ds_Minute;   /* Number of minutes past midnight */
    int32   ds_Tick;     /* Number of ticks past minute */
}; 
/* DateStamp */

#define TICKS_PER_SECOND 50    /* Fifty ticks = one second  */
                               /* One tick = twenty milliseconds */

/****************************************************************************/
/* V52 Struct ExamineData, returned by ExamineObject() and ExamineDir().
 * This structure supports unlimited string lengths, 64 bit file sizes,
 * automatic resolution of link targets and extended auxilliary information.
 *
 * NOTE; Applications DO NOT allocate these, the filesystem does it.
 *       Also, the filesystem itself must always allocate these using
 *       AllocDosObject(), otherwise they will simply not work.
 */ 

struct  ExamineData
{ 
    struct MinNode   EXDnode;     /* MinList node.                           */
    uint32           EXDinfo;     /* General purpose user data.     [Note 0] */

    /* Private members exclusively for the FS & DOS, never change these.     */
    uint32           Reserved0;   /* DOS RESERVED.                           */
    uint32           FSPrivate;   /* FILESYSTEM ONLY - Private usage.        */
    APTR             DOSPrivate;  /* DOSLIB ONLY - Private context.          */
                                  /*                                         */
    /* The following are public fields.                                      */
    uint32           StructSize;  /* (RO) Full size of the structure.        */
    uint32           Type;        /* Entry type; use EXD_IS_ macros below.   */
    int64            FileSize;    /* Size of a file, otherwise set to -1LL.  */
    struct DateStamp Date;        /* Days, Mins, Ticks.                      */
    uint32           RefCount;    /* Object hardlink references.    [Note 1] */
    uint64           ObjectID;    /* Unique object identifier.      [Note 2] */
    STRPTR           Name;        /* (RO) Object name string.                */
    uint32           NameSize;    /* (RO) Allocated size of the name buffer. */
    STRPTR           Comment;     /* (RO) Comment string for Files and Dirs. */
    uint32           CommentSize; /* (RO) Allocated size of comment buffer.  */
    STRPTR           Link;        /* (RO) Target name for links.    [Note 3] */
    uint32           LinkSize;    /* (RO) Allocated size of target buffer.   */
    uint32           Protection;  /* Protection status bitmask.              */
    uint32           OwnerUID;    /* User info.  [Note 4]                    */
    uint32           OwnerGID;    /* Group info. [Note 4]                    */
    uint32           Reserved2;   /* DOS reserved field.                     */
    uint32           Reserved3;   /* DOS reserved field.                     */
    uint32           Reserved4;   /* DOS reserved field.                     */
};
/*	(RO) = Read Only, these fields must not be modified by anyone but DOS.   */

/*
 * [Note 0] This is a general purpose field for use by anyone for anything.
 *          Neither DOS or the FileSystem will ever touch this, although DOS
 *          does guarantee it is always initialised to zero when allocated.
 *
 * [Note 1] If possible, this field should be supported by filesystems that
 *          support hardlinks, it is used to indicate the hardlink reference
 *          count for objects.  A value of one indicates that the object has
 *          no additional references other than itself, a value of two will
 *          indicate that it has one additional hardlink reference,
 *          a value of three means it has two hardlink references, etc...
 *          All hardlinks themselves always show a value of 1 in this field
 *          when supported, otherwise this field MUST be set to zero for
 *          all objects, if the filesystem does not support it.
 *          It will be undefined if the caller fails to specify the
 *          EXF_REFCOUNT bit in the EX_DataFields mask.
 *
 * [Note 2] This field is the mandatory unique object identfier for all
 *          objects on this volume, the value used here may be any arbitrary
 *          value as long as it is unique from all other objects on this
 *          volume, it may use the object node address, the disk header block
 *          number or other such values. (Note: this field is 64 bits wide.)
 *          This field will be undefined if you fail to specify the
 *          EXF_OBJECTID bit in the EX_DataFields mask.
 *
 * [Note 3] This field contains the target object name and possible path for
 *          a softlink, it may be an absolute path specification or a softlink
 *          directory relative specification, it can also reference a path
 *          on another disk volume that may or may not be currently mounted,
 *          this field is used by DOS to resolve softlinks.
 *          For hard links, this contains just the target object name,
 *          this is not used by DOS and is here for semantical reasons only.
 *          For all other objects, this will be a nul-string. ("")
 *          This field will be undefined if you fail to specify the EXF_LINK
 *          bit in the EX_DataFields mask.
 *
 * [Note 4] Historically, these fields only used the low 16 bits.
 *          For extensibility, the size of these are now 32 bit fields.
 *          However, for interoperability, it is recommended that values
 *          greater than 65535 be avoided where possible so reading only
 *          the low 16 bits results in the same value for legacy applications.
 *          These fields will be undefined if you fail to specify the
 *          EXF_OWNER bit in the EX_DataFields mask.
 *          (See extended information relating to the UID/GID fields below.)
 */


/****************************************************************************/
/* DOS USE ONLY - internal SDK version test. */
#define  V54_SDK  (1<<16)   


/****************************************************************************/
/* EX_DataFields tag, bit mask field values that determine
 * what data is returned from the ExamineDir() function.
 *
 * The data value returned in the respective fields will be undefined
 * if the mask bit is not specified, NEVER assume otherwise.
 */

#define  EXF_DATE         (1<<0)
#define  EXF_REFCOUNT     (1<<1)
#define  EXF_NAME         (1<<2)
#define  EXF_COMMENT      (1<<3)
#define  EXF_LINK         (1<<4)
#define  EXF_PROTECTION   (1<<5)
#define  EXF_OWNER        (1<<6)
#define  EXF_TYPE         ((1<<7)|V54_SDK)
#define  EXF_SIZE         (1<<8)
#define  EXF_OBJECTID     (1<<9)

#define  EXF_spare6       (1<<10)  /* Reserved for future EXF_ALL feature */
#define  EXF_spare5       (1<<11)  /* Reserved for future EXF_ALL feature */
#define  EXF_spare4       (1<<12)  /* Reserved for future EXF_ALL feature */
#define  EXF_spare3       (1<<13)  /* Reserved for future EXF_ALL feature */
#define  EXF_spare2       (1<<14)  /* Reserved for future EXF_ALL feature */
#define  EXF_spare1       (1<<15)  /* Reserved for future EXF_ALL feature */
#define  EXF_dosprivate0  (1<<16)  /* For internal dos use */

#define  EXF_ALL          (0xFFFF|V54_SDK)  /* Return all of the above. */


/****************************************************************************/
/* Values for ExamineData->Type for checking what kind of object it describes. 
 * The lower 8 bits form the unique descriptor value, the upper bits are used 
 * as a bitmask. The FSO_TYPE_MASK is used to filter the descriptor value. 
 */
#define FSO_TYPE_SOFTLINK   0      /* Object is a softlink */
#define FSO_TYPE_FILE       1      /* Object is a file */
#define FSO_TYPE_DIRECTORY  2      /* Object is a directory */
#define FSO_TYPE_PIPE       3      /* Object is a pipe stream */
#define FSO_TYPE_SOCKET     4      /* Object is a socket stream */
#define FSO_TYPE_INVALID    0xFE   /* Object is unidentifiable.
                                    * This value SHOULD never actually be seen,
                                    * it is reserved for use by the handler
                                    * and DOS to indicate internal issues.
                                    * eg; It MAY be possible to see this value if
                                    * reading the 'Type' member without setting
                                    * the EXF_TYPE bit in EX_DataFields.
                                    */

#define FSO_TYPE_MASK       0xFF    /* Mask for above object type descriptors */

#define FSOF_LINK           (1<<8)  /* Bit set for FFS style hard & soft links */

#define FSOF_ALTLINK        (1<<9)  /* Reserved bit for alternate style links, */
                                    /* -- these are currently unimplemented.   */

#define FSOF_EMULATED       (1<<10) /* Set when DOS emulates this call. 54.93+ */

#define FSOF_UNASSIGNED11   (1<<11) /* Bits 11...23 are unassigned, reserved by DOS. */

/*
 *  DEVELOPERS;
 *  The following V54 Examinedata->Type flag bits are reserved exclusively
 *  for the handlers private use, these 8 bits may be used for any purpose. 
 */
#define FSOF_FSPRIVATE24    (1<<24)
#define FSOF_FSPRIVATE25    (1<<25)
#define FSOF_FSPRIVATE26    (1<<26)
#define FSOF_FSPRIVATE27    (1<<27)
#define FSOF_FSPRIVATE28    (1<<28)
#define FSOF_FSPRIVATE29    (1<<29)
#define FSOF_FSPRIVATE30    (1<<30)
#define FSOF_FSPRIVATE31    (1<<31)


/****************************************************************************/
/* Macros for identifying what kind of basic object an ExamineData 'Type' is.
 * The EXF_TYPE bit must be specified in the EX_DataFields tag for the
 * macros below to work otherwise random values will be returned in 'Type'.
 *
 * NB:  TEST FOR ALL LINK TYPES FIRST.
 *      The object type macros below this always mask out the attribute bits,
 *      therefore it is mandatory to always check for all links first.
 */
#define EXD_IS_LINK(exd)        ((exd)->Type & (FSOF_LINK|FSOF_ALTLINK))


/*
 * Object types;
 */
#define EXD_IS_SOFTLINK(exd)    (((exd)->Type & FSO_TYPE_MASK) == FSO_TYPE_SOFTLINK)
#define EXD_IS_FILE(exd)        (((exd)->Type & FSO_TYPE_MASK) == FSO_TYPE_FILE)
#define EXD_IS_DIRECTORY(exd)   (((exd)->Type & FSO_TYPE_MASK) == FSO_TYPE_DIRECTORY)
#define EXD_IS_PIPE(exd)        (((exd)->Type & FSO_TYPE_MASK) == FSO_TYPE_PIPE)
#define EXD_IS_SOCKET(exd)      (((exd)->Type & FSO_TYPE_MASK) == FSO_TYPE_SOCKET)
/*
 * Note; EXD_IS_FILE() returns truth for a plain file or a hard file link,
 * same for  EXD_IS_DIRECTORY() with a plain directory or hard directory link.
 * This allows hard links to work just like regular files and directories.
 * Use EXD_IS_LINK() as the FIRST test, if required to differentiate.  
 */


#define EXD_IS_EMULATED(exd)      ((exd)->Type & FSOF_EMULATED)
/*
 * Added in DOS 54.93.
 * When this returns truth, it means DOS emulated this call by falling back 
 * and using one of the old limited 32 bit filesystem functions.
 * This also means fallback limitation can apply to the data, such limitations
 * may include truncated strings and/or reported file sizes limited to 4 gig max
 * or other unspecified quirks that can occur using the old calls.
 */


#define EXD_TYPE(exd)   ((exd)->Type & (FSO_TYPE_MASK|FSOF_LINK|FSOF_ALTLINK))
/* 
 * This extracts the object type identifier value along with the link bits
 * and masks out all the other bits that are not relevant for type comparisons.
 * This also provides upward compatibility by not assuming that currently
 * unassigned bits would always be zero.
 */ 




/****************************************************************************
 * Information relating to the ExamineData; OwnerUID and OwnerGID members.
 *  
 * AmigaDOS permissions are NOT the same as the standard UNIX values.
 * For the DOS/Filesystem UID/GID values;
 *
 *     [nobody/nogroup] = 0       (instead of 65534),
 *     [root/wheel]     = 65535   (instead of 0).
 *
 * These only apply to DOS and the Filesystems, but the C and usergroup
 * libraries use the standard UNIX permissions, where;
 *
 *     [nobody/nogroup] = 65534. 
 *     [root/wheel]     = 0.
 *
 * The AmigaOS C libraries convert between these two protocols.
 */

#define  DOS_OWNER_ROOT     65535
#define  DOS_OWNER_NONE     0


/****************************************************************************
 * Definitions for the ExamineData "Protection" bitfield.
 *
 * EXDB are bit definitions, EXDF are field definitions.
 * Regular RWED bits (0...3) are 0 == allowed. [ie: Negated function]
 *
 * NOTE: GRP and OTR RWED permissions are 0 == not allowed!
 * Group and Other permissions are not directly handled by the filesystem, only stored.
 *
 */

/****************************************************************************/
/* Defined protection bits.  */
/* Unsurprisingly, these just happen to coincide with the old FIB protection bits. */

#define EXDB_OTR_READ         15    /* Other: file is readable */
#define EXDB_OTR_WRITE        14    /* Other: file is writable */
#define EXDB_OTR_EXECUTE      13    /* Other: file is executable */
#define EXDB_OTR_DELETE       12    /* Other: file is deletable */
#define EXDB_GRP_READ         11    /* Group: file is readable */
#define EXDB_GRP_WRITE        10    /* Group: file is writable */
#define EXDB_GRP_EXECUTE       9    /* Group: file is executable */
#define EXDB_GRP_DELETE        8    /* Group: file is deletable */

#define EXDB_HOLD              7    /* (H) Hold in shell resident list, must also be (P) */
#define EXDB_SCRIPT            6    /* (S) Script file for the "Execute" command */
#define EXDB_PURE              5    /* (P) Pure, program is reentrant and reexecutable */
#define EXDB_ARCHIVE           4    /* (A) Archived, cleared by FS whenever object is changed */
#define EXDB_NO_READ           3    /* (R) NOT readable  */
#define EXDB_NO_WRITE          2    /* (W) NOT writable  */
#define EXDB_NO_EXECUTE        1    /* (E) NOT executable, (used by Shell handler only) */
#define EXDB_NO_DELETE         0    /* (D) NOT deletable */

/*
 *  Note that when bits 0,1,2,3  are set, this represent a negated function. 
 *  Early contrarily named definitions have been moved to dos/obsolete.h
 */

/****************************************************************************/
/* Field definitions for above bits */

#define EXDF_OTR_READ         (1L<<EXDB_OTR_READ)
#define EXDF_OTR_WRITE        (1L<<EXDB_OTR_WRITE)
#define EXDF_OTR_EXECUTE      (1L<<EXDB_OTR_EXECUTE)
#define EXDF_OTR_DELETE       (1L<<EXDB_OTR_DELETE)
#define EXDF_GRP_READ         (1L<<EXDB_GRP_READ)
#define EXDF_GRP_WRITE        (1L<<EXDB_GRP_WRITE)
#define EXDF_GRP_EXECUTE      (1L<<EXDB_GRP_EXECUTE)
#define EXDF_GRP_DELETE       (1L<<EXDB_GRP_DELETE)

#define EXDF_HOLD             (1L<<EXDB_HOLD)
#define EXDF_SCRIPT           (1L<<EXDB_SCRIPT)
#define EXDF_PURE             (1L<<EXDB_PURE)
#define EXDF_ARCHIVE          (1L<<EXDB_ARCHIVE)
#define EXDF_NO_READ          (1L<<EXDB_NO_READ)
#define EXDF_NO_WRITE         (1L<<EXDB_NO_WRITE)
#define EXDF_NO_EXECUTE       (1L<<EXDB_NO_EXECUTE)
#define EXDF_NO_DELETE        (1L<<EXDB_NO_DELETE)

/*
 * The following define is the default protection mask value for new objects.
 * This equates to the attributes; R,W,E,D
 */
#define EXDF_DEFAULT   0
  

/****************************************************************************/
/* Standard semantical maximum length for an error string from fault/printfault. 
 * However, most error strings should be kept under 60 characters if possible.
 * Don't forget space for the header you pass in. 
 */

#define FAULT_MAX  82



/****************************************************************************/
/* For the old Info() function, the structure must be on a 4 byte boundary.
 * The new V51+ GetDiskInfo() doesn't require special structure alignment. 
 * Just use AllocDosObject(DOS_INFO,0); to get the right one every time.
 *
 * The id_BytesPerBlock may, or may not, always be the same value as the
 * low level media blocksize, it generally will be, however this value can
 * be adjusted in some cases to yield the correct result when used with
 * extremely large storage devices, so it should always be treated as an
 * abstract "block" by applications.  See also; GetDiskFileSystemData()
 *
 * The id_VolumeNode field may or may not be a reference to an actual doslist
 * volume node, it is completely dependant on the handler type.
 * Not all handlers will supply this, or exactly this information.
 * Non-filesystems may use this field for other completely incompatible
 * purposes, for example, the con-handler may return a pointer to the console
 * window here.  This field should be treated with extreme caution.
 * Note that it can also be ZERO!
 *
 * The id_UseCount field shall be set to zero if there are no locks (or files)
 * active on this handler, otherwise, the non-zero value returned from some
 * older handlers may be an entirely arbitrary non-zero boolean value,
 * but more frequently a DOSTRUE (-1) value.
 * From V50+ filesystems should return an integer for the number of active
 * locks/files currently in use. 
 * Stream handlers should indicate the number of streams currently open.
 * The con-handler also uses this field for a completely different and
 * incompatible purpose, such as storing a pointer to the console I/O request.
 * As with id_VolumeNode this field should be treated with caution.
 *
 * The first two fields of this structure are deprecated and are now reserved
 * for future expansion, handler developers should leave these set to zero. 
 */

struct InfoData
{
    int32  id_Reserved1;        /* Reserved for expansion; See GetDiskInfo() for more info. */
    int32  id_Reserved2;        /* Reserved for expansion; See GetDiskInfo() for more info. */
    int32  id_DiskState;        /* Disk/Media Status, See defines below */
    uint32 id_NumBlocks;        /* Number of "blocks" on disk */
    uint32 id_NumBlocksUsed;    /* Number of "blocks" in use */
    uint32 id_BytesPerBlock;    /* The size in bytes of a "block" */
    int32  id_DOSType;          /* Handler DOSType code, see defines below */
    BPTR   id_VolumeNode;       /* BCPL pointer to volume node (see DosList) */
    int32  id_UseCount;         /* Use count, zero if not in use */
}; 
/* InfoData */

/* old name synonym */
#define id_DiskType id_DOSType
#define id_InUse    id_UseCount


/*
 *  Disk/Media states for; id_DiskState
 */
#define ID_DISKSTATE_WRITE_PROTECTED  80   /* Disk is write protected */
#define ID_DISKSTATE_VALIDATING       81   /* Disk is validating or waiting for media */
#define ID_DISKSTATE_VALIDATED        82   /* Disk is consistent and writeable */

/* NOTE: ID_DISKSTATE_VALIDATING means the medium may be readable
 *       and is currently being prepared to make it writable again.
 *       This is also used as the default "waiting" or "parked" state
 *       when the filesystem is waiting for media to be inserted and validated,
 *       or the file system is in an unknown state and unable to return
 *       meaningfull information about the medium.
 *
 *       Always refer to this in conjunction with id_DOSType to gain the full
 *       status of handlers that are in a non-functional state.
 *
 *       New ID_DISKSTATE values will likely be added for future media features.
 *
 *       Some older handlers are known to already return values other than those
 *       specified above, so write code in a way that has a default case to
 *       handle all undocumented values being presented in a suitable way.
 *       Also, be prepared for negative 1 and 0 cases.
 *       
 *       
 */



/*
 *  Special status indicator DOS type codes for; id_DOSType 
 */
#define ID_NO_DISK_PRESENT    (-1)
#define ID_UNREADABLE_DISK    (0x42414400)    /* 'BAD\0'  */
#define ID_BUSY_DISK          (0x42555359)    /* 'BUSY'   */
#define ID_NOT_REALLY_DOS     (0x4E444F53)    /* 'NDOS'   */

/* The following are the standard and historic FFS DOS types.*/ 
#define ID_DOS_DISK           (0x444F5300)    /* 'DOS\0'  */
#define ID_FFS_DISK           (0x444F5301)    /* 'DOS\1'  */
#define ID_INTER_DOS_DISK     (0x444F5302)    /* 'DOS\2'  */
#define ID_INTER_FFS_DISK     (0x444F5303)    /* 'DOS\3'  */
#define ID_FASTDIR_DOS_DISK   (0x444F5304)    /* 'DOS\4'  */
#define ID_FASTDIR_FFS_DISK   (0x444F5305)    /* 'DOS\5'  */
#define ID_LONGNAME_DOS_DISK  (0x444F5306)    /* 'DOS\6'  */
#define ID_LONGNAME_FFS_DISK  (0x444F5307)    /* 'DOS\7'  */

/* Other miscellaneous DOS types. */
#define ID_SWAP_DISK          (0x53574150)    /* 'SWAP'   swap partition  */
#define ID_KICKSTART_DISK     (0x4B49434B)    /* 'KICK'   kickstart disk  */
#define ID_CDFS_DISK          (0x43443031)    /* 'CD0\31  CDFileSystem    */

/* V53+ DOS types used for new vector-port based filesystems */
#define ID_RAM_DISK           (0x52414D01)    /* 'RAM\1' ram-handler      */
#define ID_ENV_DISK           (0x454E5601)    /* 'ENV\1' env-handler      */
#define ID_APPDIR_DISK        (0x41504401)    /* 'APD\1' appdir-handler   */
#define ID_NGF0_DISK          (0x4E474600)    /* 'NGF\0' NGFS filesystem  */    
#define ID_NGF1_DISK          (0x4E474601)    /* 'NGF\1' NGFS filesystem  */    
#define ID_VP255_DOS_DISK     (0x56504600)    /* 'VPF\0  fsvptool example */

/* Special 'DOS type' signatures returned by con-handler  */
#define ID_CON                (0x434F4E00)    /* 'CON\0'  */
#define ID_RAWCON             (0x52415700)    /* 'RAW\0'  */

/* Other known DOS types */  
#define ID_MSDOS_DISK         (0x4D534400)    /* 'MSD\0   */
#define ID_MSDOS_DISK_HD      (0x4D534800)    /* 'MSH\0'  */
#define ID_MSDOS_DISK_DS      (0x4D444400)    /* 'MDD\0'  */
#define ID_SFS0_DISK          (0x53465300)    /* 'SFS\0'  */
#define ID_SFS2_DISK          (0x53465302)    /* 'SFS\2'  */

/* FAT DOS types */
#define ID_FAT00_DISK         (0x46415400)    /* 'FAT\0'  */
#define ID_FAT01_DISK         (0x46415401)    /* 'FAT\1'  */
#define ID_FAT32_DISK         (0x46415432)    /* 'FAT\32' */

/* FUSE filesystems DOS type codes */
#define ID_BOX0_DISK          (0x424F5800)    /*  BOX\0 - BoxFileSystem */
#define ID_EXFAT_DISK         (0x46415458)    /*  FATX  - ExFATFileSystem */
#define ID_EXT2_DISK          (0x45585402)    /*  EXT\2 - FuseExt2FileSystem */
#define ID_HFS_DISK           (0x48465300)    /*  HFS\0 - FuseHFS  */
#define ID_NTFS_DISK          (0x4e544653)    /*  NTFS  - NTFileSystem3G */

/* Other misc DosTypes that may be encountered, third party or otherwise;
 *
 * DosTypes used for Unix partitions in the RDB:
 *    Amix (Commodore Amiga Unix for the A3000UX): 'UNI\0', 'UNI\1'
 * NetBSD (used by OpenBSD as well): 
 *    'NBR\7' (root partition), 'NBU\7' (others partitions), 'NBS\1' (swap partition)
 * Linux: 'LNX\0', 'SWP\0' (swap partition)
 * Ami File Safe: 'AFS\0', 'AFS\1'
 * Berkeley Fast Filesystem: 'BFFS'
 * Professional File System: 'PFS\0', 'PFS\1', 'PFS\2', 'PFS\3'
 * Smart File System, AROS little endian version: 'sfs\0'
 *
 */


/****************************************************************************/
/* Bit numbers that signal that a user has issued a break */

#define SIGBREAKB_CTRL_C 12
#define SIGBREAKB_CTRL_D 13
#define SIGBREAKB_CTRL_E 14
#define SIGBREAKB_CTRL_F 15

/*
 *  Bit fields that signal that a user has issued a break,
 *  See IDOS->CheckSignal() for examples. 
 */
#define SIGBREAKF_CTRL_C (1L<<SIGBREAKB_CTRL_C)
#define SIGBREAKF_CTRL_D (1L<<SIGBREAKB_CTRL_D)
#define SIGBREAKF_CTRL_E (1L<<SIGBREAKB_CTRL_E)
#define SIGBREAKF_CTRL_F (1L<<SIGBREAKB_CTRL_F)

/****************************************************************************/
/* Values returned by SameLock() */

#define LOCK_DIFFERENT     -1
#define LOCK_SAME           0
#define LOCK_SAME_VOLUME    1    /* locks are on same volume */

/****************************************************************************/
/* Values returned by SameFH() */

#define FH_DIFFERENT     -1
#define FH_SAME           0
#define FH_SAME_VOLUME    1    /* filehandles are on same volume */

/****************************************************************************/
/* 'Flags' bitfield definitions for Format() and FormatPort()  (v54.81) */
/* Only the first one is in use so far. */

#define FMTF_AddRecycled  (1<<0)
#define FMTF_spare1       (1<<1)
#define FMTF_spare2       (1<<2)

/****************************************************************************/
/* Types for ChangeMode() */

#define CHANGE_LOCK    0
#define CHANGE_FH      1

#define CHANGE_MODE_SHARED      SHARED_LOCK
#define CHANGE_MODE_EXCLUSIVE   EXCLUSIVE_LOCK

/****************************************************************************/
/* Mode parameter for DevNameFromLock() and DevNameFromFH() */

#define DN_DEVICEONLY  0
#define DN_FULLPATH    1
#define DN_ROOTPATH    2

/****************************************************************************/
/* The following is used by the new V51 tag;  NP_NotifyOnDeathMessage
 * See CreateNewProc() autodoc for more details.
 */

struct DeathMessage
{
    struct Message dm_Msg;    /* Embedded exec message structure.           */
    int32  dm_ReturnCode;     /* Primary process return code, set by DOS    */
    int32  dm_Result2;        /* The value returned from IoErr(),set by DOS */
};

/****************************************************************************/
/* The following is the data structure to be used for FReadLine()
 * which is allocated by the AllocDosObject() function ONLY.
 */

struct FReadLineData
{
    STRPTR   frld_Line;           /* NUL-terminated string */
    uint32   frld_LineLength;     /* what strlen(frld_Line) would return */
    uint32   frld_DosPrivate[8];  /* -- internal dos.library use only */
};

/****************************************************************************/
/* Mode flags for GetProcSegList()   (v51.88) */

#define GPSLF_CLI    (1<<1)
#define GPSLF_SEG    (1<<2)
#define GPSLF_ENT    (1<<3)
#define GPSLF_RUN    (1<<4)

/****************************************************************************/
/* Values for MakeLink() - DO NOT use random values, new link types will
 * be added in the future that require other values to be used. 
 */

#define LINK_HARD      0
#define LINK_SOFT      1

/****************************************************************************/
/* Values returned by ReadItem (and ReadLineItem V50) */

#define ITEM_EQUAL    -2    /* "=" Symbol */
#define ITEM_ERROR    -1    /* error */
#define ITEM_NOTHING   0    /* *N, ;, endstreamch */
#define ITEM_UNQUOTED  1    /* unquoted item */
#define ITEM_QUOTED    2    /* quoted item */

/****************************************************************************/
/* Types for AllocDosObject/FreeDosObject */

#define DOS_FILEHANDLE      0   /* Very few people should use this */
#define DOS_EXALLCONTROL    1   /* Must be used to allocate this! - Obsolete struct */
#define DOS_FIB             2   /* may be useful - not really, it's obsolete now */
#define DOS_STDPKT          3   /* for doing packet-level I/O */
#define DOS_CLI             4   /* for shell-writers, etc */
#define DOS_RDARGS          5   /* for ReadArgs if you pass it in */
#define DOS_ANCHORPATH      6   /* for MatchFirst/MatchNext (V50) */
#define DOS_INFODATA        7   /* for Info() aligned InfoData (V50) */
#define DOS_NOTIFYREQUEST   8   /* for Notify request functions (V51)  */
#define DOS_LOCK            9   /* for filesystem lock allocations (V51) */
#define DOS_FREADLINEDATA  10   /* for FReadLine() structure. (V51) */
#define DOS_EXAMINEDATA    11   /* for filesystem ExamineData allocations.(V51) */ 
#define DOS_DOSLIST        12   /* for struct DosList allocations. (V52.16) */
#define DOS_VOLUMELIST     13   /* for struct list with attached nodes. (V53.52) */
#define DOS_FSVECTORPORT   14   /* for filesystem vector port creation. (V53.80) */


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

#endif /* DOS_DOS_H */
