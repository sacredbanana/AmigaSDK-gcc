#ifndef PREFS_CON_H
#define PREFS_CON_H
/*
**  $VER: console.h 54.16 (22.08.2022)
**
**  File format for Console preferences
**
**  Copyright (C) 1985-2009 Hyperion Entertainment CVBA.
**      All Rights Reserved
*/

/*****************************************************************************/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

/*****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/*****************************************************************************/

#define	MAX_TAB_HEADING_LENGTH		128			// Tab heading length
#define	MAX_HISTORY_DRAWER_LENGTH	128			// directory name size
#define	MAX_FONT_LENGTH				128			// font string

#define	ID_CONP	MAKE_ID('C','O','N','P')

struct	ConsolePrefs							// prefs file contents
{
	uint16	Version;							// version of Prefs/Console
	uint16	Revision;							// revision of Prefs/Console
	uint32	CommandSize;						// command buffer size, kB
	uint32	MaxHistorySize;						// max rows in History

//	chooser values
	uint16	CursorType;							// block/underline/bar
	uint16	CursorBlink;						// none/slow/fast

	uint16	TabSpacing;							// 4, 8, etc
	uint16	Palette;							// 0 to 3
	uint16	FGColor;							// 0 to 7
	uint16	BGColor;							// 0 to 7
	uint32	User0FGColors[8],					// default foreground
			User0BGColors[8];					// and background

//	chooser values
	int16	Completion;							// inline/popup
	int16	Beep;								// never/no match/multiple/last
	int16	SortOrder;							// files/mixed/dirs first

	int16	SaveHistory;						// none/text buffer/session
	int16	UseSettings;						// current/future
	int16	ChangeShells;						// front/all

	uint32	Flags;								// replaces Booleans

	TEXT	TabHeading[MAX_TAB_HEADING_LENGTH + 2];
	TEXT	HistoryDrawer[MAX_HISTORY_DRAWER_LENGTH + 2];
	struct	TextAttr	FontAttr;				// font descriptors
	TEXT	FontName[MAX_FONT_LENGTH + 2];		// font name
};

/*****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/*****************************************************************************/

#endif /* PREFS_CON_H */
