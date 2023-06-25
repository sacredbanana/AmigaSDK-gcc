#ifndef USB_SYSTEM_H
#define USB_SYSTEM_H
/*
** $VER: system.h 53.34 (09.12.2021)
**
** USB System Software includes
**
** Copyright (c) 2001, Thomas Graff Thoeger
** Distributed by Hyperion Entertainment CVBA under permission.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_IO_H
#include <exec/io.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

/*
** Dummy USB structs for compiler type checking
**
**   Do not peek in these!
**   Do not use sizeof()
**   In short - only use these as pointer types!!
**
*/

// ** A reference to an unclaimed USB Function
struct UsbRawFunction
{
	uint32	I_Am_Private;
};

// ** A reference to a claimed USB Function
struct UsbFunction
{
	uint32	I_Am_Private;
};

// ** A reference to an unclaimed USB Interface
struct UsbRawInterface
{
	uint32	I_Am_Private;
};

// ** A reference to a claimed USB Interface
struct UsbInterface
{
	uint32	I_Am_Private;
};

// ** Reference to an EndPoint at a claimed USB Function/Interface
struct UsbEndPoint
{
	uint32	I_Am_Private;
};


/*
**
** Version numbers
**
*/

/* Current HCD API version */
#define USBHCD_APIVERSION   1


/*
**
** IO request for passing read/write requests between
** Function Driver->System
**
*/

struct USBIOReq
{
    // *** IOStdReq structure
	struct Message			io_Message;
	struct Device *			io_Device;			/* Device node pointer  */
	struct Unit *			io_Unit;			/* Unit (USS private) */
	uint16					io_Command;			/* Device command */
	uint8					io_Flags;
	int8					io_Error;			/* Error or warning num */
	uint32					io_Actual;			/* Actual number of bytes transferred */
	uint32					io_Length;			/* Requested number bytes transferred
											   If non-zero the USS may use the io_Data pointer for memory accesses */
	APTR					io_Data;			/* Points to data area.
											   A non-NULL ptr results in a USB data stage for the request */
	uint32					io_Offset;			/* Offset for block structured devices (USS private) */

    // *** USB Extension
	struct UsbEndPoint *	io_EndPoint;		/* EndPoint reference (USS's reference)*/
	APTR                	io_SetupData;		/* Ptr to Control EndPoint SETUP packet data, or NULL for no SETUP */
	uint32					io_SetupLength;		/* Bytesize of io_SetupData block. */

	/* -- v53.6 -- */
	uint32					io_TimeOut;			/* Value in Micro Seconds */
};

/*
** IO request for passing read/write requests between
** System->Host Controller Driver
*/

struct USBIOReqHCD
{
    // *** IOStdReq structure
	struct Message			io_Message;
	struct Device *			io_Device;			/* Device node pointer  */
	struct Unit *			io_Unit;			/* Unit (HCD private) */
	uint16					io_Command;			/* Device command */
	uint8					io_Flags;
	int8					io_Error;			/* Error or warning num */

	uint32					io_Actual;			/* Actual number of bytes transferred */
	uint32					io_Length;			/* Requested number bytes transferred
												   If non-zero the HCD may use the io_Data pointer for memory accesses */
	APTR					io_Data;			/* Points to data area.
												   Generate USB data stage if non-NULL.
												   Only touch data area if io_Length!=0 !!! */
	uint32					io_Offset;			/* Offset for block structured devices (HCD private) */

    // *** USB Extension
	APTR					io_EndPoint;		/* EndPoint reference (HCD's reference) */

	APTR					io_SetupData;		/* Ptr to Control EndPoint SETUP packet data, or NULL for no SETUP */
	uint32					io_SetupLength;     /* Bytesize of io_SetupData block. */

	struct USBBusDevDsc *	io_DevDsc;			/* USB Device Descriptor for USB Function. Always non-NULL */
	struct USBBusCfgDsc *	io_CfgDsc;			/* USB Descriptor for Configuration the Interface is part of (NULL if not Configured) */
	struct USBBusIntDsc *	io_IntDsc;			/* USB Descriptor for Interface the EndPoint is part of (NULL for EndPoint 0!!) */
	struct USBBusEPDsc *	io_EPDsc;			/* USB Descriptor for EndPoint (NULL for EndPoint 0!!) */

	/* -- v53.5 -- */
	uint32					io_TimeOut;			/* Value in Micro Seconds */
};

/*
** USB HCD Query
**
*/

struct USBHCDQuery
{
	uint32					HCDIndex;			/* This is set before sending Query.
												   A value of -1 indicate to get a total all HCDs */
	uint64					ReadPackets;
	uint64					ReadBytes;
	uint64					SendPackets;
	uint64					SendBytes;
};                          

/*
** IO request command codes (apart from std. Exec codes)
**
*/

#define USBCMD_HCDQuery		( CMD_NONSTD + 0 )

/*
** Error codes (apart from std. IOERR_xxx codes)
**
**  on an EndPoint with size restrictions the HCD must return
**  IOERR_BADLENGTH if size restrictions are not obeyed.
*/

#define USBERR_NOERROR			0		/* No error */

#define USBERR_DETACHED			(-11)	/* Referenced EndPoint/Function has been detached from USB bus */
#define USBERR_NOBANDWIDTH		(-12)	/* Not enough bandwidth to support EndPoint */
#define USBERR_NOMEM			(-13)	/* Out of memory */
#define USBERR_NOSIGBIT			(-14)	/* No Signal Bit available */
#define USBERR_BADARGS			(-15)	/* Bad arguments in a request */
#define USBERR_NOENDPOINT		(-16)	/* Unable to locate requested EndPoint */
#define USBERR_UNSUPPORTED		(-17)	/* The request was not supported by the hardware */
#define USBERR_ISPRESENT		(-18)	/* The object being added has already been added by someone else */
#define USBERR_ATTACHFAIL		(-19)	/* USB Function attachment failed */
#define USBERR_NOPOWER			(-20)	/* Not enough power available on the USB bus to support the
										   attachment or configuration */
#define USBERR_IOERROR			(-21)	/* HCD's can stumple over IO errors */
#define USBERR_BADLENGTH		(-22)	/* A structured passed, might be to short */
#define USBERR_NEWPORTOWNER     (-23)   /* Ownership of the port has been transfered. */

#define USBERR_STALL            (-32)	/* USB Device/Interface/EndPoint STALLed on request */
#define USBERR_XFERFAIL         (-33)	/* Fail to complete USB transfer due to bus error */
#define USBERR_NAK              (-34)	/* NAK returned from USB Function */
#define USBERR_TIMEOUT          (-35)	/* Failed to complete USB transfer due to no response from target */
#define USBERR_BUFFEROVERFLOW   (-36)	/* READ returned more data than would fit into buffer.
                                           It's up to you to decide if this should be treated
                                           as an error (not all data the USB EndPoint wanted to
                                           return could be stored and delivered to you), or as a
                                           success (you actually got the amount of data you
                                           requested from the USB EndPoint. It's right there in
                                           your buffer waiting for you) */

/*
** USB Notification Message
**
**  This is the structure of messages send to the Claimer
**  of a USB Function/Interface.
*/

struct USBNotifyMsg
{
	struct Message	Msg;
	APTR			ObjRef;		/* Receiver's private reference for object in question */
	uint16			Type;		/* Type of notification */
	uint16			pad;
};

/*** Notification types */
#define USBNM_TYPE_FUNCTIONDETACH   1   /* Function detachment notification.
                                           Only issued for claimed Functions, and only sent to owner.
                                           ObjRef is claimers reference for Function.
                                           Cannot be subscribed to. */
#define USBNM_TYPE_INTERFACEDETACH  2   /* Interface detachment notification.
                                           Only issued for claimed Interfaces, and only sent to owner.
                                           ObjRef is claimers reference for Interface.
                                           Cannot be subscribed to. */
#define USBNM_TYPE_FUNCTIONADDED    4   /* Notification that a Function has been added to the
                                           system Function list.
                                           Issued to all subscribers of this event.
                                           ObjRef is UsbRawFunction pointer for the added Function.
                                           Can only be received by subscription. */
#define USBNM_TYPE_FUNCTIONREMOVED  5   /* Notification that a Function has been removed from the
                                           system Function list.
                                           Issued to all subscribers of this event.
                                           ObjRef is UsbRawFunction pointer for the removed Function.
                                           Can only be received by subscription. */
#define USBNM_TYPE_FUNCTIONCFGCHNG  6   /* Notification that the Configuration of a Function has
                                           been changed.
                                           Issued to all subscribers of this event.
                                           ObjRef is UsbRawFunction pointer for the changed Function.
                                           Can only be received by subscription. */
#define USBNM_TYPE_STACKSTARTED     7   /* Notification that the USB stack has been started.
                                           Note that if USB stack is already started at subscription
                                           time you won't receive this notification unless the USB stack
                                           is restarted at some point.
                                           Can only be received by subscription. */
#define USBNM_TYPE_STACKFULLBOOTED  8   /* Notification that the USB stack has been fullbooted.
                                           This also implies that dos.library is around.
                                           Note that if USB stack is already fullbooted at subscription
                                           time you won't receive this notification unless the USB stack
                                           is restarted at some point.
                                           Can only be received by subscription. */
#define USBNM_TYPE_STACKSTOPPED     9   /* Notification that the USB stack has been stopped, or at
                                           least is in the process of doing so. If you're an external
                                           program using USB resources you should clean up and exit.
                                           If you want to clean up during a USB stack restart you should
                                           clean up at _STACKSTOPPED and reinitialize at _STACKSTARTED
                                           notifications (implying you register for both events).
                                           Note that if the USB stack is not running at subscription
                                           time you will not receive this notification until the USB
                                           stack has been started and is stopped again.
                                           Can only be received by subscription. */

/*
** USB System tags
**
**  These are the tags recognized by the USB System. Some are shared among
**  FD and HCD, others are valid only between the USS and the HCD, or between
**  the USS and the FD. Tags may also be limited to certain functions.
*/

/* For supplying a Device descriptor ptr (struct USBBusDevDsc *) */
#define USBA_DeviceDesc         (TAG_USER+1)
/* For supplying an Interface descriptor ptr (struct USBBusIntDsc *) */
#define USBA_InterfaceDesc      (TAG_USER+2)
/* For supplying an EndPoint descriptor ptr (struct USBBusEPDsc *) */
#define USBA_EndPointDesc       (TAG_USER+3)
/* For supplying USB Device speed to USB(HC)AddFunctionA()
   ti_Data is a USB_SPEED_xxx value.
   If not specified the default speed used *must* be USB_SPEED_LOW.
   Also used for querying HCD root bus speed using USBHCGetAttrsA() */
#define USBA_DeviceSpeed        (TAG_USER+4)

#define USB_SPEED_LOW   (0L) /*    1.5 Mbit/s */
#define USB_SPEED_FULL  (1L) /*   12   Mbit/s */
#define USB_SPEED_HIGH  (2L) /*  480   Mbit/s */
#define USB_SPEED_SUPER (3L) /* 4800   Mbit/s */

/* For supplying a Configuration Descriptor (struct USBBusCfgDsc *) */
#define USBA_ConfigurationDesc  (TAG_USER+5)
/* Reserved */
//#define USBA_unused6            (TAG_USER+6)

/* For supplying a UsbRawInterface pointer */
#define USBA_UsbRawInterface    (TAG_USER+7)

/* For supplying a USB device class */
#define USBA_Class              (TAG_USER+8)
/* For supplying a USB device subclass */
#define USBA_Subclass           (TAG_USER+9)
/* For supplying a USB Vendor ID */
#define USBA_VendorID           (TAG_USER+10)
/* For supplying a USB Product ID */
#define USBA_ProductID          (TAG_USER+11)

/* For specifying a HCD device name (NUL terminated string ptr) */
#define USBA_HCD_Name           (TAG_USER+12)
/* For specifying a HCD device unit number (ULONG) */
#define USBA_HCD_Unit           (TAG_USER+13)

/* For specifying a stack size (ULONG) */
#define USBA_StackSize          (TAG_USER+14)
/* For specifying a priority (within UBYTE range!) */
#define USBA_Priority           (TAG_USER+15)

/* For specifying a FD library name (NUL terminated string ptr) */
#define USBA_FD_Name            (TAG_USER+16)
/* For specifying a title for an FD (NUL terminated string ptr) */
#define USBA_FD_Title           (TAG_USER+17)
/* For indicating an FD has Function capability (BOOL) */
#define USBA_FD_FunctionDriver  (TAG_USER+18)
/* For indicating an FD has Interface capability (BOOL) */
#define USBA_FD_InterfaceDriver (TAG_USER+19)

/* For returning an error code from a function call (LONG *) */
#define USBA_ErrorCode          (TAG_USER+20)

/* For specifying an sd_Index argument for USBEPGetDescriptorA() (New in v1.2) */
#define USBA_USBSetupDataIndex  (TAG_USER+21)

/* HCD device USBHCGetAttrs() query: HCD API version number */
#define USBA_HCD_APIVersion     (TAG_USER+22)

/* For specifying that the FD is weak and should be preempted upon the USB
   stack FullBooting. This is basically for simple boot-point drivers to
   indicate that they should be terminated once the USB stack is running in a
   fully booted environment (BOOL) (New in v1.5) */
#define USBA_FD_WeakBinding     (TAG_USER+23)

/* For indicating that the FD calls USBFktDriverRunning()/USBIfcDriverRunning() when
   it is operational. Used by USB stack in calls to USBFDGetAttrs(). (LONG *) */
#define USBA_FD_SignalsRunning  (TAG_USER+24)

/* For specifying a hub port. Port numbers are zero based. (ULONG) (New in v1.7)*/
#define USBA_HubPort            (TAG_USER+25)

/* For specifying whether Claimed Functions/Interfaces are returned by
   USBFindFunctionA()/USBFindInterfaceA(). (BOOL) defaults to FALSE.
   (New in v1.9) */
#define USBA_SeeClaimed         (TAG_USER+26)

/* For querying the USB stack fullboot state with USBGetStackAttrsA()
   (New in v1.9) */
#define USBA_Stack_Fullbooted   (TAG_USER+27)

/* For querying the Vendor name of a Function (struct USBBusDscHead *)
   (new in v1.11) */
#define USBA_VendorName         (TAG_USER+28)
/* For querying the Product name of a Function (struct USBBusDscHead *)
   (new in v1.11) */
#define USBA_ProductName        (TAG_USER+29)
/* For querying the Serial number string of a Function (struct USBBusDscHead *)
   (new in v1.11) */
#define USBA_SerialName         (TAG_USER+30)
/* For querying the name of an Interface (struct USBBusDscHead *)
   (new in v1.11) */
#define USBA_InterfaceName      (TAG_USER+31)
/* For enabling trace-logging of IO requests (ULONG)
   (new in v1.11) */
#define USBA_TraceIO            (TAG_USER+32)
/* For indicating self-power state of a Function (ULONG) (New in v1.12) */
#define USBA_SelfPowered        (TAG_USER+33)
/* For obtaining the device address from USBHCAddFunctionA() (LONG *) (New in v2) */
#define USBA_DeviceAddress      (TAG_USER+34)
#define USBA_DataLength			(TAG_USER+35)
/* Return the number of current loaded HCD's */
/* Useful when querying for stats */
#define USBA_Stack_NumberofHCDs	(TAG_USER+36)
/* For querying the topological level of a function. New in V53.9 */
#define USBA_Level              (TAG_USER+37)
/* For querying the owner of a function. New in V53.9.(STRPTR) */
#define USBA_OwnerStr           (TAG_USER+38)
/* For querying the number of mA the device draws from its upstream port
 * in its current configuration. New in V53.9 (uint32) */
#define USBA_DevicePower        (TAG_USER+39)
/* For querying the number of mA that all devices draw from this device.
 * New in V53.9 (uint32) */
#define USBA_SubtreePower       (TAG_USER+40)

/*
** USB AutoStarting Function Driver Startup Msg
**
**  This structure is passed as initial argument to an AutoStarting FD
**  when the USS calls its entry point.
*/

struct USBFDStartupMsg
{
    struct IORequest       *USBReq; /* Reference for already-opened "usbsys.device" (do NOT close the device after use!)
                                       The ReplyPort has been specifically created for this use. If the FD decides
                                       to handle the USB Function it may use the port at its own discretion - except
                                       deleting the port.
                                    */

    APTR                    Object; /* The USB objectto handle in the FD (USS reference).
                                       All FDs must allow this field to hold a NULL pointer.
                                       If this is the case the FD should return as if it didn't support the given
                                       USB object. That is, return USBERR_UNSUPPORTED.

                                       When the USS calls an FDs USBFDRunFunction() this field
                                        points to a struct UsbRawFunction.
                                       When the USS calls an FDs USBFDRunInterface() this field
                                        points to a struct UsbRawInterface.
                                     */
    struct USBBusDscHead   *Descriptor; /* Ptr to USB descriptor for the Object:
                                           For a UsbRawFunction this is a Function descriptor (struct USBBusDevDsc) ptr.
                                           For a UsbRawInterface this is an Interface descriptor (struct USBBusIntDsc) ptr
                                         */

};


/*
**
** Return values from USBSetConfiguration()
**
*/

#define USBSETCONFIG_OK             0
#define USBSETCONFIG_FAIL           1
#define USBSETCONFIG_UNCONFIGURED   -1
#define USBSETCONFIG_INCONSISTENT   -2

/*
**
** USB Resource types for USBObtainResource()
**
*/

#define USBRES_DEFAULTADDRESS   1L  /* USB bus Default Address.
                                       Object is a struct UsbInterface pointer */

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

#endif /* USB_SYSTEM_H */

