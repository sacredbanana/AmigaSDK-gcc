#ifndef PRAGMA_SCROLLER_LIB_H
#define PRAGMA_SCROLLER_LIB_H

/*
**	$VER: scroller_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_SCROLLER_PROTOS_H
#include <clib/scroller_protos.h>
#endif /* CLIB_SCROLLER_PROTOS_H */

/* "scroller.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(ScrollerBase, 0x1e, SCROLLER_GetClass())

#endif /* PRAGMA_SCROLLER_LIB_H */
