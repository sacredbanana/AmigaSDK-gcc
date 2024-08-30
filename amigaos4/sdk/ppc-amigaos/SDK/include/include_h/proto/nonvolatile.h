#ifndef PROTO_NONVOLATILE_H
#define PROTO_NONVOLATILE_H

/*
**	$VER: nonvolatile.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef LIBRARIES_NONVOLATILE_H
#include <libraries/nonvolatile.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * NVBase;
 #else
  extern struct Library * NVBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/nonvolatile.h>
 #ifdef __USE_INLINE__
  #include <inline4/nonvolatile.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_NONVOLATILE_PROTOS_H
  #define CLIB_NONVOLATILE_PROTOS_H 1
 #endif /* CLIB_NONVOLATILE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::NVIFace * INV;
  #else
   extern struct NVIFace * INV;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_NONVOLATILE_PROTOS_H
  #include <clib/nonvolatile_protos.h>
 #endif /* CLIB_NONVOLATILE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/nonvolatile.h>
  #else /* __PPC__ */
   #include <ppcinline/nonvolatile.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/nonvolatile_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/nonvolatile_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_NONVOLATILE_H */
