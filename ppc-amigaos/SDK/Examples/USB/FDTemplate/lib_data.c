/**********************
** Library constants **
**********************/

/// Includes
#include <exec/exec.h>
#include <exec/resident.h>

#include <pragma/exec_lib.h>

#include "proto/lib_std_protos.h"
#include "proto/lib_api_protos.h"
///

/// Defines
#ifndef LibCall
#define LibCall __saveds
#endif

#ifndef NUL
#define NUL 0
#endif
///

// ---

/// Library name
const char  _LibNameString[]    = "fdtemplate.usbfd";
const char  _LibVersionString[] = "fdtemplate.usbfd V1.2 (05.01.2003)";
///

/// Function vectors

const long _LibVectors[] = { // Function vectors
    // ** Library independant functions
    (long)LibOpen,
    (long)LibClose,
    (long)LibExpunge,
    (long)LibReserved,

    // ** Library specific functions

    (long)USBFDGetAttrsA,
    (long)USBFDRunFunction,
    (long)USBFDRunInterface,

    -1 // The End
};
///

/// AutoInit data

const LONG _LibAutoInit[] = { // AutoInit informations
    (LONG) sizeof( struct Library ),
    (LONG) _LibVectors,
    (LONG) NULL,
    (LONG) LibInit
};
///

/// RomTag
const struct Resident _LibRomTag =
{
	RTC_MATCHWORD,                      /* Marker value. */
  	(struct Resident *)&_LibRomTag,     /* This points back to itself. */
  	((struct Resident *)&_LibRomTag)+1, /* This points somewhere behind this marker. */
  	RTF_AUTOINIT | RTF_COLDSTART,       /* The Library should be set up according to the given table. */
  	_LibVersion,                        /* The version of this Library. */
  	NT_LIBRARY,                         /* This defines this module as a Library. */
  	-46,                                /* Initialization priority: Two steps after usbresource.library, two steps before USB stack */
  	(char *) _LibNameString,            /* Points to the name of the Library. */
  	(char *) _LibVersionString,         /* The identification string of this Library. */
  	(APTR)_LibAutoInit,                 /* This table is for initializing the Library. */
};
///
