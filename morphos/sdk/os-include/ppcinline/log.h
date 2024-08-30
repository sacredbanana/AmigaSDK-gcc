/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_LOG_H
#define _PPCINLINE_LOG_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef LOG_BASE_NAME
#define LOG_BASE_NAME LogBase
#endif /* !LOG_BASE_NAME */

#define LogVPrintf(__p0, __p1, __p2) \
	(((void (*)(void *, char *, char *, va_list ))*(void**)((long)(LOG_BASE_NAME) - 34))((void*)(LOG_BASE_NAME), __p0, __p1, __p2))

#define LogShowWindow() \
	(((void (*)(void *))*(void**)((long)(LOG_BASE_NAME) - 46))((void*)(LOG_BASE_NAME)))

#define LogHideWindow() \
	(((void (*)(void *))*(void**)((long)(LOG_BASE_NAME) - 52))((void*)(LOG_BASE_NAME)))

#define LogAddNotify(__p0) \
	(((ULONG (*)(void *, struct MsgPort *))*(void**)((long)(LOG_BASE_NAME) - 58))((void*)(LOG_BASE_NAME), __p0))

#if !defined(__STRICT_ANSI__)
#define LogPrintf(__p0, ...) \
	(((void (*)(void *, char *, char *, ...))*(void**)((long)(LOG_BASE_NAME) - 40))((void*)(LOG_BASE_NAME), __p0, __VA_ARGS__))
#endif

#define LogRemNotify(__p0) \
	(((ULONG (*)(void *, struct MsgPort *))*(void**)((long)(LOG_BASE_NAME) - 64))((void*)(LOG_BASE_NAME), __p0))


#endif /* !_PPCINLINE_LOG_H */
