#ifndef PRAGMA_DISK_LIB_H
#define PRAGMA_DISK_LIB_H

/*
**	$VER: disk_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_DISK_PROTOS_H
#include <clib/disk_protos.h>
#endif /* CLIB_DISK_PROTOS_H */

/* "disk.resource" */
#pragma amicall(DiskBase, 0x6, AllocUnit(d0))
#pragma amicall(DiskBase, 0xc, FreeUnit(d0))
#pragma amicall(DiskBase, 0x12, GetUnit(a1))
#pragma amicall(DiskBase, 0x18, GiveUnit())
#pragma amicall(DiskBase, 0x1e, GetUnitID(d0))
/*--- functions in V37 or higher (Release 2.04) ---*/
/*------ new for V37 ------*/
#pragma amicall(DiskBase, 0x24, ReadUnitID(d0))

#endif /* PRAGMA_DISK_LIB_H */
