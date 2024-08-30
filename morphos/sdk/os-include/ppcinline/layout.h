/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_LAYOUT_H
#define _PPCINLINE_LAYOUT_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef LAYOUT_BASE_NAME
#define LAYOUT_BASE_NAME LayoutBase
#endif /* !LAYOUT_BASE_NAME */

#define SetPageGadgetAttrsA(__p0, __p1, __p2, __p3, __p4) \
	LP5(66, ULONG , SetPageGadgetAttrsA, \
		struct Gadget *, __p0, a0, \
		Object *, __p1, a1, \
		struct Window *, __p2, a2, \
		struct Requester *, __p3, a3, \
		struct TagItem *, __p4, a4, \
		, LAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PAGE_GetClass() \
	LP0(60, Class *, PAGE_GetClass, \
		, LAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RethinkLayout(__p0, __p1, __p2, __p3) \
	LP4(48, BOOL , RethinkLayout, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		LONG , __p3, d0, \
		, LAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ActivateLayoutGadget(__p0, __p1, __p2, __p3) \
	LP4(36, BOOL , ActivateLayoutGadget, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		ULONG , __p3, d0, \
		, LAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LayoutLimits(__p0, __p1, __p2, __p3) \
	LP4NR(54, LayoutLimits, \
		struct Gadget *, __p0, a0, \
		struct LayoutLimits *, __p1, a1, \
		struct TextFont *, __p2, a2, \
		struct Screen *, __p3, a3, \
		, LAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LAYOUT_GetClass() \
	LP0(30, Class *, LAYOUT_GetClass, \
		, LAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FlushLayoutDomainCache(__p0) \
	LP1NR(42, FlushLayoutDomainCache, \
		struct Gadget *, __p0, a0, \
		, LAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RefreshPageGadget(__p0, __p1, __p2, __p3) \
	LP4NR(72, RefreshPageGadget, \
		struct Gadget *, __p0, a0, \
		Object *, __p1, a1, \
		struct Window *, __p2, a2, \
		struct Requester *, __p3, a3, \
		, LAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define SetPageGadgetAttrs(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetPageGadgetAttrsA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_LAYOUT_H */
