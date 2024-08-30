#ifndef PRAGMA_GETFONT_LIB_H
#define PRAGMA_GETFONT_LIB_H

/*
**	$VER: getfont_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_GETFONT_PROTOS_H
#include <clib/getfont_protos.h>
#endif /* CLIB_GETFONT_PROTOS_H */

/* "getfont.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(GetFontBase, 0x1e, GETFONT_GetClass())

#endif /* PRAGMA_GETFONT_LIB_H */
