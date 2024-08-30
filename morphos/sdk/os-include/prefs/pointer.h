#ifndef PREFS_POINTER_H
#define PREFS_POINTER_H

/*
	pointer prefs definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#pragma pack(2)


#define ID_PNTR  MAKE_ID('P','N','T','R')


struct PointerPrefs
{
	ULONG pp_Reserved[4];
	UWORD pp_Which;
	UWORD pp_Size;
	UWORD pp_Width;
	UWORD pp_Height;
	UWORD pp_Depth;
	UWORD pp_YSize;
	UWORD pp_X, pp_Y;
};


#define WBP_NORMAL  0
#define WBP_BUSY    1


struct RGBTable
{
	UBYTE t_Red;
	UBYTE t_Green;
	UBYTE t_Blue;
};


#pragma pack()

#endif /* PREFS_POINTER_H */
