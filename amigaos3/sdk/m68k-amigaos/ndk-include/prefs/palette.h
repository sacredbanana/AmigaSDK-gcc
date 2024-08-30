#ifndef PREFS_PALETTE_H
#define PREFS_PALETTE_H
/*
**	$VER: palette.h 47.1 (2.8.2019)
**
**	File format for palette preferences
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

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif


/*****************************************************************************/


#define ID_PALT MAKE_ID('P','A','L','T')


struct PalettePrefs
{
    LONG             pap_Reserved[4];	 /* System reserved                */
    UWORD            pap_4ColorPens[32];
    UWORD            pap_8ColorPens[32];
    struct ColorSpec pap_Colors[32];     /* Used as full 16-bit RGB values */
};


/*****************************************************************************/


#endif /* PREFS_PALETTE_H */
