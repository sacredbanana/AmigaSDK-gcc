#ifndef CLIB_USBSYS_PROTOS_H
#define CLIB_USBSYS_PROTOS_H

/*
**    $Id: usbsys_protos.h,v 1.1 2010-01-31 03:38:12 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef USB_SYSTEM_H
#include <usb/system.h>
#endif

struct USBIOReq *USBAllocRequestA( struct IORequest *openreq, struct TagItem *taglist );
struct USBIOReq *USBAllocRequest( struct IORequest *openreq, ULONG tags, ... );
void USBFreeRequest( struct USBIOReq *req );

void USBGetStackAttrsA( struct TagItem *taglist );
void USBGetStackAttrs( ULONG tags, ... );


/*
** Function handling
*/

struct UsbRawFunction *USBFindFunctionA( struct UsbRawFunction *curfkt, struct TagItem *taglist );
struct UsbRawFunction *USBFindFunction( struct UsbRawFunction *curfkt, ULONG tags, ... );

void USBLockFunction( struct UsbRawFunction *rawfkt );
void USBUnlockFunction( struct UsbRawFunction *rawfkt );

void USBFktDriverRunning( struct UsbFunction *usfkt );

void USBGetRawFunctionAttrsA( struct UsbRawFunction *rawfkt, struct TagItem *taglist );
void USBGetRawFunctionAttrs( struct UsbRawFunction *rawfkt, ULONG tags, ... );

struct UsbFunction *USBClaimFunction( struct UsbRawFunction *rawfkt, APTR fdfkt, struct MsgPort *port );
void USBDeclaimFunction( struct UsbFunction *usfkt );

struct UsbRawFunction *USBAddFunctionA( struct UsbInterface *ushubifc, struct TagItem *taglist );
struct UsbRawFunction *USBAddFunction( struct UsbInterface *ushubifc, ULONG tags, ... );

void USBRemFunction( struct UsbRawFunction *rawfkt, struct UsbInterface *ushubifc );

LONG USBSetFunctionAttrsA( struct UsbFunction *usfkt, struct TagItem *taglist );
LONG USBSetFunctionAttrs( struct UsbFunction *usfkt, ULONG tags, ... );

struct UsbInterface *USBGetInterface( struct UsbFunction *usfkt, LONG ifcnum );

/*
** Interface handling
*/

struct UsbRawInterface *USBFindInterfaceA( struct UsbRawInterface *curifc, struct TagItem *taglist );
struct UsbRawInterface *USBFindInterface( struct UsbRawInterface *curifc, ULONG tags, ... );

void USBLockInterface( struct UsbRawInterface *rawifc );
void USBUnlockInterface( struct UsbRawInterface *rawifc );

void USBIfcDriverRunning( struct UsbInterface *usifc );

void USBGetRawInterfaceAttrsA( struct UsbRawInterface *rawifc, struct TagItem *taglist );
void USBGetRawInterfaceAttrs( struct UsbRawInterface *rawifc, ULONG tags, ... );

struct UsbInterface *USBClaimInterface( struct UsbRawInterface *rawifc, APTR fdifc, struct MsgPort *port );
void USBDeclaimInterface( struct UsbInterface *usifc );

LONG USBSetInterfaceAttrsA( struct UsbInterface *usifc, struct TagItem *taglist );
LONG USBSetInterfaceAttrs( struct UsbInterface *usifc, ULONG tags, ... );

struct UsbEndPoint *USBGetEndPoint( struct UsbFunction *usfkt, struct UsbInterface *usifc, LONG epnum );

/*
** Default Control Pipe abstraction
*/

LONG USBEPControlXferA(struct IORequest *openreq, struct UsbEndPoint *usep, ULONG rcmd, ULONG rtype, ULONG rval, ULONG ridx, APTR buf, ULONG buflen, struct TagItem *taglist );
LONG USBEPControlXfer(struct IORequest *openreq, struct UsbEndPoint *usep, ULONG rcmd, ULONG rtype, ULONG rval, ULONG ridx, APTR buf, ULONG buflen, ULONG tags, ... );
struct USBBusDscHead *USBEPGetDescriptorA( struct IORequest *openreq, struct UsbEndPoint *usep, ULONG rtype, LONG dtyp, LONG didx, struct TagItem *taglist );
struct USBBusDscHead *USBEPGetDescriptor( struct IORequest *openreq, struct UsbEndPoint *usep, ULONG rtype, LONG dtyp, LONG didx, ULONG tags, ... );
LONG USBEPDestall( struct IORequest *openreq, struct UsbEndPoint *usep );

struct USBBusCfgDsc *USBFktGetCfgDescriptorsA( struct IORequest *openreq, struct UsbFunction *usfkt, ULONG cfgid, struct TagItem *taglist );
struct USBBusCfgDsc *USBFktGetCfgDescriptors( struct IORequest *openreq, struct UsbFunction *usfkt, ULONG cfgid, ULONG tags, ... );
LONG USBFktSetConfigurationA( struct IORequest *openreq, struct UsbFunction *usfkt, struct USBBusCfgDsc *cfgdsc, struct TagItem *taglist );
LONG USBFktSetConfiguration( struct IORequest *openreq, struct UsbFunction *usfkt, struct USBBusCfgDsc *cfgdsc, ULONG tags, ... );

struct USBBusDscHead *USBIntGetConfigurationA( struct IORequest *openreq, struct UsbInterface *usifc, struct TagItem *taglist );
struct USBBusDscHead *USBIntGetConfiguration( struct IORequest *openreq, struct UsbInterface *usifc, ULONG tags, ... );
struct USBBusDscHead *USBIntGetAltSettingA( struct IORequest *openreq, struct UsbInterface *usifc, struct TagItem *taglist );
struct USBBusDscHead *USBIntGetAltSetting( struct IORequest *openreq, struct UsbInterface *usifc, ULONG tags, ... );
LONG USBIntSetAltSettingA( struct IORequest *openreq, struct UsbInterface *usifc, ULONG altnum, struct TagItem *taglist );
LONG USBIntSetAltSetting( struct IORequest *openreq, struct UsbInterface *usifc, ULONG altnum, ULONG tags, ... );

/*
** USB Descriptor handling
*/

struct USBBusDscHead *USBParseDescriptors( struct USBBusDscHead *buffer, ULONG buflen );
void USBFreeDescriptors( struct USBBusDscHead *dscr );
struct USBBusDscHead *USBNextDescriptor( struct USBBusDscHead *dscr );
struct USBBusDscHead *USBPrevDescriptor( struct USBBusDscHead *dscr );

/*
** Resource locking
*/

LONG USBObtainResourceA( ULONG type, APTR object, struct TagItem *taglist );
LONG USBObtainResource( ULONG type, APTR object, ULONG tags, ... );
void USBReleaseResource( ULONG type, APTR object );

/*
** USB Log
*/

void USBLogPuts( LONG err, CONST_STRPTR context, CONST_STRPTR msg );
void USBLogVPrintf( LONG err, CONST_STRPTR context, CONST_STRPTR msg, ULONG *fmtargs );


#endif
