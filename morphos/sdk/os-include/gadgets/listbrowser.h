#ifndef GADGETS_LISTBROWSER_H
#define GADGETS_LISTBROWSER_H

/*
	listbrowser.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif

#pragma pack(2)


#define LBM_ADDNODE (0x580001L)

struct lbAddNode
{
	ULONG              MethodID;
	struct GadgetInfo *lba_GInfo;
	struct Node       *lba_Node;
	struct TagItem    *lba_NodeAttrs;
};


#define LBM_REMNODE (0x580002L)

struct lbRemNode
{
	ULONG              MethodID;
	struct GadgetInfo *lbr_GInfo;
	struct Node       *lbr_Node;
};


#define LBM_EDITNODE (0x580003L)

struct lbEditNode
{
	ULONG              MethodID;
	struct GadgetInfo *lbe_GInfo;
	struct Node       *lbe_Node;
	struct TagItem    *lbe_NodeAttrs;
};


#define LBM_SORT (0x580004L)

struct lbSort
{
	ULONG              MethodID;
	struct GadgetInfo *lbs_GInfo;
	ULONG              lbs_Column;
	ULONG              lbs_Reverse;
	struct Hook       *lbs_CompareHook;
};


#define LBM_SHOWCHILDREN (0x580005L)

struct lbShowChildren
{
	ULONG              MethodID;
	struct GadgetInfo *lbsc_GInfo;
	struct Node       *lbsc_Node;
	WORD               lbsc_Depth;
};


#define LBM_HIDECHILDREN (0x580006L)

struct lbHideChildren
{
	ULONG              MethodID;
	struct GadgetInfo *lbhc_GInfo;
	struct Node       *lbhc_Node;
	WORD               lbhc_Depth;
};


/* listbrowser.gadget node attributes */

#define LBNA_Dummy           (TAG_USER + 0x5003500)
#define LBNA_Selected        (LBNA_Dummy + 1)
#define LBNA_Flags           (LBNA_Dummy + 2)
#define LBNA_UserData        (LBNA_Dummy + 3)
#define LBNA_Column          (LBNA_Dummy + 4)
#define LBNCA_Text           (LBNA_Dummy + 5)
#define LBNCA_Integer        (LBNA_Dummy + 6)
#define LBNCA_FGPen          (LBNA_Dummy + 7)
#define LBNCA_BGPen          (LBNA_Dummy + 8)
#define LBNCA_Image          (LBNA_Dummy + 9)
#define LBNCA_SelImage       (LBNA_Dummy + 10)
#define LBNCA_HorizJustify   (LBNA_Dummy + 11)
#define LBNCA_Justification  (LBNCA_HorizJustify)
#define LBNA_Generation      (LBNA_Dummy + 12)
#define LBNCA_Editable       (LBNA_Dummy + 13)
#define LBNCA_MaxChars       (LBNA_Dummy + 14)
#define LBNCA_CopyText       (LBNA_Dummy + 15)
#define LBNA_CheckBox        (LBNA_Dummy + 16)
#define LBNA_Checked         (LBNA_Dummy + 17)
#define LBNA_NodeSize        (LBNA_Dummy + 18)
#define LBNCA_EditTags       (LBNA_Dummy + 19)
#define LBNCA_RenderHook     (LBNA_Dummy + 20)
#define LBNCA_HookHeight     (LBNA_Dummy + 22)
#define LBNA_MemPool         (LBNA_Dummy + 23)
#define LBNA_NumColumns      (LBNA_Dummy + 24)
#define LBNA_Priority        (LBNA_Dummy + 25)
#define LBNCA_CopyInteger    (LBNA_Dummy + 26)
#define LBNCA_WordWrap       (LBNA_Dummy + 27)
#define LBNCA_VertJustify    (LBNA_Dummy + 28)


/* LBNA_Flags flags */

#define LBFLG_READONLY      1
#define LBFLG_CUSTOMPENS    2
#define LBFLG_HASCHILDREN   4
#define LBFLG_SHOWCHILDREN  8
#define LBFLG_HIDDEN        16


/* LBNA_HorizJustify modes */

#define LCJ_LEFT    0
#define LCJ_CENTER  1
#define LCJ_RIGHT   2

/* Language fix */

#define LCJ_CENTRE  LCJ_CENTER


/* LBNA_VertJustify modes */

#define LRJ_BOTTOM  0
#define LRJ_CENTER  1
#define LRJ_TOP     2

/* Language fix */

#define LRJ_CENTRE  LRJ_CENTER


/* LBNCA_RenderHook definitions */

#define LB_DRAW  0x202L

#define LBCB_OK       0
#define LBCB_UNKNOWN  1

#define LBR_NORMAL    0
#define LBR_SELECTED  1


struct LBDrawMsg
{
	ULONG             lbdm_MethodID;
	struct RastPort  *lbdm_RastPort;
	struct DrawInfo  *lbdm_DrawInfo;
	struct Rectangle  lbdm_Bounds;
	ULONG             lbdm_State;
};


struct LBSortMsg
{
	ULONG lbsm_TypeA;
	union
	{
		LONG   Integer;
		STRPTR Text;
	}     lbsm_DataA;
	APTR  lbsm_UserDataA;

	ULONG lbsm_TypeB;
	union
	{
		LONG   Integer;
		STRPTR Text;
	}     lbsm_DataB;
	APTR  lbsm_UserDataB;
};


struct ColumnInfo
{
	WORD   ci_Width;
	STRPTR ci_Title;
	ULONG  ci_Flags;
};


/* ColumnInfo flags */

#define CIF_WEIGHTED      0
#define CIF_FIXED         1
#define CIF_DRAGGABLE     2
#define CIF_NOSEPARATORS  4
#define CIF_SORTABLE      8


/* xxxLBColumnInfo() attributes */

#define LBCIA_MemPool   (LBNA_Dummy + 50)
#define LBCIA_Column    (LBNA_Dummy + 51)
#define LBCIA_Title     (LBNA_Dummy + 52)
#define LBCIA_Weight    (LBNA_Dummy + 53)
#define LBCIA_Width     (LBNA_Dummy + 54)
#define LBCIA_Flags     (LBNA_Dummy + 55)


/* Attributes defined by listbrowser.gadget */

#define LISTBROWSER_Dummy              (REACTION_Dummy + 0x0003000)
#define LISTBROWSER_Top                (LISTBROWSER_Dummy + 1)
#define LISTBROWSER_Reserved1          (LISTBROWSER_Dummy + 2)
#define LISTBROWSER_Labels             (LISTBROWSER_Dummy + 3)
#define LISTBROWSER_Selected           (LISTBROWSER_Dummy + 4)
#define LISTBROWSER_SelectedNode       (LISTBROWSER_Dummy + 5)
#define LISTBROWSER_MultiSelect        (LISTBROWSER_Dummy + 6)
#define LISTBROWSER_VertSeparators     (LISTBROWSER_Dummy + 7)
#define LISTBROWSER_Separators         (LISTBROWSER_VertSeparators)
#define LISTBROWSER_ColumnInfo         (LISTBROWSER_Dummy + 8)
#define LISTBROWSER_MakeVisible        (LISTBROWSER_Dummy + 9)
#define LISTBROWSER_VirtualWidth       (LISTBROWSER_Dummy + 10)
#define LISTBROWSER_Borderless         (LISTBROWSER_Dummy + 11)
#define LISTBROWSER_VerticalProp       (LISTBROWSER_Dummy + 12)
#define LISTBROWSER_HorizontalProp     (LISTBROWSER_Dummy + 13)
#define LISTBROWSER_Left               (LISTBROWSER_Dummy + 14)
#define LISTBROWSER_Reserved2          (LISTBROWSER_Dummy + 15)
#define LISTBROWSER_AutoFit            (LISTBROWSER_Dummy + 16)
#define LISTBROWSER_ColumnTitles       (LISTBROWSER_Dummy + 17)
#define LISTBROWSER_ShowSelected       (LISTBROWSER_Dummy + 18)
#define LISTBROWSER_VPropTotal         (LISTBROWSER_Dummy + 19)
#define LISTBROWSER_VPropTop           (LISTBROWSER_Dummy + 20)
#define LISTBROWSER_VPropVisible       (LISTBROWSER_Dummy + 21)
#define LISTBROWSER_HPropTotal         (LISTBROWSER_Dummy + 22)
#define LISTBROWSER_HPropTop           (LISTBROWSER_Dummy + 23)
#define LISTBROWSER_HPropVisible       (LISTBROWSER_Dummy + 24)
#define LISTBROWSER_MouseX             (LISTBROWSER_Dummy + 25)
#define LISTBROWSER_MouseY             (LISTBROWSER_Dummy + 26)
#define LISTBROWSER_Hierarchical       (LISTBROWSER_Dummy + 27)
#define LISTBROWSER_ShowImage          (LISTBROWSER_Dummy + 28)
#define LISTBROWSER_HideImage          (LISTBROWSER_Dummy + 29)
#define LISTBROWSER_LeafImage          (LISTBROWSER_Dummy + 30)
#define LISTBROWSER_ScrollRaster       (LISTBROWSER_Dummy + 31)
#define LISTBROWSER_Spacing            (LISTBROWSER_Dummy + 32)
#define LISTBROWSER_Editable           (LISTBROWSER_Dummy + 33)
#define LISTBROWSER_EditNode           (LISTBROWSER_Dummy + 35)
#define LISTBROWSER_EditColumn         (LISTBROWSER_Dummy + 36)
#define LISTBROWSER_EditTags           (LISTBROWSER_Dummy + 39)
#define LISTBROWSER_Position           (LISTBROWSER_Dummy + 34)
#define LISTBROWSER_RelEvent           (LISTBROWSER_Dummy + 37)
#define LISTBROWSER_NumSelected        (LISTBROWSER_Dummy + 38)
#define LISTBROWSER_RelColumn          (LISTBROWSER_Dummy + 40)
#define LISTBROWSER_HorizSeparators    (LISTBROWSER_Dummy + 41)
#define LISTBROWSER_CheckImage         (LISTBROWSER_Dummy + 42)
#define LISTBROWSER_UncheckedImage     (LISTBROWSER_Dummy + 43)
#define LISTBROWSER_TotalNodes         (LISTBROWSER_Dummy + 44)
#define LISTBROWSER_MinNodeSize        (LISTBROWSER_Dummy + 45)
#define LISTBROWSER_TitleClickable     (LISTBROWSER_Dummy + 46)
#define LISTBROWSER_MinVisible         (LISTBROWSER_Dummy + 47)
#define LISTBROWSER_Reserved6          (LISTBROWSER_Dummy + 48)
#define LISTBROWSER_Reserved7          (LISTBROWSER_Dummy + 49)
#define LISTBROWSER_PersistSelect      (LISTBROWSER_Dummy + 50)
#define LISTBROWSER_CursorSelect       (LISTBROWSER_Dummy + 51)
#define LISTBROWSER_CursorNode         (LISTBROWSER_Dummy + 52)
#define LISTBROWSER_FastRender         (LISTBROWSER_Dummy + 53)
#define LISTBROWSER_TotalVisibleNodes  (LISTBROWSER_Dummy + 54)
#define LISTBROWSER_WrapText           (LISTBROWSER_Dummy + 55)


/* LISTBROWSER_Position values */

#define LBP_LINEUP      1
#define LBP_LINEDOWN    2
#define LBP_PAGEUP      3
#define LBP_PAGEDOWN    4
#define LBP_TOP         5
#define LBP_BOTTOM      6
#define LBP_SHIFTLEFT   10
#define LBP_SHIFTRIGHT  11
#define LBP_LEFTEDGE    12
#define LBP_RIGHTEDGE   13


/* LISTBROWSER_RelEvent values */

#define LBRE_NORMAL        1
#define LBRE_HIDECHILDREN  2
#define LBRE_SHOWCHILDREN  4
#define LBRE_EDIT          8
#define LBRE_DOUBLECLICK   16
#define LBRE_CHECKED       32
#define LBRE_UNCHECKED     64
#define LBRE_TITLECLICK    128
#define LBRE_COLUMNADJUST  256


#pragma pack()

#endif /* GADGETS_LISTBROWSER_H */
