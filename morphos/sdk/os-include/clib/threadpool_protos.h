#ifndef CLIB_THREADPOOL_PROTOS_H
#define CLIB_THREADPOOL_PROTOS_H

/*
 * Copyright © 2012-2014 The MorphOS Development Team
 *
 */

#ifndef _SYS_TYPES_H_
#include <sys/types.h>
#endif

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef LIBRARIES_THREADPOOL_H
#include <libraries/threadpool.h>
#endif

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR CreateThreadPoolTagList(ULONG maxthreads, CONST struct TagItem *TagItems);
VOID DeleteThreadPool(APTR threadpool);
ssize_t QueueWorkItem(APTR threadpool, THREADFUNC entry, APTR userdata);
BOOL SendWorkItemMessage(APTR threadpool, ssize_t work_id, struct Message *message);
WORKITEMSTATUS AbortWorkItem(APTR threadpool, ssize_t work_id);
BOOL AbortWorkQueue(APTR threadpool);
WORKITEMSTATUS CheckWorkItem(APTR threadpool, ssize_t work_id);
BOOL CheckWorkQueue(APTR threadpool);
VOID WaitWorkItem(APTR threadpool, ssize_t work_id);
VOID WaitWorkQueue(APTR threadpool);
BOOL IsCurrentThread(APTR threadpool, ssize_t work_id);
WORKITEMSTATUS SignalWorkItem(APTR threadpool, ssize_t work_id, ULONG signalmask);
ssize_t GetCurrentWorkItem(APTR threadpool);

#if !defined(USE_INLINE_STDARG)
APTR CreateThreadPoolTags(ULONG maxthreads, Tag tag1Type, ... );
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_THREADPOOL_PROTOS_H */
