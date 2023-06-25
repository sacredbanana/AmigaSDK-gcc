#ifndef PROTO_USBHCD_H
#define PROTO_USBHCD_H

/*
**	$VER: usbhcd.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef USB_SYSTEM_H
#include <usb/system.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * USBHCDBase;
 #else
  extern struct Library * USBHCDBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/usbhcd.h>
 #ifdef __USE_INLINE__
  #include <inline4/usbhcd.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_USBHCD_PROTOS_H
  #define CLIB_USBHCD_PROTOS_H 1
 #endif /* CLIB_USBHCD_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct USBHCDIFace *IUSBHCD;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_USBHCD_PROTOS_H
  #include <clib/usbhcd_protos.h>
 #endif /* CLIB_USBHCD_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/usbhcd.h>
  #else /* __PPC__ */
   #include <ppcinline/usbhcd.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/usbhcd_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/usbhcd_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_USBHCD_H */
