#ifndef PROTO_BZIP2_H
#define PROTO_BZIP2_H

/*
**	$VER: bzip2.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef LIBRARIES_BZIP2_H
#include <libraries/bzip2.h>
#endif
#ifndef STDIO_H
#include <stdio.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * BZip2Base;
  #else
   extern struct Library * BZip2Base;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * BZip2Base;
  #else
   extern struct Library * BZip2Base;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/bzip2.h>
 #ifdef __USE_INLINE__
  #include <inline4/bzip2.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_BZIP2_PROTOS_H
  #define CLIB_BZIP2_PROTOS_H 1
 #endif /* CLIB_BZIP2_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::BZip2IFace * IBZip2;
  #else
   extern struct BZip2IFace * IBZip2;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_BZIP2_PROTOS_H
  #include <clib/bzip2_protos.h>
 #endif /* CLIB_BZIP2_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/bzip2.h>
  #else /* __PPC__ */
   #include <ppcinline/bzip2.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/bzip2_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/bzip2_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_BZIP2_H */
