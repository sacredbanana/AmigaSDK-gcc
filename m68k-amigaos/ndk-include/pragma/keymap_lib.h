#ifndef PRAGMA_KEYMAP_LIB_H
#define PRAGMA_KEYMAP_LIB_H

/*
**	$VER: keymap_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_KEYMAP_PROTOS_H
#include <clib/keymap_protos.h>
#endif /* CLIB_KEYMAP_PROTOS_H */

/* "keymap.library" */
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma amicall(KeymapBase, 0x1e, SetKeyMapDefault(a0))
#pragma amicall(KeymapBase, 0x24, AskKeyMapDefault())
#pragma amicall(KeymapBase, 0x2a, MapRawKey(a0,a1,d1,a2))
#pragma amicall(KeymapBase, 0x30, MapANSI(a0,d0,a1,d1,a2))

#endif /* PRAGMA_KEYMAP_LIB_H */
