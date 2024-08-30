#include "demo.h"


static const char text1[] = "\
\33iHello User !\33n\n\
\n\
This could be a very long text and you are looking\n\
at it through a \33uvirtual group\33n. Please use the\n\
scrollbars at the right and bottom of the group to\n\
move the visible area either vertically or\n\
horizontally. While holding down the small arrow\n\
button between both scrollbars, the display will\n\
follow your mouse moves.\n\
\n\
If you click somewhere into a \33uvirtual group\33n and\n\
move the mouse across one of its borders, the group will\n\
start scrolling. If you are lucky and own a middle mouse\n\
button, you may also want to press it and try moving.\n\
\n\
When the surrounding window is big enough for the\n\
complete virtual group to fit, the scrollers and\n\
the move button get disabled.\n\
\n\
Since this \33uvirtual group\33n does only contain a\n\
single text object, it's a rather simple example.\n\
In fact, virtual groups are a lot more powerful,\n\
they can contain any objects you like.\n\
\n\
Note to 7MHz/68000 users: Sorry if you find this\n\
thingy a bit slow. Clipping in virtual groups can\n\
get quite complicated. Please don't blame me,\n\
blame your 'out of date' machine! :-)\n\
\n\
\33i\33cHave fun, Stefan.\33n\
";


APTR MakePage1(VOID)
{
	return
	(
	ScrollgroupObject,
		MUIA_Scrollgroup_UseWinBorder, TRUE,
		MUIA_Scrollgroup_Contents, VirtgroupObject,
			VirtualFrame,
			Child, TextObject,
				MUIA_Background, MUII_TextBack,
				MUIA_Text_Contents, text1,
				End,
			End,
		End
	);
}


static const char text2[] = "\33c\
As you can see, this virtual group contains a\n\
lot of different objects. The (virtual) width\n\
and height of the virtual group are automatically\n\
calculated from the default width and height of\n\
the virtual groups contents.\
";


APTR MakePage2(VOID)
{
	#define img(nr)  ImageObject, MUIA_Image_Spec, nr, End

	APTR obj = ScrollgroupObject,
		MUIA_UserData, 42,
		MUIA_Scrollgroup_Contents, VGroupV, VirtualFrame,
			MUIA_UserData, 42,
			Child, TextObject,
				TextFrame,
				MUIA_Background, MUII_TextBack,
				MUIA_Text_Contents, text2,
				End,
			Child, HGroup,
				Child, ColGroup(2), GroupFrameT("Standard Images"),
					Child, Label("ArrowUp:"    ), Child, img(MUII_ArrowUp    ),
					Child, Label("ArrowDown:"  ), Child, img(MUII_ArrowDown  ),
					Child, Label("ArrowLeft:"  ), Child, img(MUII_ArrowLeft  ),
					Child, Label("ArrowRight:" ), Child, img(MUII_ArrowRight ),
					Child, Label("RadioButton:"), Child, img(MUII_RadioButton),
					Child, Label("File:"       ), Child, img(MUII_PopFile    ),
					Child, Label("HardDisk:"   ), Child, img(MUII_HardDisk   ),
					Child, Label("Disk:"       ), Child, img(MUII_Disk       ),
					Child, Label("Chip:"       ), Child, img(MUII_Chip       ),
					Child, Label("Drawer:"     ), Child, img(MUII_Drawer     ),
					End,
				Child, VGroup, GroupFrameT("Some Backgrounds"),
					Child, HGroup,
						Child, RectangleObject, TextFrame, MUIA_Background, MUII_BACKGROUND , MUIA_FixWidth, 30, End,
	      	   			Child, RectangleObject, TextFrame, MUIA_Background, MUII_FILL       , MUIA_FixWidth, 30, End,
	         			Child, RectangleObject, TextFrame, MUIA_Background, MUII_SHADOW     , MUIA_FixWidth, 30, End,
						End,
					Child, HGroup,
		         		Child, RectangleObject, TextFrame, MUIA_Background, MUII_SHADOWBACK , MUIA_FixWidth, 30, End,
	   	      			Child, RectangleObject, TextFrame, MUIA_Background, MUII_SHADOWFILL , MUIA_FixWidth, 30, End,
	      	   			Child, RectangleObject, TextFrame, MUIA_Background, MUII_SHADOWSHINE, MUIA_FixWidth, 30, End,
						End,
					Child, HGroup,
		         		Child, RectangleObject, TextFrame, MUIA_Background, MUII_FILLBACK   , MUIA_FixWidth, 30, End,
	   	      			Child, RectangleObject, TextFrame, MUIA_Background, MUII_SHINEBACK  , MUIA_FixWidth, 30, End,
	      	   			Child, RectangleObject, TextFrame, MUIA_Background, MUII_FILLSHINE  , MUIA_FixWidth, 30, End,
						End,
					End,
				End,
			Child, ColGroup(2), GroupFrame,
				Child, Label1("Gauge:"), Child, GaugeObject, GaugeFrame, MUIA_Gauge_Current, 66, MUIA_Gauge_Horiz, TRUE, End,
				Child, VSpace(0)       , Child, ScaleObject, End,
				End,
			End,
		End;

	return(obj);
}


static const char text3[] = "\
\33cThe above pages only showed 'read only' groups,\n\
no user actions within them were possible. Of course,\n\
handling user actions in a virtual group is not a\n\
problem for MUI. As I promised on the first page,\n\
you can use virtual groups with whatever objects\n\
you want. Here's a small example...\n\
\n\
Note: Due to some limitations of the operating system,\n\
it is not possible to clip gadgets depending on\n\
intuition.library correctly. This affects the appearence\n\
of string and proportional objects in virtual groups.\n\
You will only be able to use these gadgets when they\n\
are completely visible.\n\
\n\
PS: Also try TAB cycling here!\
";

static const char *CYA_Computer[] = { "Amiga 500","Amiga 600","Amiga 1000 :)","Amiga 1200","Amiga 2000","Amiga 3000","Amiga 4000", "Amiga 4000T", "Atari ST :(", NULL };
static const char *CYA_Printer[]  = { "HP Deskjet","NEC P6","Okimate 20",NULL };
static const char *CYA_Display[]  = { "A1081","NEC 3D","A2024","Eizo T660i",NULL };

static APTR CY_Computer,CY_Printer,CY_Display;
static APTR MT_Computer,MT_Printer,MT_Display;
static APTR LV_Computer;
static APTR BT_Button[12];

APTR MakePage3(VOID)
{
	APTR obj;

	obj = ScrollgroupObject,
		MUIA_Scrollgroup_Contents, VGroupV, VirtualFrame,
			Child, TextObject,
				TextFrame,
				MUIA_Background, MUII_TextBack,
				MUIA_Text_Contents, text3,
				End,
			Child, VGroup,
				Child, HGroup,
					Child, MT_Computer = Radio("Computer:",CYA_Computer),
					Child, VGroup,
						Child, MT_Printer = Radio("Printer:",CYA_Printer),
						Child, VSpace(0),
						Child, MT_Display = Radio("Display:",CYA_Display),
						End,
					Child, VGroup,
						Child, ColGroup(2), GroupFrameT("Cycle Gadgets"),
							Child, KeyLabel1("Computer:",'c'), Child, CY_Computer = KeyCycle(CYA_Computer,'c'),
							Child, KeyLabel1("Printer:" ,'p'), Child, CY_Printer  = KeyCycle(CYA_Printer ,'p'),
							Child, KeyLabel1("Display:" ,'d'), Child, CY_Display  = KeyCycle(CYA_Display ,'d'),
							End,
						Child, LV_Computer = ListObject, InputListFrame, MUIA_List_ScrollerPos, MUIV_List_ScrollerPos_Left, MUIA_List_Input, TRUE, End,
						End,
					End,
				Child, ColGroup(4), GroupFrameT("Button Field"),
					Child, BT_Button[ 0] = SimpleButton("Button"),
					Child, BT_Button[ 1] = SimpleButton("Button"),
					Child, BT_Button[ 2] = SimpleButton("Button"),
					Child, BT_Button[ 3] = SimpleButton("Button"),
					Child, BT_Button[ 4] = SimpleButton("Button"),
					Child, BT_Button[ 5] = SimpleButton("Button"),
					Child, BT_Button[ 6] = SimpleButton("Button"),
					Child, BT_Button[ 7] = SimpleButton("Button"),
					Child, BT_Button[ 8] = SimpleButton("Button"),
					Child, BT_Button[ 9] = SimpleButton("Button"),
					Child, BT_Button[10] = SimpleButton("Button"),
					Child, BT_Button[11] = SimpleButton("Button"),
					End,
				End,
			End,
		End;

	if (LV_Computer)
		DoMethod(LV_Computer,MUIM_List_Insert,CYA_Computer,-1,MUIV_List_Insert_Bottom);

	return(obj);
}


#define mytxt(txt)\
	TextObject,\
		MUIA_Text_Contents, "\33c"txt,\
		MUIA_Text_SetMax, TRUE,\
		End

#define ibt(i)\
	ImageObject,\
		ImageButtonFrame,\
		MUIA_Background, MUII_ButtonBack,\
		MUIA_InputMode , MUIV_InputMode_RelVerify,\
		MUIA_Image_Spec, i,\
		End

static const char *x4Pages[]   = { "Race","Class","Armors","Weapons","Levels",NULL };
static const char *x4Races[]   = { "Human","Elf","Dwarf","Hobbit","Gnome",NULL };
static const char *x4Classes[] = { "Warrior","Rogue","Bard","Monk","Magician","Archmage",NULL };
static const char *x4Weapons[] = { "Staff","Dagger","Sword","Axe","Grenade",NULL };

APTR MakePage4(VOID)
{
	APTR bt1,bt2,bt3,bt4,gr,obj,pcy,pgr;

	obj = ScrollgroupObject,
		MUIA_Scrollgroup_Contents, ColGroupV(3), VirtualFrame,
			MUIA_Group_Spacing, 10,
			Child, VGroup, GroupFrame,
				Child, HGroup,
					Child, HSpace(0),
					Child, bt1 = ibt(MUII_ArrowUp),
					Child, HSpace(0),
					End,
				Child, HGroup,
					Child, bt2 = ibt(MUII_ArrowLeft),
					Child, bt3 = ibt(MUII_ArrowRight),
					End,
				Child, HGroup,
					Child, HSpace(0),
					Child, bt4 = ibt(MUII_ArrowDown),
					Child, HSpace(0),
					End,
				End,
			Child, mytxt("Ever wanted to see\na virtual group in\na virtual group?"),
			Child, HVSpace,
			Child, mytxt("Here it is!"),

			Child, ScrollgroupObject,
				MUIA_Scrollgroup_Contents, gr = VGroupV, VirtualFrame,
					Child, ColGroup(6), MUIA_Group_SameSize, TRUE,
						Child, SimpleButton("One"),
						Child, SimpleButton("Two"),
						Child, SimpleButton("Three"),
						Child, SimpleButton("Four"),
						Child, SimpleButton("Five"),
						Child, SimpleButton("Six"),
						Child, SimpleButton("Eighteen"),
						Child, mytxt("The"),
						Child, mytxt("red"),
						Child, mytxt("brown"),
						Child, mytxt("fox"),
						Child, SimpleButton("Seven"),
						Child, SimpleButton("Seventeen"),
						Child, mytxt("dog."),
						Child, SimpleButton("Nineteen"),
						Child, SimpleButton("Twenty"),
						Child, mytxt("jumps"),
						Child, SimpleButton("Eight"),
						Child, SimpleButton("Sixteen"),
						Child, mytxt("lazy"),
						Child, mytxt("the"),
						Child, mytxt("over"),
						Child, mytxt("quickly"),
						Child, SimpleButton("Nine"),
						Child, SimpleButton("Fifteen"),
						Child, SimpleButton("Fourteen"),
						Child, SimpleButton("Thirteen"),
						Child, SimpleButton("Twelve"),
						Child, SimpleButton("Eleven"),
						Child, SimpleButton("Ten"),
						End,
					End,
				End,

			Child, mytxt("Do you like it? I hope..."),
			Child, HVSpace,
			Child, mytxt("I admit, it's a\n bit crazy... :-)\nBut it demonstrates\nthe power of\n\33bobject oriented\33n\nGUI design."),

			Child, ScrollgroupObject,
				MUIA_Scrollgroup_Contents, VGroupV, VirtualFrame, InnerSpacing(4,4),
					Child, VGroup,
						Child, pcy = Cycle(x4Pages),
						Child, pgr = PageGroup,
							Child, HCenter(Radio(NULL,x4Races)),
							Child, HCenter(Radio(NULL,x4Classes)),
							Child, HGroup,
								Child, HSpace(0),
								Child, ColGroup(2),
									Child, Label1("Cloak:" ), Child, CheckMark(TRUE),
									Child, Label1("Shield:"), Child, CheckMark(TRUE),
									Child, Label1("Gloves:"), Child, CheckMark(TRUE),
									Child, Label1("Helm:"  ), Child, CheckMark(TRUE),
									End,
								Child, HSpace(0),
								End,
							Child, HCenter(Radio(NULL,x4Weapons)),
							Child, ColGroup(2),
								Child, Label("Experience:"  ), Child, Slider(0,100, 3),
								Child, Label("Strength:"    ), Child, Slider(0,100,42),
								Child, Label("Dexterity:"   ), Child, Slider(0,100,24),
								Child, Label("Condition:"   ), Child, Slider(0,100,39),
								Child, Label("Intelligence:"), Child, Slider(0,100,74),
								End,
							End,
						End,
					End,
				End,


			End,
		End;

	if (obj)
	{
		DoMethod(bt1,MUIM_Notify,MUIA_Pressed,FALSE,gr,3,MUIM_Set,MUIA_Virtgroup_Top ,0);
		DoMethod(bt2,MUIM_Notify,MUIA_Pressed,FALSE,gr,3,MUIM_Set,MUIA_Virtgroup_Left,0);
		DoMethod(bt3,MUIM_Notify,MUIA_Pressed,FALSE,gr,3,MUIM_Set,MUIA_Virtgroup_Left,9999);
		DoMethod(bt4,MUIM_Notify,MUIA_Pressed,FALSE,gr,3,MUIM_Set,MUIA_Virtgroup_Top ,9999);

		DoMethod(pcy,MUIM_Notify,MUIA_Cycle_Active,MUIV_EveryTime,
			pgr,3,MUIM_Set,MUIA_Group_ActivePage,MUIV_TriggerValue);
	}

	return(obj);
}


int main(UNUSED int argc, UNUSED char *argv[])
{
	static APTR app,window;

	init();

	app = ApplicationObject,
		MUIA_Application_Title      , "VirtualDemo",
		MUIA_Application_Version    , "$VER: VirtualDemo 21.1 (08.02.2018)",
		MUIA_Application_Copyright  , "(C) 1992-2006 Stefan Stuntz, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Stefan Stuntz, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "Show virtual groups.",
		MUIA_Application_Base       , "VIRTUALDEMO",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Virtual Groups",
			MUIA_Window_ID   , MAKE_ID('V','I','R','T'),

/*
			WindowContents, VGroup, Child, MakePage2(), End,
*/

			MUIA_Window_UseRightBorderScroller, TRUE,
			MUIA_Window_UseBottomBorderScroller, TRUE,
			WindowContents, ColGroup(2), GroupSpacing(8),
				Child, MakePage1(),
				Child, MakePage2(),
				Child, MakePage3(),
				Child, MakePage4(),
				End,

			End,
		End;


	if (!app)
		fail(app,"Failed to create Application.");


	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
		app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

	DoMethod(window,MUIM_Window_SetCycleChain,
		MT_Computer,MT_Printer,MT_Display,
		CY_Computer,CY_Printer,CY_Display,
		LV_Computer,
		BT_Button[ 0],BT_Button[ 1],BT_Button[ 2],BT_Button[ 3],
		BT_Button[ 4],BT_Button[ 5],BT_Button[ 6],BT_Button[ 7],
		BT_Button[ 8],BT_Button[ 9],BT_Button[10],BT_Button[11],
		NULL);

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

	fail(app,NULL);

	// just to please the compiler
	return 0;
}
