#ifndef EXPANSION_CONFIGVARS_H
#define EXPANSION_CONFIGVARS_H
/*
**    $VER: configvars.h 53.29 (10.8.2015)
**
**    Software structures used by AutoConfig (tm) boards
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

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef   EXPANSION_CONFIGREGS_H
#include <expansion/configregs.h>
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

/*
** At early system startup time, one ConfigDev structure is created for
** each board found in the system.  Software may seach for ConfigDev
** structures by vendor & product ID number.  For debugging and diagnostic
** use, the entire list can be accessed.  See the expansion.library document
** for more information.
*/
struct ConfigDev
{
    struct Node         cd_Node;
    UBYTE               cd_Flags;     /* (read/write) */
    UBYTE               cd_Pad;       /* reserved */
    struct ExpansionRom cd_Rom;       /* copy of board's expansion ROM */
    APTR                cd_BoardAddr; /* where in memory the board was
                                       * placed */
    ULONG               cd_BoardSize; /* size of board in bytes */
    UWORD               cd_SlotAddr;  /* which slot number (PRIVATE) */
    UWORD               cd_SlotSize;  /* number of slots (PRIVATE) */
    APTR                cd_Driver;    /* pointer to node of driver */
    struct ConfigDev *  cd_NextCD;    /* linked list of drivers to config */
    ULONG               cd_Unused[4]; /* for whatever the driver wants */
};

/* cd_Flags */
enum enCDBits
{
    CDB_SHUTUP    = 0, /* this board has been shut up */
    CDB_CONFIGME  = 1, /* this board needs a driver to claim it */
    CDB_BADMEMORY = 2, /* this board contains bad memory */
    CDB_PROCESSED = 3  /* private flag */
};

enum enCDFlags
{
    CDF_SHUTUP    = (1<<CDB_SHUTUP),
    CDF_CONFIGME  = (1<<CDB_CONFIGME),
    CDF_BADMEMORY = (1<<CDB_BADMEMORY),
    CDF_PROCESSED = (1<<CDB_PROCESSED)
};

/*
** Boards are usually "bound" to software drivers.
** This structure is used by GetCurrentBinding() and SetCurrentBinding()
*/
struct CurrentBinding
{
    struct ConfigDev * cb_ConfigDev;     /* first configdev in chain */
    STRPTR             cb_FileName;      /* file name of driver */
    STRPTR             cb_ProductString; /* product # string */
    STRPTR *           cb_ToolTypes;     /* tooltypes from disk object */
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

#endif /* EXPANSION_CONFIGVARS_H */
