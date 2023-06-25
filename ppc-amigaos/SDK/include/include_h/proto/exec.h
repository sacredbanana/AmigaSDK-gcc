#ifndef PROTO_EXEC_H
#define PROTO_EXEC_H

/*
**	$VER: exec.h 53.29 (10.8.2015)
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
  extern struct Library * SysBase;
 #else
  extern struct ExecBase * SysBase;
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/exec.h>
 #ifdef __USE_INLINE__
  #include <inline4/exec.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_EXEC_PROTOS_H
  #define CLIB_EXEC_PROTOS_H 1
 #endif /* CLIB_EXEC_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  extern struct ExecIFace *IExec;
  extern struct MMUIFace *IMMU;
  extern struct DebugIFace *IDebug;
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_EXEC_PROTOS_H
  #include <clib/exec_protos.h>
 #endif /* CLIB_EXEC_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/exec.h>
  #else /* __PPC__ */
   #include <ppcinline/exec.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/exec_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/exec_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_EXEC_H */
