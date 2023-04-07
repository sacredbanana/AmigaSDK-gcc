#ifndef PRAGMA_RAMDRIVE_LIB_H
#define PRAGMA_RAMDRIVE_LIB_H

/*
**	$VER: ramdrive_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_RAMDRIVE_PROTOS_H
#include <clib/ramdrive_protos.h>
#endif /* CLIB_RAMDRIVE_PROTOS_H */

/* "ramdrive.device" */
/*--- functions in V34 or higher (Release 1.3) ---*/
#pragma amicall(RamdriveDevice, 0x2a, KillRAD0())
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma amicall(RamdriveDevice, 0x30, KillRAD(d0))

#endif /* PRAGMA_RAMDRIVE_LIB_H */
