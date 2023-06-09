#ifndef CARDRES_INTERFACE_DEF_H
#define CARDRES_INTERFACE_DEF_H

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

#ifndef EXEC_RESIDENT_H
#include <exec/resident.h>
#endif
#ifndef RESOURCES_CARD_H
#include <resources/card.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct CardIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct CardIFace *Self);
	ULONG APICALL (*Release)(struct CardIFace *Self);
	void APICALL (*Expunge)(struct CardIFace *Self);
	struct Interface * APICALL (*Clone)(struct CardIFace *Self);
	struct CardHandle * APICALL (*OwnCard)(struct CardIFace *Self, struct CardHandle * handle);
	VOID APICALL (*ReleaseCard)(struct CardIFace *Self, struct CardHandle * handle, ULONG flags);
	struct CardMemoryMap * APICALL (*GetCardMap)(struct CardIFace *Self);
	BOOL APICALL (*BeginCardAccess)(struct CardIFace *Self, struct CardHandle * handle);
	BOOL APICALL (*EndCardAccess)(struct CardIFace *Self, struct CardHandle * handle);
	UBYTE APICALL (*ReadCardStatus)(struct CardIFace *Self);
	BOOL APICALL (*CardResetRemove)(struct CardIFace *Self, struct CardHandle * handle, ULONG flag);
	UBYTE APICALL (*CardMiscControl)(struct CardIFace *Self, struct CardHandle * handle, UBYTE control_bits);
	ULONG APICALL (*CardAccessSpeed)(struct CardIFace *Self, struct CardHandle * handle, ULONG nanoseconds);
	LONG APICALL (*CardProgramVoltage)(struct CardIFace *Self, struct CardHandle * handle, ULONG voltage);
	BOOL APICALL (*CardResetCard)(struct CardIFace *Self, struct CardHandle * handle);
	BOOL APICALL (*CopyTuple)(struct CardIFace *Self, const struct CardHandle * handle, UBYTE * buffer, ULONG tuplecode, ULONG size);
	ULONG APICALL (*DeviceTuple)(struct CardIFace *Self, const UBYTE * tuple_data, struct DeviceTData * storage);
	struct Resident * APICALL (*IfAmigaXIP)(struct CardIFace *Self, const struct CardHandle * handle);
	BOOL APICALL (*CardForceChange)(struct CardIFace *Self);
	ULONG APICALL (*CardChangeCount)(struct CardIFace *Self);
	ULONG APICALL (*CardInterface)(struct CardIFace *Self);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* CARDRES_INTERFACE_DEF_H */
