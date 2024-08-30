/*
 * time.h
 * 
 * Struct and function declarations for dealing with time.
 */

#ifndef _TIME_H_
#define _TIME_H_

#include "_ansi.h"
#include <sys/reent.h>

#ifndef NULL
#define	NULL	0
#endif

/* Get _CLOCKS_PER_SEC_ */
#include <machine/time.h>

#ifndef _CLOCKS_PER_SEC_
#define _CLOCKS_PER_SEC_ 1000000
#endif

#define CLOCKS_PER_SEC _CLOCKS_PER_SEC_
#define CLK_TCK CLOCKS_PER_SEC
#define __need_size_t
#include <stddef.h>

#define CLOCK_REALTIME           (clockid_t)0
#define CLOCK_MONOTONIC          (clockid_t)1
#define CLOCK_PROCESS_CPUTIME_ID (clockid_t)2
#define CLOCK_THREAD_CPUTIME_ID  (clockid_t)3

#include <sys/types.h>

_BEGIN_STD_C

struct tm
{
  int	tm_sec;
  int	tm_min;
  int	tm_hour;
  int	tm_mday;
  int	tm_mon;
  int	tm_year;
  int	tm_wday;
  int	tm_yday;
  int	tm_isdst;
  long	tm_gmtoff;
  const char *tm_zone;
};

clock_t	   clock       (void);
double	   difftime    (time_t _time2, time_t _time1);
time_t	   mktime      (struct tm *_timeptr);
time_t	   time        (time_t *_timer);
char	  *asctime     (const struct tm *_tblock);
char	  *ctime       (const time_t *_time);
struct tm *gmtime      (const time_t *_timer);
struct tm *localtime   (const time_t *_timer);
size_t	   strftime    (char *_s, size_t _maxsize, const char *_fmt, const struct tm *_t);

char	  *asctime_r   (const struct tm *, char *);
char	  *ctime_r     (const time_t *, char *);
struct tm *gmtime_r    (const time_t *, struct tm *);
struct tm *localtime_r (const time_t *, struct tm *);

int        clock_settime (clockid_t clock_id, const struct timespec *tp);
int        clock_gettime (clockid_t clock_id, struct timespec *tp);
int        clock_getres  (clockid_t clock_id, struct timespec *res);

_END_STD_C

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __STRICT_ANSI__
char      *strptime (const char *, const char *, struct tm *);
void       tzset    (void);
void       _tzset_r (struct _reent *);
#endif /* !__STRICT_ANSI__ */

#ifdef __cplusplus
}
#endif

#include <sys/features.h>

#endif /* _TIME_H_ */

