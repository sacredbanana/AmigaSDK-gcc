#ifndef PRAGMAS_PENMAP_PRAGMAS_H
#define PRAGMAS_PENMAP_PRAGMAS_H

/*
**	$VER: penmap_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_PENMAP_PROTOS_H
#include <clib/penmap_protos.h>
#endif /* CLIB_PENMAP_PROTOS_H */

/* "penmap.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall PenMapBase PENMAP_GetClass 1e 00

#endif /* PRAGMAS_PENMAP_PRAGMAS_H */
