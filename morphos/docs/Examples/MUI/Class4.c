#include "demo.h"

/* Instance Data */

struct MyData
{
	Object *proc;
	LONG index;
};


/* Attributes and methods for the custom class */

#define MUISERIALNR_STUNTZI 1
#define TAGBASE_STUNTZI (TAG_USER | ( MUISERIALNR_STUNTZI << 16))
#define MUIM_Class4_Signal (TAGBASE_STUNTZI | 0x0001)
#define MUIM_Class4_Start  (TAGBASE_STUNTZI | 0x0002)
#define MUIM_Class4_Stop   (TAGBASE_STUNTZI | 0x0003)


/* Some strings to display */

static const char *LifeOfBrian[] =
{
	"Cheer up, Brian. You know what they say.",
	"Some things in life are bad,",
	"They can really make you mad.",
	"Other things just make you swear and curse.",
	"When you're chewing on life's grissle,",
	"Don't grumble, give a whistle.",
	"And this'll help things turn out for the best,",
	"And...",
	"Always look on the bright side of life",
	"Always look on the light side of life",
	"If life seems jolly rotten,",
	"There's something you've forgotten,",
	"And that's to laugh, and smile, and dance, and sing.",
	"When you're feeling in the dumps,",
	"Don't be silly chumps,",
	"Just purse your lips and whistle, that's the thing.",
	"And...",
	"Always look on the bright side of life, come on!",
	"Always look on the right side of life",
	"For life is quite absurd,",
	"And death's the final word.",
	"You must always face the curtain with a bow.",
	"Forget about your sin,",
	"Give the audience a grin.",
	"Enjoy it, it's your last chance anyhow,",
	"So...",
	"Always look on the bright side of death",
	"Just before you draw your terminal breath.",
	"Life's a piece of shit,",
	"When you look at it.",
	"Life's a laugh, and death's a joke, it's true.",
	"You'll see it's all a show,",
	"Keep 'em laughing as you go,",
	"Just remember that the last laugh is on you.",
	"And...",
	"Always look on the bright side of life !",
	"...",
	"*** THE END ***",
	"",
	NULL,
};



/***************************************************************************/
/* Here is the beginning of our new class...                               */
/***************************************************************************/


ULONG mNew(struct IClass *cl,Object *obj,Msg msg)
{
	struct MyData *data;

	if (!(obj = (Object *)DoSuperMethodA(cl,obj,msg)))
		return(0);

	data = INST_DATA(cl,obj);

	/* process object 'embedded' into class instance. */

	data->proc = MUI_NewObject(MUIC_Process,
			MUIA_Process_SourceClass , cl,
			MUIA_Process_SourceObject, obj,
			MUIA_Process_Priority    , -1,
			MUIA_Process_AutoLaunch  , FALSE,
			TAG_DONE);

	if (data->proc != NULL)
		return (IPTR)obj;

	CoerceMethod(cl,obj,OM_DISPOSE);
	return(0);
}


ULONG mDispose(struct IClass *cl,Object *obj,Msg msg)
{
	struct MyData *data = INST_DATA(cl,obj);

	/* disposing process object will wait for the process to finish */

	MUI_DisposeObject(data->proc);

	return(DoSuperMethodA(cl,obj,msg));
}


ULONG mSetup(struct IClass *cl,Object *obj,Msg msg)
{
	struct MyData *data = INST_DATA(cl,obj);

	if (!DoSuperMethodA(cl,obj,msg))
		return(FALSE);

	/* launch process when objects is layouted and ready */

	DoMethod(data->proc, MUIM_Process_Launch);

	return(TRUE);
}


ULONG mCleanup(struct IClass *cl,Object *obj,Msg msg)
{
	struct MyData *data = INST_DATA(cl,obj);

	/* kill thread when main window is iconified or gone */

	DoMethod(data->proc, MUIM_Process_Kill, 0);

	return(DoSuperMethodA(cl,obj,msg));
}


ULONG mProcess(struct IClass *cl,Object *obj,struct MUIP_Process_Process *msg)
{
	struct MyData *data = INST_DATA(cl,obj);
	struct Process *myproc = (struct Process *)FindTask(NULL);
	ULONG methodid = 0;

	while (!*msg->kill)
	{
		ULONG signals = SetSignal(0L, SIGBREAKF_CTRL_D);

		/* only way to invoke methods on objects from main process is to use MUIM_Application_PushMethod! */

		if (signals & SIGBREAKF_CTRL_D)
			methodid = DoMethod(_app(obj), MUIM_Application_PushMethod, obj, 3, MUIM_Set, MUIA_Text_Contents, "Signaled!");
		else
		{
			methodid = DoMethod(_app(obj), MUIM_Application_PushMethod, obj, 3, MUIM_Set, MUIA_Text_Contents, LifeOfBrian[data->index]);
			if (!LifeOfBrian[++data->index])
				data->index = 0;
		}

		/* process can wait for CTRL_C signal which means termination or any other signal supplied by user */

		Delay(500);
	}

	/* to be sure method is not executed after we quite, kill it */

	DoMethod(_app(obj), MUIM_Application_UnpushMethod, obj, methodid, 0);

	return 0;
}

ULONG mSignal(struct IClass *cl,Object *obj,Msg msg)
{
	struct MyData *data = INST_DATA(cl,obj);

	/* send CTRL_D signal to the process.  */

	DoMethod(data->proc, MUIM_Process_Signal, SIGBREAKF_CTRL_D);

	return 0;
}

ULONG mStart(struct IClass *cl, Object *obj, Msg msg)
{
	struct MyData *data = INST_DATA(cl,obj);

	DoMethod(data->proc, MUIM_Process_Launch);

	return 0;
}

ULONG mStop(struct IClass *cl, Object *obj, Msg msg)
{
	struct MyData *data = INST_DATA(cl,obj);
	BOOL rc = DoMethod(data->proc, MUIM_Process_Kill, 2);
	
	if (rc) 
		set(obj, MUIA_Text_Contents, "Stopped");
	else
		set(obj, MUIA_Text_Contents, "Kill timed out!");

	return 0;
}

/*
** Here comes the dispatcher for our custom class.
*/

DISPATCHER(MyClass)
{
	switch (msg->MethodID)
	{
		case OM_NEW               : return(mNew    (cl,obj,(APTR)msg));
		case OM_DISPOSE           : return(mDispose(cl,obj,(APTR)msg));
		case MUIM_Setup           : return(mSetup  (cl,obj,(APTR)msg));
		case MUIM_Cleanup         : return(mCleanup(cl,obj,(APTR)msg));
		case MUIM_Process_Process : return(mProcess(cl,obj,(APTR)msg));
		case MUIM_Class4_Signal   : return(mSignal (cl,obj,(APTR)msg));
		case MUIM_Class4_Start    : return(mStart  (cl,obj,(APTR)msg));
		case MUIM_Class4_Stop     : return(mStop   (cl,obj,(APTR)msg));
	}

	return(DoSuperMethodA(cl,obj,msg));
}
DISPATCHER_END



/***************************************************************************/
/* Thats all there is about it. Now lets see how things are used...        */
/***************************************************************************/

int main(int argc,char *argv[])
{
	Object *app,*window,*MyObj, *SigButton, *StartButton, *StopButton;
	struct MUI_CustomClass *mcc;

	init();

	/* Create the new custom class with a call to MUI_CreateCustomClass(). */
	/* Caution: This function returns not a struct IClass, but a           */
	/* struct MUI_CustomClass which contains a struct IClass to be         */
	/* used with NewObject() calls.                                        */
	/* Note well: MUI creates the dispatcher hook for you, you may         */
	/* *not* use its h_Data field! If you need custom data, use the        */
	/* cl_UserData of the IClass structure!                                */

	if (!(mcc = MUI_CreateCustomClass(NULL,MUIC_Text,NULL,sizeof(struct MyData),DISPATCHER_REF(MyClass))))
		fail(NULL,"Could not create custom class.");

	app = ApplicationObject,
		MUIA_Application_Title      , "Class4",
		MUIA_Application_Version    , "$VER: Class4 20.165 (17.04.2010)",
		MUIA_Application_Copyright  , "© 2010 Michal Wozniak",
		MUIA_Application_Author     , "Michal Wozniak",
		MUIA_Application_Description, "Demonstrate the use of custom classes with subprocess.",
		MUIA_Application_Base       , "Class4",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Process Class Demo",
			MUIA_Window_ID   , MAKE_ID('C','L','S','6'),
			WindowContents, VGroup,

				Child, TextObject,
					TextFrame,
					MUIA_Background, MUII_TextBack,
					MUIA_Text_Contents, "\33cDemonstration of a Process class.",
					End,

				Child, MyObj = NewObject(mcc->mcc_Class,NULL,
					MUIA_Frame, MUIV_Frame_None,
					MUIA_Text_PreParse, "\33c",
					TAG_DONE),

				Child, SigButton = SimpleButton("Signal!"),
				
				Child, HGroup,
					Child, StartButton = SimpleButton("Start"),
					Child, StopButton = SimpleButton("Stop!"),
					End,

				End,

			End,
		End;

	if (!app)
	{
		MUI_DeleteCustomClass(mcc); /* delete the custom class. */
		fail(app,"Failed to create Application.");
	}

	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

	DoMethod(SigButton,MUIM_Notify,MUIA_Pressed,FALSE,
		MyObj,1,MUIM_Class4_Signal);
		
	DoMethod(StartButton,MUIM_Notify,MUIA_Pressed,FALSE,
		MyObj,1,MUIM_Class4_Start);
		
	DoMethod(StopButton,MUIM_Notify,MUIA_Pressed,FALSE,
		MyObj,1,MUIM_Class4_Stop);


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
