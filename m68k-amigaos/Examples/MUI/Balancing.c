#include "demo.h"

int main(UNUSED int argc, UNUSED char *argv[])
{
	APTR app,window;

	init();

	app = ApplicationObject,
		MUIA_Application_Title      , "BalanceDemo",
		MUIA_Application_Version    , "$VER: BalanceDemo 21.1 (09.06.2020)",
		MUIA_Application_Copyright  , "(C) 1992-2006 Stefan Stuntz, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Stefan Stuntz, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "Show balancing groups",
		MUIA_Application_Base       , "BALANCEDEMO",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Balancing Groups",
			MUIA_Window_ID   , MAKE_ID('B','A','L','A'),
			MUIA_Window_Width , MUIV_Window_Width_Screen(50),
			MUIA_Window_Height, MUIV_Window_Height_Screen(50),

			WindowContents, HGroup,

				Child, VGroup, GroupFrame, MUIA_Weight, 15,
					Child, RectangleObject, TextFrame, MUIA_Weight,  50, End,
					Child, RectangleObject, TextFrame, MUIA_Weight, 100, End,
					Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 1), End,
					Child, RectangleObject, TextFrame, MUIA_Weight, 200, End,
					End,

				Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 2), End,

				Child, VGroup,
					Child, HGroup, GroupFrame,
						Child, RectangleObject, TextFrame, MUIA_ObjectID, 123, End,
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 3), End,
						Child, RectangleObject, TextFrame, MUIA_ObjectID, 456, End,
						End,
					Child, HGroup, GroupFrame,
						Child, RectangleObject, TextFrame, End,
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 4), End,
						Child, RectangleObject, TextFrame, End,
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 5), End,
						Child, RectangleObject, TextFrame, End,
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 6), End,
						Child, RectangleObject, TextFrame, End,
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 7), End,
						Child, RectangleObject, TextFrame, End,
						End,
					Child, HGroup, GroupFrame,
						Child, HGroup,
							Child, RectangleObject, TextFrame, End,
							Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 8), End,
							Child, RectangleObject, TextFrame, End,
							End,
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 9), End,
						Child, HGroup,
							Child, RectangleObject, TextFrame, End,
							Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 10), End,
							Child, RectangleObject, TextFrame, End,
							End,
						End,
					Child, HGroup, GroupFrame,
						Child, RectangleObject, TextFrame, MUIA_Weight,  50, End,
						Child, RectangleObject, TextFrame, MUIA_Weight, 100, End,
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 11), End,
						Child, RectangleObject, TextFrame, MUIA_Weight, 200, End,
						End,
					Child, HGroup, GroupFrame,
						Child, SimpleButton("Also"),
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 12), End,
						Child, SimpleButton("Try"),
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 13), End,
						Child, SimpleButton("Sizing"),
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 14), End,
						Child, SimpleButton("With"),
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 15), End,
						Child, SimpleButton("Shift"),
						End,
					Child, HGroup, GroupFrame,
						Child, Label("Label 1:"),
						Child, TextObject, MUIA_Text_Contents, "data...", End,
						Child, BalanceObject, MUIA_CycleChain, 1, MUIA_ObjectID, MAKE_ID('B', 'A', 'L', 16), End,
						Child, Label("Label 2:"),
						Child, TextObject, MUIA_Text_Contents, "more data...", End,
						End,
					End,
				End,
			End,

		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);


/*
** restore the previously set weights of all Balance objects
*/
	DoMethod(app, MUIM_Application_Load, MUIV_Application_Load_ENV);

	set(window,MUIA_Window_Open,TRUE);

/*
** This is the ideal input loop for an object oriented MUI application.
** Everything is encapsulated in classes, no return ids need to be used,
** we just call a single method which does all the dirty work.
*/

	DoMethod(app, MUIM_Application_Run);

/*
** save the current weights of all Balance objects until the next reboot
** if the weights are to be saved permanently the MUIV_Application_Save_ENVARC must be used instead
*/
	DoMethod(app, MUIM_Application_Save, MUIV_Application_Save_ENV);

	set(window,MUIA_Window_Open,FALSE);


/*
** Shut down...
*/

	fail(app,NULL);

	// just to please the compiler
	return 0;
}
