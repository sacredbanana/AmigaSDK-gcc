	IFND	GRAPHICS_CLIP_I
GRAPHICS_CLIP_I	SET	1
**
**	$VER: clip.i 47.1 (30.7.2019)
**
**	Layer and cliprect definitions
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

    IFND    EXEC_TYPES_I
    include 'exec/types.i'
    ENDC

    IFND    GRAPHICS_GFX_I
    include "graphics/gfx.i"
    ENDC

    IFND    EXEC_SEMAPHORES_I
    include "exec/semaphores.i"
    ENDC

NEWLOCKS	equ	1

*
* Keep hands off this structure. Layers builds it for you,
* and keeps and adminstrates it for you. What's documented here is
* only of interest for graphics and intuition. Especially, you may
* only look at the front/back pointer of this layer while keeping the
* layers list locked, or at the (Super)ClipRect singly (!) linked 
* list while keeping this layer locked. Bounds are the bounds of this 
* layer, rp its rastport whose layer is, surprise, surprise, this here.
* Lock is the access lock you please lock by LockLayer() or 
* LockLayerRom().
* Everything else is completely off-limits and for private use only.

 STRUCTURE  Layer,0
    LONG    lr_front
    LONG    lr_back
    LONG    lr_ClipRect
    LONG    lr_rp
    WORD    lr_MinX
    WORD    lr_MinY
    WORD    lr_MaxX
    WORD    lr_MaxY
    APTR    lr_nlink
    WORD    lr_priority
    WORD    lr_Flags
    LONG    lr_SuperBitMap
    LONG    lr_SuperClipRect
    APTR    lr_Window
    WORD    lr_Scroll_X
    WORD    lr_Scroll_Y
    APTR    lr_OnScreen
    APTR    lr_OffScreen
    APTR    lr_Backup
    APTR    lr_SuperSaveClipRects
    APTR    lr_Undamaged
    APTR    lr_LayerInfo
*			just by lucky coincidence
*			this is not confused with simplesprites
    STRUCT  lr_Lock,SS_SIZE
    APTR    lr_BackFill
    ULONG   lr_reserved1
    APTR    lr_ClipRegion
    APTR    lr_clipped
    WORD    lr_Width
    WORD    lr_Height
    STRUCT  lr_reserved2,18
    APTR    lr_DamageList
    LABEL   lr_SIZEOF

* Describes one graphic rectangle of this layer, may it
* be drawable or not. 
* The meaning of some fields in here changed in the past,
* and will remain changing. Chaining is done by Next, and
* if cr_obscured is non-NULL, BitMap *may* point to a backing
* store bitmap aligned to multiples of 16 pixels. 
* Everything else is private, and may change.
* Especially, note that this structure grew in v33(!!!)
* and has now been documented to be of this size in
* v44. NEWCLIPRECTS_1_1 is really, really obsolete.
* Do *never* allocate this yourself as layers handles them
* internally more efficiently than AllocMem() could.

 STRUCTURE  ClipRect,0
    LONG    cr_Next		* Point to next cliprect
    LONG    cr_reservedlink	* currently unused
    LONG    cr_obscured		* if non-zero, this is a backing store clip rect
    	    			* THIS IS NOT A POINTER
    LONG    cr_BitMap		* Bitmap for this cliprect (system private!!!)
    WORD    cr_MinX		* Bounds of the cliprect
    WORD    cr_MinY		*    "
    WORD    cr_MaxX		*    "
    WORD    cr_MaxY		*    "
    APTR    cr_vlink		* Layers private use!!!
    APTR    cr_home		* LayerInfo where this cliprect belongs, or NULL
    LONG    cr_reserved		* Layers private use!!!
    LONG    cr_Flags		* Layers private use!!!
 LABEL      cr_SIZEOF

* internal cliprect flags
CR_NEEDS_NO_CONCEALED_RASTERS   equ     1
CR_NEEDS_NO_LAYERBLIT_DAMAGE 	equ	2

* defines for clipping
ISLESSX equ 1
ISLESSY equ 2
ISGRTRX equ 4
ISGRTRY equ 8

	ENDC	; GRAPHICS_CLIP_I
