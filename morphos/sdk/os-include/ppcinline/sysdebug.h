/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_SYSDEBUG_H
#define _PPCINLINE_SYSDEBUG_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef SYSDEBUG_BASE_NAME
#define SYSDEBUG_BASE_NAME SysDebugBase
#endif /* !SYSDEBUG_BASE_NAME */



#define SysDebugFindSeg(__p0, __p1, __p2) \
	(((STRPTR (*)(void *, ULONG , ULONG *, ULONG *))*(void**)((long)(SYSDEBUG_BASE_NAME) - 40))((void*)(SYSDEBUG_BASE_NAME), __p0, __p1, __p2))

#define SysDebugFindSegTagList(__p0) \
	(((LONG (*)(void *, struct TagItem *))*(void**)((long)(SYSDEBUG_BASE_NAME) - 46))((void*)(SYSDEBUG_BASE_NAME), __p0))

#define SysDebugFreeArray(__p0) \
	(((void (*)(void *, APTR ))*(void**)((long)(SYSDEBUG_BASE_NAME) - 52))((void*)(SYSDEBUG_BASE_NAME), __p0))

#define SysDebugLock() \
	(((void (*)(void *))*(void**)((long)(SYSDEBUG_BASE_NAME) - 58))((void*)(SYSDEBUG_BASE_NAME)))

#define SysDebugUnLock() \
	(((void (*)(void *))*(void**)((long)(SYSDEBUG_BASE_NAME) - 64))((void*)(SYSDEBUG_BASE_NAME)))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define SysDebugFindSegTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SysDebugFindSegTagList((struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_SYSDEBUG_H */
