#include "demo.h"
#include <time.h>

#define ID_REWARD 1


/*
** Custom layout function.
** Perform several actions according to the messages lm_Type
** field. Note that you must return MUILM_UNKNOWN if you do
** not implement a specific lm_Type.
*/

HOOKPROTONHNO(LayoutFunc, LONG, struct MUI_LayoutMsg *lm)
{
	switch (lm->lm_Type)
	{
		case MUILM_MINMAX:
		{
			/*
			** MinMax calculation function. When this is called,
			** the children of your group have already been asked
			** about their min/max dimension so you can use their
			** dimensions to calculate yours.
			**
			** In this example, we make our minimum size twice as
			** big as the biggest child in our group.
			*/

			Object *cstate = (Object *)lm->lm_Children->mlh_Head;
			Object *child;

			WORD maxminwidth  = 0;
			WORD maxminheight = 0;

			/* find out biggest widths & heights of our children */

			while ((child = NextObject(&cstate)))
			{
				if (maxminwidth <MUI_MAXMAX && _minwidth (child) > maxminwidth ) maxminwidth  = _minwidth (child);
				if (maxminheight<MUI_MAXMAX && _minheight(child) > maxminheight) maxminheight = _minheight(child);
			}

			/* set the result fields in the message */

			lm->lm_MinMax.MinWidth  = 2*maxminwidth;
			lm->lm_MinMax.MinHeight = 2*maxminheight;
			lm->lm_MinMax.DefWidth  = 4*maxminwidth;
			lm->lm_MinMax.DefHeight = 4*maxminheight;
			lm->lm_MinMax.MaxWidth  = MUI_MAXMAX;
			lm->lm_MinMax.MaxHeight = MUI_MAXMAX;

			return 0;
		}

		case MUILM_LAYOUT:
		{
			/*
			** Layout function. Here, we have to call MUI_Layout() for each
			** our children. MUI wants us to place them in a rectangle
			** defined by (0,0,lm->lm_Layout.Width-1,lm->lm_Layout.Height-1)
			** You are free to put the children anywhere in this rectangle.
			**
			** If you are a virtual group, you may also extend
			** the given dimensions and place your children anywhere. Be sure
			** to return the dimensions you need in lm->lm_Layout.Width and
			** lm->lm_Layout.Height in this case.
			**
			** Return TRUE if everything went ok, FALSE on error.
			** Note: Errors during layout are not easy to handle for MUI.
			**       Better avoid them!
			*/

			Object *cstate = (Object *)lm->lm_Children->mlh_Head;
			Object *child;

			while ((child = NextObject(&cstate)))
			{
				LONG mw = _minwidth (child);
				LONG mh = _minheight(child);
				LONG l = rand() % (lm->lm_Layout.Width  - mw);
				LONG t = rand() % (lm->lm_Layout.Height - mh);

				if (!MUI_Layout(child,l,t,mw,mh,0))
					return FALSE;
			}

			return TRUE;
		}
	}
	return(MUILM_UNKNOWN);
}
MakeStaticHook(LayoutHook, LayoutFunc);


HOOKPROTONH(PressFunc, LONG, Object *app, LONG *num)
{
	static LONG lastnum = -1;

	lastnum++;

	if (lastnum!=*num)
	{
		DisplayBeep(0);
		lastnum = -1;
	}
	else if (lastnum==7)
	{
		DoMethod(app,MUIM_Application_ReturnID,ID_REWARD);
		lastnum = -1;
	}

	return 0;
}
MakeStaticHook(PressHook, PressFunc);


int main(UNUSED int argc, UNUSED char *argv[])
{
	APTR app,window;
	APTR b[8],yeah;
	ULONG signals = 0;
	BOOL running = TRUE;
	int i;

	init();

	srand(time(0));

	app = ApplicationObject,
		MUIA_Application_Title      , "Layout",
		MUIA_Application_Version    , "$VER: Layout 21.1 (12.01.2017)",
		MUIA_Application_Copyright  , "(C) 1992-2006 Stefan Stuntz, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Stefan Stuntz, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "Demonstrate custom layout hooks.",
		MUIA_Application_Base       , "Layout",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Custom Layout",
			MUIA_Window_ID   , MAKE_ID('C','L','S','3'),
			WindowContents, VGroup,

				Child, TextObject,
					TextFrame,
					MUIA_Background, MUII_TextBack,
					MUIA_Text_Contents, "\33cDemonstration of a custom layout hook.\nSince it's usually no good idea to have overlapping\nobjects, your hooks should be more sophisticated.",
					End,

				Child, VGroup,
					GroupFrame,
					MUIA_Group_LayoutHook, &LayoutHook,
					Child, b[0] = SimpleButton("Click"),
					Child, b[1] = SimpleButton("me"),
					Child, b[2] = SimpleButton("in"),
					Child, b[3] = SimpleButton("correct"),
					Child, b[4] = SimpleButton("sequence"),
					Child, b[5] = SimpleButton("to"),
					Child, b[6] = SimpleButton("be"),
					Child, b[7] = SimpleButton("rewarded!"),

					/* Child, ScrollbarObject, MUIA_Group_Horiz, TRUE, End, */

					Child, yeah = SimpleButton("Yeah!\nYou did it!\nClick to quit!"),
					End,

				End,

			End,
		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

	DoMethod(yeah,MUIM_Notify,MUIA_Pressed,FALSE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

	for (i=0;i<8;i++)
		DoMethod(b[i],MUIM_Notify,MUIA_Pressed,FALSE,
			app,3,MUIM_CallHook,&PressHook,i);

	set(yeah,MUIA_ShowMe,FALSE);


/*
** Input loop...
*/

	set(window,MUIA_Window_Open,TRUE);

	while (running)
	{
		switch (DoMethod(app,MUIM_Application_NewInput,&signals))
		{
			case MUIV_Application_ReturnID_Quit:
				running = FALSE;
				break;

			case ID_REWARD:
				set(yeah,MUIA_ShowMe,TRUE);
				break;
		}

		if (running && signals)
		{
			signals = Wait(signals | SIGBREAKF_CTRL_C);
			if(signals & SIGBREAKF_CTRL_C) break;
		}
	}

	set(window,MUIA_Window_Open,FALSE);


/*
** Shut down...
*/

	MUI_DisposeObject(app);     /* dispose all objects. */
	fail(NULL,NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
