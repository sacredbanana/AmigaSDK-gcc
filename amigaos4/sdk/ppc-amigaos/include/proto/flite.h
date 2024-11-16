#ifndef PROTO_FLITE_H
#define PROTO_FLITE_H

/*
**	$Id$
**	Includes Release 50.1
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef DEVICES_FLITE_H
#include <devices/flite.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Device * FliteBase;
 #else
  extern struct FliteBase * FliteBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/flite.h>
 #ifdef __USE_INLINE__
  #include <inline4/flite.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_FLITE_PROTOS_H
  #define CLIB_FLITE_PROTOS_H 1
 #endif /* CLIB_FLITE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct FliteIFace *IFlite;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_FLITE_PROTOS_H
  #include <clib/flite_protos.h>
 #endif /* CLIB_FLITE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/flite.h>
  #else
   #include <ppcinline/flite.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/flite_protos.h>
  #endif /* __PPC__ */
 #else
  #include <pragmas/flite_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_FLITE_H */
