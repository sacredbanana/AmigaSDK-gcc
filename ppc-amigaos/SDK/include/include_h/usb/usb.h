#ifndef USB_USB_H
#define USB_USB_H
/*
** $VER: usb.h 53.34 (09.12.2021)
**
** USB related information
**
** Copyright (c) 2001, Thomas Graff Thoeger
** Distributed by Hyperion Entertainment CVBA under permission.
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
#define LE_WORD(a) ((UWORD)(((a)>>8)|((a)<<8)))
#endif

#ifndef LE_LONG
#define LE_LONG(a) ((ULONG)(((a)&0xFF000000)>>24)|(((a)&0xFF0000)>>8)|(((a)&0xFF00)<<8)|(((a)&0xFF)<<24))
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
    UBYTE   sd_RequestType; // Type of request (Direction, Type and Recipient information)
    UBYTE   sd_Request; // Request code
    UWORD   sd_Value; // Request value argument
    UWORD   sd_Index; // Request index argument
    UWORD   sd_Length; // Length of data to transfer in data stage
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

#define USBDESC_DEVICE          ((UBYTE) 1)
#define USBDESC_CONFIGURATION   ((UBYTE) 2)
#define USBDESC_STRING          ((UBYTE) 3)
#define USBDESC_INTERFACE       ((UBYTE) 4)
#define USBDESC_ENDPOINT        ((UBYTE) 5)

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
    UBYTE   dh_Length; // Byte size of descriptor (including this header)
    UBYTE   dh_Type; // Type of descriptor following this header. One of the USBDESC_xxx constants.
};

/*
** Device descriptor
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusDevDsc
{
    struct USBBusDscHead    Head;

    UWORD   dd_USBVer; // USB Specification Version the device is compliant with (BCD)

    UBYTE   dd_Class; // Device class
    UBYTE   dd_Subclass; // Device subclass
    UBYTE   dd_Protocol; // Protocol used by device

    UBYTE   dd_MaxPacketSize0; // EndPoint Zero max packet size

    UWORD   dd_VendorID; // Device vendor's ID number
    UWORD   dd_Product; // Vendor's product code for device
    UWORD   dd_DevVer; // Device version (BCD)

    UBYTE   dd_ManufacturerStr; // Index of string holding manufacturer name
    UBYTE   dd_ProductStr; // Index of string holding product name/description
    UBYTE   dd_SerialStr; // Index of string holding serial number

    UBYTE   dd_NumConfigs; // Number of possible configurations this device supports
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

    UWORD   cd_TotalLength; // Total length of all descriptors returned with the Configuration
                            // descriptor (Configuration, interface, endpoints etc.)
    UBYTE   cd_NumInterfaces; // Number of interfaces supported by Configuration
    UBYTE   cd_ConfigID; // Value used for identifying this Configuration in a SetConfiguration() call
    UBYTE   cd_ConfigStr; // Index of string holding Configuration description
    UBYTE   cd_Attributes; // Attributes of Configuration (see flags below)
    UBYTE   cd_MaxPower; // Max power consumption (in 2mA unit counts) by device if using this Configuration (5 = 10mA consumed)
};
// Note that the struct size is only BYTE alligned!

// ** Attributes
#define USBCFGATRF_SELFPOWERED  0x40
#define USBCFGATRF_REMOTEWAKEUP 0x20

/*
** Interface descriptor
*/

struct USBBusIntDsc
{
    struct USBBusDscHead    Head;

    UBYTE   id_InterfaceID; // ID number of Interface descriptor
    UBYTE   id_AltSetting; // Value used for selecting alternate setting for Interface
    UBYTE   id_NumEndPoints; // Number of EndPoints (excluding EndPoint zero)

    UBYTE   id_Class; // Interface class code
    UBYTE   id_Subclass; // Interface subclass code
    UBYTE   id_Protocol; // Protocol used by Interface

    UBYTE   id_InterfaceStr; // Index of string describing the Interface
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

    UBYTE   ed_Address; // EndPoint address in the USB device of the described EndPoint
    UBYTE   ed_Attributes; // EndPoint attributes (see defs. below)

    UWORD   ed_MaxPacketSize; // Maximum packet size supported by EndPoint
    UBYTE   ed_Interval; // Polling interval needed by EndPoint. Expressed in milliseconds.
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
// Bitmask for extracting Transfer Type
#define USBEPATRM_TRANSFERTYPE  0x03


// Transfer types
#define USBEPTT_CONTROL     0
#define USBEPTT_ISOCHRONOUS 1
#define USBEPTT_BULK        2
#define USBEPTT_INTERRUPT   3

/*
** Language descriptor
**
**  The Language descriptor is a std. Descriptor Header followed by a UWORD array holding
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
#define USBGETSTAUS_ENDPOINT_HALT           0x0001

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
