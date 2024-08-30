/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_MYSTICVIEW_H
#define _PPCINLINE_MYSTICVIEW_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef MYSTICVIEW_BASE_NAME
#define MYSTICVIEW_BASE_NAME MysticBase
#endif /* !MYSTICVIEW_BASE_NAME */

#define MV_GetAttrsA(__p0, __p1) \
	LP2NR(66, MV_GetAttrsA, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, MYSTICVIEW_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MV_Delete(__p0) \
	LP1NR(36, MV_Delete, \
		APTR , __p0, a0, \
		, MYSTICVIEW_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MV_SetAttrsA(__p0, __p1) \
	LP2NR(42, MV_SetAttrsA, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, MYSTICVIEW_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MV_SetViewStart(__p0, __p1, __p2) \
	LP3NR(72, MV_SetViewStart, \
		APTR , __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, MYSTICVIEW_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MV_SetViewRelative(__p0, __p1, __p2) \
	LP3NR(78, MV_SetViewRelative, \
		APTR , __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, MYSTICVIEW_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MV_DrawOff(__p0) \
	LP1NR(54, MV_DrawOff, \
		APTR , __p0, a0, \
		, MYSTICVIEW_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MV_DrawOn(__p0) \
	LP1(48, BOOL , MV_DrawOn, \
		APTR , __p0, a0, \
		, MYSTICVIEW_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MV_CreateA(__p0, __p1, __p2) \
	LP3(30, APTR , MV_CreateA, \
		struct Screen *, __p0, a0, \
		struct RastPort *, __p1, a1, \
		struct TagItem *, __p2, a2, \
		, MYSTICVIEW_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MV_Refresh(__p0) \
	LP1NR(60, MV_Refresh, \
		APTR , __p0, a0, \
		, MYSTICVIEW_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define MV_Create(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MV_CreateA(__p0, __p1, (struct TagItem *)_tags);})

#define MV_SetAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MV_SetAttrsA(__p0, (struct TagItem *)_tags);})

#define MV_GetAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MV_GetAttrsA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_MYSTICVIEW_H */
