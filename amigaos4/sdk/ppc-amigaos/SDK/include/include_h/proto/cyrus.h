#ifndef PROTO_CYRUS_H
#define PROTO_CYRUS_H

/*
**	$VER: cyrus.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/


/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  extern struct Library * CyrusBase;
 #else
  extern struct Library * CyrusBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/cyrus.h>
 #ifdef __USE_INLINE__
  #include <inline4/cyrus.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_CYRUS_PROTOS_H
  #define CLIB_CYRUS_PROTOS_H 1
 #endif /* CLIB_CYRUS_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_CYRUS_PROTOS_H
  #include <clib/cyrus_protos.h>
 #endif /* CLIB_CYRUS_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/cyrus.h>
  #else /* __PPC__ */
   #include <ppcinline/cyrus.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/cyrus_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/cyrus_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_CYRUS_H */
