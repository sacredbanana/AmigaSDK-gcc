#ifndef PROTO_AMIGAGUIDE_H
#define PROTO_AMIGAGUIDE_H

/*
**	$VER: amigaguide.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef LIBRARIES_AMIGAGUIDE_H
#include <libraries/amigaguide.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef REXX_STORAGE_H
#include <rexx/storage.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * AmigaGuideBase;
 #else
  extern struct Library * AmigaGuideBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/amigaguide.h>
 #ifdef __USE_INLINE__
  #include <inline4/amigaguide.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_AMIGAGUIDE_PROTOS_H
  #define CLIB_AMIGAGUIDE_PROTOS_H 1
 #endif /* CLIB_AMIGAGUIDE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::AmigaGuideIFace * IAmigaGuide;
  #else
   extern struct AmigaGuideIFace * IAmigaGuide;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_AMIGAGUIDE_PROTOS_H
  #include <clib/amigaguide_protos.h>
 #endif /* CLIB_AMIGAGUIDE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/amigaguide.h>
  #else /* __PPC__ */
   #include <ppcinline/amigaguide.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/amigaguide_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/amigaguide_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_AMIGAGUIDE_H */
