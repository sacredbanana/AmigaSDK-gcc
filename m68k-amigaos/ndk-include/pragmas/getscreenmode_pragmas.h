#ifndef PRAGMAS_GETSCREENMODE_PRAGMAS_H
#define PRAGMAS_GETSCREENMODE_PRAGMAS_H

/*
**	$VER: getscreenmode_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_GETSCREENMODE_PROTOS_H
#include <clib/getscreenmode_protos.h>
#endif /* CLIB_GETSCREENMODE_PROTOS_H */

/* "getscreenmode.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall GetScreenModeBase GETSCREENMODE_GetClass 1e 00

#endif /* PRAGMAS_GETSCREENMODE_PRAGMAS_H */
