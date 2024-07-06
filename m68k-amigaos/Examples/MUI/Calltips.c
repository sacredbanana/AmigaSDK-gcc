#include "demo.h"
#if defined(MUI_INTERNAL)
#include "Calltips_mcc.h"
#else
#include <mui/Calltips_mcc.h>
#endif

/*
A simple demo application to show some new features of MUI 5.0.
*/

static const char *globalSuggestions[] =
{
	"Aboutmui.c",
	"Aboutpage.c",
	"AllocVecPooled.c",
	"Application.c",
	"Applist.c",
	"Area.c",
	"Argstring.c",
	"Backgroundadjust.c",
	"Balance.c",
	"Bitfield.c",
	"Bitmap.c",
	"Bodychunk.c",
	"Boopsi.c",
	"Cclist.c",
	"classheader.c",
	"Coloradjust.c",
	"Colorfield.c",
	"Colorring.c",
	"Configdata.c",
	"CopyStringBSTRToC.c",
	"Cycle.c",
	"Datamap.c",
	"Dataspace.c",
	"debug.c",
	"Dirlist.c",
	"DrawGradient.c",
	"Dtpic.c",
	"Family.c",
	"Filepanel.c",
	"Floattext.c",
	"flushimagespace.c",
	"flushmui.c",
	"Fontdisplay.c",
	"Fontpanel.c",
	"Frameadjust.c",
	"Framedisplay.c",
	"FreeVecPooled.c",
	"Frimagedisplay.c",
	"Gadget.c",
	"Gauge.c",
	"GetHead.c",
	"GetPred.c",
	"GetSucc.c",
	"GetTail.c",
	"Group.c",
	"HashTable.c",
	"idea.c",
	"Imagebrowser.c",
	"Image.c",
	"Imagedisplay.c",
	"Imagespace.c",
	"Keyadjust.c",
	"Knob.c",
	"Levelmeter.c",
	"libheader.c",
	"libmui.c",
	"libstart.c",
	"List.c",
	"Listview.c",
	"locale.c",
	"magickey.c",
	"masterbubble.c",
	"masterclass.c",
	"masterconfig.c",
	"masterdata.c",
	"masterframe.c",
	"mastergfx.c",
	"masterinit.c",
	"mastermisc.c",
	"masterobj.c",
	"masterpop.c",
	"masterreq.c",
	"masterrexx.c",
	"masterstubs.c",
	"mastertext.c",
	"Mccprefs.c",
	"Menu.c",
	"Menudisplay.c",
	"Menuitem.c",
	"Menustrip.c",
	"MoveList.c",
	"muiasl.c",
	"muigfx.c",
	"Notify.c",
	"Numericbutton.c",
	"Numeric.c",
	"Objectmap.c",
	"Palette.c",
	"Panel.c",
	"patchasl.c",
	"PeekMsg.c",
	"Penadjust.c",
	"Pendisplay.c",
	"Pixmap.c",
	"pointers.c",
	"Popasl.c",
	"popcommon.c",
	"Popframe.c",
	"Popfrimage.c",
	"Popimage.c",
	"Poplist.c",
	"Popmenu.c",
	"Popobject.c",
	"Poppen.c",
	"Popscreen.c",
	"Popstring.c",
	"prefs.c",
	"Process.c",
	"ProcessPixelArray.c",
	"profile.c",
	"Prop.c",
	"psi.c",
	"Pubscreenadjust.c",
	"Pubscreen.c",
	"Pubscreenlist.c",
	"Pubscreenpanel.c",
	"Radio.c",
	"Rectangle.c",
	"Register.c",
	"Rootgrp.c",
	"Scale.c",
	"Screenmodepanel.c",
	"Screenspace.c",
	"Scrollbar.c",
	"Scrollgroup.c",
	"Selectgroup.c",
	"Semaphore.c",
	"Settings.c",
	"Settingsgroup.c",
	"Slave.c",
	"Slider.c",
	"String.c",
	"StripIntuiMessages.c",
	"Text.c",
	"Textdata.c",
	"Title.c",
	"VASPrintf.c",
	"vastubs.c",
	"Virtgroup.c",
	"Volumelist.c",
	"Winborder.c",
	"Window.c",
	NULL,
};

struct MUI_CustomClass *tips_mcc;
struct MUI_CustomClass *source_mcc;

/* ------------------------------------------------------------------------- */

#define MUIM_Tips_UpdateSuggestions		(TAG_USER|0x0001)
#define MUIM_Tips_UseSuggestion			(TAG_USER|0x0002)

struct MUIP_Tips_UpdateSuggestions
{
	ULONG MethodID;
	const char **suggestions;
};

struct MUIP_Tips_UseSuggestion
{
	ULONG MethodID;
	LONG active;
	ULONG close;
};

#define MUIA_Tips_Suggestions			(TAG_USER|0x0001)

/* ------------------------------------------------------------------------- */

#define MUIM_Source_ShowTips			(TAG_USER|0x1001)
#define MUIM_Source_HideTips			(TAG_USER|0x1002)
#define MUIM_Source_Suggest				(TAG_USER|0x1003)

struct MUIP_Source_ShowTips
{
	ULONG MethodID;
	const char **suggestions;
};

struct MUIP_Source_Suggest
{
	ULONG MethodID;
	const char *contents;
};

/* ------------------------------------------------------------------------- */

struct TipsData
{
	Object *suggestList;
	Object *source;
};

static ULONG m_Tips_NEW(struct IClass *cl, Object *obj, Msg msg)
{
	Object *suggestList;

	if((obj = DoSuperNew(cl, obj,
		WindowContents, VGroup,
			Child, suggestList = ListObject,
				MUIA_Frame, MUIV_Frame_InputList,
				MUIA_List_ConstructHook, MUIV_List_ConstructHook_String,
				MUIA_List_DestructHook, MUIV_List_DestructHook_String,
				MUIA_List_SourceArray, GetTagData(MUIA_Tips_Suggestions, (ULONG)NULL, inittags(msg)),
				End,
			End,
		TAG_MORE, inittags(msg))) != NULL)
	{
		struct TipsData *data = INST_DATA(cl, obj);

		data->suggestList = suggestList;
		data->source = (Object *)GetTagData(MUIA_Calltips_Source, (ULONG)NULL, inittags(msg));

		DoMethod(suggestList, MUIM_Notify, MUIA_List_Active, MUIV_EveryTime, obj, 3, MUIM_Tips_UseSuggestion, MUIV_TriggerValue, FALSE);
		DoMethod(suggestList, MUIM_Notify, MUIA_List_DoubleClick, MUIV_EveryTime, obj, 3, MUIM_Tips_UseSuggestion, -1, TRUE);
	}

	return (ULONG)obj;
}

static ULONG m_Tips_SET(struct IClass *cl, Object *obj, Msg msg)
{
	struct TipsData *data = INST_DATA(cl, obj);

	ForTagItems(inittags(msg))
	{
		switch(tag->ti_Tag)
		{
			case MUIA_List_Active:
			{
				// forward the attribute to the suggestion list
				set(data->suggestList, MUIA_List_Active, tag->ti_Data);
				// let the superclass ignore this attribute
				tag->ti_Tag = TAG_IGNORE;
			}
			break;
		}
	}
	NextTagItems

	return DoSuperMethodA(cl, obj, msg);
}

static ULONG m_Tips_UpdateSuggestions(struct IClass *cl, Object *obj, struct MUIP_Tips_UpdateSuggestions *msg)
{
	struct TipsData *data = INST_DATA(cl, obj);

	// rebuild the list of collected suggestions
	set(data->suggestList, MUIA_List_Quiet, TRUE);
	DoMethod(data->suggestList, MUIM_List_Clear);
	if(msg->suggestions != NULL)
		DoMethod(data->suggestList, MUIM_List_Insert, msg->suggestions, -1, MUIV_List_Insert_Bottom);
	set(data->suggestList, MUIA_List_Quiet, FALSE);

	return 0;
}

static ULONG m_Tips_UseSuggestion(struct IClass *cl, Object *obj, struct MUIP_Tips_UseSuggestion *msg)
{
	struct TipsData *data = INST_DATA(cl, obj);
	char *value;

	if(msg->active == -1)
		get(data->suggestList, MUIA_List_Active, &msg->active);

	if((value = (char *)DoMethod(data->suggestList, MUIM_List_GetEntry, msg->active, NULL)) != NULL)
		nnset(data->source, MUIA_String_Contents, value);

	if(msg->close == TRUE)
		DoMethod(_app(obj), MUIM_Application_PushMethod, data->source, 1, MUIM_Source_HideTips);

	return 0;
}

DISPATCHER(Tips_Dispatcher)
{
	switch(msg->MethodID)
	{
		case OM_NEW							: return m_Tips_NEW(cl, obj, (APTR)msg);
		case OM_SET							: return m_Tips_SET(cl, obj, (APTR)msg);
		case MUIM_Tips_UpdateSuggestions	: return m_Tips_UpdateSuggestions(cl, obj, (APTR)msg);
		case MUIM_Tips_UseSuggestion		: return m_Tips_UseSuggestion(cl, obj, (APTR)msg);
	}

	return DoSuperMethodA(cl, obj, msg);
}

struct SourceData
{
	Object *calltips;
	struct MUI_EventHandlerNode ehn;
};

static ULONG m_Source_NEW(struct IClass *cl, Object *obj, Msg msg)
{
	if((obj = DoSuperNew(cl, obj,
		MUIA_Frame, MUIV_Frame_String,
		MUIA_String_MaxLen, 100,
		TAG_MORE, inittags(msg))) != NULL)
	{
		struct SourceData *data = INST_DATA(cl, obj);

		data->ehn.ehn_Events = IDCMP_CHANGEWINDOW|IDCMP_RAWKEY;
		data->ehn.ehn_Priority = -5;
		data->ehn.ehn_Flags = MUI_EHF_GUIMODE;
		data->ehn.ehn_Object = obj;
		data->ehn.ehn_Class = cl;

		DoMethod(obj, MUIM_Notify, MUIA_String_Contents, MUIV_EveryTime, MUIV_Notify_Self, 2, MUIM_Source_Suggest, MUIV_TriggerValue);
		DoMethod(obj, MUIM_Notify, MUIA_String_Acknowledge, MUIV_EveryTime, MUIV_Notify_Self, 1, MUIM_Source_HideTips);
	}

	return (ULONG)obj;
}

static ULONG m_Source_DISPOSE(struct IClass *cl, Object *obj, Msg msg)
{
	struct SourceData *data = INST_DATA(cl, obj);

	// hide and dispose the Calltips object if it still exists
	if(data->calltips != NULL)
		DoMethod(obj, MUIM_Source_HideTips);

	return DoSuperMethodA(cl, obj, msg);
}

static ULONG m_Source_Setup(struct IClass *cl, Object *obj, Msg msg)
{
	struct SourceData *data = INST_DATA(cl, obj);
	ULONG rc = DoSuperMethodA(cl, obj, msg);

	if(rc)
	{
		DoMethod(_win(obj), MUIM_Window_AddEventHandler, &data->ehn);

		// forward the method to the Calltips object
		if(data->calltips != NULL)
			DoMethod(data->calltips, MUIM_Calltips_ParentSetup);
	}

	return rc;
}

static ULONG m_Source_Cleanup(struct IClass *cl, Object *obj, Msg msg)
{
	struct SourceData *data = INST_DATA(cl, obj);

	// forward the method to the Calltips object
	if(data->calltips != NULL)
		DoMethod(data->calltips, MUIM_Calltips_ParentCleanup);

	DoMethod(_win(obj), MUIM_Window_RemEventHandler, &data->ehn);

	return DoSuperMethodA(cl, obj, msg);
}

static ULONG m_Source_Show(struct IClass *cl, Object *obj, Msg msg)
{
	struct SourceData *data = INST_DATA(cl, obj);
	ULONG rc = DoSuperMethodA(cl, obj, msg);

	// forward the method to the Calltips object
	if(data->calltips != NULL)
		DoMethod(data->calltips, MUIM_Calltips_ParentShow);

	return rc;
}

static ULONG m_Source_Hide(struct IClass *cl, Object *obj, Msg msg)
{
	struct SourceData *data = INST_DATA(cl, obj);

	// forward the method to the Calltips object
	if(data->calltips != NULL)
		DoMethod(data->calltips, MUIM_Calltips_ParentHide);

	return DoSuperMethodA(cl, obj, msg);
}

static ULONG m_Source_HandleEvent(struct IClass *cl, Object *obj, struct MUIP_HandleEvent *msg)
{
	struct SourceData *data = INST_DATA(cl, obj);
	ULONG rc = 0;

	if(msg->muikey != MUIKEY_NONE)
	{
		// forward up/down cursor movements to the suggestion list
		switch(msg->muikey)
		{
			case MUIKEY_UP:
			{
				if(data->calltips != NULL)
					set(data->calltips, MUIA_List_Active, MUIV_List_Active_Up);
				rc = MUI_EventHandlerRC_Eat;
			}
			break;

			case MUIKEY_DOWN:
			{
				if(data->calltips != NULL)
					set(data->calltips, MUIA_List_Active, MUIV_List_Active_Down);
				rc = MUI_EventHandlerRC_Eat;
			}
			break;
		}
	}

	if(msg->imsg != NULL)
	{
		switch(msg->imsg->Class)
		{
			case IDCMP_CHANGEWINDOW:
			{
				// forward the method to the Calltips object
				if(data->calltips != NULL)
					DoMethod(data->calltips, MUIM_Calltips_ParentWindowArranged);
			}
			break;
		}
	}

	return rc;
}

static ULONG m_Source_ShowTips(struct IClass *cl, Object *obj, struct MUIP_Source_ShowTips *msg)
{
	struct SourceData *data = INST_DATA(cl, obj);

	// create a new Calltips object if it doesn't exist yet
	if(data->calltips == NULL)
	{
		struct Rect32 rect;

		rect.MinX = _left(obj);
		rect.MinY = _bottom(obj)+1;
		rect.MaxX = _right(obj);
		rect.MaxY = _bottom(obj)+1+100;

		if((data->calltips = NewObject(tips_mcc->mcc_Class, NULL,
			MUIA_Calltips_Source, obj,
			MUIA_Calltips_Rectangle, &rect,
			MUIA_Tips_Suggestions, msg->suggestions,
			TAG_DONE)) != NULL)
		{
			DoMethod(_app(obj), OM_ADDMEMBER, data->calltips);
			set(data->calltips, MUIA_Window_Open, TRUE);
		}
	}
	else
	{
		// update the suggestions in the Calltips object
		DoMethod(data->calltips, MUIM_Tips_UpdateSuggestions, msg->suggestions);
	}

	return 0;
}

static ULONG m_Source_HideTips(struct IClass *cl, Object *obj, UNUSED Msg msg)
{
	struct SourceData *data = INST_DATA(cl, obj);

	if(data->calltips != NULL)
	{
		set(data->calltips, MUIA_Window_Open, FALSE);
		DoMethod(_app(obj), OM_REMMEMBER, data->calltips);
		MUI_DisposeObject(data->calltips);
		data->calltips = NULL;
	}

	return 0;
}

static ULONG m_Source_Suggest(UNUSED struct IClass *cl, Object *obj, struct MUIP_Source_Suggest *msg)
{
	if(msg->contents != NULL && msg->contents[0] != '\0')
	{
		LONG i;
		LONG matches;
		const char **suggestions;

		// find matches in the list of suggestions
		matches = 0;
		for(i = 0; globalSuggestions[i] != NULL; i++)
		{
			if(strncasecmp(globalSuggestions[i], msg->contents, strlen(msg->contents)) == 0)
				matches++;
		}

		if(matches != 0 && (suggestions = calloc(matches+1, sizeof(char *))) != NULL)
		{
			matches = 0;
			for(i = 0; globalSuggestions[i] != NULL; i++)
			{
				if(strncasecmp(globalSuggestions[i], msg->contents, strlen(msg->contents)) == 0)
				{
					suggestions[matches] = globalSuggestions[i];
					matches++;
				}
			}

			// show the found matches
			DoMethod(obj, MUIM_Source_ShowTips, suggestions);

			free(suggestions);
		}
	}
	else
	{
		DoMethod(obj, MUIM_Source_HideTips);
	}

	return 0;
}

DISPATCHER(Source_Dispatcher)
{
	switch(msg->MethodID)
	{
		case OM_NEW					: return m_Source_NEW(cl, obj, (APTR)msg);
		case OM_DISPOSE				: return m_Source_DISPOSE(cl, obj, (APTR)msg);
		case MUIM_Setup				: return m_Source_Setup(cl, obj, (APTR)msg);
		case MUIM_Cleanup			: return m_Source_Cleanup(cl, obj, (APTR)msg);
		case MUIM_Show				: return m_Source_Show(cl, obj, (APTR)msg);
		case MUIM_Hide				: return m_Source_Hide(cl, obj, (APTR)msg);
		case MUIM_HandleEvent		: return m_Source_HandleEvent(cl, obj, (APTR)msg);
		case MUIM_Source_ShowTips	: return m_Source_ShowTips(cl, obj, (APTR)msg);
		case MUIM_Source_HideTips	: return m_Source_HideTips(cl, obj, (APTR)msg);
		case MUIM_Source_Suggest	: return m_Source_Suggest(cl, obj, (APTR)msg);
	}

	return DoSuperMethodA(cl, obj, msg);
}

int main(UNUSED int argc, UNUSED char *argv[])
{
	Object *app;
	Object *window;
	Object *source;

	init();

	if (!(tips_mcc = MUI_CreateCustomClass(NULL, MUIC_Calltips, NULL, sizeof(struct TipsData), Tips_Dispatcher)))
		fail(NULL, "Could not create Tips custom class.");
	if (!(source_mcc = MUI_CreateCustomClass(NULL, MUIC_String, NULL, sizeof(struct SourceData), Source_Dispatcher)))
		fail(NULL, "Could not create Source custom class.");

	app = ApplicationObject,
		MUIA_Application_Title      , "Calltips",
		MUIA_Application_Version    , "$VER: Calltips 21.2 (14.01.2020)",
		MUIA_Application_Copyright  , "(C) 2013-2020 Thore Boeckelmann",
		MUIA_Application_Author     , "Thore Boeckelmann",
		MUIA_Application_Description, "Demonstrate the use of Calltips.mcc in MUI 5.0",
		MUIA_Application_Base       , "CALLTIPS",

		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Calltips.mcc",
			MUIA_Window_ID   , MAKE_ID('C','L','T','P'),
			WindowContents, VGroup,
				Child, Label("Enter some text to open the calltip"),
				Child, source = NewObject(source_mcc->mcc_Class, NULL, TAG_DONE),
				End,
			End,
		End;

	if (!app)
		fail(app, "Failed to create Application.");

	DoMethod(window, MUIM_Notify, MUIA_Window_CloseRequest, TRUE,
		app, 2, MUIM_Application_ReturnID, MUIV_Application_ReturnID_Quit);


	set(window, MUIA_Window_ActiveObject, source);
	set(window, MUIA_Window_Open, TRUE);

/*
** This is the ideal input loop for an object oriented MUI application.
** Everything is encapsulated in classes, no return ids need to be used,
** we just call a single method which does all the dirty work.
*/

	DoMethod(app, MUIM_Application_Run);

	DoMethod(source, MUIM_Source_HideTips);
	set(window, MUIA_Window_Open, FALSE);

/*
** Shut down...
*/

	MUI_DisposeObject(app);     /* dispose all objects. */
	MUI_DeleteCustomClass(tips_mcc); /* delete the custom class. */
	MUI_DeleteCustomClass(source_mcc); /* delete the custom class. */
	fail(NULL, NULL);            /* exit, app is already disposed. */

	// just to please the compiler
	return 0;
}
