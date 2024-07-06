#include "demo.h"
#if defined(MUI_INTERNAL)
#include "Hyperlink_mcc.h"
#else
#include <mui/Hyperlink_mcc.h>
#endif

/*
A simple demo application to show some new features of MUI 5.0.
*/

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app;
	Object *window;
	Object *hyperlink[6];
	Object *uri;
	ULONG i;
	static const char *const UsedClasses[] =
	{
		"Hyperlink.mcc",
		NULL
	};

	init();

	app = ApplicationObject,
		MUIA_Application_Title      , "Hyperlink",
		MUIA_Application_Version    , "$VER: Hyperlink 21.3 (30.10.2020)",
		MUIA_Application_Copyright  , "(C) 2019-2020 Thore Boeckelmann",
		MUIA_Application_Author     , "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of Hyperlink.mcc in MUI 5.0",
		MUIA_Application_Base       , "Hyperlink",
		MUIA_Application_UsedClasses, UsedClasses,

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Hyperlink.mcc",
			MUIA_Window_ID   , MAKE_ID('H','Y','P','L'),
			WindowContents, VGroup,
				Child, ColGroup(2),
					Child, HGroup,
						Child, HSpace(0),
						Child, hyperlink[0] = HyperlinkObject,
							MUIA_Background, MUII_ButtonBack,
							MUIA_Frame, MUIV_Frame_Button,
							MUIA_Hyperlink_URI, "http://www.muidev.de",
							MUIA_Hyperlink_Text, "MUI for AmigaOS Development Site",
							End,
						Child, HSpace(0),
						End,
					Child, HGroup,
						Child, HSpace(0),
						Child, hyperlink[1] = HyperlinkObject,
							MUIA_Hyperlink_URI, "mailto:user@example.com",
							MUIA_Hyperlink_Text, "user@example.com",
							End,
						Child, HSpace(0),
						End,
					Child, VSpace(8),
					Child, VSpace(8),
					Child, HGroup,
						Child, HSpace(0),
						Child, hyperlink[2] = HyperlinkObject,
							MUIA_Hyperlink_URI, "workbench:RAM%20Disk%3a",
							MUIA_Hyperlink_Text, "RAM Disk:",
							End,
						Child, HSpace(0),
						End,
					Child, HGroup,
						Child, HSpace(0),
						Child, hyperlink[3] = HyperlinkObject,
							MUIA_Hyperlink_URI, "amigados:SYS%3aUtilities/MultiView%20S%3aStartup-Sequence",
							MUIA_Hyperlink_Text, "MultiView",
							End,
						Child, HSpace(0),
						End,
					Child, VSpace(8),
					Child, VSpace(8),
					Child, HGroup,
						Child, HSpace(0),
						Child, hyperlink[4] = HyperlinkObject,
							MUIA_Hyperlink_URI, "about:Hyperlink.mcc",
							MUIA_Hyperlink_Text, "Hyperlink.mcc",
							End,
						Child, HSpace(0),
						End,
					Child, HGroup,
						Child, HSpace(0),
						Child, hyperlink[5] = HyperlinkObject,
							MUIA_Hyperlink_URI, "about:AmigaOS",
							MUIA_Hyperlink_Text, "AmigaOS",
							End,
						Child, HSpace(0),
						End,
					End,
				Child, VSpace(8),
				Child, HGroup,
					Child, LLabel("Hovered URI:"),
					Child, uri = TextObject,
						MUIA_Text_SetMin, FALSE,
						MUIA_Text_Shorten, MUIV_Text_Shorten_Cutoff,
						MUIA_Text_Copy, FALSE,
						End,
					End,
				End,
			End,
		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window,MUIM_Notify, MUIA_Window_CloseRequest, TRUE,
		app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

	// show the hovered link in the sample label
	for(i = 0; i < 6; i++)
		DoMethod(hyperlink[i], MUIM_Notify, MUIA_Hyperlink_HoverTip, MUIV_EveryTime, uri, 3, MUIM_Set, MUIA_Text_Contents, MUIV_TriggerValue);

	set(window, MUIA_Window_Open, TRUE);

/*
** This is the ideal input loop for an object oriented MUI application.
** Everything is encapsulated in classes, no return ids need to be used,
** we just call a single method which does all the dirty work.
*/

	DoMethod(app, MUIM_Application_Run);

	set(window, MUIA_Window_Open, FALSE);

/*
** Shut down...
*/

	MUI_DisposeObject(app);     /* dispose all objects. */
	fail(NULL, NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
