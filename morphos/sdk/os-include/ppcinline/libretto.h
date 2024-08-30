/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_LIBRETTO_H
#define _PPCINLINE_LIBRETTO_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef LIBRETTO_BASE_NAME
#define LIBRETTO_BASE_NAME LibrettoBase
#endif /* !LIBRETTO_BASE_NAME */

#define NewGlyphRunA(__p0, __p1, __p2) \
	(((Object *(*)(void *, APTR , LONG , struct TagItem *))*(void**)((long)(LIBRETTO_BASE_NAME) - 28))((void*)(LIBRETTO_BASE_NAME), __p0, __p1, __p2))

#define NewDrawTargetA(__p0, __p1, __p2) \
	(((Object *(*)(void *, APTR , LONG , struct TagItem *))*(void**)((long)(LIBRETTO_BASE_NAME) - 34))((void*)(LIBRETTO_BASE_NAME), __p0, __p1, __p2))

#define DrawGlyphRun(__p0, __p1, __p2, __p3) \
	(((VOID (*)(void *, Object *, Object *, LONG , LONG ))*(void**)((long)(LIBRETTO_BASE_NAME) - 40))((void*)(LIBRETTO_BASE_NAME), __p0, __p1, __p2, __p3))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define NewDrawTarget(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewDrawTargetA(__p0, __p1, (struct TagItem *)_tags);})

#define NewGlyphRun(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	NewGlyphRunA(__p0, __p1, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_LIBRETTO_H */
