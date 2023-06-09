#ifndef REQUESTER_INTERFACE_DEF_H
#define REQUESTER_INTERFACE_DEF_H

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

struct RequesterIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct RequesterIFace *Self);
	ULONG APICALL (*Release)(struct RequesterIFace *Self);
	void APICALL (*Expunge)(struct RequesterIFace *Self);
	struct Interface * APICALL (*Clone)(struct RequesterIFace *Self);
	Class * APICALL (*REQUESTER_GetClass)(struct RequesterIFace *Self);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* REQUESTER_INTERFACE_DEF_H */
