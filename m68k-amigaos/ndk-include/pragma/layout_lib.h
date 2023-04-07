#ifndef PRAGMA_LAYOUT_LIB_H
#define PRAGMA_LAYOUT_LIB_H

/*
**	$VER: layout_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_LAYOUT_PROTOS_H
#include <clib/layout_protos.h>
#endif /* CLIB_LAYOUT_PROTOS_H */

/* "layout.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(LayoutBase, 0x1e, LAYOUT_GetClass())
#pragma amicall(LayoutBase, 0x24, ActivateLayoutGadget(a0,a1,a2,d0))
#pragma amicall(LayoutBase, 0x2a, FlushLayoutDomainCache(a0))
#pragma amicall(LayoutBase, 0x30, RethinkLayout(a0,a1,a2,d0))
#pragma amicall(LayoutBase, 0x36, LayoutLimits(a0,a1,a2,a3))
#pragma amicall(LayoutBase, 0x3c, PAGE_GetClass())
#pragma amicall(LayoutBase, 0x42, SetPageGadgetAttrsA(a0,a1,a2,a3,a4))
#if defined(__STORM__)
#pragma tagcall(LayoutBase, 0x42, SetPageGadgetAttrs(a0,a1,a2,a3,a4))
#endif /* __STORM__ */
#pragma amicall(LayoutBase, 0x48, RefreshPageGadget(a0,a1,a2,a3))

#endif /* PRAGMA_LAYOUT_LIB_H */
