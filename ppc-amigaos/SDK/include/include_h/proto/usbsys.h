#ifndef PROTO_USBSYS_H
#define PROTO_USBSYS_H

/*
**	$VER: usbsys.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef USB_SYSTEM_H
#include <usb/system.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Device * USBSysBase;
 #else
  extern struct Device * USBSysBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/usbsys.h>
 #ifdef __USE_INLINE__
  #include <inline4/usbsys.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_USBSYS_PROTOS_H
  #define CLIB_USBSYS_PROTOS_H 1
 #endif /* CLIB_USBSYS_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct USBSysIFace *IUSBSys;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_USBSYS_PROTOS_H
  #include <clib/usbsys_protos.h>
 #endif /* CLIB_USBSYS_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/usbsys.h>
  #else /* __PPC__ */
   #include <ppcinline/usbsys.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/usbsys_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/usbsys_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_USBSYS_H */
