/*
**
** Function Driver code
**
*/

/// Includes
#include <stdlib.h>

#include <exec/exec.h>
#include <utility/tagitem.h>

#include <clib/debug_protos.h>
#include <pragma/exec_lib.h>

#include <usb/system.h>
#include <usb/usb.h>
#include <pragma/usbsys_lib.h>

// Protos
//#include "proto/lib_api_protos.h"
///

/// Defines
#define DB(x) x

#ifndef NULL
#define NULL 0L
#endif
///

/// Vars
extern struct ExecBase *SysBase;
struct Library  *USBSysBase;
///

// ---

/// fdmain_function()
void fdmain_function( struct USBFDStartupMsg *startmsg )
{
    // This function is the actual driver body for an entire USB Function.
    // In this example each USB Device gets its own Function Driver task running. We
    // therefore do not need to keep a private function reference for use with the
    // USS - everytime we get a notification, msg or reply we know it is for the one
    // and only USB Device we're handling.

    struct MsgPort         *fktport; // Msg port for Fkt notification
    struct UsbRawFunction  *rawfkt; // Unclaimed USB Function
    struct UsbFunction     *usfkt; // Claimed USB Function


    USBSysBase = (struct Library *) startmsg->USBReq->io_Device; // Get usbsys.device base
    rawfkt = (struct UsbRawFunction *) startmsg->Object;

    if ( fktport = CreateMsgPort() ) {

        if ( usfkt = USBClaimFunction( rawfkt, (APTR) -1L, fktport ) ) { // Obtain Function (-1L as we don't need a reference, but NULL is not allowed)

            LONG running;
            ULONG waitmask;

            DB( KPutStr( "fd: Function claimed\n" ) );

            //! ... do whatever other setup is needed ...

            // ***************
            // ** Debug: Print product name
            // ***************
            {

                struct USBBusDevDsc  *fktdsc;
                struct USBBusDscHead *fktmandsc; // Manufacturer string
                char *fktmanstr;
                int  idx;

                fktdsc = (struct USBBusDevDsc *) startmsg->Descriptor; // Get Function descriptor

                if ( fktmandsc = USBEPGetDescriptorA( startmsg->USBReq, USBGetEndPoint(usfkt, NULL, 0),
                                                      USBSDT_TYP_STANDARD | USBSDT_REC_DEVICE, USBDESC_STRING,
                                                      fktdsc->dd_ProductStr, NULL ) ) {
                    if ( fktmanstr = AllocMem( fktmandsc->dh_Length+1, MEMF_PUBLIC|MEMF_CLEAR ) ) {
                        for( idx=0; idx < fktmandsc->dh_Length-2; idx+=2 ) {
                            fktmanstr[idx>>1] = ((char *)fktmandsc)[idx+2];
                        }
//                        memcpy( fktmanstr, fktmandsc+1, fktmandsc->dh_Length ); // Copy string
                    }
                    else {
                        USBFreeDescriptors( fktmandsc );
                        fktmandsc = NULL;
                        fktmanstr = "<unknown>";
                    }
                }
                else {
                    fktmanstr = "<unknown>";
                }

                KPrintF( "\nfd: Manufacturer: %s\n\n", fktmanstr );

                if ( fktmandsc ) {
                    FreeMem( fktmanstr, fktmandsc->dh_Length+1 );
                    USBFreeDescriptors( fktmandsc );
                }

            }
            // ***************
            // ** End debug: Print product name
            // ***************



            running = TRUE;

            while ( running ) {

                // ** Wait for event
                waitmask = (1 << fktport->mp_SigBit);
                waitmask = Wait( waitmask );


                // ** Handle Function Notification
                if ( waitmask & (1 << fktport->mp_SigBit) ) {

                    struct USBNotifyMsg *msg;

                    DB( KPutStr( "fd: Fkt notification rcvd\n" ) );

                    while ( msg = (struct USBNotifyMsg *) GetMsg( fktport ) ) {

                        if ( msg->Type == USBNM_TYPE_FUNCTIONDETACH ) { // Detect Function detachment

                            DB( KPutStr( "fd: Function detached\n" ) );

                            running = FALSE; // Terminate FD
                        }

                        ReplyMsg( (struct Message *) msg );
                    }
                }

            }

            DB( KPutStr( "fd: Terminating\n" ) );

            USBDeclaimFunction( usfkt ); // Release Function

        }
        else {
            // ... somebody got hold of the Function before us - just terminate ...
        }

        DeleteMsgPort( fktport );

    }

}
///

/// fdmain_interface()
void fdmain_interface( struct USBFDStartupMsg *startmsg )
{
    // This function is the actual driver body for a USB Interface.
    // In this example each USB Interface gets its own Function Driver task running. We
    // therefore do not need to keep a private Interface reference for use with the
    // USS - everytime we get a notification, msg or reply we know it is for the one
    // and only USB Interface we're handling.

    struct MsgPort          *ifcport; // Msg port for Fkt notification
    struct UsbRawInterface  *rawifc; // Unclaimed USB Interface
    struct UsbInterface     *usifc; // Claimed USB Interface


    USBSysBase = (struct Library *) startmsg->USBReq->io_Device; // Get usbsys.device base
    rawifc = (struct UsbRawInterface *) startmsg->Object;

    if ( ifcport = CreateMsgPort() ) {

        if ( usifc = USBClaimInterface( rawifc, (APTR) -1L, ifcport ) ) { // Obtain Interface

            LONG  running;
            ULONG waitmask;

            DB( KPutStr( "fd: Interface claimed\n" ) );

            //! ... do whatever other setup is needed ...

            // ***************
            // ** Debug: Print Interface name
            // ***************
            {

                struct USBBusIntDsc  *ifcdsc;
                struct USBBusDscHead *ifcnamdsc; // Manufacturer string
                char                 *ifcnamstr;
                int                   idx;

                ifcdsc = (struct USBBusIntDsc *) startmsg->Descriptor; // Get Interface descriptor

                if ( ifcnamdsc = USBEPGetDescriptorA( startmsg->USBReq, USBGetEndPoint(NULL, usifc, 0),
                                                      USBSDT_TYP_STANDARD | USBSDT_REC_DEVICE, USBDESC_STRING,
                                                      ifcdsc->id_InterfaceStr, NULL ) ) {
                    if ( ifcnamstr = AllocMem( ifcnamdsc->dh_Length+1, MEMF_PUBLIC|MEMF_CLEAR ) ) {
                        for( idx=0; idx < ifcnamdsc->dh_Length-2; idx+=2 ) {
                            ifcnamstr[idx>>1] = ((char *)ifcnamdsc)[idx+2];
                        }
                    }
                    else {
                        USBFreeDescriptors( ifcnamdsc );
                        ifcnamdsc = NULL;
                        ifcnamstr = "<unknown>";
                    }
                }
                else {
                    ifcnamstr = "<unknown>";
                }

                KPrintF( "\nfd: Interface: %s\n\n", ifcnamstr );

                if ( ifcnamdsc ) {
                    FreeMem( ifcnamstr, ifcnamdsc->dh_Length+1 );
                    USBFreeDescriptors( ifcnamdsc );
                }

            }
            // ***************
            // ** End debug: Print Interface name
            // ***************



            running = TRUE;

            while ( running ) {

                // ** Wait for event
                waitmask = (1 << ifcport->mp_SigBit);
                waitmask = Wait( waitmask );


                // ** Handle Interface Notification
                if ( waitmask & (1 << ifcport->mp_SigBit) ) {

                    struct USBNotifyMsg *msg;

                    DB( KPutStr( "fd: Ifc notification rcvd\n" ) );

                    while ( msg = (struct USBNotifyMsg *) GetMsg( ifcport ) ) {

                        if ( msg->Type == USBNM_TYPE_INTERFACEDETACH ) { // Detect Interface detachment

                            DB( KPutStr( "fd: Interface detached\n" ) );

                            running = FALSE; // Terminate FD
                        }

                        ReplyMsg( (struct Message *) msg );
                    }
                }

            }

            DB( KPutStr( "fd: Terminating\n" ) );

            USBDeclaimInterface( usifc ); // Release Interface

        }
        else {
            // ... somebody got hold of the Interface before us - just terminate ...
        }

        DeleteMsgPort( ifcport );

    }

}
///

