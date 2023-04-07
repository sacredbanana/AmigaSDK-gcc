#ifndef PRAGMAS_MISC_PRAGMAS_H
#define PRAGMAS_MISC_PRAGMAS_H

/*
**	$VER: misc_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_MISC_PROTOS_H
#include <clib/misc_protos.h>
#endif /* CLIB_MISC_PROTOS_H */

#pragma libcall MiscBase AllocMiscResource 6 9002
#pragma libcall MiscBase FreeMiscResource c 001

#endif /* PRAGMAS_MISC_PRAGMAS_H */
