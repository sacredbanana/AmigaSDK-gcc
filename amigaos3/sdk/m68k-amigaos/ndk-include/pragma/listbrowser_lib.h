#ifndef PRAGMA_LISTBROWSER_LIB_H
#define PRAGMA_LISTBROWSER_LIB_H

/*
**	$VER: listbrowser_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_LISTBROWSER_PROTOS_H
#include <clib/listbrowser_protos.h>
#endif /* CLIB_LISTBROWSER_PROTOS_H */

/* "listbrowser.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(ListBrowserBase, 0x1e, LISTBROWSER_GetClass())
#pragma amicall(ListBrowserBase, 0x24, AllocListBrowserNodeA(d0,a0))
#if defined(__STORM__)
#pragma tagcall(ListBrowserBase, 0x24, AllocListBrowserNode(d0,a0))
#endif /* __STORM__ */
#pragma amicall(ListBrowserBase, 0x2a, FreeListBrowserNode(a0))
#pragma amicall(ListBrowserBase, 0x30, SetListBrowserNodeAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(ListBrowserBase, 0x30, SetListBrowserNodeAttrs(a0,a1))
#endif /* __STORM__ */
#pragma amicall(ListBrowserBase, 0x36, GetListBrowserNodeAttrsA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(ListBrowserBase, 0x36, GetListBrowserNodeAttrs(a0,a1))
#endif /* __STORM__ */
#pragma amicall(ListBrowserBase, 0x3c, ListBrowserSelectAll(a0))
#pragma amicall(ListBrowserBase, 0x42, ShowListBrowserNodeChildren(a0,d0))
#pragma amicall(ListBrowserBase, 0x48, HideListBrowserNodeChildren(a0))
#pragma amicall(ListBrowserBase, 0x4e, ShowAllListBrowserChildren(a0))
#pragma amicall(ListBrowserBase, 0x54, HideAllListBrowserChildren(a0))
#pragma amicall(ListBrowserBase, 0x5a, FreeListBrowserList(a0))
/*--- functions in V45 or higher (Release 3.9) ---*/
#pragma amicall(ListBrowserBase, 0x60, AllocLBColumnInfoA(d0,a0))
#if defined(__STORM__)
#pragma tagcall(ListBrowserBase, 0x60, AllocLBColumnInfo(d0,a0))
#endif /* __STORM__ */
#pragma amicall(ListBrowserBase, 0x66, SetLBColumnInfoAttrsA(a1,a0))
#if defined(__STORM__)
#pragma tagcall(ListBrowserBase, 0x66, SetLBColumnInfoAttrs(a1,a0))
#endif /* __STORM__ */
#pragma amicall(ListBrowserBase, 0x6c, GetLBColumnInfoAttrsA(a1,a0))
#if defined(__STORM__)
#pragma tagcall(ListBrowserBase, 0x6c, GetLBColumnInfoAttrs(a1,a0))
#endif /* __STORM__ */
#pragma amicall(ListBrowserBase, 0x72, FreeLBColumnInfo(a0))
#pragma amicall(ListBrowserBase, 0x78, ListBrowserClearAll(a0))

#endif /* PRAGMA_LISTBROWSER_LIB_H */
