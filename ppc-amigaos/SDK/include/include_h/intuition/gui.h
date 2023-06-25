#ifndef INTUITION_GUI_H
#define INTUITION_GUI_H
/*
**    $VER: gui.h 54.16 (22.08.2022)
**
**    GUI preferences definitions and attributes
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

/********************** GUI element base types ***********************/
/*                                                                   */
/*  Some Intuition rendering functions require specification of the  */
/*  type of GUI element they are going to operate on. The following  */
/*  is a list of the currently known GUI elements, which may grow    */
/*  with future Intuition releases.                                  */
/*                                                                   */
/*  Note: the BT_DRIPEN type can be ORed with a DrawInfo pen index   */
/*  to explicitly indicate a particular base (background) color on   */
/*  which the rendering will occur, not tied to a specific element.  */
/*                                                                   */
/*  Similarly, other base types might in the future accept modifier  */
/*  flags in the low word.                                           */
/*                                                                   */
/*********************************************************************/

#define BT_BACKGROUND  0x00000000  /* Generic background */
#define BT_DRIPEN      0x00100000  /* A base DrawInfo pen */
#define BT_WINBORDER   0x00200000  /* Window border */
#define BT_GADGET      0x00300000  /* Generic gadget */
#define BT_PROPKNOB    0x00400000  /* Proportional gadget knob */
#define BT_PROPBG      0x00500000  /* Proportional gadget background */
#define BT_WINPROPKNOB 0x00600000  /* Prop. gadget knob in window border */
#define BT_WINPROPBG   0x00700000  /* Prop. gadget backgr. in window border */
#define BT_MENU        0x00800000  /* Menu panel background */
#define BT_SCREENBAR   0x00900000  /* Screen titlebar */
#define BT_WINDOWBAR   0x00A00000  /* Window titlebar */
#define BT_WINDOWBG    0x00B00000  /* Window background */
#define BT_REQUESTERBG 0x00C00000  /* Requester background */
#define BT_TABPAGE     0x00D00000  /* Tab page background */

#define BT_FLAGSMASK   0x000F0000  /* Flags valid for ALL base types */
#define BT_OFFSETRECT  0x00010000  /* Left, top contain backfill offsets */
#define BT_DIRECTSHADE 0x00020000  /* Flag for ShadeRectA(), see autodoc */


/************************** Shading levels ***************************/
/*                                                                   */
/*  Many Intuition GUI elements feature "bright" and "dark" details  */
/*  in order to achieve a pseudo-3D embossed look. The following is  */
/*  a list of the currently supported levels of shading for the 3D   */
/*  GUI elements. Some Intuition rendering functions accept one of   */
/*  these shading levels as a parameter, allowing you to perform     */
/*  custom 3D effects in a way consistent with the Intuition look.   */
/*                                                                   */
/*********************************************************************/

#define LEVEL_BRIGHT     0  /* Full-intensity bright details */
#define LEVEL_HALFBRIGHT 1  /* Half-intensity bright details */
#define LEVEL_NORMAL     2  /* Normal imagery                */
#define LEVEL_HALFDARK   3  /* Half-intensity dark details   */
#define LEVEL_DARK       4  /* Full-intensity dark details   */


/********************* Contrast levels and flags *********************/
/*                                                                   */
/*  Some Intuition rendering functions require specification of a    */
/*  contrast level, which determines how much any brighter/darker    */
/*  graphic details stand out from the background imagery.           */
/*  The contrast levels are 8-bit values, but they can be ORed with  */
/*  any of the following modifier flags.                             */
/*                                                                   */
/*  Note: the CNTR_CORRECT flag can be used to adapt the contrast    */
/*  of full-intensity bright details according to the actual color   */
/*  they are derived from. This does usually yield better optical    */
/*  results. This flag is ignored for dark details contrast, and it  */
/*  is also ignored if the CNTR_ABSOLUTE flag is specified.          */
/*                                                                   */
/*********************************************************************/

#define STD_DISABLE_CONTRAST (0x1000)  /* For disabled imagery */

#define CNTR_CORRECT  0x0100  /* Correct contrast of bright details */
#define CNTR_ABSOLUTE 0x0200  /* Absolute (non-percentage) shading  */


/************************* ShadeRectA() tags *************************/
/*                                                                   */
/*  These are the tags recognized by the ShadeRectA() function.      */
/*                                                                   */
/*********************************************************************/

#define SRA_Dummy       (0x03800000)

#define SRA_OffsetX     (SRA_Dummy + 1)
   /* (WORD) Logical rendering offset on the X axis. */

#define SRA_OffsetY     (SRA_Dummy + 2)
   /* (WORD) Logical rendering offset on the Y axis. */

#define SRA_DeltaX      (SRA_Dummy + 3)
   /* (WORD) Delta increment for SRA_OffsetX. */

#define SRA_DeltaY      (SRA_Dummy + 4)
   /* (WORD) Delta increment for SRA_OffsetY. */

#define SRA_Domain      (SRA_Dummy + 5)
   /* (struct Rectangle *) Logical rendering container. */

#define SRA_DirectShade (SRA_Dummy + 6)
   /* (BOOL) Force on-the-fly shading */

#define SRA_RefreshBG   (SRA_Dummy + 7)
   /* (BOOL) Redraw background first to avoid overshading */


/**************** DisableTemplate() data types (V51) *****************/
/*                                                                   */
/*  These are the template types accepted by the DisableTemplate()   */
/*  function. The first one is a planar mask, the others are chunky  */
/*  alpha blending maps (arrays).                                    */
/*  Note: if an alpha map has a modulo > 1 (more than one byte per   */
/*  pixel, e.g. ARGB) it MUST be aligned to the first 'alpha' byte!  */
/*                                                                   */
/*********************************************************************/

#define TT_BITPLANE 0  /* Template is a 16-bit-aligned bitplane */
#define TT_ALPHA8   1  /* Template is an alpha map (modulo = 1) */
#define TT_ALPHA16  2  /* Template is an alpha map (modulo = 2) */
#define TT_ALPHA24  3  /* Template is an alpha map (modulo = 3) */
#define TT_ALPHA32  4  /* Template is an alpha map (modulo = 4) */


/************************** GUI attributes ***************************/
/*                                                                   */
/*  These attributes are not intended for direct usage by software   */
/*  applications. They should only be used by the system or by       */
/*  system-level components and add-ons like preferences editors,    */
/*  GUI style plugins, rendering hooks, BOOPSI classes and the like. */
/*  Also, other than for the system itself, the attributes listed    */
/*  here should be considered READ-ONLY.                             */
/*                                                                   */
/*  Applications should honor user preferences for their GUI. They   */
/*  can allow users to select and save local GUI preferences for     */
/*  specific screen(s) by using the standard GUI editor provided by  */
/*  the system. In particular, applications should NEVER override    */
/*  GUI settings at global level -- only IPrefs is allowed to do so. */
/*                                                                   */
/*  If you think you have a good reason to access GUI attributes:    */
/*                                                                   */
/*  The applicability flags fields indicate how an attribute can be  */
/*  used with windows, with screens and globally (in this order).    */
/*  GUI attributes can be applied by using SetGUIAttrsA(), and read  */
/*  with GetGUIAttrsA(). For screens and windows, they can also be   */
/*  passed at creation time.                                         */
/*                                                                   */
/*  Note: the window-level attributes can't actually be set at       */
/*  window level yet, but rather just at screen level; this will be  */
/*  changed in a future Intuition release. Check the applicability   */
/*  flags to learn if and when they can be set at window level.      */
/*                                                                   */
/*********************************************************************/

#define GUIA_Dummy                (TAG_USER + 0x4400000)

/********* Window-, screen- and global-level GUI attributes **********/

#define GUIA_DefaultStyle         (GUIA_Dummy + 1)
   /* (APTR) Default style plugin, may be overridden (G/IG/SG). */

#define GUIA_WindowBorderStyle    (GUIA_Dummy + 2)
   /* (APTR) Style plugin to be used to render window borders (G/G/G). */

#define GUIA_WindowGadgetStyle    (GUIA_Dummy + 3)
   /* (APTR) Style plugin to be used to render border gadgets (G/G/G). */

#define GUIA_SizeGadgetWidth      (GUIA_Dummy + 4)
   /* (BYTE) Width of window sizing gadget; -1 = automatic (G/IG/SG). */

#define GUIA_SizeGadgetHeight     (GUIA_Dummy + 5)
   /* (BYTE) Height of window sizing gadget; -1 = automatic (G/IG/SG). */

#define GUIA_ArrowGadgetWidth     (GUIA_Dummy + 6)
   /* (BYTE) Width of border arrow gadgets; -1 = automatic (G/IG/SG). */

#define GUIA_ArrowGadgetHeight    (GUIA_Dummy + 7)
   /* (BYTE) Height of border arrow gadgets; -1 = automatic (G/IG/SG). */

#define GUIA_WindowBorderLeft     (GUIA_Dummy + 8)
   /* (BYTE) Thickness of left window border, without gadgets (G/IG/SG). */

#define GUIA_WindowBorderTop      (GUIA_Dummy + 9)
   /* (BYTE) Thickness of top window border, without gadgets (G/IG/SG). */

#define GUIA_WindowBorderRight    (GUIA_Dummy + 10)
   /* (BYTE) Thickness of right window border, without gadgets (G/IG/SG). */

#define GUIA_WindowBorderBottom   (GUIA_Dummy + 11)
   /* (BYTE) Thickness of bottom window border, without gadgets (G/IG/SG). */

#define GUIA_WindowTitlePosition  (GUIA_Dummy + 12)
   /* (UBYTE) Position of titles in window titlebars (G/IG/SG). */

#define GUIA_WindowBarPadding     (GUIA_Dummy + 13)
   /* (UBYTE) Added to the font height to set titlebar height (G/IG/SG). */

#define GUIA_WindowReserved       (GUIA_Dummy + 14)
   /* (BOOL) Reserved for now, don't use. */

#define GUIA_WindowPropKnobHandle (GUIA_Dummy + 15)
   /* (UWORD) Type of handle for window border scroller knobs (G/ISG/SG). */

#define GUIA_WindowPropKnobColor  (GUIA_Dummy + 16)
   /* (BOOL) Do border scroller knobs use window border color? (G/ISG/SG). */

#define GUIA_WindowPropBackground (GUIA_Dummy + 17)
   /* (UWORD) Type of background for window border scrollers (G/ISG/SG). */

#define GUIA_PropBackground       (GUIA_Dummy + 18)
   /* (UWORD) Type of background for proportional gadgets (G/ISG/SG). */

#define GUIA_WindowPropKnobBackfill (GUIA_Dummy + 19)
   /* (struct Hook *) Backfill hook for border scroller knobs (G/ISG/SG). */

#define GUIA_PropKnobBackfill     (GUIA_Dummy + 20)
   /* (struct Hook *) Backfill hook for prop gadget knobs (G/ISG/SG). */

#define GUIA_WindowPropSelKnobBackfill (GUIA_Dummy + 21)
   /* (struct Hook *) Backfill hook for selected border knobs (G/ISG/SG). */

#define GUIA_PropSelKnobBackfill  (GUIA_Dummy + 22)
   /* (struct Hook *) Backfill hook for selected prop knobs (G/ISG/SG). */

#define GUIA_WindowPropInactKnobBackfill (GUIA_Dummy + 23)
   /* (struct Hook *) Backfill hook for inactive border knobs (G/ISG/SG). */

#define GUIA_WindowPropBackfill   (GUIA_Dummy + 24)
   /* (struct Hook *) Backfill hook for border scrollers (G/ISG/SG). */

#define GUIA_WindowPropInactBackfill (GUIA_Dummy + 25)
   /* (struct Hook *) Backfill hook for inactive border scrollers
      (G/ISG/SG). */

#define GUIA_PropBackfill         (GUIA_Dummy + 26)
   /* (struct Hook *) Backfill hook for proportional gadgets (G/ISG/SG). */

#define GUIA_SysImageFrameType    (GUIA_Dummy + 27)
   /* (UWORD) Type of frame for screen and window system gadgets (G/IG/SG). */

#define GUIA_WindowPropBorder     (GUIA_Dummy + 28)
   /* (BOOL) Do window border scrollers have a double border? (G/ISG/SG). */

#define GUIA_PropBorder           (GUIA_Dummy + 29)
   /* (BOOL) Do GT/RA scrollers have a double border? (G/ISG/SG). */

#define GUIA_WindowPropSpacing    (GUIA_Dummy + 30)
   /* (UBYTE) Thickness of window scrollers borders (G/ISG/SG). */

#define GUIA_PropSpacing          (GUIA_Dummy + 31)
   /* (UBYTE) Thickness of GT/RA scrollers borders (G/ISG/SG). */

#define GUIA_PropKnobHandle       (GUIA_Dummy + 32)
   /* (UWORD) Type of handle for scroller knobs (G/ISG/SG). */

#define GUIA_PropKnobColor        (GUIA_Dummy + 33)
   /* (BOOL) Do scroller knobs use FILLPEN as their color? (G/ISG/SG). */

#define GUIA_WindowSizeBorder     (GUIA_Dummy + 34)
   /* (UWORD) Preferred border(s) to place the sizing gadget in (G/IG/SG). */

#define GUIA_WindowGadgetFrameStyle (GUIA_Dummy + 35)
   /* (APTR) Style plugin to be used to render border gadget frames (G/G/G). */

#define GUIA_GadgetStyle          (GUIA_Dummy + 36)
   /* (APTR) Style plugin to be used to render GT/RA gadgets (G/G/G). */

#define GUIA_DefaultGeometry      (GUIA_Dummy + 37)
   /* (APTR) Style plugin defining geometry of GUI elements (G/IG/SG). */

#define GUIA_WindowGadgetGeometry (GUIA_Dummy + 38)
   /* (APTR) Style plugin defining geometry of border gadgets (G/G/G). */

#define GUIA_GadgetGeometry       (GUIA_Dummy + 39)
   /* (APTR) Style plugin defining geometry of GT/RA gadgets (G/G/G). */

#define GUIA_ScreenBarGadgetSize  (GUIA_Dummy + 40)
   /* (APTR) Size of gadgets in the screen titlebar (G/IG/SG). */

#define GUIA_WindowBarGadgetSize  (GUIA_Dummy + 41)
   /* (APTR) Size of gadgets in the window titlebar (G/ISG/SG). */

#define GUIA_GadgetArrowType      (GUIA_Dummy + 42)
   /* (ULONG) Type of arrow symbols to be used in arrow buttons (G/IG/SG). */

#define GUIA_GadgetCycleType      (GUIA_Dummy + 43)
   /* (ULONG) Type of cycle symbol to be used in cycle gadgets (G/IG/SG). */

#define GUIA_GadgetArrowStyle     (GUIA_Dummy + 44)
   /* (APTR) Style plugin to be used to render GT/RA arrow buttons (G/G/G). */

#define GUIA_GadgetCycleStyle     (GUIA_Dummy + 45)
   /* (APTR) Style plugin to be used to render GT/RA cycle gadgets (G/G/G). */

#define GUIA_SysImageSymbolType   (GUIA_Dummy + 46)
   /* (UWORD) Type of symbols for screen and window system gadgets
      (G/IG/SG). */

#define GUIA_SysIGeometryType     (GUIA_Dummy + 47)
   /* (UWORD) Type of geometry for screen and window system gadgets
      (G/IG/SG). */

#define GUIA_WindowBarBackfill    (GUIA_Dummy + 48)
   /* (struct Hook *) Backfill hook for active window titlebars (G/ISG/SG). */

#define GUIA_WindowBarInactBackfill (GUIA_Dummy + 49)
   /* (struct Hook *) Backfill hook for inactive window titlebars
      (G/ISG/SG). */

#define GUIA_WindowBorderBackfill (GUIA_Dummy + 50)
   /* (struct Hook *) Backfill hook for active window borders (G/ISG/SG). */

#define GUIA_WindowBorderInactBackfill (GUIA_Dummy + 51)
   /* (struct Hook *) Backfill hook for inactive window borders (G/ISG/SG). */

#define GUIA_WindowPropLook       (GUIA_Dummy + 52)
   /* (BOOL) Use the GUIA_FramePropLook also for border scrollers?
      (G/ISG/SG). */

#define GUIA_EvenRequesterButtons (GUIA_Dummy + 53)
   /* (BOOL) Make all buttons of system requesters equally wide? (G/ISG/SG). */

#define GUIA_RequestersPosition   (GUIA_Dummy + 54)
   /* (UWORD) Opening position of system requesters (G/ISG/SG). */

#define GUIA_WindowBorderLook     (GUIA_Dummy + 55)
   /* (UWORD) Type of window border (3D, framed, flat...) (G/ISG/SG). */

#define GUIA_Reserved1            (GUIA_Dummy + 56)
#define GUIA_Reserved2            (GUIA_Dummy + 57)
#define GUIA_Reserved3            (GUIA_Dummy + 58)
   /* (APTR) System reserved attributes, don't use. */

#define GUIA_WindowBarFrameThickness (GUIA_Dummy + 59)
   /* (UWORD) Thickness of 3D edges of window titlebar frames (1 or 2)
      (G/ISG/SG). */

#define GUIA_WindowFrameThickness (GUIA_Dummy + 60)
   /* (UWORD) Thickness of 3D edges of window frames (1 or 2) (G/ISG/SG). */

#define GUIA_PropOuterSpacing     (GUIA_Dummy + 61)
   /* (UWORD) Make scrollers detached from lists and/or buttons? (G/ISG/SG). */

#define GUIA_SliderDisplayMode    (GUIA_Dummy + 62)
   /* (UWORD) Preferred position of slider level display (G/ISG/SG). */

#define GUIA_CycleLabelJustify    (GUIA_Dummy + 63)
   /* (UWORD) Justification of cycle/chooser labels (G/ISG/SG). */

#define GUIA_ClickTabLook         (GUIA_Dummy + 64)
   /* (ULONG) Various flags affecting the look of clicktabs (G/ISG/SG). */

#define GUIA_GadgetHorizPadding   (GUIA_Dummy + 65)
#define GUIA_GadgetVertPadding    (GUIA_Dummy + 66)
   /* (UWORD) Horizontal and vertical padding for ReAction gadgets
      (G/ISG/SG). */

#define GUIA_WindowBackfill       (GUIA_Dummy + 67)
   /* (struct Hook *) Backfill hook for window background (G/ISG/SG). */

#define GUIA_RequesterBackfill    (GUIA_Dummy + 68)
   /* (struct Hook *) Backfill hook for requester background (G/ISG/SG). */

#define GUIA_TabTitleBackfill     (GUIA_Dummy + 69)
   /* (struct Hook *) Backfill hook for active tab header (G/ISG/SG). */

#define GUIA_TabActiveBackfill    (GUIA_Dummy + 70)
   /* (struct Hook *) Backfill hook for active tab page (G/ISG/SG). */

#define GUIA_TabInactiveBackfill  (GUIA_Dummy + 71)
   /* (struct Hook *) Backfill hook for inactive tabs (G/ISG/SG). */

#define GUIA_LayoutHorizSpacing   (GUIA_Dummy + 72)
#define GUIA_LayoutVertSpacing    (GUIA_Dummy + 73)
   /* (UWORD) Horizontal and vertical spacing in ReAction layouts
      (G/ISG/SG). */

#define GUIA_GroupLabelPlace      (GUIA_Dummy + 74)
   /* (ULONG) Position of group labels (left/center/right) (G/ISG/SG). */

#define GUIA_GroupLabelLook       (GUIA_Dummy + 75)
   /* (ULONG) Appearance of group labels (plain, 3D, bold...) (G/ISG/SG). */

#define GUIA_GroupLabelTextAttr   (GUIA_Dummy + 76)
   /* (struct TextAttr *) Font specification for group labels (G/ISG/SG). */

#define GUIA_FallbackTextAttr     (GUIA_Dummy + 77)
   /* (struct TextAttr *) Font specification for fallback layout (G/ISG/SG). */

#define GUIA_GadgetTextAttr       (GUIA_Dummy + 78)
   /* (struct TextAttr *) Font specification for RA gadgets (G/ISG/SG). */

#define GUIA_LabelTextAttr        (GUIA_Dummy + 79)
   /* (struct TextAttr *) Font specification for RA labels (G/ISG/SG). */

#define GUIA_WindowRefresh        (GUIA_Dummy + 80)
   /* (ULONG) Preferred window refresh type (1 = simple, 0 = smart)
      (G/ISG/SG). */

#define GUIA_GroupLabelVertAlign  (GUIA_Dummy + 81)
   /* (ULONG) Vertical alignment of group labels (center, baseline...)
      (G/ISG/SG). */

#define GUIA_ListHierNodeStyle    (GUIA_Dummy + 82)
   /* (UWORD) Style of hierarchical list nodes (+/- boxes, arrows)
      (G/ISG/SG). */

#define GUIA_ListHierConnectType  (GUIA_Dummy + 83)
   /* (UWORD) How to connect hierarchical list nodes (lines, nothing)
      (G/ISG/SG). */

#define GUIA_Reserved4            (GUIA_Dummy + 84)
   /* (APTR) System reserved attribute, don't use. */

#define GUIA_WindowOuterFlatThickness (GUIA_Dummy + 85)
   /* (UWORD) Thickness of outer flat borders for framed/flat window look
      (1 or 2) (G/ISG/SG). */

#define GUIA_WindowInnerFlatThickness (GUIA_Dummy + 86)
   /* (UWORD) Thickness of inner flat borders for framed/flat window look
      (1 or 2) (G/ISG/SG). */

#define GUIA_CycleLook            (GUIA_Dummy + 87)
   /* (ULONG) Various flags affecting the look of cycle/chooser gadgets
      (G/ISG/SG). */

#define GUIA_WindowGaugeLook      (GUIA_Dummy + 88)
   /* (ULONG) Various flags affecting the look of window fill gauge gadgets
      (G/ISG/SG). */

#define GUIA_GaugeLook            (GUIA_Dummy + 89)
   /* (ULONG) Various flags affecting the look of fill gauge gadgets
      (G/ISG/SG). */

#define GUIA_ClearBackground      (GUIA_Dummy + 90)
   /* (BOOL) Always erase background before redrawing GUI elements?
      (G/ISG/SG). */

#define GUIA_Reserved5            (GUIA_Dummy + 91)
   /* (APTR) System reserved attribute, don't use. */

#define GUIA_WindowAlpha          (GUIA_Dummy + 92)
   /* (UBYTE) Opaqueness of a normal window (G/ISG/SG). */

#define GUIA_WindowInactAlpha     (GUIA_Dummy + 93)
   /* (UBYTE) Opaqueness of an inactive window (G/ISG/SG). */

#define GUIA_WindowDragAlpha      (GUIA_Dummy + 94)
   /* (UBYTE) Opaqueness of a dragged window (G/ISG/SG). */

#define GUIA_WindowOpenFadeTime   (GUIA_Dummy + 95)
   /* (ULONG) Duration of window fade-in at open time (G/ISG/SG). */

#define GUIA_WindowCloseFadeTime  (GUIA_Dummy + 96)
   /* (ULONG) Duration of window fade-out at close time (G/ISG/SG). */

#define GUIA_WindowGoActiveFadeTime (GUIA_Dummy + 97)
   /* (ULONG) Duration of window fade when going active (G/ISG/SG). */

#define GUIA_WindowGoInactiveFadeTime (GUIA_Dummy + 98)
   /* (ULONG) Duration of window fade when going inactive (G/ISG/SG). */

#define GUIA_FrameAlphaStatus     (GUIA_Dummy + 99)
   /* (ULONG) Potential transparency of various frame types (G/G/G). */

#define GUIA_WindowShadowSizes    (GUIA_Dummy + 100)
   /* (ULONG) Sizes of drop shadows on the four window sides; this
      is four signed bytes packed as a single longword (G/G/G). */

#define GUIA_WindowShadowStrength (GUIA_Dummy + 101)
   /* (ULONG) Intensity of drop shadows for various window types (0..255);
      this is four unsigned bytes packed as a single longword (G/ISG/SG). */

#define GUIA_WindowShadowType     (GUIA_Dummy + 102)
   /* (ULONG) Type of built-in window drop shadow (G/ISG/SG). */

#define GUIA_WindowShadowColor    (GUIA_Dummy + 103)
   /* (ULONG) Color of window drop shadows in 00R8G8B8 form (G/ISG/SG). */

#define GUIA_WindowShadowDisplacement (GUIA_Dummy + 104)
   /* (ULONG) X/Y displacement of drop shadows relative to the window;
      this is four signed bytes packed as a single longword, two bytes
      for the active window and two for inactive windows (G/ISG/SG). */

#define GUIA_WindowShadowSmoothness (GUIA_Dummy + 105)
   /* (UWORD) Smoothness level of window drop shadows (0..20) (G/ISG/SG). */

/************** Screen- and global-level GUI attributes **************/

#define GUIA_ScreenTitlePosition  (GUIA_Dummy + 1001)
   /* (UBYTE) Position of titles in screen titlebars (G/IG/SG). */

#define GUIA_ScreenBarPadding     (GUIA_Dummy + 1002)
   /* (UBYTE) Added to the font height to set titlebar height (G/IG/SG). */

#define GUIA_MenuType             (GUIA_Dummy + 1003)
   /* (UWORD) Type of menu: MT_PULLDOWN, MT_POPUP or MT_RELATIVE (G/ISG/SG). */

#define GUIA_MenuFlags            (GUIA_Dummy + 1004)
   /* (ULONG) Menu flags (see definitions below) (G/ISG/SG). */

#define GUIA_MenuDropShadows      (GUIA_Dummy + 1005)
   /* (BOOL) Do menus cast drop shadows? (G/ISG/SG). */

#define GUIA_MenuTransparency     (GUIA_Dummy + 1006)
   /* (BOOL) Do menus have transparency? (G/ISG/SG). */

#define GUIA_MenuRenderHook       (GUIA_Dummy + 1007)
   /* (struct Hook *) Rendering hook for menus (G/ISG/SG). */

#define GUIA_MenuBackfill         (GUIA_Dummy + 1008)
   /* (struct Hook *) Backfill hook for menus (G/ISG/SG). */

#define GUIA_MenuStyle            (GUIA_Dummy + 1009)
   /* (APTR) Style plugin to import menu rendering hook from (G/ISG/SG). */

#define GUIA_BrightContrast       (GUIA_Dummy + 1010)
#define GUIA_DarkContrast         (GUIA_Dummy + 1011)
   /* (UBYTE) Default contrast for edges brightening/darkening (G/IG/SG). */

#define GUIA_FillBrightContrast   (GUIA_Dummy + 1012)
#define GUIA_FillDarkContrast     (GUIA_Dummy + 1013)
   /* (UBYTE) Contrast of FILLSHINEPEN/FILLSHADOWPEN (G/IG/SG). */

#define GUIA_InactiveFillBrightContrast (GUIA_Dummy + 1014)
#define GUIA_InactiveFillDarkContrast   (GUIA_Dummy + 1015)
   /* (UBYTE) Contrast of INACTIVEFILLSHINEPEN/INACTIVEFILLSHADOWPEN
      (G/IG/SG). */

#define GUIA_MenuBrightContrast   (GUIA_Dummy + 1016)
#define GUIA_MenuDarkContrast     (GUIA_Dummy + 1017)
   /* (UBYTE) Contrast of MENUSHINEPEN/MENUSHADOWPEN (G/IG/SG). */

#define GUIA_SelectBrightContrast (GUIA_Dummy + 1018)
#define GUIA_SelectDarkContrast   (GUIA_Dummy + 1019)
   /* (UBYTE) Contrast of SELECTSHINEPEN/SELECTSHADOWPEN (G/IG/SG). */

#define GUIA_BarBlockBrightContrast (GUIA_Dummy + 1020)
#define GUIA_BarBlockDarkContrast   (GUIA_Dummy + 1021)
   /* (UBYTE) Contrast of BARCONTOURPEN/BARTRIMPEN (G/IG/SG). */

#define GUIA_DisabledBrightContrast (GUIA_Dummy + 1022)
#define GUIA_DisabledDarkContrast   (GUIA_Dummy + 1023)
   /* (UBYTE) Contrast of DISABLEDSHINEPEN/DISABLEDSHADOWPEN (G/IG/SG). */

#define GUIA_ForeBrightContrast     (GUIA_Dummy + 1024)
#define GUIA_ForeDarkContrast       (GUIA_Dummy + 1025)
   /* (UBYTE) Contrast of FORESHINEPEN/FORESHADOWPEN (G/IG/SG). */

#define GUIA_AutomaticEdgesContrast (GUIA_Dummy + 1026)
   /* (BOOL) Enable/disable automatic computation of shine/shadow pens
      (G/IG/SG). */

#define GUIA_BrightCurve          (GUIA_Dummy + 1028)
#define GUIA_DarkCurve            (GUIA_Dummy + 1029)
   /* (UBYTE) Default curve for shine/shadow colors gradients (G/IG/SG). */

#define GUIA_FillBrightCurve      (GUIA_Dummy + 1030)
#define GUIA_FillDarkCurve        (GUIA_Dummy + 1031)
   /* (UBYTE) Curve for FILLSHINEPEN/FILLSHADOWPEN gradients (G/IG/SG). */

#define GUIA_InactiveFillBrightCurve (GUIA_Dummy + 1032)
#define GUIA_InactiveFillDarkCurve   (GUIA_Dummy + 1033)
   /* (UBYTE) Curve for INACTIVEFILLSHINEPEN/INACTIVEFILLSHADOWPEN gradients
      (G/IG/SG). */

#define GUIA_MenuBrightCurve      (GUIA_Dummy + 1034)
#define GUIA_MenuDarkCurve        (GUIA_Dummy + 1035)
   /* (UBYTE) Curve for MENUSHINEPEN/MENUSHADOWPEN gradients (G/IG/SG). */

#define GUIA_SelectBrightCurve    (GUIA_Dummy + 1036)
#define GUIA_SelectDarkCurve      (GUIA_Dummy + 1037)
   /* (UBYTE) Curve for SELECTSHINEPEN/SELECTSHADOWPEN gradients (G/IG/SG). */

#define GUIA_BarBlockBrightCurve  (GUIA_Dummy + 1038)
#define GUIA_BarBlockDarkCurve    (GUIA_Dummy + 1039)
   /* (UBYTE) Curve for BARCONTOURPEN/BARTRIMPEN gradients (G/IG/SG). */

#define GUIA_DisabledBrightCurve  (GUIA_Dummy + 1040)
#define GUIA_DisabledDarkCurve    (GUIA_Dummy + 1041)
   /* (UBYTE) Curve for DISABLEDSHINEPEN/DISABLEDSHADOWPEN gradients
      (G/IG/SG). */

#define GUIA_ForeBrightCurve      (GUIA_Dummy + 1042)
#define GUIA_ForeDarkCurve        (GUIA_Dummy + 1043)
   /* (UBYTE) Curve for FORESHINEPEN/FORESHADOWPEN gradients (G/IG/SG). */

#define GUIA_PropKnobHighlight    (GUIA_Dummy + 1044)
   /* (UBYTE) Selected knob look: 0 = raised, 1 = recessed (G/ISG/SG). */

#define GUIA_PaletteRGBTable      (GUIA_Dummy + 1045)
   /* (UBYTE *) Initial 256-color palette for the screens (G/IG/SG). */

#define GUIA_PaletteLockTable     (GUIA_Dummy + 1046)
   /* (UBYTE *) Array of locking information for each palette entry
      (G/IG/SG). */

#define GUIA_DRIPens              (GUIA_Dummy + 1047)
   /* (UWORD *) Array of DrawInfo pens for the screen (G/IG/SG). */

#define GUIA_FrameForceThinEdges  (GUIA_Dummy + 1048)
   /* (UBYTE) Flag mask, see definitions below (G/ISG/SG). */

#define GUIA_FrameSelectedColor   (GUIA_Dummy + 1049)
   /* (UBYTE) Fill pen for selected buttons, see values below (G/ISG/SG). */

#define GUIA_FrameDisabledColors  (GUIA_Dummy + 1050)
   /* (UBYTE) Pens for disabled frame edges, see values below (G/ISG/SG). */

#define GUIA_FrameButtonLook      (GUIA_Dummy + 1051)
   /* (UBYTE) Look of button frames, see values below (G/ISG/SG). */

#define GUIA_FramePressedLook     (GUIA_Dummy + 1052)
   /* (UBYTE) Look of pressed (selected) buttons, see values below
      (G/ISG/SG). */

#define GUIA_FrameCornersType     (GUIA_Dummy + 1053)
   /* (UBYTE) Type of frame corners (0 = square, 1 = rounded) (G/ISG/SG). */

#define GUIA_FrameBackfill        (GUIA_Dummy + 1054)
   /* (struct Hook *) Backfill hook for unselected frames (G/ISG/SG). */

#define GUIA_FrameSelBackfill     (GUIA_Dummy + 1055)
   /* (struct Hook *) Backfill hook for selected frames (G/ISG/SG). */

#define GUIA_FrameStringLook      (GUIA_Dummy + 1056)
   /* (UBYTE) Look of string gadget frames, see values below (G/ISG/SG). */

#define GUIA_FramePropLook        (GUIA_Dummy + 1057)
   /* (UBYTE) Look of prop gadget frames, see values below (G/ISG/SG). */

#define GUIA_FrameDisplayLook     (GUIA_Dummy + 1058)
   /* (UBYTE) Look of display gadget frames, see values below (G/ISG/SG). */

#define GUIA_WindowPropKnobHighlight (GUIA_Dummy + 1059)
   /* (UBYTE) Selected window knob look: 0 = raised, 1 = recessed
      (G/ISG/SG). */

#define GUIA_OffScreenDragging    (GUIA_Dummy + 1060)
   /* (BOOL) Is off-screen window dragging allowed on this screen?
      (G/ISG/SG). */

#define GUIA_FrameDisBackfill     (GUIA_Dummy + 1061)
   /* (struct Hook *) Backfill hook for disabled frames (G/ISG/SG). */

#define GUIA_RealShading          (GUIA_Dummy + 1062)
   /* (BOOL) Realistic bitmap shading on hicolor/truecolor screens?
      (G/ISG/SG). */

#define GUIA_ScreenBarBackfill    (GUIA_Dummy + 1063)
   /* (struct Hook *) Backfill hook for screen titlebars (G/ISG/SG). */

#define GUIA_MenuSelItemFrame     (GUIA_Dummy + 1064)
   /* (UBYTE) Type of frame for selected menu items (G/ISG/SG). */

#define GUIA_OffScreenSizing      (GUIA_Dummy + 1065)
   /* (BOOL) Is off-screen window sizing allowed on this screen? (G/ISG/SG). */

#define GUIA_OffScreenResistance  (GUIA_Dummy + 1066)
   /* (UWORD) Amount of resistance screen edges offer to window crossing
      them (G/ISG/SG). */

#define GUIA_MenuTransparencyLevel (GUIA_Dummy + 1067)
   /* (UBYTE) Level of menu transparency (if transparency is turned on)
      (G/ISG/SG). */

#define GUIA_SpecialEffects       (GUIA_Dummy + 1068)
   /* (BOOL) Enable fancy compositing-based special effects? (G/ISG/SG). */

#define GUIA_ShareComposeBitMap   (GUIA_Dummy + 1069)
   /* (BOOL) Try to save video memory by sharing temporary off-screen bitmap
      for layer composition among different screens? (G/ISG/SG). */

#define GUIA_ScreenBarShadowStrength (GUIA_Dummy + 1070)
   /* (UWORD) Intensity of screen titlebar drop shadow (0..255) (G/ISG/SG). */

#define GUIA_ScreenBarShadowColor (GUIA_Dummy + 1071)
   /* (ULONG) Color of screen titlebar drop shadow in 00R8G8B8 form
      (G/ISG/SG). */

#define GUIA_ScreenBarShadowDisplacement (GUIA_Dummy + 1072)
   /* (UWORD) Vertical displacement of drop shadow relative to the screen
      titlebar (G/ISG/SG). */

#define GUIA_ScreenBarShadowSmoothness (GUIA_Dummy + 1073)
   /* (UWORD) Smoothness level of screen titlebar drop shadow (0..20)
      (G/ISG/SG). */

#define GUIA_MenuOpenDelay        (GUIA_Dummy + 1074)
   /* (UWORD) Duration of panel open delay for menus and items (0..8).
      Packed as two bytes in a word, low byte for menus and high byte
      for items (G/ISG/SG). */

#define GUIA_MenuCloseDelay       (GUIA_Dummy + 1075)
   /* (UWORD) Duration of panel close delay for menus and items (0..8).
      Packed as two bytes in a word, low byte for menus and high byte
      for items (G/ISG/SG). */

#define GUIA_VSyncCompose         (GUIA_Dummy + 1076)
   /* (BOOL) Synchronize display updates of layer composition with
      vertical refresh rate of monitor when possible? (G/ISG/SG). */

/*********************** Global GUI attributes ***********************/

#define GUIA_GlobalFlags          (GUIA_Dummy + 5001)
   /* (ULONG) Global GUI flags (see definitions below) (G/G/SG). */

#define GUIA_ScreenDragging       (GUIA_Dummy + 5002)
   /* (BOOL) Enable/disable screen dragging (defaults to TRUE) (G/G/SG). */

#define GUIA_DefaultDRIPens       (GUIA_Dummy + 5003)
   /* (UWORD *) Default four-color DrawInfo pen array (G/G/G). */


/* Global GUI flags */

#define GGPF_SCREENDRAGGING 0x00000001  /* Enable screen dragging */

/* Values for GUIA_WindowBorderLook */

#define FRAMEWINDOW_3D     0  /* Standard 3D bevelled frame */
#define FRAMEWINDOW_FRAMED 1  /* Dark frame with 3D inner frame */
#define FRAMEWINDOW_FLAT   2  /* Thin or thick dark frame */

/* Flags for GUIA_FrameForceThinEdges */

#define FRAMETHIN_FILLEDRAISED      0x01
#define FRAMETHIN_FILLEDRECESSED    0x02
#define FRAMETHIN_EDGESONLYRAISED   0x04
#define FRAMETHIN_EDGESONLYRECESSED 0x08

/* Values for GUIA_FrameSelectedColor */

#define FRAMESELCOL_FILL   0  /* Fill pen */
#define FRAMESELCOL_SELECT 1  /* Select pen */
#define FRAMESELCOL_FOREG  2  /* Foreground pen */
#define FRAMESELCOL_BACKG  3  /* Background pen */

/* Values for GUIA_FrameDisabledColors */

#define FRAMEDISCOL_FOREG 0  /* Foreground shine/shadow pens */
#define FRAMEDISCOL_BACKG 1  /* Background shine/shadow pens */
#define FRAMEDISCOL_DISAB 2  /* Disabled shine/shadow pens */

/* Values for GUIA_FrameButtonLook */

#define FRAMEBUTTON_3D     0  /* Standard 3D bevelled frame */
#define FRAMEBUTTON_FRAMED 1  /* Dark frame with 3D inner frame */
#define FRAMEBUTTON_FLAT   2  /* Thin or thick dark frame */

/* Values for GUIA_FrameStringLook */

#define FRAMESTRING_3D      0  /* Standard 3D ridge */
#define FRAMESTRING_FRAMED  1  /* Dark frame with inner recessed frame */
#define FRAMESTRING_FLAT    2  /* Thin or thick dark frame */
#define FRAMESTRING_FRAMED2 3  /* Recessed frame with inner dark frame */

/* Values for GUIA_FramePropLook */

#define FRAMEPROP_3D     0  /* Standard 3D bevelled frame */
#define FRAMEPROP_FRAMED 1  /* Dark frame */
#define FRAMEPROP_FLAT   2  /* Thin or thick dark frame */
#define FRAMEPROP_NONE   3  /* No frame (only applies to container) */

/* Values for GUIA_FrameDisplayLook */

#define FRAMEDISPLAY_3D      0  /* Standard 3D recessed frame */
#define FRAMEDISPLAY_FRAMED  1  /* Dark frame with inner recessed frame */
#define FRAMEDISPLAY_FLAT    2  /* Thin or thick dark frame */
#define FRAMEDISPLAY_FRAMED2 3  /* Recessed frame with inner dark frame */

/* Values for GUIA_FramePressedLook */

#define FRAMEPRESSED_PUSHED   0  /* Pushed in */
#define FRAMEPRESSED_INVERTED 1  /* Inverted edges colors */

/* Values for GUIA_ClickTabLook */

#define CLICKTAB_ACTIVEBOLD       0x00000001
#define CLICKTAB_EVENWIDTH        0x00000002
#define CLICKTAB_INACTIVEDARK     0x00000004
#define CLICKTAB_ACTIVEFILLGRAD   0x00000008
#define CLICKTAB_ACTIVEPENMASK    0x000000F0
#define CLICKTAB_ACTIVEPENTEXT    0x00000000
#define CLICKTAB_ACTIVEPENHLTEXT  0x00000010
#define CLICKTAB_ACTIVEPENTITLE   0x00000020
#define CLICKTAB_ACTIVEFILLMASK   0x00000F00
#define CLICKTAB_ACTIVEFILLFILL   0x00000000
#define CLICKTAB_ACTIVEFILLSHINE  0x00000100
#define CLICKTAB_ACTIVEFILLSELECT 0x00000200
#define CLICKTAB_ACTIVEFILLNONE   0x00000F00
#define CLICKTAB_ACTIVEBRIGHT     0x00001000

/* Values for GUIA_GaugeLook and GUIA_WindowGaugeLook */

#define GAUGE_FILL_STYLEMASK  0x00000007
#define GAUGE_FILL_BORDERLESS 0x00000000
#define GAUGE_FILL_3D         0x00000001
#define GAUGE_FILL_FRAMED     0x00000002
#define GAUGE_FILL_FLAT       0x00000003
#define GAUGE_FILL_AUTOSTYLE  0x00000007
#define GAUGE_FILL_GRADIENT   0x00000010
#define GAUGE_CONT_STYLEMASK  0x00000700
#define GAUGE_CONT_BORDERLESS 0x00000000
#define GAUGE_CONT_3D         0x00000100
#define GAUGE_CONT_FRAMED     0x00000200
#define GAUGE_CONT_FLAT       0x00000300
#define GAUGE_CONT_FRAMED2    0x00000400
#define GAUGE_CONT_AUTOSTYLE  0x00000700
#define GAUGE_CONT_GRADIENT   0x00001000
#define GAUGE_SPACINGMASK     0x00030000
#define GAUGE_INNERTICKS      0x00040000
#define GAUGE_UNUSED          0x00080000
#define GAUGE_BORDERPENS      0x00100000
#define GAUGE_RESERVED        0x80000000

/* Special value for GUIA_PaletteRGBTable */

#define PALETTERGB_IGNORE (~0L)

/* Special value for GUIA_PaletteLockTable */

#define PALETTELOCK_IGNORE (~0L)

/* Special value for GUIA_DRIPens */

#define DRIPENS_IGNORE (~0L)

/* Window title positions */

#define WTPOS_LEFT      0  /* Left side (default) */
#define WTPOS_CENTERREL 1  /* Centered in dragbar */
#define WTPOS_CENTERABS 2  /* Centered in whole titlebar */

/* Menu types */

#define MT_PULLDOWN 0  /* Always pulldown (default) */
#define MT_POPUP    1  /* Always pop-up */
#define MT_RELATIVE 2  /* Pulldown or pop-up depending on position */

/* Menu flags */

#define MENUTRANSP   0x00000001  /* Menus have transparency */
#define MENUSHADOW   0x00000002  /* Menus have drop shadows */
#define MENUALTERN   0x00000010  /* Alternative look (rounded corners) */
#define MENUFRAMED   0x00000020  /* Framed style for menu edges */
#define MENUFLAT     0x00000040  /* Never use embossed effects */
#define MENUTRACK    0x00000100  /* Remember last selections */
#define MENUSTICKYPD 0x00000200  /* Use sticky pulldown menu panels */
#define MENUSTICKYPU 0x00000400  /* Use sticky pop-up menu panels */
#define MENUCMCORNER 0x00000800  /* Alt. position for context menu panels */
#define MENUNBPD     0x00001000  /* Use non-blocking pulldown menu panels */
#define MENUNBPU     0x00002000  /* Use non-blocking pop-up menu panels */
#define MENUPDTOPDEL 0x00010000  /* Use open delay with pulldown titles */
#define MENUPDTCLDEL 0x00020000  /* Use close delay with pulldown titles */

/****************************************************************************/

/* Obsolete definitions, here only for compatibility, don't use in new code */

#define FRAMEBUTTON_XEN   FRAMEBUTTON_FRAMED
#define FRAMESTRING_XEN   FRAMESTRING_FRAMED
#define FRAMESTRING_MIXED FRAMESTRING_FRAMED2
#define FRAMEPROP_XEN     FRAMEPROP_FRAMED
#define FRAMEDISPLAY_XEN  FRAMEDISPLAY_FRAMED
#define MENUXEN           MENUFRAMED

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

#endif /*  INTUITION_GUI_H */
