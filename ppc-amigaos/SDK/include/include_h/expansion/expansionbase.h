#ifndef EXPANSION_EXPANSIONBASE_H
#define EXPANSION_EXPANSIONBASE_H
/*
**    $VER: expansionbase.h 53.29 (10.8.2015)
**
**    Definitions for the expansion library base
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef   EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif

#ifndef   EXPANSION_CONFIGVARS_H
#include <expansion/configvars.h>
#endif

#ifndef   EXPANSION_PCI_H
#include <expansion/pci.h>
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

/* BootNodes are scanned by dos.library at startup.  Items found on the
 * list are started by dos. BootNodes are added with the AddDosNode() or
 * the V36 AddBootNode() calls.
 */
struct BootNode
{
    struct Node bn_Node;
    UWORD       bn_Flags;
    APTR        bn_DeviceNode;
};

/* expansion.library has functions to manipulate most of the information in
 * ExpansionBase.  Direct access is not permitted.  Use FindConfigDev()
 * to scan the board list.
 */
struct ExpansionBase
{
    struct Library        LibNode;
    UBYTE                 Flags;        /* read only (see below) */
    UBYTE                 eb_Private01; /* private */
    ULONG                 eb_Private02; /* private */
    ULONG                 eb_Private03; /* private */
    struct CurrentBinding eb_Private04; /* private */
    struct List           eb_Private05; /* private */
    struct List           MountList;    /* contains struct BootNode entries */

    /* private */
};

/* error codes
 */
enum enExpansionError
{
    EE_OK          =  0,
    EE_LASTBOARD   = 40, /* could not shut him up */
    EE_NOEXPANSION = 41, /* not enough expansion mem; board shut up */
    EE_NOMEMORY    = 42, /* not enough normal memory */
    EE_NOBOARD     = 43, /* no board at that address */
    EE_BADMEM      = 44  /* tried to add bad memory card */
};

/* Flags
 */
enum enExpansionFlagBits
{
    EBB_CLOGGED     = 0, /* someone could not be shut up */
    EBB_SHORTMEM    = 1, /* ran out of expansion mem */
    EBB_BADMEM      = 2, /* tried to add bad memory card */
    EBB_DOSFLAG     = 3, /* Set this stops DOS from opening
                            Startup-Sequence on boot */
    EBB_KICKBACK33  = 4, /* reserved for use by AmigaDOS */
    EBB_KICKBACK36  = 5, /* reserved for use by AmigaDOS */
    EBB_SILENTSTART = 6, /* If the flag is set by a floppy's bootblock
                            code, the initial open of the initial shell
                            window will be delayed until the first output
                            to that shell.  Otherwise the 1.3 compatible
                            behavior applies. */
    EBB_START_CC0   = 7  /* Magic kludge for CC0 use */
};

enum enExpansionFlags
{
    EBF_CLOGGED     = (1<<EBB_CLOGGED),
    EBF_SHORTMEM    = (1<<EBB_SHORTMEM),
    EBF_BADMEM      = (1<<EBB_BADMEM),
    EBF_DOSFLAG     = (1<<EBB_DOSFLAG),
    EBF_KICKBACK33  = (1<<EBB_KICKBACK33),
    EBF_KICKBACK36  = (1<<EBB_KICKBACK36),
    EBF_SILENTSTART = (1<<EBB_SILENTSTART),
    EBF_START_CC0   = (1<<EBB_START_CC0)
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

#endif /* EXPANSION_EXPANSIONBASE_H */
