/*
** alphatest.c - Demonstrates how to use alpha transparency API.
** Build with: gcc -noixemul -o alphatest alphatest.c
**
** ©2008 by Jacek Piszczek of MorphOS Development Team
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
#include <dos/dos.h>
#include <graphics/rpattr.h>

#include <stdio.h>

struct IntuitionBase *IntuitionBase = NULL;

void DrawWindowContent(struct Window *win);

int main(void)
{
	/* intuition v51 + required */
	if ((IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library",51)) != NULL)
	{
		struct Window *win = NULL;
		struct Screen *scr = LockPubScreen(NULL);

		if (scr != NULL)
		{
			ULONG acceleration = SASA_SourceAlphaSupport_None;

			/* since v51, screens, windows, idcmp messages are all BOOPSI objects */
			GetAttr(SA_SourceAlphaSupport,scr,&acceleration);

			if (acceleration == SASA_SourceAlphaSupport_None)
			{
				printf("Sorry, alpha opacity not supported on this screen!\n");
			}

			if (acceleration == SASA_SourceAlphaSupport_CPU)
			{
				printf("Alpha opacity done with the CPU, may be very slow!\n");
			}

			if (acceleration == SASA_SourceAlphaSupport_HW)
			{
				printf("Cool, we have hardware accelerated alpha opacity!\n");
			}

			/* do not bother opening the window if opacity isn't supported at all.. */
			if (acceleration != SASA_SourceAlphaSupport_None)
			{
				win = OpenWindowTags(NULL,
						WA_Left,100, WA_Top, 100, WA_Width, 100, WA_Height, 100,
						WA_IDCMP, IDCMP_REFRESHWINDOW | IDCMP_ACTIVEWINDOW | IDCMP_INACTIVEWINDOW,
						WA_Borderless, TRUE, WA_SimpleRefresh, TRUE, WA_Activate, TRUE,
						/* we want this window to use alpha opacity ! */
						WA_HasAlpha,TRUE,
						/* hitlevel makes the window hitable depending on the given alpha value */
						WA_HitLevel,128,
						/* borderless windows don't get any shadows, but let's force them for us
						** do note that the currently selected skin needs to provide shadows! */
						WA_ShadowTop,TRUE, WA_ShadowBottom, TRUE, WA_ShadowLeft,TRUE, WA_ShadowRight, TRUE,
						/* let's use a non-std pointer... */
						WA_PointerType,POINTERTYPE_AIMING,
						TAG_DONE);

				if (win != NULL)
				{
					struct IntuiMessage *imsg;

					DrawWindowContent(win);

					printf("The window is filled with black color, but the alpha opacity differs\n"
						   "for each vertical line. You may easily see how WA_HitLevel works now.\n\n"
						   "Press ctrl-c to abort.\n");

					for (;;)
					{
						ULONG sigs = Wait(SIGBREAKF_CTRL_C|(1L << win->UserPort->mp_SigBit));

						if (sigs & (1L << win->UserPort->mp_SigBit))
						{
							while ((imsg = (struct IntuiMessage *)GetMsg(win->UserPort)))
							{
								switch (imsg->Class)
								{
									case IDCMP_REFRESHWINDOW:
										BeginRefresh(win);
										DrawWindowContent(win);
										EndRefresh(win,TRUE);
										break;

									case IDCMP_ACTIVEWINDOW:
										printf("Window is now active\n");
										break;

									case IDCMP_INACTIVEWINDOW:
										printf("Window no longer active\n");
										break;
								}
							}
						}

						if (sigs & SIGBREAKF_CTRL_C)
						{
							printf("Terminating...\n");
							break;
						}
					}

					CloseWindow(win);
				}
			}

			UnlockPubScreen(NULL,scr);
		}

		CloseLibrary((struct Library *)IntuitionBase);
	}

	return 0;
}

void DrawWindowContent(struct Window *win)
{
	if (win != NULL)
	{
		LONG w = 0,h = 0;
		LONG cx;

		/* windows are BOOPSI objects... */
		GetAttr(WA_Width,win,&w);
		GetAttr(WA_Height,win,&h);

		/* let's draw a nice pattern... */
		for (cx = 0; cx < w; cx++)
		{
			SetRPAttrs(win->RPort,RPTAG_PenMode,FALSE,RPTAG_FgColor,((255 * cx) / 100) << 24,TAG_DONE);
			RectFill(win->RPort,cx,0,cx,h - 1);
		}
	}
}

