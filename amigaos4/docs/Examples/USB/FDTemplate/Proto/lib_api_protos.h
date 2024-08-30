/*
**
** Libary specific Prototypes
**
*/

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef USB_SYSTEM_H
#include <usb/system.h>
#endif

#ifndef LibCall
#define LibCall __saveds
#endif

// ---

void LibCall USBFDGetAttrsA( __REGA0(struct TagItem *taglist) );
LONG LibCall USBFDRunFunction( __REGA0(struct USBFDStartupMsg *startmsg) );
LONG LibCall USBFDRunInterface( __REGA0(struct USBFDStartupMsg *startmsg) );