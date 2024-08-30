#ifndef LIBRARIES_BLANKERMODULE_H
#define LIBRARIES_BLANKERMODULE_H
/*
**  $VER: blankermodule.h 54.16 (22.08.2022)
**
**	Structure and method definitions for the blankermodule library system.
**
**  Author: Stefan Robl <stefan@qdev.de>
**
**   (c) Copyright 2005 Amiga, Inc.
**       All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifndef	INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif


/******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/


#define BLANKERMODULEVERSION            ((uint32)(((  53  )<<16)|(  1  )))
#define BLANKERMODULE_GADGET_STARTID    0x8000

struct BlankerRender
{
	struct Task *task;
	uint32 taskSigBreak;
	
	struct Screen *screen;   // may be NULL in case of the preview
	struct RastPort *rp;     // RastPort where the image data has to be rendered to
	struct Layer *layer;
	struct Hook *renderHook;
	uint32 colorTableSize;   // number of entries within the color table
	uint32 *colorTable;      // colorTable -> array of uint32 (0xAARRGGBB order)

	uint32 screenWidth;      // if in preview mode, this width/height gives you an idea about the 
	uint32 screenHeight;     // screen size the blanker will have render in the real mode
		
	uint32 blankWidth;       // this is the actual with/height of the drawing
	uint32 blankHeight;      // context allocated for the blanker
	
	BOOL isPreview;          // TRUE if the blanker has to render in preview mode

	/* New for V53 */
	uint32 *colorPenTable;   // Array of pens corresponding to colorTable ARGB colors
};

struct BlankerPrefsWinGUIEvent
{
	Object *winObject;
	uint32 result;
	uint16 code;
};

struct BlankerPrefsWinIDCMPEvent
{
	APTR obj;
	struct IntuiMessage *msg;
};

struct BlankerPrefsWindowSetup
{
	uint32 winWidth;
	uint32 winHeight;
	struct Hook *eventHook;     // your own event hook for gadget events
	struct Hook *idcmpHook;     // your own idcmp hook
	struct Hook *mainIDCMPHook; // this one is set by the framework (you might need it)
	uint32 idcmpHookBits;
	Object *rootLayout;
};

struct BlankerPrefsWindowInfo
{
	Object *object;
	struct Window *window;
};

enum enBlankerModuleRenderMode
{
	BMRM_CustomScreen    = 0, // the module handles it's own screen
	BMRM_RastPortHiColor = 1, // RastPort rendering using >=15 bit/pixel
};

enum enBlankerModuleColorTableType
{
	BMCTT_None           = 0,
	BMCTT_Rainbow        = 1,
	BMCTT_Grayscale      = 2,
};

enum enBlankerModulePreferencesType
{
	BMPT_None      = 0,
	BMPT_Framework = 1,
	BMPT_Custom    = 2,
};

enum enBlankerModuleGet
{
	BMGET_Version             =  1, // uint32 (returns the module's BLANKERMODULEVERSION)
	BMGET_ModuleAuthorInfo    =  2, // CONST_STRPTR (for example "Stefan Robl <stefan@qdev.de>") 
	BMGET_ModuleVersionInfo   =  3, // CONST_STRPTR (for example "Test.blanker 51.1 (16.11.2005)")
	
	// ----
	
	BMGET_RenderMode          =  4, // uint32 (one of enBlankerModuleRenderMode)
	BMGET_NeedsDoubleBuffer   =  5, // uint32 BOOL (doubles the height of the opened screen)
	BMGET_ColorTableType      =  6, // uint32 enBlankerModuleColorTableType
	
	// ----
	
	BMGET_PreferencesType     =  7, // uint32 (one of enBlankerModulePreferencesType)
	BMGET_Preferences         =  8, // PrefsObject *
};

enum enRenderHookMessages
{
	BMRHM_FrameRendered       =  1, // uint32 bufferNr
};

enum enBlankerModuleSet
{
	BMSET_BlankerRender       =  1, // struct BlankerRender *
	BMSET_BlankingMode        =  2, // enScreenBlankerBlankingModes (from screenblanker.h)
	
	// ----
	
	BMSET_Preferences         =  3, // PrefsObject *
	BMSET_OpenPrefsWindow     =  4, // struct BlankerPrefsWindowSetup *
	BMSET_ClosePrefsWindow    =  5, // -
	BMSET_PrefsWindowInfo     =  6, // struct BlankerPrefsWindowInfo *
	BMSET_UseDefaultSettings  =  7, // -
};


/******************************************************************************/

#ifdef __cplusplus
}
#endif

/******************************************************************************/

#endif    /*  LIBRARIES_BLANKERMODULE_H  */
