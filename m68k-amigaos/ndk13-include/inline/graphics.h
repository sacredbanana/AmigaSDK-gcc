/* Automatically generated header (sfdc 1.11e)! Do not edit! */

#ifndef _INLINE_GRAPHICS_H
#define _INLINE_GRAPHICS_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

#ifndef __INLINE_MACROS_H
#include <inline/macros.h>
#endif /* !__INLINE_MACROS_H */

#ifndef GRAPHICS_BASE_NAME
#define GRAPHICS_BASE_NAME GfxBase
#endif /* !GRAPHICS_BASE_NAME */

#define BltBitMap(___srcBitMap, ___xSrc, ___ySrc, ___destBitMap, ___xDest, ___yDest, ___xSize, ___ySize, ___minterm, ___mask, ___tempA) \
      LP11(0x1e, LONG, BltBitMap , CONST struct BitMap *, ___srcBitMap, a0, LONG, ___xSrc, d0, LONG, ___ySrc, d1, struct BitMap *, ___destBitMap, a1, LONG, ___xDest, d2, LONG, ___yDest, d3, LONG, ___xSize, d4, LONG, ___ySize, d5, ULONG, ___minterm, d6, ULONG, ___mask, d7, PLANEPTR, ___tempA, a2,\
      , GRAPHICS_BASE_NAME)

#define BltTemplate(___source, ___xSrc, ___srcMod, ___destRP, ___xDest, ___yDest, ___xSize, ___ySize) \
      LP8NR(0x24, BltTemplate , CONST PLANEPTR, ___source, a0, LONG, ___xSrc, d0, LONG, ___srcMod, d1, struct RastPort *, ___destRP, a1, LONG, ___xDest, d2, LONG, ___yDest, d3, LONG, ___xSize, d4, LONG, ___ySize, d5,\
      , GRAPHICS_BASE_NAME)

#define ClearEOL(___rp) \
      LP1NR(0x2a, ClearEOL , struct RastPort *, ___rp, a1,\
      , GRAPHICS_BASE_NAME)

#define ClearScreen(___rp) \
      LP1NR(0x30, ClearScreen , struct RastPort *, ___rp, a1,\
      , GRAPHICS_BASE_NAME)

#define TextLength(___rp, ___string, ___count) \
      LP3(0x36, WORD, TextLength , struct RastPort *, ___rp, a1, CONST_STRPTR, ___string, a0, ULONG, ___count, d0,\
      , GRAPHICS_BASE_NAME)

#define Text(___rp, ___string, ___count) \
      LP3(0x3c, LONG, Text , struct RastPort *, ___rp, a1, CONST_STRPTR, ___string, a0, ULONG, ___count, d0,\
      , GRAPHICS_BASE_NAME)

#define SetFont(___rp, ___textFont) \
      LP2(0x42, LONG, SetFont , struct RastPort *, ___rp, a1, struct TextFont *, ___textFont, a0,\
      , GRAPHICS_BASE_NAME)

#define OpenFont(___textAttr) \
      LP1(0x48, struct TextFont *, OpenFont , CONST struct TextAttr *, ___textAttr, a0,\
      , GRAPHICS_BASE_NAME)

#define CloseFont(___textFont) \
      LP1NR(0x4e, CloseFont , struct TextFont *, ___textFont, a1,\
      , GRAPHICS_BASE_NAME)

#define AskSoftStyle(___rp) \
      LP1(0x54, ULONG, AskSoftStyle , struct RastPort *, ___rp, a1,\
      , GRAPHICS_BASE_NAME)

#define SetSoftStyle(___rp, ___style, ___enable) \
      LP3(0x5a, ULONG, SetSoftStyle , struct RastPort *, ___rp, a1, ULONG, ___style, d0, ULONG, ___enable, d1,\
      , GRAPHICS_BASE_NAME)

#define AddBob(___bob, ___rp) \
      LP2NR(0x60, AddBob , struct Bob *, ___bob, a0, struct RastPort *, ___rp, a1,\
      , GRAPHICS_BASE_NAME)

#define AddVSprite(___vSprite, ___rp) \
      LP2NR(0x66, AddVSprite , struct VSprite *, ___vSprite, a0, struct RastPort *, ___rp, a1,\
      , GRAPHICS_BASE_NAME)

#define DoCollision(___rp) \
      LP1NR(0x6c, DoCollision , struct RastPort *, ___rp, a1,\
      , GRAPHICS_BASE_NAME)

#define DrawGList(___rp, ___vp) \
      LP2NR(0x72, DrawGList , struct RastPort *, ___rp, a1, struct ViewPort *, ___vp, a0,\
      , GRAPHICS_BASE_NAME)

#define InitGels(___head, ___tail, ___gelsInfo) \
      LP3NR(0x78, InitGels , struct VSprite *, ___head, a0, struct VSprite *, ___tail, a1, struct GelsInfo *, ___gelsInfo, a2,\
      , GRAPHICS_BASE_NAME)

#define InitMasks(___vSprite) \
      LP1NR(0x7e, InitMasks , struct VSprite *, ___vSprite, a0,\
      , GRAPHICS_BASE_NAME)

#define RemIBob(___bob, ___rp, ___vp) \
      LP3NR(0x84, RemIBob , struct Bob *, ___bob, a0, struct RastPort *, ___rp, a1, struct ViewPort *, ___vp, a2,\
      , GRAPHICS_BASE_NAME)

#define RemVSprite(___vSprite) \
      LP1NR(0x8a, RemVSprite , struct VSprite *, ___vSprite, a0,\
      , GRAPHICS_BASE_NAME)

#define SetCollision(___num, ___routine, ___gelsInfo) \
      LP3NRFP(0x90, SetCollision , ULONG, ___num, d0, __fpt, ___routine, a0, struct GelsInfo *, ___gelsInfo, a1,\
      , GRAPHICS_BASE_NAME, VOID (*__fpt)(struct VSprite * gelA,struct VSprite * gelB))

#define SortGList(___rp) \
      LP1NR(0x96, SortGList , struct RastPort *, ___rp, a1,\
      , GRAPHICS_BASE_NAME)

#define AddAnimOb(___anOb, ___anKey, ___rp) \
      LP3NR(0x9c, AddAnimOb , struct AnimOb *, ___anOb, a0, struct AnimOb * *, ___anKey, a1, struct RastPort *, ___rp, a2,\
      , GRAPHICS_BASE_NAME)

#define Animate(___anKey, ___rp) \
      LP2NR(0xa2, Animate , struct AnimOb * *, ___anKey, a0, struct RastPort *, ___rp, a1,\
      , GRAPHICS_BASE_NAME)

#define GetGBuffers(___anOb, ___rp, ___flag) \
      LP3(0xa8, BOOL, GetGBuffers , struct AnimOb *, ___anOb, a0, struct RastPort *, ___rp, a1, LONG, ___flag, d0,\
      , GRAPHICS_BASE_NAME)

#define InitGMasks(___anOb) \
      LP1NR(0xae, InitGMasks , struct AnimOb *, ___anOb, a0,\
      , GRAPHICS_BASE_NAME)

#define DrawEllipse(___rp, ___xCenter, ___yCenter, ___a, ___b) \
      LP5NR(0xb4, DrawEllipse , struct RastPort *, ___rp, a1, LONG, ___xCenter, d0, LONG, ___yCenter, d1, LONG, ___a, d2, LONG, ___b, d3,\
      , GRAPHICS_BASE_NAME)

#define AreaEllipse(___rp, ___xCenter, ___yCenter, ___a, ___b) \
      LP5(0xba, LONG, AreaEllipse , struct RastPort *, ___rp, a1, LONG, ___xCenter, d0, LONG, ___yCenter, d1, LONG, ___a, d2, LONG, ___b, d3,\
      , GRAPHICS_BASE_NAME)

#define LoadRGB4(___vp, ___colors, ___count) \
      LP3NR(0xc0, LoadRGB4 , struct ViewPort *, ___vp, a0, CONST UWORD *, ___colors, a1, LONG, ___count, d0,\
      , GRAPHICS_BASE_NAME)

#define InitRastPort(___rp) \
      LP1NR(0xc6, InitRastPort , struct RastPort *, ___rp, a1,\
      , GRAPHICS_BASE_NAME)

#define InitVPort(___vp) \
      LP1NR(0xcc, InitVPort , struct ViewPort *, ___vp, a0,\
      , GRAPHICS_BASE_NAME)

#define MrgCop(___view) \
      LP1(0xd2, ULONG, MrgCop , struct View *, ___view, a1,\
      , GRAPHICS_BASE_NAME)

#define MakeVPort(___view, ___vp) \
      LP2(0xd8, ULONG, MakeVPort , struct View *, ___view, a0, struct ViewPort *, ___vp, a1,\
      , GRAPHICS_BASE_NAME)

#define LoadView(___view) \
      LP1NR(0xde, LoadView , struct View *, ___view, a1,\
      , GRAPHICS_BASE_NAME)

#define WaitBlit() \
      LP0NR(0xe4, WaitBlit ,\
      , GRAPHICS_BASE_NAME)

#define SetRast(___rp, ___pen) \
      LP2NR(0xea, SetRast , struct RastPort *, ___rp, a1, ULONG, ___pen, d0,\
      , GRAPHICS_BASE_NAME)

#define Move(___rp, ___x, ___y) \
      LP3NR(0xf0, Move , struct RastPort *, ___rp, a1, LONG, ___x, d0, LONG, ___y, d1,\
      , GRAPHICS_BASE_NAME)

#define Draw(___rp, ___x, ___y) \
      LP3NR(0xf6, Draw , struct RastPort *, ___rp, a1, LONG, ___x, d0, LONG, ___y, d1,\
      , GRAPHICS_BASE_NAME)

#define AreaMove(___rp, ___x, ___y) \
      LP3(0xfc, LONG, AreaMove , struct RastPort *, ___rp, a1, LONG, ___x, d0, LONG, ___y, d1,\
      , GRAPHICS_BASE_NAME)

#define AreaDraw(___rp, ___x, ___y) \
      LP3(0x102, LONG, AreaDraw , struct RastPort *, ___rp, a1, LONG, ___x, d0, LONG, ___y, d1,\
      , GRAPHICS_BASE_NAME)

#define AreaEnd(___rp) \
      LP1(0x108, LONG, AreaEnd , struct RastPort *, ___rp, a1,\
      , GRAPHICS_BASE_NAME)

#define WaitTOF() \
      LP0NR(0x10e, WaitTOF ,\
      , GRAPHICS_BASE_NAME)

#define QBlit(___blit) \
      LP1NR(0x114, QBlit , struct bltnode *, ___blit, a1,\
      , GRAPHICS_BASE_NAME)

#define InitArea(___areaInfo, ___vectorBuffer, ___maxVectors) \
      LP3NR(0x11a, InitArea , struct AreaInfo *, ___areaInfo, a0, APTR, ___vectorBuffer, a1, LONG, ___maxVectors, d0,\
      , GRAPHICS_BASE_NAME)

#define SetRGB4(___vp, ___index, ___red, ___green, ___blue) \
      LP5NR(0x120, SetRGB4 , struct ViewPort *, ___vp, a0, LONG, ___index, d0, ULONG, ___red, d1, ULONG, ___green, d2, ULONG, ___blue, d3,\
      , GRAPHICS_BASE_NAME)

#define QBSBlit(___blit) \
      LP1NR(0x126, QBSBlit , struct bltnode *, ___blit, a1,\
      , GRAPHICS_BASE_NAME)

#define BltClear(___memBlock, ___byteCount, ___flags) \
      LP3NR(0x12c, BltClear , PLANEPTR, ___memBlock, a1, ULONG, ___byteCount, d0, ULONG, ___flags, d1,\
      , GRAPHICS_BASE_NAME)

#define RectFill(___rp, ___xMin, ___yMin, ___xMax, ___yMax) \
      LP5NR(0x132, RectFill , struct RastPort *, ___rp, a1, LONG, ___xMin, d0, LONG, ___yMin, d1, LONG, ___xMax, d2, LONG, ___yMax, d3,\
      , GRAPHICS_BASE_NAME)

#define BltPattern(___rp, ___mask, ___xMin, ___yMin, ___xMax, ___yMax, ___maskBPR) \
      LP7NR(0x138, BltPattern , struct RastPort *, ___rp, a1, CONST PLANEPTR, ___mask, a0, LONG, ___xMin, d0, LONG, ___yMin, d1, LONG, ___xMax, d2, LONG, ___yMax, d3, ULONG, ___maskBPR, d4,\
      , GRAPHICS_BASE_NAME)

#define ReadPixel(___rp, ___x, ___y) \
      LP3(0x13e, ULONG, ReadPixel , struct RastPort *, ___rp, a1, LONG, ___x, d0, LONG, ___y, d1,\
      , GRAPHICS_BASE_NAME)

#define WritePixel(___rp, ___x, ___y) \
      LP3(0x144, LONG, WritePixel , struct RastPort *, ___rp, a1, LONG, ___x, d0, LONG, ___y, d1,\
      , GRAPHICS_BASE_NAME)

#define Flood(___rp, ___mode, ___x, ___y) \
      LP4(0x14a, BOOL, Flood , struct RastPort *, ___rp, a1, ULONG, ___mode, d2, LONG, ___x, d0, LONG, ___y, d1,\
      , GRAPHICS_BASE_NAME)

#define PolyDraw(___rp, ___count, ___polyTable) \
      LP3NR(0x150, PolyDraw , struct RastPort *, ___rp, a1, LONG, ___count, d0, CONST WORD *, ___polyTable, a0,\
      , GRAPHICS_BASE_NAME)

#define SetAPen(___rp, ___pen) \
      LP2NR(0x156, SetAPen , struct RastPort *, ___rp, a1, ULONG, ___pen, d0,\
      , GRAPHICS_BASE_NAME)

#define SetBPen(___rp, ___pen) \
      LP2NR(0x15c, SetBPen , struct RastPort *, ___rp, a1, ULONG, ___pen, d0,\
      , GRAPHICS_BASE_NAME)

#define SetDrMd(___rp, ___drawMode) \
      LP2NR(0x162, SetDrMd , struct RastPort *, ___rp, a1, ULONG, ___drawMode, d0,\
      , GRAPHICS_BASE_NAME)

#define InitView(___view) \
      LP1NR(0x168, InitView , struct View *, ___view, a1,\
      , GRAPHICS_BASE_NAME)

#define CBump(___copList) \
      LP1NR(0x16e, CBump , struct UCopList *, ___copList, a1,\
      , GRAPHICS_BASE_NAME)

#define CMove(___copList, ___destination, ___data) \
      LP3(0x174, LONG, CMove , struct UCopList *, ___copList, a1, APTR, ___destination, d0, LONG, ___data, d1,\
      , GRAPHICS_BASE_NAME)

#define CWait(___copList, ___v, ___h) \
      LP3(0x17a, LONG, CWait , struct UCopList *, ___copList, a1, LONG, ___v, d0, LONG, ___h, d1,\
      , GRAPHICS_BASE_NAME)

#define VBeamPos() \
      LP0(0x180, LONG, VBeamPos ,\
      , GRAPHICS_BASE_NAME)

#define InitBitMap(___bitMap, ___depth, ___width, ___height) \
      LP4NR(0x186, InitBitMap , struct BitMap *, ___bitMap, a0, LONG, ___depth, d0, LONG, ___width, d1, LONG, ___height, d2,\
      , GRAPHICS_BASE_NAME)

#define ScrollRaster(___rp, ___dx, ___dy, ___xMin, ___yMin, ___xMax, ___yMax) \
      LP7NR(0x18c, ScrollRaster , struct RastPort *, ___rp, a1, LONG, ___dx, d0, LONG, ___dy, d1, LONG, ___xMin, d2, LONG, ___yMin, d3, LONG, ___xMax, d4, LONG, ___yMax, d5,\
      , GRAPHICS_BASE_NAME)

#define WaitBOVP(___vp) \
      LP1NR(0x192, WaitBOVP , struct ViewPort *, ___vp, a0,\
      , GRAPHICS_BASE_NAME)

#define GetSprite(___sprite, ___num) \
      LP2(0x198, WORD, GetSprite , struct SimpleSprite *, ___sprite, a0, LONG, ___num, d0,\
      , GRAPHICS_BASE_NAME)

#define FreeSprite(___num) \
      LP1NR(0x19e, FreeSprite , LONG, ___num, d0,\
      , GRAPHICS_BASE_NAME)

#define ChangeSprite(___vp, ___sprite, ___newData) \
      LP3NR(0x1a4, ChangeSprite , struct ViewPort *, ___vp, a0, struct SimpleSprite *, ___sprite, a1, UWORD *, ___newData, a2,\
      , GRAPHICS_BASE_NAME)

#define MoveSprite(___vp, ___sprite, ___x, ___y) \
      LP4NR(0x1aa, MoveSprite , struct ViewPort *, ___vp, a0, struct SimpleSprite *, ___sprite, a1, LONG, ___x, d0, LONG, ___y, d1,\
      , GRAPHICS_BASE_NAME)

#define LockLayerRom(___layer) \
      LP1NRA5(0x1b0, LockLayerRom , struct Layer *, ___layer, d7,\
      , GRAPHICS_BASE_NAME)

#define UnlockLayerRom(___layer) \
      LP1NRA5(0x1b6, UnlockLayerRom , struct Layer *, ___layer, d7,\
      , GRAPHICS_BASE_NAME)

#define SyncSBitMap(___layer) \
      LP1NR(0x1bc, SyncSBitMap , struct Layer *, ___layer, a0,\
      , GRAPHICS_BASE_NAME)

#define CopySBitMap(___layer) \
      LP1NR(0x1c2, CopySBitMap , struct Layer *, ___layer, a0,\
      , GRAPHICS_BASE_NAME)

#define OwnBlitter() \
      LP0NR(0x1c8, OwnBlitter ,\
      , GRAPHICS_BASE_NAME)

#define DisownBlitter() \
      LP0NR(0x1ce, DisownBlitter ,\
      , GRAPHICS_BASE_NAME)

#define InitTmpRas(___tmpRas, ___buffer, ___size) \
      LP3(0x1d4, struct TmpRas *, InitTmpRas , struct TmpRas *, ___tmpRas, a0, PLANEPTR, ___buffer, a1, LONG, ___size, d0,\
      , GRAPHICS_BASE_NAME)

#define AskFont(___rp, ___textAttr) \
      LP2NR(0x1da, AskFont , struct RastPort *, ___rp, a1, struct TextAttr *, ___textAttr, a0,\
      , GRAPHICS_BASE_NAME)

#define AddFont(___textFont) \
      LP1NR(0x1e0, AddFont , struct TextFont *, ___textFont, a1,\
      , GRAPHICS_BASE_NAME)

#define RemFont(___textFont) \
      LP1NR(0x1e6, RemFont , struct TextFont *, ___textFont, a1,\
      , GRAPHICS_BASE_NAME)

#define AllocRaster(___width, ___height) \
      LP2(0x1ec, PLANEPTR, AllocRaster , ULONG, ___width, d0, ULONG, ___height, d1,\
      , GRAPHICS_BASE_NAME)

#define FreeRaster(___p, ___width, ___height) \
      LP3NR(0x1f2, FreeRaster , PLANEPTR, ___p, a0, ULONG, ___width, d0, ULONG, ___height, d1,\
      , GRAPHICS_BASE_NAME)

#define AndRectRegion(___region, ___rectangle) \
      LP2NR(0x1f8, AndRectRegion , struct Region *, ___region, a0, CONST struct Rectangle *, ___rectangle, a1,\
      , GRAPHICS_BASE_NAME)

#define OrRectRegion(___region, ___rectangle) \
      LP2(0x1fe, BOOL, OrRectRegion , struct Region *, ___region, a0, CONST struct Rectangle *, ___rectangle, a1,\
      , GRAPHICS_BASE_NAME)

#define NewRegion() \
      LP0(0x204, struct Region *, NewRegion ,\
      , GRAPHICS_BASE_NAME)

#define ClearRectRegion(___region, ___rectangle) \
      LP2(0x20a, BOOL, ClearRectRegion , struct Region *, ___region, a0, CONST struct Rectangle *, ___rectangle, a1,\
      , GRAPHICS_BASE_NAME)

#define ClearRegion(___region) \
      LP1NR(0x210, ClearRegion , struct Region *, ___region, a0,\
      , GRAPHICS_BASE_NAME)

#define DisposeRegion(___region) \
      LP1NR(0x216, DisposeRegion , struct Region *, ___region, a0,\
      , GRAPHICS_BASE_NAME)

#define FreeVPortCopLists(___vp) \
      LP1NR(0x21c, FreeVPortCopLists , struct ViewPort *, ___vp, a0,\
      , GRAPHICS_BASE_NAME)

#define FreeCopList(___copList) \
      LP1NR(0x222, FreeCopList , struct CopList *, ___copList, a0,\
      , GRAPHICS_BASE_NAME)

#define ClipBlit(___srcRP, ___xSrc, ___ySrc, ___destRP, ___xDest, ___yDest, ___xSize, ___ySize, ___minterm) \
      LP9NR(0x228, ClipBlit , struct RastPort *, ___srcRP, a0, LONG, ___xSrc, d0, LONG, ___ySrc, d1, struct RastPort *, ___destRP, a1, LONG, ___xDest, d2, LONG, ___yDest, d3, LONG, ___xSize, d4, LONG, ___ySize, d5, ULONG, ___minterm, d6,\
      , GRAPHICS_BASE_NAME)

#define XorRectRegion(___region, ___rectangle) \
      LP2(0x22e, BOOL, XorRectRegion , struct Region *, ___region, a0, CONST struct Rectangle *, ___rectangle, a1,\
      , GRAPHICS_BASE_NAME)

#define FreeCprList(___cprList) \
      LP1NR(0x234, FreeCprList , struct cprlist *, ___cprList, a0,\
      , GRAPHICS_BASE_NAME)

#define GetColorMap(___entries) \
      LP1(0x23a, struct ColorMap *, GetColorMap , LONG, ___entries, d0,\
      , GRAPHICS_BASE_NAME)

#define FreeColorMap(___colorMap) \
      LP1NR(0x240, FreeColorMap , struct ColorMap *, ___colorMap, a0,\
      , GRAPHICS_BASE_NAME)

#define GetRGB4(___colorMap, ___entry) \
      LP2(0x246, ULONG, GetRGB4 , struct ColorMap *, ___colorMap, a0, LONG, ___entry, d0,\
      , GRAPHICS_BASE_NAME)

#define ScrollVPort(___vp) \
      LP1NR(0x24c, ScrollVPort , struct ViewPort *, ___vp, a0,\
      , GRAPHICS_BASE_NAME)

#define UCopperListInit(___uCopList, ___n) \
      LP2(0x252, struct CopList *, UCopperListInit , struct UCopList *, ___uCopList, a0, LONG, ___n, d0,\
      , GRAPHICS_BASE_NAME)

#define FreeGBuffers(___anOb, ___rp, ___flag) \
      LP3NR(0x258, FreeGBuffers , struct AnimOb *, ___anOb, a0, struct RastPort *, ___rp, a1, LONG, ___flag, d0,\
      , GRAPHICS_BASE_NAME)

#define BltBitMapRastPort(___srcBitMap, ___xSrc, ___ySrc, ___destRP, ___xDest, ___yDest, ___xSize, ___ySize, ___minterm) \
      LP9NR(0x25e, BltBitMapRastPort , CONST struct BitMap *, ___srcBitMap, a0, LONG, ___xSrc, d0, LONG, ___ySrc, d1, struct RastPort *, ___destRP, a1, LONG, ___xDest, d2, LONG, ___yDest, d3, LONG, ___xSize, d4, LONG, ___ySize, d5, ULONG, ___minterm, d6,\
      , GRAPHICS_BASE_NAME)

#define OrRegionRegion(___srcRegion, ___destRegion) \
      LP2(0x264, BOOL, OrRegionRegion , CONST struct Region *, ___srcRegion, a0, struct Region *, ___destRegion, a1,\
      , GRAPHICS_BASE_NAME)

#define XorRegionRegion(___srcRegion, ___destRegion) \
      LP2(0x26a, BOOL, XorRegionRegion , CONST struct Region *, ___srcRegion, a0, struct Region *, ___destRegion, a1,\
      , GRAPHICS_BASE_NAME)

#define AndRegionRegion(___srcRegion, ___destRegion) \
      LP2(0x270, BOOL, AndRegionRegion , CONST struct Region *, ___srcRegion, a0, struct Region *, ___destRegion, a1,\
      , GRAPHICS_BASE_NAME)

#define SetRGB4CM(___colorMap, ___index, ___red, ___green, ___blue) \
      LP5NR(0x276, SetRGB4CM , struct ColorMap *, ___colorMap, a0, LONG, ___index, d0, ULONG, ___red, d1, ULONG, ___green, d2, ULONG, ___blue, d3,\
      , GRAPHICS_BASE_NAME)

#define BltMaskBitMapRastPort(___srcBitMap, ___xSrc, ___ySrc, ___destRP, ___xDest, ___yDest, ___xSize, ___ySize, ___minterm, ___bltMask) \
      LP10NR(0x27c, BltMaskBitMapRastPort , CONST struct BitMap *, ___srcBitMap, a0, LONG, ___xSrc, d0, LONG, ___ySrc, d1, struct RastPort *, ___destRP, a1, LONG, ___xDest, d2, LONG, ___yDest, d3, LONG, ___xSize, d4, LONG, ___ySize, d5, ULONG, ___minterm, d6, CONST PLANEPTR, ___bltMask, a2,\
      , GRAPHICS_BASE_NAME)

#define AttemptLockLayerRom(___layer) \
      LP1A5(0x28e, BOOL, AttemptLockLayerRom , struct Layer *, ___layer, d7,\
      , GRAPHICS_BASE_NAME)

#endif /* !_INLINE_GRAPHICS_H */
