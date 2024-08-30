/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_THREADPOOL_H
#define _PPCINLINE_THREADPOOL_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef THREADPOOL_BASE_NAME
#define THREADPOOL_BASE_NAME ThreadPoolBase
#endif /* !THREADPOOL_BASE_NAME */

#define SendWorkItemMessage(__p0, __p1, __p2) \
	(((BOOL (*)(APTR , ssize_t , struct Message *, void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 46))(__p0, __p1, __p2, (void*)(THREADPOOL_BASE_NAME)))

#define DeleteThreadPool(__p0) \
	(((VOID (*)(APTR , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 34))(__p0, (void*)(THREADPOOL_BASE_NAME)))

#define CheckWorkItem(__p0, __p1) \
	(((WORKITEMSTATUS (*)(APTR , ssize_t , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 64))(__p0, __p1, (void*)(THREADPOOL_BASE_NAME)))

#define QueueWorkItem(__p0, __p1, __p2) \
	(((ssize_t (*)(APTR , THREADFUNC , APTR , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 40))(__p0, __p1, __p2, (void*)(THREADPOOL_BASE_NAME)))

#define IsCurrentThread(__p0, __p1) \
	(((BOOL (*)(APTR , ssize_t , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 88))(__p0, __p1, (void*)(THREADPOOL_BASE_NAME)))

#define GetCurrentWorkItem(__p0) \
	(((ssize_t (*)(APTR , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 100))(__p0, (void*)(THREADPOOL_BASE_NAME)))

#define AbortWorkQueue(__p0) \
	(((BOOL (*)(APTR , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 58))(__p0, (void*)(THREADPOOL_BASE_NAME)))

#define AbortWorkItem(__p0, __p1) \
	(((WORKITEMSTATUS (*)(APTR , ssize_t , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 52))(__p0, __p1, (void*)(THREADPOOL_BASE_NAME)))

#define CreateThreadPoolTagList(__p0, __p1) \
	(((APTR (*)(ULONG , CONST struct TagItem *, void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 28))(__p0, __p1, (void*)(THREADPOOL_BASE_NAME)))

#define CheckWorkQueue(__p0) \
	(((BOOL (*)(APTR , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 70))(__p0, (void*)(THREADPOOL_BASE_NAME)))

#define WaitWorkQueue(__p0) \
	(((VOID (*)(APTR , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 82))(__p0, (void*)(THREADPOOL_BASE_NAME)))

#define SignalWorkItem(__p0, __p1, __p2) \
	(((WORKITEMSTATUS (*)(APTR , ssize_t , ULONG , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 94))(__p0, __p1, __p2, (void*)(THREADPOOL_BASE_NAME)))

#define WaitWorkItem(__p0, __p1) \
	(((VOID (*)(APTR , ssize_t , void *))*(void**)((long)(THREADPOOL_BASE_NAME) - 76))(__p0, __p1, (void*)(THREADPOOL_BASE_NAME)))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define CreateThreadPoolTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CreateThreadPoolTagList(__p0, (CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_THREADPOOL_H */
