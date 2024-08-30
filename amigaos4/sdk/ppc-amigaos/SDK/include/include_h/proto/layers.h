#ifndef PROTO_LAYERS_H
#define PROTO_LAYERS_H

/*
**	$VER: layers.h 54.16 (22.08.2022)
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef GRAPHICS_LAYERS_H
#include <graphics/layers.h>
#endif
#ifndef GRAPHICS_CLIP_H
#include <graphics/clip.h>
#endif
#ifndef GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif
#ifndef GRAPHICS_REGIONS_H
#include <graphics/regions.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * LayersBase;
 #else
  extern struct Library * LayersBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/layers.h>
 #ifdef __USE_INLINE__
  #include <inline4/layers.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_LAYERS_PROTOS_H
  #define CLIB_LAYERS_PROTOS_H 1
 #endif /* CLIB_LAYERS_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::LayersIFace * ILayers;
  #else
   extern struct LayersIFace * ILayers;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_LAYERS_PROTOS_H
  #include <clib/layers_protos.h>
 #endif /* CLIB_LAYERS_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/layers.h>
  #else /* __PPC__ */
   #include <ppcinline/layers.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/layers_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/layers_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_LAYERS_H */
