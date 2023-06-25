#ifndef PROTO_INTUITION_H
#define PROTO_INTUITION_H

/*
**	$VER: intuition.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef INTUITION_INTUITIONBASE_H
#include <intuition/intuitionbase.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef INTUITION_CGHOOKS_H
#include <intuition/cghooks.h>
#endif
#ifndef INTUITION_SGHOOKS_H
#include <intuition/sghooks.h>
#endif
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef INTUITION_NOTIFY_H
#include <intuition/notify.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * IntuitionBase;
  #else
   extern struct Library * IntuitionBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::IntuitionBase * IntuitionBase;
  #else
   extern struct IntuitionBase * IntuitionBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/intuition.h>
 #ifdef __USE_INLINE__
  #include <inline4/intuition.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_INTUITION_PROTOS_H
  #define CLIB_INTUITION_PROTOS_H 1
 #endif /* CLIB_INTUITION_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::IntuitionIFace * IIntuition;
  #else
   extern struct IntuitionIFace * IIntuition;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_INTUITION_PROTOS_H
  #include <clib/intuition_protos.h>
 #endif /* CLIB_INTUITION_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/intuition.h>
  #else /* __PPC__ */
   #include <ppcinline/intuition.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/intuition_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/intuition_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_INTUITION_H */
