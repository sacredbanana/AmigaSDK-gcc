#ifndef GADGETS_DATEBROWSER_H
#define GADGETS_DATEBROWSER_H
/*
**	$VER: datebrowser.h 47.2 (2.9.2019)
**
**	Definitions for the datebrowser.gadget BOOPSI class
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

/*****************************************************************************/

/* Object creation macro to ease readability of layout groups, etc.
 */
#ifndef DateBrowserObject
#define DateBrowserObject NewObject( DATEBROWSER_GetClass(), NULL
#endif
#ifndef EndDateBrowser
#define EndDateBrowser    TAG_DONE)
#endif

/* Additional attributes defined by the datebrowser.gadget class
 */
#define DATEBROWSER_Dummy			(REACTION_Dummy+0x61000)

#define DATEBROWSER_Day				(DATEBROWSER_Dummy)
	/* (UWORD) OM_NEW,OM_SET,OM_UPDATE,OM_GET
	 * Selected/Current day of the month. Defaults to 1, which
	 * is the first of the current month.
	 */

#define DATEBROWSER_Month			(DATEBROWSER_Dummy + 1)
	/* (UWORD) OM_NEW,OM_SET,OM_UPDATE,OM_GET
	 * Calendar month to display. Defaults to 1, which is January.
	 */

#define DATEBROWSER_Year			(DATEBROWSER_Dummy + 2)
	/* (LONG) OM_NEW,OM_SET,OM_UPDATE,OM_GET
	 * Calendar year to display. Defaults to 1978, which is
	 * a long time ago now, back when dinosaurs walked the earth.
	 */

#define DATEBROWSER_SelectedDays		(DATEBROWSER_Dummy + 3)
	/* (ULONG) OM_NEW,OM_SET,OM_UPDATE,OM_GET
	 * A 32 bit value, each bit represents a day of the month,
	 * if set, the corrisponding calendar day is selected.
	 * This is useful for multi-select mode to find out what
	 * days are selected via one packed return value.
	 */

#define DATEBROWSER_WeekDay			(DATEBROWSER_Dummy + 4)
	/* (UWORD) OM_NEW,OM_SET,OM_UPDATE,OM_GET
	 * Returns the day of the week for the currently
	 * selected 'DATEBROWSER_Day'. A better solution may be
	 * using datebrowser's public julian date functions.
	 */

#define DATEBROWSER_FirstWDay			(DATEBROWSER_Dummy + 5)
	/* (UWORD) OM_NEW,OM_SET,OM_UPDATE,OM_GET
	 * Returns the day of the week the first of the month
	 * will fall on with the julian calendar.
	 * Starting with 0 for Sunday, and 6 for Saterday.
	 */

#define DATEBROWSER_NumDays			(DATEBROWSER_Dummy + 6)
	/* (UWORD) OM_GET
	 * Returns the number of days in the currently set month.
	 * A better solution may be using datebrowser's public
	 * julian date functions.
	 */

#define DATEBROWSER_ShowTitle			(DATEBROWSER_Dummy + 7)
	/* (BOOL) OM_NEW,OM_SET,OM_GET
	 * Enables display of the week-day title bar.
	 * NOTE: If turned ON after layout group creation, you must be sure
	 * to FlushLayoutDomainCache() and RethinkLayout(), and potentially
	 * increase the window size to accomodate the possibly larger layout.
	 * Simply toggling iconify on/off, or close & open of the window
	 * class will achieve simular results.
	 * NOTE: If using a recent window.class you should use WM_RETHINK!!
	 */

#define DATEBROWSER_MultiSelect			(DATEBROWSER_Dummy + 8)
	/* (BOOL) OM_NEW,OM_SET,OM_UPDATE,OM_GET
	 * Enables multi-selection of calendar days.
	 */

#define DATEBROWSER_DayTitles			(DATEBROWSER_Dummy + 9)
	/* (STRPTR *) OM_NEW,OM_SET,OM_UPDATE
	 * Pointer to an array of STRPTR containing day titles.
	 * Defaults to non-localized internal "Mon", "Tue", etc.
	 */

#define DATEBROWSER_WeekTitle			(DATEBROWSER_Dummy + 11) /* OS4ONLY */

#define DATEBROWSER_CalendarType		(DATEBROWSER_Dummy + 12) /* OS4ONLY */

#endif /* GADGETS_DATEBROWSER_H */
