#ifndef PROTO_TIMER_H
#define PROTO_TIMER_H

/*
**	$VER: timer.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Device * TimerBase;
  #else
   extern struct Device * TimerBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Device * TimerBase;
  #else
   extern struct Device * TimerBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/timer.h>
 #ifdef __USE_INLINE__
  #include <inline4/timer.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_TIMER_PROTOS_H
  #define CLIB_TIMER_PROTOS_H 1
 #endif /* CLIB_TIMER_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::TimerIFace * ITimer;
  #else
   extern struct TimerIFace * ITimer;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_TIMER_PROTOS_H
  #include <clib/timer_protos.h>
 #endif /* CLIB_TIMER_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/timer.h>
  #else /* __PPC__ */
   #include <ppcinline/timer.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/timer_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/timer_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_TIMER_H */
