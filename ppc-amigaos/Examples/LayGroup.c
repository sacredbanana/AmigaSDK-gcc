#include "demo.h"
#if defined(MUI_INTERNAL)
#include "LayGroup_mcc.h"
#else
#include <mui/LayGroup_mcc.h>
#endif

/*
A simple demo application to show some new features of MUI 5.0.
*/

#define LAYGROUP_IMAGE_MUI \
	ImageObject, \
        ImageButtonFrame, \
        MUIA_InputMode, MUIV_InputMode_Toggle, \
		MUIA_Image_Spec, "4:MUI:Images/mui32_logo.mim", \
        MUIA_Image_FreeVert, TRUE, \
        MUIA_Background, MUII_ButtonBack, \
        MUIA_ShowSelState, FALSE, \
        End

#define INITIAL_IMAGE_COUNT		30

static ULONG m_LayGroup_SET(struct IClass *cl, Object *obj, struct opSet *msg)
{
	struct TagItem *tags, *tag;

	for(tags = msg->ops_AttrList; (tag = NextTagItem(&tags)) != NULL;)
	{
		switch(tag->ti_Tag)
		{
			// Of course MUIA_LayGroup_ChildNumber is not OM_SET'able in LayGroup.mcc,
			// but we abuse this tag to modify the number of child objects.
			// To make sure there is no bad impact the tag will be erased before
			// this method is forwarded to LayGroup.mcc.
			case MUIA_LayGroup_ChildNumber:
			{
				ULONG newCount = tag->ti_Data;
				ULONG oldCount = xget(obj, MUIA_LayGroup_ChildNumber);

				if(newCount != oldCount)
				{
					DoMethod(obj, MUIM_Group_InitChange);
					// remove superfluous objects
					while(newCount < oldCount)
					{
						Object *child = (Object *)DoMethod(obj, OM_REMMEMBER, -1);
						MUI_DisposeObject(child);
						oldCount--;
					}
					// add new objects
					while(newCount > oldCount)
					{
						DoMethod(obj, OM_ADDMEMBER, LAYGROUP_IMAGE_MUI);
						oldCount++;
					}
					DoMethod(obj, MUIM_Group_ExitChange);
				}

				// let the superclass ignore this tag
				tag->ti_Tag = TAG_IGNORE;
			}
			break;
		}
	}

	return DoSuperMethodA(cl, obj, (Msg)msg);
}


DISPATCHER(MyDispatcher)
{
	switch(msg->MethodID)
	{
		case OM_SET:		return m_LayGroup_SET(cl, obj, (APTR)msg);
	}

	return DoSuperMethodA(cl, obj, msg);
}

int main(UNUSED int argc, UNUSED char *argv[])
{
	struct MUI_CustomClass *mcc;
	Object *app;
	Object *window;
	Object *layGroup;
	Object *countSlider;
	Object *countLabel;
	Object *rowLabel;
	Object *columnLabel;
	static const char *const UsedClasses[] =
	{
		"LayGroup.mcc",
		NULL
	};

	init();

	if((mcc = MUI_CreateCustomClass(NULL, MUIC_LayGroup, NULL, 0, ENTRY(MyDispatcher))) == NULL)
		fail(NULL, "Could not create custom class.");

	// set up a specific name for our class
	mcc->mcc_Class->cl_ID = (ClassID)"LayGroup";

	app = ApplicationObject,
		MUIA_Application_Title      , "LayGroup",
		MUIA_Application_Version    , "$VER: Hyperlink 21.1 (21.09.2020)",
		MUIA_Application_Copyright  , "(C) 2020 Thore Boeckelmann",
		MUIA_Application_Author     , "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of LayGroup.mcc in MUI 5.0",
		MUIA_Application_Base       , "LayGroup",
		MUIA_Application_UsedClasses, UsedClasses,

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "LayGroup.mcc",
			MUIA_Window_ID   , MAKE_ID('L','Y','G','R'),
			WindowContents, VGroup,
				Child, ScrollgroupObject,
					MUIA_Scrollgroup_FreeHoriz, FALSE,
					MUIA_Scrollgroup_Contents, layGroup = NewObject(mcc->mcc_Class, NULL,
						MUIA_Group_SameSize, TRUE,
						MUIA_LayGroup_Selection, MUIV_LayGroup_Selection_Immediate,
						// child objects will be added later
						TAG_DONE),
					End,
				Child, HGroup,
					Child, LLabel1("Set number of objects:"),
					Child, countSlider = Slider(1, 99, 0),
					End,
				Child, HGroup,
					Child, HSpace(0),
					Child, countLabel = TextObject,
						MUIA_Text_PreParse, "\033c",
						MUIA_Text_Contents, "Objects:  0",
						MUIA_Text_SetMax, FALSE,
						End,
					Child, rowLabel = TextObject,
						MUIA_Text_PreParse, "\033c",
						MUIA_Text_Contents, "Rows:  0",
						MUIA_Text_SetMax, FALSE,
						End,
					Child, columnLabel = TextObject,
						MUIA_Text_PreParse, "\033c",
						MUIA_Text_Contents, "Columns:  0",
						MUIA_Text_SetMax, FALSE,
						End,
					Child, HSpace(0),
					End,
				Child, TextObject,
					MUIA_Text_PreParse, "\033c",
					MUIA_Text_Contents, "Also try the lasso selection...",
					MUIA_Text_Copy, FALSE,
					End,
				End,
			End,
		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE,
		app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

	DoMethod(countSlider, MUIM_Notify, MUIA_Numeric_Value, MUIV_EveryTime, layGroup, 3, MUIM_Set, MUIA_LayGroup_ChildNumber, MUIV_TriggerValue);

	// show the number of objects and generated rows and columns upon each change or relayout
	DoMethod(layGroup, MUIM_Notify, MUIA_LayGroup_ChildNumber, MUIV_EveryTime, countLabel, 4, MUIM_SetAsString, MUIA_Text_Contents, "Objects: %2ld", MUIV_TriggerValue);
	DoMethod(layGroup, MUIM_Notify, MUIA_LayGroup_NumberOfRows, MUIV_EveryTime, rowLabel, 4, MUIM_SetAsString, MUIA_Text_Contents, "Rows: %2ld", MUIV_TriggerValue);
	DoMethod(layGroup, MUIM_Notify, MUIA_LayGroup_NumberOfColumns, MUIV_EveryTime, columnLabel, 4, MUIM_SetAsString, MUIA_Text_Contents, "Columns: %2ld", MUIV_TriggerValue);

	// set the slider to the desired number, this will cause the image objects to be added the the LayGroup object
	set(countSlider, MUIA_Numeric_Value, INITIAL_IMAGE_COUNT);

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
	MUI_DeleteCustomClass(mcc);
	fail(NULL, NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
