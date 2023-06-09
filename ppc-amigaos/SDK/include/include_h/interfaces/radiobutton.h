#ifndef RADIOBUTTON_INTERFACE_DEF_H
#define RADIOBUTTON_INTERFACE_DEF_H

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

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct RadioButtonIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct RadioButtonIFace *Self);
	ULONG APICALL (*Release)(struct RadioButtonIFace *Self);
	void APICALL (*Expunge)(struct RadioButtonIFace *Self);
	struct Interface * APICALL (*Clone)(struct RadioButtonIFace *Self);
	Class * APICALL (*RADIOBUTTON_GetClass)(struct RadioButtonIFace *Self);
	struct Node * APICALL (*AllocRadioButtonNodeA)(struct RadioButtonIFace *Self, UWORD columns, struct TagItem * tags);
	struct Node * APICALL (*AllocRadioButtonNode)(struct RadioButtonIFace *Self, UWORD columns, ...);
	VOID APICALL (*FreeRadioButtonNode)(struct RadioButtonIFace *Self, struct Node * node);
	VOID APICALL (*SetRadioButtonNodeAttrsA)(struct RadioButtonIFace *Self, struct Node * node, struct TagItem * tags);
	VOID APICALL (*SetRadioButtonNodeAttrs)(struct RadioButtonIFace *Self, struct Node * node, ...);
	VOID APICALL (*GetRadioButtonNodeAttrsA)(struct RadioButtonIFace *Self, struct Node * node, struct TagItem * tags);
	VOID APICALL (*GetRadioButtonNodeAttrs)(struct RadioButtonIFace *Self, struct Node * node, ...);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* RADIOBUTTON_INTERFACE_DEF_H */
