/*
 *  $VER: LibraryManager.c $Revision: 1.2 $
 *
 *  This file is part of "AnimDocky".
 *
 *  Author: Stefan Robl <stefan@qdev.de>
 *
 *  (C) Copyright 2003 Hyperion Entertainment
 *      All rights reserved
 *
 * $Id: LibraryManager.c,v 1.2 2006-06-05 19:25:17 srobl Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.1  2006/05/28 21:21:09  srobl
 * Initial checkin
 *
 * Revision 1.1  2005/11/02 22:53:06  srobl
 * Initial chechin
 *
 *
 *
 */

#include <exec/exec.h>
#include <proto/exec.h>
#include <exec/libraries.h>
#include <proto/locale.h>
//#define CATCOMP_ARRAY
//#include "amidock_dockies_cd.h"

extern struct ExecIFace *IExec;

/*
static struct Library *UtilityBase = NULL;
static struct Library *DOSBase = NULL;
static struct Library *IntuitionBase = NULL;
static struct Library *GraphicsBase = NULL;
static struct Library *ApplicationBase = NULL;
static struct Library *PopupMenuBase = NULL;
static struct Library *P96Base = NULL;
static struct timerequest TimeRequest;
static struct Library *TimerBase = NULL;
static struct Library *DataTypesBase = NULL;
static struct Library *AslBase = NULL;
static struct Library *LocaleBase=NULL;
static struct Catalog *catalog = (struct Catalog *)NULL;

struct UtilityIFace *IUtility = NULL;
struct DOSIFace *IDOS = NULL;
struct IntuitionIFace *IIntuition = NULL;
struct GraphicsIFace *IGraphics = NULL;
struct ApplicationIFace *IApplication = NULL;
struct PrefsObjectsIFace *IPrefsObjects = NULL;
struct PopupMenuIFace *IPopupMenu = NULL;
struct P96IFace *IP96 = NULL;
struct DataTypesIFace *IDataTypes;
struct AslIFace *IAsl = NULL;
struct LocaleIFace *ILocale=NULL;

extern struct ExecIFace *IExec;
extern struct UtilityIFace *IUtility;
extern struct DOSIFace *IDOS;
extern struct IntuitionIFace *IIntuition;
extern struct GraphicsIFace *IGraphics;
extern struct ApplicationIFace *IApplication;
extern struct PrefsObjectsIFace *IPrefsObjects;
extern struct PopupMenuIFace *IPopupMenu;
extern struct P96IFace *IP96;
extern struct TimerIFace *ITimer;
extern struct DataTypesIFace *IDataTypes;
extern struct AslIFace *IAsl;
extern struct LocaleIFace *ILocale;
*/

static struct Library *NewlibBase = NULL;
struct Interface *INewlib = NULL;

BOOL OpenLib(CONST_STRPTR libName, uint32 libVersion, struct Library **libBasePtr)
{
	if (!(*libBasePtr = IExec->OpenLibrary(libName, libVersion)))
	{
		return FALSE;
	}
	
	return TRUE;
}

void CloseLib(struct Library **libBasePtr)
{
	if (*libBasePtr)
	{
		IExec->CloseLibrary(*libBasePtr);
		*libBasePtr = NULL;
	}
}

BOOL GetIFace(CONST_STRPTR libName, struct Library *libBase, CONST_STRPTR interfaceName, uint32 interfaceVersion, struct Interface **interfacePtr)
{
	if (!libBase)
	{
		return FALSE;
	}
		
	if (!interfaceName)
	{
		interfaceName = "main";
	}
		
	if (!(*interfacePtr = IExec->GetInterface(libBase, interfaceName, interfaceVersion, NULL)))
	{
		return FALSE;
	}
	
	return TRUE;
}

void DropIFace(struct Interface **interfacePtr)
{
	if (*interfacePtr)
	{
		IExec->DropInterface(*interfacePtr);
		*interfacePtr = NULL;
	}
}

/*
CONST_STRPTR GetLocaleString(uint32 id)
{
	LONG i=0;

	while (CatCompArray[i].cca_ID != id)
		i++;

	if (catalog)
		return ILocale->GetCatalogStr(catalog, id, CatCompArray[i].cca_Str);

	return CatCompArray[i].cca_Str;
}
*/

void CloseAllLibraries(void)
{
/*
	if (ILocale)
	{
		if (catalog)
		{
			ILocale->CloseCatalog(catalog);
			catalog = (struct Catalog *)NULL;
		}
	
		IExec->DropInterface((struct Interface *)ILocale);
		ILocale = NULL;
	}

	if (LocaleBase)
	{
		IExec->CloseLibrary(LocaleBase);
		LocaleBase = NULL;
	}
	
	DropIFace((struct Interface **)&IAsl);
	CloseLib(&AslBase);
	
	DropIFace((struct Interface **)&IDataTypes);
	CloseLib(&DataTypesBase);
	
	DropIFace((struct Interface **)&IP96);
	CloseLib(&P96Base);
	
	DropIFace((struct Interface **)&IPopupMenu);
	CloseLib(&PopupMenuBase);

	DropIFace((struct Interface **)&IPrefsObjects);
	CloseLib(&ApplicationBase);

	DropIFace((struct Interface **)&IGraphics);
	CloseLib(&GraphicsBase);

	DropIFace((struct Interface **)&IIntuition);
	CloseLib(&IntuitionBase);

	if (ITimer)
	{
		IExec->DropInterface((struct Interface *)ITimer);
		ITimer = NULL;
	}

	if (TimerBase)
	{
		IExec->CloseDevice((struct IORequest *) &TimeRequest);
		TimerBase = NULL;
	}

	DropIFace((struct Interface **)&IDOS);
	CloseLib(&DOSBase);

	DropIFace((struct Interface **)&IUtility);
	CloseLib(&UtilityBase);
*/	
	DropIFace((struct Interface **)&INewlib);
	CloseLib(&NewlibBase);
}

BOOL OpenAllLibraries(void)
{
	CONST_STRPTR libName = NULL;
	BOOL ok = TRUE;

	libName="newlib.library";
	ok &= OpenLib(libName, 4, &NewlibBase);
	ok &= GetIFace(libName, NewlibBase, NULL, 1, (struct Interface **)&INewlib);
	
/*
	libName="utility.library";
	ok &= OpenLib(libName, 50, &UtilityBase);
	ok &= GetIFace(libName, UtilityBase, NULL, 1, (struct Interface **)&IUtility);
	
	libName="dos.library";
	ok &= OpenLib(libName, 50, &DOSBase);
	ok &= GetIFace(libName, DOSBase, NULL, 1, (struct Interface **)&IDOS);
		
	if (!IExec->OpenDevice(TIMERNAME, UNIT_MICROHZ, (struct IORequest *) &TimeRequest, 0L))
	{
		TimerBase = (struct Library *)TimeRequest.tr_node.io_Device;
		if (TimerBase)
		{
			ITimer = (struct TimerIFace *)IExec->GetInterface(TimerBase, "main", 1, NULL);
			if (!ITimer)
				ok = FALSE;
		}
		else ok = FALSE;
	}
	else ok = FALSE;
		
	libName="intuition.library";
	ok &= OpenLib(libName, 50, &IntuitionBase);
	ok &= GetIFace(libName, IntuitionBase, NULL, 1, (struct Interface **)&IIntuition);
	
	libName="graphics.library";
	ok &= OpenLib(libName, 48, &GraphicsBase);
	ok &= GetIFace(libName, GraphicsBase, NULL, 1, (struct Interface **)&IGraphics);

	libName="application.library";
	ok &= OpenLib(libName, 51, &ApplicationBase);
	ok &= GetIFace(libName, ApplicationBase, "prefsobjects", 1, (struct Interface **)&IPrefsObjects);
	
	libName="popupmenu.class";
	ok &= OpenLib(libName, 50, &PopupMenuBase);
	ok &= GetIFace(libName, PopupMenuBase, NULL, 1, (struct Interface **)&IPopupMenu);
	
	libName="Picasso96API.library";
	ok &= OpenLib(libName, 2, &P96Base);
	ok &= GetIFace(libName, P96Base, NULL, 1, (struct Interface **)&IP96);
	
	DataTypesBase = IExec->OpenLibrary("datatypes.library", 44L);
	if (DataTypesBase)
	{
		IDataTypes = (struct DataTypesIFace *)IExec->GetInterface(DataTypesBase, "main", 1, NULL);
		if (!IDataTypes)
			ok = FALSE;
	}
	else ok = FALSE;
	
	libName="datatypes.library";
	ok &= OpenLib(libName, 44, &DataTypesBase);
	ok &= GetIFace(libName, DataTypesBase, NULL, 1, (struct Interface **)&IDataTypes);
	
	LocaleBase = IExec->OpenLibrary("locale.library", 50L);
	if (LocaleBase)
	{
		ILocale = (struct LocaleIFace *)IExec->GetInterface(LocaleBase, "main", 1, NULL);
		if (ILocale)
			catalog = ILocale->OpenCatalog((struct Locale *)NULL, "sys/amidock_dockies.catalog", NULL);
		else
			ok = FALSE;
	}
	else ok = FALSE;
*/	
	if (!ok)
		CloseAllLibraries();
		
	return ok;
}
