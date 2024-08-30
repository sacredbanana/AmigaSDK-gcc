/*
** runtime_example.c ©2008 Jacek Piszczek
**
** A simple screen titlebar plugin class that illustrates how to create such plugins
** from an application
**
*/
#define INTUI_V50_NOOBSOLETE

#include <exec/types.h>
#include <clib/alib_protos.h>
#include <graphics/rpattr.h>

#include <proto/muimaster.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/exec.h>
#include <proto/utility.h>

#include <intuition/screenbar.h>
#include <intuition/extensions.h>
#include <libraries/mui.h>

#include <stdlib.h>

struct Data
{
	ULONG pen;
	Object *my_app;
	struct MUI_EventHandlerNode eh;
};

#define DISPATCHERNAME_BEGIN(Name)			\
ULONG Name(void) { Class *cl=(Class*) REG_A0; Msg msg=(Msg) REG_A1; Object *obj=(Object*) REG_A2; switch (msg->MethodID) {

#define DISPATCHER_END } return DoSuperMethodA(cl,obj,msg);}

#define DISPATCHER_GATE(Name) struct EmulLibEntry _Dispatcher_##Name = { TRAP_LIB, 0, (void (*)(void)) Name };
#define DISPATCHER_REF(Name) &_Dispatcher_##Name

/*
** NOTE: do NOT use this serialno in your applications! ask for your own serial number!
*/
#define MUISERIALNO_DEBUG 0xfed8

#define CFGID_COLOR MUI_CFGID(MUISERIALNO_DEBUG,1,3)
#define CFGID_SOMECHECKMARK MUI_CFGID(MUISERIALNO_DEBUG,0,4)

/*
** NOTE: this is essentialy the same class we used in example_sbar.c!
*/
ULONG Example_New(struct IClass *cl,Object *obj,struct opSet *msg)
{
	obj = DoSuperNew(cl,obj,
					 MUIA_FillArea,FALSE,
					 TAG_MORE,msg->ops_AttrList);

	if (obj)
	{
		struct Data *data = INST_DATA(cl,obj);

		// this is basicly the only way to actually pass some data into our instances without
		// using ugly global variables. do consider using this!
		data->my_app = (Object *)cl->cl_UserData;
		
		data->pen = -1;
	}

	return (ULONG)obj;
}

static ULONG Example_Setup(struct IClass *cl,Object *obj,Msg msg)
{
	struct Data *data = INST_DATA(cl,obj);
	ULONG rc = DoSuperMethodA(cl,obj,msg);

	if (rc)
	{
		char *newcolor = "rFFFFFF";

		DoMethod(obj,MUIM_GetConfigItem,CFGID_COLOR,(ULONG)&newcolor);

		data->pen = MUI_ObtainPen(muiRenderInfo(obj),(struct MUI_PenSpec *)newcolor,NULL);

		data->eh.ehn_Priority = 0;
		data->eh.ehn_Flags = 0;
		data->eh.ehn_Events = IDCMP_MOUSEBUTTONS;
		data->eh.ehn_Object = obj;
		data->eh.ehn_Class = NULL;
		DoMethod(_win(obj),MUIM_Window_AddEventHandler,(ULONG)&data->eh);
	}

	return rc;
}

static ULONG Example_Cleanup(struct IClass *cl,Object *obj,Msg msg)
{
	struct Data *data = INST_DATA(cl,obj);

	DoMethod(_win(obj),MUIM_Window_RemEventHandler,(ULONG)&data->eh);

	if (data->pen != -1)
	{
		MUI_ReleasePen(muiRenderInfo(obj),data->pen);
		data->pen = -1;
	}

	return DoSuperMethodA(cl,obj,msg);
}

static ULONG Example_AskMinMax(struct IClass *cl,Object *obj,struct MUIP_AskMinMax *msg)
{
	ULONG rc = DoSuperMethodA(cl,obj,msg);
	struct MUI_MinMax *mm = msg->MinMaxInfo;

	// we want a nice, square thingie :)

	// mind that you should generally stick to fixed widths
	// the custom layouter isn't very smart :)
	mm->MinWidth = mm->DefWidth = mm->MaxWidth = _screen(obj)->BarHeight + 1;

	// if you provide MinHeight that's bigger than the actual titlebar size,
	// your object will not be displayed in the titlebar!
	mm->MinHeight = mm->DefHeight = mm->MaxHeight = _screen(obj)->BarHeight + 1;

	return rc;
}

static ULONG Example_Draw(struct IClass *cl,Object *obj,struct MUIP_Draw *msg)
{
	struct Data *data = INST_DATA(cl,obj);
	ULONG rc = DoSuperMethodA(cl,obj,msg);

	if (msg->flags & MADF_DRAWUPDATE)
	{
		Object *parent = NULL;

		get(obj,MUIA_Parent,&parent);

		DoMethod(parent,MUIM_DrawBackground,_left(obj),_top(obj),_width(obj),_height(obj),0,0,0);
	}

	SetAPen(_rp(obj),MUIPEN(data->pen));

	RectFill(_rp(obj),_mleft(obj),_mtop(obj),_mright(obj),_mbottom(obj));

	return rc;
}

// some helper macros
#define _between(a,x,b) ((x)>=(a) && (x)<=(b))
#define _isinobject(x,y) (_between(_mleft(obj),(x),_mright (obj)) \
						   && _between(_mtop(obj) ,(y),_mbottom(obj)))

static ULONG Example_HandleEvent(struct IClass *cl,Object *obj,struct MUIP_HandleEvent *msg)
{
	struct Data *data = INST_DATA(cl,obj);
	
	if (msg->imsg != NULL)
	{
		switch (msg->imsg->Class)
		{
			case IDCMP_MOUSEBUTTONS:
				if (msg->imsg->Code == SELECTDOWN)
				{
					if (_isinobject(msg->imsg->MouseX,msg->imsg->MouseY))
					{
						if (data->my_app)
						{
							// NOTE: you MUST NOT call any objects of your applications directly!
							// they are running on a different process.
							// for more sophisticated tasks consider using message ports and
							// a custom main loop
							DoMethod(data->my_app,MUIM_Application_PushMethod,data->my_app,2,
								MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);
						}

						return MUI_EventHandlerRC_Eat;
					}
				}
				break;
		}
	}

	return 0;
}

static ULONG Example_BuildSettingsPanel(struct IClass *cl,Object *obj,struct MUIP_Screenbar_BuildSettingsPanel *msg)
{
	Object *lcolor,*lsome;
	Object *color,*some;
	Object *prefs = MUI_NewObject(MUIC_Mccprefs,MUIA_Group_Columns,2,
								  Child,lcolor = LLabel2("Color"),
								  Child,HGroup,
									Child,color = PoppenObject,MUIA_Penadjust_PSIMode,2,MUIA_CycleChain,TRUE,MUIA_HorizWeight,1,End,
									Child,RectangleObject,MUIA_HorizWeight,10,End,
									End,
								  Child,lsome = LLabel2("Some checkmark"),
								  Child,HGroup,
									Child,some = MUI_MakeObject(MUIO_Checkmark,NULL),
									Child,RectangleObject,End,
									End,
								  Child,RectangleObject,End,
								  Child,RectangleObject,End,
								  TAG_DONE);

	DoMethod(prefs,MUIM_Mccprefs_RegisterGadget,(ULONG)color,CFGID_COLOR,3,NULL,MUIA_Pendisplay_Spec,(ULONG)lcolor);
	DoMethod(prefs,MUIM_Mccprefs_RegisterGadget,(ULONG)some,CFGID_SOMECHECKMARK,3,NULL,MUIA_Selected,(ULONG)lsome);

	return (ULONG)prefs;
}

static ULONG Example_KnowsConfigItem(struct IClass *cl,Object *obj,struct MUIP_Screenbar_KnowsConfigItem *msg)
{
	switch (msg->cfgid)
	{
		case CFGID_COLOR: return TRUE;
		case CFGID_SOMECHECKMARK: return TRUE;
	}

	return FALSE;
}

static ULONG Example_DefaultConfigItem(struct IClass *cl,Object *obj,struct MUIP_Screenbar_DefaultConfigItem *msg)
{
	switch (msg->cfgid)
	{
		case CFGID_COLOR: return (ULONG)"rFFFFFF";
		case CFGID_SOMECHECKMARK: return FALSE;
	}

	return 0;
}

/*
	Use this macro to add your objects to the refresh list. This will ensure the configuration is reloaded.
	Flags: use 0 in case you only need to be redrawn, 1 in case you want to reload prefs values and refresh.
*/

#ifndef RedrawQ
/* for MUIM_UpdateConfig
 */
#define RedrawQ(m,o,flg) \
	do { \
	if ((((flg)==0) || ((flg)==1 && muiRenderInfo(o))) && (m->redrawcount < (LONG)(sizeof(m->redrawobj)/sizeof(m->redrawobj[0])))) \
	{ \
		m->redrawflags[m->redrawcount] = flg; \
		m->redrawobj[m->redrawcount++] = o; \
	} } while(0)
#endif

static ULONG Example_UpdateConfigItem(struct IClass *cl,Object *obj,struct MUIP_Screenbar_UpdateConfigItem *msg)
{
	switch (msg->cfgid)
	{
		case CFGID_COLOR:
		case CFGID_SOMECHECKMARK:
			RedrawQ(msg,obj,1);
			break;
	}

	return 0;
}

DISPATCHERNAME_BEGIN(RuntimeExample_Sbar)
	case OM_NEW:                               return Example_New(cl,obj,(APTR)msg);
	case MUIM_Setup:                           return Example_Setup(cl,obj,(APTR)msg);
	case MUIM_Cleanup:                         return Example_Cleanup(cl,obj,(APTR)msg);
	case MUIM_AskMinMax:                       return Example_AskMinMax(cl,obj,(APTR)msg);
	case MUIM_Draw:                            return Example_Draw(cl,obj,(APTR)msg);
	case MUIM_HandleEvent:                     return Example_HandleEvent(cl,obj,(APTR)msg);
	case MUIM_Screenbar_BuildSettingsPanel:    return Example_BuildSettingsPanel(cl,obj,(APTR)msg);
	case MUIM_Screenbar_KnowsConfigItem:       return Example_KnowsConfigItem(cl,obj,(APTR)msg);
	case MUIM_Screenbar_DefaultConfigItem:     return Example_DefaultConfigItem(cl,obj,(APTR)msg);
	case MUIM_Screenbar_UpdateConfigItem:      return Example_UpdateConfigItem(cl,obj,(APTR)msg);
DISPATCHER_END
DISPATCHER_GATE(RuntimeExample_Sbar)

static char message[] =
	"\033cThe plugin is now installed!\n\n"
	"New runtime classes are enabled by default on 1st installation. After the plugin was already added\n"
	"intuition will honour user preferences. There is no way to force activation of your plugin if the\n"
	"user does not want to use it.\n\n"
	"This example also shows a simple way to pass information from the plugin instances to your\n"
	"application. Simply click on the object to signal this app to quit.\n\n"
	"Remember to remove the plugin before you quit!";

int main(void)
{
	// create our plugin class!
	struct MUI_CustomClass *screenbarclass = MUI_CreateCustomClass(NULL,MUIC_Area,NULL,sizeof (struct Data),DISPATCHER_REF(RuntimeExample_Sbar));

	if (screenbarclass)
	{
		Object *window;
		Object *application = ApplicationObject,
			MUIA_Application_Title, "Screenbar Runtime Example",
			MUIA_Application_Author, "Jacek Piszczek",
			MUIA_Application_Copyright, "(C)2007 Jacek Piszczek",
			MUIA_Application_Description, "Demonstrates the use of runtime screenbar plugins",

			SubWindow, window = WindowObject,
				MUIA_Window_Title, "Useless window",
				WindowContents, VGroup,
					Child, TextObject, MUIA_Text_Contents, message, End,
					End,
				End,
			End;

		if (application)
		{
			ULONG sigs;

			DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
				application,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

			// we MUST set the name of our class!
			screenbarclass->mcc_Class->cl_ID = "Runtime_Screenbar.sbar";

			// give our instances a way to call us back
			screenbarclass->mcc_Class->cl_UserData = (ULONG)application;

			// install the plugin!
			ScreenbarControl(SBCT_InstallPlugin,(ULONG)screenbarclass,TAG_DONE);

			set(window,MUIA_Window_Open,TRUE);

			while (DoMethod(application,MUIM_Application_NewInput,&sigs) != MUIV_Application_ReturnID_Quit)
			{
				if (sigs)
				{
					sigs = Wait(sigs | SIGBREAKF_CTRL_C);
					if (sigs & SIGBREAKF_CTRL_C) break;
				}
			}

			set(window,MUIA_Window_Open,FALSE);

			// MUST uninstall the module before exiting!!!
			ScreenbarControl(SBCT_UninstallPlugin,(ULONG)screenbarclass,TAG_DONE);

			MUI_DisposeObject(application);
		}
	}

	MUI_DeleteCustomClass(screenbarclass);

	return 0;
}

