#ifndef IMAGES_LABEL_H
#define IMAGES_LABEL_H
/*
**	$VER: label.h 47.5 (16.11.2021)
**
**	Definitions for the Label BOOPSI class
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef INTUITION_IMAGECLASS_H
#include <intuition/imageclass.h>
#endif


/*****************************************************************************/

/* Justification modes.
 */
#define LJ_LEFT 0
#define LJ_CENTRE 1
#define LJ_RIGHT 2

/* For those that can't spell :)
 */
#define LJ_CENTER LJ_CENTRE

/* Obsolete, DON'T USE THESE!
 */
#define LABEL_LEFT LJ_LEFT
#define LABEL_CENTRE LJ_CENTRE
#define LABEL_CENTER LJ_CENTRE
#define LABEL_RIGHT LJ_RIGHT

/* Vertical alignment types (OS4ONLY).
 */
#define LVALIGN_BOTTOM   0
#define LVALIGN_BASELINE 1

/*****************************************************************************/

/* Additional attributes defined by the Label class
 */
#define LABEL_Dummy				(REACTION_Dummy+0x0006000)

#define	LABEL_DrawInfo				SYSIA_DrawInfo

#define	LABEL_Text				(LABEL_Dummy+1)
	/* (STRPTR) Text to print in the label. */

#define	LABEL_Image				(LABEL_Dummy+2)
	/* (struct Image *) Image to print in the label. */

#define	LABEL_Mapping				(LABEL_Dummy+3)
	/* (UWORD *) Mapping array for the next image. */

#define	LABEL_Justification			(LABEL_Dummy+4)
	/* (UWORD) Justification modes (see above) */

#define	LABEL_Key				(LABEL_Dummy+5)
	/* (UWORD) Returns the underscored key (if any) */

#define	LABEL_Underscore			(LABEL_Dummy+6)
	/* (TEXT) Defaults to '_'. */

#define	LABEL_DisposeImage			(LABEL_Dummy+7)
	/* (BOOL) Defaults to FALSE. */

#define	LABEL_SoftStyle				(LABEL_Dummy+8)
	/* (UBYTE) Defaults to none. */

#define	LABEL_VerticalSpacing			(LABEL_Dummy+9)
	/* (UWORD) Vertical spacing between text lines. Defaults to 0. */

#define LABEL_VerticalAlignment			(LABEL_Dummy+10) /* OS4ONLY */

#define LABEL_WordWrap				(LABEL_Dummy+11) /* OS4ONLY */

#define LABEL_MenuMode				(LABEL_Dummy+12) /* OS4ONLY */

/*****************************************************************************/

#endif /* IMAGES_LABEL_H */
