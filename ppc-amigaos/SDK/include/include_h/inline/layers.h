#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_LAYERS_H
#define _INLINE_LAYERS_H

#ifndef CLIB_LAYERS_PROTOS_H
#define CLIB_LAYERS_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
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

#ifndef LAYERS_BASE_NAME
#define LAYERS_BASE_NAME LayersBase
#endif

#define InitLayers(li) ({ \
  struct Layer_Info * _InitLayers_li = (li); \
  ({ \
  register char * _InitLayers__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"))) \
  (_InitLayers__bn - 30))(_InitLayers__bn, _InitLayers_li); \
});})

#define CreateUpfrontLayer(li, bm, x0, y0, x1, y1, flags, bm2) ({ \
  struct Layer_Info * _CreateUpfrontLayer_li = (li); \
  struct BitMap * _CreateUpfrontLayer_bm = (bm); \
  LONG _CreateUpfrontLayer_x0 = (x0); \
  LONG _CreateUpfrontLayer_y0 = (y0); \
  LONG _CreateUpfrontLayer_x1 = (x1); \
  LONG _CreateUpfrontLayer_y1 = (y1); \
  LONG _CreateUpfrontLayer_flags = (flags); \
  struct BitMap * _CreateUpfrontLayer_bm2 = (bm2); \
  ({ \
  register char * _CreateUpfrontLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Layer * (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"), struct BitMap * __asm("a1"), LONG __asm("d0"), LONG __asm("d1"), LONG __asm("d2"), LONG __asm("d3"), LONG __asm("d4"), struct BitMap * __asm("a2"))) \
  (_CreateUpfrontLayer__bn - 36))(_CreateUpfrontLayer__bn, _CreateUpfrontLayer_li, _CreateUpfrontLayer_bm, _CreateUpfrontLayer_x0, _CreateUpfrontLayer_y0, _CreateUpfrontLayer_x1, _CreateUpfrontLayer_y1, _CreateUpfrontLayer_flags, _CreateUpfrontLayer_bm2); \
});})

#define CreateBehindLayer(li, bm, x0, y0, x1, y1, flags, bm2) ({ \
  struct Layer_Info * _CreateBehindLayer_li = (li); \
  struct BitMap * _CreateBehindLayer_bm = (bm); \
  LONG _CreateBehindLayer_x0 = (x0); \
  LONG _CreateBehindLayer_y0 = (y0); \
  LONG _CreateBehindLayer_x1 = (x1); \
  LONG _CreateBehindLayer_y1 = (y1); \
  LONG _CreateBehindLayer_flags = (flags); \
  struct BitMap * _CreateBehindLayer_bm2 = (bm2); \
  ({ \
  register char * _CreateBehindLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Layer * (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"), struct BitMap * __asm("a1"), LONG __asm("d0"), LONG __asm("d1"), LONG __asm("d2"), LONG __asm("d3"), LONG __asm("d4"), struct BitMap * __asm("a2"))) \
  (_CreateBehindLayer__bn - 42))(_CreateBehindLayer__bn, _CreateBehindLayer_li, _CreateBehindLayer_bm, _CreateBehindLayer_x0, _CreateBehindLayer_y0, _CreateBehindLayer_x1, _CreateBehindLayer_y1, _CreateBehindLayer_flags, _CreateBehindLayer_bm2); \
});})

#define UpfrontLayer(dummy, layer) ({ \
  LONG _UpfrontLayer_dummy = (dummy); \
  struct Layer * _UpfrontLayer_layer = (layer); \
  ({ \
  register char * _UpfrontLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), LONG __asm("a0"), struct Layer * __asm("a1"))) \
  (_UpfrontLayer__bn - 48))(_UpfrontLayer__bn, _UpfrontLayer_dummy, _UpfrontLayer_layer); \
});})

#define BehindLayer(dummy, layer) ({ \
  LONG _BehindLayer_dummy = (dummy); \
  struct Layer * _BehindLayer_layer = (layer); \
  ({ \
  register char * _BehindLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), LONG __asm("a0"), struct Layer * __asm("a1"))) \
  (_BehindLayer__bn - 54))(_BehindLayer__bn, _BehindLayer_dummy, _BehindLayer_layer); \
});})

#define MoveLayer(dummy, layer, dx, dy) ({ \
  LONG _MoveLayer_dummy = (dummy); \
  struct Layer * _MoveLayer_layer = (layer); \
  LONG _MoveLayer_dx = (dx); \
  LONG _MoveLayer_dy = (dy); \
  ({ \
  register char * _MoveLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), LONG __asm("a0"), struct Layer * __asm("a1"), LONG __asm("d0"), LONG __asm("d1"))) \
  (_MoveLayer__bn - 60))(_MoveLayer__bn, _MoveLayer_dummy, _MoveLayer_layer, _MoveLayer_dx, _MoveLayer_dy); \
});})

#define SizeLayer(dummy, layer, dx, dy) ({ \
  LONG _SizeLayer_dummy = (dummy); \
  struct Layer * _SizeLayer_layer = (layer); \
  LONG _SizeLayer_dx = (dx); \
  LONG _SizeLayer_dy = (dy); \
  ({ \
  register char * _SizeLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), LONG __asm("a0"), struct Layer * __asm("a1"), LONG __asm("d0"), LONG __asm("d1"))) \
  (_SizeLayer__bn - 66))(_SizeLayer__bn, _SizeLayer_dummy, _SizeLayer_layer, _SizeLayer_dx, _SizeLayer_dy); \
});})

#define ScrollLayer(dummy, layer, dx, dy) ({ \
  LONG _ScrollLayer_dummy = (dummy); \
  struct Layer * _ScrollLayer_layer = (layer); \
  LONG _ScrollLayer_dx = (dx); \
  LONG _ScrollLayer_dy = (dy); \
  ({ \
  register char * _ScrollLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), LONG __asm("a0"), struct Layer * __asm("a1"), LONG __asm("d0"), LONG __asm("d1"))) \
  (_ScrollLayer__bn - 72))(_ScrollLayer__bn, _ScrollLayer_dummy, _ScrollLayer_layer, _ScrollLayer_dx, _ScrollLayer_dy); \
});})

#define BeginUpdate(l) ({ \
  struct Layer * _BeginUpdate_l = (l); \
  ({ \
  register char * _BeginUpdate__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), struct Layer * __asm("a0"))) \
  (_BeginUpdate__bn - 78))(_BeginUpdate__bn, _BeginUpdate_l); \
});})

#define EndUpdate(layer, flag) ({ \
  struct Layer * _EndUpdate_layer = (layer); \
  ULONG _EndUpdate_flag = (flag); \
  ({ \
  register char * _EndUpdate__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct Layer * __asm("a0"), ULONG __asm("d0"))) \
  (_EndUpdate__bn - 84))(_EndUpdate__bn, _EndUpdate_layer, _EndUpdate_flag); \
});})

#define DeleteLayer(dummy, layer) ({ \
  LONG _DeleteLayer_dummy = (dummy); \
  struct Layer * _DeleteLayer_layer = (layer); \
  ({ \
  register char * _DeleteLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), LONG __asm("a0"), struct Layer * __asm("a1"))) \
  (_DeleteLayer__bn - 90))(_DeleteLayer__bn, _DeleteLayer_dummy, _DeleteLayer_layer); \
});})

#define LockLayer(dummy, layer) ({ \
  LONG _LockLayer_dummy = (dummy); \
  struct Layer * _LockLayer_layer = (layer); \
  ({ \
  register char * _LockLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), LONG __asm("a0"), struct Layer * __asm("a1"))) \
  (_LockLayer__bn - 96))(_LockLayer__bn, _LockLayer_dummy, _LockLayer_layer); \
});})

#define UnlockLayer(layer) ({ \
  struct Layer * _UnlockLayer_layer = (layer); \
  ({ \
  register char * _UnlockLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct Layer * __asm("a0"))) \
  (_UnlockLayer__bn - 102))(_UnlockLayer__bn, _UnlockLayer_layer); \
});})

#define LockLayers(li) ({ \
  struct Layer_Info * _LockLayers_li = (li); \
  ({ \
  register char * _LockLayers__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"))) \
  (_LockLayers__bn - 108))(_LockLayers__bn, _LockLayers_li); \
});})

#define UnlockLayers(li) ({ \
  struct Layer_Info * _UnlockLayers_li = (li); \
  ({ \
  register char * _UnlockLayers__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((BOOL (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"))) \
  (_UnlockLayers__bn - 114))(_UnlockLayers__bn, _UnlockLayers_li); \
});})

#define LockLayerInfo(li) ({ \
  struct Layer_Info * _LockLayerInfo_li = (li); \
  ({ \
  register char * _LockLayerInfo__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"))) \
  (_LockLayerInfo__bn - 120))(_LockLayerInfo__bn, _LockLayerInfo_li); \
});})

#define SwapBitsRastPortClipRect(rp, cr) ({ \
  struct RastPort * _SwapBitsRastPortClipRect_rp = (rp); \
  struct ClipRect * _SwapBitsRastPortClipRect_cr = (cr); \
  ({ \
  register char * _SwapBitsRastPortClipRect__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct RastPort * __asm("a0"), struct ClipRect * __asm("a1"))) \
  (_SwapBitsRastPortClipRect__bn - 126))(_SwapBitsRastPortClipRect__bn, _SwapBitsRastPortClipRect_rp, _SwapBitsRastPortClipRect_cr); \
});})

#define WhichLayer(li, x, y) ({ \
  struct Layer_Info * _WhichLayer_li = (li); \
  LONG _WhichLayer_x = (x); \
  LONG _WhichLayer_y = (y); \
  ({ \
  register char * _WhichLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Layer * (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"), LONG __asm("d0"), LONG __asm("d1"))) \
  (_WhichLayer__bn - 132))(_WhichLayer__bn, _WhichLayer_li, _WhichLayer_x, _WhichLayer_y); \
});})

#define UnlockLayerInfo(li) ({ \
  struct Layer_Info * _UnlockLayerInfo_li = (li); \
  ({ \
  register char * _UnlockLayerInfo__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"))) \
  (_UnlockLayerInfo__bn - 138))(_UnlockLayerInfo__bn, _UnlockLayerInfo_li); \
});})

#define NewLayerInfo() ({ \
  register char * _NewLayerInfo__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Layer_Info * (*)(char * __asm("a6"))) \
  (_NewLayerInfo__bn - 144))(_NewLayerInfo__bn); \
})

#define DisposeLayerInfo(li) ({ \
  struct Layer_Info * _DisposeLayerInfo_li = (li); \
  ({ \
  register char * _DisposeLayerInfo__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"))) \
  (_DisposeLayerInfo__bn - 150))(_DisposeLayerInfo__bn, _DisposeLayerInfo_li); \
});})

#define FattenLayerInfo(li) ({ \
  struct Layer_Info * _FattenLayerInfo_li = (li); \
  ({ \
  register char * _FattenLayerInfo__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"))) \
  (_FattenLayerInfo__bn - 156))(_FattenLayerInfo__bn, _FattenLayerInfo_li); \
});})

#define ThinLayerInfo(li) ({ \
  struct Layer_Info * _ThinLayerInfo_li = (li); \
  ({ \
  register char * _ThinLayerInfo__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"))) \
  (_ThinLayerInfo__bn - 162))(_ThinLayerInfo__bn, _ThinLayerInfo_li); \
});})

#define MoveLayerInFrontOf(layer_to_move, other_layer) ({ \
  struct Layer * _MoveLayerInFrontOf_layer_to_move = (layer_to_move); \
  struct Layer * _MoveLayerInFrontOf_other_layer = (other_layer); \
  ({ \
  register char * _MoveLayerInFrontOf__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), struct Layer * __asm("a0"), struct Layer * __asm("a1"))) \
  (_MoveLayerInFrontOf__bn - 168))(_MoveLayerInFrontOf__bn, _MoveLayerInFrontOf_layer_to_move, _MoveLayerInFrontOf_other_layer); \
});})

#define InstallClipRegion(layer, region) ({ \
  struct Layer * _InstallClipRegion_layer = (layer); \
  CONST struct Region * _InstallClipRegion_region = (region); \
  ({ \
  register char * _InstallClipRegion__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Region * (*)(char * __asm("a6"), struct Layer * __asm("a0"), CONST struct Region * __asm("a1"))) \
  (_InstallClipRegion__bn - 174))(_InstallClipRegion__bn, _InstallClipRegion_layer, _InstallClipRegion_region); \
});})

#define MoveSizeLayer(layer, dx, dy, dw, dh) ({ \
  struct Layer * _MoveSizeLayer_layer = (layer); \
  LONG _MoveSizeLayer_dx = (dx); \
  LONG _MoveSizeLayer_dy = (dy); \
  LONG _MoveSizeLayer_dw = (dw); \
  LONG _MoveSizeLayer_dh = (dh); \
  ({ \
  register char * _MoveSizeLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), struct Layer * __asm("a0"), LONG __asm("d0"), LONG __asm("d1"), LONG __asm("d2"), LONG __asm("d3"))) \
  (_MoveSizeLayer__bn - 180))(_MoveSizeLayer__bn, _MoveSizeLayer_layer, _MoveSizeLayer_dx, _MoveSizeLayer_dy, _MoveSizeLayer_dw, _MoveSizeLayer_dh); \
});})

#define CreateUpfrontHookLayer(li, bm, x0, y0, x1, y1, flags, hook, bm2) ({ \
  struct Layer_Info * _CreateUpfrontHookLayer_li = (li); \
  struct BitMap * _CreateUpfrontHookLayer_bm = (bm); \
  LONG _CreateUpfrontHookLayer_x0 = (x0); \
  LONG _CreateUpfrontHookLayer_y0 = (y0); \
  LONG _CreateUpfrontHookLayer_x1 = (x1); \
  LONG _CreateUpfrontHookLayer_y1 = (y1); \
  LONG _CreateUpfrontHookLayer_flags = (flags); \
  struct Hook * _CreateUpfrontHookLayer_hook = (hook); \
  struct BitMap * _CreateUpfrontHookLayer_bm2 = (bm2); \
  ({ \
  register char * _CreateUpfrontHookLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Layer * (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"), struct BitMap * __asm("a1"), LONG __asm("d0"), LONG __asm("d1"), LONG __asm("d2"), LONG __asm("d3"), LONG __asm("d4"), struct Hook * __asm("a3"), struct BitMap * __asm("a2"))) \
  (_CreateUpfrontHookLayer__bn - 186))(_CreateUpfrontHookLayer__bn, _CreateUpfrontHookLayer_li, _CreateUpfrontHookLayer_bm, _CreateUpfrontHookLayer_x0, _CreateUpfrontHookLayer_y0, _CreateUpfrontHookLayer_x1, _CreateUpfrontHookLayer_y1, _CreateUpfrontHookLayer_flags, _CreateUpfrontHookLayer_hook, _CreateUpfrontHookLayer_bm2); \
});})

#define CreateBehindHookLayer(li, bm, x0, y0, x1, y1, flags, hook, bm2) ({ \
  struct Layer_Info * _CreateBehindHookLayer_li = (li); \
  struct BitMap * _CreateBehindHookLayer_bm = (bm); \
  LONG _CreateBehindHookLayer_x0 = (x0); \
  LONG _CreateBehindHookLayer_y0 = (y0); \
  LONG _CreateBehindHookLayer_x1 = (x1); \
  LONG _CreateBehindHookLayer_y1 = (y1); \
  LONG _CreateBehindHookLayer_flags = (flags); \
  struct Hook * _CreateBehindHookLayer_hook = (hook); \
  struct BitMap * _CreateBehindHookLayer_bm2 = (bm2); \
  ({ \
  register char * _CreateBehindHookLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Layer * (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"), struct BitMap * __asm("a1"), LONG __asm("d0"), LONG __asm("d1"), LONG __asm("d2"), LONG __asm("d3"), LONG __asm("d4"), struct Hook * __asm("a3"), struct BitMap * __asm("a2"))) \
  (_CreateBehindHookLayer__bn - 192))(_CreateBehindHookLayer__bn, _CreateBehindHookLayer_li, _CreateBehindHookLayer_bm, _CreateBehindHookLayer_x0, _CreateBehindHookLayer_y0, _CreateBehindHookLayer_x1, _CreateBehindHookLayer_y1, _CreateBehindHookLayer_flags, _CreateBehindHookLayer_hook, _CreateBehindHookLayer_bm2); \
});})

#define InstallLayerHook(layer, hook) ({ \
  struct Layer * _InstallLayerHook_layer = (layer); \
  struct Hook * _InstallLayerHook_hook = (hook); \
  ({ \
  register char * _InstallLayerHook__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Hook * (*)(char * __asm("a6"), struct Layer * __asm("a0"), struct Hook * __asm("a1"))) \
  (_InstallLayerHook__bn - 198))(_InstallLayerHook__bn, _InstallLayerHook_layer, _InstallLayerHook_hook); \
});})

#define InstallLayerInfoHook(li, hook) ({ \
  struct Layer_Info * _InstallLayerInfoHook_li = (li); \
  CONST struct Hook * _InstallLayerInfoHook_hook = (hook); \
  ({ \
  register char * _InstallLayerInfoHook__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Hook * (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"), CONST struct Hook * __asm("a1"))) \
  (_InstallLayerInfoHook__bn - 204))(_InstallLayerInfoHook__bn, _InstallLayerInfoHook_li, _InstallLayerInfoHook_hook); \
});})

#define SortLayerCR(layer, dx, dy) ({ \
  struct Layer * _SortLayerCR_layer = (layer); \
  LONG _SortLayerCR_dx = (dx); \
  LONG _SortLayerCR_dy = (dy); \
  ({ \
  register char * _SortLayerCR__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct Layer * __asm("a0"), LONG __asm("d0"), LONG __asm("d1"))) \
  (_SortLayerCR__bn - 210))(_SortLayerCR__bn, _SortLayerCR_layer, _SortLayerCR_dx, _SortLayerCR_dy); \
});})

#define DoHookClipRects(hook, rport, rect) ({ \
  CONST struct Hook * _DoHookClipRects_hook = (hook); \
  struct RastPort * _DoHookClipRects_rport = (rport); \
  CONST struct Rectangle * _DoHookClipRects_rect = (rect); \
  ({ \
  register char * _DoHookClipRects__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), CONST struct Hook * __asm("a0"), struct RastPort * __asm("a1"), CONST struct Rectangle * __asm("a2"))) \
  (_DoHookClipRects__bn - 216))(_DoHookClipRects__bn, _DoHookClipRects_hook, _DoHookClipRects_rport, _DoHookClipRects_rect); \
});})

#define LayerOccluded(layer) ({ \
  struct Layer * _LayerOccluded_layer = (layer); \
  ({ \
  register char * _LayerOccluded__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), struct Layer * __asm("a0"))) \
  (_LayerOccluded__bn - 222))(_LayerOccluded__bn, _LayerOccluded_layer); \
});})

#define HideLayer(layer) ({ \
  struct Layer * _HideLayer_layer = (layer); \
  ({ \
  register char * _HideLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), struct Layer * __asm("a0"))) \
  (_HideLayer__bn - 228))(_HideLayer__bn, _HideLayer_layer); \
});})

#define ShowLayer(layer, infront_of) ({ \
  struct Layer * _ShowLayer_layer = (layer); \
  struct Layer * _ShowLayer_infront_of = (infront_of); \
  ({ \
  register char * _ShowLayer__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), struct Layer * __asm("a0"), struct Layer * __asm("a1"))) \
  (_ShowLayer__bn - 234))(_ShowLayer__bn, _ShowLayer_layer, _ShowLayer_infront_of); \
});})

#define SetLayerInfoBounds(li, bounds) ({ \
  struct Layer_Info * _SetLayerInfoBounds_li = (li); \
  struct Rectangle * _SetLayerInfoBounds_bounds = (bounds); \
  ({ \
  register char * _SetLayerInfoBounds__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((LONG (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"), struct Rectangle * __asm("a1"))) \
  (_SetLayerInfoBounds__bn - 240))(_SetLayerInfoBounds__bn, _SetLayerInfoBounds_li, _SetLayerInfoBounds_bounds); \
});})

#define AllocClipRect(li) ({ \
  struct Layer_Info * _AllocClipRect_li = (li); \
  ({ \
  register char * _AllocClipRect__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct ClipRect * (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"))) \
  (_AllocClipRect__bn - 246))(_AllocClipRect__bn, _AllocClipRect_li); \
});})

#define FreeClipRect(li, cr) ({ \
  struct Layer_Info * _FreeClipRect_li = (li); \
  struct ClipRect * _FreeClipRect_cr = (cr); \
  ({ \
  register char * _FreeClipRect__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((VOID (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"), struct ClipRect * __asm("a1"))) \
  (_FreeClipRect__bn - 252))(_FreeClipRect__bn, _FreeClipRect_li, _FreeClipRect_cr); \
});})

#define CreateLayerA(li, tlist) ({ \
  struct Layer_Info * _CreateLayerA_li = (li); \
  struct TagItem * _CreateLayerA_tlist = (tlist); \
  ({ \
  register char * _CreateLayerA__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Layer * (*)(char * __asm("a6"), struct Layer_Info * __asm("a0"), struct TagItem * __asm("a1"))) \
  (_CreateLayerA__bn - 258))(_CreateLayerA__bn, _CreateLayerA_li, _CreateLayerA_tlist); \
});})

#ifndef NO_INLINE_STDARG
static __inline__ struct Layer * ___CreateLayer(struct Library * LayersBase, struct Layer_Info * li, Tag tlist, ...)
{
  return CreateLayerA(li, (struct TagItem *) &tlist);
}

#define CreateLayer(li...) ___CreateLayer(LAYERS_BASE_NAME, li)
#endif

#define ChangeLayerShape(layer, region, hook) ({ \
  struct Layer * _ChangeLayerShape_layer = (layer); \
  struct Region * _ChangeLayerShape_region = (region); \
  struct Hook * _ChangeLayerShape_hook = (hook); \
  ({ \
  register char * _ChangeLayerShape__bn __asm("a6") = (char *) (LAYERS_BASE_NAME);\
  ((struct Region * (*)(char * __asm("a6"), struct Layer * __asm("a0"), struct Region * __asm("a1"), struct Hook * __asm("a2"))) \
  (_ChangeLayerShape__bn - 264))(_ChangeLayerShape__bn, _ChangeLayerShape_layer, _ChangeLayerShape_region, _ChangeLayerShape_hook); \
});})

#endif /*  _INLINE_LAYERS_H  */
