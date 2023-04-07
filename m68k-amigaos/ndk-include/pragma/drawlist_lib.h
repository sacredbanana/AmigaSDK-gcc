#ifndef PRAGMA_DRAWLIST_LIB_H
#define PRAGMA_DRAWLIST_LIB_H

/*
**	$VER: drawlist_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_DRAWLIST_PROTOS_H
#include <clib/drawlist_protos.h>
#endif /* CLIB_DRAWLIST_PROTOS_H */

/* "drawlist.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(DrawListBase, 0x1e, DRAWLIST_GetClass())

#endif /* PRAGMA_DRAWLIST_LIB_H */
