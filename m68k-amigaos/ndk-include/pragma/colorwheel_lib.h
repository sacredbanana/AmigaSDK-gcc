#ifndef PRAGMA_COLORWHEEL_LIB_H
#define PRAGMA_COLORWHEEL_LIB_H

/*
**	$VER: colorwheel_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_COLORWHEEL_PROTOS_H
#include <clib/colorwheel_protos.h>
#endif /* CLIB_COLORWHEEL_PROTOS_H */

/* "colorwheel.gadget" */
/*--- functions in V39 or higher (Release 3.0) ---*/

/* Public entries */

#pragma amicall(ColorWheelBase, 0x1e, ConvertHSBToRGB(a0,a1))
#pragma amicall(ColorWheelBase, 0x24, ConvertRGBToHSB(a0,a1))

#endif /* PRAGMA_COLORWHEEL_LIB_H */
