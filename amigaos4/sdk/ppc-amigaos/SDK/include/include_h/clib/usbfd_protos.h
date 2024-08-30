#ifndef CLIB_USBFD_PROTOS_H
#define CLIB_USBFD_PROTOS_H

/*
**    $Id: usbfd_protos.h,v 1.1 2010-01-31 03:38:12 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

void USBFDGetAttrsA( struct TagItem *taglist );
void USBFDGetAttrs( ULONG tags, ... );

LONG USBFDRunFunction( struct USBFDStartupMsg *startmsg );
LONG USBFDRunInterface( struct USBFDStartupMsg *startmsg );


#endif
