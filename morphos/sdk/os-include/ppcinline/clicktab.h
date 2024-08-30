/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CLICKTAB_H
#define _PPCINLINE_CLICKTAB_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CLICKTAB_BASE_NAME
#define CLICKTAB_BASE_NAME ClickTabBase
#endif /* !CLICKTAB_BASE_NAME */

#define FreeClickTabNode(__p0) \
	LP1NR(42, FreeClickTabNode, \
		struct Node *, __p0, a0, \
		, CLICKTAB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocClickTabNodeA(__p0) \
	LP1(36, struct Node *, AllocClickTabNodeA, \
		struct TagItem *, __p0, a0, \
		, CLICKTAB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CLICKTAB_GetClass() \
	LP0(30, Class *, CLICKTAB_GetClass, \
		, CLICKTAB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetClickTabNodeAttrsA(__p0, __p1) \
	LP2NR(54, GetClickTabNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, CLICKTAB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetClickTabNodeAttrsA(__p0, __p1) \
	LP2NR(48, SetClickTabNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, CLICKTAB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define AllocClickTabNode(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocClickTabNodeA((struct TagItem *)_tags);})

#define GetClickTabNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetClickTabNodeAttrsA(__p0, (struct TagItem *)_tags);})

#define SetClickTabNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetClickTabNodeAttrsA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_CLICKTAB_H */
