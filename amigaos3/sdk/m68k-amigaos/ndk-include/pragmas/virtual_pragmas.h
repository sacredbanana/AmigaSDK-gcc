#ifndef PRAGMAS_VIRTUAL_PRAGMAS_H
#define PRAGMAS_VIRTUAL_PRAGMAS_H

/*
**	$VER: virtual_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_VIRTUAL_PROTOS_H
#include <clib/virtual_protos.h>
#endif /* CLIB_VIRTUAL_PROTOS_H */

/* "virtual.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall VirtualBase VIRTUAL_GetClass 1e 00
#pragma libcall VirtualBase RefreshVirtualGadget 24 BA9804
#pragma libcall VirtualBase RethinkVirtualSize 2a 0BA9805

#endif /* PRAGMAS_VIRTUAL_PRAGMAS_H */
