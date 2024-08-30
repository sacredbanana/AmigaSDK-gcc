#ifndef PROTO_SLIDER_H
#define PROTO_SLIDER_H

/*
**	$VER: slider.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * SliderBase;
 #else
  extern struct Library * SliderBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * SliderClass;
  #else
   extern Class * SliderClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/slider.h>
 #ifdef __USE_INLINE__
  #include <inline4/slider.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_SLIDER_PROTOS_H
  #define CLIB_SLIDER_PROTOS_H 1
 #endif /* CLIB_SLIDER_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::SliderIFace * ISlider;
  #else
   extern struct SliderIFace * ISlider;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_SLIDER_PROTOS_H
  #include <clib/slider_protos.h>
 #endif /* CLIB_SLIDER_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/slider.h>
  #else /* __PPC__ */
   #include <ppcinline/slider.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/slider_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/slider_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_SLIDER_H */
