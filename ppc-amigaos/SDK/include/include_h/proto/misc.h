#ifndef PROTO_MISC_H
#define PROTO_MISC_H

/*
**	$VER: misc.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * MiscBase;
 #else
  extern struct Library * MiscBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/misc.h>
 #ifdef __USE_INLINE__
  #include <inline4/misc.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_MISC_PROTOS_H
  #define CLIB_MISC_PROTOS_H 1
 #endif /* CLIB_MISC_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::MiscIFace * IMisc;
  #else
   extern struct MiscIFace * IMisc;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_MISC_PROTOS_H
  #include <clib/misc_protos.h>
 #endif /* CLIB_MISC_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/misc.h>
  #else /* __PPC__ */
   #include <ppcinline/misc.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/misc_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/misc_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_MISC_H */
