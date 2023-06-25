#ifndef PROTO_LABEL_H
#define PROTO_LABEL_H

/*
**	$VER: label.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * LabelBase;
 #else
  extern struct Library * LabelBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * LabelClass;
  #else
   extern Class * LabelClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/label.h>
 #ifdef __USE_INLINE__
  #include <inline4/label.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_LABEL_PROTOS_H
  #define CLIB_LABEL_PROTOS_H 1
 #endif /* CLIB_LABEL_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::LabelIFace * ILabel;
  #else
   extern struct LabelIFace * ILabel;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_LABEL_PROTOS_H
  #include <clib/label_protos.h>
 #endif /* CLIB_LABEL_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/label.h>
  #else /* __PPC__ */
   #include <ppcinline/label.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/label_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/label_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_LABEL_H */
