/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_BULLET_H
#define _PPCINLINE_BULLET_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef BULLET_BASE_NAME
#define BULLET_BASE_NAME BulletBase
#endif /* !BULLET_BASE_NAME */

#define OpenEngine() \
	LP0(30, struct GlyphEngine *, OpenEngine, \
		, BULLET_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainInfoA(__p0, __p1) \
	LP2(48, ULONG , ObtainInfoA, \
		struct GlyphEngine *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, BULLET_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseEngine(__p0) \
	LP1NR(36, CloseEngine, \
		struct GlyphEngine *, __p0, a0, \
		, BULLET_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleaseInfoA(__p0, __p1) \
	LP2(54, ULONG , ReleaseInfoA, \
		struct GlyphEngine *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, BULLET_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetInfoA(__p0, __p1) \
	LP2(42, ULONG , SetInfoA, \
		struct GlyphEngine *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, BULLET_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define ObtainInfo(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ObtainInfoA(__p0, (struct TagItem *)_tags);})

#define ReleaseInfo(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ReleaseInfoA(__p0, (struct TagItem *)_tags);})

#define SetInfo(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetInfoA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_BULLET_H */
