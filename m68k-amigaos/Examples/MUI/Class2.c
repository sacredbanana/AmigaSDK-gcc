#include "demo.h"


/***************************************************************************/
/* Here is the beginning of our simple new class...                        */
/***************************************************************************/

/*
** This class is the same as within Class1.c except that it features
** a pen attribute.
*/

struct MyData
{
	struct MUI_PenSpec penspec;
	LONG pen;
	BOOL penchange;
};


#define MYATTR_PEN 0x8022   /* tag value for the new attribute.            */


SAVEDS ULONG mNew(struct IClass *cl,Object *obj,Msg msg)
{
	struct MyData *data;
	struct TagItem *tags,*tag;

	if (!(obj = (Object *)DoSuperMethodA(cl,obj,msg)))
		return 0;

	data = INST_DATA(cl, obj);

	/* parse initial taglist */

	for (tags=((struct opSet *)msg)->ops_AttrList;(tag=NextTagItem(&tags));)
	{
		switch (tag->ti_Tag)
		{
			case MYATTR_PEN:
				if (tag->ti_Data)
					data->penspec = *((struct MUI_PenSpec *)tag->ti_Data);
				break;
		}
	}

	return (ULONG)obj;
}



SAVEDS ULONG mDispose(struct IClass *cl,Object *obj,Msg msg)
{
	/* OM_NEW didnt allocates something, just do nothing here... */
	return DoSuperMethodA(cl, obj, msg);
}


/*
** OM_SET method, we need to see if someone changed the penspec attribute.
*/

SAVEDS ULONG mSet(struct IClass *cl,Object *obj,Msg msg)
{
	struct MyData *data = INST_DATA(cl, obj);
	struct TagItem *tags,*tag;

	for (tags=((struct opSet *)msg)->ops_AttrList;(tag=NextTagItem(&tags));)
	{
		switch (tag->ti_Tag)
		{
			case MYATTR_PEN:
				if (tag->ti_Data)
				{
					data->penspec = *((struct MUI_PenSpec *)tag->ti_Data);
					data->penchange = TRUE;
					MUI_Redraw(obj,MADF_DRAWOBJECT); /* redraw ourselves completely */
				}
				break;
		}
	}

	return DoSuperMethodA(cl, obj, msg);
}


/*
** OM_GET method, see if someone wants to read the color.
*/

static ULONG mGet(struct IClass *cl,Object *obj,Msg msg)
{
	struct MyData *data = INST_DATA(cl, obj);
	ULONG *store = ((struct opGet *)msg)->opg_Storage;

	switch (((struct opGet *)msg)->opg_AttrID)
	{
		case MYATTR_PEN: *store = (ULONG)&data->penspec; return TRUE;
	}

	return DoSuperMethodA(cl, obj, msg);
}


SAVEDS ULONG mSetup(struct IClass *cl,Object *obj,Msg msg)
{
	struct MyData *data = INST_DATA(cl, obj);

	if (!DoSuperMethodA(cl,obj,msg))
		return FALSE;

	data->pen = MUI_ObtainPen(muiRenderInfo(obj),&data->penspec,0);

	return TRUE;
}


SAVEDS ULONG mCleanup(struct IClass *cl,Object *obj,Msg msg)
{
	struct MyData *data = INST_DATA(cl, obj);

	MUI_ReleasePen(muiRenderInfo(obj),data->pen);

	return DoSuperMethodA(cl, obj, msg);
}


SAVEDS ULONG mAskMinMax(struct IClass *cl,Object *obj,struct MUIP_AskMinMax *msg)
{
	/*
	** let our superclass first fill in what it thinks about sizes.
	** this will e.g. add the size of frame and inner spacing.
	*/

	DoSuperMethodA(cl, obj, (Msg)msg);

	/*
	** now add the values specific to our object. note that we
	** indeed need to *add* these values, not just set them!
	*/

	msg->MinMaxInfo->MinWidth  += 100;
	msg->MinMaxInfo->DefWidth  += 120;
	msg->MinMaxInfo->MaxWidth  += 500;

	msg->MinMaxInfo->MinHeight += 40;
	msg->MinMaxInfo->DefHeight += 90;
	msg->MinMaxInfo->MaxHeight += 300;

	return 0;
}


/*
** Draw method is called whenever MUI feels we should render
** our object. This usually happens after layout is finished
** or when we need to refresh in a simplerefresh window.
** Note: You may only render within the rectangle
**       _mleft(obj), _mtop(obj), _mwidth(obj), _mheight(obj).
*/

SAVEDS ULONG mDraw(struct IClass *cl,Object *obj,struct MUIP_Draw *msg)
{
	struct MyData *data = INST_DATA(cl, obj);
	int i;

	/*
	** let our superclass draw itself first, area class would
	** e.g. draw the frame and clear the whole region. What
	** it does exactly depends on msg->flags.
	*/

	DoSuperMethodA(cl, obj, (Msg)msg);

	/*
	** if MADF_DRAWOBJECT isn't set, we shouldn't draw anything.
	** MUI just wanted to update the frame or something like that.
	*/

	if (!(msg->flags & MADF_DRAWOBJECT))
		return 0;

	/*
	** test if someone changed our pen
	*/

	if (data->penchange)
	{
		data->penchange = FALSE;
		MUI_ReleasePen(muiRenderInfo(obj),data->pen);
		data->pen = MUI_ObtainPen(muiRenderInfo(obj),&data->penspec,0);
	}

	/*
	** ok, everything ready to render...
	** Note that we *must* use the MUIPEN() macro before actually
	** using pens from MUI_ObtainPen() in rendering calls.
	*/

	SetAPen(_rp(obj),MUIPEN(data->pen));

	for (i=_mleft(obj);i<=_mright(obj);i+=5)
	{
		Move(_rp(obj),_mleft(obj),_mtop(obj));
		Draw(_rp(obj),i,_mbottom(obj));
		Move(_rp(obj),_mright(obj),_mtop(obj));
		Draw(_rp(obj),i,_mbottom(obj));
	}

	return 0;
}


/*
** Here comes the dispatcher for our custom class. We only need to
** care about MUIM_AskMinMax and MUIM_Draw in this simple case.
** Unknown/unused methods are passed to the superclass immediately.
*/

DISPATCHER(MyDispatcher)
{
	switch(msg->MethodID)
	{
		case OM_NEW        : return(mNew      (cl, obj, (APTR)msg));
		case OM_DISPOSE    : return(mDispose  (cl, obj, (APTR)msg));
		case OM_SET        : return(mSet      (cl, obj, (APTR)msg));
		case OM_GET        : return(mGet      (cl, obj, (APTR)msg));
		case MUIM_AskMinMax: return(mAskMinMax(cl, obj, (APTR)msg));
		case MUIM_Setup    : return(mSetup    (cl, obj, (APTR)msg));
		case MUIM_Cleanup  : return(mCleanup  (cl, obj, (APTR)msg));
		case MUIM_Draw     : return(mDraw     (cl, obj, (APTR)msg));
	}

	return DoSuperMethodA(cl, obj, msg);
}



/***************************************************************************/
/* Thats all there is about it. Now lets see how things are used...        */
/***************************************************************************/

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app,*window,*MyObj,*pen;
	struct MUI_CustomClass *mcc;
	struct MUI_PenSpec *startpen;

	init();

	/* Create the new custom class with a call to MUI_CreateCustomClass(). */
	/* Caution: This function returns not a struct IClass, but a           */
	/* struct MUI_CustomClass which contains a struct IClass to be         */
	/* used with NewObject() calls.                                        */
	/* Note well: MUI creates the dispatcher hook for you, you may         */
	/* *not* use its h_Data field! If you need custom data, use the        */
	/* cl_UserData of the IClass structure!                                */

	if (!(mcc = MUI_CreateCustomClass(NULL,MUIC_Area,NULL,sizeof(struct MyData),ENTRY(MyDispatcher))))
		fail(NULL,"Could not create custom class.");

	// set up a specific name for our class
	mcc->mcc_Class->cl_ID = (ClassID)"Class2";

	app = ApplicationObject,
		MUIA_Application_Title      , "Class2",
		MUIA_Application_Version    , "$VER: Class2 21.2 (24.01.2017)",
		MUIA_Application_Copyright  , "(C) 1992-2006 Stefan Stuntz, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Stefan Stuntz, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "Demonstrate the use of custom classes.",
		MUIA_Application_Base       , "CLASS2",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Another Custom Class",
			MUIA_Window_ID   , MAKE_ID('C','L','S','2'),
			WindowContents, VGroup,

				Child, TextObject,
					TextFrame,
					MUIA_Background, MUII_TextBack,
					MUIA_Text_Contents, "\33cThis is a custom class with attributes.\nClick on the button at the bottom of\nthe window to adjust the color.",
					End,

				Child, MyObj = NewObject(mcc->mcc_Class,NULL,
					TextFrame,
					MUIA_Background, MUII_BACKGROUND,
					TAG_DONE),

				Child, HGroup, MUIA_Weight, 10,
					Child, FreeLabel("Custom Class Color:"),
					Child, pen = PoppenObject,
						MUIA_CycleChain, 1,
						MUIA_Window_Title, "Custom Class Color",
						End,
					End,

				End,

			End,
		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

	DoMethod(pen,MUIM_Notify,MUIA_Pendisplay_Spec,MUIV_EveryTime,
		MyObj,3,MUIM_Set,MYATTR_PEN,MUIV_TriggerValue);

	DoMethod(pen,MUIM_Pendisplay_SetMUIPen,MPEN_HALFSHINE);

	get(pen,MUIA_Pendisplay_Spec,&startpen);
	set(MyObj,MYATTR_PEN,startpen);

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

	MUI_DisposeObject(app);     /* dispose all objects. */
	MUI_DeleteCustomClass(mcc); /* delete the custom class. */
	fail(NULL,NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
