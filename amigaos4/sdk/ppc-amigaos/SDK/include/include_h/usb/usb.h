#ifndef USB_USB_H
#define USB_USB_H
/*
**
** USB related information
**
** Copyright (c) 2001, Thomas Graff Thoeger
** Distributed by Hyperion Entertainment BV under permission.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(1)
   #endif
#elif defined(__VBCC__)
   #pragma pack(1)
#endif

/****************************************************************************/

/*
** Macros for Big/Little endian data swapping
*/

#ifndef LE_WORD
#define LE_WORD(a) ((uint16)(((a)>>8)|((a)<<8)))
#endif

#ifndef LE_LONG
#define LE_LONG(a) ((uint32)(((a)&0xFF000000)>>24)|(((a)&0xFF0000)>>8)|(((a)&0xFF00)<<8)|(((a)&0xFF)<<24))
#endif

/*
** Default Control Pipe request structure
**
**  Used on EndPoint zero requests, in the Setup packet sent to a USB Function
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusSetupData
{
    uint8   sd_RequestType; // Type of request (Direction, Type and Recipient information)
    uint8   sd_Request; // Request code
    uint16  sd_Value; // Request value argument
    uint16  sd_Index; // Request index argument
    uint16  sd_Length; // Length of data to transfer in data stage
};

// * RequestType values
#define USBSDT_DIR_HOSTTODEV    0x00    // (dummy direction constant)
#define USBSDT_DIR_DEVTOHOST    0x80

#define USBSDT_TYP_STANDARD     0x00    // (dummy type constant)
#define USBSDT_TYP_CLASS        0x20
#define USBSDT_TYP_VENDOR       0x40

#define USBSDT_REC_DEVICE       0x00    // (dummy recipient constant)
#define USBSDT_REC_INTERFACE    0x01
#define USBSDT_REC_ENDPOINT     0x02
#define USBSDT_REC_OTHER        0x03

// Bit masking of sections
#define USBSDTM_DIRECTION       0x80
#define USBSDTM_TYPE            0x60
#define USBSDTM_RECIPIENT       0x1F

/*
** Standard Request Codes (for Default Control Pipe)
**
**  these are normally accessed by USS's support functions,
**  but may be useful for HCDs.
*/

#define USBREQC_GET_STATUS          0
#define USBREQC_CLEAR_FEATURE       1
#define USBREQC_SET_FEATURE         3
#define USBREQC_SET_ADDRESS         5
#define USBREQC_GET_DESCRIPTOR      6
#define USBREQC_SET_DESCRIPTOR      7
#define USBREQC_GET_CONFIGURATION   8
#define USBREQC_SET_CONFIGURATION   9
#define USBREQC_GET_INTERFACE       10
#define USBREQC_SET_INTERFACE       11
#define USBREQC_SYNCH_FRAME         12

/*
** Descriptor types for GetDescriptor() and SetDescriptor()
*/

#define USBDESC_DEVICE					((uint8) 1)
#define USBDESC_CONFIGURATION			((uint8) 2)
#define USBDESC_STRING					((uint8) 3)
#define USBDESC_INTERFACE				((uint8) 4)
#define USBDESC_ENDPOINT				((uint8) 5)
#define USBDESC_DEVICE_QUALIFIER		((uint8) 6)		/* USB2 only */
#define USBDESC_OTHER_SPEED_CONFIG		((uint8) 7)		/* USB2 only */
#define USBDESC_INTERFACE_POWER			((uint8) 8)
#define USBDESC_OTG						((uint8) 9)
#define USBDESC_DEBUG					((uint8) 10)
#define USBDESC_INTERFACE_ASSOCIATION	((uint8) 11)
#define USBDESC_BOS						((uint8) 15)
#define USBDESC_DEVICE_CAPABILITY		((uint8) 16)
#define USBDESC_SUPERSPEED_USB_ENDPOINT_COMPANION		((uint8) 48)	/* From USB3 */
#define USBDESC_SUPERSPEEDPLUS_ISO_ENDPOINT_COMPANION	((uint8) 49)	/* From USB3.2 */


/*
** Feature constants for SetFeature() and ClearFeature()
*/

#define USBFEAT_DEVICE_REMOTE_WAKEUP    1
#define USBFEAT_ENDPOINT_HALT           0


/*
** Descriptor header
**
**  All USB descriptors start with one of these
*/

struct USBBusDscHead
{
    uint8   dh_Length; // Byte size of descriptor (including this header)
    uint8   dh_Type; // Type of descriptor following this header. One of the USBDESC_xxx constants.
};

/*
** Device descriptor
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusDevDsc
{
    struct USBBusDscHead    Head;

    uint16  dd_USBVer; // USB Specification Version the device is compliant with (BCD)

    uint8   dd_Class; // Device class
    uint8   dd_Subclass; // Device subclass
    uint8   dd_Protocol; // Protocol used by device

    uint8   dd_MaxPacketSize0; // EndPoint Zero max packet size

    uint16  dd_VendorID; // Device vendor's ID number
    uint16  dd_Product; // Vendor's product code for device
    uint16  dd_DevVer; // Device version (BCD)

    uint8   dd_ManufacturerStr; // Index of string holding manufacturer name
    uint8   dd_ProductStr; // Index of string holding product name/description
    uint8   dd_SerialStr; // Index of string holding serial number

    uint8   dd_NumConfigs; // Number of possible configurations this device supports
};
// Note that the struct size is only WORD alligned!

/*
** Configuration descriptor
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusCfgDsc
{
    struct USBBusDscHead    Head;

    uint16  cd_TotalLength; // Total length of all descriptors returned with the Configuration
                            // descriptor (Configuration, interface, endpoints etc.)
    uint8   cd_NumInterfaces; // Number of interfaces supported by Configuration
    uint8   cd_ConfigID; // Value used for identifying this Configuration in a SetConfiguration() call
    uint8   cd_ConfigStr; // Index of string holding Configuration description
    uint8   cd_Attributes; // Attributes of Configuration (see flags below)
    uint8   cd_MaxPower; // Max power consumption (in 2mA unit counts) by device if using this Configuration (5 = 10mA consumed)
};
// Note that the struct size is only BYTE alligned!

// ** Attributes
#define USBCFGATRF_SELFPOWERED  0x40
#define USBCFGATRF_REMOTEWAKEUP 0x20

/*
** Interface Association descriptor
**
** If present this is part of the configuration descriptor chain.
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusIntAssocDsc
{
	struct USBBusDscHead	Head;
	
	uint8	FirstInterface;	/* Interface number of first interface in the association */
	uint8	InterfaceCount;	/* Number of contiguous interfaces belonging to association */

	uint8	Class;			/* Class code of functionality provided by interface association */
	uint8	SubClass;		/* SubClass code of functionality provided by interface association */
	uint8	Protocol;		/* Protocol code of functionality provided by interface association */

	uint8	FunctionStr;	/* Index of string descriptor containing interface association name */
};


/*
** Interface descriptor
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusIntDsc
{
    struct USBBusDscHead    Head;

    uint8   id_InterfaceID; // ID number of Interface descriptor
    uint8   id_AltSetting; // Value used for selecting alternate setting for Interface
    uint8   id_NumEndPoints; // Number of EndPoints (excluding EndPoint zero)

    uint8   id_Class; // Interface class code
    uint8   id_Subclass; // Interface subclass code
    uint8   id_Protocol; // Protocol used by Interface

    uint8   id_InterfaceStr; // Index of string describing the Interface
};
// Note that the struct size is only BYTE alligned!

/*
** EndPoint descriptor
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusEPDsc
{
    struct USBBusDscHead    Head;

    uint8   ed_Address;			/* EndPoint address in the USB device of the described EndPoint */
    uint8   ed_Attributes;		/* EndPoint attributes (see defs. below) */

    uint16  ed_MaxPacketSize;	/* Maximum packet size supported by EndPoint (bitmasking required!) */
    uint8   ed_Interval; 		/* Polling interval needed by EndPoint. The unit depends on the
								   attachment speed of the containing USB device:
								    - For Low/Full speed unit is frames (1ms units)
								    - For High/Super speed unit is microframes (125us units)
								   Special considerations for interrupt and isochronous, so check
								   the USB specs for more info (USB2 spec for low/full/high speed,
								   USB3 spec for superspedd) */
};
// Note that the struct size is only BYTE alligned!

// ** Address
// Bitmask for extraction
#define USBEPADRM_EPNUMBER  0x0F
#define USBEPADRM_DIRECTION 0x80

// Direction
#define USBEPADR_DIR_OUT    0x00    // OUT EndPoint (dummy value)
#define USBEPADR_DIR_IN     0x80    // IN EndPoint

// ** Attributes
// Bitmasks for extracting endpoint attribute values
#define USBEPATRM_TRANSFERTYPE  		0x03	// Bitmask for extracting Transfer Type
#define USBEPATRM_SYNCHRONIZATIONTYPE	0x0C	// Isochronous synchronization type
#define USBEPATRM_USAGETYPE				0x30	// Isochronous usage type

// Transfer types
#define USBEPTT_CONTROL					0x00
#define USBEPTT_ISOCHRONOUS				0x01
#define USBEPTT_BULK					0x02
#define USBEPTT_INTERRUPT				0x03

// Isochronous synchronization types
#define USBEP_ISOSYNC_NONE				0x00
#define USBEP_ISOSYNC_ASYNCHRONOUS		0x04
#define USBEP_ISOSYNC_ADAPTIVE			0x08
#define USBEP_ISOSYNC_SYNCHRONOUS		0x0C

// Isochronous endpoint usage type
#define USBEP_ISOUSAGE_DATA				0x00
#define USBEP_ISOUSAGE_FEEDBACK			0x10
#define USBEP_ISOUSAGE_IMPLICITFEEDBACK	0x30

// ** MaxPacketSize masks (use on endianness converted data!)
#define USBEP_SIZEM_MAXPACKETSIZE		0x07FF	// MaxPacketSize
#define USBEP_SIZEM_ADDITIONALTRANSACT	0x1800	// Isochronous/interrupt endpoint additional transactions per microframe


/*
** SuperSpeed EndPoint Companion descriptor
**
** If present this is part of the configuration descriptor chain, directly following the descriptor
** of the EndPoint which it relates to.
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusEPCompanionDsc
{
    struct USBBusDscHead    Head;

	uint8	MaxBurst;			/* Maximum number of packets for endpoints in bursts (Value range 0-15).
								   Zero is one-packet bursts, 15 is 16-packet bursts */
	uint8	Attributes;			/* EndPoint attributes. See USBEP_SSCATTR_xxx values */
	uint16	BytesPerInterval;	/* The maximum number of bytes this endpoint will transfer every
								   service interval. Only valid for periodic endpoints */
};

// Attribute values
#define USBEP_SSCATTR_BULK_MAXSTREAMSMASK	0x1F	/* Mask for extracting MaxStreams count of a Bulk EndPoint */
#define USBEP_SSCATTR_ISO_MULTMASK			0x03	/* Mask for extracting multiplier for calculating
													   Max Number Of Packets per service interval for an
													   isochronous EndPoint:
													    MaxPackets = (MaxBurst + 1) * (Mult + 1) */


/*
** Language descriptor
**
**  The Language descriptor is a std. Descriptor Header followed by a uint16 array holding
**  the UNICODE IDs of the languages supported by the USB device.
**  The descriptor is obtained by requesting string index zero from a device.
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

// no struct

/*
** String descriptor
**
**  The String descriptor is a std. Descriptor Header followed by the UNICODE string itself.
**  The string is *not* NUL terminated - the size of the String descriptor dictates the
**  length of the string (strlen = dh_Length-2)
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

// no struct

/*
** GetStatus request definitions
**
*/

// Device-level GetStatus
#define USBGETSTATUS_DEVICE_SELFPOWERED     0x0001
#define USBGETSTATUS_DEVICE_REMOTEWAKEUP    0x0002

// Interface-level GetStatus
// <no definitions>

// EndPoint-level GetStatus
#define USBGETSTATUS_ENDPOINT_HALT          0x0001

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif

#ifdef __cplusplus
}
#endif

/****************************************************************************/

#endif /* USB_USB_H */
