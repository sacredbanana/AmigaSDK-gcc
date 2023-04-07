#ifndef PRAGMA_CHOOSER_LIB_H
#define PRAGMA_CHOOSER_LIB_H

/*
**	$VER: chooser_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_CHOOSER_PROTOS_H
#include <clib/chooser_protos.h>
#endif /* CLIB_CHOOSER_PROTOS_H */

/* "chooser.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(ChooserBase, 0x1e, CHOOSER_GetClass())
#pragma amicall(ChooserBase, 0x24, AllocChooserNodeA(a0))
#if defined(__STORM__)
#pragma tagcall(ChooserBase, 0x24, AllocChooserNode(a0))
#endif /* __STORM__ */
#pragma amicall(ChooserBase, 0x2a, FreeChooserNode(a0))
#pragma amicall(ChooserBase, 0x30, SetChooserNodeAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(ChooserBase, 0x30, SetChooserNodeAttrs(a0,a1))
#endif /* __STORM__ */
#pragma amicall(ChooserBase, 0x36, GetChooserNodeAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(ChooserBase, 0x36, GetChooserNodeAttrs(a0,a1))
#endif /* __STORM__ */
#pragma amicall(ChooserBase, 0x3c, ShowChooser(a0,a1,d0,d1))
#pragma amicall(ChooserBase, 0x42, HideChooser(a0,a1))

#endif /* PRAGMA_CHOOSER_LIB_H */
