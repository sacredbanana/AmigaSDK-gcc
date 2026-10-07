#ifndef USB_DEV_BOS_H
#define USB_DEV_BOS_H
/*
**
** USB Binary Device Object Store descriptors
**
** Copyright (c) 2019, Thomas Graff Thoeger
** Distributed by Hyperion Entertainment BV under permission.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef USB_USB_H
#include <usb/usb.h>
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
** Binary Device Object Store descriptor
** This is the main descriptor of the BOS, and the only descriptor type of the BOS you
** can request with GET_DESCRIPTOR. All the other BOS sub-descriptors are attached
** after the BOS descriptor, just like a Configuration descriptor chain.
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusBosDsc
{
    struct USBBusDscHead    Head;
    
    uint16	TotalLength;	/* Byte size of this descriptor and all its sub-descriptors */
    uint8	NumDeviceCaps;	/* Number of capability (sub) descriptors in the BOS */
};


/*
** Header for a BOS device capability descriptor
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusBosHead
{
    struct USBBusDscHead	Head;	/* All BOS capability descriptors has descriptor type
									   USBDESC_DEVICE_CAPABILITY */
    
    uint8	CapabilityType;	/* The type of capability descriptor. BOSTYPE_xxx constant */
};

// Types of capability descriptors
#define BOSTYPE_WIRELESS_USB				0x01
#define BOSTYPE_USB2_EXTENSION				0x02
#define BOSTYPE_SUPERSPEED_USB				0x03
#define BOSTYPE_CONTAINER_ID				0x04
#define BOSTYPE_PLATFORM					0x05	/* From USB3.2 */
#define BOSTYPE_POWER_DELIVERY				0x06	/* From USB3.2 */
#define BOSTYPE_BATTERY_INFO				0x07	/* From USB3.2 */
#define BOSTYPE_PD_CONSUMER_PORT			0x08	/* From USB3.2 */
#define BOSTYPE_PD_PROVIDER_PORT			0x09	/* From USB3.2 */
#define BOSTYPE_SUPERSPEED_PLUS				0x0A	/* From USB3.2 */
#define BOSTYPE_PRECISION_TIME_MEASUREMENT	0x0B	/* From USB3.2 */
#define BOSTYPE_WIRELESS_USB_EXT			0x0C	/* From USB3.2 */
#define BOSTYPE_BILLBOARD					0x0D	/* From USB3.2 */
#define BOSTYPE_AUTHENTICATION				0x0E	/* From USB3.2 */
#define BOSTYPE_BILLBOARD_EXT				0x0F	/* From USB3.2 */
#define BOSTYPE_CONFIGURATION_SUMMARY		0x10	/* From USB3.2 */


/*
** USB2 Extension capability descriptor
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusCapUsb2ExtensionDsc
{
    struct USBBusBosHead	Head;
    
    uint32	Attributes;		/* Device level features. A USB2EXT_ATTR_xxx bitmask.
                               NOTE: This is an 32-bit entity on 8-bit allignment! */
};

// USB2 Extension attributes
#define USB2EXT_ATTR_LPM	0x00000002	/* Link Power Management capable */


/*
** SuperSpeed capability descriptor
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusCapSuperSpeedDsc
{
    struct USBBusBosHead	Head;
   
    uint8	Attributes;				/* Device level features. A SUPERSPEED_ATTR_xxx bitmask */
    uint16	SpeedsSupported;		/* The supported speeds when in SuperSpeed mode.
									   A SUPERSPEED_SPEED_xxx bitmask */
	uint8	FunctionalitySupport;	/* The lowest USB speed at which all functionality of the
									   device is supported */
	uint8	U1DevExitLat;			/* U1 Device Exit latency. See USB spec for details */
	uint16	U2DevExitLat;			/* U2 Device Exit latency. See USB spec for details */
};

// SuperSpeed attributes
#define SUPERSPEED_ATTR_LTM		0x02	/* Latence Tolerance Management capable */

// SuperSpeed SpeedsSupported values
#define SUPERSPEED_SPEED_LOW	0x01	/* LowSpeed supported */
#define SUPERSPEED_SPEED_FULL	0x02	/* FullSpeed supported */
#define SUPERSPEED_SPEED_HIGH	0x04	/* HighSpeed supported */
#define SUPERSPEED_SPEED_SUPER	0x08	/* SuperSpeed supported */

// SuperSpeed FunctionalitySupport values
#define SUPERSPEED_FUNCSUPPORT_LOW		0	/* Full functionality from LowSpeed */
#define SUPERSPEED_FUNCSUPPORT_FULL		1	/* Full functionality from FullSpeed */
#define SUPERSPEED_FUNCSUPPORT_HIGH		0	/* Full functionality from HighSpeed */
#define SUPERSPEED_FUNCSUPPORT_SUPER	0	/* Full functionality from SuperSpeed */


/*
** SuperSpeed capability descriptor
**
**  Note: This structure is in Little Endian format! Use LE_WORD() macro for 16-bit r/w.
*/

struct USBBusCapSuperSpeedDsc
{
    struct USBBusBosHead	Head;

	uint8	Reserved;
	uint8	ContainerID[16];	/* UUID of device */
};


#endif /* USB_DEV_BOS_H */