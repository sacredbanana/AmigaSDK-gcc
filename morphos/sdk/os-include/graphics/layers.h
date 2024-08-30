#ifndef GRAPHICS_LAYERS_H
#define GRAPHICS_LAYERS_H

/*
	graphics layer definitions

	Copyright ? 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_LISTS_H
# include <exec/lists.h>
#endif

#ifndef EXEC_SEMAPHORES_H
# include <exec/semaphores.h>
#endif

#ifndef GRAPHICS_CLIP_H
# include <graphics/clip.h>
#endif

#pragma pack(2)


#define LAYERSIMPLE           0x1
#define LAYERSMART            0x2
#define LAYERSUPER            0x4
#define LAYERUPDATING         0x10
#define LAYERBACKDROP         0x40
#define LAYERREFRESH          0x80
#define LAYER_CLIPRECTS_LOST  0x100
#define LAYERIREFRESH         0x200
#define LAYERIREFRESH2        0x400

struct Layer_Info
{
	struct Layer           *top_layer;
	struct Layer           *check_lp;
	struct ClipRect        *obs;
	struct ClipRect        *FreeClipRects;
	LONG                    PrivateReserve1;
	LONG                    PrivateReserve2;
	struct SignalSemaphore  Lock;
	struct MinList          gs_Head;
	WORD                    PrivateReserve3;
	APTR                    PrivateReserve4;
	UWORD                   Flags;
	BYTE                    fatten_count;
	BYTE                    LockLayersCount;
	WORD                    PrivateReserve5;
	APTR                    BlankHook;
	APTR                    LayerInfo_extra;
};

#define NEWLAYERINFO_CALLED  1

/* LAYERS_NEVERBACKFILL, available since v52.22
   unlike with NOBACKFILL, the new layer will not be filled with contents
   of layers underneath it, contents is lost after resize
*/
#define LAYERS_NEVERBACKFILL  ((struct Hook *)2)
#define LAYERS_NOBACKFILL     ((struct Hook *)1)
#define LAYERS_BACKFILL       ((struct Hook *)0)


/* if you use the following hook and fill the transparent hook/region fields 
   accordingly, you can set the transparent region/hook within CreateXXHookLayer()

   NOTE: Obsolete, use new createlayer tag calls !!!
*/

struct NewLayerHook
{
	struct MinNode   h_MinNode;
	ULONG          (*h_Entry)(void);		/* use that like normal */
	ULONG          (*h_SubEntry)(void);		/* backfill hook */
	APTR             h_Data;				/* set to MAKE_ID('C','Y','B','R')) */
	struct Hook     *TransparentRegionHook;
	struct Region   *TransparentRegion;
};


/* tag calls for Create#?LayerTagList */

#define LA_Dummy        (TAG_USER + 1024)

#define LA_BackfillHook (LA_Dummy + 0x0001)
#define LA_TransRegion  (LA_Dummy + 0x0002)
#define LA_TransHook    (LA_Dummy + 0x0003)
#define LA_WindowPtr    (LA_Dummy + 0x0004)
#define LA_SuperBitMap  (LA_Dummy + 0x0005)     /* replaces bm2 in function call */


#define LR_Dummy                           (TAG_USER + 1150)
#define LR_Destination_RastPort            (LR_Dummy + 1)
/* struct RastPort * to render in */
#define LR_Destination_BitMap              (LR_Dummy + 2)
/* struct BitMap * to render in. mutually exclusive with
** LR_Destination_RastPort. Do note that the destination
** bitmap (or the rastport's bitmap) MUST be in the same
** format as the source you want to render from! */
#define LR_Destination_Bounds              (LR_Dummy + 3)
/* struct Rectangle *. the graphics will be rendered inside of
** the given boundaries. if not passed, the call assumes
** the buffer has at least the same size as LayerInfo */
#define LR_LayerInfo_Bounds                (LR_Dummy + 4)
/* struct Rectangle *. limits the portion of a LayerInfo to draw */
#define LR_Erase                           (LR_Dummy + 5)
/* BOOL. setting to FALSE will make the layers be drawn without
** the background being cleared with the screen's backfill hook
** TRUE by default */
#define LR_RenderList                      (LR_Dummy + 6)
/* struct Layer **. a NULL terminated list of struct Layer 
** pointers to render if they are within given bounds */
#define LR_IgnoreList                      (LR_Dummy + 7)
/* struct Layer **. a NULL terminated list of struct Layer 
** pointers to ommit when rendering the layerinfo.
** mutually exclusive with LR_RenderList! */
#define LR_ApplyOpacityMultiplier          (LR_Dummy + 8)
/* BOOL, if TRUE, the opacity multiplier will be applied
** when rendering the layers. Defaults to TRUE */

#pragma pack()

#endif /* GRAPHICS_LAYERS_H */
