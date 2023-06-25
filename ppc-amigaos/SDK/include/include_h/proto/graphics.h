#ifndef PROTO_GRAPHICS_H
#define PROTO_GRAPHICS_H

/*
**	$VER: graphics.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef GRAPHICS_BLITATTR_H
#include <graphics/blitattr.h>
#endif
#ifndef GRAPHICS_BOARD_H
#include <graphics/board.h>
#endif
#ifndef GRAPHICS_CLIP_H
#include <graphics/clip.h>
#endif
#ifndef GRAPHICS_COERCE_H
#include <graphics/coerce.h>
#endif
#ifndef GRAPHICS_COLLIDE_H
#include <graphics/collide.h>
#endif
#ifndef GRAPHICS_COMPOSITE_H
#include <graphics/composite.h>
#endif
#ifndef GRAPHICS_COPPER_H
#include <graphics/copper.h>
#endif
#ifndef GRAPHICS_DISPLAY_H
#include <graphics/display.h>
#endif
#ifndef GRAPHICS_DISPLAYINFO_H
#include <graphics/displayinfo.h>
#endif
#ifndef GRAPHICS_GELS_H
#include <graphics/gels.h>
#endif
#ifndef GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif
#ifndef GRAPHICS_GFXBASE_H
#include <graphics/gfxbase.h>
#endif
#ifndef GRAPHICS_GFXMACROS_H
#include <graphics/gfxmacros.h>
#endif
#ifndef GRAPHICS_GFXNODES_H
#include <graphics/gfxnodes.h>
#endif
#ifndef GRAPHICS_GRAPHINT_H
#include <graphics/graphint.h>
#endif
#ifndef GRAPHICS_LAYERS_H
#include <graphics/layers.h>
#endif
#ifndef GRAPHICS_MINTERM_H
#include <graphics/minterm.h>
#endif
#ifndef GRAPHICS_MODEID_H
#include <graphics/modeid.h>
#endif
#ifndef GRAPHICS_MONITOR_H
#include <graphics/monitor.h>
#endif
#ifndef GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif
#ifndef GRAPHICS_REGIONS_H
#include <graphics/regions.h>
#endif
#ifndef GRAPHICS_RPATTR_H
#include <graphics/rpattr.h>
#endif
#ifndef GRAPHICS_SCALE_H
#include <graphics/scale.h>
#endif
#ifndef GRAPHICS_SPRITE_H
#include <graphics/sprite.h>
#endif
#ifndef GRAPHICS_SPRITE_H
#include <graphics/sprite.h>
#endif
#ifndef GRAPHICS_TEXT_H
#include <graphics/text.h>
#endif
#ifndef GRAPHICS_VIDEOCONTROL_H
#include <graphics/videocontrol.h>
#endif
#ifndef GRAPHICS_VIEW_H
#include <graphics/view.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * GfxBase;
  #else
   extern struct Library * GfxBase;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::GfxBase * GfxBase;
  #else
   extern struct GfxBase * GfxBase;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/graphics.h>
 #ifdef __USE_INLINE__
  #include <inline4/graphics.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_GRAPHICS_PROTOS_H
  #define CLIB_GRAPHICS_PROTOS_H 1
 #endif /* CLIB_GRAPHICS_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::GraphicsIFace * IGraphics;
  #else
   extern struct GraphicsIFace * IGraphics;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_GRAPHICS_PROTOS_H
  #include <clib/graphics_protos.h>
 #endif /* CLIB_GRAPHICS_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/graphics.h>
  #else /* __PPC__ */
   #include <ppcinline/graphics.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/graphics_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/graphics_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_GRAPHICS_H */
