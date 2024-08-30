#ifndef DEVICES_CONSOLE_H
#define DEVICES_CONSOLE_H
/*
**      $VER: console.h 53.23 (8.06.2010)
**
**      Console device command definitions
**
**    Copyright (C) 1985-2009 Hyperion Entertainment CVBA.
**          All Rights Reserved
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   EXEC_IO_H
#include <exec/io.h>
#endif

#ifndef   LIBRARIES_KEYMAP_H
#include <libraries/keymap.h>
#endif

/****************************************************************************/

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

/****************************************************************************/

/****** Console commands ******/
#define CD_ASKKEYMAP          (CMD_NONSTD + 0) /* Use CD_ASKKEYMAP_POINTERS  */
#define CD_SETKEYMAP          (CMD_NONSTD + 1) /* Use CD_SETKEYMAP_POINTERS  */
#define CD_ASKDEFAULTKEYMAP   (CMD_NONSTD + 2) /* Use AskKeyMapDefault()     */
#define CD_SETDEFAULTKEYMAP   (CMD_NONSTD + 3) /* Use SetKeyMapDefault()     */
/* Leaving space for two undocumented commands of KingCON here. Oh well...   */
#define CD_ASKKEYMAP_POINTERS (CMD_NONSTD + 6) /* Added in V51.19            */
#define CD_SETKEYMAP_POINTERS (CMD_NONSTD + 7) /* Added in V51.19            */
#define	CD_GETATTRS           (CMD_NONSTD + 8) /* Added in V53.20           */
#define	CD_SETATTRS           (CMD_NONSTD + 9) /* Added in V53.20           */

/* Structure used by CD_ASKKEYMAP_POINTERS and CD_SETKEYMAP_POINTERS
 */
struct ConsoleKeyMapPointers
{
    APTR               keymapHandle;
    struct KeyMapNode *keymapNode;
    struct KeyMap     *keymap;
    APTR               reserved; /* Must be set to NULL
                                  * for CD_SETKEYMAP_POINTERS */
};

/****** SGR parameters ******/

#define SGR_PRIMARY    0
#define SGR_BOLD       1
#define SGR_ITALIC     3
#define SGR_UNDERSCORE 4
#define SGR_NEGATIVE   7

#define SGR_NORMAL        22 /* default foreground color, not bold */
#define SGR_NOTITALIC     23
#define SGR_NOTUNDERSCORE 24
#define SGR_POSITIVE      27

/* these names refer to the ANSI standard, not the implementation */
#define SGR_BLACK   30
#define SGR_RED     31
#define SGR_GREEN   32
#define SGR_YELLOW  33
#define SGR_BLUE    34
#define SGR_MAGENTA 35
#define SGR_CYAN    36
#define SGR_WHITE   37
#define SGR_DEFAULT 39

#define SGR_BLACKBG   40
#define SGR_REDBG     41
#define SGR_GREENBG   42
#define SGR_YELLOWBG  43
#define SGR_BLUEBG    44
#define SGR_MAGENTABG 45
#define SGR_CYANBG    46
#define SGR_WHITEBG   47
#define SGR_DEFAULTBG 49

/* these names refer to the implementation, they are the preferred */
/* names for use with the Amiga console device. */
#define SGR_CLR0 30
#define SGR_CLR1 31
#define SGR_CLR2 32
#define SGR_CLR3 33
#define SGR_CLR4 34
#define SGR_CLR5 35
#define SGR_CLR6 36
#define SGR_CLR7 37

#define SGR_CLR0BG 40
#define SGR_CLR1BG 41
#define SGR_CLR2BG 42
#define SGR_CLR3BG 43
#define SGR_CLR4BG 44
#define SGR_CLR5BG 45
#define SGR_CLR6BG 46
#define SGR_CLR7BG 47

/****** DSR parameters ******/
#define DSR_CPR 6

/****** CTC parameters ******/
#define CTC_HSETTAB     0
#define CTC_HCLRTAB     2
#define CTC_HCLRTABS    4
#define CTC_HCLRTABSALL 5

/****** TBC parameters ******/
#define TBC_HCLRTAB     0
#define TBC_HCLRTABSALL 3

/****** SM and RM parameters ******/
#define M_LNM  20   /* linefeed newline mode */
#define M_ASM  ">1" /* auto scroll mode */
#define M_AWM  "?7" /* auto wrap mode */

/******** Special IO Flag bits ********************/
#define	IOF_WAIT_WRITE			0x40

/******** Tags used by console, con-handler and Prefs editor, (V53.20) ******/
#define	CON_Dummy	(TAG_USER + 0x10000)

/******** SetAttrs Tags **************************/
#define	CDT_SETPALETTE			(CON_Dummy + 0)
#define	CDT_PALETTEADDRESS		(CON_Dummy + 1)
#define	CDT_SELECTPALETTE		(CON_Dummy + 2)
#define	CDT_SETTABSPACING		(CON_Dummy + 3)
#define	CDT_SETWINDOWTITLE		(CON_Dummy + 4)
#define	CDT_SETAPPWINDOWPORT	(CON_Dummy + 5)
#define	CDT_UNICONIFYWINDOW		(CON_Dummy + 6)
#define	CDT_SETNOTIFYHOOK		(CON_Dummy + 7)
#define	CDT_RESERVED1			(CON_Dummy + 8)		// obsolescent, not used
#define	CDT_HANDLER_VERSION		(CON_Dummy + 9)

/******* GetAttrs Tags ***************************/
#define	CDT_GETCONUNIT			(CON_Dummy + 100)
#define	CDT_GETPREFS			(CON_Dummy + 101)
#define	CDT_GETROWS				(CON_Dummy + 102)
#define	CDT_GETCOLUMNS			(CON_Dummy + 103)
#define	CDT_GETYCP				(CON_Dummy + 104)
#define	CDT_GETXCP				(CON_Dummy + 105)
#define	CDT_GETWINDOW			(CON_Dummy + 106)
#define	CDT_GETWINSTATE			(CON_Dummy + 107)
#define	CDT_GETTEXTSPACE		(CON_Dummy + 108)
#define	CDT_GETTEXTFONT			(CON_Dummy + 109)
#define	CDT_GETIOSTATE			(CON_Dummy + 110)
#define	CDT_CURSONSCREEN		(CON_Dummy + 111)

/****** Window parameter Tags ********************/
#define	CDT_NUMBERROWS			(CON_Dummy + 200)
#define	CDT_NUMBERCOLS			(CON_Dummy + 201)
#define	CDT_CHARSET				(CON_Dummy + 202)
#define	CDT_FORCEVISIBLE		(CON_Dummy + 203)

/****** Notification Tags, returned with Notify Hook *************/
#define	CDN_WINSTATE			(CON_Dummy + 250)
#define	CDN_NEWPREFS			(CON_Dummy + 251)
#define	CDN_CURSONSCREEN		(CON_Dummy + 252)

/******* Parameters for Select Palette tag  (V53.20) **************/
enum
{
	PALETTE_PENS		=  0,
	PALETTE_ANSI		=  1,
	PALETTE_ANSIF		=  2,
	PALETTE_USER0,
	PALETTE_USER1,
	PALETTE_USER2,
	PALETTE_USER3,
	PALETTE_USER4,
	PALETTE_USER5,
	PALETTE_USER6,
	PALETTE_USER7,
	PALETTE_USER8,
	PALETTE_USER9,
	PALETTE_USER10,
	PALETTE_USER11,
	PALETTE_USER12,
	MAX_PALETTE
};

/******** Parameters for GETWINSTATE Tag  (V53.20) *************/

/*	GetWinState returns the current state of the console window.
**	Note that the "WIN_CLOSED" state will never be returned, since the
**	Console Unit will be closed and expunged as well. The caller should
**	keep her own copy of the WinState and set it to "WIN_CLOSED" when
**	Closing the Console Unit.
*/
enum
{
	WIN_NOTOPEN = 0,		// window not opened yet
	WIN_OPEN,				// window is open for business
	WIN_ICON,				// window is currently iconified
	WIN_HIDDEN,				// hidden behind other windows in same WinFrame
	WIN_CLOSED				// window has been closed
};


/***********************************************************************/
//	Constants used by Prefs/Console, console.device and con-handler (V53.20).

//	Cursor style chooser values
enum
{
	CURSOR_BLOCK = 0,							// block cursor
	CURSOR_UNDERLINE,							// underline
	CURSOR_VERT_BAR								// vertical bar
};
#define	MIN_CURSOR_TYPE		CURSOR_BLOCK
#define	MAX_CURSOR_TYPE		CURSOR_VERT_BAR

//	Cursor blink chooser values
enum
{
	BLINK_OFF = 0,						// cursor does not blink
	BLINK_SLOW,							// blinks slowly
	BLINK_FAST							// blinks fast
};
#define	MIN_CURSOR_BLINK	BLINK_OFF
#define	MAX_CURSOR_BLINK	BLINK_FAST

#define	MIN_PALETTE			0
#define	MAX_DEF_PALETTE		3

#define	MIN_COLOR			0
#define	MAX_COLOR			7

//	Completion mode chooser values
enum
{
	COMP_INLINE = 0,					// tab-completion in line
	COMP_LIST							// pop-up list
};

//	Beep mode chooser values
enum
{
	BEEP_NEVER = 0,						// never
	BEEP_NOT_FOUND,						// if no match found
	BEEP_MULTIPLE,						// if multiple matches
	BEEP_WRAP
};

//	Name-completion sort order
enum
{
	FILES_FIRST = 0,					// files first, then dirs
	MIXED,								// mixed
	DIRS_FIRST							// dirs first, then files
};

//	Command buffer values
#define	MIN_CMD_BUFF_SIZE		16		// 16 kB min
#define	MAX_CMD_BUFF_SIZE		1024	// 1 MB max
#define	CMD_BUFF_SIZE_INC		16		// increment kB
#define	DEFAULT_CMD_BUFF_SIZE	16		// 16 kB default

//	History chooser values
enum
{
	SAVE_NONE = 0,						// keep buffer only, save nothing
	SAVE_BUFFER,						// keep buffer only, save buffer only
	SAVE_ALL							// keep whole session and save
};

//	Use Settings chooser values
enum
{
	USE_THIS_ONLY = 0,					// use in this window only
	USE_THIS_FUTURE,					// use in this and future windows
	USE_FUTURE_ONLY,					// use in future windows only
	MAX_USE_SETTINGS
};

//	Change Units chooser values
enum
{
	CHANGE_THIS_ONLY = 0,				// change this (frontmost) Unit only
	CHANGE_ALL_UNITS,					// change all Units in this window
	MAX_CHANGE_SHELLS
};

//	Flags contents
#define		BIT(x)					(1<<x)

#define		SOFT_CHAR_BLINK			BIT(0)
#define		SOFT_STRIKEOUT			BIT(1)
#define		TEXT_BEVEL				BIT(2)
#define		SHOW_INFO_FILES			BIT(3)
#define		SHOW_RES_CMDS			BIT(4)
#define		SHOW_ASSIGNS			BIT(5)

/***********************************************************************/

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

/****************************************************************************/

#endif /* DEVICES_CONSOLE_H */
