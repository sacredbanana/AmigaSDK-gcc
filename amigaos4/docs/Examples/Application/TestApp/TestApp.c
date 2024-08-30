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

extern struct ExecIFace *IExec;
extern struct DOSIFace *IDOS;
static struct Library *ApplicationBase=NULL;
static struct Library *IconBase=NULL;
static struct Library *DockyBase=NULL;
struct ApplicationIFace *IApplication=NULL;
struct IconIFace *IIcon=NULL;

extern struct Library *CreateDockyLibrary(void);

BOOL appIsHidden=FALSE;
uint32 appID=0;


BOOL OpenLibs(void)
{
	ApplicationBase = IExec->OpenLibrary("application.library", 50);
	if (ApplicationBase)
		IApplication = (struct ApplicationIFace *)IExec->GetInterface(ApplicationBase, "application", 2, NULL);

	IconBase = IExec->OpenLibrary("icon.library", 50);
	if (IconBase)
		IIcon = (struct IconIFace *)IExec->GetInterface(IconBase, "main", 1, NULL);

	DockyBase = CreateDockyLibrary();

	return (IApplication && IIcon && DockyBase);
}


void CloseLibs(void)
{
	if (DockyBase)
	{
		IExec->DeleteLibrary(DockyBase);
		DockyBase=NULL;
	}

	if (IIcon)
		{ IExec->DropInterface((struct Interface *)IIcon); IIcon=NULL; }
	if (IconBase)
		{ IExec->CloseLibrary(IconBase); IconBase=NULL; }

	if (IApplication)
		{ IExec->DropInterface((struct Interface *)IApplication); IApplication=NULL; }
	if (ApplicationBase)
		{ IExec->CloseLibrary(ApplicationBase); ApplicationBase=NULL; }
}


void ListApplications(struct MinList *list)
{
	if (list)
	{
		struct MinNode *node;

		IDOS->Printf("*******************\n");

		for (node = list->mlh_Head ; node->mln_Succ ; node = node->mln_Succ)
			IDOS->Printf("  id: %ld  name: %s\n", ((struct ApplicationNode *)node)->appID, ((struct ApplicationNode *)node)->name);
	}
}


void receiveMessages(struct MsgPort *port)
{
	struct ApplicationMsg *msg;

	while ( (msg=(struct ApplicationMsg *) IExec->GetMsg(port)) )
	{
		switch (msg->type)
		{
			case APPLIBMT_Quit:
				IDOS->Printf("I shall quit.\n");
				break;

			case APPLIBMT_ForceQuit:
				IDOS->Printf("I shall quit forced.\n");
				break;

			case APPLIBMT_Hide:
				IDOS->Printf("I shall iconify.\n");
				appIsHidden=TRUE;
				IApplication->SetApplicationAttrs(appID, APPATTR_Hidden, (ULONG)appIsHidden, TAG_DONE);
				break;

			case APPLIBMT_Unhide:
				IDOS->Printf("I shall uniconify.\n");
				appIsHidden=FALSE;
				IApplication->SetApplicationAttrs(appID, APPATTR_Hidden, (ULONG)appIsHidden, TAG_DONE);
				break;

			case APPLIBMT_ToFront:
				IDOS->Printf("I shall come to front.\n");
				break;

			case APPLIBMT_OpenPrefs:
				IDOS->Printf("I shall open my prefs\n");
				break;

			case APPLIBMT_NewBlankDoc:
				IDOS->Printf("I shall open a new blank doc.\n");
				break;

			case APPLIBMT_OpenDoc:
				IDOS->Printf("I shall open the document \"%s\"\n", ((struct ApplicationOpenPrintDocMsg *)msg)->fileName);
				IApplication->SetApplicationAttrs(appID,
						APPATTR_AppOpenedDocument, (ULONG)((struct ApplicationOpenPrintDocMsg *)msg)->fileName,
						TAG_DONE);
				IDOS->Printf("I opened the document.\n");
				break;

			case APPLIBMT_PrintDoc:
				IDOS->Printf("I shall print the document \"%s\"\n", ((struct ApplicationOpenPrintDocMsg *)msg)->fileName);
				break;
		}

		IExec->ReplyMsg((struct Message *)msg);
	}
}


void wbmain(struct WBStartup *wb)
{
	BPTR newout;
	BPTR oldout;

	newout = IDOS->Open("CON:0/0/400/300/TestApp Output", MODE_NEWFILE);
	if (newout)
	{
		oldout = IDOS->SelectOutput(newout);

		appID = IApplication->RegisterApplication("TestApp",
									REGAPP_URLIdentifier, "qdev.de",
									REGAPP_LoadPrefs, TRUE,
									REGAPP_SavePrefs, TRUE,
									REGAPP_WBStartup, (ULONG)wb,
									REGAPP_HasPrefsWindow, TRUE,
									REGAPP_HasIconifyFeature, TRUE,
									REGAPP_CanCreateNewDocs, TRUE,
									REGAPP_CanPrintDocs, TRUE,
									TAG_DONE);
		if (appID)
		{
			struct MsgPort *port;

			if (IApplication->GetApplicationAttrs(appID, APPATTR_Port, (ULONG)&port, TAG_DONE))
			{
				int i=200;

				IDOS->Printf("click me in the dock!\ndrop icons on me (in the dock)!\n\n---> do something!! <--- ;-)\n\n");

				while (i--) // we should use Wait() or WaitPort() here!!!!!!!!!!!
				{
					receiveMessages(port);
					IDOS->Delay(5);
				}
			}

			IApplication->UnregisterApplication(appID, NULL);
		}

		IDOS->SelectOutput(oldout);
		IDOS->Close(newout);
	}
}


void shellmain(int argc, char **argv)
{
	if (argc<2)
	{
		IDOS->Printf("%s command [params]\n\n", argv[0]);
		IDOS->Printf("commands are:\n");
		IDOS->Printf("openfile [fileName]\n");
		IDOS->Printf("openprefs\n");
		IDOS->Printf("docky\n");
		IDOS->Printf("receive\n");
		IDOS->Printf("icontest\n");
		IDOS->Printf("long\n");
		IDOS->Printf("notify\n");
		return;
	}

	int mode=0;

	if (strcmp(argv[1], "openfile")==0)
		mode=1;
	else if (strcmp(argv[1], "openprefs")==0)
		mode=2;
	else if (strcmp(argv[1], "docky")==0)
		mode=3;
	else if (strcmp(argv[1], "receive")==0)
		mode=4;
	else if (strcmp(argv[1], "icontest")==0)
		mode=5;
	else if (strcmp(argv[1], "long")==0)
		mode=6;
	else if (strcmp(argv[1], "notify")==0)
		mode=7;

	if (mode==1 || mode==2 || mode==4 || mode==5 || mode==6 || mode==7)
	{
		struct DiskObject *icon = NULL;

		char namebuf[256];
		IDOS->NameFromLock(IDOS->GetProgramDir(), namebuf, sizeof(namebuf));
		IDOS->AddPart(namebuf, argv[0], sizeof(namebuf));


		appID = IApplication->RegisterApplication("TestApp",
										REGAPP_URLIdentifier, "qdev.de",
										REGAPP_LoadPrefs, TRUE,
										REGAPP_SavePrefs, TRUE,
										REGAPP_FileName, namebuf,
										TAG_DONE);

		if (appID != 0)
		{
			struct MsgPort *port = NULL;
			
			IDOS->Printf("TestApp: My AppID is %ld\n", appID);

			if (IApplication->GetApplicationAttrs(appID, APPATTR_Port, (ULONG)&port, TAG_DONE))
			{
				int i;
				
				IDOS->Printf("TestApp: My AppPort is at %p\n", port);
				
				IApplication->SetApplicationAttrs(appID,
									APPATTR_AppNotifications, TRUE,
									TAG_DONE);

				if (mode==2)
				{
					IDOS->Printf("TestApp: Sending APPLIBMT_OpenPrefs to all..\n");
					IApplication->SendApplicationMsg(appID, 0, NULL, APPLIBMT_OpenPrefs);
				}
				else if (mode==1)
				{
					struct ApplicationOpenPrintDocMsg pdm;
					if (argc==3)
						pdm.fileName=argv[2];
					else
						pdm.fileName="some file";

					IDOS->Printf("TestApp: Sending APPLIBMT_OpenDoc(%s) to myself..\n", pdm.fileName);
					IApplication->SendApplicationMsg(appID, 0, (struct ApplicationMsg *) &pdm, APPLIBMT_OpenDoc);
				}
				else if (mode==5)
				{
					struct ApplicationIconInfo aii;

					icon = IIcon->GetIconTags("Sys:Disk", ICONGETA_FailIfUnavailable, FALSE, TAG_DONE);
					if (icon)
					{
						int w, it;

						for(i=0; i<10; i++)
						{
							switch (i%3)
							{
								case 0:
									aii.iconType=APPICONT_Docky;
									aii.info.dockyBase=DockyBase;
									IDOS->Printf("APPICONT_Docky\n");
									break;
								case 1:
									aii.iconType=APPICONT_ProgramIcon;
									IDOS->Printf("APPICONT_ProgramIcon\n");
									break;
								case 2:
									aii.iconType=APPICONT_CustomIcon;
									aii.info.customIcon=icon;
									IDOS->Printf("APPICONT_CustomIcon\n");
									break;
							}

							for(it=0; it<20; it++)
							{
								if (IApplication->SetApplicationAttrs(appID, APPATTR_IconType, (ULONG)&aii, TAG_DONE))
									break;
								else
									IDOS->Delay(5);
							}

							for(w=0; w<50; w++)
							{
								receiveMessages(port);
								IDOS->Delay(1);
							}
						}
					}
				}

				if (mode==2 || mode==1 || mode==4)
				{
					for(i=0; i<150; i++)
					{
						receiveMessages(port);
						IDOS->Delay(1);
					}
				}

				if (mode==6)
				{
					for(i=0; i<150; i++)
					{
						receiveMessages(port);
						IDOS->Delay(10);
					}
				}

				if (mode==7)
				{
					IApplication->Notify(appID,
						APPNOTIFY_Title, "TestApp Title",
						APPNOTIFY_Text, "TestApp is now running",
						TAG_DONE);

					receiveMessages(port);
					IDOS->Delay(10);
				}
			}

			IApplication->UnregisterApplication(appID, NULL);

			if (icon)
				IIcon->FreeDiskObject(icon);
		}
		else
			IDOS->Printf("Registering failed!\n");
	}

	if (mode==3)
	{
		struct ApplicationIconInfo aii;
		struct MinList *appList;
		struct MsgPort *port;
		int i;

		aii.iconType=APPICONT_Docky;
		aii.info.dockyBase=DockyBase;

		for(i=0; i<10; i++)
		{
			appID = IApplication->RegisterApplication("TestApp",
													REGAPP_URLIdentifier, "qdev.de",
													REGAPP_LoadPrefs, TRUE,
													REGAPP_SavePrefs, TRUE,
													REGAPP_FileName, argv[0],
													REGAPP_AppIconInfo, &aii,
													TAG_DONE);
			if (appID)
			{
				if (IApplication->GetApplicationAttrs(appID, APPATTR_Port, (ULONG)&port, TAG_DONE))
				{
					if (rand()%2==0)
					{
						appList = IApplication->GetApplicationList();
						if (appList)
						{
							ListApplications(appList);
							IApplication->FreeApplicationList(appList);
						}
					}

					if (rand()%3==0)
					{
						receiveMessages(port);
					}

					IDOS->Delay(25);
				}

				IApplication->UnregisterApplication(appID, NULL);
			}
		}
	}
}


int main(int argc, char **argv)
{
	if (OpenLibs())
	{
		if (argc==0)
		{
			wbmain((struct WBStartup *)argv);
		}
		else
		{
			shellmain(argc, argv);
		}

		CloseLibs();
	}

	return 0;
}
