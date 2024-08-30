/*
** Example.sbar ©2008 Jacek Piszczek
**
** A simple screen titlebar plugin class that illustrates how to create such plugins
**
*/
#define INTUI_V50_NOOBSOLETE

#include <exec/types.h>
#include <clib/alib_protos.h>
#include <graphics/rpattr.h>

#include <proto/muimaster.h>
#include <proto/graphics.h>
#include <proto/intuition.h>

#include <intuition/extensions.h>
#include <intuition/screenbar.h>

#include <stdlib.h>

#define D(x)
#define bug kprintf

#define DISPATCHERNAME_BEGIN(Name)			\
ULONG Name(void) { Class *cl=(Class*) REG_A0; Msg msg=(Msg) REG_A1; Object *obj=(Object*) REG_A2; switch (msg->MethodID) {

#define DISPATCHER_END } return DoSuperMethodA(cl,obj,msg);}

/*

	You MUST use your own mcc class serial no here! If you don't have one, email
	stefan@stuntz.com to obtain one. Classes using illegal serial numbers will
	be disabled!

*/

#define MUISERIALNO_DEBUG 0xfed8

#define CFGID_COLOR MUI_CFGID(MUISERIALNO_DEBUG,1,1)
#define CFGID_SOMECHECKMARK MUI_CFGID(MUISERIALNO_DEBUG,0,2)

struct Data
{
	LONG pen;
};

#define VERSION 1
#define REVISION 1
#define CLASS "Example.sbar"
#define SUPERCLASS MUIC_Area
#define _Dispatcher Example_Sbar
#define UserLibID "\0$VER: Example.sbar 1.0 (26.2.2007) © 2007 Jacek Piszczek"
#define MASTERVERSION 20

#define	LIBQUERYCLASS			QUERYCLASS_INTUITION_SCREENBAR
#define	LIBQUERYID              "Example.sbar 1.0 (26.2.2007) © 2007 Jacek Piszczek"
#define	LIBQUERYDESCRIPTION		"Example Screen Titlebar Plugin"

#include <mui/mccheader.c>

static ULONG Example_New(struct IClass *cl,Object *obj,struct opSet *msg)
{
	obj = DoSuperNew(cl,obj,
					 MUIA_FillArea,FALSE,
					 TAG_MORE,msg->ops_AttrList);

	if (obj)
	{
		struct Data *data = INST_DATA(cl,obj);

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
	}

	return rc;
}

static ULONG Example_Cleanup(struct IClass *cl,Object *obj,Msg msg)
{
	struct Data *data = INST_DATA(cl,obj);

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

DISPATCHERNAME_BEGIN(Example_Sbar)
	case OM_NEW:                               return Example_New(cl,obj,(APTR)msg);
	case MUIM_Setup:                           return Example_Setup(cl,obj,(APTR)msg);
	case MUIM_Cleanup:                           return Example_Cleanup(cl,obj,(APTR)msg);
	case MUIM_AskMinMax:                       return Example_AskMinMax(cl,obj,(APTR)msg);
	case MUIM_Draw:                            return Example_Draw(cl,obj,(APTR)msg);
	case MUIM_Screenbar_BuildSettingsPanel:    return Example_BuildSettingsPanel(cl,obj,(APTR)msg);
	case MUIM_Screenbar_KnowsConfigItem:       return Example_KnowsConfigItem(cl,obj,(APTR)msg);
	case MUIM_Screenbar_DefaultConfigItem:     return Example_DefaultConfigItem(cl,obj,(APTR)msg);
	case MUIM_Screenbar_UpdateConfigItem:      return Example_UpdateConfigItem(cl,obj,(APTR)msg);
DISPATCHER_END

