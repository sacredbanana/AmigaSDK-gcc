#ifndef PRAGMAS_REQUESTER_PRAGMAS_H
#define PRAGMAS_REQUESTER_PRAGMAS_H

/*
**	$VER: requester_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_REQUESTER_PROTOS_H
#include <clib/requester_protos.h>
#endif /* CLIB_REQUESTER_PROTOS_H */

/* "requester.class" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall RequesterBase REQUESTER_GetClass 1e 00

#endif /* PRAGMAS_REQUESTER_PRAGMAS_H */
