#ifndef PROTO_BATTCLOCK_H
#define PROTO_BATTCLOCK_H

/*
**	$VER: battclock.h 54.16 (22.08.2022)
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
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * BattClockBase;
 #else
  extern struct Library * BattClockBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/battclock.h>
 #ifdef __USE_INLINE__
  #include <inline4/battclock.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_BATTCLOCK_PROTOS_H
  #define CLIB_BATTCLOCK_PROTOS_H 1
 #endif /* CLIB_BATTCLOCK_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::BattClockIFace * IBattClock;
  #else
   extern struct BattClockIFace * IBattClock;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_BATTCLOCK_PROTOS_H
  #include <clib/battclock_protos.h>
 #endif /* CLIB_BATTCLOCK_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/battclock.h>
  #else /* __PPC__ */
   #include <ppcinline/battclock.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/battclock_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/battclock_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_BATTCLOCK_H */
