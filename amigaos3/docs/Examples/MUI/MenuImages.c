#include "demo.h"

#include <proto/intuition.h>
#include <intuition/imageclass.h>

/*
A simple demo application to show some new features of MUI 5.0.
*/

struct MUI_CustomClass *window_mcc;

/* ------------------------------------------------------------------------- */

struct MyWindowData
{
	struct Image *menuImage;
	Object *menuItem;
};

static ULONG Window_NEW(struct IClass *cl, Object *obj, Msg msg)
{
	Object *menuItem;

	// create the main window object along with the menu and remember the menu
	// item we are going to add a BOOPSI image to later
	if((obj = DoSuperNew(cl, obj,
		MUIA_Window_Menustrip, MenustripObject,
			MUIA_Family_Child, MenuObject,
				MUIA_Menu_Title, "Project",
				MUIA_Menu_CopyStrings, FALSE,
				MUIA_Family_Child, menuItem = MenuitemObject,
					MUIA_Menuitem_Title, "A menu item with an additional Amiga key image",
					MUIA_Menuitem_CopyStrings, FALSE,
				End,
			End,
		End,
		TAG_MORE, inittags(msg))) != NULL)
	{
		struct MyWindowData *data = INST_DATA(cl, obj);

		data->menuItem = menuItem;
	}

	return (ULONG)obj;
}

static ULONG Window_Setup(struct IClass *cl, Object *obj, UNUSED Msg msg)
{
	struct MyWindowData *data = INST_DATA(cl, obj);
	struct DrawInfo *dri;

	get(obj, MUIA_Window_DrawInfo, &dri);
	if(dri != NULL)
	{
		// now that we have a valid DrawInfo pointer we can create the menu image
		data->menuImage = (struct Image *)NewObject(NULL, "sysiclass",
			SYSIA_DrawInfo, dri,
			SYSIA_Which, AMIGAKEY,
			TAG_DONE);

		// pass the image to the menu item
		// it will be disposed as soon as the menu item is disposed
		set(data->menuItem, MUIA_Menuitem_Image, data->menuImage);
	}

	return DoSuperMethodA(cl, obj, msg);
}

DISPATCHER(Window_Dispatcher)
{
	switch(msg->MethodID)
	{
		case OM_NEW:            return(Window_NEW(cl, obj, (APTR)msg));
		case MUIM_Window_Setup: return(Window_Setup(cl, obj, (APTR)msg));
	}

	return DoSuperMethodA(cl, obj, msg);
}

/* ------------------------------------------------------------------------- */

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app, *window;

	init();

	/* Create the new custom class with a call to MUI_CreateCustomClass(). */
	/* Caution: This function returns not a struct IClass, but a           */
	/* struct MUI_CustomClass which contains a struct IClass to be         */
	/* used with NewObject() calls.                                        */
	/* Note well: MUI creates the dispatcher hook for you, you may         */
	/* *not* use its h_Data field! If you need custom data, use the        */
	/* cl_UserData of the IClass structure!                                */

	if (!(window_mcc = MUI_CreateCustomClass(NULL, MUIC_Window, NULL, sizeof(struct MyWindowData), ENTRY(Window_Dispatcher))))
		fail(NULL,"Could not create window custom class.");

	// set up a specific name for our class
	window_mcc->mcc_Class->cl_ID = (ClassID)"MenuImages";

	app = ApplicationObject,
		MUIA_Application_Title      , "MenuImages",
		MUIA_Application_Version    , "$VER: MenuImages 21.3 (24.01.2017)",
		MUIA_Application_Copyright  , "(C) 2015-2020 Thore Boeckelmann",
		MUIA_Application_Author     , "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of menu images in MUI 5.0",
		MUIA_Application_Base       , "MENUIMAGES",

		SubWindow, window = NewObject(window_mcc->mcc_Class, NULL,
			MUIA_Window_Title, "Menu images",
			MUIA_Window_ID   , MAKE_ID('M','A','I','N'),
			// the menu will be created in our custom class' OM_NEW method
			WindowContents, VGroup,
				Child, TextObject,
					MUIA_Text_PreParse, "\033c",
					MUIA_Text_Contents, "Click the right mouse\n"
					                    "button to open the menu...\n"
					                    "\n"
					                    "Also try to activate the 'embedded menu bar'\n"
					                    "in MUI prefs.\n"
					                    "\n"
					                    "Of course it is possible to use arbitrary images\n"
					                    "instead of this simple Amiga key image.",
					MUIA_Text_Copy, FALSE,
					MUIA_Text_SetMax, TRUE,
					End,
				End,
			TAG_DONE),

		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

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
	MUI_DeleteCustomClass(window_mcc); /* delete the custom class. */
	fail(NULL,NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
