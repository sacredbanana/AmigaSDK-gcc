#ifndef GRAPHICS_CLIP_H
#define GRAPHICS_CLIP_H
/*
**    $VER: clip.h 54.16 (22.08.2022)
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

#ifndef   EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif

#ifndef   UTILITY_HOOKS_H
#include <utility/hooks.h>
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

#define NEWLOCKS

/*
 * Thor says: Keep hands off this structure. Layers builds it for you,
 * and keeps and adminstrates it for you. What's documented here is
 * only of interest for graphics and intuition. Especially, you may
 * only look at the front/back pointer of this layer while keeping the
 * layers list locked, or at the (Super)ClipRect singly (!) linked
 * list while keeping this layer locked. Bounds are the bounds of this
 * layer, rp its rastport whose layer is, surprise, surprise, this here.
 * Lock is the access lock you please lock by LockLayer() or
 * LockLayerRom().
 * Everything else is completely off-limits and for private use only.
 */

struct Layer
{
    struct  Layer       *front,*back;
    struct  ClipRect    *ClipRect;      /* singly linked list of active cliprects */
    struct  RastPort    *rp;            /* rastport to draw into. Its layer is me */
    struct  Rectangle   bounds;         /* screen bounds of this layer */
    struct  Layer       *nlink;         /* new in V45:
                                         * next back layer for display
                                         * reorganization
                                         */
    UWORD   priority;                   /* internal use: on layer front/back move,
                                         * relative priority of the layers.
                                         * Topmost layer has lowest priority.
                                         */
    UWORD   Flags;                      /* see <graphics/layers.h> */
    struct  BitMap      *SuperBitMap;   /* if non-NULL, superbitmap layer */
    struct  ClipRect    *SuperClipRect; /* super bitmap cliprects if VBitMap != 0*/
                                        /* else damage cliprect list for refresh */
    APTR    Window;                     /* Intuition keeps its window here */
    WORD    Scroll_X,Scroll_Y;          /* layer displacement */
    struct  ClipRect *cr,*cr2,*cr3;     /* used by moveinfrontof
                                         * cr,cr2 are the new on- and off-
                                         * screen cliprects to combine.
                                         * cr3 keeps the new templates that
                                         * are not clipped by user/damage list
                                         */
    struct  ClipRect *SuperSaveClipRects; /* five preallocated super cr's */
    struct  ClipRect *_cliprects;       /* templates that are not clipped
                                         * by damage list or user clip rect
                                         */
    struct  Layer_Info  *LayerInfo;     /* points to head of the list */
    struct  SignalSemaphore Lock;       /* access to this layer */
    CONST   struct Hook *BackFill;      /* backfill hook */
    CONST   struct Region *ShapeRegion; /* the region that comprises the shape
                                         * of this layer */
    CONST struct  Region *ClipRegion;   /* user InstallClipRegion()'d region */
    struct  ClipRect *clipped;          /* clipped away by damage list or
                                         * user clip rect
                                         */
    WORD    Width,Height;               /* system use */
    struct Hook *ShapeHook;             /* hook used to generate the shaperegion */
    UBYTE   reserved2[4];               /* more reserved fields */
    struct BitMap *BitMap;              /* layer's own off-screen bitmap */
    APTR    Extension;                  /* layer extension (system private) */
    UBYTE   reserved3;                  /* another reserved field */
    UBYTE   Opaqueness;                 /* layer opaqueness */
    struct  Region  *DamageList;        /* list of rectangles to refresh */
};

/*
 * Describes one graphic rectangle of this layer, may it
 * be drawable or not.
 * The meaning of some fields in here changed in the past,
 * and will remain changing. Chaining is done by Next, and
 * if "lobs" is non-NULL, BitMap *may* point to a backing
 * store bitmap aligned to multiples of 16 pixels.
 * Everything else is private, and may change.
 * Especially, note that this structure grew in v33(!!!)
 * and has now been documented to be of this size in
 * v44. NEWCLIPRECTS_1_1 is really, really obsolete.
 * Do *never* allocate this yourself as layers handles them
 * internally more efficiently than AllocMem() could.
 */

struct ClipRect
{
    struct  ClipRect   *Next;           /* roms used to find next ClipRect */
    WORD               OffX, OffY;      /* offsets of cliprect into bitmap (V52) */
    struct  Layer      *lobs;           /* If non-NULL, this is a backing store
                                         * cliprect that is currently obscured.
                                         * NEW: In V45, this is no longer a
                                         * valid pointer since a cliprect
                                         * can be obscured by more than one
                                         * layer. Just test for NULL or non-
                                         * NULL, do *NOT* dereference.
                                         */
    struct  BitMap     *BitMap;         /* backing store bitmap if lobs != NULL */
    struct  Rectangle   bounds;         /* bounds of this cliprect */
    struct  ClipRect   *vlink;          /* Layers private use!!! */
    struct  Layer_Info *home;           /* where this cliprect belongs to.
                                         * If you *MUST* hack in your private
                                         * cliprects, ensure that you set this
                                         * field to NULL. If you don't, layers
                                         * will pool your cliprect and will
                                         * release it when it "feels like".
                                         * For NULL, V40 behaivour is
                                         * re-established.
                                         */
    LONG                Flags;          /* Layers private field for cliprects */
/*
 * For below V45, the flags field used to be below
 * this point and cliprects used to be four bytes
 * larger internally. This is no longer the case
 * now for V45.
 */
};

/* internal cliprect flags */
#define CR_USERCLIPPED    16 /* out of user clip rectangle */
#define CR_DAMAGECLIPPED  32 /* out of damage cliprects */
#define CR_LAYERBITMAP    64 /* don't free the BitMap */
#define CR_ALPHATYPE     128 /* not opaque, or covered by same */
#define CR_INVISIBLE     256 /* fully obscured, no own BitMap */
#define CR_INTUITION    1024 /* internal system use */

/* defines for code values for getcode
 * this really belongs to graphics, and is of no
 * use for layers. It's here only for traditional
 * reasons.
 */
#define ISLESSX 1
#define ISLESSY 2
#define ISGRTRX 4
#define ISGRTRY 8

/*
 * defines for shape hooks
 */
#define SHAPEHOOKACTION_CREATELAYER      0
#define SHAPEHOOKACTION_MOVELAYER        1  /* Only sent if LAYERMOVECHANGESSHAPE is set */
#define SHAPEHOOKACTION_SIZELAYER        2
#define SHAPEHOOKACTION_MOVESIZELAYER    3
#define SHAPEHOOKACTION_CHANGELAYERSHAPE 4
#define SHAPEHOOKACTION_DELETELAYER      5
#define SHAPEHOOKACTION_GETHOOKACTIONS   6

struct ShapeHookMsg
{
    ULONG             Action;
    struct Region    *NewShape;
    struct Region    *OldShape;
    struct Rectangle *NewBounds;
    struct Rectangle *OldBounds;
};

/*
 * defines for alpha hooks
 */
#define ALPHAHOOKACTION_CREATELAYER      0
#define ALPHAHOOKACTION_MOVELAYER        1  /* Only sent if LAYERMOVECHANGESSHAPE is set */
#define ALPHAHOOKACTION_SIZELAYER        2
#define ALPHAHOOKACTION_MOVESIZELAYER    3
#define ALPHAHOOKACTION_CHANGELAYERALPHA 4
#define ALPHAHOOKACTION_DELETELAYER      5
#define ALPHAHOOKACTION_GETHOOKACTIONS   6

struct AlphaHookMsg
{
    ULONG             Action;
    struct ClipRect  *NewAlphaCR;
    struct ClipRect  *OldAlphaCR;
    struct Rectangle *NewBounds;
    struct Rectangle *OldBounds;
};

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

#endif /* GRAPHICS_CLIP_H */
