#ifndef PROTO_DOS_H
#define PROTO_DOS_H

/*
**	$Id$
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef DOS_DOSEXTENS_H
#include <dos/dosextens.h>
#endif
#ifndef DOS_RECORD_H
#include <dos/record.h>
#endif
#ifndef DOS_RDARGS_H
#include <dos/rdargs.h>
#endif
#ifndef DOS_DOSASL_H
#include <dos/dosasl.h>
#endif
#ifndef DOS_VAR_H
#include <dos/var.h>
#endif
#ifndef DOS_NOTIFY_H
#include <dos/notify.h>
#endif
#ifndef DOS_DATETIME_H
#include <dos/datetime.h>
#endif
#ifndef DOS_EXALL_H
#include <dos/exall.h>
#endif
#ifndef DOS_FILEHANDLER_H
#include <dos/filehandler.h>
#endif
#ifndef DOS_DOSTAGS_H
#include <dos/dostags.h>
#endif
#ifndef DOS_MOUNT_H
#include <dos/mount.h>
#endif
#ifndef DOS_DOSHUNKS_H
#include <dos/doshunks.h>
#endif
#ifndef DOS_PATH_H
#include <dos/path.h>
#endif
#ifndef DOS_ANCHORPATH_H
#include <dos/anchorpath.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * DOSBase;
  #else
   extern struct Library * DOSBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::DosLibrary * DOSBase;
  #else
   extern struct DosLibrary * DOSBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/dos.h>
 #ifdef __USE_INLINE__
  #include <inline4/dos.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_DOS_PROTOS_H
  #define CLIB_DOS_PROTOS_H 1
 #endif /* CLIB_DOS_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::DOSIFace * IDOS;
  #else
   extern struct DOSIFace * IDOS;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_DOS_PROTOS_H
  #include <clib/dos_protos.h>
 #endif /* CLIB_DOS_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/dos.h>
  #else /* __PPC__ */
   #include <ppcinline/dos.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/dos_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/dos_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_DOS_H */
