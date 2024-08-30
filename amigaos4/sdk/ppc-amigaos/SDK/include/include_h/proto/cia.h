#ifndef PROTO_CIA_H
#define PROTO_CIA_H

/*
**	$VER: cia.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
/* There is no library base for CIA */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/cia.h>
 #ifdef __USE_INLINE__
  #include <inline4/cia.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_CIA_PROTOS_H
  #define CLIB_CIA_PROTOS_H 1
 #endif /* CLIB_CIA_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CIAIFace * ICIA;
  #else
   extern struct CIAIFace * ICIA;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_CIA_PROTOS_H
  #include <clib/cia_protos.h>
 #endif /* CLIB_CIA_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/cia.h>
  #else /* __PPC__ */
   #include <ppcinline/cia.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/cia_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/cia_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_CIA_H */
