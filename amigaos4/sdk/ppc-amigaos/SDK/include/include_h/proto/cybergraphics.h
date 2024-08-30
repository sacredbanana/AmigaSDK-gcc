#ifndef PROTO_CYBERGRAPHICS_H
#define PROTO_CYBERGRAPHICS_H

/*
**	$VER: cybergraphics.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif
#ifndef GRAPHICS_VIEW_H
#include <graphics/view.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * CyberGfxBase;
 #else
  extern struct Library * CyberGfxBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/cybergraphics.h>
 #ifdef __USE_INLINE__
  #include <inline4/cybergraphics.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_CYBERGRAPHICS_PROTOS_H
  #define CLIB_CYBERGRAPHICS_PROTOS_H 1
 #endif /* CLIB_CYBERGRAPHICS_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::CyberGfxIFace * ICyberGfx;
  #else
   extern struct CyberGfxIFace * ICyberGfx;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_CYBERGRAPHICS_PROTOS_H
  #include <clib/cybergraphics_protos.h>
 #endif /* CLIB_CYBERGRAPHICS_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/cybergraphics.h>
  #else /* __PPC__ */
   #include <ppcinline/cybergraphics.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/cybergraphics_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/cybergraphics_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_CYBERGRAPHICS_H */
