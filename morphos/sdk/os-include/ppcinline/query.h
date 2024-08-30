/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_QUERY_H
#define _PPCINLINE_QUERY_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef QUERY_BASE_NAME
#define QUERY_BASE_NAME QueryBase
#endif /* !QUERY_BASE_NAME */

#define QueryGetAttr(__p0, __p1, __p2) \
	(((ULONG (*)(void *, void *, APTR , ULONG ))*(void**)((long)(QUERY_BASE_NAME) - 52))((void*)(QUERY_BASE_NAME), __p0, __p1, __p2))

#define QueryGetDeviceAttr(__p0, __p1, __p2) \
	(((ULONG (*)(void *, struct Device *, APTR , ULONG ))*(void**)((long)(QUERY_BASE_NAME) - 64))((void*)(QUERY_BASE_NAME), __p0, __p1, __p2))

#define QueryGetFileSysEntryAttr(__p0, __p1, __p2) \
	(((ULONG (*)(void *, struct FileSysEntry *, APTR , ULONG ))*(void**)((long)(QUERY_BASE_NAME) - 76))((void*)(QUERY_BASE_NAME), __p0, __p1, __p2))

#define QueryGetLibraryAttr(__p0, __p1, __p2) \
	(((ULONG (*)(void *, struct Library *, APTR , ULONG ))*(void**)((long)(QUERY_BASE_NAME) - 58))((void*)(QUERY_BASE_NAME), __p0, __p1, __p2))

#define QueryRelease(__p0) \
	(((void (*)(void *, void *))*(void**)((long)(QUERY_BASE_NAME) - 46))((void*)(QUERY_BASE_NAME), __p0))

#define QueryObtainTagList(__p0, __p1) \
	(((void *(*)(void *, void *, struct TagItem *))*(void**)((long)(QUERY_BASE_NAME) - 40))((void*)(QUERY_BASE_NAME), __p0, __p1))

#define QueryDeletePathNode(__p0) \
	(((void *(*)(void *, void *))*(void**)((long)(QUERY_BASE_NAME) - 34))((void*)(QUERY_BASE_NAME), __p0))

#define QueryCreatePathNode(__p0, __p1, __p2) \
	(((void *(*)(void *, char *, char *, ULONG ))*(void**)((long)(QUERY_BASE_NAME) - 28))((void*)(QUERY_BASE_NAME), __p0, __p1, __p2))

#define QueryGetResidentAttr(__p0, __p1, __p2) \
	(((ULONG (*)(void *, struct Resident *, APTR , ULONG ))*(void**)((long)(QUERY_BASE_NAME) - 70))((void*)(QUERY_BASE_NAME), __p0, __p1, __p2))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define QueryObtainTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	QueryObtainTagList(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_QUERY_H */
