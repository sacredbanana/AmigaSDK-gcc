#ifndef PRAGMAS_BATTCLOCK_PRAGMAS_H
#define PRAGMAS_BATTCLOCK_PRAGMAS_H

/*
**	$VER: battclock_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_BATTCLOCK_PROTOS_H
#include <clib/battclock_protos.h>
#endif /* CLIB_BATTCLOCK_PROTOS_H */

/* "battclock.resource" */
#pragma libcall BattClockBase ResetBattClock 6 00
#pragma libcall BattClockBase ReadBattClock c 00
#pragma libcall BattClockBase WriteBattClock 12 001

#endif /* PRAGMAS_BATTCLOCK_PRAGMAS_H */
