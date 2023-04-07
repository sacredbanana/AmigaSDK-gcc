#ifndef PRAGMA_SKETCHBOARD_LIB_H
#define PRAGMA_SKETCHBOARD_LIB_H

/*
**	$VER: sketchboard_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_SKETCHBOARD_PROTOS_H
#include <clib/sketchboard_protos.h>
#endif /* CLIB_SKETCHBOARD_PROTOS_H */

/* "sketchboard.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(SketchBoardBase, 0x1e, SKETCHBOARD_GetClass())

#endif /* PRAGMA_SKETCHBOARD_LIB_H */
