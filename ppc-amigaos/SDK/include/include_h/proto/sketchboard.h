#ifndef PROTO_SKETCHBOARD_H
#define PROTO_SKETCHBOARD_H

/*
**	$VER: sketchboard.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * SketchBoardBase;
 #else
  extern struct Library * SketchBoardBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/sketchboard.h>
 #ifdef __USE_INLINE__
  #include <inline4/sketchboard.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_SKETCHBOARD_PROTOS_H
  #define CLIB_SKETCHBOARD_PROTOS_H 1
 #endif /* CLIB_SKETCHBOARD_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::SketchBoardIFace * ISketchBoard;
  #else
   extern struct SketchBoardIFace * ISketchBoard;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_SKETCHBOARD_PROTOS_H
  #include <clib/sketchboard_protos.h>
 #endif /* CLIB_SKETCHBOARD_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/sketchboard.h>
  #else /* __PPC__ */
   #include <ppcinline/sketchboard.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/sketchboard_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/sketchboard_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_SKETCHBOARD_H */
