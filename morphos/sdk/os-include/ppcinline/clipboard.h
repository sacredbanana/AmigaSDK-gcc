/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CLIPBOARD_H
#define _PPCINLINE_CLIPBOARD_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CLIPBOARD_BASE_NAME
#define CLIPBOARD_BASE_NAME ClipboardBase
#endif /* !CLIPBOARD_BASE_NAME */

#define ReadClipTextA(__p0) \
	(((APTR (*)(void *, struct TagItem *))*(void**)((long)(CLIPBOARD_BASE_NAME) - 28))((void*)(CLIPBOARD_BASE_NAME), __p0))

#define WriteClipTextA(__p0, __p1) \
	(((LONG (*)(void *, CONST_APTR , struct TagItem *))*(void**)((long)(CLIPBOARD_BASE_NAME) - 34))((void*)(CLIPBOARD_BASE_NAME), __p0, __p1))

#define ReadClipSoundA(__p0) \
	(((APTR (*)(void *, struct TagItem *))*(void**)((long)(CLIPBOARD_BASE_NAME) - 64))((void*)(CLIPBOARD_BASE_NAME), __p0))

#define WriteClipSoundA(__p0) \
	(((LONG (*)(void *, struct TagItem *))*(void**)((long)(CLIPBOARD_BASE_NAME) - 70))((void*)(CLIPBOARD_BASE_NAME), __p0))

#define FreeClipText(__p0) \
	(((VOID (*)(void *, CONST_APTR ))*(void**)((long)(CLIPBOARD_BASE_NAME) - 40))((void*)(CLIPBOARD_BASE_NAME), __p0))

#define GetClipType(__p0) \
	(((LONG (*)(void *, ULONG ))*(void**)((long)(CLIPBOARD_BASE_NAME) - 46))((void*)(CLIPBOARD_BASE_NAME), __p0))

#define WriteClipImageA(__p0) \
	(((LONG (*)(void *, struct TagItem *))*(void**)((long)(CLIPBOARD_BASE_NAME) - 58))((void*)(CLIPBOARD_BASE_NAME), __p0))

#define ReadClipImageA(__p0) \
	(((APTR (*)(void *, struct TagItem *))*(void**)((long)(CLIPBOARD_BASE_NAME) - 52))((void*)(CLIPBOARD_BASE_NAME), __p0))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define ReadClipImage(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ReadClipImageA((struct TagItem *)_tags);})

#define WriteClipImage(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	WriteClipImageA((struct TagItem *)_tags);})

#define ReadClipSound(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ReadClipSoundA((struct TagItem *)_tags);})

#define WriteClipSound(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	WriteClipSoundA((struct TagItem *)_tags);})

#define ReadClipText(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ReadClipTextA((struct TagItem *)_tags);})

#define WriteClipText(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	WriteClipTextA(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_CLIPBOARD_H */
