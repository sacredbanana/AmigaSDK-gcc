/*      $NetBSD: unistd.h,v 1.25 1995/03/19 22:51:38 mycroft Exp $      */

/*-
 * Copyright (c) 1991 The Regents of the University of California.
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
 *      @(#)unistd.h    5.13 (Berkeley) 6/17/91
 */

#ifndef _UNISTD_H_
#define _UNISTD_H_

#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/unistd.h>

#define STDIN_FILENO    0       /* standard input file descriptor */
#define STDOUT_FILENO   1       /* standard output file descriptor */
#define STDERR_FILENO   2       /* standard error file descriptor */

#ifndef NULL
#define NULL            0       /* null pointer constant */
#endif

/* Unfortunately many headers and applications incorrectly check the
   availability of POSIX functionality by checking whether the define
   is defined rather than correctly checking for it both being defined
   and the value other than -1. Hence the -1 values must be not defiend
   at all to avoid build failures. */
/*#define _POSIX_BARRIERS                 -1*/
#define _POSIX_CPUTIME                  200112L
#define _POSIX_READER_WRITER_LOCKS      200112L
#define _POSIX_REGEXP                   1
#define _POSIX_SHELL                    1
#define _POSIX_SPAWN                    200112L
#define _POSIX_SPIN_LOCKS               200112L
#define _POSIX_THREAD_ATTR_STACKSIZE    200112L
#define _POSIX_THREAD_ATTR_STACKADDR    200112L
#define _POSIX_THREAD_CPUTIME           200112L
#define _POSIX_THREAD_PRIO_INHERIT      200112L
/*#define _POSIX_THREAD_PRIO_PROTECT      -1*/
#define _POSIX_THREAD_PRIORITY_SCHEDULING 200112L
/*#define _POSIX_THREAD_PROCESS_SHARED    -1*/
/*#define _POSIX_THREAD_SAFE_FUNCTIONS    -1*/
/*#define _POSIX_THREAD_SPORADIC_SERVER   -1*/
#define _POSIX_THREADS                  200112L
/*#define _POSIX_TRACE                    -1*/
/*#define _POSIX_TRACE_EVENT_FILTER       -1*/
/*#define _POSIX_TRACE_INHERIT            -1*/
/*#define _POSIX_TRACE_LOG                -1*/
#define _POSIX2_C_BIND                  200112L
/*#define _POSIX2_C_DEV                   -1*/
#define _POSIX2_CHAR_TERM               1
/*#define _POSIX2_FORT_DEV                -1*/
/*#define _POSIX2_FORT_RUN                -1*/
/*#define _POSIX2_LOCALEDEF               -1*/
/*#define _POSIX2_PBS                     -1*/
/*#define _POSIX2_PBS_ACCOUNTING          -1*/
/*#define _POSIX2_PBS_CHECKPOINT          -1*/
/*#define _POSIX2_PBS_LOCATE              -1*/
/*#define _POSIX2_PBS_MESSAGE             -1*/
/*#define _POSIX2_PBS_TRACK               -1*/
#define _POSIX2_SW_DEV                  1
#define _POSIX2_UPE                     200112L
#define _V6_ILP32_OFF32                 0
#define _V6_ILP32_OFFBIG                0
#define _V6_LP64_OFF64                  -1
#define _V6_LPBIG_OFFBIG                -1

#if __XSI_VISIBLE
#define _XOPEN_CRYPT                    -1
#define _XOPEN_ENH_I18N                 -1
#define _XOPEN_LEGACY                   -1
#define _XOPEN_REALTIME                 -1
#define _XOPEN_REALTIME_THREADS         -1
#define _XOPEN_UNIX                     -1
#endif

/* Define the POSIX.2 version we target for compliance. */
#define _POSIX2_VERSION         199212L

/* configurable system variables */
#define _SC_ARG_MAX             1
#define _SC_CHILD_MAX           2
#define _SC_CLK_TCK             3
#define _SC_NGROUPS_MAX         4
#define _SC_OPEN_MAX            5
#define _SC_JOB_CONTROL         6
#define _SC_SAVED_IDS           7
#define _SC_VERSION             8
#define _SC_BC_BASE_MAX         14
#define _SC_BC_DIM_MAX          15
#define _SC_BC_SCALE_MAX        16
#define _SC_BC_STRING_MAX       17
#define _SC_EXPR_NEST_MAX       18
#define _SC_LINE_MAX            19
#define _SC_RE_DUP_MAX          12
#define _SC_COLL_WEIGHTS_MAX    25
#define _SC_2_VERSION           26
#define _SC_2_C_BIND            27
#define _SC_2_C_DEV             28
#define _SC_2_CHAR_TERM         29
#define _SC_2_FORT_DEV          30
#define _SC_2_FORT_RUN          31
#define _SC_2_LOCALEDEF         32
#define _SC_2_SW_DEV            33
#define _SC_2_UPE               34
#define _SC_STREAM_MAX          35
#define _SC_TZNAME_MAX          13

#if __POSIX_VISIBLE >= 199309
#define _SC_ASYNCHRONOUS_IO     36
#define _SC_MAPPED_FILES        37
#define _SC_MEMLOCK             38
#define _SC_MEMLOCK_RANGE       39
#define _SC_MEMORY_PROTECTION   40
#define _SC_MESSAGE_PASSING     41
#define _SC_PRIORITIZED_IO      42
#define _SC_PRIORITY_SCHEDULING 43
#define _SC_REALTIME_SIGNALS    44
#define _SC_SEMAPHORES          45
#define _SC_FSYNC               46
#define _SC_SHARED_MEMORY_OBJECTS 47
#define _SC_SYNCHRONIZED_IO     48
#define _SC_TIMERS              49
#define _SC_AIO_LISTIO_MAX      50
#define _SC_AIO_MAX             51
#define _SC_AIO_PRIO_DELTA_MAX  52
#define _SC_DELAYTIMER_MAX      53
#define _SC_MQ_OPEN_MAX         54
#define _SC_PAGESIZE            11
#define _SC_RTSIG_MAX           55
#define _SC_SEM_NSEMS_MAX       56
#define _SC_SEM_VALUE_MAX       57
#define _SC_SIGQUEUE_MAX        58
#define _SC_TIMER_MAX           59
#endif

#if __POSIX_VISIBLE >= 200112
#define _SC_2_PBS               60
#define _SC_2_PBS_ACCOUNTING    61
#define _SC_2_PBS_CHECKPOINT    62
#define _SC_2_PBS_LOCATE        63
#define _SC_2_PBS_MESSAGE       64
#define _SC_2_PBS_TRACK         65
#define _SC_ADVISORY_INFO       66
#define _SC_BARRIERS            67
#define _SC_CLOCK_SELECTION     68
#define _SC_CPUTIME             69
#define _SC_FILE_LOCKING        70
#define _SC_GETGR_R_SIZE_MAX    71
#define _SC_GETPW_R_SIZE_MAX    72
#define _SC_HOST_NAME_MAX       9
#define _SC_LOGIN_NAME_MAX      10
#define _SC_MONOTONIC_CLOCK     73
#define _SC_MQ_PRIO_MAX         74
#define _SC_READER_WRITER_LOCKS 75
#define _SC_REGEXP              76
#define _SC_SHELL               77
#define _SC_SPAWN               78
#define _SC_SPIN_LOCKS          79
#define _SC_SPORADIC_SERVER     80
#define _SC_THREAD_ATTR_STACKADDR 81
#define _SC_THREAD_ATTR_STACKSIZE 82
#define _SC_THREAD_CPUTIME      83
#define _SC_THREAD_DESTRUCTOR_ITERATIONS 84
#define _SC_THREAD_KEYS_MAX     85
#define _SC_THREAD_PRIO_INHERIT 86
#define _SC_THREAD_PRIO_PROTECT 87
#define _SC_THREAD_PRIORITY_SCHEDULING 88
#define _SC_THREAD_PROCESS_SHARED 89
#define _SC_THREAD_SAFE_FUNCTIONS 90
#define _SC_THREAD_SPORADIC_SERVER 91
#define _SC_THREAD_STACK_MIN    92
#define _SC_THREAD_THREADS_MAX  93
#define _SC_TIMEOUTS            94
#define _SC_THREADS             95
#define _SC_TRACE               96
#define _SC_TRACE_EVENT_FILTER  97
#define _SC_TRACE_INHERIT       98
#define _SC_TRACE_LOG           99
#define _SC_TTY_NAME_MAX        100
#define _SC_TYPED_MEMORY_OBJECTS 101
#define _SC_V6_ILP32_OFF32      102
#define _SC_V6_ILP32_OFFBIG     103
#define _SC_V6_LP64_OFF64       104
#define _SC_V6_LPBIG_OFFBIG     105
#define _SC_IPV6                106
#define _SC_RAW_SOCKETS         107
#define _SC_SYMLOOP_MAX         22
#endif

#if __XSI_VISIBLE
#define _SC_ATEXIT_MAX          108
#define _SC_IOV_MAX             109
#define _SC_PAGE_SIZE           _SC_PAGESIZE
#define _SC_XOPEN_CRYPT         110
#define _SC_XOPEN_ENH_I18N      111
#define _SC_XOPEN_LEGACY        112
#define _SC_XOPEN_REALTIME      113
#define _SC_XOPEN_REALTIME_THREADS 114
#define _SC_XOPEN_SHM           115
#define _SC_XOPEN_STREAMS       116
#define _SC_XOPEN_UNIX          117
#define _SC_XOPEN_VERSION       118
#define _SC_XOPEN_XCU_VERSION   119
#endif

#if __BSD_VISIBLE
#define _SC_NPROCESSORS_CONF    23
#define _SC_NPROCESSORS_ONLN    24
#define _SC_CPUSET_SIZE         120
#define _SC_UEXTERR_MAXLEN      121
#endif

#if __POSIX_VISIBLE >= 202405
#define _SC_NSIG                122
#endif

/* extensions found in Solaris and Linux */
#define _SC_PHYS_PAGES          20
#define _SC_AVPHYS_PAGES        21

/* name values for confstr */
#if __POSIX_VISIBLE >= 199209
#define _CS_PATH                0
#endif

#if __POSIX_VISIBLE >= 200112
#define _CS_POSIX_V6_ILP32_OFF32_CFLAGS         2
#define _CS_POSIX_V6_ILP32_OFF32_LDFLAGS        3
#define _CS_POSIX_V6_ILP32_OFF32_LIBS           4
#define _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS        5
#define _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS       6
#define _CS_POSIX_V6_ILP32_OFFBIG_LIBS          7
#define _CS_POSIX_V6_LP64_OFF64_CFLAGS          8
#define _CS_POSIX_V6_LP64_OFF64_LDFLAGS         9
#define _CS_POSIX_V6_LP64_OFF64_LIBS            10
#define _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS        11
#define _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS       12
#define _CS_POSIX_V6_LPBIG_OFFBIG_LIBS          13
#define _CS_POSIX_V6_WIDTH_RESTRICTED_ENVS      14
#endif

__BEGIN_DECLS
__dead void      _exit __P((int)) __attribute__((noreturn));
int      access __P((const char *, int));
unsigned alarm __P((unsigned));
int      chdir __P((const char *));
int      chown __P((const char *, uid_t, gid_t));
int      close __P((int));
/*void     closefrom __P((int));*/
char    *cuserid __P((char *));
int      dup __P((int));
int      dup2 __P((int, int));
int      execl __P((const char *, const char *, ...));
int      execle __P((const char *, const char *, ...));
int      execlp __P((const char *, const char *, ...));
int      execv __P((const char *, char * const *));
int      execve __P((const char *, char * const *, char * const *));
int      execveat __P((int, const char *, char * const *, char * const *, int));
int      execvp __P((const char *, char * const *));
#ifdef _KERNEL
pid_t    fork __P((void));
#endif
long     fpathconf __P((int, int));             /* not yet */
char    *getcwd __P((char *, size_t));
gid_t    getegid __P((void));
uid_t    geteuid __P((void));
gid_t    getgid __P((void));
int      getgroups __P((int, gid_t *));
char    *getlogin __P((void));
pid_t    getpgrp __P((void));
pid_t    getpid __P((void));
pid_t    getppid __P((void));
uid_t    getuid __P((void));
int      isatty __P((int));
int      link __P((const char *, const char *));
#ifndef _LSEEK_DECLARED
#define	_LSEEK_DECLARED
off_t    lseek __P((int, off_t, int));
#endif
#ifdef _LARGEFILE64_SOURCE
#ifndef _LSEEK64_DECLARED
#define _LSEEK64_DECLARED
off64_t  lseek64 __P((int, off64_t, int));
#endif
#endif
long     pathconf __P((const char *, int));     /* not yet */
int      pause __P((void));
int      pipe __P((int *));
ssize_t  read __P((int, void *, size_t));
int      rmdir __P((const char *));
int      setgid __P((gid_t));
int      setpgid __P((pid_t, pid_t));
pid_t    setsid __P((void));
int      setuid __P((uid_t));
unsigned sleep __P((unsigned));
long     sysconf __P((int));                    /* not yet */
pid_t    tcgetpgrp __P((int));
int      tcsetpgrp __P((int, pid_t));
char    *ttyname __P((int));
/*int      ttyname_r __P((int, char *, size_t));*/
int      unlink __P((const char *));
ssize_t  write __P((int, const void *, size_t));

/* 1003.2-1992 */
#if __POSIX_VISIBLE >= 199209 || __XSI_VISIBLE
size_t   confstr __P((int, char *, size_t));
#ifndef _GETOPT_DECLARED
#define _GETOPT_DECLARED
int      getopt __P((int, char * const *, const char *));

extern   char *optarg;                  /* getopt(3) external variables */
extern   int optind, opterr, optopt;
#endif /* _GETOPT_DECLARED */
#ifndef _GETSUBOPT_DECLARED
#define _GETSUBOPT_DECLARED
int      getsubopt __P((char **, char * const *, char **));
extern   char *suboptarg;               /* getsubopt(3) external variable */
#endif /* _GETSUBOPT_DECLARED */
#endif

/* ISO/IEC 9945-1: 1996 */
#if __POSIX_VISIBLE >= 199506 || __XSI_VISIBLE
int      fsync __P((int));

/*
 * ftruncate() was in the POSIX Realtime Extension (it's used for shared
 * memory), but truncate() was not.
 */
#ifndef _FTRUNCATE_DECLARED
#define	_FTRUNCATE_DECLARED
int      ftruncate __P((int, off_t));
#endif
#ifdef _LARGEFILE64_SOURCE
#ifndef _FTRUNCATE64_DECLARED
#define _FTRUNCATE64_DECLARED
int      ftruncate64 __P((int, off64_t));
#endif
#endif
#endif

/* 1003.1-2001 */
#if __POSIX_VISIBLE >= 200112 || __XSI_VISIBLE
int      fchown __P((int, uid_t, gid_t));
int      readlink __P((const char *, char *, int));
#endif
#if __POSIX_VISIBLE >= 200112
int      gethostname __P((char *, int));
int      setegid __P((gid_t));
int      seteuid __P((uid_t));
#endif

/* 1003.1-2008 */
#if __POSIX_VISIBLE >= 200809 || __XSI_VISIBLE
/*int	   getsid __P((pid_t));*/
int      fchdir __P((int));
/*int      getpgid __P((pid_t));*/
int      lchown __P((const char *, uid_t, gid_t));
ssize_t  pread __P((int, void *, size_t, off_t));
ssize_t  pwrite __P((int, const void *, size_t, off_t));
#ifdef _LARGEFILE64_SOURCE
ssize_t  pread64 __P((int, void *, size_t, off64_t));
ssize_t  pwrite64 __P((int, const void *, size_t, off64_t));
#endif

/* See comment at ftruncate() above. */
#ifndef _TRUNCATE_DECLARED
#define	_TRUNCATE_DECLARED
int      truncate __P((const char *, off_t));
#endif
#ifdef _LARGEFILE64_SOURCE
#ifndef _TRUNCATE64_DECLARED
#define _TRUNCATE64_DECLARED
int      truncate64 __P((const char *, off64_t));
#endif
#endif
#endif /* __POSIX_VISIBLE >= 200809 || __XSI_VISIBLE */

#if __POSIX_VISIBLE >= 200809
int      faccessat __P((int, const char *, int, int));
int      fchownat __P((int, const char *, uid_t, gid_t, int));
/*int      fexecve __P((int, char *const [], char *const []));*/
int      linkat __P((int, const char *, int, const char *, int));
int      readlinkat __P((int, const char *, char *, int));
int      symlinkat __P((const char *, int, const char *));
int      unlinkat __P((int, const char *, int));
#endif /* __POSIX_VISIBLE >= 200809 */

/*
 * symlink() was originally in POSIX.1a, which was withdrawn after
 * being overtaken by events (1003.1-2001).  It was in XPG4.2, and of
 * course has been in BSD since 4.2.
 */
#if __POSIX_VISIBLE >= 200112 || __XSI_VISIBLE >= 402
int      symlink __P((const char *, const char *));
#endif

/* X/Open System Interfaces */
#if __XSI_VISIBLE
char    *crypt __P((const char *, const char *));
long     gethostid __P((void));
/*int      lockf __P((int, int, off_t));*/
int      nice __P((int));
int      setregid __P((gid_t, gid_t));
int      setreuid __P((uid_t, uid_t));

#if 0
#ifndef _SWAB_DECLARED
#define _SWAB_DECLARED
void	 swab(const void * __restrict, void * __restrict, ssize_t);
#endif /* _SWAB_DECLARED */
#endif

void     sync __P((void));

#endif /* __XSI_VISIBLE */

#if (__XSI_VISIBLE && __XSI_VISIBLE <= 500) || __BSD_VISIBLE
char    *brk __P((const char *));
int      chroot __P((const char *));
int      getdtablesize __P((void));
int      getpagesize __P((void));
char    *getpass __P((const char *));
char    *sbrk __P((int));
#endif

#if (__XSI_VISIBLE && __XSI_VISIBLE <= 600) || __BSD_VISIBLE
char    *getwd __P((char *));                   /* obsoleted by getcwd() */
useconds_t ualarm __P((useconds_t, useconds_t));
int      usleep __P((useconds_t));
pid_t    vfork __P((void));
#endif

#if __BSD_VISIBLE
struct timeval;				/* select(2) */

int      acct __P((const char *));
int      des_cipher __P((const char *, char *, long, int));
int      des_setkey __P((const char *key));
int      encrypt __P((char *, int));
void     endusershell __P((void));
int      exect __P((const char *, char * const *, char * const *));
int      execvpe __P((const char *, char * const *, char * const *));
int      getdomainname __P((char *, int));
mode_t   getmode __P((const void *, mode_t));
char    *getusershell __P((void));
int      initgroups __P((const char *, gid_t));
int      iruserok __P((u_long, int, const char *, const char *));
#ifndef _MKDTEMP_DECLARED
char    *mkdtemp __P((char *));
#define	_MKDTEMP_DECLARED
#endif
#ifndef	_MKNOD_DECLARED
int      mknod __P((const char *, mode_t, dev_t));
#define	_MKNOD_DECLARED
#endif
#ifndef _MKSTEMP_DECLARED
int      mkstemp __P((char *));
#define	_MKSTEMP_DECLARED
#endif
#ifndef _MKTEMP_DECLARED
char    *mktemp __P((char *));
#define	_MKTEMP_DECLARED
#endif
int      nfssvc __P((int, void *));
void     psignal __P((unsigned int, const char *));
#ifdef _KERNEL
extern char *sys_siglist[];
#else
extern const char *const sys_siglist[];
#endif
int      profil __P((char *, int, int, int));
int      rcmd __P((char **, int, const char *,
		const char *, const char *, int *));
char    *re_comp __P((const char *));
int      re_exec __P((const char *));
int      reboot __P((int));
int      revoke __P((const char *));
int      rresvport __P((int *));
int      ruserok __P((const char *, int, const char *, const char *));
#ifndef _SELECT_DECLARED
#define	_SELECT_DECLARED
int      select __P((int, fd_set *, fd_set *, fd_set *, struct timeval *));
#endif
int      setdomainname __P((const char *, int));
int      setgroups __P((int, const gid_t *));
void     sethostid __P((long));
int      sethostname __P((const char *, int));
int      setkey __P((const char *));
int      setlogin __P((const char *));
void    *setmode __P((const char *));
int      setpgrp __P((pid_t pid, pid_t pgrp));  /* obsoleted by setpgid() */
int      setrgid __P((gid_t));
int      setruid __P((uid_t));
void     setusershell __P((void));
int      swapon __P((const char *));
int      syscall __P((int, ...));
int      ttyslot __P((void));
int      undelete __P((const char *));
void    *valloc __P((size_t));                  /* obsoleted by malloc() */

#ifndef _OPTRESET_DECLARED
#define	_OPTRESET_DECLARED
extern   int optreset;
#endif
#endif /* __BSD_VISIBLE */
__END_DECLS

#endif /* !_UNISTD_H_ */
