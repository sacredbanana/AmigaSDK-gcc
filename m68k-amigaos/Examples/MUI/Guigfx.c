#include "demo.h"
#if defined(MUI_INTERNAL)
#include "Guigfx_mcc.h"
#else
#include <mui/Guigfx_mcc.h>
#endif

#define SCALEMODEMASK(u, d, p, s)	(((u) ? NISMF_SCALEUP : 0) | ((d) ? NISMF_SCALEDOWN : 0) | ((p) ? NISMF_KEEPASPECT_PICTURE : 0) | ((s) ? NISMF_KEEPASPECT_SCREEN : 0))
#define TRANSMASK(m, r)				(((m) ? NITRF_MASK : 0 ) | ((r) ? NITRF_RGB : 0))

/* program-specific definitions */
#define FILENAME_DEFAULT		"MUI:Demos/boing.png"
#define FILENAME_HOTKEY			'f'
#define QUALITY_DEFAULT			MUIV_Guigfx_Quality_Low
#define QUALITY_HOTKEY			'q'
#define SCALEUP_DEFAULT			TRUE
#define SCALEUP_HOTKEY			'u'
#define SCALEDOWN_DEFAULT		TRUE
#define SCALEDOWN_HOTKEY		'd'
#define TRANSMASK_DEFAULT		TRUE
#define TRANSMASK_HOTKEY		'm'
#define TRANSCOLOR_DEFAULT		TRUE
#define TRANSCOLOR_HOTKEY		'c'
#define TRANSRGB_DEFAULT		(0x0)
#define TRANSRGB_HOTKEY			'r'
#define PICASPECT_DEFAULT		TRUE
#define PICASPECT_HOTKEY		'a'
#define SCREENASPECT_DEFAULT	FALSE
#define SCREENASPECT_HOTKEY		's'

/* globals */
Object *IM_Pic, *ST_File, *SL_Quality, *CM_ScaleUp, *CM_ScaleDown,
		*CM_TransMask, *CM_TransColor, *CM_PicAspect, *CM_ScreenAspect, *GR_Img;

/************************************************************************/
/*                             Hooks                                    */
/************************************************************************/

HOOKPROTONHNONP(TransparencyFunc, ULONG)
{
	LONG Mask, Color;

	get(CM_TransMask, MUIA_Selected, &Mask);
	get(CM_TransColor, MUIA_Selected, &Color);
	set(IM_Pic, MUIA_Guigfx_Transparency, TRANSMASK(Mask, Color));

	return 0;
}
MakeStaticHook(TransparencyHook, TransparencyFunc);

/************************************************************************/

HOOKPROTONHNONP(ScalingFunc, ULONG)
{
	LONG Up, Down, Pic, Screen;

	// the MUIM_Group_InitChange/ExitChange pair was required for Guigfx.mcc V19,
	// but is no longer required for Guigfx.mcc V21+
	// DoMethod(GR_Img, MUIM_Group_InitChange);
	get(CM_ScaleUp, MUIA_Selected, &Up);
	get(CM_ScaleDown, MUIA_Selected, &Down);
	get(CM_PicAspect, MUIA_Selected, &Pic);
	get(CM_ScreenAspect, MUIA_Selected, &Screen);
	set(IM_Pic, MUIA_Guigfx_ScaleMode, SCALEMODEMASK(Up, Down, Pic, Screen));
	// DoMethod(GR_Img, MUIM_Group_ExitChange);

	return 0;
}
MakeStaticHook(ScalingHook, ScalingFunc);

/************************************************************************/

DISPATCHER(QualityDispatcher)
{
	switch(msg->MethodID)
	{
		case OM_NEW:
		{
			return (ULONG)DoSuperNew(cl, obj,
				MUIA_Numeric_Min, MUIV_Guigfx_Quality_Low,
				MUIA_Numeric_Max, MUIV_Guigfx_Quality_Best,
				TAG_MORE, inittags(msg));
		}
		break;

		case MUIM_Numeric_Stringify:
		{
			switch(((struct MUIP_Numeric_Stringify *)msg)->value)
			{
				default:
				case MUIV_Guigfx_Quality_Low:		return (ULONG)"low";
				case MUIV_Guigfx_Quality_Medium:	return (ULONG)"medium";
				case MUIV_Guigfx_Quality_High:		return (ULONG)"high";
				case MUIV_Guigfx_Quality_Best:		return (ULONG)"best";
			}
		}
		break;

		default:
		{
			return DoSuperMethodA(cl, obj, msg);
		}
		break;
	}
}

/************************************************************************/
/*                              Code                                    */
/************************************************************************/

int main(UNUSED int argc, UNUSED char *argv[])
{
	struct MUI_CustomClass *QualityClass;
	Object *app;
	Object *window;

	init();

	if((QualityClass = MUI_CreateCustomClass(NULL, MUIC_Slider, NULL, 0, ENTRY(QualityDispatcher))) == NULL)
		fail(NULL, "Could not create quality custom class.");

	QualityClass->mcc_Class->cl_ID = (ClassID)"Guigfx/Quality";

	app = ApplicationObject,
		MUIA_Application_Title      , "Guigfx demo",
		MUIA_Application_Version    , "$VER: Guigfx 21.1 (03.09.2020)",
		MUIA_Application_Copyright  , "(C) 1999-2000 Matthias Bethke, (C) 2020 Thore Boeckelmann",
		MUIA_Application_Author     , "Matthias Bethke, Thore Boeckelmann",
		MUIA_Application_Description, "Shows off Guigfx.mcc",
		MUIA_Application_Base       , "GGxD",
		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Guigfx demo",
			MUIA_Window_ID, MAKE_ID('G','G','D','1'),
			WindowContents, VGroup,
				Child, HGroup,
					Child, ColGroup(2),
						GroupFrameT("Settings"),
						Child, KeyLabel2("File name:", FILENAME_HOTKEY),
						Child, PopaslObject,
							MUIA_Popstring_Button, ImageObject,
								ImageButtonFrame,
								MUIA_InputMode, MUIV_InputMode_RelVerify,
								MUIA_Image_Spec, MUII_PopFile,
								MUIA_Background, MUII_ButtonBack,
								MUIA_ControlChar, 'f',
								End,
							MUIA_Popstring_String, ST_File = String(FILENAME_DEFAULT, 200),
							End,

						Child, KeyLabel2("Quality:", QUALITY_HOTKEY),
						Child, SL_Quality = NewObject(QualityClass->mcc_Class, NULL,
							MUIA_Numeric_Value, QUALITY_DEFAULT,
							MUIA_ControlChar, QUALITY_HOTKEY,
							TAG_DONE),

						Child, KeyLabel2("Scale up:", SCALEUP_HOTKEY),
						Child, HGroup,
							Child, CM_ScaleUp = KeyCheckMark(SCALEUP_DEFAULT, SCALEUP_HOTKEY),
							Child, HSpace(0),
							End,

						Child, KeyLabel2("Scale down:", SCALEDOWN_HOTKEY),
						Child, HGroup,
							Child, CM_ScaleDown = KeyCheckMark(SCALEDOWN_DEFAULT, SCALEDOWN_HOTKEY),
							Child, HSpace(0),
							End,

						Child, KeyLabel1("Transparent mask:", TRANSMASK_HOTKEY),
						Child, HGroup,
							Child, CM_TransMask = KeyCheckMark(TRANSMASK_DEFAULT, TRANSMASK_HOTKEY),
							Child, HSpace(0),
							End,

						Child, KeyLabel1("Transparent color:", TRANSCOLOR_HOTKEY),
						Child, HGroup,
							Child, CM_TransColor = KeyCheckMark(TRANSCOLOR_DEFAULT, TRANSCOLOR_HOTKEY),
							Child, HSpace(0),
							End,

						Child, KeyLabel1("Keep picture aspect:", PICASPECT_HOTKEY),
						Child, HGroup,
							Child, CM_PicAspect = KeyCheckMark(PICASPECT_DEFAULT, PICASPECT_HOTKEY),
							Child, HSpace(0),
							End,

						Child, KeyLabel1("Keep screen aspect:", SCREENASPECT_HOTKEY),
						Child, HGroup,
							Child, CM_ScreenAspect = KeyCheckMark(SCREENASPECT_DEFAULT, SCREENASPECT_HOTKEY),
							Child, HSpace(0),
							End,

						Child, VSpace(0),
						Child, VSpace(0),
						End,

					Child, GR_Img = VGroup,
						TextFrame,
						Child, VSpace(0),
						Child, IM_Pic = GuigfxObject,
							MUIA_Guigfx_FileName, FILENAME_DEFAULT,
							MUIA_Guigfx_Quality, QUALITY_DEFAULT,
							MUIA_Guigfx_ScaleMode, SCALEMODEMASK(SCALEUP_DEFAULT, SCALEDOWN_DEFAULT, PICASPECT_DEFAULT, SCREENASPECT_DEFAULT),
							MUIA_Guigfx_Transparency, TRANSMASK(TRANSMASK_DEFAULT, TRANSCOLOR_DEFAULT),
							End,
						Child, VSpace(0),
						End,
					End,
				End,
			End,
		End;

	if(app == NULL)
		fail(app, "Failed to create Application.");

	// let closegadget quit app
	DoMethod(window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE, MUIV_Notify_Application,
				2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);

	// load new image if requested
	DoMethod(ST_File, MUIM_Notify, MUIA_String_Acknowledge, MUIV_EveryTime, IM_Pic,
				3, MUIM_Set, MUIA_Guigfx_FileName, MUIV_TriggerValue);

	// call a hook for transparency changes
	DoMethod(CM_TransMask, MUIM_Notify, MUIA_Selected, MUIV_EveryTime, MUIV_Notify_Self,
				2, MUIM_CallHook, &TransparencyHook);
	DoMethod(CM_TransColor, MUIM_Notify, MUIA_Selected, MUIV_EveryTime, MUIV_Notify_Self,
				2, MUIM_CallHook, &TransparencyHook);

	// call a hook for scalemode changes
	DoMethod(CM_ScaleUp, MUIM_Notify, MUIA_Selected, MUIV_EveryTime, MUIV_Notify_Self,
				2, MUIM_CallHook, &ScalingHook);
	DoMethod(CM_ScaleDown, MUIM_Notify, MUIA_Selected, MUIV_EveryTime, MUIV_Notify_Self,
				2, MUIM_CallHook, &ScalingHook);
	DoMethod(CM_PicAspect, MUIM_Notify, MUIA_Selected, MUIV_EveryTime, MUIV_Notify_Self,
				2, MUIM_CallHook, &ScalingHook);
	DoMethod(CM_ScreenAspect, MUIM_Notify, MUIA_Selected, MUIV_EveryTime, MUIV_Notify_Self,
				2, MUIM_CallHook, &ScalingHook);

	DoMethod(SL_Quality, MUIM_Notify, MUIA_Slider_Level, MUIV_EveryTime, IM_Pic,
				3, MUIM_Set, MUIA_Guigfx_Quality, MUIV_TriggerValue);

	// set pr_WindowPtr
	get(window,MUIA_Window_Window,&(((struct Process*)FindTask(NULL))->pr_WindowPtr));

	set(window, MUIA_Window_Open, TRUE);

/*
** This is the ideal input loop for an object oriented MUI application.
** Everything is encapsulated in classes, no return ids need to be used,
** we just call a single method which does all the dirty work.
*/

	DoMethod(app, MUIM_Application_Run);

	set(window, MUIA_Window_Open, FALSE);

/*
** Shut down...
*/

	MUI_DisposeObject(app);              /* dispose all objects. */
	MUI_DeleteCustomClass(QualityClass); /* delete the custom class. */
	fail(NULL, NULL);                    /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
