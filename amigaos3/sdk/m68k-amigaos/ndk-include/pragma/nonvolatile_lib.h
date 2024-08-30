#ifndef PRAGMA_NONVOLATILE_LIB_H
#define PRAGMA_NONVOLATILE_LIB_H

/*
**	$VER: nonvolatile_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_NONVOLATILE_PROTOS_H
#include <clib/nonvolatile_protos.h>
#endif /* CLIB_NONVOLATILE_PROTOS_H */

/* "nonvolatile.library" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(NVBase, 0x1e, GetCopyNV(a0,a1,d1))
#pragma amicall(NVBase, 0x24, FreeNVData(a0))
#pragma amicall(NVBase, 0x2a, StoreNV(a0,a1,a2,d0,d1))
#pragma amicall(NVBase, 0x30, DeleteNV(a0,a1,d1))
#pragma amicall(NVBase, 0x36, GetNVInfo(d1))
#pragma amicall(NVBase, 0x3c, GetNVList(a0,d1))
#pragma amicall(NVBase, 0x42, SetNVProtection(a0,a1,d2,d1))

#endif /* PRAGMA_NONVOLATILE_LIB_H */
