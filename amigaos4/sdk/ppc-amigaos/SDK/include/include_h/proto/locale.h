#ifndef PROTO_LOCALE_H
#define PROTO_LOCALE_H

/*
**	$VER: locale.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef LIBRARIES_LOCALE_H
#include <libraries/locale.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef REXX_STORAGE_H
#include <rexx/storage.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * LocaleBase;
 #else
  extern struct Library * LocaleBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/locale.h>
 #ifdef __USE_INLINE__
  #include <inline4/locale.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_LOCALE_PROTOS_H
  #define CLIB_LOCALE_PROTOS_H 1
 #endif /* CLIB_LOCALE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::LocaleIFace * ILocale;
  #else
   extern struct LocaleIFace * ILocale;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_LOCALE_PROTOS_H
  #include <clib/locale_protos.h>
 #endif /* CLIB_LOCALE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/locale.h>
  #else /* __PPC__ */
   #include <ppcinline/locale.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/locale_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/locale_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_LOCALE_H */
