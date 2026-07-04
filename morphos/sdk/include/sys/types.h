/*      $NetBSD: types.h,v 1.23 1995/05/28 03:06:34 jtc Exp $   */

/*-
 * Copyright (c) 1982, 1986, 1991, 1993
 *      The Regents of the University of California.  All rights reserved.
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
 *      @(#)types.h     8.4 (Berkeley) 1/21/94
 */

#ifndef _SYS_TYPES_H_
#define _SYS_TYPES_H_

#define __BUILD_IS_IXEMUL

#include <sys/cdefs.h>

/* Machine type dependent parameters. */
#include <machine/types.h>

#include <machine/ansi.h>
#include <machine/endian.h>

/* should be put in a <machine/..> header */
#ifndef __ALIGN2__
#ifdef __PPC__
#define __ALIGN2__  __attribute__((aligned(2)))
#define __PACKED__  __attribute__((packed))
#else
#define __ALIGN2__
#define __PACKED__
#endif
#endif

#if __BSD_VISIBLE || defined __MORPHOS__
typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef unsigned int    u_int;
typedef unsigned long   u_long;
#ifndef _KERNEL
typedef unsigned short  ushort;         /* Sys V compatibility */
typedef unsigned int    uint;           /* Sys V compatibility */
#endif
#endif

typedef u_int64_t       u_quad_t;       /* quads */
typedef int64_t         quad_t;
typedef quad_t *        qaddr_t;

typedef char *          caddr_t;        /* core address */
typedef int32_t         daddr_t;        /* disk address */
typedef int64_t         blkcnt_t;
typedef int32_t         blksize_t;
typedef int16_t         dev_t;          /* device number */
typedef u_int64_t       fsblkcnt_t;
typedef u_int64_t       fsfilcnt_t;
typedef u_int32_t       fixpt_t;        /* fixed point number */
typedef u_int16_t       gid_t;          /* group id */
typedef int64_t         id_t;           /* generic id */
typedef u_int32_t       ino_t;          /* inode number */
typedef long            key_t;          /* IPC key (for Sys V IPC) */
typedef u_int16_t       mode_t;         /* permissions */
typedef u_int16_t       nlink_t;        /* link count */
typedef int32_t         pid_t;          /* process id */
typedef int32_t         rlim_t;         /* resource limit */
typedef int32_t         segsz_t;        /* segment size */
typedef int32_t         swblk_t;        /* swap offset */
typedef u_int16_t       uid_t;          /* user id */
typedef int64_t         off64_t;        /* 64-bit file offset */
#ifndef __socklen_t_defined
typedef u_int32_t       socklen_t;
# define __socklen_t_defined
#endif

#ifdef  _BSD_FPOS_T_
typedef _BSD_FPOS_T_    fpos_t;
#undef  _BSD_FPOS_T_
#endif

#ifdef  _BSD_OFF_T_
typedef _BSD_OFF_T_     off_t;
#undef  _BSD_OFF_T_
#endif

#ifndef _SIZE_T
#ifdef  _BSD_SIZE_T_
typedef _BSD_SIZE_T_    size_t;
#define _SIZE_T
#undef  _BSD_SIZE_T_
#endif
#endif

/*
 * These belong in unistd.h, but are placed here too to ensure that
 * long arguments will be promoted to off_t if the program fails to 
 * include that header or explicitly cast them to off_t.
 */
#if __BSD_VISIBLE
#ifndef _KERNEL
__BEGIN_DECLS
#ifndef _FTRUNCATE_DECLARED
#define	_FTRUNCATE_DECLARED
int      ftruncate __P((int, off_t));
#endif
#ifndef _LSEEK_DECLARED
#define _LSEEK_DECLARED
off_t    lseek __P((int, off_t, int));
#endif
#ifndef _MMAP_DECLARED
#define	_MMAP_DECLARED
void    *mmap __P((void *, size_t, int, int, int, off_t));
#endif
#ifndef _TRUNCATE_DECLARED
#define	_TRUNCATE_DECLARED
int      truncate __P((const char *, off_t));
#endif
__END_DECLS
#endif /* !_KERNEL */
#endif /* !__BSD_VISIBLE */

#if __BSD_VISIBLE
/* Major, minor numbers, dev_t's. */
#define major(x)        ((int32_t)(((u_int32_t)(x) >> 8) & 0xff))
#define minor(x)        ((int32_t)((x) & 0xff))
#define makedev(x,y)    ((dev_t)(((x) << 8) | (y)))
#endif

#ifdef  _BSD_CLOCK_T_
typedef _BSD_CLOCK_T_   clock_t;
#undef  _BSD_CLOCK_T_
#endif

#ifdef  _BSD_SSIZE_T_
typedef _BSD_SSIZE_T_   ssize_t;
#undef  _BSD_SSIZE_T_
#endif

#ifdef  _BSD_TIME_T_
typedef _BSD_TIME_T_    time_t;
#undef  _BSD_TIME_T_
#endif

#define __TIMESIZE 64
typedef int32_t time32_t;

#ifdef  _BSD_CLOCKID_T_
typedef _BSD_CLOCKID_T_ clockid_t;
#undef  _BSD_CLOCKID_T_
#endif

#ifdef  _BSD_TIMER_T_
typedef _BSD_TIMER_T_   timer_t;
#undef  _BSD_TIMER_T_
#endif

#ifdef  _BSD_SUSECONDS_T_
typedef _BSD_SUSECONDS_T_ suseconds_t;
#undef  _BSD_SUSECONDS_T_
#endif

#ifdef  _BSD_USECONDS_T_
typedef _BSD_USECONDS_T_ useconds_t;
#undef  _BSD_USECONDS_T_
#endif

#define __need_size_t
#include <stddef.h>

#if __BSD_VISIBLE
#define NBBY    8               /* number of bits in a byte */

#include <sys/select.h>

#if defined(__STDC__) && defined(_KERNEL)
/*
 * Forward structure declarations for function prototypes.  We include the
 * common structures that cross subsystem boundaries here; others are mostly
 * used in the same place that the structure is defined.
 */
struct  proc;
struct  pgrp;
struct  ucred;
struct  rusage;
struct  file;
struct  buf;
struct  tty;
struct  uio;
#endif

#endif /* __BSD_VISIBLE */
#endif /* !_SYS_TYPES_H_ */
