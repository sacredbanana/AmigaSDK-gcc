#ifndef PROTO_SPACE_H
#define PROTO_SPACE_H

/*
**	$VER: space.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * SpaceBase;
 #else
  extern struct Library * SpaceBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * SpaceClass;
  #else
   extern Class * SpaceClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/space.h>
 #ifdef __USE_INLINE__
  #include <inline4/space.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_SPACE_PROTOS_H
  #define CLIB_SPACE_PROTOS_H 1
 #endif /* CLIB_SPACE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::SpaceIFace * ISpace;
  #else
   extern struct SpaceIFace * ISpace;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_SPACE_PROTOS_H
  #include <clib/space_protos.h>
 #endif /* CLIB_SPACE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/space.h>
  #else /* __PPC__ */
   #include <ppcinline/space.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/space_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/space_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_SPACE_H */
