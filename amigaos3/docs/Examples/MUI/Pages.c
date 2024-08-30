#include "demo.h"

static const char *Sex[]     = { "male","female",NULL };
static const char *Pages[]   = { "Race","Class","Armor","Level",NULL };
static const char *Races[]   = { "Human","Elf","Dwarf","Hobbit","Gnome",NULL };
static const char *Classes[] = { "Warrior","Rogue","Bard","Monk","Magician","Archmage",NULL };

int main(UNUSED int argc, UNUSED char *argv[])
{
	APTR app,window;

	init();

	app = ApplicationObject,
		MUIA_Application_Title      , "Pages-Demo",
		MUIA_Application_Version    , "$VER: Pages-Demo 20.166 (07.02.2009)",
		MUIA_Application_Copyright  , "(C) 1992-2006 Stefan Stuntz, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Stefan Stuntz, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "Show MUIs Page Groups",
		MUIA_Application_Base       , "PAGESDEMO",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Character Definition",
			MUIA_Window_ID   , MAKE_ID('P','A','G','E'),

			WindowContents, VGroup,

				Child, ColGroup(2),
					Child, Label2("Name:"), Child, String("Frodo",32),
					Child, Label1("Sex:" ), Child, Cycle(Sex),
					End,

				Child, VSpace(2),

				Child, RegisterGroup(Pages),
					MUIA_Register_Frame, TRUE,

					Child, HCenter(Radio(NULL,Races)),

					Child, HCenter(Radio(NULL,Classes)),

					Child, HGroup,
						Child, HSpace(0),
						Child, ColGroup(2),
							Child, Label1("Cloak:" ), Child, CheckMark(TRUE),
							Child, Label1("Shield:"), Child, CheckMark(TRUE),
							Child, Label1("Gloves:"), Child, CheckMark(TRUE),
							Child, Label1("Helmet:"), Child, CheckMark(TRUE),
							End,
						Child, HSpace(0),
						End,

					Child, HGroup,
						Child, HSpace(0),
						Child, ColGroup(2),
							Child, Label("Experience:"  ), Child, Slider(0,100, 3),
							Child, Label("Strength:"    ), Child, Slider(0,100,42),
							Child, Label("Dexterity:"   ), Child, Slider(0,100,24),
							Child, Label("Condition:"   ), Child, Slider(0,100,39),
							Child, Label("Intelligence:"), Child, Slider(0,100,74),
							End,
						Child, HSpace(0),
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

		while ((LONG)DoMethod(app,MUIM_Application_NewInput,&sigs) != MUIV_Application_ReturnID_Quit)
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

	// just to please the compiler
	return 0;
}
