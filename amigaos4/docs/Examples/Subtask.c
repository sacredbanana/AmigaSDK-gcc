/*

This little demo show how to write classes which need a long
time to render their contents. In this case, we take a little
fractal algorithm as example. The actual calculations are
done in a separate task, the display is updated from time
to time.

*/

#include "demo.h"
#include <dos/dostags.h>
#include <exec/memory.h>


/* Pixel dimensions of our fractal */

#define FRACTALWIDTH  300
#define FRACTALHEIGHT 300


/* Fractal Description */

struct FractalDesc
{
	float left;
	float right;
	float top;
	float bottom;
};

#define MaxIterations 60

/* Attributes and methods for the custom class */

#define MUISERIALNR_STUNTZI 1
#define TAGBASE_STUNTZI (TAG_USER | ( MUISERIALNR_STUNTZI << 16))

#define MUIM_Class4_Update (TAGBASE_STUNTZI | 0x0001)
struct MUIP_Class4_Update
{
	ULONG id;
	LONG percent;
};

#define MUIM_Class4_Calc   (TAGBASE_STUNTZI | 0x0002)
struct MUIP_Class4_Calc
{
	ULONG id;
	struct FractalDesc *fd;
};

#define MUIA_Class4_Percent (TAGBASE_STUNTZI | 0x0003)


#define STC_START 0
#define STC_STOP  1


/* Instance Data for the fractal class */

struct Data
{
	struct SignalSemaphore sema;    /* data item protection      */
	Object                *app;     /* pointer to application    */
	Object                *self;    /* pointer to ourselves      */
	struct SubTask        *subtask; /* our sub task              */
	struct RastPort        rp;      /* rastport for the sub task */
	BYTE                  *udlines; /* line update flags array   */
};




/**************************************************************/
/* Functions for easy and secure spawning/killing of subtasks */
/**************************************************************/

struct SubTaskMsg
{
	struct Message stm_Message;
	WORD           stm_Command;
	APTR           stm_Parameter;
	LONG           stm_Result;
};

struct SubTask
{
	struct Task      *st_Task;    /* sub task pointer */
	struct MsgPort   *st_Port;    /* allocated by sub task */
	struct MsgPort   *st_Reply;   /* allocated by main task */
	APTR              st_Data;    /* more initial data to pass to the sub task */
	struct SubTaskMsg st_Message; /* Message buffer */
};

#define STC_STARTUP  -2
#define STC_SHUTDOWN -1

LONG SendSubTaskMsg(struct SubTask *st,WORD command,APTR params)
{
	st->st_Message.stm_Message.mn_ReplyPort = st->st_Reply;
	st->st_Message.stm_Message.mn_Length    = sizeof(struct SubTaskMsg);
	st->st_Message.stm_Command              = command;
	st->st_Message.stm_Parameter            = params;
	st->st_Message.stm_Result               = 0;

	PutMsg(command==STC_STARTUP ? &((struct Process *)st->st_Task)->pr_MsgPort : st->st_Port,(struct Message *)&st->st_Message);
	WaitPort(st->st_Reply);
	GetMsg(st->st_Reply);

	return(st->st_Message.stm_Result);
}

struct SubTask *SpawnSubTask(const char *name,VOID (*func)(VOID),APTR data)
{
	struct SubTask *st;

	#if defined(__amigaos4__)
	if((st = AllocVecTags(sizeof(struct SubTask),
		AVT_ClearWithValue, 0,
		AVT_Type, MEMF_SHARED,
		TAG_DONE)) != NULL)
	{
		if((st->st_Reply = AllocSysObjectTags(ASOT_PORT, TAG_DONE)) != NULL)
		{
	#else
	if((st = AllocVec(sizeof(struct SubTask),MEMF_PUBLIC|MEMF_CLEAR)))
	{
		if((st->st_Reply = CreateMsgPort()))
		{
	#endif
			st->st_Data = data;

			if((st->st_Task = (struct Task *)CreateNewProcTags(NP_Entry, 	func,
																												 NP_Name,		name,
																												 TAG_DONE)
				))
			{
				if (SendSubTaskMsg(st,STC_STARTUP,st))
				{
					return(st);
				}
			}
			#if defined(__amigaos4__)
			FreeSysObject(ASOT_PORT, st->st_Reply);
			#else
			DeleteMsgPort(st->st_Reply);
			#endif
		}
		FreeVec(st);
	}
	return NULL;
}

VOID KillSubTask(struct SubTask *st)
{
	SendSubTaskMsg(st,STC_SHUTDOWN,st);
	#if defined(__amigaos4__)
	FreeSysObject(ASOT_PORT, st->st_Reply);
	#else
	DeleteMsgPort(st->st_Reply);
	#endif
	FreeVec(st);
}

/* the following functions are called from the sub task */

VOID ExitSubTask(struct SubTask *st,struct SubTaskMsg *stm)
{
	/*
	** We reply after a Forbid() to make sure we're really gone
	** when the main task continues.
	*/

	if (st->st_Port)
	{
		#if defined(__amigaos4__)
		FreeSysObject(ASOT_PORT, st->st_Port);
		#else
		DeleteMsgPort(st->st_Port);
		#endif
	}

	Forbid();
	stm->stm_Result = FALSE;
	ReplyMsg((struct Message *)stm);
}

struct SubTask *InitSubTask(void)
{
	struct Task *me = FindTask(NULL);
	struct SubTask *st;
	struct SubTaskMsg *stm;

	/*
	** Wait for our startup message from the SpawnSubTask() function.
	*/

	WaitPort(&((struct Process *)me)->pr_MsgPort);
	stm  = (struct SubTaskMsg *)GetMsg(&((struct Process *)me)->pr_MsgPort);
	st   = (struct SubTask *)stm->stm_Parameter;

	#if defined(__amigaos4__)
	if((st->st_Port = AllocSysObjectTags(ASOT_PORT, TAG_DONE)) != NULL)
	#else
	if ((st->st_Port = CreateMsgPort()))
	#endif
	{
		/*
		** Reply startup message, everything ok.
		** Note that if the initialization fails, the code falls
		** through and replies the startup message with a stm_Result
		** of 0 after a Forbid(). This tells SpawnSubTask() that the
		** sub task failed to run.
		*/

		stm->stm_Result = TRUE;
		ReplyMsg((struct Message *)stm);
		return(st);
	}
	else
	{
		ExitSubTask(st,stm);
		return NULL;
	}
}


/*******************************************************/
/* Subtask which does all the time-consuming rendering */
/*******************************************************/

VOID ASM SAVEDS RenderFunc(VOID)
{
	struct SubTask *st;
	struct Library *GfxBase;

	if ((GfxBase = OpenLibrary("graphics.library",37))) /* dont share library pointers! */
	{
		if ((st = InitSubTask()))
		{
			struct Data *data = st->st_Data;
			BOOL running = TRUE;
			BOOL worktodo = FALSE;
			LONG x=0,y=0;
			struct SubTaskMsg *stm;
			float left=0,top=0,right=0,bottom=0;

			/*
			** after the sub task is up and running, we go into
			** a loop and process the messages from the main task.
			*/

			for (;;)
			{
				while ((stm = (struct SubTaskMsg *)GetMsg(st->st_Port)))
				{
					switch (stm->stm_Command)
					{
						case STC_SHUTDOWN:
							/*
							** This is the shutdown message from KillSubTask().
							*/
							running = FALSE;
							break;

						case STC_START:
							/*
							** we received a start message with a fractal description.
							** clear the rastport and the line update array and start
							** rendering.
							*/
							SetRast(&data->rp,1);
							memset(data->udlines,0,FRACTALHEIGHT);
							left   = ((struct FractalDesc *)stm->stm_Parameter)->left  ;
							top    = ((struct FractalDesc *)stm->stm_Parameter)->top   ;
							right  = ((struct FractalDesc *)stm->stm_Parameter)->right ;
							bottom = ((struct FractalDesc *)stm->stm_Parameter)->bottom;
							y = 0;
							worktodo = TRUE;
							break;

						case STC_STOP:
							/* this message is not used in this example */
							worktodo = FALSE;
							break;
					}

					/*
					** If we received a shutdown message, we do not reply it
					** immediately. First, we need to free our resources.
					*/
					if (!running) break;

					ReplyMsg((struct Message *)stm);
				}

				if (!running) break;

				if (worktodo)
				{
					/* if there is work to do, i.e. if the fractal is not
					** finished yet, we calculate the next line and draw
					** it to the offscreen rastport.
	   			*/

					for (x=0;x<FRACTALWIDTH;x++)
					{
						float zr = 0.0;
						float zi = 0.0;
						float cr = left + x * (right - left) / FRACTALWIDTH;
						float ci = top  + y * (bottom - top) / FRACTALHEIGHT;
						float rr = zr * zr;
						float ii = zi * zi;
						int counter;

						for (counter=0;counter<MaxIterations;counter++)
						{
							zi = ci + zr * zi * 2;
							zr = cr + rr - ii;
							rr = zr * zr;
							ii = zi * zi;

							if (rr + ii >= 4.0)
							{
								/*
								** set the pixel in the offscreen rastport.
								** this demo is kind of dirty, as it does no
								** nice color allocation and palette stuff.
								** dont be so dirty in your own programs! :-)
								*/

								SetAPen(&data->rp,1+counter);
								WritePixel(&data->rp,x,y);
								break;
							}

							if (++counter==MaxIterations)
							{
								break;
							}
						}
					}

					/*
					** after the line is finished, we set the corresponding
					** flag in the line update array to FALSE. This shows the
					** main task that this line needs to be redrawn the next
					** time it gets the chance.
					*/

					ObtainSemaphore(&data->sema);
					data->udlines[y] = FALSE;
					if (data->app)
					{
						/*
						** if our class is attached to an application, we send ourselves
						** an update method. Note that because we are in a separate task,
						** we cannot send this method directly but instead have to use
						** the MUIM_Application_PushMethod call. This is the only method
						** that you may send to a MUI object from a separate task. What it
						** does is to copy the method to a private buffer and wait until
						** the next time the main task calls the input method. Then, our
						** update method will be executed under the main tasks context.
						**
						** If our class is not attached to an application
						** (i.e. we are outside of MUIM_Setup/MUIM_Cleanup), there is
						** nobody who could render something anyway so we just skip
						** the update method and continue to render in our private
						** buffer.
						*/

						DoMethod(data->app,MUIM_Application_PushMethod,data->self,2,MUIM_Class4_Update,100*(y+1)/FRACTALHEIGHT);
					}
					ReleaseSemaphore(&data->sema);

					if (++y==FRACTALHEIGHT)
					{
						/* check if we are finished to draw our fractal */
						worktodo = FALSE;
					}

					/* Since we are very busy working, we do not Wait() for signals. */
				}
				else
				{
					/* We have nothing to do, just sit quietly and wait for something to happen */
					WaitPort(st->st_Port);
				}
			}
			ExitSubTask(st,stm);
		}
		CloseLibrary(GfxBase);
	}
}



/***************************************************************************/
/* Here is the beginning of our new class...                               */
/***************************************************************************/


SAVEDS ULONG mNew(struct IClass *cl,Object *obj,Msg msg)
{
	struct Data *data;

	if (!(obj = (Object *)DoSuperMethodA(cl,obj,msg)))
		return 0;

	data = INST_DATA(cl, obj);
	memset(data,0,sizeof(*data));

	/* store a pointer to ourselves so the subtask knows about us */
	data->self = obj;

	/*
	** initialization and allocation of data structures.
	** note that if something fails here, we *must* do a
	** CoerceMethod(cl,obj,OM_DISPOSE) to give ourselves
	** (and MUI!) a chance to clean up.
	*/

	InitSemaphore(&data->sema);
	InitRastPort(&data->rp);

	#if defined(__amigaos4__)
	if ((data->udlines = AllocVecTags(FRACTALHEIGHT,
		AVT_ClearWithValue, 0,
		AVT_Type, MEMF_SHARED,
		TAG_DONE)) != NULL)
	#else
	if ((data->udlines = AllocVec(FRACTALHEIGHT,MEMF_CLEAR)))
	#endif
	{
		if ((data->rp.BitMap = AllocBitMap(FRACTALWIDTH,FRACTALHEIGHT,8,BMF_CLEAR,NULL)))
		{
			SetRast(&data->rp,1);

			/* the following call starts the sub task */

			if ((data->subtask = SpawnSubTask("Render-Task",RenderFunc,data)))
			{
				SetTaskPri(data->subtask->st_Task,-1);
				return (ULONG)obj;
			}
		}
	}

	CoerceMethod(cl,obj,OM_DISPOSE);
	return 0;
}



SAVEDS ULONG mDispose(struct IClass *cl,Object *obj,Msg msg)
{
	struct Data *data = INST_DATA(cl, obj);

	if (data->subtask)
		KillSubTask(data->subtask);

	if (data->rp.BitMap)
		FreeBitMap(data->rp.BitMap);

	if (data->udlines)
		FreeVec(data->udlines);

	return DoSuperMethodA(cl, obj, msg);
}



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

	msg->MinMaxInfo->MinWidth  += 10;
	msg->MinMaxInfo->DefWidth  += 100;
	msg->MinMaxInfo->MaxWidth  += FRACTALWIDTH;

	msg->MinMaxInfo->MinHeight += 10;
	msg->MinMaxInfo->DefHeight += 100;
	msg->MinMaxInfo->MaxHeight += FRACTALHEIGHT;

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
	** properly!
	*/

	DoSuperMethodA(cl, obj, (Msg)msg);

	if (msg->flags & MADF_DRAWUPDATE)
	{
		/*
		** This flag indicates that we were called from our
		** update method. We needn't render the complete
		** image, we only need to update the lines that
		** were changed. So what we do is to browse through
		** the line flag array and blit each changed line
		** from the offscreen buffer into the display.
		** We could do a better and more efficient job
		** by collecting subsequent changed lines to blit
		** larger rectangles, but hey... this is only a demo! :-)
		*/

		int l;

		/*
		** note the usage of semaphores to protect access
		** to variables use by both tasks.
		*/

		ObtainSemaphore(&data->sema);

		for (l=0;l<_mheight(obj);l++)
		{
			if (!data->udlines[l])
			{
				/*
				** once we copied the line, we set the corresponding line flag
				** to indicate that this line is uptodate and does not need
				** to be redrawn the next time. When our sub task gets the message
				** to calculate a new fractal, it will reset the flag to FALSE again.
				*/

				BltBitMapRastPort(data->rp.BitMap,0,l,_rp(obj),_mleft(obj),_mtop(obj)+l,_mwidth(obj),1,0xc0);
				data->udlines[l] = TRUE;
			}
		}

		ReleaseSemaphore(&data->sema);
	}
	else if (msg->flags & MADF_DRAWOBJECT)
	{
		/*
		** we were called directly from MUI because the window needs refresh.
		** no need to care about our line array here, we just copy the complete
		** offscreen buffer to our display.
		*/

		ObtainSemaphore(&data->sema);
		BltBitMapRastPort(data->rp.BitMap,0,0,_rp(obj),_mleft(obj),_mtop(obj),_mwidth(obj),_mheight(obj),0xc0);
		ReleaseSemaphore(&data->sema);
	}

	return 0;
}


SAVEDS ULONG mSetup(struct IClass *cl,Object *obj,Msg msg)
{
	struct Data *data = INST_DATA(cl, obj);

	if (!(DoSuperMethodA(cl,obj,msg)))
		return FALSE;

	/*
	** set a pointer to our application in our instance data.
	** this tells the sub task that we should be notified
	** when a new line is calculated.
	*/

	ObtainSemaphore(&data->sema);
	get(obj,MUIA_ApplicationObject,&data->app);
	ReleaseSemaphore(&data->sema);

	return TRUE;
}


SAVEDS ULONG mCleanup(struct IClass *cl,Object *obj,Msg msg)
{
	struct Data *data = INST_DATA(cl, obj);

	ObtainSemaphore(&data->sema);
	data->app = NULL;
	ReleaseSemaphore(&data->sema);

	return DoSuperMethodA(cl, obj, msg);
}


/*
** a simple method that sends a START msg with
** fractal description packet to the sub task.
*/

SAVEDS ULONG mCalc(struct IClass *cl,Object *obj,struct MUIP_Class4_Calc *msg)
{
	struct Data *data = INST_DATA(cl, obj);
	SendSubTaskMsg(data->subtask,STC_START,msg->fd);
	return 0;
}


/*
** thats the method that is called through MUIM_Application_PushMethod
** from the subtask.
*/

SAVEDS ULONG mUpdate(UNUSED struct IClass *cl,Object *obj,struct MUIP_Class4_Update *msg)
{
	/* Tell MUI to redraw our object. Set the update flag
	** so we know that only the changed lines are subject
	** to render.
	*/

	MUI_Redraw(obj,MADF_DRAWUPDATE);

	/*
	** Also set the percentage attribute. The class itself doesnt
	** have any use for this, but if we set it, its possible
	** for other objects (e.g. a gauge) to receive notifications
	*/

	set(obj,MUIA_Class4_Percent,msg->percent);

	return 0;
}


/*
** Here comes the dispatcher for our custom class.
** Unknown/unused methods are passed to the superclass immediately.
*/

DISPATCHER(MyDispatcher)
{
	switch(msg->MethodID)
	{
		case OM_NEW            : return(mNew      (cl, obj, (APTR)msg));
		case OM_DISPOSE        : return(mDispose  (cl, obj, (APTR)msg));
		case MUIM_AskMinMax    : return(mAskMinMax(cl, obj, (APTR)msg));
		case MUIM_Draw         : return(mDraw     (cl, obj, (APTR)msg));
		case MUIM_Setup        : return(mSetup    (cl, obj, (APTR)msg));
		case MUIM_Cleanup      : return(mCleanup  (cl, obj, (APTR)msg));
		case MUIM_Class4_Update: return(mUpdate   (cl, obj, (APTR)msg));
		case MUIM_Class4_Calc  : return(mCalc     (cl, obj, (APTR)msg));
	}

	return DoSuperMethodA(cl, obj, msg);
}



/****************************************************************************/
/* Misc Help Functions                                                      */
/****************************************************************************/

LONG _xget(Object *obj,ULONG attribute)
{
	LONG x;
	get(obj,attribute,&x);
	return(x);
}

char *getstr(Object *obj)
{
	return((char *)_xget(obj,MUIA_String_Contents));
}



/***************************************************************************/
/* Thats all there is about it. Now lets see how things are used...        */
/***************************************************************************/

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app,*window,*MyObj;
	Object *strleft,*strtop,*strright,*strbottom,*start,*gauge;
	struct MUI_CustomClass *mcc;
	ULONG signals = 0;
	BOOL running = TRUE;

	if (((struct Library *)SysBase)->lib_Version < 39)
	{
		fprintf(stderr,"runs only with V39 and up\n");
		exit(20);
	}

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
	mcc->mcc_Class->cl_ID = (ClassID)"Subtask";

	app = ApplicationObject,
		MUIA_Application_Title      , "Class4",
		MUIA_Application_Version    , "$VER: Class4 21.2 (24.01.2017)",
		MUIA_Application_Copyright  , "(C) 1992-2006 Stefan Stuntz, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Stefan Stuntz, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "Demonstrate rendering from sub tasks.",
		MUIA_Application_Base       , "Class4",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Subtask rendering",
			MUIA_Window_ID   , MAKE_ID('C','L','S','4'),
			WindowContents, VGroup,

				Child, HGroup, GroupSpacing(8),
					Child, ColGroup(2),
						Child, Label2("_Left:"  ), Child, strleft   = MUI_MakeObject(MUIO_String,"_L",30),
						Child, Label2("_Right:" ), Child, strright  = MUI_MakeObject(MUIO_String,"_R",30),
						End,
					Child, ColGroup(2),
						Child, Label2("_Top:"   ), Child, strtop    = MUI_MakeObject(MUIO_String,"_T",30),
						Child, Label2("_Bottom:"), Child, strbottom = MUI_MakeObject(MUIO_String,"_B",30),
						End,
					Child, MUI_MakeObject(MUIO_VBar,2),
					Child, start = VGroup,
						GroupSpacing(0),
						MUIA_Weight, 0,
						ButtonFrame,
						MUIA_InputMode , MUIV_InputMode_RelVerify,
						MUIA_Background, MUII_ButtonBack,
						Child, VSpace(0),
						Child, TextObject, MUIA_Text_Contents, "\33c  Start  ", End,
						Child, VSpace(0),
						End,
					End,

				Child, gauge = GaugeObject,
					GaugeFrame,
					MUIA_Gauge_Horiz, TRUE,
					MUIA_Gauge_Max, 100,
					MUIA_FixHeight, 8,
					End,

				Child, MyObj = NewObject(mcc->mcc_Class,NULL,
					TextFrame,
					MUIA_Background, MUII_BACKGROUND,
					TAG_DONE),

				End,
			End,
		End;

	if (!app)
	{
		MUI_DeleteCustomClass(mcc); /* delete the custom class. */
		fail(app,"Failed to create Application.");
	}

	set(window,MUIA_Window_DefaultObject, MyObj);

	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

	DoMethod(start,MUIM_Notify,MUIA_Pressed,FALSE,
		app,2,MUIM_Application_ReturnID,1);

	DoMethod(MyObj,MUIM_Notify,MUIA_Class4_Percent,MUIV_EveryTime,
		gauge,3,MUIM_Set,MUIA_Gauge_Current,MUIV_TriggerValue);

	set(strleft  ,MUIA_String_Contents,"-2.0");
	set(strright ,MUIA_String_Contents,"1.0");
	set(strtop   ,MUIA_String_Contents,"1.5");
	set(strbottom,MUIA_String_Contents,"-1.5");

/*
** Input loop...
*/

	set(window,MUIA_Window_Open,TRUE);

	while (running)
	{
		switch (DoMethod(app,MUIM_Application_NewInput,&signals))
		{
			case MUIV_Application_ReturnID_Quit:
				running = FALSE;
				break;

			case 1:
			{
				struct FractalDesc fd;

				fd.left   = atof(getstr(strleft  ));
				fd.right  = atof(getstr(strright ));
				fd.top    = atof(getstr(strtop   ));
				fd.bottom = atof(getstr(strbottom));

				if (fd.right > fd.left && fd.top > fd.bottom)
					DoMethod(MyObj,MUIM_Class4_Calc,&fd);
				else
					DisplayBeep(0);
			}
			break;
		}

		if (running && signals)
		{
			signals = Wait(signals | SIGBREAKF_CTRL_C);
			if(signals & SIGBREAKF_CTRL_C) break;
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
