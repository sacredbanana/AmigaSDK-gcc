#include <exec/libraries.h>
#include <libraries/dos.h>
#include <clib/alib_protos.h>
#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/icon.h>
#include <workbench/workbench.h>
#include <workbench/startup.h>
#include <workbench/icon.h>
#include <libraries/application.h>
#include <proto/application.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>

struct ExecIFace *IExec;
struct Library *ApplicationBase=NULL;
struct ApplicationIFace *IApplication=NULL;
struct PrefsObjectsIFace *IPrefsObjects=NULL;
extern struct DOSIFace *IDOS;
ULONG appID=0;


void wbmain(struct WBStartup *wb)
{
	ApplicationBase = IExec->OpenLibrary("application.library", 50);
	if (ApplicationBase)
	{
		IApplication  = (struct ApplicationIFace *)IExec->GetInterface(ApplicationBase, "application", 2, NULL);
		IPrefsObjects = (struct PrefsObjectsIFace *)IExec->GetInterface(ApplicationBase, "prefsobjects", 2, NULL);
	}

	if (IApplication && IPrefsObjects)
	{
		BPTR newout;
		BPTR oldout;

		newout = IDOS->Open("CON:0/0/400/50/DemoApp Output", MODE_NEWFILE);
		if (newout)
		{
			oldout = IDOS->SelectOutput(newout);

			appID=IApplication->RegisterApplication(NULL, // "DemoApp" - results in "ENV(ARC):DemoApp.qdev.de.xml"
							 						REGAPP_URLIdentifier, "qdev.de",
							 						//REGAPP_FileName, "DemoApp",
							 						REGAPP_LoadPrefs, TRUE,      // load the prefs dictionary while registering
													REGAPP_SavePrefs, TRUE,      // save the prefs while unregistering
													REGAPP_WBStartup, (ULONG)wb, // get the application name and path from WBStartup struct
													REGAPP_UniqueApplication, TRUE,
													TAG_DONE);
			if (appID)
			{
				//struct MsgPort *port;
				PrefsObject *dict;

				// read a prefs value, display it, increment it and place it back to the prefs:
				if (IApplication->GetApplicationAttrs(appID, APPATTR_MainPrefsDict, (ULONG)&dict, TAG_DONE))
				{
					LONG integer;

					IDOS->Printf("using dictionary at %p\n", dict);
					integer = IPrefsObjects->DictGetIntegerForKey(dict, "integer value", -1);

					if (integer==-1)
						IDOS->Printf("there was no stored integer. using -1 as default.\n");
					else
						IDOS->Printf("the stored 'integer value' was %ld.\n", integer);

					// replace the old value with a incremented one
					if(!IPrefsObjects->DictSetObjectForKey(dict,
														IPrefsObjects->PrefsNumber(NULL, NULL, ALPONUM_AllocSetLong, integer+1, TAG_DONE),
														"integer value"))
						IDOS->Printf("DictSetObjectForKey() failed!\n");
					/*
					** 'dict' is implicitely written back to prefs after UnregisterApplication() was called.
					** This is because REGAPP_SavePrefs was set to TRUE.
					** You can immediately "flush" the prefs using
					** SetApplicationAttrs(appID, APPATTR_FlushPrefs, NULL, TAG_DONE);
					*/
				}
				else IDOS->Printf("Error accessing main prefs dictionary.\n");

				/*
				if (GetApplicationAttrs(appID, APPATTR_Port, (ULONG)&port, TAG_DONE))
				{
					struct AppLibMsg *msg;
					BOOL running=TRUE;

					while (running)
					{
						IExec->WaitPort(port);

						while ( (msg=(struct AppLibMsg *) IExec->GetMsg(port)) )
						{
							switch (msg->type)
							{
								case APPLIBMT_Quit:
								case APPLIBMT_ForceQuit:
									running=FALSE;
									break;
							}
						}
					}
				}
				*/
				
				IDOS->Delay(100);


				/*
				** If our program icon was locked (for example by AmoiDock),
				** UnregisterApplication() may fail. In this case application.library
				** automatically sends a message of type APPLIBMT_AppWantsChangeIconType
				** to inform the locking application(s) that the icon changes.
				** If all goes well, the locking application unlocks the icon and the
				** next UnregisterApplication() all willbe successful.
				** This loop has not to be done if REGAPP_NoIcon was set to true or
				** the icon type was set on run time successfully to APPICONT_None.
				*/
				IApplication->UnregisterApplication(appID, NULL);
			}
			else
			{
				IDOS->Printf("Failed to register application.\n");
				IDOS->Delay(100);
			}
			
			IDOS->SelectOutput(oldout);
			IDOS->Close(newout);
		}
	}

	if (IPrefsObjects)
		IExec->DropInterface((struct Interface *)IPrefsObjects);
	if (IApplication)
		IExec->DropInterface((struct Interface *)IApplication);
	if (ApplicationBase)
		IExec->CloseLibrary(ApplicationBase);
}

int main(int argc, char **argv)
{
	signal(SIGINT, SIG_IGN);
	
	if( 0==argc )
	{
		wbmain((struct WBStartup *)argv);
	}
	else
	{
		IDOS->Printf("Please start from WB.\n");
	}
	
	return 0;
}


