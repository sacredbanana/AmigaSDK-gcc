/*
**
** Library API functions
**
*/

/// Includes
#include <stdlib.h>

#include <exec/exec.h>
#include <utility/tagitem.h>

#include <usb/system.h>

// Protos
#include "proto/lib_api_protos.h"
///

/// Defines
#define DB(x) x


#ifndef LibCall
#define LibCall __saveds
#endif

#ifndef NULL
#define NULL 0L
#endif
///

/// Prototypes
ULONG DeviceTypeMatch( struct USBBusDevDsc * );
ULONG InterfaceTypeMatch( struct USBBusIntDsc * );
void fdmain_function( struct USBFDStartupMsg * );
void fdmain_interface( struct USBFDStartupMsg * );
///

/// Vars
extern struct ExecBase *SysBase;

///

// ---

/*
** Lib functions goes here...
*/

/// USBFDGetAttrsA()
void LibCall USBFDGetAttrsA( __REGA0(struct TagItem *taglist) )
{
    // We don't support any tags - so we simply return

    return;
}
///

/// USBFDRunFunction()
LONG LibCall USBFDRunFunction( __REGA0(struct USBFDStartupMsg *startmsg) )
{
    // This is the Function Driver main() entry point for Function mode.

    DB( KPutStr( "fd: Booting Function...\n" ) );

    if ( DeviceTypeMatch( (struct USBBusDevDsc *) startmsg->Descriptor ) ) {

        DB( KPutStr( "fd: Function is supported\n" ) );


        fdmain_function( startmsg ); // Enter driver body


        return( USBERR_NOERROR );
    }

    DB( KPutStr( "fd: Function not supported\n" ) );

    return( USBERR_UNSUPPORTED );
}
///

/// USBFDRunInterface()
LONG LibCall USBFDRunInterface( __REGA0(struct USBFDStartupMsg *startmsg) )
{
    // This is the Function Driver main() entry point for Interface mode.

    DB( KPutStr( "fd: Booting Interface...\n" ) );

    if ( InterfaceTypeMatch( (struct USBBusIntDsc *) startmsg->Descriptor ) ) {

        DB( KPutStr( "fd: Interface is supported\n" ) );


        fdmain_interface( startmsg ); // Enter driver body


        return( USBERR_NOERROR );
    }

    DB( KPutStr( "fd: Interface not supported\n" ) );

    return( USBERR_UNSUPPORTED );
}
///

/*
** Support functions
*/

/// DeviceTypeMatch()
ULONG DeviceTypeMatch( struct USBBusDevDsc *dsc )
{
    // This function determines if the USB Device is supported by the
    // Function Driver.

    //! ... check it out here ...

    return( TRUE ); // Yes, we support it
}
///

/// InterfaceTypeMatch()
ULONG InterfaceTypeMatch( struct USBBusIntDsc *dsc )
{
    // This function determines if the USB Interface is supported by the
    // Function Driver.

    //! ... check it out here ...

    return( TRUE ); // Yes, we support it
}
///
