#ifndef PROTO_POTGO_H
#define PROTO_POTGO_H

/*
**	$VER: potgo.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * PotgoBase;
 #else
  extern struct Library * PotgoBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/potgo.h>
 #ifdef __USE_INLINE__
  #include <inline4/potgo.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_POTGO_PROTOS_H
  #define CLIB_POTGO_PROTOS_H 1
 #endif /* CLIB_POTGO_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::PotgoIFace * IPotgo;
  #else
   extern struct PotgoIFace * IPotgo;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_POTGO_PROTOS_H
  #include <clib/potgo_protos.h>
 #endif /* CLIB_POTGO_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/potgo.h>
  #else /* __PPC__ */
   #include <ppcinline/potgo.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/potgo_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/potgo_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_POTGO_H */
