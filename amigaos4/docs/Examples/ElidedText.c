#include "demo.h"

/*
A simple demo application to show some new features of MUI 5.0.
*/

struct MUI_CustomClass *list_mcc;

static const char veryLongLine[] = "A very very very very very very very very very very long line";
static const char veryLongStyledLine[] = "A very \033ivery\033n \033bvery\033n \033uvery\033n \033tvery\033n \033gvery\033n \033b\033uvery\033n \033P[ff0000]very\033P[000000] \033Bvery\033F very long line";

/* ------------------------------------------------------------------------- */

static ULONG List_NEW(UNUSED struct IClass *cl, Object *obj, Msg msg)
{
	if((obj = (Object *)DoSuperNew(cl, obj,
		InputListFrame,
		MUIA_List_Format, "MINWIDTH=100px MAXWIDTH=100px ELIDE=none,MINWIDTH=100px MAXWIDTH=100px ELIDE=left,MINWIDTH=100px MAXWIDTH=100px ELIDE=center,MINWIDTH=100px MAXWIDTH=100px ELIDE=right",
		MUIA_List_Title, TRUE,
		TAG_MORE, inittags(msg))) != NULL)
	{
		DoMethod(obj, MUIM_List_InsertSingle, 1, MUIV_List_Insert_Bottom);
		DoMethod(obj, MUIM_List_InsertSingle, 2, MUIV_List_Insert_Bottom);
	}

	return (ULONG)obj;
}

static ULONG List_Display(UNUSED struct IClass *cl, UNUSED Object *obj, struct MUIP_List_Display *msg)
{
	CONST_STRPTR *array = (CONST_STRPTR *)msg->array;

	if(msg->entry != NULL)
	{
		*array++ = (msg->entry == (STRPTR)1) ? veryLongLine : veryLongStyledLine;
		*array++ = (msg->entry == (STRPTR)1) ? veryLongLine : veryLongStyledLine;
		*array++ = (msg->entry == (STRPTR)1) ? veryLongLine : veryLongStyledLine;
		*array++ = (msg->entry == (STRPTR)1) ? veryLongLine : veryLongStyledLine;
	}
	else
	{
		*array++ = "cutoff";
		*array++ = "left";
		*array++ = "center";
		*array++ = "right";
	}

	return 0;
}

DISPATCHER(List_Dispatcher)
{
	switch(msg->MethodID)
	{
		case OM_NEW:            return(List_NEW(cl, obj, (APTR)msg));
		case MUIM_List_Display: return(List_Display(cl, obj, (APTR)msg));
	}

	return DoSuperMethodA(cl, obj, msg);
}

/* ------------------------------------------------------------------------- */

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app, *window;
	static const char *const ElideTitles[] =
	{
		"Labels",
		"List",
		NULL
	};

	init();

	/* Create the new custom class with a call to MUI_CreateCustomClass(). */
	/* Caution: This function returns not a struct IClass, but a           */
	/* struct MUI_CustomClass which contains a struct IClass to be         */
	/* used with NewObject() calls.                                        */
	/* Note well: MUI creates the dispatcher hook for you, you may         */
	/* *not* use its h_Data field! If you need custom data, use the        */
	/* cl_UserData of the IClass structure!                                */

	if (!(list_mcc = MUI_CreateCustomClass(NULL, MUIC_List, NULL, 0, ENTRY(List_Dispatcher))))
		fail(NULL,"Could not create list custom class.");

	// set up a specific name for our class
	list_mcc->mcc_Class->cl_ID = (ClassID)"ElidedText";

	app = ApplicationObject,
		MUIA_Application_Title      , "ElidedText",
		MUIA_Application_Version    , "$VER: ElidedText 21.4 (24.01.2017)",
		MUIA_Application_Copyright  , "(C) 2015-2020 Thore Boeckelmann",
		MUIA_Application_Author     , "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of elided text in MUI 5.0",
		MUIA_Application_Base       , "ELIDEDTEXT",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Elided text",
			MUIA_Window_ID, MAKE_ID('E','L','I','D'),
			WindowContents, VGroup,
				Child, RegisterGroup(ElideTitles),
					// lots of labels with no minimum width to enable the different shortening modes
					Child, ColGroup(2),
						// simple cut off text
						Child, LLabel("cutoff:"),
						Child, TextObject,
							MUIA_Frame, MUIV_Frame_Text,
							MUIA_Background, MUII_TextBack,
							MUIA_Text_Contents, veryLongStyledLine,
							MUIA_Text_Copy, FALSE,
							MUIA_Text_SetMin, FALSE,
							MUIA_Text_Shorten, MUIV_Text_Shorten_Cutoff,
							End,

						// this label intentionally hides its text as soon as it doesn't fit completely
						Child, LLabel("hide:"),
						Child, TextObject,
							MUIA_Frame, MUIV_Frame_Text,
							MUIA_Background, MUII_TextBack,
							MUIA_Text_Contents, veryLongStyledLine,
							MUIA_Text_Copy, FALSE,
							MUIA_Text_SetMin, FALSE,
							MUIA_Text_Shorten, MUIV_Text_Shorten_Hide,
							End,

						// left elided text
						Child, LLabel("left:"),
						Child, TextObject,
							MUIA_Frame, MUIV_Frame_Text,
							MUIA_Background, MUII_TextBack,
							MUIA_Text_Contents, veryLongStyledLine,
							MUIA_Text_Copy, FALSE,
							MUIA_Text_SetMin, FALSE,
							MUIA_Text_Shorten, MUIV_Text_Shorten_ElideLeft,
							End,

						// elidation done in the middle
						Child, LLabel("center:"),
						Child, TextObject,
							MUIA_Frame, MUIV_Frame_Text,
							MUIA_Background, MUII_TextBack,
							MUIA_Text_Contents, veryLongStyledLine,
							MUIA_Text_Copy, FALSE,
							MUIA_Text_SetMin, FALSE,
							MUIA_Text_Shorten, MUIV_Text_Shorten_ElideCenter,
							End,

						// right elided text
						Child, LLabel("right:"),
						Child, TextObject,
							MUIA_Frame, MUIV_Frame_Text,
							MUIA_Background, MUII_TextBack,
							MUIA_Text_Contents, veryLongStyledLine,
							MUIA_Text_Copy, FALSE,
							MUIA_Text_SetMin, FALSE,
							MUIA_Text_Shorten, MUIV_Text_Shorten_ElideRight,
							End,

						End,

					Child, VGroup,
						Child, NewObject(list_mcc->mcc_Class, NULL, TAG_DONE),
						End,

					End,
				End,
			End,

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
	MUI_DeleteCustomClass(list_mcc); /* delete the custom class. */
	fail(NULL,NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
