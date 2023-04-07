#ifndef PRAGMA_GADTOOLS_LIB_H
#define PRAGMA_GADTOOLS_LIB_H

/*
**	$VER: gadtools_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_GADTOOLS_PROTOS_H
#include <clib/gadtools_protos.h>
#endif /* CLIB_GADTOOLS_PROTOS_H */

/* "gadtools.library" */

/*--- functions in V36 or higher (Release 2.0) ---*/

/* Gadget Functions */

#pragma amicall(GadToolsBase, 0x1e, CreateGadgetA(d0,a0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(GadToolsBase, 0x1e, CreateGadget(d0,a0,a1,a2))
#endif /* __STORM__ */
#pragma amicall(GadToolsBase, 0x24, FreeGadgets(a0))
#pragma amicall(GadToolsBase, 0x2a, GT_SetGadgetAttrsA(a0,a1,a2,a3))
#if defined(__STORM__)
#pragma tagcall(GadToolsBase, 0x2a, GT_SetGadgetAttrs(a0,a1,a2,a3))
#endif /* __STORM__ */

/* Menu functions */

#pragma amicall(GadToolsBase, 0x30, CreateMenusA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(GadToolsBase, 0x30, CreateMenus(a0,a1))
#endif /* __STORM__ */
#pragma amicall(GadToolsBase, 0x36, FreeMenus(a0))
#pragma amicall(GadToolsBase, 0x3c, LayoutMenuItemsA(a0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(GadToolsBase, 0x3c, LayoutMenuItems(a0,a1,a2))
#endif /* __STORM__ */
#pragma amicall(GadToolsBase, 0x42, LayoutMenusA(a0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(GadToolsBase, 0x42, LayoutMenus(a0,a1,a2))
#endif /* __STORM__ */

/* Misc Event-Handling Functions */

#pragma amicall(GadToolsBase, 0x48, GT_GetIMsg(a0))
#pragma amicall(GadToolsBase, 0x4e, GT_ReplyIMsg(a1))
#pragma amicall(GadToolsBase, 0x54, GT_RefreshWindow(a0,a1))
#pragma amicall(GadToolsBase, 0x5a, GT_BeginRefresh(a0))
#pragma amicall(GadToolsBase, 0x60, GT_EndRefresh(a0,d0))
#pragma amicall(GadToolsBase, 0x66, GT_FilterIMsg(a1))
#pragma amicall(GadToolsBase, 0x6c, GT_PostFilterIMsg(a1))
#pragma amicall(GadToolsBase, 0x72, CreateContext(a0))

/* Rendering Functions */

#pragma amicall(GadToolsBase, 0x78, DrawBevelBoxA(a0,d0,d1,d2,d3,a1))
#if defined(__STORM__)
#pragma tagcall(GadToolsBase, 0x78, DrawBevelBox(a0,d0,d1,d2,d3,a1))
#endif /* __STORM__ */

/* Visuals Functions */

#pragma amicall(GadToolsBase, 0x7e, GetVisualInfoA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(GadToolsBase, 0x7e, GetVisualInfo(a0,a1))
#endif /* __STORM__ */
#pragma amicall(GadToolsBase, 0x84, FreeVisualInfo(a0))

/* New in V47 */

/*--- functions in V47 or higher (Release 3.2) ---*/
#pragma amicall(GadToolsBase, 0x8a, SetDesignFontA(a0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(GadToolsBase, 0x8a, SetDesignFont(a0,a1,a2))
#endif /* __STORM__ */
#pragma amicall(GadToolsBase, 0x90, ScaleGadgetRectA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(GadToolsBase, 0x90, ScaleGadgetRect(a0,a1))
#endif /* __STORM__ */


/* Reserved entries */


/*--- functions in V39 or higher (Release 3.0) ---*/

#pragma amicall(GadToolsBase, 0xae, GT_GetGadgetAttrsA(a0,a1,a2,a3))
#if defined(__STORM__)
#pragma tagcall(GadToolsBase, 0xae, GT_GetGadgetAttrs(a0,a1,a2,a3))
#endif /* __STORM__ */


#endif /* PRAGMA_GADTOOLS_LIB_H */
