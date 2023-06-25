/*
** Graphical diff example for diffview.library
**
*/


/* Uncomment this to use an external diff program instead of the built-in
** comparison of diffview.gadget. */
//#define USE_EXTERNAL_DIFF

#include <stdio.h>
#include <stdlib.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>

#define ALL_REACTION_CLASSES
#define ALL_REACTION_MACROS
#include <reaction/reaction.h>

#include <gadgets/diffview.h>
#include <proto/diffview.h>

struct Library          *IntuitionBase   = NULL;

struct Library          *WindowBase      = NULL;

struct Library          *LayoutBase      = NULL;
struct Library          *ScrollerBase    = NULL;
struct Library          *DiffViewBase    = NULL;

struct IntuitionIFace   *IIntuition      = NULL;
struct DiffViewIFace    *IDiffView       = NULL;

Class                   *WindowClass     = NULL;
Class                   *LayoutClass     = NULL;
Class                   *ScrollerClass   = NULL;
Class                   *DiffViewClass   = NULL;


enum
{
	OID_MAIN = 0,
	OID_LAST
};

enum
{
	WID_MAIN = 0,
	WID_LAST
};

enum
{
	GID_DIFFVIEW = 0,
	GID_VSCROLLER,
	GID_HSCROLLER,
	GID_LINECMP,
	GID_LCSCROLLER,
	GID_LAST
};

Object        *objs[OID_LAST];
struct Window *wins[WID_LAST];
uint32         wsig[WID_LAST];
struct Gadget *gads[GID_LAST];
uint32         gui_sigs;

STRPTR         argtemplate = "FILE1/A,FILE2/A";
int32          args[] = { 0, 0 };
struct RDArgs *rdargs;

APTR           diffobject = NULL;


TEXT tmpstr[4096];

BOOL generatediff_external(STRPTR filea, STRPTR fileb)
{
	uint32              result;
	TEXT                tmpname[256];
	struct DateStamp    ds;
	struct ExamineData *ed;
	STRPTR              errstr;
	BPTR                h;
	TEXT               *diffbuf = NULL, *newfbuf = NULL;
	uint32              diffbuflen,      newfbuflen;

	// Get a reasonably unique temp filename
	IDOS->DateStamp(&ds);
	sprintf(tmpname, "t:radiff%04x%04x%04x.tmp", (unsigned int)ds.ds_Days, (unsigned int)ds.ds_Minute, (unsigned int)ds.ds_Tick);
	snprintf(tmpstr, 4096, "diff >%s -u %s %s", tmpname, filea, fileb);
	tmpstr[4095] = 0;

	// Get a diff!
	result = IDOS->SystemTags(tmpstr, TAG_DONE);
	if (result > 1)
	{
		printf("diff returned %ld\n", result);
		return FALSE;
	}

	h = IDOS->Open(tmpname, MODE_OLDFILE);
	if (!h)
	{
		printf("Unable to open '%s'\n", tmpname);
		IDOS->Delete(tmpname);
		return FALSE;
	}

	ed = IDOS->ExamineObjectTags(EX_FileHandleInput, h, TAG_DONE);
	if (!ed)
	{
		IDOS->Close(h);
		printf("Unable to examine '%s'\n", tmpname);
		IDOS->Delete(tmpname);
		return FALSE;
	}

	diffbuflen = ed->FileSize;
	diffbuf    = IExec->AllocVecTags(diffbuflen+1, AVT_ClearWithValue, 0, TAG_DONE);
	if (!diffbuf)
	{
		IDOS->Close(h);
		printf("Out of memory\n");
		IDOS->Delete(tmpname);
		return FALSE;
	}

	result = IDOS->Read(h, diffbuf, diffbuflen);
	IDOS->Close(h);
	IDOS->Delete(tmpname);

	if (result != diffbuflen)
	{
		printf("Error reading '%s'\n", tmpname);
		IExec->FreeVec(diffbuf);
		return FALSE;
	}

	h = IDOS->Open(fileb, MODE_OLDFILE);
	if (!h)
	{
		printf("Unable to open '%s'\n", fileb);
		IExec->FreeVec(diffbuf);
		return FALSE;
	}

	ed = IDOS->ExamineObjectTags(EX_FileHandleInput, h, TAG_DONE);
	if (!ed)
	{
		IDOS->Close(h);
		IExec->FreeVec(diffbuf);
		printf("Unable to examine '%s'\n", fileb);
		return FALSE;
	}

	newfbuflen = ed->FileSize;
	newfbuf    = IExec->AllocVecTags(newfbuflen+1, AVT_ClearWithValue, 0, TAG_DONE);
	if (!newfbuf)
	{
		IDOS->Close(h);
		IExec->FreeVec(diffbuf);
		printf("Out of memory\n");
		return FALSE;
	}

	result = IDOS->Read(h, newfbuf, newfbuflen);
	IDOS->Close(h);

	if (result != newfbuflen)
	{
		printf("Error reading '%s'\n", fileb);
		IExec->FreeVec(diffbuf);
		IExec->FreeVec(newfbuf);
		return FALSE;
	}

	diffobject = IDiffView->CreateDiffObjectTags(DIFFOBJECT_Diffs,      diffbuf,
	                                             DIFFOBJECT_DiffsLen,   diffbuflen,
	                                             DIFFOBJECT_NewFile,    newfbuf,
	                                             DIFFOBJECT_NewFileLen, newfbuflen,
	                                             DIFFOBJECT_ErrorStr,   &errstr,
	                                             TAG_DONE);

	IExec->FreeVec(diffbuf);
	IExec->FreeVec(newfbuf);

	if(!diffobject)
	{
		printf( "Error creating the diffobject (%s)\n", (errstr==NULL) ? "Unknown" : errstr );
		return FALSE;
	}

	return TRUE;
}

BOOL generatediff_internal(STRPTR filea, STRPTR fileb)
{
	uint32              result;
	struct ExamineData *ed;
	STRPTR              errstr;
	BPTR                h;
	TEXT               *oldfbuf = NULL, *newfbuf = NULL;
	uint32              oldfbuflen,      newfbuflen;

	// Get file a!
	h = IDOS->Open(filea, MODE_OLDFILE);
	if (!h)
	{
		printf("Unable to open '%s'\n", filea);
		return FALSE;
	}

	ed = IDOS->ExamineObjectTags(EX_FileHandleInput, h, TAG_DONE);
	if (!ed)
	{
		IDOS->Close(h);
		printf("Unable to examine '%s'\n", filea);
		return FALSE;
	}

	oldfbuflen = ed->FileSize;
	oldfbuf    = IExec->AllocVecTags( oldfbuflen+1, AVT_ClearWithValue, 0, TAG_DONE );
	if (!oldfbuf)
	{
		IDOS->Close(h);
		printf("Out of memory\n");
		return FALSE;
	}

	result = IDOS->Read(h, oldfbuf, oldfbuflen);
	IDOS->Close(h);

	if (result != oldfbuflen)
	{
		printf("Error reading '%s'\n", filea);
		IExec->FreeVec(oldfbuf);
		return FALSE;
	}

	h = IDOS->Open(fileb, MODE_OLDFILE);
	if (!h)
	{
		printf("Unable to open '%s'\n", fileb);
		IExec->FreeVec(oldfbuf);
		return FALSE;
	}

	ed = IDOS->ExamineObjectTags(EX_FileHandleInput, h, TAG_DONE);
	if (!ed)
	{
		IDOS->Close(h);
		IExec->FreeVec(oldfbuf);
		printf("Unable to examine '%s'\n", fileb);
		return FALSE;
	}


	newfbuflen = ed->FileSize;
	newfbuf    = IExec->AllocVecTags( newfbuflen+1, AVT_ClearWithValue, 0, TAG_DONE );
	if (!newfbuf)
	{
		IDOS->Close(h);
		IExec->FreeVec(oldfbuf);
		printf("Out of memory\n");
		return FALSE;
	}

	result = IDOS->Read(h, newfbuf, newfbuflen);
	IDOS->Close(h);

	if (result != newfbuflen)
	{
		printf( "Error reading '%s'\n", fileb );
		IExec->FreeVec( oldfbuf );
		IExec->FreeVec( newfbuf );
		return FALSE;
	}

	diffobject = IDiffView->CreateDiffObjectTags(DIFFOBJECT_OldFile,     oldfbuf,
	                                             DIFFOBJECT_OldFileLen,  oldfbuflen,
	                                             DIFFOBJECT_OldFileName, filea,
	                                             DIFFOBJECT_NewFile,     newfbuf,
	                                             DIFFOBJECT_NewFileLen,  newfbuflen,
	                                             DIFFOBJECT_NewFileName, fileb,
	                                             DIFFOBJECT_ErrorStr,    &errstr,
	                                             TAG_DONE);

	IExec->FreeVec(oldfbuf);
	IExec->FreeVec(newfbuf);

	if (!diffobject)
	{
		printf("Error creating the diffobject (%s)\n", (errstr==NULL) ? "Unknown" : errstr);
		return FALSE;
	}

	return TRUE;
}

BOOL init(void)
{
	int32 i;

	signal(SIGINT, SIG_IGN);
	
	for( i=0; i<OID_LAST; i++ ) objs[i] = NULL;
	for( i=0; i<WID_LAST; i++ ) wins[i] = NULL;
	for( i=0; i<GID_LAST; i++ ) gads[i] = NULL;

	rdargs = IDOS->ReadArgs(argtemplate, args, NULL);
	if (!rdargs)
	{
		printf("Bad Args!\nUsage: radiff %s\n", argtemplate);
		return FALSE;
	}

	IntuitionBase = IExec->OpenLibrary("intuition.library", 53);
	if (!IntuitionBase)
	{
		printf("Unable to open intuition.library v53+\n");
		return FALSE;
	}

	IIntuition = (struct IntuitionIFace *)IExec->GetInterface((struct Library *)IntuitionBase, "main", 1, NULL);
	if (!IIntuition)
	{
		printf("Unable to get the diffview interface\n");
		return FALSE;
	}

	WindowBase = (struct Library *)IIntuition->OpenClass("window.class", 53, &WindowClass);
	if (!WindowBase)
	{
		printf("Unable to open window.class v53+\n");
		return FALSE;
	}

	LayoutBase = (struct Library *)IIntuition->OpenClass("gadgets/layout.gadget", 53, &LayoutClass);
	if (!LayoutBase)
	{
		printf("Unable to open layout.gadget v53+\n");
		return FALSE;
	}

	ScrollerBase = (struct Library *)IIntuition->OpenClass("gadgets/scroller.gadget", 53, &ScrollerClass);
	if (!ScrollerBase)
	{
		printf("Unable to open scroller.gadget v53+\n");
		return FALSE;
	}

	DiffViewBase = (struct Library *)IIntuition->OpenClass("gadgets/diffview.gadget", 53, &DiffViewClass);
	if (!DiffViewBase)
	{
		printf( "Unable to open diffview.gadget\n" );
		return FALSE;
	}

	IDiffView = (struct DiffViewIFace *)IExec->GetInterface((struct Library *)DiffViewBase, "main", 1, NULL);
	if (!IDiffView)
	{
		printf( "Unable to get the diffview interface\n");
		return FALSE;
	}

#ifdef USE_EXTERNAL_DIFF
	if(!generatediff_external((STRPTR)args[0], (STRPTR)args[1]))
#else
	if(!generatediff_internal((STRPTR)args[0], (STRPTR)args[1]))
#endif
	{
		return FALSE;
	}

	objs[OID_MAIN] = (Object *)IIntuition->NewObject(WindowClass, NULL,
		WA_ScreenTitle,     "radiff",
		WA_Title,           "radiff",
		WA_Activate,        TRUE,
		WA_DepthGadget,     TRUE,
		WA_DragBar,         TRUE,
		WA_CloseGadget,     TRUE,
		WA_SizeGadget,      TRUE,
		WINDOW_Position,    WPOS_FULLSCREEN,
		WINDOW_ParentGroup, (Object *)IIntuition->NewObject(LayoutClass, NULL,
			LAYOUT_Orientation,   LAYOUT_ORIENT_VERT,
			LAYOUT_SpaceOuter,    TRUE,
			LAYOUT_DeferLayout,   TRUE,
			LAYOUT_AddChild,        IIntuition->NewObject(LayoutClass, NULL,
				LAYOUT_Orientation,       LAYOUT_ORIENT_HORIZ,
				LAYOUT_AddChild,          gads[GID_DIFFVIEW] = (struct Gadget *)IIntuition->NewObject(DiffViewClass, NULL,
					GA_ID,                      GID_DIFFVIEW,
					GA_RelVerify,               TRUE,
					DIFFVIEW_DiffObject,        diffobject,
					TAG_DONE ),
				CHILD_WeightedWidth,      10,
				LAYOUT_AddChild,          gads[GID_VSCROLLER] = (struct Gadget *)IIntuition->NewObject(ScrollerClass, NULL,
					GA_ID,                      GID_VSCROLLER,
					SCROLLER_Orientation,       SORIENT_VERT,
					TAG_DONE ),
				CHILD_WeightedWidth,      0,
				TAG_DONE ),
			CHILD_WeightedHeight,     10,
			LAYOUT_AddChild,          gads[GID_HSCROLLER] = (struct Gadget *)IIntuition->NewObject(ScrollerClass, NULL,
				GA_ID,                      GID_HSCROLLER,
				SCROLLER_Orientation,       SORIENT_HORIZ,
				TAG_DONE ),
			CHILD_WeightedHeight,     0,
			LAYOUT_AddChild,          gads[GID_LINECMP] = (struct Gadget *)IIntuition->NewObject(NULL, "linecmpgclass",
				GA_ID,                      GID_LINECMP,
				TAG_DONE ),
			CHILD_WeightedHeight,     0,
			LAYOUT_AddChild,          gads[GID_LCSCROLLER] = (struct Gadget *)IIntuition->NewObject(ScrollerClass, NULL,
				GA_ID,                      GID_LCSCROLLER,
				SCROLLER_Orientation,       SORIENT_HORIZ,
				TAG_DONE ),
			CHILD_WeightedHeight,     0,
			TAG_DONE ),
		TAG_DONE );
	if (!objs[OID_MAIN])
	{
		printf("Error creating GUI\n");
		return FALSE;
	}

	IIntuition->SetAttrs(gads[GID_DIFFVIEW],
		DIFFVIEW_VertScroller,  gads[GID_VSCROLLER],
		DIFFVIEW_HorizScroller, gads[GID_HSCROLLER],
		DIFFVIEW_LineCmp,       gads[GID_LINECMP],
		TAG_DONE);

	IIntuition->SetAttrs(gads[GID_LINECMP],
		LINECMP_HorizScroller, gads[GID_LCSCROLLER],
		TAG_DONE);

	wins[WID_MAIN] = (struct Window *)IIntuition->IDoMethod(objs[OID_MAIN], WM_OPEN, NULL);
	if (!wins[WID_MAIN])
	{
		printf( "Error opening window\n" );
		return FALSE;
	}

	wsig[WID_MAIN] = 1L<<wins[WID_MAIN]->UserPort->mp_SigBit;
	gui_sigs = wsig[WID_MAIN];

	return TRUE;
}

void shut(void)
{
	if (objs[OID_MAIN])
	{
		IIntuition->DisposeObject(objs[OID_MAIN]);
		objs[OID_MAIN] = NULL;
	}

	if (diffobject) IDiffView->FreeDiffObject(diffobject);
	if (rdargs) IDOS->FreeArgs(rdargs);

	if (IDiffView)     IExec->DropInterface((struct Interface *)IDiffView);
	if (DiffViewBase)  IIntuition->CloseClass((struct ClassLibrary *)DiffViewBase);
	if (ScrollerBase)  IIntuition->CloseClass((struct ClassLibrary *)ScrollerBase);
	if (LayoutBase)    IIntuition->CloseClass((struct ClassLibrary *)LayoutBase);
	if (WindowBase)    IIntuition->CloseClass((struct ClassLibrary *)WindowBase);
	if (IIntuition)    IExec->DropInterface((struct Interface *)IIntuition);
	if (IntuitionBase) IExec->CloseLibrary(IntuitionBase);
}

int main(int argc, char *argv[])
{
	if (init())
	{
		BOOL   done = FALSE;
		uint32 gotsigs;

		while(!done)
		{
			gotsigs = IExec->Wait(gui_sigs | SIGBREAKF_CTRL_C);
			
			if (gotsigs & SIGBREAKF_CTRL_C)
			{
				signal(SIGINT, SIG_IGN);
				done = TRUE;
			}
			
			if (gotsigs & wsig[WID_MAIN])
			{
				uint32 result;
				uint16 code;
				
				while ((result = IIntuition->IDoMethod( objs[OID_MAIN], WM_HANDLEINPUT, &code)) != WMHI_LASTMSG)
				{
					switch (result & WMHI_CLASSMASK)
					{
						case WMHI_CLOSEWINDOW:
							done = TRUE;
							break;
					}
				}
			}
		}
	}
	shut();

	return 0;
}

