/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_GRAPHICS_H
#define _PPCINLINE_GRAPHICS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef GRAPHICS_BASE_NAME
#define GRAPHICS_BASE_NAME GfxBase
#endif /* !GRAPHICS_BASE_NAME */

#define WaitBOVP(__p0) \
	LP1NR(402, WaitBOVP, \
		struct ViewPort *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeColorMap(__p0) \
	LP1NR(576, FreeColorMap, \
		struct ColorMap *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenFontTagList(__p0, __p1) \
	LP2(1062, struct TextFont *, OpenFontTagList, \
		struct TextAttr *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ExtendFont(__p0, __p1) \
	LP2(816, ULONG , ExtendFont, \
		struct TextFont *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeVPortCopLists(__p0) \
	LP1NR(540, FreeVPortCopLists, \
		struct ViewPort *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CMove(__p0, __p1, __p2) \
	LP3NR(372, CMove, \
		struct UCopList *, __p0, a1, \
		APTR , __p1, d0, \
		LONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AreaEnd(__p0) \
	LP1(264, LONG , AreaEnd, \
		struct RastPort *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemVSprite(__p0) \
	LP1NR(138, RemVSprite, \
		struct VSprite *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenFont(__p0) \
	LP1(72, struct TextFont *, OpenFont, \
		struct TextAttr *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DisownBlitter() \
	LP0NR(462, DisownBlitter, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocSpriteDataA(__p0, __p1) \
	LP2(1020, struct ExtSprite *, AllocSpriteDataA, \
		CONST struct BitMap *, __p0, a2, \
		CONST struct TagItem *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseMonitor(__p0) \
	LP1(720, BOOL , CloseMonitor, \
		struct MonitorSpec *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BltMaskBitMapRastPort(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	LP10NR(636, BltMaskBitMapRastPort, \
		CONST struct BitMap *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		struct RastPort *, __p3, a1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		LONG , __p7, d5, \
		ULONG , __p8, d6, \
		CONST PLANEPTR , __p9, a2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReleasePen(__p0, __p1) \
	LP2NR(948, ReleasePen, \
		struct ColorMap *, __p0, a0, \
		ULONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BltTemplate(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8NR(36, BltTemplate, \
		CONST PLANEPTR , __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		struct RastPort *, __p3, a1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		LONG , __p7, d5, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeSpriteData(__p0) \
	LP1NR(1032, FreeSpriteData, \
		struct ExtSprite *, __p0, a2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define PolyDraw(__p0, __p1, __p2) \
	LP3NR(336, PolyDraw, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		CONST WORD *, __p2, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetBitMapAttr(__p0, __p1) \
	LP2(960, ULONG , GetBitMapAttr, \
		CONST struct BitMap *, __p0, a0, \
		ULONG , __p1, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDrMd(__p0) \
	LP1(870, ULONG , GetDrMd, \
		struct RastPort *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LoadRGB4(__p0, __p1, __p2) \
	LP3NR(192, LoadRGB4, \
		struct ViewPort *, __p0, a0, \
		CONST UWORD *, __p1, a1, \
		LONG , __p2, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScrollRaster(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7NR(396, ScrollRaster, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		LONG , __p5, d4, \
		LONG , __p6, d5, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CopySBitMap(__p0) \
	LP1NR(450, CopySBitMap, \
		struct Layer *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetRGB32(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(852, SetRGB32, \
		struct ViewPort *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AskFont(__p0, __p1) \
	LP2NR(474, AskFont, \
		struct RastPort *, __p0, a1, \
		struct TextAttr *, __p1, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemIBob(__p0, __p1, __p2) \
	LP3NR(132, RemIBob, \
		struct Bob *, __p0, a0, \
		struct RastPort *, __p1, a1, \
		struct ViewPort *, __p2, a2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define XorRegionRegion(__p0, __p1) \
	LP2(618, BOOL , XorRegionRegion, \
		CONST struct Region *, __p0, a0, \
		struct Region *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScrollRasterBF(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7NR(1002, ScrollRasterBF, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		LONG , __p5, d4, \
		LONG , __p6, d5, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TextFit(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8(696, ULONG , TextFit, \
		struct RastPort *, __p0, a1, \
		CONST_STRPTR , __p1, a0, \
		ULONG , __p2, d0, \
		CONST struct TextExtent *, __p3, a2, \
		CONST struct TextExtent *, __p4, a3, \
		LONG , __p5, d1, \
		ULONG , __p6, d2, \
		ULONG , __p7, d3, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WritePixelArray8(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7(786, LONG , WritePixelArray8, \
		struct RastPort *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		UBYTE *, __p5, a2, \
		struct RastPort *, __p6, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NextDisplayInfo(__p0) \
	LP1(732, ULONG , NextDisplayInfo, \
		ULONG , __p0, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetRast(__p0, __p1) \
	LP2NR(234, SetRast, \
		struct RastPort *, __p0, a1, \
		ULONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GfxNew(__p0) \
	LP1(660, APTR , GfxNew, \
		ULONG , __p0, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemFont(__p0) \
	LP1NR(486, RemFont, \
		struct TextFont *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitVPort(__p0) \
	LP1NR(204, InitVPort, \
		struct ViewPort *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define QBSBlit(__p0) \
	LP1NR(294, QBSBlit, \
		struct bltnode *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetRPAttrsA(__p0, __p1) \
	LP2NR(1044, GetRPAttrsA, \
		CONST struct RastPort *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocDBufInfo(__p0) \
	LP1(966, struct DBufInfo *, AllocDBufInfo, \
		struct ViewPort *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WritePixel(__p0, __p1, __p2) \
	LP3(324, LONG , WritePixel, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define VBeamPos() \
	LP0(384, LONG , VBeamPos, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetRPAttrsA(__p0, __p1) \
	LP2NR(1038, SetRPAttrsA, \
		struct RastPort *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LoadView(__p0) \
	LP1NR(222, LoadView, \
		struct View *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OrRegionRegion(__p0, __p1) \
	LP2(612, BOOL , OrRegionRegion, \
		CONST struct Region *, __p0, a0, \
		struct Region *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MakeVPort(__p0, __p1) \
	LP2(216, ULONG , MakeVPort, \
		struct View *, __p0, a0, \
		struct ViewPort *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetOutlinePen(__p0, __p1) \
	LP2(978, ULONG , SetOutlinePen, \
		struct RastPort *, __p0, a0, \
		ULONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AttemptLockLayerRom(__p0) \
	LP1(654, BOOL , AttemptLockLayerRom, \
		struct Layer *, __p0, a5, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WaitTOF() \
	LP0NR(270, WaitTOF, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LockLayerRom(__p0) \
	LP1NR(432, LockLayerRom, \
		struct Layer *, __p0, a5, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ClipBlit(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	LP9NR(552, ClipBlit, \
		struct RastPort *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		struct RastPort *, __p3, a1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		LONG , __p7, d5, \
		ULONG , __p8, d6, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AndRegionRegion(__p0, __p1) \
	LP2(624, BOOL , AndRegionRegion, \
		CONST struct Region *, __p0, a0, \
		struct Region *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainBestPenA(__p0, __p1, __p2, __p3, __p4) \
	LP5(840, LONG , ObtainBestPenA, \
		struct ColorMap *, __p0, a0, \
		ULONG , __p1, d1, \
		ULONG , __p2, d2, \
		ULONG , __p3, d3, \
		CONST struct TagItem *, __p4, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocBitMap(__p0, __p1, __p2, __p3, __p4) \
	LP5(918, struct BitMap *, AllocBitMap, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		ULONG , __p2, d2, \
		ULONG , __p3, d3, \
		CONST struct BitMap *, __p4, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AreaDraw(__p0, __p1, __p2) \
	LP3(258, LONG , AreaDraw, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeCprList(__p0) \
	LP1NR(564, FreeCprList, \
		struct cprlist *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Animate(__p0, __p1) \
	LP2NR(162, Animate, \
		struct AnimOb **, __p0, a0, \
		struct RastPort *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FontExtent(__p0, __p1) \
	LP2NR(762, FontExtent, \
		CONST struct TextFont *, __p0, a0, \
		struct TextExtent *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetSoftStyle(__p0, __p1, __p2) \
	LP3(90, ULONG , SetSoftStyle, \
		struct RastPort *, __p0, a1, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WritePixelLine8(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6(774, LONG , WritePixelLine8, \
		struct RastPort *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		UBYTE *, __p4, a2, \
		struct RastPort *, __p5, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WeighTAMatch(__p0, __p1, __p2) \
	LP3(804, WORD , WeighTAMatch, \
		struct TTextAttr *, __p0, a0, \
		struct TextAttr *, __p1, a1, \
		struct TagItem *, __p2, a2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ModeNotAvailable(__p0) \
	LP1(798, LONG , ModeNotAvailable, \
		ULONG , __p0, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BltPattern(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7NR(312, BltPattern, \
		struct RastPort *, __p0, a1, \
		CONST PLANEPTR , __p1, a0, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		ULONG , __p6, d4, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitBitMap(__p0, __p1, __p2, __p3) \
	LP4NR(390, InitBitMap, \
		struct BitMap *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetRGB4(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(288, SetRGB4, \
		struct ViewPort *, __p0, a0, \
		LONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitGels(__p0, __p1, __p2) \
	LP3NR(120, InitGels, \
		struct VSprite *, __p0, a0, \
		struct VSprite *, __p1, a1, \
		struct GelsInfo *, __p2, a2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AllocRaster(__p0, __p1) \
	LP2(492, PLANEPTR , AllocRaster, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddVSprite(__p0, __p1) \
	LP2NR(102, AddVSprite, \
		struct VSprite *, __p0, a0, \
		struct RastPort *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitMasks(__p0) \
	LP1NR(126, InitMasks, \
		struct VSprite *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScrollVPort(__p0) \
	LP1NR(588, ScrollVPort, \
		struct ViewPort *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetRGB4CM(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(630, SetRGB4CM, \
		struct ColorMap *, __p0, a0, \
		LONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UnlockLayerRom(__p0) \
	LP1NR(438, UnlockLayerRom, \
		struct Layer *, __p0, a5, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ClearRectRegion(__p0, __p1) \
	LP2(522, BOOL , ClearRectRegion, \
		struct Region *, __p0, a0, \
		CONST struct Rectangle *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AttachPalExtra(__p0, __p1) \
	LP2(834, LONG , AttachPalExtra, \
		struct ColorMap *, __p0, a0, \
		struct ViewPort *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define XorRectRegion(__p0, __p1) \
	LP2(558, BOOL , XorRectRegion, \
		struct Region *, __p0, a0, \
		CONST struct Rectangle *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetRGB32CM(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(996, SetRGB32CM, \
		struct ColorMap *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Draw(__p0, __p1, __p2) \
	LP3NR(246, Draw, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetBPen(__p0, __p1) \
	LP2NR(348, SetBPen, \
		struct RastPort *, __p0, a1, \
		ULONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OrRectRegion(__p0, __p1) \
	LP2(510, BOOL , OrRectRegion, \
		struct Region *, __p0, a0, \
		CONST struct Rectangle *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetExtSpriteA(__p0, __p1) \
	LP2(930, LONG , GetExtSpriteA, \
		struct ExtSprite *, __p0, a2, \
		CONST struct TagItem *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitTmpRas(__p0, __p1, __p2) \
	LP3(468, struct TmpRas *, InitTmpRas, \
		struct TmpRas *, __p0, a0, \
		PLANEPTR , __p1, a1, \
		LONG , __p2, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GfxAssociate(__p0, __p1) \
	LP2NR(672, GfxAssociate, \
		CONST APTR , __p0, a0, \
		APTR , __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OpenMonitor(__p0, __p1) \
	LP2(714, struct MonitorSpec *, OpenMonitor, \
		CONST_STRPTR , __p0, a1, \
		ULONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitView(__p0) \
	LP1NR(360, InitView, \
		struct View *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ObtainPen(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6(954, ULONG , ObtainPen, \
		struct ColorMap *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		LONG , __p5, d4, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetGBuffers(__p0, __p1, __p2) \
	LP3(168, BOOL , GetGBuffers, \
		struct AnimOb *, __p0, a0, \
		struct RastPort *, __p1, a1, \
		LONG , __p2, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define QBlit(__p0) \
	LP1NR(276, QBlit, \
		struct bltnode *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define GetRGB4(__p0, __p1) \
	LP2(582, ULONG , GetRGB4, \
		struct ColorMap *, __p0, a0, \
		LONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeSprite(__p0) \
	LP1NR(414, FreeSprite, \
		LONG , __p0, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ChangeExtSpriteA(__p0, __p1, __p2, __p3) \
	LP4(1026, LONG , ChangeExtSpriteA, \
		struct ViewPort *, __p0, a0, \
		struct ExtSprite *, __p1, a1, \
		struct ExtSprite *, __p2, a2, \
		CONST struct TagItem *, __p3, a3, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AreaEllipse(__p0, __p1, __p2, __p3, __p4) \
	LP5(186, LONG , AreaEllipse, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddBob(__p0, __p1) \
	LP2NR(96, AddBob, \
		struct Bob *, __p0, a0, \
		struct RastPort *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define OwnBlitter() \
	LP0NR(456, OwnBlitter, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define StripFont(__p0) \
	LP1NR(822, StripFont, \
		struct TextFont *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CWait(__p0, __p1, __p2) \
	LP3NR(378, CWait, \
		struct UCopList *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ScalerDiv(__p0, __p1, __p2) \
	LP3(684, UWORD , ScalerDiv, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		ULONG , __p2, d2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define VideoControl(__p0, __p1) \
	LP2(708, BOOL , VideoControl, \
		struct ColorMap *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DisposeRegion(__p0) \
	LP1NR(534, DisposeRegion, \
		struct Region *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TextExtent(__p0, __p1, __p2, __p3) \
	LP4(690, WORD , TextExtent, \
		struct RastPort *, __p0, a1, \
		CONST_STRPTR , __p1, a0, \
		LONG , __p2, d0, \
		struct TextExtent *, __p3, a2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeBitMap(__p0) \
	LP1NR(924, FreeBitMap, \
		struct BitMap *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define NewRegion() \
	LP0(516, struct Region *, NewRegion, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Flood(__p0, __p1, __p2, __p3) \
	LP4(330, BOOL , Flood, \
		struct RastPort *, __p0, a1, \
		ULONG , __p1, d2, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MoveSprite(__p0, __p1, __p2, __p3) \
	LP4NR(426, MoveSprite, \
		struct ViewPort *, __p0, a0, \
		struct SimpleSprite *, __p1, a1, \
		LONG , __p2, d0, \
		LONG , __p3, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetChipRev(__p0) \
	LP1(888, ULONG , SetChipRev, \
		ULONG , __p0, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadPixelArray8(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7(780, LONG , ReadPixelArray8, \
		struct RastPort *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		UBYTE *, __p5, a2, \
		struct RastPort *, __p6, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BestModeIDA(__p0) \
	LP1(1050, ULONG , BestModeIDA, \
		CONST struct TagItem *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DoCollision(__p0) \
	LP1NR(108, DoCollision, \
		struct RastPort *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetABPenDrMd(__p0, __p1, __p2, __p3) \
	LP4NR(894, SetABPenDrMd, \
		struct RastPort *, __p0, a1, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddAnimOb(__p0, __p1, __p2) \
	LP3NR(156, AddAnimOb, \
		struct AnimOb *, __p0, a0, \
		struct AnimOb **, __p1, a1, \
		struct RastPort *, __p2, a2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetBPen(__p0) \
	LP1(864, ULONG , GetBPen, \
		struct RastPort *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WriteChunkyPixels(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7NR(1056, WriteChunkyPixels, \
		struct RastPort *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		CONST UBYTE *, __p5, a2, \
		LONG , __p6, d4, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RectFill(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(306, RectFill, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetOutlinePen(__p0) \
	LP1(876, ULONG , GetOutlinePen, \
		struct RastPort *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SortGList(__p0) \
	LP1NR(150, SortGList, \
		struct RastPort *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeRaster(__p0, __p1, __p2) \
	LP3NR(498, FreeRaster, \
		PLANEPTR , __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ClearScreen(__p0) \
	LP1NR(48, ClearScreen, \
		struct RastPort *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BltBitMapRastPort(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	LP9NR(606, BltBitMapRastPort, \
		CONST struct BitMap *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		struct RastPort *, __p3, a1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		LONG , __p7, d5, \
		ULONG , __p8, d6, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindDisplayInfo(__p0) \
	LP1(726, DisplayInfoHandle , FindDisplayInfo, \
		ULONG , __p0, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define TextLength(__p0, __p1, __p2) \
	LP3(54, WORD , TextLength, \
		struct RastPort *, __p0, a1, \
		CONST_STRPTR , __p1, a0, \
		ULONG , __p2, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BitMapScale(__p0) \
	LP1NR(678, BitMapScale, \
		struct BitScaleArgs *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetDisplayInfoData(__p0, __p1, __p2, __p3, __p4) \
	LP5(756, ULONG , GetDisplayInfoData, \
		CONST DisplayInfoHandle , __p0, a0, \
		APTR , __p1, a1, \
		ULONG , __p2, d0, \
		ULONG , __p3, d1, \
		ULONG , __p4, d2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetWriteMask(__p0, __p1) \
	LP2(984, ULONG , SetWriteMask, \
		struct RastPort *, __p0, a0, \
		ULONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CoerceMode(__p0, __p1, __p2) \
	LP3(936, ULONG , CoerceMode, \
		struct ViewPort *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CalcIVG(__p0, __p1) \
	LP2(828, UWORD , CalcIVG, \
		struct View *, __p0, a0, \
		struct ViewPort *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ClearEOL(__p0) \
	LP1NR(42, ClearEOL, \
		struct RastPort *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetAPen(__p0, __p1) \
	LP2NR(342, SetAPen, \
		struct RastPort *, __p0, a1, \
		ULONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetColorMap(__p0) \
	LP1(570, struct ColorMap *, GetColorMap, \
		LONG , __p0, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SyncSBitMap(__p0) \
	LP1NR(444, SyncSBitMap, \
		struct Layer *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitRastPort(__p0) \
	LP1NR(198, InitRastPort, \
		struct RastPort *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LoadRGB32(__p0, __p1) \
	LP2NR(882, LoadRGB32, \
		struct ViewPort *, __p0, a0, \
		CONST ULONG *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CBump(__p0) \
	LP1NR(366, CBump, \
		struct UCopList *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Text(__p0, __p1, __p2) \
	LP3(60, LONG , Text, \
		struct RastPort *, __p0, a1, \
		CONST_STRPTR , __p1, a0, \
		ULONG , __p2, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeGBuffers(__p0, __p1, __p2) \
	LP3NR(600, FreeGBuffers, \
		struct AnimOb *, __p0, a0, \
		struct RastPort *, __p1, a1, \
		LONG , __p2, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetFont(__p0, __p1) \
	LP2(66, LONG , SetFont, \
		struct RastPort *, __p0, a1, \
		CONST struct TextFont *, __p1, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AreaMove(__p0, __p1, __p2) \
	LP3(252, LONG , AreaMove, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetMaxPen(__p0, __p1) \
	LP2NR(990, SetMaxPen, \
		struct RastPort *, __p0, a0, \
		ULONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ClearRegion(__p0) \
	LP1NR(528, ClearRegion, \
		struct Region *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ChangeSprite(__p0, __p1, __p2) \
	LP3NR(420, ChangeSprite, \
		struct ViewPort *, __p0, a0, \
		struct SimpleSprite *, __p1, a1, \
		UWORD *, __p2, a2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ChangeVPBitMap(__p0, __p1, __p2) \
	LP3NR(942, ChangeVPBitMap, \
		struct ViewPort *, __p0, a0, \
		struct BitMap *, __p1, a1, \
		struct DBufInfo *, __p2, a2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetRGB32(__p0, __p1, __p2, __p3) \
	LP4NR(900, GetRGB32, \
		CONST struct ColorMap *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG *, __p3, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define EraseRect(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(810, EraseRect, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitGMasks(__p0) \
	LP1NR(174, InitGMasks, \
		struct AnimOb *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GfxLookUp(__p0) \
	LP1(702, APTR , GfxLookUp, \
		CONST APTR , __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddFont(__p0) \
	LP1NR(480, AddFont, \
		struct TextFont *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GfxFree(__p0) \
	LP1NR(666, GfxFree, \
		APTR , __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseFont(__p0) \
	LP1NR(78, CloseFont, \
		struct TextFont *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define InitArea(__p0, __p1, __p2) \
	LP3NR(282, InitArea, \
		struct AreaInfo *, __p0, a0, \
		APTR , __p1, a1, \
		LONG , __p2, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetSprite(__p0, __p1) \
	LP2(408, WORD , GetSprite, \
		struct SimpleSprite *, __p0, a0, \
		LONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeDBufInfo(__p0) \
	LP1NR(972, FreeDBufInfo, \
		struct DBufInfo *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define UCopperListInit(__p0, __p1) \
	LP2(594, struct CopList *, UCopperListInit, \
		struct UCopList *, __p0, a0, \
		LONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WaitBlit() \
	LP0NR(228, WaitBlit, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadPixelLine8(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6(768, LONG , ReadPixelLine8, \
		struct RastPort *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		UBYTE *, __p4, a2, \
		struct RastPort *, __p5, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DrawGList(__p0, __p1) \
	LP2NR(114, DrawGList, \
		struct RastPort *, __p0, a1, \
		struct ViewPort *, __p1, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DrawEllipse(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(180, DrawEllipse, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define MrgCop(__p0) \
	LP1(210, ULONG , MrgCop, \
		struct View *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AskSoftStyle(__p0) \
	LP1(84, ULONG , AskSoftStyle, \
		struct RastPort *, __p0, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)


#define FreeCopList(__p0) \
	LP1NR(546, FreeCopList, \
		struct CopList *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetAPen(__p0) \
	LP1(858, ULONG , GetAPen, \
		struct RastPort *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FindColor(__p0, __p1, __p2, __p3, __p4) \
	LP5(1008, LONG , FindColor, \
		struct ColorMap *, __p0, a3, \
		ULONG , __p1, d1, \
		ULONG , __p2, d2, \
		ULONG , __p3, d3, \
		LONG , __p4, d4, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AndRectRegion(__p0, __p1) \
	LP2NR(504, AndRectRegion, \
		struct Region *, __p0, a0, \
		CONST struct Rectangle *, __p1, a1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define BltClear(__p0, __p1, __p2) \
	LP3NR(300, BltClear, \
		PLANEPTR , __p0, a1, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ReadPixel(__p0, __p1, __p2) \
	LP3(318, ULONG , ReadPixel, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetCollision(__p0, __p1, __p2) \
	LP3NRFP(144, SetCollision, \
		ULONG , __p0, d0, \
		__ft, __p1, a0, \
		struct GelsInfo *, __p2, a1, \
		, GRAPHICS_BASE_NAME, VOID (* __ft) __CLIB_PROTOTYPE((struct VSprite *gelA,struct VSprite *gelB)), 0, 0, 0, 0, 0, 0)

#define BltBitMap(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10) \
	LP11(30, LONG , BltBitMap, \
		CONST struct BitMap *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		struct BitMap *, __p3, a1, \
		LONG , __p4, d2, \
		LONG , __p5, d3, \
		LONG , __p6, d4, \
		LONG , __p7, d5, \
		ULONG , __p8, d6, \
		ULONG , __p9, d7, \
		PLANEPTR , __p10, a2, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define Move(__p0, __p1, __p2) \
	LP3NR(240, Move, \
		struct RastPort *, __p0, a1, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetVPModeID(__p0) \
	LP1(792, LONG , GetVPModeID, \
		CONST struct ViewPort *, __p0, a0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define SetDrMd(__p0, __p1) \
	LP2NR(354, SetDrMd, \
		struct RastPort *, __p0, a1, \
		ULONG , __p1, d0, \
		, GRAPHICS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define SetRPAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	SetRPAttrsA(__p0, (CONST struct TagItem *)_tags);})

#define GetRPAttrs(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetRPAttrsA(__p0, (CONST struct TagItem *)_tags);})

#define WeighTAMatchTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	WeighTAMatch(__p0, __p1, (struct TagItem *)_tags);})

#define ExtendFontTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ExtendFont(__p0, (CONST struct TagItem *)_tags);})

#define ObtainBestPen(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ObtainBestPenA(__p0, __p1, __p2, __p3, (CONST struct TagItem *)_tags);})

#define BestModeID(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	BestModeIDA((CONST struct TagItem *)_tags);})

#define VideoControlTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	VideoControl(__p0, (struct TagItem *)_tags);})

#define AllocSpriteData(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AllocSpriteDataA(__p0, (CONST struct TagItem *)_tags);})

#define GetExtSprite(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetExtSpriteA(__p0, (CONST struct TagItem *)_tags);})

#define ChangeExtSprite(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ChangeExtSpriteA(__p0, __p1, __p2, (CONST struct TagItem *)_tags);})

#define OpenFontTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	OpenFontTagList(__p0, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_GRAPHICS_H */
