#ifndef PREFS_WBPATTERN_H
#define PREFS_WBPATTERN_H

/*
	wbpattern prefs definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#pragma pack(2)


#define ID_PTRN  MAKE_ID('P','T','R','N')


struct WBPatternPrefs
{
	ULONG wbp_Reserved[4];
	UWORD wbp_Which;
	UWORD wbp_Flags;
	BYTE  wbp_Revision;
	BYTE  wbp_Depth;
	UWORD wbp_DataLength;
};


#define WBP_ROOT    0
#define WBP_DRAWER  1
#define WBP_SCREEN  2

#define WBPF_PATTERN  0x0001
#define WBPF_NOREMAP  0x0010


#define MAXDEPTH     3
#define DEFPATDEPTH  2

#define PAT_WIDTH   16
#define PAT_HEIGHT  16


/*** V44 ***/

#define WBPF_DITHER_MASK          0x0300
#define WBPF_DITHER_DEF           0x0000
#define WBPF_DITHER_BAD           0x0100
#define WBPF_DITHER_GOOD          0x0200
#define WBPF_DITHER_BEST          0x0300

#define WBPF_PRECISION_MASK       0x0C00
#define WBPF_PRECISION_DEF        0x0000
#define WBPF_PRECISION_ICON       0x0400
#define WBPF_PRECISION_IMAGE      0x0800
#define WBPF_PRECISION_EXACT      0x0C00


/*** V45 ***/

#define WBPF_PLACEMENT_MASK       0x3000
#define WBPF_PLACEMENT_TILE       0x0000
#define WBPF_PLACEMENT_CENTER     0x1000
#define WBPF_PLACEMENT_SCALE      0x2000
#define WBPF_PLACEMENT_SCALEGOOD  0x3000


#pragma pack()

#endif /* PREFS_WBPATTERN_H */
