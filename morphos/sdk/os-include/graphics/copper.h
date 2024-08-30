#ifndef GRAPHICS_COPPER_H
#define GRAPHICS_COPPER_H

/*
	graphics copper list instruction definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


#define COPPER_MOVE  0
#define COPPER_WAIT  1
#define CPRNXTBUF    2
#define CPR_NT_LOF   0x8000
#define CPR_NT_SHT   0x4000
#define CPR_NT_SYS   0x2000


struct CopIns
{
	WORD OpCode;

	union
	{
		struct CopList *nxtlist;

		struct
		{
			union
			{
				WORD VWaitPos;
				WORD DestAddr;
			} u1;

			union
			{
				WORD HWaitPos;
				WORD DestData;
			} u2;
		} u4;
	} u3;
};

#define NXTLIST   u3.nxtlist
#define VWAITPOS  u3.u4.u1.VWaitPos
#define DESTADDR  u3.u4.u1.DestAddr
#define HWAITPOS  u3.u4.u2.HWaitPos
#define DESTDATA  u3.u4.u2.DestData


struct cprlist
{
	struct cprlist *Next;
	UWORD          *start;
	WORD            MaxCount;
};

struct CopList
{
	struct CopList  *Next;
	struct CopList  *_CopList;
	struct ViewPort *_ViewPort;
	struct CopIns   *CopIns;
	struct CopIns   *CopPtr;
	UWORD           *CopLStart;
	UWORD           *CopSStart;
	WORD             Count;
	WORD             MaxCount;
	WORD             DyOffset;

#ifdef V1_3
	UWORD           *Cop2Start;
	UWORD           *Cop3Start;
	UWORD           *Cop4Start;
	UWORD           *Cop5Start;
#endif

	UWORD            SLRepeat;
	UWORD            Flags;
};

#define EXACT_LINE  1
#define HALF_LINE   2


struct UCopList
{
	struct UCopList *Next;
	struct CopList  *FirstCopList;
	struct CopList  *CopList;
};


struct copinit
{
	UWORD vsync_hblank[2];
	UWORD diagstrt[12];
	UWORD fm0[2];
	UWORD diwstart[10];
	UWORD bplcon2[2];
	UWORD sprfix[2*8];
	UWORD sprstrtup[(2*8*2)];
	UWORD wait14[2];
	UWORD norm_hblank[2];
	UWORD jump[2];
	UWORD wait_forever[6];
	UWORD sprstop[8];
};


#pragma pack()

#endif /* GRAPHICS_COPPER_H */
