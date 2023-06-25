
/*
 *  INIT.C
 */

/// Include
#include <exec/exec.h>

// Protos
#include "proto/lib_std_protos.h"
///

/// Defines
#ifndef TRUE
#define TRUE -1
#endif

#ifndef FALSE
#define FALSE 0
#endif
///

// ---

/// InitC()
LONG InitC(void)
{
    // Initialize library specific data
    //
    // Returns FALSE if unable to initialize data

    return( TRUE );
}
///

/// UnInitC()
LONG UnInitC(void)
{
    // Shutdown library before expunge

    return( TRUE );
}
///
