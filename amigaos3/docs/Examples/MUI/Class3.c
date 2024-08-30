#include "demo.h"


/***************************************************************************/
/* Here is the beginning of our new class...                               */
/***************************************************************************/

/*
** This is the instance data for our custom class.
*/

struct Data
{
	int x,y,sx,sy;
	struct MUI_EventHandlerNode eh;
};


/*
** AskMinMax method will be called before the window is opened
** and before layout takes place. We need to tell MUI the
** minimum, maximum and default size of our object.
*/

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
	struct Data *data = INST_DATA(cl, obj);

	/*
	** let our superclass draw itself first, area class would
	** e.g. draw the frame and clear the whole region. What
	** it does exactly depends on msg->flags.
	**
	** Note: You *must* call the super method prior to do
	** anything else, otherwise msg->flags will not be set
	** properly !
	*/

	DoSuperMethodA(cl, obj, (Msg)msg);

	/*
	** if MADF_DRAWOBJECT isn't set, we shouldn't draw anything.
	** MUI just wanted to update the frame or something like that.
	*/

	if (msg->flags & MADF_DRAWUPDATE) /* called from our input method */
	{
		if (data->sx || data->sy)
		{
			SetBPen(_rp(obj),_dri(obj)->dri_Pens[SHINEPEN]);
			ScrollRaster(_rp(obj),data->sx,data->sy,_mleft(obj),_mtop(obj),_mright(obj),_mbottom(obj));
			SetBPen(_rp(obj),0);
			data->sx = 0;
			data->sy = 0;
		}
		else
		{
			SetAPen(_rp(obj),_dri(obj)->dri_Pens[SHADOWPEN]);
			/* it may look superflous to substract the upper left corner coordinates in MUIM_HandleEvent
			** and to add them now again, but this is necessary for correct doublebuffering, because that
			** feature might shift the coordinate system and mixing up internal coordinates (the upper
			** left corner) and and external coordinate (the mouse position) will produce pixels at the
			** wrong position otherwise. This approach is guaranteed to produce correct results no matter
			** if doublebuffering is active or not.
			*/
			WritePixel(_rp(obj),_mleft(obj)+data->x,_mtop(obj)+data->y);
		}
	}
	else if (msg->flags & MADF_DRAWOBJECT)
	{
		SetAPen(_rp(obj),_dri(obj)->dri_Pens[SHINEPEN]);
		RectFill(_rp(obj),_mleft(obj),_mtop(obj),_mright(obj),_mbottom(obj));
	}

	return 0;
}


SAVEDS ULONG mSetup(struct IClass *cl,Object *obj,Msg msg)
{
	struct Data *data = INST_DATA(cl, obj);

	if (!(DoSuperMethodA(cl,obj,msg)))
		return FALSE;

	data->eh.ehn_Class  = cl;
	data->eh.ehn_Object = obj;
	data->eh.ehn_Events = IDCMP_MOUSEBUTTONS|IDCMP_RAWKEY;
	data->eh.ehn_Flags  = MUI_EHF_GUIMODE;
	data->eh.ehn_Priority = -1;

	if(_win(obj) != NULL)
		DoMethod(_win(obj), MUIM_Window_AddEventHandler, &data->eh);

	return TRUE;
}


SAVEDS ULONG mCleanup(struct IClass *cl,Object *obj,Msg msg)
{
	struct Data *data = INST_DATA(cl, obj);

	if(_win(obj) != NULL)
		DoMethod(_win(obj), MUIM_Window_RemEventHandler, &data->eh);

	return DoSuperMethodA(cl, obj, msg);
}


SAVEDS ULONG mHandleEvent(struct IClass *cl,Object *obj,struct MUIP_HandleEvent *msg)
{
	#define _between(a,x,b) ((x)>=(a) && (x)<=(b))
	#define _isinobject(x,y) (_between(_mleft(obj),(x),_mright(obj)) && _between(_mtop(obj),(y),_mbottom(obj)))

	struct Data *data = INST_DATA(cl, obj);
	ULONG rc = 0;

	if (msg->muikey!=MUIKEY_NONE)
	{
		switch (msg->muikey)
		{
			case MUIKEY_LEFT : data->sx=-1; MUI_Redraw(obj,MADF_DRAWUPDATE); rc = MUI_EventHandlerRC_Eat; break;
			case MUIKEY_RIGHT: data->sx= 1; MUI_Redraw(obj,MADF_DRAWUPDATE); rc = MUI_EventHandlerRC_Eat; break;
			case MUIKEY_UP   : data->sy=-1; MUI_Redraw(obj,MADF_DRAWUPDATE); rc = MUI_EventHandlerRC_Eat; break;
			case MUIKEY_DOWN : data->sy= 1; MUI_Redraw(obj,MADF_DRAWUPDATE); rc = MUI_EventHandlerRC_Eat; break;
		}
	}

	if (msg->imsg)
	{
		switch (msg->imsg->Class)
		{
			case IDCMP_MOUSEBUTTONS:
			{
				if (msg->imsg->Code==SELECTDOWN)
				{
					if (_isinobject(msg->imsg->MouseX,msg->imsg->MouseY))
					{
						/* use corrdinates relative to the upper left corner of the object */
						data->x = msg->imsg->MouseX-_mleft(obj);
						data->y = msg->imsg->MouseY-_mtop(obj);
						MUI_Redraw(obj,MADF_DRAWUPDATE);

						// request IDCMP_MOUSEMOVE events
						DoMethod(_win(obj), MUIM_Window_RemEventHandler, &data->eh);
						data->eh.ehn_Events |= IDCMP_MOUSEMOVE;
						DoMethod(_win(obj), MUIM_Window_AddEventHandler, &data->eh);
						// don't let other classes see this input event
						rc = MUI_EventHandlerRC_Eat;
					}
				}
				else
				{
					// reject IDCMP_MOUSEMOVE events
					DoMethod(_win(obj), MUIM_Window_RemEventHandler, &data->eh);
					data->eh.ehn_Events &= ~IDCMP_MOUSEMOVE;
					DoMethod(_win(obj), MUIM_Window_AddEventHandler, &data->eh);
				}
			}
			break;

			case IDCMP_MOUSEMOVE:
			{
				if (_isinobject(msg->imsg->MouseX,msg->imsg->MouseY))
				{
					/* use corrdinates relative to the upper left corner of the object */
					data->x = msg->imsg->MouseX-_mleft(obj);
					data->y = msg->imsg->MouseY-_mtop(obj);
					MUI_Redraw(obj,MADF_DRAWUPDATE);
				}
			}
			break;
		}
	}

	return rc;
}


/*
** Here comes the dispatcher for our custom class.
** Unknown/unused methods are passed to the superclass immediately.
*/

DISPATCHER(MyDispatcher)
{
	switch(msg->MethodID)
	{
		case MUIM_AskMinMax  : return(mAskMinMax  (cl, obj, (APTR)msg));
		case MUIM_Draw       : return(mDraw       (cl, obj, (APTR)msg));
		case MUIM_HandleEvent: return(mHandleEvent(cl, obj, (APTR)msg));
		case MUIM_Setup      : return(mSetup      (cl, obj, (APTR)msg));
		case MUIM_Cleanup    : return(mCleanup    (cl, obj, (APTR)msg));
	}

	return DoSuperMethodA(cl, obj, msg);
}



/***************************************************************************/
/* Thats all there is about it. Now lets see how things are used...        */
/***************************************************************************/

int main(UNUSED int argc, UNUSED char *argv[])
{
	APTR app,window,MyObj;
	struct MUI_CustomClass *mcc;

	init();

	/* Create the new custom class with a call to MUI_CreateCustomClass(). */
	/* Caution: This function returns not a struct IClass, but a           */
	/* struct MUI_CustomClass which contains a struct IClass to be         */
	/* used with NewObject() calls.                                        */
	/* Note well: MUI creates the dispatcher hook for you, you may         */
	/* *not* use its h_Data field! If you need custom data, use the        */
	/* cl_UserData of the IClass structure!                                */

	if (!(mcc = MUI_CreateCustomClass(NULL,MUIC_Area,NULL,sizeof(struct Data),ENTRY(MyDispatcher))))
		fail(NULL,"Could not create custom class.");

	// set up a specific name for our class
	mcc->mcc_Class->cl_ID = (ClassID)MUIC_Area "/Class3";

	app = ApplicationObject,
		MUIA_Application_Title      , "Class3",
		MUIA_Application_Version    , "$VER: Class3 21.3 (23.10.2017)",
		MUIA_Application_Copyright  , "(C) 1992-2006 Stefan Stuntz, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Stefan Stuntz, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "Demonstrate the use of custom classes.",
		MUIA_Application_Base       , "CLASS3",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "A rather complex custom class",
			MUIA_Window_ID   , MAKE_ID('C','L','S','3'),
			WindowContents, VGroup,

				Child, TextObject,
					TextFrame,
					MUIA_Background, MUII_TextBack,
					MUIA_Text_Contents, "\33cPaint with mouse,\nscroll with cursor keys.",
					End,

				Child, MyObj = NewObject(mcc->mcc_Class,NULL,
					TextFrame,
					TAG_DONE),

				End,

			End,
		End;

	if (!app)
		fail(app,"Failed to create Application.");

	set(window,MUIA_Window_DefaultObject, MyObj);

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

	MUI_DisposeObject(app);     /* dispose all objects. */
	MUI_DeleteCustomClass(mcc); /* delete the custom class. */
	fail(NULL,NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
