;/* Example of penmap.image
gcc -o PenMapExample PenMapExample.c -lauto
quit
;*/

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>

#include <images/penmap.h>

struct ClassLibrary *PenMapBase;
Class               *PenMapClass;

struct Window *win;
Object        *image_object;

ULONG   image_object_palette[] =
{
   2,
   0x00000000, 0x00000000, 0x00000000,
   0xEEEEEEEE, 0xDDDDDDDD, 0x00000000
};

UBYTE   happy_data[] =
{
   0,16, 0,14,
   0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
   0,0,0,1,1,2,2,2,2,2,2,1,1,0,0,0,
   0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,
   0,1,2,2,2,2,2,2,2,2,2,2,2,2,1,0,
   0,1,2,2,2,1,1,2,2,1,1,2,2,2,1,0,
   1,2,2,2,2,1,1,2,2,1,1,2,2,2,2,1,
   1,2,2,2,2,1,1,2,2,1,1,2,2,2,2,1,
   1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
   1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
   0,1,2,2,2,1,2,2,2,2,1,2,2,2,1,0,
   0,1,2,2,2,2,1,1,1,1,2,2,2,2,1,0,
   0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,
   0,0,0,1,1,2,2,2,2,2,2,1,1,0,0,0,
   0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0
};

UBYTE   scared_data[] =
{
   0,16, 0,14,
   0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
   0,0,0,1,1,2,2,2,2,2,2,1,1,0,0,0,
   0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,
   0,1,2,2,2,1,1,2,2,1,1,2,2,2,1,0,
   0,1,2,2,1,2,2,2,2,2,2,1,2,2,1,0,
   1,2,2,2,2,1,1,2,2,1,1,2,2,2,2,1,
   1,2,2,2,2,1,1,2,2,1,1,2,2,2,2,1,
   1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
   1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
   0,1,2,2,2,2,1,1,1,1,2,2,2,2,1,0,
   0,1,2,2,2,1,1,1,1,1,1,2,2,2,1,0,
   0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,
   0,0,0,1,1,2,2,2,2,2,2,1,1,0,0,0,
   0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0
};


int main()
{
	struct IntuiMessage  *msg;
	BOOL done = FALSE;

	win = IIntuition->OpenWindowTags (NULL,
		WA_Flags,	WFLG_DEPTHGADGET | WFLG_DRAGBAR |
					WFLG_CLOSEGADGET | WFLG_SIZEGADGET,
		WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_NEWSIZE,
		WA_InnerWidth,	40,
		WA_InnerHeight,	30,
		WA_MaxWidth,-1,
		WA_MaxHeight,-1,
		WA_Activate, TRUE,
		WA_SmartRefresh, TRUE,
		WA_Title, "ReAction penmap.image Demo",
		TAG_DONE);

	if (win)
	{
        PenMapBase = IIntuition->OpenClass("images/penmap.image", 53, &PenMapClass);

		if (PenMapBase != NULL)
		{
			image_object = IIntuition->NewObject (PenMapClass, NULL,
				PENMAP_RenderData, happy_data,
				PENMAP_SelectData, scared_data,
				PENMAP_Palette, image_object_palette,
				PENMAP_Screen, win->WScreen,
				TAG_DONE);

			if (image_object)
			{
				IIntuition->SetAttrs(image_object,
					IA_Width,		win->Width - (win->BorderLeft + win->BorderRight + 10L),
					IA_Height,		win->Height - (win->BorderTop + win->BorderBottom + 10L),
					TAG_DONE);

				IIntuition->DrawImageState (win->RPort,
					(struct Image*)image_object,
					win->BorderLeft + 5L,
					win->BorderTop + 5L,
					IDS_SELECTED, NULL);

				while (!done)
				{
					IExec->WaitPort (win->UserPort);
					while (msg = (struct IntuiMessage *)IExec->GetMsg (win->UserPort))
					{
						if (msg->Class == IDCMP_CLOSEWINDOW)
							done = TRUE;
						else if (msg->Class == IDCMP_NEWSIZE)
						{
							IIntuition->SetAttrs(image_object,
								IA_Width,		win->Width - (win->BorderLeft + win->BorderRight + 10L),
								IA_Height,		win->Height - (win->BorderTop + win->BorderBottom + 10L),
								TAG_DONE);

							IGraphics->SetAPen(win->RPort,0);
							IGraphics->RectFill(win->RPort,
								win->BorderLeft,
								win->BorderTop,
								win->BorderLeft + win->Width - (win->BorderRight + win->BorderLeft + 1),
								win->BorderTop + win->Height - (win->BorderTop + win->BorderBottom + 1));

							IIntuition->DrawImageState(win->RPort,
								(struct Image*)image_object,
								win->BorderLeft + 5L,
								win->BorderTop + 5L,
								IDS_SELECTED,
								NULL);
						}
						IExec->ReplyMsg ((struct Message *)msg);
					}
				}
			}
		}
	}

	IIntuition->DisposeObject (image_object);

	if (win)
		IIntuition->CloseWindow (win);

	IIntuition->CloseClass(PenMapBase);
}
