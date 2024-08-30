#include "demo.h"

/*
 * Hook, called with the following:
 * n - name of the hook (_hook appened at the end)
 * y - a2
 * z - a1
 *
 * return type is LONG
 */
#ifdef __MORPHOS__

#define NOPROF __attribute__((no_instrument_function))

#define MUI_HOOK(n, y, z) \
	static LONG n##_GATE(void); \
	static LONG n##_GATE2(struct Hook *h, y, z); \
	static const struct EmulLibEntry n = { TRAP_LIB, 0, (void (*)(void))n##_GATE }; \
	static LONG NOPROF n##_GATE(void) { return (n##_GATE2((void *)REG_A0, (void *)REG_A2, (void *)REG_A1)); } \
	static const struct Hook n##_Hook = { { 0, 0}, (void *)&n, (void *)&n##_GATE2 }; \
	static LONG n##_GATE2(struct Hook *h, y, z)

#else

#define __reg(r,x) REG(r) x

#define MUI_HOOK(n, y, z) \
	static LONG ASM SAVEDS n##_func(__reg(a0, struct Hook *h), __reg(a2, y), __reg(a1, z)); \
	static const struct Hook n##Hook = { {NULL,NULL}, (void *)n##_func,NULL,NULL }; \
	static LONG ASM SAVEDS n##_func(__reg(a0, struct Hook *h), __reg(a2, y), __reg(a1, z))

#endif /* !_MORPHOS__ */


MUI_HOOK(StrObjFunc, Object *pop, Object *str)
{
	char *x,*s;
	int i;

	get(str,MUIA_String_Contents,&s);

	for (i=0;;i++)
	{
		DoMethod(pop,MUIM_List_GetEntry,i,&x);
		if (!x)
		{
			set(pop,MUIA_List_Active,MUIV_List_Active_Off);
			break;
		}
		else if (!stricmp(x,s))
		{
			set(pop,MUIA_List_Active,i);
			break;
		}
	}
	return(TRUE);
}


MUI_HOOK(ObjStrFunc, Object *pop, Object *str)
{
	char *x;
	DoMethod(pop,MUIM_List_GetEntry,MUIV_List_GetEntry_Active,&x);
	set(str,MUIA_String_Contents,x);
	return 0;
}


MUI_HOOK(WindowFunc, Object *pop, Object *win)
{
	set(win,MUIA_Window_DefaultObject,pop);
	set(win,MUIA_Window_ID,27);
	return 0;
}


static const char *PopNames[] =
{
	"Stefan Becker",
	"Dirk Federlein",
	"Georg Heﬂmann",
	"Martin Horneffer",
	"Martin Huttenloher",
	"Kai Iske",
	"Oliver Kilian",
	"Frank Mariak",
	"Klaus Melchior",
	"Armin Sander",
	"Matthias Scheler",
	"Andreas Schildbach",
	"Wolfgang Schildbach",
	"Christian Scholz",
	"Stefan Sommerfeld",
	"Markus Stipp",
	"Henri Veistera",
	"Albert Weinert",
	"Michael-W. Hohmann", 
	"Stefan Burstroem",
	NULL
};


int main(int argc,char *argv[])
{
	APTR app,window,pop1,pop2,pop3,pop4,pop5,plist;
	ULONG signals;
	BOOL running = TRUE;

	init();

	app = ApplicationObject,
		MUIA_Application_Title      , "Popup-Demo",
		MUIA_Application_Version    , "$VER: Popup-Demo 20.167 (04.04.03)",
		MUIA_Application_Copyright  , "© 1993 Stefan Stuntz",
		MUIA_Application_Author     , "Stefan Stuntz",
		MUIA_Application_Description, "Demostrate popup objects.",
		MUIA_Application_Base       , "POPUP",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Popup Objects",
			MUIA_Window_ID   , MAKE_ID('P','O','P','P'),
			WindowContents, VGroup,

				Child, ColGroup(2),

					Child, KeyLabel2("File:",'f'),
					Child, pop1 = PopaslObject,
						MUIA_Popstring_String, KeyString(0,256,'f'),
						MUIA_Popstring_Button, PopButton(MUII_PopFile),
						ASLFR_TitleText, "Please select a file...",
						End,

					Child, KeyLabel2("Drawer:",'d'),
					Child, pop2 = PopaslObject,
						MUIA_Popstring_String, KeyString(0,256,'d'),
						MUIA_Popstring_Button, PopButton(MUII_PopDrawer),
						ASLFR_TitleText  , "Please select a drawer...",
						ASLFR_DrawersOnly, TRUE,
						End,

					Child, KeyLabel2("Font:",'o'),
					Child, pop3 = PopaslObject,
						MUIA_Popstring_String, KeyString(0,80,'o'),
						MUIA_Popstring_Button, PopButton(MUII_PopFont),
						MUIA_Popasl_Type , ASL_FontRequest,
						ASLFO_TitleText  , "Please select a font...",
						End,

					Child, KeyLabel2("Fixed Font:",'i'),
					Child, pop4 = PopaslObject,
						MUIA_Popstring_String, KeyString(0,80,'i'),
						MUIA_Popstring_Button, PopButton(MUII_PopFont),
						MUIA_Popasl_Type , ASL_FontRequest,
						ASLFO_TitleText  , "Please select a fixed font...",
						ASLFO_FixedWidthOnly, TRUE,
						End,

					Child, KeyLabel2("Thanks To:",'n'),
					Child, pop5 = PopobjectObject,
						MUIA_Popstring_String, KeyString(0,60,'n'),
						MUIA_Popstring_Button, PopButton(MUII_PopUp),
						MUIA_Popobject_StrObjHook, &StrObjFunc_Hook,
						MUIA_Popobject_ObjStrHook, &ObjStrFunc_Hook,
						MUIA_Popobject_WindowHook, &WindowFunc_Hook,
						MUIA_Popobject_Light, FALSE,
						MUIA_Popobject_Object, plist = ListviewObject,
							MUIA_Listview_List, ListObject,
								InputListFrame,
								MUIA_List_SourceArray, PopNames,
								End,
							End,
						End,

					/*
					Child, KeyLabel2("Thanks To:",'n'),
					Child, pop5 = PoplistObject,
						MUIA_Popstring_String, KeyString(0,60,'n'),
						MUIA_Popstring_Button, PopButton(MUII_PopUp),
						MUIA_Poplist_Array, PopNames,
						End,
					*/

					End,
				End,
			End,
		End;

	if (!app)
		fail(app,"Failed to create Application.");

	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

	DoMethod(window,MUIM_Window_SetCycleChain,pop1,pop2,pop3,pop4,pop5,NULL);

	/* A double click terminates the popping list with a successful return value. */
	DoMethod(plist,MUIM_Notify,MUIA_Listview_DoubleClick,TRUE,
		pop5,2,MUIM_Popstring_Close,TRUE);


/*
** Input loop...
*/

	set(window,MUIA_Window_Open,TRUE);

	while (running)
	{
		switch (DoMethod(app,MUIM_Application_Input,&signals))
		{
			case MUIV_Application_ReturnID_Quit:
			{
         	LONG active;

				get(pop1,MUIA_Popasl_Active,&active);
				if (!active) get(pop2,MUIA_Popasl_Active,&active);
				if (!active) get(pop3,MUIA_Popasl_Active,&active);
				if (!active) get(pop4,MUIA_Popasl_Active,&active);

				if (active)
					MUI_Request(app,window,0,NULL,"OK","Cannot quit now, still\nsome asl popups opened.");
				else
					running = FALSE;
			}
			break;
		}

		if (running && signals) Wait(signals);
	}

	set(window,MUIA_Window_Open,FALSE);

/*
** Shut down...
*/

	fail(app,NULL);
	return 0;
}
