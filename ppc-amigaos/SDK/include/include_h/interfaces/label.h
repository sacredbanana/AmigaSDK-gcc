#ifndef LABEL_INTERFACE_DEF_H
#define LABEL_INTERFACE_DEF_H

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

struct LabelIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct LabelIFace *Self);
	ULONG APICALL (*Release)(struct LabelIFace *Self);
	void APICALL (*Expunge)(struct LabelIFace *Self);
	struct Interface * APICALL (*Clone)(struct LabelIFace *Self);
	Class * APICALL (*LABEL_GetClass)(struct LabelIFace *Self);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* LABEL_INTERFACE_DEF_H */
