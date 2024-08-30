/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_POPCYCLE_H
#define _PPCINLINE_POPCYCLE_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef POPCYCLE_BASE_NAME
#define POPCYCLE_BASE_NAME PopCycleBase
#endif /* !POPCYCLE_BASE_NAME */

#define POPCYCLE_GetClass() \
	LP0(30, Class *, POPCYCLE_GetClass, \
		, POPCYCLE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocPopCycleNodeA(__p0) \
	LP1(36, struct Node *, AllocPopCycleNodeA, \
		struct TagItem *, __p0, a0, \
		, POPCYCLE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetPopCycleNodeAttrsA(__p0, __p1) \
	LP2NR(54, GetPopCycleNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, POPCYCLE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetPopCycleNodeAttrsA(__p0, __p1) \
	LP2NR(48, SetPopCycleNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, POPCYCLE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreePopCycleNode(__p0) \
	LP1NR(42, FreePopCycleNode, \
		struct Node *, __p0, a0, \
		, POPCYCLE_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define AllocPopCycleNode(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocPopCycleNodeA((struct TagItem *)_tags);})

#define SetPopCycleNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetPopCycleNodeAttrsA(__p0, (struct TagItem *)_tags);})

#define GetPopCycleNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetPopCycleNodeAttrsA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_POPCYCLE_H */
