#ifndef EXPANSION_PCI_H
#define EXPANSION_PCI_H
/*
**    $VER: pci.h 53.29 (10.8.2015)
**
**    Structures and defines for the expansion.library
**    PCI Interface.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef   EXEC_NODES_H
#include <exec/nodes.h>
#endif

#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#elif defined(__SASC)
   #pragma msg 79 ignore push
#endif

/****************************************************************************/

/*
** A PCI Resource range is specified with this structure. 
** Resource ranges can be either IO or Memory.
*/

struct PCIResourceRange
{
    struct Node Node;        /* Node for chaining. ln_Name */
                             /* contains the name of the range */

    ULONG       BaseAddress; /* Base address of resource range */
    ULONG       Size;        /* Size of the base */

    ULONG       Physical;    /* Physical base address of the range. */

    ULONG       Flags;       /* Flags. See below */
};

enum enPCIResourceFlags
{
    PCI_RANGE_IO       = 0x0001, /* PCI I/O Range */
    PCI_RANGE_MEMORY   = 0x0002, /* PCI Memory Range */
    PCI_RANGE_PREFETCH = 0x0004  /* Prefetchable memory range. May only
                                    be used together with PCI_RANGE_MEMORY */
};

/*
 * Flags for PCI Device Capabilities 
 */
#define PCI_CAP_BUSMASTER    0x00000001UL /* Full PCI Busmaster support */
#define PCI_CAP_INTERCARD    0x00000002UL /* Busmaster transfers possible
                                           * between two PCI cards */
#define PCI_CAP_CONFIGME     0x00000004UL /* If set, device has not yet been
                                           * configured */
#define PCI_CAP_BRIDGE       0x00000008UL /* Device is a PCI-to-PCI bridge
                                           * device */
#define PCI_CAP_CARDBUS      0x00000010UL /* Device is a cardbus device */
#define PCI_CAP_PUBLIC_FLAGS 0x000000FFUL /* Mask for public flags */
#define PCI_CAP_SETCLR       0x80000000UL /* Set/Clear bit */

enum enExpansionConstants
{
    PCI_NUM_RESOURCE_RANGES = 6,
    PCI_NUM_USER_DATA       = 5
};

enum enPCILockMode
{
    PCI_LOCK_SHARED    = 1,
    PCI_LOCK_EXCLUSIVE = 2
};

enum enPCIConfigSpace
{
    PCI_VENDOR_ID           = 0x00,
    PCI_DEVICE_ID           = 0x02,
    PCI_COMMAND             = 0x04,
    PCI_STATUS              = 0x06,
    PCI_CLASS_REVISION      = 0x08,
    PCI_REVISION_ID         = 0x08,
    PCI_CLASS_PROG          = 0x09,
    PCI_CLASS_DEVICE        = 0x0A,
    PCI_CACHE_LINE_SIZE     = 0x0C,
    PCI_LATENCY_TIMER       = 0x0D,
    PCI_HEADER_TYPE         = 0x0E,
    PCI_BIST                = 0x0F,
    PCI_BASE_ADDRESS_0      = 0x10,
    PCI_BASE_ADDRESS_1      = 0x14,
    PCI_BASE_ADDRESS_2      = 0x18,
    PCI_BASE_ADDRESS_3      = 0x1C,
    PCI_BASE_ADDRESS_4      = 0x20,
    PCI_BASE_ADDRESS_5      = 0x24,
    PCI_CARDBUS_CIS         = 0x28,
    PCI_SUBSYSTEM_VENDOR_ID = 0x2C,
    PCI_SUBSYSTEM_ID        = 0x2E,
    PCI_ROM_ADDRESS         = 0x30,
    PCI_CAPABILITY_LIST     = 0x34,
    PCI_INTERRUPT_LINE      = 0x3C,
    PCI_INTERRUPT_PIN       = 0x3D,
    PCI_MIN_GNT             = 0x3E,
    PCI_MAX_LAT             = 0x3F,

    PCI_PRIMARY_BUS         = 0x18,
    PCI_SECONDARY_BUS       = 0x19,
    PCI_SUBORDINATE_BUS     = 0x1A,
    PCI_SEC_LATENCY_TIMER   = 0x1B,
    PCI_IO_BASE             = 0x1C,
    PCI_IO_LIMIT            = 0x1D,
    PCI_SEC_STATUS          = 0x1E,
    PCI_MEMORY_BASE         = 0x20,
    PCI_MEMORY_LIMIT        = 0x22,
    PCI_PREF_MEMORY_BASE    = 0x24,
    PCI_PREF_MEMORY_LIMIT   = 0x26,
    PCI_PREF_BASE_UPPER32   = 0x28,
    PCI_PREF_LIMIT_UPPER32  = 0x2C,
    PCI_IO_BASE_UPPER_16    = 0x30,
    PCI_IO_LIMIT_UPPER16    = 0x32,
    PCI_ROM_ADDRESS1        = 0x38,
    PCI_BRIDGE_CONTROL      = 0x3E
};

enum enPCICommandBits
{
    PCI_COMMAND_IO          = 0x01,
    PCI_COMMAND_MEMORY      = 0x02,
    PCI_COMMAND_MASTER      = 0x04,
    PCI_COMMAND_SPECIAL     = 0x08,
    PCI_COMMAND_INVALIDATE  = 0x10,
    PCI_COMMAND_VGA_PALETTE = 0x20,
    PCI_COMMAND_PARITY      = 0x40,
    PCI_COMMAND_WAIT        = 0x80,
    PCI_COMMAND_SERR        = 0x100,
    PCI_COMMAND_FAST_BACK   = 0x200,
    PCI_COMMAND_INT_DISABLE = 0x400		/* since PCI 2.3 */
};

enum enPCIStatusBits
{
	PCI_STATUS_INTERRUPT		= 0x08, /* since PCI 2.3 */
    PCI_STATUS_CAP_LIST         = 0x10,
    PCI_STATUS_66MHZ            = 0x20,
    PCI_STATUS_UDF              = 0x40,
    PCI_STATUS_FAST_BACK        = 0x80,
    PCI_STATUS_PARITY           = 0x100,
    PCI_STATUS_DEVSEL_MASK      = 0x600,
    PCI_STATUS_DEVSEL_FAT       = 0x000,
    PCI_STATUS_DEVSEL_MEDIUM    = 0x200,
    PCI_STATUS_DEVSEL_SLOW      = 0x400,
    PCI_STATUS_SIG_TARGET_ABORT = 0x800,
    PCI_STATUS_REC_TARGET_ABORT = 0x1000,
    PCI_STATUS_REC_MASTER_ABORT = 0x2000,
    PCI_STATUS_SIG_SYSTEM_ERROR = 0x4000,
    PCI_STATUS_DETECTED_PARITY  = 0x8000
};

enum enPCIHeaderBits
{
    PCI_HEADER_TYPE_NORMAL        = 0,
    PCI_HEADER_TYPE_BRIDGE        = 1,
    PCI_HEADER_TYPE_CARDBUS       = 2,
    PCI_HEADER_TYPE_MULTIFUNCTION = 0x80
};

enum enPCIBaseAddressBits
{
    PCI_BASE_ADDRESS_SPACE         = 0x01,
    PCI_BASE_ADDRESS_SPACE_IO      = 0x01,
    PCI_BASE_ADDRESS_SPACE_MEMORY  = 0x00,
    PCI_BASE_ADDRESS_MEM_TYPE_MASK = 0x06,
    PCI_BASE_ADDRESS_MEM_TYPE_32   = 0x00,
    PCI_BASE_ADDRESS_MEM_TYPE_1M   = 0x02,
    PCI_BASE_ADDRESS_MEM_TYPE_64   = 0x04,
    PCI_BASE_ADDRESS_MEM_PREFETCH  = 0x08
};

#define PCI_BASE_ADDRESS_MEM_MASK (0xFFFFFFF0UL)
#define PCI_BASE_ADDRESS_IO_MASK  (0xFFFFFFF8UL)

#define PCI_ROM_ADDRESS_ENABLE    0x01
#define PCI_ROM_ADDRESS_MASK      (0xFFFF8000UL)

/*
 * This needs to be #define'd so that it adapts to the data type
 * with which it is being used
 */
#define PCI_ANY_ID (~0)

/*
 * Tag Item definitions for FindDevice
 */
#define FDT_VendorID      (TAG_USER + 1)
#define FDT_DeviceID      (TAG_USER + 2)
#define FDT_Index         (TAG_USER + 3)
#define FDT_Class         (TAG_USER + 4)
#define FDT_ClassMask     (TAG_USER + 5)
#define FDT_CandidateList (TAG_USER + 6)
#define FDT_BusNr		  (TAG_USER + 7)
#define FDT_DeviceNr	  (TAG_USER + 8)
#define FDT_FunctionNr    (TAG_USER + 9)

/*
 * Mode definitions for access endian
 */
enum enPCIEndianMode
{
    PCI_MODE_NATIVE_ENDIAN  = 0, /* Means big endian on PowerPC */
    PCI_MODE_REVERSE_ENDIAN = 1, /* Means little endian on PowerPC */
#ifdef __PPC__
    PCI_MODE_BIG_ENDIAN     = PCI_MODE_NATIVE_ENDIAN,
    PCI_MODE_LITTLE_ENDIAN  = PCI_MODE_REVERSE_ENDIAN
#endif
};         





/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#elif defined(__SASC)
   #pragma msg 79 pop
#endif

/****************************************************************************/


/* PCI Capability entry.
 * The system enumerates capabilities of PCI devices after scanning the controller.
 * Each node corresponds to one capability read from the capability pointer in the
 * devices config space.
 * The layout, data and size of the capabilities depends on the actual capability. This
 * node is just the common header containing the link for the list, the type of the
 * capability, and the size of the whole node (including the header).
 */
struct PCICapability
{
	struct MinNode			 Node;					/* Links capabilities */
	uint32					 Type;					/* Type, see enPCICapabilityID */
	uint32					 Size;					/* Size of the complete structure, including header */
	uint32					 CapOffset;				/* Base offset in config space */
};


/* PCI Capabilities IDs
 * These constants identify the type of the PCICapability strucutre (the Type field above)
 * to select the correct specific PCI Capability structure (see below)
 */
enum enPCICapabilityID
{
	PCI_CAPABILITYID_PM		= 0x01,				/* Power Management */
	PCI_CAPABILITYID_AGP	= 0x02,				/* Accelerated Graphics Port */
	PCI_CAPABILITYID_VPD	= 0x03,				/* Vital Product Data */
	PCI_CAPABILITYID_SLOTID = 0x04,				/* Slot identification */
	PCI_CAPABILITYID_MSI	= 0x05,				/* Message Signaled Interrupts */
	PCI_CAPABILITYID_CHSWP	= 0x06,				/* Compact PCI hotswap */
	PCI_CAPABILITYID_PCIX	= 0x07,				/* PCIX */
	PCI_CAPABILITYID_AMD	= 0x08,				/* Reserved for AMD */
	PCI_CAPABILITYID_VENDOR = 0x09,				/* Vendor specific */
	PCI_CAPABILITYID_DEBUG	= 0x0a,				/* Debug Port */
	PCI_CAPABILITYID_CPRSC  = 0x0b,				/* Compact PCI central resource control */
	PCI_CAPABILITYID_SHPC	= 0x0c,				/* Standard Hotplug Controller */
	PCI_CAPABILITYID_BRIDGE = 0x0d,				/* Bridge subsystem vendor/device ID */
	PCI_CAPABILITYID_AGP3	= 0x0e,				/* AGP PCI-PCI bridge */
	PCI_CAPABILITYID_SECDEV = 0x0f,				/* Secure device */
	PCI_CAPABILITYID_EXP	= 0x10,				/* PCIe */
	PCI_CAPABILITYID_MSIX	= 0x11,				/* MSI-X */
	PCI_CAPABILITYID_SATA   = 0x12,				/* SATA */
	PCI_CAPABILITYID_AF		= 0x13,				/* Advanced Feature */
};

enum enCapMSIRegs
{
	PCI_MSI_CONTROL			= 2,				/* Message Control Register */
	PCI_MSI_ADDRESS_LOW		= 4,				/* Message Address Register, low 32 bit */
	PCI_MSI_ADDRESS_HIGH	= 8,				/* Message Address Register, high 32 bit */
	PCI_MSI_DATA_32			= 8,				/* Message Data Register for 32 bit structure */
	PCI_MSI_DATA_64			= 12,				/* Message Data Register for 64 bit structure */
	PCI_MSI_MASK_32			= 12,				/* Message Mask Register for 32 bit */
	PCI_MSI_MASK_64			= 16,				/* Message Mask Register for 64 bit */
	PCI_MSI_PENDING_32		= 16,				/* Message Pending Register for 32 bit */
	PCI_MSI_PENDING_64		= 20,				/* Message Pending Register for 64 bit */
};

enum enCapMSIBits
{
	PCI_MSI_CONTROL_ENABLE	= 0x0001,			/* Enable MSI */
	PCI_MSI_CONTROL_MCAP	= 0x000e,			/* Multi Message Capable Mask */
	PCI_MSI_CONTROL_MEN		= 0x0070,			/* Multi Message Enable Mask */
	PCI_MSI_CONTROL_64		= 0x0080,			/* Structure is 64 bit */
	PCI_MSI_CONTROL_MASK	= 0x0100,			/* Individual masking allowed */
};

/* Message Signaled Interrupt CAP */
struct PCICapability_MSI
{
	struct PCICapability 	 CapHeader;

	BOOL 					 Is64Bit;				/* True if the device is capable of 64 bit MSI addresses */
	uint64					 MessageAddress;		/* The message target address. Note that the interrupt controller code
													 * has to set this up accordingly. 0 means MSI is disabled for this device
													 */

};

/****************************************************************************/

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* EXPANSION_PCI_H */
