

  /**********************************************\
  *                                              *
  *  WbMan                                       *
  *                                              *
  *  Version: 0.42 (27.8.93)                     *
  *                                              *
  *  Copyright 1993 by kMel, Klaus Melchior      *
  *  kmel@eifel.adsp.sub.org, 2:242/7.2@Fidonet  *
  *                                              *
  *  Manages the tools in the WBStartup-         *
  *  Folder, the ToolTypes could be changed.     *
  *                                              *
  \**********************************************/

/* DMAKE */

/* TAB=4 */




/*** escape sequences ***/

#define eR "\033r"
#define eC "\033c"
#define eL "\033l"

#define eN "\033n"
#define eB "\033b"
#define eI "\033i"

#define ePB "\0332"
#define ePW "\0338"




/*** includes ***/

#include "demo.h"
#define MAXNAMELEN 256

#include <exec/memory.h>
#include <workbench/workbench.h>
#include <clib/icon_protos.h>




/*** ids ***/

enum ids {
	ID_DUMMY,
	ID_ABOUT,
	ID_RESCAN, ID_SELECT_ALL, ID_SELECT_NONE, ID_SELECT_PATTERN,
	ID_EDIT, ID_LV_ACTIVE,
	ID_ACTIVATE, ID_TOGGLE, ID_DEACTIVATE, ID_RESTORE,
	ID_PERFORM, ID_QUIT,

	ID_STRING_OK, ID_STRING_CANCEL,

	ID_EDIT_LV_ACTIVE,
	ID_EDIT_NEW, ID_EDIT_COPY, ID_EDIT_REMOVE,
	ID_EDIT_ACTIVATE, ID_EDIT_DEACTIVATE,
	ID_EDIT_ST_READY,
	ID_EDIT_SAVE, ID_EDIT_CANCEL,
};

enum mode_change {
	MODE_ACTIVATE, MODE_DEACTIVATE,
	MODE_TOGGLE, MODE_RESTORE,
};




/*** variables ***/

static APTR app;
static APTR wi_main;
static APTR lv_tools;
static APTR bt_activate, bt_toggle, bt_deactivate;
static APTR bt_edit;
static APTR tx_info;
static APTR bt_perform, bt_quit;

static APTR wi_string_request;
static APTR st_string;
static APTR bt_string_ok, bt_string_cancel;

static APTR wi_edit;
static APTR tx_edit;
static APTR lv_edit;
static APTR bt_edit_new, bt_edit_copy, bt_edit_remove;
static APTR bt_edit_activate, bt_edit_deactivate;
static APTR st_edit_string, st_edit_default;
static APTR bt_edit_save, bt_edit_cancel;


static struct DiskObject *disk_object;
static BOOL temp_dobj_flag;

static BOOL edit_window_open = FALSE;
static BOOL string_request_open = FALSE;




#if defined(__amigaos4__)
#define allocMem(size, flags)	AllocVecTags(size, AVT_Type, MEMF_SHARED, (flags & MEMF_CLEAR) ? AVT_ClearWithValue : TAG_IGNORE, 0, TAG_DONE)
#else
#define allocMem(size, flags)	AllocVec(size, flags)
#endif
#define freeMem(mem,size)		FreeVec(mem)

/*** funcs ***/

/*** clear tools_listview ***/

BOOL clear_tools_list(void)
{
	DoMethod(lv_tools, MUIM_List_Clear);

	return TRUE;
}




/*** insert tools in tools_listview ***/

BOOL insert_tools_list(void)
{
	BOOL ok = FALSE;
	struct FileInfoBlock *fib;

	/*** alloc mem for fileinfoblock ***/
	if ((fib = AllocDosObject(DOS_FIB, NULL)))
	{
		BPTR lock;

		/*** lock on the wbstartup-directory ***/
		if ((lock = Lock("SYS:WBStartup/", ACCESS_READ)))
		{
			/*** first examine ***/
			Examine(lock, fib);

			/*** scan, until last entry ***/
			while (ExNext(lock, fib) && (IoErr()!=ERROR_NO_MORE_ENTRIES))
			{
				/*** mui refresh ***/
				DoMethod(app, MUIM_Application_InputBuffered);

				/*** insert fib-entry ***/
				DoMethod(lv_tools, MUIM_List_Insert, &fib, 1, MUIV_List_Insert_Sorted);
			}

			UnLock(lock);
			ok = TRUE;
		}

		FreeDosObject(DOS_FIB, fib);
	}

	return(ok);
}




/*** rescan filenames of tools in the wbstartup-path ***/

void rescan_tools_list(void)
{
	if (!(
		clear_tools_list() &&
		insert_tools_list()
		))
	{
		fail(app,"Lock on 'SYS:WBStartup/' failed !");
	}
}




/*** check tool, if it exists in wbstartup-path ***/

BOOL check_tool_name(char *n)
{
	char *fn;
	BPTR fh = (BPTR)NULL;

	/*** alloc mem for complete filename ***/
	if ((fn = allocMem(MAXNAMELEN, MEMF_ANY)))
	{
		snprintf(fn, MAXNAMELEN, "SYS:WBStartup/%s", n);

		if ((fh = Open(fn, MODE_OLDFILE)))
			Close(fh);

		freeMem(fn, MAXNAMELEN);
	}

	return((BOOL) fh);
}




/*** count active & inactive tools ***/

void count_tools_list(void)
{
	ULONG i;
	UWORD nr_active = 0, nr_inactive = 0, nr_changed = 0;
	char *line;

	/*** count ***/
	for (i=0; ; i++)
	{
		DoMethod(lv_tools, MUIM_List_GetEntry, i, &line);

		/*** last line ? ***/
		if (!line)
			break;

		/*** count tools ***/
		if (*(line+2) == '8')
			nr_active++;
		else
			nr_inactive++;

		if (*(line+4) == 'b')
			nr_changed++;
	}

	{
		const char *s_inactive = "s";

		/*** check if 'tool' or 'tools' ***/
		if (nr_inactive == 1)
			s_inactive = "";

		/*** generate info text ***/
		DoMethod(tx_info, MUIM_SetAsString, MUIA_Text_Contents,
			eC ePB "%ld tool%s inactive · " ePW "%ld active · " eB ePB "%ld changed",
			nr_inactive, s_inactive, nr_active, nr_changed);
	}
}





/*** disable gadgets & menus, show changes ***/

void check_entries(void)
{
	ULONG i, sel, c_pos;
	UWORD nr_active = 0, nr_inactive = 0, nr_selected = 0;
	char *line;

	BOOL disable_activate = TRUE, disable_toggle = TRUE;
	BOOL disable_deactivate = TRUE, disable_restore = TRUE;
	BOOL disable_perform = TRUE, disable_edit = TRUE;

	BOOL refresh_display = FALSE;


	/*** cursor position ***/
	get(lv_tools, MUIA_List_Active, &c_pos);

	/*** count ***/
	for (i=0;; i++)
	{
		DoMethod(lv_tools, MUIM_List_GetEntry, i, &line);

		/*** last line ? ***/
		if (!line)
			break;

		/*** count selected or at cursor-position ***/
		DoMethod(lv_tools, MUIM_List_Select, i, MUIV_List_Select_Ask, &sel);
		if (sel || i==c_pos)
		{
			/*** count status of selected tools ***/
			if (*(line+2)=='8')
				nr_active++;
			else
				nr_inactive++;

			nr_selected++;
		}

		/*** check difference between stored and new status ***/
		if (*(line+2) != *line)
		{
			/*** make entry bold ***/
			if (*(line+4)!='b')
				refresh_display = TRUE;
			*(line+4)='b';

			disable_perform = FALSE;
		}
		else
		{
			/*** now a normal entry ***/
			if (*(line+4)!='n')
				refresh_display = TRUE;
			*(line+4)='n';
		}
	}

	if (nr_selected > 0)
	{
		disable_toggle = FALSE;
		disable_restore = FALSE;

		if (nr_inactive)
			disable_activate = FALSE;

		if (nr_active)
			disable_deactivate = FALSE;
	}

	if (nr_selected == 1)
		disable_edit = FALSE;


	/*** set status of gadgets ***/
	set(bt_perform, MUIA_Disabled, disable_perform);

	set(bt_activate, MUIA_Disabled, disable_activate);
	set(bt_toggle, MUIA_Disabled, disable_toggle);
	set(bt_deactivate, MUIA_Disabled, disable_deactivate);
	set(bt_edit, MUIA_Disabled, disable_edit);


	/*** set status of menus ***/
	DoMethod(wi_main, MUIM_Window_SetMenuState ,ID_PERFORM, !disable_perform);

	DoMethod(wi_main, MUIM_Window_SetMenuState ,ID_ACTIVATE, !disable_activate);
	DoMethod(wi_main, MUIM_Window_SetMenuState ,ID_DEACTIVATE, !disable_deactivate);
	DoMethod(wi_main, MUIM_Window_SetMenuState ,ID_TOGGLE, !disable_toggle);
	DoMethod(wi_main, MUIM_Window_SetMenuState ,ID_RESTORE, !disable_restore);

	DoMethod(wi_main, MUIM_Window_SetMenuState ,ID_EDIT, !disable_edit);

	/*** refresh display ***/
	if (refresh_display)
		DoMethod(lv_tools, MUIM_List_Redraw, MUIV_List_Redraw_All);
}




/*** change status of tools ***/

void change_tools_list_entry(LONG pos, UWORD mode)
{
	char *line, *pen;

	/*** get entry ***/
	DoMethod(lv_tools, MUIM_List_GetEntry, pos, &line);
	pen = line+2;

	/*** change entry ***/
	switch (mode)
	{
		case MODE_ACTIVATE:
			*pen = '8';
		break;

		case MODE_DEACTIVATE:
			*pen = '2';
		break;

		case MODE_TOGGLE:
			if (*pen=='2')
				*pen = '8';
			else
				*pen = '2';
		break;

		case MODE_RESTORE:
			*pen = *line;
		break;
	}
}

void change_tools_list_entry_cursor(UWORD mode)
{
	LONG i;

	get(lv_tools, MUIA_List_Active, &i);

	if (i >= 0)
	{
		change_tools_list_entry(i, mode);
		DoMethod(lv_tools, MUIM_List_Redraw, i);
	}
}

void change_tools_list(UWORD mode)
{
	ULONG end, i, nr=0;
	ULONG sel;

	/*** get number of all entries ***/
	get(lv_tools, MUIA_List_Entries, &end);

	set(lv_tools, MUIA_List_Quiet, TRUE);
	for (i=0; i<end ; i++)
	{
		/*** entry selected ? ***/
		DoMethod(lv_tools, MUIM_List_Select, i, MUIV_List_Select_Ask, &sel);
		if (sel)
		{
			change_tools_list_entry(i, mode);
			nr++;
		}
	}
	set(lv_tools, MUIA_List_Quiet, FALSE);

	/*** refresh display, if almost one entry is selected ***/
	if (nr>0)
		DoMethod(lv_tools, MUIM_List_Redraw, MUIV_List_Redraw_All);

	/*** change entry on cursor-position ***/
	else
		change_tools_list_entry_cursor(mode);
}




/*** select every entry of tools_list ***/

void select_tools_list(ULONG mode)
{
	ULONG end, i;
	ULONG sel;

	/*** get number of all entries ***/
	get(lv_tools, MUIA_List_Entries, &end);

	for (i=0; i<end ; i++)
		DoMethod(lv_tools, MUIM_List_Select, i, mode, &sel);

	/*** refresh display ***/
	DoMethod(lv_tools, MUIM_List_Redraw, MUIV_List_Redraw_All);
}




/*** select tools of tools_list matching pattern ***/

void select_pattern_tools_list(char *pattern)
{
	ULONG end, i;
	ULONG sel;
	char *tool_name, *pattern_token;

	/*** alloc mem for pattern_name ***/
	if ((pattern_token = allocMem(MAXNAMELEN, MEMF_ANY)))
	{
		/*** tokenize pattern ***/
		ParsePatternNoCase(pattern, pattern_token, MAXNAMELEN);

		/*** get number of all entries ***/
		get(lv_tools, MUIA_List_Entries, &end);

		for (i=0; i<end ; i++)
		{
			DoMethod(lv_tools, MUIM_List_GetEntry, i, &tool_name);

			/*** check tool_name, if it fits on pattern ***/
			if (MatchPatternNoCase(pattern_token, tool_name+5))
				DoMethod(lv_tools, MUIM_List_Select, i, MUIV_List_Select_On, &sel);
		}

		/*** refresh display ***/
		DoMethod(lv_tools, MUIM_List_Redraw, MUIV_List_Redraw_All);

		freeMem(pattern_token, MAXNAMELEN);
	}
}




/*** rename the tools in the wbstartup-directory ***/

void rename_tools_list(void)
{
	char *file_name, *new_file_name;

	/*** alloc mem for filenames ***/
	if ((file_name = allocMem(MAXNAMELEN, MEMF_ANY)))
	{
		if ((new_file_name = allocMem(MAXNAMELEN, MEMF_ANY)))
		{
			char *line;
			ULONG i;

			for (i=0; ; i++)
			{
				DoMethod(lv_tools, MUIM_List_GetEntry, i, &line);

				if (!line)
					break;

				/*** check if old and new status different ***/
				if (*(line+4) == 'b')
				{

					/*** turn status to active ***/
					if (*(line+2) == '8')
					{
						snprintf(file_name, MAXNAMELEN, "SYS:WBStartup/%s.noinfo", line+5);
						snprintf(new_file_name, MAXNAMELEN, "SYS:WBStartup/%s.info", line+5);
					}

					/*** turn status to inactive ***/
					else
					{
						snprintf(file_name, MAXNAMELEN, "SYS:WBStartup/%s.info", line+5);
						snprintf(new_file_name, MAXNAMELEN, "SYS:WBStartup/%s.noinfo", line+5);
					}

					if (rename(file_name, new_file_name))
						printf("Can't rename: '%s' -> '%s'\n", file_name, new_file_name);
				}
			}
			freeMem(new_file_name, MAXNAMELEN);

		}
		freeMem(file_name, MAXNAMELEN);

	}
}




/*** string requester ***/

/*** open requester ***/

BOOL open_string_request(const char *title_text, ULONG string_len)
{
	wi_string_request = WindowObject,
		MUIA_Window_ID, MAKE_ID('S','R','E','Q'),
		MUIA_Window_Title, "WbMan",
		MUIA_Window_Menu, MUIV_Window_Menu_NoMenu,
		WindowContents, VGroup,
			Child, HGroup,
				GroupFrameT(title_text),
				Child, st_string = StringObject,
					StringFrame,
					MUIA_String_MaxLen, string_len,
					End,
				End,
			Child, VSpace(2),
			Child, HGroup,
				MUIA_Group_SameSize, TRUE,
				Child, bt_string_ok = SimpleButton("_OK"),
				Child, HSpace(0),
				Child, bt_string_cancel = SimpleButton("_Cancel"),
				End,
			End,
		End;


	/*** string requester failed ? ***/
	if (!wi_string_request)
		fail(app, "Creating string-requester failed !");



	/*** connections & cycle ***/

	DoMethod(wi_string_request,	MUIM_Notify,	MUIA_Window_CloseRequest,	TRUE,		app,	2,	MUIM_Application_ReturnID,	ID_STRING_CANCEL	);

	DoMethod(bt_string_ok,		MUIM_Notify,	MUIA_Pressed,				FALSE,		app,	2,	MUIM_Application_ReturnID,	ID_STRING_OK		);
	DoMethod(bt_string_cancel,	MUIM_Notify,	MUIA_Pressed,				FALSE,		app,	2,	MUIM_Application_ReturnID,	ID_STRING_CANCEL	);

	/*** activate ok-button if string is ready ***/
	DoMethod(st_string,
		MUIM_Notify, MUIA_String_Acknowledge, MUIV_EveryTime,
		wi_string_request, 3,
		MUIM_Set, MUIA_Window_ActiveObject, bt_string_ok);

	DoMethod(wi_string_request, MUIM_Window_SetCycleChain,
		st_string,
		bt_string_ok, bt_string_cancel,
		NULL);


	/*** add & open window ***/

	DoMethod(app, OM_ADDMEMBER, wi_string_request);
	set(wi_string_request, MUIA_Window_Open			, TRUE);
	set(wi_string_request, MUIA_Window_ActiveObject	, st_string);

	return TRUE;
}


/*** close requester ***/

void close_string_request(void)
{
	/*** close & remove window ***/
	set(wi_string_request, MUIA_Window_Open, FALSE);
	DoMethod(app, OM_REMMEMBER, wi_string_request);
	MUI_DisposeObject(wi_string_request);

	/*** wake up main-window ***/
	set(wi_main, MUIA_Window_Sleep, FALSE);
}




/*** edit tooltypes ***/

/*** open edit-window ***/

BOOL open_edit_window(struct DiskObject *dobj, char *name)
{
	wi_edit = WindowObject,
		MUIA_Window_ID, MAKE_ID('E','D','I','T'),
		MUIA_Window_Title, "WbMan",
		MUIA_Window_Menu, MUIV_Window_Menu_NoMenu,
		WindowContents, VGroup,
			Child, HGroup,
				TextFrame,
				InnerSpacing(4,3),
				Child, ImageObject,
					MUIA_Image_OldImage, dobj->do_Gadget.GadgetRender,
					End,
				Child, VGroup,
					Child, VSpace(0),
					Child, tx_edit = TextObject,
						MUIA_Text_PreParse, eC,
						MUIA_Text_Contents, name,
						MUIA_Text_SetMin, TRUE,
						End,
					Child, VSpace(0),
					End,
				Child, ImageObject,
					MUIA_Image_OldImage, dobj->do_Gadget.GadgetRender,
					End,
				End,
			Child, VGroup,
				GroupFrameT("ToolTypes"),
				Child, VGroup,
					GroupSpacing(0),
					Child, lv_edit = ListObject,
						InputListFrame,
						MUIA_List_Input, TRUE,
						MUIA_List_ConstructHook, MUIV_List_ConstructHook_String,
						MUIA_List_DestructHook, MUIV_List_DestructHook_String,
						End,
					Child, HGroup,
						GroupSpacing(0),
						Child, bt_edit_new = SimpleButton("_New"),
						Child, bt_edit_copy = SimpleButton("Cop_y"),
						Child, bt_edit_remove = SimpleButton("_Remove"),
						End,
					Child, HGroup,
						GroupSpacing(0),
						Child, bt_edit_activate = SimpleButton("_Activate"),
						Child, bt_edit_deactivate = SimpleButton("_Deactivate"),
						End,
					Child, st_edit_string = StringObject,
						StringFrame,
						End,
					End,
				End,
			Child, HGroup,
				Child, Label2("Default Tool:"),
				Child, st_edit_default = String(NULL, MAXNAMELEN),
				End,
			Child, VSpace(2),
			Child, HGroup,
				MUIA_Group_SameSize, TRUE,
				Child, bt_edit_save = SimpleButton("_Save"),
				Child, HSpace(0),
				Child, bt_edit_cancel = SimpleButton("_Cancel"),
				End,
			End,
		End;


	/*** window failed ? ***/
	if (!wi_edit)
		fail(app, "Creating edit-window failed !");


	/*** connections & cycle ***/

	DoMethod(wi_edit,				MUIM_Notify,	MUIA_Window_CloseRequest,	TRUE,		app,	2,	MUIM_Application_ReturnID,	ID_EDIT_CANCEL		);

	DoMethod(bt_edit_new,			MUIM_Notify,	MUIA_Pressed,				FALSE,		app,	2,	MUIM_Application_ReturnID,	ID_EDIT_NEW			);
	DoMethod(bt_edit_copy,			MUIM_Notify,	MUIA_Pressed,				FALSE,		app,	2,	MUIM_Application_ReturnID,	ID_EDIT_COPY		);
	DoMethod(bt_edit_remove,		MUIM_Notify,	MUIA_Pressed,				FALSE,		app,	2,	MUIM_Application_ReturnID,	ID_EDIT_REMOVE		);

	DoMethod(bt_edit_activate,		MUIM_Notify,	MUIA_Pressed,				FALSE,		app,	2,	MUIM_Application_ReturnID,	ID_EDIT_ACTIVATE	);
	DoMethod(bt_edit_deactivate,	MUIM_Notify,	MUIA_Pressed,				FALSE,		app,	2,	MUIM_Application_ReturnID,	ID_EDIT_DEACTIVATE	);

	DoMethod(bt_edit_save,			MUIM_Notify,	MUIA_Pressed,				FALSE,		app,	2,	MUIM_Application_ReturnID,	ID_EDIT_SAVE		);
	DoMethod(bt_edit_cancel,		MUIM_Notify,	MUIA_Pressed,				FALSE,		app,	2,	MUIM_Application_ReturnID,	ID_EDIT_CANCEL		);

	DoMethod(lv_edit,				MUIM_Notify,	MUIA_List_SelectChange,		TRUE,		app,	2,	MUIM_Application_ReturnID,	ID_EDIT_LV_ACTIVE	);

	set(lv_edit, MUIA_List_Active, MUIV_List_Active_Top);
	DoMethod(lv_edit,
		MUIM_Notify, MUIA_List_Active, MUIV_EveryTime,
		app, 2,
		MUIM_Application_ReturnID, ID_EDIT_LV_ACTIVE);

	set(st_edit_string, MUIA_String_AttachedList, lv_edit);
	DoMethod(st_edit_string,
		MUIM_Notify, MUIA_String_Acknowledge, MUIV_EveryTime,
		app, 2,
		MUIM_Application_ReturnID,  ID_EDIT_ST_READY);

	DoMethod(wi_edit, MUIM_Window_SetCycleChain,
		st_edit_string,
		bt_edit_new, bt_edit_copy, bt_edit_remove,
		st_edit_default,
		bt_edit_save, bt_edit_cancel,
		NULL);


	/*** add & open window ***/
	DoMethod(app, OM_ADDMEMBER, wi_edit);
	set(wi_edit, MUIA_Window_Open, TRUE);
	set(wi_edit, MUIA_Window_ActiveObject, st_edit_string);

	return TRUE;
}


/*** close edit-window ***/

void close_edit_window(void)
{
	/*** close & remove window ***/
	set(wi_edit, MUIA_Window_Open, FALSE);
	DoMethod(app, OM_REMMEMBER, wi_edit);
	MUI_DisposeObject(wi_edit);

	if (disk_object)
		FreeDiskObject(disk_object);

	/*** wake up main-window ***/
	set(wi_main, MUIA_Window_Sleep, FALSE);
}


/*** disable gadgets ***/

void check_edit_entries(void)
{
	LONG pos;
	char *line;

	BOOL disable_cursor = TRUE;
	BOOL disable_activate = TRUE, disable_deactivate = TRUE;


	/*** cursor position ***/
	get(lv_edit, MUIA_List_Active, &pos);

	if (pos >= 0)
	{
		disable_cursor = FALSE;

		/*** get active line ***/
		DoMethod(lv_edit, MUIM_List_GetEntry, pos, &line);

		/*** check if there are brakets -> inactive ***/
		if (*line == '(' && *(line + strlen(line) - 1) == ')')
			disable_activate = FALSE;
		else
			disable_deactivate = FALSE;
	}

	set(bt_edit_copy, MUIA_Disabled, disable_cursor);
	set(bt_edit_remove, MUIA_Disabled, disable_cursor);
	set(st_edit_string, MUIA_Disabled, disable_cursor);

	set(bt_edit_activate, MUIA_Disabled, disable_activate);
	set(bt_edit_deactivate, MUIA_Disabled, disable_deactivate);

	/*** clear string if disabled ***/
	if (disable_cursor)
		set(st_edit_string, MUIA_String_Contents, "");

}


/*** edit the active tool ***/

void edit_tooltypes_diskobject(struct DiskObject *dobj, char *fn)
{
	STRPTR *tt;

	/*** open window ***/
	if (open_edit_window(dobj, fn))
	{
		tt = dobj->do_ToolTypes;

		/*** copy tooltype-array into listview ***/
		while (tt && *tt)
			DoMethod(lv_edit, MUIM_List_Insert, tt++, 1, MUIV_List_Insert_Bottom);

		/*** fill in strings ***/
		set(st_edit_default, MUIA_String_Contents, dobj->do_DefaultTool);
		set(lv_edit, MUIA_List_Active, MUIV_List_Active_Top);
	}
}

void edit_tooltypes_entry(void)
{
	char *file_name;

	if ((file_name = allocMem(MAXNAMELEN, MEMF_ANY)))
	{
		char *line;

		/*** get entry ***/
		DoMethod(lv_tools, MUIM_List_GetEntry, MUIV_List_GetEntry_Active, &line);

		snprintf(file_name, MAXNAMELEN, "SYS:WBStartup/%s", line+5);

		if ((disk_object = GetDiskObject(file_name)))
		{
			temp_dobj_flag = FALSE;
			edit_tooltypes_diskobject(disk_object, line+5);
		}
		else
		{
			/*** is tool inactive ? create temporary .info-file ***/
			temp_dobj_flag = TRUE;
			snprintf(file_name, MAXNAMELEN, "copy SYS:WBStartup/%s.noinfo T:WbMan_Temp.info", line+5);
			if (Execute(file_name, (BPTR)NULL, (BPTR)NULL) &&
				(disk_object = GetDiskObjectNew((STRPTR)"T:WbMan_Temp"))
				)
				edit_tooltypes_diskobject(disk_object, line+5);
			else
			{
			}
		}

		check_edit_entries();

		freeMem(file_name, MAXNAMELEN);
	}
}

void save_tooltypes(void)
{
	if (disk_object)
	{
		STRPTR file_name;

		if ((file_name = allocMem(MAXNAMELEN, MEMF_ANY)))
		{
			STRPTR old_def_tool;
			STRPTR *old_tooltypes;
			STRPTR line;
			ULONG nr;
			STRPTR *new_tooltypes;

			/*** store actual data ***/
			old_def_tool = disk_object->do_DefaultTool;
			old_tooltypes = disk_object->do_ToolTypes;

			/*** new data ***/
			get(st_edit_default, MUIA_String_Contents, &line);
			disk_object->do_DefaultTool = line;

			/*** generate array of tooltypes ***/
			get(lv_edit, MUIA_List_Entries, &nr);
			if ((new_tooltypes = allocMem((nr+1) << 2, MEMF_ANY)))
			{
				STRPTR *l;
				ULONG i;

				l = new_tooltypes;
				for (i=0; ; i++)
				{
					DoMethod(lv_edit, MUIM_List_GetEntry, i, &line);

					/*** last line ? ***/
					if (!line)
						break;

					*l++ = line;
				}
				/*** terminate array ***/
				*l = NULL;

				/*** new_data ***/
				disk_object->do_ToolTypes = new_tooltypes;

				/*** get entry ***/
				DoMethod(lv_tools, MUIM_List_GetEntry, MUIV_List_GetEntry_Active, &line);

				if (temp_dobj_flag)
				{
					PutDiskObject((STRPTR)"T:WbMan_Temp", disk_object);

					snprintf(file_name, MAXNAMELEN, "copy T:WbMan_Temp.info SYS:WBStartup/%s.noinfo", line+5);
					Execute(file_name, (BPTR)NULL, (BPTR)NULL);
				}
				else
				{
					/*** get disk object ***/
					snprintf(file_name, MAXNAMELEN, "SYS:WBStartup/%s", line+5);

					PutDiskObject(file_name, disk_object);
				}

				freeMem(new_tooltypes, (nr+1) << 2);
			}

			/*** restore data ***/
			disk_object->do_DefaultTool = old_def_tool;
			disk_object->do_ToolTypes = old_tooltypes;

			freeMem(file_name, MAXNAMELEN);
		}
	}
}




/*** image-stuff ***/

static UWORD wbman_sleep_img1_data[] = {
	0x0003,0xc000,0x0000,0x0000,0x0004,0x4000,0x0000,0x0000,
	0x0008,0x4000,0x0000,0x0000,0x0018,0x4de0,0x0000,0x0000,
	0x0020,0x3210,0x0000,0x0000,0x0020,0x0008,0x0000,0x0000,
	0x0020,0x0008,0x0000,0x0000,0x0020,0xf008,0x0000,0x0000,
	0x0020,0x2788,0x0000,0x0000,0x0010,0x4108,0x0000,0x0000,
	0x0010,0xf208,0x0000,0x0000,0x0008,0x0790,0x0000,0x0000,
	0x0008,0x0020,0x0000,0x0000,0x003c,0x00c0,0x0000,0x0400,
	0x0046,0x3f00,0x0000,0x0c00,0x0083,0xe000,0x0000,0x0c00,
	0x0100,0x8004,0x0000,0x2c00,0x0101,0x001c,0x0000,0x2c00,
	0x0386,0x007e,0x0000,0x2c00,0x04c8,0x01fe,0x0001,0x2c00,
	0x08b0,0x07f8,0x0001,0x2c00,0x0500,0x1fe0,0x0001,0x2c00,
	0x0200,0x7f80,0x0009,0x2c00,0x0001,0xfe00,0x0009,0x2c00,
	0x0007,0xf8f8,0x2009,0x2c00,0x001f,0xe1cc,0x7009,0x2c00,
	0x007f,0x8038,0x7009,0xcc00,0x01fe,0x0070,0x2009,0x0c00,
	0x01f8,0x0000,0x0009,0x0c00,0x00e0,0x0070,0x700e,0x0c00,
	0x0080,0x0000,0x0008,0x0c00,0x0000,0x0000,0x0008,0x0c00,
	0x0000,0x3fff,0xfff0,0x0c00,0x0000,0x0000,0x0000,0x0c00,
	0x7fff,0xffff,0xffff,0xfc00,0x0003,0xc000,0x0000,0x0000,
	0x0007,0xc000,0x0000,0x0000,0x000f,0xc000,0x0000,0x0000,
	0x001f,0xcde0,0x0000,0x0000,0x003f,0xfff0,0x0000,0x0000,
	0x003f,0xfff8,0x0000,0x0000,0x003f,0xfff8,0x0000,0x0000,
	0x003f,0x0ff8,0x0000,0x0000,0x003f,0xd878,0x0000,0x0000,
	0x001f,0xbef8,0x0000,0x0000,0x001f,0x0df8,0x0000,0x0000,
	0x000f,0xf870,0x0000,0x0000,0x000f,0xffe0,0x0000,0x0000,
	0xffff,0xffff,0xffff,0xf800,0xd57f,0xff54,0x1555,0x5000,
	0xd5ff,0xf5f8,0xcfff,0xd000,0xd5ff,0xd7e7,0xefff,0x9000,
	0xd5ff,0x5713,0xcaa9,0x1000,0xd7ff,0x5e41,0x1ffe,0x1000,
	0xd7fd,0x5902,0x7ffc,0x1000,0xdff5,0x4409,0x5548,0x1000,
	0xd755,0x1027,0xfff0,0x1000,0xd754,0x409f,0xffe0,0x1000,
	0xd551,0x022a,0xaa40,0x1000,0xd544,0x0802,0x8a80,0x1000,
	0xd510,0x2222,0x8a80,0x9000,0xd440,0x8a82,0x8a80,0x3000,
	0xd102,0x6a8a,0x8a80,0x5000,0xc209,0xeaaa,0xaa84,0x5000,
	0xcf25,0xea8a,0x8a81,0x5000,0xdf95,0xf2aa,0xaa45,0x5000,
	0xcc55,0xe000,0x0025,0x5000,0xc155,0xc000,0x000d,0x5000,
	0xd555,0x5555,0x5555,0x5000,0x8000,0x0000,0x0000,0x0000,

};

static struct Image wbman_sleep_img1 = {
	0x0000,0x0000,0x0036,0x0023,0x0002,
	&wbman_sleep_img1_data[0],
	0x03,0x00,0x00000000,
};

static struct DiskObject wbman_sleep_dobj = {
	0xe310,0x0001,
	{
		0x00000000,
		0x00a9,0x00fa,0x0036,0x0024,0x0005,0x0001,0x95a5,
		(APTR)&wbman_sleep_img1,NULL,
		0x00000000,0x00000000,0x00000000,
		0x0064,
		0x00000000
	},
	0x0003,
	0x00000000,0x00000000,0x000000a5,0x000000e5,
	0x00000000,0x00000000,0x00001000,
};




/*** mui-stuff ***/

/*** list hooks ***/

HOOKPROTONHNO(tools_list_confunc, char *, struct FileInfoBlock *fib)
{
	char active_pattern[14];
	char inactive_pattern[20];

	/*** tokenize pattern ***/
	ParsePatternNoCase("#?.info", active_pattern, 14);
	ParsePatternNoCase("#?.noinfo", inactive_pattern, 20);

	/*** check, only files ***/
	if (fib->fib_DirEntryType < 0)
	{
		char *file_name, *entry;

		if ((entry = allocMem(MAXNAMELEN, MEMF_ANY)))
		{
			file_name = &fib->fib_FileName[0];

			/*** check if active ***/
			if (MatchPatternNoCase(active_pattern, file_name))
			{
				/*** cut the ".info" at end ***/
				*(file_name + strlen(file_name) - 5) = 0;

				/*** valid filename ? ***/
				if (check_tool_name(file_name))
				{
					snprintf(entry, MAXNAMELEN, "8" ePW eN "%s", file_name);
					return(entry);
				}
			}

			/*** or inactive ***/
			else if (MatchPatternNoCase(inactive_pattern, file_name))
			{
				/*** cut the ".noinfo" at end ***/
				*(file_name + strlen(file_name) - 7) = 0;

				/*** valid filename ? ***/
				if (check_tool_name(file_name))
				{
					snprintf(entry, MAXNAMELEN, "2" ePB eN "%s", file_name);
					return(entry);
				}
			}

			freeMem(entry, MAXNAMELEN);
		}
	}

	/*** insert nothing ***/
	return 0;
}
MakeStaticHook(tools_list_conhook, tools_list_confunc);


HOOKPROTONHNO(tools_list_desfunc, LONG, char *line)
{
	freeMem(line, MAXNAMELEN);

	return 0;
}
MakeStaticHook(tools_list_deshook, tools_list_desfunc);


HOOKPROTONH(tools_list_dspfunc, LONG, char **array, char *line)
{
	*array = line+1;
	return 0;
}
MakeStaticHook(tools_list_dsphook, tools_list_dspfunc);


HOOKPROTONH(tools_list_cmpfunc, LONG, char *line1, char *line2)
{
	return(stricmp(line2+5, line1+5));
}
MakeStaticHook(tools_list_cmphook, tools_list_cmpfunc);



/*** arexx hooks ***/

HOOKPROTONHNO(select_rxfunc, APTR, ULONG *arg)
{
	char *pattern;

	/*** pattern valid ? ***/
	if ((pattern = (char *)*arg))
	{
		/*** clear list & select matching pattern ***/
		select_tools_list(MUIV_List_Select_Off);
		select_pattern_tools_list(pattern);
	}

	return(RETURN_OK);
}
MakeStaticHook(select_rxhook, select_rxfunc);



/*** arexx list ***/

static struct MUI_Command arexx_list[] =
{
	{(char *)"rescan",		MC_TEMPLATE_ID,			ID_RESCAN,		NULL, {0, 0, 0, 0, 0}},

	{(char *)"select",		(char *)"PATTERN/A",	1,				(struct Hook *)&select_rxhook, {0, 0, 0, 0, 0}},

	{(char *)"activate",	MC_TEMPLATE_ID,			ID_ACTIVATE,	NULL, {0, 0, 0, 0, 0}},
	{(char *)"deactivate",	MC_TEMPLATE_ID,			ID_DEACTIVATE,	NULL, {0, 0, 0, 0, 0}},
	{(char *)"toggle",		MC_TEMPLATE_ID,			ID_TOGGLE,		NULL, {0, 0, 0, 0, 0}},
	{(char *)"restore",		MC_TEMPLATE_ID,			ID_RESTORE,		NULL, {0, 0, 0, 0, 0}},

	{NULL,					NULL,					0,				NULL, {0, 0, 0, 0, 0}}
};



/*** menu ***/

static const struct NewMenu menu_list[] =
{
	{ NM_TITLE,	(char *)"Project",			NULL,		0,	0,	0							},

	{ NM_ITEM,	(char *)"About...",			(char *)"?",0,	0,	(APTR) ID_ABOUT				},
	{ NM_ITEM,	NM_BARLABEL,				NULL,		0,	0,	0							},
	{ NM_ITEM,	(char *)"Rescan",			(char *)"S",0,	0,	(APTR) ID_RESCAN			},
	{ NM_ITEM,	NM_BARLABEL,				NULL,		0,	0,	0							},
	{ NM_ITEM,	(char *)"Perform",			(char *)"P",0,	0,	(APTR) ID_PERFORM			},
	{ NM_ITEM,	(char *)"Quit",				(char *)"Q",0,	0,	(APTR) ID_QUIT				},


	{ NM_TITLE,	(char *)"Tools",			NULL,		0,	0,	0							},

	{ NM_ITEM,	(char *)"Select All",		(char *)"A",0,	0,	(APTR) ID_SELECT_ALL		},
	{ NM_ITEM,	(char *)"Select None",		(char *)"N",0,	0,	(APTR) ID_SELECT_NONE		},
	{ NM_ITEM,	(char *)"Select Pattern",	(char *)"E",0,	0,	(APTR) ID_SELECT_PATTERN	},
	{ NM_ITEM,	NM_BARLABEL,				NULL,		0,	0,	0							},
	{ NM_ITEM,	(char *)"Activate",			(char *)"V",0,	0,	(APTR) ID_ACTIVATE			},
	{ NM_ITEM,	(char *)"Deactivate",		(char *)"D",0,	0,	(APTR) ID_DEACTIVATE		},
	{ NM_ITEM,	(char *)"Toggle",			(char *)"T",0,	0,	(APTR) ID_TOGGLE			},
	{ NM_ITEM,	(char *)"Restore",			(char *)"R",0,	0,	(APTR) ID_RESTORE			},
	{ NM_ITEM,	NM_BARLABEL,				NULL,		0,	0,	0							},
	{ NM_ITEM,	(char *)"Edit Tooltypes",	(char *)"O",0,	0,	(APTR) ID_EDIT				},


	{ NM_END,	NULL,						NULL,		0,	0,	0							},
};




/*** main ***/

int main(UNUSED int argc, UNUSED char *argv[])
{
	/*** init ***/
	BOOL not_end = TRUE;
	ULONG signal = 0;

	init();


	/*** create mui-application ***/
	app = ApplicationObject,
		MUIA_Application_Title,				"WbMan",
		MUIA_Application_Version,			"$VER: WbMan 21.2 (08.02.2018)",
		MUIA_Application_Copyright,		"(C) 1993 Klaus Melchior, (C) 2006-2020 Thore Boeckelmann, Jens Maus",
		MUIA_Application_Author,			"Klaus Melchior, Thore Boeckelmann, Jens Maus",
		MUIA_Application_Description,	"Manages the WBStartup",
		MUIA_Application_Base,				"WBMAN",
		MUIA_Application_Menu,				menu_list,
		MUIA_Application_Commands,			arexx_list,
		MUIA_Application_SingleTask,		TRUE,
		MUIA_Application_DiskObject,		&wbman_sleep_dobj,

		SubWindow, wi_main = WindowObject,
			MUIA_Window_ID, MAKE_ID('M','A','I','N'),
			MUIA_Window_Title, "WbMan",
			WindowContents, VGroup,
				Child, VGroup,
					Child, tx_info = TextObject,
						TextFrame,
						MUIA_Background, MUII_TextBack,
						End,
					Child, VGroup,
						GroupSpacing(0),
						Child, lv_tools = ListObject,
							InputListFrame,
							MUIA_List_MultiSelect, TRUE,
							MUIA_List_DoubleClick, TRUE,
							MUIA_List_ConstructHook, &tools_list_conhook,
							MUIA_List_DestructHook, &tools_list_deshook,
							MUIA_List_CompareHook, &tools_list_cmphook,
							MUIA_List_DisplayHook, &tools_list_dsphook,
							End,
						Child, HGroup,
							GroupSpacing(0),
							Child, bt_activate		= SimpleButton("_Activate"),
							Child, bt_toggle		= SimpleButton("_Toggle"),
							Child, bt_deactivate	= SimpleButton("_Deactivate"),
							End,
						Child, HGroup,
							GroupSpacing(0),
							Child, bt_edit			= SimpleButton("_Edit Tooltypes"),
							End,
						End,
					End,
				Child, VSpace(2),
				Child, HGroup,
					MUIA_Group_SameSize, TRUE,
					Child, bt_perform = SimpleButton("_Perform"),
					Child, HSpace(0),
					Child, bt_quit = SimpleButton("_Quit"),
					End,
				End,
			End,
		End;


	/*** application failed ? ***/
	if (!app)
		fail(app, "Creating application failed !");

	/*** connections & cycle ***/
	DoMethod(wi_main,		MUIM_Notify,	MUIA_Window_CloseRequest,	TRUE,	app,	2,	MUIM_Application_ReturnID,	ID_QUIT			);

	DoMethod(bt_activate,	MUIM_Notify,	MUIA_Pressed,				FALSE,	app,	2,	MUIM_Application_ReturnID,	ID_ACTIVATE		);
	DoMethod(bt_toggle,		MUIM_Notify,	MUIA_Pressed,				FALSE,	app,	2,	MUIM_Application_ReturnID,	ID_TOGGLE		);
	DoMethod(bt_deactivate,	MUIM_Notify,	MUIA_Pressed,				FALSE,	app,	2,	MUIM_Application_ReturnID,	ID_DEACTIVATE	);
	DoMethod(bt_edit,		MUIM_Notify,	MUIA_Pressed,				FALSE,	app,	2,	MUIM_Application_ReturnID,	ID_EDIT			);

	DoMethod(bt_perform,	MUIM_Notify,	MUIA_Pressed,				FALSE,	app,	2,	MUIM_Application_ReturnID,	ID_PERFORM		);
	DoMethod(bt_quit,		MUIM_Notify,	MUIA_Pressed,				FALSE,	app,	2,	MUIM_Application_ReturnID,	ID_QUIT			);

	DoMethod(lv_tools,		MUIM_Notify,	MUIA_List_DoubleClick,		TRUE,	app,	2,	MUIM_Application_ReturnID,	ID_EDIT			);
	DoMethod(lv_tools,		MUIM_Notify,	MUIA_List_SelectChange,		TRUE,	app,	2,	MUIM_Application_ReturnID,	ID_LV_ACTIVE	);

	DoMethod(lv_tools, MUIM_Notify, MUIA_List_Active, MUIV_EveryTime,
		app, 2,
		MUIM_Application_ReturnID, ID_LV_ACTIVE);

	DoMethod(wi_main,		MUIM_Window_SetCycleChain,
		lv_tools,
		bt_activate, bt_toggle, bt_deactivate,
		bt_perform, bt_quit,
		NULL);


	/*** open window ***/
	set(wi_main, MUIA_Window_Open,			TRUE);
	set(wi_main, MUIA_Window_DefaultObject,	lv_tools);


	/*** get files ***/
	rescan_tools_list();
	count_tools_list();

	/*** set cursor on listview & check disable gadget ***/
	check_entries();

	/*** main-loop ***/
	while (not_end)
	{
		ULONG id;
		LONG pos;
		char *line;

		switch (id = DoMethod(app, MUIM_Application_NewInput, &signal))
		{
			case ID_ABOUT:
				MUI_Request(app, wi_main, 0, NULL, "OK",
					eC ePW "WbMan\n\n"
					ePB "WbMan 0.41 (13.8.93)\n"
					"Copyright 1993 by kMel, Klaus Melchior.\n"
					"\nThis is a MUI-Application.\n"
					"MUI is copyrighted by Stefan Stuntz.",
					TAG_END);
			break;

			case MUIV_Application_ReturnID_Quit:
			case ID_QUIT:
				not_end = FALSE;
			break;

			case ID_PERFORM:
				rename_tools_list();
				not_end = FALSE;
			break;


			case ID_EDIT:
				if (!edit_window_open)
				{
					edit_window_open = TRUE;

					/*** main-window must sleep now ***/
					set(wi_main, MUIA_Window_Sleep, TRUE);

					edit_tooltypes_entry();
				}
			break;

			case ID_LV_ACTIVE:
				check_entries();
			break;


			case ID_RESCAN:
				rescan_tools_list();
				check_entries();
				count_tools_list();
			break;

			case ID_ACTIVATE:
				change_tools_list(MODE_ACTIVATE);
				check_entries();
				count_tools_list();
			break;

			case ID_DEACTIVATE:
				change_tools_list(MODE_DEACTIVATE);
				check_entries();
				count_tools_list();
			break;

			case ID_TOGGLE:
				change_tools_list(MODE_TOGGLE);
				check_entries();
				count_tools_list();
			break;

			case ID_RESTORE:
				change_tools_list(MODE_RESTORE);
				check_entries();
				count_tools_list();
			break;


			/*** pattern window ***/

			case ID_SELECT_ALL:
				select_tools_list(MUIV_List_Select_On);
				check_entries();
			break;

			case ID_SELECT_NONE:
				select_tools_list(MUIV_List_Select_Off);
				check_entries();
			break;

			case ID_SELECT_PATTERN:
				if (!string_request_open)
				{
					string_request_open = TRUE;

					/*** main-window must sleep now ***/
					set(wi_main, MUIA_Window_Sleep, TRUE);

					open_string_request("Pattern", 127);
				}
			break;


			case ID_STRING_OK:
				/*** get pattern ***/
				get(st_string, MUIA_String_Contents, &line);

				/*** clear list & select matching pattern ***/
				select_tools_list(MUIV_List_Select_Off);
				select_pattern_tools_list(line);

				close_string_request();
				string_request_open = FALSE;
				check_entries();
			break;

			case ID_STRING_CANCEL:
				close_string_request();
				string_request_open = FALSE;
			break;



			/*** edit window ***/

			case ID_EDIT_LV_ACTIVE:
				/*** copy active line into string ***/
				DoMethod(lv_edit, MUIM_List_GetEntry, MUIV_List_GetEntry_Active, &line);
				set(st_edit_string, MUIA_String_Contents, line);
				check_edit_entries();
				set(wi_edit, MUIA_Window_ActiveObject, st_edit_string);
			break;


			case ID_EDIT_NEW:
				line = (char *)">> new <<";

				/*** insert at cursor-position ***/
				get(lv_edit, MUIA_List_Active, &pos);
				if (pos == -1)
					pos = 0;
				DoMethod(lv_edit, MUIM_List_Insert, &line, 1, pos);
				set(lv_edit, MUIA_List_Active, pos);

				check_edit_entries();
			break;

			case ID_EDIT_COPY:
				get(lv_edit, MUIA_List_Active, &pos);
				DoMethod(lv_edit, MUIM_List_GetEntry, pos, &line);
				DoMethod(lv_edit, MUIM_List_Insert, &line, 1, pos);
				set(lv_edit, MUIA_List_Active, pos);
			break;

			case ID_EDIT_REMOVE:
				get(lv_edit, MUIA_List_Active, &pos);
				DoMethod(lv_edit, MUIM_List_Remove, pos);

				check_edit_entries();
			break;

			case ID_EDIT_ACTIVATE:
				set(lv_edit, MUIA_List_Quiet, TRUE);
				get(lv_edit, MUIA_List_Active, &pos);
				DoMethod(lv_edit, MUIM_List_Remove, pos);
				get(st_edit_string, MUIA_String_Contents, &line);

				{
					char *new_line, *insert_line;

					new_line = strdup(line);
					if (new_line)
					{
						*(new_line + strlen(new_line) - 1) = 0;
						insert_line = new_line + 1;
						DoMethod(lv_edit, MUIM_List_Insert, &insert_line, 1, pos);
						free(new_line);
					}

				}

				set(lv_edit, MUIA_List_Quiet, FALSE);
				set(lv_edit, MUIA_List_Active, pos);
				check_edit_entries();
			break;

			case ID_EDIT_DEACTIVATE:
				set(lv_edit, MUIA_List_Quiet, TRUE);
				get(lv_edit, MUIA_List_Active, &pos);
				DoMethod(lv_edit, MUIM_List_Remove, pos);
				get(st_edit_string, MUIA_String_Contents, &line);

				{
					char *insert_line;

					if ((insert_line = allocMem(MAXNAMELEN, MEMF_ANY)))
					{
						snprintf(insert_line, MAXNAMELEN, "(%s)", line);
						DoMethod(lv_edit, MUIM_List_Insert, &insert_line, 1, pos);

						freeMem(insert_line, MAXNAMELEN);
					}
				}

				set(lv_edit, MUIA_List_Quiet, FALSE);
				set(lv_edit, MUIA_List_Active, pos);
				check_edit_entries();
			break;


			case ID_EDIT_ST_READY:
				set(lv_edit, MUIA_List_Quiet, TRUE);
				get(lv_edit, MUIA_List_Active, &pos);
				DoMethod(lv_edit, MUIM_List_Remove, pos);
				get(st_edit_string, MUIA_String_Contents, &line);
				DoMethod(lv_edit, MUIM_List_Insert, &line, 1, pos);
				set(lv_edit, MUIA_List_Quiet, FALSE);
				set(lv_edit, MUIA_List_Active, pos);
			break;


			case ID_EDIT_SAVE:
				save_tooltypes();
				close_edit_window();
				edit_window_open = FALSE;
			break;

			case ID_EDIT_CANCEL:
				close_edit_window();
				edit_window_open = FALSE;
			break;


			/*** default ***/

			default:
				if (id)
					printf("ID: %ld = %08lx\n", id, id);
			break;
		}

		if (not_end && signal)
		{
			signal = Wait(signal | SIGBREAKF_CTRL_C);
			if(signal & SIGBREAKF_CTRL_C) break;
		}
	}

	fail(app, NULL);

	// just to please the compiler
	return 0;
}
