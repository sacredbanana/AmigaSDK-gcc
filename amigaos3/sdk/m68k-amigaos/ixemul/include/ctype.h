/*	$NetBSD: ctype.h,v 1.14 1994/10/26 00:55:47 cgd Exp $	*/

/*
 * Copyright (c) 1989 The Regents of the University of California.
 * All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
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
 *	@(#)ctype.h	5.3 (Berkeley) 4/3/91
 */

#ifndef _CTYPE_H_
#define _CTYPE_H_
#include <sys/cdefs.h>

#define	_U	0x01
#define	_L	0x02
#define	_N	0x04
#define	_S	0x08
#define	_P	0x10
#define	_C	0x20
#define	_X	0x40
#define	_B	0x80

#ifdef _KERNEL
extern const char _ctype_[];
#else
extern const char	*_ctype_;
#endif

__BEGIN_DECLS
extern int	isalnum __P ((int));
extern int	isalpha __P ((int));
extern int	iscntrl __P ((int));
extern int	isdigit __P ((int));
extern int	isgraph __P ((int));
extern int	islower __P ((int));
extern int	isprint __P ((int));
extern int	ispunct __P ((int));
extern int	isspace __P ((int));
extern int	isupper __P ((int));
extern int	isxdigit __P ((int));
extern int	tolower __P ((int));
extern int	toupper __P ((int));

#if !defined(_ANSI_SOURCE) && !defined(_POSIX_SOURCE)
extern int	isblank __P ((int));
extern int	isascii __P ((int));
extern int	toascii __P ((int));
extern int	_tolower __P ((int));
extern int	_toupper __P ((int));
#endif
__END_DECLS

#define	isdigit(c)	((_ctype_ + 1)[(unsigned char)c] & _N)
#define	islower(c)	((_ctype_ + 1)[(unsigned char)c] & _L)
#define	isspace(c)	((_ctype_ + 1)[(unsigned char)c] & _S)
#define	ispunct(c)	((_ctype_ + 1)[(unsigned char)c] & _P)
#define	isupper(c)	((_ctype_ + 1)[(unsigned char)c] & _U)
#define	isalpha(c)	((_ctype_ + 1)[(unsigned char)c] & (_U|_L))
#define	isxdigit(c)	((_ctype_ + 1)[(unsigned char)c] & (_N|_X))
#define	isalnum(c)	((_ctype_ + 1)[(unsigned char)c] & (_U|_L|_N))
#define	isprint(c)	((_ctype_ + 1)[(unsigned char)c] & (_P|_U|_L|_N|_B))
#define	isgraph(c)	((_ctype_ + 1)[(unsigned char)c] & (_P|_U|_L|_N))
#define	iscntrl(c)	((_ctype_ + 1)[(unsigned char)c] & _C)
#if (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#define	toupper(c)	( { int _c = (c); islower(_c) ? _c - 'a' + 'A' : _c; } )
#define	tolower(c)	( { int _c = (c); isupper(_c) ? _c - 'A' + 'a' : _c; } )
#endif

#if !defined(_ANSI_SOURCE) && !defined (_POSIX_SOURCE)
#if notyet
#define isblank(c)	((_ctype_ + 1)[(unsigned char)c] & _B)
#endif
#define	isascii(c)	(((c) & ~0177) == 0)
#define	toascii(c)	((c) & 0177)
#define isiso(c)	(((c) & ~0377) == 0)
#define toiso(c)	((c) & 0377)
#define _tolower(c)	((c) - 'A' + 'a')
#define _toupper(c)	((c) - 'a' + 'A')
#endif

#endif /* !_CTYPE_H_ */
