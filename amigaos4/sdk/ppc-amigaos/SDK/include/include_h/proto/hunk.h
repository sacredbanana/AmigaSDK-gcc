#ifndef PROTO_HUNK_H
#define PROTO_HUNK_H

/*
**	$VER: hunk.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef LIBRARIES_HUNK_H
#include <libraries/hunk.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef INTERFACES_HUNK_H
#include <interfaces/hunk.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * HunkBase;
  #else
   extern struct Library * HunkBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::HunkLibrary * HunkBase;
  #else
   extern struct HunkLibrary * HunkBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/hunk.h>
 #ifdef __USE_INLINE__
  #include <inline4/hunk.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_HUNK_PROTOS_H
  #define CLIB_HUNK_PROTOS_H 1
 #endif /* CLIB_HUNK_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::HunkIFace * IHunk;
  #else
   extern struct HunkIFace * IHunk;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_HUNK_PROTOS_H
  #include <clib/hunk_protos.h>
 #endif /* CLIB_HUNK_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/hunk.h>
  #else /* __PPC__ */
   #include <ppcinline/hunk.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/hunk_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/hunk_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_HUNK_H */
