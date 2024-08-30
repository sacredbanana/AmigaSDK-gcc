#ifndef PRAGMA_WINDOW_LIB_H
#define PRAGMA_WINDOW_LIB_H

/*
**	$VER: window_lib.h 47.2 (4.12.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_WINDOW_PROTOS_H
#include <clib/window_protos.h>
#endif /* CLIB_WINDOW_PROTOS_H */

/* "window.class" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(WindowBase, 0x1e, WINDOW_GetClass())

#endif /* PRAGMA_WINDOW_LIB_H */
