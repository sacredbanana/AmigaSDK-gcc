#ifndef LIBRARIES_PCIX_H
#define LIBRARIES_PCIX_H

#include <utility/tagitem.h>

/*
 * PCIGetBoardAttr() attributes
 */

#define	PCIXTAG_Dummy			(TAG_USER + 0x100000)

#define	PCIXTAG_BUS			(PCIXTAG_Dummy + 0)
#define	PCIXTAG_BRIDGENAME		(PCIXTAG_Dummy + 1)
#define	PCIXTAG_DEV			(PCIXTAG_Dummy + 2)
#define	PCIXTAG_FUNCTION		(PCIXTAG_Dummy + 3)
#define	PCIXTAG_ROMADDRESS		(PCIXTAG_Dummy + 4)
#define	PCIXTAG_ROMSIZE			(PCIXTAG_Dummy + 5)
#define	PCIXTAG_BASEADDRESS0		(PCIXTAG_Dummy + 20)
#define	PCIXTAG_BASEADDRESS1		(PCIXTAG_Dummy + 21)
#define	PCIXTAG_BASEADDRESS2		(PCIXTAG_Dummy + 22)
#define	PCIXTAG_BASEADDRESS3		(PCIXTAG_Dummy + 23)
#define	PCIXTAG_BASEADDRESS4		(PCIXTAG_Dummy + 24)
#define	PCIXTAG_BASEADDRESS5		(PCIXTAG_Dummy + 25)
#define	PCIXTAG_BASESIZE0		(PCIXTAG_Dummy + 26)
#define	PCIXTAG_BASESIZE1		(PCIXTAG_Dummy + 27)
#define	PCIXTAG_BASESIZE2		(PCIXTAG_Dummy + 28)
#define	PCIXTAG_BASESIZE3		(PCIXTAG_Dummy + 29)
#define	PCIXTAG_BASESIZE4		(PCIXTAG_Dummy + 30)
#define	PCIXTAG_BASESIZE5		(PCIXTAG_Dummy + 31)

/*
 * PCIGetBusAttr() special attributes
 */

#define	PCIXTAG_SLOTS			(PCIXTAG_Dummy + 32)
#define	PCIXTAG_IOBASE			(PCIXTAG_Dummy + 33)
/*
 * Normal Attribute
 */
#define PCIXTAG_OWNER			(PCIXTAG_Dummy + 40)

/*
 * PCI ConfigSpace offsets for the
 * PCIReadConfigByte()
 * PCIReadConfigWord()
 * PCIReadConfigLong()
 * PCIWriteConfigByte()
 * PCIWriteConfigWord()
 * PCIWriteConfigLong()
 * functions
 */

#define	PCIXCONFIG_VENDOR			(0x0)
#define	PCIXCONFIG_DEVICE			(0x2)
#define	PCIXCONFIG_COMMAND			(0x4)
#define	PCIXCONFIG_STATUS			(0x6)
#define	PCIXCONFIG_REVISION			(0x8)
#define	PCIXCONFIG_PROGINTERFACE		(0x9)
#define	PCIXCONFIG_SUBCLASS			(0xa)
#define	PCIXCONFIG_CLASS			(0xb)
#define	PCIXCONFIG_CACHELINESIZE		(0xc)
#define	PCIXCONFIG_LATENCYTIMER			(0xd)
#define	PCIXCONFIG_HEADERTYPE			(0xe)
#define	PCIXCONFIG_BIST				(0xf)
#define	PCIXCONFIG_BASE0			(0x10)
#define	PCIXCONFIG_BASE1			(0x14)
#define	PCIXCONFIG_BASE2			(0x18)
#define	PCIXCONFIG_BASE3			(0x1c)
#define	PCIXCONFIG_BASE4			(0x20)
#define	PCIXCONFIG_BASE5			(0x24)
#define	PCIXCONFIG_CARDBUSCIS			(0x28)
#define	PCIXCONFIG_SUBSYSTEMVENDORID		(0x2c)
#define	PCIXCONFIG_SUBSYSTEMID			(0x2e)
#define	PCIXCONFIG_ROMBASE			(0x30)
#define	PCIXCONFIG_CAPPTR			(0x34)
#define	PCIXCONFIG_RESERVED2			(0x38)
#define	PCIXCONFIG_INTERRUPTLINE		(0x3c)
#define	PCIXCONFIG_INTERRUPTPIN			(0x3d)
#define	PCIXCONFIG_MINGNT			(0x3e)
#define	PCIXCONFIG_MAXLAT			(0x3f)


/*
 * PCIFindBoardTagList() attributes
 * PCIFindBridgeTagList() attributes
 *  only PCIXFINDTAG_NAME
 */

#define	PCIXFINDTAG_Dummy		(TAG_USER + 0x100100)
#define	PCIXFINDTAG_BUS			(PCIXFINDTAG_Dummy + 0x1)
/*
 * Only search in a specific Device Slot
 */
#define	PCIXFINDTAG_DEV			(PCIXFINDTAG_Dummy + 0x2)
/*
 * Only search in a specific Function
 */
#define	PCIXFINDTAG_FUNCTION		(PCIXFINDTAG_Dummy + 0x3)
/*
 * PCI Class
 */
#define	PCIXFINDTAG_CLASS		(PCIXFINDTAG_Dummy + 0x4)
/*
 * PCI Vendor
 */
#define	PCIXFINDTAG_VENDOR		(PCIXFINDTAG_Dummy + 0x5)
/*
 * PCI Device
 */
#define	PCIXFINDTAG_DEVICE		(PCIXFINDTAG_Dummy + 0x6)
/*
 * Care for hidden functions.
 * There are board with hidden functions, though
 * they aren't marked multifunction.
 */
#define	PCIXFINDTAG_SHOWHIDDEN		(PCIXFINDTAG_Dummy + 0x7)
/*
 * Name Search Tag
 * Only used with PCIFindBusTagList()
 */
#define	PCIXFINDTAG_NAME		(PCIXFINDTAG_Dummy + 0x8)
/*
 * Ignore already owned boards.
 */
#define	PCIXFINDTAG_IGNOREOWNED		(PCIXFINDTAG_Dummy + 0x9)
/*
 * PCI SubClass
 */
#define	PCIXFINDTAG_SUBCLASS		(PCIXFINDTAG_Dummy + 0xa)
/*
 * Class and SubClass combined
 * for the the PCI_CLASS_ defines below
 */
#define	PCIXFINDTAG_FULLCLASS		(PCIXFINDTAG_Dummy + 0xc)


/*
 * PCICreateIntObject() attributes
 */
#define	PCIXINTTAG_Dummy		(TAG_USER + 0x100200)
#define	PCIXINTTAG_PRI			(PCIXINTTAG_Dummy + 0x1)
/*
 * MorphOS Tag to specify the code type
 */
#define	PCIXINTTAG_MACHINE		(PCIXINTTAG_Dummy + 0x2)





#define PCI_CLASS_NOT_DEFINED		0x0000
#define PCI_CLASS_NOT_DEFINED_VGA	0x0001

#define PCI_BASE_CLASS_STORAGE		0x01
#define PCI_CLASS_STORAGE_SCSI		0x0100
#define PCI_CLASS_STORAGE_IDE		0x0101
#define PCI_CLASS_STORAGE_FLOPPY	0x0102
#define PCI_CLASS_STORAGE_IPI		0x0103
#define PCI_CLASS_STORAGE_RAID		0x0104
#define PCI_CLASS_STORAGE_OTHER		0x0180

#define PCI_BASE_CLASS_NETWORK		0x02
#define PCI_CLASS_NETWORK_ETHERNET	0x0200
#define PCI_CLASS_NETWORK_TOKEN_RING	0x0201
#define PCI_CLASS_NETWORK_FDDI		0x0202
#define PCI_CLASS_NETWORK_ATM		0x0203
#define PCI_CLASS_NETWORK_OTHER		0x0280

#define PCI_BASE_CLASS_DISPLAY		0x03
#define PCI_CLASS_DISPLAY_VGA		0x0300
#define PCI_CLASS_DISPLAY_XGA		0x0301
#define PCI_CLASS_DISPLAY_OTHER		0x0380

#define PCI_BASE_CLASS_MULTIMEDIA	0x04
#define PCI_CLASS_MULTIMEDIA_VIDEO	0x0400
#define PCI_CLASS_MULTIMEDIA_AUDIO	0x0401
#define PCI_CLASS_MULTIMEDIA_OTHER	0x0480

#define PCI_BASE_CLASS_MEMORY		0x05
#define  PCI_CLASS_MEMORY_RAM		0x0500
#define  PCI_CLASS_MEMORY_FLASH		0x0501
#define  PCI_CLASS_MEMORY_OTHER		0x0580

#define PCI_BASE_CLASS_BRIDGE		0x06
#define  PCI_CLASS_BRIDGE_HOST		0x0600
#define  PCI_CLASS_BRIDGE_ISA		0x0601
#define  PCI_CLASS_BRIDGE_EISA		0x0602
#define  PCI_CLASS_BRIDGE_MC		0x0603
#define  PCI_CLASS_BRIDGE_PCI		0x0604
#define  PCI_CLASS_BRIDGE_PCMCIA	0x0605
#define  PCI_CLASS_BRIDGE_NUBUS		0x0606
#define  PCI_CLASS_BRIDGE_CARDBUS	0x0607
#define  PCI_CLASS_BRIDGE_OTHER		0x0680


#define PCI_BASE_CLASS_COMMUNICATION	0x07
#define PCI_CLASS_COMMUNICATION_SERIAL	0x0700
#define PCI_CLASS_COMMUNICATION_PARALLEL 0x0701
#define PCI_CLASS_COMMUNICATION_OTHER	0x0780

#define PCI_BASE_CLASS_SYSTEM		0x08
#define PCI_CLASS_SYSTEM_PIC		0x0800
#define PCI_CLASS_SYSTEM_DMA		0x0801
#define PCI_CLASS_SYSTEM_TIMER		0x0802
#define PCI_CLASS_SYSTEM_RTC		0x0803
#define PCI_CLASS_SYSTEM_OTHER		0x0880

#define PCI_BASE_CLASS_INPUT		0x09
#define PCI_CLASS_INPUT_KEYBOARD	0x0900
#define PCI_CLASS_INPUT_PEN		0x0901
#define PCI_CLASS_INPUT_MOUSE		0x0902
#define PCI_CLASS_INPUT_OTHER		0x0980

#define PCI_BASE_CLASS_DOCKING		0x0a
#define PCI_CLASS_DOCKING_GENERIC	0x0a00
#define PCI_CLASS_DOCKING_OTHER		0x0a01

#define PCI_BASE_CLASS_PROCESSOR	0x0b
#define PCI_CLASS_PROCESSOR_386		0x0b00
#define PCI_CLASS_PROCESSOR_486		0x0b01
#define PCI_CLASS_PROCESSOR_PENTIUM	0x0b02
#define PCI_CLASS_PROCESSOR_ALPHA	0x0b10
#define PCI_CLASS_PROCESSOR_POWERPC	0x0b20
#define PCI_CLASS_PROCESSOR_CO		0x0b40

#define PCI_BASE_CLASS_SERIAL		0x0c
#define PCI_CLASS_SERIAL_FIREWIRE	0x0c00
#define PCI_CLASS_SERIAL_ACCESS		0x0c01
#define PCI_CLASS_SERIAL_SSA		0x0c02
#define PCI_CLASS_SERIAL_USB		0x0c03
#define PCI_CLASS_SERIAL_FIBER		0x0c04

#define PCI_CLASS_OTHERS		0xff



/* Disconnect Device
 */
#define  PCI_COMMAND_DISCONNECT		0x0

/* Enable response in I/O space
 */
#define  PCI_COMMANDF_IO		0x1

/* Enable response in Memory space
 */
#define  PCI_COMMANDF_MEMORY		0x2

/* Enable bus mastering
 */
#define  PCI_COMMANDF_MASTER		0x4

/* Enable response to special cycles
 */
#define  PCI_COMMANDF_SPECIAL		0x8

/* Use memory write and invalidate
 */
#define  PCI_COMMANDF_INVALIDATE	0x10

/* Enable palette snooping
 */
#define  PCI_COMMANDF_VGA_PALETTE	0x20

/* Enable parity checking
 */
#define  PCI_COMMANDF_PARITY		0x40

/* Enable address/data stepping
 */
#define  PCI_COMMANDF_WAIT 		0x80

/* Enable SERR Driver
 * PCI_COMMANDF_SERR AND PCI_COMMANDF_PARITY
 * must be set to report parity errors
 */
#define  PCI_COMMANDF_SERR		0x100

/* Enable back-to-back writes
 */
#define  PCI_COMMANDF_FAST_BACK		0x200




/* Capability..PCI 2.2
 */
#define  PCI_STATUSF_CAP_LIST		0x10
/* Support 66 Mhz PCI 2.1 bus
 */
#define  PCI_STATUSF_66MHZ		0x20
/* Support User Definable Features
 */
#define  PCI_STATUSF_UDF		0x40

/* Accept fast-back to back
 */
#define  PCI_STATUSF_FAST_BACK		0x80

/* Detected parity error
 */
#define  PCI_STATUSF_PARITY		0x100

/* DEVSEL timing
 */
#define  PCI_STATUSF_DEVSEL_MASK	0x600
#define  PCI_STATUSF_DEVSEL_FAST	0x000	
#define  PCI_STATUSF_DEVSEL_MEDIUM	0x200
#define  PCI_STATUSF_DEVSEL_SLOW	0x400

/* Set on target abort
 */
#define  PCI_STATUSF_SIG_TARGET_ABORT	0x800
/* Master ack of
 */
#define  PCI_STATUSF_REC_TARGET_ABORT	0x1000
/* Set on master abort
 */
#define  PCI_STATUSF_REC_MASTER_ABORT	0x2000

/* Set when we drive SERR
 */
#define  PCI_STATUSF_SIG_SYSTEM_ERROR	0x4000
/* Set on parity error
 */
#define  PCI_STATUSF_DETECTED_PARITY	0x8000

#endif	/* LIBRARIES_PCI_H */
