#ifndef CLIB_LAYERS_PROTOS_H
#define CLIB_LAYERS_PROTOS_H

/*
**	$VER: layers_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  GRAPHICS_LAYERS_H
#include <graphics/layers.h>
#endif
#ifndef  GRAPHICS_CLIP_H
#include <graphics/clip.h>
#endif
#ifndef  GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif
#ifndef  GRAPHICS_REGIONS_H
#include <graphics/regions.h>
#endif
VOID    __stdargs InitLayers( struct Layer_Info *li );
struct Layer *   __stdargs CreateUpfrontLayer( struct Layer_Info *li, struct BitMap *bm, LONG x0, LONG y0, LONG x1, LONG y1, LONG flags, struct BitMap *bm2 );
struct Layer *   __stdargs CreateBehindLayer( struct Layer_Info *li, struct BitMap *bm, LONG x0, LONG y0, LONG x1, LONG y1, LONG flags, struct BitMap *bm2 );
LONG    __stdargs UpfrontLayer( LONG dummy, struct Layer *layer );
LONG    __stdargs BehindLayer( LONG dummy, struct Layer *layer );
LONG    __stdargs MoveLayer( LONG dummy, struct Layer *layer, LONG dx, LONG dy );
LONG    __stdargs SizeLayer( LONG dummy, struct Layer *layer, LONG dx, LONG dy );
VOID    __stdargs ScrollLayer( LONG dummy, struct Layer *layer, LONG dx, LONG dy );
LONG    __stdargs BeginUpdate( struct Layer *l );
VOID    __stdargs EndUpdate( struct Layer *layer, ULONG flag );
LONG    __stdargs DeleteLayer( LONG dummy, struct Layer *layer );
VOID    __stdargs LockLayer( LONG dummy, struct Layer *layer );
VOID    __stdargs UnlockLayer( struct Layer *layer );
VOID    __stdargs LockLayers( struct Layer_Info *li );
VOID    __stdargs UnlockLayers( struct Layer_Info *li );
VOID    __stdargs LockLayerInfo( struct Layer_Info *li );
VOID    __stdargs SwapBitsRastPortClipRect( struct RastPort *rp, struct ClipRect *cr );
struct Layer *   __stdargs WhichLayer( struct Layer_Info *li, LONG x, LONG y );
VOID    __stdargs UnlockLayerInfo( struct Layer_Info *li );
struct Layer_Info *   __stdargs NewLayerInfo( VOID );
VOID    __stdargs DisposeLayerInfo( struct Layer_Info *li );
LONG    __stdargs FattenLayerInfo( struct Layer_Info *li );
VOID    __stdargs ThinLayerInfo( struct Layer_Info *li );
LONG    __stdargs MoveLayerInFrontOf( struct Layer *layer_to_move, struct Layer *other_layer );
struct Region *   __stdargs InstallClipRegion( struct Layer *layer, struct Region *region );
LONG    __stdargs MoveSizeLayer( struct Layer *layer, LONG dx, LONG dy, LONG dw, LONG dh );
struct Layer *   __stdargs CreateUpfrontHookLayer( struct Layer_Info *li, struct BitMap *bm, LONG x0, LONG y0, LONG x1, LONG y1, LONG flags, struct Hook *hook, struct BitMap *bm2 );
struct Layer *   __stdargs CreateBehindHookLayer( struct Layer_Info *li, struct BitMap *bm, LONG x0, LONG y0, LONG x1, LONG y1, LONG flags, struct Hook *hook, struct BitMap *bm2 );
struct Hook *   __stdargs InstallLayerHook( struct Layer *layer, struct Hook *hook );
/*--- functions in V39 or higher (Release 3.0) ---*/
struct Hook *   __stdargs InstallLayerInfoHook( struct Layer_Info *li, struct Hook *hook );
VOID    __stdargs SortLayerCR( struct Layer *layer, LONG dx, LONG dy );
VOID    __stdargs DoHookClipRects( struct Hook *hook, struct RastPort *rport, CONST struct Rectangle *rect );
/*--- functions in V45 or higher (Release 3.9) ---*/
BOOL    __stdargs LayerOccluded( struct Layer *layer );
LONG    __stdargs HideLayer( struct Layer *layer );
LONG    __stdargs ShowLayer( struct Layer *layer, struct Layer *in_front_of );
BOOL    __stdargs SetLayerInfoBounds( struct Layer_Info *li, CONST struct Rectangle *bounds );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_LAYERS_PROTOS_H */
