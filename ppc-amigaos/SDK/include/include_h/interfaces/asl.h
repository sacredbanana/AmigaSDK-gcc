#ifndef ASL_INTERFACE_DEF_H
#define ASL_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 52.7.
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
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_ASL_H
#include <libraries/asl.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct AslIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct AslIFace *Self);
	uint32 APICALL (*Release)(struct AslIFace *Self);
	void APICALL (*Expunge)(struct AslIFace *Self);
	struct Interface * APICALL (*Clone)(struct AslIFace *Self);
	struct FileRequester * APICALL (*OBSOLETE_AllocFileRequest)(struct AslIFace *Self);
	VOID APICALL (*OBSOLETE_FreeFileRequest)(struct AslIFace *Self, struct FileRequester * fileReq);
	BOOL APICALL (*OBSOLETE_RequestFile)(struct AslIFace *Self, struct FileRequester * fileReq);
	APTR APICALL (*AllocAslRequest)(struct AslIFace *Self, uint32 reqType, const struct TagItem * tagList);
	APTR APICALL (*AllocAslRequestTags)(struct AslIFace *Self, uint32 reqType, ...);
	VOID APICALL (*FreeAslRequest)(struct AslIFace *Self, APTR requester);
	BOOL APICALL (*AslRequest)(struct AslIFace *Self, APTR requester, const struct TagItem * tagList);
	BOOL APICALL (*AslRequestTags)(struct AslIFace *Self, APTR requester, ...);
	VOID APICALL (*AslFreeVec)(struct AslIFace *Self, APTR memory);
	APTR APICALL (*AslAllocVec)(struct AslIFace *Self, uint32 byteSize, uint32 attributes);
	VOID APICALL (*AbortAslRequest)(struct AslIFace *Self, APTR requester);
	VOID APICALL (*ActivateAslRequest)(struct AslIFace *Self, APTR requester);
	uint32 APICALL (*AslControl)(struct AslIFace *Self, const struct TagItem * tags);
	uint32 APICALL (*AslControlTags)(struct AslIFace *Self, ...);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* ASL_INTERFACE_DEF_H */