#ifndef PRAGMAS_GADTOOLS_PRAGMAS_H
#define PRAGMAS_GADTOOLS_PRAGMAS_H

/*
**	$VER: gadtools_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_GADTOOLS_PROTOS_H
#include <clib/gadtools_protos.h>
#endif /* CLIB_GADTOOLS_PROTOS_H */

/* "gadtools.library" */

/*--- functions in V36 or higher (Release 2.0) ---*/

/* Gadget Functions */

#pragma libcall GadToolsBase CreateGadgetA 1e A98004
#if defined(__SASC_60)
#pragma tagcall GadToolsBase CreateGadget 1e A98004
#endif /* __SASC_60 */
#pragma libcall GadToolsBase FreeGadgets 24 801
#pragma libcall GadToolsBase GT_SetGadgetAttrsA 2a BA9804
#if defined(__SASC_60)
#pragma tagcall GadToolsBase GT_SetGadgetAttrs 2a BA9804
#endif /* __SASC_60 */

/* Menu functions */

#pragma libcall GadToolsBase CreateMenusA 30 9802
#if defined(__SASC_60)
#pragma tagcall GadToolsBase CreateMenus 30 9802
#endif /* __SASC_60 */
#pragma libcall GadToolsBase FreeMenus 36 801
#pragma libcall GadToolsBase LayoutMenuItemsA 3c A9803
#if defined(__SASC_60)
#pragma tagcall GadToolsBase LayoutMenuItems 3c A9803
#endif /* __SASC_60 */
#pragma libcall GadToolsBase LayoutMenusA 42 A9803
#if defined(__SASC_60)
#pragma tagcall GadToolsBase LayoutMenus 42 A9803
#endif /* __SASC_60 */

/* Misc Event-Handling Functions */

#pragma libcall GadToolsBase GT_GetIMsg 48 801
#pragma libcall GadToolsBase GT_ReplyIMsg 4e 901
#pragma libcall GadToolsBase GT_RefreshWindow 54 9802
#pragma libcall GadToolsBase GT_BeginRefresh 5a 801
#pragma libcall GadToolsBase GT_EndRefresh 60 0802
#pragma libcall GadToolsBase GT_FilterIMsg 66 901
#pragma libcall GadToolsBase GT_PostFilterIMsg 6c 901
#pragma libcall GadToolsBase CreateContext 72 801

/* Rendering Functions */

#pragma libcall GadToolsBase DrawBevelBoxA 78 93210806
#if defined(__SASC_60)
#pragma tagcall GadToolsBase DrawBevelBox 78 93210806
#endif /* __SASC_60 */

/* Visuals Functions */

#pragma libcall GadToolsBase GetVisualInfoA 7e 9802
#if defined(__SASC_60)
#pragma tagcall GadToolsBase GetVisualInfo 7e 9802
#endif /* __SASC_60 */
#pragma libcall GadToolsBase FreeVisualInfo 84 801

/* New in V47 */

/*--- functions in V47 or higher (Release 3.2) ---*/
#pragma libcall GadToolsBase SetDesignFontA 8a A9803
#if defined(__SASC_60)
#pragma tagcall GadToolsBase SetDesignFont 8a A9803
#endif /* __SASC_60 */
#pragma libcall GadToolsBase ScaleGadgetRectA 90 9802
#if defined(__SASC_60)
#pragma tagcall GadToolsBase ScaleGadgetRect 90 9802
#endif /* __SASC_60 */


/* Reserved entries */


/*--- functions in V39 or higher (Release 3.0) ---*/

#pragma libcall GadToolsBase GT_GetGadgetAttrsA ae BA9804
#if defined(__SASC_60)
#pragma tagcall GadToolsBase GT_GetGadgetAttrs ae BA9804
#endif /* __SASC_60 */


#endif /* PRAGMAS_GADTOOLS_PRAGMAS_H */
