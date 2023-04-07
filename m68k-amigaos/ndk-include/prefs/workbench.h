#ifndef PREFS_WORKBENCH_H
#define PREFS_WORKBENCH_H

/*
**	$VER: workbench.h 47.3 (16.11.2021)
**
**	File format for workbench control preferences
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif

#ifndef	GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

/*****************************************************************************/

#define ID_WBNC MAKE_ID('W','B','N','C')

struct WorkbenchPrefs
{
	/* settings from workbench.library */
	ULONG wbp_DefaultStackSize;        /* in bytes */
	ULONG wbp_TypeRestartTime;         /* in seconds */
	/* settings from icon.library */
	ULONG wbp_IconPrecision;           /* PRECISION_#? values */
	struct Rectangle wbp_EmbossRect;
	BOOL wbp_Borderless;
	LONG wbp_MaxNameLength;
	BOOL wbp_NewIconsSupport;
	BOOL wbp_ColorIconSupport;
};

/* The following includes extensions from V45/Os 3.9 */
struct WorkbenchExtendedPrefs
{
  struct WorkbenchPrefs wbe_BasicPrefs;
  ULONG                 wbe_IconMemoryType;  /* exec MEMF_xxxx, obsolete */
  BOOL                  wbe_LockPens;        /* if TRUE, locks pens 4..7 with predefined colors */
  BOOL                  wbe_DisableTitleBar;
  BOOL                  wbe_DisableVolumeGauge;
  /* new for V47 */
  UWORD            	wbe_TitleUpdateDelay;  /* in milliseconds */
  ULONG            	wbe_CopyBufferSize;    /* in bytes */
  ULONG                 wbe_Flags;             /* assorted options */
};

#define ID_WBHD MAKE_ID('W','B','H','D')

struct WorkbenchHiddenDevicePrefs
{
	TEXT whdp_Name[0]; /* C String including NUL char */
};

/* New for V47 */
#define ID_WBTF MAKE_ID('W','B','T','F')

struct WorkbenchTitleFormatPrefs
{
	TEXT wtfp_Format[0];
};

/*****************************************************************************/

#endif /* PREFS_WORKBENCH_H */
