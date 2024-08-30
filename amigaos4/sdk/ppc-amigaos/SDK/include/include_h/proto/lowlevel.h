#ifndef PROTO_LOWLEVEL_H
#define PROTO_LOWLEVEL_H

/*
**	$VER: lowlevel.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef LIBRARIES_LOWLEVEL_H
#include <libraries/lowlevel.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * LowLevelBase;
 #else
  extern struct Library * LowLevelBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/lowlevel.h>
 #ifdef __USE_INLINE__
  #include <inline4/lowlevel.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_LOWLEVEL_PROTOS_H
  #define CLIB_LOWLEVEL_PROTOS_H 1
 #endif /* CLIB_LOWLEVEL_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::LowLevelIFace * ILowLevel;
  #else
   extern struct LowLevelIFace * ILowLevel;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_LOWLEVEL_PROTOS_H
  #include <clib/lowlevel_protos.h>
 #endif /* CLIB_LOWLEVEL_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/lowlevel.h>
  #else /* __PPC__ */
   #include <ppcinline/lowlevel.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/lowlevel_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/lowlevel_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_LOWLEVEL_H */
