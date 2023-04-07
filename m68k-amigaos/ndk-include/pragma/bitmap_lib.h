#ifndef PRAGMA_BITMAP_LIB_H
#define PRAGMA_BITMAP_LIB_H

/*
**	$VER: bitmap_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_BITMAP_PROTOS_H
#include <clib/bitmap_protos.h>
#endif /* CLIB_BITMAP_PROTOS_H */

/* "bitmap.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(BitMapBase, 0x1e, BITMAP_GetClass())

#endif /* PRAGMA_BITMAP_LIB_H */
