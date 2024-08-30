#ifndef PROTO_AHI_SUB_H
#define PROTO_AHI_SUB_H

/*
**	$VER: ahi_sub.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_AHI_SUB_H
#include <libraries/ahi_sub.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * AHIsubBase;
  #else
   extern struct Library * AHIsubBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * AHIsubBase;
  #else
   extern struct Library * AHIsubBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/ahi_sub.h>
 #ifdef __USE_INLINE__
  #include <inline4/ahi_sub.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_AHI_SUB_PROTOS_H
  #define CLIB_AHI_SUB_PROTOS_H 1
 #endif /* CLIB_AHI_SUB_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::AHIsubIFace * IAHIsub;
  #else
   extern struct AHIsubIFace * IAHIsub;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_AHI_SUB_PROTOS_H
  #include <clib/ahi_sub_protos.h>
 #endif /* CLIB_AHI_SUB_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/ahi_sub.h>
  #else /* __PPC__ */
   #include <ppcinline/ahi_sub.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/ahi_sub_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/ahi_sub_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_AHI_SUB_H */
