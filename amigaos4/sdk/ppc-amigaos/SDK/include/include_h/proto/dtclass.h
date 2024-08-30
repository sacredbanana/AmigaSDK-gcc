#ifndef PROTO_DTCLASS_H
#define PROTO_DTCLASS_H

/*
**	$VER: dtclass.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * DTClassBase;
 #else
  extern struct Library * DTClassBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/dtclass.h>
 #ifdef __USE_INLINE__
  #include <inline4/dtclass.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_DTCLASS_PROTOS_H
  #define CLIB_DTCLASS_PROTOS_H 1
 #endif /* CLIB_DTCLASS_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::DTClassIFace * IDTClass;
  #else
   extern struct DTClassIFace * IDTClass;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_DTCLASS_PROTOS_H
  #include <clib/dtclass_protos.h>
 #endif /* CLIB_DTCLASS_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/dtclass.h>
  #else /* __PPC__ */
   #include <ppcinline/dtclass.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/dtclass_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/dtclass_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_DTCLASS_H */
