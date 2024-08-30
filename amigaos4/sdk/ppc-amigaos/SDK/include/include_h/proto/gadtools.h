#ifndef PROTO_GADTOOLS_H
#define PROTO_GADTOOLS_H

/*
**	$VER: gadtools.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_GADTOOLS_H
#include <libraries/gadtools.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * GadToolsBase;
 #else
  extern struct Library * GadToolsBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/gadtools.h>
 #ifdef __USE_INLINE__
  #include <inline4/gadtools.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_GADTOOLS_PROTOS_H
  #define CLIB_GADTOOLS_PROTOS_H 1
 #endif /* CLIB_GADTOOLS_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::GadToolsIFace * IGadTools;
  #else
   extern struct GadToolsIFace * IGadTools;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_GADTOOLS_PROTOS_H
  #include <clib/gadtools_protos.h>
 #endif /* CLIB_GADTOOLS_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/gadtools.h>
  #else /* __PPC__ */
   #include <ppcinline/gadtools.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/gadtools_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/gadtools_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_GADTOOLS_H */
