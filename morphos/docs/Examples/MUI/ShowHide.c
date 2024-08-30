/*
** The ShowHide demo shows how to hide and show objects.
*/

#include "demo.h"


#ifdef MYDEBUG
Object *makeobj(int num)
{
	Object *obj;
	char buf[20];

	sprintf(buf,"Button\n%ld",num);

	obj = TextObject,
		ButtonFrame,
		MUIA_Background, MUII_ButtonBack,
		MUIA_InputMode, MUIV_InputMode_RelVerify,
		MUIA_Text_PreParse, "\33c",
		MUIA_Text_Contents, buf,
		MUIA_Text_SetVMax, FALSE,
		End;

	if (obj)
	{
		DoMethod(obj,MUIM_Notify,MUIA_Pressed,FALSE,obj,3,MUIM_Set,MUIA_ShowMe,FALSE);

		if (num==5 || num==10)
		{
			sprintf(buf,"%ld",num);
			set(obj,MUIA_Text_Contents,buf);
			set(obj,MUIA_Text_SetVMax,TRUE);
			set(obj,MUIA_Text_SetMax,TRUE);
		}
	}

	return(obj);
}
#endif


int main(int argc,char *argv[])
{
	Object *app,*window,*cm1,*cm2,*cm3,*cm4,*cm5,*bt1,*bt2,*bt3,*bt4,*bt5;

	init();

	app = ApplicationObject,
		MUIA_Application_Title      , "ShowHide",
		MUIA_Application_Version    , "$VER: ShowHide 20.170 (04.04.03)",
		MUIA_Application_Copyright  , "© 1992/93 Stefan Stuntz",
		MUIA_Application_Author     , "Stefan Stuntz",
		MUIA_Application_Description, "Show object hiding.",
		MUIA_Application_Base       , "SHOWHIDE",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Show & Hide",
			MUIA_Window_ID   , MAKE_ID('S','H','H','D'),

			WindowContents, HGroup,

				Child, VGroup, GroupFrame,

					Child, HGroup, MUIA_Weight, 0,
						Child, cm1 = CheckMark(TRUE),
						Child, cm2 = CheckMark(TRUE),
						Child, cm3 = CheckMark(TRUE),
						Child, cm4 = CheckMark(TRUE),
						Child, cm5 = CheckMark(TRUE),
						End,

					Child, VGroup,
						Child, bt1 = SimpleButton("Button 1"),
						Child, bt2 = SimpleButton("Button 2"),
						Child, bt3 = SimpleButton("Button 3"),
						Child, bt4 = SimpleButton("Button 4"),
						Child, bt5 = SimpleButton("Button 5"),
						Child, VSpace(0),
						End,

					End,

				#ifdef MYDEBUG
				Child, ColGroup(4), GroupFrame, MUIA_Background, MUII_FILL,
					Child, makeobj(0),
					Child, makeobj(1),
					Child, makeobj(2),
					Child, makeobj(3),
					Child, makeobj(4),
					Child, makeobj(5),
					Child, makeobj(6),
					Child, makeobj(7),
					Child, makeobj(8),
					Child, makeobj(9),
					Child, makeobj(10),
					Child, makeobj(11),
					Child, makeobj(12),
					Child, makeobj(13),
					Child, makeobj(14),
					/*Child, makeobj(15),*/
					End,
				#endif

				End,
			End,
		End;

	if (!app)
		fail(app,"Failed to create Application.");


/*
** Install notification events...
*/

	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

	DoMethod(cm1,MUIM_Notify,MUIA_Selected,MUIV_EveryTime,bt1,3,MUIM_Set,MUIA_ShowMe,MUIV_TriggerValue);
	DoMethod(cm2,MUIM_Notify,MUIA_Selected,MUIV_EveryTime,bt2,3,MUIM_Set,MUIA_ShowMe,MUIV_TriggerValue);
	DoMethod(cm3,MUIM_Notify,MUIA_Selected,MUIV_EveryTime,bt3,3,MUIM_Set,MUIA_ShowMe,MUIV_TriggerValue);
	DoMethod(cm4,MUIM_Notify,MUIA_Selected,MUIV_EveryTime,bt4,3,MUIM_Set,MUIA_ShowMe,MUIV_TriggerValue);
	DoMethod(cm5,MUIM_Notify,MUIA_Selected,MUIV_EveryTime,bt5,3,MUIM_Set,MUIA_ShowMe,MUIV_TriggerValue);

	set(cm3,MUIA_Selected,FALSE);

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

	fail(app,NULL);
	return(0);
}
