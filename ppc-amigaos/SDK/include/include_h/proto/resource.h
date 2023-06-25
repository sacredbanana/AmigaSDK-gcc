#ifndef PROTO_RESOURCE_H
#define PROTO_RESOURCE_H

/*
**	$VER: resource.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef LIBRARIES_RESOURCE_H
#include <libraries/resource.h>
#endif
#ifndef INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef LIBRARIES_LOCALE_H
#include <libraries/locale.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * ResourceBase;
 #else
  extern struct Library * ResourceBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/resource.h>
 #ifdef __USE_INLINE__
  #include <inline4/resource.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_RESOURCE_PROTOS_H
  #define CLIB_RESOURCE_PROTOS_H 1
 #endif /* CLIB_RESOURCE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ResourceIFace * IResource;
  #else
   extern struct ResourceIFace * IResource;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_RESOURCE_PROTOS_H
  #include <clib/resource_protos.h>
 #endif /* CLIB_RESOURCE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/resource.h>
  #else /* __PPC__ */
   #include <ppcinline/resource.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/resource_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/resource_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_RESOURCE_H */
