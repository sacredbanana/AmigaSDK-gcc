#ifndef MUIMASTER_INTERFACE_DEF_H
#define MUIMASTER_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.22.
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

#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct MUIMasterIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct MUIMasterIFace *Self);
	uint32 APICALL (*Release)(struct MUIMasterIFace *Self);
	APTR Expunge_UNIMPLEMENTED;
	APTR Clone_UNIMPLEMENTED;
	Object * APICALL (*MUI_NewObjectA)(struct MUIMasterIFace *Self, CONST_STRPTR cl, struct TagItem * tags);
	Object * APICALL (*MUI_NewObject)(struct MUIMasterIFace *Self, CONST_STRPTR cl, ...);
	VOID APICALL (*MUI_DisposeObject)(struct MUIMasterIFace *Self, Object * obj);
	LONG APICALL (*MUI_RequestA)(struct MUIMasterIFace *Self, Object * app, Object * win, ULONG flags, CONST_STRPTR title, CONST_STRPTR gadgets, CONST_STRPTR format, APTR params);
	LONG APICALL (*MUI_Request)(struct MUIMasterIFace *Self, Object * app, Object * win, ULONG flags, CONST_STRPTR title, CONST_STRPTR gadgets, CONST_STRPTR format, ...);
	APTR APICALL (*MUI_AllocAslRequest)(struct MUIMasterIFace *Self, ULONG type, struct TagItem * tags);
	APTR APICALL (*MUI_AllocAslRequestTags)(struct MUIMasterIFace *Self, ULONG type, ...);
	BOOL APICALL (*MUI_AslRequest)(struct MUIMasterIFace *Self, APTR req, struct TagItem * tags);
	BOOL APICALL (*MUI_AslRequestTags)(struct MUIMasterIFace *Self, APTR req, ...);
	VOID APICALL (*MUI_FreeAslRequest)(struct MUIMasterIFace *Self, APTR req);
	DEPRECATED LONG APICALL (*MUI_Error)(struct MUIMasterIFace *Self);
	DEPRECATED LONG APICALL (*MUI_SetError)(struct MUIMasterIFace *Self, LONG errnum);
	DEPRECATED struct IClass * APICALL (*MUI_GetClass)(struct MUIMasterIFace *Self, CONST_STRPTR name);
	DEPRECATED VOID APICALL (*MUI_FreeClass)(struct MUIMasterIFace *Self, struct IClass * cl);
	DEPRECATED VOID APICALL (*MUI_RequestIDCMP)(struct MUIMasterIFace *Self, Object * obj, ULONG flags);
	DEPRECATED VOID APICALL (*MUI_RejectIDCMP)(struct MUIMasterIFace *Self, Object * obj, ULONG flags);
	VOID APICALL (*MUI_Redraw)(struct MUIMasterIFace *Self, Object * obj, ULONG flags);
	struct MUI_CustomClass * APICALL (*MUI_CreateCustomClass)(struct MUIMasterIFace *Self, struct Library * base, CONST_STRPTR supername, struct MUI_CustomClass * supermcc, ULONG datasize, APTR dispatcher);
	BOOL APICALL (*MUI_DeleteCustomClass)(struct MUIMasterIFace *Self, struct MUI_CustomClass * mcc);
	Object * APICALL (*MUI_MakeObjectA)(struct MUIMasterIFace *Self, LONG type, ULONG * params);
	Object * APICALL (*MUI_MakeObject)(struct MUIMasterIFace *Self, LONG type, ...);
	BOOL APICALL (*MUI_Layout)(struct MUIMasterIFace *Self, Object * obj, LONG l, LONG t, LONG w, LONG h, ULONG flags);
	VOID APICALL (*MUIP_private0)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private1)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private2)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private3)(struct MUIMasterIFace *Self);
	LONG APICALL (*MUI_ObtainPen)(struct MUIMasterIFace *Self, struct MUI_RenderInfo * mri, const struct MUI_PenSpec * spec, ULONG flags);
	VOID APICALL (*MUI_ReleasePen)(struct MUIMasterIFace *Self, struct MUI_RenderInfo * mri, LONG pen);
	APTR APICALL (*MUI_AddClipping)(struct MUIMasterIFace *Self, struct MUI_RenderInfo * mri, WORD l, WORD t, WORD w, WORD h);
	VOID APICALL (*MUI_RemoveClipping)(struct MUIMasterIFace *Self, struct MUI_RenderInfo * mri, APTR h);
	APTR APICALL (*MUI_AddClipRegion)(struct MUIMasterIFace *Self, struct MUI_RenderInfo * mri, struct Region * region);
	VOID APICALL (*MUI_RemoveClipRegion)(struct MUIMasterIFace *Self, struct MUI_RenderInfo * mri, APTR region);
	BOOL APICALL (*MUI_BeginRefresh)(struct MUIMasterIFace *Self, struct MUI_RenderInfo * mri, ULONG flags);
	VOID APICALL (*MUI_EndRefresh)(struct MUIMasterIFace *Self, struct MUI_RenderInfo * mri, ULONG flags);
	VOID APICALL (*MUIP_private4)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private5)(struct MUIMasterIFace *Self);
	ULONG APICALL (*MUI_Show)(struct MUIMasterIFace *Self, Object * obj);
	ULONG APICALL (*MUI_Hide)(struct MUIMasterIFace *Self, Object * obj);
	BOOL APICALL (*MUI_LayoutObj)(struct MUIMasterIFace *Self, Object * obj, LONG l, LONG t, LONG w, LONG h, ULONG flags);
	VOID APICALL (*MUI_Offset)(struct MUIMasterIFace *Self, Object * obj, LONG x, LONG y);
	VOID APICALL (*MUIP_private6)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private7)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private8)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private9)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private10)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private11)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private12)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private13)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private14)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private15)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private16)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private17)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private18)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private19)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private20)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private21)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private22)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private23)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private24)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private25)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private26)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private27)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private28)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private29)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private30)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private31)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private32)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private33)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private34)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private35)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private36)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private37)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private38)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private39)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private40)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private41)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private42)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private43)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private44)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private45)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private46)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private47)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private48)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private49)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private50)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private51)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private52)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private53)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private54)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private55)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private56)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private57)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private58)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private59)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private60)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private61)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private62)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private63)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private64)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private65)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private66)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private67)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private68)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private69)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private70)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private71)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private72)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private73)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private74)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private75)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private76)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private77)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private78)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private79)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private80)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private81)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private82)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private83)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private84)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private85)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private86)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private87)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private88)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private89)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private90)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private91)(struct MUIMasterIFace *Self);
	VOID APICALL (*MUIP_private92)(struct MUIMasterIFace *Self);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* MUIMASTER_INTERFACE_DEF_H */
