/* ListExample.c
 *
 * This code demonstrates features of List.mui class.
 */

#include "demo.h"

struct ListData
{
};

struct entry
{
	TEXT Name[80];
	TEXT Address[80];
	TEXT City[80];
	TEXT Time[80];
	struct DateStamp DateStamp;
};

#define DUMMY_BASE  0x81be0000

#define MM_List_Add    (DUMMY_BASE + 1)
#define MM_List_Remove (DUMMY_BASE + 2)

static size_t mListDisplay(struct IClass *cl, Boopsiobject *obj, struct MUIP_List_Display *msg)
{
	STRPTR *p = msg->array;

	if (msg->entry == NULL)
	{
		p[0] = "Name";
		p[1] = "Address";
		p[2] = "City";
		p[3] = "Added";
	}
	else
	{
		struct entry *e = msg->entry;

		p[0] = e->Name;
		p[1] = e->Address;
		p[2] = e->City;
		p[3] = e->Time;
	}

	return 0;
}

static ssize_t mListCompare(struct IClass *cl, Boopsiobject *obj, struct MUIP_List_Compare *msg)
{
	struct entry *p1 = msg->entry1;
	struct entry *p2 = msg->entry2;
	ssize_t rc = 0;

	switch (msg->column)
	{
		case 0:
			return Stricmp(p1->Name, p2->Name);

		case 1:
			return Stricmp(p1->Address, p2->Address);

		case 2:
			return Stricmp(p1->City, p2->City);

		case 3:
			rc = p1->DateStamp.ds_Days - p2->DateStamp.ds_Days;

			if (rc == 0)
			{
				rc = p1->DateStamp.ds_Minute - p2->DateStamp.ds_Minute;

				if (rc == 0)
				{
					rc = p1->DateStamp.ds_Tick - p2->DateStamp.ds_Tick;
				}
			}
			break;
	}

	return rc;
}

static size_t mListConstruct(struct IClass *cl, Boopsiobject *obj, Msg msg)
{
	struct entry *e = AllocMem(sizeof(*e), MEMF_ANY);

	if (e)
	{
		struct DateTime dt;

		stccpy(e->Name, "<name>", sizeof(e->Name));
		stccpy(e->Address, "<address>", sizeof(e->Address));
		stccpy(e->City, "<city>", sizeof(e->City));
		DateStamp(&e->DateStamp);

		dt.dat_Stamp = e->DateStamp;
		dt.dat_Format = FORMAT_INT;
		dt.dat_Flags = 0;
		dt.dat_StrDay = NULL;
		dt.dat_StrDate = NULL;
		dt.dat_StrTime = e->Time;

		DateToStr(&dt);
	}

	return (size_t)e;
}

static size_t mListDestruct(struct IClass *cl, Boopsiobject *obj, struct MUIP_List_Destruct *msg)
{
	struct entry *e = msg->entry;
	FreeMem(e, sizeof(*e));
	return 0;
}

static size_t mListCreateEditObject(struct IClass *cl, Boopsiobject *obj, struct MUIP_List_CreateEditObject *msg)
{
	struct entry *e = msg->entry;

	switch (msg->column)
	{
		case 0:
			return (size_t)StringObject,
				StringFrame,
				MUIA_String_Contents, e->Name,
				End;

		case 1:
			return (size_t)StringObject,
				StringFrame,
				MUIA_String_Contents, e->Address,
				End;

		case 2:
			return (size_t)StringObject,
				StringFrame,
				MUIA_String_Contents, e->City,
				End;
	}

	return 0;
}

static size_t mListEdit(struct IClass *cl, Boopsiobject *obj, struct MUIP_List_Edit *msg)
{
	if (msg->column >= 3)
		return 0;
	else
		return DoSuperMethodA(cl, obj, (Msg)msg);
}

static size_t mListEditDone(struct IClass *cl, Boopsiobject *obj, struct MUIP_List_EditDone *msg)
{
	struct entry *e = msg->entry;

	if (e)
	{
		STRPTR s;
		GetAttr(MUIA_String_Contents, msg->editobj, (ULONG *)&s);

		switch (msg->column)
		{
			case 0: stccpy(e->Name, s, sizeof(e->Name)); break;
			case 1: stccpy(e->Address, s, sizeof(e->Address)); break;
			case 2: stccpy(e->City, s, sizeof(e->City)); break;
		}

		DoMethod(obj, MUIM_List_Redraw, MUIV_List_Redraw_Active);
	}

	return TRUE;
}

DISPATCHER(MyClass)
{
	switch (msg->MethodID)
	{
		case MUIM_List_Compare         : return mListCompare(cl, obj, (APTR)msg);
		case MUIM_List_Display         : return mListDisplay(cl, obj, (APTR)msg);
		case MUIM_List_Construct       : return mListConstruct(cl, obj, (APTR)msg);
		case MUIM_List_Destruct        : return mListDestruct(cl, obj, (APTR)msg);
		case MUIM_List_CreateEditObject: return mListCreateEditObject(cl, obj, (APTR)msg);
		case MUIM_List_Edit            : return mListEdit(cl, obj, (APTR)msg);
		case MUIM_List_EditDone        : return mListEditDone(cl, obj, (APTR)msg);
	}

	return(DoSuperMethodA(cl,obj,msg));
}
DISPATCHER_END

static struct MUI_CustomClass *mcc;

static void del_mcc()
{
	if (mcc)
		MUI_DeleteCustomClass(mcc);
}

int main()
{
	APTR App, Win, List, BT_Add, BT_Remove;

	init();

	if (!(mcc = MUI_CreateCustomClass(NULL, MUIC_List, NULL, sizeof(struct ListData), DISPATCHER_REF(MyClass))))
		fail(NULL,"Could not create custom class.");

	atexit(del_mcc);

	App = ApplicationObject,
		MUIA_Application_Title      , "ListExample",
		MUIA_Application_Version    , "$VER: ListExample 21.0 (23.1.2016)",
		MUIA_Application_Copyright  , "© 2016 The MorphOS Team",
		MUIA_Application_Author     , "Ilkka Lehtoranta",
		MUIA_Application_Description, "List example.",
		MUIA_Application_Base       , "LISTEXAMPLE",
		SubWindow, Win = WindowObject,
			MUIA_Window_ID, MAKE_ID('M','A','I','N'),
			MUIA_Window_Title, "List Example",
			WindowContents, VGroup,
				Child, List = NewObject(mcc->mcc_Class, NULL,
					InputListFrame,
					MUIA_List_Editable, TRUE,
					MUIA_List_Format, "SORTABLE BAR,SORTABLE BAR,SORTABLE BAR,SORTABLE",
					MUIA_List_Title, TRUE,
					MUIA_List_Stripes, TRUE,
					MUIA_CycleChain, 1,
					End,
				Child, HGroup, MUIA_Group_SameSize, TRUE,
					Child, BT_Add   = SimpleButton("_Add"  ),
					Child, BT_Remove = SimpleButton("_Remove"),
					End,
				End,
			End,
		End;

	if (!App) fail(App,"Failed to create Application.");

	DoMethod(Win, MUIM_Notify, MUIA_Window_CloseRequest, TRUE, App, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);
	DoMethod(BT_Add, MUIM_Notify, MUIA_Pressed, FALSE, List, 3, MUIM_List_InsertSingle, NULL, MUIV_List_Insert_Bottom);
	DoMethod(BT_Remove, MUIM_Notify, MUIA_Pressed, FALSE, List, 2, MUIM_List_Remove, MUIV_List_Remove_Active);

	set(Win, MUIA_Window_Open, TRUE);

	DoMethod(App, MUIM_Application_Run);

	fail(App,NULL);
	return(0);
}
