#ifndef INTUITION_IOBSOLETE_H
#define INTUITION_IOBSOLETE_H

/*
	intuition obsolete definitions

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef DEVICES_TIMER_H
# include <devices/timer.h>
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

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)

#ifndef INTUI_V50_NOOBSOLETE

/* cghooks.h */

struct GadgetInfo
{
	struct Screen    *gi_Screen;
	struct Window    *gi_Window;
	struct Requester *gi_Requester;

	struct RastPort  *gi_RastPort;
	struct Layer     *gi_Layer;

	struct IBox       gi_Domain;

	struct
	{
		UBYTE DetailPen;
		UBYTE BlockPen;
	}                 gi_Pens;

	struct DrawInfo  *gi_DrInfo;

	ULONG             gi_Reserved[6];
};

struct PGX
{
	struct IBox pgx_Container;
	struct IBox pgx_NewKnob;
};

#define CUSTOM_HOOK(gadget)  ((struct Hook *)(gadget)->MutualExclude)

/* sghooks.h */

struct StringExtend
{
	struct TextFont *Font;
	UBYTE            Pens[2];
	UBYTE            ActivePens[2];

	ULONG            InitialModes;
	struct Hook     *EditHook;
	UBYTE           *WorkBuffer;

	ULONG            Reserved[4];
};

struct SGWork
{
	struct Gadget     *Gadget;
	struct StringInfo *StringInfo;
	UBYTE             *WorkBuffer;
	UBYTE             *PrevBuffer;
	ULONG              Modes;

	struct InputEvent *IEvent;
	UWORD              Code;
	WORD               BufferPos;
	WORD               NumChars;
	ULONG              Actions;
	LONG               LongInt;

	struct GadgetInfo *GadgetInfo;
	UWORD              EditOp;
};


#define EO_NOOP         (0x0001)
#define EO_DELBACKWARD  (0x0002)
#define EO_DELFORWARD   (0x0003)
#define EO_MOVECURSOR   (0x0004)
#define EO_ENTER        (0x0005)
#define EO_RESET        (0x0006)
#define EO_REPLACECHAR  (0x0007)
#define EO_INSERTCHAR   (0x0008)
#define EO_BADFORMAT    (0x0009)
#define EO_BIGCHANGE    (0x000A)
#define EO_UNDO         (0x000B)
#define EO_CLEAR        (0x000C)
#define EO_SPECIAL      (0x000D)


#define SGM_REPLACE     (1<<0)
#define SGM_FIXEDFIELD  (1<<1)
#define SGM_NOFILTER    (1<<2)
#define SGM_NOCHANGE    (1<<3)
#define SGM_NOWORKB     (1<<4)
#define SGM_CONTROL     (1<<5)
#define SGM_LONGINT     (1<<6)
#define SGM_EXITHELP    (1<<7)


#define SGA_USE         (0x1)
#define SGA_END         (0x2)
#define SGA_BEEP        (0x4)
#define SGA_REUSE       (0x8)
#define SGA_REDISPLAY   (0x10)

#define SGA_NEXTACTIVE  (0x20)
#define SGA_PREVACTIVE  (0x40)


#define SGH_KEY    (1L)
#define SGH_CLICK  (2L)


/* preferences.h */


#define FILENAME_SIZE  30
#define DEVNAME_SIZE   16
#define POINTERSIZE    ((1 + 16 + 1) * 2)

#define TOPAZ_EIGHTY  8
#define TOPAZ_SIXTY   9


struct Preferences
{
	BYTE           FontHeight;

	UBYTE          PrinterPort;

	UWORD          BaudRate;

	struct timeval KeyRptSpeed;
	struct timeval KeyRptDelay;
	struct timeval DoubleClick;

	UWORD          PointerMatrix[POINTERSIZE];
	BYTE           XOffset;
	BYTE           YOffset;
	UWORD          color17;
	UWORD          color18;
	UWORD          color19;
	UWORD          PointerTicks;

	UWORD          color0;
	UWORD          color1;
	UWORD          color2;
	UWORD          color3;

	BYTE           ViewXOffset;
	BYTE           ViewYOffset;
	WORD           ViewInitX, ViewInitY;

	BOOL           EnableCLI;

	UWORD          PrinterType;
	UBYTE          PrinterFilename[FILENAME_SIZE];

	UWORD          PrintPitch;
	UWORD          PrintQuality;
	UWORD          PrintSpacing;
	UWORD          PrintLeftMargin;
	UWORD          PrintRightMargin;
	UWORD          PrintImage;
	UWORD          PrintAspect;
	UWORD          PrintShade;
	WORD           PrintThreshold;

	UWORD          PaperSize;
	UWORD          PaperLength;
	UWORD          PaperType;

	UBYTE          SerRWBits;
	UBYTE          SerStopBuf;
	UBYTE          SerParShk;
	UBYTE          LaceWB;

	UBYTE          Pad[12];
	UBYTE          PrtDevName[DEVNAME_SIZE];
	UBYTE          DefaultPrtUnit;
	UBYTE          DefaultSerUnit;

	BYTE           RowSizeChange;
	BYTE           ColumnSizeChange;

	UWORD          PrintFlags;
	UWORD          PrintMaxWidth;
	UWORD          PrintMaxHeight;
	UBYTE          PrintDensity;
	UBYTE          PrintXOffset;

	UWORD          wb_Width;
	UWORD          wb_Height;
	UBYTE          wb_Depth;

	UBYTE          ext_size;
};


#define LACEWB       (1<<0)
#define LW_RESERVED  1

#define SCREEN_DRAG  (1<<14)
#define MOUSE_ACCEL  (1<<15)


#define PARALLEL_PRINTER  0x00
#define SERIAL_PRINTER    0x01


#define BAUD_110    0x00
#define BAUD_300    0x01
#define BAUD_1200   0x02
#define BAUD_2400   0x03
#define BAUD_4800   0x04
#define BAUD_9600   0x05
#define BAUD_19200  0x06
#define BAUD_MIDI   0x07


#define FANFOLD  0x00
#define SINGLE   0x80


#define PICA   0x000
#define ELITE  0x400
#define FINE   0x800


#define DRAFT   0x000
#define LETTER  0x100


#define SIX_LPI    0x000
#define EIGHT_LPI  0x200


#define IMAGE_POSITIVE  0x00
#define IMAGE_NEGATIVE  0x01


#define ASPECT_HORIZ  0x00
#define ASPECT_VERT   0x01


#define SHADE_BW         0x00
#define SHADE_GREYSCALE  0x01
#define SHADE_COLOR      0x02


#define US_LETTER  0x00
#define US_LEGAL   0x10
#define N_TRACTOR  0x20
#define W_TRACTOR  0x30
#define CUSTOM     0x40


#define EURO_A0  0x50
#define EURO_A1  0x60
#define EURO_A2  0x70
#define EURO_A3  0x80
#define EURO_A4  0x90
#define EURO_A5  0xA0
#define EURO_A6  0xB0
#define EURO_A7  0xC0
#define EURO_A8  0xD0


#define CUSTOM_NAME       0x00
#define ALPHA_P_101       0x01
#define BROTHER_15XL      0x02
#define CBM_MPS1000       0x03
#define DIAB_630          0x04
#define DIAB_ADV_D25      0x05
#define DIAB_C_150        0x06
#define EPSON             0x07
#define EPSON_JX_80       0x08
#define OKIMATE_20        0x09
#define QUME_LP_20        0x0A
#define HP_LASERJET       0x0B
#define HP_LASERJET_PLUS  0x0C


#define SBUF_512    0x00
#define SBUF_1024   0x01
#define SBUF_2048   0x02
#define SBUF_4096   0x03
#define SBUF_8000   0x04
#define SBUF_16000  0x05


#define SREAD_BITS     0xF0
#define SWRITE_BITS    0x0F

#define SSTOP_BITS     0xF0
#define SBUFSIZE_BITS  0x0F

#define SPARITY_BITS   0xF0
#define SHSHAKE_BITS   0x0F


#define SPARITY_NONE   0
#define SPARITY_EVEN   1
#define SPARITY_ODD    2
#define SPARITY_MARK   3
#define SPARITY_SPACE  4


#define SHSHAKE_XON   0
#define SHSHAKE_RTS   1
#define SHSHAKE_NONE  2


#define CORRECT_RED          0x0001
#define CORRECT_GREEN        0x0002
#define CORRECT_BLUE         0x0004

#define CENTER_IMAGE         0x0008

#define IGNORE_DIMENSIONS    0x0000
#define BOUNDED_DIMENSIONS   0x0010
#define ABSOLUTE_DIMENSIONS  0x0020
#define PIXEL_DIMENSIONS     0x0040
#define MULTIPLY_DIMENSIONS  0x0080

#define INTEGER_SCALING      0x0100

#define ORDERED_DITHERING    0x0000
#define HALFTONE_DITHERING   0x0200
#define FLOYD_DITHERING      0x0400

#define ANTI_ALIAS           0x0800
#define GREY_SCALE2          0x1000


#define CORRECT_RGB_MASK     (CORRECT_RED|CORRECT_GREEN|CORRECT_BLUE)
#define DIMENSIONS_MASK      (BOUNDED_DIMENSIONS|ABSOLUTE_DIMENSIONS|PIXEL_DIMENSIONS|MULTIPLY_DIMENSIONS)
#define DITHERING_MASK       (HALFTONE_DITHERING|FLOYD_DITHERING)


/* screens.h */

/* use diattrs.h instead */
#define DRI_VERSION  (3)

struct DrawInfo
{
	UWORD            dri_Version;
	UWORD            dri_NumPens;
	UWORD           *dri_Pens;

	struct TextFont *dri_Font;
	UWORD            dri_Depth;

	struct
	{
		UWORD X;
		UWORD Y;
	}                dri_Resolution;

	ULONG            dri_Flags;
	struct Image    *dri_CheckMark;
	struct Image    *dri_AmigaKey;
	ULONG            dri_Reserved[5];
};

#define DRIF_NEWLOOK  0x00000001

#define DETAILPEN         (0x0000)
#define BLOCKPEN          (0x0001)
#define TEXTPEN           (0x0002)
#define SHINEPEN          (0x0003)
#define SHADOWPEN         (0x0004)
#define FILLPEN           (0x0005)
#define FILLTEXTPEN       (0x0006)
#define BACKGROUNDPEN     (0x0007)
#define HIGHLIGHTTEXTPEN  (0x0008)
#define BARDETAILPEN      (0x0009)
#define BARBLOCKPEN       (0x000A)
#define BARTRIMPEN        (0x000B)
#define HALFSHINEPEN      (0x000C)
#define HALFSHADOWPEN     (0x000D)

#define NUMDRIPENS        (0x000E)

#define PEN_C3  0xFEFC
#define PEN_C2  0xFEFD
#define PEN_C1  0xFEFE
#define PEN_C0  0xFEFF

struct Screen
{
	struct Screen     *NextScreen;
	struct Window     *FirstWindow;

	WORD               LeftEdge, TopEdge;
	WORD               Width, Height;

	WORD               MouseY, MouseX;

	UWORD              Flags;

	/* pointers to the title and default screen title, this fields shouldn't generaly be accessed at all.
	** to modify the screen title for your window use SetWindowTitles()

	** IMPORTANT: the string you pass is NOT cached in any way, you must NOT modify it while it's being
	** used as screen/window title! */
	UBYTE             *Title;
	UBYTE             *DefaultTitle;

	/* OBSOLETE fields used to describe window border sizes and other ui components.
	** please use GetSkinInfoAttr instead to get real values instead of computing them
	** yourself! */
	BYTE               BarHeight, BarVBorder, BarHBorder, MenuVBorder, MenuHBorder;
	BYTE               WBorTop, WBorLeft, WBorRight, WBorBottom;

	struct TextAttr   *Font;
	struct ViewPort    ViewPort;
	struct RastPort    RastPort;

	/* OBSOLETE, always use screen->RastPort.BitMap */
	struct BitMap      BitMap;

	struct Layer_Info  LayerInfo;
	struct Gadget     *FirstGadget;

	/* OBSOLETE field, use the drawinfo API */
	UBYTE              DetailPen, BlockPen;

	/* OBSOLETE private field */
	UWORD              SaveColor0;

	struct Layer      *BarLayer;

	UBYTE             *ExtData;
	UBYTE             *UserData;
};

#define SHOWTITLE     0x0010 /* OBSOLETE flag, set with SA_ShowTitle, change with ShowTitle(), may not always be respected */
#define BEEPING       0x0020 /* OBSOLETE flag */
#define CUSTOMBITMAP  0x0040 /* OBSOLETE flag, set with SA_Bitmap, set if you supplied own bitmap */
#define SCREENHIRES   0x0200 /* OBSOLETE flag */
#define NS_EXTENDED   0x1000 /* OBSOLETE flag, always use OpenScreenTagList(NULL,tags) instead of OpenScreen() */

#ifndef NSTAG_EXT_VPMODE
# define NSTAG_EXT_VPMODE  (TAG_USER | 1)
#endif

#define OSCAN_TEXT      (1)
#define OSCAN_STANDARD  (2)
#define OSCAN_MAX       (3)
#define OSCAN_VIDEO     (4)

#define SDEPTH_INFAMILY   (2) /* LEGACY STUFF. DO NOT USE */
#define SDEPTH_CHILDONLY  SDEPTH_INFAMILY

/* use OpenScreenTagList(NULL, tags)! */

struct NewScreen
{
	WORD             LeftEdge, TopEdge, Width, Height, Depth;

	UBYTE            DetailPen, BlockPen;
	UWORD            ViewModes;
	UWORD            Type;

	struct TextAttr *Font;
	UBYTE           *DefaultTitle;

	struct Gadget   *Gadgets;
	struct BitMap   *CustomBitMap;
};

struct ExtNewScreen
{
	WORD             LeftEdge, TopEdge, Width, Height, Depth;
	UBYTE            DetailPen, BlockPen;
	UWORD            ViewModes;
	UWORD            Type;
	struct TextAttr *Font;
	UBYTE           *DefaultTitle;
	struct Gadget   *Gadgets;
	struct BitMap   *CustomBitMap;

	struct TagItem  *Extension;
};

#endif

#ifndef INTUI_V36_NAMES_ONLY

#define GADGHIGHBITS  GFLG_GADGHIGHBITS
#define GADGHCOMP     GFLG_GADGHCOMP
#define GADGHBOX      GFLG_GADGHBOX
#define GADGHIMAGE    GFLG_GADGHIMAGE
#define GADGHNONE     GFLG_GADGHNONE
#define GADGIMAGE     GFLG_GADGIMAGE
#define GRELBOTTOM    GFLG_RELBOTTOM
#define GRELRIGHT     GFLG_RELRIGHT
#define GRELWIDTH     GFLG_RELWIDTH
#define GRELHEIGHT    GFLG_RELHEIGHT
#define SELECTED      GFLG_SELECTED
#define GADGDISABLED  GFLG_DISABLED
#define LABELMASK     GFLG_LABELMASK
#define LABELITEXT    GFLG_LABELITEXT
#define LABELSTRING   GFLG_LABELSTRING
#define LABELIMAGE    GFLG_LABELIMAGE


#define RELVERIFY      GACT_RELVERIFY
#define GADGIMMEDIATE  GACT_IMMEDIATE
#define ENDGADGET      GACT_ENDGADGET
#define FOLLOWMOUSE    GACT_FOLLOWMOUSE
#define RIGHTBORDER    GACT_RIGHTBORDER
#define LEFTBORDER     GACT_LEFTBORDER
#define TOPBORDER      GACT_TOPBORDER
#define BOTTOMBORDER   GACT_BOTTOMBORDER
#define BORDERSNIFF    GACT_BORDERSNIFF
#define TOGGLESELECT   GACT_TOGGLESELECT
#define BOOLEXTEND     GACT_BOOLEXTEND
#define STRINGLEFT     GACT_STRINGLEFT
#define STRINGCENTER   GACT_STRINGCENTER
#define STRINGRIGHT    GACT_STRINGRIGHT
#define LONGINT        GACT_LONGINT
#define ALTKEYMAP      GACT_ALTKEYMAP
#define STRINGEXTEND   GACT_STRINGEXTEND
#define ACTIVEGADGET   GACT_ACTIVEGADGET


#define GADGETTYPE    GTYP_GADGETTYPE
#define SYSGADGET     GTYP_SYSGADGET
#define SCRGADGET     GTYP_SCRGADGET
#define GZZGADGET     GTYP_GZZGADGET
#define REQGADGET     GTYP_REQGADGET
#define SIZING        GTYP_SIZING
#define WDRAGGING     GTYP_WDRAGGING
#define SDRAGGING     GTYP_SDRAGGING
#define WUPFRONT      GTYP_WUPFRONT
#define SUPFRONT      GTYP_SUPFRONT
#define WDOWNBACK     GTYP_WDOWNBACK
#define SDOWNBACK     GTYP_SDOWNBACK
#define CLOSE         GTYP_CLOSE
#define BOOLGADGET    GTYP_BOOLGADGET
#define GADGET0002    GTYP_GADGET0002
#define PROPGADGET    GTYP_PROPGADGET
#define STRGADGET     GTYP_STRGADGET
#define CUSTOMGADGET  GTYP_CUSTOMGADGET
#define GTYPEMASK     GTYP_GTYPEMASK


#define SIZEVERIFY      IDCMP_SIZEVERIFY
#define NEWSIZE         IDCMP_NEWSIZE
#define REFRESHWINDOW   IDCMP_REFRESHWINDOW
#define MOUSEBUTTONS    IDCMP_MOUSEBUTTONS
#define MOUSEMOVE       IDCMP_MOUSEMOVE
#define GADGETDOWN      IDCMP_GADGETDOWN
#define GADGETUP        IDCMP_GADGETUP
#define REQSET          IDCMP_REQSET
#define MENUPICK        IDCMP_MENUPICK
#define CLOSEWINDOW     IDCMP_CLOSEWINDOW
#define RAWKEY          IDCMP_RAWKEY
#define REQVERIFY       IDCMP_REQVERIFY
#define REQCLEAR        IDCMP_REQCLEAR
#define MENUVERIFY      IDCMP_MENUVERIFY
#define NEWPREFS        IDCMP_NEWPREFS
#define DISKINSERTED    IDCMP_DISKINSERTED
#define DISKREMOVED     IDCMP_DISKREMOVED
#define WBENCHMESSAGE   IDCMP_WBENCHMESSAGE
#define ACTIVEWINDOW    IDCMP_ACTIVEWINDOW
#define INACTIVEWINDOW  IDCMP_INACTIVEWINDOW
#define DELTAMOVE       IDCMP_DELTAMOVE
#define VANILLAKEY      IDCMP_VANILLAKEY
#define INTUITICKS      IDCMP_INTUITICKS
#define IDCMPUPDATE     IDCMP_IDCMPUPDATE
#define MENUHELP        IDCMP_MENUHELP
#define CHANGEWINDOW    IDCMP_CHANGEWINDOW
#define LONELYMESSAGE   IDCMP_LONELYMESSAGE


#define WINDOWSIZING    WFLG_SIZEGADGET
#define WINDOWDRAG      WFLG_DRAGBAR
#define WINDOWDEPTH     WFLG_DEPTHGADGET
#define WINDOWCLOSE     WFLG_CLOSEGADGET
#define SIZEBRIGHT      WFLG_SIZEBRIGHT
#define SIZEBBOTTOM     WFLG_SIZEBBOTTOM
#define REFRESHBITS     WFLG_REFRESHBITS
#define SMART_REFRESH   WFLG_SMART_REFRESH
#define SIMPLE_REFRESH  WFLG_SIMPLE_REFRESH
#define SUPER_BITMAP    WFLG_SUPER_BITMAP
#define OTHER_REFRESH   WFLG_OTHER_REFRESH
#define BACKDROP        WFLG_BACKDROP
#define REPORTMOUSE     WFLG_REPORTMOUSE
#define GIMMEZEROZERO   WFLG_GIMMEZEROZERO
#define BORDERLESS      WFLG_BORDERLESS
#define ACTIVATE        WFLG_ACTIVATE
#define WINDOWACTIVE    WFLG_WINDOWACTIVE
#define INREQUEST       WFLG_INREQUEST
#define MENUSTATE       WFLG_MENUSTATE
#define RMBTRAP         WFLG_RMBTRAP
#define NOCAREREFRESH   WFLG_NOCAREREFRESH
#define WINDOWREFRESH   WFLG_WINDOWREFRESH
#define WBENCHWINDOW    WFLG_WBENCHWINDOW
#define WINDOWTICKED    WFLG_WINDOWTICKED
#define NW_EXTENDED     WFLG_NW_EXTENDED
#define VISITOR         WFLG_VISITOR
#define ZOOMED          WFLG_ZOOMED
#define HASZOOM         WFLG_HASZOOM


#define GA_LEFT          GA_Left
#define GA_RELRIGHT      GA_RelRight
#define GA_TOP           GA_Top
#define GA_RELBOTTOM     GA_RelBottom
#define GA_WIDTH         GA_Width
#define GA_RELWIDTH      GA_RelWidth
#define GA_HEIGHT        GA_Height
#define GA_RELHEIGHT     GA_RelHeight
#define GA_TEXT          GA_Text
#define GA_IMAGE         GA_Image
#define GA_BORDER        GA_Border
#define GA_SELECTRENDER  GA_SelectRender
#define GA_HIGHLIGHT     GA_Highlight
#define GA_DISABLED      GA_Disabled
#define GA_GZZGADGET     GA_GZZGadget
#define GA_USERDATA      GA_UserData
#define GA_SPECIALINFO   GA_SpecialInfo
#define GA_SELECTED      GA_Selected
#define GA_ENDGADGET     GA_EndGadget
#define GA_IMMEDIATE     GA_Immediate
#define GA_RELVERIFY     GA_RelVerify
#define GA_FOLLOWMOUSE   GA_FollowMouse
#define GA_RIGHTBORDER   GA_RightBorder
#define GA_LEFTBORDER    GA_LeftBorder
#define GA_TOPBORDER     GA_TopBorder
#define GA_BOTTOMBORDER  GA_BottomBorder
#define GA_TOGGLESELECT  GA_ToggleSelect
#define GA_SYSGADGET     GA_SysGadget
#define GA_SYSGTYPE      GA_SysGType
#define GA_PREVIOUS      GA_Previous
#define GA_NEXT          GA_Next
#define GA_DRAWINFO      GA_DrawInfo
#define GA_INTUITEXT     GA_IntuiText
#define GA_LABELIMAGE    GA_LabelImage

#define PGA_FREEDOM     PGA_Freedom
#define PGA_BORDERLESS  PGA_Borderless
#define PGA_HORIZPOT    PGA_HorizPot
#define PGA_HORIZBODY   PGA_HorizBody
#define PGA_VERTPOT     PGA_VertPot
#define PGA_VERTBODY    PGA_VertBody
#define PGA_TOTAL       PGA_Total
#define PGA_VISIBLE     PGA_Visible
#define PGA_TOP         PGA_Top

#define LAYOUTA_LAYOUTOBJ    LAYOUTA_LayoutObj
#define LAYOUTA_SPACING      LAYOUTA_Spacing
#define LAYOUTA_ORIENTATION  LAYOUTA_Orientation


#define IMAGE_ATTRIBUTES  (IA_Dummy)
#define IA_LEFT           IA_Left
#define IA_TOP            IA_Top
#define IA_WIDTH          IA_Width
#define IA_HEIGHT         IA_Height
#define IA_FGPEN          IA_FGPen
#define IA_BGPEN          IA_BGPen
#define IA_DATA           IA_Data
#define IA_LINEWIDTH      IA_LineWidth
#define IA_PENS           IA_Pens
#define IA_RESOLUTION     IA_Resolution
#define IA_APATTERN       IA_APattern
#define IA_APATSIZE       IA_APatSize
#define IA_MODE           IA_Mode
#define IA_FONT           IA_Font
#define IA_OUTLINE        IA_Outline
#define IA_RECESSED       IA_Recessed
#define IA_DOUBLEEMBOSS   IA_DoubleEmboss
#define IA_EDGESONLY      IA_EdgesOnly
#define IA_SHADOWPEN      IA_ShadowPen
#define IA_HIGHLIGHTPEN   IA_HighlightPen


#define detailPen       DETAILPEN
#define blockPen        BLOCKPEN
#define textPen         TEXTPEN
#define shinePen        SHINEPEN
#define shadowPen       SHADOWPEN
#define hifillPen       FILLPEN
#define hifilltextPen   FILLTEXTPEN
#define backgroundPen   BACKGROUNDPEN
#define hilighttextPen  HIGHLIGHTTEXTPEN
#define numDrIPens      NUMDRIPENS

#endif /* !INTUI_V36_NAMES_ONLY */


#pragma pack()

#endif /* INTUITION_IOBSOLETE_H */
