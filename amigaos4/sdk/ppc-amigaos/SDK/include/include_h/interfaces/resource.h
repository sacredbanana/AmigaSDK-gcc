#ifndef RESOURCE_INTERFACE_DEF_H
#define RESOURCE_INTERFACE_DEF_H

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

#ifndef LIBRARIES_RESOURCE_H
#include <libraries/resource.h>
#endif
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef LIBRARIES_LOCALE_H
#include <libraries/locale.h>
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

struct ResourceIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ResourceIFace *Self);
	ULONG APICALL (*Release)(struct ResourceIFace *Self);
	void APICALL (*Expunge)(struct ResourceIFace *Self);
	struct Interface * APICALL (*Clone)(struct ResourceIFace *Self);
	RESOURCEFILE APICALL (*RL_OpenResource)(struct ResourceIFace *Self, APTR resource, struct Screen * screen, struct Catalog * catalog);
	VOID APICALL (*RL_CloseResource)(struct ResourceIFace *Self, RESOURCEFILE resfile);
	Object * APICALL (*RL_NewObjectA)(struct ResourceIFace *Self, RESOURCEFILE resfile, RESOURCEID resid, struct TagItem * tags);
	Object * APICALL (*RL_NewObject)(struct ResourceIFace *Self, RESOURCEFILE resfile, RESOURCEID resid, ...);
	VOID APICALL (*RL_DisposeObject)(struct ResourceIFace *Self, RESOURCEFILE resfile, Object * obj);
	Object ** APICALL (*RL_NewGroupA)(struct ResourceIFace *Self, RESOURCEFILE resfile, RESOURCEID id, struct TagItem * taglist);
	Object ** APICALL (*RL_NewGroup)(struct ResourceIFace *Self, RESOURCEFILE resfile, RESOURCEID id, ...);
	VOID APICALL (*RL_DisposeGroup)(struct ResourceIFace *Self, RESOURCEFILE resfile, Object ** obj);
	Object ** APICALL (*RL_GetObjectArray)(struct ResourceIFace *Self, RESOURCEFILE resfile, Object * obj, RESOURCEID id);
	BOOL APICALL (*RL_SetResourceScreen)(struct ResourceIFace *Self, RESOURCEFILE resfile, struct Screen * screen);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* RESOURCE_INTERFACE_DEF_H */