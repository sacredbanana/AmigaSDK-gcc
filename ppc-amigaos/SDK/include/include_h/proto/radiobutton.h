#ifndef PROTO_RADIOBUTTON_H
#define PROTO_RADIOBUTTON_H

/*
**	$VER: radiobutton.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * RadioButtonBase;
 #else
  extern struct Library * RadioButtonBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * RadioButtonClass;
  #else
   extern Class * RadioButtonClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/radiobutton.h>
 #ifdef __USE_INLINE__
  #include <inline4/radiobutton.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_RADIOBUTTON_PROTOS_H
  #define CLIB_RADIOBUTTON_PROTOS_H 1
 #endif /* CLIB_RADIOBUTTON_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::RadioButtonIFace * IRadioButton;
  #else
   extern struct RadioButtonIFace * IRadioButton;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_RADIOBUTTON_PROTOS_H
  #include <clib/radiobutton_protos.h>
 #endif /* CLIB_RADIOBUTTON_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/radiobutton.h>
  #else /* __PPC__ */
   #include <ppcinline/radiobutton.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/radiobutton_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/radiobutton_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_RADIOBUTTON_H */
