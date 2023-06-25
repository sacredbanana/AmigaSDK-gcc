/*
 *  LIB.C
 *
 *  Basic Library Resource Handling
 *
 *  WARNING: arguments are passed in certain registers from the assembly
 *    tag file, matched to how they are declared below.  Do not change
 *    the argument declarations!
 */

/// Includes
#include <exec/exec.h>
#include <dos/dos.h>

#include <pragma/exec_lib.h>
#include <clib/usbresource_protos.h>

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

#define DB(x) x
///

/// Vars
extern const char _LibNameString[];
extern const char _LibVersionString[];

struct ExecBase *SysBase;
struct Library  *USBResourceBase;

BPTR   seglist;
APTR   fdkey; // FD descriptor key from usbresource.library

///

// ---

/// Lib_AvoidExecute()
ULONG Lib_AvoidExecute( void )
{
    return(0);
}
///

// ---

/// LibInit()
/*
 *    The Initialization routine is given a pointer to our library base and
 *    our seglist.  Since we are AUTOINIT we need NOT construct and add the
 *    library ourselves (that's why we get our library base in D0 - exec has
 *    build the library for us).
 *    If the initialization goes well we return non-NULL (here the library
 *    pointer), else we return NULL.  Exec has Forbid() for us during the call.
 *
 *    If you have an extended structure you must specify the size
 *    in the AutoInit structure in lib_data.c
 */

struct Library * LibCall LibInit( __REGD0(struct Library *lib), __REGA0(long segment) )
{
    SysBase = *(struct ExecBase **) 4; // Get Exec library
    fdkey = NULL;
    seglist = segment; // Store local copy of seglist here (to keep library code as
                       //  sepparated from the program code as possible)

    lib->lib_Node.ln_Type = NT_LIBRARY;
    lib->lib_Node.ln_Name = (char *) _LibNameString;
    lib->lib_Flags = LIBF_CHANGED|LIBF_SUMUSED;
    lib->lib_Version  = _LibVersion;
    lib->lib_Revision = _LibRevision;
    lib->lib_IdString = (APTR) _LibVersionString;

    if ( InitC() ) { // Initialize library specific data

        if ( USBResourceBase = (struct Library *) OpenLibrary( "usbresource.library", 1 ) ) {

            LONG err;

            fdkey = USBResRegisterFD( USBA_FD_Name, _LibNameString,
                                      USBA_FD_Title, "HID driver",
                                      USBA_FD_InterfaceDriver, TRUE,
                                      USBA_Class, 0x03, // HID class
                                      USBA_ErrorCode, &err,
                                      TAG_DONE );
            if ( (fdkey != NULL) || (fdkey == NULL && err == USBERR_ISPRESENT) ) {
                // Either we successfully added ourselves, or we were already
                // registered (propably added by USS during FullBoot)

                return( lib );
            }

            CloseLibrary( USBResourceBase );
        }

        UnInitC();
    }

    return( NULL );

}
///

/// LibOpen()
/*
 *    Open is given the library pointer and the version request.  Either
 *    return the library pointer or NULL.  Remove the DELAYED-EXPUNGE flag.
 *    Exec has Forbid() for us during the call.
 */

struct Library * LibCall LibOpen( __REGD0(long version), __REGA6(struct Library *lib) )
{
    ++lib->lib_OpenCnt;
    lib->lib_Flags &= ~LIBF_DELEXP;
    return( lib );
}
///

/// LibClose()
/*
 *    Close is given the library pointer.  Be sure not to decrement the open
 *    count if already zero.  If the open count is or becomes zero AND there
 *    is a LIBF_DELEXP, we expunge the library and return the seglist.
 *    Otherwise we return NULL.
 *
 *    Note that this routine never sets LIBF_DELEXP on its own.
 *
 *    Exec has Forbid() for us during the call.
 */

LONG LibCall LibClose( __REGA6(struct Library *lib) )
{
    if ( lib->lib_OpenCnt && --lib->lib_OpenCnt )
        return( NULL );

    if ( lib->lib_Flags & LIBF_DELEXP )
        return( LibExpunge( lib ) );

    return( NULL );
}
///

/// LibExpunge()
/*
 *    We expunge the library and return the Seglist ONLY if the open count
 *    is zero.  If the open count is not zero we set the DELAYED-EXPUNGE
 *    flag and return NULL.
 *
 *    Exec has Forbid() for us during the call.  NOTE ALSO that Expunge
 *    might be called from the memory allocator and thus we CANNOT DO A
 *    Wait() or otherwise take a long time to complete (straight from RKM).
 *
 *    Apparently RemLibrary(lib) calls our expunge routine and would
 *    therefore freeze if we called it ourselves.
 *    LibExpunge(lib) must remove the library itself as shown below.
 */

LONG LibCall LibExpunge( __REGA6(struct Library *lib) )
{

    if (lib->lib_OpenCnt) {
        lib->lib_Flags |= LIBF_DELEXP;
        return(NULL);
    }

    if ( USBResourceBase ) {
        if ( fdkey ) USBResUnregisterFD( fdkey ); // Remove FD descriptor if we added one
        CloseLibrary( USBResourceBase );
    }

    Remove(&lib->lib_Node);

    UnInitC();

    FreeMem( (char *) lib-lib->lib_NegSize, (ULONG) lib->lib_NegSize+lib->lib_PosSize );

    return( (long) seglist );
}
///

/// LibReserved()
LONG LibCall LibReserved(void)
{
    return( NULL );
}
///
