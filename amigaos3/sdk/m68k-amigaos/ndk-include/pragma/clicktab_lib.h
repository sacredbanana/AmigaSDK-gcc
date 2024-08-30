#ifndef PRAGMA_CLICKTAB_LIB_H
#define PRAGMA_CLICKTAB_LIB_H

/*
**	$VER: clicktab_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_CLICKTAB_PROTOS_H
#include <clib/clicktab_protos.h>
#endif /* CLIB_CLICKTAB_PROTOS_H */

/* "clicktab.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(ClickTabBase, 0x1e, CLICKTAB_GetClass())
#pragma amicall(ClickTabBase, 0x24, AllocClickTabNodeA(a0))
#if defined(__STORM__)
#pragma tagcall(ClickTabBase, 0x24, AllocClickTabNode(a0))
#endif /* __STORM__ */
#pragma amicall(ClickTabBase, 0x2a, FreeClickTabNode(a0))
#pragma amicall(ClickTabBase, 0x30, SetClickTabNodeAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(ClickTabBase, 0x30, SetClickTabNodeAttrs(a0,a1))
#endif /* __STORM__ */
#pragma amicall(ClickTabBase, 0x36, GetClickTabNodeAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(ClickTabBase, 0x36, GetClickTabNodeAttrs(a0,a1))
#endif /* __STORM__ */

#endif /* PRAGMA_CLICKTAB_LIB_H */
