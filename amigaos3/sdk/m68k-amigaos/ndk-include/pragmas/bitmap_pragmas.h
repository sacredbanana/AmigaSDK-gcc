#ifndef PRAGMAS_BITMAP_PRAGMAS_H
#define PRAGMAS_BITMAP_PRAGMAS_H

/*
**	$VER: bitmap_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_BITMAP_PROTOS_H
#include <clib/bitmap_protos.h>
#endif /* CLIB_BITMAP_PROTOS_H */

/* "bitmap.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall BitMapBase BITMAP_GetClass 1e 00

#endif /* PRAGMAS_BITMAP_PRAGMAS_H */
