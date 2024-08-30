#ifndef PROTO_TIMEZONE_H
#define PROTO_TIMEZONE_H

/*
**	$VER: timezone.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef LIBRARIES_TIMEZONE_H
#include <libraries/timezone.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * TimezoneBase;
 #else
  extern struct Library * TimezoneBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/timezone.h>
 #ifdef __USE_INLINE__
  #include <inline4/timezone.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_TIMEZONE_PROTOS_H
  #define CLIB_TIMEZONE_PROTOS_H 1
 #endif /* CLIB_TIMEZONE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::TimezoneIFace * ITimezone;
  #else
   extern struct TimezoneIFace * ITimezone;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_TIMEZONE_PROTOS_H
  #include <clib/timezone_protos.h>
 #endif /* CLIB_TIMEZONE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/timezone.h>
  #else /* __PPC__ */
   #include <ppcinline/timezone.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/timezone_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/timezone_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_TIMEZONE_H */
