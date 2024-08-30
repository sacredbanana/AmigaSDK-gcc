/*
** $Id: Animals.c,v 1.14 2009/02/21 23:19:07 stuntzi Exp $
*/

#include "demo.h"


#define MYTAGBASE 0x8042 // 16bit mui tagbase for stuntzi.
                         // use your own registered id here!

#define MUI_CFGID_APP(tagbase,isstring,x) ( (((tagbase)<<16) & 0x7fffffff) | 0x00008000 | ((isstring)<<14) | (x) )

#define CFG_BIRD_WINGSPAN      MUI_CFGID_APP(MYTAGBASE,0,1)
#define CFG_BIRD_FLIGHTHEIGHT  MUI_CFGID_APP(MYTAGBASE,0,2)
#define CFG_BIRD_FEATHERCOLOR  MUI_CFGID_APP(MYTAGBASE,1,3)
#define CFG_MAMMALS_CHILDCARRY MUI_CFGID_APP(MYTAGBASE,0,4)
#define CFG_MAMMALS_LEGCOUNT   MUI_CFGID_APP(MYTAGBASE,0,5)
#define CFG_MAMMALS_ARMCOUNT   MUI_CFGID_APP(MYTAGBASE,0,6)


/***********************************************************************************************************/


#define DemoSlider(format,min,max)\
	SliderObject,\
		MUIA_Numeric_Min  , min,\
		MUIA_Numeric_Max  , max,\
		MUIA_Numeric_Format, format, \
		End

struct myapp_Data
{
	int dummy;
};


Object *makeBirds(void)
{
	Object *obj,*s1,*s2,*s3,*l1,*l2,*l3;

	obj = MUI_NewObject(MUIC_Mccprefs,
		MUIA_Group_Columns, 2,
		Child, l1 = Label2("Average wing span:"    ), Child, s1 = DemoSlider("%ld cm",1,100),
		Child, l2 = Label2("Maximum flight height:"), Child, s2 = DemoSlider("%ld m" ,1,1000),
		Child, l3 = Label2("Feather color:"        ), Child, s3 = String("",64),
Child, VSpace(0), Child, VSpace(0),
		TAG_DONE);

	if (obj)
	{
		DoMethod(obj,MUIM_Mccprefs_RegisterGadget,s1,CFG_BIRD_WINGSPAN    ,3,NULL,MUIA_Numeric_Value  ,l1);
		DoMethod(obj,MUIM_Mccprefs_RegisterGadget,s2,CFG_BIRD_FLIGHTHEIGHT,3,NULL,MUIA_Numeric_Value  ,l2);
		DoMethod(obj,MUIM_Mccprefs_RegisterGadget,s3,CFG_BIRD_FEATHERCOLOR,3,NULL,MUIA_String_Contents,l3);
	}

	return(obj);
}


Object *makeMammals(void)
{
	Object *obj,*s1,*s2,*s3,*l1,*l2,*l3;

	obj = MUI_NewObject(MUIC_Mccprefs,
		MUIA_Group_Columns, 2,
		Child, l1 = Label("Average child carrying time:"), Child, s1 = DemoSlider("%ld weeks",1,80),
		Child, l2 = Label("Number of arms:"             ), Child, s2 = DemoSlider("%ld" ,1,8),
		Child, l3 = Label("Number of legs:"             ), Child, s3 = DemoSlider("%ld" ,1,8),
Child, VSpace(0), Child, VSpace(0),
		TAG_DONE);

	if (obj)
	{
		DoMethod(obj,MUIM_Mccprefs_RegisterGadget,s1,CFG_MAMMALS_CHILDCARRY,3,NULL,MUIA_Numeric_Value,l1);
		DoMethod(obj,MUIM_Mccprefs_RegisterGadget,s2,CFG_MAMMALS_ARMCOUNT  ,3,NULL,MUIA_Numeric_Value,l2);
		DoMethod(obj,MUIM_Mccprefs_RegisterGadget,s3,CFG_MAMMALS_LEGCOUNT  ,3,NULL,MUIA_Numeric_Value,l3);
	}

	return(obj);
}


ULONG myapp_BuildSettingsPanel(struct IClass *cl,Object *obj,struct MUIP_Application_BuildSettingsPanel *msg)
{
	switch (msg->number)
	{
		case  0: return((ULONG)"Birds"       ); case 0x00010000: return((ULONG)makeBirds()      );
		case  1: return((ULONG)"Mammals"     ); case 0x00010001: return((ULONG)makeMammals()    );
		case  2: return((ULONG)"Mammals/Dogs"); //case 0x00010002: return((ULONG)myapp_MammalsDogs());
		case  3: return((ULONG)"Mammals/Cats"); //case 0x00010003: return((ULONG)myapp_MammalsCats());
	}

	return(DoSuperMethodA(cl,obj,msg));
}


ULONG myapp_DefaultConfigItem(struct IClass *cl,Object *obj,struct MUIP_Application_DefaultConfigItem *msg)
{
	printf("defaults %08lx\n",msg->cfgid);

	switch (msg->cfgid)
	{
		case CFG_BIRD_WINGSPAN     : return(30);
		case CFG_BIRD_FLIGHTHEIGHT : return(100);
		case CFG_BIRD_FEATHERCOLOR : return((ULONG)"light brown");
		case CFG_MAMMALS_CHILDCARRY: return(16);
		case CFG_MAMMALS_LEGCOUNT  : return(2);
		case CFG_MAMMALS_ARMCOUNT  : return(2);
	}

	return(DoSuperMethodA(cl,obj,msg));
}


ULONG getcfg(Object *o,ULONG id)
{
	ULONG storage=0;
	DoMethod(o,MUIM_GetConfigItem,id,&storage);
	return(storage);
}


ULONG myapp_UpdateConfig(struct IClass *cl,Object *obj,struct MUIP_UpdateConfig *msg)
{
	switch (msg->cfgid)
	{
		case CFG_BIRD_WINGSPAN     : printf("wingspan %ld\n"   ,getcfg(obj,msg->cfgid)); break;
		case CFG_BIRD_FLIGHTHEIGHT : printf("flightheit %ld\n" ,getcfg(obj,msg->cfgid)); break;
		case CFG_BIRD_FEATHERCOLOR : printf("feathercolor %s\n",getcfg(obj,msg->cfgid)); break;
		case CFG_MAMMALS_CHILDCARRY: printf("childcarry %ld\n" ,getcfg(obj,msg->cfgid)); break;
		case CFG_MAMMALS_LEGCOUNT  : printf("legs %ld\n"       ,getcfg(obj,msg->cfgid)); break;
		case CFG_MAMMALS_ARMCOUNT  : printf("arms %ld\n"       ,getcfg(obj,msg->cfgid)); break;
	}

	return(DoSuperMethodA(cl,obj,msg));
}


DISPATCHER(myapp)
{
	switch (msg->MethodID)
	{
		case MUIM_Application_BuildSettingsPanel  : return(myapp_BuildSettingsPanel  (cl,obj,(APTR)msg));
		case MUIM_Application_DefaultConfigItem: return(myapp_DefaultConfigItem(cl,obj,(APTR)msg));
		case MUIM_UpdateConfig: return(myapp_UpdateConfig(cl,obj,(APTR)msg));
	}

	return(DoSuperMethodA(cl,obj,msg));
}
DISPATCHER_END


/***********************************************************************************************************/


int main(int argc,char *argv[])
{
	struct MUI_CustomClass *myapp_class;
	APTR app,window,button;

	init();

	if (!(myapp_class = MUI_CreateCustomClass(NULL,MUIC_Application,NULL,sizeof(struct myapp_Data),DISPATCHER_REF(myapp))))
		fail(NULL,"Could not create myapp class.");

	app = NewObject(myapp_class->mcc_Class, NULL,
		MUIA_Application_Title      , "Animals",
		MUIA_Application_Version    , "$VER: Animals 1.0 (04.11.05)",
		MUIA_Application_Copyright  , "© 2005 Stefan Stuntz",
		MUIA_Application_Author     , "Stefan Stuntz",
		MUIA_Application_Description, "Demonstrate settings interface",
		MUIA_Application_Base       , "ANIMALS",
		SubWindow, window = WindowObject,
			MUIA_Window_Title, "Animals - demo program to show the settings interface",
			MUIA_Window_ID   , MAKE_ID('A','N','I','M'),
			WindowContents, VGroup,
				Child, button = SimpleButton("\33cSettings...\n(that would normally be a menu entry)"),
				End,
			End,
		TAG_DONE);

	if (app)
	{
		ULONG sigs = 0;

		set(button,MUIA_Text_SetVMax,FALSE);

		DoMethod(button,MUIM_Notify,MUIA_Pressed,FALSE,
			MUIV_Notify_Application,2,MUIM_Application_OpenConfigWindow,0);

		DoMethod(window,MUIM_Notify,MUIA_Window_CloseRequest,TRUE,
			app,2,MUIM_Application_ReturnID,MUIV_Application_ReturnID_Quit);

		set(window,MUIA_Window_ActiveObject,button);

		set(window,MUIA_Window_Open,TRUE);

		while (DoMethod(app,MUIM_Application_NewInput,&sigs) != MUIV_Application_ReturnID_Quit)
		{
			if (sigs)
			{
				sigs = Wait(sigs | SIGBREAKF_CTRL_C);
				if (sigs & SIGBREAKF_CTRL_C) break;
			}
		}

		set(window,MUIA_Window_Open,FALSE);
	}

	MUI_DisposeObject(app);
	MUI_DeleteCustomClass(myapp_class);
	fail(NULL,NULL);
	return(0);
}
