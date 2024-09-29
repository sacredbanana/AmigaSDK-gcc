#ifndef WB_INTERFACE_DEF_H
#define WB_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 52.6.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct WorkbenchIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct WorkbenchIFace *Self);
	ULONG APICALL (*Release)(struct WorkbenchIFace *Self);
	void APICALL (*Expunge)(struct WorkbenchIFace *Self);
	struct Interface * APICALL (*Clone)(struct WorkbenchIFace *Self);
	VOID APICALL (*UpdateWorkbench)(struct WorkbenchIFace *Self, CONST_STRPTR name, ULONG lock, LONG action);
	APTR Private1;
	APTR Private2;
	struct AppWindow * APICALL (*AddAppWindowA)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, struct Window * window, struct MsgPort * msgport, const struct TagItem * taglist);
	struct AppWindow * APICALL (*AddAppWindow)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, struct Window * window, struct MsgPort * msgport, ...);
	BOOL APICALL (*RemoveAppWindow)(struct WorkbenchIFace *Self, struct AppWindow * appWindow);
	struct AppIcon * APICALL (*AddAppIconA)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort * msgport, BPTR lock, struct DiskObject * diskobj, const struct TagItem * taglist);
	struct AppIcon * APICALL (*AddAppIcon)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort * msgport, BPTR lock, struct DiskObject * diskobj, ...);
	BOOL APICALL (*RemoveAppIcon)(struct WorkbenchIFace *Self, struct AppIcon * appIcon);
	struct AppMenuItem * APICALL (*AddAppMenuItemA)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort * msgport, const struct TagItem * taglist);
	struct AppMenuItem * APICALL (*AddAppMenuItem)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort * msgport, ...);
	BOOL APICALL (*RemoveAppMenuItem)(struct WorkbenchIFace *Self, struct AppMenuItem * appMenuItem);
	APTR Private3;
	ULONG APICALL (*WBInfo)(struct WorkbenchIFace *Self, BPTR lock, CONST_STRPTR name, struct Screen * screen);
	BOOL APICALL (*OpenWorkbenchObjectA)(struct WorkbenchIFace *Self, CONST_STRPTR name, const struct TagItem * tags);
	BOOL APICALL (*OpenWorkbenchObject)(struct WorkbenchIFace *Self, CONST_STRPTR name, ...);
	BOOL APICALL (*CloseWorkbenchObjectA)(struct WorkbenchIFace *Self, CONST_STRPTR name, const struct TagItem * tags);
	BOOL APICALL (*CloseWorkbenchObject)(struct WorkbenchIFace *Self, CONST_STRPTR name, ...);
	BOOL APICALL (*WorkbenchControlA)(struct WorkbenchIFace *Self, CONST_STRPTR name, const struct TagItem * tags);
	BOOL APICALL (*WorkbenchControl)(struct WorkbenchIFace *Self, CONST_STRPTR name, ...);
	struct AppWindowDropZone * APICALL (*AddAppWindowDropZoneA)(struct WorkbenchIFace *Self, struct AppWindow * aw, ULONG id, ULONG userdata, const struct TagItem * tags);
	struct AppWindowDropZone * APICALL (*AddAppWindowDropZone)(struct WorkbenchIFace *Self, struct AppWindow * aw, ULONG id, ULONG userdata, ...);
	BOOL APICALL (*RemoveAppWindowDropZone)(struct WorkbenchIFace *Self, struct AppWindow * aw, struct AppWindowDropZone * dropZone);
	BOOL APICALL (*ChangeWorkbenchSelectionA)(struct WorkbenchIFace *Self, CONST_STRPTR name, struct Hook * hook, const struct TagItem * tags);
	BOOL APICALL (*ChangeWorkbenchSelection)(struct WorkbenchIFace *Self, CONST_STRPTR name, struct Hook * hook, ...);
	BOOL APICALL (*MakeWorkbenchObjectVisibleA)(struct WorkbenchIFace *Self, CONST_STRPTR name, const struct TagItem * tags);
	BOOL APICALL (*MakeWorkbenchObjectVisible)(struct WorkbenchIFace *Self, CONST_STRPTR name, ...);
	ULONG APICALL (*WhichWorkbenchObjectA)(struct WorkbenchIFace *Self, struct Window * window, LONG x, LONG y, const struct TagItem * tags);
	ULONG APICALL (*WhichWorkbenchObject)(struct WorkbenchIFace *Self, struct Window * window, LONG x, LONG y, ...);
	APTR Private4;
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* WB_INTERFACE_DEF_H */