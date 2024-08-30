/*
** godpms.c - Demonstrates how to use MONITORCLASS API.
** Build with: gcc -noixemul -o godmps godmps.c
**
** ©2012 by Jacek Piszczek of MorphOS Development Team
*/
#define INTUI_V50_NOOBSOLETE

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/dos.h>

#include <intuition/intuition.h>
#include <intuition/extensions.h>
#include <intuition/monitorclass.h>
#include <cybergraphx/cybergraphics.h>
#include <dos/dos.h>

#include <clib/alib_protos.h>
#include <stdio.h>

struct IntuitionBase *IntuitionBase;

int main(void)
{
	IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library",51);

	/* MONITORCLASS is supported since 51 */

	if (IntuitionBase)
	{

		/* 1st let's determine how many monitors we have */

		Object **monitors = GetMonitorList(NULL);

		if (monitors)
		{
			struct Screen *pubscr = NULL;
			LONG monitor = 0;

			/* now let's scan through all installed monitors and print some
			info about them */

			while (monitors[monitor])
			{
			
				DoMethod(monitors[monitor], MM_EnterPowerSaveMode);
			
				monitor++;
			}

			/* free resources */
			FreeMonitorList(monitors);

		} else {
			printf("Whoops!? No monitors installed?! We must be running out of mem.\n");
		}

	} else {
		printf("Intuition library is too old\n");
	}
	
	if (IntuitionBase) CloseLibrary((struct Library *)IntuitionBase);

	return 0;
}

