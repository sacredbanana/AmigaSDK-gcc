#ifndef PROTO_UTILITY_H
#define PROTO_UTILITY_H

/*
**	$VER: utility.h 53.29 (10.8.2015)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef UTILITY_UTILITY_H
#include <utility/utility.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * UtilityBase;
 #else
  extern struct UtilityBase * UtilityBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/utility.h>
 #ifdef __USE_INLINE__
  #include <inline4/utility.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_UTILITY_PROTOS_H
  #define CLIB_UTILITY_PROTOS_H 1
 #endif /* CLIB_UTILITY_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct UtilityIFace *IUtility;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_UTILITY_PROTOS_H
  #include <clib/utility_protos.h>
 #endif /* CLIB_UTILITY_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/utility.h>
  #else /* __PPC__ */
   #include <ppcinline/utility.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/utility_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/utility_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_UTILITY_H */
