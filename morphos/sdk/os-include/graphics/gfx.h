#ifndef GRAPHICS_GFX_H
#define GRAPHICS_GFX_H

/*
	graphics.library general include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


#define BITSET  0x8000
#define BITCLR  0


#define AGNUS

#ifdef AGNUS
# define TOBB(a)  ((long)(a))
#else
# define TOBB(a)  ((long)(a)>>1)
#endif


struct Rectangle
{
	WORD MinX, MinY;
	WORD MaxX, MaxY;
};

struct Rect32
{
	LONG MinX, MinY;
	LONG MaxX, MaxY;
};

typedef
struct tPoint
{
	WORD x, y;
} Point;

typedef UBYTE *PLANEPTR;

struct BitMap
{
	UWORD    BytesPerRow;
	UWORD    Rows;
	UBYTE    Flags;
	UBYTE    Depth;
	UWORD    pad;
	PLANEPTR Planes[8];
};


#define RASSIZE(w,h)  ((ULONG)(h)*(((ULONG)(w)+15)>>3&0xFFFE))


#define BMB_CLEAR        0
#define BMB_DISPLAYABLE  1
#define BMB_INTERLEAVED  2
#define BMB_STANDARD     3
#define BMB_MINPLANES    4

#define BMF_CLEAR        (1<<BMB_CLEAR)
#define BMF_DISPLAYABLE  (1<<BMB_DISPLAYABLE)
#define BMF_INTERLEAVED  (1<<BMB_INTERLEAVED)
#define BMF_STANDARD     (1<<BMB_STANDARD)
#define BMF_MINPLANES    (1<<BMB_MINPLANES)

#define BMA_HEIGHT  0
#define BMA_DEPTH   4
#define BMA_WIDTH   8
#define BMA_FLAGS   12


#pragma pack()

#endif /* GRAPHICS_GFX_H */
