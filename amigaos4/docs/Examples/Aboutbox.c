#include "demo.h"
#if defined(MUI_INTERNAL)
#include "Aboutbox_mcc.h"
#else
#include <mui/Aboutbox_mcc.h>
#endif

/*
A simple demo application to show some new features of MUI 5.0.
*/

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app, *window;
	Object *aboutboxWin;
	Object *aboutboxButton;
	static const char *const UsedClasses[] =
	{
		"Aboutbox.mcc",
		NULL
	};

	init();

	app = ApplicationObject,
		MUIA_Application_Title,       "Aboutbox",
		MUIA_Application_Version,     "$VER: Aboutbox 21.4 (28.10.2020)",
		MUIA_Application_Copyright,   "(C) 2015-2020 Thore Boeckelmann",
		MUIA_Application_Author,      "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of Aboutbox.mcc in MUI 5.0",
		MUIA_Application_Base,        "ABOUTBOX",
		MUIA_Application_UsedClasses, UsedClasses,

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Aboutbox.mcc",
			MUIA_Window_ID, MAKE_ID('A','B','O','T'),
			WindowContents, VGroup,
				Child, aboutboxButton = MUI_MakeObject(MUIO_Button, "Open 'About...' window"),
				End,
			TAG_DONE),

		SubWindow, aboutboxWin = AboutboxObject,
			MUIA_Aboutbox_Build,   "svn rXYZ",
			MUIA_Aboutbox_Credits, "Just a tiny demonstration of the Aboutbox.mcc custom class\n"
								   "\n"
								   "Try clicking the version string above...\n"
								   "\n"
								   "\033b%p\033n\n"
								   "\tThore Boeckelmann\n"
								   "\n"
								   "\033b%T\033n\n"
								   "\tkas1e for the idea and beta testing\n"
								   "\n"
								   "\033b%l\033n\n"
								   "\tno translation available\n"
								   "\n"
								   "\033b%W\033n\n"
								   "\twww.muidev.de\n"
								   "\n"
								   "There are lots of more placeholders available",
			// prefer the external image instead of the program icon
			MUIA_Aboutbox_LogoFallbackMode, MAKE_ID('E', 'D', '\0', '\0'),
			MUIA_Aboutbox_LogoFile, "PROGDIR:boing.png",
			// fallback to embedded image in case the external image cannot be loaded
			// MUIA_Aboutbox_LogoData, boing_bz2, // see EmbeddedImages demo how to create suitable embedded data for Rawimage.mcc
			MUIA_Aboutbox_URL, "http://www.muidev.de",
			MUIA_Aboutbox_URLText, "Visit the MUI for AmigaOS Development Site",
			End,

		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE,
		app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

	DoMethod(aboutboxWin, MUIM_Notify, MUIA_Window_CloseRequest, TRUE, MUIV_Notify_Self, 3, MUIM_Set, MUIA_Window_Open, FALSE);
	DoMethod(aboutboxButton, MUIM_Notify, MUIA_Pressed, FALSE, aboutboxWin, 3, MUIM_Set, MUIA_Window_Open, TRUE);

	set(window, MUIA_Window_ActiveObject, aboutboxButton);
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
