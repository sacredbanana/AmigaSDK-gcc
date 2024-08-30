/*
**   MagicBeaconExample.c
**
**   Copyright (C) 2022 Guido Mersmann <geit@gmx.de>
**   All rights reserved.
**
**   This is a simple example showing how to setup MagicBeacon
**   and how to send and process beacons.
**
**   To compile just execute the following line in shell.
**
**   gcc magicbeaconexample.c -noixemul -oMagicBeaconExample
**
**
*/

/***********************************************************************/

#include <stdio.h>

#include <dos/dos.h>
#include <exec/libraries.h>
#include <utility/tagitem.h>

#include <libraries/magicbeacon.h>

#include <proto/exec.h>

#define USE_INLINE_STDARG
#include <proto/magicbeacon.h>
#undef USE_INLINE_STDARG

#include <proto/dos.h>

/***********************************************************************/

#define APPLICATIONNAME "MagicBeaconExample"
#define SHELLPREFIX     APPLICATIONNAME ": "

struct Library *MagicBeaconBase;

/***********************************************************************/

int main( void )
{
APTR handle, beacon;
IPTR result, signals, signalmask, count;
STRPTR notificationname;

	if( ( MagicBeaconBase = OpenLibrary( "magicbeacon.library", 0 ) ) ) {

		if( ( handle = MagicBeacon_ApplicationRegisterTags( MAGICBEACON_APPLICATIONNAME, (IPTR) APPLICATIONNAME, MAGICBEACON_APPLICATIONSIGNALNUMBER, -1, TAG_DONE ) ) ) {
			printf( SHELLPREFIX "Press CTRL-C to quit this demo application\n");

			printf( SHELLPREFIX "Click with the left or right button into the bubbles to create a live result.\n");

			/* No check needed as this cannot fail. We used "-1" as signal number, so the library allocated the signal during registration */
			signalmask = MagicBeacon_GetAttr( handle, NULL, MAGICBEACON_APPLICATIONSIGNALMASK );

			/* now we flood out some beacons. This is not a real use case and just an example */
			MagicBeacon_BeaconSendTags( handle, MAGICBEACON_NOTIFICATIONNAME, (IPTR) MBN_TRACKNEXT,         /* name of the notification */
												MAGICBEACON_MESSAGE         , (IPTR) "T:Almdudel.mp3",
												TAG_DONE );
			MagicBeacon_BeaconSendTags( handle, MAGICBEACON_NOTIFICATIONNAME, (IPTR) MBN_SCREENSHOT,        /* name of the notification */
												MAGICBEACON_MESSAGE         , (IPTR) "RAM:Picture2.png",
												TAG_DONE );
			MagicBeacon_BeaconSendTags( handle, MAGICBEACON_NOTIFICATIONNAME, (IPTR) MBN_TRANSFERDONE,      /* name of the notification */
												MAGICBEACON_MESSAGE         , (IPTR) "Picture1.jpg",
												TAG_DONE );

			/* This one is configured as a one way notification. There won't be any reply. If MAGICBEACON_APPLICATIONSIGNALNUMBER was
			** not set during application registering, all messages will be turned into one way messages without reply, as there is
			** no reply port */
			MagicBeacon_BeaconSendTags( handle, MAGICBEACON_NOTIFICATIONNAME, (IPTR) MBN_OPERATIONDONE,           /* name of the notification */
												MAGICBEACON_MESSAGE         , (IPTR) "Defragmentation complete", 
												MAGICBEACON_WAITFORRESULT   , FALSE,                              /* this is a one way message */
												TAG_DONE );

			/* As you can see there is no result check required. If something goes wrong, there just wont be any notification */
			count = 3;  /* remember we send three messages, which get replied */
			while( count ) {
				signals = Wait( signalmask | SIGBREAKF_CTRL_C );
				if( signals & SIGBREAKF_CTRL_C ) { break; }   /* lets abort with CTRL-C */

				if( signals & signalmask ) {   /* magic beacon signal */
					/* we got a signal, so process it */
					while( ( beacon = MagicBeacon_BeaconObtain( handle ) ) ) {   /* get first finished beacon */
						/* grab the result and the name. The user may clicked the bubble. Here you would also read the user data. */

						MagicBeacon_GetAttrsTags( handle, beacon, MAGICBEACON_RESULT, (IPTR) &result, MAGICBEACON_NOTIFICATIONNAME, (IPTR) &notificationname, TAG_DONE );
						printf( SHELLPREFIX "Beacon \"%s\" was %s! (Result code: %ld)\n", notificationname,
																							( result == NOTIFICATIONRESULT_IGNORED      ) ? "ignored" :
																							( result == NOTIFICATIONRESULT_CONFIRMED    ) ? "confirmed" :
																							( result == NOTIFICATIONRESULT_CANCELLED    ) ? "cancelled" :
																							( result == NOTIFICATIONRESULT_NOTDISPLAYED ) ? "not displayed" : "unknown", result );
						MagicBeacon_BeaconDispose( handle, beacon );
						count--;
					}
				}
			}
			MagicBeacon_ApplicationUnregister( handle );
		}
		CloseLibrary( MagicBeaconBase );
	} else {
		printf( SHELLPREFIX "Could not open magicbeacon.library\n");
	}
	return 0;
}
