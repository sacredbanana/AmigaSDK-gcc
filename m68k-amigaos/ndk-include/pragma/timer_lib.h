#ifndef PRAGMA_TIMER_LIB_H
#define PRAGMA_TIMER_LIB_H

/*
**	$VER: timer_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_TIMER_PROTOS_H
#include <clib/timer_protos.h>
#endif /* CLIB_TIMER_PROTOS_H */

/* "Timer.Device" */
#pragma amicall(TimerBase, 0x2a, AddTime(a0,a1))
#pragma amicall(TimerBase, 0x30, SubTime(a0,a1))
#pragma amicall(TimerBase, 0x36, CmpTime(a0,a1))
#pragma amicall(TimerBase, 0x3c, ReadEClock(a0))
#pragma amicall(TimerBase, 0x42, GetSysTime(a0))

#endif /* PRAGMA_TIMER_LIB_H */
