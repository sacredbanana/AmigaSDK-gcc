#ifndef  CLIB_USBCLASS_PROTOS_H
#define  CLIB_USBCLASS_PROTOS_H

/*
**	$Id: usbclass_protos.h,v 1.3 2008/09/15 21:36:25 piru Exp $
**
**	C prototypes. For use with 32 bit integers only.
**
**	Copyright © 2002 Chris Hodges
**	    All Rights Reserved
*/

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef  EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif
#ifndef  EXEC_DEVICES_H
#include <exec/devices.h>
#endif
#ifndef  EXEC_IO_H
#include <exec/io.h>
#endif
#ifndef  EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef  UTILITY_UTILITY_H
#include <utility/utility.h>
#endif
#ifndef  DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef  LIBRARIES_POSEIDON_H
#include <libraries/poseidon.h>
#endif
#ifndef  LIBRARIES_USBCLASS_H
#include <libraries/usbclass.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

APTR usbAttemptInterfaceBinding( APTR pif );
VOID usbReleaseInterfaceBinding( APTR uifb );
APTR usbAttemptDeviceBinding( APTR pd );
VOID usbReleaseDeviceBinding( APTR udb );
APTR usbForceInterfaceBinding( APTR pif );
APTR usbForceDeviceBinding( APTR pd );
LONG usbGetAttrsA( ULONG type, APTR usbstruct, struct TagItem *taglist );
LONG usbGetAttrs( ULONG type, APTR usbstruct, ULONG tag1, ... );
LONG usbSetAttrsA( ULONG type, APTR usbstruct, struct TagItem *taglist );
LONG usbSetAttrs( ULONG type, APTR usbstruct, ULONG tag1, ... );
LONG usbDoMethodA( ULONG methodid, APTR methoddata );
LONG usbDoMethod( ULONG methodid, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_USBCLASS_PROTOS_H */
