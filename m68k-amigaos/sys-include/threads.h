/*-
 * Copyright (c) 2011 Ed Schouten <ed@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef _THREADS_H_
#define	_THREADS_H_

#include <machine/_threads.h>
#include <time.h>

typedef void (*tss_dtor_t)(void *);
typedef int (*thrd_start_t)(void *);

enum {
	mtx_plain = 0x1,
	mtx_recursive = 0x2,
	mtx_timed = 0x4
};

enum {
	thrd_busy = 1,
	thrd_error = 2,
	thrd_nomem = 3,
	thrd_success = 4,
	thrd_timedout = 5
};

#if !defined(__cplusplus) || __cplusplus < 201103L
#define	thread_local		_Thread_local
#endif

__BEGIN_DECLS
__stdargs void	call_once(once_flag *, void (*)(void));
__stdargs int	cnd_broadcast(cnd_t *);
__stdargs void	cnd_destroy(cnd_t *);
__stdargs int	cnd_init(cnd_t *);
__stdargs int	cnd_signal(cnd_t *);
__stdargs int	cnd_timedwait(cnd_t *__restrict, mtx_t *__restrict __mtx,
    const struct timespec *__restrict)
    __requires_exclusive(*__mtx);
__stdargs int	cnd_wait(cnd_t *, mtx_t *__mtx)
    __requires_exclusive(*__mtx);
__stdargs void	mtx_destroy(mtx_t *__mtx)
    __requires_unlocked(*__mtx);
__stdargs int	mtx_init(mtx_t *__mtx, int)
    __requires_unlocked(*__mtx);
__stdargs int	mtx_lock(mtx_t *__mtx)
    __locks_exclusive(*__mtx);
__stdargs int	mtx_timedlock(mtx_t *__restrict __mtx,
    const struct timespec *__restrict)
    __trylocks_exclusive(thrd_success, *__mtx);
__stdargs int	mtx_trylock(mtx_t *__mtx)
    __trylocks_exclusive(thrd_success, *__mtx);
__stdargs int	mtx_unlock(mtx_t *__mtx)
    __unlocks(*__mtx);
__stdargs int	thrd_create(thrd_t *, thrd_start_t, void *);
__stdargs thrd_t	thrd_current(void);
__stdargs int	thrd_detach(thrd_t);
__stdargs int	thrd_equal(thrd_t, thrd_t);
_Noreturn void
	thrd_exit(int);
__stdargs int	thrd_join(thrd_t, int *);
__stdargs int	thrd_sleep(const struct timespec *, struct timespec *);
__stdargs void	thrd_yield(void);
__stdargs int	tss_create(tss_t *, tss_dtor_t);
__stdargs void	tss_delete(tss_t);
void *	tss_get(tss_t);
__stdargs int	tss_set(tss_t, void *);
__END_DECLS

#endif /* !_THREADS_H_ */
