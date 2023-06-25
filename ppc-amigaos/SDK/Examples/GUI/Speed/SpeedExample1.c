;/* execute me to compile
gcc -o SpeedExample1 SpeedExample1.c -lauto
quit
*/

/*
 * Original version
 * Copyright (c) 1995 Christopher Aldi
 * All Rights Reserved.
 *
 * This example shows the speed of laying out & rendering 100 buttons.
 */

#include <classes/window.h>
#include <gadgets/layout.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/utility.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/window.h>
#include <proto/button.h>
#include <proto/layout.h>


LONG ARG[1];

int main( void )
{
	struct Window *window;
	Object *Win_Object;
	ULONG signal, result;
	ULONG done = FALSE;
	struct RDArgs *args;

	if (!WindowBase || !ButtonBase || !LayoutBase)
		return 20;

	if (!(args = IDOS->ReadArgs("ND=NODEFER/S",ARG,NULL)))
		return 20;

	/* Create the window object.
	 */
	Win_Object = IIntuition->NewObject(NULL, "window.class",
		WA_Title, "SpeedTest1 (100 buttons)",
		WA_SizeGadget, TRUE,
		WA_Left, 40,
		WA_Top, 30,
		WA_DepthGadget, TRUE,
		WA_DragBar, TRUE,
		WA_CloseGadget, TRUE,
		WA_Activate, TRUE,
		WINDOW_Layout, IIntuition->NewObject(NULL, "layout.gadget",
			LAYOUT_SpaceOuter, TRUE,
			LAYOUT_DeferLayout, !ARG[0],
			LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
			LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
			TAG_END),
			LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
			TAG_END),
			LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
			TAG_END),
			LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
			TAG_END),
			LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
			TAG_END),
			LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
			TAG_END),
			LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
			TAG_END),
			LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
			TAG_END),
			LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
			TAG_END),
			LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
				LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "Button",
				TAG_END),
			TAG_END),
		TAG_END),
	TAG_END);

	/*  Object creation successful?
	 */
	if( Win_Object )
	{
		/*  Open the window.
		 */
		if( window = (struct Window *) IIntuition->IDoMethod(Win_Object, WM_OPEN) )
		{
			ULONG wait;

			/* Obtain the window wait signal mask.
			 */
			IIntuition->GetAttr( WINDOW_SigMask, Win_Object, &signal );

			/* Input Event Loop
			 */
			while( !done )
			{
				wait = IExec->Wait(signal|SIGBREAKF_CTRL_C);

				if (wait & SIGBREAKF_CTRL_C) done = TRUE;
				else

				while ((result = IIntuition->IDoMethod(Win_Object,WM_HANDLEINPUT,NULL)) != WMHI_LASTMSG)
				{
					switch(result)
					{
						case WMHI_CLOSEWINDOW:
							done = TRUE;
							break;
					}
				}
			}
		}

		/* Disposing of the window object will
		 * also close the window if it is
		 * already opened and it will dispose of
		 * all objects attached to it.
		 */
		IIntuition->DisposeObject( Win_Object );
	}

	IDOS->FreeArgs(args);
}
