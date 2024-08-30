/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_BATTCLOCK_H
#define _PPCINLINE_BATTCLOCK_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef BATTCLOCK_BASE_NAME
#define BATTCLOCK_BASE_NAME BattClockBase
#endif /* !BATTCLOCK_BASE_NAME */

#define ReadBattClock() \
	LP0(12, ULONG , ReadBattClock, \
		, BATTCLOCK_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ResetBattClock() \
	LP0NR(6, ResetBattClock, \
		, BATTCLOCK_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadUTCBattClock() \
	(((ULONG (*)(void *))*(void**)((long)(BATTCLOCK_BASE_NAME) - 40))((void*)(BATTCLOCK_BASE_NAME)))

#define WriteUTCBattClock(__p0) \
	(((VOID (*)(void *, ULONG ))*(void**)((long)(BATTCLOCK_BASE_NAME) - 46))((void*)(BATTCLOCK_BASE_NAME), __p0))

#define WriteBattClock(__p0) \
	LP1NR(18, WriteBattClock, \
		ULONG , __p0, d0, \
		, BATTCLOCK_BASE_NAME, 0, 0, 0, 0, 0, 0)

#endif /* !_PPCINLINE_BATTCLOCK_H */
