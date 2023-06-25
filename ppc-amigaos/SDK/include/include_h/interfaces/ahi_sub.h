#ifndef AHI_SUB_INTERFACE_DEF_H
#define AHI_SUB_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.7.
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
#ifndef LIBRARIES_AHI_SUB_H
#include <libraries/ahi_sub.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct AHIsubIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct AHIsubIFace *Self);
	uint32 APICALL (*Release)(struct AHIsubIFace *Self);
	void APICALL (*Expunge)(struct AHIsubIFace *Self);
	struct Interface * APICALL (*Clone)(struct AHIsubIFace *Self);
	ULONG APICALL (*AHIsub_AllocAudio)(struct AHIsubIFace *Self, struct TagItem * tagList, struct AHIAudioCtrlDrv * AudioCtrl);
	void APICALL (*AHIsub_FreeAudio)(struct AHIsubIFace *Self, struct AHIAudioCtrlDrv * AudioCtrl);
	void APICALL (*AHIsub_Disable)(struct AHIsubIFace *Self, struct AHIAudioCtrlDrv * AudioCtrl);
	void APICALL (*AHIsub_Enable)(struct AHIsubIFace *Self, struct AHIAudioCtrlDrv * AudioCtrl);
	ULONG APICALL (*AHIsub_Start)(struct AHIsubIFace *Self, ULONG Flags, struct AHIAudioCtrlDrv * AudioCtrl);
	ULONG APICALL (*AHIsub_Update)(struct AHIsubIFace *Self, ULONG Flags, struct AHIAudioCtrlDrv * AudioCtrl);
	ULONG APICALL (*AHIsub_Stop)(struct AHIsubIFace *Self, ULONG Flags, struct AHIAudioCtrlDrv * AudioCtrl);
	ULONG APICALL (*AHIsub_SetVol)(struct AHIsubIFace *Self, UWORD Channel, Fixed Volume, sposition Pan, struct AHIAudioCtrlDrv * AudioCtrl, ULONG Flags);
	ULONG APICALL (*AHIsub_SetFreq)(struct AHIsubIFace *Self, UWORD Channel, ULONG Freq, struct AHIAudioCtrlDrv * AudioCtrl, ULONG Flags);
	ULONG APICALL (*AHIsub_SetSound)(struct AHIsubIFace *Self, UWORD Channel, UWORD Sound, ULONG Offset, LONG Length, struct AHIAudioCtrlDrv * AudioCtrl, ULONG Flags);
	ULONG APICALL (*AHIsub_SetEffect)(struct AHIsubIFace *Self, APTR Effect, struct AHIAudioCtrlDrv * AudioCtrl);
	ULONG APICALL (*AHIsub_LoadSound)(struct AHIsubIFace *Self, UWORD Sound, ULONG Type, APTR Info, struct AHIAudioCtrlDrv * AudioCtrl);
	ULONG APICALL (*AHIsub_UnloadSound)(struct AHIsubIFace *Self, UWORD Sound, struct AHIAudioCtrlDrv * Audioctrl);
	LONG APICALL (*AHIsub_GetAttr)(struct AHIsubIFace *Self, ULONG Attribute, LONG Argument, LONG DefValue, struct TagItem * tagList, struct AHIAudioCtrlDrv * AudioCtrl);
	LONG APICALL (*AHIsub_HardwareControl)(struct AHIsubIFace *Self, ULONG Attribute, LONG Argument, struct AHIAudioCtrlDrv * AudioCtrl);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* AHI_SUB_INTERFACE_DEF_H */
