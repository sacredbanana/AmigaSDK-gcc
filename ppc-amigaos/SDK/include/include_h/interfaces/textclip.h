#ifndef TEXTCLIP_INTERFACE_DEF_H
#define TEXTCLIP_INTERFACE_DEF_H

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

struct TextClipIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct TextClipIFace *Self);
	ULONG APICALL (*Release)(struct TextClipIFace *Self);
	void APICALL (*Expunge)(struct TextClipIFace *Self);
	struct Interface * APICALL (*Clone)(struct TextClipIFace *Self);
	LONG APICALL (*WriteClipVector)(struct TextClipIFace *Self, CONST_STRPTR vector, ULONG size);
	LONG APICALL (*ReadClipVector)(struct TextClipIFace *Self, STRPTR * bufptr, ULONG * sizptr);
	VOID APICALL (*DisposeClipVector)(struct TextClipIFace *Self, STRPTR vector);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* TEXTCLIP_INTERFACE_DEF_H */
