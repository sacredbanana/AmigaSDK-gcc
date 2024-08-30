	IFND	GRAPHICS_SCALE_I
GRAPHICS_SCALE_I	SET	1
**
**	$VER: scale.i 47.1 (31.7.2019)
**
**	structure argument to BitMapScale()
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

    IFND    EXEC_TYPES_I
    include 'exec/types.i'
    ENDC

 STRUCTURE	BitScaleArgs,0
    UWORD   bsa_SrcX		; source origin
    UWORD   bsa_SrcY
    UWORD   bsa_SrcWidth	; source size
    UWORD   bsa_SrcHeight
    UWORD   bsa_XSrcFactor	; scale factor denominators
    UWORD   bsa_YSrcFactor
    UWORD   bsa_DestX		; destination origin
    UWORD   bsa_DestY
    UWORD   bsa_DestWidth	; destination size result
    UWORD   bsa_DestHeight
    UWORD   bsa_XDestFactor	; scale factor numerators
    UWORD   bsa_YDestFactor
    APTR    bsa_SrcBitMap	; source BitMap
    APTR    bsa_DestBitMap	; destination BitMap
    ULONG   bsa_Flags		; reserved.  Must be zero!
    UWORD   bsa_XDDA		; reserved
    UWORD   bsa_YDDA
    LONG    bsa_Reserved1
    LONG    bsa_Reserved2
    LABEL   bsa_SIZEOF

	ENDC	; GRAPHICS_SCALE_I
