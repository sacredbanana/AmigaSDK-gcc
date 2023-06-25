#ifndef PROTO_REALTIME_H
#define PROTO_REALTIME_H

/*
**	$VER: realtime.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef LIBRARIES_REALTIME_H
#include <libraries/realtime.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * RealTimeBase;
 #else
  extern struct Library * RealTimeBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/realtime.h>
 #ifdef __USE_INLINE__
  #include <inline4/realtime.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_REALTIME_PROTOS_H
  #define CLIB_REALTIME_PROTOS_H 1
 #endif /* CLIB_REALTIME_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::RealTimeIFace * IRealTime;
  #else
   extern struct RealTimeIFace * IRealTime;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_REALTIME_PROTOS_H
  #include <clib/realtime_protos.h>
 #endif /* CLIB_REALTIME_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/realtime.h>
  #else /* __PPC__ */
   #include <ppcinline/realtime.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/realtime_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/realtime_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_REALTIME_H */
