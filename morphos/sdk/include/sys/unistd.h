/*
 * Copyright (c) 1989 The Regents of the University of California.
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
 *      @(#)unistd.h    5.14 (Berkeley) 4/1/91
 */

#ifndef _SYS_UNISTD_H_
#define _SYS_UNISTD_H_

#include <sys/cdefs.h>

/* Unfortunately many headers and applications incorrectly check the
   availability of POSIX functionality by checking whether the define
   is defined rather than correctly checking for it both being defined
   and the value other than -1. Hence the -1 values must be not defiend
   at all to avoid build failures. */
#define _POSIX_ADVISORY_INFO            200112L
/*#define _POSIX_ASYNCHRONOUS_IO          -1*/
#define _POSIX_CHOWN_RESTRICTED         1
/*#define _POSIX_CLOCK_SELECTION          -1*/
#define _POSIX_CPUTIME                  200112L
#define _POSIX_FSYNC                    200112L
/*#define _POSIX_IPV6                     -1*/
#define _POSIX_JOB_CONTROL              1
#define _POSIX_MAPPED_FILES             200112L
#define _POSIX_MEMLOCK                  200112L
#define _POSIX_MEMLOCK_RANGE            200112L
#define _POSIX_MEMORY_PROTECTION        200112L
/*#define _POSIX_MESSAGE_PASSING          -1*/
#define _POSIX_MONOTONIC_CLOCK          200112L
#define _POSIX_NO_TRUNC                 0
/*#define _POSIX_PRIORITIZED_IO           -1*/
/*#define _POSIX_PRIORITY_SCHEDULING      -1*/
#define _POSIX_RAW_SOCKETS              200112L
/*#define _POSIX_REALTIME_SIGNALS         -1*/
#define _POSIX_SEMAPHORES               200112L
#define _POSIX_SHARED_MEMORY_OBJECTS    200112L
/*#define _POSIX_SPORADIC_SERVER          -1*/
/*#define _POSIX_SYNCHRONIZED_IO          -1*/
/*#define _POSIX_TIMEOUTS                 -1*/
#define _POSIX_TIMERS                   200112L
/*#define _POSIX_TYPED_MEMORY_OBJECTS     -1*/
#ifndef _POSIX_VDISABLE
#define _POSIX_VDISABLE                 0xff
#endif
#if __XSI_VISIBLE
#define _XOPEN_SHM              1
#define _XOPEN_STREAMS          -1
#endif

#ifdef _NOT_AVAILABLE
#define _POSIX_SAVED_IDS        1 /* saved set-user-ID and set-group-ID */
#endif

/* Define the POSIX.1 version we target for compliance. */
#define _POSIX_VERSION          200809L

/* access function */
#define F_OK            0       /* test for existence of file */
#define X_OK            0x01    /* test for execute or search permission */
#define W_OK            0x02    /* test for write permission */
#define R_OK            0x04    /* test for read permission */

/* whence values for lseek(2) */
#ifndef SEEK_SET
#define SEEK_SET        0       /* set file offset to offset */
#define SEEK_CUR        1       /* set file offset to current plus offset */
#define SEEK_END        2       /* set file offset to EOF plus offset */
#endif

#ifndef _POSIX_SOURCE
/* whence values for lseek(2); renamed by POSIX 1003.1 */
#define L_SET           SEEK_SET
#define L_INCR          SEEK_CUR
#define L_XTND          SEEK_END
#endif

/* configurable pathname variables */
#define _PC_LINK_MAX            1
#define _PC_MAX_CANON           2
#define _PC_MAX_INPUT           3
#define _PC_NAME_MAX            4
#define _PC_PATH_MAX            5
#define _PC_PIPE_BUF            6
#define _PC_CHOWN_RESTRICTED    7
#define _PC_NO_TRUNC            8
#define _PC_VDISABLE            9

#if __POSIX_VISIBLE >= 199309
#define _PC_ASYNC_IO            53
#define _PC_PRIO_IO             54
#define _PC_SYNC_IO             55
#endif

#if __POSIX_VISIBLE >= 200112
#define _PC_ALLOC_SIZE_MIN      10
#define _PC_FILESIZEBITS        12
#define _PC_REC_INCR_XFER_SIZE  14
#define _PC_REC_MAX_XFER_SIZE   15
#define _PC_REC_MIN_XFER_SIZE   16
#define _PC_REC_XFER_ALIGN      17
#define _PC_SYMLINK_MAX         18
#endif

#if __BSD_VISIBLE
#define _PC_ACL_EXTENDED        59
#define _PC_ACL_PATH_MAX        60
#define _PC_CAP_PRESENT         61
#define _PC_INF_PRESENT         62
#define _PC_MAC_PRESENT         63
#define _PC_ACL_NFS4            64
#define _PC_DEALLOC_PRESENT     65
#define _PC_NAMEDATTR_ENABLED   66
#define _PC_HAS_NAMEDATTR       67
#define _PC_XATTR_ENABLED       _PC_NAMEDATTR_ENABLED
#define _PC_XATTR_EXISTS        _PC_HAS_NAMEDATTR
#define _PC_HAS_HIDDENSYSTEM    68
#define _PC_CLONE_BLKSIZE       69
#endif

/* From OpenSolaris, used by SEEK_DATA/SEEK_HOLE. */
#define _PC_MIN_HOLE_SIZE       21

#endif /* !_SYS_UNISTD_H_ */
