#ifndef PREFS_WORKBENCH_H
#define PREFS_WORKBENCH_H

/*
	Workbench(TM) prefs definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.

	Workbench is a Registered Trademark of Commodore-Amiga, Inc.
*/

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#ifndef GRAPHICS_GFX_H
# include <graphics/gfx.h>
#endif

#pragma pack(2)


#define ID_WBNC  MAKE_ID('W','B','N','C')
#define ID_WBHD  MAKE_ID('W','B','H','D')


struct WorkbenchPrefs
{
	ULONG            wbp_DefaultStackSize;
	ULONG            wbp_TypeRestartTime;
	ULONG            wbp_IconPrecision;
	struct Rectangle wbp_EmbossRect;
	BOOL             wbp_Borderless;
	LONG             wbp_MaxNameLength;
	BOOL             wbp_NewIconsSupport;
	BOOL             wbp_ColorIconSupport;

	/*** V45 ***/

	ULONG            wbp_ImageMemType;
	BOOL             wbp_LockPens;
	BOOL             wbp_NoTitleBar;
	BOOL             wbp_NoGauge;
};


struct WorkbenchHiddenDevicePrefs
{
	UBYTE whdp_Name[0];
};


#pragma pack()

#endif /* PREFS_WORKBENCH_H */
