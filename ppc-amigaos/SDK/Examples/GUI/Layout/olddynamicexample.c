;/* Dynamic Example
gcc -o OldDynamicExample olddynamicexample.c -lauto
quit
*/

/****************************************************************************
*
* Dynamic layout example
*
* --- WARNING ---
*
* This example is obsolete since layout.gadget 53.2 introduced
* the LM_ADDCHILD, LM_ADDIMAGE, LM_MODIFYCHILD and LM_REMOVECHILD
* methods.
*
* You should never use the LAYOUT_AddChild, LAYOUT_AddImage,
* LAYOUT_ModifyChild and LAYOUT_RemoveChild tags with an open
* window or it could cause a deadlock with Intuition.
*
* It is safe to use these tags with a GUI which is not currently
* displayed. Use the new methods when the GUI is being displayed.
*
*****************************************************************************
*/

#include <dos/dos.h>
#include <classes/window.h>
#include <gadgets/layout.h>
#include <gadgets/button.h>
#include <gadgets/checkbox.h>
#include <libraries/gadtools.h>
#include <proto/intuition.h>
#include <proto/exec.h>


enum
{
	GID_MAIN=0,
	GID_ADDBUTTON,
	GID_REMBUTTON,
	GID_REPLACE,
	GID_ADDED,
	GID_QUIT,
	GID_LAST
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


int main()
{
	/* make sure our classes opened... */
	extern struct Library *ButtonBase, *CheckBoxBase, *WindowBase, *LayoutBase;
	if (!ButtonBase || !CheckBoxBase || !WindowBase || !LayoutBase)
	{
		return RETURN_FAIL;
	}

	struct Window *windows[WID_LAST];

	struct Gadget *gadgets[GID_LAST];

	Object *objects[OID_LAST];

	/* we must initialize this pointer! */
	gadgets[GID_ADDED] = NULL;

	struct MsgPort *AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_DONE);

	if ( AppPort != NULL )
	{
		/* Create the window object. */
		objects[OID_MAIN] = IIntuition->NewObject(NULL, "window.class",
			WA_ScreenTitle, "ReAction",
			WA_Title, "ReAction Dynamic Layout Example",
			WA_Activate, TRUE,
			WA_DepthGadget, TRUE,
			WA_DragBar, TRUE,
			WA_CloseGadget, TRUE,
			WA_SizeGadget, TRUE,
			WINDOW_IconifyGadget, TRUE,
			WINDOW_IconTitle, "Dynamic Iconified",
			WINDOW_AppPort, AppPort,
			WINDOW_Position, WPOS_CENTERMOUSE,
			WINDOW_ParentGroup, gadgets[GID_MAIN] = (struct Gadget*)IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_Orientation, LAYOUT_VERTICAL,
				LAYOUT_DeferLayout, TRUE,
				LAYOUT_SpaceOuter, TRUE,

				LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
					LAYOUT_EvenSize, TRUE,
					LAYOUT_AddChild, gadgets[GID_ADDBUTTON] = (struct Gadget*)IIntuition->NewObject(NULL, "button.gadget",
						GA_ID, GID_ADDBUTTON,
						GA_RelVerify, TRUE,
						GA_Text, "_AddChild",
					TAG_DONE),

					LAYOUT_AddChild, gadgets[GID_REMBUTTON] = (struct Gadget*)IIntuition->NewObject(NULL, "button.gadget",
						GA_ID, GID_REMBUTTON,
						GA_RelVerify, TRUE,
						GA_Text, "_RemoveChild",
						GA_Disabled, TRUE,
					TAG_DONE),

					LAYOUT_AddChild, gadgets[GID_REPLACE] = (struct Gadget*)IIntuition->NewObject(NULL, "button.gadget",
						GA_ID, GID_REPLACE,
						GA_RelVerify, TRUE,
						GA_Text, "Replace",
						GA_Disabled, TRUE,
					TAG_DONE),

					LAYOUT_AddChild, gadgets[GID_QUIT] = (struct Gadget*)IIntuition->NewObject(NULL, "button.gadget",
						GA_ID, GID_QUIT,
						GA_RelVerify, TRUE,
						GA_Text,"_Quit",
					TAG_DONE),
				TAG_DONE),
			TAG_DONE),
		TAG_DONE);

	 	/*  Object creation sucessful? */
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
										case GID_ADDBUTTON:
											if (gadgets[GID_ADDED] == NULL)
											{
												IIntuition->SetGadgetAttrs(gadgets[GID_ADDBUTTON], windows[WID_MAIN], NULL,
													GA_Disabled, TRUE,
													TAG_DONE);
												IIntuition->SetGadgetAttrs(gadgets[GID_REMBUTTON], windows[WID_MAIN], NULL,
													GA_Disabled, FALSE,
													TAG_DONE);
												IIntuition->SetGadgetAttrs(gadgets[GID_REPLACE], windows[WID_MAIN], NULL,
													GA_Disabled, FALSE,
													TAG_DONE);

												/* add a new child! */
												IIntuition->SetGadgetAttrs(gadgets[GID_MAIN], windows[WID_MAIN], NULL,
													LAYOUT_Inverted, TRUE,	// Causes AddHead vs. AddTail!
													LAYOUT_AddChild, gadgets[GID_ADDED] = (struct Gadget*)IIntuition->NewObject(NULL, "button.gadget",
														GA_ID, GID_ADDED,
														GA_RelVerify, TRUE,
														GA_Text, "Peekaboo!",
														TAG_DONE),
													TAG_DONE);

												/* rethink the window layout */
												IIntuition->IDoMethod(objects[OID_MAIN], WM_RETHINK);
											}
											break;

										case GID_REMBUTTON:
											if (gadgets[GID_ADDED] != NULL)
											{
												IIntuition->SetGadgetAttrs(gadgets[GID_ADDBUTTON], windows[WID_MAIN], NULL,
													GA_Disabled, FALSE,
													TAG_DONE);
												IIntuition->SetGadgetAttrs(gadgets[GID_REMBUTTON], windows[WID_MAIN], NULL,
													GA_Disabled, TRUE,
													TAG_DONE);
												IIntuition->SetGadgetAttrs(gadgets[GID_REPLACE], windows[WID_MAIN], NULL,
													GA_Disabled, TRUE,
													TAG_DONE);

												/* remove the child! */
												IIntuition->SetGadgetAttrs(gadgets[GID_MAIN], windows[WID_MAIN], NULL,
													LAYOUT_RemoveChild, gadgets[GID_ADDED],
													TAG_DONE);

												/* clear the pointer */
												gadgets[GID_ADDED] = NULL;

												/* bring the window back to minimum size again */
												IIntuition->SizeWindow( windows[WID_MAIN], 64000, 64000 );

												/* rethink the window layout */
												IIntuition->IDoMethod(objects[OID_MAIN], WM_RETHINK);
											}
											break;

										case GID_REPLACE:
											if (gadgets[GID_ADDED] != NULL)
											{
												struct Gadget *temp = NULL;

												IIntuition->SetGadgetAttrs(gadgets[GID_REPLACE], windows[WID_MAIN], NULL,
													GA_Disabled, TRUE,
													TAG_DONE);

												/* replace the child! */
												IIntuition->SetGadgetAttrs(gadgets[GID_MAIN], windows[WID_MAIN], NULL,
													LAYOUT_ModifyChild, gadgets[GID_ADDED],
														CHILD_ReplaceObject, temp = (struct Gadget*)IIntuition->NewObject(NULL, "checkbox.gadget",
															GA_ID, GID_ADDED,
															GA_RelVerify, TRUE,
															GA_Text, "Peekaboo!",
															CHECKBOX_TextPlace, PLACETEXT_RIGHT,
														TAG_DONE),
													TAG_DONE);

												gadgets[GID_ADDED] = temp;

												/* rethink the window layout */
												IIntuition->IDoMethod(objects[OID_MAIN], WM_RETHINK);
											}
											break;

										case GID_ADDED:
											break;

										case GID_QUIT:
											done = TRUE;
											break;
									}
									break;

								case WMHI_ICONIFY:
									if (IIntuition->IDoMethod(objects[OID_MAIN], WM_ICONIFY) != 0)
									{
										windows[WID_MAIN] = NULL;
									}
									break;

								case WMHI_UNICONIFY:
									windows[WID_MAIN] = (struct Window *) IIntuition->IDoMethod(objects[OID_MAIN], WM_OPEN);

									if (windows[WID_MAIN] != NULL)
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

			/* Disposing of the window object will also close the window if it is
			 * already opened, and it will dispose of the layout object attached to it.
			 */
			IIntuition->DisposeObject(objects[OID_MAIN]);
		}

		IExec->FreeSysObject(ASOT_PORT, AppPort);
	}

	return RETURN_OK;
}
