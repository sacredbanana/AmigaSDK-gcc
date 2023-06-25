;/*
gcc -o Clicktab_HintInfos clicktab_hintinfo_example.c -lauto
quit
*/

/*
** This example shows the new GM_QUERY feature, which can set the hintinfo string
** depending on certain situations. Clicktab implements this by allowing a hintinfo
** string to be set for each tab in the gadget. From there, everything is automatic.
** you can set a hintinfo for the tabs you need, you don't have to set them all.
** You must supply a default hintinfo via the WINDOW_HintInfo array for the clicktab,
** and this string will be used unless the tab specifies its own string. Set only the
** tabs you need, and these tabs will show the hintinfo as specified, or the
** default string. You can see this effect if you hover the pointer over an area between
** the tabs, the default hintinfo is shown, but when the pointer is over an actual
** tab, the string for that button is shown.
*/

#include <stdio.h>

#include <classes/window.h>
#include <gadgets/layout.h>
#include <gadgets/clicktab.h>
#include <images/label.h>

#include <proto/intuition.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/clicktab.h>
#include <proto/window.h>
#include <proto/label.h>
#include <proto/layout.h>
#include <proto/button.h>

enum
{
	GID_CLICKTAB,
	GID_QUIT,
	GID_LAST
};

/* clicktab hintinfos */
struct HintInfo hintinfo[] =
{
    { GID_CLICKTAB, -1, "Select a settings category", 0 },
    { GID_QUIT, -1, "Quit the demo", 0 },
    { -1, -1, NULL, 0 }
};

enum
{
	WID_MAIN=0,
	WID_LAST
};

enum
{
	OID_MAIN=0,
	OID_LAST
};

BOOL make_clicktab_list( struct List *clicktab_list )
{
	struct Node *node;

	IExec->NewList( clicktab_list );

	if(( node = IClickTab->AllocClickTabNode( TNA_Text, "General", TNA_HintInfo, "General settings", TNA_Number, 0, TAG_DONE )))
		IExec->AddTail( clicktab_list, node );
	else
		return FALSE;

	if(( node = IClickTab->AllocClickTabNode( TNA_Text, "Display", TNA_HintInfo, "Display settings", TNA_Number, 1, TAG_DONE )))
		IExec->AddTail( clicktab_list, node );
	else
		return FALSE;

	if(( node = IClickTab->AllocClickTabNode( TNA_Text, "External", TNA_HintInfo, "External program settings", TNA_Number, 2, TAG_DONE )))
		IExec->AddTail( clicktab_list, node );
	else
		return FALSE;

	if(( node = IClickTab->AllocClickTabNode( TNA_Text, "Connection", TNA_HintInfo, "Connection settings", TNA_Number, 3, TAG_DONE )))
		IExec->AddTail( clicktab_list, node );
	else
		return FALSE;

	return TRUE;
}


VOID free_clicktab_list( struct List *clicktab_list )
{
	struct Node *node = IExec->GetHead(clicktab_list), *nextnode;

	while(( nextnode = node->ln_Succ ))
	{
	    IExec->Remove( node );
		IClickTab->FreeClickTabNode( node );

		node = nextnode;
	}
}


int main()
{
	struct Window *windows[WID_LAST];

	Object *gadgets[GID_LAST];

	Object *objects[OID_LAST];

	struct List clicktab_list;

	/* make sure our classes opened... */
	if (!ButtonBase || !ClickTabBase || !WindowBase || !LayoutBase || !LabelBase)
		return(30);

	if (( make_clicktab_list(&clicktab_list ) ))
	{
		// this msgport is used for iconification. Create it before the window
		struct MsgPort *AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_DONE);

		if ( AppPort != NULL )
		{
			/* Create the window object. */
			objects[OID_MAIN] = IIntuition->NewObject(NULL, "window.class",
				WA_ScreenTitle, "ReAction Demo",
				WA_Title, "ReAction ClickTab Example",
				WA_Activate, TRUE,
				WA_DepthGadget, TRUE,
				WA_DragBar, TRUE,
				WA_CloseGadget, TRUE,
				WA_SizeGadget, TRUE,
				WINDOW_IconifyGadget, TRUE,
				WINDOW_IconTitle, "Clicktab",
				WINDOW_AppPort, AppPort,
				WINDOW_Position, WPOS_CENTERMOUSE,
                            WINDOW_HintInfo, &hintinfo,  /* we must supply a default hintinfo for the clicktab */
                            WINDOW_GadgetHelp, TRUE,
				WINDOW_Layout, IIntuition->NewObject(NULL, "layout.gadget",
					LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
					LAYOUT_SpaceOuter, TRUE,
					LAYOUT_DeferLayout, TRUE,

					LAYOUT_AddChild, gadgets[GID_CLICKTAB] = IIntuition->NewObject(NULL, "clicktab.gadget",
						GA_ID, GID_CLICKTAB,
						GA_RelVerify, TRUE,
						CLICKTAB_Labels, &clicktab_list,
						CLICKTAB_Current, 0,
						CLICKTAB_EvenSize, FALSE,
					TAG_DONE),
					CHILD_MinWidth, 160,

					LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
						LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
						LAYOUT_SpaceOuter, TRUE,
						LAYOUT_VertAlignment, LALIGN_CENTER,
						LAYOUT_HorizAlignment, LALIGN_CENTER,
						LAYOUT_BevelStyle, BVS_FIELD,

						LAYOUT_AddImage, IIntuition->NewObject(NULL, "label.image",
							LABEL_Text, "The clicktab supports multiple hint info strings.\n",
							LABEL_Text, "Usually the programmer is limited to only one string\n",
							LABEL_Text, "per gadget that is used in the 'Help bubbles', but now\n",
							LABEL_Text, "it is easy to specify a different string for each tab.\n",
							LABEL_Text, "This makes the gadget much more intuitive, especially\n",
							LABEL_Text, "when the dynamic tabs are shrunk in size to make them\n",
							LABEL_Text, "fit into the current layout space.\n",
						TAG_DONE),
					TAG_DONE),


					LAYOUT_AddChild, gadgets[GID_QUIT] = IIntuition->NewObject(NULL, "button.gadget",
						GA_ID, GID_QUIT,
						GA_RelVerify, TRUE,
						GA_Text,"_Quit",
					TAG_DONE),
					CHILD_WeightedHeight, 0,

				TAG_DONE),
			TAG_DONE);

		 	/*  Object creation sucessfull? */
			if (objects[OID_MAIN])
			{
				/*  Open the window. */
				if (windows[WID_MAIN] = (struct Window *) IIntuition->IDoMethod(objects[OID_MAIN], WM_OPEN))
				{
					ULONG wait, signal, app = (1L << AppPort->mp_SigBit);
					ULONG done = FALSE;
					ULONG result;
					UWORD code;

				 	/* Obtain the window wait signal mask.*/
					IIntuition->GetAttr(WINDOW_SigMask, objects[OID_MAIN], &signal);

					/* Input Event Loop */
					while (!done)
					{
						wait = IExec->Wait( signal | SIGBREAKF_CTRL_C | app );

						if ( wait & SIGBREAKF_CTRL_C )
						{
							done = TRUE;
						}
						else
						{
							while ( (result = IIntuition->IDoMethod(objects[OID_MAIN], WM_HANDLEINPUT, &code) ) != WMHI_LASTMSG )
							{
								switch (result & WMHI_CLASSMASK)
								{
									case WMHI_CLOSEWINDOW:
										windows[WID_MAIN] = NULL;
										done = TRUE;
										break;

									case WMHI_GADGETUP:
										switch (result & WMHI_GADGETMASK)
										{
											case GID_CLICKTAB:
												printf("Tab Selected: %d\n", (int)code );
												break;

											case GID_QUIT:
												done = TRUE;
												break;
										}
										break;

									case WMHI_ICONIFY:
										IIntuition->IDoMethod(objects[OID_MAIN], WM_ICONIFY);
										windows[WID_MAIN] = NULL;
										break;

									case WMHI_UNICONIFY:
										windows[WID_MAIN] = (struct Window *) IIntuition->IDoMethod(objects[OID_MAIN], WM_OPEN);

										if (windows[WID_MAIN])
										{
											IIntuition->GetAttr(WINDOW_SigMask, objects[OID_MAIN], &signal);
										}
										else
										{
											done = TRUE;	// error re-opening window!
										}
									 	break;
								}
							}
						}
					}
				}

				/* Disposing of the window object will
				 * also close the window if it is
				 * already opened and it will dispose of
				 * all objects attached to it.
				 */
				IIntuition->DisposeObject(objects[OID_MAIN]);
			}

			IExec->FreeSysObject(ASOT_PORT, AppPort);
		}
	}

	free_clicktab_list(&clicktab_list);

	return(0);
}
