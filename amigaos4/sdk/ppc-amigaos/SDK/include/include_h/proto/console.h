#ifndef PROTO_CONSOLE_H
#define PROTO_CONSOLE_H

/*
**	$VER: console.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef DEVICES_KEYMAP_H
#include <devices/keymap.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Device * ConsoleDevice;
 #else
  extern struct Device * ConsoleDevice;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/console.h>
 #ifdef __USE_INLINE__
  #include <inline4/console.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_CONSOLE_PROTOS_H
  #define CLIB_CONSOLE_PROTOS_H 1
 #endif /* CLIB_CONSOLE_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::ConsoleIFace * IConsole;
  #else
   extern struct ConsoleIFace * IConsole;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_CONSOLE_PROTOS_H
  #include <clib/console_protos.h>
 #endif /* CLIB_CONSOLE_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/console.h>
  #else /* __PPC__ */
   #include <ppcinline/console.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/console_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/console_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_CONSOLE_H */
