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
#include <signal.h>

extern struct ExecIFace *IExec;
extern struct DOSIFace *IDOS;
static struct Library *ApplicationBase=NULL;
static struct Library *IconBase=NULL;
static struct Library *DockyBase=NULL;
struct ApplicationIFace *IApplication=NULL;
struct IconIFace *IIcon=NULL;

extern struct Library *CreateDockyLibrary(void);


BOOL OpenLibs(void)
{
	ApplicationBase = IExec->OpenLibrary("application.library", 50);
	if (ApplicationBase)
		IApplication = (struct ApplicationIFace *)IExec->GetInterface(ApplicationBase, "application", 2, NULL);
		
	IconBase = IExec->OpenLibrary("icon.library", 45);
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


void wbmain(struct WBStartup *wb)
{
	BPTR newout, oldout;

	if (OpenLibs())
	{
		newout = IDOS->Open("CON:0/0/400/150/Anxious Output", MODE_NEWFILE);
		if (newout)
		{
			oldout = IDOS->SelectOutput(newout);
		
			struct DiskObject *icon=NULL;
			ULONG appID;

			icon = IIcon->GetIconTags("Sys:Disk", ICONGETA_FailIfUnavailable, FALSE, TAG_DONE);
			if (icon)
			{
				struct ApplicationIconInfo aii;

				aii.iconType=APPICONT_Docky;
				aii.info.dockyBase=DockyBase;

				appID = IApplication->RegisterApplication(NULL,
															REGAPP_WBStartup, (ULONG)wb,
															REGAPP_URLIdentifier, "qdev.de",
															REGAPP_AppIconInfo, (ULONG)&aii,
															TAG_DONE);
						
				if (appID)
				{
					int i, it;

					for(i=1; i<10; i++)
					{
						IDOS->Delay(50);

						switch (i%3)
						{
							case 0:
								aii.iconType=APPICONT_Docky;
								aii.info.dockyBase=DockyBase;
								break;
							case 1:
								aii.iconType=APPICONT_CustomIcon;
								aii.info.customIcon=icon;
								break;
							case 2:
								aii.iconType=APPICONT_ProgramIcon;
								break;
						}

						for(it=0; it<20; it++)
						{
							IDOS->Printf("trying to change icon type... ");

							if (IApplication->SetApplicationAttrs(appID, APPATTR_IconType, (ULONG)&aii, TAG_DONE))
							{
								IDOS->Printf("successful!\n");
								break;
							}
							else
							{
								IDOS->Printf("we have to wait for unlock...\n");
								IDOS->Delay(5);
							}
						}
					}

					IDOS->Printf("unregistering...\n");
					IApplication->UnregisterApplication(appID, NULL);
					IDOS->Printf("unregistered.\n");

					IDOS->Delay(50);
				}
				IIcon->FreeDiskObject(icon);
			}

			IDOS->SelectOutput(oldout);
			IDOS->Close(newout);
		}
	}
	
	CloseLibs();
}


int main(int argc, char **argv)
{
	signal(SIGINT, SIG_IGN);
	
	if (argc==0)
	{
		wbmain((struct WBStartup *)argv);
	}
	else
	{
		IDOS->Printf("Please start from WB!\n");
	}
	return 0;
}

