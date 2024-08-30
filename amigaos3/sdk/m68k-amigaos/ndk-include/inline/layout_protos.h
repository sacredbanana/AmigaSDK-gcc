/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_LAYOUT_H
#define _INLINE_LAYOUT_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

Class * __LAYOUT_GetClass(__reg("a6") struct Library * ) = "\tjsr\t-30(a6)";
#define LAYOUT_GetClass() __LAYOUT_GetClass(LayoutBase)

BOOL __ActivateLayoutGadget(__reg("a6") struct Library * , __reg("a0") struct Gadget * gadget , __reg("a1") struct Window * window , __reg("a2") struct Requester * requester , __reg("d0") ULONG object ) = "\tjsr\t-36(a6)";
#define ActivateLayoutGadget(gadget, window, requester, object) __ActivateLayoutGadget(LayoutBase, (gadget), (window), (requester), (object))

VOID __FlushLayoutDomainCache(__reg("a6") struct Library * , __reg("a0") struct Gadget * gadget ) = "\tjsr\t-42(a6)";
#define FlushLayoutDomainCache(gadget) __FlushLayoutDomainCache(LayoutBase, (gadget))

BOOL __RethinkLayout(__reg("a6") struct Library * , __reg("a0") struct Gadget * gadget , __reg("a1") struct Window * window , __reg("a2") struct Requester * requester , __reg("d0") LONG refresh ) = "\tjsr\t-48(a6)";
#define RethinkLayout(gadget, window, requester, refresh) __RethinkLayout(LayoutBase, (gadget), (window), (requester), (refresh))

VOID __LayoutLimits(__reg("a6") struct Library * , __reg("a0") struct Gadget * gadget , __reg("a1") struct LayoutLimits * limits , __reg("a2") struct TextFont * font , __reg("a3") struct Screen * screen ) = "\tjsr\t-54(a6)";
#define LayoutLimits(gadget, limits, font, screen) __LayoutLimits(LayoutBase, (gadget), (limits), (font), (screen))

Class * __PAGE_GetClass(__reg("a6") struct Library * ) = "\tjsr\t-60(a6)";
#define PAGE_GetClass() __PAGE_GetClass(LayoutBase)

ULONG __SetPageGadgetAttrsA(__reg("a6") struct Library * , __reg("a0") struct Gadget * gadget , __reg("a1") Object * object , __reg("a2") struct Window * window , __reg("a3") struct Requester * requester , __reg("a4") struct TagItem * tags ) = "\tjsr\t-66(a6)";
#define SetPageGadgetAttrsA(gadget, object, window, requester, tags) __SetPageGadgetAttrsA(LayoutBase, (gadget), (object), (window), (requester), (tags))

#if !defined(NO_INLINE_STDARG) && (__STDC__ == 1L) && (__STDC_VERSION__ >= 199901L)
ULONG __SetPageGadgetAttrs(__reg("a6") struct Library * , __reg("a0") struct Gadget * gadget , __reg("a1") Object * object , __reg("a2") struct Window * window , __reg("a3") struct Requester * requester , Tag _tag1 , ... ) = "\tmove.l\ta4,-(a7)\n\tlea\t4(a7),a4\n\tjsr\t-66(a6)\n\tmovea.l\t(a7)+,a4";
#define SetPageGadgetAttrs(gadget, object, window, requester, ...) __SetPageGadgetAttrs(LayoutBase, (gadget), (object), (window), (requester), __VA_ARGS__)
#endif

VOID __RefreshPageGadget(__reg("a6") struct Library * , __reg("a0") struct Gadget * gadget , __reg("a1") Object * object , __reg("a2") struct Window * window , __reg("a3") struct Requester * requester ) = "\tjsr\t-72(a6)";
#define RefreshPageGadget(gadget, object, window, requester) __RefreshPageGadget(LayoutBase, (gadget), (object), (window), (requester))

#endif /* !_INLINE_LAYOUT_H */
