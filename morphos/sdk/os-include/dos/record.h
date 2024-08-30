#ifndef DOS_RECORD_H
#define DOS_RECORD_H

/*
	dos record definitions

	Copyright © 2002-2003 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#pragma pack(2)


#define REC_EXCLUSIVE        0
#define REC_EXCLUSIVE_IMMED  1
#define REC_SHARED           2
#define REC_SHARED_IMMED     3


struct RecordLock
{
	BPTR  rec_FH;
	ULONG rec_Offset;
	ULONG rec_Length;
	ULONG rec_Mode;
};


/* 64bit DOS extensions - V51 */

struct RecordLock64
{
	BPTR   rec_FH;
	UQUAD  rec_Offset;
	UQUAD  rec_Length;
	ULONG  rec_Mode;
};

#pragma pack()

#endif /* DOS_RECORD_H */
