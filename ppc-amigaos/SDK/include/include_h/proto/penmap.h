#ifndef PROTO_PENMAP_H
#define PROTO_PENMAP_H

/*
**	$VER: penmap.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * PenMapBase;
 #else
  extern struct Library * PenMapBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * PenMapClass;
  #else
   extern Class * PenMapClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/penmap.h>
 #ifdef __USE_INLINE__
  #include <inline4/penmap.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_PENMAP_PROTOS_H
  #define CLIB_PENMAP_PROTOS_H 1
 #endif /* CLIB_PENMAP_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::PenMapIFace * IPenMap;
  #else
   extern struct PenMapIFace * IPenMap;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_PENMAP_PROTOS_H
  #include <clib/penmap_protos.h>
 #endif /* CLIB_PENMAP_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/penmap.h>
  #else /* __PPC__ */
   #include <ppcinline/penmap.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/penmap_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/penmap_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_PENMAP_H */
