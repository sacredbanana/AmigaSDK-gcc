#ifndef PRAGMAS_LAYOUT_PRAGMAS_H
#define PRAGMAS_LAYOUT_PRAGMAS_H

/*
**	$VER: layout_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_LAYOUT_PROTOS_H
#include <clib/layout_protos.h>
#endif /* CLIB_LAYOUT_PROTOS_H */

/* "layout.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall LayoutBase LAYOUT_GetClass 1e 00
#pragma libcall LayoutBase ActivateLayoutGadget 24 0A9804
#pragma libcall LayoutBase FlushLayoutDomainCache 2a 801
#pragma libcall LayoutBase RethinkLayout 30 0A9804
#pragma libcall LayoutBase LayoutLimits 36 BA9804
#pragma libcall LayoutBase PAGE_GetClass 3c 00
#pragma libcall LayoutBase SetPageGadgetAttrsA 42 CBA9805
#if defined(__SASC_60)
#pragma tagcall LayoutBase SetPageGadgetAttrs 42 CBA9805
#endif /* __SASC_60 */
#pragma libcall LayoutBase RefreshPageGadget 48 BA9804

#endif /* PRAGMAS_LAYOUT_PRAGMAS_H */
