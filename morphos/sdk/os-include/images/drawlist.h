#ifndef IMAGES_DRAWLIST_H
#define IMAGES_DRAWLIST_H

/*
	drawlist.image definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_IMAGECLASS_H
# include <intuition/imageclass.h>
#endif

#pragma pack(2)


/* Attributes defined by drawlist.image */

#define DRAWLIST_Dummy       (REACTION_Dummy + 0x17000)
#define DRAWLIST_Directives  (DRAWLIST_Dummy + 1)
#define DRAWLIST_RefHeight   (DRAWLIST_Dummy + 2)
#define DRAWLIST_RefWidth    (DRAWLIST_Dummy + 3)
#define DRAWLIST_DrawInfo    (DRAWLIST_Dummy + 4)


/* drawlist.image primitives */

#define DLST_END       0

#define DLST_LINE      1
#define DLST_RECT      2
#define DLST_FILL      3
#define DLST_ELLIPSE   4
#define DLST_CIRCLE    5
#define DLST_LINEPAT   6
#define DLST_FILLPAT   7
#define DLST_AMOVE     8
#define DLST_ADRAW     9
#define DLST_AFILL     10
#define DLST_BEVELBOX  11
#define DLST_ARC       12
#define DLST_START     13
#define DLST_BOUNDS    13
#define DLST_LINESIZE  14


struct DrawList
{
	WORD  dl_Directive;
	UWORD dl_X1, dl_Y1;
	UWORD dl_X2, dl_Y2;
	WORD  dl_Pen;
};


#pragma pack()

#endif /* IMAGES_DRAWLIST_H */
