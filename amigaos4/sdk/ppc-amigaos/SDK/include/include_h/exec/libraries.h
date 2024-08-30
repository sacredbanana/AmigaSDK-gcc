#ifndef EXEC_LIBRARIES_H
#define EXEC_LIBRARIES_H
/*
**    $VER: libraries.h 53.29 (10.8.2015)
**
**    Definitions for use when creating or using Exec libraries
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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
#elif defined(__SASC)
   #pragma msg 79 ignore push
#endif

/****************************************************************************/

/*------ Special Constants ---------------------------------------*/
/* Note: This only applies to "legacy" 68k-based functions */
enum enLibConstants
{
    LIB_VECTSIZE = 6,    /* Each library entry takes 6 bytes */
    LIB_RESERVED = 4,    /* Exec reserves the first 4 vectors */
    LIB_BASE     = (-LIB_VECTSIZE),
    LIB_USERDEF  = (LIB_BASE-(LIB_RESERVED*LIB_VECTSIZE)),
    LIB_NONSTD   = (LIB_USERDEF)
};

/*------ Standard Functions --------------------------------------*/
/* Note: This only applies to "legacy" 68k-based functions */
enum enStandardFunctions
{
    LIB_OPEN    = (- 6),
    LIB_CLOSE   = (-12),
    LIB_EXPUNGE = (-18),
    LIB_EXTFUNC = (-24) /* for future expansion */
};

/*------ Library Base Structure ----------------------------------*/
/* Also used for Devices and some Resources */
struct Library
{
    struct Node lib_Node;
    uint8       lib_Flags;
    uint8       lib_ABIVersion; /* ABI exported by library */
    uint16      lib_NegSize;    /* number of bytes before library */
    uint16      lib_PosSize;    /* number of bytes after library */
    uint16      lib_Version;    /* major */
    uint16      lib_Revision;   /* minor */
    APTR        lib_IdString;   /* ASCII identification */
    uint32      lib_Sum;        /* the checksum itself */
    uint16      lib_OpenCnt;    /* number of current opens */
}; /* Warning: size is not a longword multiple! */

#define lib_pad lib_ABIVersion

/* lib_ABIVersion definitions */
enum enABIVersion
{
    LIBABI_68K    = 0, /* A 68k library (pre OS4) */
    LIBABI_MIFACE = 1  /* V50 multi interface library */
};      

/* lib_Flags bit definitions (all others are system reserved) */
enum enLibraryFlags
{
    LIBF_SUMMING = (1<<0), /* we are currently checksumming */
    LIBF_CHANGED = (1<<1), /* we have just changed the lib */
    LIBF_SUMUSED = (1<<2), /* set if we should bother to sum */
    LIBF_DELEXP  = (1<<3), /* delayed expunge */
    LIBF_EXP0CNT = (1<<4)
};

/* Temporary Compatibility */
#ifdef USE_OLD_LIBRARY_DEFINES
#define lh_Node     lib_Node
#define lh_Flags    lib_Flags
#define lh_pad      lib_pad
#define lh_NegSize  lib_NegSize
#define lh_PosSize  lib_PosSize
#define lh_Version  lib_Version
#define lh_Revision lib_Revision
#define lh_IdString lib_IdString
#define lh_Sum      lib_Sum
#define lh_OpenCnt  lib_OpenCnt
#endif

/* Convenience macro for testing if the given lib satisfies the given
 * version/revision criteria. */
#define LIB_IS_AT_LEAST(lib,vers,rev) (((lib)->lib_Version > (vers)) || ((lib)->lib_Version == vers && ((lib)->lib_Revision >= (rev))))

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

/* Warning: Everything below is default alignment */

/*------ Extended Library Base Structure ----------------------------------*/
/* Used to extend the standard library for V50 */
struct ExtendedLibrary
{
    struct Library *                 Parent;     /* Back pointer to self */
    struct LibraryManagerInterface * ILibrary;   /* Library interface */
    struct DeviceManagerInterface *  IDevice;    /* Device interface */
    struct List                      Interfaces; /* List of interfaces
                                                  * exported by this library */
    uint32                           ExtFlags;   /* Extended flags */
    struct Interface *               MainIFace;  /* For 68k cross-calls */
};

/* Extended flags */
enum enExtFlags
{
    LIBEF_DEVICE = 0x00000001 /* Library is a device library */
}; 


/****************************************************************************/

struct Interface;

typedef struct Library * (*LIBINITFUNC)(struct Library *library,
                                        APTR seglist,
                                        struct Interface *exec);

/****************************************************************************/

#if defined(__SASC)
   #pragma msg 79 pop
#endif

/****************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXEC_LIBRARIES_H */
