#ifndef PROTO_ICONMODULE_H
#define PROTO_ICONMODULE_H

/*
**	$VER: iconmodule.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef WORKBENCH_ICON_H
#include <workbench/icon.h>
#endif
#ifndef WORKBENCH_ICONMODULE_H
#include <workbench/iconmodule.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * IconModuleBase;
 #else
  extern struct Library * IconModuleBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/iconmodule.h>
 #ifdef __USE_INLINE__
  #include <inline4/iconmodule.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_ICONMODULE_PROTOS_H
  #define CLIB_ICONMODULE_PROTOS_H 1
 #endif /* CLIB_ICONMODULE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::IconModuleIFace * IIconModule;
  #else
   extern struct IconModuleIFace * IIconModule;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_ICONMODULE_PROTOS_H
  #include <clib/iconmodule_protos.h>
 #endif /* CLIB_ICONMODULE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/iconmodule.h>
  #else /* __PPC__ */
   #include <ppcinline/iconmodule.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/iconmodule_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/iconmodule_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_ICONMODULE_H */
