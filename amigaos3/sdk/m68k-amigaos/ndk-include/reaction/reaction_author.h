#ifndef REACTION_AUTHOR_H
#define REACTION_AUTHOR_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/*
**	$VER: reaction_author.h 44.1 (17.7.99)
**
**	Copyright (c) 1999 Christopher E. Aldi
**	  All Rights Reserved.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifndef REACTION_Dummy
#define REACTION_Dummy 			(TAG_USER + 0x5000000)
#endif

/* The tags below are used internally to layout and others
 * classes to make some magic happen. They are not intended for your
 * general usage.
 */

#define REACTION_TextAttr		(REACTION_Dummy + 5)
 /* (struct TextAttr *) Class private tag set internally by layout
  * only. This tag sets a gadgets font, but does NOT override GA_TextAttr!
  */

#define REACTION_ChangePrefs	(REACTION_Dummy + 6)
 /* (struct UIPrefs *) Signals classes of dynamic prefs change.
  */

#define REACTION_SpecialPens		(REACTION_Dummy + 7)
 /* (struct UIExtPens *) Pens used for Xen-style shadowing, etc.
  * Custom classes MUST propagate this tag to other gadgets
  * contained within, as well all images, most notably, bevel!
  */


struct UIExtPens
{
	WORD extp_Version;	/* Currently 0 */
	LONG extp_DarkPen;	/* XEN/Thick extended locked pen */
	LONG extp_LightPen;	/* XEN/Thick extended locked pen */
	/* NOTE: This structure may grow! */
};

#endif /* REACTION_AUTHOR_H */
