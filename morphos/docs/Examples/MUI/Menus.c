/*
** $Id: Menus.c,v 1.15 2009/02/20 21:22:52 stuntzi Exp $
*/

/*
** This demo shows the use of MUI's menus classes.
*/

#include "demo.h"

/*
** MUI still supports the use of a conventional gadtools NewMenu structure
** to define a menu strip. The address of this structure is passed to a
** MUI_MakeObject(MUIO_MenustripNM,newmenu,0) function which creates a complete
** object tree for this menu and returns a pointer to the menustrip object,
** This pointer should be placed in a windows MUIA_Window_Menustrip attribute
** or in an applications MUIA_Application_Menustrip attribute, in which case
** all windows will inherit the menu. To get direct access to the menu item
** objects of such an auto generated tree, you can use the MUIM_FindUserData
** method.
**
** You can of course create the menu object tree yourself by defining
** a menu strip object with some menu object children with some menu
** item object children with optionally some more menu item object
** children. In this case, use the MUI_MakeObject(MUIO_Menuitem,...)
** call to create the menu items if possible.
**
** The main program shows some different methods how to create items and
** how to react on menu items. Choose the one you like best, and don't
** forget to use sub classes or MUIM_CallHook if you dislike switch/case
** in the main loop!
*/

#define RB CHECKIT
#define TG CHECKIT|MENUTOGGLE

enum { MEN_PROJECT=1,MEN_ABOUT,MEN_QUIT,MEN_EDIT,MEN_CUT,MEN_COPY,MEN_PASTE,MEN_SETTINGS,MEN_HARDWARE,MEN_A1000,MEN_A2000,MEN_A3000,MEN_A4000,MEN_SOFTWARE,MEN_MUI,MEN_MFR,MEN_MWB,MEN_DFA,ID_ADD,ID_REM,ID_RADIO,ID_TOG,ID_POP };

static struct NewMenu MenuData1[] =
{
	{ NM_TITLE, "Project"                  ,"P",0 ,0             ,(APTR)MEN_PROJECT  },
	{ NM_ITEM ,  "About"                   ,"?",0 ,0             ,(APTR)MEN_ABOUT    },
	{ NM_ITEM ,  NM_BARLABEL               , 0 ,0 ,0             ,(APTR)0            },
	{ NM_ITEM ,  "Quit"                    ,"Q",0 ,0             ,(APTR)MEN_QUIT     },

	{ NM_TITLE, "E\0Edit"                  , 0 ,0 ,0             ,(APTR)MEN_EDIT     },
	{ NM_ITEM ,  "Cut"                     ,"X",0 ,0             ,(APTR)MEN_CUT      },
	{ NM_ITEM ,  "Copy"                    ,"C",0 ,0             ,(APTR)MEN_COPY     },
	{ NM_ITEM ,  "Paste"                   ,"V",0 ,0             ,(APTR)MEN_PASTE    },

	{ NM_TITLE, "S\0Settings"              , 0 ,NM_MENUDISABLED,0,(APTR)MEN_SETTINGS },
	{ NM_ITEM ,  "H\0Hardware"             , 0 ,NM_ITEMDISABLED,0,(APTR)MEN_HARDWARE },
	{ NM_SUB  ,   "A1000"                  ,"1",RB|CHECKED,2|4|8 ,(APTR)MEN_A1000    },
	{ NM_SUB  ,   "A2000"                  ,"2",RB,1|4|8         ,(APTR)MEN_A2000    },
	{ NM_SUB  ,   "A3000"                  ,"3",RB,1|2|8         ,(APTR)MEN_A3000    },
	{ NM_SUB  ,   "A4000"                  ,"4",RB,1|2|4         ,(APTR)MEN_A4000    },
	{ NM_ITEM ,  "S\0Software"             , 0 ,NM_ITEMDISABLED,0,(APTR)MEN_SOFTWARE },
	{ NM_SUB  ,   "MUI"                    ,"M",TG,0             ,(APTR)MEN_MUI      },
	{ NM_SUB  ,   "MFR"                    ,"F",TG,0             ,(APTR)MEN_MFR      },
	{ NM_SUB  ,   "MagicWB"                ,"W",TG,0             ,(APTR)MEN_MWB      },
	{ NM_SUB  ,   "DFA"                    ,"D",TG,0             ,(APTR)MEN_DFA      },

	{ NM_END,NULL,0,0,0,(APTR)0 },
};


int main(int argc,char *argv[])
{
	APTR app,win1,cm1,cm2,cm3,cm4,radio,cy1,cy2,cy3,menuset,menuedit,itemhw,itemsw,strip,menumisc,btadd,btrem,bttog,possi,nomen,btpop;
	#ifdef MYDEBUG
	APTR mdis;
	APTR mdis2;
	APTR mdis3;
	APTR mdis4;
	#endif
	ULONG signals,x;
	BOOL running = TRUE;
	BOOL addedmisc = FALSE;
	static char *hardware[] = { "Amiga 1000", "Amiga 2000", "Amiga 3000", "Amiga 4000", NULL };
	static char *endis1[]   = { "Settings disabled", "Settings enabled", NULL };
	static char *endis2[]   = { "Hardware disabled", "Hardware enabled",  NULL };
	static char *endis3[]   = { "Software disabled", "Software enabled",  NULL };

	init();

	app = ApplicationObject,
		MUIA_Application_Title      , "Menus",
		MUIA_Application_Version    , "$VER: Menus 20.229 (13.05.03)",
		MUIA_Application_Copyright  , "© 2000 Stefan Stuntz",
		MUIA_Application_Author     , "Stefan Stuntz",
		MUIA_Application_Description, "Demonstrate MUI's menu classes.",
		MUIA_Application_Base       , "MENU",
		MUIA_Application_Window, win1 = WindowObject,
			MUIA_Window_Title, "Menus",
			MUIA_Window_ID   , MAKE_ID('M','E','N','1'),
			MUIA_Window_Menustrip, strip = MUI_MakeObject(MUIO_MenustripNM,MenuData1,MUIO_MenustripNM_CommandKeyCheck),
			WindowContents, VGroup,
				Child, cy1 = MUI_MakeObject(MUIO_Cycle,NULL,endis1),
				Child, HGroup, MUIA_Group_SameSize, TRUE,
					Child, cy2 = MUI_MakeObject(MUIO_Cycle,NULL,endis2),
					Child, cy3 = MUI_MakeObject(MUIO_Cycle,NULL,endis3),
					End,
				Child, MUI_MakeObject(MUIO_HBar,4),
				Child, HGroup,
					Child, HSpace(0),
					Child, VGroup,
						Child, radio = MUI_MakeObject(MUIO_Radio,NULL,hardware),
						Child, HGroup, Child, Label("No Menus"), Child, nomen = MUI_MakeObject(MUIO_Checkmark,NULL), End,
						End,
					Child, HSpace(0),
					Child, MUI_MakeObject(MUIO_VBar,1),
					Child, HSpace(0),
					Child, ColGroup(2),
						Child, Label("_MUI"    ), Child, cm1 = MUI_MakeObject(MUIO_Checkmark,"_MUI"    ),
						Child, Label("M_FR"    ), Child, cm2 = MUI_MakeObject(MUIO_Checkmark,"M_FR"    ),
						Child, Label("Magic_WB"), Child, cm3 = MUI_MakeObject(MUIO_Checkmark,"Magic_WB"),
						Child, Label("_DFA"    ), Child, cm4 = MUI_MakeObject(MUIO_Checkmark,"_DFA"    ),
						End,
					Child, HSpace(0),
					End,
				Child, MUI_MakeObject(MUIO_HBar,4),
				Child, HGroup, MUIA_Group_SameSize, TRUE,
					Child, btadd = MUI_MakeObject(MUIO_Button,"_Add Misc Menu"),
					Child, btrem = MUI_MakeObject(MUIO_Button,"_Remove Misc Menu"),
					Child, bttog = MUI_MakeObject(MUIO_Button,"_Toggle Misc Titles"),
					Child, btpop = MUI_MakeObject(MUIO_Button,"_Custom Popup"),
					End,
				#ifdef MYDEBUG
				Child, mdis  = MUI_NewObject(MUIC_Menudisplay,MUIA_Frame,MUIV_Frame_ImageButton,MUIA_Background,MUII_ListBack,TAG_DONE),
				Child, mdis2 = MUI_NewObject(MUIC_Menudisplay,MUIA_Frame,MUIV_Frame_ImageButton,MUIA_Background,MUII_ListBack,TAG_DONE),
				Child, mdis3 = MUI_NewObject(MUIC_Menudisplay,MUIA_Frame,MUIV_Frame_ImageButton,MUIA_Background,MUII_ListBack,TAG_DONE),
				Child, mdis4 = MUI_NewObject(MUIC_Menudisplay,MUIA_Frame,MUIV_Frame_ImageButton,MUIA_Background,MUII_ListBack,TAG_DONE),
				#endif
				End,
			End,
		End;

	menumisc = MenuObject, MUIA_Menu_Title, "Misc",
		MUIA_Family_Child, MUI_MakeObject(MUIO_Menuitem,"Dynamic" ,0,0,0),
		MUIA_Family_Child, MUI_MakeObject(MUIO_Menuitem,"Adding"  ,0,0,0),
		MUIA_Family_Child, MUI_MakeObject(MUIO_Menuitem,"Of"      ,0,0,0),
		MUIA_Family_Child, MUI_MakeObject(MUIO_Menuitem,"Items"   ,0,0,0),
		MUIA_Family_Child, MUI_MakeObject(MUIO_Menuitem,"Is"      ,0,0,0),
		MUIA_Family_Child, possi = MUI_MakeObject(MUIO_Menuitem,"Possible",0,CHECKIT|CHECKED|MENUTOGGLE,0),
		End;

	if (!app || !menumisc)
	{
		MUI_DisposeObject(menumisc);
		fail(app,"Failed to create Application.");
	}

	#ifdef MYDEBUG
	DoMethod(mdis,MUIM_Menudisplay_SetMenu,strip);
	DoMethod(mdis2,MUIM_Menudisplay_SetMenu,strip);
	DoMethod(mdis3,MUIM_Menudisplay_SetMenu,strip);
	DoMethod(mdis4,MUIM_Menudisplay_SetMenu,strip);
	#endif

	menuset  = (APTR)DoMethod(strip,MUIM_FindUData,MEN_SETTINGS);
	menuedit = (APTR)DoMethod(strip,MUIM_FindUData,MEN_EDIT);
	itemhw   = (APTR)DoMethod(strip,MUIM_FindUData,MEN_HARDWARE);
	itemsw   = (APTR)DoMethod(strip,MUIM_FindUData,MEN_SOFTWARE);

	DoMethod(cy1,MUIM_Notify,MUIA_Cycle_Active,MUIV_EveryTime,menuset,3,MUIM_Set,MUIA_Menu_Enabled    ,MUIV_TriggerValue);
	DoMethod(cy2,MUIM_Notify,MUIA_Cycle_Active,MUIV_EveryTime,itemhw ,3,MUIM_Set,MUIA_Menuitem_Enabled,MUIV_TriggerValue);
	DoMethod(cy3,MUIM_Notify,MUIA_Cycle_Active,MUIV_EveryTime,itemsw ,3,MUIM_Set,MUIA_Menuitem_Enabled,MUIV_TriggerValue);

	DoMethod(btadd,MUIM_Notify,MUIA_Pressed,FALSE,app,2,MUIM_Application_ReturnID,ID_ADD);
	DoMethod(btrem,MUIM_Notify,MUIA_Pressed,FALSE,app,2,MUIM_Application_ReturnID,ID_REM);
	DoMethod(bttog,MUIM_Notify,MUIA_Pressed,FALSE,app,2,MUIM_Application_ReturnID,ID_TOG);
	DoMethod(btpop,MUIM_Notify,MUIA_Pressed,FALSE,app,2,MUIM_Application_ReturnID,ID_POP);

//	DoMethod(app,MUIM_Notify,MUIA_Application_MenuAction,MEN_A1000,radio,3,MUIM_Set,MUIA_Radio_Active,0);
	DoMethod(app,MUIM_Notify,MUIA_Application_MenuAction,MEN_A1000,MUIV_Notify_Application,6,MUIM_Application_PushMethod,radio,3,MUIM_Set,MUIA_Radio_Active,0); // special laire-o-test-case, same as above

	DoMethod(app,MUIM_Notify,MUIA_Application_MenuAction,MEN_A2000,radio,3,MUIM_Set,MUIA_Radio_Active,1);
	DoMethod(app,MUIM_Notify,MUIA_Application_MenuAction,MEN_A3000,radio,3,MUIM_Set,MUIA_Radio_Active,2);
	DoMethod(app,MUIM_Notify,MUIA_Application_MenuAction,MEN_A4000,radio,3,MUIM_Set,MUIA_Radio_Active,3);

	DoMethod(cm1,MUIM_Notify,MUIA_Selected,MUIV_EveryTime,strip,4,MUIM_SetUData,MEN_MUI,MUIA_Menuitem_Checked,MUIV_TriggerValue);
	DoMethod(cm2,MUIM_Notify,MUIA_Selected,MUIV_EveryTime,strip,4,MUIM_SetUData,MEN_MFR,MUIA_Menuitem_Checked,MUIV_TriggerValue);
	DoMethod(cm3,MUIM_Notify,MUIA_Selected,MUIV_EveryTime,strip,4,MUIM_SetUData,MEN_MWB,MUIA_Menuitem_Checked,MUIV_TriggerValue);
	DoMethod(cm4,MUIM_Notify,MUIA_Selected,MUIV_EveryTime,strip,4,MUIM_SetUData,MEN_DFA,MUIA_Menuitem_Checked,MUIV_TriggerValue);

	DoMethod(nomen,MUIM_Notify,MUIA_Selected,MUIV_EveryTime,win1,3,MUIM_Set,MUIA_Window_NoMenus,MUIV_TriggerValue);

	DoMethod(radio,MUIM_Notify,MUIA_Radio_Active,MUIV_EveryTime,app,2,MUIM_Application_ReturnID,ID_RADIO);

	DoMethod(win1,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

	set(btrem,MUIA_Disabled,TRUE);

	set(cm1,MUIA_UserData,MEN_MUI);
	set(cm2,MUIA_UserData,MEN_MFR);
	set(cm3,MUIA_UserData,MEN_MWB);
	set(cm4,MUIA_UserData,MEN_DFA);

	set(cm1,MUIA_CycleChain,TRUE);
	set(cm2,MUIA_CycleChain,TRUE);
	set(cm3,MUIA_CycleChain,TRUE);
	set(cm4,MUIA_CycleChain,TRUE);

	#ifdef MYDEBUG
	set(mdis ,MUIA_CycleChain,TRUE);
	set(mdis2,MUIA_CycleChain,TRUE);
	set(mdis3,MUIA_CycleChain,TRUE);
	set(mdis4,MUIA_CycleChain,TRUE);
	#endif

/*
** Input loop...
*/

	set(win1,MUIA_Window_Open,TRUE);

	while (running)
	{
		ULONG id = DoMethod(app,MUIM_Application_Input,&signals);

		switch (id)
		{
			case MEN_QUIT:
			case MUIV_Application_ReturnID_Quit:
				running = FALSE;
				break;

			case MEN_ABOUT:
				MUI_Request(app,win1,0,NULL,"OK","Some little about window.");
				break;

			case ID_ADD:
				set(btadd,MUIA_Disabled,TRUE);
				set(btrem,MUIA_Disabled,FALSE);
				DoMethod(strip,MUIM_Family_Insert,menumisc,menuedit);
				addedmisc = TRUE;
				break;

			case ID_REM:
				set(btadd,MUIA_Disabled,FALSE);
				set(btrem,MUIA_Disabled,TRUE);
				DoMethod(strip,MUIM_Family_Remove,menumisc);
				addedmisc = FALSE;
				break;

			case ID_TOG:
			{
				char *x;

				#ifdef MYDEBUG
				#ifndef clock
				int clock(void);
				#endif
				int t=clock();
				int i;
				DoMethod(menumisc,MUIM_Menustrip_InitChange);
				for (i=0;i<21;i++)
				{
				#endif

				get(menumisc,MUIA_Menu_Title,&x);
				if (strcmp(x,"Misc"))
					set(menumisc,MUIA_Menu_Title,"Misc");
				else
					set(menumisc,MUIA_Menu_Title,"Miscodil");

				get(possi,MUIA_Menuitem_Title,&x);
				if (strcmp(x,"Possible"))
					set(possi,MUIA_Menuitem_Title,"Possible");
				else
					set(possi,MUIA_Menuitem_Title,"elbissoP");

				#ifdef MYDEBUG
				}
				DoMethod(menumisc,MUIM_Menustrip_ExitChange);
				t=clock()-t;
				printf("took %ld ticks\n",t);
				#endif

				break;
			}

			case MEN_MUI:
			case MEN_MFR:
			case MEN_MWB:
			case MEN_DFA:
				DoMethod(strip,MUIM_GetUData,id,MUIA_Menuitem_Checked,&x);
				DoMethod(win1,MUIM_SetUData,id,MUIA_Selected,x);
				break;

			case ID_RADIO:
				get(radio,MUIA_Radio_Active,&x);
				DoMethod(itemhw,MUIM_SetUData,MEN_A1000,MUIA_Menuitem_Checked,x==0);
				DoMethod(itemhw,MUIM_SetUData,MEN_A2000,MUIA_Menuitem_Checked,x==1);
				DoMethod(itemhw,MUIM_SetUData,MEN_A3000,MUIA_Menuitem_Checked,x==2);
				DoMethod(itemhw,MUIM_SetUData,MEN_A4000,MUIA_Menuitem_Checked,x==3);
				break;

			case ID_POP:
			{
				Object *strip;

				if ((strip = MenustripObject,
					Child, MenuObject, 
						Child, MenuitemObject, MUIA_UserData, 1, MUIA_Menuitem_Title, "Custom popup menu", End,
						Child, MenuitemObject, MUIA_UserData, 2, MUIA_Menuitem_Title, "Use anytime & anywhere", End,
						Child, MenuitemObject, MUIA_UserData, 3, MUIA_Menuitem_Title, "Enjoy!", End,
						End,
					End))
				{
					ULONG poprc = DoMethod(strip,MUIM_Menustrip_Popup,btpop,0,_left(btpop),_bottom(btpop)+1);
					printf("popup result: %ld\n",poprc);
					MUI_DisposeObject(strip);
				}
			}
			break;
		}
		if (running && signals) Wait(signals);
	}

	set(win1,MUIA_Window_Open,FALSE);

/*
** Shut down...
*/

	if (!addedmisc)
		MUI_DisposeObject(menumisc);

	fail(app,NULL);
	return(0);
}
