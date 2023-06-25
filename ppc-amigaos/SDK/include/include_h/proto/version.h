#ifndef PROTO_VERSION_H
#define PROTO_VERSION_H

/*
**	$VER: version.h 54.16 (22.08.2022)
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

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * VersionBase;
 #else
  extern struct Library * VersionBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/version.h>
 #ifdef __USE_INLINE__
  #include <inline4/version.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_VERSION_PROTOS_H
  #define CLIB_VERSION_PROTOS_H 1
 #endif /* CLIB_VERSION_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::VersionIFace * IVersion;
  #else
   extern struct VersionIFace * IVersion;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_VERSION_PROTOS_H
  #include <clib/version_protos.h>
 #endif /* CLIB_VERSION_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/version.h>
  #else /* __PPC__ */
   #include <ppcinline/version.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/version_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/version_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_VERSION_H */
