#ifndef CLIB_GRAPHICS_PROTOS_H
#define CLIB_GRAPHICS_PROTOS_H

/*
**	$VER: graphics_protos.h 47.2 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  GRAPHICS_GFXBASE_H
#include <graphics/gfxbase.h>
#endif
#ifndef  GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif
#ifndef  GRAPHICS_DISPLAYINFO_H
#include <graphics/displayinfo.h>
#endif
#ifndef  GRAPHICS_GELS_H
#include <graphics/gels.h>
#endif
#ifndef  GRAPHICS_RASTPORT_H
#include <graphics/rastport.h>
#endif
#ifndef  GRAPHICS_VIEW_H
#include <graphics/view.h>
#endif
#ifndef  GRAPHICS_COPPER_H
#include <graphics/copper.h>
#endif
#ifndef  GRAPHICS_CLIP_H
#include <graphics/clip.h>
#endif
#ifndef  GRAPHICS_REGIONS_H
#include <graphics/regions.h>
#endif
#ifndef  GRAPHICS_SPRITE_H
#include <graphics/sprite.h>
#endif
#ifndef  GRAPHICS_TEXT_H
#include <graphics/text.h>
#endif
#ifndef  HARDWARE_BLIT_H
#include <hardware/blit.h>
#endif
#ifndef  GRAPHICS_SCALE_H
#include <graphics/scale.h>
#endif
/*------ BitMap primitives ------*/
LONG  __stdargs BltBitMap( CONST struct BitMap *srcBitMap, LONG xSrc, LONG ySrc, struct BitMap *destBitMap, LONG xDest, LONG yDest, LONG xSize, LONG ySize, ULONG minterm, ULONG mask, PLANEPTR tempA );
VOID  __stdargs BltTemplate( CONST PLANEPTR source, LONG xSrc, LONG srcMod, struct RastPort *destRP, LONG xDest, LONG yDest, LONG xSize, LONG ySize );
/*------ Text routines ------*/
VOID  __stdargs ClearEOL( struct RastPort *rp );
VOID  __stdargs ClearScreen( struct RastPort *rp );
WORD  __stdargs TextLength( struct RastPort *rp, CONST_STRPTR string, ULONG count );
LONG  __stdargs Text( struct RastPort *rp, CONST_STRPTR string, ULONG count );
LONG  __stdargs SetFont( struct RastPort *rp, struct TextFont *textFont );
struct TextFont * __stdargs OpenFont( CONST struct TextAttr *textAttr );
VOID  __stdargs CloseFont( struct TextFont *textFont );
ULONG  __stdargs AskSoftStyle( struct RastPort *rp );
ULONG  __stdargs SetSoftStyle( struct RastPort *rp, ULONG style, ULONG enable );
/*------	Gels routines ------*/
VOID  __stdargs AddBob( struct Bob *bob, struct RastPort *rp );
VOID  __stdargs AddVSprite( struct VSprite *vSprite, struct RastPort *rp );
VOID  __stdargs DoCollision( struct RastPort *rp );
VOID  __stdargs DrawGList( struct RastPort *rp, struct ViewPort *vp );
VOID  __stdargs InitGels( struct VSprite *head, struct VSprite *tail, struct GelsInfo *gelsInfo );
VOID  __stdargs InitMasks( struct VSprite *vSprite );
VOID  __stdargs RemIBob( struct Bob *bob, struct RastPort *rp, struct ViewPort *vp );
VOID  __stdargs RemVSprite( struct VSprite *vSprite );
VOID  __stdargs SetCollision( ULONG num, VOID (*routine)(struct VSprite *gelA, struct VSprite *gelB), struct GelsInfo *gelsInfo );
VOID  __stdargs SortGList( struct RastPort *rp );
VOID  __stdargs AddAnimOb( struct AnimOb *anOb, struct AnimOb **anKey, struct RastPort *rp );
VOID  __stdargs Animate( struct AnimOb **anKey, struct RastPort *rp );
BOOL  __stdargs GetGBuffers( struct AnimOb *anOb, struct RastPort *rp, LONG flag );
VOID  __stdargs InitGMasks( struct AnimOb *anOb );
/*------	General graphics routines ------*/
VOID  __stdargs DrawEllipse( struct RastPort *rp, LONG xCenter, LONG yCenter, LONG a, LONG b );
LONG  __stdargs AreaEllipse( struct RastPort *rp, LONG xCenter, LONG yCenter, LONG a, LONG b );
VOID  __stdargs LoadRGB4( struct ViewPort *vp, CONST UWORD *colors, LONG count );
VOID  __stdargs InitRastPort( struct RastPort *rp );
VOID  __stdargs InitVPort( struct ViewPort *vp );
ULONG  __stdargs MrgCop( struct View *view );
ULONG  __stdargs MakeVPort( struct View *view, struct ViewPort *vp );
VOID  __stdargs LoadView( struct View *view );
VOID  __stdargs WaitBlit( VOID );
VOID  __stdargs SetRast( struct RastPort *rp, ULONG pen );
VOID  __stdargs Move( struct RastPort *rp, LONG x, LONG y );
VOID  __stdargs Draw( struct RastPort *rp, LONG x, LONG y );
LONG  __stdargs AreaMove( struct RastPort *rp, LONG x, LONG y );
LONG  __stdargs AreaDraw( struct RastPort *rp, LONG x, LONG y );
LONG  __stdargs AreaEnd( struct RastPort *rp );
VOID  __stdargs WaitTOF( VOID );
VOID  __stdargs QBlit( struct bltnode *blit );
VOID  __stdargs InitArea( struct AreaInfo *areaInfo, APTR vectorBuffer, LONG maxVectors );
VOID  __stdargs SetRGB4( struct ViewPort *vp, LONG index, ULONG red, ULONG green, ULONG blue );
VOID  __stdargs QBSBlit( struct bltnode *blit );
VOID  __stdargs BltClear( PLANEPTR memBlock, ULONG byteCount, ULONG flags );
VOID  __stdargs RectFill( struct RastPort *rp, LONG xMin, LONG yMin, LONG xMax, LONG yMax );
VOID  __stdargs BltPattern( struct RastPort *rp, CONST PLANEPTR mask, LONG xMin, LONG yMin, LONG xMax, LONG yMax, ULONG maskBPR );
ULONG  __stdargs ReadPixel( struct RastPort *rp, LONG x, LONG y );
LONG  __stdargs WritePixel( struct RastPort *rp, LONG x, LONG y );
BOOL  __stdargs Flood( struct RastPort *rp, ULONG mode, LONG x, LONG y );
VOID  __stdargs PolyDraw( struct RastPort *rp, LONG count, CONST WORD *polyTable );
VOID  __stdargs SetAPen( struct RastPort *rp, ULONG pen );
VOID  __stdargs SetBPen( struct RastPort *rp, ULONG pen );
VOID  __stdargs SetDrMd( struct RastPort *rp, ULONG drawMode );
VOID  __stdargs InitView( struct View *view );
VOID  __stdargs CBump( struct UCopList *copList );
LONG  __stdargs CMove( struct UCopList *copList, APTR destination, LONG data );
LONG  __stdargs CWait( struct UCopList *copList, LONG v, LONG h );
LONG  __stdargs VBeamPos( VOID );
VOID  __stdargs InitBitMap( struct BitMap *bitMap, LONG depth, LONG width, LONG height );
VOID  __stdargs ScrollRaster( struct RastPort *rp, LONG dx, LONG dy, LONG xMin, LONG yMin, LONG xMax, LONG yMax );
VOID  __stdargs WaitBOVP( struct ViewPort *vp );
WORD  __stdargs GetSprite( struct SimpleSprite *sprite, LONG num );
VOID  __stdargs FreeSprite( LONG num );
VOID  __stdargs ChangeSprite( struct ViewPort *vp, struct SimpleSprite *sprite, UWORD *newData );
VOID  __stdargs MoveSprite( struct ViewPort *vp, struct SimpleSprite *sprite, LONG x, LONG y );
VOID  __stdargs LockLayerRom( struct Layer *layer );
VOID  __stdargs UnlockLayerRom( struct Layer *layer );
VOID  __stdargs SyncSBitMap( struct Layer *layer );
VOID  __stdargs CopySBitMap( struct Layer *layer );
VOID  __stdargs OwnBlitter( VOID );
VOID  __stdargs DisownBlitter( VOID );
struct TmpRas * __stdargs InitTmpRas( struct TmpRas *tmpRas, PLANEPTR buffer, LONG size );
VOID  __stdargs AskFont( struct RastPort *rp, struct TextAttr *textAttr );
VOID  __stdargs AddFont( struct TextFont *textFont );
VOID  __stdargs RemFont( struct TextFont *textFont );
PLANEPTR  __stdargs AllocRaster( ULONG width, ULONG height );
VOID  __stdargs FreeRaster( PLANEPTR p, ULONG width, ULONG height );
VOID  __stdargs AndRectRegion( struct Region *region, CONST struct Rectangle *rectangle );
BOOL  __stdargs OrRectRegion( struct Region *region, CONST struct Rectangle *rectangle );
struct Region * __stdargs NewRegion( VOID );
BOOL  __stdargs ClearRectRegion( struct Region *region, CONST struct Rectangle *rectangle );
VOID  __stdargs ClearRegion( struct Region *region );
VOID  __stdargs DisposeRegion( struct Region *region );
VOID  __stdargs FreeVPortCopLists( struct ViewPort *vp );
VOID  __stdargs FreeCopList( struct CopList *copList );
VOID  __stdargs ClipBlit( struct RastPort *srcRP, LONG xSrc, LONG ySrc, struct RastPort *destRP, LONG xDest, LONG yDest, LONG xSize, LONG ySize, ULONG minterm );
BOOL  __stdargs XorRectRegion( struct Region *region, CONST struct Rectangle *rectangle );
VOID  __stdargs FreeCprList( struct cprlist *cprList );
struct ColorMap * __stdargs GetColorMap( LONG entries );
VOID  __stdargs FreeColorMap( struct ColorMap *colorMap );
ULONG  __stdargs GetRGB4( struct ColorMap *colorMap, LONG entry );
VOID  __stdargs ScrollVPort( struct ViewPort *vp );
struct CopList * __stdargs UCopperListInit( struct UCopList *uCopList, LONG n );
VOID  __stdargs FreeGBuffers( struct AnimOb *anOb, struct RastPort *rp, LONG flag );
VOID  __stdargs BltBitMapRastPort( CONST struct BitMap *srcBitMap, LONG xSrc, LONG ySrc, struct RastPort *destRP, LONG xDest, LONG yDest, LONG xSize, LONG ySize, ULONG minterm );
BOOL  __stdargs OrRegionRegion( CONST struct Region *srcRegion, struct Region *destRegion );
BOOL  __stdargs XorRegionRegion( CONST struct Region *srcRegion, struct Region *destRegion );
BOOL  __stdargs AndRegionRegion( CONST struct Region *srcRegion, struct Region *destRegion );
VOID  __stdargs SetRGB4CM( struct ColorMap *colorMap, LONG index, ULONG red, ULONG green, ULONG blue );
VOID  __stdargs BltMaskBitMapRastPort( CONST struct BitMap *srcBitMap, LONG xSrc, LONG ySrc, struct RastPort *destRP, LONG xDest, LONG yDest, LONG xSize, LONG ySize, ULONG minterm, CONST PLANEPTR bltMask );
BOOL  __stdargs AttemptLockLayerRom( struct Layer *layer );
/*--- functions in V36 or higher (Release 2.0) ---*/
APTR  __stdargs GfxNew( ULONG gfxNodeType );
VOID  __stdargs GfxFree( APTR gfxNodePtr );
VOID  __stdargs GfxAssociate( APTR associateNode, APTR gfxNodePtr );
VOID  __stdargs BitMapScale( struct BitScaleArgs *bitScaleArgs );
UWORD  __stdargs ScalerDiv( ULONG factor, ULONG numerator, ULONG denominator );
WORD  __stdargs TextExtent( struct RastPort *rp, CONST_STRPTR string, LONG count, struct TextExtent *textExtent );
ULONG  __stdargs TextFit( struct RastPort *rp, CONST_STRPTR string, ULONG strLen, CONST struct TextExtent *textExtent, CONST struct TextExtent *constrainingExtent, LONG strDirection, ULONG constrainingBitWidth, ULONG constrainingBitHeight );
APTR  __stdargs GfxLookUp( CONST_APTR associateNode );
BOOL  __stdargs VideoControl( struct ColorMap *colorMap, struct TagItem *tagarray );
BOOL  __stdargs VideoControlTags( struct ColorMap *colorMap, ULONG tag1Type, ... );
struct MonitorSpec * __stdargs OpenMonitor( CONST_STRPTR monitorName, ULONG displayID );
BOOL  __stdargs CloseMonitor( struct MonitorSpec *monitorSpec );
DisplayInfoHandle  __stdargs FindDisplayInfo( ULONG displayID );
ULONG  __stdargs NextDisplayInfo( ULONG displayID );
ULONG  __stdargs GetDisplayInfoData( DisplayInfoHandle handle, APTR buf, ULONG size, ULONG tagID, ULONG displayID );
VOID  __stdargs FontExtent( CONST struct TextFont *font, struct TextExtent *fontExtent );
LONG  __stdargs ReadPixelLine8( struct RastPort *rp, ULONG xstart, ULONG ystart, ULONG width, UBYTE *array, struct RastPort *tempRP );
LONG  __stdargs WritePixelLine8( struct RastPort *rp, ULONG xstart, ULONG ystart, ULONG width, UBYTE *array, struct RastPort *tempRP );
LONG  __stdargs ReadPixelArray8( struct RastPort *rp, ULONG xstart, ULONG ystart, ULONG xstop, ULONG ystop, UBYTE *array, struct RastPort *temprp );
LONG  __stdargs WritePixelArray8( struct RastPort *rp, ULONG xstart, ULONG ystart, ULONG xstop, ULONG ystop, UBYTE *array, struct RastPort *temprp );
LONG  __stdargs GetVPModeID( CONST struct ViewPort *vp );
LONG  __stdargs ModeNotAvailable( ULONG modeID );
WORD  __stdargs WeighTAMatch( CONST struct TextAttr *reqTextAttr, CONST struct TextAttr *targetTextAttr, CONST struct TagItem *targetTags );
WORD  __stdargs WeighTAMatchTags( CONST struct TextAttr *reqTextAttr, CONST struct TextAttr *targetTextAttr, ULONG tag1Type, ... );
VOID  __stdargs EraseRect( struct RastPort *rp, LONG xMin, LONG yMin, LONG xMax, LONG yMax );
ULONG  __stdargs ExtendFont( struct TextFont *font, CONST struct TagItem *fontTags );
ULONG  __stdargs ExtendFontTags( struct TextFont *font, ULONG tag1Type, ... );
VOID  __stdargs StripFont( struct TextFont *font );
/*--- functions in V39 or higher (Release 3.0) ---*/
UWORD  __stdargs CalcIVG( struct View *v, struct ViewPort *vp );
LONG  __stdargs AttachPalExtra( struct ColorMap *cm, struct ViewPort *vp );
LONG  __stdargs ObtainBestPenA( struct ColorMap *cm, ULONG r, ULONG g, ULONG b, CONST struct TagItem *tags );
LONG  __stdargs ObtainBestPen( struct ColorMap *cm, ULONG r, ULONG g, ULONG b, ULONG tag1Type, ... );
VOID  __stdargs SetRGB32( struct ViewPort *vp, ULONG n, ULONG r, ULONG g, ULONG b );
ULONG  __stdargs GetAPen( struct RastPort *rp );
ULONG  __stdargs GetBPen( struct RastPort *rp );
ULONG  __stdargs GetDrMd( struct RastPort *rp );
ULONG  __stdargs GetOutlinePen( struct RastPort *rp );
VOID  __stdargs LoadRGB32( struct ViewPort *vp, CONST ULONG *table );
ULONG  __stdargs SetChipRev( ULONG want );
VOID  __stdargs SetABPenDrMd( struct RastPort *rp, ULONG apen, ULONG bpen, ULONG drawmode );
VOID  __stdargs GetRGB32( CONST struct ColorMap *cm, ULONG firstcolor, ULONG ncolors, ULONG *table );
struct BitMap * __stdargs AllocBitMap( ULONG sizex, ULONG sizey, ULONG depth, ULONG flags, CONST struct BitMap *friend_bitmap );
VOID  __stdargs FreeBitMap( struct BitMap *bm );
LONG  __stdargs GetExtSpriteA( struct ExtSprite *ss, CONST struct TagItem *tags );
LONG  __stdargs GetExtSprite( struct ExtSprite *ss, ULONG tag1Type, ... );
ULONG  __stdargs CoerceMode( struct ViewPort *vp, ULONG monitorid, ULONG flags );
VOID  __stdargs ChangeVPBitMap( struct ViewPort *vp, struct BitMap *bm, struct DBufInfo *db );
VOID  __stdargs ReleasePen( struct ColorMap *cm, ULONG n );
ULONG  __stdargs ObtainPen( struct ColorMap *cm, ULONG n, ULONG r, ULONG g, ULONG b, LONG f );
ULONG  __stdargs GetBitMapAttr( CONST struct BitMap *bm, ULONG attrnum );
struct DBufInfo * __stdargs AllocDBufInfo( struct ViewPort *vp );
VOID  __stdargs FreeDBufInfo( struct DBufInfo *dbi );
ULONG  __stdargs SetOutlinePen( struct RastPort *rp, ULONG pen );
ULONG  __stdargs SetWriteMask( struct RastPort *rp, ULONG msk );
VOID  __stdargs SetMaxPen( struct RastPort *rp, ULONG maxpen );
VOID  __stdargs SetRGB32CM( struct ColorMap *cm, ULONG n, ULONG r, ULONG g, ULONG b );
VOID  __stdargs ScrollRasterBF( struct RastPort *rp, LONG dx, LONG dy, LONG xMin, LONG yMin, LONG xMax, LONG yMax );
LONG  __stdargs FindColor( struct ColorMap *cm, ULONG r, ULONG g, ULONG b, LONG maxcolor );
struct ExtSprite * __stdargs AllocSpriteDataA( CONST struct BitMap *bm, CONST struct TagItem *tags );
struct ExtSprite * __stdargs AllocSpriteData( CONST struct BitMap *bm, ULONG tag1Type, ... );
LONG  __stdargs ChangeExtSpriteA( struct ViewPort *vp, struct ExtSprite *oldsprite, struct ExtSprite *newsprite, CONST struct TagItem *tags );
LONG  __stdargs ChangeExtSprite( struct ViewPort *vp, struct ExtSprite *oldsprite, struct ExtSprite *newsprite, ULONG tag1Type, ... );
VOID  __stdargs FreeSpriteData( struct ExtSprite *sp );
VOID  __stdargs SetRPAttrsA( struct RastPort *rp, CONST struct TagItem *tags );
VOID  __stdargs SetRPAttrs( struct RastPort *rp, ULONG tag1Type, ... );
VOID  __stdargs GetRPAttrsA( struct RastPort *rp, CONST struct TagItem *tags );
VOID  __stdargs GetRPAttrs( struct RastPort *rp, ULONG tag1Type, ... );
ULONG  __stdargs BestModeIDA( CONST struct TagItem *tags );
ULONG  __stdargs BestModeID( ULONG tag1Type, ... );
/*--- functions in V40 or higher (Release 3.1) ---*/
VOID  __stdargs WriteChunkyPixels( struct RastPort *rp, ULONG xstart, ULONG ystart, ULONG xstop, ULONG ystop, UBYTE *array, LONG bytesperrow );
/*--- functions in V47 or higher (Release 3.2) ---*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_GRAPHICS_PROTOS_H */
