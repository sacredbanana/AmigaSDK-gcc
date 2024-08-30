#ifndef INTUITION_SCREENS_H
#define INTUITION_SCREENS_H

/*
	intuition screen definitions

	Copyright (C) 2002-2008 The MorphOS Development Team, All Rights Reserved.
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

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


#ifdef INTUI_V50_NOOBSOLETE

/* As of intuition.library v50 the direct use of struct DrawInfo is considered
** obsolete. Please use the GetDrawInfoAttr() call described in diattr.h.
**
** The old v40 structure is still available in iobsolete.h and included by
** default. To get rid of obsolete structures and tags you should add following
** defines before including any of intuition includes:
**
** #define INTUI_V50_NOOBSOLETE
** #define INTUITION_IOBSOLETE_H and/or #define INTUI_V36_NAMES_ONLY
**
** As of intuition.library 50.75+ SA_DisplayID has been declared OBSOLETE!
** You should NEVER use it for preferences and store: monitor name, display
** width/height, screen width/height (if different than display w/h) and
** screen depth. This ensures the screen you open will match user's request
** even if the gfx cards or display modes are changed.
**
** The correct examples of a flexible OpenScreen():
**
** Open the screen on a default monitor:
**
** screen = OpenScreenTags(NULL,SA_Width,1024,
**                              SA_Height,768,
**                              SA_Depth,24,
**                              TAG_DONE);
**
** Open the screen on a requested monitor:
**
** screen = OpenScreenTags(NULL,SA_Width,1024,
**                              SA_Height,768,
**                              SA_Depth,24,
**                              SA_MonitorName,"Radeon9000.monitor",
**                              TAG_DONE);
**
** NOTE: if Radeon9000.monitor is not found intuition will try to open
** the screen on other monitors from Radeon family and if that is not
** possible on the default monitor (or any other matching the requirements).
**
** Open an autoscrolling screen with size 2000x2000 and a 1024x768 display mode:
**
** screen = OpenScreenTags(NULL,SA_Width,2000,
**                              SA_Height,2000,
**                              SA_DisplayWidth,1024,
**                              SA_DisplayHeight,768,
**                              SA_Depth,24,
**                              SA_AutoScroll,TRUE,
**                              TAG_DONE);
**
** See the notes in SA_MonitorName, SA_DisplayWidth, SA_DisplayID for more info.
*/

struct DrawInfo;
struct NewScreen;
struct ExtNewScreen;

/* Screen structure is used to describe intuition screens. All fields are READ ONLY and can
** only be modified with intuition's screen functions.
**
** Starting with 50.53 you should use the Set/GetAttr BOOPSI interface to query/set
** screen params. Reading from struct Screen is still allowed though.
**
** NOTE: the old structure is still included in iobsolete.h
*/

struct Screen
{
	/* pointer to the next screen, can only be accessed between LockIBase()/UnlockIBase() */
	struct Screen     *NextScreen;

	/* pointer to the first opened window on screen, can only be accessed between LockIBase()/UnlockIBase() */
	struct Window     *FirstWindow;

	/* used for screen movement if the width/height is greater that display width/height,
	can be modified with MoveScreen() function */
	WORD               LeftEdge, TopEdge;

	/* dimensions of the screen */
	WORD               Width, Height;

	/* mouse position on screen */
	WORD               MouseY, MouseX;

	/* one of the flags defined below */
	UWORD              Flags;

	/* pointers to the title and default screen title, this fields shouldn't generaly be accessed at all.
	** to modify the screen title for your window use SetWindowTitles()
	** IMPORTANT: the string you pass is NOT cached in any way, you must NOT modify it while it's being
	** used as screen/window title! */
	UBYTE             *Title;
	UBYTE             *DefaultTitle;

	/* BarHeight can still be read if you need to know the actual size of the bar, even if it's not
	** visible due to user configuration. Remember to add 1 to get real height */
	BYTE               BarHeight;
	BYTE               Obsolete1[4];
	BYTE               Obsolete2[4];

	/* default font for this screen */
	struct TextAttr   *Font;

	/* structure used to describe screen's display mode & state, should not be accessed */
	struct ViewPort    ViewPort;

	/* main RastPort structure of the screen, should never be used unless the screen is a custom
	** screen with no windows on it. */
	struct RastPort    RastPort;

	/* OBSOLETE, always use screen->RastPort.BitMap */
	struct BitMap      Obsolete3;

	/* main layer structure of the screen, should only be used for layer lock calls */
	struct Layer_Info  LayerInfo;

	/* pointer to the first gadget attached to the screen, a private field */
	struct Gadget     *FirstGadget;

	ULONG              Obsolete4;

	/* pointer to the layer of screen's titlebar, private */
	struct Layer      *BarLayer;

	UBYTE             *ExtData;

	/* general purpose pointer to data supplied by user, should only be used on custom screens */
	UBYTE             *UserData;
};

#endif

#define SCREENTYPE    0x000F /* screen type mask */
#define WBENCHSCREEN  0x0001 /* desktop screen */
#define PUBLICSCREEN  0x0002 /* standard intuition screen */
#define CUSTOMSCREEN  0x000F /* custom screen, can't have visitors, only useful for games */

#define SCREENBEHIND  0x0080 /* set with SA_Behind, set if you want your screen to open behind other screens */
#define SCREENQUIET   0x0100 /* set with SA_Quiet, set if you don't want a screen titlebar, useful on custom screens */
#define AUTOSCROLL    0x4000 /* set with SA_Autoscroll, set if you want intuition to allow user to scroll the screen with mouse */
#define PENSHARED     0x0400 /* set with SA_SharePens, allows pen allocation routines to work */

#define STDSCREENHEIGHT  -1
#define STDSCREENWIDTH   -1
/* Use as the value passed for SA_Width/SA_Height to get the default size of the screen
** for a supplied SA_DisplayID */

#define SA_Dummy                        (TAG_USER + 32)

#define SA_Left /* ISG */               (SA_Dummy + 1)
#define SA_Top  /* ISG */               (SA_Dummy + 2)
/* LONG. Specifies the screen position when the screen dimensions do not
** match the display dimensions. These tags shouldn't usualy be used,
** it's generaly better to open autoscrolling screens.
*/

#define SA_Width   /* I*G */            (SA_Dummy + 3)
#define SA_Height  /* I*G */            (SA_Dummy + 4)
/* LONG. Specifies screen width & height. Please note that you should not
** pass STDSCREENWIDTH/STDSCREENHEIGHT if you do not pass SA_DisplayID as
** well. Read the notes in SA_MonitorName and SA_DisplayWidth/Height!
*/

#define SA_Depth   /* I*G */            (SA_Dummy + 5)
#define SA_DetailPen /* I** */          (SA_Dummy + 6)
#define SA_BlockPen /* I** */           (SA_Dummy + 7)
#define SA_Title   /* I** */            (SA_Dummy + 8)
#define SA_Colors  /* I** */            (SA_Dummy + 9)
#define SA_ErrorCode /* I** */          (SA_Dummy + 10)
#define SA_Font    /* I** */            (SA_Dummy + 11)
#define SA_SysFont /* I** */            (SA_Dummy + 12)
#define SA_Type    /* I** */            (SA_Dummy + 13)
#define SA_BitMap  /* I** */            (SA_Dummy + 14)
#define SA_PubName /* I*G */            (SA_Dummy + 15)
#define SA_PubSig  /* I** */            (SA_Dummy + 16)
#define SA_PubTask /* I** */            (SA_Dummy + 17)
#define SA_DisplayID /* I*G */          (SA_Dummy + 18)
#define SA_DClip   /* I** */            (SA_Dummy + 19)
#define SA_Overscan /* I** */           (SA_Dummy + 20)
#define SA_Obsolete1 /* I** */          (SA_Dummy + 21)

#define SA_ShowTitle /* I** */          (SA_Dummy + 22)
#define SA_Behind  /* I*G */            (SA_Dummy + 23)
#define SA_Quiet   /* I** */            (SA_Dummy + 24)
#define SA_AutoScroll /* I** */         (SA_Dummy + 25)
#define SA_Pens    /* I** */            (SA_Dummy + 26)
#define SA_FullPalette /* I** */        (SA_Dummy + 27)
#define SA_ColorMapEntries /* I** */    (SA_Dummy + 28)
#define SA_Parent  /* I** */            (SA_Dummy + 29)
#define SA_Draggable /* I** */          (SA_Dummy + 30)
#define SA_Exclusive /* I** */          (SA_Dummy + 31)
#define SA_SharePens /* I** */          (SA_Dummy + 32)
#define SA_BackFill /* I** */           (SA_Dummy + 33)
#define SA_Interleaved /* I** */        (SA_Dummy + 34)
#define SA_Colors32 /* I** */           (SA_Dummy + 35)
#define SA_VideoControl /* I** */       (SA_Dummy + 36)
#define SA_FrontChild /* I** */         (SA_Dummy + 37)
#define SA_BackChild /* I** */          (SA_Dummy + 38)
#define SA_LikeWorkbench /* I** */      (SA_Dummy + 39)
#define SA_Reserved                     (SA_Dummy + 40)
#define SA_MinimizeISG /* I** */        (SA_Dummy + 41)

/* V51 */


#define SA_Displayed /* **G */                  (SA_Dummy + 101)
/* BOOL. Check whether the screen is currently displayed on one of
** system's gfx cards. */

#define SA_MonitorName /* I*G */                (SA_Dummy + 102)
/* char *. Should be used to determine on which monitor (gfx card)
** the screen should be opened. Please use this instead of storing ModeIDs
** in prefs files! Overrides SA_DisplayID and will be used to get the
** best available mode together with SA_Depth or SA_Width/Height.
** Will open a screen on other gfx card if the selected one is not
** found. Please note that .monitor prefix is included in the name.
** For autoscrolling and other non-typical screens please read
** SA_DisplayWidth/Height notes.
*/

#define SA_MonitorObject /* **G */              (SA_Dummy + 103)
/* Object *. Returns the MONITORCLASS object associated with the
** screen. Use it in order to get more info about the gfx card
** used to display the screen, monitor alignment, etc.
*/

#define SA_TopLeftScreen /* **G */              (SA_Dummy + 112)
#define SA_TopMiddleScreen                      (SA_Dummy + 113)
#define SA_TopRightScreen                       (SA_Dummy + 114)
#define SA_MiddleLeftScreen                     (SA_Dummy + 115)
#define SA_MiddleRightScreen                    (SA_Dummy + 117)
#define SA_BottomLeftScreen                     (SA_Dummy + 118)
#define SA_BottomMiddleScreen                   (SA_Dummy + 119)
#define SA_BottomRightScreen                    (SA_Dummy + 120)
/* struct Screen *. Returns a pointer to the displayed screen
** on a monitor positioned relatively to the monitor your screen is
** displayed on. Returns NULL if no screen can be found or the
** frontmost screen is not a public one. You MUST lock the
** public screens lists if you wish to use the pointer:
**
** this example will position a new window on a monitor positioned
** on a left side of the one you have a window on.
**
** struct Screen *newscreen;
**
** LockPubScreenList(); //lock the screens list
** GetAttr(SA_MiddleLeftScreen,(APTR) mywindow->WScreen,(ULONG*) &newscreen);
**
** if (newscreen)
** {
**     //open a window on newscreen here
** }
**
** UnlockPubScreenList(); //unlock the screens list
*/

#define SA_StopBlanker  /* *S* */               (SA_Dummy + 121)
/* BOOL. Setting this tag to TRUE will stop the intuition's
** screensaver/DPMS features. Please note that the call nests,
** you have to set it to FALSE as many times as you set it to TRUE
** to really enable blanking again.
** IMPORTANT: please remember that you're supposed to set SA_StopBlanker
** to FALSE for example when the user presses Pause in your movie player
** and set it to TRUE again once playback is restarted.
*/

#define SA_ShowPointer /* ISG */                (SA_Dummy + 122)
/* BOOL. Setting this tag to FALSE will hide the mouse pointer on your
** screen. Please note that this tag is ONLY supported for CUSTOM
** screens. On public screens you're only supposed to modify the pointer
** of your own window(s). Defaults to TRUE.
*/

#define SA_GammaControl /* I** */               (SA_Dummy + 123)
/* BOOL. Set to true if you wish to have control of screen's gamma settings.
** This tag enables the use of SA_GammaRed/Blue/Green tags.
*/

#define SA_GammaRed   /* ISG */	                (SA_Dummy + 124)
#define SA_GammaBlue  /* ISG */                 (SA_Dummy + 125)
#define SA_GammaGreen /* ISG */                 (SA_Dummy + 126)
/* UBYTE *. Pointer to a 256 byte array containing gamma values for
** all color levels. Setting this tag to NULL will cause intuition to
** use the default values defined for screen's monitor. The array is
** NOT copied! Setting the pointer to the current value will cause a
** gamma refresh.
*/

#define SA_3DSupport /* I** */                  (SA_Dummy + 127)
/* BOOL. Set this tag to TRUE to make intuition pick a screen mode
** with 3d support. Intuition might pick up a different depth for
** you if the one you requested doesn't have 3d support at all.
*/

#define SA_AdaptSize /* I** */                  (SA_Dummy + 128)
/* BOOL. Will adapt screen's width & height to screen's display
** width/height (note: this is determined by the available modes
** so if someone has wrong modes for his display, it may match
** that).
** EXAMPLE: SA_Width,1280,SA_Height,960,SA_AdaptSize,TRUE on a
** 1280x1024 LCD will increase the screen height to 1024.
*/

#define SA_DisplayWidth  /* I*G */              (SA_Dummy + 129)
#define SA_DisplayHeight /* I*G */              (SA_Dummy + 130)
/* ULONG. Will be used to search for the displayID instead of
** SA_Width/Height. Use this tag if you want to open a screen
** larger or smaller than the display size (for example an
** autoscrolling screen). The new screen will use dimensions
** passed with SA_Width/Height.
*/

#define SA_OpacitySupport     /* **G */         (SA_Dummy + 131)
#define SA_SourceAlphaSupport /* **G */         (SA_Dummy + 132)

#define SA_PixelFormat        /* **G */         (SA_Dummy + 133)

#define SA_ScreenbarTextYPos  /* **G */         (SA_Dummy + 134)
/* LONG. Text Y pos the screenbar plugins should use. Consistent with
** title and clocks embedded plugins. Includes the baseline of the font
** returned with SA_ScreenbarTextFont! You should use this position rather
** than compute it yourself, since it's SkinConfig dependant */

#define SA_ScreenbarTextPen   /* **G */         (SA_Dummy + 135)
/* ULONG. Text pen color used for rendering text on the screenbar */

#define SA_ScreenbarTextFont  /* **G */         (SA_Dummy + 136)
/* struct TextFont *. Font used by screenbar */

#define SA_ScreenbarSignal    /* **G */         (SA_Dummy + 137)
/* ULONG. Returns a common signal bit num (not mask!) that sbars
** may use. Mind that the signal is not yours to free */

#define SA_ExactMatchMonitorName /* I** */      (SA_Dummy + 138)
/* BOOL. If TRUE, the screen will either be opened on the
** monitor matched by SA_MonitorName or won't open at all */

#define SA_CompositingLayers     /* I*G */      (SA_Dummy + 139)
/* BOOL. Set this to true to request a compositing engine to
** handle layers on your screen. Get this attr to see if this
** succceeded. From v51.30 */

#define OSERR_NOMONITOR    (1)
#define OSERR_NOCHIPS      (2)
#define OSERR_NOMEM        (3)
#define OSERR_NOCHIPMEM    (4)
#define OSERR_PUBNOTUNIQUE (5)
#define OSERR_UNKNOWNMODE  (6)
#define OSERR_TOODEEP      (7)
#define OSERR_ATTACHFAIL   (8)
#define OSERR_NOTAVAILABLE (9)


struct PubScreenNode
{
	struct Node    psn_Node;
	struct Screen *psn_Screen;
	UWORD          psn_Flags;
	WORD           psn_Size;
	WORD           psn_VisitorCount;
	struct Task   *psn_SigTask;
	UBYTE          psn_SigBit;
};

#define PSNF_PRIVATE  (0x0001)


#define MAXPUBSCREENNAME  (139)


#define SHANGHAI      0x0001
#define POPPUBSCREEN  0x0002

/* ScreenDepth() flags, it's generaly easier to use ScreenToFront()/ScreenToBack() calls */
#define SDEPTH_TOFRONT    (0) /* bring the screen to front */
#define SDEPTH_TOBACK     (1) /* bring the screen to back */


#define SPOS_RELATIVE     (0)
#define SPOS_ABSOLUTE     (1)
#define SPOS_MAKEVISIBLE  (2)
#define SPOS_FORCEDRAG    (4)

/* Structure used for double or triple-buffering of screens, can only
** be used on custom screens. The buffers can only be allocated with the
** AllocScreenBuffer() call.
*/
struct ScreenBuffer
{
	struct BitMap   *sb_BitMap;
	struct DBufInfo *sb_DBufInfo;
};

/* AllocScreenBuffer flags, documented in AllocScreenBuffer autodoc */
#define SB_SCREEN_BITMAP  1
#define SB_COPY_BITMAP    2

/* Flags for screen's layer opacity + source opacity support */
#define SAOS_OpacitySupport_None        0 /* opacity setting unsupported                  */
#define SAOS_OpacitySupport_OnOff       1 /* only fully visible/fully invisible supported */
#define SAOS_OpacitySupport_CPU         2 /* opacity is done by the CPU - slow            */
#define SAOS_OpacitySupport_HW          3 /* opacity is hardware accelerated              */

#define SASA_SourceAlphaSupport_None    0 /* source alpha not supported                   */
#define SASA_SourceAlphaSupport_CPU     1 /* source alpha done by the CPU - slow!!!       */
#define SASA_SourceAlphaSupport_HW      2 /* source alpha hardware accelerated            */

#pragma pack()

#ifndef INTUITION_IOBSOLETE_H
# include <intuition/iobsolete.h>
#endif

#endif /* INTUITION_SCREENS_H */
