#ifndef COMMODITIES_INTERFACE_DEF_H
#define COMMODITIES_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.5.
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

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif
#ifndef LIBRARIES_COMMODITIES_H
#include <libraries/commodities.h>
#endif
#ifndef DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef DEVICES_KEYMAP_H
#include <devices/keymap.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct CommoditiesIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct CommoditiesIFace *Self);
	uint32 APICALL (*Release)(struct CommoditiesIFace *Self);
	void APICALL (*Expunge)(struct CommoditiesIFace *Self);
	struct Interface * APICALL (*Clone)(struct CommoditiesIFace *Self);
	CxObj * APICALL (*CreateCxObj)(struct CommoditiesIFace *Self, uint32 type, int32 arg1, int32 arg2);
	CxObj * APICALL (*CxBroker)(struct CommoditiesIFace *Self, const struct NewBroker * nb, int32 * error);
	int32 APICALL (*ActivateCxObj)(struct CommoditiesIFace *Self, CxObj * co, int32 doIt);
	VOID APICALL (*DeleteCxObj)(struct CommoditiesIFace *Self, CxObj * co);
	VOID APICALL (*DeleteCxObjAll)(struct CommoditiesIFace *Self, CxObj * co);
	uint32 APICALL (*CxObjType)(struct CommoditiesIFace *Self, const CxObj * co);
	int32 APICALL (*CxObjError)(struct CommoditiesIFace *Self, const CxObj * co);
	VOID APICALL (*ClearCxObjError)(struct CommoditiesIFace *Self, CxObj * co);
	int32 APICALL (*SetCxObjPri)(struct CommoditiesIFace *Self, CxObj * co, int32 pri);
	VOID APICALL (*AttachCxObj)(struct CommoditiesIFace *Self, CxObj * headObj, CxObj * co);
	VOID APICALL (*EnqueueCxObj)(struct CommoditiesIFace *Self, CxObj * headObj, CxObj * co);
	VOID APICALL (*InsertCxObj)(struct CommoditiesIFace *Self, CxObj * headObj, CxObj * co, CxObj * pred);
	VOID APICALL (*RemoveCxObj)(struct CommoditiesIFace *Self, CxObj * co);
	VOID APICALL (*CxReserved0)(struct CommoditiesIFace *Self);
	VOID APICALL (*SetTranslate)(struct CommoditiesIFace *Self, CxObj * translator, struct InputEvent * events);
	VOID APICALL (*SetFilter)(struct CommoditiesIFace *Self, CxObj * filter, CONST_STRPTR text);
	VOID APICALL (*SetFilterIX)(struct CommoditiesIFace *Self, CxObj * filter, const IX * ix);
	int32 APICALL (*ParseIX)(struct CommoditiesIFace *Self, CONST_STRPTR description, IX * ix);
	uint32 APICALL (*CxMsgType)(struct CommoditiesIFace *Self, const CxMsg * cxm);
	APTR APICALL (*CxMsgData)(struct CommoditiesIFace *Self, const CxMsg * cxm);
	int32 APICALL (*CxMsgID)(struct CommoditiesIFace *Self, const CxMsg * cxm);
	VOID APICALL (*DivertCxMsg)(struct CommoditiesIFace *Self, CxMsg * cxm, CxObj * headObj, CxObj * returnObj);
	VOID APICALL (*RouteCxMsg)(struct CommoditiesIFace *Self, CxMsg * cxm, CxObj * co);
	VOID APICALL (*DisposeCxMsg)(struct CommoditiesIFace *Self, CxMsg * cxm);
	BOOL APICALL (*InvertKeyMap)(struct CommoditiesIFace *Self, uint32 ansiCode, struct InputEvent * event, const struct KeyMap * km);
	VOID APICALL (*AddIEvents)(struct CommoditiesIFace *Self, struct InputEvent * events);
	int32 APICALL (*CopyBrokerList)(struct CommoditiesIFace *Self, struct List * blist);
	VOID APICALL (*FreeBrokerList)(struct CommoditiesIFace *Self, struct List * list);
	int32 APICALL (*BrokerCommand)(struct CommoditiesIFace *Self, CONST_STRPTR name, int32 id);
	BOOL APICALL (*MatchIX)(struct CommoditiesIFace *Self, const struct InputEvent * event, const IX * ix);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* COMMODITIES_INTERFACE_DEF_H */
