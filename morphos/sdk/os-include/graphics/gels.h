#ifndef GRAPHICS_GELS_H
#define GRAPHICS_GELS_H

/*
	graphics GELS definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


#define SUSERFLAGS    0x00FF
#define VSPRITE       0x0001
#define SAVEBACK      0x0002
#define OVERLAY       0x0004
#define MUSTDRAW      0x0008
#define BACKSAVED     0x0100
#define BOBUPDATE     0x0200
#define GELGONE       0x0400
#define VSOVERFLOW    0x0800

#define BUSERFLAGS    0x00FF
#define SAVEBOB       0x0001
#define BOBISCOMP     0x0002
#define BWAITING      0x0100
#define BDRAWN        0x0200
#define BOBSAWAY      0x0400
#define BOBNIX        0x0800
#define SAVEPRESERVE  0x1000
#define OUTSTEP       0x2000

#define ANFRACSIZE   6
#define ANIMHALF     0x0020
#define RINGTRIGGER  0x0001


#ifndef VUserStuff
# define VUserStuff  WORD
#endif

#ifndef BUserStuff
# define BUserStuff  WORD
#endif

#ifndef AUserStuff
# define AUserStuff  WORD
#endif


struct VSprite
{
	struct VSprite *NextVSprite;
	struct VSprite *PrevVSprite;

	struct VSprite *DrawPath;
	struct VSprite *ClearPath;

	WORD            OldY, OldX;

	WORD            Flags;

	WORD            Y, X;

	WORD            Height;
	WORD            Width;
	WORD            Depth;

	WORD            MeMask;
	WORD            HitMask;

	WORD           *ImageData;

	WORD           *BorderLine;
	WORD           *CollMask;

	WORD           *SprColors;

	struct Bob     *VSBob;

	BYTE            PlanePick;
	BYTE            PlaneOnOff;

	VUserStuff      VUserExt;
};

struct Bob
{
	WORD               Flags;

	WORD              *SaveBuffer;

	WORD              *ImageShadow;

	struct Bob        *Before;
	struct Bob        *After;

	struct VSprite    *BobVSprite;

	struct AnimComp   *BobComp;

	struct DBufPacket *DBuffer;

	BUserStuff         BUserExt;
};

struct AnimComp
{
	WORD              Flags;

	WORD              Timer;
	WORD              TimeSet;

	struct AnimComp  *NextComp;
	struct AnimComp  *PrevComp;

	struct AnimComp  *NextSeq;
	struct AnimComp  *PrevSeq;

	WORD            (*AnimCRoutine) __CLIB_PROTOTYPE((struct AnimComp *));

	WORD              YTrans;
	WORD              XTrans;

	struct AnimOb    *HeadOb;

	struct Bob       *AnimBob;
};

struct AnimOb
{
	struct AnimOb    *NextOb, *PrevOb;

	LONG              Clock;

	WORD              AnOldY, AnOldX;
	WORD              AnY, AnX;

	WORD              YVel, XVel;
	WORD              YAccel, XAccel;

	WORD              RingYTrans, RingXTrans;

	WORD            (*AnimORoutine) __CLIB_PROTOTYPE((struct AnimOb *));

	struct AnimComp  *HeadComp;

	AUserStuff        AUserExt;
};

struct DBufPacket
{
	WORD            BufY, BufX;
	struct VSprite *BufPath;

	WORD           *BufBuffer;
};


#define InitAnimate(animKey)  { *(animKey) = NULL; }
#define RemBob(b)             { (b)->Flags |= BOBSAWAY; }


#define B2NORM    0
#define B2SWAP    1
#define B2BOBBER  2


struct collTable
{
	LONG (*collPtrs[16]) __CLIB_PROTOTYPE((struct VSprite *, struct VSprite *));
};


#pragma pack()

#endif /* GRAPHICS_GELS_H */
