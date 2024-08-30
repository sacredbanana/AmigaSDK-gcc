#ifndef PROTO_ASL_H
#define PROTO_ASL_H

/*
**	$VER: asl.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_ASL_H
#include <libraries/asl.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * AslBase;
 #else
  extern struct Library * AslBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/asl.h>
 #ifdef __USE_INLINE__
  #include <inline4/asl.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_ASL_PROTOS_H
  #define CLIB_ASL_PROTOS_H 1
 #endif /* CLIB_ASL_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::AslIFace * IAsl;
  #else
   extern struct AslIFace * IAsl;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_ASL_PROTOS_H
  #include <clib/asl_protos.h>
 #endif /* CLIB_ASL_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/asl.h>
  #else /* __PPC__ */
   #include <ppcinline/asl.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/asl_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/asl_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_ASL_H */
