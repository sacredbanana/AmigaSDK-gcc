#ifndef PRAGMA_PALETTE_LIB_H
#define PRAGMA_PALETTE_LIB_H

/*
**	$VER: palette_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_PALETTE_PROTOS_H
#include <clib/palette_protos.h>
#endif /* CLIB_PALETTE_PROTOS_H */

/* "palette.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(PaletteBase, 0x1e, PALETTE_GetClass())

#endif /* PRAGMA_PALETTE_LIB_H */
