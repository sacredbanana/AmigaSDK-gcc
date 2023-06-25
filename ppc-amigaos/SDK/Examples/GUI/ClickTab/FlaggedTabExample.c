;/*  To compile:
gcc -o FlaggedTabExample FlaggedTabExample.c -lauto -Werror -Wall
quit

  Original written by Simon Archer (20.7.2008)
*/

#include <exec/exec.h>
#include <intuition/intuition.h>
#include <dos/dos.h>
#include <images/bitmap.h>
#include <classes/window.h>
#include <gadgets/layout.h>
#include <gadgets/clicktab.h>

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/dos.h>
#include <proto/clicktab.h>
#include <proto/bitmap.h>
#include <proto/utility.h>


#define OBJ(x) Objects[x]
#define GAD(x) (struct Gadget *)Objects[x]


Object *win = NULL;

struct MsgPort *AppPort = NULL;

enum
{
	OBJ_DISK,
    OBJ_BUT_1,
    OBJ_BUT_2,
    OBJ_BUT_3,
    OBJ_CLICKTAB,
    OBJ_QUIT,
    OBJ_NUM
};

Object *Objects[OBJ_NUM];

struct List labels;
struct Window *window = NULL;

CONST_STRPTR BTEXT = "Click for flag";


void append_tab(uint16 num, CONST_STRPTR label)
{
	struct Node *node = IClickTab->AllocClickTabNode(
		TNA_Number, num,
		TNA_Text, label,
		TAG_DONE);

	if (node != NULL)
	{
		IExec->AddTail(&labels, node);
	}
}


Object *
make_window(void)
{
	struct Screen *scr;

	if(( scr = IIntuition->LockPubScreen( NULL )))
	{
		OBJ(OBJ_DISK) = IIntuition->NewObject(NULL, "bitmap.image",
			BITMAP_SourceFile, "Disk",
			BITMAP_Screen, scr,
			BITMAP_Transparent, TRUE,
        	BITMAP_Masking, TRUE,
			TAG_DONE);

		if(OBJ(OBJ_DISK) == NULL)
			return NULL;


		IIntuition->UnlockPubScreen( NULL, scr );
	}

	append_tab(0, " Tab 1");
	append_tab(1, " Tab 2");
	append_tab(2, " Tab 3");

    return IIntuition->NewObject(NULL, "window.class",
        WA_ScreenTitle,        "ReAction Example",
        WA_Title,              "Flagged ClickTab Example",
        WA_DragBar,            TRUE,
        WA_CloseGadget,        TRUE,
        WA_SizeGadget,         TRUE,
        WA_DepthGadget,        TRUE,
        WA_Activate,           TRUE,
        WA_SmartRefresh,	   TRUE,
        WINDOW_IconifyGadget,  TRUE,
        WINDOW_IconTitle,      "Iconified",
        WINDOW_AppPort,        AppPort,
        WINDOW_Position,       WPOS_CENTERSCREEN,
        WINDOW_Layout,         IIntuition->NewObject(NULL, "layout.gadget",
			LAYOUT_Orientation,   LAYOUT_ORIENT_VERT,
			LAYOUT_DeferLayout, TRUE,
            LAYOUT_AddChild,       OBJ(OBJ_CLICKTAB) = IIntuition->NewObject(NULL, "clicktab.gadget",
            	GA_ID, 				OBJ_CLICKTAB,
            	GA_RelVerify,		TRUE,
		        CLICKTAB_Labels,	&labels,
    		    CLICKTAB_Current,   0,
        		CLICKTAB_FlagImage, OBJ(OBJ_DISK),
        		CLICKTAB_EvenSize,  TRUE,
        		CLICKTAB_LabelTruncate, FALSE,
				CLICKTAB_AutoFit,   FALSE,  // Remember WM_RETHINK if you change any labels (see autodoc).
        		CLICKTAB_PageGroup, IIntuition->NewObject(NULL, "page.gadget",
            		PAGE_Add,       IIntuition->NewObject(NULL, "layout.gadget",
						LAYOUT_Orientation,   LAYOUT_ORIENT_VERT,
                		LAYOUT_BevelStyle,    BVS_GROUP,
                		LAYOUT_Label,         "Page One",
                		LAYOUT_AddChild,      IIntuition->NewObject(NULL, "button.gadget", GA_Text, BTEXT, GA_ID, OBJ_BUT_1, GA_RelVerify, TRUE, TAG_DONE),
                		CHILD_WeightedHeight, 0,
            		TAG_DONE),
            		PAGE_Add,       IIntuition->NewObject(NULL, "layout.gadget",
						LAYOUT_Orientation,   LAYOUT_ORIENT_VERT,
                		LAYOUT_BevelStyle,  BVS_GROUP,
                		LAYOUT_Label,       "Page Two",
                		LAYOUT_AddChild,    IIntuition->NewObject(NULL, "button.gadget", GA_Text, BTEXT, GA_ID, OBJ_BUT_2, GA_RelVerify, TRUE, TAG_DONE),
                		CHILD_WeightedHeight, 0,
            		TAG_DONE),
            		PAGE_Add,       IIntuition->NewObject(NULL, "layout.gadget",
						LAYOUT_Orientation,   LAYOUT_ORIENT_VERT,
    					LAYOUT_BevelStyle,  BVS_GROUP,
                		LAYOUT_Label,       "Page Three",
                		LAYOUT_AddChild,    IIntuition->NewObject(NULL, "button.gadget", GA_Text, BTEXT, GA_ID, OBJ_BUT_3, GA_RelVerify, TRUE, TAG_DONE),
                		CHILD_WeightedHeight, 0,
             		TAG_DONE),
        		TAG_DONE),
	    	TAG_DONE),

            LAYOUT_AddChild,       IIntuition->NewObject(NULL, "button.gadget", GA_Text, "_Quit", GA_ID, OBJ_QUIT, GA_RelVerify, TRUE, TAG_DONE),
            CHILD_WeightedHeight,  0,

        TAG_DONE),
    TAG_DONE);
}


void FlagClicktab( void )
{
	/* This function does the magic of setting the active tab
	** "Flagged". It displays a small disk image in the upper
	** left corner of the tab, or removes it if already flagged
	** As a bonus, it also demonstrates the dynamic way in which
	** the text for the node can be changed too.
	*/

	struct Node *node = NULL;

	/* get the currently active node, and the lable list pointer */
	IIntuition->GetAttrs( OBJ(OBJ_CLICKTAB),
		CLICKTAB_CurrentNode, &node,
		TAG_DONE );

	/* detach the label list from the gadget */
	IIntuition->SetAttrs( OBJ(OBJ_CLICKTAB),
		CLICKTAB_Labels, NULL,
		TAG_DONE );

	/* get the state of the tab (flagged or not) */
	ULONG state = 0;

	IClickTab->GetClickTabNodeAttrs( node,
		TNA_Flagged, &state,
		TAG_DONE );

	/* set the flagged attribute depending on whether it is flagged already or not, and set the label accordingly */
	IClickTab->SetClickTabNodeAttrs( node,
		TNA_Flagged, state ? FALSE : TRUE,
		TNA_Text, state ? "Unflagged" : "Flagged",
		TAG_DONE );

	/* Reattach the list back to the gadget. No need for refresh at this
	 * point since we are invoking WM_RETHINK below.
	 * CLICKTAB_AutoFit we must make sure
	 */
	IIntuition->SetAttrs( GAD(OBJ_CLICKTAB),
		CLICKTAB_Labels, &labels,
		TAG_DONE );

	/* Since we changed the labels the clicktab.gadget may not fit within
	 * it's domain any longer. We must call WM_RETHINK in case the window
	 * needs to grow to accomodate the new size.
	 */
	IIntuition->IDoMethod(win, WM_RETHINK);
}


int
main()
{
	IExec->NewList(&labels);

    if ((AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_DONE)))
    {
        win = make_window();
        if ((window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN)))
        {
            uint32
                sigmask     = 0,
                siggot      = 0,
                result      = 0;
            uint16
                code        = 0;
            BOOL
                done        = FALSE;

            IIntuition->GetAttr(WINDOW_SigMask, win, &sigmask);
            while (!done)
            {
                siggot = IExec->Wait(sigmask | SIGBREAKF_CTRL_C);

                if (siggot & SIGBREAKF_CTRL_C)
                	done = TRUE;

                while ((result = IIntuition->IDoMethod(win, WM_HANDLEINPUT, &code)))
                {
                    switch(result & WMHI_CLASSMASK)
                    {
                        case WMHI_CLOSEWINDOW:
                            done = TRUE;
                            break;

                        case WMHI_GADGETUP:
                            switch (result & WMHI_GADGETMASK)
                            {
                            	case OBJ_BUT_1:
                            	case OBJ_BUT_2:
                            	case OBJ_BUT_3:
                            		/* set the current tab as "Flagged" */
                            		FlagClicktab();
                            		break;

                                case OBJ_QUIT:
                                    done=TRUE;
                                    break;
                            }
                            break;

                        case WMHI_ICONIFY:
                            if (IIntuition->IDoMethod(win, WM_ICONIFY)) window = NULL;
                            break;

                        case WMHI_UNICONIFY:
                            window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN);
                            break;
                    }
                }
            }
        }

        IIntuition->DisposeObject(win);
		IClickTab->FreeClickTabList(&labels);
        IExec->FreeSysObject(ASOT_PORT, AppPort);
    }

    return 0;
}
