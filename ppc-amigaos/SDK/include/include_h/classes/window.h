#ifndef CLASSES_WINDOW_H
#define CLASSES_WINDOW_H
/*
**    $VER: window.h 54.16 (22.08.2022)
**
**    window.class definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
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

/*
** Attributes specific to window.class
*/

#define WINDOW_Dummy              (REACTION_Dummy + 0x25000)

#define WINDOW_Window             (WINDOW_Dummy + 1)
    /* (struct Window *) Return the pointer to the real
       Intuition window structure. */

#define WINDOW_SigMask            (WINDOW_Dummy + 2)
    /* (uint32) Return the signal bit that you must wait for
       this window to know if the window as received
       any input. Defaults to 0. */

#define WINDOW_MenuStrip          (WINDOW_Dummy + 4)
    /* (struct MenuStrip *) A list of Menu structures, or a BOOPSI
       menu tree built with "menuclass", that will be used as
       the menu of this window when open. Defaults to NULL. */

#define WINDOW_Layout             (WINDOW_Dummy + 5)
#define WINDOW_ParentLayout       WINDOW_Layout
#define WINDOW_ParentGroup        WINDOW_Layout
    /* (Object *) Layout group object for the window
       Defaults to NULL. */

#define WINDOW_UserData           (WINDOW_Dummy + 6)
    /* (APTR) A value that will be stored in the Window Object
       structure. Defaults to NULL. */

#define WINDOW_SharedPort         (WINDOW_Dummy + 7)
    /* (struct MsgPort *) A port that will be used for this
       window.  The port will not be closed at dispose time.
       Defaults to NULL. */

#define WINDOW_Zoom               (WINDOW_Dummy + 8)
    /* When TRUE, it will act as a click on the zoom button. */

#define WINDOW_FrontBack          (WINDOW_Dummy + 9)
    /* (uint16) Only WT_FRONT and WT_BACK can be used here.
       This put the window in front or in back of
       others windows */

#define WINDOW_Activate           (WINDOW_Dummy + 10)
    /* (BOOL) Activate the window (and its master group) if
       set to TRUE and the window is open. */

#define WINDOW_LockWidth          (WINDOW_Dummy + 11)
    /* (BOOL) Lock the window from resize in width.
       Defaults to FALSE. */

#define WINDOW_LockHeight         (WINDOW_Dummy + 12)
    /* (BOOL) Lock the window from resize in height.
       Defaults to FALSE. */

#define WINDOW_AppPort            (WINDOW_Dummy + 13)
    /* (struct MsgPort *) A shared message port for appmessages
       You must pass this to be able to iconify the window.
       Defaults to NULL. */

#define WINDOW_Position           (WINDOW_Dummy + 14)
    /* (uint32) The initial position to open at. */

#define WINDOW_IDCMPHook          (WINDOW_Dummy + 15)
    /* (struct Hook *) Defaults to NULL. */

#define WINDOW_IDCMPHookBits      (WINDOW_Dummy + 16)
    /* (uint32) Defaults to 0L. */

#define WINDOW_GadgetUserData     (WINDOW_Dummy + 17)
#define WINDOW_InterpretUserData  WINDOW_GadgetUserData
    /* (uint16) How Gadget.UserData is interpreted.
       Defaults to WGUD_IGNORE. */

#define WINDOW_MenuUserData       (WINDOW_Dummy + 25)
    /* (uint16) How GTMENUITEM_USERDATA (for GadTools
       menus) or MA_UserData (for BOOPSI menus) is
       interpreted.
       Defaults to WGUD_IGNORE. */

#define WGUD_HOOK   0 /* Gadget/MenuItem UserData points to a Hook */
#define WGUD_FUNC   1 /* Points to a function */
#define WGUD_IGNORE 2 /* App private, don't touch it */

#define WINDOW_IconTitle          (WINDOW_Dummy + 18)
    /* (CONST_STRPTR) Title of the iconified window. */

#define WINDOW_AppMsgHook         (WINDOW_Dummy + 19)
    /* (struct Hook *) Defaults to NULL. */

#define WINDOW_Icon               (WINDOW_Dummy + 20)
    /* (struct DiskObject *) Custom icon for the window. */

#define WINDOW_AppWindow          (WINDOW_Dummy + 21)
    /* (BOOL) Make the window a Workbench AppWindow. */

#define WINDOW_GadgetHelp         (WINDOW_Dummy + 22)
    /* (BOOL) Set gadget-help on/off. */

#define WINDOW_IconifyGadget      (WINDOW_Dummy + 23)
    /* (BOOL) Add an iconification gadget to window title bar. */

#define WINDOW_TextAttr           (WINDOW_Dummy + 24)
    /* (struct TextAttr *)Default font for window.
       If not set, use screen font. */

#define WINDOW_BackFillName       (WINDOW_Dummy + 26)
    /* (CONST_STRPTR) replaces the default backfill pattern with this file,
       loaded through datatypes. */

#define WINDOW_RefWindow          (WINDOW_Dummy + 41)
    /* (struct Window *) Causes WINDOW_Position to be relative to
       to this window vs the screen. (V42) */

#define WINDOW_InputEvent         (WINDOW_Dummy + 42)
    /* (struct InputEvent *) returns a pointer to an inputevent
       which will be current *ONLY* after a WHMI_RAWKEY. (V42) */

#define WINDOW_HintInfo           (WINDOW_Dummy + 43)
    /* (struct HintInfo *) Static Array of help hints.
        Pointer to a gadget HintInfo array. This is similar in concept
       to Apple's bubble help or Microsoft's help tips. By providing
       this array of helpinfo, and setting WINDOW_GadgetHelp, TRUE,
       window class will transparently manage the help hints. */

#define WINDOW_KillWindow         (WINDOW_Dummy + 44)
#define WINDOW_Application        (WINDOW_Dummy + 45)
    /* ** PRIVATE TAGS SET/GET BY APPLICATION CLASS! ** (V43 BETA) */

#define WINDOW_InterpretIDCMPHook (WINDOW_Dummy + 46)
    /* Interpret IDCMPHook results. (V43 BETA) */

#define WINDOW_Parent             (WINDOW_Dummy + 47)
    /* ** PRIVATE TAG SET/GET BY APPLICATION CLASS! ** (V43 BETA) */

#define WINDOW_PreRefreshHook     (WINDOW_Dummy + 48)
    /* (struct Hook *) window.class calls this hook BEFORE RefreshGList() */

#define WINDOW_PostRefreshHook    (WINDOW_Dummy + 49)
    /* (struct Hook *) window.class calls this hook AFTER RefreshGList() */

#define WINDOW_AppWindowPtr       (WINDOW_Dummy + 50)
    /* (struct AppWindow *) GetAttr()'able pointer to AddAppWindow() result.*/

#define WINDOW_VertProp           (WINDOW_Dummy + 27)
    /* (int32) Show/hide vertical border scroller. (V45, public since V51) */

#define WINDOW_VertObject         (WINDOW_Dummy + 28)
    /* (Object *) OM_GET the vertical scroller object pointer. (V45) */

#define WINDOW_HorizProp          (WINDOW_Dummy + 29)
    /* (int32) Show/hide horizontal border scroller. (V45, public since V51) */

#define WINDOW_HorizObject        (WINDOW_Dummy + 30)
    /* (Object *) OM_GET the horizontal scroller object pointer. (V45) */

#define WINDOW_IconNoDispose      (WINDOW_Dummy + 51)
    /* (BOOL) Dispose WINDOW_Icon? Defaults to false (ie. dispose) (V50). */

#define WINDOW_NewMenu            (WINDOW_Dummy + 52)
    /* (struct NewMenu *) Let window.class create and layout the menus
       useful for iconification and screenchanges (V50). */

#define WINDOW_Qualifier          (WINDOW_Dummy + 53)
    /* (uint16) Current qualifiers from intuimessage (V50). */

#define WINDOW_CharSet            (WINDOW_Dummy + 54)
    /* (uint32) Charset of the WINDOW_HintInfo strings and the
       WINDOW_NewMenu strings (V51.11). */

#define WINDOW_BuiltInScroll      (WINDOW_Dummy + 55)
    /* (BOOL) Turn on built-in scrollwheel support. Also needs
    IDCMP_EXTENDEDMOUSE specified. */

#define WINDOW_IDCMPSnoopHook     (WINDOW_Dummy + 56)
    /* (struct Hook *) Defaults to NULL. */

#define WINDOW_ShowingHint        (WINDOW_Dummy + 57)
    /* (BOOL) Is there a GadgetHelp hint displayed? */

#define WINDOW_NewPrefsHook       (WINDOW_Dummy + 58)
    /* (struct Hook *) Called when the window receives a NEWPREFS
       notification from GUI prefs */

#define WINDOW_Iconifiable        (WINDOW_Dummy + 59)
    /* (BOOL) Window can be iconified via WMHI_ICONIFY/WMHI_UNICONIFY
       but does not have an iconify gadget. */

#define WINDOW_PopupGadget        (WINDOW_Dummy + 60)
    /* (BOOL) Tell window class that the window should have a popup
       gadget. Defaults to FALSE */

#define WINDOW_PopupHook          (WINDOW_Dummy + 61)
    /* (APTR) Set the pointer to a hook which will add popup menu
       items. */

#define WINDOW_PopupItem          (WINDOW_Dummy + 62)
    /* (APTR) If a user-defined popup item was selected, get the
        pointer to it. */

#define WINDOW_JumpScreensMenu    (WINDOW_Dummy + 63)
    /* (BOOL) Show the "Jump to screen" menu. Defaults to FALSE */

#define WINDOW_UniqueID           (WINDOW_Dummy + 64)
    /* (STRPTR) An ID for this window for snapshot and restore
       functionality. */

#define WINDOW_MenuAddress        (WINDOW_Dummy + 65)
    /* (APTR) Address of the menu strip (traditional or BOOPSI)
       the latest WMHI_MENUPICK/WMHI_MENUHELP event originated
       from. This can be different from WINDOW_MenuStrip in case
       the event came from a context menu.
       If you don't use context menus you never need to check this
       attribute. (V54) */

#define WINDOW_MenuType           (WINDOW_Dummy + 66)
    /* (uint32) The value of the IMTAG_MenuType tag item from the
       latest WMHI_MENUPICK/WMHI_MENUHELP event's IntuiMessage.
       This allows to distinguish between a normal window menu
       selection and one from a context menu, and in the latter
       case tells exactly which type of context menu generated
       the menu event.
       The possible values can be IMT_DEFAULT, IMT_CONTEXT_WINDOW,
       IMT_CONTEXT_GADGET_APP or IMT_CONTEXT_GADGET_OBJ (for more
       information see <intuition/intuition.h>).
       If you don't use context menus you never need to check this
       attribute. (V54) */

#define WINDOW_MenuContext        (WINDOW_Dummy + 67)
    /* (APTR) The value of the IMTAG_MenuContext tag item from the
       latest WMHI_MENUPICK/WMHI_MENUHELP event's IntuiMessage.
       This can be used to quickly identify the actual "context"
       a context menu event applies to.
       If WINDOW_MenuType is IMT_CONTEXT_WINDOW, this is whatever
       value your window's context menu hook passed back in the
       ContextMenuMsg.Context field. For IMT_CONTEXT_GADGET_APP and
       IMT_CONTEXT_GADGET_OBJ, this is the address of the gadget
       the context menu belongs to.
       Do not read if WINDOW_MenuType is IMT_DEFAULT (i.e. upon a
       normal window menu event), as the value is undefined in that
       case (for more information see <intuition/intuition.h>).
       If you don't use context menus you never need to check this
       attribute. (V54) */

/****************************************************************************/

/* Pre-defined WM_HANDLEINPUT return codes. */
#define WMHI_LASTMSG         (0L)     /* No more messages */
#define WMHI_IGNORE          (~0L)    /* Ignore */
#define WMHI_GADGETMASK      (0xffff) /* Gadget ID mask value */
#define WMHI_MENUMASK        (0xffff) /* Menu ID mask value */
#define WMHI_KEYMASK         (0xff)   /* Key code mask value */
#define WMHI_CLASSMASK   (0xffff0000) /* Event class mask value */
#define WMHI_CLOSEWINDOW     (1L<<16) /* The close gadget was clicked */
                                      /* or a hook function trigged close */
#define WMHI_GADGETUP        (2L<<16) /* A gadget was released */
#define WMHI_INACTIVE        (3L<<16) /* The window was de-activated */
#define WMHI_ACTIVE          (4L<<16) /* The window was activated */
#define WMHI_NEWSIZE         (5L<<16) /* The window was resized */
#define WMHI_MENUPICK        (6L<<16) /* A menu item was picked */
#define WMHI_MENUHELP        (7L<<16) /* Help was hit in a menu */
#define WMHI_GADGETHELP      (8L<<16) /* A gadget returns a help code */
#define WMHI_ICONIFY         (9L<<16) /* Window requests to be iconified */
#define WMHI_UNICONIFY      (10L<<16) /* Window was uniconified */
#define WMHI_RAWKEY         (11L<<16) /* Raw key codes */
#define WMHI_VANILLAKEY     (12L<<16) /* Vanilla key codes */
#define WMHI_CHANGEWINDOW   (13L<<16) /* Window moved (or depth arranged) */
#define WMHI_INTUITICK      (14L<<16) /* IDCMP intuitick (maximum 10 per second) */
#define WMHI_MOUSEMOVE      (15L<<16) /* IDCMP mouse move */
#define WMHI_MOUSEBUTTONS   (16L<<16) /* IDCMP mouse buttons */
#define WMHI_DISPOSEDWINDOW (17L<<16) /* Hook function triggered disposal */
#define WMHI_JUMPSCREEN     (18L<<16) /* User wants window on a different Screen */
#define WMHI_POPUPMENU      (19L<<16) /* A user defined popup menu item was selected */
#define WMHI_GADGETDOWN     (20L<<16) /* A gadget was activated (V53.52) */

/****************************************************************************/

#define WHOOKRSLT_IGNORE        (0L) /* Ignore return value */
#define WHOOKRSLT_CLOSEWINDOW   (1L) /* WM_CLOSE and return WMHI_CLOSEWINDOW */
#define WHOOKRSLT_DISPOSEWINDOW (2L) /* OM_DISPOSE and return WMHI_DISPOSEDWINDOW */

/****************************************************************************/

#define WMF_ZOOMED    (0x0001) /* Window is in zoomed state */
#define WMF_ZIPWINDOW (0x0002) /* This resize toggled zoom state */

/****************************************************************************/

/* Possible WINDOW_FrontBack values */
#define WT_FRONT    TRUE
#define WT_BACK     FALSE

/* Possible WINDOW_Position values */
#define WPOS_CENTERSCREEN (1L)    /* Center on the screen */
#define WPOS_CENTERMOUSE  (2L)    /* Center under the mouse */
#define WPOS_TOPLEFT      (3L)    /* Top-left of the screen */
#define WPOS_CENTERWINDOW (4L)    /* Center in another window */
#define WPOS_FULLSCREEN   (5L)    /* Top-left of, and fill the screen */

/****************************************************************************/

/*
 * Window Methods
 */
#define WM_HANDLEINPUT    (0x570001L)

/* The WM_HANDLEINPUT method should be called by for each received
 * IDCMP message.
 * If the message could be linked to a gadget in the window, the int16
 * pointed to by wmh_Code will be set to the gadget's return code.
 */

struct wmHandle
{
    uint32 MethodID;    /* WM_HANDLEINPUT */
    int16 *wmh_Code;    /* The code from the gadget */
};

#define WM_OPEN           (0x570002L)
#define WM_CLOSE          (0x570003L)
#define WM_NEWPREFS       (0x570004L)
#define WM_ICONIFY        (0x570005L)
#define WM_RETHINK        (0x570006L)
#define WM_ACTIVATEGADGET (0x570007L)    /* V50 */

struct wmActivateGadget
{
    uint32         MethodID;
    struct Gadget *wma_Object;
};


#define WM_SNAPSHOT       (0x570008L)    /* 53.51 */

enum SnapHow
{
    SAVE = 0, /* forces WM_SNAPSHOT to save data to ENVARC; */
    USE       /* data is only saved to ENV: */
};
struct wmSnapshot
{
    uint32         MethodID; /* always WM_SNAPSHOT */
    enum SnapHow   How;
};

#define WM_UNSNAPSHOT     (0x570009L)    /* 53.51 */
#define WM_RESTORE        (0x570010L)    /* 53.51 */


/****************************************************************************/

/* The use of GA_HintInfo is highly recommended over
** using arrays of the following structure .
*/

struct HintInfo
{
    int16  hi_GadgetID;   /* Gadget ID hint belongs to, -1 indicates end. */
    int16  hi_Code;       /* Code required for this gadget,
                           * or -1 if it doesn't matter. */
    CONST_STRPTR hi_Text; /* The text of the hint.. */
    uint32 hi_Flags;      /* Flags, currently unsupported and must be 0 */
};

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

#endif /* CLASSES_WINDOW_H */
