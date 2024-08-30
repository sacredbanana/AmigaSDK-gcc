	IFND	GRAPHICS_GFX_I
GRAPHICS_GFX_I	SET	1
**
**	$VER: gfx.i 47.2 (4.1.2021)
**
**	general include file for application programs
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
**

    IFND    EXEC_TYPES_I
    include 'exec/types.i'
    ENDC
    IFND    UTILITY_TAGITEM_I
    include 'utility/tagitem.i'
    ENDC

BITSET      equ $8000
BITCLR      equ 0
AGNUS       equ 1
DENISE      equ 1

    STRUCTURE   BitMap,0
    WORD    bm_BytesPerRow
    WORD    bm_Rows
    BYTE    bm_Flags
    BYTE    bm_Depth
    WORD    bm_Pad
    STRUCT  bm_Planes,8*4
    LABEL   bm_SIZEOF

   STRUCTURE   Rectangle,0
      WORD  ra_MinX
      WORD  ra_MinY
      WORD  ra_MaxX
      WORD  ra_MaxY
   LABEL    ra_SIZEOF

   STRUCTURE   Rect32,0
      LONG  r32_MinX
      LONG  r32_MinY
      LONG  r32_MaxX
      LONG  r32_MaxY
   LABEL    r32_SIZEOF

   STRUCTURE   tPoint,0
      WORD  tpt_x
      WORD  tpt_y
   LABEL    tpt_SIZEOF

	;; flags for AllocBitMap
	BITDEF  BM,CLEAR,0
	BITDEF  BM,DISPLAYABLE,1
	BITDEF	BM,INTERLEAVED,2
	BITDEF	BM,STANDARD,3
	BITDEF	BM,MINPLANES,4
	;; the following are new in V45
	BITDEF	BM,HIJACKED,7
	BITDEF	BM,RTGTAGS,8
	BITDEF	BM,RTGCHECK,9
	BITDEF	BM,FRIENDISTAG,10
	BITDEF	BM,INVALID,11

	;; if the flags AND checkmask equals CHECKVALUE
	;; then the "friend" pointer is actually a tag list
BMF_CHECKMASK	equ	BMF_HIJACKED+BMF_RTGTAGS+BMF_RTGCHECK+BMF_FRIENDISTAG+BMF_INVALID
BMF_CHECKVALUE  equ	BMF_RTGTAGS+BMF_RTGCHECK+BMF_FRIENDISTAG

	;; flags for GetBitMapAttr()
BMA_HEIGHT	equ	0
BMA_DEPTH	equ	4
BMA_WIDTH	equ	8
BMA_FLAGS	equ	12

	;; tags for AllocBitMap

BMATags_Friend		equ	TAG_USER+0 ;specify a friend bitmap by tags. Default is no friend
BMATags_Depth		equ	TAG_USER+1 ;depth of the bitmap. Default is the depth parameter
BMATags_PixelFormat	equ	TAG_USER+2 ;pixel format for RTG graphics. Ignored by graphics.
BMATags_Clear		equ	TAG_USER+3 ;clear the bitmap? Default is taken from the BMF_Clear flag.
BMATags_Displayable 	equ	TAG_USER+4 ;used for loading onto graphics hardware for display? Default is from flag.
BMATags_Private1 	equ	TAG_USER+5 ;internal use only
BMATags_NoMemory	equ	TAG_USER+6 ;only allocate the bitmap structure, no memory. Ignored by graphics.
BMATags_NoSprite        equ	TAG_USER+7 ;disable hardware sprites. Ignored by graphics.
BMATags_Private2	equ	TAG_USER+8 ;internal use only
BMATags_Private3	equ	TAG_USER+9 ;internal use only
BMATags_ModeWidth  	equ	TAG_USER+10 ;width of the visible area. Default is from DisplayInfoDB. Ignored by Gfx.
BMATags_ModeHeight 	equ	TAG_USER+11 ;height of the visible area. Default is from DisplayInfoDB. Ignored by Gfx.
BMATags_RenderFunc	equ	TAG_USER+12 ;private use only
BMATags_SaveFunc	equ	TAG_USER+13 ;private use only
BMATags_UserData	equ	TAG_USER+14 ;private use only
BMATags_Alignment	equ	TAG_USER+15 ;alignment of rows (powers of two). Igored by Gfx.
BMATags_ConstantBytesPerRow equ	TAG_USER+16 ;enforce alignment for displayable bitmaps. Ignored by Gfx.
BMATags_UserPrivate	equ	TAG_USER+17 ;bitmap will never be loaded into video RAM. Ignored by Gfx.
BMATags_Private4	equ	TAG_USER+18 ;internal use only
BMATags_Private5	equ	TAG_USER+19 ;internal use only
BMATags_Private6	equ	TAG_USER+20 ;internal use only
BMATags_Private7	equ	TAG_USER+21 ;internal use only
BMATags_DisplayID	equ	TAG_USER+$32 ;a display ID from the monitor data base for which to allocate the bitmap
	;; this is intentionally identical to SA_DisplayID from intuition/intuition.i
BMATags_BitmapInvisible	equ	TAG_USER+$37 ;bitmap is not initially visible
	;; intentionally identical to SA_Behind from intuition/intuition.i
BMATags_BitmapColors	equ	TAG_USER+$29 ;ptr to an array of struct ColorSpec, terminated by -1
	;; this defines an initial palette. intentionally identical to SA_Colors, ignored by Gfx
BMATags_BitmapColors32	equ	TAG_USER+$43 ;ptr to 32-bits-per-gun color, passed over to LoadRGB32
	;; this also defines an initial palette in an alternative way, ignored by Gfx
	;; this tag is intentionally identical to SA_Colors32

    ENDC	; GRAPHICS_GFX_I
