#ifndef PROTO_REXXSYSLIB_H
#define PROTO_REXXSYSLIB_H

/*
**	$VER: rexxsyslib.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef REXX_RXSLIB_H
#include <rexx/rxslib.h>
#endif
#ifndef REXX_REXXIO_H
#include <rexx/rexxio.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * RexxSysBase;
 #else
  extern struct Library * RexxSysBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/rexxsyslib.h>
 #ifdef __USE_INLINE__
  #include <inline4/rexxsyslib.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_REXXSYSLIB_PROTOS_H
  #define CLIB_REXXSYSLIB_PROTOS_H 1
 #endif /* CLIB_REXXSYSLIB_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::RexxSysIFace * IRexxSys;
  #else
   extern struct RexxSysIFace * IRexxSys;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_REXXSYSLIB_PROTOS_H
  #include <clib/rexxsyslib_protos.h>
 #endif /* CLIB_REXXSYSLIB_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/rexxsyslib.h>
  #else /* __PPC__ */
   #include <ppcinline/rexxsyslib.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/rexxsyslib_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/rexxsyslib_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_REXXSYSLIB_H */
