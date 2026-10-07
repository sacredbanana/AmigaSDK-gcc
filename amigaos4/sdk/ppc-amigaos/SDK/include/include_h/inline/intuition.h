#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_INTUITION_H
#define _INLINE_INTUITION_H

#ifndef CLIB_INTUITION_PROTOS_H
#define CLIB_INTUITION_PROTOS_H
#endif

#ifndef  INTUITION_INTUITIONBASE_H
#include <intuition/intuitionbase.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  INTUITION_CGHOOKS_H
#include <intuition/cghooks.h>
#endif
#ifndef  INTUITION_SGHOOKS_H
#include <intuition/sghooks.h>
#endif
#ifndef  INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef  INTUITION_NOTIFY_H
#include <intuition/notify.h>
#endif

#ifndef INTUITION_BASE_NAME
#define INTUITION_BASE_NAME IntuitionBase
#endif

#define OpenIntuition() ({ \
  register struct Library * const __OpenIntuition__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  __asm volatile ("jsr a6@(-30:W)" \
  : \
  : "r"(__OpenIntuition__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define Intuition(iEvent) ({ \
  struct InputEvent * _Intuition_iEvent = (iEvent); \
  { \
  register struct Library * const __Intuition__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct InputEvent * __Intuition_iEvent __asm("a0") = (_Intuition_iEvent); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__Intuition__bn), "r"(__Intuition_iEvent) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddGadget(window, gadget, position) ({ \
  struct Window * _AddGadget_window = (window); \
  struct Gadget * _AddGadget_gadget = (gadget); \
  ULONG _AddGadget_position = (position); \
  UWORD _AddGadget__re = \
  ({ \
  register struct Library * const __AddGadget__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register UWORD __AddGadget__re __asm("d0"); \
  register struct Window * __AddGadget_window __asm("a0") = (_AddGadget_window); \
  register struct Gadget * __AddGadget_gadget __asm("a1") = (_AddGadget_gadget); \
  register ULONG __AddGadget_position __asm("d0") = (_AddGadget_position); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__AddGadget__re) \
  : "r"(__AddGadget__bn), "r"(__AddGadget_window), "r"(__AddGadget_gadget), "r"(__AddGadget_position) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddGadget__re; \
  }); \
  _AddGadget__re; \
})

#define ClearDMRequest(window) ({ \
  struct Window * _ClearDMRequest_window = (window); \
  BOOL _ClearDMRequest__re = \
  ({ \
  register struct Library * const __ClearDMRequest__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __ClearDMRequest__re __asm("d0"); \
  register struct Window * __ClearDMRequest_window __asm("a0") = (_ClearDMRequest_window); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__ClearDMRequest__re) \
  : "r"(__ClearDMRequest__bn), "r"(__ClearDMRequest_window) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ClearDMRequest__re; \
  }); \
  _ClearDMRequest__re; \
})

#define ClearMenuStrip(window) ({ \
  struct Window * _ClearMenuStrip_window = (window); \
  { \
  register struct Library * const __ClearMenuStrip__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __ClearMenuStrip_window __asm("a0") = (_ClearMenuStrip_window); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__ClearMenuStrip__bn), "r"(__ClearMenuStrip_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ClearPointer(window) ({ \
  struct Window * _ClearPointer_window = (window); \
  { \
  register struct Library * const __ClearPointer__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __ClearPointer_window __asm("a0") = (_ClearPointer_window); \
  __asm volatile ("jsr a6@(-60:W)" \
  : \
  : "r"(__ClearPointer__bn), "r"(__ClearPointer_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CloseScreen(screen) ({ \
  struct Screen * _CloseScreen_screen = (screen); \
  BOOL _CloseScreen__re = \
  ({ \
  register struct Library * const __CloseScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __CloseScreen__re __asm("d0"); \
  register struct Screen * __CloseScreen_screen __asm("a0") = (_CloseScreen_screen); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__CloseScreen__re) \
  : "r"(__CloseScreen__bn), "r"(__CloseScreen_screen) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CloseScreen__re; \
  }); \
  _CloseScreen__re; \
})

#define CloseWindow(window) ({ \
  struct Window * _CloseWindow_window = (window); \
  { \
  register struct Library * const __CloseWindow__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __CloseWindow_window __asm("a0") = (_CloseWindow_window); \
  __asm volatile ("jsr a6@(-72:W)" \
  : \
  : "r"(__CloseWindow__bn), "r"(__CloseWindow_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CloseWorkBench() ({ \
  LONG _CloseWorkBench__re = \
  ({ \
  register struct Library * const __CloseWorkBench__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __CloseWorkBench__re __asm("d0"); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__CloseWorkBench__re) \
  : "r"(__CloseWorkBench__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CloseWorkBench__re; \
  }); \
  _CloseWorkBench__re; \
})

#define CurrentTime(seconds, micros) ({ \
  ULONG * _CurrentTime_seconds = (seconds); \
  ULONG * _CurrentTime_micros = (micros); \
  { \
  register struct Library * const __CurrentTime__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG * __CurrentTime_seconds __asm("a0") = (_CurrentTime_seconds); \
  register ULONG * __CurrentTime_micros __asm("a1") = (_CurrentTime_micros); \
  __asm volatile ("jsr a6@(-84:W)" \
  : \
  : "r"(__CurrentTime__bn), "r"(__CurrentTime_seconds), "r"(__CurrentTime_micros) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DisplayAlert(alertNumber, string, height) ({ \
  ULONG _DisplayAlert_alertNumber = (alertNumber); \
  CONST_STRPTR _DisplayAlert_string = (string); \
  ULONG _DisplayAlert_height = (height); \
  BOOL _DisplayAlert__re = \
  ({ \
  register struct Library * const __DisplayAlert__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __DisplayAlert__re __asm("d0"); \
  register ULONG __DisplayAlert_alertNumber __asm("d0") = (_DisplayAlert_alertNumber); \
  register CONST_STRPTR __DisplayAlert_string __asm("a0") = (_DisplayAlert_string); \
  register ULONG __DisplayAlert_height __asm("d1") = (_DisplayAlert_height); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__DisplayAlert__re) \
  : "r"(__DisplayAlert__bn), "r"(__DisplayAlert_alertNumber), "r"(__DisplayAlert_string), "r"(__DisplayAlert_height) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DisplayAlert__re; \
  }); \
  _DisplayAlert__re; \
})

#define DisplayBeep(screen) ({ \
  struct Screen * _DisplayBeep_screen = (screen); \
  { \
  register struct Library * const __DisplayBeep__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __DisplayBeep_screen __asm("a0") = (_DisplayBeep_screen); \
  __asm volatile ("jsr a6@(-96:W)" \
  : \
  : "r"(__DisplayBeep__bn), "r"(__DisplayBeep_screen) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DoubleClick(sSeconds, sMicros, cSeconds, cMicros) ({ \
  ULONG _DoubleClick_sSeconds = (sSeconds); \
  ULONG _DoubleClick_sMicros = (sMicros); \
  ULONG _DoubleClick_cSeconds = (cSeconds); \
  ULONG _DoubleClick_cMicros = (cMicros); \
  BOOL _DoubleClick__re = \
  ({ \
  register struct Library * const __DoubleClick__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __DoubleClick__re __asm("d0"); \
  register ULONG __DoubleClick_sSeconds __asm("d0") = (_DoubleClick_sSeconds); \
  register ULONG __DoubleClick_sMicros __asm("d1") = (_DoubleClick_sMicros); \
  register ULONG __DoubleClick_cSeconds __asm("d2") = (_DoubleClick_cSeconds); \
  register ULONG __DoubleClick_cMicros __asm("d3") = (_DoubleClick_cMicros); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__DoubleClick__re) \
  : "r"(__DoubleClick__bn), "r"(__DoubleClick_sSeconds), "r"(__DoubleClick_sMicros), "r"(__DoubleClick_cSeconds), "r"(__DoubleClick_cMicros) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DoubleClick__re; \
  }); \
  _DoubleClick__re; \
})

#define DrawBorder(rp, border, leftOffset, topOffset) ({ \
  struct RastPort * _DrawBorder_rp = (rp); \
  const struct Border * _DrawBorder_border = (border); \
  LONG _DrawBorder_leftOffset = (leftOffset); \
  LONG _DrawBorder_topOffset = (topOffset); \
  { \
  register struct Library * const __DrawBorder__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __DrawBorder_rp __asm("a0") = (_DrawBorder_rp); \
  register const struct Border * __DrawBorder_border __asm("a1") = (_DrawBorder_border); \
  register LONG __DrawBorder_leftOffset __asm("d0") = (_DrawBorder_leftOffset); \
  register LONG __DrawBorder_topOffset __asm("d1") = (_DrawBorder_topOffset); \
  __asm volatile ("jsr a6@(-108:W)" \
  : \
  : "r"(__DrawBorder__bn), "r"(__DrawBorder_rp), "r"(__DrawBorder_border), "r"(__DrawBorder_leftOffset), "r"(__DrawBorder_topOffset) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DrawImage(rp, image, leftOffset, topOffset) ({ \
  struct RastPort * _DrawImage_rp = (rp); \
  struct Image * _DrawImage_image = (image); \
  LONG _DrawImage_leftOffset = (leftOffset); \
  LONG _DrawImage_topOffset = (topOffset); \
  { \
  register struct Library * const __DrawImage__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __DrawImage_rp __asm("a0") = (_DrawImage_rp); \
  register struct Image * __DrawImage_image __asm("a1") = (_DrawImage_image); \
  register LONG __DrawImage_leftOffset __asm("d0") = (_DrawImage_leftOffset); \
  register LONG __DrawImage_topOffset __asm("d1") = (_DrawImage_topOffset); \
  __asm volatile ("jsr a6@(-114:W)" \
  : \
  : "r"(__DrawImage__bn), "r"(__DrawImage_rp), "r"(__DrawImage_image), "r"(__DrawImage_leftOffset), "r"(__DrawImage_topOffset) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define EndRequest(requester, window) ({ \
  struct Requester * _EndRequest_requester = (requester); \
  struct Window * _EndRequest_window = (window); \
  { \
  register struct Library * const __EndRequest__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Requester * __EndRequest_requester __asm("a0") = (_EndRequest_requester); \
  register struct Window * __EndRequest_window __asm("a1") = (_EndRequest_window); \
  __asm volatile ("jsr a6@(-120:W)" \
  : \
  : "r"(__EndRequest__bn), "r"(__EndRequest_requester), "r"(__EndRequest_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetDefPrefs(preferences, size) ({ \
  struct Preferences * _GetDefPrefs_preferences = (preferences); \
  LONG _GetDefPrefs_size = (size); \
  struct Preferences * _GetDefPrefs__re = \
  ({ \
  register struct Library * const __GetDefPrefs__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Preferences * __GetDefPrefs__re __asm("d0"); \
  register struct Preferences * __GetDefPrefs_preferences __asm("a0") = (_GetDefPrefs_preferences); \
  register LONG __GetDefPrefs_size __asm("d0") = (_GetDefPrefs_size); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__GetDefPrefs__re) \
  : "r"(__GetDefPrefs__bn), "r"(__GetDefPrefs_preferences), "r"(__GetDefPrefs_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetDefPrefs__re; \
  }); \
  _GetDefPrefs__re; \
})

#define GetPrefs(preferences, size) ({ \
  struct Preferences * _GetPrefs_preferences = (preferences); \
  LONG _GetPrefs_size = (size); \
  struct Preferences * _GetPrefs__re = \
  ({ \
  register struct Library * const __GetPrefs__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Preferences * __GetPrefs__re __asm("d0"); \
  register struct Preferences * __GetPrefs_preferences __asm("a0") = (_GetPrefs_preferences); \
  register LONG __GetPrefs_size __asm("d0") = (_GetPrefs_size); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__GetPrefs__re) \
  : "r"(__GetPrefs__bn), "r"(__GetPrefs_preferences), "r"(__GetPrefs_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetPrefs__re; \
  }); \
  _GetPrefs__re; \
})

#define InitRequester(requester) ({ \
  struct Requester * _InitRequester_requester = (requester); \
  { \
  register struct Library * const __InitRequester__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Requester * __InitRequester_requester __asm("a0") = (_InitRequester_requester); \
  __asm volatile ("jsr a6@(-138:W)" \
  : \
  : "r"(__InitRequester__bn), "r"(__InitRequester_requester) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ItemAddress(menuStrip, menuNumber) ({ \
  const struct Menu * _ItemAddress_menuStrip = (menuStrip); \
  ULONG _ItemAddress_menuNumber = (menuNumber); \
  struct MenuItem * _ItemAddress__re = \
  ({ \
  register struct Library * const __ItemAddress__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct MenuItem * __ItemAddress__re __asm("d0"); \
  register const struct Menu * __ItemAddress_menuStrip __asm("a0") = (_ItemAddress_menuStrip); \
  register ULONG __ItemAddress_menuNumber __asm("d0") = (_ItemAddress_menuNumber); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__ItemAddress__re) \
  : "r"(__ItemAddress__bn), "r"(__ItemAddress_menuStrip), "r"(__ItemAddress_menuNumber) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ItemAddress__re; \
  }); \
  _ItemAddress__re; \
})

#define ModifyIDCMP(window, flags) ({ \
  struct Window * _ModifyIDCMP_window = (window); \
  ULONG _ModifyIDCMP_flags = (flags); \
  BOOL _ModifyIDCMP__re = \
  ({ \
  register struct Library * const __ModifyIDCMP__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __ModifyIDCMP__re __asm("d0"); \
  register struct Window * __ModifyIDCMP_window __asm("a0") = (_ModifyIDCMP_window); \
  register ULONG __ModifyIDCMP_flags __asm("d0") = (_ModifyIDCMP_flags); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__ModifyIDCMP__re) \
  : "r"(__ModifyIDCMP__bn), "r"(__ModifyIDCMP_window), "r"(__ModifyIDCMP_flags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ModifyIDCMP__re; \
  }); \
  _ModifyIDCMP__re; \
})

#define ModifyProp(gadget, window, requester, flags, horizPot, vertPot, horizBody, vertBody) ({ \
  struct Gadget * _ModifyProp_gadget = (gadget); \
  struct Window * _ModifyProp_window = (window); \
  struct Requester * _ModifyProp_requester = (requester); \
  ULONG _ModifyProp_flags = (flags); \
  ULONG _ModifyProp_horizPot = (horizPot); \
  ULONG _ModifyProp_vertPot = (vertPot); \
  ULONG _ModifyProp_horizBody = (horizBody); \
  ULONG _ModifyProp_vertBody = (vertBody); \
  { \
  register struct Library * const __ModifyProp__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Gadget * __ModifyProp_gadget __asm("a0") = (_ModifyProp_gadget); \
  register struct Window * __ModifyProp_window __asm("a1") = (_ModifyProp_window); \
  register struct Requester * __ModifyProp_requester __asm("a2") = (_ModifyProp_requester); \
  register ULONG __ModifyProp_flags __asm("d0") = (_ModifyProp_flags); \
  register ULONG __ModifyProp_horizPot __asm("d1") = (_ModifyProp_horizPot); \
  register ULONG __ModifyProp_vertPot __asm("d2") = (_ModifyProp_vertPot); \
  register ULONG __ModifyProp_horizBody __asm("d3") = (_ModifyProp_horizBody); \
  register ULONG __ModifyProp_vertBody __asm("d4") = (_ModifyProp_vertBody); \
  __asm volatile ("jsr a6@(-156:W)" \
  : \
  : "r"(__ModifyProp__bn), "r"(__ModifyProp_gadget), "r"(__ModifyProp_window), "r"(__ModifyProp_requester), "r"(__ModifyProp_flags), "r"(__ModifyProp_horizPot), "r"(__ModifyProp_vertPot), "r"(__ModifyProp_horizBody), "r"(__ModifyProp_vertBody) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define MoveScreen(screen, dx, dy) ({ \
  struct Screen * _MoveScreen_screen = (screen); \
  LONG _MoveScreen_dx = (dx); \
  LONG _MoveScreen_dy = (dy); \
  { \
  register struct Library * const __MoveScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __MoveScreen_screen __asm("a0") = (_MoveScreen_screen); \
  register LONG __MoveScreen_dx __asm("d0") = (_MoveScreen_dx); \
  register LONG __MoveScreen_dy __asm("d1") = (_MoveScreen_dy); \
  __asm volatile ("jsr a6@(-162:W)" \
  : \
  : "r"(__MoveScreen__bn), "r"(__MoveScreen_screen), "r"(__MoveScreen_dx), "r"(__MoveScreen_dy) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define MoveWindow(window, dx, dy) ({ \
  struct Window * _MoveWindow_window = (window); \
  LONG _MoveWindow_dx = (dx); \
  LONG _MoveWindow_dy = (dy); \
  { \
  register struct Library * const __MoveWindow__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __MoveWindow_window __asm("a0") = (_MoveWindow_window); \
  register LONG __MoveWindow_dx __asm("d0") = (_MoveWindow_dx); \
  register LONG __MoveWindow_dy __asm("d1") = (_MoveWindow_dy); \
  __asm volatile ("jsr a6@(-168:W)" \
  : \
  : "r"(__MoveWindow__bn), "r"(__MoveWindow_window), "r"(__MoveWindow_dx), "r"(__MoveWindow_dy) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OffGadget(gadget, window, requester) ({ \
  struct Gadget * _OffGadget_gadget = (gadget); \
  struct Window * _OffGadget_window = (window); \
  struct Requester * _OffGadget_requester = (requester); \
  { \
  register struct Library * const __OffGadget__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Gadget * __OffGadget_gadget __asm("a0") = (_OffGadget_gadget); \
  register struct Window * __OffGadget_window __asm("a1") = (_OffGadget_window); \
  register struct Requester * __OffGadget_requester __asm("a2") = (_OffGadget_requester); \
  __asm volatile ("jsr a6@(-174:W)" \
  : \
  : "r"(__OffGadget__bn), "r"(__OffGadget_gadget), "r"(__OffGadget_window), "r"(__OffGadget_requester) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OffMenu(window, menuNumber) ({ \
  struct Window * _OffMenu_window = (window); \
  ULONG _OffMenu_menuNumber = (menuNumber); \
  { \
  register struct Library * const __OffMenu__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __OffMenu_window __asm("a0") = (_OffMenu_window); \
  register ULONG __OffMenu_menuNumber __asm("d0") = (_OffMenu_menuNumber); \
  __asm volatile ("jsr a6@(-180:W)" \
  : \
  : "r"(__OffMenu__bn), "r"(__OffMenu_window), "r"(__OffMenu_menuNumber) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OnGadget(gadget, window, requester) ({ \
  struct Gadget * _OnGadget_gadget = (gadget); \
  struct Window * _OnGadget_window = (window); \
  struct Requester * _OnGadget_requester = (requester); \
  { \
  register struct Library * const __OnGadget__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Gadget * __OnGadget_gadget __asm("a0") = (_OnGadget_gadget); \
  register struct Window * __OnGadget_window __asm("a1") = (_OnGadget_window); \
  register struct Requester * __OnGadget_requester __asm("a2") = (_OnGadget_requester); \
  __asm volatile ("jsr a6@(-186:W)" \
  : \
  : "r"(__OnGadget__bn), "r"(__OnGadget_gadget), "r"(__OnGadget_window), "r"(__OnGadget_requester) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OnMenu(window, menuNumber) ({ \
  struct Window * _OnMenu_window = (window); \
  ULONG _OnMenu_menuNumber = (menuNumber); \
  { \
  register struct Library * const __OnMenu__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __OnMenu_window __asm("a0") = (_OnMenu_window); \
  register ULONG __OnMenu_menuNumber __asm("d0") = (_OnMenu_menuNumber); \
  __asm volatile ("jsr a6@(-192:W)" \
  : \
  : "r"(__OnMenu__bn), "r"(__OnMenu_window), "r"(__OnMenu_menuNumber) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OpenScreen(newScreen) ({ \
  const struct NewScreen * _OpenScreen_newScreen = (newScreen); \
  struct Screen * _OpenScreen__re = \
  ({ \
  register struct Library * const __OpenScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __OpenScreen__re __asm("d0"); \
  register const struct NewScreen * __OpenScreen_newScreen __asm("a0") = (_OpenScreen_newScreen); \
  __asm volatile ("jsr a6@(-198:W)" \
  : "=r"(__OpenScreen__re) \
  : "r"(__OpenScreen__bn), "r"(__OpenScreen_newScreen) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenScreen__re; \
  }); \
  _OpenScreen__re; \
})

#define OpenWindow(newWindow) ({ \
  const struct NewWindow * _OpenWindow_newWindow = (newWindow); \
  struct Window * _OpenWindow__re = \
  ({ \
  register struct Library * const __OpenWindow__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __OpenWindow__re __asm("d0"); \
  register const struct NewWindow * __OpenWindow_newWindow __asm("a0") = (_OpenWindow_newWindow); \
  __asm volatile ("jsr a6@(-204:W)" \
  : "=r"(__OpenWindow__re) \
  : "r"(__OpenWindow__bn), "r"(__OpenWindow_newWindow) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenWindow__re; \
  }); \
  _OpenWindow__re; \
})

#define OpenWorkBench() ({ \
  ULONG _OpenWorkBench__re = \
  ({ \
  register struct Library * const __OpenWorkBench__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __OpenWorkBench__re __asm("d0"); \
  __asm volatile ("jsr a6@(-210:W)" \
  : "=r"(__OpenWorkBench__re) \
  : "r"(__OpenWorkBench__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenWorkBench__re; \
  }); \
  _OpenWorkBench__re; \
})

#define PrintIText(rp, iText, left, top) ({ \
  struct RastPort * _PrintIText_rp = (rp); \
  const struct IntuiText * _PrintIText_iText = (iText); \
  LONG _PrintIText_left = (left); \
  LONG _PrintIText_top = (top); \
  { \
  register struct Library * const __PrintIText__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __PrintIText_rp __asm("a0") = (_PrintIText_rp); \
  register const struct IntuiText * __PrintIText_iText __asm("a1") = (_PrintIText_iText); \
  register LONG __PrintIText_left __asm("d0") = (_PrintIText_left); \
  register LONG __PrintIText_top __asm("d1") = (_PrintIText_top); \
  __asm volatile ("jsr a6@(-216:W)" \
  : \
  : "r"(__PrintIText__bn), "r"(__PrintIText_rp), "r"(__PrintIText_iText), "r"(__PrintIText_left), "r"(__PrintIText_top) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RefreshGadgets(gadgets, window, requester) ({ \
  struct Gadget * _RefreshGadgets_gadgets = (gadgets); \
  struct Window * _RefreshGadgets_window = (window); \
  struct Requester * _RefreshGadgets_requester = (requester); \
  { \
  register struct Library * const __RefreshGadgets__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Gadget * __RefreshGadgets_gadgets __asm("a0") = (_RefreshGadgets_gadgets); \
  register struct Window * __RefreshGadgets_window __asm("a1") = (_RefreshGadgets_window); \
  register struct Requester * __RefreshGadgets_requester __asm("a2") = (_RefreshGadgets_requester); \
  __asm volatile ("jsr a6@(-222:W)" \
  : \
  : "r"(__RefreshGadgets__bn), "r"(__RefreshGadgets_gadgets), "r"(__RefreshGadgets_window), "r"(__RefreshGadgets_requester) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemoveGadget(window, gadget) ({ \
  struct Window * _RemoveGadget_window = (window); \
  struct Gadget * _RemoveGadget_gadget = (gadget); \
  UWORD _RemoveGadget__re = \
  ({ \
  register struct Library * const __RemoveGadget__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register UWORD __RemoveGadget__re __asm("d0"); \
  register struct Window * __RemoveGadget_window __asm("a0") = (_RemoveGadget_window); \
  register struct Gadget * __RemoveGadget_gadget __asm("a1") = (_RemoveGadget_gadget); \
  __asm volatile ("jsr a6@(-228:W)" \
  : "=r"(__RemoveGadget__re) \
  : "r"(__RemoveGadget__bn), "r"(__RemoveGadget_window), "r"(__RemoveGadget_gadget) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoveGadget__re; \
  }); \
  _RemoveGadget__re; \
})

#define ReportMouse(flag, window) ({ \
  LONG _ReportMouse_flag = (flag); \
  struct Window * _ReportMouse_window = (window); \
  { \
  register struct Library * const __ReportMouse__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __ReportMouse_flag __asm("d0") = (_ReportMouse_flag); \
  register struct Window * __ReportMouse_window __asm("a0") = (_ReportMouse_window); \
  __asm volatile ("jsr a6@(-234:W)" \
  : \
  : "r"(__ReportMouse__bn), "r"(__ReportMouse_flag), "r"(__ReportMouse_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ReportMouse1(flag, window) ReportMouse((flag), (window))

#define Request(requester, window) ({ \
  struct Requester * _Request_requester = (requester); \
  struct Window * _Request_window = (window); \
  BOOL _Request__re = \
  ({ \
  register struct Library * const __Request__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __Request__re __asm("d0"); \
  register struct Requester * __Request_requester __asm("a0") = (_Request_requester); \
  register struct Window * __Request_window __asm("a1") = (_Request_window); \
  __asm volatile ("jsr a6@(-240:W)" \
  : "=r"(__Request__re) \
  : "r"(__Request__bn), "r"(__Request_requester), "r"(__Request_window) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Request__re; \
  }); \
  _Request__re; \
})

#define ScreenToBack(screen) ({ \
  struct Screen * _ScreenToBack_screen = (screen); \
  { \
  register struct Library * const __ScreenToBack__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __ScreenToBack_screen __asm("a0") = (_ScreenToBack_screen); \
  __asm volatile ("jsr a6@(-246:W)" \
  : \
  : "r"(__ScreenToBack__bn), "r"(__ScreenToBack_screen) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ScreenToFront(screen) ({ \
  struct Screen * _ScreenToFront_screen = (screen); \
  { \
  register struct Library * const __ScreenToFront__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __ScreenToFront_screen __asm("a0") = (_ScreenToFront_screen); \
  __asm volatile ("jsr a6@(-252:W)" \
  : \
  : "r"(__ScreenToFront__bn), "r"(__ScreenToFront_screen) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetDMRequest(window, requester) ({ \
  struct Window * _SetDMRequest_window = (window); \
  struct Requester * _SetDMRequest_requester = (requester); \
  BOOL _SetDMRequest__re = \
  ({ \
  register struct Library * const __SetDMRequest__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __SetDMRequest__re __asm("d0"); \
  register struct Window * __SetDMRequest_window __asm("a0") = (_SetDMRequest_window); \
  register struct Requester * __SetDMRequest_requester __asm("a1") = (_SetDMRequest_requester); \
  __asm volatile ("jsr a6@(-258:W)" \
  : "=r"(__SetDMRequest__re) \
  : "r"(__SetDMRequest__bn), "r"(__SetDMRequest_window), "r"(__SetDMRequest_requester) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetDMRequest__re; \
  }); \
  _SetDMRequest__re; \
})

#define SetMenuStrip(window, menu) ({ \
  struct Window * _SetMenuStrip_window = (window); \
  struct Menu * _SetMenuStrip_menu = (menu); \
  BOOL _SetMenuStrip__re = \
  ({ \
  register struct Library * const __SetMenuStrip__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __SetMenuStrip__re __asm("d0"); \
  register struct Window * __SetMenuStrip_window __asm("a0") = (_SetMenuStrip_window); \
  register struct Menu * __SetMenuStrip_menu __asm("a1") = (_SetMenuStrip_menu); \
  __asm volatile ("jsr a6@(-264:W)" \
  : "=r"(__SetMenuStrip__re) \
  : "r"(__SetMenuStrip__bn), "r"(__SetMenuStrip_window), "r"(__SetMenuStrip_menu) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetMenuStrip__re; \
  }); \
  _SetMenuStrip__re; \
})

#define SetPointer(window, pointer, height, width, xOffset, yOffset) ({ \
  struct Window * _SetPointer_window = (window); \
  UWORD * _SetPointer_pointer = (pointer); \
  LONG _SetPointer_height = (height); \
  LONG _SetPointer_width = (width); \
  LONG _SetPointer_xOffset = (xOffset); \
  LONG _SetPointer_yOffset = (yOffset); \
  { \
  register struct Library * const __SetPointer__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __SetPointer_window __asm("a0") = (_SetPointer_window); \
  register UWORD * __SetPointer_pointer __asm("a1") = (_SetPointer_pointer); \
  register LONG __SetPointer_height __asm("d0") = (_SetPointer_height); \
  register LONG __SetPointer_width __asm("d1") = (_SetPointer_width); \
  register LONG __SetPointer_xOffset __asm("d2") = (_SetPointer_xOffset); \
  register LONG __SetPointer_yOffset __asm("d3") = (_SetPointer_yOffset); \
  __asm volatile ("jsr a6@(-270:W)" \
  : \
  : "r"(__SetPointer__bn), "r"(__SetPointer_window), "r"(__SetPointer_pointer), "r"(__SetPointer_height), "r"(__SetPointer_width), "r"(__SetPointer_xOffset), "r"(__SetPointer_yOffset) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetWindowTitles(window, windowTitle, screenTitle) ({ \
  struct Window * _SetWindowTitles_window = (window); \
  CONST_STRPTR _SetWindowTitles_windowTitle = (windowTitle); \
  CONST_STRPTR _SetWindowTitles_screenTitle = (screenTitle); \
  { \
  register struct Library * const __SetWindowTitles__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __SetWindowTitles_window __asm("a0") = (_SetWindowTitles_window); \
  register CONST_STRPTR __SetWindowTitles_windowTitle __asm("a1") = (_SetWindowTitles_windowTitle); \
  register CONST_STRPTR __SetWindowTitles_screenTitle __asm("a2") = (_SetWindowTitles_screenTitle); \
  __asm volatile ("jsr a6@(-276:W)" \
  : \
  : "r"(__SetWindowTitles__bn), "r"(__SetWindowTitles_window), "r"(__SetWindowTitles_windowTitle), "r"(__SetWindowTitles_screenTitle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ShowTitle(screen, showIt) ({ \
  struct Screen * _ShowTitle_screen = (screen); \
  LONG _ShowTitle_showIt = (showIt); \
  { \
  register struct Library * const __ShowTitle__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __ShowTitle_screen __asm("a0") = (_ShowTitle_screen); \
  register LONG __ShowTitle_showIt __asm("d0") = (_ShowTitle_showIt); \
  __asm volatile ("jsr a6@(-282:W)" \
  : \
  : "r"(__ShowTitle__bn), "r"(__ShowTitle_screen), "r"(__ShowTitle_showIt) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SizeWindow(window, dx, dy) ({ \
  struct Window * _SizeWindow_window = (window); \
  LONG _SizeWindow_dx = (dx); \
  LONG _SizeWindow_dy = (dy); \
  { \
  register struct Library * const __SizeWindow__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __SizeWindow_window __asm("a0") = (_SizeWindow_window); \
  register LONG __SizeWindow_dx __asm("d0") = (_SizeWindow_dx); \
  register LONG __SizeWindow_dy __asm("d1") = (_SizeWindow_dy); \
  __asm volatile ("jsr a6@(-288:W)" \
  : \
  : "r"(__SizeWindow__bn), "r"(__SizeWindow_window), "r"(__SizeWindow_dx), "r"(__SizeWindow_dy) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ViewAddress() ({ \
  struct View * _ViewAddress__re = \
  ({ \
  register struct Library * const __ViewAddress__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct View * __ViewAddress__re __asm("d0"); \
  __asm volatile ("jsr a6@(-294:W)" \
  : "=r"(__ViewAddress__re) \
  : "r"(__ViewAddress__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ViewAddress__re; \
  }); \
  _ViewAddress__re; \
})

#define ViewPortAddress(window) ({ \
  const struct Window * _ViewPortAddress_window = (window); \
  struct ViewPort * _ViewPortAddress__re = \
  ({ \
  register struct Library * const __ViewPortAddress__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct ViewPort * __ViewPortAddress__re __asm("d0"); \
  register const struct Window * __ViewPortAddress_window __asm("a0") = (_ViewPortAddress_window); \
  __asm volatile ("jsr a6@(-300:W)" \
  : "=r"(__ViewPortAddress__re) \
  : "r"(__ViewPortAddress__bn), "r"(__ViewPortAddress_window) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ViewPortAddress__re; \
  }); \
  _ViewPortAddress__re; \
})

#define WindowToBack(window) ({ \
  struct Window * _WindowToBack_window = (window); \
  { \
  register struct Library * const __WindowToBack__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __WindowToBack_window __asm("a0") = (_WindowToBack_window); \
  __asm volatile ("jsr a6@(-306:W)" \
  : \
  : "r"(__WindowToBack__bn), "r"(__WindowToBack_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define WindowToFront(window) ({ \
  struct Window * _WindowToFront_window = (window); \
  { \
  register struct Library * const __WindowToFront__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __WindowToFront_window __asm("a0") = (_WindowToFront_window); \
  __asm volatile ("jsr a6@(-312:W)" \
  : \
  : "r"(__WindowToFront__bn), "r"(__WindowToFront_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define WindowLimits(window, widthMin, heightMin, widthMax, heightMax) ({ \
  struct Window * _WindowLimits_window = (window); \
  LONG _WindowLimits_widthMin = (widthMin); \
  LONG _WindowLimits_heightMin = (heightMin); \
  ULONG _WindowLimits_widthMax = (widthMax); \
  ULONG _WindowLimits_heightMax = (heightMax); \
  BOOL _WindowLimits__re = \
  ({ \
  register struct Library * const __WindowLimits__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __WindowLimits__re __asm("d0"); \
  register struct Window * __WindowLimits_window __asm("a0") = (_WindowLimits_window); \
  register LONG __WindowLimits_widthMin __asm("d0") = (_WindowLimits_widthMin); \
  register LONG __WindowLimits_heightMin __asm("d1") = (_WindowLimits_heightMin); \
  register ULONG __WindowLimits_widthMax __asm("d2") = (_WindowLimits_widthMax); \
  register ULONG __WindowLimits_heightMax __asm("d3") = (_WindowLimits_heightMax); \
  __asm volatile ("jsr a6@(-318:W)" \
  : "=r"(__WindowLimits__re) \
  : "r"(__WindowLimits__bn), "r"(__WindowLimits_window), "r"(__WindowLimits_widthMin), "r"(__WindowLimits_heightMin), "r"(__WindowLimits_widthMax), "r"(__WindowLimits_heightMax) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WindowLimits__re; \
  }); \
  _WindowLimits__re; \
})

#define SetPrefs(preferences, size, inform) ({ \
  const struct Preferences * _SetPrefs_preferences = (preferences); \
  LONG _SetPrefs_size = (size); \
  LONG _SetPrefs_inform = (inform); \
  struct Preferences  * _SetPrefs__re = \
  ({ \
  register struct Library * const __SetPrefs__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Preferences  * __SetPrefs__re __asm("d0"); \
  register const struct Preferences * __SetPrefs_preferences __asm("a0") = (_SetPrefs_preferences); \
  register LONG __SetPrefs_size __asm("d0") = (_SetPrefs_size); \
  register LONG __SetPrefs_inform __asm("d1") = (_SetPrefs_inform); \
  __asm volatile ("jsr a6@(-324:W)" \
  : "=r"(__SetPrefs__re) \
  : "r"(__SetPrefs__bn), "r"(__SetPrefs_preferences), "r"(__SetPrefs_size), "r"(__SetPrefs_inform) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetPrefs__re; \
  }); \
  _SetPrefs__re; \
})

#define IntuiTextLength(iText) ({ \
  const struct IntuiText * _IntuiTextLength_iText = (iText); \
  LONG _IntuiTextLength__re = \
  ({ \
  register struct Library * const __IntuiTextLength__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __IntuiTextLength__re __asm("d0"); \
  register const struct IntuiText * __IntuiTextLength_iText __asm("a0") = (_IntuiTextLength_iText); \
  __asm volatile ("jsr a6@(-330:W)" \
  : "=r"(__IntuiTextLength__re) \
  : "r"(__IntuiTextLength__bn), "r"(__IntuiTextLength_iText) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IntuiTextLength__re; \
  }); \
  _IntuiTextLength__re; \
})

#define WBenchToBack() ({ \
  BOOL _WBenchToBack__re = \
  ({ \
  register struct Library * const __WBenchToBack__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __WBenchToBack__re __asm("d0"); \
  __asm volatile ("jsr a6@(-336:W)" \
  : "=r"(__WBenchToBack__re) \
  : "r"(__WBenchToBack__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WBenchToBack__re; \
  }); \
  _WBenchToBack__re; \
})

#define WBenchToFront() ({ \
  BOOL _WBenchToFront__re = \
  ({ \
  register struct Library * const __WBenchToFront__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __WBenchToFront__re __asm("d0"); \
  __asm volatile ("jsr a6@(-342:W)" \
  : "=r"(__WBenchToFront__re) \
  : "r"(__WBenchToFront__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WBenchToFront__re; \
  }); \
  _WBenchToFront__re; \
})

#define AutoRequest(window, body, posText, negText, pFlag, nFlag, width, height) ({ \
  struct Window * _AutoRequest_window = (window); \
  const struct IntuiText * _AutoRequest_body = (body); \
  const struct IntuiText * _AutoRequest_posText = (posText); \
  const struct IntuiText * _AutoRequest_negText = (negText); \
  ULONG _AutoRequest_pFlag = (pFlag); \
  ULONG _AutoRequest_nFlag = (nFlag); \
  ULONG _AutoRequest_width = (width); \
  ULONG _AutoRequest_height = (height); \
  BOOL _AutoRequest__re = \
  ({ \
  register struct Library * const __AutoRequest__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __AutoRequest__re __asm("d0"); \
  register struct Window * __AutoRequest_window __asm("a0") = (_AutoRequest_window); \
  register const struct IntuiText * __AutoRequest_body __asm("a1") = (_AutoRequest_body); \
  register const struct IntuiText * __AutoRequest_posText __asm("a2") = (_AutoRequest_posText); \
  register const struct IntuiText * __AutoRequest_negText __asm("a3") = (_AutoRequest_negText); \
  register ULONG __AutoRequest_pFlag __asm("d0") = (_AutoRequest_pFlag); \
  register ULONG __AutoRequest_nFlag __asm("d1") = (_AutoRequest_nFlag); \
  register ULONG __AutoRequest_width __asm("d2") = (_AutoRequest_width); \
  register ULONG __AutoRequest_height __asm("d3") = (_AutoRequest_height); \
  __asm volatile ("jsr a6@(-348:W)" \
  : "=r"(__AutoRequest__re) \
  : "r"(__AutoRequest__bn), "r"(__AutoRequest_window), "r"(__AutoRequest_body), "r"(__AutoRequest_posText), "r"(__AutoRequest_negText), "r"(__AutoRequest_pFlag), "r"(__AutoRequest_nFlag), "r"(__AutoRequest_width), "r"(__AutoRequest_height) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AutoRequest__re; \
  }); \
  _AutoRequest__re; \
})

#define BeginRefresh(window) ({ \
  struct Window * _BeginRefresh_window = (window); \
  { \
  register struct Library * const __BeginRefresh__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __BeginRefresh_window __asm("a0") = (_BeginRefresh_window); \
  __asm volatile ("jsr a6@(-354:W)" \
  : \
  : "r"(__BeginRefresh__bn), "r"(__BeginRefresh_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define BuildSysRequest(window, body, posText, negText, flags, width, height) ({ \
  struct Window * _BuildSysRequest_window = (window); \
  const struct IntuiText * _BuildSysRequest_body = (body); \
  const struct IntuiText * _BuildSysRequest_posText = (posText); \
  const struct IntuiText * _BuildSysRequest_negText = (negText); \
  ULONG _BuildSysRequest_flags = (flags); \
  ULONG _BuildSysRequest_width = (width); \
  ULONG _BuildSysRequest_height = (height); \
  struct Window * _BuildSysRequest__re = \
  ({ \
  register struct Library * const __BuildSysRequest__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __BuildSysRequest__re __asm("d0"); \
  register struct Window * __BuildSysRequest_window __asm("a0") = (_BuildSysRequest_window); \
  register const struct IntuiText * __BuildSysRequest_body __asm("a1") = (_BuildSysRequest_body); \
  register const struct IntuiText * __BuildSysRequest_posText __asm("a2") = (_BuildSysRequest_posText); \
  register const struct IntuiText * __BuildSysRequest_negText __asm("a3") = (_BuildSysRequest_negText); \
  register ULONG __BuildSysRequest_flags __asm("d0") = (_BuildSysRequest_flags); \
  register ULONG __BuildSysRequest_width __asm("d1") = (_BuildSysRequest_width); \
  register ULONG __BuildSysRequest_height __asm("d2") = (_BuildSysRequest_height); \
  __asm volatile ("jsr a6@(-360:W)" \
  : "=r"(__BuildSysRequest__re) \
  : "r"(__BuildSysRequest__bn), "r"(__BuildSysRequest_window), "r"(__BuildSysRequest_body), "r"(__BuildSysRequest_posText), "r"(__BuildSysRequest_negText), "r"(__BuildSysRequest_flags), "r"(__BuildSysRequest_width), "r"(__BuildSysRequest_height) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __BuildSysRequest__re; \
  }); \
  _BuildSysRequest__re; \
})

#define EndRefresh(window, complete) ({ \
  struct Window * _EndRefresh_window = (window); \
  LONG _EndRefresh_complete = (complete); \
  { \
  register struct Library * const __EndRefresh__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __EndRefresh_window __asm("a0") = (_EndRefresh_window); \
  register LONG __EndRefresh_complete __asm("d0") = (_EndRefresh_complete); \
  __asm volatile ("jsr a6@(-366:W)" \
  : \
  : "r"(__EndRefresh__bn), "r"(__EndRefresh_window), "r"(__EndRefresh_complete) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FreeSysRequest(window) ({ \
  struct Window * _FreeSysRequest_window = (window); \
  { \
  register struct Library * const __FreeSysRequest__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __FreeSysRequest_window __asm("a0") = (_FreeSysRequest_window); \
  __asm volatile ("jsr a6@(-372:W)" \
  : \
  : "r"(__FreeSysRequest__bn), "r"(__FreeSysRequest_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define MakeScreen(screen) ({ \
  struct Screen * _MakeScreen_screen = (screen); \
  LONG _MakeScreen__re = \
  ({ \
  register struct Library * const __MakeScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __MakeScreen__re __asm("d0"); \
  register struct Screen * __MakeScreen_screen __asm("a0") = (_MakeScreen_screen); \
  __asm volatile ("jsr a6@(-378:W)" \
  : "=r"(__MakeScreen__re) \
  : "r"(__MakeScreen__bn), "r"(__MakeScreen_screen) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __MakeScreen__re; \
  }); \
  _MakeScreen__re; \
})

#define RemakeDisplay() ({ \
  LONG _RemakeDisplay__re = \
  ({ \
  register struct Library * const __RemakeDisplay__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __RemakeDisplay__re __asm("d0"); \
  __asm volatile ("jsr a6@(-384:W)" \
  : "=r"(__RemakeDisplay__re) \
  : "r"(__RemakeDisplay__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemakeDisplay__re; \
  }); \
  _RemakeDisplay__re; \
})

#define RethinkDisplay() ({ \
  LONG _RethinkDisplay__re = \
  ({ \
  register struct Library * const __RethinkDisplay__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __RethinkDisplay__re __asm("d0"); \
  __asm volatile ("jsr a6@(-390:W)" \
  : "=r"(__RethinkDisplay__re) \
  : "r"(__RethinkDisplay__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RethinkDisplay__re; \
  }); \
  _RethinkDisplay__re; \
})

#define AllocRemember(rememberKey, size, flags) ({ \
  struct Remember ** _AllocRemember_rememberKey = (rememberKey); \
  ULONG _AllocRemember_size = (size); \
  ULONG _AllocRemember_flags = (flags); \
  APTR _AllocRemember__re = \
  ({ \
  register struct Library * const __AllocRemember__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __AllocRemember__re __asm("d0"); \
  register struct Remember ** __AllocRemember_rememberKey __asm("a0") = (_AllocRemember_rememberKey); \
  register ULONG __AllocRemember_size __asm("d0") = (_AllocRemember_size); \
  register ULONG __AllocRemember_flags __asm("d1") = (_AllocRemember_flags); \
  __asm volatile ("jsr a6@(-396:W)" \
  : "=r"(__AllocRemember__re) \
  : "r"(__AllocRemember__bn), "r"(__AllocRemember_rememberKey), "r"(__AllocRemember_size), "r"(__AllocRemember_flags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocRemember__re; \
  }); \
  _AllocRemember__re; \
})

#define FreeRemember(rememberKey, reallyForget) ({ \
  struct Remember ** _FreeRemember_rememberKey = (rememberKey); \
  LONG _FreeRemember_reallyForget = (reallyForget); \
  { \
  register struct Library * const __FreeRemember__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Remember ** __FreeRemember_rememberKey __asm("a0") = (_FreeRemember_rememberKey); \
  register LONG __FreeRemember_reallyForget __asm("d0") = (_FreeRemember_reallyForget); \
  __asm volatile ("jsr a6@(-408:W)" \
  : \
  : "r"(__FreeRemember__bn), "r"(__FreeRemember_rememberKey), "r"(__FreeRemember_reallyForget) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define LockIBase(dontknow) ({ \
  ULONG _LockIBase_dontknow = (dontknow); \
  ULONG _LockIBase__re = \
  ({ \
  register struct Library * const __LockIBase__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __LockIBase__re __asm("d0"); \
  register ULONG __LockIBase_dontknow __asm("d0") = (_LockIBase_dontknow); \
  __asm volatile ("jsr a6@(-414:W)" \
  : "=r"(__LockIBase__re) \
  : "r"(__LockIBase__bn), "r"(__LockIBase_dontknow) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LockIBase__re; \
  }); \
  _LockIBase__re; \
})

#define UnlockIBase(ibLock) ({ \
  ULONG _UnlockIBase_ibLock = (ibLock); \
  { \
  register struct Library * const __UnlockIBase__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __UnlockIBase_ibLock __asm("a0") = (_UnlockIBase_ibLock); \
  __asm volatile ("jsr a6@(-420:W)" \
  : \
  : "r"(__UnlockIBase__bn), "r"(__UnlockIBase_ibLock) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetScreenData(buffer, size, type, screen) ({ \
  APTR _GetScreenData_buffer = (buffer); \
  ULONG _GetScreenData_size = (size); \
  ULONG _GetScreenData_type = (type); \
  const struct Screen * _GetScreenData_screen = (screen); \
  LONG _GetScreenData__re = \
  ({ \
  register struct Library * const __GetScreenData__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __GetScreenData__re __asm("d0"); \
  register APTR __GetScreenData_buffer __asm("a0") = (_GetScreenData_buffer); \
  register ULONG __GetScreenData_size __asm("d0") = (_GetScreenData_size); \
  register ULONG __GetScreenData_type __asm("d1") = (_GetScreenData_type); \
  register const struct Screen * __GetScreenData_screen __asm("a1") = (_GetScreenData_screen); \
  __asm volatile ("jsr a6@(-426:W)" \
  : "=r"(__GetScreenData__re) \
  : "r"(__GetScreenData__bn), "r"(__GetScreenData_buffer), "r"(__GetScreenData_size), "r"(__GetScreenData_type), "r"(__GetScreenData_screen) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetScreenData__re; \
  }); \
  _GetScreenData__re; \
})

#define RefreshGList(gadgets, window, requester, numGad) ({ \
  struct Gadget * _RefreshGList_gadgets = (gadgets); \
  struct Window * _RefreshGList_window = (window); \
  struct Requester * _RefreshGList_requester = (requester); \
  LONG _RefreshGList_numGad = (numGad); \
  { \
  register struct Library * const __RefreshGList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Gadget * __RefreshGList_gadgets __asm("a0") = (_RefreshGList_gadgets); \
  register struct Window * __RefreshGList_window __asm("a1") = (_RefreshGList_window); \
  register struct Requester * __RefreshGList_requester __asm("a2") = (_RefreshGList_requester); \
  register LONG __RefreshGList_numGad __asm("d0") = (_RefreshGList_numGad); \
  __asm volatile ("jsr a6@(-432:W)" \
  : \
  : "r"(__RefreshGList__bn), "r"(__RefreshGList_gadgets), "r"(__RefreshGList_window), "r"(__RefreshGList_requester), "r"(__RefreshGList_numGad) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddGList(window, gadget, position, numGad, requester) ({ \
  struct Window * _AddGList_window = (window); \
  struct Gadget * _AddGList_gadget = (gadget); \
  ULONG _AddGList_position = (position); \
  LONG _AddGList_numGad = (numGad); \
  struct Requester * _AddGList_requester = (requester); \
  UWORD _AddGList__re = \
  ({ \
  register struct Library * const __AddGList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register UWORD __AddGList__re __asm("d0"); \
  register struct Window * __AddGList_window __asm("a0") = (_AddGList_window); \
  register struct Gadget * __AddGList_gadget __asm("a1") = (_AddGList_gadget); \
  register ULONG __AddGList_position __asm("d0") = (_AddGList_position); \
  register LONG __AddGList_numGad __asm("d1") = (_AddGList_numGad); \
  register struct Requester * __AddGList_requester __asm("a2") = (_AddGList_requester); \
  __asm volatile ("jsr a6@(-438:W)" \
  : "=r"(__AddGList__re) \
  : "r"(__AddGList__bn), "r"(__AddGList_window), "r"(__AddGList_gadget), "r"(__AddGList_position), "r"(__AddGList_numGad), "r"(__AddGList_requester) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddGList__re; \
  }); \
  _AddGList__re; \
})

#define RemoveGList(remPtr, gadget, numGad) ({ \
  struct Window * _RemoveGList_remPtr = (remPtr); \
  struct Gadget * _RemoveGList_gadget = (gadget); \
  LONG _RemoveGList_numGad = (numGad); \
  UWORD _RemoveGList__re = \
  ({ \
  register struct Library * const __RemoveGList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register UWORD __RemoveGList__re __asm("d0"); \
  register struct Window * __RemoveGList_remPtr __asm("a0") = (_RemoveGList_remPtr); \
  register struct Gadget * __RemoveGList_gadget __asm("a1") = (_RemoveGList_gadget); \
  register LONG __RemoveGList_numGad __asm("d0") = (_RemoveGList_numGad); \
  __asm volatile ("jsr a6@(-444:W)" \
  : "=r"(__RemoveGList__re) \
  : "r"(__RemoveGList__bn), "r"(__RemoveGList_remPtr), "r"(__RemoveGList_gadget), "r"(__RemoveGList_numGad) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoveGList__re; \
  }); \
  _RemoveGList__re; \
})

#define ActivateWindow(window) ({ \
  struct Window * _ActivateWindow_window = (window); \
  { \
  register struct Library * const __ActivateWindow__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __ActivateWindow_window __asm("a0") = (_ActivateWindow_window); \
  __asm volatile ("jsr a6@(-450:W)" \
  : \
  : "r"(__ActivateWindow__bn), "r"(__ActivateWindow_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RefreshWindowFrame(window) ({ \
  struct Window * _RefreshWindowFrame_window = (window); \
  { \
  register struct Library * const __RefreshWindowFrame__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __RefreshWindowFrame_window __asm("a0") = (_RefreshWindowFrame_window); \
  __asm volatile ("jsr a6@(-456:W)" \
  : \
  : "r"(__RefreshWindowFrame__bn), "r"(__RefreshWindowFrame_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ActivateGadget(gadgets, window, requester) ({ \
  struct Gadget * _ActivateGadget_gadgets = (gadgets); \
  struct Window * _ActivateGadget_window = (window); \
  struct Requester * _ActivateGadget_requester = (requester); \
  BOOL _ActivateGadget__re = \
  ({ \
  register struct Library * const __ActivateGadget__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __ActivateGadget__re __asm("d0"); \
  register struct Gadget * __ActivateGadget_gadgets __asm("a0") = (_ActivateGadget_gadgets); \
  register struct Window * __ActivateGadget_window __asm("a1") = (_ActivateGadget_window); \
  register struct Requester * __ActivateGadget_requester __asm("a2") = (_ActivateGadget_requester); \
  __asm volatile ("jsr a6@(-462:W)" \
  : "=r"(__ActivateGadget__re) \
  : "r"(__ActivateGadget__bn), "r"(__ActivateGadget_gadgets), "r"(__ActivateGadget_window), "r"(__ActivateGadget_requester) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ActivateGadget__re; \
  }); \
  _ActivateGadget__re; \
})

#define NewModifyProp(gadget, window, requester, flags, horizPot, vertPot, horizBody, vertBody, numGad) ({ \
  struct Gadget * _NewModifyProp_gadget = (gadget); \
  struct Window * _NewModifyProp_window = (window); \
  struct Requester * _NewModifyProp_requester = (requester); \
  ULONG _NewModifyProp_flags = (flags); \
  ULONG _NewModifyProp_horizPot = (horizPot); \
  ULONG _NewModifyProp_vertPot = (vertPot); \
  ULONG _NewModifyProp_horizBody = (horizBody); \
  ULONG _NewModifyProp_vertBody = (vertBody); \
  LONG _NewModifyProp_numGad = (numGad); \
  { \
  register struct Library * const __NewModifyProp__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Gadget * __NewModifyProp_gadget __asm("a0") = (_NewModifyProp_gadget); \
  register struct Window * __NewModifyProp_window __asm("a1") = (_NewModifyProp_window); \
  register struct Requester * __NewModifyProp_requester __asm("a2") = (_NewModifyProp_requester); \
  register ULONG __NewModifyProp_flags __asm("d0") = (_NewModifyProp_flags); \
  register ULONG __NewModifyProp_horizPot __asm("d1") = (_NewModifyProp_horizPot); \
  register ULONG __NewModifyProp_vertPot __asm("d2") = (_NewModifyProp_vertPot); \
  register ULONG __NewModifyProp_horizBody __asm("d3") = (_NewModifyProp_horizBody); \
  register ULONG __NewModifyProp_vertBody __asm("d4") = (_NewModifyProp_vertBody); \
  register LONG __NewModifyProp_numGad __asm("d5") = (_NewModifyProp_numGad); \
  __asm volatile ("jsr a6@(-468:W)" \
  : \
  : "r"(__NewModifyProp__bn), "r"(__NewModifyProp_gadget), "r"(__NewModifyProp_window), "r"(__NewModifyProp_requester), "r"(__NewModifyProp_flags), "r"(__NewModifyProp_horizPot), "r"(__NewModifyProp_vertPot), "r"(__NewModifyProp_horizBody), "r"(__NewModifyProp_vertBody), "r"(__NewModifyProp_numGad) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define QueryOverscan(displayID, rect, oScanType) ({ \
  ULONG _QueryOverscan_displayID = (displayID); \
  struct Rectangle * _QueryOverscan_rect = (rect); \
  LONG _QueryOverscan_oScanType = (oScanType); \
  LONG _QueryOverscan__re = \
  ({ \
  register struct Library * const __QueryOverscan__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __QueryOverscan__re __asm("d0"); \
  register ULONG __QueryOverscan_displayID __asm("a0") = (_QueryOverscan_displayID); \
  register struct Rectangle * __QueryOverscan_rect __asm("a1") = (_QueryOverscan_rect); \
  register LONG __QueryOverscan_oScanType __asm("d0") = (_QueryOverscan_oScanType); \
  __asm volatile ("jsr a6@(-474:W)" \
  : "=r"(__QueryOverscan__re) \
  : "r"(__QueryOverscan__bn), "r"(__QueryOverscan_displayID), "r"(__QueryOverscan_rect), "r"(__QueryOverscan_oScanType) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __QueryOverscan__re; \
  }); \
  _QueryOverscan__re; \
})

#define MoveWindowInFrontOf(window, behindWindow) ({ \
  struct Window * _MoveWindowInFrontOf_window = (window); \
  struct Window * _MoveWindowInFrontOf_behindWindow = (behindWindow); \
  { \
  register struct Library * const __MoveWindowInFrontOf__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __MoveWindowInFrontOf_window __asm("a0") = (_MoveWindowInFrontOf_window); \
  register struct Window * __MoveWindowInFrontOf_behindWindow __asm("a1") = (_MoveWindowInFrontOf_behindWindow); \
  __asm volatile ("jsr a6@(-480:W)" \
  : \
  : "r"(__MoveWindowInFrontOf__bn), "r"(__MoveWindowInFrontOf_window), "r"(__MoveWindowInFrontOf_behindWindow) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ChangeWindowBox(window, left, top, width, height) ({ \
  struct Window * _ChangeWindowBox_window = (window); \
  LONG _ChangeWindowBox_left = (left); \
  LONG _ChangeWindowBox_top = (top); \
  LONG _ChangeWindowBox_width = (width); \
  LONG _ChangeWindowBox_height = (height); \
  { \
  register struct Library * const __ChangeWindowBox__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __ChangeWindowBox_window __asm("a0") = (_ChangeWindowBox_window); \
  register LONG __ChangeWindowBox_left __asm("d0") = (_ChangeWindowBox_left); \
  register LONG __ChangeWindowBox_top __asm("d1") = (_ChangeWindowBox_top); \
  register LONG __ChangeWindowBox_width __asm("d2") = (_ChangeWindowBox_width); \
  register LONG __ChangeWindowBox_height __asm("d3") = (_ChangeWindowBox_height); \
  __asm volatile ("jsr a6@(-486:W)" \
  : \
  : "r"(__ChangeWindowBox__bn), "r"(__ChangeWindowBox_window), "r"(__ChangeWindowBox_left), "r"(__ChangeWindowBox_top), "r"(__ChangeWindowBox_width), "r"(__ChangeWindowBox_height) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetEditHook(hook) ({ \
  struct Hook * _SetEditHook_hook = (hook); \
  struct Hook * _SetEditHook__re = \
  ({ \
  register struct Library * const __SetEditHook__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Hook * __SetEditHook__re __asm("d0"); \
  register struct Hook * __SetEditHook_hook __asm("a0") = (_SetEditHook_hook); \
  __asm volatile ("jsr a6@(-492:W)" \
  : "=r"(__SetEditHook__re) \
  : "r"(__SetEditHook__bn), "r"(__SetEditHook_hook) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetEditHook__re; \
  }); \
  _SetEditHook__re; \
})

#define SetMouseQueue(window, queueLength) ({ \
  struct Window * _SetMouseQueue_window = (window); \
  ULONG _SetMouseQueue_queueLength = (queueLength); \
  LONG _SetMouseQueue__re = \
  ({ \
  register struct Library * const __SetMouseQueue__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __SetMouseQueue__re __asm("d0"); \
  register struct Window * __SetMouseQueue_window __asm("a0") = (_SetMouseQueue_window); \
  register ULONG __SetMouseQueue_queueLength __asm("d0") = (_SetMouseQueue_queueLength); \
  __asm volatile ("jsr a6@(-498:W)" \
  : "=r"(__SetMouseQueue__re) \
  : "r"(__SetMouseQueue__bn), "r"(__SetMouseQueue_window), "r"(__SetMouseQueue_queueLength) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetMouseQueue__re; \
  }); \
  _SetMouseQueue__re; \
})

#define ZipWindow(window) ({ \
  struct Window * _ZipWindow_window = (window); \
  { \
  register struct Library * const __ZipWindow__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __ZipWindow_window __asm("a0") = (_ZipWindow_window); \
  __asm volatile ("jsr a6@(-504:W)" \
  : \
  : "r"(__ZipWindow__bn), "r"(__ZipWindow_window) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define LockPubScreen(name) ({ \
  CONST_STRPTR _LockPubScreen_name = (name); \
  struct Screen * _LockPubScreen__re = \
  ({ \
  register struct Library * const __LockPubScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __LockPubScreen__re __asm("d0"); \
  register CONST_STRPTR __LockPubScreen_name __asm("a0") = (_LockPubScreen_name); \
  __asm volatile ("jsr a6@(-510:W)" \
  : "=r"(__LockPubScreen__re) \
  : "r"(__LockPubScreen__bn), "r"(__LockPubScreen_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LockPubScreen__re; \
  }); \
  _LockPubScreen__re; \
})

#define UnlockPubScreen(name, screen) ({ \
  CONST_STRPTR _UnlockPubScreen_name = (name); \
  struct Screen * _UnlockPubScreen_screen = (screen); \
  { \
  register struct Library * const __UnlockPubScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register CONST_STRPTR __UnlockPubScreen_name __asm("a0") = (_UnlockPubScreen_name); \
  register struct Screen * __UnlockPubScreen_screen __asm("a1") = (_UnlockPubScreen_screen); \
  __asm volatile ("jsr a6@(-516:W)" \
  : \
  : "r"(__UnlockPubScreen__bn), "r"(__UnlockPubScreen_name), "r"(__UnlockPubScreen_screen) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define LockPubScreenList() ({ \
  struct List * _LockPubScreenList__re = \
  ({ \
  register struct Library * const __LockPubScreenList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct List * __LockPubScreenList__re __asm("d0"); \
  __asm volatile ("jsr a6@(-522:W)" \
  : "=r"(__LockPubScreenList__re) \
  : "r"(__LockPubScreenList__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LockPubScreenList__re; \
  }); \
  _LockPubScreenList__re; \
})

#define UnlockPubScreenList() ({ \
  register struct Library * const __UnlockPubScreenList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  __asm volatile ("jsr a6@(-528:W)" \
  : \
  : "r"(__UnlockPubScreenList__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define NextPubScreen(screen, namebuf) ({ \
  const struct Screen * _NextPubScreen_screen = (screen); \
  STRPTR _NextPubScreen_namebuf = (namebuf); \
  STRPTR _NextPubScreen__re = \
  ({ \
  register struct Library * const __NextPubScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register STRPTR __NextPubScreen__re __asm("d0"); \
  register const struct Screen * __NextPubScreen_screen __asm("a0") = (_NextPubScreen_screen); \
  register STRPTR __NextPubScreen_namebuf __asm("a1") = (_NextPubScreen_namebuf); \
  __asm volatile ("jsr a6@(-534:W)" \
  : "=r"(__NextPubScreen__re) \
  : "r"(__NextPubScreen__bn), "r"(__NextPubScreen_screen), "r"(__NextPubScreen_namebuf) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NextPubScreen__re; \
  }); \
  _NextPubScreen__re; \
})

#define SetDefaultPubScreen(name) ({ \
  CONST_STRPTR _SetDefaultPubScreen_name = (name); \
  { \
  register struct Library * const __SetDefaultPubScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register CONST_STRPTR __SetDefaultPubScreen_name __asm("a0") = (_SetDefaultPubScreen_name); \
  __asm volatile ("jsr a6@(-540:W)" \
  : \
  : "r"(__SetDefaultPubScreen__bn), "r"(__SetDefaultPubScreen_name) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetPubScreenModes(modes) ({ \
  ULONG _SetPubScreenModes_modes = (modes); \
  UWORD _SetPubScreenModes__re = \
  ({ \
  register struct Library * const __SetPubScreenModes__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register UWORD __SetPubScreenModes__re __asm("d0"); \
  register ULONG __SetPubScreenModes_modes __asm("d0") = (_SetPubScreenModes_modes); \
  __asm volatile ("jsr a6@(-546:W)" \
  : "=r"(__SetPubScreenModes__re) \
  : "r"(__SetPubScreenModes__bn), "r"(__SetPubScreenModes_modes) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetPubScreenModes__re; \
  }); \
  _SetPubScreenModes__re; \
})

#define PubScreenStatus(screen, statusFlags) ({ \
  struct Screen * _PubScreenStatus_screen = (screen); \
  ULONG _PubScreenStatus_statusFlags = (statusFlags); \
  UWORD _PubScreenStatus__re = \
  ({ \
  register struct Library * const __PubScreenStatus__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register UWORD __PubScreenStatus__re __asm("d0"); \
  register struct Screen * __PubScreenStatus_screen __asm("a0") = (_PubScreenStatus_screen); \
  register ULONG __PubScreenStatus_statusFlags __asm("d0") = (_PubScreenStatus_statusFlags); \
  __asm volatile ("jsr a6@(-552:W)" \
  : "=r"(__PubScreenStatus__re) \
  : "r"(__PubScreenStatus__bn), "r"(__PubScreenStatus_screen), "r"(__PubScreenStatus_statusFlags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PubScreenStatus__re; \
  }); \
  _PubScreenStatus__re; \
})

#define ObtainGIRPort(gInfo) ({ \
  struct GadgetInfo * _ObtainGIRPort_gInfo = (gInfo); \
  struct RastPort   * _ObtainGIRPort__re = \
  ({ \
  register struct Library * const __ObtainGIRPort__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort   * __ObtainGIRPort__re __asm("d0"); \
  register struct GadgetInfo * __ObtainGIRPort_gInfo __asm("a0") = (_ObtainGIRPort_gInfo); \
  __asm volatile ("jsr a6@(-558:W)" \
  : "=r"(__ObtainGIRPort__re) \
  : "r"(__ObtainGIRPort__bn), "r"(__ObtainGIRPort_gInfo) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainGIRPort__re; \
  }); \
  _ObtainGIRPort__re; \
})

#define ReleaseGIRPort(rp) ({ \
  struct RastPort * _ReleaseGIRPort_rp = (rp); \
  { \
  register struct Library * const __ReleaseGIRPort__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __ReleaseGIRPort_rp __asm("a0") = (_ReleaseGIRPort_rp); \
  __asm volatile ("jsr a6@(-564:W)" \
  : \
  : "r"(__ReleaseGIRPort__bn), "r"(__ReleaseGIRPort_rp) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GadgetMouse(gadget, gInfo, mousePoint) ({ \
  struct Gadget * _GadgetMouse_gadget = (gadget); \
  struct GadgetInfo * _GadgetMouse_gInfo = (gInfo); \
  WORD * _GadgetMouse_mousePoint = (mousePoint); \
  { \
  register struct Library * const __GadgetMouse__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Gadget * __GadgetMouse_gadget __asm("a0") = (_GadgetMouse_gadget); \
  register struct GadgetInfo * __GadgetMouse_gInfo __asm("a1") = (_GadgetMouse_gInfo); \
  register WORD * __GadgetMouse_mousePoint __asm("a2") = (_GadgetMouse_mousePoint); \
  __asm volatile ("jsr a6@(-570:W)" \
  : \
  : "r"(__GadgetMouse__bn), "r"(__GadgetMouse_gadget), "r"(__GadgetMouse_gInfo), "r"(__GadgetMouse_mousePoint) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetDefaultPubScreen(nameBuffer) ({ \
  STRPTR _GetDefaultPubScreen_nameBuffer = (nameBuffer); \
  { \
  register struct Library * const __GetDefaultPubScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register STRPTR __GetDefaultPubScreen_nameBuffer __asm("a0") = (_GetDefaultPubScreen_nameBuffer); \
  __asm volatile ("jsr a6@(-582:W)" \
  : \
  : "r"(__GetDefaultPubScreen__bn), "r"(__GetDefaultPubScreen_nameBuffer) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define EasyRequestArgs(window, easyStruct, idcmpPtr, args) ({ \
  struct Window * _EasyRequestArgs_window = (window); \
  const struct EasyStruct * _EasyRequestArgs_easyStruct = (easyStruct); \
  ULONG * _EasyRequestArgs_idcmpPtr = (idcmpPtr); \
  const APTR _EasyRequestArgs_args = (args); \
  LONG _EasyRequestArgs__re = \
  ({ \
  register struct Library * const __EasyRequestArgs__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __EasyRequestArgs__re __asm("d0"); \
  register struct Window * __EasyRequestArgs_window __asm("a0") = (_EasyRequestArgs_window); \
  register const struct EasyStruct * __EasyRequestArgs_easyStruct __asm("a1") = (_EasyRequestArgs_easyStruct); \
  register ULONG * __EasyRequestArgs_idcmpPtr __asm("a2") = (_EasyRequestArgs_idcmpPtr); \
  register const APTR __EasyRequestArgs_args __asm("a3") = (_EasyRequestArgs_args); \
  __asm volatile ("jsr a6@(-588:W)" \
  : "=r"(__EasyRequestArgs__re) \
  : "r"(__EasyRequestArgs__bn), "r"(__EasyRequestArgs_window), "r"(__EasyRequestArgs_easyStruct), "r"(__EasyRequestArgs_idcmpPtr), "r"(__EasyRequestArgs_args) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __EasyRequestArgs__re; \
  }); \
  _EasyRequestArgs__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___EasyRequest(struct Library * IntuitionBase, struct Window * window, const struct EasyStruct * easyStruct, ULONG * idcmpPtr, ULONG args, ...)
{
  return EasyRequestArgs(window, easyStruct, idcmpPtr, (const APTR) &args);
}

#define EasyRequest(window, easyStruct, idcmpPtr...) ___EasyRequest((struct Library *) INTUITION_BASE_NAME, window, easyStruct, idcmpPtr)
#endif

#define BuildEasyRequestArgs(window, easyStruct, idcmp, args) ({ \
  struct Window * _BuildEasyRequestArgs_window = (window); \
  const struct EasyStruct * _BuildEasyRequestArgs_easyStruct = (easyStruct); \
  ULONG _BuildEasyRequestArgs_idcmp = (idcmp); \
  const APTR _BuildEasyRequestArgs_args = (args); \
  struct Window * _BuildEasyRequestArgs__re = \
  ({ \
  register struct Library * const __BuildEasyRequestArgs__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __BuildEasyRequestArgs__re __asm("d0"); \
  register struct Window * __BuildEasyRequestArgs_window __asm("a0") = (_BuildEasyRequestArgs_window); \
  register const struct EasyStruct * __BuildEasyRequestArgs_easyStruct __asm("a1") = (_BuildEasyRequestArgs_easyStruct); \
  register ULONG __BuildEasyRequestArgs_idcmp __asm("d0") = (_BuildEasyRequestArgs_idcmp); \
  register const APTR __BuildEasyRequestArgs_args __asm("a3") = (_BuildEasyRequestArgs_args); \
  __asm volatile ("jsr a6@(-594:W)" \
  : "=r"(__BuildEasyRequestArgs__re) \
  : "r"(__BuildEasyRequestArgs__bn), "r"(__BuildEasyRequestArgs_window), "r"(__BuildEasyRequestArgs_easyStruct), "r"(__BuildEasyRequestArgs_idcmp), "r"(__BuildEasyRequestArgs_args) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __BuildEasyRequestArgs__re; \
  }); \
  _BuildEasyRequestArgs__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Window * ___BuildEasyRequest(struct Library * IntuitionBase, struct Window * window, const struct EasyStruct * easyStruct, ULONG idcmp, ULONG args, ...)
{
  return BuildEasyRequestArgs(window, easyStruct, idcmp, (const APTR) &args);
}

#define BuildEasyRequest(window, easyStruct, idcmp...) ___BuildEasyRequest((struct Library *) INTUITION_BASE_NAME, window, easyStruct, idcmp)
#endif

#define SysReqHandler(window, idcmpPtr, waitInput) ({ \
  struct Window * _SysReqHandler_window = (window); \
  ULONG * _SysReqHandler_idcmpPtr = (idcmpPtr); \
  LONG _SysReqHandler_waitInput = (waitInput); \
  LONG _SysReqHandler__re = \
  ({ \
  register struct Library * const __SysReqHandler__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __SysReqHandler__re __asm("d0"); \
  register struct Window * __SysReqHandler_window __asm("a0") = (_SysReqHandler_window); \
  register ULONG * __SysReqHandler_idcmpPtr __asm("a1") = (_SysReqHandler_idcmpPtr); \
  register LONG __SysReqHandler_waitInput __asm("d0") = (_SysReqHandler_waitInput); \
  __asm volatile ("jsr a6@(-600:W)" \
  : "=r"(__SysReqHandler__re) \
  : "r"(__SysReqHandler__bn), "r"(__SysReqHandler_window), "r"(__SysReqHandler_idcmpPtr), "r"(__SysReqHandler_waitInput) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SysReqHandler__re; \
  }); \
  _SysReqHandler__re; \
})

#define OpenWindowTagList(newWindow, tagList) ({ \
  const struct NewWindow * _OpenWindowTagList_newWindow = (newWindow); \
  const struct TagItem * _OpenWindowTagList_tagList = (tagList); \
  struct Window * _OpenWindowTagList__re = \
  ({ \
  register struct Library * const __OpenWindowTagList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __OpenWindowTagList__re __asm("d0"); \
  register const struct NewWindow * __OpenWindowTagList_newWindow __asm("a0") = (_OpenWindowTagList_newWindow); \
  register const struct TagItem * __OpenWindowTagList_tagList __asm("a1") = (_OpenWindowTagList_tagList); \
  __asm volatile ("jsr a6@(-606:W)" \
  : "=r"(__OpenWindowTagList__re) \
  : "r"(__OpenWindowTagList__bn), "r"(__OpenWindowTagList_newWindow), "r"(__OpenWindowTagList_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenWindowTagList__re; \
  }); \
  _OpenWindowTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Window * ___OpenWindowTags(struct Library * IntuitionBase, const struct NewWindow * newWindow, ULONG tagList, ...)
{
  return OpenWindowTagList(newWindow, (const struct TagItem *) &tagList);
}

#define OpenWindowTags(newWindow...) ___OpenWindowTags((struct Library *) INTUITION_BASE_NAME, newWindow)
#endif

#define OpenScreenTagList(newScreen, tagList) ({ \
  const struct NewScreen * _OpenScreenTagList_newScreen = (newScreen); \
  const struct TagItem * _OpenScreenTagList_tagList = (tagList); \
  struct Screen * _OpenScreenTagList__re = \
  ({ \
  register struct Library * const __OpenScreenTagList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __OpenScreenTagList__re __asm("d0"); \
  register const struct NewScreen * __OpenScreenTagList_newScreen __asm("a0") = (_OpenScreenTagList_newScreen); \
  register const struct TagItem * __OpenScreenTagList_tagList __asm("a1") = (_OpenScreenTagList_tagList); \
  __asm volatile ("jsr a6@(-612:W)" \
  : "=r"(__OpenScreenTagList__re) \
  : "r"(__OpenScreenTagList__bn), "r"(__OpenScreenTagList_newScreen), "r"(__OpenScreenTagList_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenScreenTagList__re; \
  }); \
  _OpenScreenTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Screen * ___OpenScreenTags(struct Library * IntuitionBase, const struct NewScreen * newScreen, ULONG tagList, ...)
{
  return OpenScreenTagList(newScreen, (const struct TagItem *) &tagList);
}

#define OpenScreenTags(newScreen...) ___OpenScreenTags((struct Library *) INTUITION_BASE_NAME, newScreen)
#endif

#define DrawImageState(rp, image, leftOffset, topOffset, state, drawInfo) ({ \
  struct RastPort * _DrawImageState_rp = (rp); \
  struct Image * _DrawImageState_image = (image); \
  LONG _DrawImageState_leftOffset = (leftOffset); \
  LONG _DrawImageState_topOffset = (topOffset); \
  ULONG _DrawImageState_state = (state); \
  const struct DrawInfo * _DrawImageState_drawInfo = (drawInfo); \
  { \
  register struct Library * const __DrawImageState__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __DrawImageState_rp __asm("a0") = (_DrawImageState_rp); \
  register struct Image * __DrawImageState_image __asm("a1") = (_DrawImageState_image); \
  register LONG __DrawImageState_leftOffset __asm("d0") = (_DrawImageState_leftOffset); \
  register LONG __DrawImageState_topOffset __asm("d1") = (_DrawImageState_topOffset); \
  register ULONG __DrawImageState_state __asm("d2") = (_DrawImageState_state); \
  register const struct DrawInfo * __DrawImageState_drawInfo __asm("a2") = (_DrawImageState_drawInfo); \
  __asm volatile ("jsr a6@(-618:W)" \
  : \
  : "r"(__DrawImageState__bn), "r"(__DrawImageState_rp), "r"(__DrawImageState_image), "r"(__DrawImageState_leftOffset), "r"(__DrawImageState_topOffset), "r"(__DrawImageState_state), "r"(__DrawImageState_drawInfo) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define PointInImage(point, image) ({ \
  ULONG _PointInImage_point = (point); \
  struct Image * _PointInImage_image = (image); \
  BOOL _PointInImage__re = \
  ({ \
  register struct Library * const __PointInImage__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __PointInImage__re __asm("d0"); \
  register ULONG __PointInImage_point __asm("d0") = (_PointInImage_point); \
  register struct Image * __PointInImage_image __asm("a0") = (_PointInImage_image); \
  __asm volatile ("jsr a6@(-624:W)" \
  : "=r"(__PointInImage__re) \
  : "r"(__PointInImage__bn), "r"(__PointInImage_point), "r"(__PointInImage_image) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PointInImage__re; \
  }); \
  _PointInImage__re; \
})

#define EraseImage(rp, image, leftOffset, topOffset) ({ \
  struct RastPort * _EraseImage_rp = (rp); \
  struct Image * _EraseImage_image = (image); \
  LONG _EraseImage_leftOffset = (leftOffset); \
  LONG _EraseImage_topOffset = (topOffset); \
  { \
  register struct Library * const __EraseImage__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __EraseImage_rp __asm("a0") = (_EraseImage_rp); \
  register struct Image * __EraseImage_image __asm("a1") = (_EraseImage_image); \
  register LONG __EraseImage_leftOffset __asm("d0") = (_EraseImage_leftOffset); \
  register LONG __EraseImage_topOffset __asm("d1") = (_EraseImage_topOffset); \
  __asm volatile ("jsr a6@(-630:W)" \
  : \
  : "r"(__EraseImage__bn), "r"(__EraseImage_rp), "r"(__EraseImage_image), "r"(__EraseImage_leftOffset), "r"(__EraseImage_topOffset) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define NewObjectA(classPtr, classID, tagList) ({ \
  struct IClass * _NewObjectA_classPtr = (classPtr); \
  CONST_STRPTR _NewObjectA_classID = (classID); \
  const struct TagItem * _NewObjectA_tagList = (tagList); \
  APTR _NewObjectA__re = \
  ({ \
  register struct Library * const __NewObjectA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __NewObjectA__re __asm("d0"); \
  register struct IClass * __NewObjectA_classPtr __asm("a0") = (_NewObjectA_classPtr); \
  register CONST_STRPTR __NewObjectA_classID __asm("a1") = (_NewObjectA_classID); \
  register const struct TagItem * __NewObjectA_tagList __asm("a2") = (_NewObjectA_tagList); \
  __asm volatile ("jsr a6@(-636:W)" \
  : "=r"(__NewObjectA__re) \
  : "r"(__NewObjectA__bn), "r"(__NewObjectA_classPtr), "r"(__NewObjectA_classID), "r"(__NewObjectA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NewObjectA__re; \
  }); \
  _NewObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___NewObject(struct Library * IntuitionBase, struct IClass * classPtr, CONST_STRPTR classID, ULONG tagList, ...)
{
  return NewObjectA(classPtr, classID, (const struct TagItem *) &tagList);
}

#define NewObject(classPtr, classID...) ___NewObject((struct Library *) INTUITION_BASE_NAME, classPtr, classID)
#endif

#define DisposeObject(object) ({ \
  APTR _DisposeObject_object = (object); \
  { \
  register struct Library * const __DisposeObject__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __DisposeObject_object __asm("a0") = (_DisposeObject_object); \
  __asm volatile ("jsr a6@(-642:W)" \
  : \
  : "r"(__DisposeObject__bn), "r"(__DisposeObject_object) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetAttrsA(object, tagList) ({ \
  APTR _SetAttrsA_object = (object); \
  const struct TagItem * _SetAttrsA_tagList = (tagList); \
  ULONG _SetAttrsA__re = \
  ({ \
  register struct Library * const __SetAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __SetAttrsA__re __asm("d0"); \
  register APTR __SetAttrsA_object __asm("a0") = (_SetAttrsA_object); \
  register const struct TagItem * __SetAttrsA_tagList __asm("a1") = (_SetAttrsA_tagList); \
  __asm volatile ("jsr a6@(-648:W)" \
  : "=r"(__SetAttrsA__re) \
  : "r"(__SetAttrsA__bn), "r"(__SetAttrsA_object), "r"(__SetAttrsA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetAttrsA__re; \
  }); \
  _SetAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___SetAttrs(struct Library * IntuitionBase, APTR object, ULONG tagList, ...)
{
  return SetAttrsA(object, (const struct TagItem *) &tagList);
}

#define SetAttrs(object...) ___SetAttrs((struct Library *) INTUITION_BASE_NAME, object)
#endif

#define GetAttr(attrID, object, storagePtr) ({ \
  ULONG _GetAttr_attrID = (attrID); \
  APTR _GetAttr_object = (object); \
  ULONG * _GetAttr_storagePtr = (storagePtr); \
  ULONG _GetAttr__re = \
  ({ \
  register struct Library * const __GetAttr__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __GetAttr__re __asm("d0"); \
  register ULONG __GetAttr_attrID __asm("d0") = (_GetAttr_attrID); \
  register APTR __GetAttr_object __asm("a0") = (_GetAttr_object); \
  register ULONG * __GetAttr_storagePtr __asm("a1") = (_GetAttr_storagePtr); \
  __asm volatile ("jsr a6@(-654:W)" \
  : "=r"(__GetAttr__re) \
  : "r"(__GetAttr__bn), "r"(__GetAttr_attrID), "r"(__GetAttr_object), "r"(__GetAttr_storagePtr) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetAttr__re; \
  }); \
  _GetAttr__re; \
})

#define SetGadgetAttrsA(gadget, window, requester, tagList) ({ \
  struct Gadget * _SetGadgetAttrsA_gadget = (gadget); \
  struct Window * _SetGadgetAttrsA_window = (window); \
  struct Requester * _SetGadgetAttrsA_requester = (requester); \
  const struct TagItem * _SetGadgetAttrsA_tagList = (tagList); \
  ULONG _SetGadgetAttrsA__re = \
  ({ \
  register struct Library * const __SetGadgetAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __SetGadgetAttrsA__re __asm("d0"); \
  register struct Gadget * __SetGadgetAttrsA_gadget __asm("a0") = (_SetGadgetAttrsA_gadget); \
  register struct Window * __SetGadgetAttrsA_window __asm("a1") = (_SetGadgetAttrsA_window); \
  register struct Requester * __SetGadgetAttrsA_requester __asm("a2") = (_SetGadgetAttrsA_requester); \
  register const struct TagItem * __SetGadgetAttrsA_tagList __asm("a3") = (_SetGadgetAttrsA_tagList); \
  __asm volatile ("jsr a6@(-660:W)" \
  : "=r"(__SetGadgetAttrsA__re) \
  : "r"(__SetGadgetAttrsA__bn), "r"(__SetGadgetAttrsA_gadget), "r"(__SetGadgetAttrsA_window), "r"(__SetGadgetAttrsA_requester), "r"(__SetGadgetAttrsA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetGadgetAttrsA__re; \
  }); \
  _SetGadgetAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___SetGadgetAttrs(struct Library * IntuitionBase, struct Gadget * gadget, struct Window * window, struct Requester * requester, ULONG tagList, ...)
{
  return SetGadgetAttrsA(gadget, window, requester, (const struct TagItem *) &tagList);
}

#define SetGadgetAttrs(gadget, window, requester...) ___SetGadgetAttrs((struct Library *) INTUITION_BASE_NAME, gadget, window, requester)
#endif

#define NextObject(objectPtrPtr) ({ \
  APTR _NextObject_objectPtrPtr = (objectPtrPtr); \
  APTR _NextObject__re = \
  ({ \
  register struct Library * const __NextObject__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __NextObject__re __asm("d0"); \
  register APTR __NextObject_objectPtrPtr __asm("a0") = (_NextObject_objectPtrPtr); \
  __asm volatile ("jsr a6@(-666:W)" \
  : "=r"(__NextObject__re) \
  : "r"(__NextObject__bn), "r"(__NextObject_objectPtrPtr) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NextObject__re; \
  }); \
  _NextObject__re; \
})

#define MakeClass(classID, superClassID, superClassPtr, instanceSize, flags) ({ \
  CONST_STRPTR _MakeClass_classID = (classID); \
  CONST_STRPTR _MakeClass_superClassID = (superClassID); \
  const struct IClass * _MakeClass_superClassPtr = (superClassPtr); \
  ULONG _MakeClass_instanceSize = (instanceSize); \
  ULONG _MakeClass_flags = (flags); \
  struct IClass * _MakeClass__re = \
  ({ \
  register struct Library * const __MakeClass__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct IClass * __MakeClass__re __asm("d0"); \
  register CONST_STRPTR __MakeClass_classID __asm("a0") = (_MakeClass_classID); \
  register CONST_STRPTR __MakeClass_superClassID __asm("a1") = (_MakeClass_superClassID); \
  register const struct IClass * __MakeClass_superClassPtr __asm("a2") = (_MakeClass_superClassPtr); \
  register ULONG __MakeClass_instanceSize __asm("d0") = (_MakeClass_instanceSize); \
  register ULONG __MakeClass_flags __asm("d1") = (_MakeClass_flags); \
  __asm volatile ("jsr a6@(-678:W)" \
  : "=r"(__MakeClass__re) \
  : "r"(__MakeClass__bn), "r"(__MakeClass_classID), "r"(__MakeClass_superClassID), "r"(__MakeClass_superClassPtr), "r"(__MakeClass_instanceSize), "r"(__MakeClass_flags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __MakeClass__re; \
  }); \
  _MakeClass__re; \
})

#define AddClass(classPtr) ({ \
  struct IClass * _AddClass_classPtr = (classPtr); \
  { \
  register struct Library * const __AddClass__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct IClass * __AddClass_classPtr __asm("a0") = (_AddClass_classPtr); \
  __asm volatile ("jsr a6@(-684:W)" \
  : \
  : "r"(__AddClass__bn), "r"(__AddClass_classPtr) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetScreenDrawInfo(screen) ({ \
  struct Screen * _GetScreenDrawInfo_screen = (screen); \
  struct DrawInfo * _GetScreenDrawInfo__re = \
  ({ \
  register struct Library * const __GetScreenDrawInfo__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct DrawInfo * __GetScreenDrawInfo__re __asm("d0"); \
  register struct Screen * __GetScreenDrawInfo_screen __asm("a0") = (_GetScreenDrawInfo_screen); \
  __asm volatile ("jsr a6@(-690:W)" \
  : "=r"(__GetScreenDrawInfo__re) \
  : "r"(__GetScreenDrawInfo__bn), "r"(__GetScreenDrawInfo_screen) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetScreenDrawInfo__re; \
  }); \
  _GetScreenDrawInfo__re; \
})

#define FreeScreenDrawInfo(screen, drawInfo) ({ \
  struct Screen * _FreeScreenDrawInfo_screen = (screen); \
  struct DrawInfo * _FreeScreenDrawInfo_drawInfo = (drawInfo); \
  { \
  register struct Library * const __FreeScreenDrawInfo__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __FreeScreenDrawInfo_screen __asm("a0") = (_FreeScreenDrawInfo_screen); \
  register struct DrawInfo * __FreeScreenDrawInfo_drawInfo __asm("a1") = (_FreeScreenDrawInfo_drawInfo); \
  __asm volatile ("jsr a6@(-696:W)" \
  : \
  : "r"(__FreeScreenDrawInfo__bn), "r"(__FreeScreenDrawInfo_screen), "r"(__FreeScreenDrawInfo_drawInfo) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ResetMenuStrip(window, menu) ({ \
  struct Window * _ResetMenuStrip_window = (window); \
  struct Menu * _ResetMenuStrip_menu = (menu); \
  BOOL _ResetMenuStrip__re = \
  ({ \
  register struct Library * const __ResetMenuStrip__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __ResetMenuStrip__re __asm("d0"); \
  register struct Window * __ResetMenuStrip_window __asm("a0") = (_ResetMenuStrip_window); \
  register struct Menu * __ResetMenuStrip_menu __asm("a1") = (_ResetMenuStrip_menu); \
  __asm volatile ("jsr a6@(-702:W)" \
  : "=r"(__ResetMenuStrip__re) \
  : "r"(__ResetMenuStrip__bn), "r"(__ResetMenuStrip_window), "r"(__ResetMenuStrip_menu) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ResetMenuStrip__re; \
  }); \
  _ResetMenuStrip__re; \
})

#define RemoveClass(classPtr) ({ \
  struct IClass * _RemoveClass_classPtr = (classPtr); \
  { \
  register struct Library * const __RemoveClass__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct IClass * __RemoveClass_classPtr __asm("a0") = (_RemoveClass_classPtr); \
  __asm volatile ("jsr a6@(-708:W)" \
  : \
  : "r"(__RemoveClass__bn), "r"(__RemoveClass_classPtr) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FreeClass(classPtr) ({ \
  struct IClass * _FreeClass_classPtr = (classPtr); \
  BOOL _FreeClass__re = \
  ({ \
  register struct Library * const __FreeClass__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __FreeClass__re __asm("d0"); \
  register struct IClass * __FreeClass_classPtr __asm("a0") = (_FreeClass_classPtr); \
  __asm volatile ("jsr a6@(-714:W)" \
  : "=r"(__FreeClass__re) \
  : "r"(__FreeClass__bn), "r"(__FreeClass_classPtr) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FreeClass__re; \
  }); \
  _FreeClass__re; \
})

#define AllocScreenBuffer(sc, bm, flags) ({ \
  struct Screen * _AllocScreenBuffer_sc = (sc); \
  struct BitMap * _AllocScreenBuffer_bm = (bm); \
  ULONG _AllocScreenBuffer_flags = (flags); \
  struct ScreenBuffer * _AllocScreenBuffer__re = \
  ({ \
  register struct Library * const __AllocScreenBuffer__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct ScreenBuffer * __AllocScreenBuffer__re __asm("d0"); \
  register struct Screen * __AllocScreenBuffer_sc __asm("a0") = (_AllocScreenBuffer_sc); \
  register struct BitMap * __AllocScreenBuffer_bm __asm("a1") = (_AllocScreenBuffer_bm); \
  register ULONG __AllocScreenBuffer_flags __asm("d0") = (_AllocScreenBuffer_flags); \
  __asm volatile ("jsr a6@(-768:W)" \
  : "=r"(__AllocScreenBuffer__re) \
  : "r"(__AllocScreenBuffer__bn), "r"(__AllocScreenBuffer_sc), "r"(__AllocScreenBuffer_bm), "r"(__AllocScreenBuffer_flags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocScreenBuffer__re; \
  }); \
  _AllocScreenBuffer__re; \
})

#define FreeScreenBuffer(sc, sb) ({ \
  struct Screen * _FreeScreenBuffer_sc = (sc); \
  struct ScreenBuffer * _FreeScreenBuffer_sb = (sb); \
  { \
  register struct Library * const __FreeScreenBuffer__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __FreeScreenBuffer_sc __asm("a0") = (_FreeScreenBuffer_sc); \
  register struct ScreenBuffer * __FreeScreenBuffer_sb __asm("a1") = (_FreeScreenBuffer_sb); \
  __asm volatile ("jsr a6@(-774:W)" \
  : \
  : "r"(__FreeScreenBuffer__bn), "r"(__FreeScreenBuffer_sc), "r"(__FreeScreenBuffer_sb) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ChangeScreenBuffer(sc, sb) ({ \
  struct Screen * _ChangeScreenBuffer_sc = (sc); \
  struct ScreenBuffer * _ChangeScreenBuffer_sb = (sb); \
  ULONG _ChangeScreenBuffer__re = \
  ({ \
  register struct Library * const __ChangeScreenBuffer__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __ChangeScreenBuffer__re __asm("d0"); \
  register struct Screen * __ChangeScreenBuffer_sc __asm("a0") = (_ChangeScreenBuffer_sc); \
  register struct ScreenBuffer * __ChangeScreenBuffer_sb __asm("a1") = (_ChangeScreenBuffer_sb); \
  __asm volatile ("jsr a6@(-780:W)" \
  : "=r"(__ChangeScreenBuffer__re) \
  : "r"(__ChangeScreenBuffer__bn), "r"(__ChangeScreenBuffer_sc), "r"(__ChangeScreenBuffer_sb) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ChangeScreenBuffer__re; \
  }); \
  _ChangeScreenBuffer__re; \
})

#define ScreenDepth(screen, flags, reserved) ({ \
  struct Screen * _ScreenDepth_screen = (screen); \
  ULONG _ScreenDepth_flags = (flags); \
  APTR _ScreenDepth_reserved = (reserved); \
  { \
  register struct Library * const __ScreenDepth__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __ScreenDepth_screen __asm("a0") = (_ScreenDepth_screen); \
  register ULONG __ScreenDepth_flags __asm("d0") = (_ScreenDepth_flags); \
  register APTR __ScreenDepth_reserved __asm("a1") = (_ScreenDepth_reserved); \
  __asm volatile ("jsr a6@(-786:W)" \
  : \
  : "r"(__ScreenDepth__bn), "r"(__ScreenDepth_screen), "r"(__ScreenDepth_flags), "r"(__ScreenDepth_reserved) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ScreenPosition(screen, flags, x1, y1, x2, y2) ({ \
  struct Screen * _ScreenPosition_screen = (screen); \
  ULONG _ScreenPosition_flags = (flags); \
  LONG _ScreenPosition_x1 = (x1); \
  LONG _ScreenPosition_y1 = (y1); \
  LONG _ScreenPosition_x2 = (x2); \
  LONG _ScreenPosition_y2 = (y2); \
  { \
  register struct Library * const __ScreenPosition__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __ScreenPosition_screen __asm("a0") = (_ScreenPosition_screen); \
  register ULONG __ScreenPosition_flags __asm("d0") = (_ScreenPosition_flags); \
  register LONG __ScreenPosition_x1 __asm("d1") = (_ScreenPosition_x1); \
  register LONG __ScreenPosition_y1 __asm("d2") = (_ScreenPosition_y1); \
  register LONG __ScreenPosition_x2 __asm("d3") = (_ScreenPosition_x2); \
  register LONG __ScreenPosition_y2 __asm("d4") = (_ScreenPosition_y2); \
  __asm volatile ("jsr a6@(-792:W)" \
  : \
  : "r"(__ScreenPosition__bn), "r"(__ScreenPosition_screen), "r"(__ScreenPosition_flags), "r"(__ScreenPosition_x1), "r"(__ScreenPosition_y1), "r"(__ScreenPosition_x2), "r"(__ScreenPosition_y2) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ScrollWindowRaster(win, dx, dy, xMin, yMin, xMax, yMax) ({ \
  struct Window * _ScrollWindowRaster_win = (win); \
  LONG _ScrollWindowRaster_dx = (dx); \
  LONG _ScrollWindowRaster_dy = (dy); \
  LONG _ScrollWindowRaster_xMin = (xMin); \
  LONG _ScrollWindowRaster_yMin = (yMin); \
  LONG _ScrollWindowRaster_xMax = (xMax); \
  LONG _ScrollWindowRaster_yMax = (yMax); \
  { \
  register struct Library * const __ScrollWindowRaster__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __ScrollWindowRaster_win __asm("a1") = (_ScrollWindowRaster_win); \
  register LONG __ScrollWindowRaster_dx __asm("d0") = (_ScrollWindowRaster_dx); \
  register LONG __ScrollWindowRaster_dy __asm("d1") = (_ScrollWindowRaster_dy); \
  register LONG __ScrollWindowRaster_xMin __asm("d2") = (_ScrollWindowRaster_xMin); \
  register LONG __ScrollWindowRaster_yMin __asm("d3") = (_ScrollWindowRaster_yMin); \
  register LONG __ScrollWindowRaster_xMax __asm("d4") = (_ScrollWindowRaster_xMax); \
  register LONG __ScrollWindowRaster_yMax __asm("d5") = (_ScrollWindowRaster_yMax); \
  __asm volatile ("jsr a6@(-798:W)" \
  : \
  : "r"(__ScrollWindowRaster__bn), "r"(__ScrollWindowRaster_win), "r"(__ScrollWindowRaster_dx), "r"(__ScrollWindowRaster_dy), "r"(__ScrollWindowRaster_xMin), "r"(__ScrollWindowRaster_yMin), "r"(__ScrollWindowRaster_xMax), "r"(__ScrollWindowRaster_yMax) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define LendMenus(fromwindow, towindow) ({ \
  struct Window * _LendMenus_fromwindow = (fromwindow); \
  struct Window * _LendMenus_towindow = (towindow); \
  { \
  register struct Library * const __LendMenus__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __LendMenus_fromwindow __asm("a0") = (_LendMenus_fromwindow); \
  register struct Window * __LendMenus_towindow __asm("a1") = (_LendMenus_towindow); \
  __asm volatile ("jsr a6@(-804:W)" \
  : \
  : "r"(__LendMenus__bn), "r"(__LendMenus_fromwindow), "r"(__LendMenus_towindow) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DoGadgetMethodA(gad, win, req, message) ({ \
  struct Gadget * _DoGadgetMethodA_gad = (gad); \
  struct Window * _DoGadgetMethodA_win = (win); \
  struct Requester * _DoGadgetMethodA_req = (req); \
  Msg _DoGadgetMethodA_message = (message); \
  ULONG _DoGadgetMethodA__re = \
  ({ \
  register struct Library * const __DoGadgetMethodA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __DoGadgetMethodA__re __asm("d0"); \
  register struct Gadget * __DoGadgetMethodA_gad __asm("a0") = (_DoGadgetMethodA_gad); \
  register struct Window * __DoGadgetMethodA_win __asm("a1") = (_DoGadgetMethodA_win); \
  register struct Requester * __DoGadgetMethodA_req __asm("a2") = (_DoGadgetMethodA_req); \
  register Msg __DoGadgetMethodA_message __asm("a3") = (_DoGadgetMethodA_message); \
  __asm volatile ("jsr a6@(-810:W)" \
  : "=r"(__DoGadgetMethodA__re) \
  : "r"(__DoGadgetMethodA__bn), "r"(__DoGadgetMethodA_gad), "r"(__DoGadgetMethodA_win), "r"(__DoGadgetMethodA_req), "r"(__DoGadgetMethodA_message) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DoGadgetMethodA__re; \
  }); \
  _DoGadgetMethodA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___DoGadgetMethod(struct Library * IntuitionBase, struct Gadget * gad, struct Window * win, struct Requester * req, ULONG message, ...)
{
  return DoGadgetMethodA(gad, win, req, (Msg) &message);
}

#define DoGadgetMethod(gad, win, req...) ___DoGadgetMethod((struct Library *) INTUITION_BASE_NAME, gad, win, req)
#endif

#define SetWindowPointerA(win, taglist) ({ \
  struct Window * _SetWindowPointerA_win = (win); \
  const struct TagItem * _SetWindowPointerA_taglist = (taglist); \
  { \
  register struct Library * const __SetWindowPointerA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __SetWindowPointerA_win __asm("a0") = (_SetWindowPointerA_win); \
  register const struct TagItem * __SetWindowPointerA_taglist __asm("a1") = (_SetWindowPointerA_taglist); \
  __asm volatile ("jsr a6@(-816:W)" \
  : \
  : "r"(__SetWindowPointerA__bn), "r"(__SetWindowPointerA_win), "r"(__SetWindowPointerA_taglist) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___SetWindowPointer(struct Library * IntuitionBase, struct Window * win, ULONG taglist, ...)
{
  SetWindowPointerA(win, (const struct TagItem *) &taglist);
}

#define SetWindowPointer(win...) ___SetWindowPointer((struct Library *) INTUITION_BASE_NAME, win)
#endif

#define TimedDisplayAlert(alertNumber, string, height, Time) ({ \
  ULONG _TimedDisplayAlert_alertNumber = (alertNumber); \
  CONST_STRPTR _TimedDisplayAlert_string = (string); \
  ULONG _TimedDisplayAlert_height = (height); \
  ULONG _TimedDisplayAlert_Time = (Time); \
  BOOL _TimedDisplayAlert__re = \
  ({ \
  register struct Library * const __TimedDisplayAlert__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __TimedDisplayAlert__re __asm("d0"); \
  register ULONG __TimedDisplayAlert_alertNumber __asm("d0") = (_TimedDisplayAlert_alertNumber); \
  register CONST_STRPTR __TimedDisplayAlert_string __asm("a0") = (_TimedDisplayAlert_string); \
  register ULONG __TimedDisplayAlert_height __asm("d1") = (_TimedDisplayAlert_height); \
  register ULONG __TimedDisplayAlert_Time __asm("a1") = (_TimedDisplayAlert_Time); \
  __asm volatile ("jsr a6@(-822:W)" \
  : "=r"(__TimedDisplayAlert__re) \
  : "r"(__TimedDisplayAlert__bn), "r"(__TimedDisplayAlert_alertNumber), "r"(__TimedDisplayAlert_string), "r"(__TimedDisplayAlert_height), "r"(__TimedDisplayAlert_Time) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __TimedDisplayAlert__re; \
  }); \
  _TimedDisplayAlert__re; \
})

#define HelpControl(win, flags) ({ \
  struct Window * _HelpControl_win = (win); \
  ULONG _HelpControl_flags = (flags); \
  { \
  register struct Library * const __HelpControl__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Window * __HelpControl_win __asm("a0") = (_HelpControl_win); \
  register ULONG __HelpControl_flags __asm("d0") = (_HelpControl_flags); \
  __asm volatile ("jsr a6@(-828:W)" \
  : \
  : "r"(__HelpControl__bn), "r"(__HelpControl_win), "r"(__HelpControl_flags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ShowWindow(window, other) ({ \
  struct Window * _ShowWindow_window = (window); \
  struct Window * _ShowWindow_other = (other); \
  BOOL _ShowWindow__re = \
  ({ \
  register struct Library * const __ShowWindow__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __ShowWindow__re __asm("d0"); \
  register struct Window * __ShowWindow_window __asm("a0") = (_ShowWindow_window); \
  register struct Window * __ShowWindow_other __asm("a1") = (_ShowWindow_other); \
  __asm volatile ("jsr a6@(-834:W)" \
  : "=r"(__ShowWindow__re) \
  : "r"(__ShowWindow__bn), "r"(__ShowWindow_window), "r"(__ShowWindow_other) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ShowWindow__re; \
  }); \
  _ShowWindow__re; \
})

#define HideWindow(window) ({ \
  struct Window * _HideWindow_window = (window); \
  BOOL _HideWindow__re = \
  ({ \
  register struct Library * const __HideWindow__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __HideWindow__re __asm("d0"); \
  register struct Window * __HideWindow_window __asm("a0") = (_HideWindow_window); \
  __asm volatile ("jsr a6@(-840:W)" \
  : "=r"(__HideWindow__re) \
  : "r"(__HideWindow__bn), "r"(__HideWindow_window) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __HideWindow__re; \
  }); \
  _HideWindow__re; \
})

#define GetAttrsA(object, tagList) ({ \
  APTR _GetAttrsA_object = (object); \
  CONST struct TagItem * _GetAttrsA_tagList = (tagList); \
  ULONG _GetAttrsA__re = \
  ({ \
  register struct Library * const __GetAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __GetAttrsA__re __asm("d0"); \
  register APTR __GetAttrsA_object __asm("a0") = (_GetAttrsA_object); \
  register CONST struct TagItem * __GetAttrsA_tagList __asm("a1") = (_GetAttrsA_tagList); \
  __asm volatile ("jsr a6@(-846:W)" \
  : "=r"(__GetAttrsA__re) \
  : "r"(__GetAttrsA__bn), "r"(__GetAttrsA_object), "r"(__GetAttrsA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetAttrsA__re; \
  }); \
  _GetAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___GetAttrs(struct Library * IntuitionBase, APTR object, Tag tagList, ...)
{
  return GetAttrsA(object, (CONST struct TagItem *) &tagList);
}

#define GetAttrs(object...) ___GetAttrs((struct Library *) INTUITION_BASE_NAME, object)
#endif

#define LockGUIPrefs(reserved) ({ \
  ULONG _LockGUIPrefs_reserved = (reserved); \
  APTR _LockGUIPrefs__re = \
  ({ \
  register struct Library * const __LockGUIPrefs__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __LockGUIPrefs__re __asm("d0"); \
  register ULONG __LockGUIPrefs_reserved __asm("a0") = (_LockGUIPrefs_reserved); \
  __asm volatile ("jsr a6@(-852:W)" \
  : "=r"(__LockGUIPrefs__re) \
  : "r"(__LockGUIPrefs__bn), "r"(__LockGUIPrefs_reserved) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LockGUIPrefs__re; \
  }); \
  _LockGUIPrefs__re; \
})

#define UnlockGUIPrefs(lock) ({ \
  APTR _UnlockGUIPrefs_lock = (lock); \
  { \
  register struct Library * const __UnlockGUIPrefs__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __UnlockGUIPrefs_lock __asm("a0") = (_UnlockGUIPrefs_lock); \
  __asm volatile ("jsr a6@(-858:W)" \
  : \
  : "r"(__UnlockGUIPrefs__bn), "r"(__UnlockGUIPrefs_lock) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetGUIAttrsA(reserved, drawinfo, taglist) ({ \
  APTR _SetGUIAttrsA_reserved = (reserved); \
  struct DrawInfo * _SetGUIAttrsA_drawinfo = (drawinfo); \
  struct TagItem * _SetGUIAttrsA_taglist = (taglist); \
  ULONG _SetGUIAttrsA__re = \
  ({ \
  register struct Library * const __SetGUIAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __SetGUIAttrsA__re __asm("d0"); \
  register APTR __SetGUIAttrsA_reserved __asm("a0") = (_SetGUIAttrsA_reserved); \
  register struct DrawInfo * __SetGUIAttrsA_drawinfo __asm("a1") = (_SetGUIAttrsA_drawinfo); \
  register struct TagItem * __SetGUIAttrsA_taglist __asm("a2") = (_SetGUIAttrsA_taglist); \
  __asm volatile ("jsr a6@(-864:W)" \
  : "=r"(__SetGUIAttrsA__re) \
  : "r"(__SetGUIAttrsA__bn), "r"(__SetGUIAttrsA_reserved), "r"(__SetGUIAttrsA_drawinfo), "r"(__SetGUIAttrsA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetGUIAttrsA__re; \
  }); \
  _SetGUIAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___SetGUIAttrs(struct Library * IntuitionBase, APTR reserved, struct DrawInfo * drawinfo, Tag taglist, ...)
{
  return SetGUIAttrsA(reserved, drawinfo, (struct TagItem *) &taglist);
}

#define SetGUIAttrs(reserved, drawinfo...) ___SetGUIAttrs((struct Library *) INTUITION_BASE_NAME, reserved, drawinfo)
#endif

#define GetGUIAttrsA(reserved, drawinfo, taglist) ({ \
  APTR _GetGUIAttrsA_reserved = (reserved); \
  struct DrawInfo * _GetGUIAttrsA_drawinfo = (drawinfo); \
  struct TagItem * _GetGUIAttrsA_taglist = (taglist); \
  ULONG _GetGUIAttrsA__re = \
  ({ \
  register struct Library * const __GetGUIAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __GetGUIAttrsA__re __asm("d0"); \
  register APTR __GetGUIAttrsA_reserved __asm("a0") = (_GetGUIAttrsA_reserved); \
  register struct DrawInfo * __GetGUIAttrsA_drawinfo __asm("a1") = (_GetGUIAttrsA_drawinfo); \
  register struct TagItem * __GetGUIAttrsA_taglist __asm("a2") = (_GetGUIAttrsA_taglist); \
  __asm volatile ("jsr a6@(-870:W)" \
  : "=r"(__GetGUIAttrsA__re) \
  : "r"(__GetGUIAttrsA__bn), "r"(__GetGUIAttrsA_reserved), "r"(__GetGUIAttrsA_drawinfo), "r"(__GetGUIAttrsA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetGUIAttrsA__re; \
  }); \
  _GetGUIAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___GetGUIAttrs(struct Library * IntuitionBase, APTR reserved, struct DrawInfo * drawinfo, Tag taglist, ...)
{
  return GetGUIAttrsA(reserved, drawinfo, (struct TagItem *) &taglist);
}

#define GetGUIAttrs(reserved, drawinfo...) ___GetGUIAttrs((struct Library *) INTUITION_BASE_NAME, reserved, drawinfo)
#endif

#define GetHalfPens(drawinfo, basepen, halfshineptr, halfshadowptr) ({ \
  struct DrawInfo * _GetHalfPens_drawinfo = (drawinfo); \
  ULONG _GetHalfPens_basepen = (basepen); \
  UWORD * _GetHalfPens_halfshineptr = (halfshineptr); \
  UWORD * _GetHalfPens_halfshadowptr = (halfshadowptr); \
  ULONG _GetHalfPens__re = \
  ({ \
  register struct Library * const __GetHalfPens__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __GetHalfPens__re __asm("d0"); \
  register struct DrawInfo * __GetHalfPens_drawinfo __asm("a0") = (_GetHalfPens_drawinfo); \
  register ULONG __GetHalfPens_basepen __asm("d0") = (_GetHalfPens_basepen); \
  register UWORD * __GetHalfPens_halfshineptr __asm("a1") = (_GetHalfPens_halfshineptr); \
  register UWORD * __GetHalfPens_halfshadowptr __asm("a2") = (_GetHalfPens_halfshadowptr); \
  __asm volatile ("jsr a6@(-876:W)" \
  : "=r"(__GetHalfPens__re) \
  : "r"(__GetHalfPens__bn), "r"(__GetHalfPens_drawinfo), "r"(__GetHalfPens_basepen), "r"(__GetHalfPens_halfshineptr), "r"(__GetHalfPens_halfshadowptr) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetHalfPens__re; \
  }); \
  _GetHalfPens__re; \
})

#define GadgetBox(gadget, domain, domaintype, flags, box) ({ \
  struct Gadget * _GadgetBox_gadget = (gadget); \
  APTR _GadgetBox_domain = (domain); \
  ULONG _GadgetBox_domaintype = (domaintype); \
  ULONG _GadgetBox_flags = (flags); \
  APTR _GadgetBox_box = (box); \
  ULONG _GadgetBox__re = \
  ({ \
  register struct Library * const __GadgetBox__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __GadgetBox__re __asm("d0"); \
  register struct Gadget * __GadgetBox_gadget __asm("a0") = (_GadgetBox_gadget); \
  register APTR __GadgetBox_domain __asm("a1") = (_GadgetBox_domain); \
  register ULONG __GadgetBox_domaintype __asm("d0") = (_GadgetBox_domaintype); \
  register ULONG __GadgetBox_flags __asm("d1") = (_GadgetBox_flags); \
  register APTR __GadgetBox_box __asm("a2") = (_GadgetBox_box); \
  __asm volatile ("jsr a6@(-882:W)" \
  : "=r"(__GadgetBox__re) \
  : "r"(__GadgetBox__bn), "r"(__GadgetBox_gadget), "r"(__GadgetBox_domain), "r"(__GadgetBox_domaintype), "r"(__GadgetBox_flags), "r"(__GadgetBox_box) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GadgetBox__re; \
  }); \
  _GadgetBox__re; \
})

#define RefreshSetGadgetAttrsA(gadget, window, req, taglist) ({ \
  struct Gadget * _RefreshSetGadgetAttrsA_gadget = (gadget); \
  struct Window * _RefreshSetGadgetAttrsA_window = (window); \
  struct Requester * _RefreshSetGadgetAttrsA_req = (req); \
  struct TagItem * _RefreshSetGadgetAttrsA_taglist = (taglist); \
  { \
  register struct Library * const __RefreshSetGadgetAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Gadget * __RefreshSetGadgetAttrsA_gadget __asm("a0") = (_RefreshSetGadgetAttrsA_gadget); \
  register struct Window * __RefreshSetGadgetAttrsA_window __asm("a1") = (_RefreshSetGadgetAttrsA_window); \
  register struct Requester * __RefreshSetGadgetAttrsA_req __asm("a2") = (_RefreshSetGadgetAttrsA_req); \
  register struct TagItem * __RefreshSetGadgetAttrsA_taglist __asm("a3") = (_RefreshSetGadgetAttrsA_taglist); \
  __asm volatile ("jsr a6@(-888:W)" \
  : \
  : "r"(__RefreshSetGadgetAttrsA__bn), "r"(__RefreshSetGadgetAttrsA_gadget), "r"(__RefreshSetGadgetAttrsA_window), "r"(__RefreshSetGadgetAttrsA_req), "r"(__RefreshSetGadgetAttrsA_taglist) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___RefreshSetGadgetAttrs(struct Library * IntuitionBase, struct Gadget * gadget, struct Window * window, struct Requester * req, Tag taglist, ...)
{
  RefreshSetGadgetAttrsA(gadget, window, req, (struct TagItem *) &taglist);
}

#define RefreshSetGadgetAttrs(gadget, window, req...) ___RefreshSetGadgetAttrs((struct Library *) INTUITION_BASE_NAME, gadget, window, req)
#endif

#define IDoSuperMethodA(cl, object, msg) ({ \
  Class * _IDoSuperMethodA_cl = (cl); \
  Object * _IDoSuperMethodA_object = (object); \
  Msg _IDoSuperMethodA_msg = (msg); \
  ULONG _IDoSuperMethodA__re = \
  ({ \
  register struct Library * const __IDoSuperMethodA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __IDoSuperMethodA__re __asm("d0"); \
  register Class * __IDoSuperMethodA_cl __asm("a0") = (_IDoSuperMethodA_cl); \
  register Object * __IDoSuperMethodA_object __asm("a2") = (_IDoSuperMethodA_object); \
  register Msg __IDoSuperMethodA_msg __asm("a1") = (_IDoSuperMethodA_msg); \
  __asm volatile ("jsr a6@(-894:W)" \
  : "=r"(__IDoSuperMethodA__re) \
  : "r"(__IDoSuperMethodA__bn), "r"(__IDoSuperMethodA_cl), "r"(__IDoSuperMethodA_object), "r"(__IDoSuperMethodA_msg) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IDoSuperMethodA__re; \
  }); \
  _IDoSuperMethodA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___IDoSuperMethod(struct Library * IntuitionBase, Class * cl, Object * object, Tag msg, ...)
{
  return IDoSuperMethodA(cl, object, (Msg) &msg);
}

#define IDoSuperMethod(cl, object...) ___IDoSuperMethod((struct Library *) INTUITION_BASE_NAME, cl, object)
#endif

#define ISetSuperAttrsA(cl, object, taglist) ({ \
  Class * _ISetSuperAttrsA_cl = (cl); \
  Object * _ISetSuperAttrsA_object = (object); \
  struct TagItem * _ISetSuperAttrsA_taglist = (taglist); \
  ULONG _ISetSuperAttrsA__re = \
  ({ \
  register struct Library * const __ISetSuperAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __ISetSuperAttrsA__re __asm("d0"); \
  register Class * __ISetSuperAttrsA_cl __asm("a0") = (_ISetSuperAttrsA_cl); \
  register Object * __ISetSuperAttrsA_object __asm("a2") = (_ISetSuperAttrsA_object); \
  register struct TagItem * __ISetSuperAttrsA_taglist __asm("a1") = (_ISetSuperAttrsA_taglist); \
  __asm volatile ("jsr a6@(-900:W)" \
  : "=r"(__ISetSuperAttrsA__re) \
  : "r"(__ISetSuperAttrsA__bn), "r"(__ISetSuperAttrsA_cl), "r"(__ISetSuperAttrsA_object), "r"(__ISetSuperAttrsA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ISetSuperAttrsA__re; \
  }); \
  _ISetSuperAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___ISetSuperAttrs(struct Library * IntuitionBase, Class * cl, Object * object, Tag taglist, ...)
{
  return ISetSuperAttrsA(cl, object, (struct TagItem *) &taglist);
}

#define ISetSuperAttrs(cl, object...) ___ISetSuperAttrs((struct Library *) INTUITION_BASE_NAME, cl, object)
#endif

#define ICoerceMethodA(cl, object, msg) ({ \
  Class * _ICoerceMethodA_cl = (cl); \
  Object * _ICoerceMethodA_object = (object); \
  Msg _ICoerceMethodA_msg = (msg); \
  ULONG _ICoerceMethodA__re = \
  ({ \
  register struct Library * const __ICoerceMethodA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __ICoerceMethodA__re __asm("d0"); \
  register Class * __ICoerceMethodA_cl __asm("a0") = (_ICoerceMethodA_cl); \
  register Object * __ICoerceMethodA_object __asm("a2") = (_ICoerceMethodA_object); \
  register Msg __ICoerceMethodA_msg __asm("a1") = (_ICoerceMethodA_msg); \
  __asm volatile ("jsr a6@(-906:W)" \
  : "=r"(__ICoerceMethodA__re) \
  : "r"(__ICoerceMethodA__bn), "r"(__ICoerceMethodA_cl), "r"(__ICoerceMethodA_object), "r"(__ICoerceMethodA_msg) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ICoerceMethodA__re; \
  }); \
  _ICoerceMethodA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___ICoerceMethod(struct Library * IntuitionBase, Class * cl, Object * object, Tag msg, ...)
{
  return ICoerceMethodA(cl, object, (Msg) &msg);
}

#define ICoerceMethod(cl, object...) ___ICoerceMethod((struct Library *) INTUITION_BASE_NAME, cl, object)
#endif

#define IDoMethodA(object, msg) ({ \
  Object * _IDoMethodA_object = (object); \
  Msg _IDoMethodA_msg = (msg); \
  ULONG _IDoMethodA__re = \
  ({ \
  register struct Library * const __IDoMethodA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __IDoMethodA__re __asm("d0"); \
  register Object * __IDoMethodA_object __asm("a2") = (_IDoMethodA_object); \
  register Msg __IDoMethodA_msg __asm("a1") = (_IDoMethodA_msg); \
  __asm volatile ("jsr a6@(-912:W)" \
  : "=r"(__IDoMethodA__re) \
  : "r"(__IDoMethodA__bn), "r"(__IDoMethodA_object), "r"(__IDoMethodA_msg) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IDoMethodA__re; \
  }); \
  _IDoMethodA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___IDoMethod(struct Library * IntuitionBase, Object * object, Tag msg, ...)
{
  return IDoMethodA(object, (Msg) &msg);
}

#define IDoMethod(object...) ___IDoMethod((struct Library *) INTUITION_BASE_NAME, object)
#endif

#define OpenClass(name, version, cl_ptr) ({ \
  STRPTR _OpenClass_name = (name); \
  ULONG _OpenClass_version = (version); \
  Class ** _OpenClass_cl_ptr = (cl_ptr); \
  struct ClassLibrary * _OpenClass__re = \
  ({ \
  register struct Library * const __OpenClass__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct ClassLibrary * __OpenClass__re __asm("d0"); \
  register STRPTR __OpenClass_name __asm("a0") = (_OpenClass_name); \
  register ULONG __OpenClass_version __asm("d0") = (_OpenClass_version); \
  register Class ** __OpenClass_cl_ptr __asm("a1") = (_OpenClass_cl_ptr); \
  __asm volatile ("jsr a6@(-918:W)" \
  : "=r"(__OpenClass__re) \
  : "r"(__OpenClass__bn), "r"(__OpenClass_name), "r"(__OpenClass_version), "r"(__OpenClass_cl_ptr) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenClass__re; \
  }); \
  _OpenClass__re; \
})

#define CloseClass(cl) ({ \
  struct ClassLibrary * _CloseClass_cl = (cl); \
  { \
  register struct Library * const __CloseClass__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct ClassLibrary * __CloseClass_cl __asm("a0") = (_CloseClass_cl); \
  __asm volatile ("jsr a6@(-924:W)" \
  : \
  : "r"(__CloseClass__bn), "r"(__CloseClass_cl) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define LockScreen(screen, micros) ({ \
  struct Screen * _LockScreen_screen = (screen); \
  ULONG _LockScreen_micros = (micros); \
  BOOL _LockScreen__re = \
  ({ \
  register struct Library * const __LockScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __LockScreen__re __asm("d0"); \
  register struct Screen * __LockScreen_screen __asm("a0") = (_LockScreen_screen); \
  register ULONG __LockScreen_micros __asm("d0") = (_LockScreen_micros); \
  __asm volatile ("jsr a6@(-936:W)" \
  : "=r"(__LockScreen__re) \
  : "r"(__LockScreen__bn), "r"(__LockScreen_screen), "r"(__LockScreen_micros) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LockScreen__re; \
  }); \
  _LockScreen__re; \
})

#define UnlockScreen(screen) ({ \
  struct Screen * _UnlockScreen_screen = (screen); \
  { \
  register struct Library * const __UnlockScreen__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __UnlockScreen_screen __asm("a0") = (_UnlockScreen_screen); \
  __asm volatile ("jsr a6@(-942:W)" \
  : \
  : "r"(__UnlockScreen__bn), "r"(__UnlockScreen_screen) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetWindowAttrsA(win, taglist) ({ \
  struct Window * _GetWindowAttrsA_win = (win); \
  struct TagItem * _GetWindowAttrsA_taglist = (taglist); \
  LONG _GetWindowAttrsA__re = \
  ({ \
  register struct Library * const __GetWindowAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __GetWindowAttrsA__re __asm("d0"); \
  register struct Window * __GetWindowAttrsA_win __asm("a0") = (_GetWindowAttrsA_win); \
  register struct TagItem * __GetWindowAttrsA_taglist __asm("a1") = (_GetWindowAttrsA_taglist); \
  __asm volatile ("jsr a6@(-948:W)" \
  : "=r"(__GetWindowAttrsA__re) \
  : "r"(__GetWindowAttrsA__bn), "r"(__GetWindowAttrsA_win), "r"(__GetWindowAttrsA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetWindowAttrsA__re; \
  }); \
  _GetWindowAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___GetWindowAttrs(struct Library * IntuitionBase, struct Window * win, Tag taglist, ...)
{
  return GetWindowAttrsA(win, (struct TagItem *) &taglist);
}

#define GetWindowAttrs(win...) ___GetWindowAttrs((struct Library *) INTUITION_BASE_NAME, win)
#endif

#define SetWindowAttrsA(win, taglist) ({ \
  struct Window * _SetWindowAttrsA_win = (win); \
  struct TagItem * _SetWindowAttrsA_taglist = (taglist); \
  LONG _SetWindowAttrsA__re = \
  ({ \
  register struct Library * const __SetWindowAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __SetWindowAttrsA__re __asm("d0"); \
  register struct Window * __SetWindowAttrsA_win __asm("a0") = (_SetWindowAttrsA_win); \
  register struct TagItem * __SetWindowAttrsA_taglist __asm("a1") = (_SetWindowAttrsA_taglist); \
  __asm volatile ("jsr a6@(-954:W)" \
  : "=r"(__SetWindowAttrsA__re) \
  : "r"(__SetWindowAttrsA__bn), "r"(__SetWindowAttrsA_win), "r"(__SetWindowAttrsA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetWindowAttrsA__re; \
  }); \
  _SetWindowAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SetWindowAttrs(struct Library * IntuitionBase, struct Window * win, Tag taglist, ...)
{
  return SetWindowAttrsA(win, (struct TagItem *) &taglist);
}

#define SetWindowAttrs(win...) ___SetWindowAttrs((struct Library *) INTUITION_BASE_NAME, win)
#endif

#define GetWindowAttr(win, attr, data, size) ({ \
  struct Window * _GetWindowAttr_win = (win); \
  ULONG _GetWindowAttr_attr = (attr); \
  APTR _GetWindowAttr_data = (data); \
  ULONG _GetWindowAttr_size = (size); \
  LONG _GetWindowAttr__re = \
  ({ \
  register struct Library * const __GetWindowAttr__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __GetWindowAttr__re __asm("d0"); \
  register struct Window * __GetWindowAttr_win __asm("a0") = (_GetWindowAttr_win); \
  register ULONG __GetWindowAttr_attr __asm("d0") = (_GetWindowAttr_attr); \
  register APTR __GetWindowAttr_data __asm("a1") = (_GetWindowAttr_data); \
  register ULONG __GetWindowAttr_size __asm("d1") = (_GetWindowAttr_size); \
  __asm volatile ("jsr a6@(-960:W)" \
  : "=r"(__GetWindowAttr__re) \
  : "r"(__GetWindowAttr__bn), "r"(__GetWindowAttr_win), "r"(__GetWindowAttr_attr), "r"(__GetWindowAttr_data), "r"(__GetWindowAttr_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetWindowAttr__re; \
  }); \
  _GetWindowAttr__re; \
})

#define SetWindowAttr(win, attr, data, size) ({ \
  struct Window * _SetWindowAttr_win = (win); \
  ULONG _SetWindowAttr_attr = (attr); \
  APTR _SetWindowAttr_data = (data); \
  ULONG _SetWindowAttr_size = (size); \
  LONG _SetWindowAttr__re = \
  ({ \
  register struct Library * const __SetWindowAttr__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __SetWindowAttr__re __asm("d0"); \
  register struct Window * __SetWindowAttr_win __asm("a0") = (_SetWindowAttr_win); \
  register ULONG __SetWindowAttr_attr __asm("d0") = (_SetWindowAttr_attr); \
  register APTR __SetWindowAttr_data __asm("a1") = (_SetWindowAttr_data); \
  register ULONG __SetWindowAttr_size __asm("d1") = (_SetWindowAttr_size); \
  __asm volatile ("jsr a6@(-966:W)" \
  : "=r"(__SetWindowAttr__re) \
  : "r"(__SetWindowAttr__bn), "r"(__SetWindowAttr_win), "r"(__SetWindowAttr_attr), "r"(__SetWindowAttr_data), "r"(__SetWindowAttr_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetWindowAttr__re; \
  }); \
  _SetWindowAttr__re; \
})

#define StripIntuiMessages(port, win) ({ \
  struct MsgPort * _StripIntuiMessages_port = (port); \
  struct Window * _StripIntuiMessages_win = (win); \
  { \
  register struct Library * const __StripIntuiMessages__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct MsgPort * __StripIntuiMessages_port __asm("a0") = (_StripIntuiMessages_port); \
  register struct Window * __StripIntuiMessages_win __asm("a1") = (_StripIntuiMessages_win); \
  __asm volatile ("jsr a6@(-972:W)" \
  : \
  : "r"(__StripIntuiMessages__bn), "r"(__StripIntuiMessages_port), "r"(__StripIntuiMessages_win) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetScreenAttrsA(scr, taglist) ({ \
  struct Screen * _GetScreenAttrsA_scr = (scr); \
  struct TagItem * _GetScreenAttrsA_taglist = (taglist); \
  LONG _GetScreenAttrsA__re = \
  ({ \
  register struct Library * const __GetScreenAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __GetScreenAttrsA__re __asm("d0"); \
  register struct Screen * __GetScreenAttrsA_scr __asm("a0") = (_GetScreenAttrsA_scr); \
  register struct TagItem * __GetScreenAttrsA_taglist __asm("a1") = (_GetScreenAttrsA_taglist); \
  __asm volatile ("jsr a6@(-990:W)" \
  : "=r"(__GetScreenAttrsA__re) \
  : "r"(__GetScreenAttrsA__bn), "r"(__GetScreenAttrsA_scr), "r"(__GetScreenAttrsA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetScreenAttrsA__re; \
  }); \
  _GetScreenAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___GetScreenAttrs(struct Library * IntuitionBase, struct Screen * scr, Tag taglist, ...)
{
  return GetScreenAttrsA(scr, (struct TagItem *) &taglist);
}

#define GetScreenAttrs(scr...) ___GetScreenAttrs((struct Library *) INTUITION_BASE_NAME, scr)
#endif

#define SetScreenAttrsA(scr, taglist) ({ \
  struct Screen * _SetScreenAttrsA_scr = (scr); \
  struct TagItem * _SetScreenAttrsA_taglist = (taglist); \
  LONG _SetScreenAttrsA__re = \
  ({ \
  register struct Library * const __SetScreenAttrsA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __SetScreenAttrsA__re __asm("d0"); \
  register struct Screen * __SetScreenAttrsA_scr __asm("a0") = (_SetScreenAttrsA_scr); \
  register struct TagItem * __SetScreenAttrsA_taglist __asm("a1") = (_SetScreenAttrsA_taglist); \
  __asm volatile ("jsr a6@(-996:W)" \
  : "=r"(__SetScreenAttrsA__re) \
  : "r"(__SetScreenAttrsA__bn), "r"(__SetScreenAttrsA_scr), "r"(__SetScreenAttrsA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetScreenAttrsA__re; \
  }); \
  _SetScreenAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SetScreenAttrs(struct Library * IntuitionBase, struct Screen * scr, Tag taglist, ...)
{
  return SetScreenAttrsA(scr, (struct TagItem *) &taglist);
}

#define SetScreenAttrs(scr...) ___SetScreenAttrs((struct Library *) INTUITION_BASE_NAME, scr)
#endif

#define GetScreenAttr(scr, attr, data, size) ({ \
  struct Screen * _GetScreenAttr_scr = (scr); \
  ULONG _GetScreenAttr_attr = (attr); \
  APTR _GetScreenAttr_data = (data); \
  ULONG _GetScreenAttr_size = (size); \
  LONG _GetScreenAttr__re = \
  ({ \
  register struct Library * const __GetScreenAttr__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __GetScreenAttr__re __asm("d0"); \
  register struct Screen * __GetScreenAttr_scr __asm("a0") = (_GetScreenAttr_scr); \
  register ULONG __GetScreenAttr_attr __asm("d0") = (_GetScreenAttr_attr); \
  register APTR __GetScreenAttr_data __asm("a1") = (_GetScreenAttr_data); \
  register ULONG __GetScreenAttr_size __asm("d1") = (_GetScreenAttr_size); \
  __asm volatile ("jsr a6@(-1002:W)" \
  : "=r"(__GetScreenAttr__re) \
  : "r"(__GetScreenAttr__bn), "r"(__GetScreenAttr_scr), "r"(__GetScreenAttr_attr), "r"(__GetScreenAttr_data), "r"(__GetScreenAttr_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetScreenAttr__re; \
  }); \
  _GetScreenAttr__re; \
})

#define SetScreenAttr(scr, attr, data, size) ({ \
  struct Screen * _SetScreenAttr_scr = (scr); \
  ULONG _SetScreenAttr_attr = (attr); \
  APTR _SetScreenAttr_data = (data); \
  ULONG _SetScreenAttr_size = (size); \
  LONG _SetScreenAttr__re = \
  ({ \
  register struct Library * const __SetScreenAttr__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register LONG __SetScreenAttr__re __asm("d0"); \
  register struct Screen * __SetScreenAttr_scr __asm("a0") = (_SetScreenAttr_scr); \
  register ULONG __SetScreenAttr_attr __asm("d0") = (_SetScreenAttr_attr); \
  register APTR __SetScreenAttr_data __asm("a1") = (_SetScreenAttr_data); \
  register ULONG __SetScreenAttr_size __asm("d1") = (_SetScreenAttr_size); \
  __asm volatile ("jsr a6@(-1008:W)" \
  : "=r"(__SetScreenAttr__re) \
  : "r"(__SetScreenAttr__bn), "r"(__SetScreenAttr_scr), "r"(__SetScreenAttr_attr), "r"(__SetScreenAttr_data), "r"(__SetScreenAttr_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetScreenAttr__re; \
  }); \
  _SetScreenAttr__re; \
})

#define LockScreenList() ({ \
  struct Screen * _LockScreenList__re = \
  ({ \
  register struct Library * const __LockScreenList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Screen * __LockScreenList__re __asm("d0"); \
  __asm volatile ("jsr a6@(-1014:W)" \
  : "=r"(__LockScreenList__re) \
  : "r"(__LockScreenList__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LockScreenList__re; \
  }); \
  _LockScreenList__re; \
})

#define UnlockScreenList() ({ \
  register struct Library * const __UnlockScreenList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  __asm volatile ("jsr a6@(-1020:W)" \
  : \
  : "r"(__UnlockScreenList__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define LockScreenGI(gi, micros) ({ \
  struct GadgetInfo * _LockScreenGI_gi = (gi); \
  ULONG _LockScreenGI_micros = (micros); \
  struct RastPort * _LockScreenGI__re = \
  ({ \
  register struct Library * const __LockScreenGI__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __LockScreenGI__re __asm("d0"); \
  register struct GadgetInfo * __LockScreenGI_gi __asm("a0") = (_LockScreenGI_gi); \
  register ULONG __LockScreenGI_micros __asm("d0") = (_LockScreenGI_micros); \
  __asm volatile ("jsr a6@(-1026:W)" \
  : "=r"(__LockScreenGI__re) \
  : "r"(__LockScreenGI__bn), "r"(__LockScreenGI_gi), "r"(__LockScreenGI_micros) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LockScreenGI__re; \
  }); \
  _LockScreenGI__re; \
})

#define UnlockScreenGI(gi, rp) ({ \
  struct GadgetInfo * _UnlockScreenGI_gi = (gi); \
  struct RastPort * _UnlockScreenGI_rp = (rp); \
  { \
  register struct Library * const __UnlockScreenGI__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct GadgetInfo * __UnlockScreenGI_gi __asm("a0") = (_UnlockScreenGI_gi); \
  register struct RastPort * __UnlockScreenGI_rp __asm("a1") = (_UnlockScreenGI_rp); \
  __asm volatile ("jsr a6@(-1032:W)" \
  : \
  : "r"(__UnlockScreenGI__bn), "r"(__UnlockScreenGI_gi), "r"(__UnlockScreenGI_rp) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetMarkedBlock(sgw) ({ \
  struct SGWork * _GetMarkedBlock_sgw = (sgw); \
  ULONG _GetMarkedBlock__re = \
  ({ \
  register struct Library * const __GetMarkedBlock__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __GetMarkedBlock__re __asm("d0"); \
  register struct SGWork * __GetMarkedBlock_sgw __asm("a0") = (_GetMarkedBlock_sgw); \
  __asm volatile ("jsr a6@(-1038:W)" \
  : "=r"(__GetMarkedBlock__re) \
  : "r"(__GetMarkedBlock__bn), "r"(__GetMarkedBlock_sgw) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetMarkedBlock__re; \
  }); \
  _GetMarkedBlock__re; \
})

#define SetMarkedBlock(sgw, block) ({ \
  struct SGWork * _SetMarkedBlock_sgw = (sgw); \
  ULONG _SetMarkedBlock_block = (block); \
  { \
  register struct Library * const __SetMarkedBlock__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct SGWork * __SetMarkedBlock_sgw __asm("a0") = (_SetMarkedBlock_sgw); \
  register ULONG __SetMarkedBlock_block __asm("d0") = (_SetMarkedBlock_block); \
  __asm volatile ("jsr a6@(-1044:W)" \
  : \
  : "r"(__SetMarkedBlock__bn), "r"(__SetMarkedBlock_sgw), "r"(__SetMarkedBlock_block) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainBitMapSourceA(name, taglist) ({ \
  STRPTR _ObtainBitMapSourceA_name = (name); \
  struct TagItem * _ObtainBitMapSourceA_taglist = (taglist); \
  APTR _ObtainBitMapSourceA__re = \
  ({ \
  register struct Library * const __ObtainBitMapSourceA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __ObtainBitMapSourceA__re __asm("d0"); \
  register STRPTR __ObtainBitMapSourceA_name __asm("a0") = (_ObtainBitMapSourceA_name); \
  register struct TagItem * __ObtainBitMapSourceA_taglist __asm("a1") = (_ObtainBitMapSourceA_taglist); \
  __asm volatile ("jsr a6@(-1050:W)" \
  : "=r"(__ObtainBitMapSourceA__re) \
  : "r"(__ObtainBitMapSourceA__bn), "r"(__ObtainBitMapSourceA_name), "r"(__ObtainBitMapSourceA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainBitMapSourceA__re; \
  }); \
  _ObtainBitMapSourceA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___ObtainBitMapSource(struct Library * IntuitionBase, STRPTR name, Tag taglist, ...)
{
  return ObtainBitMapSourceA(name, (struct TagItem *) &taglist);
}

#define ObtainBitMapSource(name...) ___ObtainBitMapSource((struct Library *) INTUITION_BASE_NAME, name)
#endif

#define ReleaseBitMapSource(bitmapsource) ({ \
  APTR _ReleaseBitMapSource_bitmapsource = (bitmapsource); \
  { \
  register struct Library * const __ReleaseBitMapSource__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __ReleaseBitMapSource_bitmapsource __asm("a0") = (_ReleaseBitMapSource_bitmapsource); \
  __asm volatile ("jsr a6@(-1056:W)" \
  : \
  : "r"(__ReleaseBitMapSource__bn), "r"(__ReleaseBitMapSource_bitmapsource) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainBitMapInstanceA(bitmapsource, screen, taglist) ({ \
  APTR _ObtainBitMapInstanceA_bitmapsource = (bitmapsource); \
  struct Screen * _ObtainBitMapInstanceA_screen = (screen); \
  struct TagItem * _ObtainBitMapInstanceA_taglist = (taglist); \
  APTR _ObtainBitMapInstanceA__re = \
  ({ \
  register struct Library * const __ObtainBitMapInstanceA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __ObtainBitMapInstanceA__re __asm("d0"); \
  register APTR __ObtainBitMapInstanceA_bitmapsource __asm("a0") = (_ObtainBitMapInstanceA_bitmapsource); \
  register struct Screen * __ObtainBitMapInstanceA_screen __asm("a1") = (_ObtainBitMapInstanceA_screen); \
  register struct TagItem * __ObtainBitMapInstanceA_taglist __asm("a2") = (_ObtainBitMapInstanceA_taglist); \
  __asm volatile ("jsr a6@(-1062:W)" \
  : "=r"(__ObtainBitMapInstanceA__re) \
  : "r"(__ObtainBitMapInstanceA__bn), "r"(__ObtainBitMapInstanceA_bitmapsource), "r"(__ObtainBitMapInstanceA_screen), "r"(__ObtainBitMapInstanceA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainBitMapInstanceA__re; \
  }); \
  _ObtainBitMapInstanceA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___ObtainBitMapInstance(struct Library * IntuitionBase, APTR bitmapsource, struct Screen * screen, Tag taglist, ...)
{
  return ObtainBitMapInstanceA(bitmapsource, screen, (struct TagItem *) &taglist);
}

#define ObtainBitMapInstance(bitmapsource, screen...) ___ObtainBitMapInstance((struct Library *) INTUITION_BASE_NAME, bitmapsource, screen)
#endif

#define ReleaseBitMapInstance(bitmapinstance) ({ \
  APTR _ReleaseBitMapInstance_bitmapinstance = (bitmapinstance); \
  { \
  register struct Library * const __ReleaseBitMapInstance__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __ReleaseBitMapInstance_bitmapinstance __asm("a0") = (_ReleaseBitMapInstance_bitmapinstance); \
  __asm volatile ("jsr a6@(-1068:W)" \
  : \
  : "r"(__ReleaseBitMapInstance__bn), "r"(__ReleaseBitMapInstance_bitmapinstance) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define EmbossDisableRect(rp, minx, miny, maxx, maxy, backtype, contrast, dri) ({ \
  struct RastPort * _EmbossDisableRect_rp = (rp); \
  LONG _EmbossDisableRect_minx = (minx); \
  LONG _EmbossDisableRect_miny = (miny); \
  LONG _EmbossDisableRect_maxx = (maxx); \
  LONG _EmbossDisableRect_maxy = (maxy); \
  ULONG _EmbossDisableRect_backtype = (backtype); \
  ULONG _EmbossDisableRect_contrast = (contrast); \
  struct DrawInfo * _EmbossDisableRect_dri = (dri); \
  { \
  register struct Library * const __EmbossDisableRect__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __EmbossDisableRect_rp __asm("a0") = (_EmbossDisableRect_rp); \
  register LONG __EmbossDisableRect_minx __asm("d0") = (_EmbossDisableRect_minx); \
  register LONG __EmbossDisableRect_miny __asm("d1") = (_EmbossDisableRect_miny); \
  register LONG __EmbossDisableRect_maxx __asm("d2") = (_EmbossDisableRect_maxx); \
  register LONG __EmbossDisableRect_maxy __asm("d3") = (_EmbossDisableRect_maxy); \
  register ULONG __EmbossDisableRect_backtype __asm("d4") = (_EmbossDisableRect_backtype); \
  register ULONG __EmbossDisableRect_contrast __asm("d5") = (_EmbossDisableRect_contrast); \
  register struct DrawInfo * __EmbossDisableRect_dri __asm("a1") = (_EmbossDisableRect_dri); \
  __asm volatile ("jsr a6@(-1074:W)" \
  : \
  : "r"(__EmbossDisableRect__bn), "r"(__EmbossDisableRect_rp), "r"(__EmbossDisableRect_minx), "r"(__EmbossDisableRect_miny), "r"(__EmbossDisableRect_maxx), "r"(__EmbossDisableRect_maxy), "r"(__EmbossDisableRect_backtype), "r"(__EmbossDisableRect_contrast), "r"(__EmbossDisableRect_dri) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define EmbossDisableText(rp, text, len, backtype, contrast, dri) ({ \
  struct RastPort * _EmbossDisableText_rp = (rp); \
  STRPTR _EmbossDisableText_text = (text); \
  ULONG _EmbossDisableText_len = (len); \
  ULONG _EmbossDisableText_backtype = (backtype); \
  ULONG _EmbossDisableText_contrast = (contrast); \
  struct DrawInfo * _EmbossDisableText_dri = (dri); \
  { \
  register struct Library * const __EmbossDisableText__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __EmbossDisableText_rp __asm("a0") = (_EmbossDisableText_rp); \
  register STRPTR __EmbossDisableText_text __asm("a1") = (_EmbossDisableText_text); \
  register ULONG __EmbossDisableText_len __asm("d0") = (_EmbossDisableText_len); \
  register ULONG __EmbossDisableText_backtype __asm("d1") = (_EmbossDisableText_backtype); \
  register ULONG __EmbossDisableText_contrast __asm("d2") = (_EmbossDisableText_contrast); \
  register struct DrawInfo * __EmbossDisableText_dri __asm("a2") = (_EmbossDisableText_dri); \
  __asm volatile ("jsr a6@(-1080:W)" \
  : \
  : "r"(__EmbossDisableText__bn), "r"(__EmbossDisableText_rp), "r"(__EmbossDisableText_text), "r"(__EmbossDisableText_len), "r"(__EmbossDisableText_backtype), "r"(__EmbossDisableText_contrast), "r"(__EmbossDisableText_dri) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define PrintEmbossedDisabledIText(rp, itext, left, top, backtype, contrast, dri) ({ \
  struct RastPort * _PrintEmbossedDisabledIText_rp = (rp); \
  struct IntuiText * _PrintEmbossedDisabledIText_itext = (itext); \
  LONG _PrintEmbossedDisabledIText_left = (left); \
  LONG _PrintEmbossedDisabledIText_top = (top); \
  ULONG _PrintEmbossedDisabledIText_backtype = (backtype); \
  ULONG _PrintEmbossedDisabledIText_contrast = (contrast); \
  struct DrawInfo * _PrintEmbossedDisabledIText_dri = (dri); \
  { \
  register struct Library * const __PrintEmbossedDisabledIText__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __PrintEmbossedDisabledIText_rp __asm("a0") = (_PrintEmbossedDisabledIText_rp); \
  register struct IntuiText * __PrintEmbossedDisabledIText_itext __asm("a1") = (_PrintEmbossedDisabledIText_itext); \
  register LONG __PrintEmbossedDisabledIText_left __asm("d0") = (_PrintEmbossedDisabledIText_left); \
  register LONG __PrintEmbossedDisabledIText_top __asm("d1") = (_PrintEmbossedDisabledIText_top); \
  register ULONG __PrintEmbossedDisabledIText_backtype __asm("d2") = (_PrintEmbossedDisabledIText_backtype); \
  register ULONG __PrintEmbossedDisabledIText_contrast __asm("d3") = (_PrintEmbossedDisabledIText_contrast); \
  register struct DrawInfo * __PrintEmbossedDisabledIText_dri __asm("a2") = (_PrintEmbossedDisabledIText_dri); \
  __asm volatile ("jsr a6@(-1086:W)" \
  : \
  : "r"(__PrintEmbossedDisabledIText__bn), "r"(__PrintEmbossedDisabledIText_rp), "r"(__PrintEmbossedDisabledIText_itext), "r"(__PrintEmbossedDisabledIText_left), "r"(__PrintEmbossedDisabledIText_top), "r"(__PrintEmbossedDisabledIText_backtype), "r"(__PrintEmbossedDisabledIText_contrast), "r"(__PrintEmbossedDisabledIText_dri) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define IntuiTextExtent(rp, itext, textent) ({ \
  struct RastPort * _IntuiTextExtent_rp = (rp); \
  struct IntuiText * _IntuiTextExtent_itext = (itext); \
  struct TextExtent * _IntuiTextExtent_textent = (textent); \
  ULONG _IntuiTextExtent__re = \
  ({ \
  register struct Library * const __IntuiTextExtent__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __IntuiTextExtent__re __asm("d0"); \
  register struct RastPort * __IntuiTextExtent_rp __asm("a0") = (_IntuiTextExtent_rp); \
  register struct IntuiText * __IntuiTextExtent_itext __asm("a1") = (_IntuiTextExtent_itext); \
  register struct TextExtent * __IntuiTextExtent_textent __asm("a2") = (_IntuiTextExtent_textent); \
  __asm volatile ("jsr a6@(-1092:W)" \
  : "=r"(__IntuiTextExtent__re) \
  : "r"(__IntuiTextExtent__bn), "r"(__IntuiTextExtent_rp), "r"(__IntuiTextExtent_itext), "r"(__IntuiTextExtent_textent) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IntuiTextExtent__re; \
  }); \
  _IntuiTextExtent__re; \
})

#define ShadeRectOld(rp, minx, miny, maxx, maxy, shadelevel, backtype, state, dri) ({ \
  struct RastPort * _ShadeRectOld_rp = (rp); \
  LONG _ShadeRectOld_minx = (minx); \
  LONG _ShadeRectOld_miny = (miny); \
  LONG _ShadeRectOld_maxx = (maxx); \
  LONG _ShadeRectOld_maxy = (maxy); \
  ULONG _ShadeRectOld_shadelevel = (shadelevel); \
  ULONG _ShadeRectOld_backtype = (backtype); \
  ULONG _ShadeRectOld_state = (state); \
  struct DrawInfo * _ShadeRectOld_dri = (dri); \
  ULONG _ShadeRectOld__re = \
  ({ \
  register struct Library * const __ShadeRectOld__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __ShadeRectOld__re __asm("d0"); \
  register struct RastPort * __ShadeRectOld_rp __asm("a0") = (_ShadeRectOld_rp); \
  register LONG __ShadeRectOld_minx __asm("d0") = (_ShadeRectOld_minx); \
  register LONG __ShadeRectOld_miny __asm("d1") = (_ShadeRectOld_miny); \
  register LONG __ShadeRectOld_maxx __asm("d2") = (_ShadeRectOld_maxx); \
  register LONG __ShadeRectOld_maxy __asm("d3") = (_ShadeRectOld_maxy); \
  register ULONG __ShadeRectOld_shadelevel __asm("d4") = (_ShadeRectOld_shadelevel); \
  register ULONG __ShadeRectOld_backtype __asm("d5") = (_ShadeRectOld_backtype); \
  register ULONG __ShadeRectOld_state __asm("d6") = (_ShadeRectOld_state); \
  register struct DrawInfo * __ShadeRectOld_dri __asm("a1") = (_ShadeRectOld_dri); \
  __asm volatile ("jsr a6@(-1098:W)" \
  : "=r"(__ShadeRectOld__re) \
  : "r"(__ShadeRectOld__bn), "r"(__ShadeRectOld_rp), "r"(__ShadeRectOld_minx), "r"(__ShadeRectOld_miny), "r"(__ShadeRectOld_maxx), "r"(__ShadeRectOld_maxy), "r"(__ShadeRectOld_shadelevel), "r"(__ShadeRectOld_backtype), "r"(__ShadeRectOld_state), "r"(__ShadeRectOld_dri) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ShadeRectOld__re; \
  }); \
  _ShadeRectOld__re; \
})

#define FindMenuKey(menu, code) ({ \
  struct Menu * _FindMenuKey_menu = (menu); \
  LONG _FindMenuKey_code = (code); \
  UWORD _FindMenuKey__re = \
  ({ \
  register struct Library * const __FindMenuKey__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register UWORD __FindMenuKey__re __asm("d0"); \
  register struct Menu * __FindMenuKey_menu __asm("a0") = (_FindMenuKey_menu); \
  register LONG __FindMenuKey_code __asm("d0") = (_FindMenuKey_code); \
  __asm volatile ("jsr a6@(-1116:W)" \
  : "=r"(__FindMenuKey__re) \
  : "r"(__FindMenuKey__bn), "r"(__FindMenuKey_menu), "r"(__FindMenuKey_code) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindMenuKey__re; \
  }); \
  _FindMenuKey__re; \
})

#define BitMapInstanceControlA(bitmapinstance, taglist) ({ \
  APTR _BitMapInstanceControlA_bitmapinstance = (bitmapinstance); \
  struct TagItem * _BitMapInstanceControlA_taglist = (taglist); \
  ULONG _BitMapInstanceControlA__re = \
  ({ \
  register struct Library * const __BitMapInstanceControlA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __BitMapInstanceControlA__re __asm("d0"); \
  register APTR __BitMapInstanceControlA_bitmapinstance __asm("a0") = (_BitMapInstanceControlA_bitmapinstance); \
  register struct TagItem * __BitMapInstanceControlA_taglist __asm("a1") = (_BitMapInstanceControlA_taglist); \
  __asm volatile ("jsr a6@(-1122:W)" \
  : "=r"(__BitMapInstanceControlA__re) \
  : "r"(__BitMapInstanceControlA__bn), "r"(__BitMapInstanceControlA_bitmapinstance), "r"(__BitMapInstanceControlA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __BitMapInstanceControlA__re; \
  }); \
  _BitMapInstanceControlA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___BitMapInstanceControl(struct Library * IntuitionBase, APTR bitmapinstance, Tag taglist, ...)
{
  return BitMapInstanceControlA(bitmapinstance, (struct TagItem *) &taglist);
}

#define BitMapInstanceControl(bitmapinstance...) ___BitMapInstanceControl((struct Library *) INTUITION_BASE_NAME, bitmapinstance)
#endif

#define ObtainIPluginList(type, attrmask, applymask) ({ \
  ULONG _ObtainIPluginList_type = (type); \
  ULONG _ObtainIPluginList_attrmask = (attrmask); \
  ULONG _ObtainIPluginList_applymask = (applymask); \
  struct List * _ObtainIPluginList__re = \
  ({ \
  register struct Library * const __ObtainIPluginList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct List * __ObtainIPluginList__re __asm("d0"); \
  register ULONG __ObtainIPluginList_type __asm("d0") = (_ObtainIPluginList_type); \
  register ULONG __ObtainIPluginList_attrmask __asm("d1") = (_ObtainIPluginList_attrmask); \
  register ULONG __ObtainIPluginList_applymask __asm("d2") = (_ObtainIPluginList_applymask); \
  __asm volatile ("jsr a6@(-1128:W)" \
  : "=r"(__ObtainIPluginList__re) \
  : "r"(__ObtainIPluginList__bn), "r"(__ObtainIPluginList_type), "r"(__ObtainIPluginList_attrmask), "r"(__ObtainIPluginList_applymask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainIPluginList__re; \
  }); \
  _ObtainIPluginList__re; \
})

#define ReleaseIPluginList(list) ({ \
  struct List * _ReleaseIPluginList_list = (list); \
  { \
  register struct Library * const __ReleaseIPluginList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct List * __ReleaseIPluginList_list __asm("a0") = (_ReleaseIPluginList_list); \
  __asm volatile ("jsr a6@(-1134:W)" \
  : \
  : "r"(__ReleaseIPluginList__bn), "r"(__ReleaseIPluginList_list) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OpenGUIPlugin(name, version, type, attrmask, applymask) ({ \
  STRPTR _OpenGUIPlugin_name = (name); \
  ULONG _OpenGUIPlugin_version = (version); \
  ULONG _OpenGUIPlugin_type = (type); \
  ULONG _OpenGUIPlugin_attrmask = (attrmask); \
  ULONG _OpenGUIPlugin_applymask = (applymask); \
  struct GUIPlugin * _OpenGUIPlugin__re = \
  ({ \
  register struct Library * const __OpenGUIPlugin__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct GUIPlugin * __OpenGUIPlugin__re __asm("d0"); \
  register STRPTR __OpenGUIPlugin_name __asm("a0") = (_OpenGUIPlugin_name); \
  register ULONG __OpenGUIPlugin_version __asm("d0") = (_OpenGUIPlugin_version); \
  register ULONG __OpenGUIPlugin_type __asm("d1") = (_OpenGUIPlugin_type); \
  register ULONG __OpenGUIPlugin_attrmask __asm("d2") = (_OpenGUIPlugin_attrmask); \
  register ULONG __OpenGUIPlugin_applymask __asm("d3") = (_OpenGUIPlugin_applymask); \
  __asm volatile ("jsr a6@(-1140:W)" \
  : "=r"(__OpenGUIPlugin__re) \
  : "r"(__OpenGUIPlugin__bn), "r"(__OpenGUIPlugin_name), "r"(__OpenGUIPlugin_version), "r"(__OpenGUIPlugin_type), "r"(__OpenGUIPlugin_attrmask), "r"(__OpenGUIPlugin_applymask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenGUIPlugin__re; \
  }); \
  _OpenGUIPlugin__re; \
})

#define CloseGUIPlugin(plugin) ({ \
  struct GUIPlugin * _CloseGUIPlugin_plugin = (plugin); \
  { \
  register struct Library * const __CloseGUIPlugin__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct GUIPlugin * __CloseGUIPlugin_plugin __asm("a0") = (_CloseGUIPlugin_plugin); \
  __asm volatile ("jsr a6@(-1146:W)" \
  : \
  : "r"(__CloseGUIPlugin__bn), "r"(__CloseGUIPlugin_plugin) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DrawSysImageA(rp, left, top, width, height, which, backtype, state, dri, taglist) ({ \
  struct RastPort * _DrawSysImageA_rp = (rp); \
  LONG _DrawSysImageA_left = (left); \
  LONG _DrawSysImageA_top = (top); \
  LONG _DrawSysImageA_width = (width); \
  LONG _DrawSysImageA_height = (height); \
  ULONG _DrawSysImageA_which = (which); \
  ULONG _DrawSysImageA_backtype = (backtype); \
  ULONG _DrawSysImageA_state = (state); \
  struct DrawInfo * _DrawSysImageA_dri = (dri); \
  struct TagItem * _DrawSysImageA_taglist = (taglist); \
  ULONG _DrawSysImageA__re = \
  ({ \
  register struct Library * const __DrawSysImageA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __DrawSysImageA__re __asm("d0"); \
  register struct RastPort * __DrawSysImageA_rp __asm("a0") = (_DrawSysImageA_rp); \
  register LONG __DrawSysImageA_left __asm("d0") = (_DrawSysImageA_left); \
  register LONG __DrawSysImageA_top __asm("d1") = (_DrawSysImageA_top); \
  register LONG __DrawSysImageA_width __asm("d2") = (_DrawSysImageA_width); \
  register LONG __DrawSysImageA_height __asm("d3") = (_DrawSysImageA_height); \
  register ULONG __DrawSysImageA_which __asm("d4") = (_DrawSysImageA_which); \
  register ULONG __DrawSysImageA_backtype __asm("d5") = (_DrawSysImageA_backtype); \
  register ULONG __DrawSysImageA_state __asm("d6") = (_DrawSysImageA_state); \
  register struct DrawInfo * __DrawSysImageA_dri __asm("a1") = (_DrawSysImageA_dri); \
  register struct TagItem * __DrawSysImageA_taglist __asm("a2") = (_DrawSysImageA_taglist); \
  __asm volatile ("jsr a6@(-1152:W)" \
  : "=r"(__DrawSysImageA__re) \
  : "r"(__DrawSysImageA__bn), "r"(__DrawSysImageA_rp), "r"(__DrawSysImageA_left), "r"(__DrawSysImageA_top), "r"(__DrawSysImageA_width), "r"(__DrawSysImageA_height), "r"(__DrawSysImageA_which), "r"(__DrawSysImageA_backtype), "r"(__DrawSysImageA_state), "r"(__DrawSysImageA_dri), "r"(__DrawSysImageA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DrawSysImageA__re; \
  }); \
  _DrawSysImageA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___DrawSysImage(struct Library * IntuitionBase, struct RastPort * rp, LONG left, LONG top, LONG width, LONG height, ULONG which, ULONG backtype, ULONG state, struct DrawInfo * dri, Tag taglist, ...)
{
  return DrawSysImageA(rp, left, top, width, height, which, backtype, state, dri, (struct TagItem *) &taglist);
}

#define DrawSysImage(rp, left, top, width, height, which, backtype, state, dri...) ___DrawSysImage((struct Library *) INTUITION_BASE_NAME, rp, left, top, width, height, which, backtype, state, dri)
#endif

#define DoRender(o, gi, flags) ({ \
  Object * _DoRender_o = (o); \
  struct GadgetInfo * _DoRender_gi = (gi); \
  ULONG _DoRender_flags = (flags); \
  ULONG _DoRender__re = \
  ({ \
  register struct Library * const __DoRender__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __DoRender__re __asm("d0"); \
  register Object * __DoRender_o __asm("a0") = (_DoRender_o); \
  register struct GadgetInfo * __DoRender_gi __asm("a1") = (_DoRender_gi); \
  register ULONG __DoRender_flags __asm("d0") = (_DoRender_flags); \
  __asm volatile ("jsr a6@(-1158:W)" \
  : "=r"(__DoRender__re) \
  : "r"(__DoRender__bn), "r"(__DoRender_o), "r"(__DoRender_gi), "r"(__DoRender_flags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DoRender__re; \
  }); \
  _DoRender__re; \
})

#define SetRenderDomain(rp, domain) ({ \
  struct RastPort * _SetRenderDomain_rp = (rp); \
  struct Rectangle * _SetRenderDomain_domain = (domain); \
  ULONG _SetRenderDomain__re = \
  ({ \
  register struct Library * const __SetRenderDomain__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __SetRenderDomain__re __asm("d0"); \
  register struct RastPort * __SetRenderDomain_rp __asm("a0") = (_SetRenderDomain_rp); \
  register struct Rectangle * __SetRenderDomain_domain __asm("a1") = (_SetRenderDomain_domain); \
  __asm volatile ("jsr a6@(-1164:W)" \
  : "=r"(__SetRenderDomain__re) \
  : "r"(__SetRenderDomain__bn), "r"(__SetRenderDomain_rp), "r"(__SetRenderDomain_domain) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetRenderDomain__re; \
  }); \
  _SetRenderDomain__re; \
})

#define GetRenderDomain(rp, domain) ({ \
  struct RastPort * _GetRenderDomain_rp = (rp); \
  struct Rectangle * _GetRenderDomain_domain = (domain); \
  ULONG _GetRenderDomain__re = \
  ({ \
  register struct Library * const __GetRenderDomain__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __GetRenderDomain__re __asm("d0"); \
  register struct RastPort * __GetRenderDomain_rp __asm("a0") = (_GetRenderDomain_rp); \
  register struct Rectangle * __GetRenderDomain_domain __asm("a1") = (_GetRenderDomain_domain); \
  __asm volatile ("jsr a6@(-1170:W)" \
  : "=r"(__GetRenderDomain__re) \
  : "r"(__GetRenderDomain__bn), "r"(__GetRenderDomain_rp), "r"(__GetRenderDomain_domain) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetRenderDomain__re; \
  }); \
  _GetRenderDomain__re; \
})

#define DrawGradient(rp, left, top, width, height, domain, reserved, gradientspec, dri) ({ \
  struct RastPort * _DrawGradient_rp = (rp); \
  LONG _DrawGradient_left = (left); \
  LONG _DrawGradient_top = (top); \
  LONG _DrawGradient_width = (width); \
  LONG _DrawGradient_height = (height); \
  struct IBox * _DrawGradient_domain = (domain); \
  ULONG _DrawGradient_reserved = (reserved); \
  struct GradientSpec * _DrawGradient_gradientspec = (gradientspec); \
  struct DrawInfo * _DrawGradient_dri = (dri); \
  ULONG _DrawGradient__re = \
  ({ \
  register struct Library * const __DrawGradient__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __DrawGradient__re __asm("d0"); \
  register struct RastPort * __DrawGradient_rp __asm("a0") = (_DrawGradient_rp); \
  register LONG __DrawGradient_left __asm("d0") = (_DrawGradient_left); \
  register LONG __DrawGradient_top __asm("d1") = (_DrawGradient_top); \
  register LONG __DrawGradient_width __asm("d2") = (_DrawGradient_width); \
  register LONG __DrawGradient_height __asm("d3") = (_DrawGradient_height); \
  register struct IBox * __DrawGradient_domain __asm("a1") = (_DrawGradient_domain); \
  register ULONG __DrawGradient_reserved __asm("d4") = (_DrawGradient_reserved); \
  register struct GradientSpec * __DrawGradient_gradientspec __asm("a2") = (_DrawGradient_gradientspec); \
  register struct DrawInfo * __DrawGradient_dri __asm("a3") = (_DrawGradient_dri); \
  __asm volatile ("jsr a6@(-1176:W)" \
  : "=r"(__DrawGradient__re) \
  : "r"(__DrawGradient__bn), "r"(__DrawGradient_rp), "r"(__DrawGradient_left), "r"(__DrawGradient_top), "r"(__DrawGradient_width), "r"(__DrawGradient_height), "r"(__DrawGradient_domain), "r"(__DrawGradient_reserved), "r"(__DrawGradient_gradientspec), "r"(__DrawGradient_dri) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DrawGradient__re; \
  }); \
  _DrawGradient__re; \
})

#define DirectionVector(degrees) ({ \
  ULONG _DirectionVector_degrees = (degrees); \
  ULONG _DirectionVector__re = \
  ({ \
  register struct Library * const __DirectionVector__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __DirectionVector__re __asm("d0"); \
  register ULONG __DirectionVector_degrees __asm("d0") = (_DirectionVector_degrees); \
  __asm volatile ("jsr a6@(-1182:W)" \
  : "=r"(__DirectionVector__re) \
  : "r"(__DirectionVector__bn), "r"(__DirectionVector_degrees) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DirectionVector__re; \
  }); \
  _DirectionVector__re; \
})

#define ShadeRectA(rp, minx, miny, maxx, maxy, shadelevel, backtype, state, dri, taglist) ({ \
  struct RastPort * _ShadeRectA_rp = (rp); \
  LONG _ShadeRectA_minx = (minx); \
  LONG _ShadeRectA_miny = (miny); \
  LONG _ShadeRectA_maxx = (maxx); \
  LONG _ShadeRectA_maxy = (maxy); \
  ULONG _ShadeRectA_shadelevel = (shadelevel); \
  ULONG _ShadeRectA_backtype = (backtype); \
  ULONG _ShadeRectA_state = (state); \
  struct DrawInfo * _ShadeRectA_dri = (dri); \
  struct TagItem * _ShadeRectA_taglist = (taglist); \
  ULONG _ShadeRectA__re = \
  ({ \
  register struct Library * const __ShadeRectA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __ShadeRectA__re __asm("d0"); \
  register struct RastPort * __ShadeRectA_rp __asm("a0") = (_ShadeRectA_rp); \
  register LONG __ShadeRectA_minx __asm("d0") = (_ShadeRectA_minx); \
  register LONG __ShadeRectA_miny __asm("d1") = (_ShadeRectA_miny); \
  register LONG __ShadeRectA_maxx __asm("d2") = (_ShadeRectA_maxx); \
  register LONG __ShadeRectA_maxy __asm("d3") = (_ShadeRectA_maxy); \
  register ULONG __ShadeRectA_shadelevel __asm("d4") = (_ShadeRectA_shadelevel); \
  register ULONG __ShadeRectA_backtype __asm("d5") = (_ShadeRectA_backtype); \
  register ULONG __ShadeRectA_state __asm("d6") = (_ShadeRectA_state); \
  register struct DrawInfo * __ShadeRectA_dri __asm("a1") = (_ShadeRectA_dri); \
  register struct TagItem * __ShadeRectA_taglist __asm("a2") = (_ShadeRectA_taglist); \
  __asm volatile ("jsr a6@(-1188:W)" \
  : "=r"(__ShadeRectA__re) \
  : "r"(__ShadeRectA__bn), "r"(__ShadeRectA_rp), "r"(__ShadeRectA_minx), "r"(__ShadeRectA_miny), "r"(__ShadeRectA_maxx), "r"(__ShadeRectA_maxy), "r"(__ShadeRectA_shadelevel), "r"(__ShadeRectA_backtype), "r"(__ShadeRectA_state), "r"(__ShadeRectA_dri), "r"(__ShadeRectA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ShadeRectA__re; \
  }); \
  _ShadeRectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___ShadeRect(struct Library * IntuitionBase, struct RastPort * rp, LONG minx, LONG miny, LONG maxx, LONG maxy, ULONG shadelevel, ULONG backtype, ULONG state, struct DrawInfo * dri, Tag taglist, ...)
{
  return ShadeRectA(rp, minx, miny, maxx, maxy, shadelevel, backtype, state, dri, (struct TagItem *) &taglist);
}

#define ShadeRect(rp, minx, miny, maxx, maxy, shadelevel, backtype, state, dri...) ___ShadeRect((struct Library *) INTUITION_BASE_NAME, rp, minx, miny, maxx, maxy, shadelevel, backtype, state, dri)
#endif

#define DoScrollHook(scrollhook, scrollmode) ({ \
  struct ScrollHook * _DoScrollHook_scrollhook = (scrollhook); \
  LONG _DoScrollHook_scrollmode = (scrollmode); \
  { \
  register struct Library * const __DoScrollHook__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct ScrollHook * __DoScrollHook_scrollhook __asm("a0") = (_DoScrollHook_scrollhook); \
  register LONG __DoScrollHook_scrollmode __asm("d0") = (_DoScrollHook_scrollmode); \
  __asm volatile ("jsr a6@(-1194:W)" \
  : \
  : "r"(__DoScrollHook__bn), "r"(__DoScrollHook_scrollhook), "r"(__DoScrollHook_scrollmode) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainIBackFill(dri, element, state, flags) ({ \
  struct DrawInfo * _ObtainIBackFill_dri = (dri); \
  ULONG _ObtainIBackFill_element = (element); \
  ULONG _ObtainIBackFill_state = (state); \
  ULONG _ObtainIBackFill_flags = (flags); \
  struct Hook * _ObtainIBackFill__re = \
  ({ \
  register struct Library * const __ObtainIBackFill__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Hook * __ObtainIBackFill__re __asm("d0"); \
  register struct DrawInfo * __ObtainIBackFill_dri __asm("a0") = (_ObtainIBackFill_dri); \
  register ULONG __ObtainIBackFill_element __asm("d0") = (_ObtainIBackFill_element); \
  register ULONG __ObtainIBackFill_state __asm("d1") = (_ObtainIBackFill_state); \
  register ULONG __ObtainIBackFill_flags __asm("d2") = (_ObtainIBackFill_flags); \
  __asm volatile ("jsr a6@(-1200:W)" \
  : "=r"(__ObtainIBackFill__re) \
  : "r"(__ObtainIBackFill__bn), "r"(__ObtainIBackFill_dri), "r"(__ObtainIBackFill_element), "r"(__ObtainIBackFill_state), "r"(__ObtainIBackFill_flags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainIBackFill__re; \
  }); \
  _ObtainIBackFill__re; \
})

#define ReleaseIBackFill(hook) ({ \
  struct Hook * _ReleaseIBackFill_hook = (hook); \
  { \
  register struct Library * const __ReleaseIBackFill__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct Hook * __ReleaseIBackFill_hook __asm("a0") = (_ReleaseIBackFill_hook); \
  __asm volatile ("jsr a6@(-1206:W)" \
  : \
  : "r"(__ReleaseIBackFill__bn), "r"(__ReleaseIBackFill_hook) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define IntuitionControlA(object, taglist) ({ \
  APTR _IntuitionControlA_object = (object); \
  struct TagItem * _IntuitionControlA_taglist = (taglist); \
  ULONG _IntuitionControlA__re = \
  ({ \
  register struct Library * const __IntuitionControlA__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register ULONG __IntuitionControlA__re __asm("d0"); \
  register APTR __IntuitionControlA_object __asm("a0") = (_IntuitionControlA_object); \
  register struct TagItem * __IntuitionControlA_taglist __asm("a1") = (_IntuitionControlA_taglist); \
  __asm volatile ("jsr a6@(-1212:W)" \
  : "=r"(__IntuitionControlA__re) \
  : "r"(__IntuitionControlA__bn), "r"(__IntuitionControlA_object), "r"(__IntuitionControlA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IntuitionControlA__re; \
  }); \
  _IntuitionControlA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___IntuitionControl(struct Library * IntuitionBase, APTR object, Tag taglist, ...)
{
  return IntuitionControlA(object, (struct TagItem *) &taglist);
}

#define IntuitionControl(object...) ___IntuitionControl((struct Library *) INTUITION_BASE_NAME, object)
#endif

#define StartScreenNotifyTagList(taglist) ({ \
  struct TagItem * _StartScreenNotifyTagList_taglist = (taglist); \
  APTR _StartScreenNotifyTagList__re = \
  ({ \
  register struct Library * const __StartScreenNotifyTagList__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register APTR __StartScreenNotifyTagList__re __asm("d0"); \
  register struct TagItem * __StartScreenNotifyTagList_taglist __asm("a0") = (_StartScreenNotifyTagList_taglist); \
  __asm volatile ("jsr a6@(-1218:W)" \
  : "=r"(__StartScreenNotifyTagList__re) \
  : "r"(__StartScreenNotifyTagList__bn), "r"(__StartScreenNotifyTagList_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __StartScreenNotifyTagList__re; \
  }); \
  _StartScreenNotifyTagList__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___StartScreenNotifyTags(struct Library * IntuitionBase, Tag taglist, ...)
{
  return StartScreenNotifyTagList((struct TagItem *) &taglist);
}

#define StartScreenNotifyTags(tags...) ___StartScreenNotifyTags((struct Library *) INTUITION_BASE_NAME, tags)
#endif

#define EndScreenNotify(request) ({ \
  APTR _EndScreenNotify_request = (request); \
  BOOL _EndScreenNotify__re = \
  ({ \
  register struct Library * const __EndScreenNotify__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register BOOL __EndScreenNotify__re __asm("d0"); \
  register APTR __EndScreenNotify_request __asm("a0") = (_EndScreenNotify_request); \
  __asm volatile ("jsr a6@(-1224:W)" \
  : "=r"(__EndScreenNotify__re) \
  : "r"(__EndScreenNotify__bn), "r"(__EndScreenNotify_request) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __EndScreenNotify__re; \
  }); \
  _EndScreenNotify__re; \
})

#define DisableTemplate(rp, left, top, width, height, template_ptr, offx, template_type, bytesperrow, backtype, dri) ({ \
  struct RastPort * _DisableTemplate_rp = (rp); \
  LONG _DisableTemplate_left = (left); \
  LONG _DisableTemplate_top = (top); \
  LONG _DisableTemplate_width = (width); \
  LONG _DisableTemplate_height = (height); \
  APTR _DisableTemplate_template_ptr = (template_ptr); \
  LONG _DisableTemplate_offx = (offx); \
  ULONG _DisableTemplate_template_type = (template_type); \
  ULONG _DisableTemplate_bytesperrow = (bytesperrow); \
  ULONG _DisableTemplate_backtype = (backtype); \
  struct DrawInfo * _DisableTemplate_dri = (dri); \
  { \
  register struct Library * const __DisableTemplate__bn __asm("a6") = (struct Library *) (INTUITION_BASE_NAME);\
  register struct RastPort * __DisableTemplate_rp __asm("a0") = (_DisableTemplate_rp); \
  register LONG __DisableTemplate_left __asm("d0") = (_DisableTemplate_left); \
  register LONG __DisableTemplate_top __asm("d1") = (_DisableTemplate_top); \
  register LONG __DisableTemplate_width __asm("d2") = (_DisableTemplate_width); \
  register LONG __DisableTemplate_height __asm("d3") = (_DisableTemplate_height); \
  register APTR __DisableTemplate_template_ptr __asm("a1") = (_DisableTemplate_template_ptr); \
  register LONG __DisableTemplate_offx __asm("d4") = (_DisableTemplate_offx); \
  register ULONG __DisableTemplate_template_type __asm("d5") = (_DisableTemplate_template_type); \
  register ULONG __DisableTemplate_bytesperrow __asm("d6") = (_DisableTemplate_bytesperrow); \
  register ULONG __DisableTemplate_backtype __asm("d7") = (_DisableTemplate_backtype); \
  register struct DrawInfo * __DisableTemplate_dri __asm("a2") = (_DisableTemplate_dri); \
  __asm volatile ("jsr a6@(-1230:W)" \
  : \
  : "r"(__DisableTemplate__bn), "r"(__DisableTemplate_rp), "r"(__DisableTemplate_left), "r"(__DisableTemplate_top), "r"(__DisableTemplate_width), "r"(__DisableTemplate_height), "r"(__DisableTemplate_template_ptr), "r"(__DisableTemplate_offx), "r"(__DisableTemplate_template_type), "r"(__DisableTemplate_bytesperrow), "r"(__DisableTemplate_backtype), "r"(__DisableTemplate_dri) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_INTUITION_H  */
