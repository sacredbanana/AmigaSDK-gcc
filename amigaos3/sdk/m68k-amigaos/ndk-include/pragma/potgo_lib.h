#ifndef PRAGMA_POTGO_LIB_H
#define PRAGMA_POTGO_LIB_H

/*
**	$VER: potgo_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_POTGO_PROTOS_H
#include <clib/potgo_protos.h>
#endif /* CLIB_POTGO_PROTOS_H */

/* "potgo.resource" */
#pragma amicall(PotgoBase, 0x6, AllocPotBits(d0))
#pragma amicall(PotgoBase, 0xc, FreePotBits(d0))
#pragma amicall(PotgoBase, 0x12, WritePotgo(d0,d1))

#endif /* PRAGMA_POTGO_LIB_H */
