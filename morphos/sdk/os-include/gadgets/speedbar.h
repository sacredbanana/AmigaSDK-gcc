#ifndef GADGETS_SPEEDBAR_H
#define GADGETS_SPEEDBAR_H

/*
	speedbar.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* speedbar.gadget node attributes */

#define SBNA_Dummy      (TAG_USER + 0x010000)
#define SBNA_Left       (SBNA_Dummy + 1)
#define SBNA_Top        (SBNA_Dummy + 2)
#define SBNA_Width      (SBNA_Dummy + 3)
#define SBNA_Height     (SBNA_Dummy + 4)
#define SBNA_UserData   (SBNA_Dummy + 5)
#define SBNA_Enabled    (SBNA_Dummy + 6)
#define SBNA_Spacing    (SBNA_Dummy + 7)
#define SBNA_Highlight  (SBNA_Dummy + 8)
#define SBNA_Image      (SBNA_Dummy + 9)
#define SBNA_SelImage   (SBNA_Dummy + 10)
#define SBNA_Help       (SBNA_Dummy + 11)
#define SBNA_Toggle     (SBNA_Dummy + 12)
#define SBNA_Selected   (SBNA_Dummy + 13)
#define SBNA_MXGroup    (SBNA_Dummy + 14)
#define SBNA_Disabled   (SBNA_Dummy + 15)


/* SBNA_Highlight modes */

#define SBH_NONE      0
#define SBH_BACKFILL  1
#define SBH_RECESS    2
#define SBH_IMAGE     3


/* Attributes defined by speedbar.gadget */

#define SPEEDBAR_Dummy         (REACTION_Dummy + 0x13000)
#define SPEEDBAR_Buttons       (SPEEDBAR_Dummy + 1)
#define SPEEDBAR_Orientation   (SPEEDBAR_Dummy + 2)
#define SPEEDBAR_Background    (SPEEDBAR_Dummy + 3)
#define SPEEDBAR_Window        (SPEEDBAR_Dummy + 4)
#define SPEEDBAR_StrumBar      (SPEEDBAR_Dummy + 5)
#define SPEEDBAR_OnButton      (SPEEDBAR_Dummy + 6)
#define SPEEDBAR_OffButton     (SPEEDBAR_Dummy + 7)
#define SPEEDBAR_ScrollLeft    (SPEEDBAR_Dummy + 8)
#define SPEEDBAR_ScrollRight   (SPEEDBAR_Dummy + 9)
#define SPEEDBAR_Top           (SPEEDBAR_Dummy + 10)
#define SPEEDBAR_Visible       (SPEEDBAR_Dummy + 11)
#define SPEEDBAR_Total         (SPEEDBAR_Dummy + 12)
#define SPEEDBAR_Help          (SPEEDBAR_Dummy + 13)
#define SPEEDBAR_BevelStyle    (SPEEDBAR_Dummy + 14)
#define SPEEDBAR_Selected      (SPEEDBAR_Dummy + 15)
#define SPEEDBAR_SelectedNode  (SPEEDBAR_Dummy + 16)
#define SPEEDBAR_EvenSize      (SPEEDBAR_Dummy + 17)


/* SPEEDBAR_Orientation modes */

#define SBORIENT_HORIZ  0
#define SBORIENT_VERT   1

/*** OBSOLETE ***/

#define SPEEDBAR_HORIZONTAL  SBORIENT_HORIZ
#define SPEEDBAR_VERTICAL    SBORIENT_VERT


#endif /* GADGETS_SPEEDBAR_H */
