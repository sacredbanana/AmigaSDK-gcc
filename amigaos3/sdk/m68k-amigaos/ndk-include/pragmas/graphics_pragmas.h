#ifndef PRAGMAS_GRAPHICS_PRAGMAS_H
#define PRAGMAS_GRAPHICS_PRAGMAS_H

/*
**	$VER: graphics_pragmas.h 47.2 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_GRAPHICS_PROTOS_H
#include <clib/graphics_protos.h>
#endif /* CLIB_GRAPHICS_PROTOS_H */

/* "graphics.library" */
/*------ BitMap primitives ------*/
#pragma libcall GfxBase BltBitMap 1e A76543291080B
#pragma libcall GfxBase BltTemplate 24 5432910808
/*------ Text routines ------*/
#pragma libcall GfxBase ClearEOL 2a 901
#pragma libcall GfxBase ClearScreen 30 901
#pragma libcall GfxBase TextLength 36 08903
#pragma libcall GfxBase Text 3c 08903
#pragma libcall GfxBase SetFont 42 8902
#pragma libcall GfxBase OpenFont 48 801
#pragma libcall GfxBase CloseFont 4e 901
#pragma libcall GfxBase AskSoftStyle 54 901
#pragma libcall GfxBase SetSoftStyle 5a 10903
/*------	Gels routines ------*/
#pragma libcall GfxBase AddBob 60 9802
#pragma libcall GfxBase AddVSprite 66 9802
#pragma libcall GfxBase DoCollision 6c 901
#pragma libcall GfxBase DrawGList 72 8902
#pragma libcall GfxBase InitGels 78 A9803
#pragma libcall GfxBase InitMasks 7e 801
#pragma libcall GfxBase RemIBob 84 A9803
#pragma libcall GfxBase RemVSprite 8a 801
#pragma libcall GfxBase SetCollision 90 98003
#pragma libcall GfxBase SortGList 96 901
#pragma libcall GfxBase AddAnimOb 9c A9803
#pragma libcall GfxBase Animate a2 9802
#pragma libcall GfxBase GetGBuffers a8 09803
#pragma libcall GfxBase InitGMasks ae 801
/*------	General graphics routines ------*/
#pragma libcall GfxBase DrawEllipse b4 3210905
#pragma libcall GfxBase AreaEllipse ba 3210905
#pragma libcall GfxBase LoadRGB4 c0 09803
#pragma libcall GfxBase InitRastPort c6 901
#pragma libcall GfxBase InitVPort cc 801
#pragma libcall GfxBase MrgCop d2 901
#pragma libcall GfxBase MakeVPort d8 9802
#pragma libcall GfxBase LoadView de 901
#pragma libcall GfxBase WaitBlit e4 00
#pragma libcall GfxBase SetRast ea 0902
#pragma libcall GfxBase Move f0 10903
#pragma libcall GfxBase Draw f6 10903
#pragma libcall GfxBase AreaMove fc 10903
#pragma libcall GfxBase AreaDraw 102 10903
#pragma libcall GfxBase AreaEnd 108 901
#pragma libcall GfxBase WaitTOF 10e 00
#pragma libcall GfxBase QBlit 114 901
#pragma libcall GfxBase InitArea 11a 09803
#pragma libcall GfxBase SetRGB4 120 3210805
#pragma libcall GfxBase QBSBlit 126 901
#pragma libcall GfxBase BltClear 12c 10903
#pragma libcall GfxBase RectFill 132 3210905
#pragma libcall GfxBase BltPattern 138 432108907
#pragma libcall GfxBase ReadPixel 13e 10903
#pragma libcall GfxBase WritePixel 144 10903
#pragma libcall GfxBase Flood 14a 102904
#pragma libcall GfxBase PolyDraw 150 80903
#pragma libcall GfxBase SetAPen 156 0902
#pragma libcall GfxBase SetBPen 15c 0902
#pragma libcall GfxBase SetDrMd 162 0902
#pragma libcall GfxBase InitView 168 901
#pragma libcall GfxBase CBump 16e 901
#pragma libcall GfxBase CMove 174 10903
#pragma libcall GfxBase CWait 17a 10903
#pragma libcall GfxBase VBeamPos 180 00
#pragma libcall GfxBase InitBitMap 186 210804
#pragma libcall GfxBase ScrollRaster 18c 543210907
#pragma libcall GfxBase WaitBOVP 192 801
#pragma libcall GfxBase GetSprite 198 0802
#pragma libcall GfxBase FreeSprite 19e 001
#pragma libcall GfxBase ChangeSprite 1a4 A9803
#pragma libcall GfxBase MoveSprite 1aa 109804
#pragma libcall GfxBase LockLayerRom 1b0 D01
#pragma libcall GfxBase UnlockLayerRom 1b6 D01
#pragma libcall GfxBase SyncSBitMap 1bc 801
#pragma libcall GfxBase CopySBitMap 1c2 801
#pragma libcall GfxBase OwnBlitter 1c8 00
#pragma libcall GfxBase DisownBlitter 1ce 00
#pragma libcall GfxBase InitTmpRas 1d4 09803
#pragma libcall GfxBase AskFont 1da 8902
#pragma libcall GfxBase AddFont 1e0 901
#pragma libcall GfxBase RemFont 1e6 901
#pragma libcall GfxBase AllocRaster 1ec 1002
#pragma libcall GfxBase FreeRaster 1f2 10803
#pragma libcall GfxBase AndRectRegion 1f8 9802
#pragma libcall GfxBase OrRectRegion 1fe 9802
#pragma libcall GfxBase NewRegion 204 00
#pragma libcall GfxBase ClearRectRegion 20a 9802
#pragma libcall GfxBase ClearRegion 210 801
#pragma libcall GfxBase DisposeRegion 216 801
#pragma libcall GfxBase FreeVPortCopLists 21c 801
#pragma libcall GfxBase FreeCopList 222 801
#pragma libcall GfxBase ClipBlit 228 65432910809
#pragma libcall GfxBase XorRectRegion 22e 9802
#pragma libcall GfxBase FreeCprList 234 801
#pragma libcall GfxBase GetColorMap 23a 001
#pragma libcall GfxBase FreeColorMap 240 801
#pragma libcall GfxBase GetRGB4 246 0802
#pragma libcall GfxBase ScrollVPort 24c 801
#pragma libcall GfxBase UCopperListInit 252 0802
#pragma libcall GfxBase FreeGBuffers 258 09803
#pragma libcall GfxBase BltBitMapRastPort 25e 65432910809
#pragma libcall GfxBase OrRegionRegion 264 9802
#pragma libcall GfxBase XorRegionRegion 26a 9802
#pragma libcall GfxBase AndRegionRegion 270 9802
#pragma libcall GfxBase SetRGB4CM 276 3210805
#pragma libcall GfxBase BltMaskBitMapRastPort 27c A6543291080A
#pragma libcall GfxBase AttemptLockLayerRom 28e D01
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma libcall GfxBase GfxNew 294 001
#pragma libcall GfxBase GfxFree 29a 801
#pragma libcall GfxBase GfxAssociate 2a0 9802
#pragma libcall GfxBase BitMapScale 2a6 801
#pragma libcall GfxBase ScalerDiv 2ac 21003
#pragma libcall GfxBase TextExtent 2b2 A08904
#pragma libcall GfxBase TextFit 2b8 321BA08908
#pragma libcall GfxBase GfxLookUp 2be 801
#pragma libcall GfxBase VideoControl 2c4 9802
#if defined(__SASC_60)
#pragma tagcall GfxBase VideoControlTags 2c4 9802
#endif /* __SASC_60 */
#pragma libcall GfxBase OpenMonitor 2ca 0902
#pragma libcall GfxBase CloseMonitor 2d0 801
#pragma libcall GfxBase FindDisplayInfo 2d6 001
#pragma libcall GfxBase NextDisplayInfo 2dc 001
#pragma libcall GfxBase GetDisplayInfoData 2f4 2109805
#pragma libcall GfxBase FontExtent 2fa 9802
#pragma libcall GfxBase ReadPixelLine8 300 9A210806
#pragma libcall GfxBase WritePixelLine8 306 9A210806
#pragma libcall GfxBase ReadPixelArray8 30c 9A3210807
#pragma libcall GfxBase WritePixelArray8 312 9A3210807
#pragma libcall GfxBase GetVPModeID 318 801
#pragma libcall GfxBase ModeNotAvailable 31e 001
#pragma libcall GfxBase WeighTAMatch 324 A9803
#if defined(__SASC_60)
#pragma tagcall GfxBase WeighTAMatchTags 324 A9803
#endif /* __SASC_60 */
#pragma libcall GfxBase EraseRect 32a 3210905
#pragma libcall GfxBase ExtendFont 330 9802
#if defined(__SASC_60)
#pragma tagcall GfxBase ExtendFontTags 330 9802
#endif /* __SASC_60 */
#pragma libcall GfxBase StripFont 336 801
/*--- functions in V39 or higher (Release 3.0) ---*/
#pragma libcall GfxBase CalcIVG 33c 9802
#pragma libcall GfxBase AttachPalExtra 342 9802
#pragma libcall GfxBase ObtainBestPenA 348 9321805
#if defined(__SASC_60)
#pragma tagcall GfxBase ObtainBestPen 348 9321805
#endif /* __SASC_60 */
#pragma libcall GfxBase SetRGB32 354 3210805
#pragma libcall GfxBase GetAPen 35a 801
#pragma libcall GfxBase GetBPen 360 801
#pragma libcall GfxBase GetDrMd 366 801
#pragma libcall GfxBase GetOutlinePen 36c 801
#pragma libcall GfxBase LoadRGB32 372 9802
#pragma libcall GfxBase SetChipRev 378 001
#pragma libcall GfxBase SetABPenDrMd 37e 210904
#pragma libcall GfxBase GetRGB32 384 910804
#pragma libcall GfxBase AllocBitMap 396 8321005
#pragma libcall GfxBase FreeBitMap 39c 801
#pragma libcall GfxBase GetExtSpriteA 3a2 9A02
#if defined(__SASC_60)
#pragma tagcall GfxBase GetExtSprite 3a2 9A02
#endif /* __SASC_60 */
#pragma libcall GfxBase CoerceMode 3a8 10803
#pragma libcall GfxBase ChangeVPBitMap 3ae A9803
#pragma libcall GfxBase ReleasePen 3b4 0802
#pragma libcall GfxBase ObtainPen 3ba 43210806
#pragma libcall GfxBase GetBitMapAttr 3c0 1802
#pragma libcall GfxBase AllocDBufInfo 3c6 801
#pragma libcall GfxBase FreeDBufInfo 3cc 901
#pragma libcall GfxBase SetOutlinePen 3d2 0802
#pragma libcall GfxBase SetWriteMask 3d8 0802
#pragma libcall GfxBase SetMaxPen 3de 0802
#pragma libcall GfxBase SetRGB32CM 3e4 3210805
#pragma libcall GfxBase ScrollRasterBF 3ea 543210907
#pragma libcall GfxBase FindColor 3f0 4321B05
#pragma libcall GfxBase AllocSpriteDataA 3fc 9A02
#if defined(__SASC_60)
#pragma tagcall GfxBase AllocSpriteData 3fc 9A02
#endif /* __SASC_60 */
#pragma libcall GfxBase ChangeExtSpriteA 402 BA9804
#if defined(__SASC_60)
#pragma tagcall GfxBase ChangeExtSprite 402 BA9804
#endif /* __SASC_60 */
#pragma libcall GfxBase FreeSpriteData 408 A01
#pragma libcall GfxBase SetRPAttrsA 40e 9802
#if defined(__SASC_60)
#pragma tagcall GfxBase SetRPAttrs 40e 9802
#endif /* __SASC_60 */
#pragma libcall GfxBase GetRPAttrsA 414 9802
#if defined(__SASC_60)
#pragma tagcall GfxBase GetRPAttrs 414 9802
#endif /* __SASC_60 */
#pragma libcall GfxBase BestModeIDA 41a 801
#if defined(__SASC_60)
#pragma tagcall GfxBase BestModeID 41a 801
#endif /* __SASC_60 */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma libcall GfxBase WriteChunkyPixels 420 4A3210807
/* Three reserved functions */
/*--- (3 function slots reserved here) ---*/
/*--- functions in V47 or higher (Release 3.2) ---*/

#endif /* PRAGMAS_GRAPHICS_PRAGMAS_H */
