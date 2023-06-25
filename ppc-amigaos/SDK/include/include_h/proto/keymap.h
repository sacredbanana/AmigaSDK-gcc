#ifndef PROTO_KEYMAP_H
#define PROTO_KEYMAP_H

/*
**	$VER: keymap.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef LIBRARIES_KEYMAP_H
#include <libraries/keymap.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * KeymapBase;
 #else
  extern struct Library * KeymapBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/keymap.h>
 #ifdef __USE_INLINE__
  #include <inline4/keymap.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_KEYMAP_PROTOS_H
  #define CLIB_KEYMAP_PROTOS_H 1
 #endif /* CLIB_KEYMAP_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::KeymapIFace * IKeymap;
  #else
   extern struct KeymapIFace * IKeymap;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_KEYMAP_PROTOS_H
  #include <clib/keymap_protos.h>
 #endif /* CLIB_KEYMAP_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/keymap.h>
  #else /* __PPC__ */
   #include <ppcinline/keymap.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/keymap_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/keymap_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_KEYMAP_H */
