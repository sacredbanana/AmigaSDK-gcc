#ifndef PREFS_OVERSCAN_H
#define PREFS_OVERSCAN_H
/*
**	$VER: overscan.h 47.1 (2.8.2019)
**
**	File format for overscan preferences
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

#ifndef GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif


/*****************************************************************************/


#define ID_OSCN MAKE_ID('O','S','C','N')

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

/* os_HStart, os_HStop, os_VStart, os_VStop can only be looked at if
 * os_Magic equals OSCAN_MAGIC. If os_Magic is set to any other value,
 * these four fields are undefined
 */


/*****************************************************************************/


#endif /* PREFS_OVERSCAN_H */
