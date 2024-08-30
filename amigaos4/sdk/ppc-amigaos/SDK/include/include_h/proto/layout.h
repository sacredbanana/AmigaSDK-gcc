#ifndef PROTO_LAYOUT_H
#define PROTO_LAYOUT_H

/*
**	$VER: layout.h 54.16 (22.08.2022)
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
#ifndef GADGETS_LAYOUT_H
#include <gadgets/layout.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * LayoutBase;
 #else
  extern struct Library * LayoutBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * LayoutClass;
  #else
   extern Class * LayoutClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/layout.h>
 #ifdef __USE_INLINE__
  #include <inline4/layout.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_LAYOUT_PROTOS_H
  #define CLIB_LAYOUT_PROTOS_H 1
 #endif /* CLIB_LAYOUT_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::LayoutIFace * ILayout;
  #else
   extern struct LayoutIFace * ILayout;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_LAYOUT_PROTOS_H
  #include <clib/layout_protos.h>
 #endif /* CLIB_LAYOUT_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/layout.h>
  #else /* __PPC__ */
   #include <ppcinline/layout.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/layout_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/layout_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_LAYOUT_H */
