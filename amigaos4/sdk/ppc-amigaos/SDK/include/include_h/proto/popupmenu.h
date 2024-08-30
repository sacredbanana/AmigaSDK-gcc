#ifndef PROTO_POPUPMENU_H
#define PROTO_POPUPMENU_H

/*
**	$VER: popupmenu.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef CLASSES_POPUPMENU_H
#include <classes/popupmenu.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * PopupMenuBase;
 #else
  extern struct Library * PopupMenuBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * PopupMenuClass;
  #else
   extern Class * PopupMenuClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/popupmenu.h>
 #ifdef __USE_INLINE__
  #include <inline4/popupmenu.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_POPUPMENU_PROTOS_H
  #define CLIB_POPUPMENU_PROTOS_H 1
 #endif /* CLIB_POPUPMENU_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::PopupMenuIFace * IPopupMenu;
  #else
   extern struct PopupMenuIFace * IPopupMenu;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_POPUPMENU_PROTOS_H
  #include <clib/popupmenu_protos.h>
 #endif /* CLIB_POPUPMENU_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/popupmenu.h>
  #else /* __PPC__ */
   #include <ppcinline/popupmenu.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/popupmenu_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/popupmenu_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_POPUPMENU_H */
