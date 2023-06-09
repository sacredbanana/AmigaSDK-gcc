#ifndef EXPANSION_INTERFACE_DEF_H
#define EXPANSION_INTERFACE_DEF_H

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

#ifndef EXPANSION_PCI_H
#include <expansion/pci.h>
#endif
#ifndef EXPANSION_EXPANSION_H
#include <expansion/expansion.h>
#endif
#ifndef EXPANSION_CONFIGVARS_H
#include <expansion/configvars.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef DOS_DOSEXTENS_H
#include <dos/dosextens.h>
#endif
#ifndef DOS_FILEHANDLER_H
#include <dos/filehandler.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct ExpansionIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ExpansionIFace *Self);
	ULONG APICALL (*Release)(struct ExpansionIFace *Self);
	void APICALL (*Expunge)(struct ExpansionIFace *Self);
	struct Interface * APICALL (*Clone)(struct ExpansionIFace *Self);
	void APICALL (*AddConfigDev)(struct ExpansionIFace *Self, struct ConfigDev * configDev);
	BOOL APICALL (*AddBootNode)(struct ExpansionIFace *Self, LONG bootPri, ULONG flags, APTR deviceNode, struct ConfigDev * configDev);
	ULONG APICALL (*AllocBoardMem)(struct ExpansionIFace *Self, ULONG slotSpec);
	struct ConfigDev * APICALL (*AllocConfigDev)(struct ExpansionIFace *Self);
	APTR APICALL (*AllocExpansionMem)(struct ExpansionIFace *Self, ULONG numSlots, ULONG slotAlign);
	ULONG APICALL (*ConfigBoard)(struct ExpansionIFace *Self, APTR board, struct ConfigDev * configDev);
	ULONG APICALL (*ConfigChain)(struct ExpansionIFace *Self, APTR baseAddr);
	struct ConfigDev * APICALL (*FindConfigDev)(struct ExpansionIFace *Self, const struct ConfigDev * oldConfigDev, LONG manufacturer, LONG product);
	void APICALL (*FreeBoardMem)(struct ExpansionIFace *Self, ULONG startSlot, ULONG slotSpec);
	void APICALL (*FreeConfigDev)(struct ExpansionIFace *Self, struct ConfigDev * configDev);
	void APICALL (*FreeExpansionMem)(struct ExpansionIFace *Self, ULONG startSlot, ULONG numSlots);
	UBYTE APICALL (*ReadExpansionByte)(struct ExpansionIFace *Self, CONST_APTR board, ULONG offset);
	ULONG APICALL (*ReadExpansionRom)(struct ExpansionIFace *Self, CONST_APTR board, struct ConfigDev * configDev);
	void APICALL (*RemConfigDev)(struct ExpansionIFace *Self, struct ConfigDev * configDev);
	void APICALL (*WriteExpansionByte)(struct ExpansionIFace *Self, APTR board, ULONG offset, UBYTE byte);
	void APICALL (*ObtainConfigBinding)(struct ExpansionIFace *Self);
	void APICALL (*ReleaseConfigBinding)(struct ExpansionIFace *Self);
	void APICALL (*SetCurrentBinding)(struct ExpansionIFace *Self, struct CurrentBinding * currentBinding, ULONG bindingSize);
	ULONG APICALL (*GetCurrentBinding)(struct ExpansionIFace *Self, const struct CurrentBinding * currentBinding, ULONG bindingSize);
	struct DeviceNode * APICALL (*MakeDosNode)(struct ExpansionIFace *Self, CONST_APTR parmPacket);
	BOOL APICALL (*AddDosNode)(struct ExpansionIFace *Self, LONG bootPri, ULONG flags, struct DeviceNode * deviceNode);
	void APICALL (*WriteExpansionWord)(struct ExpansionIFace *Self, APTR board, ULONG offset, UWORD word);
	ULONG APICALL (*GetMachineInfo)(struct ExpansionIFace *Self, const struct TagItem * tagList);
	ULONG APICALL (*GetMachineInfoTags)(struct ExpansionIFace *Self, ...);
};

struct PCIIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PCIIFace *Self);
	ULONG APICALL (*Release)(struct PCIIFace *Self);
	void APICALL (*Expunge)(struct PCIIFace *Self);
	struct Interface * APICALL (*Clone)(struct PCIIFace *Self);
	struct PCIDevice * APICALL (*FindDevice)(struct PCIIFace *Self, const struct TagItem * tagList);
	struct PCIDevice * APICALL (*FindDeviceTags)(struct PCIIFace *Self, ...);
	void APICALL (*FreeDevice)(struct PCIIFace *Self, struct PCIDevice * device);
	struct PCIResourceRange * APICALL (*AllocResource)(struct PCIIFace *Self, ULONG ResType, ULONG NumBytes);
	void APICALL (*FreeResource)(struct PCIIFace *Self, struct PCIResourceRange * Resource);
};

struct PCIDevice
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PCIDevice *Self);
	ULONG APICALL (*Release)(struct PCIDevice *Self);
	void APICALL (*Expunge)(struct PCIDevice *Self);
	struct Interface * APICALL (*Clone)(struct PCIDevice *Self);
	UBYTE APICALL (*ReadConfigByte)(struct PCIDevice *Self, ULONG Offset);
	UWORD APICALL (*ReadConfigWord)(struct PCIDevice *Self, ULONG Offset);
	ULONG APICALL (*ReadConfigLong)(struct PCIDevice *Self, ULONG Offset);
	void APICALL (*WriteConfigByte)(struct PCIDevice *Self, ULONG Offset, UBYTE Value);
	void APICALL (*WriteConfigWord)(struct PCIDevice *Self, ULONG Offset, UWORD Value);
	void APICALL (*WriteConfigLong)(struct PCIDevice *Self, ULONG Offset, ULONG Value);
	UBYTE APICALL (*InByte)(struct PCIDevice *Self, ULONG Port);
	UWORD APICALL (*InWord)(struct PCIDevice *Self, ULONG Port);
	ULONG APICALL (*InLong)(struct PCIDevice *Self, ULONG Port);
	void APICALL (*OutByte)(struct PCIDevice *Self, ULONG Port, UBYTE Value);
	void APICALL (*OutWord)(struct PCIDevice *Self, ULONG Port, UWORD Value);
	void APICALL (*OutLong)(struct PCIDevice *Self, ULONG Port, ULONG Value);
	struct PCIResourceRange * APICALL (*GetResourceRange)(struct PCIDevice *Self, UBYTE BaseNum);
	void APICALL (*FreeResourceRange)(struct PCIDevice *Self, struct PCIResourceRange * ResourceRange);
	ULONG APICALL (*GetCapabilities)(struct PCIDevice *Self);
	ULONG APICALL (*SetCapabilities)(struct PCIDevice *Self, ULONG Flags);
	void APICALL (*SetHALData)(struct PCIDevice *Self, APTR HALData);
	APTR APICALL (*GetHALData)(struct PCIDevice *Self);
	void APICALL (*SetResourceRange)(struct PCIDevice *Self, UBYTE BaseNum, struct PCIResourceRange * Range);
	struct Node * APICALL (*GetNode)(struct PCIDevice *Self);
	void APICALL (*SetAddress)(struct PCIDevice *Self, UBYTE Bus, UBYTE Dev, UBYTE Fn);
	void APICALL (*GetAddress)(struct PCIDevice *Self, UBYTE * Bus, UBYTE * Dev, UBYTE * Fn);
	BOOL APICALL (*Autoconfig)(struct PCIDevice *Self);
	APTR APICALL (*GetUserData)(struct PCIDevice *Self, UBYTE ItemNum);
	void APICALL (*SetUserData)(struct PCIDevice *Self, UBYTE ItemNum, APTR UserData);
	BOOL APICALL (*Lock)(struct PCIDevice *Self, UBYTE Mode);
	void APICALL (*Unlock)(struct PCIDevice *Self);
	ULONG APICALL (*MapInterrupt)(struct PCIDevice *Self);
	void APICALL (*SetEndian)(struct PCIDevice *Self, uint32 Mode);
	void APICALL (*InByteBlock)(struct PCIDevice *Self, uint32 Port, uint8 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	void APICALL (*InWordBlock)(struct PCIDevice *Self, uint32 Port, uint16 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	void APICALL (*InLongBlock)(struct PCIDevice *Self, uint32 Port, uint32 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	void APICALL (*OutByteBlock)(struct PCIDevice *Self, uint32 Port, uint8 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	void APICALL (*OutWordBlock)(struct PCIDevice *Self, uint32 Port, uint16 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	void APICALL (*OutLongBlock)(struct PCIDevice *Self, uint32 Port, uint32 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	struct PCICapability * APICALL (*GetFirstCapability)(struct PCIDevice *Self);
	struct PCICapability * APICALL (*GetNextCapability)(struct PCIDevice *Self, struct PCICapability * current);
	struct PCICapability * APICALL (*FindCapability)(struct PCIDevice *Self, uint32 id);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* EXPANSION_INTERFACE_DEF_H */
