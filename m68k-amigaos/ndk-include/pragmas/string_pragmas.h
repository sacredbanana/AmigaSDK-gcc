#ifndef PRAGMAS_STRING_PRAGMAS_H
#define PRAGMAS_STRING_PRAGMAS_H

/*
**	$VER: string_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_STRING_PROTOS_H
#include <clib/string_protos.h>
#endif /* CLIB_STRING_PROTOS_H */

/* "string.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall StringBase STRING_GetClass 1e 00

#endif /* PRAGMAS_STRING_PRAGMAS_H */
