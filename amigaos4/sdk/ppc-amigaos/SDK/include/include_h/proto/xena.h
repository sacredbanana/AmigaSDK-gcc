#ifndef PROTO_XENA_H
#define PROTO_XENA_H

/*
**	$VER: xena.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/


/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * XenaBase;
 #else
  extern struct Library * XenaBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/xena.h>
 #ifdef __USE_INLINE__
  #include <inline4/xena.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_XENA_PROTOS_H
  #define CLIB_XENA_PROTOS_H 1
 #endif /* CLIB_XENA_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::XenaIFace * IXena;
  #else
   extern struct XenaIFace * IXena;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_XENA_PROTOS_H
  #include <clib/xena_protos.h>
 #endif /* CLIB_XENA_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/xena.h>
  #else /* __PPC__ */
   #include <ppcinline/xena.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/xena_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/xena_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_XENA_H */
