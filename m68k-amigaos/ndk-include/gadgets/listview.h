#ifndef LISTVIEW_H
#define LISTVIEW_H
/*
**    $VER: listview.h 47.3 (29.12.2019)
**
**    Definitions for the ListView BOOPSI class
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef   INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

/*****************************************************************************/

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

/* This defines a entry in the ListView list.
 */
struct ListLabelNode
{
    struct Node    lvn_Node;             /* Exec Node structure */
    ULONG          lvn_UserData;

    WORD           lvn_RenderForeground; /* Render foreground pen */
    WORD           lvn_RenderBackground; /* Render background pen */

    WORD           lvn_SelectForeground; /* Select foreground pen */
    WORD           lvn_SelectBackground; /* Select background pen */

    struct Image * lvn_RenderImage;      /* Optional rendered imagery */
    struct Image * lvn_SelectImage;      /* Optional selected imagery */

    /* PRIVATE FIELDS - CRASH & BURN! */
    WORD           lvn_TextLength;
    WORD           lvn_LeftEdge;
    WORD           lvn_TopEdge;
    WORD           lvn_Width;
    WORD           lvn_Height;
    WORD           lvn_Justification;    /* text/image justification */
    WORD           lvn_Selected;         /* is node selected? */
};

/*****************************************************************************/

#define LVJ_LEFT   0
#define LVJ_CENTER 1
#define LVJ_RIGHT  2

/*****************************************************************************/

/* Additional attributes defined by the ListView class */

#define LISTVIEW_Dummy        (TAG_USER+0x04000000)

#define LISTVIEW_Labels       (LISTVIEW_Dummy+1)  /* (struct List *) listview labels */
#define LISTVIEW_Top          (LISTVIEW_Dummy+2)  /* ListView Top Offset */
#define LISTVIEW_Visible      (LISTVIEW_Dummy+3)  /* ListView Node Visible */
#define LISTVIEW_Total        (LISTVIEW_Dummy+4)  /* ListView Total Nodes */
#define LISTVIEW_ShowSelected (LISTVIEW_Dummy+6)  /* BOOL */
#define LISTVIEW_Selected     (LISTVIEW_Dummy+7)  /* Currently selected node number */
#define LISTVIEW_SelectedNode (LISTVIEW_Dummy+7)  /* Currently selected node */
#define LISTVIEW_MakeVisible  (LISTVIEW_Dummy+8)  /* make/is node visible */
#define LISTVIEW_MultiSelect  (LISTVIEW_Dummy+9)  /* allow multiselect? */
#define LISTVIEW_ItemHeight   (LISTVIEW_Dummy+10) /* Node/Item height */
#define LISTVIEW_CallHook     (LISTVIEW_Dummy+11) /* Render Hook */
#define LISTVIEW_ScrollUp     (LISTVIEW_Dummy+12) /* scroll view up ? labels */
#define LISTVIEW_ScrollDown   (LISTVIEW_Dummy+13) /* scroll view down ? labels */
#define LISTVIEW_ScrollLeft   (LISTVIEW_Dummy+14) /* scroll view left ? pixels */
#define LISTVIEW_ScrollRight  (LISTVIEW_Dummy+15) /* scroll view right ? pixels */
#define LISTVIEW_Spacing      (LISTVIEW_Dummy+16) /* not currently implemented */

/*****************************************************************************/

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

#endif /* LISTVIEW_H */
