#include "demo.h"

int main(int argc,char *argv[])
{
	APTR app,window;

	init();

	app = ApplicationObject,
		MUIA_Application_Title      , "BalanceDemo",
		MUIA_Application_Version    , "$VER: BalanceDemo 20.168 (04.04.03)",
		MUIA_Application_Copyright  , "© 1995 Stefan Stuntz",
		MUIA_Application_Author     , "Stefan Stuntz",
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
					Child, BalanceObject, MUIA_CycleChain, 1, End,
					Child, RectangleObject, TextFrame, MUIA_Weight, 200, End,
					End,

				Child, BalanceObject, MUIA_CycleChain, 1, End,

				Child, VGroup,
					Child, HGroup, GroupFrame,
						Child, RectangleObject, TextFrame, End,
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, RectangleObject, TextFrame, End,
						End,
					Child, HGroup, GroupFrame,
						Child, RectangleObject, TextFrame, End,
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, RectangleObject, TextFrame, End,
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, RectangleObject, TextFrame, End,
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, RectangleObject, TextFrame, End,
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, RectangleObject, TextFrame, End,
						End,
					Child, HGroup, GroupFrame,
						Child, HGroup,
							Child, RectangleObject, TextFrame, End,
							Child, BalanceObject, MUIA_CycleChain, 1, End,
							Child, RectangleObject, TextFrame, End,
							End,
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, HGroup,
							Child, RectangleObject, TextFrame, End,
							Child, BalanceObject, MUIA_CycleChain, 1, End,
							Child, RectangleObject, TextFrame, End,
							End,
						End,
					Child, HGroup, GroupFrame,
						Child, RectangleObject, TextFrame, MUIA_Weight,  50, End,
						Child, RectangleObject, TextFrame, MUIA_Weight, 100, End,
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, RectangleObject, TextFrame, MUIA_Weight, 200, End,
						End,
					Child, HGroup, GroupFrame,
						Child, SimpleButton("Also"),
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, SimpleButton("Try"),
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, SimpleButton("Sizing"),
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, SimpleButton("With"),
						Child, BalanceObject, MUIA_CycleChain, 1, End,
						Child, SimpleButton("Shift"),
						End,
					Child, HGroup, GroupFrame,
						Child, Label("Label 1:"),
						Child, TextObject, MUIA_Text_Contents, "data...", End,
						Child, BalanceObject, MUIA_CycleChain, 1, End,
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
** This is the ideal input loop for an object oriented MUI application.
** Everything is encapsulated in classes, no return ids need to be used,
** we just check if the program shall terminate.
** Note that MUIM_Application_NewInput expects sigs to contain the result
** from Wait() (or 0). This makes the input loop significantly faster.
*/

	set(window,MUIA_Window_Open,TRUE);

	{
		ULONG sigs = 0;

		while (DoMethod(app,MUIM_Application_NewInput,&sigs) != MUIV_Application_ReturnID_Quit)
		{
			if (sigs)
			{
				sigs = Wait(sigs | SIGBREAKF_CTRL_C);
				if (sigs & SIGBREAKF_CTRL_C) break;
			}
		}
	}

	set(window,MUIA_Window_Open,FALSE);


/*
** Shut down...
*/

	fail(app,NULL);
	return(0);
}
