#ifndef CLIB_USBFD_PROTOS_H
#define CLIB_USBFD_PROTOS_H

/*
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
**    Copyright (c) 2025 Hyperion Entertainment BV.
**        All Rights Reserved.
*/

void USBFDGetAttrsA( struct TagItem *taglist );
void USBFDGetAttrs( ULONG tags, ... );

LONG USBFDRunFunction( struct USBFDStartupMsg *startmsg );
LONG USBFDRunInterface( struct USBFDStartupMsg *startmsg );


#endif
