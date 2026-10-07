#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_VIRTUAL_H
#define _INLINE_VIRTUAL_H

#ifndef CLIB_VIRTUAL_PROTOS_H
#define CLIB_VIRTUAL_PROTOS_H
#endif

#ifndef  INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef  GADGETS_LAYOUT_H
#include <gadgets/layout.h>
#endif

#ifndef VIRTUAL_BASE_NAME
#define VIRTUAL_BASE_NAME VirtualBase
#endif

#define VIRTUAL_GetClass() ({ \
  Class * _VIRTUAL_GetClass__re = \
  ({ \
  register struct Library * const __VIRTUAL_GetClass__bn __asm("a6") = (struct Library *) (VIRTUAL_BASE_NAME);\
  register Class * __VIRTUAL_GetClass__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__VIRTUAL_GetClass__re) \
  : "r"(__VIRTUAL_GetClass__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __VIRTUAL_GetClass__re; \
  }); \
  _VIRTUAL_GetClass__re; \
})

#define RefreshVirtualGadget(gadget, obj, window, requester) ({ \
  struct Gadget * _RefreshVirtualGadget_gadget = (gadget); \
  Object * _RefreshVirtualGadget_obj = (obj); \
  struct Window * _RefreshVirtualGadget_window = (window); \
  struct Requester * _RefreshVirtualGadget_requester = (requester); \
  { \
  register struct Library * const __RefreshVirtualGadget__bn __asm("a6") = (struct Library *) (VIRTUAL_BASE_NAME);\
  register struct Gadget * __RefreshVirtualGadget_gadget __asm("a0") = (_RefreshVirtualGadget_gadget); \
  register Object * __RefreshVirtualGadget_obj __asm("a1") = (_RefreshVirtualGadget_obj); \
  register struct Window * __RefreshVirtualGadget_window __asm("a2") = (_RefreshVirtualGadget_window); \
  register struct Requester * __RefreshVirtualGadget_requester __asm("a3") = (_RefreshVirtualGadget_requester); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__RefreshVirtualGadget__bn), "r"(__RefreshVirtualGadget_gadget), "r"(__RefreshVirtualGadget_obj), "r"(__RefreshVirtualGadget_window), "r"(__RefreshVirtualGadget_requester) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RethinkVirtualSize(virt_obj, rootlayout, font, screen, layoutlimits) ({ \
  Object * _RethinkVirtualSize_virt_obj = (virt_obj); \
  Object * _RethinkVirtualSize_rootlayout = (rootlayout); \
  struct TextFont * _RethinkVirtualSize_font = (font); \
  struct Screen * _RethinkVirtualSize_screen = (screen); \
  struct LayoutLimits * _RethinkVirtualSize_layoutlimits = (layoutlimits); \
  BOOL _RethinkVirtualSize__re = \
  ({ \
  register struct Library * const __RethinkVirtualSize__bn __asm("a6") = (struct Library *) (VIRTUAL_BASE_NAME);\
  register BOOL __RethinkVirtualSize__re __asm("d0"); \
  register Object * __RethinkVirtualSize_virt_obj __asm("a0") = (_RethinkVirtualSize_virt_obj); \
  register Object * __RethinkVirtualSize_rootlayout __asm("a1") = (_RethinkVirtualSize_rootlayout); \
  register struct TextFont * __RethinkVirtualSize_font __asm("a2") = (_RethinkVirtualSize_font); \
  register struct Screen * __RethinkVirtualSize_screen __asm("a3") = (_RethinkVirtualSize_screen); \
  register struct LayoutLimits * __RethinkVirtualSize_layoutlimits __asm("d0") = (_RethinkVirtualSize_layoutlimits); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__RethinkVirtualSize__re) \
  : "r"(__RethinkVirtualSize__bn), "r"(__RethinkVirtualSize_virt_obj), "r"(__RethinkVirtualSize_rootlayout), "r"(__RethinkVirtualSize_font), "r"(__RethinkVirtualSize_screen), "r"(__RethinkVirtualSize_layoutlimits) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RethinkVirtualSize__re; \
  }); \
  _RethinkVirtualSize__re; \
})

#endif /*  _INLINE_VIRTUAL_H  */
