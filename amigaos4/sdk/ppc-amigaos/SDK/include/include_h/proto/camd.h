#ifndef PROTO_CAMD_H
#define PROTO_CAMD_H

/*
**	$VER: camd.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/


/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * CamdBase;
 #else
  extern struct Library * CamdBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/camd.h>
 #ifdef __USE_INLINE__
  #include <inline4/camd.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_CAMD_PROTOS_H
  #define CLIB_CAMD_PROTOS_H 1
 #endif /* CLIB_CAMD_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CamdIFace * ICamd;
  #else
   extern struct CamdIFace * ICamd;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_CAMD_PROTOS_H
  #include <clib/camd_protos.h>
 #endif /* CLIB_CAMD_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/camd.h>
  #else /* __PPC__ */
   #include <ppcinline/camd.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/camd_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/camd_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_CAMD_H */
