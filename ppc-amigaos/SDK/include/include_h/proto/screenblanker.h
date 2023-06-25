#ifndef PROTO_SCREENBLANKER_H
#define PROTO_SCREENBLANKER_H

/*
**	$VER: screenblanker.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef PROTO_BLANKERMODULE_H
#include <proto/blankermodule.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * ScreenBlanker;
 #else
  extern struct Library * ScreenBlanker;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/screenblanker.h>
 #ifdef __USE_INLINE__
  #include <inline4/screenblanker.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_SCREENBLANKER_PROTOS_H
  #define CLIB_SCREENBLANKER_PROTOS_H 1
 #endif /* CLIB_SCREENBLANKER_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ScreenBlankerIFace * IScreenBlanker;
  #else
   extern struct ScreenBlankerIFace * IScreenBlanker;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_SCREENBLANKER_PROTOS_H
  #include <clib/screenblanker_protos.h>
 #endif /* CLIB_SCREENBLANKER_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/screenblanker.h>
  #else /* __PPC__ */
   #include <ppcinline/screenblanker.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/screenblanker_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/screenblanker_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_SCREENBLANKER_H */
