#ifndef PRAGMA_GETSCREENMODE_LIB_H
#define PRAGMA_GETSCREENMODE_LIB_H

/*
**	$VER: getscreenmode_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_GETSCREENMODE_PROTOS_H
#include <clib/getscreenmode_protos.h>
#endif /* CLIB_GETSCREENMODE_PROTOS_H */

/* "getscreenmode.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(GetScreenModeBase, 0x1e, GETSCREENMODE_GetClass())

#endif /* PRAGMA_GETSCREENMODE_LIB_H */
