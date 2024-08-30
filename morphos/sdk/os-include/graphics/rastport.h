#ifndef GRAPHICS_RASTPORT_H
#define GRAPHICS_RASTPORT_H

/*
	graphics rastport definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef GRAPHICS_GFX_H
# include <graphics/gfx.h>
#endif

#pragma pack(2)


struct AreaInfo
{
	WORD *VctrTbl;
	WORD *VctrPtr;
	BYTE *FlagTbl;
	BYTE *FlagPtr;
	WORD  Count;
	WORD  MaxCount;
	WORD  FirstX, FirstY;
};

struct TmpRas
{
	BYTE *RasPtr;
	LONG  Size;
};

struct GelsInfo
{
	BYTE               sprRsrvd;
	UBYTE              Flags;
	struct VSprite    *gelHead, *gelTail;
	WORD              *nextLine;
	WORD             **lastColor;
	struct collTable  *collHandler;
	WORD               leftmost, rightmost, topmost, bottommost;
	APTR               firstBlissObj, lastBlissObj;
};

struct RastPort
{
	struct Layer    *Layer;
	struct BitMap   *BitMap;
	UWORD           *AreaPtrn;
	struct TmpRas   *TmpRas;
	struct AreaInfo *AreaInfo;
	struct GelsInfo *GelsInfo;
	UBYTE            Mask;
	BYTE             FgPen;
	BYTE             BgPen;
	BYTE             AOlPen;
	BYTE             DrawMode;
	BYTE             AreaPtSz;
	BYTE             linpatcnt;
	BYTE             dummy;
	UWORD            Flags;
	UWORD            LinePtrn;
	WORD             cp_x, cp_y;
	UBYTE            minterms[8];
	WORD             PenWidth;
	WORD             PenHeight;
	struct TextFont *Font;
	UBYTE            AlgoStyle;
	UBYTE            TxFlags;
	UWORD            TxHeight;
	UWORD            TxWidth;
	UWORD            TxBaseline;
	WORD             TxSpacing;
	APTR            *RP_User;
	ULONG            longreserved[2];

#ifndef GFX_RASTPORT_1_2
	UWORD            wordreserved[7];
	UBYTE            reserved[8];
#endif
};


#define JAM1        0
#define JAM2        1
#define COMPLEMENT  2
#define INVERSVID   4

#define FRST_DOT  0x01
#define ONE_DOT   0x02
#define DBUFFER   0x04

#define AREAOUTLINE  0x08
#define NOCROSSFILL  0x20


#pragma pack()

#endif /* GRAPHICS_RASTPORT_H */
