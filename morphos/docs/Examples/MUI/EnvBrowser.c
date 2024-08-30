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

int main(int argc,char *argv[])
{
	static char buffer[2048];
	char *var;
	BOOL running = TRUE;
	ULONG signal;

	init();

	App = ApplicationObject,
		MUIA_Application_Title      , "EnvBrowser",
		MUIA_Application_Version    , "$VER: EnvBrowser 20.163 (04.04.03)",
		MUIA_Application_Copyright  , "© 1992/93 Stefan Stuntz",
		MUIA_Application_Author     , "Stefan Stuntz",
		MUIA_Application_Description, "View environment variables.",
		MUIA_Application_Base       , "ENVBROWSER",
		SubWindow, WI_Browser = WindowObject,
			MUIA_Window_ID, MAKE_ID('M','A','I','N'),
			MUIA_Window_Title, "Environment Browser",
			WindowContents, VGroup,
				Child, HGroup,
					Child, LV_Vars = ListviewObject,
						MUIA_Listview_List, DirlistObject,
							InputListFrame,
							MUIA_Dirlist_Directory      , "env:",
							MUIA_Dirlist_FilterDrawers, TRUE,
							MUIA_List_Format          , "COL=0",
							End,
						End,
					Child, LV_Show = ListviewObject,
						MUIA_Listview_List, FloattextObject,
							ReadListFrame,
							MUIA_Font, MUIV_Font_Fixed,
							End,
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
	DoMethod(LV_Vars   ,MUIM_Notify,MUIA_Listview_DoubleClick,TRUE,App,2,MUIM_Application_ReturnID,ID_EDIT);
	DoMethod(BT_Delete ,MUIM_Notify,MUIA_Pressed,FALSE,App,2,MUIM_Application_ReturnID,ID_DELETE);
	DoMethod(BT_Save   ,MUIM_Notify,MUIA_Pressed,FALSE,App,2,MUIM_Application_ReturnID,ID_SAVE  );
	DoMethod(BT_Edit   ,MUIM_Notify,MUIA_Pressed,FALSE,App,2,MUIM_Application_ReturnID,ID_EDIT  );

	DoMethod(WI_Browser,MUIM_Window_SetCycleChain,LV_Vars,LV_Show,BT_Edit,BT_Delete,BT_Save,NULL);

	set(WI_Browser,MUIA_Window_Open,TRUE);

	while (running)
	{
		switch (DoMethod(App,MUIM_Application_Input,&signal))
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
					sprintf(buffer,"copy env:%s envarc:%s",FilePart(var),FilePart(var));
					Execute(buffer,0,0);
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
					sprintf(buffer,"ed -sticky \"%s\"",var);
					Execute(buffer,0,0);
					set(App,MUIA_Application_Sleep,FALSE);
					DoMethod(WI_Browser,MUIM_Window_ScreenToFront);
				}
				else DisplayBeep(0);
				break;
			}
		}

		if (running && signal)
			Wait(signal);
	}

	fail(App,NULL);
	return(0);
}
