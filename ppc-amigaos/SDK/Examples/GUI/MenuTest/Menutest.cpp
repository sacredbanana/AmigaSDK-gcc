//
// Copyright (c) 2006 Hyperion Entertainment VOF & Amiga, Inc.
//
// Copyright (c) 2010 Hyperion Entertainment CVBA. All rights reserved.
//
// Written by Philippe-André Bourdin, http://www.Bourdin.ch/Philippe/
//
// AmigaOS 4.x NewMenu Demonstration Application
// ============================================

// Includes

#include <classes/window.h>

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/dos.h>
#include <proto/locale.h>
#include <proto/gadtools.h>
#include <proto/window.h>
#include <proto/layout.h>

#include <reaction/reaction_macros.h>
#include <intuition/classusr.h>

#include "Menutest.h"


// Variables

struct Window *intuiWindow = NULL;
Object *windowObj = NULL;

struct MsgPort *appPort = NULL;
struct MenuItem *item;
struct Menu *menuStrip = NULL;
struct Catalog *catalog;

ULONG windowSignal, userSignal, appSignal, result;
UWORD code;


// Prototypes

void initGUI (void);
STRPTR GetCatStr (LONG);
void cleanExitGUI (void);
BOOL handleEvent (void);
void cleanExit (const char *);


// Functions

void initGUI ()
{

	static struct NewMenu myMenu[] = {

		// Using makros is simple:
		Title (GetCatStr (MSG_MENU_PROJECT)),
		Item (2 + GetCatStr (MSG_MENU_PROJECT_ABOUT), GetCatStr (MSG_MENU_PROJECT_ABOUT), (APTR) (MID_PROJECT_ABOUT)),
		ItemBar,
		Item (2 + GetCatStr (MSG_MENU_PROJECT_QUIT),  GetCatStr (MSG_MENU_PROJECT_QUIT),  (APTR) (MID_PROJECT_QUIT)),
		Title (GetCatStr (MSG_MENU_EDIT)),
		Item (2 + GetCatStr (MSG_MENU_EDIT_UNDO),     GetCatStr (MSG_MENU_EDIT_UNDO),     (APTR) (MID_EDIT_UNDO)),
		Title (GetCatStr (MSG_MENU_VIEW)),

		// Using all fields of the NewMenu structure:
		{ NM_ITEM, 2 + GetCatStr (MSG_MENU_VIEW_FUNCTIONS), GetCatStr (MSG_MENU_VIEW_FUNCTIONS), 0, 0L, (APTR) (MID_VIEW_FUNCTIONS) },
		{ NM_ITEM, 2 + GetCatStr (MSG_MENU_VIEW_NUMERIC),   GetCatStr (MSG_MENU_VIEW_NUMERIC),   0, 0L, (APTR) (MID_VIEW_NUMERIC) },
		{ NM_ITEM, 2 + GetCatStr (MSG_MENU_VIEW_BASIC),     GetCatStr (MSG_MENU_VIEW_BASIC),     0, 0L, (APTR) (MID_VIEW_BASIC) },
		{ NM_ITEM, 2 + GetCatStr (MSG_MENU_VIEW_EXTENDED),  GetCatStr (MSG_MENU_VIEW_EXTENDED),  0, 0L, (APTR) (MID_VIEW_EXTENDED) },

		EndMenu
	};

	ULONG myCharSet = 0;
	catalog = ILocale->OpenCatalog (NULL, "Menutest.catalog", OC_BuiltInLanguage, "ASCII_english", OC_BuiltInCodeSet, 4, /* = ISO-8859-1 */ TAG_END);
	if (!catalog) { printf ("Could not find catalog.\n"); }
	else { myCharSet = catalog->cat_CodeSet; }

	// appPort = IExec->CreateMsgPort ();
	appPort = (struct MsgPort *)IExec->AllocSysObjectTags (ASOT_PORT, TAG_END);
	if (!appPort) { cleanExit ("Could not create message port !"); }
	appSignal = (1L << appPort->mp_SigBit);

	windowObj = (Object *)
			WindowObject,
				WA_Activate, TRUE,
				WA_Title, GetCatStr (MSG_TITLE),
				WA_DragBar, TRUE,
				WA_CloseGadget, TRUE,
				WA_DepthGadget, TRUE,
				WA_SizeGadget, TRUE,
				WA_InnerWidth, 150,
				WA_InnerHeight, 50,
				WA_NewLookMenus, TRUE,
				WA_IDCMP, IDCMP_RAWKEY | IDCMP_MENUPICK | IDCMP_CLOSEWINDOW | IDCMP_GADGETUP,
				WINDOW_IconifyGadget, TRUE,
				WINDOW_IconTitle, GetCatStr (MSG_ICON_TITLE),
				WINDOW_AppPort, appPort,
				WINDOW_NewMenu, (ULONG) myMenu,
				WINDOW_MenuUserData, WGUD_IGNORE,
				WINDOW_CharSet, myCharSet,
				WINDOW_Position, WPOS_CENTERMOUSE,
				WINDOW_Layout, ContainerGroup,
					LAYOUT_CharSet, myCharSet,
					LAYOUT_AddChild, Button (GetCatStr (MSG_OK_GAD), GID_OK),
				End,
			End;

	if (!windowObj) { cleanExit ("Could not create the window !"); }

	intuiWindow = (struct Window *) RA_OpenWindow (windowObj);
	if (!intuiWindow) { cleanExit ("Could not open the window !"); }

	IIntuition->GetAttr (WINDOW_SigMask, windowObj, (ULONG *) &windowSignal);
	IIntuition->GetAttr (WINDOW_MenuStrip, windowObj, (ULONG *) &menuStrip);

#ifdef DEBUG
if (DEBUG > 3)
	for (int i=0; i < 15; i++) { printf ("Addresses of myMenu[%2d]: %d   menuStrip[%2d]: %d\n", i, &(myMenu[i]), i, &(menuStrip[i])); }
#endif
}


STRPTR GetCatStr (LONG id)
{

	LONG size = sizeof (CatCompArray) / sizeof (CatCompArray [0]);
	LONG left = 0, right = size - 1, middle;

	while (left <= right) {
		middle = (left + right) / 2;
		if (id > CatCompArray [middle].cca_ID) { left = middle + 1; }
		else if (id < CatCompArray [middle].cca_ID) { right = middle - 1; }
		else {
			if (ILocale) { return (STRPTR) ILocale->GetCatalogStr (catalog, id, (STRPTR) CatCompArray [middle].cca_Str); }
			return (STRPTR) CatCompArray [middle].cca_Str;
		}
	}
	return (STRPTR)"N/A";
}


void cleanExitGUI ()
{

	if (windowObj) {
		IIntuition->IDoMethod (windowObj, WM_CLOSE);
		IIntuition->DisposeObject (windowObj);
		windowObj = NULL;
	}

	if (intuiWindow) {
		IIntuition->ClearMenuStrip (intuiWindow);
		intuiWindow = NULL;
	}

	ILocale->CloseCatalog (catalog);
}


// All Event handling.

BOOL handleEvent ()
{

	userSignal = IExec->Wait (windowSignal | appSignal | SIGBREAKF_CTRL_C);

	if (userSignal == SIGBREAKF_CTRL_C) { return FALSE; }

	while ((result = RA_HandleInput (windowObj, &code)) != WMHI_LASTMSG) {

#ifdef DEBUG
if (DEBUG > 3)
				printf ("result:%d  classmasked:%d  keymasked:%d  -  code:%d\n", result, result & WMHI_CLASSMASK, result & WMHI_KEYMASK, code);
#endif

		switch (result & WMHI_CLASSMASK) {

			case WMHI_CLOSEWINDOW:
				return FALSE;

			case WMHI_RAWKEY:
				if ((result & WMHI_KEYMASK) == 69) { return FALSE; }
				break;

			case WMHI_ICONIFY:
				RA_Iconify (windowObj);
				intuiWindow = NULL;
				break;

			case WMHI_UNICONIFY:
				intuiWindow = (struct Window *) RA_OpenWindow (windowObj);
				if (!intuiWindow) { cleanExit ("Could not open the window !"); }

				IIntuition->GetAttr (WINDOW_SigMask, windowObj, (ULONG *) &windowSignal);
				break;

			case WMHI_MENUPICK:
#ifdef DEBUG
if (DEBUG > 2)
					printf ("  =>  CODE: menu=%d   item=%d   subitem=%d\n", MENUNUM(code), ITEMNUM(code), SUBNUM(code));
#endif
				if (code != MENUNULL) {
					item = IIntuition->ItemAddress (menuStrip, code);
#ifdef DEBUG
if (DEBUG > 2)
					printf ("  =>  SELECTED ITEM: %d   UserData: %ld\n", item, (ULONG) GTMENUITEM_USERDATA (item));
#endif
					if (!item) { break; }

					switch ((ULONG) GTMENUITEM_USERDATA (item)) {

						case MID_PROJECT_ABOUT:
							printf ("About selected.\n");
							break;
						case MID_PROJECT_QUIT:
							return FALSE;
							break;
						case MID_EDIT_UNDO:
							printf ("Undo selected.\n");
							break;
						case MID_VIEW_FUNCTIONS:
							printf ("Functions selected.\n");
							break;
						case MID_VIEW_NUMERIC:
							printf ("Numeric selected.\n");
							break;
						case MID_VIEW_BASIC:
							printf ("Basic selected.\n");
							break;
						case MID_VIEW_EXTENDED:
							printf ("Extended selected.\n");
							break;
						default:
#ifdef DEBUG
if (DEBUG > 1)
							printf ("  =>  MENU: not found\n");
#endif
							;
					}
				}
				break;

			case WMHI_GADGETUP:
				switch (result & WMHI_GADGETMASK) {

					case GID_OK:
						printf ("OK pressed.\n");
						break;
					default:
#ifdef DEBUG
if (DEBUG > 3)
						printf ("  =>  Gadget: not found (ID:%d)\n", result & WMHI_GADGETMASK, code);
#endif
						;
				}
				break;
		}
	}

	return TRUE;
}


int main (int argc, char *argv[])
{
	initGUI ();

	while (handleEvent ()) {

		; // Enter your code here
	}

	cleanExit (NULL);

	return 0;
}


void cleanExit (const char *errorText)
{

	cleanExitGUI ();

	if (appPort) {
		// IExec->DeleteMsgPort (appPort);
		IExec->FreeSysObject(ASOT_PORT, appPort);
		appPort = NULL;
	}

	if (errorText) { printf ("%s\n", errorText); }
}

