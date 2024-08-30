#ifndef PROTO_CLICKTAB_H
#define PROTO_CLICKTAB_H

/*
**	$VER: clicktab.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * ClickTabBase;
 #else
  extern struct Library * ClickTabBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * ClickTabClass;
  #else
   extern Class * ClickTabClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/clicktab.h>
 #ifdef __USE_INLINE__
  #include <inline4/clicktab.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_CLICKTAB_PROTOS_H
  #define CLIB_CLICKTAB_PROTOS_H 1
 #endif /* CLIB_CLICKTAB_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ClickTabIFace * IClickTab;
  #else
   extern struct ClickTabIFace * IClickTab;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_CLICKTAB_PROTOS_H
  #include <clib/clicktab_protos.h>
 #endif /* CLIB_CLICKTAB_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/clicktab.h>
  #else /* __PPC__ */
   #include <ppcinline/clicktab.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/clicktab_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/clicktab_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_CLICKTAB_H */
