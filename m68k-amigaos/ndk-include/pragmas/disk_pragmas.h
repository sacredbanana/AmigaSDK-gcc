#ifndef PRAGMAS_DISK_PRAGMAS_H
#define PRAGMAS_DISK_PRAGMAS_H

/*
**	$VER: disk_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_DISK_PROTOS_H
#include <clib/disk_protos.h>
#endif /* CLIB_DISK_PROTOS_H */

/* "disk.resource" */
#pragma libcall DiskBase AllocUnit 6 001
#pragma libcall DiskBase FreeUnit c 001
#pragma libcall DiskBase GetUnit 12 901
#pragma libcall DiskBase GiveUnit 18 00
#pragma libcall DiskBase GetUnitID 1e 001
/*--- functions in V37 or higher (Release 2.04) ---*/
/*------ new for V37 ------*/
#pragma libcall DiskBase ReadUnitID 24 001

#endif /* PRAGMAS_DISK_PRAGMAS_H */
