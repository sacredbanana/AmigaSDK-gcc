#ifndef GADGETS_LISTBROWSER_H
#define GADGETS_LISTBROWSER_H
/*
**    $VER: listbrowser.h 54.16 (22.08.2022)
**
**    Definitions for the ListBrowser BOOPSI class
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
*/

/*****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
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

/* LBM_ADDNODE creates a listbrowser node and inserts it to the currently
 * attached list. The number of columns is automatically set according to the
 * object's column number. If the node would become visible, it is automatically
 * rendered. This method returns the address of the new node. (V41)
 */
#define LBM_ADDNODE (0x580001L)

struct lbAddNode
{
    uint32              MethodID;      /* LBM_ADDNODE */
    struct GadgetInfo * lba_GInfo;     /* to provide rendering info */
    struct Node *       lba_Node;      /* Insert() after this node */
    struct TagItem *    lba_NodeAttrs; /* LBNA tag list */
};


/* LBM_REMNODE removes and frees the chosen node. If the node was visible, the
 * display is updated. The method returns 1 if the operation was successful.
 * (V41)
 */
#define LBM_REMNODE (0x580002L)

struct lbRemNode
{
    uint32              MethodID;  /* LBM_REMNODE */
    struct GadgetInfo * lbr_GInfo; /* to provide rendering info */
    struct Node *       lbr_Node;  /* Remove() this node */
};


/* LBM_EDITNODE changes the chosen node's attributes and renders the
 * changes. The method returns 1 if the operation was successful. (V41)
 */
#define LBM_EDITNODE (0x580003L)

struct lbEditNode
{
    uint32              MethodID;      /* LBM_EDITNODE */
    struct GadgetInfo * lbe_GInfo;     /* to provide rendering info */
    struct Node *       lbe_Node;      /* modify this node */
    struct TagItem *    lbe_NodeAttrs; /* according to this tag list */
};


/* LBM_SORT */
#define LBM_SORT (0x580004L)

struct lbSort
{
	uint32              MethodID;        /* LBM_SORT */
	struct GadgetInfo * lbs_GInfo;       /* to provide rendering info */
	uint32              lbs_Column;      /* Column to sort by */
	uint32              lbs_Direction;   /* Sort direction (see below) */
    struct Hook *       lbs_CompareHook; /* Optional hook to compare items */
};

// For compatibility only; do not use in new code.
#define lbs_Reverse lbs_Direction

#define LBMSORT_FORWARD  0  // Forward sort (down sort arrow)
#define LBMSORT_REVERSE  1  // Reverse sort (up sort arrow)

/* LBM_SHOWCHILDREN */
#define LBM_SHOWCHILDREN (0x580005L)

struct lbShowChildren
{
    uint32              MethodID;   /* LBM_SHOWCHILDREN */
    struct GadgetInfo * lbsc_GInfo; /* to provide rendering info */
    struct Node *       lbsc_Node;  /* Starting ParentNode,
                                       NULL means start at root. */
    int16               lbsc_Depth; /* Depth to Show */
};


/* LBM_HIDECHILDREN
 */
#define LBM_HIDECHILDREN (0x580006L)

struct lbHideChildren
{
    uint32              MethodID;   /* LBM_HIDECHILDREN */
    struct GadgetInfo * lbhc_GInfo; /* to provide rendering info */
    struct Node *       lbhc_Node;  /* Starting ParentNode,
                                       NULL means start at root. */
    int16               lbhc_Depth; /* Depth to Hide */
};

/*****************************************************************************/

/* ListBrowser Node attributes. */
#define LBNA_Dummy                (TAG_USER+0x5003500)

#define LBNA_Selected             (LBNA_Dummy+1)
    /* (BOOL) If the node is to be selected.  Defaults to FALSE. */

#define LBNA_Flags                (LBNA_Dummy+2)
    /* (uint32) Flags for the node.  Defaults to 0. */

#define LBNA_UserData             (LBNA_Dummy+3)
    /* (uint32) User data.  Defaults to NULL. */

#define LBNA_Column               (LBNA_Dummy+4)
    /* (int16) Column in the node that the attributes below affect.
       Defaults to 0. */

#define LBNCA_Text                (LBNA_Dummy+5)
    /* (CONST_STRPTR) Text to display in the column. Defaults to NULL. */

#define LBNCA_Integer             (LBNA_Dummy+6)
    /* (int32 *) Pointer to an integer to display in the column.
       Defaults to NULL. */

#define LBNCA_FGPen               (LBNA_Dummy+7)
    /* (int16) Column foreground pen. */

#define LBNCA_BGPen               (LBNA_Dummy+8)
    /* (int16) Column background pen. */

#define LBNCA_Image               (LBNA_Dummy+9)
    /* (struct Image *) Image to display in the column.  Defaults to NULL. */

#define LBNCA_SelImage            (LBNA_Dummy+10)
    /* (struct Image *) Image to display in column when selected.
       Defaults to NULL. */

#define LBNCA_HorizJustify        (LBNA_Dummy+11)
#define LBNCA_Justification       LBNCA_HorizJustify
    /* (int16) Column justification.  Defaults to LCJ_LEFT. */

#define LBNA_Generation           (LBNA_Dummy+12)
    /* (uint32) Node generation (1..N).  Defaults to 0 (no generation). */

#define LBNCA_Editable            (LBNA_Dummy+13)
    /* (BOOL) If this column is editable.  Requires LBNCA_CopyText.
       Defaults to FALSE. */

#define LBNCA_MaxChars            (LBNA_Dummy+14)
    /* (int16) Maximum characters in an editable entry.  Required when using
       LBNCA_Editable. */

#define LBNCA_CopyText            (LBNA_Dummy+15)
    /* (BOOL) Copy the LBNCA_Text contents to an internal buffer. */

#define LBNA_CheckBox             (LBNA_Dummy+16)
    /* (BOOL) This is a checkbox node. */

#define LBNA_Checked              (LBNA_Dummy+17)
    /* (BOOL) If true, this checkbox node is checked. */

#define LBNA_NodeSize             (LBNA_Dummy+18)
    /* (uint32) Size of custom node (and optimize mempool puddles). */

#define LBNCA_EditTags            (LBNA_Dummy+19)
    /* (struct TagItem *) Tag list for string gadget used to edit column. */

#define LBNCA_RenderHook          (LBNA_Dummy+20)
    /* (struct Hook *) Effectively the same as GadTools listview hook. */

#define LBNCA_HookHeight          (LBNA_Dummy+22)
    /* (int16) Height in pixels of the hook function rendering. */

#define LBNA_MemPool              (LBNA_Dummy+23)
    /* (APTR) Exec memory pool to use for this node's allocations. */

#define LBNA_NumColumns           (LBNA_Dummy+24)
    /* (int16) For GetListBrowserNodeAttrs() only! */

#define LBNA_Priority             (LBNA_Dummy+25)
    /* (int8) Sets the Exec node->ln_Pri. */

#define LBNCA_CopyInteger         (LBNA_Dummy+26)
    /* (BOOL) AllocListBrowserNodeAttrs() or SetListBrowserNodeAttrs()
       only! */

#define LBNCA_WordWrap            (LBNA_Dummy+27)
    /* (BOOL) Word wrap this node's LBNCA_Text data. */

#define LBNCA_VertJustify         (LBNA_Dummy+28)
    /* (int16) Row justification.  Defaults to LRJ_CENTER. */

#define LBNCA_FillPen             (LBNA_Dummy+29)
    /* (int16) Column fill pen. (V51) */


/* ListBrowser ColumnInfo attributes. */
#define LBCIA_MemPool             (LBNA_Dummy+50)
    /* (APTR) MemPool for ColumnInfo (V45) */

#define LBCIA_Column              (LBNA_Dummy+51)
    /* (int16) Column number (0..N) (V45) */

#define LBCIA_Title               (LBNA_Dummy+52)
    /* (CONST_STRPTR) Column text label. (V45) */

#define LBCIA_Weight              (LBNA_Dummy+53)
    /* (int16) Column weight (implies ~CIF_FIXED) (V45) */

#define LBCIA_Width               (LBNA_Dummy+54)
    /* (int16) Column width in pixels (implies CIF_FIXED) (V45) */

#define LBCIA_Flags               (LBNA_Dummy+55)
    /* (uint32) Column flags (defined below) (V45) */

#define LBNCA_SoftStyle           (LBNA_Dummy+56)
    /* (uint8) Text font style (V52.14) */

#define LBCIA_UserData            (LBNA_Dummy+57)
    /* (APTR) User data (V53.16) */

#define LBCIA_AutoSort            (LBNA_Dummy+58)
    /* (BOOL) Automatically sort this column (V53.17) */

#define LBCIA_SortDirection       (LBNA_Dummy+59)
    /* (uint32) Direction of the sort (V53.17) */

#define LBCIA_CompareHook         (LBNA_Dummy+60)
    /* (struct Hook *) Sort comparison hook (V53.17) */

#define LBCIA_Sortable            (LBNA_Dummy+61)
    /* (BOOL) Column is sortable (V53.17) */

#define LBCIA_DraggableSeparator  (LBNA_Dummy+62)
    /* (BOOL) Column separator is draggable (V53.17) */

#define LBCIA_Separator           (LBNA_Dummy+63)
    /* (BOOL) Column has separators (V53.17) */

#define LBCIA_SortArrow           (LBNA_Dummy+64)
    /* (BOOL) Column has a sort arrow (V53.17) */

#define LBCIA_CopyTitle           (LBNA_Dummy+65)
    /* (BOOL) Copy the LBCIA_Title contents to an internal buffer (V53.62) */

#define LBCIA_SoftStyle           (LBNA_Dummy+66)
    /* (uint8) Text font style (V53.68) */

#define LBCIA_HorizJustify        (LBNA_Dummy+67)
    /* (int16) Column justification.  Defaults to LCJ_LEFT (V53.69) */


/* Flags for the LBNA_Flags node attribute. */
#define LBFLG_READONLY      1
#define LBFLG_CUSTOMPENS    2
#define LBFLG_HASCHILDREN   4
#define LBFLG_SHOWCHILDREN  8
#define LBFLG_HIDDEN       16


/* Justification modes for the LBNCA_HorizJustify node column attribute. */
#define LCJ_LEFT   0
#define LCJ_CENTER 1
#define LCJ_RIGHT  2
#define LCJ_CENTRE LCJ_CENTER

/* Justification modes for the LBNCA_VertJustify node column attribute. */
#define LRJ_BOTTOM 0
#define LRJ_CENTER 1
#define LRJ_TOP    2
#define LRJ_CENTRE LRJ_CENTER

/* These definitions are for the LBNCA_RenderHook tag. */

/* The different types of messages that a listview callback hook can see.
 */
#define LB_DRAW 0x202L /* Draw yourself, with state */

/* Possible return values from a render hook.
 */
#define LBCB_OK      0 /* callback understands this message type */
#define LBCB_UNKNOWN 1 /* callback does not understand this message */

/* States for LBDrawMsg.lbdm_State.
 */
#define LBR_NORMAL   0 /* The usual */
#define LBR_SELECTED 1 /* For selected gadgets    */

/* Structure of LB_DRAW messages, object is a (struct Node *). */
struct LBDrawMsg
{
    uint32            lbdm_MethodID; /* LV_DRAW */
    struct RastPort * lbdm_RastPort; /* Where to render to */
    struct DrawInfo * lbdm_DrawInfo; /* Useful to have around */
    struct Rectangle  lbdm_Bounds;   /* Limits of where to render */
    uint32            lbdm_State;    /* How to render */
};


/* Sort Hook Data Structure.
 */
struct LBSortMsg
{
    // Data for Node A.
    uint32 lbsm_TypeA;

    union
    {
        int32        Integer;
        CONST_STRPTR Text;
    } lbsm_DataA;

    APTR lbsm_UserDataA;


    // Data for Node B.
    uint32 lbsm_TypeB;
    union
    {
        int32        Integer;
        CONST_STRPTR Text;
    } lbsm_DataB;

    APTR lbsm_UserDataB;

    int16  lbsm_Column;     // Column number  (V53.18)
    uint32 lbsm_Direction;  // Sort direction (V53.18)

	BOOL   lbsm_CheckedA;   // Checkbox state (V53.41)
	BOOL   lbsm_CheckedB;   // Checkbox state (V53.41)
};


/*****************************************************************************/

/* Information for columns of the list browser.
 *
 * NOTE:
 * Since V53.16 this structure is retained for backwards compatibility only.
 * Use the AllocLBColumnInfoA() family of functions to safely manipulate
 * and retrieve all column information. This structure has been extended
 * and will continue to be extended in the future. Do not depend on any
 * of the fields in this structure for any purpose.
 */
struct ColumnInfo
{
    int16        ci_Width;
    CONST_STRPTR ci_Title;
    uint32       ci_Flags;
};

/* Possible ColumnInfo flags (deprecated: use equivalent tags instead) */
#define CIF_WEIGHTED      0  // weighted width column (default)
#define CIF_FIXED         1  // fixed pixel width specified in ci_Width
#define CIF_DRAGGABLE     2  // separator is user draggable
#define CIF_NOSEPARATORS  4  // no separator on this column
#define CIF_SORTABLE      8  // column is sortable (see LBM_SORT)


/*****************************************************************************/

/* Additional attributes defined by the List Browser class
 */
#define LISTBROWSER_Dummy             (REACTION_Dummy+0x0003000)

#define LISTBROWSER_Top               (LISTBROWSER_Dummy+1)
    /* (int32) Top position node. Defaults to 0. */

#define LISTBROWSER_Reserved1         (LISTBROWSER_Dummy+2)
    /* RESERVED */

#define LISTBROWSER_Labels            (LISTBROWSER_Dummy+3)
    /* (struct List *) Defaults to ~0. */

#define LISTBROWSER_Selected          (LISTBROWSER_Dummy+4)
    /* (int32) Numeric index of node currently selected; defaults to -1. */

#define LISTBROWSER_SelectedNode      (LISTBROWSER_Dummy+5)
    /* (struct Node *) Node currently selected. */

#define LISTBROWSER_MultiSelect       (LISTBROWSER_Dummy+6)
    /* (BOOL) Allow multiple selection. Defaults to FALSE. */

#define LISTBROWSER_VertSeparators    (LISTBROWSER_Dummy+7)
#define LISTBROWSER_Separators        LISTBROWSER_VertSeparators
    /* (BOOL) Render column separators. Defaults to TRUE. */

#define LISTBROWSER_ColumnInfo        (LISTBROWSER_Dummy+8)
    /* (struct ColumnInfo *) Column information. Defaults to NULL. */

#define LISTBROWSER_MakeVisible       (LISTBROWSER_Dummy+9)
    /* (int32) Move this node into view. Defaults to 0. */

#define LISTBROWSER_VirtualWidth      (LISTBROWSER_Dummy+10)
    /* (int16) Virtual width of the item list. Defaults to 0. */

#define LISTBROWSER_Borderless        (LISTBROWSER_Dummy+11)
    /* (BOOL) Don't render a frame around the list. Defaults to FALSE. */

#define LISTBROWSER_VerticalProp      (LISTBROWSER_Dummy+12)
    /* (BOOL) The listbrowser has a vertical scroller. Defaults to TRUE. */

#define LISTBROWSER_HorizontalProp    (LISTBROWSER_Dummy+13)
    /* (BOOL) The listbrowser has a horizontal scroller. Defaults to FALSE. */

#define LISTBROWSER_Left              (LISTBROWSER_Dummy+14)
    /* (int16) First visible pixel column. Defaults to 0. */

#define LISTBROWSER_Reserved2         (LISTBROWSER_Dummy+15)
    /* RESERVED */

#define LISTBROWSER_AutoFit           (LISTBROWSER_Dummy+16)
    /* (BOOL) Compute width of columns automatically. Defaults to FALSE. */

#define LISTBROWSER_ColumnTitles      (LISTBROWSER_Dummy+17)
    /* (BOOL) Display titles of columns. Defaults to FALSE. */

#define LISTBROWSER_ShowSelected      (LISTBROWSER_Dummy+18)
    /* (BOOL) The selected item stays highlighted. Defaults to FALSE. */

#define LISTBROWSER_VPropTotal        (LISTBROWSER_Dummy+19)
#define LISTBROWSER_VPropTop          (LISTBROWSER_Dummy+20)
#define LISTBROWSER_VPropVisible      (LISTBROWSER_Dummy+21)
    /* (uint32) State of the vertical prop gadget (if any). */

#define LISTBROWSER_HPropTotal        (LISTBROWSER_Dummy+22)
#define LISTBROWSER_HPropTop          (LISTBROWSER_Dummy+23)
#define LISTBROWSER_HPropVisible      (LISTBROWSER_Dummy+24)
    /* (uint32) State of the horizontal prop gadget (if any). */

#define LISTBROWSER_MouseX            (LISTBROWSER_Dummy+25)
#define LISTBROWSER_MouseY            (LISTBROWSER_Dummy+26)
    /* (int16) Returns position of mouse release. */

#define LISTBROWSER_Hierarchical      (LISTBROWSER_Dummy+27)
    /* (BOOL) Enables ListTree mode. Defaults to FALSE. */

#define LISTBROWSER_ShowImage         (LISTBROWSER_Dummy+28)
    /* (struct Image *) ListTree expanded branch custom image.
       Defaults to NULL. */

#define LISTBROWSER_HideImage         (LISTBROWSER_Dummy+29)
    /* (struct Image *) ListTree collapsed branch custom image.
       Defaults to NULL. */

#define LISTBROWSER_LeafImage         (LISTBROWSER_Dummy+30)
    /* (struct Image *) ListTree branch item custom image.
       Defaults to NULL. */

#define LISTBROWSER_ScrollRaster      (LISTBROWSER_Dummy+31)
    /* (BOOL) See autodocs for Intuition V37 bug.  Defaults to TRUE. */

#define LISTBROWSER_Spacing           (LISTBROWSER_Dummy+32)
    /* (int16) Additional vertical spacing for nodes. Defaults to 0. */

#define LISTBROWSER_Editable          (LISTBROWSER_Dummy+33)
    /* (int16) Allow inline editing of node text. Defaults to FALSE. */

#define LISTBROWSER_EditNode          (LISTBROWSER_Dummy+35)
    /* (int32) Specify a node to edit. */

#define LISTBROWSER_EditColumn        (LISTBROWSER_Dummy+36)
    /* (int16) Specify a column to edit. */

#define LISTBROWSER_EditTags          (LISTBROWSER_Dummy+39)
    /* (struct TagItem *) Tag list passed to editable node string gadget.
       Defaults to NULL. */

#define LISTBROWSER_Position          (LISTBROWSER_Dummy+34)
    /* (uint32) Change the view position. See possible values below. */

#define LISTBROWSER_RelEvent          (LISTBROWSER_Dummy+37)
    /* (uint32) Event that caused the last message from the listbrowser.
       See possible values below. */

#define LISTBROWSER_NumSelected       (LISTBROWSER_Dummy+38)
    /* (int32) Number of selected nodes. */

#define LISTBROWSER_RelColumn         (LISTBROWSER_Dummy+40)
    /* (int16) Column number clicked on, or edited inline. */

#define LISTBROWSER_HorizSeparators   (LISTBROWSER_Dummy+41)
    /* (BOOL) Show horizontal node separators. */

#define LISTBROWSER_CheckImage        (LISTBROWSER_Dummy+42)
    /* (struct Image *) Custom checkbox image for checked state. */

#define LISTBROWSER_UncheckedImage    (LISTBROWSER_Dummy+43)
    /* (struct Image *) Custom checkbox image for unchecked state. */

#define LISTBROWSER_TotalNodes        (LISTBROWSER_Dummy+44)
    /* (int32) Total node count. */

#define LISTBROWSER_MinNodeSize       (LISTBROWSER_Dummy+45)
    /* (int32) Minimum Node size for custom node MemPool optimization. */

#define LISTBROWSER_TitleClickable    (LISTBROWSER_Dummy+46)
    /* (BOOL) Allow column title bar clicking. */

#define LISTBROWSER_MinVisible        (LISTBROWSER_Dummy+47)
    /* (int32) Minimum visible node count. This causes the minimum
       domain to be large enough to hold the specified number of nodes
       using the estimated average node height. Note, ESTIMATED, this
       is not a guaranteed result. The result may be slightly more or
       less than specified, and potentially a lot greater if other objects
       within the layout group cause the listbrowser to layout larger
       than its minimum domain. */

#define LISTBROWSER_Reserved6         (LISTBROWSER_Dummy+48)
    /* RESERVED */

#define LISTBROWSER_Reserved7         (LISTBROWSER_Dummy+49)
    /* RESERVED */

#define LISTBROWSER_PersistSelect     (LISTBROWSER_Dummy+50)
    /* (int32) When set to TRUE, SHIFT key is NOT required for multi-select. */

#define LISTBROWSER_CursorSelect      (LISTBROWSER_Dummy+51)
    /* (int32) Keyboard cursor selected node number. */

#define LISTBROWSER_CursorNode        (LISTBROWSER_Dummy+52)
    /* (struct Node *) Keyboard cursor selected node. */

#define LISTBROWSER_FastRender        (LISTBROWSER_Dummy+53)
    /* Obsolete */

#define LISTBROWSER_TotalVisibleNodes (LISTBROWSER_Dummy+54)
    /* (int32) Total visible node count. */

#define LISTBROWSER_WrapText          (LISTBROWSER_Dummy+55)
    /* (BOOL) Enable word wrap of text nodes. */

#define LISTBROWSER_MemPool           (LISTBROWSER_Dummy+56)
    /* (APTR) Exec memory pool to use for this object's allocations. (V51) */

#define LISTBROWSER_Bottom            (LISTBROWSER_Dummy+57)
    /* (int32) Bottom position node. Defaults to 0. (V52.7) */

#define LISTBROWSER_MakeNodeVisible   (LISTBROWSER_Dummy+58)
    /* (struct Node *) Causes the specified node to be brought into view (V52.11) */

#define LISTBROWSER_AutoVirtualWidth  (LISTBROWSER_Dummy+59)
    /* let the gadget set the virtual width for us */

#define LISTBROWSER_HintInfoHook      (LISTBROWSER_Dummy+60)
    /* (struct Hook *) Hook to be called when the GM_QUERY method is invoked (V53.11) */

#define LISTBROWSER_SortColumn        (LISTBROWSER_Dummy+61)
    /* (int16) Column number to sort (V53.17) */

#define LISTBROWSER_Striping          (LISTBROWSER_Dummy+62)
    /* (uint32) Striping effects. See below for defines. (V53.18) */

#define LISTBROWSER_AllowNoSelection  (LISTBROWSER_Dummy+63)
    /* (BOOL)  Allow notification if no item is selected */


/* Possible values for LISTBROWSER_Position.
 */
#define LBP_LINEUP      1
#define LBP_LINEDOWN    2
#define LBP_PAGEUP      3
#define LBP_PAGEDOWN    4
#define LBP_TOP         5
#define LBP_BOTTOM      6
#define LBP_SHIFTLEFT  10
#define LBP_SHIFTRIGHT 11
#define LBP_LEFTEDGE   12
#define LBP_RIGHTEDGE  13
#define LBP_PAGELEFT   14  /* New for V51 */
#define LBP_PAGERIGHT  15  /* New for V51 */

/* Possible values for LISTBROWSER_RelEvent.
 */
#define LBRE_NORMAL          1
#define LBRE_HIDECHILDREN    2
#define LBRE_SHOWCHILDREN    4
#define LBRE_EDIT            8
#define LBRE_DOUBLECLICK    16
#define LBRE_CHECKED        32
#define LBRE_UNCHECKED      64
#define LBRE_TITLECLICK    128
#define LBRE_COLUMNADJUST  256
#define LBRE_EDITTABNEXT   512  /* New for V51 */
#define LBRE_EDITTABPREV  1024  /* New for V51 */

/* Possible values for LISTBROWSER_Striping.
 */
#define LBS_NONE     0
#define LBS_ROWS     1
#define LBS_COLUMNS  2  /* Not yet implemented */
#define LBS_BOTH     3  /* Not yet implemented */

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

#endif /* GADGETS_LISTBROWSER_H */
