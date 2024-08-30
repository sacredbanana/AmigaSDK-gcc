#ifndef PREFS_OVERSCAN_H
#define PREFS_OVERSCAN_H

/*
	overscan prefs definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef LIBRARIES_IFFPARSE_H
# include <libraries/iffparse.h>
#endif

#ifndef GRAPHICS_GFX_H
# include <graphics/gfx.h>
#endif

#pragma pack(2)


#define ID_OSCN  MAKE_ID('O','S','C','N')

#define OSCAN_MAGIC  0xFEDCBA89


struct OverscanPrefs
{
	ULONG            os_Reserved;
	ULONG            os_Magic;
	UWORD            os_HStart;
	UWORD            os_HStop;
	UWORD            os_VStart;
	UWORD            os_VStop;
	ULONG            os_DisplayID;
	Point            os_ViewPos;
	Point            os_Text;
	struct Rectangle os_Standard;
};


#pragma pack()

#endif /* PREFS_OVERSCAN_H */
