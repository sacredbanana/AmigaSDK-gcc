/*	$NetBSD: signal.h,v 1.7 1995/05/28 03:10:06 jtc Exp $	*/

/*-
 * Copyright (c) 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)signal.h	8.3 (Berkeley) 3/30/94
 */

#ifndef _USER_SIGNAL_H
#define _USER_SIGNAL_H

#include <sys/cdefs.h>
#include <sys/signal.h>

#if !defined(_ANSI_SOURCE)
#include <sys/types.h>
#endif

__BEGIN_DECLS
#if !defined(_ANSI_SOURCE) && !defined(_POSIX_SOURCE)
extern __const char *__const sys_signame[];
#ifdef _KERNEL
extern char *sys_siglist[];
#else
extern const char *const sys_siglist[];
#endif
#endif

int	raise __P((int));
#ifndef	_ANSI_SOURCE
int	kill __P((pid_t, int));
int	sigaction __P((int, const struct sigaction *, struct sigaction *));
int	sigaddset __P((sigset_t *, int));
int	sigdelset __P((sigset_t *, int));
int	sigemptyset __P((sigset_t *));
int	sigfillset __P((sigset_t *));
int	sigismember __P((const sigset_t *, int));
int	sigpending __P((sigset_t *));
int	sigprocmask __P((int, const sigset_t *, sigset_t *));
int	sigsuspend __P((const sigset_t *));

int     sigaddset __P((sigset_t *set, int signo));
int     sigdelset __P((sigset_t *set, int signo));
int     sigismember __P((const sigset_t *set, int signo));
int     sigemptyset __P((sigset_t *mask));
int     sigfillset __P((sigset_t *mask));

#ifndef _POSIX_SOURCE
int	killpg __P((pid_t, int));
int	sigblock __P((int));
int	siginterrupt __P((int, int));
int	sigpause __P((int));
void	sigreturn __P((struct sigcontext *));
int	sigsetmask __P((int));
int	sigstack __P((const struct sigstack *, struct sigstack *));
int	sigvec __P((int, struct sigvec *, struct sigvec *));
//void	psignal __P((unsigned int, const char *));
#endif	/* !_POSIX_SOURCE */
#endif	/* !_ANSI_SOURCE */
__END_DECLS

#endif	/* !_USER_SIGNAL_H */
