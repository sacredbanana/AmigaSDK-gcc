#ifndef PRAGMA_GLYPH_LIB_H
#define PRAGMA_GLYPH_LIB_H

/*
**	$VER: glyph_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_GLYPH_PROTOS_H
#include <clib/glyph_protos.h>
#endif /* CLIB_GLYPH_PROTOS_H */

/* "glyph.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(GlyphBase, 0x1e, GLYPH_GetClass())

#endif /* PRAGMA_GLYPH_LIB_H */
