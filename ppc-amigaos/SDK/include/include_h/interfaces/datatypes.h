#ifndef DATATYPES_INTERFACE_DEF_H
#define DATATYPES_INTERFACE_DEF_H

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

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef DATATYPES_DATATYPESCLASS_H
#include <datatypes/datatypesclass.h>
#endif
#ifndef DATATYPES_DATATYPES_H
#include <datatypes/datatypes.h>
#endif
#ifndef REXX_STORAGE_H
#include <rexx/storage.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct DataTypesIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct DataTypesIFace *Self);
	ULONG APICALL (*Release)(struct DataTypesIFace *Self);
	void APICALL (*Expunge)(struct DataTypesIFace *Self);
	struct Interface * APICALL (*Clone)(struct DataTypesIFace *Self);
	LONG APICALL (*RLDispatch)(struct DataTypesIFace *Self, struct RexxMsg * rmsg, STRPTR * result);
	struct DataType * APICALL (*ObtainDataTypeA)(struct DataTypesIFace *Self, ULONG type, APTR handle, CONST struct TagItem * attrs);
	struct DataType * APICALL (*ObtainDataType)(struct DataTypesIFace *Self, ULONG type, APTR handle, ...);
	VOID APICALL (*ReleaseDataType)(struct DataTypesIFace *Self, struct DataType * dt);
	Object * APICALL (*NewDTObjectA)(struct DataTypesIFace *Self, CONST_STRPTR name, CONST struct TagItem * attrs);
	Object * APICALL (*NewDTObject)(struct DataTypesIFace *Self, CONST_STRPTR name, ...);
	VOID APICALL (*DisposeDTObject)(struct DataTypesIFace *Self, Object * o);
	ULONG APICALL (*SetDTAttrsA)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, CONST struct TagItem * attrs);
	ULONG APICALL (*SetDTAttrs)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, ...);
	ULONG APICALL (*GetDTAttrsA)(struct DataTypesIFace *Self, Object * o, CONST struct TagItem * attrs);
	ULONG APICALL (*GetDTAttrs)(struct DataTypesIFace *Self, Object * o, ...);
	LONG APICALL (*AddDTObject)(struct DataTypesIFace *Self, struct Window * win, struct Requester * req, Object * o, LONG pos);
	VOID APICALL (*RefreshDTObjectA)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, CONST struct TagItem * attrs);
	VOID APICALL (*RefreshDTObjects)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, ...);
	VOID APICALL (*RefreshDTObject)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, ...);
	ULONG APICALL (*DoAsyncLayout)(struct DataTypesIFace *Self, Object * o, struct gpLayout * gpl);
	ULONG APICALL (*DoDTMethodA)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, Msg msg);
	ULONG APICALL (*DoDTMethod)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, ...);
	LONG APICALL (*RemoveDTObject)(struct DataTypesIFace *Self, struct Window * win, Object * o);
	ULONG * APICALL (*GetDTMethods)(struct DataTypesIFace *Self, Object * object);
	struct DTMethod * APICALL (*GetDTTriggerMethods)(struct DataTypesIFace *Self, Object * object);
	ULONG APICALL (*PrintDTObjectA)(struct DataTypesIFace *Self, Object * o, struct Window * w, struct Requester * r, struct dtPrint * msg);
	ULONG APICALL (*PrintDTObject)(struct DataTypesIFace *Self, Object * o, struct Window * w, struct Requester * r, ...);
	APTR APICALL (*ObtainDTDrawInfoA)(struct DataTypesIFace *Self, Object * o, CONST struct TagItem * attrs);
	APTR APICALL (*ObtainDTDrawInfo)(struct DataTypesIFace *Self, Object * o, ...);
	LONG APICALL (*DrawDTObjectA)(struct DataTypesIFace *Self, struct RastPort * rp, Object * o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, CONST struct TagItem * attrs);
	LONG APICALL (*DrawDTObject)(struct DataTypesIFace *Self, struct RastPort * rp, Object * o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, ...);
	VOID APICALL (*ReleaseDTDrawInfo)(struct DataTypesIFace *Self, Object * o, APTR handle);
	CONST_STRPTR APICALL (*GetDTString)(struct DataTypesIFace *Self, ULONG id);
	void APICALL (*Reserved1)(struct DataTypesIFace *Self);
	void APICALL (*Reserved2)(struct DataTypesIFace *Self);
	void APICALL (*Reserved3)(struct DataTypesIFace *Self);
	void APICALL (*Reserved4)(struct DataTypesIFace *Self);
	void APICALL (*Reserved5)(struct DataTypesIFace *Self);
	void APICALL (*Reserved6)(struct DataTypesIFace *Self);
	void APICALL (*Reserved7)(struct DataTypesIFace *Self);
	void APICALL (*Reserved8)(struct DataTypesIFace *Self);
	void APICALL (*Reserved9)(struct DataTypesIFace *Self);
	void APICALL (*Reserved10)(struct DataTypesIFace *Self);
	void APICALL (*Reserved11)(struct DataTypesIFace *Self);
	void APICALL (*Reserved12)(struct DataTypesIFace *Self);
	ULONG APICALL (*SaveDTObject)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, CONST_STRPTR file, ULONG mode, BOOL saveicon, ...);
	ULONG APICALL (*DoDTDomain)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, struct RastPort * rport, ULONG which, struct IBox * domain, ...);
	struct ToolNode * APICALL (*FindToolNode)(struct DataTypesIFace *Self, struct List * tl, ...);
	ULONG APICALL (*LaunchTool)(struct DataTypesIFace *Self, struct Tool * t, CONST_STRPTR project, ...);
	VOID APICALL (*LockDataType)(struct DataTypesIFace *Self, struct DataType * dt);
	struct ToolNode * APICALL (*FindToolNodeA)(struct DataTypesIFace *Self, struct List * tl, CONST struct TagItem * attrs);
	ULONG APICALL (*LaunchToolA)(struct DataTypesIFace *Self, struct Tool * t, CONST_STRPTR project, CONST struct TagItem * attrs);
	ULONG * APICALL (*FindMethod)(struct DataTypesIFace *Self, ULONG * methods, ULONG searchmethodid);
	struct DTMethod * APICALL (*FindTriggerMethod)(struct DataTypesIFace *Self, struct DTMethod * dtm, CONST_STRPTR command, ULONG method);
	ULONG * APICALL (*CopyDTMethods)(struct DataTypesIFace *Self, ULONG * methods, ULONG * include, ULONG * exclude);
	struct DTMethod * APICALL (*CopyDTTriggerMethods)(struct DataTypesIFace *Self, struct DTMethod * methods, struct DTMethod * include, struct DTMethod * exclude);
	VOID APICALL (*FreeDTMethods)(struct DataTypesIFace *Self, APTR methods);
	ULONG APICALL (*GetDTTriggerMethodDataFlags)(struct DataTypesIFace *Self, ULONG triggermethod);
	ULONG APICALL (*SaveDTObjectA)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, CONST_STRPTR file, ULONG mode, BOOL saveicon, CONST struct TagItem * attrs);
	ULONG APICALL (*StartDragSelect)(struct DataTypesIFace *Self, Object * o);
	ULONG APICALL (*DoDTDomainA)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, struct RastPort * rport, ULONG which, struct IBox * domain, CONST struct TagItem * attrs);
	ULONG APICALL (*datatypesPrivate001)(struct DataTypesIFace *Self);
	ULONG APICALL (*datatypesPrivate002)(struct DataTypesIFace *Self);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* DATATYPES_INTERFACE_DEF_H */
