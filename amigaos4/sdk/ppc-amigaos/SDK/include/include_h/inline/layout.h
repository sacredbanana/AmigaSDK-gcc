#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_LAYOUT_H
#define _INLINE_LAYOUT_H

#ifndef CLIB_LAYOUT_PROTOS_H
#define CLIB_LAYOUT_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  GADGETS_LAYOUT_H
#include <gadgets/layout.h>
#endif

#ifndef LAYOUT_BASE_NAME
#define LAYOUT_BASE_NAME LayoutBase
#endif

#define LAYOUT_GetClass() ({ \
  Class * _LAYOUT_GetClass__re = \
  ({ \
  register struct Library * const __LAYOUT_GetClass__bn __asm("a6") = (struct Library *) (LAYOUT_BASE_NAME);\
  register Class * __LAYOUT_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__LAYOUT_GetClass__re) \
  : "r"(__LAYOUT_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LAYOUT_GetClass__re; \
  }); \
  _LAYOUT_GetClass__re; \
})

#define ActivateLayoutGadget(gadget, window, requester, object) ({ \
  struct Gadget * _ActivateLayoutGadget_gadget = (gadget); \
  struct Window * _ActivateLayoutGadget_window = (window); \
  struct Requester * _ActivateLayoutGadget_requester = (requester); \
  ULONG _ActivateLayoutGadget_object = (object); \
  BOOL _ActivateLayoutGadget__re = \
  ({ \
  register struct Library * const __ActivateLayoutGadget__bn __asm("a6") = (struct Library *) (LAYOUT_BASE_NAME);\
  register BOOL __ActivateLayoutGadget__re __asm("d0"); \
  register struct Gadget * __ActivateLayoutGadget_gadget __asm("a0") = (_ActivateLayoutGadget_gadget); \
  register struct Window * __ActivateLayoutGadget_window __asm("a1") = (_ActivateLayoutGadget_window); \
  register struct Requester * __ActivateLayoutGadget_requester __asm("a2") = (_ActivateLayoutGadget_requester); \
  register ULONG __ActivateLayoutGadget_object __asm("d0") = (_ActivateLayoutGadget_object); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__ActivateLayoutGadget__re) \
  : "r"(__ActivateLayoutGadget__bn), "r"(__ActivateLayoutGadget_gadget), "r"(__ActivateLayoutGadget_window), "r"(__ActivateLayoutGadget_requester), "r"(__ActivateLayoutGadget_object) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ActivateLayoutGadget__re; \
  }); \
  _ActivateLayoutGadget__re; \
})

#define FlushLayoutDomainCache(gadget) ({ \
  struct Gadget * _FlushLayoutDomainCache_gadget = (gadget); \
  { \
  register struct Library * const __FlushLayoutDomainCache__bn __asm("a6") = (struct Library *) (LAYOUT_BASE_NAME);\
  register struct Gadget * __FlushLayoutDomainCache_gadget __asm("a0") = (_FlushLayoutDomainCache_gadget); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__FlushLayoutDomainCache__bn), "r"(__FlushLayoutDomainCache_gadget) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RethinkLayout(gadget, window, requester, refresh) ({ \
  struct Gadget * _RethinkLayout_gadget = (gadget); \
  struct Window * _RethinkLayout_window = (window); \
  struct Requester * _RethinkLayout_requester = (requester); \
  LONG _RethinkLayout_refresh = (refresh); \
  BOOL _RethinkLayout__re = \
  ({ \
  register struct Library * const __RethinkLayout__bn __asm("a6") = (struct Library *) (LAYOUT_BASE_NAME);\
  register BOOL __RethinkLayout__re __asm("d0"); \
  register struct Gadget * __RethinkLayout_gadget __asm("a0") = (_RethinkLayout_gadget); \
  register struct Window * __RethinkLayout_window __asm("a1") = (_RethinkLayout_window); \
  register struct Requester * __RethinkLayout_requester __asm("a2") = (_RethinkLayout_requester); \
  register LONG __RethinkLayout_refresh __asm("d0") = (_RethinkLayout_refresh); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__RethinkLayout__re) \
  : "r"(__RethinkLayout__bn), "r"(__RethinkLayout_gadget), "r"(__RethinkLayout_window), "r"(__RethinkLayout_requester), "r"(__RethinkLayout_refresh) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RethinkLayout__re; \
  }); \
  _RethinkLayout__re; \
})

#define LayoutLimits(gadget, limits, font, screen) ({ \
  struct Gadget * _LayoutLimits_gadget = (gadget); \
  struct LayoutLimits * _LayoutLimits_limits = (limits); \
  struct TextFont * _LayoutLimits_font = (font); \
  struct Screen * _LayoutLimits_screen = (screen); \
  { \
  register struct Library * const __LayoutLimits__bn __asm("a6") = (struct Library *) (LAYOUT_BASE_NAME);\
  register struct Gadget * __LayoutLimits_gadget __asm("a0") = (_LayoutLimits_gadget); \
  register struct LayoutLimits * __LayoutLimits_limits __asm("a1") = (_LayoutLimits_limits); \
  register struct TextFont * __LayoutLimits_font __asm("a2") = (_LayoutLimits_font); \
  register struct Screen * __LayoutLimits_screen __asm("a3") = (_LayoutLimits_screen); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__LayoutLimits__bn), "r"(__LayoutLimits_gadget), "r"(__LayoutLimits_limits), "r"(__LayoutLimits_font), "r"(__LayoutLimits_screen) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define PAGE_GetClass() ({ \
  Class * _PAGE_GetClass__re = \
  ({ \
  register struct Library * const __PAGE_GetClass__bn __asm("a6") = (struct Library *) (LAYOUT_BASE_NAME);\
  register Class * __PAGE_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__PAGE_GetClass__re) \
  : "r"(__PAGE_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PAGE_GetClass__re; \
  }); \
  _PAGE_GetClass__re; \
})

#define SetPageGadgetAttrsA(gadget, object, window, requester, tags) ({ \
  struct Gadget * _SetPageGadgetAttrsA_gadget = (gadget); \
  Object * _SetPageGadgetAttrsA_object = (object); \
  struct Window * _SetPageGadgetAttrsA_window = (window); \
  struct Requester * _SetPageGadgetAttrsA_requester = (requester); \
  struct TagItem * _SetPageGadgetAttrsA_tags = (tags); \
  ULONG _SetPageGadgetAttrsA__re = \
  ({ \
  register struct Library * const __SetPageGadgetAttrsA__bn __asm("a6") = (struct Library *) (LAYOUT_BASE_NAME);\
  register ULONG __SetPageGadgetAttrsA__re __asm("d0"); \
  register struct Gadget * __SetPageGadgetAttrsA_gadget __asm("a0") = (_SetPageGadgetAttrsA_gadget); \
  register Object * __SetPageGadgetAttrsA_object __asm("a1") = (_SetPageGadgetAttrsA_object); \
  register struct Window * __SetPageGadgetAttrsA_window __asm("a2") = (_SetPageGadgetAttrsA_window); \
  register struct Requester * __SetPageGadgetAttrsA_requester __asm("a3") = (_SetPageGadgetAttrsA_requester); \
  register struct TagItem * __SetPageGadgetAttrsA_tags __asm("d2") = (_SetPageGadgetAttrsA_tags); \
  __asm volatile ("exg a4,d2\n\tjsr a6@(-66:W)\n\texg a4,d2" \
  : "=r"(__SetPageGadgetAttrsA__re) \
  : "r"(__SetPageGadgetAttrsA__bn), "r"(__SetPageGadgetAttrsA_gadget), "r"(__SetPageGadgetAttrsA_object), "r"(__SetPageGadgetAttrsA_window), "r"(__SetPageGadgetAttrsA_requester), "r"(__SetPageGadgetAttrsA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetPageGadgetAttrsA__re; \
  }); \
  _SetPageGadgetAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___SetPageGadgetAttrs(struct Library * LayoutBase, struct Gadget * gadget, Object * object, struct Window * window, struct Requester * requester, ...)
{
  return SetPageGadgetAttrsA(gadget, object, window, requester, (struct TagItem *) ((ULONG) &requester + sizeof(struct Requester *)));
}

#define SetPageGadgetAttrs(gadget, object, window, requester...) ___SetPageGadgetAttrs(LAYOUT_BASE_NAME, gadget, object, window, requester)
#endif

#define RefreshPageGadget(gadget, object, window, requester) ({ \
  struct Gadget * _RefreshPageGadget_gadget = (gadget); \
  Object * _RefreshPageGadget_object = (object); \
  struct Window * _RefreshPageGadget_window = (window); \
  struct Requester * _RefreshPageGadget_requester = (requester); \
  { \
  register struct Library * const __RefreshPageGadget__bn __asm("a6") = (struct Library *) (LAYOUT_BASE_NAME);\
  register struct Gadget * __RefreshPageGadget_gadget __asm("a0") = (_RefreshPageGadget_gadget); \
  register Object * __RefreshPageGadget_object __asm("a1") = (_RefreshPageGadget_object); \
  register struct Window * __RefreshPageGadget_window __asm("a2") = (_RefreshPageGadget_window); \
  register struct Requester * __RefreshPageGadget_requester __asm("a3") = (_RefreshPageGadget_requester); \
  __asm volatile ("jsr a6@(-72:W)" \
  : \
  : "r"(__RefreshPageGadget__bn), "r"(__RefreshPageGadget_gadget), "r"(__RefreshPageGadget_object), "r"(__RefreshPageGadget_window), "r"(__RefreshPageGadget_requester) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_LAYOUT_H  */
