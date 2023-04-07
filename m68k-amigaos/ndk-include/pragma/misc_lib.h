#ifndef PRAGMA_MISC_LIB_H
#define PRAGMA_MISC_LIB_H

/*
**	$VER: misc_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_MISC_PROTOS_H
#include <clib/misc_protos.h>
#endif /* CLIB_MISC_PROTOS_H */

#pragma amicall(MiscBase, 0x6, AllocMiscResource(d0,a1))
#pragma amicall(MiscBase, 0xc, FreeMiscResource(d0))

#endif /* PRAGMA_MISC_LIB_H */
