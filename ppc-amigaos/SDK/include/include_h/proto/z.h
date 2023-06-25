#ifndef PROTO_Z_H
#define PROTO_Z_H

/*
**	$VER: z.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef LIBRARIES_Z_H
#include <libraries/z.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * ZBase;
  #else
   extern struct Library * ZBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ZLibBase * ZBase;
  #else
   extern struct ZLibBase * ZBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/z.h>
 #ifdef __USE_INLINE__
  #include <inline4/z.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_Z_PROTOS_H
  #define CLIB_Z_PROTOS_H 1
 #endif /* CLIB_Z_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ZIFace * IZ;
  #else
   extern struct ZIFace * IZ;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_Z_PROTOS_H
  #include <clib/z_protos.h>
 #endif /* CLIB_Z_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/z.h>
  #else /* __PPC__ */
   #include <ppcinline/z.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/z_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/z_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_Z_H */
