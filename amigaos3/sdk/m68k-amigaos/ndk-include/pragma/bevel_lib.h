#ifndef PRAGMA_BEVEL_LIB_H
#define PRAGMA_BEVEL_LIB_H

/*
**	$VER: bevel_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_BEVEL_PROTOS_H
#include <clib/bevel_protos.h>
#endif /* CLIB_BEVEL_PROTOS_H */

/* "bevel.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(BevelBase, 0x1e, BEVEL_GetClass())

#endif /* PRAGMA_BEVEL_LIB_H */
