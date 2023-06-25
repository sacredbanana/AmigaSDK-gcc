#ifndef LIBRARIES_HUNK_H
#define LIBRARIES_HUNK_H
/*
**    $VER: hunk.h  54.100 (07.09.2020)
**
**    Definitions for the HUNK library loader
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

#define HUNKNAME "hunk.library"

/****************************************************************************/
/* Message structure passed to the hook function calls.                     */

struct HunkMessage 
{
    uint32 hm_StructureSize; /* Always the size of this structure.      */

    APTR   hm_Handle;        /* Set by tag; LH_Handle in LoadHunk().    */
                             /* Set to overlay handle in UnLoadHunk().  */

    APTR   hm_Library;       /* Set by tag; LH_Library exclusively.     */
                                                                
    APTR   hm_Memory;        /* The memory or buffer parameter.         */

    uint32 hm_MemoryAttr;    /* The memory attributes for allocations.  */

    uint32 hm_Length;        /* The size/length parameter.              */
};




/****************************************************************************/
/* Tag definitions for LoadHunkTags()                                       */

#define LH_Dummy              (TAG_USER+750)


#define LH_AllocHook          (LH_Dummy+1) 
   /* (struct Hook *) -- Pointer to the hook structure which has
    *  the h_Entry field pointing to your memory allocation function. 
    *  The hook function shall return NULL on error or a
    *  pointer to the memory block if it succeeds.
    *
    *  Hook function invocation will be;
    *  APTR hook_function( struct Hook *hook, APTR userdata, 
    *                      struct HunkMessage *hm);
    *
    *  The hm_Length field is the size in bytes to allocate.
    *  The hm_MemoryAttr is the memory attribute flags.
    */

#define LH_FreeHook           (LH_Dummy+2) 
   /* (struct Hook *) -- Pointer to the hook structure which has
    *  the h_Entry field pointing to your memory deallocation function.
    *  The hook function return value is ignored.
    * 
    *  Hook function invocation will be;
    *  VOID hook_function( struct Hook *hook, APTR userdata, 
    *                      struct HunkMessage *hm);
    *
    *  The hm_Length field is the size in bytes.
    *  The hm_Memory is the memory block pointer to free.
    */

#define LH_ReadHook           (LH_Dummy+3) 
   /* (struct Hook *) -- Pointer to the hook structure which has
    *  the h_Entry field pointing to your data reading function. 
    *  The hook function shall return -1 on error (Not 0)
    *  or the number of bytes read into memory upon success.
    *
    *  Hook function invocation will be;
    *  int32 hook_function( struct Hook *hook, APTR userdata, 
    *                       struct HunkMessage *hm);
    *
    *  The hm_Length field is the number of bytes to read.
    *  The hm_Memory is the buffer to read the data into.
    */

#define LH_UserData           (LH_Dummy+4) 
   /* (APTR) -- (OPTIONAL) Anything you wish to pass to all
    *  the hook function calls as the "userdata" arg.
    *  Default 0.
    */

#define LH_Handle             (LH_Dummy+5) 
   /* (APTR) -- (OPTIONAL) Pointer to the value that goes 
    *  into the hm_Handle field when calling LoadHunk[tags](). 
    *  You should use this for your file handle pointer.
    *  Default 0.
    */

#define LH_Library            (LH_Dummy+6) 
   /* (APTR) -- (OPTIONAL) Pointer to a library base or an 
    *  interface you may wish to pass to the hook
    *  function in the hm_Library field.  Default 0.
    */

#define LH_FileSize           (LH_Dummy+7) 
   /* (uint32 *) -- (OPTIONAL) Pointer to a longword to return
    *  the size of the binary file.  Default NULL.
    */

#define LH_FileXSum           (LH_Dummy+8) 
   /* (uint32 *) -- (OPTIONAL) Pointer to a longword to return
    *  the 32 bit checksum of the binary file. Default NULL.
    */

#define LH_IoErr              (LH_Dummy+9) 
   /* (int32 *) -- (OPTIONAL) Pointer to a longword to return
    *  the DOS error code if the function fails. 
    *  This will only be valid if the function returns failure.
    *  Default NULL.
    */

#define LH_HunkTable   (LH_Dummy+10)
   /* (APTR) -- (OPTIONAL) Pointer to the hunk table
    *  memory allocation, generally when used to load overlays.
    *  Default 0. 
    */

#define LH_SegList            (LH_Dummy+11)
   /* (BPTR) -- BCPL Pointer to the seglist that is to be freed.
    *  Used in conjunctions with the UnLoadHunk[tags]() fuction.
    */




/****************************************************************************/
/* The following is the old style Overlay hunk file reference header.
 * (First segment only) That was used in the past for overlay hunk files.  
 * This is what the first segment of an overlay hunk file should look like. 
 *
 * Overlay hunk files loaded with LoadHunk() return the BPTR to the seglist
 * header below as a negative BPTR value, (-seglist), you need to negate it
 * before you can use it.   This is for backward compatibility purposes in DOS. 
 *
 * Normal (non overlay) hunk files do not do this.
 */

#define  OVHID  0xABCD
  
struct OverlayHunk
{  
   BPTR   ov_NextSeg;        /* BPTR to the next segment.                    */
   uint32 ov_BRA;            /* Usually a 68K branch instruction to ov_User  */
   uint32 ov_Ident;          /* Identifier value; 0xABCD                     */
   BPTR   ov_Handle;         /* The open filehandle, must close it on unload.*/
   APTR   ov_OverlayTable;   /* APTR pointer to the overlay table.           */
   BPTR   ov_HunkTable;      /* A BPTR to the hunk table.                    */
   int32  ov_GlobVec;        /* Was the BCPL global vector, now -1 as of V50 */
   APTR   ov_User;           /* Actual start of user space, and following... */
};




/****************************************************************************/
/* hunk types - previously found in include file; dos/doshunks.h            */

#define HUNK_UNIT          999
#define HUNK_NAME          1000
#define HUNK_CODE          1001
#define HUNK_DATA          1002
#define HUNK_BSS           1003
#define HUNK_RELOC32       1004
#define HUNK_ABSRELOC32    HUNK_RELOC32
#define HUNK_RELOC16       1005
#define HUNK_RELRELOC16    HUNK_RELOC16
#define HUNK_RELOC8        1006
#define HUNK_RELRELOC8     HUNK_RELOC8
#define HUNK_EXT           1007
#define HUNK_SYMBOL        1008
#define HUNK_DEBUG         1009
#define HUNK_END           1010
#define HUNK_HEADER        1011

#define HUNK_OVERLAY       1013
#define HUNK_BREAK         1014

#define HUNK_DREL32        1015
#define HUNK_DREL16        1016
#define HUNK_DREL8         1017

#define HUNK_LIB           1018
#define HUNK_INDEX         1019

/*
 * Note: V37 LoadSeg uses 1015 (HUNK_DREL32) by mistake.  This will continue
 * to be supported in future versions, since HUNK_DREL32 is illegal in load files
 * anyways.  Future versions will support both 1015 and 1020, though anything
 * that should be usable under V37 should use 1015.
 */
#define HUNK_RELOC32SHORT  1020

/* see ext_xxx below.  New for V39 (note that LoadSeg only handles RELRELOC32).*/
#define HUNK_RELRELOC32    1021
#define HUNK_ABSRELOC16    1022

/*
 * Any hunks that have the HUNKB_ADVISORY bit set will be ignored if they
 * aren't understood.  When ignored, they're treated like HUNK_DEBUG hunks.
 * NOTE: this handling of HUNKB_ADVISORY started as of V39 dos.library!  If
 * loading such executables is attempted under <V39 dos, it will fail with a
 * bad hunk type.
 */
#define HUNKB_ADVISORY    29
#define HUNKB_CHIP        30
#define HUNKB_FAST        31

#define HUNKF_ADVISORY    (1L<<29)
#define HUNKF_CHIP        (1L<<30)
#define HUNKF_FAST        (1L<<31)


/* hunk_ext sub-types */
#define EXT_SYMB        0    /* symbol table */
#define EXT_DEF         1    /* relocatable definition */
#define EXT_ABS         2    /* Absolute definition */
#define EXT_RES         3    /* no longer supported */
#define EXT_REF32     129    /* 32 bit absolute reference to symbol */
#define EXT_ABSREF32    EXT_REF32
#define EXT_COMMON    130    /* 32 bit absolute reference to COMMON block */
#define EXT_ABSCOMMON   EXT_COMMON
#define EXT_REF16     131    /* 16 bit PC-relative reference to symbol */
#define EXT_RELREF16    EXT_REF16
#define EXT_REF8      132    /*  8 bit PC-relative reference to symbol */
#define EXT_RELREF8     EXT_REF8
#define EXT_DEXT32    133    /* 32 bit data relative reference */
#define EXT_DEXT16    134    /* 16 bit data relative reference */
#define EXT_DEXT8     135    /*  8 bit data relative reference */

/* These are to support some of the '020 and up modes that are rarely used */
#define EXT_RELREF32     136    /* 32 bit PC-relative reference to symbol */
#define EXT_RELCOMMON    137    /* 32 bit PC-relative reference to COMMON block */

/* for completeness... All 680x0's support this */
#define EXT_ABSREF16     138    /* 16 bit absolute reference to symbol */

/* this only exists on '020's and above, in the (d8,An,Xn) address mode */
#define EXT_ABSREF8      139    /* 8 bit absolute reference to symbol */

/****************************************************************************/





#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

#endif
