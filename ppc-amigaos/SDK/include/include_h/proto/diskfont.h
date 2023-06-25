#ifndef PROTO_DISKFONT_H
#define PROTO_DISKFONT_H

/*
**	$VER: diskfont.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef LIBRARIES_DISKFONT_H
#include <libraries/diskfont.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * DiskfontBase;
 #else
  extern struct Library * DiskfontBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/diskfont.h>
 #ifdef __USE_INLINE__
  #include <inline4/diskfont.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_DISKFONT_PROTOS_H
  #define CLIB_DISKFONT_PROTOS_H 1
 #endif /* CLIB_DISKFONT_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::DiskfontIFace * IDiskfont;
  #else
   extern struct DiskfontIFace * IDiskfont;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_DISKFONT_PROTOS_H
  #include <clib/diskfont_protos.h>
 #endif /* CLIB_DISKFONT_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/diskfont.h>
  #else /* __PPC__ */
   #include <ppcinline/diskfont.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/diskfont_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/diskfont_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_DISKFONT_H */
