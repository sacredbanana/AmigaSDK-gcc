#ifndef PREFS_SCREENMODE_H
#define PREFS_SCREENMODE_H

/*
	screenmode prefs definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#pragma pack(2)


#define ID_SCRM  MAKE_ID('S','C','R','M')


struct ScreenModePrefs
{
	ULONG smp_Reserved[4];
	ULONG smp_DisplayID;
	UWORD smp_Width;
	UWORD smp_Height;
	UWORD smp_Depth;
	UWORD smp_Control;
};


#define SMB_AUTOSCROLL  0

#define SMF_AUTOSCROLL  (1<<SMB_AUTOSCROLL)


#pragma pack()

#endif /* PREFS_SCREENMODE_H */
