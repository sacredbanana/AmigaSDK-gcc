#ifndef PRAGMAS_GETFONT_PRAGMAS_H
#define PRAGMAS_GETFONT_PRAGMAS_H

/*
**	$VER: getfont_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_GETFONT_PROTOS_H
#include <clib/getfont_protos.h>
#endif /* CLIB_GETFONT_PROTOS_H */

/* "getfont.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall GetFontBase GETFONT_GetClass 1e 00

#endif /* PRAGMAS_GETFONT_PRAGMAS_H */
