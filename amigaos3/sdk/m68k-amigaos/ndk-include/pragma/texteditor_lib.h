#ifndef PRAGMA_TEXTEDITOR_LIB_H
#define PRAGMA_TEXTEDITOR_LIB_H

/*
**	$VER: texteditor_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_TEXTEDITOR_PROTOS_H
#include <clib/texteditor_protos.h>
#endif /* CLIB_TEXTEDITOR_PROTOS_H */

/* "texteditor.gadget" */
/* NOTE: The library base name is "TextFieldBase" and not "TextEditorBase". */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(TextFieldBase, 0x1e, TEXTEDITOR_GetClass())
/*--- functions in V47 or higher (Release 3.2) ---*/
#pragma amicall(TextFieldBase, 0x24, HighlightSetFormat(a0,d0,d1,d2))

#endif /* PRAGMA_TEXTEDITOR_LIB_H */
