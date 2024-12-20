/*	$NetBSD: time.h,v 1.9 1994/10/26 00:56:35 cgd Exp $	*/

/*
 * Copyright (c) 1989 The Regents of the University of California.
 * All rights reserved.
 *
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
 *	@(#)time.h	5.12 (Berkeley) 3/9/91
 */

#ifndef _TIME_H_
#define	_TIME_H_

#include <machine/ansi.h>

#ifdef	_BSD_CLOCK_T_
typedef	_BSD_CLOCK_T_	clock_t;
#undef	_BSD_CLOCK_T_
#endif

#if !defined(_ANSI_SOURCE)
#ifdef	_BSD_CLOCKID_T_
typedef	_BSD_CLOCKID_T_	clockid_t;
#undef	_BSD_CLOCKID_T_
#endif

#include <sys/time.h>
#endif /* !defined(_ANSI_SOURCE) */

#ifdef	_BSD_TIME_T_
typedef	_BSD_TIME_T_	time_t;
#undef	_BSD_TIME_T_
#endif

#define __need_NULL
#define __need_size_t
#include <stddef.h>

#define CLOCKS_PER_SEC	100

#if !defined(CLOCK_REALTIME) && !defined(_ANSI_SOURCE)
#define CLOCK_REALTIME			0
#define CLOCK_MONOTONIC			1
#define CLOCK_PROCESS_CPUTIME_ID        2
#define CLOCK_THREAD_CPUTIME_ID         3
#define CLOCK_MONOTONIC_RAW		4
#endif /* !defined(CLOCK_REALTIME) && !defined(_ANSI_SOURCE) */

#if !defined(TIMER_ABSTIME) && !defined(_ANSI_SOURCE)
#define TIMER_RELTIME	0x0	/* relative timer */
#define TIMER_ABSTIME	0x1	/* absolute timer */
#endif /* !defined(TIMER_ABSTIME) && !defined(_ANSI_SOURCE)*/

struct tm {
	int	tm_sec;		/* seconds after the minute [0-60] */
	int	tm_min;		/* minutes after the hour [0-59] */
	int	tm_hour;	/* hours since midnight [0-23] */
	int	tm_mday;	/* day of the month [1-31] */
	int	tm_mon;		/* months since January [0-11] */
	int	tm_year;	/* years since 1900 */
	int	tm_wday;	/* days since Sunday [0-6] */
	int	tm_yday;	/* days since January 1 [0-365] */
	int	tm_isdst;	/* Daylight Savings Time flag */
	long	tm_gmtoff;	/* offset from CUT in seconds */
	char	*tm_zone;	/* timezone abbreviation */
};

#include <sys/cdefs.h>

__BEGIN_DECLS
char *asctime __P((const struct tm *));
char *asctime_r __P((const struct tm *, char *));
clock_t clock __P((void));
char *ctime __P((const time_t *));
char *ctime_r __P((const time_t *, char *));
double difftime __P((time_t, time_t));
struct tm *gmtime __P((const time_t *));
struct tm *gmtime_r __P((const time_t *, struct tm *));
struct tm *localtime __P((const time_t *));
struct tm *localtime_r __P((const time_t *, struct tm *));
time_t mktime __P((struct tm *));
size_t strftime __P((char *, size_t, const char *, const struct tm *));
time_t time __P((time_t *));

#if !defined(_ANSI_SOURCE)
#define CLK_TCK		100
extern char *tzname[2];
void tzset __P((void));

int clock_getres __P((clockid_t, struct timespec *));
int clock_gettime __P((clockid_t, struct timespec *));
int clock_settime __P((clockid_t, const struct timespec *));
int nanosleep __P((const struct timespec *, struct timespec *));
int clock_getcpuclockid __P((pid_t, clockid_t *));
int clock_nanosleep __P((clockid_t, int, const struct timespec *, struct timespec *));
#endif /* not ANSI */

#if !defined(_ANSI_SOURCE) && !defined(_POSIX_SOURCE)
char *timezone __P((int, int));
void tzsetwall __P((void));

struct DateStamp;
void utunpk __P((long, char *));
//int timer(unsigned int *);
time_t __datecvt __P((const struct DateStamp *));
struct DateStamp *__timecvt __P((time_t));
long utpack __P((const char *));
#endif /* neither ANSI nor POSIX */
__END_DECLS

#endif /* !_TIME_H_ */
