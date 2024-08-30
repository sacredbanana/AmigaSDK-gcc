/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_EXTRAS_H
#define _PPCINLINE_EXTRAS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef EXTRAS_BASE_NAME
#define EXTRAS_BASE_NAME ExtrasBase
#endif /* !EXTRAS_BASE_NAME */

#define LoadImageToArrayA(__p0, __p1) \
	(((APTR (*)(void *, CONST_STRPTR , struct TagItem *))*(void**)((long)(EXTRAS_BASE_NAME) - 40))((void*)(EXTRAS_BASE_NAME), __p0, __p1))

#define LoadImageToBitMapA(__p0, __p1) \
	(((struct BitMap *(*)(void *, CONST_STRPTR , struct TagItem *))*(void**)((long)(EXTRAS_BASE_NAME) - 28))((void*)(EXTRAS_BASE_NAME), __p0, __p1))

#define LoadFileA(__p0, __p1) \
	(((APTR (*)(void *, CONST_STRPTR , struct TagItem *))*(void**)((long)(EXTRAS_BASE_NAME) - 34))((void*)(EXTRAS_BASE_NAME), __p0, __p1))

#ifdef USE_INLINE_STDARG

#include <stdarg.h>

#define LoadImageToArray(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LoadImageToArrayA(__p0, (struct TagItem *)_tags);})

#define LoadImageToBitMap(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LoadImageToBitMapA(__p0, (struct TagItem *)_tags);})

#define LoadFile(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LoadFileA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_EXTRAS_H */
