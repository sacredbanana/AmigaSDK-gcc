/*
 * Simple test application for libauto.a
 * Written 2004 Hans-Joerg Frieden.
 * Modified in 2010 for the SDK.
 * This program is public domain.
 *
 */

#include <exec/exec.h>
#include <intuition/intuition.h>
#include <intuition/icclass.h>
#include <dos/dos.h>

#include <classes/window.h>
#include <classes/requester.h>

#include <gadgets/fuelgauge.h>
#include <gadgets/layout.h>
#include <gadgets/texteditor.h>
#include <gadgets/radiobutton.h>
#include <gadgets/chooser.h>
#include <gadgets/integer.h>
#include <gadgets/clicktab.h>

/*
 * Autoinit takes care of these
 */
#include <proto/exec.h>
#include <proto/intuition.h>

/*
 * Simply include the proto file for all ReAction classes you intent to use
 * to trigger their autoinitialization.
 */
#include <proto/fuelgauge.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/texteditor.h>
#include <proto/radiobutton.h>
#include <proto/chooser.h>
#include <proto/checkbox.h>
#include <proto/integer.h>
#include <proto/space.h>
#include <proto/clicktab.h>
#include <proto/requester.h>

#include <reaction/reaction_macros.h>

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

Object *win;

/*
 * These are label arrays that are used throughout the sample
 */
STRPTR QualityLabels[] =
{
	"Draft", "Text", "Photo", NULL
};

STRPTR PrintModeLabels[] =
{
	"Black and White",
	"Greyscale",
	"Full Color",
	NULL
};

STRPTR PaperTypeLabels[] =
{
	"Normal/Bright White paper",
	"Matte/Heavy Weight",
	"Photo Paper",
	"Coated/Inkjet",
	"Transparent Slides",
	NULL
};

STRPTR PaperSizeLabels[] =
{
	"A4", "B5", "A5", "Letter", "Legal", "Postcard", NULL
};

STRPTR PageLabels[] =
{
	"Print Settings",
	"Layout Options",
	NULL
};

/*
 * This enum generates the unique ID's we need both for
 * GadgetID's as well as for the index into our objects
 * array. You might want to use separate variables (we
 * did so for the window object) or use this method.
 * Note that not all objects need an id, and not all
 * objects need to be stored (Layout groups for example).
 * Essentially only store object pointers that you need
 * to manipulate from your program.
 */
enum
{
	/* -- page 1 controls -- */
	OBJ_QUALITY_SETTINGS,
	OBJ_PRINT_MODE,
	OBJ_PAPER_TYPE,
	OBJ_PAPER_SIZE,
	OBJ_PRINT_PREVIEW,
	OBJ_PRINT_ENHANCE,

	/* -- page 2 controls -- */
	OBJ_ROTATE_180,
	OBJ_MIRROR,
	OBJ_NUP_ENABLE,
	OBJ_PAGES_PER_SHEET,
	OBJ_NUM_COPIES,
	OBJ_COLLATE,
	OBJ_SORT,

	/* -- other controls -- */
	OBJ_CLICKTAB,
	OBJ_PRINT,
	OBJ_CANCEL,
	OBJ_HELP,

	OBJ_NUM
};

/*
 * This array will hold the objects we create. The two macros
 * below are for convenience.
 */
Object *Objects[OBJ_NUM];
#define OBJ(x) Objects[x]
#define GAD(x) (struct Gadget *)Objects[x]

/* Quite handy */
#define SPACE LAYOUT_AddChild, SpaceObject, End

Object *
make_window(void)
{
	/* For this forged "printer" dialog we want two pages:
	 * Page 1: Main settings
	 *   Quality settings (draft, text, photo)
	 *   Paper type and format
	 *   Print options
	 *
	 * Page 2: Layout
	 *   Rotate 180 degrees checkbox
	 *   "Mirror" checkbox
	 *   # of copies
	 *   "Multipage" settings
	 */

	Object
		*page1 = NULL,
		*page2 = NULL;

	page1 = VLayoutObject,
		LAYOUT_AddChild, HLayoutObject,
			/* BevelStyle sets the style of the group border to BVS_GROUP,
			 * which is the standard group frame. The Label tags gives a
			 * text string to be displayed embedded into the frame.
			 */
			LAYOUT_BevelStyle,  BVS_GROUP,
			LAYOUT_Label,       "Print Quality",
			/* LAYOUT_AddChild adds a new child into the group. Depending
			 * on the layout parameter (horizontal vs. vertical) the
			 * objects are placed next to each other, or stacked one
			 * above the other.
			 */
			LAYOUT_AddChild,    OBJ(OBJ_QUALITY_SETTINGS) = RadioButtonObject,
				GA_Text,        QualityLabels,
				GA_ID,          OBJ_QUALITY_SETTINGS,
			End, /* RadioButton */
			LAYOUT_AddChild,    OBJ(OBJ_PRINT_MODE) = RadioButtonObject,
				GA_Text,        PrintModeLabels,
				GA_ID,          OBJ_PRINT_MODE,
			End, /* RadioButton */
			/*
			 * This adds expandable space to the group. If we don't do that,
			 * both objects created above will "stick" to the group frame
			 * and space will expand between them. Using this trick, we
			 * will have both of them together in the top left corner of the
			 * group.
			 */
			SPACE,
		End, /* HLayoutObject */
		LAYOUT_AddChild, HLayoutObject,
			LAYOUT_AddChild,    VLayoutObject,
				LAYOUT_BevelStyle,      BVS_GROUP,
				LAYOUT_Label,           "Paper Options",
				/*
				 * A chooser is called "Cycle Gadget" in GadTools lingo,
				 * although the ReAction choose can do much more than the
				 * GadTools counterpart. Specifiying CHOOSER_LabelArray
				 * we can pass an array of STRPTR's instead of creating
				 * our own labels, making it very easy to use
				 */
				LAYOUT_AddChild,        OBJ(OBJ_PAPER_TYPE) = ChooserObject,
					CHOOSER_LabelArray, PaperTypeLabels,
					GA_ID,              OBJ_PAPER_TYPE,
					GA_RelVerify,       TRUE,
				End, /* ChooserObject */
				LAYOUT_AddChild,        OBJ(OBJ_PAPER_SIZE) = ChooserObject,
					CHOOSER_LabelArray, PaperSizeLabels,
					GA_ID,              OBJ_PAPER_SIZE,
					GA_RelVerify,       TRUE,
				End, /* ChooserObject */
				SPACE,
			End, /* VLayoutObject */
			LAYOUT_AddChild,    VLayoutObject,
				LAYOUT_BevelStyle,      BVS_GROUP,
				LAYOUT_Label,           "Print Options",
				LAYOUT_AddChild,        OBJ(OBJ_PRINT_PREVIEW) = CheckBoxObject,
					GA_Text,            "Print preview",
					GA_ID,              OBJ_PRINT_PREVIEW,
				End, /* CheckBoxObject */
				LAYOUT_AddChild,        OBJ(OBJ_PRINT_ENHANCE) = CheckBoxObject,
					GA_Text,            "Print Enhance(tm)",
					GA_ID,              OBJ_PRINT_ENHANCE,
				End, /* CheckBoxObject */
				SPACE,
			End, /* VLayoutObject */
		End, /* HLayoutObject */
	End; /* VLayoutObject */

	page2 = VLayoutObject,
		LAYOUT_AddChild,    HLayoutObject,
			LAYOUT_BevelStyle,      BVS_GROUP,
			LAYOUT_Label,           "More Options",
			LAYOUT_AddChild,        OBJ(OBJ_ROTATE_180) = CheckBoxObject,
				GA_Text,            "Rotate by 180?",
				GA_ID,              OBJ_ROTATE_180,
			End, /* CheckBox */
			LAYOUT_AddChild,        OBJ(OBJ_MIRROR) = CheckBoxObject,
				GA_Text,            "Mirror",
				GA_ID,              OBJ_MIRROR,
			End, /* CheckBox */
			SPACE,
		End, /* HLayout */
		LAYOUT_AddChild,    HLayoutObject,
			LAYOUT_AddChild,        VLayoutObject,
				LAYOUT_BevelStyle,      BVS_GROUP,
				LAYOUT_Label,           "PSNUP Settings",
				LAYOUT_AddChild,        OBJ(OBJ_NUP_ENABLE) = CheckBoxObject,
					GA_Text,            "Enable Multi-Paging",
					GA_ID,              OBJ_NUP_ENABLE,
					GA_RelVerify,       TRUE,
				End, /* CheckBox */
				/*
				 * Note that this gadget is created with its GA_Disabled
				 * tag set to TRUE, meaning that it will appear "ghosted"
				 * in the UI. That is because the checkbox above should
				 * control whether the n-up feature (multiple pages per
				 * sheet) is used or not, and if it isn't used, then there
				 * is no need to have the user worry about this gadget that
				 * will not have an impact on the final printout anyway.
				 *
				 * Note that under normal circumstances you might want to
				 * limit the number of pages you can put on a single sheet
				 * to a power of two, i.e. 2,4, or 8. This is beyond the
				 * scope of this example, therefore we just offer two arrow
				 * buttons
				 */
				LAYOUT_AddChild,        OBJ(OBJ_PAGES_PER_SHEET) = IntegerObject,
					GA_Text,            "Pages per sheet",
					GA_ID,              OBJ_PAGES_PER_SHEET,
					INTEGER_Arrows,     TRUE,
					INTEGER_Number,     2,
					INTEGER_Minimum,    2,
					INTEGER_Maximum,    8,
					GA_Disabled,        TRUE,
				End, /* Integer */
				SPACE,
			End, /* VLayout */
			LAYOUT_AddChild,            VLayoutObject,
				LAYOUT_BevelStyle,      BVS_GROUP,
				LAYOUT_Label,           "Copies",
				LAYOUT_AddChild,        OBJ(OBJ_NUM_COPIES) = IntegerObject,
					GA_Text,            "# of copies",
					GA_ID,              OBJ_NUM_COPIES,
					INTEGER_Arrows,     TRUE,
					INTEGER_Number,     1,
					INTEGER_Minimum,    1,
					INTEGER_Maximum,    20,
				End, /* Integer */
				LAYOUT_AddChild,        OBJ(OBJ_COLLATE) = CheckBoxObject,
					GA_Text,            "Collate",
					GA_ID,              OBJ_COLLATE,
				End, /* CheckBox */
				LAYOUT_AddChild,        OBJ(OBJ_SORT) = CheckBoxObject,
					GA_Text,            "Sort Pages",
					GA_ID,              OBJ_SORT,
				End, /* CheckBox */
				SPACE,
			End, /* VLayout */
		End, /* HLayout */
	End; /* VLayout */

	/*
	 * A clicktab object is a controller for the page object. It's the
	 * register card type gadget along the top of the resultiong dialog.
	 * The GA_Text tag points to the STRPTR array with the labels to
	 * display (plain ascii text in this case), and the pagegroup is
	 * a special case of group that only displays one child at a time.
	 *
	 * This way we can select exactly one of the above pages as a time.
	 */
	OBJ(OBJ_CLICKTAB) = ClickTabObject,
		GA_Text,            PageLabels,
		CLICKTAB_Current,   0,
		CLICKTAB_PageGroup, PageObject,
			PAGE_Add,       page1,
			PAGE_Add,       page2,
		End, /* PageObject */
	End; /* ClickTab */

	/*
	 * This will generate our window object. The content of the window
	 * is specified with the WINDOW_ParentGroup. We make this a VLayout
	 * because we want to place our clicktabbed group above a row of
	 * additional buttons (Print, Cancel and Help).
	 */
	return WindowObject,
		WA_Title,           "Auto lib Test App",
		WA_DragBar,         TRUE,
		WA_SmartRefresh,    TRUE,
		WA_CloseGadget,     TRUE,
		WA_SizeGadget,      TRUE,
		WA_DepthGadget,     TRUE,
		WINDOW_ParentGroup, VLayoutObject,
			LAYOUT_AddChild, OBJ(OBJ_CLICKTAB),
			/*
			 * This will be special because we want the group to
			 * stay the same size vertically regardless of window size
			 * and rather let the content above (the clicktabbed groups)
			 * expand and take up the space.
			 *
			 * For that we first generate a group with horizontal layout
			 * and add our buttons to it. Specifying LAYOUT_EvenSize will
			 * make all buttons the same size, which looks nicer.
			 */
			LAYOUT_AddChild,        HLayoutObject,
				LAYOUT_BevelStyle,  BVS_SBAR_HORIZ,
				LAYOUT_EvenSize,    TRUE,
				LAYOUT_AddChild,    ButtonObject,
					GA_ID,          OBJ_PRINT,
					GA_Text,        "_Print",
					GA_RelVerify,   TRUE,
				End, /* Button */
				LAYOUT_AddChild,    ButtonObject,
					GA_ID,          OBJ_CANCEL,
					GA_Text,        "_Cancel",
					GA_RelVerify,   TRUE,
				End, /* Button */
				LAYOUT_AddChild,    ButtonObject,
					GA_ID,          OBJ_HELP,
					GA_Text,        "_Help",
					GA_RelVerify,   TRUE,
				End, /* Button */
			End, /* HLayout */
			/*
			 * This CHILD tag references the LAST child added (aka the
			 * current child) and therefore sets the weighted height of
			 * the above HLayoutObject containing the buttons to zero. This
			 * prevents the buttons from growing, which would look a bit
			 * queer.
			 */
			CHILD_WeightedHeight,   0,
		End, /* VLayout */
	End; /* WindowObject */
}


uint32 MessageBoxA(char *gadgets, char *format, APTR args )
{
	Object *requester;
	char buffer[512];
	uint32 result = 0;

	memset(buffer, 0, 512);
	IExec->RawDoFmt(format, args, NULL, buffer);
	requester = IIntuition->NewObject(IRequester->REQUESTER_GetClass(), NULL,
		REQ_Type,                       REQTYPE_INFO,
		REQ_TitleText,          "Auto Sample",
		REQ_BodyText,           buffer,
		REQ_GadgetText,         gadgets,
	TAG_DONE);
	if (requester)
	{
		result = IIntuition->IDoMethod( requester, RM_OPENREQ, NULL, NULL, NULL );
		IIntuition->DisposeObject(requester);
	}

	return result;
}

uint32 VARARGS68K MessageBox(char *gadgets, char *format, ...)
{
	va_list  ap;
	LONG     result;

	va_startlinear (ap, format);
	result = MessageBoxA(gadgets, format, va_getlinearva(ap,void*) );
	va_end(ap);
	return result;
}

int
main()
{
	struct Window
		*window;

	win = make_window();

	window = RA_OpenWindow(win);
	if (window)
	{
		uint32
			attr        = 0,
			sigmask     = 0,
			siggot      = 0,
			result      = 0,
			code        = 0;

		BOOL
			done        = FALSE;

		IIntuition->GetAttr(WINDOW_SigMask, win, &sigmask);

		while (!done)
		{
			siggot = IExec->Wait(sigmask | SIGBREAKF_CTRL_C);
			if (siggot & SIGBREAKF_CTRL_C) done = TRUE;

			while ((result = RA_HandleInput(win, &code)))
			{
				switch(result & WMHI_CLASSMASK)
				{
					case WMHI_CLOSEWINDOW:
						done = TRUE;
						break;
					case WMHI_GADGETUP:
						switch (result & WMHI_GADGETMASK)
						{
							case OBJ_NUP_ENABLE:
								/*
								 * Read the state of the checkbox. Could
								 * have used the code field from HandleInput,
								 * but I would like to demonstrate how to
								 * read gadget attributes.
								 */
								IIntuition->GetAttr(GA_Selected,
									OBJ(OBJ_NUP_ENABLE), &attr);
								attr = (attr == 0);
								/* (Un)ghost OBJ_PAGES_PER_SHEET */
								IIntuition->SetGadgetAttrs(GAD(OBJ_PAGES_PER_SHEET),
									window, NULL,
									GA_Disabled,    attr,
								TAG_DONE);
								break;
							case OBJ_PRINT:
							{
								uint32
									paper_size,
									paper_type;

								IIntuition->GetAttr(CHOOSER_Selected,
									OBJ(OBJ_PAPER_TYPE), &paper_type);
								IIntuition->GetAttr(CHOOSER_Selected,
									OBJ(OBJ_PAPER_SIZE), &paper_size);

								MessageBox("OK",
									"(Insert sound of a printer working...)\n" \
									"Using paper size %s on paper type %s\n" \
									"Printout finished",
									PaperSizeLabels[paper_size],
									PaperTypeLabels[paper_type]);
								done=TRUE;
								break;
							}
							case OBJ_CANCEL:
								done=TRUE;
								break;
							case OBJ_HELP:
								MessageBox("OK",
									"Normally you would display an AmigaGuide with\n" \
									"your application's help page here\n" \
									"However, this is an example only.");
								break;
						}

						break;
				}
			}
		}
	}

	IIntuition->DisposeObject(win);

	return 0;
}
