	IFND	GRAPHICS_LAYERS_I
GRAPHICS_LAYERS_I	SET	1
**
**	$VER: layers.i 47.1 (31.7.2019)
**
**	Layer flags, and Layer_Info
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
**

    IFND    EXEC_SEMAPHORES_I
       include "exec/semaphores.i"
    ENDC

    IFND  EXEC_LISTS_I
       include	"exec/lists.i"
    ENDC

* these should be clip.i/h but you know backwards compatibility etc.
LAYERSIMPLE		equ   1
LAYERSMART		equ   2
LAYERSUPER		equ   4
LAYERUPDATING		equ   $10
LAYERBACKDROP		equ   $40
LAYERREFRESH		equ   $80
LAYERIREFRESH		equ   $200
LAYERIREFRESH2		equ   $400

LAYER_CLIPRECTS_LOST	equ   $100
LAYERSAVEBACK		equ   $800   * New for V44: Set if clips are saved back *
LAYERHIDDEN		equ   $1000  * New for V45: Layer is invisible *


* Thor says: Keep hands off this Layer_Info. There's really nothing in
* here to play with. The only thing you possibly may be interested in
* is the top_layer that points to the topmost layer of this layer_info,
* and the Lock which locks this structure. Even that is quite private,
* but everything else is really really private. Leave all this to
* layers.library as some fields are likely to change their meaning
* in the near future.


 STRUCTURE	Layer_Info,0
	APTR	li_top_layer
	APTR	li_resPtr1			;* V45 spare *
	APTR	li_resPtr2			;* another V45 spare *
	APTR	li_FreeClipRects		;* !! Private !! *
	WORD	li_MinX				; clipping bounds of this layer info
	WORD	li_MinY
	WORD	li_MaxX
	WORD	li_MaxY
	STRUCT	li_Lock,SS_SIZE			;* Layer_Info lock *
	STRUCT	li_gs_Head,MLH_SIZE		;* linked list of all semaphores *
	WORD	li_PrivateReserve3		;* !! Private !! *
	APTR	li_PrivateReserve4		;* !! Private !! *
	WORD	li_Flags
	BYTE	li_res_count			;* V45 spare, no longer used *
	BYTE	li_LockLayersCount		;* Counts LockLayers *
	WORD	li_PrivateReserve5		;* !! Private !! *
	APTR	li_BlankHook			;* !! Private !! *
	APTR	li_resPtr5			;* !! Private !! *
	LABEL	li_SIZEOF

NEWLAYERINFO_CALLED	equ 1

*
* LAYERS_NOBACKFILL is the value needed to get no backfill hook
* LAYERS_BACKFILL is the value needed to get the default backfill hook
*
LAYERS_NOBACKFILL	equ	1
LAYERS_BACKFILL		equ	0

*
* Special codes for ShowLayer():
* Give this as target layer where
* to move your layer to.
*/
LAYER_BACKMOST		equ	0
LAYER_FRONTMOST 	equ	1


	ENDC	; GRAPHICS_LAYERS_I
