#ifndef IMAGES_LABEL_H
#define IMAGES_LABEL_H

/*
	label.image definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/imageclass.h>
#endif


/* Attributes defined by label.image */

#define LABEL_Dummy            (REACTION_Dummy + 0x0006000)
#define LABEL_DrawInfo         (SYSIA_DrawInfo)
#define LABEL_Text             (LABEL_Dummy + 1)
#define LABEL_Image            (LABEL_Dummy + 2)
#define LABEL_Mapping          (LABEL_Dummy + 3)
#define LABEL_Justification    (LABEL_Dummy + 4)
#define LABEL_Key              (LABEL_Dummy + 5)
#define LABEL_Underscore       (LABEL_Dummy + 6)
#define LABEL_DisposeImage     (LABEL_Dummy + 7)
#define LABEL_SoftStyle        (LABEL_Dummy + 8)
#define LABEL_VerticalSpacing  (LABEL_Dummy + 9)


/* LABEL_Justification modes */

#define LJ_LEFT    0
#define LJ_CENTRE  1
#define LJ_RIGHT   2

/* Language fix */

#define LJ_CENTER  LJ_CENTRE

/*** OBSOLETE ***/

#define LABEL_LEFT    LJ_LEFT
#define LABEL_CENTRE  LJ_CENTRE
#define LABEL_CENTER  LJ_CENTRE
#define LABEL_RIGHT   LJ_RIGHT


#endif /* IMAGES_LABEL_H */
