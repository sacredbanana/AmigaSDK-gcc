#ifndef PRAGMAS_CLICKTAB_PRAGMAS_H
#define PRAGMAS_CLICKTAB_PRAGMAS_H

/*
**	$VER: clicktab_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_CLICKTAB_PROTOS_H
#include <clib/clicktab_protos.h>
#endif /* CLIB_CLICKTAB_PROTOS_H */

/* "clicktab.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall ClickTabBase CLICKTAB_GetClass 1e 00
#pragma libcall ClickTabBase AllocClickTabNodeA 24 801
#if defined(__SASC_60)
#pragma tagcall ClickTabBase AllocClickTabNode 24 801
#endif /* __SASC_60 */
#pragma libcall ClickTabBase FreeClickTabNode 2a 801
#pragma libcall ClickTabBase SetClickTabNodeAttrsA 30 9802
#if defined(__SASC_60)
#pragma tagcall ClickTabBase SetClickTabNodeAttrs 30 9802
#endif /* __SASC_60 */
#pragma libcall ClickTabBase GetClickTabNodeAttrsA 36 9802
#if defined(__SASC_60)
#pragma tagcall ClickTabBase GetClickTabNodeAttrs 36 9802
#endif /* __SASC_60 */

#endif /* PRAGMAS_CLICKTAB_PRAGMAS_H */
