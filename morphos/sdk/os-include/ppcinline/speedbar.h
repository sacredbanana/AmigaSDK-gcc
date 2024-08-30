/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SPEEDBAR_H
#define _PPCINLINE_SPEEDBAR_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SPEEDBAR_BASE_NAME
#define SPEEDBAR_BASE_NAME SpeedBarBase
#endif /* !SPEEDBAR_BASE_NAME */

#define GetSpeedButtonNodeAttrsA(__p0, __p1) \
	LP2NR(54, GetSpeedButtonNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, SPEEDBAR_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocSpeedButtonNodeA(__p0, __p1) \
	LP2(36, struct Node *, AllocSpeedButtonNodeA, \
		ULONG , __p0, d0, \
		struct TagItem *, __p1, a0, \
		, SPEEDBAR_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetSpeedButtonNodeAttrsA(__p0, __p1) \
	LP2NR(48, SetSpeedButtonNodeAttrsA, \
		struct Node *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, SPEEDBAR_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeSpeedButtonNode(__p0) \
	LP1NR(42, FreeSpeedButtonNode, \
		struct Node *, __p0, a0, \
		, SPEEDBAR_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SPEEDBAR_GetClass() \
	LP0(30, Class *, SPEEDBAR_GetClass, \
		, SPEEDBAR_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define AllocSpeedButtonNode(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocSpeedButtonNodeA(__p0, (struct TagItem *)_tags);})

#define GetSpeedButtonNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetSpeedButtonNodeAttrsA(__p0, (struct TagItem *)_tags);})

#define SetSpeedButtonNodeAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetSpeedButtonNodeAttrsA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_SPEEDBAR_H */
