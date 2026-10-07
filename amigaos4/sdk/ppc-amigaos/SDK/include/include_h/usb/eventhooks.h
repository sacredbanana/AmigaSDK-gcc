#ifndef USB_EVENTHOOKS_H
#define USB_EVENTHOOKS_H
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

#ifndef DEVICCES_TIMER_H
#include <devices/timer.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef USB_SYSTEM_H
#include <usb/system.h>
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
**
** Callback hook event types
**
*/

#define USB_HOOKEVENT_HOOKCHANGE	0	/* Hooks were added or removed */
#define USB_HOOKEVENT_LOGENTRY		1	/* Hook is called when USB log entries are added */
#define USB_HOOKEVENT_IOTRACE		2	/* Hook is called when IO tracing events occur */

/* Hook packet for USB_HOOKEVENT_HOOKCHANGE */
struct USBHookChangeEventData
{
	uint32 EventType; /* The type of event a hook was added to or removed from. A USB_HOOKEVENT_xxx value */
};

/* Hook packet for USB_HOOKEVENT_LOGENTRY */
struct USBLogEntryEventData
{
	struct TimeVal Time; /* Time of the log entry */
	int32 Level; /* Log level */
    char *TaskName; /* Name of the task logging the message */
    char *Context; /* The context name as given by the logger */
    char *Message; /* Actual log message */
    
    struct TagItem *TagList; /* Extended information in form of a TagList.
                                NULL if no more information exist */
};

/* Hook packet for USB_HOOKEVENT_IOTRACE */
struct USBIoTraceEventData
{
	uint32 TransactionId; /* Id number identifying the transaction across multiple trace events.
	                         TransactionId combined with IoRequest is unique within the context
	                         of a single HCD. That is, the same TransactionId may be used
	                         simultaneously for two transaction event traces related to the same
	                         HCD  - one with a NULL IoRequest and one with a non-NULL IoRequest
	                         value. This may occur if an USBIOReq is being traced at the same
	                         time where a HCD chooses to use the same TransactionId for an
	                         internal USB transaction which is being traced */

	uint32 TracePoint; /* The trace point of this event */
	uint32 Flags; /* Flags for this event */
	
	struct USBIOReq *IoRequest; /* The IO request being traced. May be NULL if tracing a
	                               transaction which does not originate from an IO request */
	struct UsbEndPoint *EndPoint; /* The EndPoint targeted by IO. May Be NULL */
	struct UsbRawInterface *Interface; /* The USB Interface hosting endpoint of IO (if any). May be NULL */
	struct UsbRawFunction *Function; /* The USB Function hosting endpoint of IO. May be NULL */
	uint32 BusNumber; // The USB bus number the IO is taking place on.

	uint8 EndPointType; /* Type of endpoint targeted by IO - a USBEPTT_xxx value */
	uint8 EndPointNumber; /* EndPoint number targeted by IO */
	uint16 pad1;

	/* Begin IO request state data - superceedes IoRequest content */
	uint16 IoCommand;
	uint8 IoFlags;
	int8 IoError;
	uint32 IoActual;
	uint32 IoOffset;
	APTR IoData;
	uint32 IoLength;
	APTR IoSetupData;
	uint32 IoSetupLength;
	uint32 IoTargetFrame;
	/* End IO request state data */

	/* Begin USB_IOTRACE_POINT_HCDXFER specific data fields */
	uint8 TransferType;
	int8 TransferError;
	uint16 pad2;
	uint32 TransferLength;
	/* End USB_IOTRACE_POINT_HCDXFER specific data fields */
	
	struct USBIoTraceCustomData *CustomData; /* Custom trace data name/value pair array. May be NULL.
	                                            Array is terminated by entry with NULL Name */

	/* Below here only available from usbsys.device V53.26 or later */

	struct USBFktPathElement *FunctionPath; /* Path of the USB function. Array of USBFktPathElement instances
	                                           each holding one level of the path. First index holds hub closest to HCD
	                                           root. Last element always holds a NULL Hub value terminating the array */
};

/*
** USBIoTraceEventData.TracePoint
*/
#define USB_IOTRACE_POINTF_PREPARING	0x0000	/* IO is on its way towards bus transfer */
#define USB_IOTRACE_POINTF_ACTIVE		0x4000	/* IO is in flight as bus transfer */
#define USB_IOTRACE_POINTF_RETURNING	0x8000	/* IO is on its way back after bus transfer */
#define USB_IOTRACE_POINTM_STATE		(USB_IOTRACE_POINTF_PREPARING | USB_IOTRACE_POINTF_ACTIVE | USB_IOTRACE_POINTF_RETURNING)

#define USB_IOTRACE_POINT_BEGIN		(USB_IOTRACE_POINTF_PREPARING | 0x0001)	/* IO has been received by USB stack */
#define USB_IOTRACE_POINT_HCDBEGIN	(USB_IOTRACE_POINTF_PREPARING | 0x0002)	/* IO has been received by HCD */
#define USB_IOTRACE_POINT_HCDXFER	(USB_IOTRACE_POINTF_ACTIVE | 0x0003)	/* A transfer has completed for IO in the HCD*/
#define USB_IOTRACE_POINT_HCDCUSTOM	(USB_IOTRACE_POINTF_ACTIVE | 0x0004)	/* A custom trace from HCD */
#define USB_IOTRACE_POINT_HCDEND	(USB_IOTRACE_POINTF_RETURNING | 0x0002)  /* IO is being replied from HCD */
#define USB_IOTRACE_POINT_END		(USB_IOTRACE_POINTF_RETURNING | 0x0001)  /* IO is being replied from USB stack */

/*
** USBIoTraceEventData.Flags
*/
#define USB_IOTRACEF_NONE			0x00000000 /* Named "no flags set" value */
#define USB_IOTRACEF_BUFFERACCESS	0x00000001 /* If set IO request data buffers can be accessed, 
                                                  If not set buffers are locked for DMA and must _not_ be accessed.
                                                  Failure to observe this flag may corrupt the data buffer of the
                                                  traced IO request */

/*
** Custom IO trace data name/value pair
*/
struct USBIoTraceCustomData
{
	char *Name; /* Name of the custom trace data */
	char *Value; /* Value of the custom trace data. NULL is only allowed if Name is NULL */
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

#endif /* USB_EVENTHOOKS_H */
