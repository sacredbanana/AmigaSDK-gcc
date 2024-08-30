#include "demo.h"


static const char *QuickVols[] = {"dh0:","dh1:","df0:","df1:","ram:","sys:"};


#define showreq(obj,msg) MUI_Request((APTR)_xget(obj,MUIA_ApplicationObject),(APTR)_xget(obj,MUIA_WindowObject),0,NULL,"OK",msg)


LONG _xget(Object *obj,ULONG attribute)
{
	LONG x;
	get(obj,attribute,&x);
	return(x);
}


BOOL CheckDirs(APTR *lists)
{
	if (_xget(lists[0],MUIA_Dirlist_Status)!=MUIV_Dirlist_Status_Valid)
	{
		showreq(lists[0],"Source directory invalid.");
		return FALSE;
	}
	else if (_xget(lists[1],MUIA_Dirlist_Status)!=MUIV_Dirlist_Status_Valid)
	{
		showreq(lists[0],"Destination directory invalid.");
		return FALSE;
	}
	return TRUE;
}


HOOKPROTONHNO(CopyFunc, void, APTR *lists)
{
	struct FileInfoBlock *fib;
	LONG id = -1;

	if (!CheckDirs(lists)) return;

	for (;;)
	{
		DoMethod(lists[0],MUIM_List_NextSelected,&id);
		if (id==-1) break;

		DoMethod(lists[0],MUIM_List_GetEntry,id,&fib);
		printf("copy %s to %s\n",fib->fib_FileName,(char *)_xget(lists[1],MUIA_Dirlist_Directory));
	}
	printf("---\n");
}
MakeStaticHook(CopyHook, CopyFunc);


HOOKPROTONHNO(MoveFunc, void, APTR *lists)
{
	struct FileInfoBlock *fib;
	LONG id = -1;

	if (!CheckDirs(lists)) return;

	for (;;)
	{
		DoMethod(lists[0],MUIM_List_NextSelected,&id);
		if (id==-1) break;

		DoMethod(lists[0],MUIM_List_GetEntry,id,&fib);
		printf("move %s to %s\n",fib->fib_FileName,(char *)_xget(lists[1],MUIA_Dirlist_Directory));
	}
	printf("---\n");
}
MakeStaticHook(MoveHook, MoveFunc);


HOOKPROTONHNO(DeleteFunc, void, APTR *lists)
{
	struct FileInfoBlock *fib;
	LONG id = -1;

	for (;;)
	{
		DoMethod(lists[0],MUIM_List_NextSelected,&id);
		if (id==-1) break;

		DoMethod(lists[0],MUIM_List_GetEntry,id,&fib);
		printf("delete %s\n",fib->fib_FileName);
	}
	printf("---\n");
}
MakeStaticHook(DeleteHook, DeleteFunc);


struct FileAction
{
	const char *name;
	int controlchar;
	struct Hook *hook;
};

static const struct FileAction FileActions[] =
{
	{ "Copy"  , 'c', &CopyHook},
	{ "Move"  , 'm', &MoveHook},
	{ "Delete", 'd', &DeleteHook},
};


Object *MakeList(APTR *list)
{
	APTR obj,volgroup,str;

	obj = VGroup, GroupSpacing(0),
		Child, str   = String(0,256),
		Child, *list = DirlistObject,
			MUIA_List_MultiSelect, TRUE,
			MUIA_List_Title, TRUE,
			InputListFrame,
			End,
		Child, volgroup = HGroup,
			MUIA_Group_SameSize, TRUE,
			GroupSpacing(0),
			End,
		End;

	if (obj)
	{
		int i;

		DoMethod(str,MUIM_Notify,MUIA_String_Acknowledge,MUIV_EveryTime,
			*list,3,MUIM_Set,MUIA_Dirlist_Directory,MUIV_TriggerValue);

		for (i=0;i<(int)(sizeof(QuickVols)/sizeof(char *));i++)
		{
			Object *bt;

			bt = TextObject,
				ButtonFrame,
				MUIA_Text_Contents, QuickVols[i],
				MUIA_Text_PreParse, "\33c",
				MUIA_InputMode    , MUIV_InputMode_RelVerify,
				MUIA_Background   , MUII_ButtonBack,
				MUIA_Font         , MUIV_Font_Tiny,
				End;

			if (bt)
			{
				DoMethod(volgroup,OM_ADDMEMBER,bt);

				DoMethod(bt,MUIM_Notify,MUIA_Pressed,FALSE,
					*list,3,MUIM_Set,MUIA_Dirlist_Directory,QuickVols[i]);

				DoMethod(bt,MUIM_Notify,MUIA_Pressed,FALSE,
					str,3,MUIM_Set,MUIA_String_Contents,QuickVols[i]);
			}
		}
	}

	return(obj);
}


int main(UNUSED int argc, UNUSED char *argv[])
{
	ULONG signals = 0;
	BOOL running = TRUE;
	int i;
	APTR app,window,actgroup,list[2];

	init();

	app = ApplicationObject,
		MUIA_Application_Title      , "MultiSel",
		MUIA_Application_Version    , "$VER: MultiSel 21.2 (08.02.2018)",
		MUIA_Application_Copyright  , "(C) 1992-2006 Stefan Stuntz, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Stefan Stuntz, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "MultiSel something.",
		MUIA_Application_Base       , "MULTISEL",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "MultiSel",
			MUIA_Window_ID   , MAKE_ID('T','E','S','T'),
			WindowContents, VGroup,
				Child, HGroup,
					Child, MakeList(&list[0]),
					Child, MakeList(&list[1]),
					End,
				Child, actgroup = HGroup,
					MUIA_Group_SameSize, TRUE,
					End,
				End,
			End,
		End;

	if (!app)
		fail(app,"Failed to create Application.");

	for (i=0;i<(int)(sizeof(FileActions)/sizeof(struct FileAction));i++)
	{
		APTR bt;

		bt = TextObject,
			ButtonFrame,
			MUIA_Text_Contents, FileActions[i].name,
			MUIA_Text_PreParse, "\33c",
			MUIA_Text_HiChar  , FileActions[i].controlchar,
			MUIA_ControlChar  , FileActions[i].controlchar,
			MUIA_InputMode    , MUIV_InputMode_RelVerify,
			MUIA_Background   , MUII_ButtonBack,
			End;

		DoMethod(actgroup,OM_ADDMEMBER,bt);

		DoMethod(bt,MUIM_Notify,MUIA_Pressed,FALSE,
			bt,4,MUIM_CallHook,FileActions[i].hook,list[0],list[1]);
	}


	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);


	set(window,MUIA_Window_Open,TRUE);

	while (running)
	{
		switch (DoMethod(app,MUIM_Application_NewInput,&signals))
		{
			case MUIV_Application_ReturnID_Quit:
				running = FALSE;
				break;
		}

		if (running && signals)
		{
			signals = Wait(signals | SIGBREAKF_CTRL_C);
			if(signals & SIGBREAKF_CTRL_C) break;
		}
	}

	set(window,MUIA_Window_Open,FALSE);

	fail(app,NULL);

	// just to please the compiler
	return 0;
}
