#ifndef PRAGMA_WB_LIB_H
#define PRAGMA_WB_LIB_H

/*
**	$VER: wb_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_WB_PROTOS_H
#include <clib/wb_protos.h>
#endif /* CLIB_WB_PROTOS_H */

/* "workbench.library" */
/*--- functions in V36 or higher (Release 2.0) ---*/


#pragma amicall(WorkbenchBase, 0x1e, UpdateWorkbench(a0,a1,d0))



#pragma amicall(WorkbenchBase, 0x30, AddAppWindowA(d0,d1,a0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(WorkbenchBase, 0x30, AddAppWindow(d0,d1,a0,a1,a2))
#endif /* __STORM__ */

#pragma amicall(WorkbenchBase, 0x36, RemoveAppWindow(a0))

#pragma amicall(WorkbenchBase, 0x3c, AddAppIconA(d0,d1,a0,a1,a2,a3,a4))
#if defined(__STORM__)
#pragma tagcall(WorkbenchBase, 0x3c, AddAppIcon(d0,d1,a0,a1,a2,a3,a4))
#endif /* __STORM__ */

#pragma amicall(WorkbenchBase, 0x42, RemoveAppIcon(a0))

#pragma amicall(WorkbenchBase, 0x48, AddAppMenuItemA(d0,d1,a0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(WorkbenchBase, 0x48, AddAppMenuItem(d0,d1,a0,a1,a2))
#endif /* __STORM__ */

#pragma amicall(WorkbenchBase, 0x4e, RemoveAppMenuItem(a0))

/*--- functions in V39 or higher (Release 3.0) ---*/


#pragma amicall(WorkbenchBase, 0x5a, WBInfo(a0,a1,a2))

/*--- functions in V44 or higher (Release 3.5) ---*/
#pragma amicall(WorkbenchBase, 0x60, OpenWorkbenchObjectA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(WorkbenchBase, 0x60, OpenWorkbenchObject(a0,a1))
#endif /* __STORM__ */
#pragma amicall(WorkbenchBase, 0x66, CloseWorkbenchObjectA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(WorkbenchBase, 0x66, CloseWorkbenchObject(a0,a1))
#endif /* __STORM__ */
#pragma amicall(WorkbenchBase, 0x6c, WorkbenchControlA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(WorkbenchBase, 0x6c, WorkbenchControl(a0,a1))
#endif /* __STORM__ */
#pragma amicall(WorkbenchBase, 0x72, AddAppWindowDropZoneA(a0,d0,d1,a1))
#if defined(__STORM__)
#pragma tagcall(WorkbenchBase, 0x72, AddAppWindowDropZone(a0,d0,d1,a1))
#endif /* __STORM__ */
#pragma amicall(WorkbenchBase, 0x78, RemoveAppWindowDropZone(a0,a1))
#pragma amicall(WorkbenchBase, 0x7e, ChangeWorkbenchSelectionA(a0,a1,a2))
#if defined(__STORM__)
#pragma tagcall(WorkbenchBase, 0x7e, ChangeWorkbenchSelection(a0,a1,a2))
#endif /* __STORM__ */
#pragma amicall(WorkbenchBase, 0x84, MakeWorkbenchObjectVisibleA(a0,a1))
#if defined(__STORM__)
#pragma tagcall(WorkbenchBase, 0x84, MakeWorkbenchObjectVisible(a0,a1))
#endif /* __STORM__ */

/*--- functions in V47 or higher (Release 3.2) ---*/
#pragma amicall(WorkbenchBase, 0x8a, WhichWorkbenchObjectA(a0,d0,d1,a1))
#if defined(__STORM__)
#pragma tagcall(WorkbenchBase, 0x8a, WhichWorkbenchObject(a0,d0,d1,a1))
#endif /* __STORM__ */


#endif /* PRAGMA_WB_LIB_H */
