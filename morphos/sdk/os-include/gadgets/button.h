#ifndef GADGETS_BUTTON_H
#define GADGETS_BUTTON_H

/*
	button.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif

#ifndef IMAGES_BEVEL_H
# include <images/bevel.h>
#endif


/* Attributes defined by button.gadget */

#define BUTTON_Dummy              (TAG_USER + 0x04000000)
#define BUTTON_PushButton         (BUTTON_Dummy + 1)
#define BUTTON_Glyph              (BUTTON_Dummy + 2)

#define BUTTON_TextPen            (BUTTON_Dummy + 5)
#define BUTTON_FillPen            (BUTTON_Dummy + 6)
#define BUTTON_FillTextPen        (BUTTON_Dummy + 7)
#define BUTTON_BackgroundPen      (BUTTON_Dummy + 8)

#define BUTTON_RenderImage        (GA_Image)
#define BUTTON_SelectImage        (GA_SelectRender)

#define BUTTON_BevelStyle         (BUTTON_Dummy + 13)

#define BUTTON_Transparent        (BUTTON_Dummy + 15)
#define BUTTON_Justification      (BUTTON_Dummy + 16)
#define BUTTON_SoftStyle          (BUTTON_Dummy + 17)
#define BUTTON_AutoButton         (BUTTON_Dummy + 18)
#define BUTTON_VarArgs            (BUTTON_Dummy + 19)
#define BUTTON_DomainString       (BUTTON_Dummy + 20)
#define BUTTON_Integer            (BUTTON_Dummy + 21)
#define BUTTON_BitMap             (BUTTON_Dummy + 22)

#define BUTTON_AnimButton         (BUTTON_Dummy + 50)
#define BUTTON_AnimImages         (BUTTON_Dummy + 51)
#define BUTTON_SelAnimImages      (BUTTON_Dummy + 52)
#define BUTTON_MaxAnimImages      (BUTTON_Dummy + 53)
#define BUTTON_AnimImageNumber    (BUTTON_Dummy + 54)
#define BUTTON_AddAnimImageNumber (BUTTON_Dummy + 55)
#define BUTTON_SubAnimImageNumber (BUTTON_Dummy + 56)


/* BUTTON_Justification modes */

#define BCJ_LEFT    0
#define BCJ_CENTER  1
#define BCJ_RIGHT   2

/* Language fix */

#define BCJ_CENTRE BCJ_CENTER


/* BUTTON_AutoButton glyphs */

#define BAG_POPFILE     1
#define BAG_POPDRAWER   2
#define BAG_POPFONT     3
#define BAG_CHECKBOX    4
#define BAG_CANCELBOX   5
#define BAG_UPARROW     6
#define BAG_DNARROW     7
#define BAG_RTARROW     8
#define BAG_LFARROW     9
#define BAG_POPTIME     10
#define BAG_POPSCREEN   11
#define BAG_POPUP       12


#endif /* GADGETS_BUTTON_H */
