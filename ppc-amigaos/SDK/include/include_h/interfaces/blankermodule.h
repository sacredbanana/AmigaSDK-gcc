#ifndef BLANKERMODULE_INTERFACE_DEF_H
#define BLANKERMODULE_INTERFACE_DEF_H

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

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct BlankerModuleIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct BlankerModuleIFace *Self);
	uint32 APICALL (*Release)(struct BlankerModuleIFace *Self);
	void APICALL (*Expunge)(struct BlankerModuleIFace *Self);
	struct BlankerModuleIFace * APICALL (*Clone)(struct BlankerModuleIFace *Self);
	BOOL APICALL (*BlankerModuleGet)(struct BlankerModuleIFace *Self, uint32 msgType, uint32 * msgData);
	BOOL APICALL (*BlankerModuleSet)(struct BlankerModuleIFace *Self, uint32 msgType, uint32 msgData);
	void APICALL (*BlankerModuleBlankTask)(struct BlankerModuleIFace *Self);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* BLANKERMODULE_INTERFACE_DEF_H */
