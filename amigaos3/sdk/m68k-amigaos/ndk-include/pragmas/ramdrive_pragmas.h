#ifndef PRAGMAS_RAMDRIVE_PRAGMAS_H
#define PRAGMAS_RAMDRIVE_PRAGMAS_H

/*
**	$VER: ramdrive_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_RAMDRIVE_PROTOS_H
#include <clib/ramdrive_protos.h>
#endif /* CLIB_RAMDRIVE_PROTOS_H */

/* "ramdrive.device" */
/*--- functions in V34 or higher (Release 1.3) ---*/
#pragma libcall RamdriveDevice KillRAD0 2a 00
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma libcall RamdriveDevice KillRAD 30 001

#endif /* PRAGMAS_RAMDRIVE_PRAGMAS_H */
