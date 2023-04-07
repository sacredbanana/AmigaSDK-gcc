#ifndef PREFS_WBPATTERN_H
#define PREFS_WBPATTERN_H
/*
**	$VER: wbpattern.h 47.1 (2.8.2019)
**
**	File format for wbpattern preferences
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

/*****************************************************************************/

#define ID_PTRN MAKE_ID('P','T','R','N')

/*****************************************************************************/

struct WBPatternPrefs
{
    ULONG	 wbp_Reserved[4];
    UWORD	 wbp_Which;			/* Which pattern is it */
    UWORD	 wbp_Flags;
    BYTE 	 wbp_Revision;			/* Must be set to zero */
    BYTE 	 wbp_Depth;			/* Depth of pattern */
    UWORD	 wbp_DataLength;		/* Length of following data */
};

/*****************************************************************************/

/* constants for WBPatternPrefs.wbp_Which */
#define	WBP_ROOT	0
#define	WBP_DRAWER	1
#define	WBP_SCREEN	2

/* wbp_Flags values */
#define	WBPF_PATTERN	0x0001
	/* Data contains a pattern */

#define	WBPF_NOREMAP	0x0010
	/* Don't remap the pattern */

#define WBPF_DITHER_MASK		0x0300
	/* Mask for dithering flags */

/* PDTA_DitherQuality: see pictureclass.h */
#define	WBPF_DITHER_DEF			0x0000 /* DitherQuality: Default */
#define	WBPF_DITHER_BAD			0x0100 /* DitherQuality: 0 */
#define	WBPF_DITHER_GOOD		0x0200 /* DitherQuality: 2 */
#define	WBPF_DITHER_BEST		0x0300 /* DitherQuality: 4 */

/*
** The following were added in V47
** How to place graphics.
*/
#define WBPF_PLACEMENT_MASK      0x3000
#define WBPF_PLACEMENT_TILE      0x0000
#define WBPF_PLACEMENT_CENTER    0x1000
#define WBPF_PLACEMENT_SCALE     0x2000
#define WBPF_PLACEMENT_SCALEGOOD 0x3000

/*
** Alignment of the image for pattern
** Currently ignored
*/
#define WBPF_ALIGNMENT_MASK        0xC000
#define WBPF_ALIGNMENT_MIDDLE      0x0000
#define WBPF_ALIGNMENT_LEFTTOP     0x4000
#define WBPF_ALIGNMENT_RIGHTBOTTOM 0x8000

#define WBPF_PRECISION_MASK			0x0C00
	/* Mask for color matching precision flags */

/* OBP_Precision: see pictureclass.h */
#define	WBPF_PRECISION_DEF		0x0000
#define	WBPF_PRECISION_ICON		0x0400
#define	WBPF_PRECISION_IMAGE	0x0800
#define	WBPF_PRECISION_EXACT	0x0C00

/*****************************************************************************/

#define MAXDEPTH	3	/*  Max depth supported (8 colors) */
#define DEFPATDEPTH	2	/*  Depth of default patterns */

/*  Pattern width & height: */
#define PAT_WIDTH	16
#define PAT_HEIGHT	16

/*****************************************************************************/

#endif /* PREFS_WBPATTERN_H */
