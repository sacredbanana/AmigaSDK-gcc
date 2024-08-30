/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_INTUITION_H
#define _INLINE_INTUITION_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef INTUITION_BASE_NAME
#define INTUITION_BASE_NAME IntuitionBase
#endif /* !INTUITION_BASE_NAME */

#define OpenIntuition() \
      LP0NR(0x1e, OpenIntuition ,\
      , INTUITION_BASE_NAME)

#define Intuition(___iEvent) \
      LP1NR(0x24, Intuition , struct InputEvent *, ___iEvent, a0,\
      , INTUITION_BASE_NAME)

#define AddGadget(___window, ___gadget, ___position) \
      LP3(0x2a, UWORD, AddGadget , struct Window *, ___window, a0, struct Gadget *, ___gadget, a1, ULONG, ___position, d0,\
      , INTUITION_BASE_NAME)

#define ClearDMRequest(___window) \
      LP1(0x30, BOOL, ClearDMRequest , struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define ClearMenuStrip(___window) \
      LP1NR(0x36, ClearMenuStrip , struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define ClearPointer(___window) \
      LP1NR(0x3c, ClearPointer , struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define CloseScreen(___screen) \
      LP1(0x42, BOOL, CloseScreen , struct Screen *, ___screen, a0,\
      , INTUITION_BASE_NAME)

#define CloseWindow(___window) \
      LP1NR(0x48, CloseWindow , struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define CloseWorkBench() \
      LP0(0x4e, LONG, CloseWorkBench ,\
      , INTUITION_BASE_NAME)

#define CurrentTime(___seconds, ___micros) \
      LP2NR(0x54, CurrentTime , ULONG *, ___seconds, a0, ULONG *, ___micros, a1,\
      , INTUITION_BASE_NAME)

#define DisplayAlert(___alertNumber, ___string, ___height) \
      LP3(0x5a, BOOL, DisplayAlert , ULONG, ___alertNumber, d0, CONST_STRPTR, ___string, a0, ULONG, ___height, d1,\
      , INTUITION_BASE_NAME)

#define DisplayBeep(___screen) \
      LP1NR(0x60, DisplayBeep , struct Screen *, ___screen, a0,\
      , INTUITION_BASE_NAME)

#define DoubleClick(___sSeconds, ___sMicros, ___cSeconds, ___cMicros) \
      LP4(0x66, BOOL, DoubleClick , ULONG, ___sSeconds, d0, ULONG, ___sMicros, d1, ULONG, ___cSeconds, d2, ULONG, ___cMicros, d3,\
      , INTUITION_BASE_NAME)

#define DrawBorder(___rp, ___border, ___leftOffset, ___topOffset) \
      LP4NR(0x6c, DrawBorder , struct RastPort *, ___rp, a0, CONST struct Border *, ___border, a1, LONG, ___leftOffset, d0, LONG, ___topOffset, d1,\
      , INTUITION_BASE_NAME)

#define DrawImage(___rp, ___image, ___leftOffset, ___topOffset) \
      LP4NR(0x72, DrawImage , struct RastPort *, ___rp, a0, CONST struct Image *, ___image, a1, LONG, ___leftOffset, d0, LONG, ___topOffset, d1,\
      , INTUITION_BASE_NAME)

#define EndRequest(___requester, ___window) \
      LP2NR(0x78, EndRequest , struct Requester *, ___requester, a0, struct Window *, ___window, a1,\
      , INTUITION_BASE_NAME)

#define GetDefPrefs(___preferences, ___size) \
      LP2(0x7e, struct Preferences *, GetDefPrefs , struct Preferences *, ___preferences, a0, LONG, ___size, d0,\
      , INTUITION_BASE_NAME)

#define GetPrefs(___preferences, ___size) \
      LP2(0x84, struct Preferences *, GetPrefs , struct Preferences *, ___preferences, a0, LONG, ___size, d0,\
      , INTUITION_BASE_NAME)

#define InitRequester(___requester) \
      LP1NR(0x8a, InitRequester , struct Requester *, ___requester, a0,\
      , INTUITION_BASE_NAME)

#define ItemAddress(___menuStrip, ___menuNumber) \
      LP2(0x90, struct MenuItem *, ItemAddress , CONST struct Menu *, ___menuStrip, a0, ULONG, ___menuNumber, d0,\
      , INTUITION_BASE_NAME)

#define ModifyIDCMP(___window, ___flags) \
      LP2(0x96, BOOL, ModifyIDCMP , struct Window *, ___window, a0, ULONG, ___flags, d0,\
      , INTUITION_BASE_NAME)

#define ModifyProp(___gadget, ___window, ___requester, ___flags, ___horizPot, ___vertPot, ___horizBody, ___vertBody) \
      LP8NR(0x9c, ModifyProp , struct Gadget *, ___gadget, a0, struct Window *, ___window, a1, struct Requester *, ___requester, a2, ULONG, ___flags, d0, ULONG, ___horizPot, d1, ULONG, ___vertPot, d2, ULONG, ___horizBody, d3, ULONG, ___vertBody, d4,\
      , INTUITION_BASE_NAME)

#define MoveScreen(___screen, ___dx, ___dy) \
      LP3NR(0xa2, MoveScreen , struct Screen *, ___screen, a0, LONG, ___dx, d0, LONG, ___dy, d1,\
      , INTUITION_BASE_NAME)

#define MoveWindow(___window, ___dx, ___dy) \
      LP3NR(0xa8, MoveWindow , struct Window *, ___window, a0, LONG, ___dx, d0, LONG, ___dy, d1,\
      , INTUITION_BASE_NAME)

#define OffGadget(___gadget, ___window, ___requester) \
      LP3NR(0xae, OffGadget , struct Gadget *, ___gadget, a0, struct Window *, ___window, a1, struct Requester *, ___requester, a2,\
      , INTUITION_BASE_NAME)

#define OffMenu(___window, ___menuNumber) \
      LP2NR(0xb4, OffMenu , struct Window *, ___window, a0, ULONG, ___menuNumber, d0,\
      , INTUITION_BASE_NAME)

#define OnGadget(___gadget, ___window, ___requester) \
      LP3NR(0xba, OnGadget , struct Gadget *, ___gadget, a0, struct Window *, ___window, a1, struct Requester *, ___requester, a2,\
      , INTUITION_BASE_NAME)

#define OnMenu(___window, ___menuNumber) \
      LP2NR(0xc0, OnMenu , struct Window *, ___window, a0, ULONG, ___menuNumber, d0,\
      , INTUITION_BASE_NAME)

#define OpenScreen(___newScreen) \
      LP1(0xc6, struct Screen *, OpenScreen , CONST struct NewScreen *, ___newScreen, a0,\
      , INTUITION_BASE_NAME)

#define OpenWindow(___newWindow) \
      LP1(0xcc, struct Window *, OpenWindow , CONST struct NewWindow *, ___newWindow, a0,\
      , INTUITION_BASE_NAME)

#define OpenWorkBench() \
      LP0(0xd2, ULONG, OpenWorkBench ,\
      , INTUITION_BASE_NAME)

#define PrintIText(___rp, ___iText, ___left, ___top) \
      LP4NR(0xd8, PrintIText , struct RastPort *, ___rp, a0, CONST struct IntuiText *, ___iText, a1, LONG, ___left, d0, LONG, ___top, d1,\
      , INTUITION_BASE_NAME)

#define RefreshGadgets(___gadgets, ___window, ___requester) \
      LP3NR(0xde, RefreshGadgets , struct Gadget *, ___gadgets, a0, struct Window *, ___window, a1, struct Requester *, ___requester, a2,\
      , INTUITION_BASE_NAME)

#define RemoveGadget(___window, ___gadget) \
      LP2(0xe4, UWORD, RemoveGadget , struct Window *, ___window, a0, struct Gadget *, ___gadget, a1,\
      , INTUITION_BASE_NAME)

#define ReportMouse(___flag, ___window) \
      LP2NR(0xea, ReportMouse , LONG, ___flag, d0, struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define Request(___requester, ___window) \
      LP2(0xf0, BOOL, Request , struct Requester *, ___requester, a0, struct Window *, ___window, a1,\
      , INTUITION_BASE_NAME)

#define ScreenToBack(___screen) \
      LP1NR(0xf6, ScreenToBack , struct Screen *, ___screen, a0,\
      , INTUITION_BASE_NAME)

#define ScreenToFront(___screen) \
      LP1NR(0xfc, ScreenToFront , struct Screen *, ___screen, a0,\
      , INTUITION_BASE_NAME)

#define SetDMRequest(___window, ___requester) \
      LP2(0x102, BOOL, SetDMRequest , struct Window *, ___window, a0, struct Requester *, ___requester, a1,\
      , INTUITION_BASE_NAME)

#define SetMenuStrip(___window, ___menu) \
      LP2(0x108, BOOL, SetMenuStrip , struct Window *, ___window, a0, struct Menu *, ___menu, a1,\
      , INTUITION_BASE_NAME)

#define SetPointer(___window, ___pointer, ___height, ___width, ___xOffset, ___yOffset) \
      LP6NR(0x10e, SetPointer , struct Window *, ___window, a0, UWORD *, ___pointer, a1, LONG, ___height, d0, LONG, ___width, d1, LONG, ___xOffset, d2, LONG, ___yOffset, d3,\
      , INTUITION_BASE_NAME)

#define SetWindowTitles(___window, ___windowTitle, ___screenTitle) \
      LP3NR(0x114, SetWindowTitles , struct Window *, ___window, a0, CONST_STRPTR, ___windowTitle, a1, CONST_STRPTR, ___screenTitle, a2,\
      , INTUITION_BASE_NAME)

#define ShowTitle(___screen, ___showIt) \
      LP2NR(0x11a, ShowTitle , struct Screen *, ___screen, a0, LONG, ___showIt, d0,\
      , INTUITION_BASE_NAME)

#define SizeWindow(___window, ___dx, ___dy) \
      LP3NR(0x120, SizeWindow , struct Window *, ___window, a0, LONG, ___dx, d0, LONG, ___dy, d1,\
      , INTUITION_BASE_NAME)

#define ViewAddress() \
      LP0(0x126, struct View *, ViewAddress ,\
      , INTUITION_BASE_NAME)

#define ViewPortAddress(___window) \
      LP1(0x12c, struct ViewPort *, ViewPortAddress , CONST struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define WindowToBack(___window) \
      LP1NR(0x132, WindowToBack , struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define WindowToFront(___window) \
      LP1NR(0x138, WindowToFront , struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define WindowLimits(___window, ___widthMin, ___heightMin, ___widthMax, ___heightMax) \
      LP5(0x13e, BOOL, WindowLimits , struct Window *, ___window, a0, LONG, ___widthMin, d0, LONG, ___heightMin, d1, ULONG, ___widthMax, d2, ULONG, ___heightMax, d3,\
      , INTUITION_BASE_NAME)

#define SetPrefs(___preferences, ___size, ___inform) \
      LP3(0x144, struct Preferences *, SetPrefs , CONST struct Preferences *, ___preferences, a0, LONG, ___size, d0, LONG, ___inform, d1,\
      , INTUITION_BASE_NAME)

#define IntuiTextLength(___iText) \
      LP1(0x14a, LONG, IntuiTextLength , CONST struct IntuiText *, ___iText, a0,\
      , INTUITION_BASE_NAME)

#define WBenchToBack() \
      LP0(0x150, BOOL, WBenchToBack ,\
      , INTUITION_BASE_NAME)

#define WBenchToFront() \
      LP0(0x156, BOOL, WBenchToFront ,\
      , INTUITION_BASE_NAME)

#define AutoRequest(___window, ___body, ___posText, ___negText, ___pFlag, ___nFlag, ___width, ___height) \
      LP8(0x15c, BOOL, AutoRequest , struct Window *, ___window, a0, CONST struct IntuiText *, ___body, a1, CONST struct IntuiText *, ___posText, a2, CONST struct IntuiText *, ___negText, a3, ULONG, ___pFlag, d0, ULONG, ___nFlag, d1, ULONG, ___width, d2, ULONG, ___height, d3,\
      , INTUITION_BASE_NAME)

#define BeginRefresh(___window) \
      LP1NR(0x162, BeginRefresh , struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define BuildSysRequest(___window, ___body, ___posText, ___negText, ___flags, ___width, ___height) \
      LP7(0x168, struct Window *, BuildSysRequest , struct Window *, ___window, a0, CONST struct IntuiText *, ___body, a1, CONST struct IntuiText *, ___posText, a2, CONST struct IntuiText *, ___negText, a3, ULONG, ___flags, d0, ULONG, ___width, d1, ULONG, ___height, d2,\
      , INTUITION_BASE_NAME)

#define EndRefresh(___window, ___complete) \
      LP2NR(0x16e, EndRefresh , struct Window *, ___window, a0, LONG, ___complete, d0,\
      , INTUITION_BASE_NAME)

#define FreeSysRequest(___window) \
      LP1NR(0x174, FreeSysRequest , struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define MakeScreen(___screen) \
      LP1(0x17a, LONG, MakeScreen , struct Screen *, ___screen, a0,\
      , INTUITION_BASE_NAME)

#define RemakeDisplay() \
      LP0(0x180, LONG, RemakeDisplay ,\
      , INTUITION_BASE_NAME)

#define RethinkDisplay() \
      LP0(0x186, LONG, RethinkDisplay ,\
      , INTUITION_BASE_NAME)

#define AllocRemember(___rememberKey, ___size, ___flags) \
      LP3(0x18c, APTR, AllocRemember , struct Remember * *, ___rememberKey, a0, ULONG, ___size, d0, ULONG, ___flags, d1,\
      , INTUITION_BASE_NAME)

#define AlohaWorkbench(___wbport) \
      LP1NR(0x192, AlohaWorkbench , LONG, ___wbport, a0,\
      , INTUITION_BASE_NAME)

#define FreeRemember(___rememberKey, ___reallyForget) \
      LP2NR(0x198, FreeRemember , struct Remember * *, ___rememberKey, a0, LONG, ___reallyForget, d0,\
      , INTUITION_BASE_NAME)

#define LockIBase(___dontknow) \
      LP1(0x19e, ULONG, LockIBase , ULONG, ___dontknow, d0,\
      , INTUITION_BASE_NAME)

#define UnlockIBase(___ibLock) \
      LP1NR(0x1a4, UnlockIBase , ULONG, ___ibLock, a0,\
      , INTUITION_BASE_NAME)

#define GetScreenData(___buffer, ___size, ___type, ___screen) \
      LP4(0x1aa, LONG, GetScreenData , APTR, ___buffer, a0, ULONG, ___size, d0, ULONG, ___type, d1, CONST struct Screen *, ___screen, a1,\
      , INTUITION_BASE_NAME)

#define RefreshGList(___gadgets, ___window, ___requester, ___numGad) \
      LP4NR(0x1b0, RefreshGList , struct Gadget *, ___gadgets, a0, struct Window *, ___window, a1, struct Requester *, ___requester, a2, LONG, ___numGad, d0,\
      , INTUITION_BASE_NAME)

#define AddGList(___window, ___gadget, ___position, ___numGad, ___requester) \
      LP5(0x1b6, UWORD, AddGList , struct Window *, ___window, a0, struct Gadget *, ___gadget, a1, ULONG, ___position, d0, LONG, ___numGad, d1, struct Requester *, ___requester, a2,\
      , INTUITION_BASE_NAME)

#define RemoveGList(___remPtr, ___gadget, ___numGad) \
      LP3(0x1bc, UWORD, RemoveGList , struct Window *, ___remPtr, a0, struct Gadget *, ___gadget, a1, LONG, ___numGad, d0,\
      , INTUITION_BASE_NAME)

#define ActivateWindow(___window) \
      LP1NR(0x1c2, ActivateWindow , struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define RefreshWindowFrame(___window) \
      LP1NR(0x1c8, RefreshWindowFrame , struct Window *, ___window, a0,\
      , INTUITION_BASE_NAME)

#define ActivateGadget(___gadgets, ___window, ___requester) \
      LP3(0x1ce, BOOL, ActivateGadget , struct Gadget *, ___gadgets, a0, struct Window *, ___window, a1, struct Requester *, ___requester, a2,\
      , INTUITION_BASE_NAME)

#define NewModifyProp(___gadget, ___window, ___requester, ___flags, ___horizPot, ___vertPot, ___horizBody, ___vertBody, ___numGad) \
      LP9NR(0x1d4, NewModifyProp , struct Gadget *, ___gadget, a0, struct Window *, ___window, a1, struct Requester *, ___requester, a2, ULONG, ___flags, d0, ULONG, ___horizPot, d1, ULONG, ___vertPot, d2, ULONG, ___horizBody, d3, ULONG, ___vertBody, d4, LONG, ___numGad, d5,\
      , INTUITION_BASE_NAME)

#endif /* !_INLINE_INTUITION_H */
