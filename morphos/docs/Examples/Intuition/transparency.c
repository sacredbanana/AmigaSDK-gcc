/*
** transparency.c - Demonstrates how to use transparency API.
** Build with: gcc -noixemul -o transparency transparency.c
**
** This code requires V50 intuition and ilustrates transparent hooks usage.
**
** ©2003-2008 by Jacek Piszczek of MorphOS Development Team
*/

#define INTUI_V50_NOOBSOLETE

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>

#include <utility/hooks.h>
#include <intuition/intuition.h>
#include <intuition/imageclass.h>
#include <intuition/gadgetclass.h>
#include <intuition/extensions.h>
#include <intuition/screens.h>

struct IntuitionBase *IntuitionBase = NULL;
struct GfxBase *GfxBase = NULL;

extern ULONG HookEntry();
struct Hook transphook;

void MyTranspHook(struct Hook *hook,struct Window *window,struct TransparencyMessage *msg);
BOOL ismouseonborder(struct Window *window);

int main(void)
{
	if ((IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library",50)) &&
	    (GfxBase = (struct GfxBase *)OpenLibrary("graphics.library",39)))
	{
		struct Window *window = NULL;
		struct Screen *screen = LockPubScreen(NULL);
		BOOL working = TRUE;

		if (!screen) goto fail;

		transphook.h_Entry = HookEntry;
		transphook.h_SubEntry = (APTR)MyTranspHook;

		window = OpenWindowTags(0,WA_PubScreen,screen,
		                  WA_Title,"transparency.c",
		                  WA_Width,200,
		                  WA_Height,200,
		                  WA_Left,screen->Width/2 - 100,
		                  WA_Top,screen->Height/2 - 100,
		                  WA_MaxWidth,-1,
		                  WA_MaxHeight,-1,
		                  WA_Flags,WFLG_SIZEGADGET|
		                           WFLG_CLOSEGADGET|
		                           WFLG_DEPTHGADGET|
		                           WFLG_REPORTMOUSE|
		                           WFLG_DRAGBAR,
		                  WA_IDCMP,IDCMP_CLOSEWINDOW|
		                           IDCMP_MOUSEMOVE|
		                           IDCMP_INACTIVEWINDOW|
		                           IDCMP_ACTIVEWINDOW|
		                           IDCMP_REFRESHWINDOW,
		                  WA_SimpleRefresh,TRUE,
		                  WA_Activate,TRUE,
		                  WA_SkinInfo,0,
		                  WA_TransparentRegionHook,&transphook,
		                  TAG_DONE);

		if (!window) goto fail;

		SetAPen(window->RPort,1);
		RectFill(window->RPort,window->BorderLeft,window->BorderTop,window->Width - 1 - window->BorderRight,window->Height - 1 - window->BorderBottom);

		while (working)
		{
			struct IntuiMessage *imsg;
			BOOL mouseonborder = ismouseonborder(window);

			WaitPort(window->UserPort);

			while ((imsg = (struct IntuiMessage *)GetMsg(window->UserPort)))
			{
				switch (imsg->Class)
				{
					case IDCMP_MOUSEMOVE:
						{
							BOOL mouse = ismouseonborder(window);

							if (mouse != mouseonborder)
							{
								TransparencyControl(window,TRANSPCONTROLMETHOD_UPDATETRANSPARENCY,NULL);
							}

							mouseonborder = mouse;
						}
						break;

					case IDCMP_ACTIVEWINDOW:
					case IDCMP_INACTIVEWINDOW:
						TransparencyControl(window,TRANSPCONTROLMETHOD_UPDATETRANSPARENCY,NULL);
						break;

					case IDCMP_CLOSEWINDOW:
						working = FALSE;
						break;

					case IDCMP_REFRESHWINDOW:
						BeginRefresh(window);
						RectFill(window->RPort,window->BorderLeft,window->BorderTop,window->Width - 1 - window->BorderRight,window->Height - 1 - window->BorderBottom);
						EndRefresh(window,TRUE);
						break;
				}

				ReplyMsg((struct Message *)imsg);
			}
		}

fail:
		if (window)
		{
			struct TagItem tags[] =
			{
				{TRANSPCONTROL_REGIONHOOK,0},
				{TAG_DONE}
			};

			TransparencyControl(window,TRANSPCONTROLMETHOD_INSTALLREGIONHOOK,tags);
			CloseWindow(window);
		}

		if (screen) UnlockPubScreen(NULL,screen);
	}

	if (GfxBase)
		CloseLibrary((struct Library *)GfxBase);

	if (IntuitionBase)
		CloseLibrary((struct Library *)IntuitionBase);

	return 0;
}

void MyTranspHook(struct Hook *hook,struct Window *window,struct TransparencyMessage *msg)
{
	struct Rectangle rect;

	/* use transp only when window is active */
	if (!(window->Flags & WFLG_WINDOWACTIVE)) return;

	/* use transp only when pointer NOT on border */
	if (ismouseonborder(window)) return;

	/* make top border transparent */
	rect.MinX = 0;
	rect.MinY = 0;
	rect.MaxX = window->Width - 1;
	rect.MaxY = window->BorderTop;

	OrRectRegion(msg->Region,&rect);

	/* left border */
	rect.MinX = 0;
	rect.MinY = window->BorderTop;
	rect.MaxX = window->BorderLeft - 1;
	rect.MaxY = window->Height - window->BorderBottom - 1;

	OrRectRegion(msg->Region,&rect);

	/* right border */
	rect.MinX = window->Width - window->BorderRight;
	rect.MinY = window->BorderTop;
	rect.MaxX = window->Width - 1;
	rect.MaxY = window->Height - window->BorderBottom - 1;

	OrRectRegion(msg->Region,&rect);

	/* bottom border */
	rect.MinX = 0;
	rect.MinY = window->Height - window->BorderBottom;
	rect.MaxX = window->Width - 1;
	rect.MaxY = window->Height - 1;

	OrRectRegion(msg->Region,&rect);
}

BOOL ismouseonborder(struct Window *window)
{
	if (window->MouseX < 0 || window->MouseY < 0 || window->MouseX > window->Width - 1 || window->MouseY > window->Height - 1) return FALSE;

	if (window->MouseY > 0 && window->MouseY < window->BorderTop) return TRUE;
	if (window->MouseY > window->Height - window->BorderBottom - 1 && window->MouseY < window->Height) return TRUE;

	if (window->MouseX > 0 && window->MouseX < window->BorderLeft) return TRUE;
	if (window->MouseX > window->Width - window->BorderRight - 1 && window->MouseX < window->Width) return TRUE;

	return FALSE;
}

