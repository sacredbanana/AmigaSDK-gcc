	IFND	DISKFONT_GLYPH_I
DISKFONT_GLYPH_I	EQU	1

**
**	$VER: glyph.i 47.1 (29.7.2019)
**
**	structures for glyph libraries
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

	IFND	EXEC_TYPES_I
	INCLUDE	"exec/types.i"
	ENDC

	IFND	EXEC_LIBRARIES_I
	INCLUDE	"exec/libraries.i"
	ENDC

	IFND	EXEC_NODES_I
	INCLUDE	"exec/nodes.i"
	ENDC

; A GlyphEngine must be acquired via OpenEngine and is read-only
 STRUCTURE	GlyphEngine,0
    APTR    gle_Library		; (struct Library *) engine library
    APTR    gle_Name		; (char *) library basename: e.g. "bullet"
    ; private library data follows...

 STRUCTURE	GlyphMap,0
    UWORD   glm_BMModulo	; # of bytes in row: always multiple of 4
    UWORD   glm_BMRows		; # of rows in bitmap
    UWORD   glm_BlackLeft	; # of blank pixel columns at left
    UWORD   glm_BlackTop	; # of blank rows at top
    UWORD   glm_BlackWidth	; span of contiguous non-blank columns
    UWORD   glm_BlackHeight	; span of contiguous non-blank rows
    ; the following five ULONGs are FIXED: 
    ULONG   glm_XOrigin		; distance from upper left corner of bitmap
    ULONG   glm_YOrigin		;   to initial CP, in fractional pixels
    WORD    glm_X0		; approximation of XOrigin in whole pixels
    WORD    glm_Y0		; approximation of YOrigin in whole pixels
    WORD    glm_X1		; approximation of XOrigin + Width
    WORD    glm_Y1		; approximation of YOrigin + Width
    ULONG   glm_Width		; character advance, as fraction of em width
    APTR    glm_BitMap		; (ULONG *) actual glyph bitmap
    LABEL   GlyphMap_SIZEOF

 STRUCTURE	GlyphWidthEntry,0
    STRUCT  gwe_Node,MLN_SIZE	; on list returned by OT_WidthList inquiry
    UWORD   gwe_Code		; entry's character code value
    ; the following ULONG is FIXED: 
    ULONG   gwe_Width		; character advance, as fraction of em width
    LABEL   GlyphWidthEntry_SIZEOF

; Structure returned when asking for OT_WidthList32,
; the original GlyphWidthEntry structure is limited to
; 16 bit glyph code (UWORD gwe_Code).

 STRUCTURE	GlyphWidthEntry32,0
    STRUCT  gwe32_Node,MLN_SIZE	; on list returned by OT_WidthList inquiry
    UWORD   gwe32_reserved	; for alignment and backwards compatibility
    ; the following ULONG is FIXED: 
    ULONG   gwe32_Width		; character advance, as fraction of em width
    ULONG   gwe32_Code;		; entry's character code value
    LABEL   GlyphWidthEntry32_SIZEOF

	ENDC	; DISKFONT_GLYPH_I
