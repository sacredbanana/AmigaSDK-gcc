#ifndef CLIB_USBRESOURCE_PROTOS_H
#define CLIB_USBRESOURCE_PROTOS_H

/*
**    $Id: usbresource_protos.h,v 1.1 2010-01-31 03:38:12 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/*
** FD descriptor
*/

APTR USBResRegisterFDA( struct TagItem *taglist );
APTR USBResRegisterFD( ULONG Tag1, ... );
void USBResUnregisterFD( APTR fdkey );

/*
** HCD descriptor
*/

APTR USBResRegisterHCDA( struct TagItem *taglist );
APTR USBResRegisterHCD( ULONG Tag1, ... );
void USBResUnregisterHCD( APTR hcdkey );

/*
** Notification Subscription handling
*/

APTR USBResAddNotify( ULONG type, struct MsgPort *port );
void USBResRemNotify( APTR subs );


#endif
