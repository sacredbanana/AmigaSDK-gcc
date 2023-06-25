;/* execute me to compile
gcc -o SpeedExample2 SpeedExample2.c -lauto
quit
*/

/* Original version
 * Copyright � 1995 Christopher Aldi
 * All Rights Reserved.
 *
 * This Example Shows speed of laying out & rendering 50 checkboxs
 */

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/utility.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/layout.h>
#include <proto/checkbox.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <proto/window.h>
#include <classes/window.h>

#include <libraries/gadtools.h>

#define ALL_REACTION_CLASSES
#include <reaction/reaction.h>
#include <reaction/reaction_macros.h>



LONG ARG[1];

int main( void )
{
	struct Window *window;
	Object *Win_Object;
	ULONG signal, result;
	ULONG done = FALSE;
	struct RDArgs *args;

	if (!(args = IDOS->ReadArgs("ND=NODEFER/S",ARG,NULL)))
		return 20;

	Win_Object = WindowObject,
		WA_ScreenTitle, "ReAction Example",
		WA_Title, "SpeedTest2 (50 checkboxes)",
		WA_SizeGadget, TRUE,
		WA_Left, 40,
		WA_Top, 30,
		WA_DepthGadget, TRUE,
		WA_DragBar, TRUE,
		WA_CloseGadget, TRUE,
		WA_Activate, TRUE,
		WINDOW_ParentGroup, HGroupObject,
			TAligned,
			LAYOUT_SpaceOuter, TRUE,
			LAYOUT_DeferLayout, !ARG[0],
			StartVGroup,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
			End,
			StartVGroup,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
			End,
			StartVGroup,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
			End,
			StartVGroup,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
			End,
			StartVGroup,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
				StartMember, CheckBoxObject,
					GA_Text, "CheckBox",
				EndMember,
			End,

		EndMember,
	EndWindow;

	/*  Object creation sucessful?
	 */
	if( Win_Object )
	{
		/*  Open the window.
		 */
		if( window = (struct Window *) RA_OpenWindow(Win_Object) )
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

				while ((result = RA_HandleInput(Win_Object,NULL)) != WMHI_LASTMSG)
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
