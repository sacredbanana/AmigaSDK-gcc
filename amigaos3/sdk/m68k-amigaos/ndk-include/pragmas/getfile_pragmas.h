#ifndef PRAGMAS_GETFILE_PRAGMAS_H
#define PRAGMAS_GETFILE_PRAGMAS_H

/*
**	$VER: getfile_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_GETFILE_PROTOS_H
#include <clib/getfile_protos.h>
#endif /* CLIB_GETFILE_PROTOS_H */

/* "getfile.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall GetFileBase GETFILE_GetClass 1e 00

#endif /* PRAGMAS_GETFILE_PRAGMAS_H */
