#ifndef GRAPHICS_LAYERS_H
#define GRAPHICS_LAYERS_H
/*
**    $VER: layers.h 54.16 (22.08.2022)
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_LISTS_H
#include <exec/lists.h>
#endif

#ifndef   EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif

#ifndef   GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/

/*
 * layer status flags. These really belong to
 * graphics/clip.h but are here for traditional reason
 * (and to confuse you).
 */

#define LAYERSIMPLE           1
#define LAYERSMART            2
#define LAYERSUPER            4
#define LAYEROFFSCREEN        8       /* New for V53 (system private) */
#define LAYERUPDATING         0x10
#define LAYERBACKDROP         0x40
#define LAYERREFRESH          0x80
#define LAYER_CLIPRECTS_LOST  0x100   /* during BeginUpdate */
                                      /* or during layerop */
                                      /* this happens if out of memory */
#define LAYERIREFRESH         0x200
#define LAYERIREFRESH2        0x400

#define LAYERSAVEBACK         0x800   /* New for V44: Set if clips
                                       * are saved back */
#define LAYERHIDDEN           0x1000  /* New for V45: Layer is invisible */
#define LAYERSTAYTOP          0x2000  /* New for V45: Layer can't be moved
                                       * behind other layers */
#define LAYERMOVECHANGESSHAPE 0x4000  /* New for V45: Report MoveLayer()
                                       * to shapechangehook */
#define LAYERBACKUP           0x8000  /* New for V53 (system private) */

#define ALPHA_PREFIX 0x01000000

/*
 * Thor says: Keep hands off this Layer_Info. There's really nothing in
 * here to play with. The only thing you possibly may be interested in
 * is the top_layer that points to the topmost layer of this layer_info,
 * and the Lock which locks this structure. Even that is quite private,
 * but everything else is really really private. Leave all this to
 * layers.library as some fields are likely to change their meaning
 * in the near future.
 */

struct Layer_Info
{
    struct Layer          *top_layer;          /* Frontmost layer */
    void                  *resPtr1;            /* V45 spare */
    void                  *resPtr2;            /* Another V45 spare */
    struct ClipRect       *FreeClipRects;      /* Implements a backing store
                                                * of cliprects to avoid
                                                * frequent re-allocation
                                                * of cliprects. Private.
                                                */
    struct Rectangle       bounds;             /* clipping bounds of
                                                * this layer info. All layers
                                                * are clipped against this
                                                */
    struct SignalSemaphore Lock;               /* Layer_Info lock */
    struct MinList         gs_Head;            /* linked list of all semaphores
                                                * of all layers within this layer
                                                * info
                                                */
    WORD                   PrivateReserve3;    /* !! Private !! */
    APTR                   ClipRectPool;       /* V45: Pool for cliprects
                                                * (private use only)
                                                */
    UWORD                  Flags;
    BYTE                   res_count;          /* V45 spare, no longer used */
    BYTE                   LockLayersCount;    /* Counts # times LockLayers
                                                * has been called
                                                */
    WORD                   PrivateReserve5;    /* !! Private !! */
    CONST struct Hook     *BlankHook;          /* LayerInfo backfill hook */
    void                  *Extension;          /* !! Private !! */
};

#define NEWLAYERINFO_CALLED 1

#define LIF_EXTLBOUNDS  0x0200  /* System private */
#define LIF_OFFSCREEN   0x0400  /* System private */
#define LIF_SYNCCOMPOSE 0x0800  /* System private */
#define LIF_SYNCALWAYS  0x1000  /* System private */
#define LIF_COLLECTONLY 0x2000  /* System private */
#define LIF_IGNORE      0x4000  /* System private */
#define LIF_OPTIMIZE    0x8000  /* System private */

/*
 * Special backfill hook values you may want to install here.
 *
 * LAYERS_NOBACKFILL is the value needed to get no backfill hook
 * LAYERS_BACKFILL is the value needed to get the default backfill hook
 */
#define LAYERS_NOBACKFILL  ((struct Hook *)1)
#define LAYERS_BACKFILL    ((struct Hook *)0)

/*
 * Special codes for ShowLayer():
 * Give this as target layer where
 * to move your layer to.
 */
#define LAYER_BACKMOST     ((struct Layer *)0)
#define LAYER_FRONTMOST    ((struct Layer *)1)

/*
 * CreateBackFillHookA() attributes
 */
#define LAYERS_DUMMY       (TAG_USER)
#define BFHA_APen          (LAYERS_DUMMY+0)  /* foreground color (def ~0) */
#define BFHA_BPen          (LAYERS_DUMMY+1)  /* background color (def ~0) */
#define BFHA_DrMd          (LAYERS_DUMMY+2)  /* drawmode (def JAM2) */
#define BFHA_PatSize       (LAYERS_DUMMY+3)  /* pattern size, see SetAfPt() */
#define BFHA_Pattern       (LAYERS_DUMMY+4)  /* the pattern */
#define BFHA_BitMap        (LAYERS_DUMMY+5)  /* bitmap to use as backfill */
#define BFHA_Width         (LAYERS_DUMMY+6)  /* width of bm */
#define BFHA_Height        (LAYERS_DUMMY+7)  /* height of bm */
#define BFHA_OffsetX       (LAYERS_DUMMY+8)  /* x offset into the bm */
#define BFHA_OffsetY       (LAYERS_DUMMY+9)  /* y offset into the bm */

/*
 * CreateLayerA() attributes
 */
#define LAYA_MinX          (LAYERS_DUMMY+30) /* upper left corner */
#define LAYA_MinY          (LAYERS_DUMMY+31) /* of layer */
#define LAYA_MaxX          (LAYERS_DUMMY+32) /* lower right corner */
#define LAYA_MaxY          (LAYERS_DUMMY+33) /* of layer */
#define LAYA_ShapeRegion   (LAYERS_DUMMY+34) /* shape of this layer */
#define LAYA_ShapeHook     (LAYERS_DUMMY+35) /* hook to create layer shape */
#define LAYA_InFrontOf     (LAYERS_DUMMY+36) /* create the layer in front
                                              * of the given one */
#define LAYA_BitMap        (LAYERS_DUMMY+37) /* common bitmap used by
                                              * all layers */
#define LAYA_SuperBitMap   (LAYERS_DUMMY+38) /* the superbitmap, sets
                                              * LAYERSUPER */
#define LAYA_SimpleRefresh (LAYERS_DUMMY+39) /* make it a simple refresh
                                              * layer */
#define LAYA_SmartRefresh  (LAYERS_DUMMY+40) /* smart refresh layer
                                              * (default TRUE) */
#define LAYA_Hidden        (LAYERS_DUMMY+41) /* make it invisible */
#define LAYA_Backdrop      (LAYERS_DUMMY+42) /* request backdrop layer */
#define LAYA_Flags         (LAYERS_DUMMY+43) /* layer flags */
#define LAYA_BackFillHook  (LAYERS_DUMMY+44) /* backfill hook for this layer */
#define LAYA_Behind        (LAYERS_DUMMY+45) /* create behind layer
                                              * (default FALSE) */
#define LAYA_StayTop       (LAYERS_DUMMY+46) /* create a window that stays
                                              * on top of all other layers */
#define LAYA_AlphaClips    (LAYERS_DUMMY+47) /* alpha shape of this layer */
#define LAYA_AlphaHook     (LAYERS_DUMMY+48) /* hook to create layer alpha
                                              * shape */
#define LAYA_Opaqueness    (LAYERS_DUMMY+49) /* opaqueness of this layer */
#define LAYA_Window        (LAYERS_DUMMY+50) /* window associated to this
                                              * layer (system use only) */
#define LAYA_Padding       (LAYERS_DUMMY+51) /* extra padding on layer sides,
                                              * extending screen redraw area
                                              * (system use only) */

/*
 * SetLayerInfoAttrsA()/GetLayerInfoAttrsA() attributes
 */
#define LAYERINFO_BackFillHook    (LAYERS_DUMMY+100)  /* Backfill hook for this
                                                       * LayerInfo */
#define LAYERINFO_Bounds          (LAYERS_DUMMY+101)  /* Clipping bounds for
                                                       * this LayerInfo */
#define LAYERINFO_OffScreenBitMap (LAYERS_DUMMY+102)  /* Common offscreen
                                                       * bitmap for this
                                                       * LayerInfo's layers */
#define LAYERINFO_ComposeHook     (LAYERS_DUMMY+103)  /* Compositing hook for
                                                       * this LayerInfo */
#define LAYERINFO_ComposeLock     (LAYERS_DUMMY+104)  /* Semaphore protecting
                                                       * compositing hook */


/*
 * The message a backfill hook receives
 */
struct BackFillMessage
{
    struct Layer     *Layer;
    struct Rectangle  Bounds;
    LONG              OffsetX;
    LONG              OffsetY;
};

/*
 * The message a compose hook receives (system private)
 */
struct LayerComposeMsg
{
   ULONG Action;
   struct Layer_Info *LayerInfo;
   struct BitMap *BackBitMap;
   struct Rectangle Bounds;
};

#define LCM_COMPOSE 0
#define LCM_DAMAGE  1

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* GRAPHICS_LAYERS_H */
