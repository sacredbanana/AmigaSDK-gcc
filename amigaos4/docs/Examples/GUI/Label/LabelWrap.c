;/* Execute me to compile
gcc -o LabelWrap LabelWrap.c -lauto
quit
:*/

/**
 **  LabelWrap.c -- Label class example.
 **
 **  This is a simple example testing the label text wrapping feature.
 **
 **/

#include <images/label.h>
#include <gadgets/layout.h>
#include <classes/window.h>
#include <dos/dos.h>

#include <proto/intuition.h>
#include <proto/exec.h>
#include <proto/label.h>
#include <proto/window.h>
#include <proto/layout.h>


CONST_STRPTR label_text =
	"This is the label text which is a lot longer than a single " \
	"line and needs to be word wrapped to fit within the label properly." \
	"Lines can also contain line-breaks like this\n\nso that a basic form of formatting can be achieved\n\nsee?";


int main()
{
	// Make sure the classes are loaded.
	if (!WindowBase || !LayoutBase || !LabelBase)
	{
		return RETURN_FAIL;
	}

	struct Screen *screen = IIntuition->LockPubScreen(NULL);

	if (screen != NULL)
	{
		struct DrawInfo *drinfo = IIntuition->GetScreenDrawInfo(screen);

		if (drinfo != NULL)
		{
			Object *win_obj = IIntuition->NewObject(NULL, "window.class",
				WA_CloseGadget, TRUE,
				WA_SizeGadget, TRUE,
				WA_DragBar, TRUE,
				WA_Title, "Label Text Wrap Example",
				WINDOW_Layout, IIntuition->NewObject(NULL, "layout.gadget",
					LAYOUT_AddImage, IIntuition->NewObject(NULL, "label.image",
						LABEL_DrawInfo, drinfo,
						LABEL_WordWrap, 20,
						LABEL_Text, label_text,
						TAG_END),
					TAG_END),
				TAG_END);

			if (win_obj != NULL)
			{
				struct Window *win = (struct Window*)IIntuition->IDoMethod(win_obj, WM_OPEN);

				if (win != NULL)
				{
					uint32 waitmask = 0;
					IIntuition->GetAttr(WINDOW_SigMask, win_obj, &waitmask);

					BOOL done = FALSE;

					while (!done)
					{
						uint32 sigmask = IExec->Wait(waitmask);

						uint32 result = 0;
						int16 code    = 0;

						while ((result = IIntuition->IDoMethod(win_obj, WM_HANDLEINPUT, &code)) != WMHI_LASTMSG)
						{
							switch (result & WMHI_CLASSMASK)
							{
								case WMHI_CLOSEWINDOW:
									done = TRUE;
									break;
							}
						}
					}
				}

				IIntuition->DisposeObject(win_obj);
			}

			IIntuition->FreeScreenDrawInfo(screen, drinfo);
		}

		IIntuition->UnlockPubScreen(0, screen);
	}

	return RETURN_OK;
}
