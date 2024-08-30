#ifndef CLIB_USBHCD_PROTOS_H
#define CLIB_USBHCD_PROTOS_H

/*
**    $Id: usbhcd_protos.h,v 1.1 2010-01-31 03:38:12 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/


APTR USBHCAddFunctionA( APTR hcunit, APTR hchub, APTR usfkt, struct TagItem *taglist );
APTR USBHCAddFunction( APTR hcunit, APTR hchub, APTR usfkt, ULONG tags, ... );
void USBHCRemFunction( APTR hcunit, APTR hcfkt);

APTR USBHCAddEndPointA( APTR hcunit, APTR hcfkt, APTR usep, LONG epnum, struct TagItem *taglist );
APTR USBHCAddEndPoint( APTR hcunit, APTR hcfkt, APTR usep, LONG epnum, ULONG tags, ... );
void USBHCRemEndPoint( APTR hcunit, APTR hcep );

void USBHCGetAttrsA( struct TagItem *taglist );
void USBHCGetAttrs( ULONG tags, ... );

LONG USBHCInitRootHubA( APTR hcunit, struct UsbRawInterface *usifc, APTR *hcfkt, struct TagItem *taglist );
LONG USBHCInitRootHub( APTR hcunit, struct UsbRawInterface *usifc, APTR *hcfkt, ULONG tags, ... );
void USBHCUninitRootHub( APTR hcunit, APTR hcfkt );


#endif
