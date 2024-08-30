#ifndef PROTO_AHI_H
#define PROTO_AHI_H

/*
**	$VER: ahi.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_DEVICES_H
#include <exec/devices.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef DEVICES_AHI_H
#include <devices/ahi.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Device * AHIBase;
  #else
   extern struct Device * AHIBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * AHIBase;
  #else
   extern struct Library * AHIBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/ahi.h>
 #ifdef __USE_INLINE__
  #include <inline4/ahi.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_AHI_PROTOS_H
  #define CLIB_AHI_PROTOS_H 1
 #endif /* CLIB_AHI_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::AHIIFace * IAHI;
  #else
   extern struct AHIIFace * IAHI;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_AHI_PROTOS_H
  #include <clib/ahi_protos.h>
 #endif /* CLIB_AHI_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/ahi.h>
  #else /* __PPC__ */
   #include <ppcinline/ahi.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/ahi_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/ahi_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_AHI_H */
