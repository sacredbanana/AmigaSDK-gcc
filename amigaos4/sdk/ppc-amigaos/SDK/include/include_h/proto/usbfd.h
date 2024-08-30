#ifndef PROTO_USBFD_H
#define PROTO_USBFD_H

/*
**	$VER: usbfd.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * USBFDBase;
 #else
  extern struct Library * USBFDBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/usbfd.h>
 #ifdef __USE_INLINE__
  #include <inline4/usbfd.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_USBFD_PROTOS_H
  #define CLIB_USBFD_PROTOS_H 1
 #endif /* CLIB_USBFD_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct USBFDIFace *IUSBFD;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_USBFD_PROTOS_H
  #include <clib/usbfd_protos.h>
 #endif /* CLIB_USBFD_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/usbfd.h>
  #else /* __PPC__ */
   #include <ppcinline/usbfd.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/usbfd_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/usbfd_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_USBFD_H */
