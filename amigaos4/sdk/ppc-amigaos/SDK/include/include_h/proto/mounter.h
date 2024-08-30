#ifndef PROTO_MOUNTER_H
#define PROTO_MOUNTER_H

/*
**	$VER: mounter.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef UTILITY_UTILITY_H
#include <utility/utility.h>
#endif
#ifndef LIBRARIES_MOUNTER_H
#include <libraries/mounter.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * MounterBase;
  #else
   extern struct Library * MounterBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::MounterBase * MounterBase;
  #else
   extern struct MounterBase * MounterBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/mounter.h>
 #ifdef __USE_INLINE__
  #include <inline4/mounter.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_MOUNTER_PROTOS_H
  #define CLIB_MOUNTER_PROTOS_H 1
 #endif /* CLIB_MOUNTER_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::MounterIFace * IMounter;
  #else
   extern struct MounterIFace * IMounter;
  #endif
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::MounterPrivateIFace * IMounterPrivate;
  #else
   extern struct MounterPrivateIFace * IMounterPrivate;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_MOUNTER_PROTOS_H
  #include <clib/mounter_protos.h>
 #endif /* CLIB_MOUNTER_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/mounter.h>
  #else /* __PPC__ */
   #include <ppcinline/mounter.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/mounter_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/mounter_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_MOUNTER_H */
