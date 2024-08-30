#ifndef PROTO_BATTMEM_H
#define PROTO_BATTMEM_H

/*
**	$VER: battmem.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * BattMemBase;
 #else
  extern struct Library * BattMemBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/battmem.h>
 #ifdef __USE_INLINE__
  #include <inline4/battmem.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_BATTMEM_PROTOS_H
  #define CLIB_BATTMEM_PROTOS_H 1
 #endif /* CLIB_BATTMEM_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::BattMemIFace * IBattMem;
  #else
   extern struct BattMemIFace * IBattMem;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_BATTMEM_PROTOS_H
  #include <clib/battmem_protos.h>
 #endif /* CLIB_BATTMEM_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/battmem.h>
  #else /* __PPC__ */
   #include <ppcinline/battmem.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/battmem_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/battmem_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_BATTMEM_H */
