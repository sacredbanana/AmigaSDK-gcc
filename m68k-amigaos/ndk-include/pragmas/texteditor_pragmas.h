#ifndef PRAGMAS_TEXTEDITOR_PRAGMAS_H
#define PRAGMAS_TEXTEDITOR_PRAGMAS_H

/*
**	$VER: texteditor_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_TEXTEDITOR_PROTOS_H
#include <clib/texteditor_protos.h>
#endif /* CLIB_TEXTEDITOR_PROTOS_H */

/* "texteditor.gadget" */
/* NOTE: The library base name is "TextFieldBase" and not "TextEditorBase". */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall TextFieldBase TEXTEDITOR_GetClass 1e 00
/*--- functions in V47 or higher (Release 3.2) ---*/
#pragma libcall TextFieldBase HighlightSetFormat 24 210804

#endif /* PRAGMAS_TEXTEDITOR_PRAGMAS_H */
