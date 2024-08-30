#ifndef PRAGMA_VIRTUAL_LIB_H
#define PRAGMA_VIRTUAL_LIB_H

/*
**	$VER: virtual_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_VIRTUAL_PROTOS_H
#include <clib/virtual_protos.h>
#endif /* CLIB_VIRTUAL_PROTOS_H */

/* "virtual.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(VirtualBase, 0x1e, VIRTUAL_GetClass())
#pragma amicall(VirtualBase, 0x24, RefreshVirtualGadget(a0,a1,a2,a3))
#pragma amicall(VirtualBase, 0x2a, RethinkVirtualSize(a0,a1,a2,a3,d0))

#endif /* PRAGMA_VIRTUAL_LIB_H */
