#ifndef INTUITION_INTUITION_H
#define INTUITION_INTUITION_H

/*
	intuition definitions

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef GRAPHICS_GFX_H
# include <graphics/gfx.h>
#endif

#ifndef GRAPHICS_CLIP_H
# include <graphics/clip.h>
#endif

#ifndef GRAPHICS_VIEW_H
# include <graphics/view.h>
#endif

#ifndef GRAPHICS_RASTPORT_H
# include <graphics/rastport.h>
#endif

#ifndef GRAPHICS_LAYERS_H
# include <graphics/layers.h>
#endif

#ifndef GRAPHICS_TEXT_H
# include <graphics/text.h>
#endif

#ifndef EXEC_PORTS_H
# include <exec/ports.h>
#endif

#ifndef DEVICES_INPUTEVENT_H
# include <devices/inputevent.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


struct Menu
{
	struct Menu     *NextMenu;
	WORD             LeftEdge, TopEdge;
	WORD             Width, Height;
	UWORD            Flags;
	BYTE            *MenuName;
	struct MenuItem *FirstItem;

	WORD             JazzX, JazzY, BeatX, BeatY;
};


#define MENUENABLED  0x0001
#define MIDRAWN      0x0100


struct MenuItem
{
	struct MenuItem *NextItem;
	WORD             LeftEdge, TopEdge;
	WORD             Width, Height;
	UWORD            Flags;

	LONG             MutualExclude;

	APTR             ItemFill;

	APTR             SelectFill;

	BYTE             Command;

	struct MenuItem *SubItem;

	UWORD            NextSelect;
};


#define CHECKIT      0x0001
#define ITEMTEXT     0x0002
#define COMMSEQ      0x0004
#define MENUTOGGLE   0x0008
#define ITEMENABLED  0x0010

#define HIGHFLAGS    0x00C0
#define HIGHIMAGE    0x0000
#define HIGHCOMP     0x0040
#define HIGHBOX      0x0080
#define HIGHNONE     0x00C0

#define CHECKED      0x0100

#define ISDRAWN      0x1000
#define HIGHITEM     0x2000
#define MENUTOGGLED  0x4000


struct Requester
{
	struct Requester *OlderRequest;
	WORD              LeftEdge, TopEdge;
	WORD              Width, Height;
	WORD              RelLeft, RelTop;

	struct Gadget    *ReqGadget;
	struct Border    *ReqBorder;
	struct IntuiText *ReqText;
	UWORD             Flags;

	UBYTE             BackFill;
	struct Layer     *ReqLayer;
	UBYTE             ReqPad1[32];

	struct BitMap    *ImageBMap;
	struct Window    *RWindow;

	struct Image     *ReqImage;
	UBYTE             ReqPad2[32];
};


#define POINTREL       0x0001
#define PREDRAWN       0x0002
#define NOISYREQ       0x0004
#define SIMPLEREQ      0x0010
#define USEREQIMAGE    0x0020
#define NOREQBACKFILL  0x0040

#define REQOFFWINDOW   0x1000
#define REQACTIVE      0x2000
#define SYSREQUEST     0x4000
#define DEFERREFRESH   0x8000


struct Gadget
{
	struct Gadget    *NextGadget;

	WORD              LeftEdge, TopEdge;
	WORD              Width, Height;

	UWORD             Flags;
	UWORD             Activation;

	UWORD             GadgetType;
	APTR              GadgetRender;
	APTR              SelectRender;

	struct IntuiText *GadgetText;
	LONG              MutualExclude;
	APTR              SpecialInfo;

	UWORD             GadgetID;
	APTR              UserData;
};


struct ExtGadget
{
	struct ExtGadget *NextGadget;
	WORD              LeftEdge, TopEdge;
	WORD              Width, Height;
	UWORD             Flags;
	UWORD             Activation;
	UWORD             GadgetType;
	APTR              GadgetRender;
	APTR              SelectRender;
	struct IntuiText *GadgetText;
	LONG              MutualExclude;
	APTR              SpecialInfo;
	UWORD             GadgetID;
	APTR              UserData;

	ULONG             MoreFlags;
	WORD              BoundsLeftEdge;
	WORD              BoundsTopEdge;
	WORD              BoundsWidth;
	WORD              BoundsHeight;
};


#define GFLG_GADGHIGHBITS  0x0003
#define GFLG_GADGHCOMP     0x0000
#define GFLG_GADGHBOX      0x0001
#define GFLG_GADGHIMAGE    0x0002
#define GFLG_GADGHNONE     0x0003
#define GFLG_GADGIMAGE     0x0004

#define GFLG_RELBOTTOM     0x0008
#define GFLG_RELRIGHT      0x0010
#define GFLG_RELWIDTH      0x0020
#define GFLG_RELHEIGHT     0x0040

#define GFLG_RELSPECIAL    0x4000
#define GFLG_SELECTED      0x0080
#define GFLG_DISABLED      0x0100

#define GFLG_LABELMASK     0x3000
#define GFLG_LABELITEXT    0x0000
#define GFLG_LABELSTRING   0x1000
#define GFLG_LABELIMAGE    0x2000

#define GFLG_TABCYCLE      0x0200
#define GFLG_STRINGEXTEND  0x0400
#define GFLG_IMAGEDISABLE  0x0800

#define GFLG_EXTENDED      0x8000


#define GACT_RELVERIFY     0x0001
#define GACT_IMMEDIATE     0x0002
#define GACT_ENDGADGET     0x0004
#define GACT_FOLLOWMOUSE   0x0008

#define GACT_RIGHTBORDER   0x0010
#define GACT_LEFTBORDER    0x0020
#define GACT_TOPBORDER     0x0040
#define GACT_BOTTOMBORDER  0x0080
#define GACT_BORDERSNIFF   0x8000

#define GACT_TOGGLESELECT  0x0100
#define GACT_BOOLEXTEND    0x2000

#define GACT_STRINGLEFT    0x0000
#define GACT_STRINGCENTER  0x0200
#define GACT_STRINGRIGHT   0x0400
#define GACT_LONGINT       0x0800
#define GACT_ALTKEYMAP     0x1000
#define GACT_STRINGEXTEND  0x2000

#define GACT_ACTIVEGADGET  0x4000


#define GTYP_GADGETTYPE    0xFC00

#define GTYP_SCRGADGET     0x4000
#define GTYP_GZZGADGET     0x2000
#define GTYP_REQGADGET     0x1000

#define GTYP_SYSGADGET     0x8000
#define GTYP_SYSTYPEMASK   0x00F0

#define GTYP_SIZING        0x0010
#define GTYP_WDRAGGING     0x0020
#define GTYP_SDRAGGING     0x0030
#define GTYP_WDEPTH        0x0040
#define GTYP_SDEPTH        0x0050
#define GTYP_WZOOM         0x0060
#define GTYP_SUNUSED       0x0070
#define GTYP_CLOSE         0x0080

/* V50 SYSGADGET types */
#define GTYP_WDRAGGING2    0x0090 /* GTYP_WDRAGGING2 gadgets only send IDCMP_GADGETDOWN, this one also sends IDCMP_GADGETUP*/

#define GTYP_WUPFRONT      GTYP_WDEPTH
#define GTYP_SUPFRONT      GTYP_SDEPTH
#define GTYP_WDOWNBACK     GTYP_WZOOM
#define GTYP_SDOWNBACK     GTYP_SUNUSED

#define GTYP_GTYPEMASK     0x0007

#define GTYP_BOOLGADGET    0x0001
#define GTYP_GADGET0002    0x0002
#define GTYP_PROPGADGET    0x0003
#define GTYP_STRGADGET     0x0004
#define GTYP_CUSTOMGADGET  0x0005


#define GMORE_BOUNDS        0x00000001L
#define GMORE_GADGETHELP    0x00000002L
#define GMORE_SCROLLRASTER  0x00000004L


struct BoolInfo
{
	UWORD  Flags;
	UWORD *Mask;
	ULONG  Reserved;
};

#define BOOLMASK  0x0001


struct PropInfo
{
	UWORD Flags;

	UWORD HorizPot;
	UWORD VertPot;

	UWORD HorizBody;
	UWORD VertBody;

	UWORD CWidth;
	UWORD CHeight;
	UWORD HPotRes, VPotRes;
	UWORD LeftBorder;
	UWORD TopBorder;
};


#define AUTOKNOB        0x0001
#define FREEHORIZ       0x0002
#define FREEVERT        0x0004
#define PROPBORDERLESS  0x0008
#define KNOBHIT         0x0100
#define PROPNEWLOOK     0x0010

#define KNOBHMIN  6
#define KNOBVMIN  4
#define MAXBODY   0xFFFF
#define MAXPOT    0xFFFF


struct StringInfo
{
	UBYTE               *Buffer;
	UBYTE               *UndoBuffer;
	WORD                 BufferPos;
	WORD                 MaxChars;
	WORD                 DispPos;

	WORD                 UndoPos;
	WORD                 NumChars;
	WORD                 DispCount;
	WORD                 CLeft, CTop;

	struct StringExtend *Extension;

	LONG                 LongInt;

	struct KeyMap       *AltKeyMap;
};


struct IntuiText
{
	UBYTE             FrontPen, BackPen;
	UBYTE             DrawMode;
	WORD              LeftEdge;
	WORD              TopEdge;
	struct TextAttr  *ITextFont;
	UBYTE            *IText;
	struct IntuiText *NextText;
};


struct Border
{
	WORD           LeftEdge, TopEdge;
	UBYTE          FrontPen, BackPen;
	UBYTE          DrawMode;
	BYTE           Count;
	WORD          *XY;
	struct Border *NextBorder;
};


struct Image
{
	WORD          LeftEdge;
	WORD          TopEdge;
	WORD          Width;
	WORD          Height;
	WORD          Depth;
	UWORD        *ImageData;

	UBYTE         PlanePick, PlaneOnOff;

	struct Image *NextImage;
};


struct IntuiMessage
{
	struct Message       ExecMessage;

	ULONG                Class;
	UWORD                Code;
	UWORD                Qualifier;
	APTR                 IAddress;

	WORD                 MouseX, MouseY;
	ULONG                Seconds, Micros;

	struct Window       *IDCMPWindow;

	struct IntuiMessage *SpecialLink;
};


struct ExtIntuiMessage
{
	struct IntuiMessage eim_IntuiMessage;
	struct TabletData  *eim_TabletData;
};


#define IDCMP_SIZEVERIFY        0x00000001
#define IDCMP_NEWSIZE           0x00000002
#define IDCMP_REFRESHWINDOW     0x00000004
#define IDCMP_MOUSEBUTTONS      0x00000008
#define IDCMP_MOUSEMOVE         0x00000010
#define IDCMP_GADGETDOWN        0x00000020
#define IDCMP_GADGETUP          0x00000040
#define IDCMP_REQSET            0x00000080
#define IDCMP_MENUPICK          0x00000100
#define IDCMP_CLOSEWINDOW       0x00000200
#define IDCMP_RAWKEY            0x00000400
#define IDCMP_REQVERIFY         0x00000800
#define IDCMP_REQCLEAR          0x00001000
#define IDCMP_MENUVERIFY        0x00002000
#define IDCMP_NEWPREFS          0x00004000
#define IDCMP_DISKINSERTED      0x00008000
#define IDCMP_DISKREMOVED       0x00010000
#define IDCMP_WBENCHMESSAGE     0x00020000
#define IDCMP_ACTIVEWINDOW      0x00040000
#define IDCMP_INACTIVEWINDOW    0x00080000
#define IDCMP_DELTAMOVE         0x00100000
#define IDCMP_VANILLAKEY        0x00200000
#define IDCMP_INTUITICKS        0x00400000
#define IDCMP_IDCMPUPDATE       0x00800000
#define IDCMP_MENUHELP          0x01000000
#define IDCMP_CHANGEWINDOW      0x02000000
#define IDCMP_GADGETHELP        0x04000000

#define IDCMP_MOUSEHOVER        0x08000000 /* v50 */
#define IDCMP_MOUSEOBJECTMUI    0x40000000 /* special idcmp message created by MUI */

#define IDCMP_LONELYMESSAGE     0x80000000


#define CWCODE_MOVESIZE   0x0000
#define CWCODE_DEPTH      0x0001

#define MENUHOT          0x0001
#define MENUCANCEL       0x0002
#define MENUWAITING      0x0003

#define OKOK             MENUHOT
#define OKABORT          0x0004
#define OKCANCEL         MENUCANCEL

#define WBENCHOPEN       0x0001
#define WBENCHCLOSE      0x0002

#define HOVERSTART       0x0001 /* v50 */
#define HOVERSTOP        0x0002 /* v50 */

struct IBox
{
	WORD Left;
	WORD Top;
	WORD Width;
	WORD Height;
};


struct Window
{
	struct Window       *NextWindow;

	WORD                 LeftEdge, TopEdge;
	WORD                 Width, Height;

	WORD                 MouseY, MouseX;

	WORD                 MinWidth, MinHeight;
	UWORD                MaxWidth, MaxHeight;

	ULONG                Flags;

	struct Menu         *MenuStrip;

	UBYTE               *Title;

	struct Requester    *FirstRequest;

	struct Requester    *DMRequest;

	WORD                 ReqCount;

	struct Screen       *WScreen;
	struct RastPort     *RPort;

	BYTE                 BorderLeft, BorderTop, BorderRight, BorderBottom;
	struct RastPort     *BorderRPort;

	struct Gadget       *FirstGadget;

	struct Window       *Parent, *Descendant;

	UWORD               *Pointer;
	BYTE                 PtrHeight;
	BYTE                 PtrWidth;
	BYTE                 XOffset, YOffset;

	ULONG                IDCMPFlags;
	struct MsgPort      *UserPort, *WindowPort;
	struct IntuiMessage *MessageKey;

	UBYTE                DetailPen, BlockPen;

	struct Image        *CheckMark;

	UBYTE               *ScreenTitle;

	WORD                 GZZMouseX;
	WORD                 GZZMouseY;
	WORD                 GZZWidth;
	WORD                 GZZHeight;

	UBYTE               *ExtData;

	BYTE                *UserData;

	struct Layer        *WLayer;

	struct TextFont     *IFont;

	ULONG                MoreFlags;
};


#define WFLG_SIZEGADGET      0x00000001
#define WFLG_DRAGBAR         0x00000002
#define WFLG_DEPTHGADGET     0x00000004
#define WFLG_CLOSEGADGET     0x00000008

#define WFLG_SIZEBRIGHT      0x00000010
#define WFLG_SIZEBBOTTOM     0x00000020

#define WFLG_REFRESHBITS     0x000000C0
#define WFLG_SMART_REFRESH   0x00000000
#define WFLG_SIMPLE_REFRESH  0x00000040
#define WFLG_SUPER_BITMAP    0x00000080
#define WFLG_OTHER_REFRESH   0x000000C0

#define WFLG_BACKDROP        0x00000100

#define WFLG_REPORTMOUSE     0x00000200

#define WFLG_GIMMEZEROZERO   0x00000400

#define WFLG_BORDERLESS      0x00000800

#define WFLG_ACTIVATE        0x00001000

#define WFLG_RMBTRAP         0x00010000
#define WFLG_NOCAREREFRESH   0x00020000

#define WFLG_NW_EXTENDED     0x00040000

#define WFLG_NEWLOOKMENUS    0x00200000

#define WFLG_WINDOWACTIVE    0x00002000
#define WFLG_INREQUEST       0x00004000
#define WFLG_MENUSTATE       0x00008000
#define WFLG_WINDOWREFRESH   0x01000000
#define WFLG_WBENCHWINDOW    0x02000000
#define WFLG_WINDOWTICKED    0x04000000

#define WFLG_VISITOR         0x08000000
#define WFLG_ZOOMED          0x10000000
#define WFLG_HASZOOM         0x20000000


#define DEFAULTMOUSEQUEUE  (5)


struct NewWindow
{
	WORD           LeftEdge, TopEdge;
	WORD           Width, Height;

	UBYTE          DetailPen, BlockPen;
	ULONG          IDCMPFlags;
	ULONG          Flags;
	struct Gadget *FirstGadget;

	struct Image  *CheckMark;

	UBYTE         *Title;
	struct Screen *Screen;
	struct BitMap *BitMap;

	WORD           MinWidth, MinHeight;
	UWORD          MaxWidth, MaxHeight;

	UWORD          Type;
};

struct ExtNewWindow
{
	WORD            LeftEdge, TopEdge;
	WORD            Width, Height;

	UBYTE           DetailPen, BlockPen;
	ULONG           IDCMPFlags;
	ULONG           Flags;
	struct Gadget  *FirstGadget;

	struct Image   *CheckMark;

	UBYTE          *Title;
	struct Screen  *Screen;
	struct BitMap  *BitMap;

	WORD            MinWidth, MinHeight;
	UWORD           MaxWidth, MaxHeight;

	UWORD           Type;

	struct TagItem *Extension;
};


#define WA_Dummy                              (TAG_USER + 99)
#define WA_Left         /* ISG */             (WA_Dummy + 1)
#define WA_Top          /* ISG */             (WA_Dummy + 2)
#define WA_Width        /* ISG */             (WA_Dummy + 3)
#define WA_Height       /* ISG */             (WA_Dummy + 4)
#define WA_DetailPen    /* I* */              (WA_Dummy + 5)
#define WA_BlockPen     /* I* */              (WA_Dummy + 6)
#define WA_IDCMP        /* ISG */             (WA_Dummy + 7)
#define WA_Flags        /* I** */             (WA_Dummy + 8)
#define WA_Gadgets      /* I** */             (WA_Dummy + 9)
#define WA_Checkmark    /* I** */             (WA_Dummy + 10)
#define WA_Title        /* I** */             (WA_Dummy + 11)
#define WA_ScreenTitle  /* I** */             (WA_Dummy + 12)
#define WA_CustomScreen /* I** */             (WA_Dummy + 13)
#define WA_SuperBitMap  /* I** */             (WA_Dummy + 14)
#define WA_MinWidth     /* ISG */             (WA_Dummy + 15)
#define WA_MinHeight    /* ISG */             (WA_Dummy + 16)
#define WA_MaxWidth     /* ISG */             (WA_Dummy + 17)
#define WA_MaxHeight    /* ISG */             (WA_Dummy + 18)

#define WA_InnerWidth   /* ISG */             (WA_Dummy + 19)
#define WA_InnerHeight  /* ISG */             (WA_Dummy + 20)
#define WA_PubScreenName  /* I** */           (WA_Dummy + 21)
#define WA_PubScreen      /* I** */           (WA_Dummy + 22)
#define WA_PubScreenFallBack  /* I** */       (WA_Dummy + 23)
#define WA_WindowName   /* I** */             (WA_Dummy + 24)
#define WA_Colors       /* I** */             (WA_Dummy + 25)
#define WA_Zoom         /* I*G */             (WA_Dummy + 26)
#define WA_MouseQueue   /* I** */             (WA_Dummy + 27)
#define WA_BackFill     /* I** */             (WA_Dummy + 28)
#define WA_RptQueue     /* I** */             (WA_Dummy + 29)

#define WA_SizeGadget   /* I** */             (WA_Dummy + 30)
#define WA_DragBar      /* I** */             (WA_Dummy + 31)
#define WA_DepthGadget  /* I** */             (WA_Dummy + 32)
#define WA_CloseGadget  /* I** */             (WA_Dummy + 33)
#define WA_Backdrop     /* I** */             (WA_Dummy + 34)
#define WA_ReportMouse  /* I** */             (WA_Dummy + 35)
#define WA_NoCareRefresh /* I** */            (WA_Dummy + 36)
#define WA_Borderless   /* I** */             (WA_Dummy + 37)
#define WA_Activate     /* I** */             (WA_Dummy + 38)
#define WA_RMBTrap      /* I** */             (WA_Dummy + 39)
#define WA_WBenchWindow /* I** */             (WA_Dummy + 40)
#define WA_SimpleRefresh /* I** */            (WA_Dummy + 41)
#define WA_SmartRefresh /* I** */             (WA_Dummy + 42)
#define WA_SizeBRight   /* I** */             (WA_Dummy + 43)
#define WA_SizeBBottom  /* I** */             (WA_Dummy + 44)

#define WA_AutoAdjust   /* I** */             (WA_Dummy + 45)
#define WA_GimmeZeroZero /* I** */            (WA_Dummy + 46)

#define WA_MenuHelp     /* I** */             (WA_Dummy + 47)
#define WA_NewLookMenus /* I** */             (WA_Dummy + 48)
#define WA_AmigaKey     /* I** */             (WA_Dummy + 49)
#define WA_NotifyDepth  /* I** */             (WA_Dummy + 50)

#define WA_Pointer      /* IS* */             (WA_Dummy + 52)
#define WA_BusyPointer  /* ISG */             (WA_Dummy + 53)
#define WA_PointerDelay /* IS* */             (WA_Dummy + 54)
#define WA_TabletMessages /* I** */           (WA_Dummy + 55)
#define WA_HelpGroup    /* I** */             (WA_Dummy + 56)
#define WA_HelpGroupWindow /* I** */          (WA_Dummy + 57)

/* new OpenWindowTags tags (added some padding there) */

/* V50 */


#define WA_ExtraTitlebarGadgets /* I** */       (WA_Dummy + 151)

/* ULONG flag field to indicate window titlebar gadgets
** your app wants to use. Those are built-in in sysiclass
** and use intuition skins system.
** You'll be notified with normal IDCMP_GADGETUP when one
** of those gadgets get pressed.
*/

#define WA_ExtraGadgetsStartID /* I** */        (WA_Dummy + 152)

/* All the extra gadgets have the Gadget ID's set to
** ETI_Dummy + gadget id value (defined below). Set this tag
** if you want to change ETI_Dummy value for your gadgets.
** (for example when those ID's are already in use)
*/

/* instead of using WA_ExtraTitlebarGadgets... */
#define WA_ExtraGadget_Iconify /* IS* */        (WA_Dummy + 153)
#define WA_ExtraGadget_Lock    /* IS* */        (WA_Dummy + 154)
#define WA_ExtraGadget_MUI     /* IS* */        (WA_Dummy + 155)
#define WA_ExtraGadget_PopUp   /* IS* */        (WA_Dummy + 156)
#define WA_ExtraGadget_Snapshot /* IS* */       (WA_Dummy + 157)
#define WA_ExtraGadget_Jump    /* IS* */        (WA_Dummy + 158)

#define WA_SkinInfo            /* I** */        (WA_Dummy + 159)

/* Intuition skins system usualy enchances window size when
** SIZEIMAGE width/height forces non-std border sizes.
** If your app already knows about the border sizes (GetSkinInfo)
** please add this tag to your OpenWindow call. This will switch
** off window size adjustment.
** ti_Data should point to SkinInfo struct allocated by GetSkinInfo.
** IMPORTANT: passing WA_SkinInfo tag to OpenWindowTags means
** that your app IS Skin compilant. Expect windows with non
** standard titlebar height, etc when you pass it (also with NULL
** tag->ti_Data!)
*/

#define WA_TransparentRegion    /* I** */       (WA_Dummy + 160)

/* Installs the provided region as a transparent region in window's layer.
** Best solution for fixed size windows. Setting WA_TransparentRegion clears
** previously set WA_TransparentRegionHook!
**
** For more information please refer to intuition/TransparencyControl() autodoc.
*/

#define WA_TransparentRegionHook /* I** */      (WA_Dummy + 161)

/* Installs the provided transparent region hook. The hook is called whenever
** window's layer needs updating (usualy on resize). The hook is called with
** window pointer in A2 and struct TransparencyMessage * in A1 registers.
** Setting this tag clears previously set WA_TransparentRegion!
**
** For more information please refer to intuition/TransparencyControl() autodoc.
*/

#define WA_UserPort              /* I*G */       (WA_Dummy + 162)
/* Please note that ModifyIDCMP(win,NULL) WILL NOT FREE userport
** when you use WA_UserPort!!! It will also NOT create a new msg
** port later!!! Keep in mind that ModifyIDCMP(win,NULL) will
** clear win->UserPort, but NOT free it - you need to store it and
** free manually! CloseWindow() doesn't free the port as well.
** IMPORTANT: remember that you need to reply all messages before
** the msg port was detached from all your windows!
*/

/* V51 */

#define WA_ToolbarWindow /* I** */              (WA_Dummy + 163) 
/* Toolbar windows are windows that cannot be activated. They react
** fine on IDCMP_MOUSEBUTTONS, IDCMP_MOUSEMOVE, IDCMP_INTUITICKS, but
** only on those. The one and only supported intuition gadget is a
** GTYP_WDRAGGING(2) gadget, rest will be ignored. Toolbar windows
** are _always_ borderless.
*/

#define WA_PointerType /* ISG */                (WA_Dummy + 164) 
/* Use one of intuition's built-in pointers in your window. There's
** basicly everything an app should need there - please avoid using
** custom pointers when possible.
*/

#define WA_FrontWindow  /* I** */               (WA_Dummy + 165) 
/* Window stays always on front of other windows.
*/

#define WA_Parent       /* I*G */               (WA_Dummy + 166) 
/* struct Window *. Makes the new window a child window of the one
** passed in ti_Data. Useful for popup windows - you can set
** child window position relatively to parent top/leftedge, child
** windows are also depth arranged with their parent
** windows, but NOT dragged (you need to care about this yourself).
*/


#define WA_Opacity /* ISG */                    (WA_Dummy + 168)
/* ULONG. A 32bit opacity value. Use 0xFFFFFFFF for full visibility.
** NOTES: GZZ windows are not supported */

#define WA_HasAlpha /* ISG */                   (WA_Dummy + 169)
/* BOOL. Set to TRUE to make the window use the alpha data of it's
** buffer as window's opacity level
** NOTES: GZZ windows are not supported */


#define WA_SizeNumerator /* ISG */              (WA_Dummy + 171)
#define WA_SizeDenominator /* ISG */            (WA_Dummy + 172)
#define WA_SizeExtraWidth /* ISG */             (WA_Dummy + 173)
#define WA_SizeExtraHeight /* ISG */            (WA_Dummy + 174)
/* ULONG. The four attributes define how the window should act when
** the user resizes it. This allows to define an aspect ratio in
** which the window will be resized. ExtraWidth/Height attributes
** specify the total size of the area which the aspect ratio resize
** should not include (toolbars, window borders, etc).
** To disable aspect resizing, set the Numerator and Denominator to 1.
** Setting aspect resize doesn't resize the window or change it's 
** size limits - you have to do it yourself. */

#define WA_HitLevel /* ISG */                   (WA_Dummy + 175)
/* ULONG. Defines the maximum opacity value to which the window
** will not be clickable. Unlike WA_Opacity, the value is in the
** 0-255 range. WA_HitLevel,0 will make the window clickable if
** it's opacity is != 0. Use 255 to make a fully visible window
** ignore mouse clicks, hovering, etc */

#define WA_ShadowTop    /* ISG */               (WA_Dummy + 176)
#define WA_ShadowLeft   /* ISG */               (WA_Dummy + 177)
#define WA_ShadowRight  /* ISG */               (WA_Dummy + 178)
#define WA_ShadowBottom /* ISG */               (WA_Dummy + 179)
/* BOOL. Some skins might support window shadows in certain display
** modes (depending on the hardware). In such case all windows with
** a window border will be given a shadow. You can query if the
** shadow is on with those attributes (to disable your own fake shadows,
** etc). Set any of the tags above to false to disable a certain
** part of the shadow. Set any of the tags above to true to force
** shadows in a borderless window */

#define WA_VisibleOnMaximize /* ISG */          (WA_Dummy + 180)
/* BOOL. When maximizing windows, intuition will take the windows
** with this tag on into the account and substract them from the
** area the maximized window will cover. Do note that intuition will
** not take windows that are not touching any screen border into the
** account. You should generally let user decide if he wants this
** functionality or not */

#define WA_Unicode /* I*G */                    (WA_Dummy + 181)
/* BOOL. If set to true, the window menu titles are assumed to be
** encoded in UTF-8. Defaults to FALSE. */

#define WA_RealtimeLayer /* I** */              (WA_Dummy + 182)
/* BOOL. If set to true, the window's layers will be realtime.
** OpenWindow will fail if the screen isn't composited. Window must
** be a borderless one. */

/* window methods */
#define WM_Dummy WA_Dummy

#define WM_OpenMenu                             (WM_Dummy + 1)
/* void. Makes intuition open a menu for the window the method was
** called on. Does nothing if there is no menu or the system
** is busy. Will fail silently if the menu did not open */

#define WM_ObtainEvents                         (WM_Dummy + 2)
/* BOOL. Obtains the events for the screen the window is at.
** This is an equivalent of installing your own, high priority
** inputhandler to capture input events. All IDCMPs will
** be sent to your window. Clicking outside of your window
** will not send events to other windows or cause their activation.
** Intuition menus will not be opened. The mouse pointer will use
** whatever your window has set, even if your window was not
** active when you obtained the pointer. Use this solely for the
** purpose of letting user pick a window, mark some area for
** snapshoting, etc. Will return FALSE if another window
** currently owns the events or your window already owns them.
** If the method returns true, you are the pointer owner and
** MUST match the call with WM_ReleaseEvents after you are done.
** For security reasons, if your application crashes or refuses
** to reply to IDCMP messages, the event ownership might be
** silently revoked. If a new window opens or gets activated
** while you have the ownership, it will be revoked and you
** will receive an IDCMP_INACTIVEWINDOW idcmp (even if your window
** is still active or was inactive before obtaining the pointer).
** The IDCMPS that your window will actually capture are:
** IDCMP_MOUSEMOVE, IDCMP_MOUSEBUTTON, IDCMP_RAWKEY,
** IDCMP_VANILLAKEY, IDCMP_INTUITICKS */

#define WM_ReleaseEvents                        (WM_Dummy + 3)
/* void. Releases the events obtained with WM_ObtainEvents. You MUST
** always call it after WM_ObtainEvents returned TRUE. It is safe
** to call it in case your events ownership was revoked by the
** system */


#define HC_GADGETHELP  (1)


#pragma pack()

#ifndef INTUITION_SCREENS_H
# include <intuition/screens.h>
#endif

#ifndef INTUITION_PREFERENCES_H
# include <intuition/preferences.h>
#endif

#pragma pack(2)


struct Remember
{
	struct Remember *NextRemember;
	ULONG            RememberSize;
	UBYTE           *Memory;
};


struct ColorSpec
{
	WORD  ColorIndex;
	UWORD Red;
	UWORD Green;
	UWORD Blue;
};

struct EasyStruct
{
	ULONG  es_StructSize;
	ULONG  es_Flags;
	UBYTE *es_Title;
	UBYTE *es_TextFormat;
	UBYTE *es_GadgetFormat;
};


#define MENUNUM(n)                  ((n) & 0x1F)
#define ITEMNUM(n)                  (((n) >> 5) & 0x003F)
#define SUBNUM(n)                   (((n) >> 11) & 0x001F)

#define SHIFTMENU(n)                ((n) & 0x1F)
#define SHIFTITEM(n)                (((n) & 0x3F) << 5)
#define SHIFTSUB(n)                 (((n) & 0x1F) << 11)

#define FULLMENUNUM(menu,item,sub)  (SHIFTSUB(sub) | SHIFTITEM(item) | SHIFTMENU(menu))

#define SRBNUM(n)                   (0x08 - ((n) >> 4))
#define SWBNUM(n)                   (0x08 - ((n) & 0x0F))
#define SSBNUM(n)                   (0x01 + ((n) >> 4))
#define SPARNUM(n)                  ((n) >> 4)
#define SHAKNUM(n)                  ((n) & 0x0F)


#define NOMENU    0x001F
#define NOITEM    0x003F
#define NOSUB     0x001F
#define MENUNULL  0xFFFF


#define FOREVER  for(;;)
#ifdef __GNUC__
# define SIGN(x)  ({typeof(x) __tmpx__ = (x); ((__tmpx__) > 0) - ((__tmpx__) < 0);})
#else /* __GNUC__ */
# define SIGN(x)  (((x) > 0) - ((x) < 0))
#endif /* __GNUC__ */
#define NOT      !


#define CHECKWIDTH     19
#define COMMWIDTH      27
#define LOWCHECKWIDTH  13
#define LOWCOMMWIDTH   16


#define ALERT_TYPE      0x80000000
#define RECOVERY_ALERT  0x00000000
#define DEADEND_ALERT   0x80000000


#define AUTOFRONTPEN   0
#define AUTOBACKPEN    1
#define AUTODRAWMODE   JAM2
#define AUTOLEFTEDGE   6
#define AUTOTOPEDGE    3
#define AUTOITEXTFONT  NULL
#define AUTONEXTTEXT   NULL


#define SELECTUP    (IECODE_LBUTTON | IECODE_UP_PREFIX)
#define SELECTDOWN  (IECODE_LBUTTON)
#define MENUUP      (IECODE_RBUTTON | IECODE_UP_PREFIX)
#define MENUDOWN    (IECODE_RBUTTON)
#define MIDDLEUP    (IECODE_MBUTTON | IECODE_UP_PREFIX)
#define MIDDLEDOWN  (IECODE_MBUTTON)
#define ALTLEFT     (IEQUALIFIER_LALT)
#define ALTRIGHT    (IEQUALIFIER_RALT)
#define AMIGALEFT   (IEQUALIFIER_LCOMMAND)
#define AMIGARIGHT  (IEQUALIFIER_RCOMMAND)
#define AMIGAKEYS   (AMIGALEFT | AMIGARIGHT)

#define CURSORUP         0x4C
#define CURSORLEFT       0x4F
#define CURSORRIGHT      0x4E
#define CURSORDOWN       0x4D
#define KEYCODE_Q        0x10
#define KEYCODE_Z        0x31
#define KEYCODE_X        0x32
#define KEYCODE_V        0x34
#define KEYCODE_B        0x35
#define KEYCODE_N        0x36
#define KEYCODE_M        0x37
#define KEYCODE_LESS     0x38
#define KEYCODE_GREATER  0x39


#define TABLETA_Dummy        (TAG_USER + 0x3A000)
#define TABLETA_TabletZ      (TABLETA_Dummy + 1)
#define TABLETA_RangeZ       (TABLETA_Dummy + 2)
#define TABLETA_AngleX       (TABLETA_Dummy + 3)
#define TABLETA_AngleY       (TABLETA_Dummy + 4)
#define TABLETA_AngleZ       (TABLETA_Dummy + 5)
#define TABLETA_Pressure     (TABLETA_Dummy + 6)
#define TABLETA_ButtonBits   (TABLETA_Dummy + 7)
#define TABLETA_InProximity  (TABLETA_Dummy + 8)
#define TABLETA_ResolutionX  (TABLETA_Dummy + 9)
#define TABLETA_ResolutionY  (TABLETA_Dummy + 10)


struct TabletData
{
	UWORD           td_XFraction, td_YFraction;
	ULONG           td_TabletX, td_TabletY;
	ULONG           td_RangeX, td_RangeY;

	struct TagItem *td_TagList;
};


struct TabletHookData
{
	struct Screen *thd_Screen;

	ULONG          thd_Width;
	ULONG          thd_Height;

	LONG           thd_ScreenChanged;
};


#pragma pack()

#ifndef INTUITION_IOBSOLETE_H
# include <intuition/iobsolete.h>
#endif

#endif /* INTUITION_INTUITION_H */
