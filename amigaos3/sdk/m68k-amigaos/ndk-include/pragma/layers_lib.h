#ifndef PRAGMA_LAYERS_LIB_H
#define PRAGMA_LAYERS_LIB_H

/*
**	$VER: layers_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_LAYERS_PROTOS_H
#include <clib/layers_protos.h>
#endif /* CLIB_LAYERS_PROTOS_H */

/* "layers.library" */
#pragma amicall(LayersBase, 0x1e, InitLayers(a0))
#pragma amicall(LayersBase, 0x24, CreateUpfrontLayer(a0,a1,d0,d1,d2,d3,d4,a2))
#pragma amicall(LayersBase, 0x2a, CreateBehindLayer(a0,a1,d0,d1,d2,d3,d4,a2))
#pragma amicall(LayersBase, 0x30, UpfrontLayer(a0,a1))
#pragma amicall(LayersBase, 0x36, BehindLayer(a0,a1))
#pragma amicall(LayersBase, 0x3c, MoveLayer(a0,a1,d0,d1))
#pragma amicall(LayersBase, 0x42, SizeLayer(a0,a1,d0,d1))
#pragma amicall(LayersBase, 0x48, ScrollLayer(a0,a1,d0,d1))
#pragma amicall(LayersBase, 0x4e, BeginUpdate(a0))
#pragma amicall(LayersBase, 0x54, EndUpdate(a0,d0))
#pragma amicall(LayersBase, 0x5a, DeleteLayer(a0,a1))
#pragma amicall(LayersBase, 0x60, LockLayer(a0,a1))
#pragma amicall(LayersBase, 0x66, UnlockLayer(a0))
#pragma amicall(LayersBase, 0x6c, LockLayers(a0))
#pragma amicall(LayersBase, 0x72, UnlockLayers(a0))
#pragma amicall(LayersBase, 0x78, LockLayerInfo(a0))
#pragma amicall(LayersBase, 0x7e, SwapBitsRastPortClipRect(a0,a1))
#pragma amicall(LayersBase, 0x84, WhichLayer(a0,d0,d1))
#pragma amicall(LayersBase, 0x8a, UnlockLayerInfo(a0))
#pragma amicall(LayersBase, 0x90, NewLayerInfo())
#pragma amicall(LayersBase, 0x96, DisposeLayerInfo(a0))
#pragma amicall(LayersBase, 0x9c, FattenLayerInfo(a0))
#pragma amicall(LayersBase, 0xa2, ThinLayerInfo(a0))
#pragma amicall(LayersBase, 0xa8, MoveLayerInFrontOf(a0,a1))
#pragma amicall(LayersBase, 0xae, InstallClipRegion(a0,a1))
#pragma amicall(LayersBase, 0xb4, MoveSizeLayer(a0,d0,d1,d2,d3))
#pragma amicall(LayersBase, 0xba, CreateUpfrontHookLayer(a0,a1,d0,d1,d2,d3,d4,a3,a2))
#pragma amicall(LayersBase, 0xc0, CreateBehindHookLayer(a0,a1,d0,d1,d2,d3,d4,a3,a2))
#pragma amicall(LayersBase, 0xc6, InstallLayerHook(a0,a1))
/*--- functions in V39 or higher (Release 3.0) ---*/
#pragma amicall(LayersBase, 0xcc, InstallLayerInfoHook(a0,a1))
#pragma amicall(LayersBase, 0xd2, SortLayerCR(a0,d0,d1))
#pragma amicall(LayersBase, 0xd8, DoHookClipRects(a0,a1,a2))
/*--- functions in V45 or higher (Release 3.9) ---*/
#pragma amicall(LayersBase, 0xde, LayerOccluded(a0))
#pragma amicall(LayersBase, 0xe4, HideLayer(a0))
#pragma amicall(LayersBase, 0xea, ShowLayer(a0,a1))
#pragma amicall(LayersBase, 0xf0, SetLayerInfoBounds(a0,a1))

#endif /* PRAGMA_LAYERS_LIB_H */
