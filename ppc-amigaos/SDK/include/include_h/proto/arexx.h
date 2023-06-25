#ifndef PROTO_AREXX_H
#define PROTO_AREXX_H

/*
**	$VER: arexx.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * ARexxBase;
 #else
  extern struct Library * ARexxBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * ARexxClass;
  #else
   extern Class * ARexxClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/arexx.h>
 #ifdef __USE_INLINE__
  #include <inline4/arexx.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_AREXX_PROTOS_H
  #define CLIB_AREXX_PROTOS_H 1
 #endif /* CLIB_AREXX_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ARexxIFace * IARexx;
  #else
   extern struct ARexxIFace * IARexx;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_AREXX_PROTOS_H
  #include <clib/arexx_protos.h>
 #endif /* CLIB_AREXX_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/arexx.h>
  #else /* __PPC__ */
   #include <ppcinline/arexx.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/arexx_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/arexx_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_AREXX_H */
