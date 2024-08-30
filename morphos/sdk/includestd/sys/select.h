/*-
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 1992, 1993
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
 * 3. Neither the name of the University nor the names of its contributors
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
 * $FreeBSD$
 */

#ifndef _SYS_SELECT_DECL_H_
#define	_SYS_SELECT_DECL_H_

#include <sys/types.h>

#if !defined(_SYS_SELECT_H_NO_PROTOS)
#include <sys/cdefs.h>
#include <sys/signal.h>
#include <sys/time.h>
#endif

/*
 * Select uses bit masks of file descriptors in longs.  These macros
 * manipulate such bit fields (the filesystem macros use chars).
 * FD_SETSIZE may be defined by the user, but the default here should
 * be enough for most uses.
 */
#ifndef FD_SETSIZE
#define FD_SETSIZE	256
#endif

typedef int32_t fd_mask;
#define NFDBITS (sizeof(fd_mask) * NBBY)        /* bits per mask */

#ifndef howmany
#define howmany(x, y)	(((x) + ((y) - 1)) / (y))
#endif

typedef struct fd_set {
	fd_mask fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} fd_set;

#define FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1 << ((n) % NFDBITS)))
#define FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1 << ((n) % NFDBITS)))
#define FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1 << ((n) % NFDBITS)))
#define FD_COPY(f, t)	bcopy(f, t, sizeof(*(f)))
#define FD_ZERO(p)	bzero(p, sizeof(*(p)))

#endif /* _SYS_SELECT_DECL_H_ */

#if !defined(_SYS_SELECT_H_NO_PROTOS)
#ifndef _SYS_SELECT_PROTOS_H_
#define	_SYS_SELECT_PROTOS_H_

#include <sys/cdefs.h>

#ifndef PROTO_SOCKET_H
#include <proto/socket.h>
#endif

#ifndef _KERNEL
__BEGIN_DECLS
/*int pselect __P((int, fd_set *, fd_set *, fd_set *, const struct timespec *, const sigset_t *));*/
#ifndef _SELECT_DECLARED
#define	_SELECT_DECLARED
#define select _static_inline_select
static __inline int
select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exeptfds,
         struct timeval *timeout)
{
  /* call WaitSelect with NULL signal mask pointer */
  return WaitSelect(nfds, readfds, writefds, exeptfds, timeout, NULL);
}
#endif
__END_DECLS
#endif /* !_KERNEL */

#endif /* _SYS_SELECT_PROTOS_H_ */
#endif /* !_SYS_SELECT_H_NO_PROTOS */
