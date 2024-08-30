/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_ASOUND_H
#define _PPCINLINE_ASOUND_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef ASOUND_BASE_NAME
#define ASOUND_BASE_NAME ASoundBase
#endif /* !ASOUND_BASE_NAME */

#define ASound_Abort(__p0) \
	(((void (*)(APTR ))*(void**)((long)(ASOUND_BASE_NAME) - 58))(__p0))

#define ASound_GetAttr(__p0, __p1) \
	(((APTR (*)(APTR , ULONG ))*(void**)((long)(ASOUND_BASE_NAME) - 64))(__p0, __p1))

#define ASound_PlaySync(__p0, __p1, __p2) \
	(((ULONG (*)(APTR , APTR , ULONG ))*(void**)((long)(ASOUND_BASE_NAME) - 40))(__p0, __p1, __p2))

#define ASound_Delete(__p0) \
	(((void (*)(APTR ))*(void**)((long)(ASOUND_BASE_NAME) - 34))(__p0))

#define ASound_PlayAsync(__p0, __p1, __p2) \
	(((ULONG (*)(APTR , APTR , ULONG ))*(void**)((long)(ASOUND_BASE_NAME) - 46))(__p0, __p1, __p2))

#define ASound_Create(__p0, __p1) \
	(((APTR (*)(ULONG , struct TagItem *))*(void**)((long)(ASOUND_BASE_NAME) - 28))(__p0, __p1))

#define ASound_Wait(__p0) \
	(((ULONG (*)(APTR ))*(void**)((long)(ASOUND_BASE_NAME) - 52))(__p0))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define ASound_CreateTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ASound_Create(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_ASOUND_H */
