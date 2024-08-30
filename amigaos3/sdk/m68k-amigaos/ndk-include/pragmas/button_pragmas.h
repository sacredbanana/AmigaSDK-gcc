#ifndef PRAGMAS_BUTTON_PRAGMAS_H
#define PRAGMAS_BUTTON_PRAGMAS_H

/*
**	$VER: button_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_BUTTON_PROTOS_H
#include <clib/button_protos.h>
#endif /* CLIB_BUTTON_PROTOS_H */

/* "button.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall ButtonBase BUTTON_GetClass 1e 00

#endif /* PRAGMAS_BUTTON_PRAGMAS_H */
