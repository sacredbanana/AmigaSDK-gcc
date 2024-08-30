/*      $NetBSD: cdefs.h,v 1.15 1995/01/19 01:54:52 jtc Exp $   */

/*
 * Copyright (c) 1991, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Berkeley Software Design, Inc.
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
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
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
 *      @(#)cdefs.h     8.7 (Berkeley) 1/21/94
 */

#ifndef _SYS_CDEFS_H_
#define _SYS_CDEFS_H_

#include <machine/cdefs.h>

#if defined(__cplusplus)
#define __BEGIN_DECLS   extern "C" {
#define __END_DECLS     };
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif

/*
 * Macros to test the versions of gcc.
 */
#if defined __GNUC__ && !defined __GNUC_PREREQ
#define __GNUC_PREREQ(maj, min) ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#else
# define __GNUC_PREREQ(maj, min) 0
#endif

#if defined __GNUC_PREREQ && !defined __GNUC_PREREQ__
#define __GNUC_PREREQ__ __GNUC_PREREQ
#endif

/*
 * __LEAF, __THROW et all
 */
#ifdef __GNUC__
#if __GNUC_PREREQ(4,6) && !defined(_LIBC)
#define __LEAF , __leaf__
#define __LEAF_ATTR __attribute__ ((__leaf__))
#else
#define __LEAF
#define __LEAF_ATTR
#endif /* __GNUC_PREREQ(4,6) && !defined(_LIBC) */
#if !defined(__cplusplus) && __GNUC_PREREQ(3,3)
#define __THROW __attribute__ ((__nothrow__ __LEAF))
#define __THROWNL __attribute__ ((__nothrow__))
#define __NTH(f) __attribute__ ((__nothrow__ __LEAF)) f
#define __NTHNL(f) __attribute__ ((__nothrow__)) f
#else
#if defined(__cplusplus) && __GNUC_PREREQ(2,8)
#define __THROW throw()
#define __THROWNL throw()
#define __NTH(f) __LEAF_ATTR f throw()
#define __NTHNL(f) f throw()
#else
#define __THROW
#define __THROWNL
#define __NTH(f) f
#define __NTHNL(f) f
#endif /* defined(__cplusplus) && __GNUC_PREREQ(2,8) */
#endif /* !defined(__cplusplus) && __GNUC_PREREQ(3,3) */
#else
#if (defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L)))
#define __inline inline
#else
#define __inline
#endif /* (defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L))) */
#define __THROW
#define __THROWNL
#define __NTH(f) f
#endif /* __GNUC__ */

/*
 * The __CONCAT macro is used to concatenate parts of symbol names, e.g.
 * with "#define OLD(foo) __CONCAT(old,foo)", OLD(foo) produces oldfoo.
 * The __CONCAT macro is a bit tricky -- make sure you don't put spaces
 * in between its arguments.  __CONCAT can also concatenate double-quoted
 * strings produced by the __STRING macro, but this only works with ANSI C.
 */
#if defined(__STDC__) || defined(__cplusplus)
#define __P(protos)     protos          /* full-blown ANSI C */
#define __CONCAT1(x,y)  x ## y
#define __CONCAT(x,y)   __CONCAT1(x,y)
#define __STRING(x)     #x              /* stringify without expanding x */
#define __XSTRING(x)    __STRING(x)     /* expand x, then stringify */

#define __const         const           /* define reserved names to standard */
#define __signed        signed
#define __volatile      volatile
#else   /* !(__STDC__ || __cplusplus) */
#define __P(protos)     ()              /* traditional C preprocessor */
#define __CONCAT(x,y)   x/**/y
#define __STRING(x)     "x"

#ifndef __GNUC__
#define __const                         /* delete pseudo-ANSI C keywords */
#define __signed
#define __volatile
#endif  /* !__GNUC__ */

/*
 * In non-ANSI C environments, new programs will want ANSI-only C keywords
 * deleted from the program and old programs will want them left alone.
 * Programs using the ANSI C keywords const, inline etc. as normal
 * identifiers should define -DNO_ANSI_KEYWORDS.
 */
#ifndef NO_ANSI_KEYWORDS
#define const           __const         /* convert ANSI C keywords */
#define inline          __inline
#define signed          __signed
#define volatile        __volatile
#endif /* !NO_ANSI_KEYWORDS */
#endif  /* !(__STDC__ || __cplusplus) */

/*
 * Compiler-dependent macros to help declare dead (non-returning) and
 * pure (no side effects) functions, and unused variables.  They are
 * null except for versions of gcc that are known to support the features
 * properly (old versions of gcc-2 supported the dead and pure features
 * in a different (wrong) way).
 */
#if __GNUC__ < 2 || __GNUC__ == 2 && __GNUC_MINOR__ < 5
#define __dead2
#define __pure2
#define __unused
#endif
#if __GNUC__ == 2 && __GNUC_MINOR__ >= 5 && __GNUC_MINOR__ < 7
#define __dead2         __attribute__((__noreturn__))
#define __pure2         __attribute__((__const__))
#define __unused
#endif
#if __GNUC__ == 2 && __GNUC_MINOR__ >= 7 || __GNUC__ >= 3
#define __dead2         __attribute__((__noreturn__))
#define __pure2         __attribute__((__const__))
#define __unused        __attribute__((__unused__))
#endif

#ifdef __GNUC__
#define __strong_reference(sym,aliassym) \
	extern __typeof (sym) aliassym __attribute__ ((alias (#sym)));
#define __weak_reference(sym,aliassym) \
	extern __typeof (sym) aliassym __attribute__ ((weak, alias (#sym)));
#endif

/*
 * GCC1 and some versions of GCC2 declare dead (non-returning) and
 * pure (no side effects) functions using "volatile" and "const";
 * unfortunately, these then cause warnings under "-ansi -pedantic".
 * GCC2 uses a new, peculiar __attribute__((attrs)) style.  All of
 * these work for GNU C++ (modulo a slight glitch in the C++ grammar
 * in the distribution version of 2.5.5).
 */
#if !defined(__GNUC__) || __GNUC__ < 2 || \
	(__GNUC__ == 2 && __GNUC_MINOR__ < 5)
#define __attribute__(x)        /* delete __attribute__ if non-gcc or gcc1 */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define __dead          __volatile
#define __pure          __const
#endif
#endif

/* Delete pseudo-keywords wherever they are not available or needed. */
#ifndef __dead
#define __dead
#define __pure
#endif

#endif /* !_SYS_CDEFS_H_ */
