#ifndef PRAGMA_FUELGAUGE_LIB_H
#define PRAGMA_FUELGAUGE_LIB_H

/*
**	$VER: fuelgauge_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_FUELGAUGE_PROTOS_H
#include <clib/fuelgauge_protos.h>
#endif /* CLIB_FUELGAUGE_PROTOS_H */

/* "fuelgauge.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(FuelGaugeBase, 0x1e, FUELGAUGE_GetClass())

#endif /* PRAGMA_FUELGAUGE_LIB_H */
