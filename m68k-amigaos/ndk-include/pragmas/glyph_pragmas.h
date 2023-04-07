#ifndef PRAGMAS_GLYPH_PRAGMAS_H
#define PRAGMAS_GLYPH_PRAGMAS_H

/*
**	$VER: glyph_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_GLYPH_PROTOS_H
#include <clib/glyph_protos.h>
#endif /* CLIB_GLYPH_PROTOS_H */

/* "glyph.image" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall GlyphBase GLYPH_GetClass 1e 00

#endif /* PRAGMAS_GLYPH_PRAGMAS_H */
