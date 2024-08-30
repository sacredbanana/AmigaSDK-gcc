#ifndef PRAGMA_SLIDER_LIB_H
#define PRAGMA_SLIDER_LIB_H

/*
**	$VER: slider_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_SLIDER_PROTOS_H
#include <clib/slider_protos.h>
#endif /* CLIB_SLIDER_PROTOS_H */

/* "slider.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(SliderBase, 0x1e, SLIDER_GetClass())

#endif /* PRAGMA_SLIDER_LIB_H */
