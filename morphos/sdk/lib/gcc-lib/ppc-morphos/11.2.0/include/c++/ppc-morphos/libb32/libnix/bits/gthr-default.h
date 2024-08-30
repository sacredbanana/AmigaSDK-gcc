/* Threads compatibility routines for libgcc2.  */
/* Compile this one with gcc.  */
/* Copyright (C) 1997, 1999, 2000, 2004, 2008, 2009
   Free Software Foundation, Inc.
   Copyright (C) 2016-2020 Harry Sintonen

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

#ifndef _GLIBCXX_GCC_GTHR_MORPHOS_H
#define _GLIBCXX_GCC_GTHR_MORPHOS_H

#define __GTHREADS 1
#define __GTHREADS_CXX0X 1
#define __GTHREAD_HAS_COND 1

#include <sys/time.h>
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * __gthr_morphos_active_p
 */

extern int __gthr_morphos_active_p (void);
static int __is_gthr_morphos_active = -1;

static inline int
__gthread_active_p (void)
{
  if(__is_gthr_morphos_active < 0)
    __is_gthr_morphos_active = __gthr_morphos_active_p();

  return __is_gthr_morphos_active > 0 ? 1 : 0;
}

/*
 * MorphOS - Generic
 */

typedef struct timespec __gthread_time_t;
#define __GTHREAD_TIME_INIT { 0, 0 }

/*
 * MorphOS - Once
 */

#define __GTHREAD_ONCE_INIT { 0, 0 }

typedef struct {
	volatile long busy;
	volatile long done;
} __gthread_once_t;

extern int __gthr_morphos_once (__gthread_once_t *__once, void (*__func) (void));
extern void __gthr_morphos_once_unlock (__gthread_once_t *__once);

/*
 * MorphOS - Key
 */

typedef unsigned long __gthread_key_t;

extern int __gthr_morphos_key_create (__gthread_key_t *__key, void (*__func) (void *));
extern int __gthr_morphos_key_delete (__gthread_key_t __key);
extern void *__gthr_morphos_getspecific (__gthread_key_t __key);
extern int __gthr_morphos_setspecific (__gthread_key_t __key, const void *__v);

/*
 * MorphOS - Mutex
 */

#ifdef _GTHREAD_USE_MUTEX_INIT_FUNC
# define __GTHREAD_MUTEX_INIT_FUNCTION           __gthread_mutex_init_function
#else
# define __GTHREAD_MUTEX_INIT                    { {{ 0 }}, 0 }
#endif
#ifdef _GTHREAD_USE_RECURSIVE_MUTEX_INIT_FUNC
# define __GTHREAD_RECURSIVE_MUTEX_INIT_FUNCTION __gthread_recursive_mutex_init_function
#else
# define __GTHREAD_RECURSIVE_MUTEX_INIT          { {{ 0 }}, 0 }
#endif

typedef struct {
	union {
		char _priv[60];
	} u;
	int incond;
} __gthread_mutex_t;

typedef __gthread_mutex_t __gthread_recursive_mutex_t;

extern void __gthr_morphos_mutex_init_function (__gthread_mutex_t *__mutex);
extern int __gthr_morphos_mutex_destroy (__gthread_mutex_t *__mutex);

extern int __gthr_morphos_mutex_lock (__gthread_mutex_t *__mutex);
extern int __gthr_morphos_mutex_trylock (__gthread_mutex_t *__mutex);
extern int __gthr_morphos_mutex_unlock (__gthread_mutex_t *__mutex);
extern int __gthr_morphos_mutex_timedlock (__gthread_mutex_t *__mutex,
                                           const __gthread_time_t *__abs_timeout);

extern void __gthr_morphos_recursive_mutex_init_function (__gthread_recursive_mutex_t *__mutex);
extern int __gthr_morphos_recursive_mutex_lock (__gthread_recursive_mutex_t *__mutex);
extern int __gthr_morphos_recursive_mutex_trylock (__gthread_recursive_mutex_t *__mutex);
extern int __gthr_morphos_recursive_mutex_unlock (__gthread_recursive_mutex_t *__mutex);
extern int __gthr_morphos_recursive_mutex_destroy (__gthread_mutex_t *__mutex);
extern int __gthr_morphos_recursive_mutex_timedlock (__gthread_mutex_t *__mutex,
                                                     const __gthread_time_t *__abs_timeout);

/*
 * MorphOS - Cond
 */

#ifdef _GTHREAD_USE_COND_INIT_FUNC
# define __GTHREAD_COND_INIT_FUNCTION __gthread_cond_init_function
#else
# define __GTHREAD_COND_INIT          { {{ 0 }}, {{ 0 }} }
#endif

typedef struct {
	union {
		char _priv[60];
	} u1;
	union {
		void *_priv[3];
	} u2;
} __gthread_cond_t;

extern void __gthr_morphos_cond_init_function (__gthread_cond_t *__cond);
extern int __gthr_morphos_cond_destroy (__gthread_cond_t *__cond);
extern int __gthr_morphos_cond_broadcast (__gthread_cond_t *__cond);
extern int __gthr_morphos_cond_signal (__gthread_cond_t *__cond);
extern int __gthr_morphos_cond_wait (__gthread_cond_t *__cond, __gthread_mutex_t *__mutex);
extern int __gthr_morphos_cond_wait_recursive (__gthread_cond_t *__cond,
                                               __gthread_recursive_mutex_t *__mutex);
extern int __gthr_morphos_cond_timedwait (__gthread_cond_t *__cond,
                                          __gthread_mutex_t *__mutex,
                                          const __gthread_time_t *__abs_timeout);

/*
 * MorphOS - Thread
 */

typedef unsigned int __gthread_t;

extern int __gthr_morphos_create (__gthread_t *__threadid, void *(*__func) (void *),
                                  void *__args);
extern int __gthr_morphos_join (__gthread_t __threadid, void **__value_ptr);
extern int __gthr_morphos_detach (__gthread_t __threadid);
extern int __gthr_morphos_equal (__gthread_t __t1, __gthread_t __t2);
extern __gthread_t __gthr_morphos_self (void);
extern int __gthr_morphos_yield (void);


/*
 * MorphOS - Once
 */

static inline int
__gthread_once (__gthread_once_t *__once, void (*__func) (void))
{
  if (__gthread_active_p ())
    return __gthr_morphos_once (__once, __func);
  else
    return -1;
}

static inline void
__gthread_once_unlock (__gthread_once_t *__once)
{
  __gthr_morphos_once_unlock (__once);
}

/*
 * MorphOS - Key
 */

static inline int
__gthread_key_create (__gthread_key_t *__key, void (*__dtor) (void *))
{
  return __gthr_morphos_key_create (__key, __dtor);
}

static inline int
__gthread_key_delete (__gthread_key_t __key)
{
  return __gthr_morphos_key_delete (__key);
}

static inline void *
__gthread_getspecific (__gthread_key_t __key)
{
  return __gthr_morphos_getspecific (__key);
}

static inline int
__gthread_setspecific (__gthread_key_t __key, const void *__ptr)
{
  return __gthr_morphos_setspecific (__key, __ptr);
}

/*
 * MorphOS - Mutex
 */

static inline void
__gthread_mutex_init_function (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    __gthr_morphos_mutex_init_function (__mutex);
}

static inline int
__gthread_mutex_destroy (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthr_morphos_mutex_destroy (__mutex);
  else
    return 0;
}

static inline int
__gthread_mutex_lock (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthr_morphos_mutex_lock (__mutex);
  else
    return 0;
}

static inline int
__gthread_mutex_trylock (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthr_morphos_mutex_trylock (__mutex);
  else
    return 0;
}

static inline int
__gthread_mutex_timedlock (__gthread_mutex_t *__mutex,
                           const __gthread_time_t *__abs_timeout)
{
  if (__gthread_active_p ())
    return __gthr_morphos_mutex_timedlock (__mutex, __abs_timeout);
  else
    return 0;
}

static inline int
__gthread_mutex_unlock (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthr_morphos_mutex_unlock (__mutex);
  else
    return 0;
}

static inline void
__gthread_recursive_mutex_init_function (__gthread_recursive_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    __gthr_morphos_recursive_mutex_init_function (__mutex);
}

static inline int
__gthread_recursive_mutex_lock (__gthread_recursive_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthr_morphos_recursive_mutex_lock (__mutex);
  else
    return 0;
}

static inline int
__gthread_recursive_mutex_trylock (__gthread_recursive_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthr_morphos_recursive_mutex_trylock (__mutex);
  else
    return 0;
}

static inline int
__gthread_recursive_mutex_timedlock (__gthread_recursive_mutex_t *__mutex,
                                     const __gthread_time_t *__abs_timeout)
{
  if (__gthread_active_p ())
    return __gthr_morphos_recursive_mutex_timedlock (__mutex, __abs_timeout);
  else
    return 0;
}

static inline int
__gthread_recursive_mutex_unlock (__gthread_recursive_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthr_morphos_recursive_mutex_unlock (__mutex);
  else
    return 0;
}

static inline int
__gthread_recursive_mutex_destroy (__gthread_mutex_t *__mutex)
{
  if (__gthread_active_p ())
    return __gthr_morphos_mutex_destroy (__mutex);
  else
    return 0;
}

/*
 * MorphOS - Cond
 */

static inline void
__gtrhread_cond_init_function (__gthread_cond_t *__cond)
{
  if (__gthread_active_p ())
    __gthr_morphos_cond_init_function (__cond);
}

static inline int
__gthread_cond_destroy (__gthread_cond_t *__cond)
{
  if (__gthread_active_p ())
    return __gthr_morphos_cond_destroy (__cond);
  else
    return 0;
}

static inline int
__gthread_cond_broadcast (__gthread_cond_t *__cond)
{
  return __gthr_morphos_cond_broadcast (__cond);
}

static inline int
__gthread_cond_signal (__gthread_cond_t *__cond)
{
  return __gthr_morphos_cond_signal (__cond);
}

static inline int
__gthread_cond_wait (__gthread_cond_t *__cond, __gthread_mutex_t *__mutex)
{
  return __gthr_morphos_cond_wait (__cond, __mutex);
}

static inline int
__gthread_cond_wait_recursive (__gthread_cond_t *__cond,
                               __gthread_recursive_mutex_t *__mutex)
{
  return __gthr_morphos_cond_wait_recursive (__cond, __mutex);
}

static inline int
__gthread_cond_timedwait (__gthread_cond_t *__cond, __gthread_mutex_t *__mutex,
                          const __gthread_time_t *__abs_timeout)
{
  return __gthr_morphos_cond_timedwait (__cond, __mutex, __abs_timeout);
}

/*
 * MorphOS - Thread
 */

static inline int
__gthread_create (__gthread_t *__threadid, void *(*__func) (void *),
                  void *__args)
{
  if (__gthread_active_p ())
    return __gthr_morphos_create (__threadid, __func, __args);
  else
    return 0;
}

static inline int
__gthread_join (__gthread_t __threadid, void **__value_ptr)
{
  return __gthr_morphos_join (__threadid, __value_ptr);
}

static inline int
__gthread_detach (__gthread_t __threadid)
{
  return __gthr_morphos_detach (__threadid);
}

static inline int
__gthread_equal (__gthread_t __t1, __gthread_t __t2)
{
  return __gthr_morphos_equal (__t1, __t2);
}

static inline __gthread_t
__gthread_self (void)
{
  return __gthr_morphos_self ();
}

static inline int
__gthread_yield (void)
{
  return __gthr_morphos_yield ();
}

#ifdef __cplusplus
}
#endif

#endif /* ! _GLIBCXX_GCC_GTHR_MORPHOS_H */
