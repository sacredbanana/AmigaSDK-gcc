#ifndef GRAPHICS_GFXNODES_H
#define GRAPHICS_GFXNODES_H
/*
**    $VER: gfxnodes.h 54.16 (22.08.2022)
**
**    graphics extended node definintions
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

/* define structure names in this scope */
struct GraphicsIFace;

struct ExtendedNode
{
    struct Node *xln_Succ;
    struct Node *xln_Pred;
    UBYTE        xln_Type;
    BYTE         xln_Pri;
    STRPTR       xln_Name;
    UBYTE        xln_Subsystem;
    UBYTE        xln_Subtype;
    LONG         xln_Library;
    LONG       (*xln_Init)(struct GraphicsIFace *,
                           struct ExtendedNode *,
                           UWORD); /* only used if MONITOR_SPEC_TYPE */
};

#define SS_GRAPHICS 0x02

#define VIEW_EXTRA_TYPE      1
#define VIEWPORT_EXTRA_TYPE  2
#define SPECIAL_MONITOR_TYPE 3
#define MONITOR_SPEC_TYPE    4
#define RASTPORT_EXTRA_TYPE  5

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

#endif /* GRAPHICS_GFXNODES_H */
