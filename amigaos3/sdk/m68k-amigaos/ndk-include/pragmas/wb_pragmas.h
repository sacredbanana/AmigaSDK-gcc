#ifndef PRAGMAS_WB_PRAGMAS_H
#define PRAGMAS_WB_PRAGMAS_H

/*
**	$VER: wb_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_WB_PROTOS_H
#include <clib/wb_protos.h>
#endif /* CLIB_WB_PROTOS_H */

/* "workbench.library" */
/*--- functions in V36 or higher (Release 2.0) ---*/


#pragma libcall WorkbenchBase UpdateWorkbench 1e 09803



#pragma libcall WorkbenchBase AddAppWindowA 30 A981005
#if defined(__SASC_60)
#pragma tagcall WorkbenchBase AddAppWindow 30 A981005
#endif /* __SASC_60 */

#pragma libcall WorkbenchBase RemoveAppWindow 36 801

#pragma libcall WorkbenchBase AddAppIconA 3c CBA981007
#if defined(__SASC_60)
#pragma tagcall WorkbenchBase AddAppIcon 3c CBA981007
#endif /* __SASC_60 */

#pragma libcall WorkbenchBase RemoveAppIcon 42 801

#pragma libcall WorkbenchBase AddAppMenuItemA 48 A981005
#if defined(__SASC_60)
#pragma tagcall WorkbenchBase AddAppMenuItem 48 A981005
#endif /* __SASC_60 */

#pragma libcall WorkbenchBase RemoveAppMenuItem 4e 801

/*--- functions in V39 or higher (Release 3.0) ---*/


#pragma libcall WorkbenchBase WBInfo 5a A9803

/*--- functions in V44 or higher (Release 3.5) ---*/
#pragma libcall WorkbenchBase OpenWorkbenchObjectA 60 9802
#if defined(__SASC_60)
#pragma tagcall WorkbenchBase OpenWorkbenchObject 60 9802
#endif /* __SASC_60 */
#pragma libcall WorkbenchBase CloseWorkbenchObjectA 66 9802
#if defined(__SASC_60)
#pragma tagcall WorkbenchBase CloseWorkbenchObject 66 9802
#endif /* __SASC_60 */
#pragma libcall WorkbenchBase WorkbenchControlA 6c 9802
#if defined(__SASC_60)
#pragma tagcall WorkbenchBase WorkbenchControl 6c 9802
#endif /* __SASC_60 */
#pragma libcall WorkbenchBase AddAppWindowDropZoneA 72 910804
#if defined(__SASC_60)
#pragma tagcall WorkbenchBase AddAppWindowDropZone 72 910804
#endif /* __SASC_60 */
#pragma libcall WorkbenchBase RemoveAppWindowDropZone 78 9802
#pragma libcall WorkbenchBase ChangeWorkbenchSelectionA 7e A9803
#if defined(__SASC_60)
#pragma tagcall WorkbenchBase ChangeWorkbenchSelection 7e A9803
#endif /* __SASC_60 */
#pragma libcall WorkbenchBase MakeWorkbenchObjectVisibleA 84 9802
#if defined(__SASC_60)
#pragma tagcall WorkbenchBase MakeWorkbenchObjectVisible 84 9802
#endif /* __SASC_60 */

/*--- functions in V47 or higher (Release 3.2) ---*/
#pragma libcall WorkbenchBase WhichWorkbenchObjectA 8a 910804
#if defined(__SASC_60)
#pragma tagcall WorkbenchBase WhichWorkbenchObject 8a 910804
#endif /* __SASC_60 */


#endif /* PRAGMAS_WB_PRAGMAS_H */
