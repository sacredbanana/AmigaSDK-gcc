#ifndef PROTO_BOOTSD_H
#define PROTO_BOOTSD_H

/*
**	$VER: bootsd.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/


/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * BootSDBase;
 #else
  extern struct Library * BootSDBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/bootsd.h>
 #ifdef __USE_INLINE__
  #include <inline4/bootsd.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_BOOTSD_PROTOS_H
  #define CLIB_BOOTSD_PROTOS_H 1
 #endif /* CLIB_BOOTSD_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::BootSDIFace * IBootSD;
  #else
   extern struct BootSDIFace * IBootSD;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_BOOTSD_PROTOS_H
  #include <clib/bootsd_protos.h>
 #endif /* CLIB_BOOTSD_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/bootsd.h>
  #else /* __PPC__ */
   #include <ppcinline/bootsd.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/bootsd_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/bootsd_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_BOOTSD_H */
