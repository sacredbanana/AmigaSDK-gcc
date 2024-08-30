/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_PPCDISS_H
#define _PPCINLINE_PPCDISS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef PPCDISS_BASE_NAME
#define PPCDISS_BASE_NAME PPCDissBase
#endif /* !PPCDISS_BASE_NAME */

#define PPCDissTranslateTagList(__p0, __p1) \
	LP2(42, ULONG , PPCDissTranslateTagList, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, PPCDISS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCDissCreateObjectTagList(__p0) \
	LP1(30, APTR , PPCDissCreateObjectTagList, \
		struct TagItem *, __p0, a0, \
		, PPCDISS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PPCDissDeleteObject(__p0) \
	LP1NR(36, PPCDissDeleteObject, \
		APTR , __p0, a0, \
		, PPCDISS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define PPCDissCreateObjectTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCDissCreateObjectTagList((struct TagItem *)_tags);})

#define PPCDissTranslateTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	PPCDissTranslateTagList(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_PPCDISS_H */
