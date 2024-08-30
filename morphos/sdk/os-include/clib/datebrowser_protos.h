#ifndef CLIB_DATEBROWSER_PROTOS_H
#define CLIB_DATEBROWSER_PROTOS_H

/*
	datebrowser.gadget C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef INTUITION_CLASSES_H
# include <intuition/classes.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

Class *DATEBROWSER_GetClass( VOID );
UWORD JulianWeekDay( ULONG day, ULONG month, LONG year );
UWORD JulianMonthDays( ULONG month, LONG year );
BOOL JulianLeapYear( LONG year );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_DATEBROWSER_PROTOS_H */
