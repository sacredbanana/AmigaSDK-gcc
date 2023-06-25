#ifndef PROTO_APPLICATION_H
#define PROTO_APPLICATION_H

/*
**	$VER: application.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef LIBRARIES_APPLICATION_H
#include <libraries/application.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * ApplicationBase;
 #else
  extern struct Library * ApplicationBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/application.h>
 #ifdef __USE_INLINE__
  #include <inline4/application.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_APPLICATION_PROTOS_H
  #define CLIB_APPLICATION_PROTOS_H 1
 #endif /* CLIB_APPLICATION_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ApplicationIFace * IApplication;
  #else
   extern struct ApplicationIFace * IApplication;
  #endif
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::PrefsObjectsIFace * IPrefsObjects;
  #else
   extern struct PrefsObjectsIFace * IPrefsObjects;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_APPLICATION_PROTOS_H
  #include <clib/application_protos.h>
 #endif /* CLIB_APPLICATION_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/application.h>
  #else /* __PPC__ */
   #include <ppcinline/application.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/application_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/application_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_APPLICATION_H */
