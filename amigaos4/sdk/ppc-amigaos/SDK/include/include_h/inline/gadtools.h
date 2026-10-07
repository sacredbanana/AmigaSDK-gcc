#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_GADTOOLS_H
#define _INLINE_GADTOOLS_H

#ifndef CLIB_GADTOOLS_PROTOS_H
#define CLIB_GADTOOLS_PROTOS_H
#endif

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  LIBRARIES_GADTOOLS_H
#include <libraries/gadtools.h>
#endif

#ifndef GADTOOLS_BASE_NAME
#define GADTOOLS_BASE_NAME GadToolsBase
#endif

#define CreateGadgetA(kind, gad, ng, taglist) ({ \
  ULONG _CreateGadgetA_kind = (kind); \
  struct Gadget * _CreateGadgetA_gad = (gad); \
  const struct NewGadget * _CreateGadgetA_ng = (ng); \
  const struct TagItem * _CreateGadgetA_taglist = (taglist); \
  struct Gadget * _CreateGadgetA__re = \
  ({ \
  register struct Library * const __CreateGadgetA__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct Gadget * __CreateGadgetA__re __asm("d0"); \
  register ULONG __CreateGadgetA_kind __asm("d0") = (_CreateGadgetA_kind); \
  register struct Gadget * __CreateGadgetA_gad __asm("a0") = (_CreateGadgetA_gad); \
  register const struct NewGadget * __CreateGadgetA_ng __asm("a1") = (_CreateGadgetA_ng); \
  register const struct TagItem * __CreateGadgetA_taglist __asm("a2") = (_CreateGadgetA_taglist); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__CreateGadgetA__re) \
  : "r"(__CreateGadgetA__bn), "r"(__CreateGadgetA_kind), "r"(__CreateGadgetA_gad), "r"(__CreateGadgetA_ng), "r"(__CreateGadgetA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateGadgetA__re; \
  }); \
  _CreateGadgetA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Gadget * ___CreateGadget(struct Library * GadToolsBase, ULONG kind, struct Gadget * gad, const struct NewGadget * ng, Tag taglist, ...)
{
  return CreateGadgetA(kind, gad, ng, (const struct TagItem *) &taglist);
}

#define CreateGadget(kind, gad, ng...) ___CreateGadget(GADTOOLS_BASE_NAME, kind, gad, ng)
#endif

#define FreeGadgets(gad) ({ \
  struct Gadget * _FreeGadgets_gad = (gad); \
  { \
  register struct Library * const __FreeGadgets__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct Gadget * __FreeGadgets_gad __asm("a0") = (_FreeGadgets_gad); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__FreeGadgets__bn), "r"(__FreeGadgets_gad) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GT_SetGadgetAttrsA(gad, win, req, taglist) ({ \
  struct Gadget * _GT_SetGadgetAttrsA_gad = (gad); \
  struct Window * _GT_SetGadgetAttrsA_win = (win); \
  struct Requester * _GT_SetGadgetAttrsA_req = (req); \
  const struct TagItem * _GT_SetGadgetAttrsA_taglist = (taglist); \
  { \
  register struct Library * const __GT_SetGadgetAttrsA__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct Gadget * __GT_SetGadgetAttrsA_gad __asm("a0") = (_GT_SetGadgetAttrsA_gad); \
  register struct Window * __GT_SetGadgetAttrsA_win __asm("a1") = (_GT_SetGadgetAttrsA_win); \
  register struct Requester * __GT_SetGadgetAttrsA_req __asm("a2") = (_GT_SetGadgetAttrsA_req); \
  register const struct TagItem * __GT_SetGadgetAttrsA_taglist __asm("a3") = (_GT_SetGadgetAttrsA_taglist); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__GT_SetGadgetAttrsA__bn), "r"(__GT_SetGadgetAttrsA_gad), "r"(__GT_SetGadgetAttrsA_win), "r"(__GT_SetGadgetAttrsA_req), "r"(__GT_SetGadgetAttrsA_taglist) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___GT_SetGadgetAttrs(struct Library * GadToolsBase, struct Gadget * gad, struct Window * win, struct Requester * req, Tag taglist, ...)
{
  GT_SetGadgetAttrsA(gad, win, req, (const struct TagItem *) &taglist);
}

#define GT_SetGadgetAttrs(gad, win, req...) ___GT_SetGadgetAttrs(GADTOOLS_BASE_NAME, gad, win, req)
#endif

#define CreateMenusA(newmenu, taglist) ({ \
  const struct NewMenu * _CreateMenusA_newmenu = (newmenu); \
  const struct TagItem * _CreateMenusA_taglist = (taglist); \
  struct Menu * _CreateMenusA__re = \
  ({ \
  register struct Library * const __CreateMenusA__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct Menu * __CreateMenusA__re __asm("d0"); \
  register const struct NewMenu * __CreateMenusA_newmenu __asm("a0") = (_CreateMenusA_newmenu); \
  register const struct TagItem * __CreateMenusA_taglist __asm("a1") = (_CreateMenusA_taglist); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__CreateMenusA__re) \
  : "r"(__CreateMenusA__bn), "r"(__CreateMenusA_newmenu), "r"(__CreateMenusA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateMenusA__re; \
  }); \
  _CreateMenusA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Menu * ___CreateMenus(struct Library * GadToolsBase, const struct NewMenu * newmenu, Tag taglist, ...)
{
  return CreateMenusA(newmenu, (const struct TagItem *) &taglist);
}

#define CreateMenus(newmenu...) ___CreateMenus(GADTOOLS_BASE_NAME, newmenu)
#endif

#define FreeMenus(menu) ({ \
  struct Menu * _FreeMenus_menu = (menu); \
  { \
  register struct Library * const __FreeMenus__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct Menu * __FreeMenus_menu __asm("a0") = (_FreeMenus_menu); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__FreeMenus__bn), "r"(__FreeMenus_menu) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define LayoutMenuItemsA(firstitem, vi, taglist) ({ \
  struct MenuItem * _LayoutMenuItemsA_firstitem = (firstitem); \
  APTR _LayoutMenuItemsA_vi = (vi); \
  const struct TagItem * _LayoutMenuItemsA_taglist = (taglist); \
  BOOL _LayoutMenuItemsA__re = \
  ({ \
  register struct Library * const __LayoutMenuItemsA__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register BOOL __LayoutMenuItemsA__re __asm("d0"); \
  register struct MenuItem * __LayoutMenuItemsA_firstitem __asm("a0") = (_LayoutMenuItemsA_firstitem); \
  register APTR __LayoutMenuItemsA_vi __asm("a1") = (_LayoutMenuItemsA_vi); \
  register const struct TagItem * __LayoutMenuItemsA_taglist __asm("a2") = (_LayoutMenuItemsA_taglist); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__LayoutMenuItemsA__re) \
  : "r"(__LayoutMenuItemsA__bn), "r"(__LayoutMenuItemsA_firstitem), "r"(__LayoutMenuItemsA_vi), "r"(__LayoutMenuItemsA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LayoutMenuItemsA__re; \
  }); \
  _LayoutMenuItemsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___LayoutMenuItems(struct Library * GadToolsBase, struct MenuItem * firstitem, APTR vi, Tag taglist, ...)
{
  return LayoutMenuItemsA(firstitem, vi, (const struct TagItem *) &taglist);
}

#define LayoutMenuItems(firstitem, vi...) ___LayoutMenuItems(GADTOOLS_BASE_NAME, firstitem, vi)
#endif

#define LayoutMenusA(firstmenu, vi, taglist) ({ \
  struct Menu * _LayoutMenusA_firstmenu = (firstmenu); \
  APTR _LayoutMenusA_vi = (vi); \
  const struct TagItem * _LayoutMenusA_taglist = (taglist); \
  BOOL _LayoutMenusA__re = \
  ({ \
  register struct Library * const __LayoutMenusA__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register BOOL __LayoutMenusA__re __asm("d0"); \
  register struct Menu * __LayoutMenusA_firstmenu __asm("a0") = (_LayoutMenusA_firstmenu); \
  register APTR __LayoutMenusA_vi __asm("a1") = (_LayoutMenusA_vi); \
  register const struct TagItem * __LayoutMenusA_taglist __asm("a2") = (_LayoutMenusA_taglist); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__LayoutMenusA__re) \
  : "r"(__LayoutMenusA__bn), "r"(__LayoutMenusA_firstmenu), "r"(__LayoutMenusA_vi), "r"(__LayoutMenusA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LayoutMenusA__re; \
  }); \
  _LayoutMenusA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___LayoutMenus(struct Library * GadToolsBase, struct Menu * firstmenu, APTR vi, Tag taglist, ...)
{
  return LayoutMenusA(firstmenu, vi, (const struct TagItem *) &taglist);
}

#define LayoutMenus(firstmenu, vi...) ___LayoutMenus(GADTOOLS_BASE_NAME, firstmenu, vi)
#endif

#define GT_GetIMsg(iport) ({ \
  struct MsgPort * _GT_GetIMsg_iport = (iport); \
  struct IntuiMessage * _GT_GetIMsg__re = \
  ({ \
  register struct Library * const __GT_GetIMsg__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct IntuiMessage * __GT_GetIMsg__re __asm("d0"); \
  register struct MsgPort * __GT_GetIMsg_iport __asm("a0") = (_GT_GetIMsg_iport); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__GT_GetIMsg__re) \
  : "r"(__GT_GetIMsg__bn), "r"(__GT_GetIMsg_iport) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GT_GetIMsg__re; \
  }); \
  _GT_GetIMsg__re; \
})

#define GT_ReplyIMsg(imsg) ({ \
  struct IntuiMessage * _GT_ReplyIMsg_imsg = (imsg); \
  { \
  register struct Library * const __GT_ReplyIMsg__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct IntuiMessage * __GT_ReplyIMsg_imsg __asm("a1") = (_GT_ReplyIMsg_imsg); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__GT_ReplyIMsg__bn), "r"(__GT_ReplyIMsg_imsg) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GT_RefreshWindow(win, req) ({ \
  struct Window * _GT_RefreshWindow_win = (win); \
  struct Requester * _GT_RefreshWindow_req = (req); \
  { \
  register struct Library * const __GT_RefreshWindow__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct Window * __GT_RefreshWindow_win __asm("a0") = (_GT_RefreshWindow_win); \
  register struct Requester * __GT_RefreshWindow_req __asm("a1") = (_GT_RefreshWindow_req); \
  __asm volatile ("jsr a6@(-84:W)" \
  : \
  : "r"(__GT_RefreshWindow__bn), "r"(__GT_RefreshWindow_win), "r"(__GT_RefreshWindow_req) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GT_BeginRefresh(win) ({ \
  struct Window * _GT_BeginRefresh_win = (win); \
  { \
  register struct Library * const __GT_BeginRefresh__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct Window * __GT_BeginRefresh_win __asm("a0") = (_GT_BeginRefresh_win); \
  __asm volatile ("jsr a6@(-90:W)" \
  : \
  : "r"(__GT_BeginRefresh__bn), "r"(__GT_BeginRefresh_win) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GT_EndRefresh(win, complete) ({ \
  struct Window * _GT_EndRefresh_win = (win); \
  LONG _GT_EndRefresh_complete = (complete); \
  { \
  register struct Library * const __GT_EndRefresh__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct Window * __GT_EndRefresh_win __asm("a0") = (_GT_EndRefresh_win); \
  register LONG __GT_EndRefresh_complete __asm("d0") = (_GT_EndRefresh_complete); \
  __asm volatile ("jsr a6@(-96:W)" \
  : \
  : "r"(__GT_EndRefresh__bn), "r"(__GT_EndRefresh_win), "r"(__GT_EndRefresh_complete) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GT_FilterIMsg(imsg) ({ \
  const struct IntuiMessage * _GT_FilterIMsg_imsg = (imsg); \
  struct IntuiMessage * _GT_FilterIMsg__re = \
  ({ \
  register struct Library * const __GT_FilterIMsg__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct IntuiMessage * __GT_FilterIMsg__re __asm("d0"); \
  register const struct IntuiMessage * __GT_FilterIMsg_imsg __asm("a1") = (_GT_FilterIMsg_imsg); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__GT_FilterIMsg__re) \
  : "r"(__GT_FilterIMsg__bn), "r"(__GT_FilterIMsg_imsg) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GT_FilterIMsg__re; \
  }); \
  _GT_FilterIMsg__re; \
})

#define GT_PostFilterIMsg(imsg) ({ \
  struct IntuiMessage * _GT_PostFilterIMsg_imsg = (imsg); \
  struct IntuiMessage * _GT_PostFilterIMsg__re = \
  ({ \
  register struct Library * const __GT_PostFilterIMsg__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct IntuiMessage * __GT_PostFilterIMsg__re __asm("d0"); \
  register struct IntuiMessage * __GT_PostFilterIMsg_imsg __asm("a1") = (_GT_PostFilterIMsg_imsg); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__GT_PostFilterIMsg__re) \
  : "r"(__GT_PostFilterIMsg__bn), "r"(__GT_PostFilterIMsg_imsg) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GT_PostFilterIMsg__re; \
  }); \
  _GT_PostFilterIMsg__re; \
})

#define CreateContext(glistptr) ({ \
  struct Gadget ** _CreateContext_glistptr = (glistptr); \
  struct Gadget * _CreateContext__re = \
  ({ \
  register struct Library * const __CreateContext__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct Gadget * __CreateContext__re __asm("d0"); \
  register struct Gadget ** __CreateContext_glistptr __asm("a0") = (_CreateContext_glistptr); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__CreateContext__re) \
  : "r"(__CreateContext__bn), "r"(__CreateContext_glistptr) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateContext__re; \
  }); \
  _CreateContext__re; \
})

#define DrawBevelBoxA(rport, left, top, width, height, taglist) ({ \
  struct RastPort * _DrawBevelBoxA_rport = (rport); \
  LONG _DrawBevelBoxA_left = (left); \
  LONG _DrawBevelBoxA_top = (top); \
  LONG _DrawBevelBoxA_width = (width); \
  LONG _DrawBevelBoxA_height = (height); \
  const struct TagItem * _DrawBevelBoxA_taglist = (taglist); \
  { \
  register struct Library * const __DrawBevelBoxA__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register struct RastPort * __DrawBevelBoxA_rport __asm("a0") = (_DrawBevelBoxA_rport); \
  register LONG __DrawBevelBoxA_left __asm("d0") = (_DrawBevelBoxA_left); \
  register LONG __DrawBevelBoxA_top __asm("d1") = (_DrawBevelBoxA_top); \
  register LONG __DrawBevelBoxA_width __asm("d2") = (_DrawBevelBoxA_width); \
  register LONG __DrawBevelBoxA_height __asm("d3") = (_DrawBevelBoxA_height); \
  register const struct TagItem * __DrawBevelBoxA_taglist __asm("a1") = (_DrawBevelBoxA_taglist); \
  __asm volatile ("jsr a6@(-120:W)" \
  : \
  : "r"(__DrawBevelBoxA__bn), "r"(__DrawBevelBoxA_rport), "r"(__DrawBevelBoxA_left), "r"(__DrawBevelBoxA_top), "r"(__DrawBevelBoxA_width), "r"(__DrawBevelBoxA_height), "r"(__DrawBevelBoxA_taglist) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___DrawBevelBox(struct Library * GadToolsBase, struct RastPort * rport, LONG left, LONG top, LONG width, LONG height, Tag taglist, ...)
{
  DrawBevelBoxA(rport, left, top, width, height, (const struct TagItem *) &taglist);
}

#define DrawBevelBox(rport, left, top, width, height...) ___DrawBevelBox(GADTOOLS_BASE_NAME, rport, left, top, width, height)
#endif

#define GetVisualInfoA(screen, taglist) ({ \
  struct Screen * _GetVisualInfoA_screen = (screen); \
  const struct TagItem * _GetVisualInfoA_taglist = (taglist); \
  APTR _GetVisualInfoA__re = \
  ({ \
  register struct Library * const __GetVisualInfoA__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register APTR __GetVisualInfoA__re __asm("d0"); \
  register struct Screen * __GetVisualInfoA_screen __asm("a0") = (_GetVisualInfoA_screen); \
  register const struct TagItem * __GetVisualInfoA_taglist __asm("a1") = (_GetVisualInfoA_taglist); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__GetVisualInfoA__re) \
  : "r"(__GetVisualInfoA__bn), "r"(__GetVisualInfoA_screen), "r"(__GetVisualInfoA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetVisualInfoA__re; \
  }); \
  _GetVisualInfoA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___GetVisualInfo(struct Library * GadToolsBase, struct Screen * screen, Tag taglist, ...)
{
  return GetVisualInfoA(screen, (const struct TagItem *) &taglist);
}

#define GetVisualInfo(screen...) ___GetVisualInfo(GADTOOLS_BASE_NAME, screen)
#endif

#define FreeVisualInfo(vi) ({ \
  APTR _FreeVisualInfo_vi = (vi); \
  { \
  register struct Library * const __FreeVisualInfo__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register APTR __FreeVisualInfo_vi __asm("a0") = (_FreeVisualInfo_vi); \
  __asm volatile ("jsr a6@(-132:W)" \
  : \
  : "r"(__FreeVisualInfo__bn), "r"(__FreeVisualInfo_vi) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GT_GetGadgetAttrsA(gad, win, req, taglist) ({ \
  struct Gadget * _GT_GetGadgetAttrsA_gad = (gad); \
  struct Window * _GT_GetGadgetAttrsA_win = (win); \
  struct Requester * _GT_GetGadgetAttrsA_req = (req); \
  const struct TagItem * _GT_GetGadgetAttrsA_taglist = (taglist); \
  LONG _GT_GetGadgetAttrsA__re = \
  ({ \
  register struct Library * const __GT_GetGadgetAttrsA__bn __asm("a6") = (struct Library *) (GADTOOLS_BASE_NAME);\
  register LONG __GT_GetGadgetAttrsA__re __asm("d0"); \
  register struct Gadget * __GT_GetGadgetAttrsA_gad __asm("a0") = (_GT_GetGadgetAttrsA_gad); \
  register struct Window * __GT_GetGadgetAttrsA_win __asm("a1") = (_GT_GetGadgetAttrsA_win); \
  register struct Requester * __GT_GetGadgetAttrsA_req __asm("a2") = (_GT_GetGadgetAttrsA_req); \
  register const struct TagItem * __GT_GetGadgetAttrsA_taglist __asm("a3") = (_GT_GetGadgetAttrsA_taglist); \
  __asm volatile ("jsr a6@(-174:W)" \
  : "=r"(__GT_GetGadgetAttrsA__re) \
  : "r"(__GT_GetGadgetAttrsA__bn), "r"(__GT_GetGadgetAttrsA_gad), "r"(__GT_GetGadgetAttrsA_win), "r"(__GT_GetGadgetAttrsA_req), "r"(__GT_GetGadgetAttrsA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GT_GetGadgetAttrsA__re; \
  }); \
  _GT_GetGadgetAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___GT_GetGadgetAttrs(struct Library * GadToolsBase, struct Gadget * gad, struct Window * win, struct Requester * req, Tag taglist, ...)
{
  return GT_GetGadgetAttrsA(gad, win, req, (const struct TagItem *) &taglist);
}

#define GT_GetGadgetAttrs(gad, win, req...) ___GT_GetGadgetAttrs(GADTOOLS_BASE_NAME, gad, win, req)
#endif

#endif /*  _INLINE_GADTOOLS_H  */
