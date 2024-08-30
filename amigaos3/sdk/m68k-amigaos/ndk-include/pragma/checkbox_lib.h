#ifndef PRAGMA_CHECKBOX_LIB_H
#define PRAGMA_CHECKBOX_LIB_H

/*
**	$VER: checkbox_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_CHECKBOX_PROTOS_H
#include <clib/checkbox_protos.h>
#endif /* CLIB_CHECKBOX_PROTOS_H */

/* "checkbox.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(CheckBoxBase, 0x1e, CHECKBOX_GetClass())

#endif /* PRAGMA_CHECKBOX_LIB_H */
