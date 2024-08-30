/* Threads compatibility routines for libgcc2 and libobjc.  */
/* Compile this one with gcc.  */
/* Copyright (C) 1997-2018 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#ifndef _GLIBCXX_GCC_GTHR_AMIGAOS_H
#define _GLIBCXX_GCC_GTHR_AMIGAOS_H

#include <stdlib.h>
#include <stdint.h>

typedef struct { int data1, data2; } __gthread_once_t;

typedef struct { long unsigned int id; } __gthread_key_t;

/* Should cover at least as much data as the maximum of sizeof(struct SignalSemaphore)
 * and sizeof(pthread_mutex_t)
 */
typedef struct { char data[48]; } __gthread_mutex_t;
typedef struct { char data[48]; } __gthread_recursive_mutex_t;

typedef struct { char data[8]; } __gthread_cond_t;

typedef int __gthread_t;
typedef struct { int seconds; long nanoseconds;} __gthread_time_t;

#define __GTHREADS 1
#define __GTHREADS_CXX0X 1

#define __GTHREAD_ONCE_INIT {0,0}
//#define __GTHREAD_MUTEX_INIT 0
#define __GTHREAD_MUTEX_INIT_FUNCTION(mx) __gthread_mutex_init(mx)
//#define __GTHREAD_RECURSIVE_MUTEX_INIT 0
#define __GTHREAD_RECURSIVE_MUTEX_INIT_FUNCTION(mx) __gthread_recursive_mutex_init(mx)

//#define __GTHREAD_COND_INIT 0
#define __GTHREAD_COND_INIT_FUNCTION(cond) __gthread_cond_init(cond)

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef _LIBOBJC

#ifndef _GLIBCXX_UNUSED
#define _GLIBCXX_UNUSED __attribute__((__unused__))
#define _GLIBCXX_UNUSED_DEFINED
#endif

/* Thread local storage for a single thread */
static void *thread_local_storage = NULL;

/* Backend initialization functions */

/* Initialize the threads subsystem.  */
static inline int
__gthread_objc_init_thread_system (void)
{
  /* No thread support available */
  return -1;
}

/* Close the threads subsystem.  */
static inline int
__gthread_objc_close_thread_system (void)
{
  /* No thread support available */
  return -1;
}

/* Backend thread functions */

/* Create a new thread of execution.  */
static inline objc_thread_t
__gthread_objc_thread_detach (void (* func)(void *), void * arg _GLIBCXX_UNUSED)
{
  /* No thread support available */
  return NULL;
}

/* Set the current thread's priority.  */
static inline int
__gthread_objc_thread_set_priority (int priority _GLIBCXX_UNUSED)
{
  /* No thread support available */
  return -1;
}

/* Return the current thread's priority.  */
static inline int
__gthread_objc_thread_get_priority (void)
{
  return OBJC_THREAD_INTERACTIVE_PRIORITY;
}

/* Yield our process time to another thread.  */
static inline void
__gthread_objc_thread_yield (void)
{
  return;
}

/* Terminate the current thread.  */
static inline int
__gthread_objc_thread_exit (void)
{
  /* No thread support available */
  /* Should we really exit the program */
  /* exit (&__objc_thread_exit_status); */
  return -1;
}

/* Returns an integer value which uniquely describes a thread.  */
static inline objc_thread_t
__gthread_objc_thread_id (void)
{
  /* No thread support, use 1.  */
  return (objc_thread_t) 1;
}

/* Sets the thread's local storage pointer.  */
static inline int
__gthread_objc_thread_set_data (void *value)
{
  thread_local_storage = value;
  return 0;
}

/* Returns the thread's local storage pointer.  */
static inline void *
__gthread_objc_thread_get_data (void)
{
  return thread_local_storage;
}

/* Backend mutex functions */

/* Allocate a mutex.  */
static inline int
__gthread_objc_mutex_allocate (objc_mutex_t mutex _GLIBCXX_UNUSED)
{
  return 0;
}

/* Deallocate a mutex.  */
static inline int
__gthread_objc_mutex_deallocate (objc_mutex_t mutex _GLIBCXX_UNUSED)
{
  return 0;
}

/* Grab a lock on a mutex.  */
static inline int
__gthread_objc_mutex_lock (objc_mutex_t mutex _GLIBCXX_UNUSED)
{
  /* There can only be one thread, so we always get the lock */
  return 0;
}

/* Try to grab a lock on a mutex.  */
static inline int
__gthread_objc_mutex_trylock (objc_mutex_t mutex _GLIBCXX_UNUSED)
{
  /* There can only be one thread, so we always get the lock */
  return 0;
}

/* Unlock the mutex */
static inline int
__gthread_objc_mutex_unlock (objc_mutex_t mutex _GLIBCXX_UNUSED)
{
  return 0;
}

/* Backend condition mutex functions */

/* Allocate a condition.  */
static inline int
__gthread_objc_condition_allocate (objc_condition_t condition _GLIBCXX_UNUSED)
{
  return 0;
}

/* Deallocate a condition.  */
static inline int
__gthread_objc_condition_deallocate (objc_condition_t condition _GLIBCXX_UNUSED)
{
  return 0;
}

/* Wait on the condition */
static inline int
__gthread_objc_condition_wait (objc_condition_t condition _GLIBCXX_UNUSED,
			       objc_mutex_t mutex _GLIBCXX_UNUSED)
{
  return 0;
}

/* Wake up all threads waiting on this condition.  */
static inline int
__gthread_objc_condition_broadcast (objc_condition_t condition _GLIBCXX_UNUSED)
{
  return 0;
}

/* Wake up one thread waiting on this condition.  */
static inline int
__gthread_objc_condition_signal (objc_condition_t condition _GLIBCXX_UNUSED)
{
  return 0;
}

#ifndef _GLIBCXX_UNUSED_DEFINED
#undef _GLIBCXX_UNUSED
#endif

#else /* _LIBOBJC */

int
__gthread_active_p (void);

int
__gthread_once (__gthread_once_t *__once, void (*__func) (void));

int
__gthread_key_create (__gthread_key_t *__key, void (*destroy) (void *));

int
__gthread_key_delete (__gthread_key_t __key);

void *
__gthread_getspecific (__gthread_key_t __key);

int
__gthread_setspecific (__gthread_key_t __key, const void *__v);

int
__gthread_mutex_init (__gthread_mutex_t *__mutex);

int
__gthread_mutex_destroy (__gthread_mutex_t *__mutex);

int
__gthread_mutex_lock (__gthread_mutex_t *__mutex);

int
__gthread_mutex_trylock (__gthread_mutex_t *__mutex);

int
__gthread_mutex_unlock (__gthread_mutex_t *__mutex);

int
__gthread_recursive_mutex_init (__gthread_recursive_mutex_t *__mutex);

int
__gthread_recursive_mutex_lock (__gthread_recursive_mutex_t *__mutex);

int
__gthread_recursive_mutex_trylock (__gthread_recursive_mutex_t *__mutex);

int
__gthread_recursive_mutex_unlock (__gthread_recursive_mutex_t *__mutex);

int
__gthread_recursive_mutex_destroy (__gthread_recursive_mutex_t *__mutex);

/******************************************************************************/

int
__gthread_cond_init (__gthread_cond_t *cond);

int
__gthread_cond_signal (__gthread_cond_t *__cond);

int
__gthread_cond_broadcast (__gthread_cond_t *cond);

int
__gthread_cond_wait (__gthread_cond_t *cond, __gthread_mutex_t *mutex);

int
__gthread_cond_wait_recursive (__gthread_cond_t *cond,
                               __gthread_recursive_mutex_t *mutex);

int
__gthread_cond_timedwait (__gthread_cond_t *cond,
                            __gthread_mutex_t *mutex,
                            const __gthread_time_t *abs_timeout);

int
__gthread_cond_destroy (__gthread_cond_t *__cond);

/******************************************************************************/

int
__gthread_create (__gthread_t *thread, void *(*func) (void*), void *args);

int
__gthread_join (__gthread_t thread, void **value_ptr);

int
__gthread_detach (__gthread_t thread);

int
__gthread_equal (__gthread_t t1, __gthread_t t2);

__gthread_t
__gthread_self (void);

int
__gthread_yield (void);

int
__gthread_mutex_timedlock (__gthread_mutex_t *m, const __gthread_time_t *abs_timeout);

int
__gthread_recursive_mutex_timedlock (__gthread_recursive_mutex_t *m,
                                    const __gthread_time_t *abs_time);

#endif /* _LIBOBJC */

#ifdef __cplusplus
}
#endif

#endif /* ! _GLIBCXX_GCC_GTHR_AMIGAOS_H */
