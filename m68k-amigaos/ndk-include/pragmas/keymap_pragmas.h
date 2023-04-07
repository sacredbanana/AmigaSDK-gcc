#ifndef PRAGMAS_KEYMAP_PRAGMAS_H
#define PRAGMAS_KEYMAP_PRAGMAS_H

/*
**	$VER: keymap_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_KEYMAP_PROTOS_H
#include <clib/keymap_protos.h>
#endif /* CLIB_KEYMAP_PROTOS_H */

/* "keymap.library" */
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma libcall KeymapBase SetKeyMapDefault 1e 801
#pragma libcall KeymapBase AskKeyMapDefault 24 00
#pragma libcall KeymapBase MapRawKey 2a A19804
#pragma libcall KeymapBase MapANSI 30 A190805

#endif /* PRAGMAS_KEYMAP_PRAGMAS_H */
