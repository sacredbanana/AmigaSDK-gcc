/*      $NetBSD: time.h,v 1.9 1994/10/26 00:56:35 cgd Exp $     */

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
 *      @(#)time.h      5.12 (Berkeley) 3/9/91
 */

#ifndef _TIME_H_
#define _TIME_H_

#include <sys/cdefs.h>
#include <sys/types.h>
#include <machine/ansi.h>

#if __POSIX_VISIBLE >= 199309
#define CLOCK_REALTIME          1
#define CLOCK_MONOTONIC         4
#endif
#if __BSD_VISIBLE
#define CLOCK_MONOTONIC_RAW     5
#define CLOCK_UPTIME            6
#endif
#if __POSIX_VISIBLE >= 199506
#define CLOCK_THREAD_CPUTIME_ID 14
#define CLOCK_PROCESS_CPUTIME_ID 15
#endif
#if __BSD_VISIBLE
#define CLOCK_BOOTTIME          CLOCK_MONOTONIC
#endif

#if __POSIX_VISIBLE >= 199309
#define TIMER_ABSTIME   0x1     /* absolute timer */
#endif

#if __POSIX_VISIBLE > 0 && __POSIX_VISIBLE < 200112 || __BSD_VISIBLE
#define CLK_TCK         100
#endif

#define CLOCKS_PER_SEC  100

#ifdef  _BSD_CLOCK_T_
typedef _BSD_CLOCK_T_   clock_t;
#undef  _BSD_CLOCK_T_
#endif

#ifdef  _BSD_TIME_T_
typedef _BSD_TIME_T_    time_t;
#undef  _BSD_TIME_T_
#endif

#define __need_NULL
#define __need_size_t
#include <stddef.h>

#if __POSIX_VISIBLE >= 199309
#include <sys/timespec.h>
#endif

struct tm {
	int     tm_sec;         /* seconds after the minute [0-60] */
	int     tm_min;         /* minutes after the hour [0-59] */
	int     tm_hour;        /* hours since midnight [0-23] */
	int     tm_mday;        /* day of the month [1-31] */
	int     tm_mon;         /* months since January [0-11] */
	int     tm_year;        /* years since 1900 */
	int     tm_wday;        /* days since Sunday [0-6] */
	int     tm_yday;        /* days since January 1 [0-365] */
	int     tm_isdst;       /* Daylight Savings Time flag */
	long    tm_gmtoff;      /* offset from CUT in seconds */
	char    *tm_zone;       /* timezone abbreviation */
};

#if __POSIX_VISIBLE
extern char *tzname[2];
#endif

__BEGIN_DECLS
char *asctime __P((const struct tm *));
clock_t clock __P((void));
char *ctime __P((const time_t *));
#ifndef _STANDALONE
double difftime __P((time_t, time_t));
#endif
struct tm *gmtime __P((const time_t *));
struct tm *localtime __P((const time_t *));
time_t mktime __P((struct tm *));
size_t strftime __P((char *, size_t, const char *, const struct tm *));
time_t time __P((time_t *));
#if __POSIX_VISIBLE >= 200112
struct sigevent;
int timer_create __P((clockid_t, struct sigevent *, timer_t *));
int timer_delete __P((timer_t));
int timer_gettime __P((timer_t, struct itimerspec *));
int timer_getoverrun __P((timer_t));
int timer_settime __P((timer_t, int, const struct itimerspec *, struct itimerspec *));
#endif
#if __POSIX_VISIBLE
void tzset __P((void));
#endif

#if __POSIX_VISIBLE >= 199309
int clock_getres __P((clockid_t, struct timespec *));
int clock_gettime __P((clockid_t, struct timespec *));
int clock_settime __P((clockid_t, const struct timespec *));
int nanosleep __P((const struct timespec *, struct timespec *));
#endif

#if __POSIX_VISIBLE >= 200112
int clock_getcpuclockid __P((pid_t, clockid_t *));
int clock_nanosleep __P((clockid_t, int, const struct timespec *, struct timespec *));
#endif

#if __POSIX_VISIBLE >= 199506
char *asctime_r __P((const struct tm *, char *));
char *ctime_r __P((const time_t *, char *));
struct tm *gmtime_r __P((const time_t *, struct tm *));
struct tm *localtime_r __P((const time_t *, struct tm *));
#endif

#if __BSD_VISIBLE
time_t timelocal __P((struct tm * const));
time_t timegm __P((struct tm * const));
/*int timer_oshandle_np __P((timer_t timerid));*/
time_t time2posix __P((time_t t));
time_t posix2time __P((time_t t));
struct tm *offtime __P((const time_t *, long));
/*struct tm *offtime_r __P((const time_t *, long, struct tm *));*/
#endif

#if __BSD_VISIBLE
char *timezone __P((int, int));
void tzsetwall __P((void));
#endif

__END_DECLS

#endif /* !_TIME_H_ */
