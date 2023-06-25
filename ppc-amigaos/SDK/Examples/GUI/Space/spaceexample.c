;/* Space Example
gcc -o Space spaceexample.c -lauto
quit
*/

/**
 **  SpaceExample.c -- space.gadget example.
 **  V1.0 - Martin McKenzie
 **
 **  This is a simple example testing some of the capabilities of the
 **  space gadget class.
 **
 **  This opens a window with two buttons and a space gadget.
 **  Select the 'Display Areabox values' button to output the space
 **  gadgets current Left/Top/Width/Height values. Resize the window, then
 **  select the button again to output the updated values.
 **
 **/

/* system includes
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALL_REACTION_CLASSES
#include <reaction/reaction.h>
#include <reaction/reaction_macros.h>
#include <proto/exec.h>
#include <proto/intuition.h>

enum
{
	GID_MAIN=0,
	GID_QUIT,
	GID_DISPLAYAREABOX,
	GID_SPACETEST,
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
	struct MsgPort *AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_END);

	struct Window *windows[WID_LAST];

	struct Gadget *gadgets[GID_LAST];

	Object *objects[OID_LAST];

	/* make sure our classes opened... */
	if (!ButtonBase || !WindowBase || !SpaceBase || !LayoutBase)
		return(30);

	if ( AppPort != NULL )
	{
			/* Create the window object. */
			objects[OID_MAIN] = WindowObject,
				WA_ScreenTitle, "ReAction OS4",
				WA_Title, "ReAction Space AreaBox Example",
				WA_Activate, TRUE,
				WA_DepthGadget, TRUE,
				WA_DragBar, TRUE,
				WA_CloseGadget, TRUE,
				WA_SizeGadget, TRUE,
				WINDOW_IconifyGadget, TRUE,
				WINDOW_IconTitle, "AreaBox Test",
				WINDOW_AppPort, AppPort,
				WINDOW_Position, WPOS_CENTERMOUSE,
				WINDOW_ParentGroup, gadgets[GID_MAIN] = (struct Gadget*)VGroupObject,
					LAYOUT_SpaceOuter, TRUE,
					LAYOUT_DeferLayout, TRUE,

					LAYOUT_AddChild, gadgets[GID_DISPLAYAREABOX] = (struct Gadget*)ButtonObject,
						GA_ID, GID_DISPLAYAREABOX,
						GA_RelVerify, TRUE,
						GA_Text,"_Display Areabox values",
					ButtonEnd,

					LAYOUT_AddChild, ButtonObject,
						GA_ID, GID_QUIT,
						GA_RelVerify, TRUE,
						GA_Text,"_Quit",
					ButtonEnd,
					CHILD_WeightedHeight, 0,

					LAYOUT_AddChild, gadgets[GID_SPACETEST] = (struct Gadget*)SpaceObject,
						GA_ID, GID_SPACETEST,
						SPACE_MinWidth,     50,
						SPACE_MinHeight,    50,
					SpaceEnd,

				EndGroup,
			EndWindow;

		/*  Object creation sucessful? */
		if (objects[OID_MAIN])
		{
			/*  Open the window.*/
			if (windows[WID_MAIN] = (struct Window *) RA_OpenWindow(objects[OID_MAIN]))
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
						while ( (result = RA_HandleInput(objects[OID_MAIN], &code) ) != WMHI_LASTMSG )
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
										case GID_DISPLAYAREABOX:
										{
											struct IBox box;
											IIntuition->GetAttr(SPACE_RenderBox, (Object*)gadgets[GID_SPACETEST], (uint32*)&box);
											printf("space areabox->left: %d\n", box.Left);
											printf("space areabox->top: %d\n", box.Top);
											printf("space areabox->width: %d\n", box.Width);
											printf("space areabox->height: %d\n", box.Height);
											break;
										}

										case GID_QUIT:
											done = TRUE;
											break;
									}
									break;

								case WMHI_ICONIFY:
									RA_Iconify(objects[OID_MAIN]);
									windows[WID_MAIN] = NULL;
									break;

								case WMHI_UNICONIFY:
									windows[WID_MAIN] = (struct Window *) RA_OpenWindow(objects[OID_MAIN]);

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

	return 0;
}

