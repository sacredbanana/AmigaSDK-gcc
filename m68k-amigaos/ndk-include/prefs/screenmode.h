#ifndef PREFS_SCREENMODE_H
#define PREFS_SCREENMODE_H
/*
**	$VER: screenmode.h 47.1 (2.8.2019)
**
**	File format for screen mode preferences
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


#define ID_SCRM MAKE_ID('S','C','R','M')


struct ScreenModePrefs
{
    ULONG smp_Reserved[4];
    ULONG smp_DisplayID;
    UWORD smp_Width;
    UWORD smp_Height;
    UWORD smp_Depth;
    UWORD smp_Control;
};

/* flags for ScreenModePrefs.smp_Control */
#define SMB_AUTOSCROLL 1

#define SMF_AUTOSCROLL (1<<0)


/*****************************************************************************/


#endif /* PREFS_SCREENMODE_H */
