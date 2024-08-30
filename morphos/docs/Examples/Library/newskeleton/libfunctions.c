#include "libdata.h"
#include <stdio.h>
#include <stdarg.h>
#include "os-include/libraries/skeletonnew.h"

/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/
/***********************************************************************/

/* Look at the .fd file to how the library base position is specified. */

/* The inline macro uses LibBase as first arg */
void LIB_TestSPrintf(struct LibBase *MyLibBase,
                     char           *Buffer,
                     const char     *FmtString,
                     ...)
{
	va_list args;

	va_start(args,FmtString);

	vsprintf(Buffer,
	         (char*) FmtString,
	         args);

	va_end(args);
}

/* No library base is passed */
double LIB_TestAdd(double a,
                   double b)
{
	return a+b;
}

/* The library base is the last argument */
double LIB_TestSub(double a,
                   double b,
                   struct LibBase *MyLibBase)
{
	return a-b;
}


ULONG LIB_TestTagList(struct LibBase  *MyLibBase,
                      struct TagItem  *MyTags)
{
	return GetTagData(TESTTAG_GETVALUE, 0, MyTags);
}

