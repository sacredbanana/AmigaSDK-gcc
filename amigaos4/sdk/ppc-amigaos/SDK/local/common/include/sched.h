#ifndef SCHED_H
#define SCHED_H
/*
**    $Id: sched.h$
**
**    POSIX thread library
**
**    Copyright 2004 Thomas and Hans-Jörg Frieden
**    All rights reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**    All Rights Reserved.
*/

#include <errno.h>
#include <sys/types.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif


enum enShedParam
{
	SCHED_OTHER = 0,
	SCHED_FIFO = 1,
	SCHED_RR = 2
};


struct sched_param
{
	int sched_priority;
};

/* Both clib2 and newlib define struct timespec */
#if !defined(__CLIB2__) && !defined(__NEWLIB__)
struct timespec
{
	unsigned int tv_sec;
	unsigned int tv_nsec;
};
#endif


int		sched_get_priority_max(int);
int		sched_get_priority_min(int);
int		sched_getparam(pid_t, struct sched_param *);
int		sched_getscheduler(pid_t);
int		sched_rr_get_interval(pid_t, struct timespec *);
int		sched_setparam(pid_t, const struct sched_param *);
int		sched_setscheduler(pid_t, int, const struct sched_param *);
int		sched_yield(void);

#ifdef __cplusplus
}
#endif
#endif
