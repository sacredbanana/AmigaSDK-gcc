#ifndef PRAGMAS_AREXX_PRAGMAS_H
#define PRAGMAS_AREXX_PRAGMAS_H

/*
**	$VER: arexx_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_AREXX_PROTOS_H
#include <clib/arexx_protos.h>
#endif /* CLIB_AREXX_PROTOS_H */

/* "arexx.class" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall ARexxBase AREXX_GetClass 1e 00

#endif /* PRAGMAS_AREXX_PRAGMAS_H */
