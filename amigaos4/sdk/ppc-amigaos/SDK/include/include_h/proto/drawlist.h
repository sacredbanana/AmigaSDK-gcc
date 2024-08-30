#ifndef PROTO_DRAWLIST_H
#define PROTO_DRAWLIST_H

/*
**	$VER: drawlist.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * DrawListBase;
 #else
  extern struct Library * DrawListBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * DrawListClass;
  #else
   extern Class * DrawListClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/drawlist.h>
 #ifdef __USE_INLINE__
  #include <inline4/drawlist.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_DRAWLIST_PROTOS_H
  #define CLIB_DRAWLIST_PROTOS_H 1
 #endif /* CLIB_DRAWLIST_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::DrawListIFace * IDrawList;
  #else
   extern struct DrawListIFace * IDrawList;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_DRAWLIST_PROTOS_H
  #include <clib/drawlist_protos.h>
 #endif /* CLIB_DRAWLIST_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/drawlist.h>
  #else /* __PPC__ */
   #include <ppcinline/drawlist.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/drawlist_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/drawlist_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_DRAWLIST_H */
