#ifndef PREFS_GUI_H
#define PREFS_GUI_H

/*
**    $VER: gui.h 54.16 (22.08.2022)
**
**    File format for GUI preferences
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
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

#define ID_GUI MAKE_ID('G','U','I',' ')

typedef struct
{
    struct TextAttr Attr;
    TEXT            Name[82];
} FONTSPEC;

struct GUIPrefs
{
    LONG     gp_Reserved[4];                /* System reserved                        */
    UWORD    gp_Version;                    /* Version of the GUIPrefs structure      */
    ULONG    gp_GlobalFlags;                /* Global control flags                   */
    ULONG    gp_ScreenFlags;                /* Screen control flags                   */
    UBYTE    gp_STitlePos;                  /* Position of screen title               */
    UBYTE    gp_STitlebarHIncr;             /* Increment to screen titlebar height    */
    UWORD    gp_MenuType;                   /* PULLDOWN, POPUP or RELATIVE            */
    UWORD    gp_MenuStyle;                  /* SQUARE, ROUNDED...                     */
    ULONG    gp_MenuFlags;                  /* MENUSHADOW, MENUTRANSP...              */
    TEXT     gp_MenuBackfill[256];          /* Menu backfill picture path             */
    TEXT     gp_MenuStylePlugin[40];        /* Menu style plugin name                 */
    ULONG    gp_STitlebarGSize;             /* Size of screen titlebar gadgets        */
    UWORD    gp_SysISubStyles[32];          /* Sub-style indices for style plugins    */
    UWORD    gp_MenuSelectedItemFrame;      /* How to draw selected menu items        */
    UWORD    gp_ReqPosition;                /* Opening position of system requesters  */
    UBYTE    gp_LayoutSpacing[2];           /* RA layout spacing in virtual pixels    */
    UWORD    gp_GroupLabelPlace;            /* Position of layout group labels        */
    UWORD    gp_GroupLabelLook;             /* Appearance of layout group labels      */
    UWORD    gp_WindowRefresh;              /* Preferred refresh type for windows     */
    UWORD    gp_GroupLabelVAlign;           /* Vert. alignment of layout group labels */
    UWORD    gp_ListHierNodeStyle;          /* Style of hierarchical list nodes       */
    UWORD    gp_ListHierConnectType;        /* How to connect hierarchical list nodes */
    ULONG    gp_GaugeLook[2];               /* Look of level/progress gauges          */
    UWORD    gp_GadgetRedraw;               /* Options for gadget redraw              */
    UBYTE    gp_Reserved2[120];             /* System reserved                        */
    UWORD    gp_DRIPens[96];                /* DrawInfo pens                          */
    UBYTE    gp_EdgesContrast[16][2];       /* Contrast levels for edges              */
    UBYTE    gp_HalfCurve[16][2];           /* Gradient curves for intermediate pens  */
    UBYTE    gp_PropKnobHighlight[2];       /* Look of selected prop knob             */
    UWORD    gp_WindowPropLook;             /* Look of window border scrollers        */
    UBYTE    gp_FrameProperties[20];        /* Various properties for frameiclass     */
    TEXT     gp_FrameBackfill[2][256];      /* Frameiclass backfill picture paths     */
    UBYTE    gp_WindowFlags;                /* Window control flags                   */
    UBYTE    gp_WTitlePos;                  /* Position of window title               */
    UBYTE    gp_WTitlebarHIncr;             /* Increment to window titlebar height    */
    BYTE     gp_SizeSize[2];                /* Width and height of sizing gadget      */
    BYTE     gp_ArrowSize[2];               /* Width and height of arrow gadgets      */
    BYTE     gp_BorderSize[4];              /* Sizes of gadgetless window borders     */
    UWORD    gp_SizeBorder;                 /* Preferred position for sizing gadget   */
    UWORD    gp_SysIFrameType;              /* Type of frame for system images        */
    UBYTE    gp_PropBorder[2];              /* Do scrollers have a border?            */
    UWORD    gp_PropKnobHandle[2];          /* Type of border scroller knob handle    */
    UWORD    gp_PropKnobColor[2];           /* Color of scroller knobs                */
    UWORD    gp_PropBackground[2];          /* Type of background for prop gadgets    */
    UBYTE    gp_PropSpacing[2];             /* Spacing for scroller borders           */
    TEXT     gp_PropBackfill[8][256];       /* Prop gadgets backfill picture paths    */
    TEXT     gp_TBarBackfill[3][256];       /* Screen/window titlebar texture paths   */
    TEXT     gp_BorderBackfill[2][256];     /* Window borders texture paths           */
    UBYTE    gp_Reserved3[256];             /* System reserved                        */
    TEXT     gp_WBorderStylePlugin[40];     /* Window border style plugin name        */
    TEXT     gp_WGadgetStylePlugin[40];     /* Window gadget symbol style plugin name */
    TEXT     gp_WGFrameStylePlugin[40];     /* Window gadget frame style plugin name  */
    TEXT     gp_GadgetStylePlugin[4][40];   /* GT/RA gadget symbol style plugin names */
    TEXT     gp_DefaultStylePlugin[40];     /* Fallback style plugin name             */
    ULONG    gp_WTitlebarGSize;             /* Size of window titlebar gadgets        */
    UWORD    gp_SFrameThickness;            /* Screen titlebar frame thickness        */
    UWORD    gp_WFrameThickness[2];         /* Window titlebar/border frame thickness */
    UWORD    gp_WindowBorderLook;           /* Window border outline look             */
    UWORD    gp_PropOuterSpacing;           /* Spacing around scrollers (in windows)  */
    UWORD    gp_SliderDisplayMode;          /* Where to display slider levels         */
    UWORD    gp_CycleLabelJustify;          /* Justification of cycle/chooser labels  */
    ULONG    gp_ClickTabLook;               /* Flags affecting clicktab look          */
    UBYTE    gp_FramePadding[2];            /* Horizontal/vertical gadget padding     */
    UWORD    gp_WFlatFrameThickness[2];     /* Window outer/inner flat thickness      */
    ULONG    gp_CycleLook;                  /* Flags affecting cycle/chooser look     */
    ULONG    gp_WindowFadeTime[8];          /* Fade time for window state transitions */
    TEXT     gp_FrameBackfill2[256];        /* Frameiclass backfill picture path (2)  */
    TEXT     gp_WGadgetGeometryPlugin[40];  /* Window gadget geometry plugin name     */
    TEXT     gp_GadgetGeometryPlugin[40];   /* GT/RA gadget geometry plugin name      */
    TEXT     gp_DefaultGeometryPlugin[40];  /* Fallback geometry plugin name          */
    TEXT     gp_BitmapSet[256];             /* Bitmap set path                        */
    UWORD    gp_OffScreenResistance;        /* Resistance of screen edges             */
    UBYTE    gp_MenuTranspLevel;            /* Level of menu transparency             */
    UBYTE    gp_Reserved4[5];               /* System reserved                        */
    TEXT     gp_WindowBackfill[256];        /* Window backfill picture path           */
    TEXT     gp_RequesterBackfill[256];     /* Requester backfill picture path        */
    GRADSPEC gp_GradientSpecs[30];          /* Various gradient specifications        */
    UBYTE    gp_WindowAlpha[8];             /* Alpha levels for various window types  */
    BYTE     gp_WindowShadowSizes[4];       /* Sizes of window drop shadows           */
    UBYTE    gp_WindowShadowStrength[8];    /* Intensity of window drop shadows       */
    UWORD    gp_WindowShadowType;           /* Type of built-in window drop shadow    */
    ULONG    gp_WindowShadowColor;          /* Color of window drop shadows           */
    BYTE     gp_WindowShadowDispl[4];       /* Window drop shadows X/Y displacement   */
    UWORD    gp_WindowShadowSmoothness;     /* Smoothness of window drop shadows      */
    UWORD    gp_STitlebarShadowDispl;       /* Screen bar drop shadow Y displacement  */
    UWORD    gp_STitlebarShadowStrength;    /* Intensity of screen bar drop shadow    */
    ULONG    gp_STitlebarShadowColor;       /* Color of screen bar drop shadow        */
    UWORD    gp_STitlebarShadowSmoothness;  /* Smoothness of screen bar drop shadow   */
    ULONG    gp_MenuOpenDelay;              /* Delay of (sub-)menu panel opening      */
    ULONG    gp_MenuCloseDelay;             /* Delay of (sub-)menu panel closing      */
    UBYTE    gp_Reserved5[102];             /* System reserved                        */
    FONTSPEC gp_GadgetFont;                 /* Font for RA gadgets                    */
    FONTSPEC gp_LabelFont;                  /* Font for RA labels (outside gadgets)   */
    FONTSPEC gp_GroupLabelFont;             /* Font for RA layout group title labels  */
    FONTSPEC gp_FallbackFont;               /* Fallback (small) font for RA GUIs      */
};


/* Current GUIPrefs structure version */
#define GUIPREFS_VERSION (1)

/* Flags for GUIPrefs.gp_ScreenFlags */
#define GF_SCREENAUTOCONTRAST   0x00000004  /* Automatic edges contrast */
#define GF_SCREENOFFSDRAGGING   0x00000020  /* Off-screen window dragging */
#define GF_SCREENREALBMSHADING  0x00000040  /* Realistic bitmap shading */
#define GF_SCREENOFFSSIZING     0x00000080  /* Off-screen window sizing */
#define GF_SCREENSPECIALEFFECTS 0x00000100  /* Fancy special effects */
#define GF_SCREENSHARECOMPOSEBM 0x00000200  /* Share compose bitmap */
#define GF_SCREENNOVSYNCCOMPOSE 0x00000400  /* No vert. sync for composing */

/* Flags for GUIPrefs.gp_WindowFlags */
#define GF_WINDOWEVENREQBUTTONS 0x00000001  /* Even-sized requester buttons */

/* Values for GUIPrefs.gp_MenuType */
#define GUI_MENUTYPE_PULLDOWN 0  /* Always pulldown (default) */
#define GUI_MENUTYPE_POPUP    1  /* Always pop-up */
#define GUI_MENUTYPE_RELATIVE 2  /* Pulldown or pop-up depending on position */

/* Flags for GUIPrefs.gp_MenuFlags */
#define GF_MENUTRANSP   0x00000001  /* Menus have transparency */
#define GF_MENUSHADOW   0x00000002  /* Menus have drop shadows */
#define GF_MENUALTERN   0x00000010  /* Alternative look (rounded corners) */
#define GF_MENUXEN      0x00000020  /* XEN style for menu edges */
#define GF_MENUFLAT     0x00000040  /* Never use embossed effects */
#define GF_MENUTRACK    0x00000100  /* Remember last selections */
#define GF_MENUSTICKYPD 0x00000200  /* Use sticky pulldown menu panels */
#define GF_MENUSTICKYPU 0x00000400  /* Use sticky pop-up menu panels */
#define GF_MENUCMCORNER 0x00000800  /* Alt. position for context menu panels */
#define GF_MENUNBPD     0x00001000  /* Use non-blocking pulldown menu panels */
#define GF_MENUNBPU     0x00002000  /* Use non-blocking pop-up menu panels */
#define GF_MENUPDTOPDEL 0x00010000  /* Use open delay with pulldown titles */
#define GF_MENUPDTCLDEL 0x00020000  /* Use close delay with pulldown titles */

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

#endif /* PREFS_GUI_H */
