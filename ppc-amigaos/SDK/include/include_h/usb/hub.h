#ifndef USB_HUB_H
#define USB_HUB_H
/*
** $VER: hub.h 53.34 (09.12.2021)
**
** Hub driver includes
**
** Copyright (c) 2001, Thomas Graff Thoeger
** Distributed by Hyperion Entertainment CVBA under permission.
*/

#ifndef USB_USB_H
#include <usb/usb.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

#define pack(x) x __attribute__ ((packed))

/*
**
** Hub descriptor
**
*/

// Notice that hd_Characteristics is a UWORD but is only BYTE alligned.
// The field_packed() macro is used to force this structure layout. If not
// forced, then C compilers will allign the UWORD to another boundary by
// inserting invisible bytes. Be warned - check that your compiler supports
// packing of structure members, otherwise you'll read the wrong data when
// accessing hub descriptors! This header file works with GCC.
// You can check this by doing a sizeof(struct USBBusHubDsc). It should be
// 8 bytes in size.

#define USBDESC_HUB     ((UBYTE) 0x29)

struct USBBusHubDsc {
    struct USBBusDscHead    Head; // Descriptor header

    UBYTE   hd_NumPorts; // Number of hub ports
    pack( UWORD   hd_Characteristics ); // Hub characteristics
    UBYTE   hd_PwrOn2PwrGood; // PwrOnToPwrGood time in 2ms intervals
    UBYTE   hd_HubCtrlCurrent; // Hub controller current req. in mA
    UBYTE   hd_DevRemovable[1]; // Bitmap indicating if ports contain detachable or
                                // non-detachable devices. One bit per port, rounded to bytes.
    // A USB1.0 compatibility PwrCtrlMask bitmask is also present, but unused.
};

// *** Characteristics
// ** Power switching
#define USBHUB_PWRMODE_MASK         0x0003
// Ganged power switching - all switch together
#define USBHUB_PWRMODE_GANGED       0x0000
// Individual power switching
#define USBHUB_PWRMODE_INDIVIDUAL   0x0001

// ** Compound device indicator (AND to check)
#define USBHUB_COMPOUND             0x0004

// ** Overcurrent protection
#define USBHUB_PROTECT_MASK         0x0018
// Single global protection
#define USBHUB_PROTECT_GLOBAL       0x0000
// Individual port protection
#define USBHUB_PROTECT_INDIVIDUAL   0x0008
// No protection (AND to check)
#define USBHUB_PROTECT_NONE         0x0010

/* Transaction translator think time (for USB 2.0 hubs) */
#define USBHUB_TT_THINK_TIME_MASK	0x0060
#define USBHUB_TT_THINK_TIME_8FS	0x0000 /* requires at most 8 full speed bit times */
#define USBHUB_TT_THINK_TIME_16FS	0x0020 /* requires at most 16 full speed bit times */
#define USBHUB_TT_THINK_TIME_24FS	0x0040 /* requires at most 24 full speed bit times */
#define USBHUB_TT_THINK_TIME_32FS	0x0060 /* requires at most 32 full speed but times */

#define USBHUB_TT_THINK_TIME_GET_FS(x) (((((x)>>5)&0x3)+1)*8)

#define USBHUB_PORT_INDICATORS		0x0080 /* Hub supports port indicators and corresponding interface */

/*
** Hub Request codes
*/

#define USBREQC_HUB_GET_STATUS      USBREQC_GET_STATUS
#define USBREQC_HUB_CLEAR_FEATURE   USBREQC_CLEAR_FEATURE
#define USBREQC_HUB_GET_STATE       2
#define USBREQC_HUB_SET_FEATURE     USBREQC_SET_FEATURE
#define USBREQC_HUB_GET_DESCRIPTOR  USBREQC_GET_DESCRIPTOR
#define USBREQC_HUB_SET_DESCRIPTOR  USBREQC_SET_DESCRIPTOR
#define USBREQC_HUB_CLEAR_TT_BUFFER 8
#define USBREQC_HUB_RESET_TT        9
#define USBREQC_HUB_GET_TT_STATE    10
#define USBREQC_HUB_STOP_TT         11


/*
** Hub Features
*/

#define USBFEAT_HUB_C_HUB_LOCALPOWER    0
#define USBFEAT_HUB_C_HUB_OVERCURRENT   1

#define USBFEAT_HUB_PORT_CONNECTION     0
#define USBFEAT_HUB_PORT_ENABLE         1
#define USBFEAT_HUB_PORT_SUSPEND        2
#define USBFEAT_HUB_PORT_OVERCURRENT    3
#define USBFEAT_HUB_PORT_RESET          4
#define USBFEAT_HUB_PORT_POWER          8
#define USBFEAT_HUB_PORT_LOW_SPEED      9
#define USBFEAT_HUB_C_PORT_CONNECTION   16
#define USBFEAT_HUB_C_PORT_ENABLE       17
#define USBFEAT_HUB_C_PORT_SUSPEND      18
#define USBFEAT_HUB_C_PORT_OVERCURRENT  19
#define USBFEAT_HUB_C_PORT_RESET        20
#define USBFEAT_HUB_PORT_TEST			21
#define USBFEAT_HUB_PORT_INDICATOR		22

/*
**
** GetHubStatus bit definitions
**
*/

struct USBBusHubStatus {
    UWORD   Status;
    UWORD   Change;
};

/*
** Hub Status bits
*/
#define USBHUB_HUBSTATUSF_LOCALPOWER    0x0001  /* If cleared then Hub has local power supply.
                                                   If set then Hub is bus powered */
#define USBHUB_HUBSTATUSF_OVERCURRENT   0x0002  /* Hub is in an overcurrent condition.
                                                   Only valid for hubs detecting overcurrent on a hub-basis */

/*
** Hub Change bits
*/
#define USBHUB_HUBCHANGEF_LOCALPOWER    0x0001
#define USBHUB_HUBCHANGEF_OVERCURRENT   0x0002


/*
**
** GetPortStatus bit definitions
**
*/

struct USBBusHubPortStatus {
    UWORD   Status;
    UWORD   Change;
};

/*
** Port Status bits
*/
#define USBHUB_PORTSTATUSF_CONNECTED    0x0001  /* USB Device attached to port */
#define USBHUB_PORTSTATUSF_ENABLED      0x0002  /* Port is enabled */
#define USBHUB_PORTSTATUSF_SUSPENDED    0x0004  /* Port is suspended or resuming */
#define USBHUB_PORTSTATUSF_OVERCURRENT  0x0008  /* Overcurrent condition on port */
#define USBHUB_PORTSTATUSF_RESETTING    0x0010  /* Port is resetting */

#define USBHUB_PORTSTATUSF_POWERED      0x0100  /* Port is powered */
#define USBHUB_PORTSTATUSF_LOWSPEED     0x0200  /* Attached device is Low Speed */
#define USBHUB_PORTSTATUSF_HIGHSPEED    0x0400  /* Attached device is High Speed.
                                                   Relevant only if _LOWSPEED is not set */
#define USBHUB_PORTSTATUSF_TESTMODE     0x0800  /* Port is in Port Test Mode */
#define USBHUB_PORTSTATUSF_INDICATOR    0x1000  /* If set port indicator LED is under
                                                   software control. Otherwise indicator
                                                   is under hub control (default colors) */

/*
** Port Change bits
*/
#define USBHUB_PORTCHANGEF_CONNECT      0x0001
#define USBHUB_PORTCHANGEF_ENABLE       0x0002
#define USBHUB_PORTCHANGEF_SUSPEND      0x0004
#define USBHUB_PORTCHANGEF_OVERCURRENT  0x0008
#define USBHUB_PORTCHANGEF_RESET        0x0010


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

#endif /* USB_HUB_H */

