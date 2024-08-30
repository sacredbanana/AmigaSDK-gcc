#ifndef INTUITION_SCREENBAR_H
#define INTUITION_SCREENBAR_H

/*
	intuition screenbar plugin definitions

	Copyright © 2007-2010 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#ifndef LIBRARIES_MUI_H
# include <libraries/mui.h>
#endif

/* Creates a cfgid x from your tagbase. Set isstring to 1 if the config item is textual 
** Otherwise it will be stored as ULONG (4 bytes) */
#define MUI_CFGID(tagbase,isstring,x) ( (((tagbase)<<16) & 0x7fffffff) | 0x00008000 | ((isstring)<<14) | (x) )

/* Please obtain your own MUI serial number if you wish to develop screenbar classes! */
#define MUISERIALNO_INTUITION 0xFECF
#define TAGBASE_SCREENBAR ((TAG_USER | (MUISERIALNO_INTUITION << 16)) + 3000)

#define MUIA_Screenbar_DisplayedName      (TAGBASE_SCREENBAR + 2)
/* Returns a CONST_STRPTR containing a displayable name of the sbar. This is optional. If missing,
** the class name will be used. You should generally localise this string. The result will be copied. */

#define MUIA_Screenbar_DisplayedImage     (TAGBASE_SCREENBAR + 3)
/* Returns an image object that will be used to draw the image in the Settings window. This is exactly
** the same as implementing the MCC_Query(2) call in your MCC. The object will be disposed when it's
** no longer needed, no later than the last instance of the class is disposed */

/* In order to support user preferences in your screenbar plugin, implement all of the following methods: */

#define MUIM_Screenbar_BuildSettingsPanel (TAGBASE_SCREENBAR + 20)
/* Builds a settings panel, inheriting from MUIC_Mccprefs and returns the pointer to the
** prefs object. All classes must implement this, even if it's just to hold the (C) info. */

#define MUIM_Screenbar_KnowsConfigItem    (TAGBASE_SCREENBAR + 21)
/* Return TRUE if msg->cfgid is one of your prefs CFGIDs, otherwise false */

#define MUIM_Screenbar_DefaultConfigItem  (TAGBASE_SCREENBAR + 22)
/* Return a default value for a cfgid */

#define MUIM_Screenbar_UpdateConfigItem   MUIM_UpdateConfig
/* This method will be called whenever preferences are updated */

#define MUIM_Screenbar_Lock               (TAGBASE_SCREENBAR + 24)
/* Locks the screenbar so that it does not disappear when you need it
** you should generally always lock it if you pop a context menu up, 
** open a popup window, etc */

#define MUIM_Screenbar_Unlock             (TAGBASE_SCREENBAR + 25)

#define MUIM_Screenbar_Signal             (TAGBASE_SCREENBAR + 26)
/* Implement this if you need to handle signals in your sbar plugin.
** The method is called on all sbar instances when a common signal
** arrives to the application controlling the screenbars.
** Check screens.h to find out how to get the common signal bit. */

struct MUIP_Screenbar_BuildSettingsPanel {ULONG id;};
struct MUIP_Screenbar_KnowsConfigItem {ULONG id; ULONG cfgid;};
struct MUIP_Screenbar_DefaultConfigItem {ULONG id; ULONG cfgid;};
#define MUIP_Screenbar_UpdateConfigItem MUIP_UpdateConfig
struct MUIP_Screenbar_Lock {ULONG id;};
struct MUIP_Screenbar_Unlock {ULONG id;};
struct MUIP_Screenbar_Signal {ULONG id;};

/* ScreenbarControl tags */
#define SBCT_Dummy                    (TAG_USER + 0x60500)
#define SBCT_InstallPlugin            (SBCT_Dummy + 1)

/* struct MUI_CustomClass *,mcc_Class->cl_ID must contain a valid name
** with ascii letters only */

#define SBCT_UninstallPlugin          (SBCT_Dummy + 2)
/* struct MUI_CustomClass * */

#endif /* INTUITION_SCREENBAR_H */
