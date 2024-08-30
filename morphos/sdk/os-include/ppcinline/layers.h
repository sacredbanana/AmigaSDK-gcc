/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_LAYERS_H
#define _PPCINLINE_LAYERS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef LAYERS_BASE_NAME
#define LAYERS_BASE_NAME LayersBase
#endif /* !LAYERS_BASE_NAME */

#define WhichLayer(__p0, __p1, __p2) \
	LP3(132, struct Layer *, WhichLayer, \
		struct Layer_Info *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define CreateBehindLayerTagList(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8(240, struct Layer *, CreateBehindLayerTagList, \
		struct Layer_Info *, __p0, a0, \
		struct BitMap *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		struct TagItem *, __p7, a2, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RenderLayerInfoTagList(__p0, __p1) \
	LP2(282, BOOL , RenderLayerInfoTagList, \
		struct Layer_Info *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateBehindHookLayer(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	LP9(192, struct Layer *, CreateBehindHookLayer, \
		struct Layer_Info *, __p0, a0, \
		struct BitMap *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		struct Hook *, __p7, a3, \
		struct BitMap *, __p8, a2, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UpfrontLayer(__p0, __p1) \
	LP2(48, LONG , UpfrontLayer, \
		LONG , __p0, a0, \
		struct Layer *, __p1, a1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SizeLayer(__p0, __p1, __p2, __p3) \
	LP4(66, LONG , SizeLayer, \
		LONG , __p0, a0, \
		struct Layer *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define WhichLayerBehindLayer(__p0, __p1, __p2) \
	LP3(252, struct Layer *, WhichLayerBehindLayer, \
		struct Layer *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewLayerInfo() \
	LP0(144, struct Layer_Info *, NewLayerInfo, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define IsVisibleInLayer(__p0, __p1, __p2, __p3, __p4) \
	LP5(300, BOOL , IsVisibleInLayer, \
		struct Layer *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockLayerUpdates(__p0) \
	LP1NR(294, UnlockLayerUpdates, \
		struct Layer *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FattenLayerInfo(__p0) \
	LP1(156, LONG , FattenLayerInfo, \
		struct Layer_Info *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SwapBitsRastPortClipRect(__p0, __p1) \
	LP2NR(126, SwapBitsRastPortClipRect, \
		struct RastPort *, __p0, a0, \
		struct ClipRect *, __p1, a1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoHookClipRects(__p0, __p1, __p2) \
	LP3NR(216, DoHookClipRects, \
		struct Hook *, __p0, a0, \
		struct RastPort *, __p1, a1, \
		CONST struct Rectangle *, __p2, a2, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockLayers(__p0) \
	LP1NR(114, UnlockLayers, \
		struct Layer_Info *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockLayer(__p0) \
	LP1NR(102, UnlockLayer, \
		struct Layer *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MoveSizeLayer(__p0, __p1, __p2, __p3, __p4) \
	LP5(180, LONG , MoveSizeLayer, \
		struct Layer *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockLayers(__p0) \
	LP1NR(108, LockLayers, \
		struct Layer_Info *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define CreateUpfrontLayer(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8(36, struct Layer *, CreateUpfrontLayer, \
		struct Layer_Info *, __p0, a0, \
		struct BitMap *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		struct BitMap *, __p7, a2, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define LockLayer(__p0, __p1) \
	LP2NR(96, LockLayer, \
		LONG , __p0, a0, \
		struct Layer *, __p1, a1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BeginUpdate(__p0) \
	LP1(78, LONG , BeginUpdate, \
		struct Layer *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockLayerUpdates(__p0) \
	LP1NR(288, LockLayerUpdates, \
		struct Layer *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define EndUpdate(__p0, __p1) \
	LP2NR(84, EndUpdate, \
		struct Layer *, __p0, a0, \
		ULONG , __p1, d0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitLayers(__p0) \
	LP1NR(30, InitLayers, \
		struct Layer_Info *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SortLayerCR(__p0, __p1, __p2) \
	LP3NR(210, SortLayerCR, \
		struct Layer *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateUpfrontLayerTagList(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8(234, struct Layer *, CreateUpfrontLayerTagList, \
		struct Layer_Info *, __p0, a0, \
		struct BitMap *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		struct TagItem *, __p7, a2, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DeleteLayer(__p0, __p1) \
	LP2(90, LONG , DeleteLayer, \
		LONG , __p0, a0, \
		struct Layer *, __p1, a1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MoveLayer(__p0, __p1, __p2, __p3) \
	LP4(60, LONG , MoveLayer, \
		LONG , __p0, a0, \
		struct Layer *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IsLayerVisible(__p0) \
	LP1(258, BOOL , IsLayerVisible, \
		struct Layer *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockLayerInfo(__p0) \
	LP1NR(120, LockLayerInfo, \
		struct Layer_Info *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define IsLayerHitable(__p0) \
	LP1(306, BOOL , IsLayerHitable, \
		struct Layer *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InstallClipRegion(__p0, __p1) \
	LP2(174, struct Region *, InstallClipRegion, \
		struct Layer *, __p0, a0, \
		CONST struct Region *, __p1, a1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DisposeLayerInfo(__p0) \
	LP1NR(150, DisposeLayerInfo, \
		struct Layer_Info *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScrollLayer(__p0, __p1, __p2, __p3) \
	LP4NR(72, ScrollLayer, \
		LONG , __p0, a0, \
		struct Layer *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InstallLayerInfoHook(__p0, __p1) \
	LP2(204, struct Hook *, InstallLayerInfoHook, \
		struct Layer_Info *, __p0, a0, \
		CONST struct Hook *, __p1, a1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockLayerInfo(__p0) \
	LP1NR(138, UnlockLayerInfo, \
		struct Layer_Info *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define MoveLayerInFrontOf(__p0, __p1) \
	LP2(168, LONG , MoveLayerInFrontOf, \
		struct Layer *, __p0, a0, \
		struct Layer *, __p1, a1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateBehindLayer(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8(42, struct Layer *, CreateBehindLayer, \
		struct Layer_Info *, __p0, a0, \
		struct BitMap *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		struct BitMap *, __p7, a2, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BehindLayer(__p0, __p1) \
	LP2(54, LONG , BehindLayer, \
		LONG , __p0, a0, \
		struct Layer *, __p1, a1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InstallLayerHook(__p0, __p1) \
	LP2(198, struct Hook *, InstallLayerHook, \
		struct Layer *, __p0, a0, \
		struct Hook *, __p1, a1, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateUpfrontHookLayer(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	LP9(186, struct Layer *, CreateUpfrontHookLayer, \
		struct Layer_Info *, __p0, a0, \
		struct BitMap *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		struct Hook *, __p7, a3, \
		struct BitMap *, __p8, a2, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ThinLayerInfo(__p0) \
	LP1NR(162, ThinLayerInfo, \
		struct Layer_Info *, __p0, a0, \
		, LAYERS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>


#define RenderLayerInfoTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	RenderLayerInfoTagList(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_LAYERS_H */
