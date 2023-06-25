;/* Execute to compile
gcc -o DynamicTabExample DynamicTabExample.c -lauto -Werror -Wall
quit

  Original version by Simon Archer (21.7.2008)
*/

#include <classes/window.h>
#include <gadgets/button.h>
#include <gadgets/layout.h>
#include <gadgets/clicktab.h>

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/dos.h>
#include <proto/clicktab.h>
#include <proto/checkbox.h>
#include <proto/button.h>
#include <proto/utility.h>

#include <string.h>


enum
{
    OBJ_ADD,
    OBJ_REMOVE,
    OBJ_CLICKTAB,
    OBJ_PAGE,
    OBJ_QUIT,
    OBJ_RETHINK,
    OBJ_EVENSIZE,
    OBJ_TRUNCATE,
    OBJ_AUTOFIT,
    OBJ_NUM
};


Object *Objects[OBJ_NUM];

struct MsgPort *AppPort = NULL;
Object *win = NULL;
struct Window *window = NULL;

struct List clicktablabels;


struct Node *append_page(CONST_STRPTR label)
{
	Object *page = IIntuition->NewObject(NULL, "layout.gadget",
        LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
        LAYOUT_BevelStyle, BVS_GROUP,
        LAYOUT_Label, "Page Group",

        LAYOUT_AddChild, Objects[OBJ_REMOVE] = IIntuition->NewObject(NULL, "button.gadget",
            GA_ID, OBJ_REMOVE,
            GA_Text, "Click to Remove Tab",
            GA_RelVerify, TRUE,
        TAG_DONE),
        CHILD_WeightedHeight, 0,
        CHILD_WeightedWidth,  0,
    TAG_DONE);

	if (page != NULL)
	{
		IIntuition->SetAttrs(Objects[OBJ_PAGE],
			PAGE_Add, page,
			TAG_DONE);
	}

    struct Node *tab_node = IClickTab->AllocClickTabNode(
        TNA_Text, label,
        TNA_UserData, page,
        TAG_DONE);

    if (tab_node != NULL)
    {
        IExec->AddTail( &clicktablabels, tab_node );
    }

    return tab_node;
}


void free_page(struct Node *tab_node)
{
	// Detach the list from the gadget.
	IIntuition->SetAttrs(Objects[OBJ_CLICKTAB],
		CLICKTAB_Labels, NULL,
		TAG_DONE);

	// Remove it from the list.
    IExec->Remove( tab_node );

	// Free the page associated with this tab.
	Object *page = NULL;

    IClickTab->GetClickTabNodeAttrs(tab_node,
    	TNA_UserData, &page,
        TAG_DONE);

	// This also disposes the page object.
	IIntuition->SetAttrs(Objects[OBJ_PAGE],
    	PAGE_Remove, page,
        TAG_DONE);

	// Free the tab node; this is the only way to free nodes
	IClickTab->FreeClickTabNode( tab_node );
    tab_node = NULL;

	/* Add the list back and make the first tab the active one.
     *
     * We are making the first tab the active one as we have removed
     * the one that was active. You can do some clever processing to
     * determine which should be the active one, but this is just an
     * example, right? :)
     */
	IIntuition->RefreshSetGadgetAttrs((struct Gadget *)Objects[OBJ_CLICKTAB], window, NULL,
    	CLICKTAB_Labels, &clicktablabels,
        CLICKTAB_Current, 0,
        TAG_DONE);
}


void relabel_tabs(void)
{
	// Always detach the clicktab label list before manipulating.
	IIntuition->SetAttrs(Objects[OBJ_CLICKTAB],
		CLICKTAB_Labels, NULL,
		TAG_DONE);

	struct Node *tab_node = IExec->GetHead(&clicktablabels);

	while (tab_node != NULL)
	{
		CONST_STRPTR tab_text = NULL;
    	uint32 tab_num = 0;
        Object *page = NULL;

        IClickTab->GetClickTabNodeAttrs(tab_node,
			TNA_Text, &tab_text,
        	TNA_Number, &tab_num,
            TNA_UserData, &page,
            TAG_DONE);

		if (page != NULL)
        {
			// Here we play some string games so that the tab number
			// appears before the tab label. The clicktab.gadget copies
			// the label into internal buffers so we don't have to
			// worry about keeping the string buffer around.
			char buf[128];

			const char* name = strchr(tab_text, ':');
			if (name == NULL)
			{
				IUtility->SNPrintf(buf, sizeof(buf), "%lu: %s", tab_num, tab_text);
				name = buf;
			}
			else
			{
				IUtility->SNPrintf(buf, sizeof(buf), "%lu: %s", tab_num, name + 2);
				name = buf;
			}

			IClickTab->SetClickTabNodeAttrs(tab_node,
				TNA_Text, name,
				TAG_DONE);
        }

		tab_node = IExec->GetSucc(tab_node);
	}

	// Since we changed the labels we must refresh the tabs.
	IIntuition->RefreshSetGadgetAttrs((struct Gadget*)Objects[OBJ_CLICKTAB], window, NULL,
    	CLICKTAB_Labels, &clicktablabels,
        TAG_DONE);
}


Object *make_window(void)
{
    /* prepare the clicktablabels list */
    IExec->NewList(&clicktablabels);

    Object *layout = IIntuition->NewObject(NULL, "layout.gadget",
        LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
        LAYOUT_DeferLayout, TRUE,
        LAYOUT_AddChild, Objects[OBJ_CLICKTAB] = IIntuition->NewObject(NULL, "clicktab.gadget",
            GA_ID, OBJ_CLICKTAB,
            GA_RelVerify, TRUE,
            // The list of tabs; we add this later.
            CLICKTAB_Labels, NULL,
            // Override the system settings and force each tab to be even size.
            CLICKTAB_EvenSize, FALSE,
            // Allow tabs to be truncated, adding tabs requires more room.
            CLICKTAB_LabelTruncate, TRUE,
            // Automatically fit dynamic tabs within our rendering bounds.
            CLICKTAB_AutoFit, TRUE,
            // Add a page.gadget for flipping between pages.
            CLICKTAB_PageGroup, Objects[OBJ_PAGE] = IIntuition->NewObject(NULL, "page.gadget", TAG_DONE),
            // Automatically number tabs for the page group page.gadget.
            CLICKTAB_AutoTabNumbering, TRUE,
        TAG_DONE),

        LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
            LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
            LAYOUT_AddChild, Objects[OBJ_EVENSIZE] = IIntuition->NewObject(NULL, "checkbox.gadget",
                GA_ID, OBJ_EVENSIZE,
                GA_Text, "_Even Size",
                GA_RelVerify, TRUE,
                GA_Selected, FALSE,
            TAG_DONE),
            LAYOUT_AddChild, Objects[OBJ_TRUNCATE] = IIntuition->NewObject(NULL, "checkbox.gadget",
                GA_ID, OBJ_TRUNCATE,
                GA_Text, "_Truncate Labels",
                GA_RelVerify, TRUE,
                GA_Selected, TRUE,
            TAG_DONE),
            LAYOUT_AddChild, Objects[OBJ_AUTOFIT] = IIntuition->NewObject(NULL, "checkbox.gadget",
                GA_ID, OBJ_AUTOFIT,
                GA_Text, "Auto-_Fit",
                GA_RelVerify, TRUE,
                GA_Selected, TRUE,
            TAG_DONE),
        TAG_DONE),
        CHILD_WeightedHeight, 0,

        LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
            LAYOUT_FixedVert, FALSE,
            LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
				GA_ID, OBJ_ADD,
				GA_Text, "_Add Tab",
				GA_RelVerify, TRUE,
			TAG_DONE),
            LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
				GA_ID, OBJ_RETHINK,
				GA_Text, "_Rethink Layout",
				GA_RelVerify, TRUE,
			TAG_DONE),
            LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
				GA_ID, OBJ_QUIT,
				GA_Text, "_Quit",
				GA_RelVerify, TRUE,
			TAG_DONE),
        TAG_DONE),
        CHILD_WeightedHeight,  0,
        CHILD_WeightedWidth,  0,

    TAG_DONE);

	// Create some initial pages.
    append_page( "This is a Tab" );
    append_page( "Another Tab" );
    append_page( "Yet Another Tab" );
    append_page( "A Really Long Tab That Goes Beyond The Bounds" );

    IIntuition->SetAttrs(Objects[OBJ_CLICKTAB],
        CLICKTAB_Labels, &clicktablabels,
        CLICKTAB_Current, 0,
        TAG_DONE);

	relabel_tabs();

    Object *window = IIntuition->NewObject(NULL, "window.class",
        WA_Title, "Dynamic ClickTab Example",
        WA_DragBar, TRUE,
        WA_CloseGadget, TRUE,
        WA_SizeGadget, TRUE,
        WA_DepthGadget, TRUE,
        WA_Activate, TRUE,
        WA_SmartRefresh, TRUE,
        WINDOW_IconifyGadget, TRUE,
        WINDOW_IconTitle, "Iconified",
        WINDOW_AppPort, AppPort,
        WINDOW_Position, WPOS_CENTERSCREEN,
        WINDOW_Layout, layout,
    TAG_DONE);

    return window;
}


int main()
{
    // Make sure the classes are loaded.
    if (!WindowBase || !LayoutBase || !ButtonBase || !ClickTabBase || !CheckBoxBase)
    {
        return RETURN_FAIL;
    }

    AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_DONE);
    if (AppPort != NULL)
    {
        win = make_window();

        window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN);

        if (window != NULL)
        {
            uint32 waitmask = 0;
            uint32 sigmask  = 0;
            uint32 result   = 0;
            uint16 code     = 0;
            BOOL done       = FALSE;

            IIntuition->GetAttr(WINDOW_SigMask, win, &waitmask);
            while (!done)
            {
                sigmask = IExec->Wait(waitmask | SIGBREAKF_CTRL_C);

                if (sigmask & SIGBREAKF_CTRL_C)
                    done = TRUE;

                while ((result = IIntuition->IDoMethod(win, WM_HANDLEINPUT, &code)) != WMHI_LASTMSG)
                {
                    switch(result & WMHI_CLASSMASK)
                    {
                        case WMHI_CLOSEWINDOW:
                            done = TRUE;
                            break;

                        case WMHI_GADGETUP:
                            switch (result & WMHI_GADGETMASK)
                            {
                                case OBJ_ADD:
                                {
                                    // Here is where we dynamically add a tab for display in the clicktab.

                                    // Detach the clicktab labels from the gadget...
                                    IIntuition->SetAttrs(Objects[OBJ_CLICKTAB],
										CLICKTAB_Labels, NULL,
										TAG_DONE);

                                    // Add a new tab and page...
                                    struct Node *node = append_page( "New Tab" );

                                    /* Add the labels back to the gadget and make the new tab current.
									 *
                                     * Using RefreshSetGadgetAttrs() is required to force intuition
                                     * to refresh the gadget imagery.
                                     */
                                    IIntuition->RefreshSetGadgetAttrs((struct Gadget *)Objects[OBJ_CLICKTAB], window, NULL,
                                        CLICKTAB_Labels, &clicktablabels,
                                        CLICKTAB_CurrentNode, node,
                                        TAG_DONE);

									// Relabel the buttons to match the automatic tab numbering.
									relabel_tabs();

                                    break;
                                }

                                case OBJ_REMOVE:
                                {
                                    // We are going to remove the currently active tab.

                                    // Get the current tab so we can remove it.
                                    struct Node *tab_node = NULL;

                                    IIntuition->GetAttrs((struct Gadget *)Objects[OBJ_CLICKTAB],
                                    	CLICKTAB_CurrentNode, &tab_node,
                                    	TAG_DONE);

									// The node could be NULL if the list is empty.
                                    if( tab_node != NULL)
                                    {
										free_page(tab_node);

										// Relabel the buttons to match the automatic tab numbering.
										relabel_tabs();
                                    }

                                    break;
                                }

                                case OBJ_RETHINK:
                                {
                                    IIntuition->IDoMethod(win, WM_RETHINK);
                                    break;
                                }

                                case OBJ_EVENSIZE:
                                {
                                    uint32 selected = 0;
                                    IIntuition->GetAttr(GA_Selected, Objects[OBJ_EVENSIZE], &selected);

                                    IIntuition->RefreshSetGadgetAttrs((struct Gadget *)Objects[OBJ_CLICKTAB], window, NULL,
                                        CLICKTAB_EvenSize, selected,
                                        TAG_DONE);

                                    break;
                                }

                                case OBJ_TRUNCATE:
                                {
                                    uint32 selected = 0;
                                    IIntuition->GetAttr(GA_Selected, Objects[OBJ_TRUNCATE], &selected);

                                    IIntuition->RefreshSetGadgetAttrs((struct Gadget *)Objects[OBJ_CLICKTAB], window, NULL,
                                        CLICKTAB_LabelTruncate, selected,
                                        TAG_DONE);

                                    break;
                                }

                                case OBJ_AUTOFIT:
                                {
                                    uint32 selected = 0;
                                    IIntuition->GetAttr(GA_Selected, Objects[OBJ_AUTOFIT], &selected);

                                    IIntuition->RefreshSetGadgetAttrs((struct Gadget *)Objects[OBJ_CLICKTAB], window, NULL,
                                        CLICKTAB_AutoFit, selected,
                                        TAG_DONE);

                                    break;
                                }

                                case OBJ_QUIT:
                                {
                                    done = TRUE;
                                    break;
                                }
                            }

                            break;

                        case WMHI_ICONIFY:
                            if (IIntuition->IDoMethod(win, WM_ICONIFY))
							{
								window = NULL;
							}
                            break;

                        case WMHI_UNICONIFY:
                            window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN);
                            break;
                    }
                }
            }
        }

        IIntuition->DisposeObject(win);
        IExec->FreeSysObject(ASOT_PORT, AppPort);
    }

    return RETURN_OK;
}
