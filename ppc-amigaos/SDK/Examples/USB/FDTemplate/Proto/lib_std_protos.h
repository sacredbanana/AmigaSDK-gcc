/*
**
** Generic Libary Prototypes
**
*/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

/*
** Some constants
*/
#define _LibVersion     1
#define _LibRevision    1

/*
** Some defines
*/

#ifndef LibCall
#define LibCall __saveds
#endif

/*
** The actual protos
*/

struct Library * LibCall LibInit( __REGD0(struct Library *), __REGA0(long) );
struct Library * LibCall LibOpen( __REGD0(long), __REGA6(struct Library *) ); // Uses StormC default LibOpen()
LONG LibCall LibClose( __REGA6(struct Library *) ); // Uses StormC default LibClose()
LONG LibCall LibExpunge( __REGA6(struct Library *) );
LONG LibCall LibReserved( void );

/*
** Library dependant setup/shutdown routines
*/

LONG InitC(void);
LONG UnInitC(void);
