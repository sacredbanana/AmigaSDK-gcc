/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_CHARSETS_H
#define _PPCINLINE_CHARSETS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef CHARSETS_BASE_NAME
#define CHARSETS_BASE_NAME CharsetsBase
#endif /* !CHARSETS_BASE_NAME */

#define GetSystemCharset(__p0, __p1) \
	(((LONG (*)(STRPTR , ULONG , void *))*(void**)((long)(CHARSETS_BASE_NAME) - 52))(__p0, __p1, (void*)(CHARSETS_BASE_NAME)))

#define ConvertTagList(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((LONG (*)(void *, APTR , LONG , APTR , LONG , ULONG , ULONG , CONST struct TagItem *))*(void**)((long)(CHARSETS_BASE_NAME) - 82))((void*)(CHARSETS_BASE_NAME), __p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GetUTF16BE(__p0, __p1) \
	(((WCHAR (*)(UTF16 *, ULONG ))*(void**)((long)(CHARSETS_BASE_NAME) - 58))(__p0, __p1))


#define GetByteSize(__p0, __p1, __p2, __p3) \
	(((LONG (*)(APTR , LONG , ULONG , ULONG , void *))*(void**)((long)(CHARSETS_BASE_NAME) - 76))(__p0, __p1, __p2, __p3, (void*)(CHARSETS_BASE_NAME)))

#define GetUTF16LE(__p0, __p1) \
	(((WCHAR (*)(UTF16 *, ULONG ))*(void**)((long)(CHARSETS_BASE_NAME) - 64))(__p0, __p1))


#define GetCharsetName(__p0, __p1, __p2) \
	(((CONST_STRPTR (*)(ULONG , CONST_STRPTR *, CONST CONST_STRPTR **, void *))*(void**)((long)(CHARSETS_BASE_NAME) - 28))(__p0, __p1, __p2, (void*)(CHARSETS_BASE_NAME)))

#define GetLength(__p0, __p1, __p2) \
	(((LONG (*)(APTR , LONG , ULONG , void *))*(void**)((long)(CHARSETS_BASE_NAME) - 70))(__p0, __p1, __p2, (void*)(CHARSETS_BASE_NAME)))

#define GetCharsetNumber(__p0, __p1) \
	(((ULONG (*)(CONST_STRPTR , ULONG , void *))*(void**)((long)(CHARSETS_BASE_NAME) - 34))(__p0, __p1, (void*)(CHARSETS_BASE_NAME)))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define ConvertTags(__p0, __p1, __p2, __p3, __p4, __p5, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ConvertTagList(__p0, __p1, __p2, __p3, __p4, __p5, (CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_CHARSETS_H */
