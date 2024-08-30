/* ListExample.c
 *
 * This code demonstrates features of List.mui class.
 */

#include "demo.h"

static void add_entry(APTR obj, int idx, char *city, int population)
{
	char buf[20], buf2[40];
	char *arr[4];

	snprintf(buf, sizeof(buf), "%d", idx);
	snprintf(buf2, sizeof(buf2), "%d", population);

	arr[0] = buf;
	arr[1] = city;
	arr[2] = buf2;

	DoMethod(obj, MUIM_List_InsertSingle, &arr, MUIV_List_Insert_Sorted);
}

int main()
{
	CONST_STRPTR list_titles[] = { "#", "City", "Population" };
	APTR App, Win, List;

	init();

	App = ApplicationObject,
		MUIA_Application_Title      , "ListExample",
		MUIA_Application_Version    , "$VER: ListExample 21.0 (5.3.2016)",
		MUIA_Application_Copyright  , "© 2016 The MorphOS Team",
		MUIA_Application_Author     , "Ilkka Lehtoranta",
		MUIA_Application_Description, "List example.",
		MUIA_Application_Base       , "LISTEXAMPLE2",
		SubWindow, Win = WindowObject,
			MUIA_Window_ID, MAKE_ID('M','A','I','N'),
			MUIA_Window_Title, "List Example",
			WindowContents, VGroup,
				Child, List = ListObject,
					MUIA_Listview_Input, FALSE,
					ReadListFrame,
					MUIA_List_ConstructHook, MUIV_List_ConstructHook_StringArray,
					MUIA_List_DestructHook, MUIV_List_DestructHook_StringArray,
					MUIA_List_CompareHook, MUIV_List_CompareHook_StringArray,
					MUIA_List_DisplayHook, MUIV_List_DisplayHook_StringArray,
					MUIA_List_Format, "SORTABLE BAR,SORTABLE BAR,SORTABLE",
					MUIA_List_MaxColumns, 3,
					MUIA_List_TitleArray, list_titles,
					MUIA_CycleChain, 1,
					End,
				End,
			End,
		End;

	if (!App) fail(App,"Failed to create Application.");

	DoMethod(Win, MUIM_Notify, MUIA_Window_CloseRequest, TRUE, App, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

	add_entry(List, 1, "Tokyo", 37126000);
	add_entry(List, 2, "Jakarta", 26063000);
	add_entry(List, 3, "Seoul", 22547000);
	add_entry(List, 4, "Delhi", 22242000);
	add_entry(List, 5, "Shanghai", 20860000);
	add_entry(List, 6, "Manila", 20767000);
	add_entry(List, 7, "Karachi", 20711000);
	add_entry(List, 8, "New York", 20464000);
	add_entry(List, 9, "Sao Paulo", 20186000);
	add_entry(List, 10, "Mexico City", 19463000);
	add_entry(List, 11, "Cairo", 17816000);
	add_entry(List, 12, "Beijing", 17311000); 
	add_entry(List, 13, "Osaka", 17011000);
	add_entry(List, 14, "Mumbai", 16910000);
	add_entry(List, 15, "Guangzhou", 16827000);

	set(Win, MUIA_Window_Open, TRUE);

	DoMethod(App, MUIM_Application_Run);

	fail(App,NULL);
	return(0);
}
