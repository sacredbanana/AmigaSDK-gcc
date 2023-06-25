#ifndef USB_DEVCLASSES_H
#define USB_DEVCLASSES_H

/*
** $VER: devclasses.h 53.34 (09.12.2021)
**
** USB Device Class definitions
**
** Copyright (c) 2001, Thomas Graff Thoeger
** Distributed by Hyperion Entertainment CVBA under permission.
*/

/*
** Interface Classes
*/

#define USBCLASS_NONE           0x00
#define USBCLASS_AUDIO          0x01
#define USBCLASS_CDCCONTROL     0x02
#define USBCLASS_HID            0x03
//..
#define USBCLASS_PHYSICAL       0x05
#define USBCLASS_IMAGE          0x06    /* Subclass and Protocol must be 1 */
#define USBCLASS_PRINTER        0x07
#define USBCLASS_MASSSTORAGE    0x08
#define USBCLASS_HUB            0x09
#define USBCLASS_CDCDATA        0x0A
#define USBCLASS_CARD           0x0B    /* Chip'n'Smart Cards */
//..
#define USBCLASS_SECURITY       0x0D
#define USBCLASS_VIDEO			0x0E
#define USBCLASS_HEALTHCARE		0x0F
//..
#define USBCLASS_DIAGNOSTIC     0xDC
//..
#define USBCLASS_WIRELESS       0xE0
//..
#define USBCLASS_MISCELLANEOUS	0xEF
//..
#define USBCLASS_APPLICATION    0xFE
#define USBCLASS_VENDOR         0xFF

#endif  /* USB_DEVCLASSES_H */
