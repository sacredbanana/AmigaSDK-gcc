/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_INTUITION_H
#define _PPCINLINE_INTUITION_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef INTUITION_BASE_NAME
#define INTUITION_BASE_NAME IntuitionBase
#endif /* !INTUITION_BASE_NAME */

#define OpenIntuition() \
	LP0NR(30, OpenIntuition, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Intuition(__p0) \
	LP1NR(36, Intuition, \
		struct InputEvent *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddGadget(__p0, __p1, __p2) \
	LP3(42, UWORD , AddGadget, \
		struct Window *, __p0, a0, \
		struct Gadget *, __p1, a1, \
		ULONG , __p2, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ClearDMRequest(__p0) \
	LP1(48, BOOL , ClearDMRequest, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ClearMenuStrip(__p0) \
	LP1NR(54, ClearMenuStrip, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ClearPointer(__p0) \
	LP1NR(60, ClearPointer, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseScreen(__p0) \
	LP1(66, BOOL , CloseScreen, \
		struct Screen *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseWindow(__p0) \
	LP1NR(72, CloseWindow, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseWorkBench() \
	LP0(78, LONG , CloseWorkBench, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CurrentTime(__p0, __p1) \
	LP2NR(84, CurrentTime, \
		ULONG *, __p0, a0, \
		ULONG *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DisplayAlert(__p0, __p1, __p2) \
	LP3(90, BOOL , DisplayAlert, \
		ULONG , __p0, d0, \
		CONST_STRPTR , __p1, a0, \
		ULONG , __p2, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DisplayBeep(__p0) \
	LP1NR(96, DisplayBeep, \
		struct Screen *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoubleClick(__p0, __p1, __p2, __p3) \
	LP4(102, BOOL , DoubleClick, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		ULONG , __p2, d2, \
		ULONG , __p3, d3, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DrawBorder(__p0, __p1, __p2, __p3) \
	LP4NR(108, DrawBorder, \
		struct RastPort *, __p0, a0, \
		CONST struct Border *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DrawImage(__p0, __p1, __p2, __p3) \
	LP4NR(114, DrawImage, \
		struct RastPort *, __p0, a0, \
		struct Image *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define EndRequest(__p0, __p1) \
	LP2NR(120, EndRequest, \
		struct Requester *, __p0, a0, \
		struct Window *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDefPrefs(__p0, __p1) \
	LP2(126, struct Preferences *, GetDefPrefs, \
		struct Preferences *, __p0, a0, \
		LONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetPrefs(__p0, __p1) \
	LP2(132, struct Preferences *, GetPrefs, \
		struct Preferences *, __p0, a0, \
		LONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitRequester(__p0) \
	LP1NR(138, InitRequester, \
		struct Requester *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ItemAddress(__p0, __p1) \
	LP2(144, struct MenuItem *, ItemAddress, \
		CONST struct Menu *, __p0, a0, \
		ULONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ModifyIDCMP(__p0, __p1) \
	LP2(150, BOOL , ModifyIDCMP, \
		struct Window *, __p0, a0, \
		ULONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ModifyProp(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8NR(156, ModifyProp, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		ULONG , __p3, d0, \
		ULONG , __p4, d1, \
		ULONG , __p5, d2, \
		ULONG , __p6, d3, \
		ULONG , __p7, d4, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MoveScreen(__p0, __p1, __p2) \
	LP3NR(162, MoveScreen, \
		struct Screen *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MoveWindow(__p0, __p1, __p2) \
	LP3NR(168, MoveWindow, \
		struct Window *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OffGadget(__p0, __p1, __p2) \
	LP3NR(174, OffGadget, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OffMenu(__p0, __p1) \
	LP2NR(180, OffMenu, \
		struct Window *, __p0, a0, \
		ULONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OnGadget(__p0, __p1, __p2) \
	LP3NR(186, OnGadget, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OnMenu(__p0, __p1) \
	LP2NR(192, OnMenu, \
		struct Window *, __p0, a0, \
		ULONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenScreen(__p0) \
	LP1(198, struct Screen *, OpenScreen, \
		CONST struct NewScreen *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenWindow(__p0) \
	LP1(204, struct Window *, OpenWindow, \
		CONST struct NewWindow *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenWorkBench() \
	LP0(210, ULONG , OpenWorkBench, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PrintIText(__p0, __p1, __p2, __p3) \
	LP4NR(216, PrintIText, \
		struct RastPort *, __p0, a0, \
		CONST struct IntuiText *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RefreshGadgets(__p0, __p1, __p2) \
	LP3NR(222, RefreshGadgets, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemoveGadget(__p0, __p1) \
	LP2(228, UWORD , RemoveGadget, \
		struct Window *, __p0, a0, \
		struct Gadget *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReportMouse(__p0, __p1) \
	LP2NR(234, ReportMouse, \
		LONG , __p0, d0, \
		struct Window *, __p1, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Request(__p0, __p1) \
	LP2(240, BOOL , Request, \
		struct Requester *, __p0, a0, \
		struct Window *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScreenToBack(__p0) \
	LP1NR(246, ScreenToBack, \
		struct Screen *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScreenToFront(__p0) \
	LP1NR(252, ScreenToFront, \
		struct Screen *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetDMRequest(__p0, __p1) \
	LP2(258, BOOL , SetDMRequest, \
		struct Window *, __p0, a0, \
		struct Requester *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetMenuStrip(__p0, __p1) \
	LP2(264, BOOL , SetMenuStrip, \
		struct Window *, __p0, a0, \
		struct Menu *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetPointer(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6NR(270, SetPointer, \
		struct Window *, __p0, a0, \
		UWORD *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetWindowTitles(__p0, __p1, __p2) \
	LP3NR(276, SetWindowTitles, \
		struct Window *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		CONST_STRPTR , __p2, a2, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ShowTitle(__p0, __p1) \
	LP2NR(282, ShowTitle, \
		struct Screen *, __p0, a0, \
		LONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SizeWindow(__p0, __p1, __p2) \
	LP3NR(288, SizeWindow, \
		struct Window *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ViewAddress() \
	LP0(294, struct View *, ViewAddress, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ViewPortAddress(__p0) \
	LP1(300, struct ViewPort *, ViewPortAddress, \
		CONST struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WindowToBack(__p0) \
	LP1NR(306, WindowToBack, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WindowToFront(__p0) \
	LP1NR(312, WindowToFront, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WindowLimits(__p0, __p1, __p2, __p3, __p4) \
	LP5(318, BOOL , WindowLimits, \
		struct Window *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetPrefs(__p0, __p1, __p2) \
	LP3(324, struct Preferences *, SetPrefs, \
		CONST struct Preferences *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IntuiTextLength(__p0) \
	LP1(330, LONG , IntuiTextLength, \
		CONST struct IntuiText *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WBenchToBack() \
	LP0(336, BOOL , WBenchToBack, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WBenchToFront() \
	LP0(342, BOOL , WBenchToFront, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AutoRequest(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8(348, BOOL , AutoRequest, \
		struct Window *, __p0, a0, \
		CONST struct IntuiText *, __p1, a1, \
		CONST struct IntuiText *, __p2, a2, \
		CONST struct IntuiText *, __p3, a3, \
		ULONG , __p4, d0, \
		ULONG , __p5, d1, \
		ULONG , __p6, d2, \
		ULONG , __p7, d3, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BeginRefresh(__p0) \
	LP1NR(354, BeginRefresh, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BuildSysRequest(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7(360, struct Window *, BuildSysRequest, \
		struct Window *, __p0, a0, \
		CONST struct IntuiText *, __p1, a1, \
		CONST struct IntuiText *, __p2, a2, \
		CONST struct IntuiText *, __p3, a3, \
		ULONG , __p4, d0, \
		ULONG , __p5, d1, \
		ULONG , __p6, d2, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define EndRefresh(__p0, __p1) \
	LP2NR(366, EndRefresh, \
		struct Window *, __p0, a0, \
		LONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeSysRequest(__p0) \
	LP1NR(372, FreeSysRequest, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MakeScreen(__p0) \
	LP1(378, LONG , MakeScreen, \
		struct Screen *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemakeDisplay() \
	LP0(384, LONG , RemakeDisplay, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RethinkDisplay() \
	LP0(390, LONG , RethinkDisplay, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocRemember(__p0, __p1, __p2) \
	LP3(396, APTR , AllocRemember, \
		struct Remember **, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeRemember(__p0, __p1) \
	LP2NR(408, FreeRemember, \
		struct Remember **, __p0, a0, \
		LONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockIBase(__p0) \
	LP1(414, ULONG , LockIBase, \
		ULONG , __p0, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockIBase(__p0) \
	LP1NR(420, UnlockIBase, \
		ULONG , __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetScreenData(__p0, __p1, __p2, __p3) \
	LP4(426, LONG , GetScreenData, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		CONST struct Screen *, __p3, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RefreshGList(__p0, __p1, __p2, __p3) \
	LP4NR(432, RefreshGList, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		LONG , __p3, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddGList(__p0, __p1, __p2, __p3, __p4) \
	LP5(438, UWORD , AddGList, \
		struct Window *, __p0, a0, \
		struct Gadget *, __p1, a1, \
		ULONG , __p2, d0, \
		LONG , __p3, d1, \
		struct Requester *, __p4, a2, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemoveGList(__p0, __p1, __p2) \
	LP3(444, UWORD , RemoveGList, \
		struct Window *, __p0, a0, \
		struct Gadget *, __p1, a1, \
		LONG , __p2, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ActivateWindow(__p0) \
	LP1NR(450, ActivateWindow, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RefreshWindowFrame(__p0) \
	LP1NR(456, RefreshWindowFrame, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ActivateGadget(__p0, __p1, __p2) \
	LP3(462, BOOL , ActivateGadget, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewModifyProp(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	LP9NR(468, NewModifyProp, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		ULONG , __p3, d0, \
		ULONG , __p4, d1, \
		ULONG , __p5, d2, \
		ULONG , __p6, d3, \
		ULONG , __p7, d4, \
		LONG , __p8, d5, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define QueryOverscan(__p0, __p1, __p2) \
	LP3(474, LONG , QueryOverscan, \
		ULONG , __p0, a0, \
		struct Rectangle *, __p1, a1, \
		LONG , __p2, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MoveWindowInFrontOf(__p0, __p1) \
	LP2NR(480, MoveWindowInFrontOf, \
		struct Window *, __p0, a0, \
		struct Window *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ChangeWindowBox(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(486, ChangeWindowBox, \
		struct Window *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetEditHook(__p0) \
	LP1(492, struct Hook *, SetEditHook, \
		struct Hook *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetMouseQueue(__p0, __p1) \
	LP2(498, LONG , SetMouseQueue, \
		struct Window *, __p0, a0, \
		ULONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ZipWindow(__p0) \
	LP1NR(504, ZipWindow, \
		struct Window *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockPubScreen(__p0) \
	LP1(510, struct Screen *, LockPubScreen, \
		CONST_STRPTR , __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockPubScreen(__p0, __p1) \
	LP2NR(516, UnlockPubScreen, \
		CONST_STRPTR , __p0, a0, \
		struct Screen *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockPubScreenList() \
	LP0(522, struct List *, LockPubScreenList, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockPubScreenList() \
	LP0NR(528, UnlockPubScreenList, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NextPubScreen(__p0, __p1) \
	LP2(534, STRPTR , NextPubScreen, \
		CONST struct Screen *, __p0, a0, \
		STRPTR , __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetDefaultPubScreen(__p0) \
	LP1NR(540, SetDefaultPubScreen, \
		CONST_STRPTR , __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetPubScreenModes(__p0) \
	LP1(546, UWORD , SetPubScreenModes, \
		ULONG , __p0, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PubScreenStatus(__p0, __p1) \
	LP2(552, UWORD , PubScreenStatus, \
		struct Screen *, __p0, a0, \
		ULONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainGIRPort(__p0) \
	LP1(558, struct RastPort *, ObtainGIRPort, \
		struct GadgetInfo *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleaseGIRPort(__p0) \
	LP1NR(564, ReleaseGIRPort, \
		struct RastPort *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GadgetMouse(__p0, __p1, __p2) \
	LP3NR(570, GadgetMouse, \
		struct Gadget *, __p0, a0, \
		struct GadgetInfo *, __p1, a1, \
		WORD *, __p2, a2, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDefaultPubScreen(__p0) \
	LP1NR(582, GetDefaultPubScreen, \
		STRPTR , __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define EasyRequestArgs(__p0, __p1, __p2, __p3) \
	LP4(588, LONG , EasyRequestArgs, \
		struct Window *, __p0, a0, \
		CONST struct EasyStruct *, __p1, a1, \
		ULONG *, __p2, a2, \
		CONST APTR , __p3, a3, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BuildEasyRequestArgs(__p0, __p1, __p2, __p3) \
	LP4(594, struct Window *, BuildEasyRequestArgs, \
		struct Window *, __p0, a0, \
		CONST struct EasyStruct *, __p1, a1, \
		ULONG , __p2, d0, \
		CONST APTR , __p3, a3, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SysReqHandler(__p0, __p1, __p2) \
	LP3(600, LONG , SysReqHandler, \
		struct Window *, __p0, a0, \
		ULONG *, __p1, a1, \
		LONG , __p2, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenWindowTagList(__p0, __p1) \
	LP2(606, struct Window *, OpenWindowTagList, \
		CONST struct NewWindow *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenScreenTagList(__p0, __p1) \
	LP2(612, struct Screen *, OpenScreenTagList, \
		CONST struct NewScreen *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DrawImageState(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6NR(618, DrawImageState, \
		struct RastPort *, __p0, a0, \
		struct Image *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		ULONG , __p4, d2, \
		CONST struct DrawInfo *, __p5, a2, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PointInImage(__p0, __p1) \
	LP2(624, BOOL , PointInImage, \
		ULONG , __p0, d0, \
		struct Image *, __p1, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define EraseImage(__p0, __p1, __p2, __p3) \
	LP4NR(630, EraseImage, \
		struct RastPort *, __p0, a0, \
		struct Image *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewObjectA(__p0, __p1, __p2) \
	LP3(636, APTR , NewObjectA, \
		struct IClass *, __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		CONST struct TagItem *, __p2, a2, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DisposeObject(__p0) \
	LP1NR(642, DisposeObject, \
		APTR , __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetAttrsA(__p0, __p1) \
	LP2(648, ULONG , SetAttrsA, \
		APTR , __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetAttr(__p0, __p1, __p2) \
	LP3(654, ULONG , GetAttr, \
		ULONG , __p0, d0, \
		APTR , __p1, a0, \
		ULONG *, __p2, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetGadgetAttrsA(__p0, __p1, __p2, __p3) \
	LP4(660, ULONG , SetGadgetAttrsA, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		CONST struct TagItem *, __p3, a3, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NextObject(__p0) \
	LP1(666, APTR , NextObject, \
		APTR , __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MakeClass(__p0, __p1, __p2, __p3, __p4) \
	LP5(678, struct IClass *, MakeClass, \
		CONST_STRPTR , __p0, a0, \
		CONST_STRPTR , __p1, a1, \
		CONST struct IClass *, __p2, a2, \
		ULONG , __p3, d0, \
		ULONG , __p4, d1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddClass(__p0) \
	LP1NR(684, AddClass, \
		struct IClass *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetScreenDrawInfo(__p0) \
	LP1(690, struct DrawInfo *, GetScreenDrawInfo, \
		struct Screen *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeScreenDrawInfo(__p0, __p1) \
	LP2NR(696, FreeScreenDrawInfo, \
		struct Screen *, __p0, a0, \
		struct DrawInfo *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ResetMenuStrip(__p0, __p1) \
	LP2(702, BOOL , ResetMenuStrip, \
		struct Window *, __p0, a0, \
		struct Menu *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemoveClass(__p0) \
	LP1NR(708, RemoveClass, \
		struct IClass *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeClass(__p0) \
	LP1(714, BOOL , FreeClass, \
		struct IClass *, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocScreenBuffer(__p0, __p1, __p2) \
	LP3(768, struct ScreenBuffer *, AllocScreenBuffer, \
		struct Screen *, __p0, a0, \
		struct BitMap *, __p1, a1, \
		ULONG , __p2, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeScreenBuffer(__p0, __p1) \
	LP2NR(774, FreeScreenBuffer, \
		struct Screen *, __p0, a0, \
		struct ScreenBuffer *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ChangeScreenBuffer(__p0, __p1) \
	LP2(780, ULONG , ChangeScreenBuffer, \
		struct Screen *, __p0, a0, \
		struct ScreenBuffer *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScreenDepth(__p0, __p1, __p2) \
	LP3NR(786, ScreenDepth, \
		struct Screen *, __p0, a0, \
		ULONG , __p1, d0, \
		APTR , __p2, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScreenPosition(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6NR(792, ScreenPosition, \
		struct Screen *, __p0, a0, \
		ULONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		LONG , __p5, d4, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScrollWindowRaster(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7NR(798, ScrollWindowRaster, \
		struct Window *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		LONG , __p5, d4, \
		LONG , __p6, d5, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LendMenus(__p0, __p1) \
	LP2NR(804, LendMenus, \
		struct Window *, __p0, a0, \
		struct Window *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoGadgetMethodA(__p0, __p1, __p2, __p3) \
	LP4(810, ULONG , DoGadgetMethodA, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		Msg , __p3, a3, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetWindowPointerA(__p0, __p1) \
	LP2NR(816, SetWindowPointerA, \
		struct Window *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TimedDisplayAlert(__p0, __p1, __p2, __p3) \
	LP4(822, BOOL , TimedDisplayAlert, \
		ULONG , __p0, d0, \
		CONST_STRPTR , __p1, a0, \
		ULONG , __p2, d1, \
		ULONG , __p3, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define HelpControl(__p0, __p1) \
	LP2NR(828, HelpControl, \
		struct Window *, __p0, a0, \
		ULONG , __p1, d0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)




#define GetSkinInfoAttrA(__p0, __p1, __p2) \
	LP3(918, ULONG , GetSkinInfoAttrA, \
		struct DrawInfo *, __p0, a0, \
		ULONG , __p1, d0, \
		struct TagItem *, __p2, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDrawInfoAttr(__p0, __p1, __p2) \
	LP3(936, ULONG , GetDrawInfoAttr, \
		struct DrawInfo *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG *, __p2, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WindowAction(__p0, __p1, __p2) \
	LP3NR(942, WindowAction, \
		struct Window *, __p0, a0, \
		ULONG , __p1, d0, \
		struct TagItem *, __p2, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TransparencyControl(__p0, __p1, __p2) \
	LP3(948, BOOL , TransparencyControl, \
		struct Window *, __p0, a0, \
		ULONG , __p1, d0, \
		struct TagItem *, __p2, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScrollWindowRasterNoFill(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7NR(954, ScrollWindowRasterNoFill, \
		struct Window *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		LONG , __p5, d4, \
		LONG , __p6, d5, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define GetMonitorList(__p0) \
	LP1(966, Boopsiobject **, GetMonitorList, \
		struct TagItem *, __p0, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeMonitorList(__p0) \
	LP1NR(972, FreeMonitorList, \
		Boopsiobject **, __p0, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScreenbarControlA(__p0) \
	LP1(978, ULONG , ScreenbarControlA, \
		struct TagItem *, __p0, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)



#define GetMonitorModesList(__p0, __p1) \
	LP2(996, Boopsiobject **, GetMonitorModesList, \
		Boopsiobject *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeMonitorModesList(__p0) \
	LP1NR(1002, FreeMonitorModesList, \
		Boopsiobject **, __p0, a0, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetMonitorMode(__p0, __p1, __p2, __p3, __p4) \
	LP5(1008, Boopsiobject *, GetMonitorMode, \
		CONST_STRPTR , __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		struct TagItem *, __p4, a1, \
		, INTUITION_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define EasyRequest(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	EasyRequestArgs(__p0, __p1, __p2, (CONST APTR )_tags);})

#define BuildEasyRequest(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	BuildEasyRequestArgs(__p0, __p1, __p2, (CONST APTR )_tags);})

#define OpenWindowTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	OpenWindowTagList(__p0, (CONST struct TagItem *)_tags);})

#define OpenScreenTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	OpenScreenTagList(__p0, (CONST struct TagItem *)_tags);})

#define NewObject(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewObjectA(__p0, __p1, (CONST struct TagItem *)_tags);})

#define SetAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetAttrsA(__p0, (CONST struct TagItem *)_tags);})

#define SetGadgetAttrs(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetGadgetAttrsA(__p0, __p1, __p2, (CONST struct TagItem *)_tags);})

#define DoGadgetMethod(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DoGadgetMethodA(__p0, __p1, __p2, (Msg )_tags);})

#define SetWindowPointer(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetWindowPointerA(__p0, (CONST struct TagItem *)_tags);})

#define GetSkinInfoAttr(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetSkinInfoAttrA(__p0, __p1, (struct TagItem *)_tags);})

#define ScreenbarControl(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ScreenbarControlA((struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_INTUITION_H */
