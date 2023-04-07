#ifndef PRAGMA_DATEBROWSER_LIB_H
#define PRAGMA_DATEBROWSER_LIB_H

/*
**	$VER: datebrowser_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_DATEBROWSER_PROTOS_H
#include <clib/datebrowser_protos.h>
#endif /* CLIB_DATEBROWSER_PROTOS_H */

/* "datebrowser.gadget" */
/*--- functions in V40 or higher (Release 3.1) ---*/
#pragma amicall(DateBrowserBase, 0x1e, DATEBROWSER_GetClass())
#pragma amicall(DateBrowserBase, 0x24, JulianWeekDay(d0,d1,d2))
#pragma amicall(DateBrowserBase, 0x2a, JulianMonthDays(d0,d1))
#pragma amicall(DateBrowserBase, 0x30, JulianLeapYear(d0))

#endif /* PRAGMA_DATEBROWSER_LIB_H */
