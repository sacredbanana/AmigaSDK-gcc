#ifndef PROTO_DIFFVIEW_H
#define PROTO_DIFFVIEW_H

/*
**	$VER: diffview.h 54.16 (22.08.2022)
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
#ifndef GADGETS_DIFFVIEW_H
#include <gadgets/diffview.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * DiffViewBase;
 #else
  extern struct Library * DiffViewBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/diffview.h>
 #ifdef __USE_INLINE__
  #include <inline4/diffview.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_DIFFVIEW_PROTOS_H
  #define CLIB_DIFFVIEW_PROTOS_H 1
 #endif /* CLIB_DIFFVIEW_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::DiffViewIFace * IDiffView;
  #else
   extern struct DiffViewIFace * IDiffView;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_DIFFVIEW_PROTOS_H
  #include <clib/diffview_protos.h>
 #endif /* CLIB_DIFFVIEW_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/diffview.h>
  #else /* __PPC__ */
   #include <ppcinline/diffview.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/diffview_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/diffview_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_DIFFVIEW_H */
