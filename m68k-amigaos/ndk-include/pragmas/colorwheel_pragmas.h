#ifndef PRAGMAS_COLORWHEEL_PRAGMAS_H
#define PRAGMAS_COLORWHEEL_PRAGMAS_H

/*
**	$VER: colorwheel_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_COLORWHEEL_PROTOS_H
#include <clib/colorwheel_protos.h>
#endif /* CLIB_COLORWHEEL_PROTOS_H */

/* "colorwheel.gadget" */
/*--- functions in V39 or higher (Release 3.0) ---*/

/* Public entries */

#pragma libcall ColorWheelBase ConvertHSBToRGB 1e 9802
#pragma libcall ColorWheelBase ConvertRGBToHSB 24 9802

#endif /* PRAGMAS_COLORWHEEL_PRAGMAS_H */
