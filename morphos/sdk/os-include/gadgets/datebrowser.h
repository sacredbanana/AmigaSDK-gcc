#ifndef GADGETS_DATEBROWSER_H
#define GADGETS_DATEBROWSER_H

/*
	datebrowser.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
# include <intuition/gadgetclass.h>
#endif


/* Attributes defined by datebrowser.gadget */

#define DATEBROWSER_Dummy         (REACTION_Dummy + 0x61000)
#define DATEBROWSER_Day           (DATEBROWSER_Dummy)
#define DATEBROWSER_Month         (DATEBROWSER_Dummy + 1)
#define DATEBROWSER_Year          (DATEBROWSER_Dummy + 2)
#define DATEBROWSER_SelectedDays  (DATEBROWSER_Dummy + 3)
#define DATEBROWSER_WeekDay       (DATEBROWSER_Dummy + 4)
#define DATEBROWSER_FirstWDay     (DATEBROWSER_Dummy + 5)
#define DATEBROWSER_NumDays       (DATEBROWSER_Dummy + 6)
#define DATEBROWSER_ShowTitle     (DATEBROWSER_Dummy + 7)
#define DATEBROWSER_MultiSelect   (DATEBROWSER_Dummy + 8)
#define DATEBROWSER_DayTitles     (DATEBROWSER_Dummy + 9)


/* Useful macros */

#ifndef DateBrowserObject
# define DateBrowserObject  NewObject(DATEBROWSER_GetClass(), NULL
#endif

#ifndef EndDateBrowser
# define EndDateBrowser     TAG_DONE)
#endif


#endif /* GADGETS_DATEBROWSER_H */
