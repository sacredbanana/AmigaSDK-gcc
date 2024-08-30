/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_BUGREPORT_H
#define _PPCINLINE_BUGREPORT_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef BUGREPORT_BASE_NAME
#define BUGREPORT_BASE_NAME BugReportBase
#endif /* !BUGREPORT_BASE_NAME */

#define SendBug(__p0, __p1) \
	(((void (*)(void *, STRPTR , struct TagItem *))*(void**)((long)(BUGREPORT_BASE_NAME) - 28))((void*)(BUGREPORT_BASE_NAME), __p0, __p1))

#define BPutStr(__p0) \
	(((void (*)(void *, STRPTR ))*(void**)((long)(BUGREPORT_BASE_NAME) - 40))((void*)(BUGREPORT_BASE_NAME), __p0))

#if !defined(__STRICT_ANSI__)
#define BPrintf(__p0, ...) \
	(((void (*)(void *, STRPTR , ...))*(void**)((long)(BUGREPORT_BASE_NAME) - 34))((void*)(BUGREPORT_BASE_NAME), __p0, __VA_ARGS__))
#endif

#define ClearBug() \
	(((void (*)(void *))*(void**)((long)(BUGREPORT_BASE_NAME) - 46))((void*)(BUGREPORT_BASE_NAME)))

#ifdef USE_INLINE_STDARG

#include <stdarg.h>

#define SendBugTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SendBug(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_BUGREPORT_H */
