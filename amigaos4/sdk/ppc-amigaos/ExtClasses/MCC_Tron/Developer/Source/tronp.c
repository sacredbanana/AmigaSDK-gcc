/*

		Tron.mcc (c) Copyright 1995-96 by kmel, Klaus Melchior

		Registered MUI class, Serial Number: 0002

		tronp.c

*/




/* SMAKE */

/*** includes ***/



#ifdef __KMEL
	#include <kmel/kmel.h>
	#include <kmel/kmel_debug.h>

	#include <mui/tron_mcc.h>
#else
	#include <clib/alib_protos.h>
	#include <clib/graphics_protos.h>
	#include <clib/utility_protos.h>
	#include <clib/muimaster_protos.h>
	#include <pragmas/muimaster_pragmas.h>
	#include <libraries/mui.h>

	#if MUIMASTER_VLATEST <= 14
		#include "mui/mui33_mcc.h"
	#endif

	#include "mui/tron_mcc_private.h"

	#define DB / ## /
#endif

#define D / ## /


#define CLASS       MUIC_TronP
#define SUPERCLASSP MUIC_Mccprefs

struct DataP
{
	Object *gr_prefs;
	Object *tr_sample;
	Object *pp_player1, *pp_background, *pp_player2, *sl_speed;
};

#include "rev/Tron.mcp.rev"

#define UserLibID "$VER: " __VERS " (" __DATE ") " __VERSCR
#define VERSION __VERSION
#define REVISION __REVISION
#define MASTERVERSION 14

#define USE_PREFS_IMAGE_COLORS
#define USE_PREFS_IMAGE_BODY
#include "prefs_image.c"

#define PREFSIMAGEOBJECT prefs_image_object()
Object *prefs_image_object(void);

#include "mui/mccheader.c"


Object *prefs_image_object(void)
{
	Object *ret;

	ret = BodychunkObject,
		MUIA_FixWidth             , PREFS_IMAGE_WIDTH,
		MUIA_FixHeight            , PREFS_IMAGE_HEIGHT,
		MUIA_Bitmap_Width         , PREFS_IMAGE_WIDTH,
		MUIA_Bitmap_Height        , PREFS_IMAGE_HEIGHT,
		MUIA_Bodychunk_Depth      , PREFS_IMAGE_DEPTH,
		MUIA_Bodychunk_Body       , (UBYTE *)prefs_image_body,
		MUIA_Bodychunk_Compression, PREFS_IMAGE_COMPRESSION,
		MUIA_Bodychunk_Masking    , PREFS_IMAGE_MASKING,
		MUIA_Bitmap_SourceColors  , (ULONG *)prefs_image_colors,
		MUIA_Bitmap_Transparent   , 0,
		End;

	return(ret);
}






ULONG ASM _NewP(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
	struct DataP *data;

	if(!(obj = (Object *)DoSuperMethodA(cl, obj, msg)))
		return(0);

	DB("_NewP\n");

	/*** init data ***/
	data = INST_DATA(cl,obj);

	/*** make group ***/
	data->gr_prefs = VGroup,

		Child, MUI_MakeObject(MUIO_BarTitle, "Sample"),
		Child, data->tr_sample = TronObject,
			VirtualFrame,
			MUIA_ShortHelp, "The Tron object sample,\nreacts on preferences below.",
			End,

		Child, VSpace(8),

		Child, MUI_MakeObject(MUIO_BarTitle, "Preferences"),
		Child, VGroup,

			Child, HGroup,
				Child, FreeKeyLabel("Player 1", '1'),
				Child, data->pp_player1 = MUI_NewObject(MUIC_Poppen,
					MUIA_Window_Title, "Adjust Pen for Player 1",
					MUIA_ControlChar, '1',
					MUIA_Draggable, TRUE,
					MUIA_ShortHelp, "Color of Player 1.",
					End,

				Child, HSpace(8),

				Child, FreeKeyLabel("Background", 'b'),
				Child, data->pp_background = MUI_NewObject(MUIC_Poppen,
					MUIA_Window_Title, "Adjust Pen for Background",
					MUIA_ControlChar, 'b',
					MUIA_Draggable, TRUE,
					MUIA_ShortHelp, "Color of Background.",
					End,

				Child, HSpace(8),

				Child, FreeKeyLabel("Player 2", '2'),
				Child, data->pp_player2 = MUI_NewObject(MUIC_Poppen,
					MUIA_Window_Title, "Adjust Pen for Player 2",
					MUIA_ControlChar, '2',
					MUIA_Draggable, TRUE,
					MUIA_ShortHelp, "Color of Player 2.",
					End,
				End,

			Child, HGroup,
				Child, FreeKeyLabel("Speed", 's'),
				Child, VGroup,
					Child, VSpace(0),
					Child, data->sl_speed = KeySlider(4, 20, 0, 's'),
					Child, VSpace(0),
					MUIA_ShortHelp, "Speed of the game.",
					End,
				End,

			Child, TextObject,
				TextFrame,
				MUIA_Background, MUII_TextBack,
				MUIA_FixHeightTxt, "\n",
				MUIA_Text_Contents, MUIX_C __VSTRING "\n" __VERSCR,
				End,

			End,

		End;

	if(!data->gr_prefs)
	{
		CoerceMethod(cl, obj, OM_DISPOSE);
		return(0);
	}

	DoMethod(obj, OM_ADDMEMBER, data->gr_prefs);


	/*** Colors ***/
	DoMethod(data->pp_player1, MUIM_Notify, MUIA_Pendisplay_Spec, MUIV_EveryTime,
		data->tr_sample, 3,
		MUIM_Set, MUIA_Tron_PenSpec1, MUIV_TriggerValue);
	DoMethod(data->pp_player2, MUIM_Notify, MUIA_Pendisplay_Spec, MUIV_EveryTime,
		data->tr_sample, 3,
		MUIM_Set, MUIA_Tron_PenSpec2, MUIV_TriggerValue);
	DoMethod(data->pp_background, MUIM_Notify, MUIA_Pendisplay_Spec, MUIV_EveryTime,
		data->tr_sample, 3,
		MUIM_Set, MUIA_Tron_PenSpecB, MUIV_TriggerValue);

	/*** Speed ***/
	DoMethod(data->sl_speed, MUIM_Notify, MUIA_Slider_Level, MUIV_EveryTime,
		data->tr_sample, 3,
		MUIM_Set, MUIA_Tron_Speed, MUIV_TriggerValue);

	return((ULONG)obj);
}


ULONG ASM _DisposeP(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
	return(DoSuperMethodA(cl,obj,msg));
}


ULONG ASM _SetupP(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) struct MUIP_Setup *msg)
{
	struct DataP *data = INST_DATA(cl, obj);
	ULONG d;

	if(!(DoSuperMethodA(cl,obj,(Msg)msg)))
		return(FALSE);

	DB("SetupP\n");

	/*** Colors ***/
	get(data->pp_player1, MUIA_Pendisplay_Spec, &d);
	set(data->pp_player1, MUIA_Pendisplay_Spec, d);
	get(data->pp_player2, MUIA_Pendisplay_Spec, &d);
	set(data->pp_player2, MUIA_Pendisplay_Spec, d);
	get(data->pp_background, MUIA_Pendisplay_Spec, &d);
	set(data->pp_background, MUIA_Pendisplay_Spec, d);

	/*** Speed ***/
	get(data->sl_speed, MUIA_Slider_Level, &d);
	set(data->sl_speed, MUIA_Slider_Level, d);

	return(TRUE);
}


ULONG ASM _CleanupP(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) struct MUIP_Setup *msg)
{
//	struct DataP *data = INST_DATA(cl, obj);

	if(!(DoSuperMethodA(cl,obj,(Msg)msg)))
		return(FALSE);

	DB("CleanupP\n");

	return(TRUE);
}


ULONG ASM _ConfigToGadgets(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) struct MUIP_Settingsgroup_ConfigToGadgets *msg)
{
	struct DataP *data = INST_DATA(cl, obj);
	Object *pd_obj;
	ULONG d;

	DB("ConfigToGadgets\n");

	/*** create objects ***/
	pd_obj = MUI_NewObject(MUIC_Pendisplay, TAG_DONE);

	DB("pd_obj:%08lx\n", pd_obj);

	/*** set colors ***/
	if(d = DoMethod(msg->configdata, MUIM_Dataspace_Find, MUICFG_Tron_Pen1))
	{
		DB("Color1: '%s'\n", (char *)d);
		set(data->pp_player1, MUIA_Pendisplay_Spec, d);
	}
	else
	{
		if(pd_obj)
		{
			struct MUI_PenSpec *pen;

			DoMethod(pd_obj, MUIM_Pendisplay_SetMUIPen, DEFAULT_PEN1);
			get(pd_obj, MUIA_Pendisplay_Spec, &pen);
			set(data->pp_player1, MUIA_Pendisplay_Spec, pen);

			DB("pen:'%s'\n", pen);
		}
	}

	if(d = DoMethod(msg->configdata, MUIM_Dataspace_Find, MUICFG_Tron_Pen2))
	{
		DB("Color2: '%s'\n", (char *)d);
		set(data->pp_player2, MUIA_Pendisplay_Spec, d);
	}
	else
	{
		if(pd_obj)
		{
			struct MUI_PenSpec *pen;

			DoMethod(pd_obj, MUIM_Pendisplay_SetMUIPen, DEFAULT_PEN2);
			get(pd_obj, MUIA_Pendisplay_Spec, &pen);
			set(data->pp_player2, MUIA_Pendisplay_Spec, pen);
		}
	}

	if(d = DoMethod(msg->configdata, MUIM_Dataspace_Find, MUICFG_Tron_PenB))
	{
		DB("ColorB: '%s'\n", (char *)d);
		set(data->pp_background, MUIA_Pendisplay_Spec, d);
	}
	else
	{
		if(pd_obj)
		{
			struct MUI_PenSpec *pen;

			DoMethod(pd_obj, MUIM_Pendisplay_SetMUIPen, DEFAULT_PENB);
			get(pd_obj, MUIA_Pendisplay_Spec, &pen);
			set(data->pp_background, MUIA_Pendisplay_Spec, pen);
		}
	}

	/*** set speed ***/
	if(d = DoMethod(msg->configdata, MUIM_Dataspace_Find, MUICFG_Tron_Speed))
		set(data->sl_speed, MUIA_Slider_Level, *(ULONG *)d);
	else
		set(data->sl_speed, MUIA_Slider_Level, DEFAULT_SPEED);

	/*** dispose created objects ***/
	if(pd_obj)
		MUI_DisposeObject(pd_obj);

	return(0);
}


ULONG ASM _GadgetsToConfig(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) struct MUIP_Settingsgroup_GadgetsToConfig *msg)
{
	struct DataP *data = INST_DATA(cl, obj);
	ULONG d;

	DB("GadgetsToConfig\n");

	/*** Colors ***/
	get(data->pp_player1, MUIA_Pendisplay_Spec, &d);
	if(d)
		DoMethod(msg->configdata, MUIM_Dataspace_Add, d, sizeof(struct MUI_PenSpec), MUICFG_Tron_Pen1);
	DB("Color1: '%s'\n", (char *)d);
	get(data->pp_player2, MUIA_Pendisplay_Spec, &d);
	if(d)
		DoMethod(msg->configdata, MUIM_Dataspace_Add, d, sizeof(struct MUI_PenSpec), MUICFG_Tron_Pen2);
	DB("Color2: '%s'\n", (char *)d);
	get(data->pp_background, MUIA_Pendisplay_Spec, &d);
	if(d)
		DoMethod(msg->configdata, MUIM_Dataspace_Add, d, sizeof(struct MUI_PenSpec), MUICFG_Tron_PenB);
	DB("ColorB: '%s'\n", (char *)d);

	/*** Speed ***/
	get(data->sl_speed, MUIA_Slider_Level, &d);
	DoMethod(msg->configdata, MUIM_Dataspace_Add, &d, 4, MUICFG_Tron_Speed);
	DB("Speed: %ld\n", d);

	return(0);
}


ULONG ASM _HandleInputP(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) struct MUIP_HandleInput *msg)
{
//	struct DataP *data = INST_DATA(cl, obj);

	if(msg->imsg)
	{
		switch(msg->imsg->Class)
		{
			case IDCMP_INTUITICKS:
			{
			}
			break;
		}
	}

	return(DoSuperMethodA(cl,obj,(Msg)msg));
}

ULONG ASM SAVEDS _DispatcherP(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
	switch(msg->MethodID)
	{
		case OM_NEW                       : return(_NewP           (cl,obj,(APTR)msg));
		case OM_DISPOSE                   : return(_DisposeP       (cl,obj,(APTR)msg));
		case MUIM_Setup                   : return(_SetupP         (cl,obj,(APTR)msg));
		case MUIM_Cleanup                 : return(_CleanupP       (cl,obj,(APTR)msg));

		case MUIM_Settingsgroup_ConfigToGadgets: return(_ConfigToGadgets(cl,obj,(APTR)msg));
		case MUIM_Settingsgroup_GadgetsToConfig: return(_GadgetsToConfig(cl,obj,(APTR)msg));

		case MUIM_HandleInput             : return(_HandleInputP   (cl,obj,(APTR)msg));
	}

	return(DoSuperMethodA(cl,obj,msg));
}
