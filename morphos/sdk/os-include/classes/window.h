#ifndef CLASSES_WINDOW_H
#define CLASSES_WINDOW_H

/*
	window.class definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#pragma pack(2)


/* Attributes specific to window.class */

#define WINDOW_Dummy               (REACTION_Dummy + 0x25000)
#define WINDOW_Window              (WINDOW_Dummy + 1)
#define WINDOW_SigMask             (WINDOW_Dummy + 2)
#define WINDOW_MenuStrip           (WINDOW_Dummy + 4)
#define WINDOW_Layout              (WINDOW_Dummy + 5)
#define WINDOW_ParentLayout        (WINDOW_Layout)
#define WINDOW_ParentGroup         (WINDOW_Layout)
#define WINDOW_UserData            (WINDOW_Dummy + 6)
#define WINDOW_SharedPort          (WINDOW_Dummy + 7)
#define WINDOW_Zoom                (WINDOW_Dummy + 8)
#define WINDOW_FrontBack           (WINDOW_Dummy + 9)
#define WINDOW_Activate            (WINDOW_Dummy + 10)
#define WINDOW_LockWidth           (WINDOW_Dummy + 11)
#define WINDOW_LockHeight          (WINDOW_Dummy + 12)
#define WINDOW_AppPort             (WINDOW_Dummy + 13)
#define WINDOW_Position            (WINDOW_Dummy + 14)
#define WINDOW_IDCMPHook           (WINDOW_Dummy + 15)
#define WINDOW_IDCMPHookBits       (WINDOW_Dummy + 16)
#define WINDOW_GadgetUserData      (WINDOW_Dummy + 17)
#define WINDOW_InterpretUserData   (WINDOW_GadgetUserData)
#define WINDOW_IconTitle           (WINDOW_Dummy + 18)
#define WINDOW_AppMsgHook          (WINDOW_Dummy + 19)
#define WINDOW_Icon                (WINDOW_Dummy + 20)
#define WINDOW_AppWindow           (WINDOW_Dummy + 21)
#define WINDOW_GadgetHelp          (WINDOW_Dummy + 22)
#define WINDOW_IconifyGadget       (WINDOW_Dummy + 23)
#define WINDOW_TextAttr            (WINDOW_Dummy + 24)
#define WINDOW_MenuUserData        (WINDOW_Dummy + 25)
#define WINDOW_BackFillName        (WINDOW_Dummy + 26)

#define WINDOW_VertProp            (WINDOW_Dummy + 27)
#define WINDOW_VertObject          (WINDOW_Dummy + 28)
#define WINDOW_HorizProp           (WINDOW_Dummy + 29)
#define WINDOW_HorizObject         (WINDOW_Dummy + 30)

#define WINDOW_RefWindow           (WINDOW_Dummy + 41)
#define WINDOW_InputEvent          (WINDOW_Dummy + 42)
#define WINDOW_HintInfo            (WINDOW_Dummy + 43)
#define WINDOW_KillWindow          (WINDOW_Dummy + 44)
#define WINDOW_Application         (WINDOW_Dummy + 45)
#define WINDOW_InterpretIDCMPHook  (WINDOW_Dummy + 46)
#define WINDOW_Parent              (WINDOW_Dummy + 47)
#define WINDOW_PreRefreshHook      (WINDOW_Dummy + 48)
#define WINDOW_PostRefreshHook     (WINDOW_Dummy + 49)
#define WINDOW_AppWindowPtr        (WINDOW_Dummy + 50)


/* Gadget/MenuItem userdata */

#define WGUD_HOOK    0
#define WGUD_FUNC    1
#define WGUD_IGNORE  2


/* Predefined WM_HANDLEINPUT return codes */

#define WMHI_LASTMSG              (0L)
#define WMHI_IGNORE              (~0L)
#define WMHI_GADGETMASK       (0xffff)
#define WMHI_MENUMASK         (0xffff)
#define WMHI_KEYMASK            (0xff)
#define WMHI_CLASSMASK    (0xffff0000)
#define WMHI_CLOSEWINDOW       (1<<16)
#define WMHI_GADGETUP          (2<<16)
#define WMHI_INACTIVE          (3<<16)
#define WMHI_ACTIVE            (4<<16)
#define WMHI_NEWSIZE           (5<<16)
#define WMHI_MENUPICK          (6<<16)
#define WMHI_MENUHELP          (7<<16)
#define WMHI_GADGETHELP        (8<<16)
#define WMHI_ICONIFY           (9<<16)
#define WMHI_UNICONIFY        (10<<16)
#define WMHI_RAWKEY           (11<<16)
#define WMHI_VANILLAKEY       (12<<16)
#define WMHI_CHANGEWINDOW     (13<<16)
#define WMHI_INTUITICK        (14<<16)
#define WMHI_MOUSEMOVE        (15<<16)
#define WMHI_MOUSEBUTTONS     (16<<16)
#define WMHI_DISPOSEDWINDOW   (17<<16)

#define WMF_ZOOMED            (0x0001)
#define WMF_ZIPWINDOW         (0x0002)


/* Possible WINDOW_FrontBack values */

#define WT_FRONT  TRUE
#define WT_BACK  FALSE


/* Possible WINDOW_Position values */

#define WPOS_CENTERSCREEN         (1L)
#define WPOS_CENTERMOUSE          (2L)
#define WPOS_TOPLEFT              (3L)
#define WPOS_CENTERWINDOW         (4L)
#define WPOS_FULLSCREEN           (5L)


/* Window methods */

#define WM_HANDLEINPUT     (0x570001L)


struct wmHandle
{
	ULONG  MethodID;
	WORD  *wmh_Code;
};


#define WM_OPEN            (0x570002L)
#define WM_CLOSE           (0x570003L)
#define WM_NEWPREFS        (0x570004L)
#define WM_ICONIFY         (0x570005L)
#define WM_RETHINK         (0x570006L)


struct HintInfo
{
	WORD    hi_GadgetID;
	WORD    hi_Code;
	STRPTR  hi_Text;
	ULONG   hi_Flags;
};


#pragma pack()

#endif /* CLASSES_WINDOW_H */
