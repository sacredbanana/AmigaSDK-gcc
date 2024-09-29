#ifndef RAMDRIVE_INTERFACE_DEF_H
#define RAMDRIVE_INTERFACE_DEF_H

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


#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct RamdriveIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct RamdriveIFace *Self);
	ULONG APICALL (*Release)(struct RamdriveIFace *Self);
	void APICALL (*Expunge)(struct RamdriveIFace *Self);
	struct Interface * APICALL (*Clone)(struct RamdriveIFace *Self);
	STRPTR APICALL (*KillRAD0)(struct RamdriveIFace *Self);
	STRPTR APICALL (*KillRAD)(struct RamdriveIFace *Self, ULONG unit);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* RAMDRIVE_INTERFACE_DEF_H */