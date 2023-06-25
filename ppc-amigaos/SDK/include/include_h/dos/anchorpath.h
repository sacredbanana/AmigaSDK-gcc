#ifndef DOS_ANCHORPATH_H
#define DOS_ANCHORPATH_H
/*
**    $VER: anchorpath.h  54.100 (07.09.2020)
**
**    Pattern-matching structure definitions
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/
                      
#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
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

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

/* Forward declaration for below */
struct AChain;
struct AnchorPathOld;

/****************************************************************************/


/****************************************************************************/
/*  Returned by obsolete Examine(), ExamineFH() and ExNext(), it must also be
**  allocated on a 4 byte boundary address.
**
**  This structure is obsolete, due to 4 gig file size limits, short string 
**  length issues and lack of extensibility.
**  Software should migrate to using the new ExamineDir() and the ExamineObject()
**  functions which use the struct ExamineData.   See; dos/dos.h
** 
**  This structure is here because it is nested within other structures and for
**  legacy compatibility reasons, so this definition can't be removed at this time.
**
**  NOTE: The fib_DOSReserved[8] area is ABSOLUTELY DOS PRIVATE !! - Do not access it.
**        DOS uses all of this space for context information when emulating the
**        old V40 functions that require this structure.
*/

struct FileInfoBlock
{
    uint32           fib_DiskKey;        /* -- FILESYSTEM PRIVATE !!                */
    int32            fib_DirEntryType;   /* Use FIB_IS_ macros to identify object.  */
    TEXT             fib_FileName[108];  /* Null terminated.                        */
    uint32           fib_Protection;     /* Bit mask of protection, rwxd are 3-0.   */

    int32            fib_Obsolete;       /* -- OBSOLETE !! - Do not access this.    */
                                         /* Change old source code to reference     */
                                         /* the fib_DirEntryType member instead.    */
                                         /* Handlers should init this to the same   */
                                         /* compatibility value as fib_DirEntryType */

    uint32           fib_Size;           /* Byte size of file, only good to 4 gig   */
    uint32           fib_NumBlocks;      /* Number of blocks in file, max 4 gig     */
    struct DateStamp fib_Date;           /* Date file last changed                  */
    TEXT             fib_Comment[80];    /* Null terminated comment string.         */

    /*
    **  Note: the following two fields are not supported by all filesystems.
    **  They should be initialized to 0 when sending an ACTION_EXAMINE packet.
    **  When Examine() is called, these are set to 0 for you.
    **  AllocDosObject() also initializes them to 0. 
    */
    uint16           fib_OwnerUID;       /* owner's UID */
    uint16           fib_OwnerGID;       /* owner's GID */

    uint32           fib_DOSReserved[8]; /* -- DOS PRIVATE !! - Do not access this. 
                                         **    DOS uses all of this space for the
                                         **    legacy emulation context data.
                                         */
}; 
/* FileInfoBlock - 260 bytes */

/****************************************************************************/
/*  Old types for fib_DirEntryType. NOTE that both USERDIR and ROOT are
**  both directories, softlinks may appear as directories if care is not taken.
**  Always perform directory/file/link checks against these specific values.
*/

#define ST_ROOT         1    /* root directory */
#define ST_USERDIR      2    /* sub directory - some filesystems may return this for root too. */
#define ST_SOFTLINK     3    /* looks like dir, but may point to a file because it a softlink */
#define ST_LINKDIR      4    /* hard link to dir */
#define ST_FILE        -3    /* a real file - must be negative */
#define ST_LINKFILE    -4    /* hard link to file */
#define ST_PIPEFILE    -5    /* for pipes that support ExamineFH */





/***********************************************************************
************************ PATTERN MATCHING ******************************
************************************************************************
*
* Structure expected by MatchFirst, MatchNext.
* You MUST allocate this structure with AllocDosObject() from DOS 50.76+
* to take advantage of the extended features, otherwise it will default
* to the old V40 version of the structure shown below the new one.
*
* If you do not allocate the structure with AllocDosObject() then you may
*   #define USE_OLD_ANCHORPATH  to force the use of the fallback structure.
* Note that the structure must also be on a 4 byte boundary address.
*
* Then, initialize the ADO_Flags with the appropriate bits as follows:
* Set ADO_Mask, (ap_BreakBits) to the signal bitmask (^CDEF) that you want
* to take a break on, if you don't want to convenience the user.
*
* If you want to have the FULL DOS PATH NAME of the matching objects,
* allocate a full path buffer using the tag ADO_Strlen, this will place the
* allocated buffer in ap_Buffer and the size into ap_Strlen.
* Doing this will make DOS build a fully qualified DOS path for the object,
* if this is not required, please do not specifiy the ADO_Strlen tag.
* By default, this will set ap_Strlen to zero, for no full path buffer.
*
* In every situation, the name of the file, and other stats are available in
* the ap_ExData structure if not NULL, (or the FIB ap_Info legacy struct),
* Note that the ap_ExData pointer was NULL prior to V54, so you MUST check
* the pointer before access, when using earlier dos.library releases.
* Always use ap_ExData in preference to the old ap_Info data, because only
* ap_ExData supports 64 bit file sizes and long names > 107 bytes.
*
* PLEASE use the supplied macros below to access the AnchorPath data.
*
* Call MatchFirst() and then afterwards, MatchNext() with this structure.
* You should check the return value each time (see below) and take the
* appropriate action, ultimately calling MatchEnd() when there are
* no more files and you are done.  You can tell when you are done by
* checking for the normal AmigaDOS return code ERROR_NO_MORE_ENTRIES.
*
*****************************************************************************
*/

#ifndef USE_OLD_ANCHORPATH

struct AnchorPath                         /* Redefined for dos 50.76+ (2004) */
{
    uint32               ap_StructSize;   /* Size of this structure.         */
    struct AChain *      ap_Base;         /* Ptr to first anchorchain        */
    struct AChain *      ap_Current;      /* Ptr to current anchorchain      */
    uint32               ap_BreakBits;    /* Bits we want to break on        */
    uint32               ap_FoundBreak;   /* Bits we broke on.               */
    uint32               ap_Flags;        /* The flags bitfield.             */
    struct ExamineData * ap_ExData;       /* Ptr to ExamineData (or NULL)    */
    uint32               ap_Reserved[3];  /* --Reserved for future use       */
    uint32               ap_Strlen;       /* Strlen : Size of the buffer -1  */
    STRPTR               ap_Buffer;       /* Full name, (see ADO_Strlen)     */
    struct FileInfoBlock ap_Info;         /* The legacy FileInfoBlock space  */
    APTR                 ap_DOSPrivate;   /* --PRIVATE, compatibility field. */
    uint32               ap_Private2;     /* --PRIVATE, DOS use only.        */
};


/****************************************************************************/
/*  Always use these compatibility macros to access the AnchorPath data.
**  These will return data from the ExamineData when available or needed, else the FIB.
**  These macros are not available for software using the old anchorpath structure.
*/
#define AP_GET_SIZE(ap)       (((ap)->ap_ExData) ? (ap)->ap_ExData->FileSize : (int64)(ap)->ap_Info.fib_Size)
#define AP_GET_NAME(ap)       (((ap)->ap_ExData) ? (ap)->ap_ExData->Name : (ap)->ap_Info.fib_FileName)
#define AP_GET_COMMENT(ap)    (((ap)->ap_ExData) ? (ap)->ap_ExData->Comment : (ap)->ap_Info.fib_Comment)
#define AP_GET_PROTECTION(ap) (((ap)->ap_ExData) ? (ap)->ap_ExData->Protection : (ap)->ap_Info.fib_Protection)
#define AP_GET_DATE(ap)       (((ap)->ap_ExData) ? &(ap)->ap_ExData->Date : &(ap)->ap_Info.fib_Date)

#define AP_GET_CD_LOCK(ap)    ((ap)->ap_Current->an_Lock)

/****************************************************************************/
/*  Note that the following AP_IS_xxx() macros will only read the fib_DirEntryType member
**  to determine the object type, this is for compatibility with older software that does
**  type morphing with this value alone.
*/
#define AP_IS_FILE(ap)        ((ap)->ap_Info.fib_DirEntryType < 0)
#define AP_IS_DIRECTORY(ap)   ((ap)->ap_Info.fib_DirEntryType > 0 && (ap)->ap_Info.fib_DirEntryType != ST_SOFTLINK)
#define AP_IS_SOFTLINK(ap)    ((ap)->ap_Info.fib_DirEntryType == ST_SOFTLINK)
#define AP_IS_LINKDIR(ap)     ((ap)->ap_Info.fib_DirEntryType == ST_LINKDIR)
#define AP_IS_LINKFILE(ap)    ((ap)->ap_Info.fib_DirEntryType == ST_LINKFILE)

/* any link type */
#define AP_IS_LINK(ap)        ((ap)->ap_Info.fib_DirEntryType == ST_SOFTLINK || \
                               (ap)->ap_Info.fib_DirEntryType == ST_LINKDIR || \
                               (ap)->ap_Info.fib_DirEntryType == ST_LINKFILE)


/****************************************************************************/

#else   /* USE_OLD_ANCHORPATH */
#define   AnchorPath    AnchorPathOld
#endif  /* USE_OLD_ANCHORPATH */

/*****************************************************************************/
/*
**  Obsolete V40 definition ==ONLY== for legacy reference.     
**  This is what DOS will expect when NOT allocated by AllocDosObject().    
**                                                                          
**  #define USE_OLD_ANCHORPATH   ; will force the use of this old definition
**  for old source code that does NOT allocate it with AllocDosObject().    
*/

struct AnchorPathOld
{
    struct AChain *      ap_Base;       /* pointer to first anchor */
    struct AChain *      ap_Current;    /* pointer to current anchor */
    uint32               ap_BreakBits;  /* Bits we want to break on */
    uint32               ap_FoundBreak; /* Bits we broke on. Also returns ERROR_BREAK */
    uint8                ap_Flags;      /* New use for extra word. */
    uint8                ap_Reserved;
    uint16               ap_Strlen;     /* This is what ap_Length used to be */
    struct FileInfoBlock ap_Info;
    TEXT                 ap_Buf[1];     /* Buffer for path name, allocated by user */
};





/****************************************************************************/
/* 
 * Some usefull synonyms.
 */

#define ap_First      ap_Base
#define ap_Last       ap_Current



/***************************************************************************/
/* 
 * Flags for AnchorPath->ap_Flags.
 */

#define APB_DOWILD       0  /* Unused */

#define APB_ITSWILD      1  /* Set by MatchFirst, used by MatchNext.
                               Application can test APB_ITSWILD, too
                              (means that there's a wildcard
                               in the pattern after calling
                               MatchFirst). */

#define APB_DODIR        2  /* Bit is SET if a DIR node should be
                               entered. Application can RESET this
                               bit after MatchFirst/MatchNext to AVOID
                               entering a dir. */

#define APB_DIDDIR       3  /* Bit is SET for an "expired" dir node. */

#define APB_NOMEMERR     4  /* Set on memory error */

#define APB_DODOT        5  /* Unused */

#define APB_DirChanged   6  /* ap_Current->an_Lock changed
                               since last MatchNext call */

#define APB_FollowHLinks 7  /* follow hardlinks on DODIR - defaults
                               to not following hardlinks on a DODIR. */

#define APB_MultiAssigns 8  /* Set this bit via AllocDosObject() to allow
                               Multi-Assign scanning to be enabled.  
                              ( NOTE: ONLY AVAILABLE FROM DOS 50.76+ ) */


#define APF_DOWILD       (1<<APB_DOWILD)
#define APF_ITSWILD      (1<<APB_ITSWILD)
#define APF_DODIR        (1<<APB_DODIR)
#define APF_DIDDIR       (1<<APB_DIDDIR)
#define APF_NOMEMERR     (1<<APB_NOMEMERR)
#define APF_DODOT        (1<<APB_DODOT)
#define APF_DirChanged   (1<<APB_DirChanged)
#define APF_FollowHLinks (1<<APB_FollowHLinks)

#define APF_MultiAssigns (1<<APB_MultiAssigns)  
                         /* New for V50, See AllocDosObject() */


/****************************************************************************/
/* This flag is not available with old structure 8 bit flags field. */

#ifdef USE_OLD_ANCHORPATH
  #undef APB_MultiAssigns
  #undef APF_MultiAssigns
#endif


/****************************************************************************/
/* The public AChain structure. DOS private data extends past the end.      */
#ifndef dos_achain


struct AChain
{
    struct AChain * an_Child;
    struct AChain * an_Parent;
    BPTR            an_Lock;
    /*
    **  an_Lock is the directory lock for the object.
    */
};


#endif /* dos_achain */
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

#endif /* DOS_ANCHORPATH_H */

