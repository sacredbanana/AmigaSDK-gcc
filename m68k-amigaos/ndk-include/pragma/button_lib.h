#ifndef PRAGMA_BUTTON_LIB_H
#define PRAGMA_BUTTON_LIB_H

/*
**	$VER: button_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_BUTTON_PROTOS_H
#include <clib/button_protos.h>
#endif /* CLIB_BUTTON_PROTOS_H */

/* "button.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(ButtonBase, 0x1e, BUTTON_GetClass())

#endif /* PRAGMA_BUTTON_LIB_H */
