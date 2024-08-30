#include "demo.h"

#define ID_DISPLAY 1
#define ID_EDIT    2
#define ID_DELETE  3
#define ID_SAVE    4

static Object * App       ; /* Application object       */
static Object * WI_Browser; /* Window object            */
static Object * BT_Edit   ; /* Edit Button object       */
static Object * BT_Delete ; /* Delete Button object     */
static Object * BT_Save   ; /* Save Button object       */
static Object * LV_Vars   ; /* Env.Var. Listview object */
static Object * LV_Show   ; /* Contents Listview object */

int main(UNUSED int argc, UNUSED char *argv[])
{
	static char buffer[2048];
	char *var;
	BOOL running = TRUE;
	ULONG signal = 0;

	init();

	App = ApplicationObject,
		MUIA_Application_Title      , "EnvBrowser",
		MUIA_Application_Version    , "$VER: EnvBrowser 21.1 (08.02.2018)",
		MUIA_Application_Copyright  , "(C) 1992-2006 Stefan Stuntz, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Stefan Stuntz, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "View environment variables.",
		MUIA_Application_Base       , "ENVBROWSER",
		SubWindow, WI_Browser = WindowObject,
			MUIA_Window_ID, MAKE_ID('M','A','I','N'),
			MUIA_Window_Title, "Environment Browser",
			WindowContents, VGroup,
				Child, HGroup,
					Child, LV_Vars = DirlistObject,
						InputListFrame,
						MUIA_Dirlist_Directory, "env:",
						MUIA_Dirlist_FilesOnly, TRUE,
						MUIA_List_Format, "COL=0",
						End,
					Child, LV_Show = FloattextObject,
						ReadListFrame,
						MUIA_Font, MUIV_Font_Fixed,
						End,
					End,
				Child, HGroup, MUIA_Group_SameSize, TRUE,
					Child, BT_Edit   = SimpleButton("_Edit"  ),
					Child, BT_Delete = SimpleButton("_Delete"),
					Child, BT_Save   = SimpleButton("_Save"  ),
					End,
				End,
			End,
		End;

	if (!App) fail(App,"Failed to create Application.");

	DoMethod(WI_Browser,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,App,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);
	DoMethod(LV_Vars   ,MUIM_Notify,MUIA_List_Active,MUIV_EveryTime,App,2,MUIM_Application_ReturnID,ID_DISPLAY);
	DoMethod(LV_Vars   ,MUIM_Notify,MUIA_List_DoubleClick,TRUE,App,2,MUIM_Application_ReturnID,ID_EDIT);
	DoMethod(BT_Delete ,MUIM_Notify,MUIA_Pressed,FALSE,App,2,MUIM_Application_ReturnID,ID_DELETE);
	DoMethod(BT_Save   ,MUIM_Notify,MUIA_Pressed,FALSE,App,2,MUIM_Application_ReturnID,ID_SAVE  );
	DoMethod(BT_Edit   ,MUIM_Notify,MUIA_Pressed,FALSE,App,2,MUIM_Application_ReturnID,ID_EDIT  );

	DoMethod(WI_Browser,MUIM_Window_SetCycleChain,LV_Vars,LV_Show,BT_Edit,BT_Delete,BT_Save,NULL);

	set(WI_Browser,MUIA_Window_Open,TRUE);

	while (running)
	{
		switch (DoMethod(App,MUIM_Application_NewInput,&signal))
		{
			case MUIV_Application_ReturnID_Quit:
				running = FALSE;
				break;

			case ID_DISPLAY:
			{
				get(LV_Vars,MUIA_Dirlist_Path,&var);
				if (var && GetVar(var,buffer,sizeof(buffer),GVF_GLOBAL_ONLY|GVF_BINARY_VAR)!=-1)
					set(LV_Show,MUIA_Floattext_Text,buffer);
				else DisplayBeep(0);
				break;
			}

			case ID_DELETE:
			{
				get(LV_Vars,MUIA_Dirlist_Path,&var);
				if (var)
				{
					set(LV_Show,MUIA_Floattext_Text,NULL);
					DeleteFile(var);
					DoMethod(LV_Vars,MUIM_List_Remove,MUIV_List_Remove_Active);
				}
 				else DisplayBeep(0);
				break;
			}

			case ID_SAVE:
			{
				get(LV_Vars,MUIA_Dirlist_Path,&var);
				if (var)
				{
					set(App,MUIA_Application_Sleep,TRUE);
					snprintf(buffer,sizeof(buffer),"copy env:%s envarc:%s",FilePart(var),FilePart(var));
					System(buffer, NULL);
					set(App,MUIA_Application_Sleep,FALSE);
				}
				else DisplayBeep(0);
				break;
			}

			case ID_EDIT:
			{
				get(LV_Vars,MUIA_Dirlist_Path,&var);
				if (var)
				{
					set(App,MUIA_Application_Sleep,TRUE);
					#if defined(__amigaos4__)
					snprintf(buffer,sizeof(buffer),"SYS:Utilities/NotePad \"%s\"",var);
					#else
					snprintf(buffer,sizeof(buffer),"C:Ed \"%s\"",var);
					#endif
					System(buffer, NULL);
					set(App,MUIA_Application_Sleep,FALSE);
					DoMethod(WI_Browser,MUIM_Window_ScreenToFront);
				}
				else DisplayBeep(0);
				break;
			}
		}

		if (running && signal)
		{
			signal = Wait(signal | SIGBREAKF_CTRL_C);
			if(signal & SIGBREAKF_CTRL_C) break;
		}
	}

	fail(App,NULL);

	// just to please the compiler
	return 0;
}
