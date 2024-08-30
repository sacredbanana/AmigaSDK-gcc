#ifndef PRAGMAS_SPACE_PRAGMAS_H
#define PRAGMAS_SPACE_PRAGMAS_H

/*
**	$VER: space_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_SPACE_PROTOS_H
#include <clib/space_protos.h>
#endif /* CLIB_SPACE_PROTOS_H */

/* "space.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall SpaceBase SPACE_GetClass 1e 00

#endif /* PRAGMAS_SPACE_PRAGMAS_H */
