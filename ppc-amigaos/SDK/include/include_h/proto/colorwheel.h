#ifndef PROTO_COLORWHEEL_H
#define PROTO_COLORWHEEL_H

/*
**	$VER: colorwheel.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef GADGETS_COLORWHEEL_H
#include <gadgets/colorwheel.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * ColorWheelBase;
 #else
  extern struct Library * ColorWheelBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * ColorWheelClass;
  #else
   extern Class * ColorWheelClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/colorwheel.h>
 #ifdef __USE_INLINE__
  #include <inline4/colorwheel.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_COLORWHEEL_PROTOS_H
  #define CLIB_COLORWHEEL_PROTOS_H 1
 #endif /* CLIB_COLORWHEEL_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ColorWheelIFace * IColorWheel;
  #else
   extern struct ColorWheelIFace * IColorWheel;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_COLORWHEEL_PROTOS_H
  #include <clib/colorwheel_protos.h>
 #endif /* CLIB_COLORWHEEL_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/colorwheel.h>
  #else /* __PPC__ */
   #include <ppcinline/colorwheel.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/colorwheel_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/colorwheel_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_COLORWHEEL_H */
