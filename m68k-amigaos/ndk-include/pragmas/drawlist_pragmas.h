#ifndef PRAGMAS_DRAWLIST_PRAGMAS_H
#define PRAGMAS_DRAWLIST_PRAGMAS_H

/*
**	$VER: drawlist_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_DRAWLIST_PROTOS_H
#include <clib/drawlist_protos.h>
#endif /* CLIB_DRAWLIST_PROTOS_H */

/* "drawlist.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall DrawListBase DRAWLIST_GetClass 1e 00

#endif /* PRAGMAS_DRAWLIST_PRAGMAS_H */
