#ifndef PROTO_TIMESYNC_H
#define PROTO_TIMESYNC_H

/*
**	$VER: timesync.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef LIBRARIES_TIMESYNC_H
#include <libraries/timesync.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * TimesyncBase;
 #else
  extern struct Library * TimesyncBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/timesync.h>
 #ifdef __USE_INLINE__
  #include <inline4/timesync.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_TIMESYNC_PROTOS_H
  #define CLIB_TIMESYNC_PROTOS_H 1
 #endif /* CLIB_TIMESYNC_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::TimesyncIFace * ITimesync;
  #else
   extern struct TimesyncIFace * ITimesync;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_TIMESYNC_PROTOS_H
  #include <clib/timesync_protos.h>
 #endif /* CLIB_TIMESYNC_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/timesync.h>
  #else /* __PPC__ */
   #include <ppcinline/timesync.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/timesync_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/timesync_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_TIMESYNC_H */
