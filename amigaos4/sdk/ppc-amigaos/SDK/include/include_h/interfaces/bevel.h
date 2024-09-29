#ifndef BEVEL_INTERFACE_DEF_H
#define BEVEL_INTERFACE_DEF_H

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

struct BevelIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct BevelIFace *Self);
	ULONG APICALL (*Release)(struct BevelIFace *Self);
	void APICALL (*Expunge)(struct BevelIFace *Self);
	struct Interface * APICALL (*Clone)(struct BevelIFace *Self);
	Class * APICALL (*BEVEL_GetClass)(struct BevelIFace *Self);
	void APICALL (*Reserved1)(struct BevelIFace *Self);
	void APICALL (*Reserved2)(struct BevelIFace *Self);
	void APICALL (*NewBevelPrefs)(struct BevelIFace *Self);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* BEVEL_INTERFACE_DEF_H */