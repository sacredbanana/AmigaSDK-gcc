/*      $NetBSD: signal.h,v 1.19 1995/08/13 22:51:24 mycroft Exp $      */

/*
 * Copyright (c) 1982, 1986, 1989, 1991, 1993
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
 *      @(#)signal.h    8.2 (Berkeley) 1/21/94
 */

#ifndef _SYS_SIGNAL_H_
#define _SYS_SIGNAL_H_

#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/_sigset.h>
#include <machine/signal.h>     /* sigcontext; codes for SIGILL, SIGFPE */

#if __POSIX_VISIBLE || __XSI_VISIBLE
#define SIGHUP  1       /* hangup */
#endif
#define SIGINT  2       /* interrupt */
#if __POSIX_VISIBLE || __XSI_VISIBLE
#define SIGQUIT 3       /* quit */
#endif
#define SIGILL  4       /* illegal instruction (not reset when caught) */
#if __XSI_VISIBLE
#define SIGTRAP 5       /* trace trap (not reset when caught) */
#endif
#define SIGABRT 6       /* abort() */
#if __BSD_VISIBLE
#define SIGIOT  SIGABRT /* compatibility */
#define SIGEMT  7       /* EMT instruction */
#endif
#define SIGFPE  8       /* floating point exception */
#if __POSIX_VISIBLE || __XSI_VISIBLE
#define SIGKILL 9       /* kill (cannot be caught or ignored) */
#endif
#if __POSIX_VISIBLE >= 200112 || __XSI_VISIBLE
#define SIGBUS  10      /* bus error */
#endif
#define SIGSEGV 11      /* segmentation violation */
#if __POSIX_VISIBLE >= 200112 || __XSI_VISIBLE
#define SIGSYS  12      /* bad argument to system call */
#endif
#if __POSIX_VISIBLE || __XSI_VISIBLE
#define SIGPIPE 13      /* write on a pipe with no one to read it */
#define SIGALRM 14      /* alarm clock */
#endif
#define SIGTERM 15      /* software termination signal from kill */
#if __POSIX_VISIBLE >= 200112 || __XSI_VISIBLE
#define SIGURG  16      /* urgent condition on IO channel */
#endif
#if __POSIX_VISIBLE || __XSI_VISIBLE
#define SIGSTOP 17      /* sendable stop signal not from tty */
#define SIGTSTP 18      /* stop signal from tty */
#define SIGCONT 19      /* continue a stopped process */
#define SIGCHLD 20      /* to parent on child stop or exit */
#define SIGTTIN 21      /* to readers pgrp upon background tty read */
#define SIGTTOU 22      /* like TTIN for output if (tp->t_local&LTOSTOP) */
#endif
#if __BSD_VISIBLE
#define SIGIO   23      /* input/output possible signal */
#define SIGPOLL SIGIO
#endif
#if __XSI_VISIBLE
#define SIGXCPU 24      /* exceeded CPU time limit */
#define SIGXFSZ 25      /* exceeded file size limit */
#define SIGVTALRM 26    /* virtual time alarm */
#define SIGPROF 27      /* profiling time alarm */
#endif
#if __BSD_VISIBLE
#define SIGWINCH 28     /* window size changes */
#define SIGINFO 29      /* information request */
#endif
#if __POSIX_VISIBLE || __XSI_VISIBLE
#define SIGUSR1 30      /* user defined signal 1 */
#define SIGUSR2 31      /* user defined signal 2 */
#endif
#if __BSD_VISIBLE
#define SIGMSG  32      /* an AmigaOS signal has been set. SIGMSG is normally ignored.
			   (code is the mask of new signals) */
#endif

#define SIG_DFL         ((__sighandler_t *)0)
#define SIG_IGN         ((__sighandler_t *)1)
#define SIG_ERR         ((__sighandler_t *)-1)
#define SIG_CATCH       ((__sighandler_t *)2)
#define SIG_HOLD        ((__sighandler_t *)3)

/*
 * Type of a signal handling function.
 *
 * Language spec sez we must list exactly one parameter, even though we
 * actually supply three.  Ugh!
 */
typedef void __sighandler_t(int);

#if __POSIX_VISIBLE || __XSI_VISIBLE
#ifndef _SIGSET_T_DECLARED
#define _SIGSET_T_DECLARED
typedef __sigset_t      sigset_t;
#endif
#endif

#if __POSIX_VISIBLE >= 199309 || __XSI_VISIBLE >= 500
/*
 * Signal Generation and Delivery
 */
union sigval {
	int    sival_int;    /* Integer signal value */
	void  *sival_ptr;    /* Pointer signal value */
};
#endif

#if __POSIX_VISIBLE >= 199309

struct pthread_attr;

struct sigevent {
	int     sigev_notify;           /* Notification type */
	int     sigev_signo;            /* Signal number */
	union sigval sigev_value;       /* Signal value */
	union {
		struct {
			void (*_function)(union sigval);
			struct pthread_attr **_attribute;
		} _sigev_thread;
		long __spare__[8];
	} _sigev_un;
};

#define sigev_notify_function           _sigev_un._sigev_thread._function
#define sigev_notify_attributes         _sigev_un._sigev_thread._attribute

#define SIGEV_NONE   0  /* No async notification. */
#define SIGEV_SIGNAL 1  /* Generate a queued signal. */
#define SIGEV_THREAD 2  /* A notification function is called to perform notification. */

#endif /* __POSIX_VISIBLE >= 199309 */

#if __POSIX_VISIBLE >= 199309 || __XSI_VISIBLE
typedef struct __siginfo {
	int          si_signo;    /* Signal number */
	int          si_errno;    /* errno association */
	int          si_code;     /* Cause of the signal */
	pid_t        si_pid;      /* sending process */
	uid_t        si_uid;      /* sender's ruid */
	int          si_status;   /* exit value */
	union sigval si_value;    /* Signal value */
	union {
		struct {
			int	_timerid;
			int	_overrun;
		} _timer;
		struct {
			long    _band;
		} _poll;
		struct {
			unsigned int _amigasigs; /* filled for SIGMSG */
		} _asigs;
		struct {
			long	__spare1__;
			int	__spare2__[7];
		} __spare__;
	} _reason;
} siginfo_t;

#define si_timerid      _reason._timer._timerid
#define si_overrun      _reason._timer._overrun
#define si_band         _reason._poll._band
#define si_amigasigs    _reason._asigs._amigasigs

/** si_code **/
#define CLD_EXITED      1       /* Child has exited */
#define CLD_STOPPED     5       /* Child has stopped */
#define CLD_CONTINUED   6       /* Stopped child has continued */

#endif

#if __POSIX_VISIBLE || __XSI_VISIBLE
struct __siginfo;

/*
 * Signal vector "template" used in sigaction call.
 */
struct sigaction {
	union {
		void (*__sa_handler)(int);  /* SIG_DFL, SIG_IGN, or pointer to a function */
		void (*__sa_sigaction)(int, struct __siginfo *, void *);
	} __sigaction_u;          /* signal handler */
	sigset_t sa_mask;         /* signal mask to apply */
	int sa_flags;             /* see signal options below */
};

#define sa_handler      __sigaction_u.__sa_handler
#endif

#if __XSI_VISIBLE
#define sa_sigaction    __sigaction_u.__sa_sigaction
#endif

#if __POSIX_VISIBLE || __XSI_VISIBLE
#define SA_NOCLDSTOP    0x0008  /* do not generate SIGCHLD on child stop */
#endif

#if __XSI_VISIBLE || __POSIX_VISIBLE >= 200809
#define SA_ONSTACK      0x0001  /* take signal on signal stack */
#define SA_RESTART      0x0002  /* restart system on signal return */
#define SA_RESETHAND    0x0004  /* reset to SIG_DFL when taking signal */
#define SA_NODEFER      0x0010  /* don't mask the signal we're delivering */
#define SA_NOCLDWAIT    0x0020  /* don't keep zombies around */
#define SA_SIGINFO      0x0040  /* signal handler with SA_SIGINFO args */
#ifdef COMPAT_SUNOS
#define SA_USERTRAMP    0x0100  /* do not bounce off kernel's sigtramp */
#endif
#endif

#define _NSIG   33      /* counting 0; could be 33 (mask is 1-32) */

#if __BSD_VISIBLE
#define NSIG _NSIG
#endif

#if __POSIX_VISIBLE || __XSI_VISIBLE
/*
 * Signal Actions
 */
#define SI_NOINFO  0       /* No signal info besides si_signo */
#define SI_USER    0x10001    /* Sent by a user. kill(), abort(), etc */
#define SI_QUEUE   0x10002    /* Sent by sigqueue() */
#define SI_TIMER   0x10003    /* Sent by expiration of a timer_settime() timer */
#define SI_ASYNCIO 0x10004    /* Indicates completion of asycnhronous IO */
#define SI_MESGQ   0x10005    /* Indicates arrival of a message at an empty queue */
#define SI_KERNEL  0x10006    /* Sent by kernel */
#endif

#if __BSD_VISIBLE
typedef __sighandler_t  *sig_t; /* type of pointer to a signal function */
#endif

#if __XSI_VISIBLE
#if __BSD_VISIBLE
#define	__stack_t sigaltstack
#endif
typedef	struct __stack_t stack_t;

#define SS_ONSTACK      0x0001  /* take signals on alternate stack */
#define SS_DISABLE      0x0004  /* disable taking signals on alternate stack */
#define MINSIGSTKSZ     8192                    /* minimum allowable stack */
#define SIGSTKSZ        (MINSIGSTKSZ + 32768)   /* recommended stack size */
#endif

/*
 * Structure used in sigaltstack call.
 */
struct  __stack_t {
	char    *ss_base;               /* signal stack base */
	int     ss_size;                /* signal stack length */
	int     ss_flags;               /* SS_DISABLE and/or SS_ONSTACK */
};

#if __BSD_VISIBLE
/*
 * 4.3 compatibility:
 * Signal vector "template" used in sigvec call.
 */
struct  sigvec {
	__sighandler_t *sv_handler;     /* signal handler */
	int     sv_mask;                /* signal mask to apply */
	int     sv_flags;               /* see signal options below */
};
#define SV_ONSTACK      SA_ONSTACK
#define SV_INTERRUPT    SA_RESTART      /* same bit, opposite sense */
#define SV_RESETHAND    SA_RESETHAND
#define SV_NODEFER      SA_NODEFER
#define SV_NOCLDSTOP    SA_NOCLDSTOP
#define SV_SIGINFO      SA_SIGINFO
#define sv_onstack sv_flags     /* isn't compatibility wonderful! */
#endif

#if __XSI_VISIBLE
/*
 * Structure used in sigstack call.
 */
struct  sigstack {
	char    *ss_sp;                 /* signal stack pointer */
	int     ss_onstack;             /* current status */
};
#endif

#if __BSD_VISIBLE || __POSIX_VISIBLE > 0 && __POSIX_VISIBLE <= 200112
/*
 * Macro for converting signal number to a mask suitable for
 * sigblock().
 */
#define sigmask(m)      (1 << ((m)-1))
#endif

#if __BSD_VISIBLE
#define BADSIG          SIG_ERR
#endif

#ifdef _KERNEL

#define sigcantmask     (sigmask(SIGKILL)|sigmask(SIGSTOP))
/*
 * get signal action for process and signal; currently only for current process
 */
#define SIGACTION(p, sig)       (u.u_signal[(sig)])

/*
 * Determine signal that should be delivered to process p, the current process,
 * 0 if none.  If there is a pending stop signal with default action,
 * the process stops in issig().
 */
#define CURSIG(p) \
	(((p)->p_sig == 0 || \
	    (((p)->p_flag&STRC) == 0 && ((p)->p_sig &~ (p)->p_sigmask) == 0)) ? \
	    0 : issig(p))

/*
 * Clear a pending signal from a process.
 */
#define CLRSIG(p, sig)  { (p)->p_sig &= ~sigmask(sig); }

#endif

#if __POSIX_VISIBLE || __XSI_VISIBLE
/*
 * Flags for sigprocmask:
 */
#define SIG_BLOCK       1       /* block specified signal set */
#define SIG_UNBLOCK     2       /* unblock specified signal set */
#define SIG_SETMASK     3       /* set specified signal set */
#endif

/*
 * For historical reasons; programs expect signal's return value to be
 * defined by <sys/signal.h>.
 */
__BEGIN_DECLS
__sighandler_t *signal __P((int, __sighandler_t *));
__END_DECLS

#endif  /* !_SYS_SIGNAL_H_ */
