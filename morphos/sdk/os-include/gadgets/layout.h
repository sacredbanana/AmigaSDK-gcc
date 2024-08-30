#ifndef GADGETS_LAYOUT_H
#define GADGETS_LAYOUT_H

/*
	layout.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif

#ifndef IMAGES_BEVEL_H
# include <images/bevel.h>
#endif

#pragma pack(2)


struct WeightObject
{
	ULONG wb_SuccHeight;
	ULONG wb_PredHeight;
	ULONG wb_Reserved1;

	ULONG wb_SuccWidth;
	ULONG wb_PredWidth;
	ULONG wb_Reserved2;
};

struct LayoutLimits
{
	UWORD MinWidth;
	UWORD MinHeight;
	UWORD MaxWidth;
	UWORD MaxHeight;
};


/* Attributes defined by layout.gadget */

#define LAYOUT_Dummy            (REACTION_Dummy + 0x7000)
#define LAYOUT_Orientation      (LAYOUT_Dummy + 1)
#define LAYOUT_FixedHoriz       (LAYOUT_Dummy + 2)
#define LAYOUT_FixedVert        (LAYOUT_Dummy + 3)
#define LAYOUT_HorizAlignment   (LAYOUT_Dummy + 4)
#define LAYOUT_VertAlignment    (LAYOUT_Dummy + 5)
#define LAYOUT_ShrinkWrap       (LAYOUT_Dummy + 6)
#define LAYOUT_EvenSize         (LAYOUT_Dummy + 7)

#define LAYOUT_InnerSpacing     (LAYOUT_Dummy + 9)
#define LAYOUT_HorizSpacing     (LAYOUT_InnerSpacing)
#define LAYOUT_VertSpacing      (LAYOUT_InnerSpacing)

#define INTERSPACING  4
#define INTERSPACE    INTERSPACING

#define LAYOUT_TopSpacing       (LAYOUT_Dummy + 10)
#define LAYOUT_BottomSpacing    (LAYOUT_Dummy + 11)
#define LAYOUT_LeftSpacing      (LAYOUT_Dummy + 12)
#define LAYOUT_RightSpacing     (LAYOUT_Dummy + 13)
#define LAYOUT_BevelState       (LAYOUT_Dummy + 14)
#define LAYOUT_BevelStyle       (LAYOUT_Dummy + 15)
#define LAYOUT_Label            (LAYOUT_Dummy + 16)
#define LAYOUT_LabelImage       (LAYOUT_Dummy + 17)
#define LAYOUT_LabelPlace       (LAYOUT_Dummy + 18)

#define LAYOUT_RemoveChild      (LAYOUT_Dummy + 19)
#define LAYOUT_AddChild         (LAYOUT_Dummy + 20)
#define LAYOUT_AddImage         (LAYOUT_Dummy + 21)
#define LAYOUT_ModifyChild      (LAYOUT_Dummy + 22)

#define LAYOUT_RelVerify        (LAYOUT_Dummy + 23)
#define LAYOUT_RelCode          (LAYOUT_Dummy + 24)
#define LAYOUT_Parent           (LAYOUT_Dummy + 25)
#define LAYOUT_DeferLayout      (LAYOUT_Dummy + 26)
#define LAYOUT_RequestLayout    (LAYOUT_Dummy + 27)
#define LAYOUT_RequestRefresh   (LAYOUT_Dummy + 28)
#define LAYOUT_TextPen          (LAYOUT_Dummy + 29)
#define LAYOUT_FillPen          (LAYOUT_Dummy + 30)
#define LAYOUT_FillPattern      (LAYOUT_Dummy + 31)
#define LAYOUT_PageBackFill     (LAYOUT_Dummy + 32)
#define LAYOUT_BackFill         (GA_BackFill)
#define LAYOUT_TabVerify        (LAYOUT_Dummy + 33)
#define LAYOUT_LabelColumn      (LAYOUT_Dummy + 34)
#define LAYOUT_LabelWidth       (LAYOUT_Dummy + 35)
#define LAYOUT_AlignLabels      (LAYOUT_Dummy + 36)
#define LAYOUT_SpaceInner       (LAYOUT_Dummy + 37)
#define LAYOUT_SpaceOuter       (LAYOUT_Dummy + 38)
#define LAYOUT_RelAddress       (LAYOUT_Dummy + 39)
#define LAYOUT_HelpHit          (LAYOUT_Dummy + 40)
#define LAYOUT_HelpGadget       (LAYOUT_Dummy + 41)
#define LAYOUT_DisposeLabels    (LAYOUT_Dummy)
#define LAYOUT_Inverted         (LAYOUT_Dummy + 42)
#define LAYOUT_WeightBar        (LAYOUT_Dummy + 43)


/* Child tags */

#define CHILD_Dummy             (LAYOUT_Dummy + 0x100)
#define CHILD_MinWidth          (CHILD_Dummy + 1)
#define CHILD_MinHeight         (CHILD_Dummy + 2)
#define CHILD_MaxWidth          (CHILD_Dummy + 3)
#define CHILD_MaxHeight         (CHILD_Dummy + 4)
#define CHILD_WeightedWidth     (CHILD_Dummy + 5)
#define CHILD_WeightedHeight    (CHILD_Dummy + 6)
#define CHILD_ReplaceObject     (CHILD_Dummy + 7)
#define CHILD_ReplaceImage      (LAYOUT_Dummy + 8)	/*** ?!?BUG?!? ***/
#define CHILD_CacheDomain       (CHILD_Dummy + 9)
#define CHILD_WeightMinimum     (CHILD_Dummy + 10)
#define CHILD_NominalSize       (CHILD_Dummy + 11)
#define CHILD_Label             (CHILD_Dummy + 12)
#define CHILD_NoDispose         (CHILD_Dummy + 13)
#define CHILD_ScaleHeight       (CHILD_Dummy + 14)
#define CHILD_ScaleWidth        (CHILD_Dummy + 15)
#define CHILD_DataType          (CHILD_Dummy + 16)


/* Blank CHILD_Label value */

#define LCLABEL_NOLABEL  ((Object *) 1L)


/* LAYOUT_Orientation values */

#define LAYOUT_HORIZONTAL  0
#define LAYOUT_VERTICAL    1

#define LAYOUT_ORIENT_HORIZ  LAYOUT_HORIZONTAL
#define LAYOUT_ORIENT_VERT   LAYOUT_VERTICAL


/* LAYOUT_HorizAlignment values */

#define LALIGN_LEFT    0
#define LALIGN_RIGHT   1
/*#define LALIGN_CENTER  2*/

#define LAYOUT_ALIGN_LEFT    LALIGN_LEFT
#define LAYOUT_ALIGN_RIGHT   LALIGN_RIGHT
/*#define LAYOUT_ALIGN_CENTER  LALIGN_CENTER*/


/* LAYOUT_VertAlignment values */

#define LALIGN_TOP     0
#define LALIGN_BOTTOM  1
#define LALIGN_CENTER  2

#define LAYOUT_ALIGN_TOP     LALIGN_TOP
#define LAYOUT_ALIGN_BOTTOM  LALIGN_BOTTOM
#define LAYOUT_ALIGN_CENTER  LALIGN_CENTER

/* Language fix */

#define LALIGN_CENTRE        LALIGN_CENTER
#define LAYOUT_ALIGN_CENTRE  LAYOUT_ALIGN_CENTER


/* Page tags  */

#define PAGE_Dummy        (LAYOUT_Dummy + 0x200)
#define PAGE_Add          (PAGE_Dummy + 1)
#define PAGE_Remove       (PAGE_Dummy + 2)
#define PAGE_Current      (PAGE_Dummy + 3)
#define PAGE_FixedVert    (PAGE_Dummy + 4)
#define PAGE_FixedHoriz   (PAGE_Dummy + 5)
#define PAGE_Transparent  (PAGE_Dummy + 6)


#pragma pack()

#endif  /* GADGETS_LAYOUT_H */
