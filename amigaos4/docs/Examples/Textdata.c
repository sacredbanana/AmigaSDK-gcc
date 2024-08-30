#include "demo.h"

/*
A simple demo application to show some new features of MUI 5.0.
*/

int main(UNUSED int argc, UNUSED char *argv[])
{
	APTR app, window, maingrp;
	struct Library *csLib;

	init();

	csLib = OpenLibrary("codesets.library", 0);

	app = ApplicationObject,
		MUIA_Application_Title,       "Textdata",
		MUIA_Application_Version,     "$VER: Textdata 21.3 (20.01.2017)",
		MUIA_Application_Copyright,   "(C) 2016-2020 Thore Boeckelmann",
		MUIA_Application_Author,      "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of Textdata.mui in MUI 5.0",
		MUIA_Application_Base,        "TEXTDATA",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Textdata.mui",
			MUIA_Window_ID,    MAKE_ID('T','X','T','D'),
			WindowContents, maingrp = VGroup,
				Child, ColGroup(2),
					Child, Label("plain:"),
					Child, TextObject,
						MUIA_Text_Contents, "äöüÄÖÜß`'",
						End,

					Child, Label("UTF-8:"),
					Child, TextObject,
						// UTF8 representation of
						// U+00E4 U+00F6 U+00FC U+00C4 U+00D6 U+00DC U+00DF U+2018 U+2019
						MUIA_Text_Data, UTextdata("\xc3\xa4\xc3\xb6\xc3\xbc\xc3\x84\xc3\x96\xc3\x9c\xc3\x9f\xe2\x80\x98\xe2\x80\x99"),
						End,

					Child, Label("UCS-2:"),
					Child, TextObject,
						// UCS-2 representation of
						// U+00E4 U+00F6 U+00FC U+00C4 U+00D6 U+00DC U+00DF U+2018 U+2019
						MUIA_Text_Data, LTextdata("\x00\xe4\x00\xf6\x00\xfc\x00\xc4\x00\xd6\x00\xdc\x00\xdf\x20\x18\x20\x19\x00\x00"),
						End,

					Child, Label("ISO8859-1:"),
					Child, TextObject,
						MUIA_Text_Data, ATextdata("äöüÄÖÜß`'"),
						End,

					End,
				End,

			End,
		End;

	if(app == NULL)
		fail(app, "Failed to create Application.");

	// check for codesets.library 6.20+
	if(csLib == NULL || csLib->lib_Version < 6 || (csLib->lib_Version == 6 && csLib->lib_Revision < 20))
	{
		DoMethod(maingrp, MUIM_Group_AddHead, TextObject,
			MUIA_Frame, MUIV_Frame_Text,
			MUIA_Background, "2:rff0000",
			MUIA_Text_PreParse, "\033c",
			MUIA_Text_Contents, "codesets.library 6.20+ is missing!\n"
			                    "If some of the texts below are unreadable,\n"
			                    "then this is the reason why.",
			MUIA_Text_Copy, FALSE,
			End);
	}

	DoMethod(window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE,
		app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

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
	if(csLib != NULL)
		CloseLibrary(csLib);
	fail(NULL, NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
