#ifndef IMAGES_BEVEL_H
#define IMAGES_BEVEL_H

/*
	bevel.image definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_IMAGECLASS_H
# include <intuition/imageclass.h>
#endif


/* Attributes defined by bevel.image */

#define BEVEL_Dummy        (REACTION_Dummy + 0x16000)
#define BEVEL_Style        (BEVEL_Dummy + 1)
#define BEVEL_Label        (BEVEL_Dummy + 3)
#define BEVEL_LabelImage   (BEVEL_Dummy + 4)
#define BEVEL_LabelPlace   (BEVEL_Dummy + 5)
#define BEVEL_InnerTop     (BEVEL_Dummy + 6)
#define BEVEL_InnerLeft    (BEVEL_Dummy + 7)
#define BEVEL_InnerWidth   (BEVEL_Dummy + 8)
#define BEVEL_InnerHeight  (BEVEL_Dummy + 9)
#define BEVEL_HorizSize    (BEVEL_Dummy + 10)
#define BEVEL_HorzSize     (BEVEL_HorizSize)
#define BEVEL_VertSize     (BEVEL_Dummy + 11)
#define BEVEL_FillPen      (BEVEL_Dummy + 12)
#define BEVEL_FillPattern  (BEVEL_Dummy + 13)
#define BEVEL_TextPen      (BEVEL_Dummy + 14)
#define BEVEL_Transparent  (BEVEL_Dummy + 15)
#define BEVEL_SoftStyle    (BEVEL_Dummy + 16)
#define BEVEL_ColorMap     (BEVEL_Dummy + 17)
#define BEVEL_ColourMap    (BEVEL_ColorMap)
#define BEVEL_Flags        (BEVEL_Dummy + 18)


/* BEVEL_Style styles */

#define BVS_THIN         0
#define BVS_BUTTON       1
#define BVS_GROUP        2
#define BVS_FIELD        3
#define BVS_NONE         4
#define BVS_DROPBOX      5
#define BVS_SBAR_HORIZ   6
#define BVS_SBAR_VERT    7
#define BVS_BOX          8
#define BVS_FOCUS        9
#define BVS_RADIOBUTTON  10
#define BVS_STANDARD     11

/*** OBSOLETE ***/

#define BVS_SBAR_HORZ    BVS_SBAR_HORIZ


/* BEVEL_Flags */

#define BFLG_XENFILL  0x01
#define BFLG_TRANS    0x02


/* BEVEL_LabelPlace values */

#define BVJ_TOP_CENTER  0
#define BVJ_TOP_LEFT    1
#define BVJ_TOP_RIGHT   2
#define BVJ_IN_CENTER   3
#define BVJ_IN_LEFT     4
#define BVJ_IN_RIGHT    5
#define BVJ_BOT_CENTER  6
#define BVJ_BOT_LEFT    7
#define BVJ_BOT_RIGHT   8


#endif /* IMAGES_BEVEL_H */
