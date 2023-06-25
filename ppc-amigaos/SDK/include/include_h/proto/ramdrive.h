#ifndef PROTO_RAMDRIVE_H
#define PROTO_RAMDRIVE_H

/*
**	$VER: ramdrive.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Device * RamdriveDevice;
 #else
  extern struct Device * RamdriveDevice;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/ramdrive.h>
 #ifdef __USE_INLINE__
  #include <inline4/ramdrive.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_RAMDRIVE_PROTOS_H
  #define CLIB_RAMDRIVE_PROTOS_H 1
 #endif /* CLIB_RAMDRIVE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::RamdriveIFace * IRamdrive;
  #else
   extern struct RamdriveIFace * IRamdrive;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_RAMDRIVE_PROTOS_H
  #include <clib/ramdrive_protos.h>
 #endif /* CLIB_RAMDRIVE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/ramdrive.h>
  #else /* __PPC__ */
   #include <ppcinline/ramdrive.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/ramdrive_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/ramdrive_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_RAMDRIVE_H */
