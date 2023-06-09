#ifndef USBHCD_INTERFACE_DEF_H
#define USBHCD_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.6.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef USB_SYSTEM_H
#include <usb/system.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct USBHCDIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct USBHCDIFace *Self);
	ULONG APICALL (*Release)(struct USBHCDIFace *Self);
	void APICALL (*Expunge)(struct USBHCDIFace *Self);
	struct Interface * APICALL (*Clone)(struct USBHCDIFace *Self);
	APTR APICALL (*USBHCAddFunctionA)(struct USBHCDIFace *Self, APTR hcunit, APTR hchub, APTR usfkt, struct TagItem * taglist);
	APTR APICALL (*USBHCAddFunction)(struct USBHCDIFace *Self, APTR hcunit, APTR hchub, APTR usfkt, ...);
	void APICALL (*USBHCRemFunction)(struct USBHCDIFace *Self, APTR hcunit, APTR hcfkt);
	APTR APICALL (*USBHCAddEndPointA)(struct USBHCDIFace *Self, APTR hcunit, APTR hcfkt, APTR usep, LONG epnum, struct TagItem * taglist);
	APTR APICALL (*USBHCAddEndPoint)(struct USBHCDIFace *Self, APTR hcunit, APTR hcfkt, APTR usep, LONG epnum, ...);
	void APICALL (*USBHCRemEndPoint)(struct USBHCDIFace *Self, APTR hcunit, APTR hcep);
	void APICALL (*USBHCGetAttrsA)(struct USBHCDIFace *Self, struct TagItem * taglist);
	void APICALL (*USBHCGetAttrs)(struct USBHCDIFace *Self, ...);
	LONG APICALL (*USBHCInitRootHubA)(struct USBHCDIFace *Self, APTR hcunit, struct UsbRawInterface * usifc, APTR * hcfkt, struct TagItem * taglist);
	LONG APICALL (*USBHCInitRootHub)(struct USBHCDIFace *Self, APTR hcunit, struct UsbRawInterface * usifc, APTR * hcfkt, ...);
	void APICALL (*USBHCUninitRootHub)(struct USBHCDIFace *Self, APTR hcunit, APTR hcfkt);
	ULONG APICALL (*USBHCGetFrameNumber)(struct USBHCDIFace *Self, APTR hcunit, struct TimeVal * timestamp);
	void APICALL (*USBHCGetUnitAttrsA)(struct USBHCDIFace *Self, APTR hcunit, struct TagItem * taglist);
	void APICALL (*USBHCGetUnitAttrs)(struct USBHCDIFace *Self, APTR hcunit, ...);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* USBHCD_INTERFACE_DEF_H */
