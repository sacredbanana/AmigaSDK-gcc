#ifndef CLIB_LAYERS_PROTOS_H
#define CLIB_LAYERS_PROTOS_H


/*
**    $Id: layers_protos.h,v 1.13 2010-01-31 01:29:02 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**    All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef   GRAPHICS_LAYERS_H
#include <graphics/layers.h>
#endif
#ifndef   GRAPHICS_CLIP_H
#include <graphics/clip.h>
#endif
#ifndef   GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif
#ifndef   GRAPHICS_REGIONS_H
#include <graphics/regions.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

VOID InitLayers(struct Layer_Info * li);
struct Layer * CreateUpfrontLayer(struct Layer_Info * li, struct BitMap * bm, LONG x0, LONG y0,
    LONG x1, LONG y1, LONG flags, struct BitMap * bm2);
struct Layer * CreateBehindLayer(struct Layer_Info * li, struct BitMap * bm, LONG x0, LONG y0,
    LONG x1, LONG y1, LONG flags, struct BitMap * bm2);
LONG UpfrontLayer(LONG dummy, struct Layer * layer);
LONG BehindLayer(LONG dummy, struct Layer * layer);
LONG MoveLayer(LONG dummy, struct Layer * layer, LONG dx, LONG dy);
LONG SizeLayer(LONG dummy, struct Layer * layer, LONG dx, LONG dy);
VOID ScrollLayer(LONG dummy, struct Layer * layer, LONG dx, LONG dy);
LONG BeginUpdate(struct Layer * l);
VOID EndUpdate(struct Layer * layer, ULONG flag);
LONG DeleteLayer(LONG dummy, struct Layer * layer);
VOID LockLayer(LONG dummy, struct Layer * layer);
VOID UnlockLayer(struct Layer * layer);
VOID LockLayers(struct Layer_Info * li);
BOOL UnlockLayers(struct Layer_Info * li);
VOID LockLayerInfo(struct Layer_Info * li);
VOID SwapBitsRastPortClipRect(struct RastPort * rp, struct ClipRect * cr);
struct Layer * WhichLayer(struct Layer_Info * li, LONG x, LONG y);
VOID UnlockLayerInfo(struct Layer_Info * li);
struct Layer_Info * NewLayerInfo(void);
VOID DisposeLayerInfo(struct Layer_Info * li);
LONG FattenLayerInfo(struct Layer_Info * li);
VOID ThinLayerInfo(struct Layer_Info * li);
LONG MoveLayerInFrontOf(struct Layer * layer_to_move, struct Layer * other_layer);
struct Region * InstallClipRegion(struct Layer * layer, CONST struct Region * region);
LONG MoveSizeLayer(struct Layer * layer, LONG dx, LONG dy, LONG dw, LONG dh);
struct Layer * CreateUpfrontHookLayer(struct Layer_Info * li, struct BitMap * bm, LONG x0, LONG y0,
    LONG x1, LONG y1, LONG flags, struct Hook * hook,
    struct BitMap * bm2);
struct Layer * CreateBehindHookLayer(struct Layer_Info * li, struct BitMap * bm, LONG x0, LONG y0,
    LONG x1, LONG y1, LONG flags, struct Hook * hook,
    struct BitMap * bm2);
struct Hook * InstallLayerHook(struct Layer * layer, struct Hook * hook);
struct Hook * InstallLayerInfoHook(struct Layer_Info * li, CONST struct Hook * hook);
VOID SortLayerCR(struct Layer * layer, LONG dx, LONG dy);
VOID DoHookClipRects(CONST struct Hook * hook, struct RastPort * rport,
    CONST struct Rectangle * rect);
LONG LayerOccluded(struct Layer * layer);
LONG HideLayer(struct Layer * layer);
LONG ShowLayer(struct Layer * layer, struct Layer * infront_of);
LONG SetLayerInfoBounds(struct Layer_Info * li, struct Rectangle * bounds);
struct Hook * CreateBackFillHookA(struct TagItem * tags);
struct Hook * CreateBackFillHook(ULONG tags, ...);
VOID DeleteBackFillHook(struct Hook * hook);
ULONG SetBackFillHookAttrsA(struct Hook * hook, struct TagItem * tags);
ULONG SetBackFillHookAttrs(struct Hook * hook, ULONG tags, ...);
ULONG GetBackFillHookAttrsA(struct Hook * hook, struct TagItem * tags);
ULONG GetBackFillHookAttrs(struct Hook * hook, ULONG tags, ...);
struct Layer * CreateLayerA(struct Layer_Info * li, struct TagItem * tags);
struct Layer * CreateLayer(struct Layer_Info * li, ULONG tags, ...);
struct Region * ChangeLayerShape(struct Layer *layer, struct Region *region, struct Hook *hook);

#endif /*  CLIB_LAYERS_PROTOS_H  */
