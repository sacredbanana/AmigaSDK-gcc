/*  Chart-Demo
 *  by Ilkka Lehtoranta
 *
 *  $Id: Chart-Demo.c,v 1.2 2013/01/06 08:55:02 itix Exp $
 */

#include <libraries/mui.h>
#include <libraries/iffparse.h> /* for MAKE_ID */

#include "../../../../development/os-include/mui/Chart_mcc.h"
//#include <mui/Chart_mcc.h>

#include <proto/alib.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>
#include <proto/exec.h>
#include <proto/dos.h>

static const STRPTR used_classes[]   = { MUIC_Chart, NULL, };

#define PRECISION 1000

int main(void)
{
	APTR app, window, chart;
	ULONG rc = RETURN_FAIL;

	app = ApplicationObject,
		MUIA_Application_Title,       "ChartDemo",
		MUIA_Application_Version,     "$VER: ChartDemo 1.0 (16.7.2012)",
		MUIA_Application_Copyright,   "© 2012 Ilkka Lehtoranta",
		MUIA_Application_Author,      "Ilkka Lehtoranta",
		MUIA_Application_Description, "Demonstrates Chart.mcc.",
		MUIA_Application_Base,        "CHARTDEMO",
		MUIA_Application_UsedClasses, used_classes,

			SubWindow, window = WindowObject,
				MUIA_Window_Title,  "Chart.mcc Demo",
				MUIA_Window_ID,     MAKE_ID('C','H','A','R'),
				MUIA_Window_Width,  MUIV_Window_Width_Visible(40),
				MUIA_Window_Height, MUIV_Window_Height_Visible(40),
				WindowContents, VGroup,
					Child, chart = ChartObject,
						MUIA_Chart_Title, "Chart demo",
						MUIA_Chart_Unit, "m/s",
						MUIA_Chart_GroupSize, 3,
					End,
				End,
			End,
		End;

	if (app)
	{
		IPTR sigs = 0;
		ULONG i;

		DoMethod(window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE, app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

		for (i = 0; i < 10; i++)
		{
			DOUBLE val[3];
			TEXT buf[200];
			ULONG j;

			NewRawDoFmt("Value %c", NULL, buf, 'a' + i);

			for (j = 0; j < 3; j++)
				val[j] = (DOUBLE)RangeRand(5000);

			DoMethod(chart, MUIM_Chart_InsertGroup, MUIV_Chart_InsertGroup_Last, buf, &val);
		}

		set(window, MUIA_Window_Open, TRUE);

		while (DoMethod(app, MUIM_Application_NewInput, &sigs) != (IPTR)MUIV_Application_ReturnID_Quit)
		{
			if (sigs)
			{
				sigs = Wait(sigs | SIGBREAKF_CTRL_C);
				if (sigs & SIGBREAKF_CTRL_C) break;
			}
		}

		MUI_DisposeObject(app);
		rc = RETURN_OK;
	}
	else
	{
		Printf("Failed to create application.\n");
	}

	return rc;
}
