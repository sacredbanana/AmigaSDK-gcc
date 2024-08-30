#ifndef PROTO_TRANSLATOR_H
#define PROTO_TRANSLATOR_H

/*
**	$Id$
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/


/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * TranslatorBase;
 #else
  extern struct Library * TranslatorBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/translator.h>
 #ifdef __USE_INLINE__
  #include <inline4/translator.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_TRANSLATOR_PROTOS_H
  #define CLIB_TRANSLATOR_PROTOS_H 1
 #endif /* CLIB_TRANSLATOR_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_TRANSLATOR_PROTOS_H
  #include <clib/translator_protos.h>
 #endif /* CLIB_TRANSLATOR_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/translator.h>
  #else /* __PPC__ */
   #include <ppcinline/translator.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/translator_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/translator_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_TRANSLATOR_H */
