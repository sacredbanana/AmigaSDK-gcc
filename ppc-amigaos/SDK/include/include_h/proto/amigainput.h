#ifndef PROTO_AMIGAINPUT_H
#define PROTO_AMIGAINPUT_H

/*
**	$VER: amigainput.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef AMIGAINPUT_AMIGAINPUT_H
#include <amigainput/amigainput.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * AIN_Base;
 #else
  extern struct Library * AIN_Base;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/amigainput.h>
 #ifdef __USE_INLINE__
  #include <inline4/amigainput.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_AMIGAINPUT_PROTOS_H
  #define CLIB_AMIGAINPUT_PROTOS_H 1
 #endif /* CLIB_AMIGAINPUT_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::AIN_IFace * IAIN;
  #else
   extern struct AIN_IFace * IAIN;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_AMIGAINPUT_PROTOS_H
  #include <clib/amigainput_protos.h>
 #endif /* CLIB_AMIGAINPUT_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/amigainput.h>
  #else /* __PPC__ */
   #include <ppcinline/amigainput.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/amigainput_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/amigainput_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_AMIGAINPUT_H */
