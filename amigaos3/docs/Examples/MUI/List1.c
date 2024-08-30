#include "demo.h"

/*
A simple demo application to show some new features of MUI5's List class.
*/

struct MUI_CustomClass *list_mcc;

/* ------------------------------------------------------------------------- */

struct ListEntry
{
	char firstName[128];
	char lastName[128];
	char dateTime[LEN_DATSTRING*2];
	struct DateStamp ds;
};

static ULONG List_Construct(UNUSED struct IClass *cl, UNUSED Object *obj, UNUSED struct MUIP_List_Construct *msg)
{
	struct ListEntry *le;

	#if defined(__amigaos4__)
	if((le = AllocVecTags(sizeof(*le), AVT_Type, MEMF_SHARED, TAG_DONE)) != NULL)
	#else
	if((le = AllocVec(sizeof(*le), MEMF_ANY)) != NULL)
	#endif
	{
		struct DateTime dt;
		char date[LEN_DATSTRING];
		char time[LEN_DATSTRING];

		strlcpy(le->firstName, "<first name>", sizeof(le->firstName));
		strlcpy(le->lastName, "<last name>", sizeof(le->lastName));
		DateStamp(&le->ds);

		dt.dat_Stamp = le->ds;
		dt.dat_Format = FORMAT_DOS;
		dt.dat_Flags = 0;
		dt.dat_StrDay = NULL;
		dt.dat_StrDate = date;
		dt.dat_StrTime = time;

		DateToStr(&dt);

		snprintf(le->dateTime, sizeof(le->dateTime), "%s%s", date, time);
	}

	return (ULONG)le;
}

static ULONG List_Destruct(UNUSED struct IClass *cl, UNUSED Object *obj, struct MUIP_List_Destruct *msg)
{
	struct ListEntry *le = (struct ListEntry *)msg->entry;

	FreeVec(le);

	return 0;
}

static ULONG List_Compare(UNUSED struct IClass *cl, UNUSED Object *obj, struct MUIP_List_Compare *msg)
{
	struct ListEntry *le1 = (struct ListEntry *)msg->entry1;
	struct ListEntry *le2 = (struct ListEntry *)msg->entry2;
	LONG rc;

	// check which column is to be sorted
	switch(msg->column)
	{
		case 0:
			rc = stricmp(le1->firstName, le2->firstName);
		break;

		case 1:
			rc = stricmp(le1->lastName, le2->lastName);
		break;

		case 2:
			rc = le1->ds.ds_Days - le2->ds.ds_Days;
			if(rc == 0)
				rc = le1->ds.ds_Minute - le2->ds.ds_Minute;
			if(rc == 0)
				rc = le1->ds.ds_Tick - le2->ds.ds_Tick;
		break;

		default:
			rc = 0;
		break;
	}

	return rc;
}

static ULONG List_Display(UNUSED struct IClass *cl, UNUSED Object *obj, struct MUIP_List_Display *msg)
{
	CONST_STRPTR *array = msg->array;
	struct ListEntry *le = (struct ListEntry *)msg->entry;

	if(le == NULL)
	{
		array[0] = "First name";
		array[1] = "Last name";
		array[2] = "Date";
	}
	else
	{
		array[0] = le->firstName;
		array[1] = le->lastName;
		array[2] = le->dateTime;
	}

	return 0;
}

static ULONG List_CreateEditObject(UNUSED struct IClass *cl, UNUSED Object *obj, struct MUIP_List_CreateEditObject *msg)
{
	struct ListEntry *le = (struct ListEntry *)msg->entry;
	Object *rc;

	// check which column is to be edited and create an appropriate edit object
	switch(msg->column)
	{
		case 0:
			rc = StringObject,
				StringFrame,
				MUIA_String_Contents, le->firstName,
			End;
		break;

		case 1:
			rc = StringObject,
				StringFrame,
				MUIA_String_Contents, le->lastName,
			End;
		break;

		default:
			// for all non-editable columns we return no valid object
			rc = NULL;
		break;
	}

	return (ULONG)rc;
}

static ULONG List_Edit(struct IClass *cl, Object *obj, struct MUIP_List_Edit *msg)
{
	ULONG rc;

	// forbid editing of the "Date" column or further columns
	if(msg->column >= 2)
		rc = 0;
	else
		rc = DoSuperMethodA(cl, obj, (Msg)msg);

	return rc;
}

static ULONG List_EditDone(UNUSED struct IClass *cl, Object *obj, struct MUIP_List_EditDone *msg)
{
	struct ListEntry *le = (struct ListEntry *)msg->entry;

	// if we get a valid entry pointer here the edit action was successful and we
	// can obtain the new contents from the edit object
	if(le != NULL)
	{
		STRPTR p;
		LONG sortColumn;

		get(msg->editobj, MUIA_String_Contents, &p);

		switch(msg->column)
		{
			case 0:
				strlcpy(le->firstName, p, sizeof(le->firstName));
			break;

			case 1:
				strlcpy(le->lastName, p, sizeof(le->lastName));
			break;
		}

		// redraw the modified entry
		DoMethod(obj, MUIM_List_Redraw, MUIV_List_Redraw_Active);

		// resort the list if the modified column is the current sort column
		get(obj, MUIA_List_SortColumn, &sortColumn);
		if(msg->column == sortColumn)
		{
			DoMethod(obj, MUIM_List_Sort);
		}
	}

	// If the edited entry is not acceptable in any way FALSE should be returned
	// here to force the user to continue editing.
	// We always allow to finish editing.
	return TRUE;
}

DISPATCHER(List_Dispatcher)
{
	switch(msg->MethodID)
	{
		case MUIM_List_Construct			: return List_Construct(cl, obj, (APTR)msg);
		case MUIM_List_Destruct				: return List_Destruct(cl, obj, (APTR)msg);
		case MUIM_List_Compare				: return List_Compare(cl, obj, (APTR)msg);
		case MUIM_List_Display				: return List_Display(cl, obj, (APTR)msg);
		case MUIM_List_CreateEditObject		: return List_CreateEditObject(cl, obj, (APTR)msg);
		case MUIM_List_Edit					: return List_Edit(cl, obj, (APTR)msg);
		case MUIM_List_EditDone				: return List_EditDone(cl, obj, (APTR)msg);
	}

	return DoSuperMethodA(cl, obj, msg);
}

/* ------------------------------------------------------------------------- */

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app, *window;
	Object *list, *add, *rem, *editable;

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
	list_mcc->mcc_Class->cl_ID = (ClassID)"List1";

	app = ApplicationObject,
		MUIA_Application_Title      , "List1",
		MUIA_Application_Version    , "$VER: List1 21.6 (08.10.2019)",
		MUIA_Application_Copyright  , "(C) 2016-2020 Thore Boeckelmann",
		MUIA_Application_Author     , "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of List.mui in MUI 5.0",
		MUIA_Application_Base       , "LIST1",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Editable list",
			MUIA_Window_ID, MAKE_ID('L','I','S','1'),
			WindowContents, VGroup,
				Child, list = NewObject(list_mcc->mcc_Class, NULL,
					InputListFrame,
					MUIA_List_Editable, TRUE,
					MUIA_List_Title, TRUE,
					MUIA_List_Format, "SORTABLE BAR,SORTABLE BAR,SORTABLE",
					TAG_DONE),

				Child, HGroup,
					MUIA_Group_SameSize, TRUE,
					Child, add = SimpleButton("_Add entry"),
					Child, rem = SimpleButton("_Remove entry"),
					Child, HGroup,
						Child, editable = KeyCheckMark(TRUE, 'e'),
						Child, LLabel("_Editable"),
						End,
					End,

				End,
			End,

		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE, app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);
	DoMethod(add, MUIM_Notify, MUIA_Pressed, FALSE, list, 3, MUIM_List_InsertSingle, NULL, MUIV_List_Insert_Bottom);
	DoMethod(rem, MUIM_Notify, MUIA_Pressed, FALSE, list, 2, MUIM_List_Remove, MUIV_List_Remove_Active);
	// toggle the list's general editability
	DoMethod(editable, MUIM_Notify, MUIA_Selected, MUIV_EveryTime, list, 3, MUIM_Set, MUIA_List_Editable, MUIV_TriggerValue);

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
	MUI_DeleteCustomClass(list_mcc); /* delete the custom class. */
	fail(NULL, NULL);           /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
