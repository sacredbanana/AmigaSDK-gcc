/*

		Tron.mcc (c) Copyright 1995-96 by kmel, Klaus Melchior

		Example for Tron.mcc

		tron-demo.c

*/

/* SMAKE */


#ifdef __KMEL
	#include <kmel/kmel.h>
	#include <kmel/kmel_debug.h>

	#include <mui/tron_mcc.h>

	#include "rev/Tron-Demo.rev"

	extern char *vers_string;
#else
	#include <clib/alib_protos.h>
	#include <clib/exec_protos.h>
	#include <clib/graphics_protos.h>
	#include <clib/utility_protos.h>
	#include <clib/muimaster_protos.h>
	#include <pragmas/muimaster_pragmas.h>
	#include <libraries/mui.h>
	#include <stdio.h>

	#include "mui/tron_mcc.h"
	#include "rev/Tron-Demo.rev"

	#define DB / ## /
	#define MAKE_ID(a,b,c,d) ((ULONG) (a)<<24 | (ULONG) (b)<<16 | (ULONG) (c)<<8 | (ULONG) (d))

	char *vers_string  = __VSTRING;
	char *vers_tag = __VERSTAG;
#endif

/*** externals ***/
extern struct Library *SysBase;

/*** main ***/
int main(int argc,char *argv[])
{
	struct Library *IntuitionBase;
	int ret=RETURN_ERROR;

	if(IntuitionBase = OpenLibrary("intuition.library", 36))
	{
		struct Library *MUIMasterBase;

		if(MUIMasterBase = OpenLibrary(MUIMASTER_NAME, 13))
		{
			APTR app;
			APTR window;
			APTR tr_game, bt_start, bt_stop;

			ULONG signals;
			BOOL running = TRUE;

			app = ApplicationObject,
				MUIA_Application_Title      , "Tron-Demo",
				MUIA_Application_Version    , vers_string,
				MUIA_Application_Copyright  , __VERSCR,
				MUIA_Application_Author     , "Klaus Melchior",
				MUIA_Application_Description, "Demonstrates the Tron class.",
				MUIA_Application_Base       , "TRONDEMO",

				SubWindow, window = WindowObject,
					MUIA_Window_Title, "TronClass",
					MUIA_Window_ID   , MAKE_ID('T','R','O','N'),
					MUIA_Window_Width, 240,
					WindowContents, VGroup,

						/*** create a Tron game ***/
						Child, tr_game = TronObject,
							GaugeFrame,
							End,

						Child, HGroup,
							Child, bt_start = KeyButton("Start", 'a'),
							Child, bt_stop = KeyButton("Stop", 's'),
							End,

						End,

					End,
				End;

			if(app)
			{
				/*** generate notifies ***/
				DoMethod(window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE,
					app, 2,
					MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

				DoMethod(bt_start, MUIM_Notify, MUIA_Timer, MUIV_EveryTime,
					tr_game, 3,
					MUIM_Set, MUIA_Tron_Running, TRUE);
				DoMethod(bt_stop, MUIM_Notify, MUIA_Timer, MUIV_EveryTime,
					tr_game, 3,
					MUIM_Set, MUIA_Tron_Running, FALSE);

				/*** ready to open the window ... ***/
				set(window,MUIA_Window_Open,TRUE);

				set(tr_game, MUIA_Tron_Running, TRUE);

				while (running)
				{
					switch(DoMethod(app,MUIM_Application_Input,&signals))
					{
						case MUIV_Application_ReturnID_Quit:
							running = FALSE;
							break;
					}

					if(running && signals)
						Wait(signals);
				}

				set(tr_game, MUIA_Tron_Running, FALSE);

				set(window, MUIA_Window_Open, FALSE);

				/*** shutdown ***/
				MUI_DisposeObject(app);      /* dispose all objects. */

				ret = RETURN_OK;
			}
			else
			{
				puts("Could not open application!");
				ret = RETURN_FAIL;
			}

			CloseLibrary(MUIMasterBase);
		}
		else
		{
			puts("Could not open muimaster.library v13!");
			ret = RETURN_FAIL;
		}

		CloseLibrary(IntuitionBase);
	}
	else
	{
		puts("Could not open intuition.library v36!");
		ret = RETURN_FAIL;
	}

	return(ret);
}

