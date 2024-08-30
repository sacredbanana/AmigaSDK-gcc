/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_VIRTUAL_H
#define _INLINE_VIRTUAL_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

Class * __VIRTUAL_GetClass(__reg("a6") struct Library * ) = "\tjsr\t-30(a6)";
#define VIRTUAL_GetClass() __VIRTUAL_GetClass(VirtualBase)

VOID __RefreshVirtualGadget(__reg("a6") struct Library * , __reg("a0") struct Gadget * gadget , __reg("a1") Object * obj , __reg("a2") struct Window * window , __reg("a3") struct Requester * requester ) = "\tjsr\t-36(a6)";
#define RefreshVirtualGadget(gadget, obj, window, requester) __RefreshVirtualGadget(VirtualBase, (gadget), (obj), (window), (requester))

BOOL __RethinkVirtualSize(__reg("a6") struct Library * , __reg("a0") Object * virt_obj , __reg("a1") Object * rootlayout , __reg("a2") struct TextFont * font , __reg("a3") struct Screen * screen , __reg("d0") struct LayoutLimits * layoutlimits ) = "\tjsr\t-42(a6)";
#define RethinkVirtualSize(virt_obj, rootlayout, font, screen, layoutlimits) __RethinkVirtualSize(VirtualBase, (virt_obj), (rootlayout), (font), (screen), (layoutlimits))

#endif /* !_INLINE_VIRTUAL_H */
