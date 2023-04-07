#ifndef PRAGMA_PENMAP_LIB_H
#define PRAGMA_PENMAP_LIB_H

/*
**	$VER: penmap_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_PENMAP_PROTOS_H
#include <clib/penmap_protos.h>
#endif /* CLIB_PENMAP_PROTOS_H */

/* "penmap.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(PenMapBase, 0x1e, PENMAP_GetClass())

#endif /* PRAGMA_PENMAP_LIB_H */
