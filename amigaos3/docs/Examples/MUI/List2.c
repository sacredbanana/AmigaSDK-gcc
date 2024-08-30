#include "demo.h"

/*
A simple demo application to show some new features of MUI5's List class.
*/

static const char *titles[] =
{
	"State",
	"Land area",
	"Sea area"
};

static void addState(Object *list, const char *state, LONG land, LONG sea)
{
	char landStr[32];
	char seaStr[32];
	const char *array[3];

	snprintf(landStr, sizeof(landStr), "\033r%8ldkm²", land);
	snprintf(seaStr, sizeof(seaStr), "\033r%8ldkm²", sea);

	// prepare the string array
	array[0] = state;
	array[1] = landStr;
	array[2] = seaStr;

	// and finally insert it into the list
	DoMethod(list, MUIM_List_InsertSingle, &array, MUIV_List_Insert_Sorted);
}

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app, *window;
	Object *list;

	init();

	app = ApplicationObject,
		MUIA_Application_Title      , "List2",
		MUIA_Application_Version    , "$VER: List2 21.3 (24.04.2018)",
		MUIA_Application_Copyright  , "(C) 2016-2020 Thore Boeckelmann",
		MUIA_Application_Author     , "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of List.mui in MUI 5.0",
		MUIA_Application_Base       , "LIST2",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Sortable multi column list",
			MUIA_Window_ID, MAKE_ID('L','I','S','2'),
			WindowContents, VGroup,
				Child, list = ListObject,
					ReadListFrame,
					MUIA_List_ConstructHook, MUIV_List_ConstructHook_StringArray,
					MUIA_List_DestructHook, MUIV_List_DestructHook_StringArray,
					MUIA_List_CompareHook, MUIV_List_CompareHook_StringArray,
					MUIA_List_DisplayHook, MUIV_List_DisplayHook_StringArray,
					MUIA_List_Format, "SORTABLE BAR,SORTABLE BAR,SORTABLE",
					MUIA_List_MaxColumns, 3,
					MUIA_List_TitleArray, titles,
					MUIA_List_Stripes, TRUE,
					MUIA_CycleChain, TRUE,
					End,

				End,
			End,

		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE, app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

	// add some content to the list
	addState(list, "Russia",        16377742, 720500);
	addState(list, "Canada",         9093507, 891163);
	addState(list, "United States",  9161966, 664709);
	addState(list, "China",          9326410, 270550);
	addState(list, "Brazil",         8459417,  55460);
	addState(list, "Australia",      7682300,  58920);
	addState(list, "India",          2973193, 314070);
	addState(list, "Argentina",      2736690,  43710);
	addState(list, "Kazakhstan",     2699700,  25200);
	addState(list, "Algeria",        2381741,  77810);
	addState(list, "Kongo",          2267048,      0);
	addState(list, "Greenland",      2166086,      0);
	addState(list, "Saudi Arabia",   2149690,      0);
	addState(list, "Mexico",         1943945,  20430);
	addState(list, "Indonesia",      1811569,  93000);
	addState(list, "Sudan",          1861484,      0);

	set(window,MUIA_Window_Open,TRUE);

/*
** This is the ideal input loop for an object oriented MUI application.
** Everything is encapsulated in classes, no return ids need to be used,
** we just call a single method which does all the dirty work.
*/

	DoMethod(app, MUIM_Application_Run);

	set(window,MUIA_Window_Open,FALSE);


/*
** Shut down...
*/

	MUI_DisposeObject(app);     /* dispose all objects. */
	fail(NULL,NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
