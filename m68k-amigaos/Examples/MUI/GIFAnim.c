#include "demo.h"
#if defined(MUI_INTERNAL)
#include "GIFAnim_mcc.h"
#else
#include <mui/GIFAnim_mcc.h>
#endif

/*
A simple demo application to show some new features of MUI 5.0.
*/

int main(int argc, char *argv[])
{
	Object *app, *window, *gif, *frame;
	Object *first, *prev, *next, *last, *play, *playOnce, *pause;
	const char *animFile;
	static const char *const UsedClasses[] =
	{
		"GIFAnim_mcc",
		NULL
	};

	init();

	animFile = (argc >= 2) ? argv[1] : "MUI:Demos/anim.gif",

	app = ApplicationObject,
		MUIA_Application_Title      , "GIFAnim",
		MUIA_Application_Version    , "$VER: GIFAnim 21.1 (02.01.2017)",
		MUIA_Application_Copyright  , "(C) 2016-2020 Thore Boeckelmann",
		MUIA_Application_Author     , "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of GIFAnim.mcc in MUI 5.0",
		MUIA_Application_Base       , "GIFANIM",
		MUIA_Application_UsedClasses, UsedClasses,

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "GIFAnim.mcc",
			MUIA_Window_ID   , MAKE_ID('G','I','F','A'),
			WindowContents, VGroup,
				Child, gif = GIFAnimObject,
					MUIA_GIFAnim_File, animFile,
					End,
				Child, frame = TextObject,
					MUIA_Text_SetMin, FALSE,
					MUIA_Text_SetMax, FALSE,
					End,
				Child, HGroup,
					Child, first = MUI_MakeObject(MUIO_Button, "_First"),
					Child, prev = MUI_MakeObject(MUIO_Button, "_Prev"),
					Child, next = MUI_MakeObject(MUIO_Button, "_Next"),
					Child, last = MUI_MakeObject(MUIO_Button, "_Last"),
					Child, HSpace(0),
					Child, play = MUI_MakeObject(MUIO_Button, "P_lay"),
					Child, playOnce = MUI_MakeObject(MUIO_Button, "P_lay once"),
					Child, pause = MUI_MakeObject(MUIO_Button, "P_ause"),
					End,
				End,
			End,

		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

/*
** Disable the control buttons first, but enable them again as soon
** as the animation is fully decoded.
*/
    DoMethod(app, MUIM_MultiSet, MUIA_Disabled, TRUE, next, prev, first, last, play, pause, NULL);
    DoMethod(gif, MUIM_Notify, MUIA_GIFAnim_Decoded, MUIV_EveryTime, next,     3, MUIM_Set, MUIA_Disabled, MUIV_NotTriggerValue);
    DoMethod(gif, MUIM_Notify, MUIA_GIFAnim_Decoded, MUIV_EveryTime, prev,     3, MUIM_Set, MUIA_Disabled, MUIV_NotTriggerValue);
    DoMethod(gif, MUIM_Notify, MUIA_GIFAnim_Decoded, MUIV_EveryTime, first,    3, MUIM_Set, MUIA_Disabled, MUIV_NotTriggerValue);
    DoMethod(gif, MUIM_Notify, MUIA_GIFAnim_Decoded, MUIV_EveryTime, last,     3, MUIM_Set, MUIA_Disabled, MUIV_NotTriggerValue);
    DoMethod(gif, MUIM_Notify, MUIA_GIFAnim_Decoded, MUIV_EveryTime, play,     3, MUIM_Set, MUIA_Disabled, MUIV_NotTriggerValue);
    DoMethod(gif, MUIM_Notify, MUIA_GIFAnim_Decoded, MUIV_EveryTime, playOnce, 3, MUIM_Set, MUIA_Disabled, MUIV_NotTriggerValue);
    DoMethod(gif, MUIM_Notify, MUIA_GIFAnim_Decoded, MUIV_EveryTime, pause,    3, MUIM_Set, MUIA_Disabled, MUIV_NotTriggerValue);

    DoMethod(next,     MUIM_Notify, MUIA_Pressed, FALSE, gif, 1, MUIM_GIFAnim_Next);
    DoMethod(prev,     MUIM_Notify, MUIA_Pressed, FALSE, gif, 1, MUIM_GIFAnim_Pred);
    DoMethod(first,    MUIM_Notify, MUIA_Pressed, FALSE, gif, 1, MUIM_GIFAnim_First);
    DoMethod(last,     MUIM_Notify, MUIA_Pressed, FALSE, gif, 1, MUIM_GIFAnim_Last);
    DoMethod(play,     MUIM_Notify, MUIA_Pressed, FALSE, gif, 2, MUIM_GIFAnim_Play, MUIV_GIFAnim_Play_On|MUIV_GIFAnim_Play_Rewind);
    DoMethod(playOnce, MUIM_Notify, MUIA_Pressed, FALSE, gif, 2, MUIM_GIFAnim_Play, MUIV_GIFAnim_Play_On|MUIV_GIFAnim_Play_Once|MUIV_GIFAnim_Play_Rewind);
    DoMethod(pause,    MUIM_Notify, MUIA_Pressed, FALSE, gif, 2, MUIM_GIFAnim_Play, MUIV_GIFAnim_Play_Off);

    DoMethod(gif, MUIM_Notify, MUIA_GIFAnim_Current, MUIV_EveryTime, frame, 4, MUIM_SetAsString, MUIA_Text_Contents, "current frame %ld", MUIV_TriggerValue);

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
