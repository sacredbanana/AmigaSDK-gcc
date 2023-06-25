#ifndef PROTO_FILLER_H
#define PROTO_FILLER_H

/*
**	$VER: filler.h 54.16 (22.08.2022)
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
  extern struct AmigaOS::Library * FillerBase;
 #else
  extern struct Library * FillerBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/filler.h>
 #ifdef __USE_INLINE__
  #include <inline4/filler.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_FILLER_PROTOS_H
  #define CLIB_FILLER_PROTOS_H 1
 #endif /* CLIB_FILLER_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::FillerIFace * IFiller;
  #else
   extern struct FillerIFace * IFiller;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_FILLER_PROTOS_H
  #include <clib/filler_protos.h>
 #endif /* CLIB_FILLER_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/filler.h>
  #else /* __PPC__ */
   #include <ppcinline/filler.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/filler_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/filler_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_FILLER_H */
