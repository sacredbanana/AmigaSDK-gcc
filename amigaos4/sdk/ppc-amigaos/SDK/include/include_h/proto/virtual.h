#ifndef PROTO_VIRTUAL_H
#define PROTO_VIRTUAL_H

/*
**	$VER: virtual.h 54.16 (22.08.2022)
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
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef GADGETS_LAYOUT_H
#include <gadgets/layout.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * VirtualBase;
 #else
  extern struct Library * VirtualBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/virtual.h>
 #ifdef __USE_INLINE__
  #include <inline4/virtual.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_VIRTUAL_PROTOS_H
  #define CLIB_VIRTUAL_PROTOS_H 1
 #endif /* CLIB_VIRTUAL_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::VirtualIFace * IVirtual;
  #else
   extern struct VirtualIFace * IVirtual;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_VIRTUAL_PROTOS_H
  #include <clib/virtual_protos.h>
 #endif /* CLIB_VIRTUAL_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/virtual.h>
  #else /* __PPC__ */
   #include <ppcinline/virtual.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/virtual_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/virtual_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_VIRTUAL_H */
