#ifndef PROTO_WARP3D_H
#define PROTO_WARP3D_H

/*
**	$VER: warp3d.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef WARP3D_WARP3D_H
#include <Warp3D/Warp3D.h>
#endif
#ifndef GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * Warp3DBase;
 #else
  extern struct Library * Warp3DBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/warp3d.h>
 #ifdef __USE_INLINE__
  #include <inline4/warp3d.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_WARP3D_PROTOS_H
  #define CLIB_WARP3D_PROTOS_H 1
 #endif /* CLIB_WARP3D_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Warp3DIFace * IWarp3D;
  #else
   extern struct Warp3DIFace * IWarp3D;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_WARP3D_PROTOS_H
  #include <clib/warp3d_protos.h>
 #endif /* CLIB_WARP3D_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/warp3d.h>
  #else /* __PPC__ */
   #include <ppcinline/warp3d.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/warp3d_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/warp3d_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_WARP3D_H */
