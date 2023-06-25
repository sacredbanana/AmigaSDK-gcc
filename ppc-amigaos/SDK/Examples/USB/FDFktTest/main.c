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

                struct UsbRawFunction *rawfkt;

                puts( "USB opened" );

                struct Library *USBSysBase = (struct Library *) ioreq->io_Device;

                struct USBSysIFace *IUSBSys = (struct USBSysIFace *) IExec->GetInterface(USBSysBase, "main", 1, 0);

                if ( IUSBSys != NULL ) {

                    if ( rawfkt = IUSBSys->USBFindFunction( NULL,
//                                                     USBA_Class, 0,
//                                                     USBA_Subclass, 0,
                                                     USBA_ProductID, 0xC212,
                                                     TAG_DONE ) ) { // Get fkt of specified class

                        struct UsbFunction *fkt;

                        puts( "Got a Fkt" );

                        if ( fkt = IUSBSys->USBClaimFunction( rawfkt, (APTR) 1L, port ) ) { // Claim fkt ("1L" is our private reference for the fkt. The USS will use this ref. in notifications sent to us)

                            struct USBBusDevDsc *dsc;

                            dsc = (struct USBBusDevDsc *) IUSBSys->USBEPGetDescriptorA( ioreq, IUSBSys->USBGetEndPoint( fkt, NULL, 0 ),
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


                            IUSBSys->USBDeclaimFunction( fkt ); // Declaim fkt
                        }
                        else {
                            puts( "Dang! Fkt is already in use" );
                        }

                        IUSBSys->USBUnlockFunction( rawfkt ); // Unlock fkt (we don't intend to use it)
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

