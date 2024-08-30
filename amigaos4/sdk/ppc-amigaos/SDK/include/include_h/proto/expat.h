#ifndef PROTO_EXPAT_H
#define PROTO_EXPAT_H

/*
**	$Id$
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef LIBRARIES_EXPAT_H
#include <libraries/expat.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * ExpatBase;
  #else
   extern struct Library * ExpatBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * ExpatBase;
  #else
   extern struct Library * ExpatBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/expat.h>
 #ifdef __USE_INLINE__
  #include <inline4/expat.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_EXPAT_PROTOS_H
  #define CLIB_EXPAT_PROTOS_H 1
 #endif /* CLIB_EXPAT_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ExpatIFace * IExpat;
  #else
   extern struct ExpatIFace * IExpat;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_EXPAT_PROTOS_H
  #include <clib/expat_protos.h>
 #endif /* CLIB_EXPAT_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/expat.h>
  #else /* __PPC__ */
   #include <ppcinline/expat.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/expat_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/expat_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_EXPAT_H */
