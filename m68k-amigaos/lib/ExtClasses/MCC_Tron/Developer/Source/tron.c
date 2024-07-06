/*

		Tron.mcc (c) Copyright 1995-96 by kmel, Klaus Melchior

		Registered MUI class, Serial Number: 0002

		tron.c

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


#define CLASS       MUIC_Tron
#define SUPERCLASS  MUIC_Area

struct Data
{
	LONG  Pen1;
	LONG  Pen2;
	LONG  PenB;
	LONG  Speed;

	struct MUI_RenderInfo *mri;
	BOOL refresh;
	BOOL showhide;
};

#include "rev/Tron.mcc.rev"

#define UserLibID "$VER: " __VERS " (" __DATE ") " __VERSCR
#define VERSION __VERSION
#define REVISION __REVISION
#define MASTERVERSION 14

#include "mui/mccheader.c"


/*** subs ***/

void release_pen(struct MUI_RenderInfo *mri, LONG *pen)
{
	if(*pen != -1)
	{
		/*** only valid between Setup/Cleanup ! ***/
		if(mri)
			MUI_ReleasePen(mri, *pen);

		*pen = -1;
	}
}

void obtain_pen(struct MUI_RenderInfo *mri, LONG *pen, struct MUI_PenSpec *ps)
{
	/*** only valid between Setup/Cleanup ! ***/
	if(mri)
	{
		release_pen(mri, pen);
		*pen = MUI_ObtainPen(mri, ps, 0);
	}
}


void RedrawAll(Object *obj, struct Data *data)
{
	/*** only valid between Show/Hide ! ***/
	if(data->showhide)
	{
		SetAPen(_rp(obj), MUIPEN(data->PenB));
		RectFill(_rp(obj), _mleft(obj), _mtop(obj), _mright(obj), _mbottom(obj));

		SetAPen(_rp(obj), MUIPEN(data->Pen1));
		RectFill(_rp(obj), _mleft(obj), _mtop(obj), _mleft(obj) + data->Speed, _mbottom(obj));

		SetAPen(_rp(obj), MUIPEN(data->Pen2));
		RectFill(_rp(obj), _mright(obj) - data->Speed, _mtop(obj), _mright(obj), _mbottom(obj));
	}

}



ULONG ASM _New(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
	struct Data *data;

	if (!(obj = (Object *)DoSuperMethodA(cl, obj, msg)))
		return(0);

	/*** init data ***/
	data = INST_DATA(cl, obj);

	data->Pen1    = -1;
	data->Pen2    = -1;
	data->PenB    = -1;
	data->Speed   = DEFAULT_SPEED;

	data->mri     = NULL;
	data->refresh = FALSE;

	/*** trick to set arguments ***/
	msg->MethodID = OM_SET;
	DoMethodA(obj, (Msg)msg);
	msg->MethodID = OM_NEW;

	return((ULONG)obj);
}



ULONG ASM _Dispose(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
	return(DoSuperMethodA(cl,obj,msg));
}



ULONG ASM _Set(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
	struct Data *data = INST_DATA(cl, obj);
	struct TagItem *tags,*tag;

	for(tags=((struct opSet *)msg)->ops_AttrList; tag=NextTagItem(&tags); )
	{
		switch(tag->ti_Tag)
		{
			case MUIA_Tron_Speed:
				DB("SET MUIA_Tron_Speed; %ld\n", tag->ti_Data);
				if(data->Speed != tag->ti_Data)
				{
					data->Speed = tag->ti_Data;
					data->refresh = TRUE;
				}
			break;

			case MUIA_Tron_PenSpec1:
				if(data->mri)
				{
					obtain_pen(data->mri, &data->Pen1, (struct MUI_PenSpec *)tag->ti_Data);
					data->refresh = TRUE;
				}
			break;

			case MUIA_Tron_PenSpec2:
				if(data->mri)
				{
					obtain_pen(data->mri, &data->Pen2, (struct MUI_PenSpec *)tag->ti_Data);
					data->refresh = TRUE;
				}
			break;

			case MUIA_Tron_PenSpecB:
				if(data->mri)
				{
					obtain_pen(data->mri, &data->PenB, (struct MUI_PenSpec *)tag->ti_Data);
					data->refresh = TRUE;
				}
			break;

		}
	}

	if(data->refresh)
	{
		if(data->mri)
			MUI_Redraw(obj, MADF_DRAWOBJECT);

		data->refresh = FALSE;
	}

	return(DoSuperMethodA(cl, obj, msg));
}


static ULONG ASM _Get(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
//	struct Data *data = INST_DATA(cl, obj);
	ULONG *store = ((struct opGet *)msg)->opg_Storage;

	switch( ((struct opGet *)msg)->opg_AttrID )
	{
		case MUIA_Version:  *store = VERSION;  return(TRUE); break;
		case MUIA_Revision: *store = REVISION; return(TRUE); break;
	}

	return(DoSuperMethodA(cl, obj, msg));
}


static ULONG ASM _Setup(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) struct MUIP_Setup *msg)
{
	struct Data *data = INST_DATA(cl, obj);
	Object *pd_obj;
	ULONG l;

	if(!(DoSuperMethodA(cl,obj,(Msg)msg)))
		return(FALSE);

	data->mri = msg->RenderInfo;

	/*** create objects ***/
	pd_obj = MUI_NewObject(MUIC_Pendisplay, TAG_DONE);

	DB("pd_obj:%08lx\n", pd_obj);

	/*** get pen 1 ***/
	if(DoMethod(obj, MUIM_GetConfigItem, MUICFG_Tron_Pen1, &l))
	{
		obtain_pen(data->mri, &data->Pen1, (struct MUI_PenSpec *)l);
	}
	else
	{
		if(pd_obj)
		{
			struct MUI_PenSpec *pen;

			DoMethod(pd_obj, MUIM_Pendisplay_SetMUIPen, DEFAULT_PEN1);
			get(pd_obj, MUIA_Pendisplay_Spec, &pen);
			obtain_pen(data->mri, &data->Pen1, pen);
		}
	}
	
	DB("Obtain Pen1: %ld\n", MUIPEN(data->Pen1));

	/*** get pen 2 ***/
	if(DoMethod(obj, MUIM_GetConfigItem, MUICFG_Tron_Pen2, &l))
	{
		obtain_pen(data->mri, &data->Pen2, (struct MUI_PenSpec *)l);
	}
	else
	{
		if(pd_obj)
		{
			struct MUI_PenSpec *pen;

			DoMethod(pd_obj, MUIM_Pendisplay_SetMUIPen, DEFAULT_PEN2);
			get(pd_obj, MUIA_Pendisplay_Spec, &pen);
			obtain_pen(data->mri, &data->Pen2, pen);
		}
	}
	DB("Obtain Pen2: %ld\n", MUIPEN(data->Pen2));

	/*** get pen B ***/
	if(DoMethod(obj, MUIM_GetConfigItem, MUICFG_Tron_PenB, &l))
	{
		obtain_pen(data->mri, &data->PenB, (struct MUI_PenSpec *)l);
	}
	else
	{
		if(pd_obj)
		{
			struct MUI_PenSpec *pen;

			DoMethod(pd_obj, MUIM_Pendisplay_SetMUIPen, DEFAULT_PENB);
			get(pd_obj, MUIA_Pendisplay_Spec, &pen);
			obtain_pen(data->mri, &data->PenB, pen);
		}
	}
	DB("Obtain PenB: %ld\n", MUIPEN(data->PenB));


	/*** get speed ***/
	if(DoMethod(obj, MUIM_GetConfigItem, MUICFG_Tron_Speed, &l))
	{
		data->Speed = *(ULONG *)l;
	}
	else
		data->Speed = DEFAULT_SPEED;
	DB("Speed: %ld\n", data->Speed);

	/*** dispose created objects ***/
	if(pd_obj)
		MUI_DisposeObject(pd_obj);

	return(TRUE);
}


static ULONG ASM _Cleanup(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
	struct Data *data = INST_DATA(cl, obj);

	release_pen(data->mri, &data->Pen1);
	release_pen(data->mri, &data->Pen2);
	release_pen(data->mri, &data->PenB);

	data->mri = NULL;

	return(DoSuperMethodA(cl,obj,msg));
}


STATIC ULONG ASM _Show(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
	struct Data *data = INST_DATA(cl, obj);

	data->showhide = TRUE;

	return(DoSuperMethodA(cl,obj,msg));
}


STATIC ULONG ASM _Hide(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
	struct Data *data = INST_DATA(cl, obj);

	data->showhide = FALSE;

	return(DoSuperMethodA(cl,obj,msg));
}


ULONG ASM _AskMinMax(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) struct MUIP_AskMinMax *msg)
{
	DoSuperMethodA(cl, obj, (Msg)msg);

	msg->MinMaxInfo->MinWidth  += 20;
	msg->MinMaxInfo->DefWidth  += 50;
	msg->MinMaxInfo->MaxWidth  += MUI_MAXMAX;

	msg->MinMaxInfo->MinHeight += 20;
	msg->MinMaxInfo->DefHeight += 50;
	msg->MinMaxInfo->MaxHeight += MUI_MAXMAX;

	return(0);
}

ULONG ASM _Draw(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) struct MUIP_Draw *msg)
{
	struct Data *data = INST_DATA(cl, obj);

	/*** first draw the superclass ***/
	DoSuperMethodA(cl, obj, (Msg)msg);

	DB("_Draw\n");

	/*** move the Tron line ***/
	if(msg->flags & MADF_DRAWUPDATE)
	{
	}
	else if(msg->flags & MADF_DRAWOBJECT)
	{
		RedrawAll(obj, data);
	}

	return(0);
}


ULONG ASM SAVEDS _Dispatcher(REG(a0) struct IClass *cl, REG(a2) Object *obj, REG(a1) Msg msg)
{
	switch(msg->MethodID)
	{
		case OM_NEW        : return(_New      (cl,obj,(APTR)msg));
		case OM_DISPOSE    : return(_Dispose  (cl,obj,(APTR)msg));
		case OM_SET        : return(_Set      (cl,obj,(APTR)msg));
		case OM_GET        : return(_Get      (cl,obj,(APTR)msg));

		case MUIM_Setup    : return(_Setup    (cl,obj,(APTR)msg));
		case MUIM_Cleanup  : return(_Cleanup  (cl,obj,(APTR)msg));
		case MUIM_Show     : return(_Show     (cl,obj,(APTR)msg));
		case MUIM_Hide     : return(_Hide     (cl,obj,(APTR)msg));
		case MUIM_AskMinMax: return(_AskMinMax(cl,obj,(APTR)msg));
		case MUIM_Draw     : return(_Draw     (cl,obj,(APTR)msg));
	}

	return(DoSuperMethodA(cl,obj,msg));
}

