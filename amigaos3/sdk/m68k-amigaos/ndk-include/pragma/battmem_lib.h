#ifndef PRAGMA_BATTMEM_LIB_H
#define PRAGMA_BATTMEM_LIB_H

/*
**	$VER: battmem_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_BATTMEM_PROTOS_H
#include <clib/battmem_protos.h>
#endif /* CLIB_BATTMEM_PROTOS_H */

/* "battmem.resource" */
#pragma amicall(BattMemBase, 0x6, ObtainBattSemaphore())
#pragma amicall(BattMemBase, 0xc, ReleaseBattSemaphore())
#pragma amicall(BattMemBase, 0x12, ReadBattMem(a0,d0,d1))
#pragma amicall(BattMemBase, 0x18, WriteBattMem(a0,d0,d1))

#endif /* PRAGMA_BATTMEM_LIB_H */
