/*
 *  $VER: init.c $Revision: 1.2 $ (09-Jan-2004)
 *
 *  This file is part of "SkeletonDocky".
 *
 *  (C) Copyright 2004 Hyperion Entertainment
 *  	All rights reserved
 *
 * $Id: init.c,v 1.2 2006-05-28 21:18:54 srobl Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.1  2005/11/02 22:52:44  srobl
 * Initial chechin
 *
 *
 *
 */

#include <exec/exec.h>
#include <proto/exec.h>
#include <exec/libraries.h>
#include <proto/docky.h>
#include <stdarg.h>
#include "DockyBase.h"
#include "DockyData.h"

/* Version Tag */
#include "Skeleton.docky_rev.h"
#define LIBNAME "Skeleton.docky"
volatile char __attribute__((unused)) verstag[] = VERSTAG;

struct ExecIFace *IExec;

int _start(void)
{
	return 0;
}

/* Open the library */
struct Library *libOpen(struct LibraryManagerInterface *Self, ULONG version)
{
	struct Library *libBase = (struct Library *)Self->Data.LibBase; 
//(struct ExecIFace *)(*(struct ExecBase **)4)->DebugPrintF("libOpen\n");
	
	libBase->lib_Flags |= LIBF_DELEXP;

	/* Add any specific open code here 
   	Return 0 before incrementing OpenCnt to fail opening */

	/* Add up the open count */
	((struct Library *)libBase)->lib_OpenCnt++;
	return libBase;
}


/* Close the library */
APTR libClose(struct LibraryManagerInterface *Self)
{
	struct Library *libBase = (struct Library *)Self->Data.LibBase;
	/* Make sure to undo what open did */

//(struct ExecIFace *)(*(struct ExecBase **)4)->DebugPrintF("libClose\n");

	/* Make the close count */
	((struct Library *)libBase)->lib_OpenCnt--;

	return 0;
}





/* Expunge the library */
APTR libExpunge(struct LibraryManagerInterface *Self)
{
	/* If your library cannot be expunged, return 0 */
	APTR result = (APTR)0;
	struct Library *libBase = (struct Library *)Self->Data.LibBase;
	struct DockyBase *DockyLibBase = (struct DockyBase *)libBase;
		
//IExec->DebugPrintF("libExpunge\n");
	
	if (libBase->lib_OpenCnt == 0)
	{
		result = (APTR)DockyLibBase->SegList;
		/* Undo what the init code did */
		
		CloseAllLibraries();

		IExec->Remove((struct Node *)libBase);
		IExec->DeleteLibrary(libBase);
	}
	else
	{
		result = (APTR)0;
		libBase->lib_Flags |= LIBF_DELEXP;
	}
	return result;
}

/* The ROMTAG Init Function */
struct Library *libInit(struct Library *libBase, APTR seglist, struct Interface *exec)
{
	struct DockyBase *DockyLibBase = (struct DockyBase *)libBase;
	IExec = (struct ExecIFace *)exec;

	libBase->lib_Node.ln_Type = NT_LIBRARY;
	libBase->lib_Node.ln_Pri  = 0;
	libBase->lib_Node.ln_Name = LIBNAME;
	libBase->lib_Flags        = LIBF_SUMUSED|LIBF_CHANGED;
	libBase->lib_Version      = VERSION;
	libBase->lib_Revision     = REVISION;
	libBase->lib_IdString     = VSTRING;
	
//IExec->DebugPrintF("lensdocky::libInit\n");

	/* This assumes your library base has a seglist field */
	DockyLibBase->SegList = seglist;

	/* Additional libraries: */

	if (OpenAllLibraries())
	{
		return libBase;
	}
	
   	return NULL;
}

/* ------------------- Manager Interface ------------------------ */
/* These are generic. Replace if you need more fancy stuff */
static LONG _manager_Obtain(struct LibraryManagerInterface *Self)
{
	Self->Data.RefCount++;
	return Self->Data.RefCount;
}

static ULONG _manager_Release(struct LibraryManagerInterface *Self)
{
	Self->Data.RefCount--;
	return Self->Data.RefCount;
}

/* Manager interface vectors */
static void *lib_manager_vectors[] =
{
	(void *)_manager_Obtain,
	(void *)_manager_Release,
	(void *)0,
	(void *)0,
	(void *)libOpen,
	(void *)libClose,
	(void *)libExpunge,
	(void *)0,
	(void *)-1,
};

/* "__library" interface tag list */
static struct TagItem lib_managerTags[] =
{
	{MIT_Name,			(ULONG)"__library"},
	{MIT_VectorTable,   (ULONG)lib_manager_vectors},
	{MIT_Version,		1},
	{TAG_DONE,			0}
};

/* ------------------- Library Interface(s) ------------------------ */

#include "docky_vectors.c"

/* Uncomment this line (and see below) if your library has a 68k jump table */
/* extern ULONG VecTable68K; */

struct TagItem dockyTags[] =
{
	{MIT_Name,			(uint32)"docky"},
	{MIT_VectorTable,   (uint32)docky_vectors},
	{MIT_DataSize,		(uint32)(sizeof(struct DockyData))},
	{MIT_Flags,			IFLF_PRIVATE},
	{MIT_Version,		1},
	{TAG_DONE,			0}
};

static uint32 libInterfaces[] =
{
	(uint32)lib_managerTags,
	(uint32)dockyTags,
	(uint32)0
};

struct TagItem libCreateTags[] =
{
	{CLT_DataSize,		(uint32)(sizeof(struct DockyBase))},
	{CLT_InitFunc,		(uint32)libInit},
	{CLT_Interfaces,	(uint32)libInterfaces},
	{TAG_DONE,			0}
};


/* ------------------- ROM Tag ------------------------ */
struct Resident lib_res =
{
	RTC_MATCHWORD,
	&lib_res,
	&lib_res+1,
	RTF_NATIVE|RTF_AUTOINIT, /* Add RTF_COLDSTART if required */
	VERSION,
	NT_LIBRARY, /* Make this NT_DEVICE if needed */
	0, /* PRI */
	LIBNAME,
	VSTRING,
	libCreateTags
};

