#ifndef PROTO_DOCKY_H
#define PROTO_DOCKY_H

/*
**	$VER: docky.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * Docky;
 #else
  extern struct Library * Docky;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/docky.h>
 #ifdef __USE_INLINE__
  #include <inline4/docky.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_DOCKY_PROTOS_H
  #define CLIB_DOCKY_PROTOS_H 1
 #endif /* CLIB_DOCKY_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::DockyIFace * IDocky;
  #else
   extern struct DockyIFace * IDocky;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_DOCKY_PROTOS_H
  #include <clib/docky_protos.h>
 #endif /* CLIB_DOCKY_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/docky.h>
  #else /* __PPC__ */
   #include <ppcinline/docky.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/docky_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/docky_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_DOCKY_H */
