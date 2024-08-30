#ifndef GADGETS_GETFONT_H
#define GADGETS_GETFONT_H

/*
	getfont.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif

#pragma pack(2)


/* Attributes defined by getfont.gadget */

#define GETFONT_Dummy           (REACTION_Dummy + 0x40000)
#define GETFONT_TextAttr        (GETFONT_Dummy + 1)
#define GETFONT_DoFrontPen      (GETFONT_Dummy + 2)
#define GETFONT_DoBackPen       (GETFONT_Dummy + 3)
#define GETFONT_DoStyle         (GETFONT_Dummy + 4)
#define GETFONT_DoDrawMode      (GETFONT_Dummy + 5)
#define GETFONT_MinHeight       (GETFONT_Dummy + 6)
#define GETFONT_MaxHeight       (GETFONT_Dummy + 7)
#define GETFONT_FixedWidthOnly  (GETFONT_Dummy + 8)
#define GETFONT_TitleText       (GETFONT_Dummy + 9)
#define GETFONT_Height          (GETFONT_Dummy + 10)
#define GETFONT_Width           (GETFONT_Dummy + 11)
#define GETFONT_LeftEdge        (GETFONT_Dummy + 12)
#define GETFONT_TopEdge         (GETFONT_Dummy + 13)
#define GETFONT_FrontPen        (GETFONT_Dummy + 14)
#define GETFONT_BackPen         (GETFONT_Dummy + 15)
#define GETFONT_DrawMode        (GETFONT_Dummy + 16)
#define GETFONT_MaxFrontPen     (GETFONT_Dummy + 17)
#define GETFONT_MaxBackPen      (GETFONT_Dummy + 18)
#define GETFONT_ModeList        (GETFONT_Dummy + 19)
#define GETFONT_FrontPens       (GETFONT_Dummy + 20)
#define GETFONT_BackPens        (GETFONT_Dummy + 21)
#define GETFONT_SoftStyle       (GETFONT_Dummy + 22)


/* getfont.gadget methods */

#define GFONT_REQUEST  (0x600001L)


struct gfRequest
{
	ULONG          MethodID;
	struct Window *gfr_Window;
};


/* Useful macros */

#define gfRequestFont(obj, win)  DoMethod(obj, GFONT_REQUEST, win)


#pragma pack()

#endif /* GADGETS_GETFONT_H */
