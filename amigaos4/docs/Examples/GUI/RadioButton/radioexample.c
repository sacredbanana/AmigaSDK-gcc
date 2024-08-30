;/* RadioButton Example
gcc -o RadioButton radioexample.c -lauto
quit
*/

/**
 **  RadioExample.c -- radiobutton class example.
 **
 **  This is a simple example testing some of the capabilities of the
 **  radiobutton gadget class.
 **
 **  This opens a window with radio button gadget.
 **
 **/

#include <classes/window.h>
#include <gadgets/button.h>
#include <gadgets/layout.h>
#include <gadgets/radiobutton.h>

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/button.h>
#include <proto/layout.h>
#include <proto/radiobutton.h>
#include <proto/window.h>

enum
{
	GID_MAIN=0,
	GID_RADIOBUTTON,
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
	struct MsgPort *AppPort = NULL;

	struct Window *windows[WID_LAST];

	struct Gadget *gadgets[GID_LAST];

	Object *objects[OID_LAST];

	/* make sure our classes opened... */
	if (!IButton || !IRadioButton || !IWindow || !ILayout)
		return RETURN_FAIL;
	else if ( AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_END) )
	{
		/* Create radiobutton label list. */
		CONST_STRPTR radiolist[] = {"1200","2400","4800","9600","19200","38400","57600",NULL};

		/* Create the window object. */
		objects[OID_MAIN] = IIntuition->NewObject(NULL, "window.class",
			WA_ScreenTitle, "ReAction",
			WA_Title, "ReAction RadioButton Example",
			WA_Activate, TRUE,
			WA_DepthGadget, TRUE,
			WA_DragBar, TRUE,
			WA_CloseGadget, TRUE,
			WA_SizeGadget, TRUE,
			WINDOW_IconifyGadget, TRUE,
			WINDOW_IconTitle, "RadioButton",
			WINDOW_AppPort, AppPort,
			WINDOW_Position, WPOS_CENTERMOUSE,
			WINDOW_ParentGroup, gadgets[GID_MAIN] = (struct Gadget*)IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
				LAYOUT_SpaceOuter, TRUE,
				LAYOUT_DeferLayout, TRUE,

				LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
					LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
					LAYOUT_SpaceOuter, TRUE,
					LAYOUT_BevelStyle, BVS_GROUP,
					LAYOUT_Label, "Baud",

					LAYOUT_AddChild, gadgets[GID_RADIOBUTTON] = (struct Gadget*)IIntuition->NewObject(NULL, "radiobutton.gadget",
						GA_ID, GID_RADIOBUTTON,
						GA_RelVerify, TRUE,
						GA_Text, radiolist,
						RADIOBUTTON_Selected, 0,
					TAG_END),
				TAG_END),

				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_ID, GID_QUIT,
					GA_RelVerify, TRUE,
					GA_Text,"_Quit",
				TAG_END),
				CHILD_WeightedHeight, 0,

			TAG_END),
		TAG_END);

 	 	/*  Object creation sucessful? */
		if (objects[OID_MAIN])
		{
			/*  Open the window.*/
			if (windows[WID_MAIN] = (struct Window *)IIntuition->IDoMethod(objects[OID_MAIN], WM_OPEN))
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
										case GID_RADIOBUTTON:
										{
											uint32 selected = 0;
											IIntuition->GetAttr(RADIOBUTTON_Selected, (Object*)gadgets[GID_RADIOBUTTON], &selected);
											IDOS->Printf("You selected item: code=%lu selected=%lu\n", code, selected);
											break;
										}

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

			/* Disposing of the window object will also close the window if it is
			 * already opened, and it will dispose of the layout object attached to it.
			 */
			IIntuition->DisposeObject(objects[OID_MAIN]);
		}

		IExec->FreeSysObject(ASOT_PORT, AppPort);
	}

	return RETURN_OK;
}
