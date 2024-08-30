#ifndef PROTO_FILESYSBOX_H
#define PROTO_FILESYSBOX_H

/*
**	$VER: filesysbox.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_FILESYSBOX_H
#include <libraries/filesysbox.h>
#endif
#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * FileSysBoxBase;
  #else
   extern struct Library * FileSysBoxBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * FileSysBoxBase;
  #else
   extern struct Library * FileSysBoxBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/filesysbox.h>
 #ifdef __USE_INLINE__
  #include <inline4/filesysbox.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_FILESYSBOX_PROTOS_H
  #define CLIB_FILESYSBOX_PROTOS_H 1
 #endif /* CLIB_FILESYSBOX_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::FileSysBoxIFace * IFileSysBox;
  #else
   extern struct FileSysBoxIFace * IFileSysBox;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_FILESYSBOX_PROTOS_H
  #include <clib/filesysbox_protos.h>
 #endif /* CLIB_FILESYSBOX_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/filesysbox.h>
  #else /* __PPC__ */
   #include <ppcinline/filesysbox.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/filesysbox_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/filesysbox_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_FILESYSBOX_H */
