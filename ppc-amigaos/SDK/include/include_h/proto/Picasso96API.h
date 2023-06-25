#ifndef PROTO_PICASSO96API_H
#define PROTO_PICASSO96API_H

/*
**	$VER: Picasso96API.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef LIBRARIES_PICASSO96_H
#include <libraries/Picasso96.h>
#endif
#ifndef GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif
#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * P96Base;
 #else
  extern struct Library * P96Base;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/Picasso96API.h>
 #ifdef __USE_INLINE__
  #include <inline4/Picasso96API.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_PICASSO96API_PROTOS_H
  #define CLIB_PICASSO96API_PROTOS_H 1
 #endif /* CLIB_PICASSO96API_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::P96IFace * IP96;
  #else
   extern struct P96IFace * IP96;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_PICASSO96API_PROTOS_H
  #include <clib/Picasso96API_protos.h>
 #endif /* CLIB_PICASSO96API_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/Picasso96API.h>
  #else /* __PPC__ */
   #include <ppcinline/Picasso96API.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/Picasso96API_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/Picasso96API_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_PICASSO96API_H */
