#include <exec/libraries.h>
#include <exec/types.h>
#include <exec/memory.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <libraries/docky.h>
#include <interfaces/docky.h>

extern struct ExecIFace *IExec;

//#define DOCKY_DEBUG

// ---------------

struct DockyData
{
	struct DockyObjectNr self;
	struct DockySize ds;
	ULONG *destination;

	struct DockyPosition mousepos, pointpos;
	struct DockyDockyDND dnd;
	BOOL leftmouse;

	BOOL in;
	LONG dx,dy;
};

// ---------------

static void *docky_vectors[];

static struct TagItem dockyTags[] =
{
	{MIT_Name,			(uint32)"docky"},
	{MIT_VectorTable,	(uint32)docky_vectors},
	{MIT_DataSize,		(uint32)(sizeof(struct DockyData))},
	{MIT_Flags,			IFLF_PRIVATE},
	{MIT_Version,		1},
	{TAG_DONE,			0}
};

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

static void *lib_manager_vectors[] =
{
	(void *)_manager_Obtain,
	(void *)_manager_Release,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)0,
	(void *)-1,
};

static struct TagItem lib_managerTags[] =
{
	{MIT_Name,			(ULONG)"__library"},
	{MIT_VectorTable,   (ULONG)lib_manager_vectors},
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
	{CLT_DataSize,		(uint32)(sizeof(struct Library))},
	{CLT_Interfaces,	(uint32)libInterfaces},
	{TAG_DONE,			0}
};


void drawImage(struct DockyData *dd)
{

	// do periodic things only one time and as last thing in this context

	if (!dd->in)
	{
		dd->pointpos.x+=dd->dx;
		dd->pointpos.y+=dd->dy;

		if (dd->pointpos.x<2 || dd->pointpos.x>=dd->ds.width-3)
		{
			dd->dx*=-1;
			dd->pointpos.x+=dd->dx;
		}

		if (dd->pointpos.y<2 || dd->pointpos.y>=dd->ds.height-3)
		{
			dd->dy*=-1;
			dd->pointpos.y+=dd->dy;
		}
	}

	if (dd->destination)
	{
		ULONG *ptr=(ULONG *)dd->destination;
		struct DockyPosition p;
		int x, y, w, h, ww;
		BOOL leftmouse;


		leftmouse=dd->leftmouse;
		w=dd->ds.width;
		h=dd->ds.height;
		p=dd->pointpos;

		if (leftmouse)
			ww=9;
		else
			ww=5;

		p.x-=ww/2;
		p.y-=ww/2;

		if (p.x<0)
			p.x=0;
		else if (p.x>=(w-ww-1))
			p.x=(w-ww);

		if (p.y<0)
			p.y=0;
		else if (p.y>=(h-ww-1))
			p.y=(h-ww);

		for(y=0; y<h; y++)
			for(x=0; x<w; x++)
			{
				if ( x>=p.x && x<(p.x+ww) && y>=p.y && y<(p.y+ww) )
				{
					if (leftmouse)
						*ptr++=0x00ff0000;
					else
						*ptr++=0x00ffffff;
				}
				else
				{
					*ptr++=0x00224466;
				}
			}
	}
}



uint32 _docky_Obtain(struct DockyIFace *Self)
{
	#ifdef DOCKY_DEBUG
	IExec->DebugPrintF("dummydocky::_docky_Obtain()\n");
	#endif
	
	Self->Data.RefCount++;
	return Self->Data.RefCount;
}

uint32 _docky_Release(struct DockyIFace *Self)
{
	#ifdef DOCKY_DEBUG
	IExec->DebugPrintF("dummydocky::_docky_Release()\n");
	#endif
	
	Self->Data.RefCount--;
	
	if (!Self->Data.RefCount && (Self->Data.Flags & IFLF_CLONED))
	{
		IExec->DeleteInterface((struct Interface *)Self);
		return 0;
	}
	
	return Self->Data.RefCount;
}

struct DockyIFace * _docky_Clone(struct DockyIFace *Self)
{
	struct DockyIFace *docky;

	#ifdef DOCKY_DEBUG
	IExec->DebugPrintF("dummydocky::_docky_Clone()\n");
	#endif
	
	docky = (struct DockyIFace *)IExec->MakeInterface(NULL, dockyTags);
	if (docky)
	{
		struct DockyData *dd = (struct DockyData *) ((uint32)docky - docky->Data.NegativeSize); 

		docky->Data.Flags |= IFLF_CLONED;
		
		dd->ds.width=32;
		dd->ds.height=32;

		srand((int)dd); // randomize

		dd->pointpos.x=5+(rand()%20);
		dd->pointpos.y=5+(rand()%20);
		dd->in=FALSE;
		dd->dx=-1+((rand()%2)*2);
		dd->dy=-1+((rand()%2)*2);
	}
	
	return docky;
}

void _docky_Expunge(struct DockyIFace *Self)
{
	#ifdef DOCKY_DEBUG
	IExec->DebugPrintF("dummydocky::_docky_Expunge()\n");
	#endif
}


BOOL _docky_DockyGet(struct DockyIFace *Self,
			 uint32 msgType,
			 uint32 * msgData)
{
	struct DockyData *dd = (struct DockyData *) ((uint32)Self - Self->Data.NegativeSize); 
	BOOL result=TRUE;

	switch (msgType)
	{
		case DOCKYGET_Version:
			*msgData = DOCKYVERSION;
			break;

		case DOCKYGET_GetSize:
			*((struct DockySize *)msgData) = dd->ds;
			break;

		case DOCKYGET_FrameDelay:
			*msgData = 1;
			break;

		case DOCKYGET_RenderMode:
			*msgData = DOCKYRENDERMODE_ARGB;
			break;

		case DOCKYGET_Notifications:
			*msgData = ~0;
			break;

		default:
			result=FALSE;
			break;
	}

	return result;
}


BOOL _docky_DockySet(struct DockyIFace *Self,
			 uint32 msgType,
			 uint32 msgData)
{
	struct DockyData *dd = (struct DockyData *) ((uint32)Self - Self->Data.NegativeSize); 
	BOOL result=TRUE;

	switch (msgType)
	{
		case DOCKYSET_RenderDestination:
			{
				struct DockyRenderDestination *drd=(struct DockyRenderDestination *)msgData;

				dd->ds=drd->renderSize;

				if (drd->renderMode==DOCKYRENDERMODE_ARGB)
					dd->destination=(ULONG *)drd->render.RGB;
				else
					dd->destination=NULL;
			}
			break;

		case DOCKYSET_RedrawNow:
			drawImage(dd);
			break;

		case DOCKYSET_DockTypeChange:
			{
				struct DockyDockType *ddt=(struct DockyDockType *)msgData;
				if (dd->self.dockNr==ddt->dockNr && ddt->dockType!=AMIDOCK_DockType_Icons)
					result=FALSE;
			}
			break;

		case DOCKYSET_DockyChange:
			dd->self=*((struct DockyObjectNr *)msgData);
			break;

		case DOCKYSET_MouseMove:
			{
				struct DockyPosition *dp=(struct DockyPosition *)msgData;
				dd->mousepos=*dp;

				if (dp->x>=0 && dp->y>=0 && dp->x<dd->ds.width && dp->y<dd->ds.height)
				{
					dd->pointpos=*dp;

					if (dd->pointpos.x<2)
						dd->pointpos.x=2;
					else if (dd->pointpos.x>dd->ds.width-4)
						dd->pointpos.x=dd->ds.width-4;

					if (dd->pointpos.y<2)
						dd->pointpos.y=2;
					else if (dd->pointpos.y>dd->ds.height-4)
						dd->pointpos.y=dd->ds.height-4;

					dd->in=TRUE;
				}
				else dd->in=FALSE;

				
			}
			break;

		case DOCKYSET_SelectChange:
			dd->leftmouse=(BOOL) msgData;
			break;

		default:
			result=FALSE;
			break;
	}

	return result;
}

BOOL _docky_DockyProcess(struct DockyIFace *Self,
			 uint32 turnCount,
			 uint32 * msgType,
			 uint32 * msgData,
			 BOOL * anotherTurn)
{
	//struct DockyData *dd = (struct DockyData *) ((uint32)Self - Self->Data.NegativeSize); 

	// we need no messages
	// msgType, msgData and anotherTurn are set by AmiDock already to NULL, NULL and FALSE
	// *msgType=0;
	// *msgData=0;
	// *anotherTurn=FALSE;

	return TRUE; // needs drawing?
}

static void *docky_vectors[] = 
{
	(void *)_docky_Obtain,
	(void *)_docky_Release,
	(void *)_docky_Expunge,
	(void *)_docky_Clone,
	(void *)_docky_DockyGet,
	(void *)_docky_DockySet,
	(void *)_docky_DockyProcess,
	(void *)-1
};

struct Library *CreateDockyLibrary(void)
{
	return IExec->CreateLibrary(libCreateTags);
}
