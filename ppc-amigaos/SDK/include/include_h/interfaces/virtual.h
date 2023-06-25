#ifndef VIRTUAL_INTERFACE_DEF_H
#define VIRTUAL_INTERFACE_DEF_H

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

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef GADGETS_LAYOUT_H
#include <gadgets/layout.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct VirtualIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct VirtualIFace *Self);
	ULONG APICALL (*Release)(struct VirtualIFace *Self);
	void APICALL (*Expunge)(struct VirtualIFace *Self);
	struct Interface * APICALL (*Clone)(struct VirtualIFace *Self);
	Class * APICALL (*VIRTUAL_GetClass)(struct VirtualIFace *Self);
	VOID APICALL (*RefreshVirtualGadget)(struct VirtualIFace *Self, struct Gadget * gadget, Object * obj, struct Window * window, struct Requester * requester);
	BOOL APICALL (*RethinkVirtualSize)(struct VirtualIFace *Self, Object * virt_obj, Object * rootlayout, struct TextFont * font, struct Screen * screen, struct LayoutLimits * layoutlimits);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* VIRTUAL_INTERFACE_DEF_H */