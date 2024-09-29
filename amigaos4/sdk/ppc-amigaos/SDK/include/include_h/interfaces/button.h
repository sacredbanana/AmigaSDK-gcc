#ifndef BUTTON_INTERFACE_DEF_H
#define BUTTON_INTERFACE_DEF_H

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

struct ButtonIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ButtonIFace *Self);
	ULONG APICALL (*Release)(struct ButtonIFace *Self);
	void APICALL (*Expunge)(struct ButtonIFace *Self);
	struct Interface * APICALL (*Clone)(struct ButtonIFace *Self);
	Class * APICALL (*BUTTON_GetClass)(struct ButtonIFace *Self);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* BUTTON_INTERFACE_DEF_H */