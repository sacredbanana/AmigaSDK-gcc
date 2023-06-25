#ifndef PROTO_DISKIO_H
#define PROTO_DISKIO_H

/*
**	$VER: diskio.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_DISKIO_H
#include <libraries/diskio.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * DiskIOBase;
  #else
   extern struct Library * DiskIOBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * DiskIOBase;
  #else
   extern struct Library * DiskIOBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/diskio.h>
 #ifdef __USE_INLINE__
  #include <inline4/diskio.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_DISKIO_PROTOS_H
  #define CLIB_DISKIO_PROTOS_H 1
 #endif /* CLIB_DISKIO_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::DiskIOIFace * IDiskIO;
  #else
   extern struct DiskIOIFace * IDiskIO;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_DISKIO_PROTOS_H
  #include <clib/diskio_protos.h>
 #endif /* CLIB_DISKIO_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/diskio.h>
  #else /* __PPC__ */
   #include <ppcinline/diskio.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/diskio_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/diskio_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_DISKIO_H */
