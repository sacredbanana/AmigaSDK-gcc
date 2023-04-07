#ifndef PRAGMA_SPACE_LIB_H
#define PRAGMA_SPACE_LIB_H

/*
**	$VER: space_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_SPACE_PROTOS_H
#include <clib/space_protos.h>
#endif /* CLIB_SPACE_PROTOS_H */

/* "space.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(SpaceBase, 0x1e, SPACE_GetClass())

#endif /* PRAGMA_SPACE_LIB_H */
