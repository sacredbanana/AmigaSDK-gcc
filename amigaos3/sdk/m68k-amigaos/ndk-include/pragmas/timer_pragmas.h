#ifndef PRAGMAS_TIMER_PRAGMAS_H
#define PRAGMAS_TIMER_PRAGMAS_H

/*
**	$VER: timer_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_TIMER_PROTOS_H
#include <clib/timer_protos.h>
#endif /* CLIB_TIMER_PROTOS_H */

/* "Timer.Device" */
#pragma libcall TimerBase AddTime 2a 9802
#pragma libcall TimerBase SubTime 30 9802
#pragma libcall TimerBase CmpTime 36 9802
#pragma libcall TimerBase ReadEClock 3c 801
#pragma libcall TimerBase GetSysTime 42 801

#endif /* PRAGMAS_TIMER_PRAGMAS_H */
