#ifndef PROTO_INPUT_H
#define PROTO_INPUT_H

/*
**	$VER: input.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Device * InputBase;
 #else
  extern struct Device * InputBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/input.h>
 #ifdef __USE_INLINE__
  #include <inline4/input.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_INPUT_PROTOS_H
  #define CLIB_INPUT_PROTOS_H 1
 #endif /* CLIB_INPUT_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::InputIFace * IInput;
  #else
   extern struct InputIFace * IInput;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_INPUT_PROTOS_H
  #include <clib/input_protos.h>
 #endif /* CLIB_INPUT_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/input.h>
  #else /* __PPC__ */
   #include <ppcinline/input.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/input_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/input_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_INPUT_H */
