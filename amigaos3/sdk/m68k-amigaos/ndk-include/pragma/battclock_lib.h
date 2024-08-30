#ifndef PRAGMA_BATTCLOCK_LIB_H
#define PRAGMA_BATTCLOCK_LIB_H

/*
**	$VER: battclock_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_BATTCLOCK_PROTOS_H
#include <clib/battclock_protos.h>
#endif /* CLIB_BATTCLOCK_PROTOS_H */

/* "battclock.resource" */
#pragma amicall(BattClockBase, 0x6, ResetBattClock())
#pragma amicall(BattClockBase, 0xc, ReadBattClock())
#pragma amicall(BattClockBase, 0x12, WriteBattClock(d0))

#endif /* PRAGMA_BATTCLOCK_LIB_H */
