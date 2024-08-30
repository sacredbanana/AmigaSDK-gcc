#ifndef PRAGMA_AREXX_LIB_H
#define PRAGMA_AREXX_LIB_H

/*
**	$VER: arexx_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_AREXX_PROTOS_H
#include <clib/arexx_protos.h>
#endif /* CLIB_AREXX_PROTOS_H */

/* "arexx.class" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(ARexxBase, 0x1e, AREXX_GetClass())

#endif /* PRAGMA_AREXX_LIB_H */
