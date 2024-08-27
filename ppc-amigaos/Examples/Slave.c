#include "demo.h"

/* Instance Data */

struct MyData
{
	Object *slave;
	LONG slaveSignal;
	LONG index;
	struct MUI_InputHandlerNode ih;
};


/* Attributes and methods for the custom class */

#define MUISERIALNR_STUNTZI 1
#define TAGBASE_STUNTZI (TAG_USER | ( MUISERIALNR_STUNTZI << 16))
#define MUIM_MyClass_Timer            (TAGBASE_STUNTZI | 0x0001)
#define MUIM_MyClass_Signal           (TAGBASE_STUNTZI | 0x0002)
#define MUIM_MyClass_DispatchOnSlave  (TAGBASE_STUNTZI | 0x0003)
#define MUIM_MyClass_DispatchOnMain   (TAGBASE_STUNTZI | 0x0004)

struct MUIP_MyClass_DispatchOnMain
{
	ULONG MethodID;
	STRPTR text;
};

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


ULONG mSetup(struct IClass *cl, Object *obj, Msg msg)
{
	struct MyData *data = INST_DATA(cl, obj);
	ULONG rc;

	if((rc = DoSuperMethodA(cl, obj, msg)) != 0)
	{
		// show messages once per second
	    data->ih.ihn_Flags  = MUIIHNF_TIMER;
	    data->ih.ihn_Method = MUIM_MyClass_Timer;
	    data->ih.ihn_Object = obj;
	    data->ih.ihn_Millis = 1000;

	    data->slaveSignal = -1;

		// create the Slave object to handle the asynchronous methods
		// as soon as we are fully set up
		if((data->slave = MUI_NewObject(MUIC_Slave,
			MUIA_Slave_Class, cl,
			MUIA_Slave_Object, obj,
			MUIA_Process_Name, "Slave demo slave process",
			TAG_DONE)) == NULL)
		{
			rc = FALSE;
		}
	}

	return rc;
}


ULONG mCleanup(struct IClass *cl, Object *obj, Msg msg)
{
	struct MyData *data = INST_DATA(cl, obj);

	// kill the Slave object when main window is iconified or gone
	MUI_DisposeObject(data->slave);
	data->slave = NULL;

	return DoSuperMethodA(cl, obj, msg);
}


ULONG mSlaveSetup(struct IClass *cl, Object *obj, UNUSED Msg msg)
{
	struct MyData *data = INST_DATA(cl, obj);

	// add the input handler now that the slave process is up and running
	DoMethod(_app(obj), MUIM_Application_AddInputHandler, &data->ih);

	// allocate a custom signal
	data->slaveSignal = AllocSignal(-1);

	// report the allocated signal mask
	return (1 << data->slaveSignal);
}


ULONG mSlaveCleanup(struct IClass *cl, Object *obj, UNUSED Msg msg)
{
	struct MyData *data = INST_DATA(cl, obj);

	// remove the input handler again before the slave process eventually terminates
	DoMethod(_app(obj), MUIM_Application_RemInputHandler, &data->ih);

	// free the allocated signal
	FreeSignal(data->slaveSignal);
	data->slaveSignal = -1;

	return 0;
}


ULONG mSlaveSignalsReceived(struct IClass *cl, Object *obj, struct MUIP_Slave_SignalsReceived *msg)
{
	struct MyData *data = INST_DATA(cl, obj);

	// react on our allocated signal
	if(msg->sigmask & (1 << data->slaveSignal))
	{
		STRPTR text;

		if((text = strdup("Signaled!")) != NULL)
		{
			// return control to the main thread to display the message
			if(DoMethod(data->slave, MUIM_Slave_Dispatch, 0, 2, MUIM_MyClass_DispatchOnMain, text) == FALSE)
			{
				// dispatch failed
				free(text);
			}
		}
	}

	return 0;
}


ULONG mSlaveError(UNUSED struct IClass *cl, UNUSED Object *obj, struct MUIP_Slave_Error *msg)
{
	// free all dynamically allocated parameters of methods that failed to be dispatched
	switch(((Msg)msg->FailedDispatch)->MethodID)
	{
		case MUIM_MyClass_DispatchOnMain:
		{
			struct MUIP_MyClass_DispatchOnMain *dmsg = (struct MUIP_MyClass_DispatchOnMain *)msg->FailedDispatch;

			free(dmsg->text);
		}
		break;
	}

	return 0;
}


ULONG mDispatchOnSlave(struct IClass *cl, Object *obj, UNUSED Msg msg)
{
	// this method is executed in the Slave's process
	struct MyData *data = INST_DATA(cl, obj);
	STRPTR text;

	if((text = strdup(LifeOfBrian[data->index])) != NULL)
	{
		if(DoMethod(data->slave, MUIM_Slave_Dispatch, 0, 2, MUIM_MyClass_DispatchOnMain, text) == FALSE)
		{
			// dispatch failed
			free(text);
		}

		data->index++;
		if(LifeOfBrian[data->index] == NULL)
			data->index = 0;
	}

	return 0;
}


ULONG mDispatchOnMain(UNUSED struct IClass *cl, Object *obj, struct MUIP_MyClass_DispatchOnMain *msg)
{
	// this method is executed in the main process
	set(obj, MUIA_Text_Contents, msg->text);

	// free the dynamically allocated text
	free(msg->text);

	return 0;
}


ULONG mTimer(struct IClass *cl,Object *obj,UNUSED Msg msg)
{
	struct MyData *data = INST_DATA(cl, obj);

	DoMethod(data->slave, MUIM_Slave_Dispatch, 0, 1, MUIM_MyClass_DispatchOnSlave);

	return 0;
}


ULONG mSignal(struct IClass *cl,Object *obj,UNUSED Msg msg)
{
	struct MyData *data = INST_DATA(cl, obj);

	// send our allocated signal to the process
	DoMethod(data->slave, MUIM_Process_Signal, (1 << data->slaveSignal));

	return 0;
}


/*
** Here comes the dispatcher for our custom class.
*/

DISPATCHER(MyDispatcher)
{
	switch(msg->MethodID)
	{
		case MUIM_Setup                  : return mSetup(cl, obj, (APTR)msg);
		case MUIM_Cleanup                : return mCleanup(cl, obj, (APTR)msg);
		case MUIM_Slave_Setup            : return mSlaveSetup(cl, obj, (APTR)msg);
		case MUIM_Slave_Cleanup          : return mSlaveCleanup(cl, obj, (APTR)msg);
		case MUIM_Slave_SignalsReceived  : return mSlaveSignalsReceived(cl, obj, (APTR)msg);
		case MUIM_Slave_Error            : return mSlaveError(cl, obj, (APTR)msg);
		case MUIM_MyClass_Timer          : return mTimer(cl, obj, (APTR)msg);
		case MUIM_MyClass_Signal         : return mSignal(cl, obj, (APTR)msg);
		case MUIM_MyClass_DispatchOnSlave: return mDispatchOnSlave(cl, obj, (APTR)msg);
		case MUIM_MyClass_DispatchOnMain : return mDispatchOnMain(cl, obj, (APTR)msg);
	}

	return DoSuperMethodA(cl, obj, msg);
}



/***************************************************************************/
/* Thats all there is about it. Now lets see how things are used...        */
/***************************************************************************/

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app, *window, *MyObj, *SigButton;
	struct MUI_CustomClass *mcc;

	init();

	/* Create the new custom class with a call to MUI_CreateCustomClass(). */
	/* Caution: This function returns not a struct IClass, but a           */
	/* struct MUI_CustomClass which contains a struct IClass to be         */
	/* used with NewObject() calls.                                        */
	/* Note well: MUI creates the dispatcher hook for you, you may         */
	/* *not* use its h_Data field! If you need custom data, use the        */
	/* cl_UserData of the IClass structure!                                */

	if((mcc = MUI_CreateCustomClass(NULL, MUIC_Text, NULL, sizeof(struct MyData), ENTRY(MyDispatcher))) == NULL)
		fail(NULL, "Could not create custom class.");

	// set up a specific name for our class
	mcc->mcc_Class->cl_ID = (ClassID)"Slave";

	app = ApplicationObject,
		MUIA_Application_Title      , "Slave",
		MUIA_Application_Version    , "$VER: Slave 21.2 (28.04.2018)",
		MUIA_Application_Copyright  , "(C) 2018-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "Demonstrate the use of Slave class.",
		MUIA_Application_Base       , "SLAVE",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Slave Class Demo",
			MUIA_Window_ID, MAKE_ID('S','L','A','V'),
			WindowContents, VGroup,

				Child, TextObject,
					TextFrame,
					MUIA_Background, MUII_TextBack,
					MUIA_Text_Contents, "\33cDemonstration of a Slave class.",
					End,

				Child, MyObj = NewObject(mcc->mcc_Class, NULL,
					MUIA_Frame, MUIV_Frame_None,
					MUIA_Text_PreParse, "\33c",
					TAG_DONE),

				Child, SigButton = SimpleButton("Signal!"),

				End,

			End,
		End;

	if(app == NULL)
	{
		MUI_DeleteCustomClass(mcc); /* delete the custom class. */
		fail(app, "Failed to create Application.");
	}

	DoMethod(window, MUIM_Notify,MUIA_Window_CloseRequest, TRUE, app, 2, MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);
	DoMethod(SigButton, MUIM_Notify, MUIA_Pressed, FALSE, MyObj, 1, MUIM_MyClass_Signal);


/*
** This is the ideal input loop for an object oriented MUI application.
** Everything is encapsulated in classes, no return ids need to be used,
** we just check if the program shall terminate.
*/

	set(window, MUIA_Window_Open, TRUE);

	DoMethod(app, MUIM_Application_Run);

	set(window, MUIA_Window_Open, FALSE);


/*
** Shut down...
*/

	MUI_DisposeObject(app);     /* dispose all objects. */
	MUI_DeleteCustomClass(mcc); /* delete the custom class. */
	fail(NULL, NULL);           /* exit, app is already disposed. */
	return 0;
}
