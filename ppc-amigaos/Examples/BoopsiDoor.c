/*
** This program needs at least V39 include files !
*/

#include "demo.h"

#include "gadgets/colorwheel.h"
#include "intuition/icclass.h"
#include "intuition/gadgetclass.h"


/*
** Gauge object macro to display colorwheels
** hue and saturation values.
*/

#define InfoGauge GaugeObject,\
	GaugeFrame    , \
	MUIA_Background  , MUII_BACKGROUND,\
	MUIA_Gauge_Max   , 16384,\
	MUIA_Gauge_Divide, 262144,\
	MUIA_Gauge_Horiz , TRUE,\
	End


int main(UNUSED int argc, UNUSED char *argv[])
{
	struct Library *ColorWheelBase;
	APTR app,window,Wheel,Hue,Sat;

	init();

	if (!(ColorWheelBase = OpenLibrary("gadgets/colorwheel.gadget",0)))
		fail(NULL,"colorwheel boopsi gadget not available\n");

	app = ApplicationObject,
		MUIA_Application_Title      , "BoopsiDoor",
		MUIA_Application_Version    , "$VER: BoopsiDoor 20.166 (07.02.2009)",
		MUIA_Application_Copyright  , "(C) 1992-2006 Stefan Stuntz, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author     , "Stefan Stuntz, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description, "Show a boopsi colorwheel with MUI.",
		MUIA_Application_Base       , "BOOPSIDOOR",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "BoopsiDoor",
			MUIA_Window_ID   , MAKE_ID('B','O','O','P'),

			WindowContents, VGroup,

				Child, ColGroup(2),
					Child, Label("Hue:"       ), Child, Hue = InfoGauge,
					Child, Label("Saturation:"), Child, Sat = InfoGauge,
					Child, RectangleObject,MUIA_Weight,0,End, Child, ScaleObject, End,
					End,

				Child, Wheel = BoopsiObject,  /* MUI and Boopsi tags mixed */

					GroupFrame,

					MUIA_Boopsi_ClassID  , "colorwheel.gadget",

					MUIA_Boopsi_MinWidth , 30, /* boopsi objects don't know */
					MUIA_Boopsi_MinHeight, 30, /* their sizes, so we help   */

					MUIA_Boopsi_Remember , WHEEL_Saturation, /* keep important values */
					MUIA_Boopsi_Remember , WHEEL_Hue,        /* during window resize  */

					MUIA_Boopsi_TagScreen, WHEEL_Screen, /* this magic fills in */
					WHEEL_Screen         , NULL,         /* the screen pointer  */

					GA_Left     , 0,
					GA_Top      , 0, /* MUI will automatically     */
					GA_Width    , 0, /* fill in the correct values */
					GA_Height   , 0,

					ICA_TARGET  , ICTARGET_IDCMP, /* needed for notification */

					WHEEL_Saturation, 0, /* start in the center */

					MUIA_FillArea, TRUE, /* use this because it defaults to FALSE
					                        for boopsi gadgets but the colorwheel
					                        doesnt bother about redrawing its backgorund */

					End,
				End,
			End,
		End;

	if (!app)
	{
		if (ColorWheelBase) CloseLibrary(ColorWheelBase);
		fail(app,"Failed to create Application.");
	}


/*
** you can react on every boopsi notification
** event as on any other MUI attribute.
*/

	DoMethod(Wheel,MUIM_Notify,WHEEL_Hue       ,MUIV_EveryTime,Hue,4,MUIM_Set,MUIA_Gauge_Current,MUIV_TriggerValue);
	DoMethod(Wheel,MUIM_Notify,WHEEL_Saturation,MUIV_EveryTime,Sat,4,MUIM_Set,MUIA_Gauge_Current,MUIV_TriggerValue);


	DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);


/*
** This is the ideal input loop for an object oriented MUI application.
** Everything is encapsulated in classes, no return ids need to be used,
** we just check if the program shall terminate.
** Note that MUIM_Application_NewInput expects sigs to contain the result
** from Wait() (or 0). This makes the input loop significantly faster.
*/

	set(window,MUIA_Window_Open,TRUE);

	{
		ULONG sigs = 0;

		while ((LONG)DoMethod(app,MUIM_Application_NewInput,&sigs) != MUIV_Application_ReturnID_Quit)
		{
			if (sigs)
			{
				sigs = Wait(sigs | SIGBREAKF_CTRL_C);
				if (sigs & SIGBREAKF_CTRL_C) break;
			}
		}
	}

	set(window,MUIA_Window_Open,FALSE);



/*
** shut down.
*/

	if (ColorWheelBase) CloseLibrary(ColorWheelBase);
	fail(app,NULL);

	// just to please the compiler
	return 0;
}
