#ifndef USB_SYSTEM_H
#define USB_SYSTEM_H
/*
**
** USB System Software includes
**
** Copyright (c) 2001, Thomas Graff Thoeger
** Distributed by Hyperion Entertainment BV under permission.
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

// HCD API version 2 (from 53.15) - Current HCD API version
#define USBHCD_APIVERSION_2	2

// HCD API version 1 (before 53.15) - still supported in parallel to version 2
#define USBHCD_APIVERSION_1	1

// Old USBHCD_APIVERSION constant deprecated to ensure that no V1
// API HCDs are accidentally compiled with V2 indication.


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
	uint32					io_Actual;			/* Number of bytes actually transferred.
												   For isochronous endpoint IO this is the number of
												   transfer setups processed for the operation, unless the
												   IO request is not using transfer setups (compatibility mode) (53.17) */
	uint32					io_Length;			/* Number of bytes requested transferred from/to the io_Data buffer.
											       If non-zero the USS may use the io_Data pointer for memory accesses */
	APTR					io_Data;			/* Pointer to data buffer for the IO.
											       A non-NULL ptr results in a USB data stage for the request */
	uint32					io_Offset;			/* Offset for block structured devices (USS private) */

    // *** USB Extension
	struct UsbEndPoint *	io_EndPoint;		/* EndPoint reference (USS's reference)*/
	APTR                	io_SetupData;		/* Ptr to Control EndPoint SETUP packet data, or NULL for no SETUP */
	uint32					io_SetupLength;		/* Bytesize of io_SetupData block. */

	/* -- v53.6 -- */
	uint32					io_TimeOut;			/* Value in microseconds */
	/* -- v53.18 -- */
	uint32					io_UsbFlags;		/* USB specific flags for IO operation */
	uint32					io_TargetFrame;		/* Target frame for isochronous transfers. I.e. the USB frame number at
												   which the IO request should be started on the USB bus. Ignored unless
												   io_UsbFlags has USBIOF_ISO_USETARGETFRAME bit set.
												   When in use, a replied IO will see this field hold frame number of the
												   first transfer made for the isochronous IO.
												   io_TargetFrame is only usable with a HCD which maintains a current USB
												   frame number (see USBGetRawFunctionAttrs() or USBGetRawInterfaceAttrs()) */
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

	uint32					io_Actual;			/* Number of bytes actually transferred.
												   For isochronous endpoints on HCDAPI v2 or greater, this is the number of
												   transfer setups processed for the IO operation */
	uint32					io_Length;			/* Number of bytes requested transferred.
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
	uint32					io_TimeOut;			/* Value in microseconds */
	/* -- v53.18 -- */
	uint32					io_UsbFlags;		/* USB specific flags for IO operation */
	uint32					io_TargetFrame;		/* Target frame for isochronous transfers. I.e. the USB frame number at
												   which the IO request should be started on the USB bus. Must be ignored
												   unless io_UsbFlags has USBIOF_ISO_USETARGETFRAME bit set.
												   For isochronous requests where io_UsbFlags has USBIOF_ISO_USETARGETFRAME bit set
												   this must be updated by the HCD to the actual frame number of the first
												   transfer performed for the IO request */
};



/*
** Flags for io_UsbFlags
*/

#define USBIOF_ISO_USETARGETFRAME	0x00000001	/* Indicates that IO request to isochronous endpoint should
												   target the USB frame mentioned in io_IsoStartFrame.
												   Isochronous endpoints have a pre-determined servicing
												   schedule so the actual target frame will be the first
												   servicing point at, or after, this USB frame. If not
												   specified the IO request will target the next available
												   USB frame where the endpoint is serviced. */
#define USBIOF_BUFFER_CACHEALIGNED	0x00000002	/* Promises that io_Data points (into) to a buffer which is
												   allocated while taking CPU cache line size into consideration.
												   I.e. the io_Data/io_Length buffer is safe to use for DMA
												   operations even if io_Data is not on a cache line size
												   aligned memory address and io_Length is not a multiple of
												   the cache line size.
												   In other words the underlying buffer extends at least to
												   the nearest preceeding cache line size aligned memory address
												   and at least up to the first cache line sized address
												   at, or following, io_Data + io_Length.
												   This allows a HCD to optimize its buffer handling with
												   regards to DMA operations for seemingly unaligned buffer
												   start and end addresses, but where the underlying buffer is
												   in fact DMA friendly in size and alignment.
												   So allocating your buffer to match and setting this flag
												   may lower the CPU overhead of your IO by the HCD being able
												   to use DMA more often than it would otherwise be able to. */

/*
** Isochronous transfer frame data
**
** IO requests for Isochronous endpoints must define a set of transfer setups indicating
** how the entire IO request buffer is to be transfered to/read from the isochronous
** endpoint. One setup must exist for each transfer on the USB bus (in USB1 one per
** serviced frame, in USB2 one per serviced microframe of an EndPoint). As such each
** transfer defined may cover multiple USB bus packets (for high-speed high-bandwidth
** added in USB2, and burst mode added in USB3), but may never exceed the size of the
** EndPoint MaxTransferSize (MaxPacketSize * packets_per_transfer)
*/

/*
** Structure defining a section of an IO request data buffer to use for transfer to/from
** an isochronous endpoint within a single USB (micro)frame (frame for USB1 endpoint,
** microframe for USB2 endpoint).
**
** These data are read only for for Function Drivers and Host Controller Drivers alike
** and can only be modified thru usbsys.device API function calls. Never edit the
** contents manually - ever!
*/

struct USBTransferSetup
{
    uint32  Offset;	/* Offset into IO request data buffer of buffer for USB (micro)frame.
                       Must be no further than the target endpoint's MaxTransferSize bytes
                       from the Offset of the previous UsbTransferSetup in the IO request */
    uint32  Length; /* Length (byte size) of buffer chunk for USB (micro)frame. Must be no
                       more than the target endpoint's MaxTransferSize */
};

/*
** Structure holding the result of the transfer performed in a given USB (micro)frame.
** The result matches a single UsbTransferSetup instance, describing its outcome after
** the transfer has occured.
**
** These data are read only for Function Drivers and Host Controller Drivers alike
** and can only be modified thru usbsys.device API function calls. Never edit the
** contents manually - ever!
*/

struct USBTransferResult
{    
	uint32  Actual; /* Number of bytes actually transfered */
    int32   Error; /* USBERR_xxx error of the (micro)frame transfer */
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

#define USBCMD_HCDQuery		(CMD_NONSTD+0)	/* io_Data points to USBHCDQuery to be filled by HCD */
#define USBCMD_TRACING		(CMD_NONSTD+1)	/* Control IO tracing of HCD (if supported by HCD).
                                               io_Data points to USBTracingControlData with IO tracing settings */

struct USBTracingControlData
{
	uint8	EnableTracing; /* Non-zero if IO tracing is to be enabled */
};

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

#define USBERR_BADLENGTH		(-22)	/* A bad length was detected in an IO request */
#define USBERR_NEWPORTOWNER     (-23)   /* Ownership of a hub port has been transfered so port is not reachable. */
#define USBERR_BADTRANSFERSETUP (-24)   /* The isochronous transfer setup data for an IO request is erroneous */
#define USBERR_NOTRANSFERSETUP  (-25)	/* An IO request without any transfer setups is sent to an endpoint
                                           where transfer setups are required for the IO request */
#define USBERR_INCOMPATIBLEHCD	(-26)	/* An IORequest cannot be supported by the HCD handling the endpoint
                                           due to it having a too old API version */

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
#define USBERR_FRAMEMISSED		(-37)	/* Target frame for an isochronous transfer has been missed.
                                           The requested transfer has not taken place. */
#define USBERR_CHECKRESULTS		(-38)	/* Isochronous transfer results contains errors. Some transfers may
                                           be OK while others have failed. */


/*
** Return codes from USBSetTransferSetup()
*/

#define USBISOSETFRAME_OK             0    /* All went well */
#define USBISOSETFRAME_INDEX_UNKNOWN  1    /* The transfer index requested does not exist in the IO request */
#define USBISOSETFRAME_OFFSET_INVALID 2    /* The offset specified is invalid - i.e. lies before the previous offset */


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
	uint16			Value;		/* A 16 bit value field used for argument passing for some notification types */
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
#define USBNM_TYPE_HUB_RESETPORT	10	/* (53.24) Notification from USB stack to a hub driver that a
                                           specific hub port should be reset. I.e. detach what is there
                                           and retry attachment if a device is still connected on the port.
                                           The notification sent is in fact a USBNotifyHubPortResetMsg.
                                           Msg.ObjRef is the claimed Function or Interface (which ever the
                                           hub driver has claimed with the recipient MsgPort) on which
                                           the hub port should be reset.
                                           Msg.Value is the zero based hub port number to reset.
                                           PortFkt is the Fkt which is expected to be reset with the hub
                                           port. If this is not the Fkt currently attached at the hub
                                           port when the driver processes the notification it should
                                           be ignored and thought of as obsolete.
                                           This notification cannot be subscribed to. */
#define USBNM_TYPE_FUNCTIONDRIVERCHANGE	12	/* (53.29) Notification that the driver associated with a
										   Function, or the properties of the driver, has changed.
										   Issued to all subscribers of this event.
										   ObjRef is a UsbRawFunction pointer for the Function affected.
										   Can only be received by subscription */
#define USBNM_TYPE_INTERFACEDRIVERCHANGE	13	/* (53.29) Notification that the driver associated with an
										   Interface, or the properties of the driver, has changed.
										   Issued to all subscribers of this event.
										   ObjRef is a UsbRawInterface pointer for the Interface affected.
										   Can only be received by subscription */



// Extended notification message sent for USBNM_TYPE_HUB_RESETPORT
struct USBNotifyHubPortResetMsg
{
	struct USBNotifyMsg 	Msg; /* Base notification msg */
	
	struct UsbRawFunction *	PortFkt; /* The UsbRawFunction expected to be reset at the hub port.
							            This will be NULL if expecting to reset an empty hub port */
};

/*
** Misc data structures
**
*/

struct USBVendorProductIDs
{
	uint32 VendorID;
	uint32 ProductIDCount; // Number of entries in the ProductIDs array. Must be zero if ProductIDs is NULL.
	uint32 *ProductIDs; // Ptr to array of ProductIDs for vendor or NULL. *MUST* contain at least ProductIDCount elements.
};

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

#define USB_SPEED_LOW   (0L) /*    1.5 Mbit/s (USB1) */
#define USB_SPEED_FULL  (1L) /*   12   Mbit/s (USB1) */
#define USB_SPEED_HIGH  (2L) /*  480   Mbit/s (USB2) */
#define USB_SPEED_SUPER (3L) /* 4800   Mbit/s (USB3) */

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
/* For querying the maximum number of bytes an isochronous or interrupt
   endpoint can transfer in a single serviced USB (micro)frame. New in V53.14 */
#define USBA_EP_MaxTransferSize	(TAG_USER+41)
/* The number of USB frames the HCD will cache ahead of the current USB frame.
   I.e. how many USB frames into the future scheduling is fixed for
   isochronous transfers. New in 53.18 */
#define USBA_HCD_CachedIsochronousFrames	(TAG_USER+42)
/* For quering the number of transfer a periodic endpoint can perform
   in each USB Frame in which it is getting serviced. New in V53.18 */
#define USBA_EP_TransfersPerFrame		 	(TAG_USER+43)
/* Boolean indicating if a HCD maintains a current USB frame number, and
   thus supports absolute frame adressing of isochronous endpoint IO (uint32 *).
   New in V53.18 */
#define USBA_HCD_MaintainsFrameNumber		(TAG_USER+44)
/* The maximum number of microframes a periodic EndPoint will have as
   poll interval. Larger numbers in the endpoint descriptor will be
   limited to this value. (uint32 *). New in V53.19 */
#define USBA_HCD_MaxPeriodicPollInterval	(TAG_USER+45)
/* The poll interval in use for a periodic endpoint, specified in microframes.
   The value returned by this tag superceedes the value from the endpoint
   descriptor, in that the HCD may've limited the poll interval to be able
   to handle the endpoint. The value is always equal to, or lower than, that
   calculated from the endpoint's descriptor. (uint32 *) New in V53.19 */
#define USBA_EP_PollInterval	(TAG_USER+46)
/* For indicating whether a Function being attached to a USB1-speed segment
   on a higher speed USB bus is positioned below a hub with multiple
   Transaction Translators available for mapping transactions into the USB1
   domain. (uint32) new in V53.24 */
#define USBA_HubHasMultiTT		(TAG_USER+47)
/* For specifying an endpoint of a USB Function.
   (struct UsbEndPoint *) new in V53.25 */
#define USBA_EndPoint			(TAG_USER+48)
/* For specifying an IO tracing transaction ID
   (uint32) new in V53.25 */
#define USBA_TransactionId		(TAG_USER+49)
/* An IO request command
   (uint32) new in V53.25 */
#define USBA_IO_Command			(TAG_USER+50)
/* Pointer to an IO data buffer.
   (APTR) new in V53.25 */
#define USBA_IO_Data			(TAG_USER+51)
/* Length of an IO data buffer
   (uint32) new in V53.25 */
#define USBA_IO_Length			(TAG_USER+52)
/* Pointer to an IO Setup-phase data buffer.
   (APTR) new in V53.25 */
#define USBA_IO_SetupData		(TAG_USER+53)
/* Length of an IO Setup-phase data buffer.
   (uint32) new in V53.25 */
#define USBA_IO_SetupLength		(TAG_USER+54)
/* An IO error code
   (int32) new in V53.25 */
#define USBA_IO_Error			(TAG_USER+55)
/* Type of the transfer completed in a USB_IOTRACE_POINT_HCDXFER IO trace point.
   ti_Data is one of the USB_XFERTYPE_ constants. (uint32) new in V35.25 */
#define USBA_TransferType		(TAG_USER+56)
/* Length of the transfer completed in a USB_IOTRACE_POINT_HCDXFER IO trace point.
   (uint32) new in V35.25 */
#define USBA_TransferLength		(TAG_USER+57)
/* IO error of the transfer completed in a USB_IOTRACE_POINT_HCDXFER IO trace point.
   (int32) new in V35.25 */
#define USBA_TransferError		(TAG_USER+58)
/* For specifying a USB Function instance
   (struct UsbRawFunction *) new in V53.25 */
#define USBA_RawFunction		(TAG_USER+59)
/* For specifying an array of VendorID/ProductIDs groups
   The array must be terminated by an instance with zeroed ProductIDs ptr and ProductIDCount.
   (struct USBVendorProductIDs *) new tag in V53.30 */
#define USBA_VendorProductIDs	(TAG_USER+60)


/*
** Transfer types as used by USBA_TransferType tag
*/
#define USB_XFERTYPE_OUT	0
#define USB_XFERTYPE_IN		1
#define USB_XFERTYPE_SETUP	2

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

/*
** USB Function path information
*/

struct USBFktPathElement
{
	struct UsbRawFunction *Hub; // Hub in the path between a Function and its Host Controller
	int16 Port; // Zero-based port on Hub to which the child topology connects. -1 if hub port is unknown.
	int16 pad;
};


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

