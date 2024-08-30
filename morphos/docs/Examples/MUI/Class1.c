#include "demo.h"


/***************************************************************************/
/* Here is the beginning of our simple new class...                        */
/***************************************************************************/

/*
** This is an example for the simplest possible MUI class. It's just some
** kind of custom image and supports only two methods: 
** MUIM_AskMinMax and MUIM_Draw.
*/

/*
** This is the instance data for our custom class.
** Since it's a very simple class, it contains just a dummy entry.
*/

struct MyData
{
	LONG dummy;
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

	DoSuperMethodA(cl,obj,msg);

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

	return(0);
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
	int i;

	/*
	** let our superclass draw itself first, area class would
	** e.g. draw the frame and clear the whole region. What
	** it does exactly depends on msg->flags.
	*/

	DoSuperMethodA(cl,obj,msg);

	/*
	** if MADF_DRAWOBJECT isn't set, we shouldn't draw anything.
	** MUI just wanted to update the frame or something like that.
	*/

	if (!(msg->flags & MADF_DRAWOBJECT))
		return(0);

	/*
	** ok, everything ready to render...
	*/

	SetAPen(_rp(obj),_dri(obj)->dri_Pens[TEXTPEN]);

	for (i=_mleft(obj);i<=_mright(obj);i+=5)
	{
		Move(_rp(obj),_mleft(obj),_mbottom(obj));
		Draw(_rp(obj),i,_mtop(obj));
		Move(_rp(obj),_mright(obj),_mbottom(obj));
		Draw(_rp(obj),i,_mtop(obj));
	}

	return(0);
}


/*
** Here comes the dispatcher for our custom class. We only need to
** care about MUIM_AskMinMax and MUIM_Draw in this simple case.
** Unknown/unused methods are passed to the superclass immediately.
*/

DISPATCHER(MyClass)
{
	switch (msg->MethodID)
	{
		case MUIM_AskMinMax: return(mAskMinMax(cl,obj,(APTR)msg));
		case MUIM_Draw     : return(mDraw     (cl,obj,(APTR)msg));
	}

	return(DoSuperMethodA(cl,obj,msg));
}
DISPATCHER_END


/***************************************************************************/
/* Thats all there is about it. Now lets see how things are used...        */
/***************************************************************************/

int main(int argc,char *argv[])
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

	if (!(mcc = MUI_CreateCustomClass(NULL,MUIC_Area,NULL,sizeof(struct MyData),DISPATCHER_REF(MyClass))))
		fail(NULL,"Could not create custom class.");

	app = ApplicationObject,
		MUIA_Application_Title      , "Class1",
		MUIA_Application_Version    , "$VER: Class1 20.165 (04.04.03)",
		MUIA_Application_Copyright  , "© 1993 Stefan Stuntz",
		MUIA_Application_Author     , "Stefan Stuntz",
		MUIA_Application_Description, "Demonstrate the use of custom classes.",
		MUIA_Application_Base       , "CLASS1",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "A Simple Custom Class",
			MUIA_Window_ID   , MAKE_ID('C','L','S','1'),
			WindowContents, VGroup,

				Child, MyObj = NewObject(mcc->mcc_Class,NULL,
					TextFrame,
					MUIA_Background, MUII_BACKGROUND,
					TAG_DONE),

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

		while (DoMethod(app,MUIM_Application_NewInput,&sigs) != MUIV_Application_ReturnID_Quit)
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
	return(0);
}
