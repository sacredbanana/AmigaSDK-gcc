#ifndef PROTO_CHOOSER_H
#define PROTO_CHOOSER_H

/*
**	$VER: chooser.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * ChooserBase;
 #else
  extern struct Library * ChooserBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * ChooserClass;
  #else
   extern Class * ChooserClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/chooser.h>
 #ifdef __USE_INLINE__
  #include <inline4/chooser.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_CHOOSER_PROTOS_H
  #define CLIB_CHOOSER_PROTOS_H 1
 #endif /* CLIB_CHOOSER_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ChooserIFace * IChooser;
  #else
   extern struct ChooserIFace * IChooser;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_CHOOSER_PROTOS_H
  #include <clib/chooser_protos.h>
 #endif /* CLIB_CHOOSER_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/chooser.h>
  #else /* __PPC__ */
   #include <ppcinline/chooser.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/chooser_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/chooser_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_CHOOSER_H */
