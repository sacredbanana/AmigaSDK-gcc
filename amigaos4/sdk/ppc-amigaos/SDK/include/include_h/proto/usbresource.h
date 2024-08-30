#ifndef PROTO_USBRESOURCE_H
#define PROTO_USBRESOURCE_H

/*
**	$VER: usbresource.h 54.16 (22.08.2022)
**	Includes Release 50.1
**
**	Prototype/inline/pragma header file combo
**
**	(C) Copyright 2003-2004 Amiga, Inc.
**	    All Rights Reserved
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

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * USBResourceBase;
 #else
  extern struct Library * USBResourceBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/usbresource.h>
 #ifdef __USE_INLINE__
  #include <inline4/usbresource.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_USBRESOURCE_PROTOS_H
  #define CLIB_USBRESOURCE_PROTOS_H 1
 #endif /* CLIB_USBRESOURCE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct USBResourceIFace *IUSBResource;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_USBRESOURCE_PROTOS_H
  #include <clib/usbresource_protos.h>
 #endif /* CLIB_USBRESOURCE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/usbresource.h>
  #else
   #include <ppcinline/usbresource.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/usbresource_protos.h>
  #endif /* __PPC__ */
 #else
  #include <pragmas/usbresource_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_USBRESOURCE_H */
