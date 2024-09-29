#ifndef XENA_INTERFACE_DEF_H
#define XENA_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.5.
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

struct XenaIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct XenaIFace *Self);
	uint32 APICALL (*Release)(struct XenaIFace *Self);
	void APICALL (*Expunge)(struct XenaIFace *Self);
	struct Interface * APICALL (*Clone)(struct XenaIFace *Self);
	CONST_STRPTR APICALL (*AllocResource)(struct XenaIFace *Self, uint32 unitNum, CONST_STRPTR name);
	void APICALL (*FreeResource)(struct XenaIFace *Self, uint32 unitNum);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* XENA_INTERFACE_DEF_H */