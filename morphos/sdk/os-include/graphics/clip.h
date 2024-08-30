#ifndef GRAPHICS_CLIP_H
#define GRAPHICS_CLIP_H

/*
	graphics clip definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef GRAPHICS_GFX_H
# include <graphics/gfx.h>
#endif

#ifndef EXEC_SEMAPHORES_H
# include <exec/semaphores.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#pragma pack(2)


#define NEWLOCKS

struct Layer
{
	struct Layer           *front, *back;
	struct ClipRect        *ClipRect;
	struct RastPort        *rp;
	struct Rectangle        bounds;
	UBYTE                   reserved[4];
	UWORD                   priority;
	UWORD                   Flags;
	struct BitMap          *SuperBitMap;
	struct ClipRect        *SuperClipRect;
	APTR                    Window;
	WORD                    Scroll_X, Scroll_Y;
	struct ClipRect        *cr, *cr2, *crnew;
	struct ClipRect        *SuperSaveClipRects;
	struct ClipRect        *_cliprects;
	struct Layer_Info      *LayerInfo;
	struct SignalSemaphore  Lock;
	struct Hook            *BackFill;
	ULONG                   reserved1;
	struct Region          *ClipRegion;
	struct Region          *saveClipRects;
	WORD                    Width,Height;
	UBYTE                   reserved2[18];
	struct Region          *DamageList;
};

struct ClipRect
{
	struct ClipRect  *Next;
	struct ClipRect  *prev;
	struct Layer     *lobs;
	struct BitMap    *BitMap;
	struct Rectangle  bounds;
	APTR              _p1;
	APTR              _p2;
	LONG              reserved;

#ifdef NEWCLIPRECTS_1_1
	LONG              Flags;
#endif
};


#define CR_NEEDS_NO_CONCEALED_RASTERS  1
#define CR_NEEDS_NO_LAYERBLIT_DAMAGE   2


#define ISLESSX  1
#define ISLESSY  2
#define ISGRTRX  4
#define ISGRTRY  8


#pragma pack()

#endif /* GRAPHICS_CLIP_H */
