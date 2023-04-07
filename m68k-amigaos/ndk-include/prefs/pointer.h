#ifndef PREFS_POINTER_H
#define PREFS_POINTER_H
/*
**	$VER: pointer.h 47.1 (2.8.2019)
**
**	File format for pointer preferences
**
**	Copyright (C) 2019 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

/*****************************************************************************/

#define ID_PNTR MAKE_ID('P','N','T','R')

/*****************************************************************************/

struct PointerPrefs
{
    ULONG pp_Reserved[4];
    UWORD pp_Which;				/* 0=NORMAL, 1=BUSY */
    UWORD pp_Size;				/* see <intuition/pointerclass.h> */
    UWORD pp_Width;				/* Width in pixels */
    UWORD pp_Height;				/* Height in pixels */
    UWORD pp_Depth;				/* Depth */
    UWORD pp_YSize;				/* YSize */
    WORD  pp_X, pp_Y;				/* Hotspot */

    /* Color Table:  numEntries = (1 << pp_Depth) - 1 */

    /* Data follows */
};

/*****************************************************************************/

/* constants for PointerPrefs.pp_Which */
#define	WBP_NORMAL	0
#define	WBP_BUSY	1

/*****************************************************************************/

struct RGBTable
{
    UBYTE t_Red;
    UBYTE t_Green;
    UBYTE t_Blue;
};

/*****************************************************************************/

#endif /* PREFS_POINTER_H */
