/*
** Test SelfStarting USB Function Driver
**
** Copyright (c) 2001, Thomas Graff Thøger
**
*/

#include <stdio.h>

#include <exec/exec.h>
#include <usb/usb.h>

#include <proto/exec.h>
#include <proto/usbsys.h>


void DumpBuf( UBYTE *buf, ULONG len )
{
    while (len--) {

        printf( " 0x%02lx", (ULONG) (*buf) );
        buf++;
    }
    puts("");
}


int main()
{
    struct MsgPort *port = IExec->AllocSysObjectTags(ASOT_PORT, TAG_DONE);
    
    if (port != NULL)
    {
        struct IORequest *ioreq = IExec->AllocSysObjectTags(ASOT_IOREQUEST, 
                ASOIOR_Size, sizeof(struct IORequest),
                ASOIOR_ReplyPort, port,
                TAG_DONE);

        if (ioreq != NULL)
        {
            
            if ( IExec->OpenDevice( "usbsys.device", 0, ioreq, 0 ) == 0 ) {

                struct UsbRawInterface *rawifc;

                puts( "USB opened" );

                struct Library *USBSysBase = (struct Library *) ioreq->io_Device;

                struct USBSysIFace *IUSBSys = (struct USBSysIFace *) IExec->GetInterface(USBSysBase, "main", 1, 0);

                if ( IUSBSys != NULL ) {

                   if ( rawifc = IUSBSys->USBFindInterface( NULL, USBA_Class, 8,
//                                                      USBA_Subclass, 0,
                                                      TAG_DONE ) ) { // Get ifc of specified class

                        struct UsbInterface *ifc;

                        puts( "Got an Ifc" );

                        if ( ifc = IUSBSys->USBClaimInterface( rawifc, (APTR) 1L, port ) ) { // Claim ifc ("1L" is our private reference for the Interface and will be used by the USS in notifications)

                            struct USBBusDevDsc *dsc;

                            dsc = (struct USBBusDevDsc *) IUSBSys->USBEPGetDescriptorA( ioreq, IUSBSys->USBGetEndPoint( NULL, ifc, 0 ),
                                                   USBSDT_TYP_STANDARD | USBSDT_REC_DEVICE,
                                                   USBDESC_DEVICE, 0, NULL );
                            if ( dsc ) {

                                puts( "Descriptor contents:" );
                                DumpBuf( (UBYTE *) dsc, dsc->Head.dh_Length );

                                IUSBSys->USBFreeDescriptors( (struct USBBusDscHead *) dsc );
                            }
                            else {
                                puts( "Error reading config!" );
                            }


                            //! Do something clever here ;-)


                            IUSBSys->USBDeclaimInterface( ifc ); // Declaim ifc
                        }
                        else {
                            puts( "Dang! Ifc is already in use" );
                        }

                        IUSBSys->USBUnlockInterface( rawifc ); // Unlock ifc (we don't intend to use it)
                    }

                    IExec->DropInterface((struct Interface *)IUSBSys);
                }


                IExec->CloseDevice( ioreq );
            }

            IExec->FreeSysObject(ASOT_IOREQUEST, ioreq);
        }

        IExec->FreeSysObject(ASOT_PORT, port);
    }

    puts( "Bye!" );

    return 0;
}

