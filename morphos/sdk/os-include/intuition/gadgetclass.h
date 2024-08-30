#ifndef INTUITION_GADGETCLASS_H
#define INTUITION_GADGETCLASS_H

/*
	intuition gadget class definitions (V50)

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


#define GA_Dummy           (TAG_USER + 0x30000)
#define GA_Left            (GA_Dummy + 1)
#define GA_RelRight        (GA_Dummy + 2)
#define GA_Top             (GA_Dummy + 3)
#define GA_RelBottom       (GA_Dummy + 4)
#define GA_Width           (GA_Dummy + 5)
#define GA_RelWidth        (GA_Dummy + 6)
#define GA_Height          (GA_Dummy + 7)
#define GA_RelHeight       (GA_Dummy + 8)
#define GA_Text            (GA_Dummy + 9)
#define GA_Image           (GA_Dummy + 10)
#define GA_Border          (GA_Dummy + 11)
#define GA_SelectRender    (GA_Dummy + 12)
#define GA_Highlight       (GA_Dummy + 13)
#define GA_Disabled        (GA_Dummy + 14)
#define GA_GZZGadget       (GA_Dummy + 15)
#define GA_ID              (GA_Dummy + 16)
#define GA_UserData        (GA_Dummy + 17)
#define GA_SpecialInfo     (GA_Dummy + 18)
#define GA_Selected        (GA_Dummy + 19)
#define GA_EndGadget       (GA_Dummy + 20)
#define GA_Immediate       (GA_Dummy + 21)
#define GA_RelVerify       (GA_Dummy + 22)
#define GA_FollowMouse     (GA_Dummy + 23)
#define GA_RightBorder     (GA_Dummy + 24)
#define GA_LeftBorder      (GA_Dummy + 25)
#define GA_TopBorder       (GA_Dummy + 26)
#define GA_BottomBorder    (GA_Dummy + 27)
#define GA_ToggleSelect    (GA_Dummy + 28)
#define GA_SysGadget       (GA_Dummy + 29)
#define GA_SysGType        (GA_Dummy + 30)
#define GA_Previous        (GA_Dummy + 31)
#define GA_Next            (GA_Dummy + 32)
#define GA_DrawInfo        (GA_Dummy + 33)
#define GA_IntuiText       (GA_Dummy + 34)
#define GA_LabelImage      (GA_Dummy + 35)
#define GA_TabCycle        (GA_Dummy + 36)
#define GA_GadgetHelp      (GA_Dummy + 37)
#define GA_Bounds          (GA_Dummy + 38)
#define GA_RelSpecial      (GA_Dummy + 39)

/*** V42 ***/

#define GA_TextAttr        (GA_Dummy + 40)
#define GA_ReadOnly        (GA_Dummy + 41)

/*** V44 ***/

#define GA_Underscore      (GA_Dummy + 42)
#define GA_ActivateKey     (GA_Dummy + 43)
#define GA_BackFill        (GA_Dummy + 44)
#define GA_GadgetHelpText  (GA_Dummy + 45)
#define GA_UserInput       (GA_Dummy + 46)

/*** V50 ***/

  /* [I..] (LONG) Choose the placing of the label. GadgetClass does not support
     this directly. Its subclasses have to take care of that. For possible
     values see below. */
#define GA_LabelPlace      (GA_Dummy + 100)

#define GV_LabelPlace_In    1
#define GV_LabelPlace_Left  2
#define GV_LabelPlace_Right 3
#define GV_LabelPlace_Above 4
#define GV_LabelPlace_Below 5


#define PGA_Dummy       (TAG_USER + 0x31000)
#define PGA_Freedom     (PGA_Dummy + 1)
#define PGA_Borderless  (PGA_Dummy + 2)
#define PGA_HorizPot    (PGA_Dummy + 3)
#define PGA_HorizBody   (PGA_Dummy + 4)
#define PGA_VertPot     (PGA_Dummy + 5)
#define PGA_VertBody    (PGA_Dummy + 6)
#define PGA_Total       (PGA_Dummy + 7)
#define PGA_Visible     (PGA_Dummy + 8)
#define PGA_Top         (PGA_Dummy + 9)
#define PGA_NewLook     (PGA_Dummy + 10)

/*** V50 ***/

 /* [I] (UWORD) If set to PG_BEHAVIOUR_NICE OM_NOTIFY messages are sent
    also during OM_SET/OM_UPDATE, not just when user drags the knob,
    which is the default behaviour (PG_BEHAVIOUR_COMPATIBLE) */
#define PGA_NotifyBehaviour (PGA_Dummy + 30)

 /* [I] (UWORD) If set to PG_BEHAVIOUR_NICE the gadget is re-rendered
    during OM_SET/OM_UPDATE even when being a subclass of propgclass.
    The default behaviour (PG_BEHAVIOUR_COMPATIBLE) is that subclasses
    of propgclass don't render in OM_SET/OM_UPDATE */
#define PGA_RenderBehaviour (PGA_Dummy + 31)

#define PG_BEHAVIOUR_COMPATIBLE 0
#define PG_BEHAVIOUR_NICE       1


#define STRINGA_Dummy           (TAG_USER + 0x32000)
#define STRINGA_MaxChars        (STRINGA_Dummy + 1)
#define STRINGA_Buffer          (STRINGA_Dummy + 2)
#define STRINGA_UndoBuffer      (STRINGA_Dummy + 3)
#define STRINGA_WorkBuffer      (STRINGA_Dummy + 4)
#define STRINGA_BufferPos       (STRINGA_Dummy + 5)
#define STRINGA_DispPos         (STRINGA_Dummy + 6)
#define STRINGA_AltKeyMap       (STRINGA_Dummy + 7)
#define STRINGA_Font            (STRINGA_Dummy + 8)
#define STRINGA_Pens            (STRINGA_Dummy + 9)
#define STRINGA_ActivePens      (STRINGA_Dummy + 10)
#define STRINGA_EditHook        (STRINGA_Dummy + 11)
#define STRINGA_EditModes       (STRINGA_Dummy + 12)

#define STRINGA_ReplaceMode     (STRINGA_Dummy + 13)
#define STRINGA_FixedFieldMode  (STRINGA_Dummy + 14)
#define STRINGA_NoFilterMode    (STRINGA_Dummy + 15)

#define STRINGA_Justification   (STRINGA_Dummy + 16)
#define STRINGA_LongVal         (STRINGA_Dummy + 17)
#define STRINGA_TextVal         (STRINGA_Dummy + 18)

#define STRINGA_ExitHelp        (STRINGA_Dummy + 19)

#define STRINGA_InvisibleTextOk (STRINGA_Dummy + 500)

#define SG_DEFAULTMAXCHARS  (128)


#define LAYOUTA_Dummy           (TAG_USER + 0x38000)
#define LAYOUTA_LayoutObj       (LAYOUTA_Dummy + 1)
#define LAYOUTA_Spacing         (LAYOUTA_Dummy + 2)
#define LAYOUTA_Orientation     (LAYOUTA_Dummy + 3)

/*** V42 ***/

#define LAYOUTA_ChildMaxWidth   (LAYOUTA_Dummy + 4)
#define LAYOUTA_ChildMaxHeight  (LAYOUTA_Dummy + 5)


#define LORIENT_NONE    0
#define LORIENT_HORIZ   1
#define LORIENT_VERT    2


#define GM_Dummy         (-1)
#define GM_HITTEST        (0)
#define GM_RENDER         (1)
#define GM_GOACTIVE       (2)
#define GM_HANDLEINPUT    (3)
#define GM_GOINACTIVE     (4)
#define GM_HELPTEST       (5)
#define GM_LAYOUT         (6)
#define GM_DOMAIN         (7)
#define GM_KEYTEST        (8)
#define GM_KEYGOACTIVE    (9)
#define GM_KEYGOINACTIVE  (10)


struct gpHitTest
{
	ULONG              MethodID;
	struct GadgetInfo *gpht_GInfo;

	struct
	{
		WORD X;
		WORD Y;
	}                  gpht_Mouse;
};


#define GMR_GADGETHIT  (0x00000004)
#define GMR_NOHELPHIT  (0x00000000)
#define GMR_HELPHIT    (0xFFFFFFFF)
#define GMR_HELPCODE   (0x00010000)


struct gpRender
{
	ULONG              MethodID;
	struct GadgetInfo *gpr_GInfo;
	struct RastPort   *gpr_RPort;
	LONG               gpr_Redraw;
};

#define GREDRAW_UPDATE  (2)
#define GREDRAW_REDRAW  (1)
#define GREDRAW_TOGGLE  (0)


struct gpInput
{
	ULONG              MethodID;
	struct GadgetInfo *gpi_GInfo;
	struct InputEvent *gpi_IEvent;
	LONG              *gpi_Termination;

	struct
	{
		WORD X;
		WORD Y;
	}                  gpi_Mouse;

	struct TabletData *gpi_TabletData;
};

#define GMR_MEACTIVE    (0)
#define GMR_NOREUSE     (1<<1)
#define GMR_REUSE       (1<<2)
#define GMR_VERIFY      (1<<3)

#define GMR_NEXTACTIVE  (1<<4)
#define GMR_PREVACTIVE  (1<<5)


struct gpGoInactive
{
	ULONG              MethodID;
	struct GadgetInfo *gpgi_GInfo;

	ULONG              gpgi_Abort;
};


struct gpLayout
{
	ULONG              MethodID;
	struct GadgetInfo *gpl_GInfo;
	ULONG              gpl_Initial;
};


struct gpDomain
{
	ULONG              MethodID;
	struct GadgetInfo *gpd_GInfo;
	struct RastPort   *gpd_RPort;
	LONG               gpd_Which;
	struct IBox        gpd_Domain;
	struct TagItem    *gpd_Attrs;
};

#define GDOMAIN_MINIMUM  (0)
#define GDOMAIN_NOMINAL  (1)
#define GDOMAIN_MAXIMUM  (2)


struct gpKeyTest
{
	ULONG                MethodID;
	struct GadgetInfo   *gpkt_GInfo;
	struct IntuiMessage *gpkt_IMsg;
	ULONG                gpkt_VanillaKey;
};


struct gpKeyInput
{
	ULONG              MethodID;
	struct GadgetInfo *gpk_GInfo;
	struct InputEvent *gpk_IEvent;
	LONG              *gpk_Termination;
};

#define GMR_KEYACTIVE  (1<<4)
#define GMR_KEYVERIFY  (1<<5)


struct gpKeyGoInactive
{
	ULONG              MethodID;
	struct GadgetInfo *gpki_GInfo;
	ULONG              gpki_Abort;
};


#pragma pack()

#ifndef INTUITION_IOBSOLETE_H
# include <intuition/iobsolete.h>
#endif

#endif /* INTUITION_GADGETCLASS_H */
