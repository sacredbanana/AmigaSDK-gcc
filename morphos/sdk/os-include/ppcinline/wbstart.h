/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_WBSTART_H
#define _PPCINLINE_WBSTART_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef WBSTART_BASE_NAME
#define WBSTART_BASE_NAME WBStartBase
#endif /* !WBSTART_BASE_NAME */

#define WBStartTagList(__p0) \
	LP1(36, LONG , WBStartTagList, \
		struct TagItem *, __p0, a0, \
		, WBSTART_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define WBStartTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	WBStartTagList((struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_WBSTART_H */
