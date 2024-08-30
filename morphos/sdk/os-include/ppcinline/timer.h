/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_TIMER_H
#define _PPCINLINE_TIMER_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef TIMER_BASE_NAME
#define TIMER_BASE_NAME TimerBase
#endif /* !TIMER_BASE_NAME */

#define GetUpTime(__p0) \
	(((VOID (*)(void *, struct timeval *))*(void**)((long)(TIMER_BASE_NAME) - 76))((void*)(TIMER_BASE_NAME), __p0))

#define SubTime(__p0, __p1) \
	LP2NR(48, SubTime, \
		struct timeval *, __p0, a0, \
		CONST struct timeval *, __p1, a1, \
		, TIMER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CmpTime(__p0, __p1) \
	LP2(54, LONG , CmpTime, \
		CONST struct timeval *, __p0, a0, \
		CONST struct timeval *, __p1, a1, \
		, TIMER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadEClock(__p0) \
	LP1(60, ULONG , ReadEClock, \
		struct EClockVal *, __p0, a0, \
		, TIMER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadCPUClock(__p0) \
	(((ULONG (*)(void *, UQUAD *))*(void**)((long)(TIMER_BASE_NAME) - 70))((void*)(TIMER_BASE_NAME), __p0))

#define AddTime(__p0, __p1) \
	LP2NR(42, AddTime, \
		struct timeval *, __p0, a0, \
		CONST struct timeval *, __p1, a1, \
		, TIMER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetUTCSysTime(__p0) \
	(((VOID (*)(void *, struct timeval *))*(void**)((long)(TIMER_BASE_NAME) - 88))((void*)(TIMER_BASE_NAME), __p0))

#define GetSysTime(__p0) \
	LP1NR(66, GetSysTime, \
		struct timeval *, __p0, a0, \
		, TIMER_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_TIMER_H */
