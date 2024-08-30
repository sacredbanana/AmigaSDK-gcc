#ifndef PROTO_LISTBROWSER_H
#define PROTO_LISTBROWSER_H

/*
**	$VER: listbrowser.h 54.16 (22.08.2022)
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
#ifndef GADGETS_LISTBROWSER_H
#include <gadgets/listbrowser.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * ListBrowserBase;
 #else
  extern struct Library * ListBrowserBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <intuition/classes.h>
 #ifndef __NOGLOBALCLASS__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern AmigaOS::Class * ListBrowserClass;
  #else
   extern Class * ListBrowserClass;
  #endif
 #endif /* __NOGLOBALCLASS__ */

 #include <interfaces/listbrowser.h>
 #ifdef __USE_INLINE__
  #include <inline4/listbrowser.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_LISTBROWSER_PROTOS_H
  #define CLIB_LISTBROWSER_PROTOS_H 1
 #endif /* CLIB_LISTBROWSER_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ListBrowserIFace * IListBrowser;
  #else
   extern struct ListBrowserIFace * IListBrowser;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_LISTBROWSER_PROTOS_H
  #include <clib/listbrowser_protos.h>
 #endif /* CLIB_LISTBROWSER_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/listbrowser.h>
  #else /* __PPC__ */
   #include <ppcinline/listbrowser.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/listbrowser_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/listbrowser_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_LISTBROWSER_H */
