;/*  To compile:
gcc -o CloseTest CloseTest.c -lauto
quit
*/

#include <dos/dos.h>
#include <images/bitmap.h>
#include <classes/window.h>
#include <gadgets/clicktab.h>
#include <intuition/gui.h>
#include <prefs/gui.h>

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/bitmap.h>
#include <proto/dos.h>
#include <proto/clicktab.h>
#include <proto/bitmap.h>
#include <proto/utility.h>


//	Forward references (function prototypes)

void	DisconnectList (void);
void	ReconnectList (struct Node *currNode);

struct	IntuitionIFace		*IIntuition;
struct	Library			*WindowBase;
struct	WindowIFace		*IWindow;
struct	Library			*LayoutBase;
struct	LayoutIFace		*ILayout;
struct	Library			*ClickTabBase;
struct	ClickTabIFace		*IClickTab;
struct	Library			*BitMapBase;
struct	BitMapIFace		*IBitMap;
Class					*ClickTabClass;
struct	MsgPort			*AppPort;
struct	Window			*window = NULL;
struct	List			TabList;
struct	Screen			*screen;

enum
{
	OBJ_DISK,
	OBJ_CLICKTAB,
	OBJ_CLOSEIMAGE,
	OBJ_QUIT,
	OBJ_CLICKTABLAYOUT,
	OBJ_NUM
};

Object	*winObject;
Object	*Objects[OBJ_NUM];

int32	count;
int32	numTabs = 0,
		currTab = 0;

TEXT	TextBuff[16];
BOOL	disabled = FALSE;

/* some defines to make casting objects easier */
#define OBJ(x) Objects[x]
#define GAD(x) (struct Gadget *)Objects[x]

#define	NUM_NODES	4
#define	MAX_NODES	8

void
MakeWindow (void)
{
	winObject = IIntuition->NewObject(NULL, "window.class",
		WA_ScreenTitle,			"ReAction Example",
		WA_Title,				"ClickTab Example",
		WA_DragBar,				TRUE,
		WA_CloseGadget,			TRUE,
		WA_SizeGadget,			TRUE,
		WA_DepthGadget,			TRUE,
		WA_Activate,			TRUE,
		WA_SmartRefresh,		TRUE,
		WINDOW_IconifyGadget,	TRUE,
		WINDOW_IconTitle,		"Iconified",
		WINDOW_AppPort,			AppPort,
		WINDOW_Position,		WPOS_CENTERSCREEN,
		WINDOW_Layout,			IIntuition->NewObject(NULL, "layout.gadget",
			LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
			LAYOUT_AddChild, OBJ(OBJ_CLICKTABLAYOUT) = IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_DeferLayout, 		TRUE,
				LAYOUT_FixedVert, 			FALSE,
				LAYOUT_AddChild,			OBJ(OBJ_CLICKTAB) = IIntuition->NewObject(NULL, "clicktab.gadget",
					GA_ID,				OBJ_CLICKTAB,
					GA_RelVerify,			TRUE,
					CLICKTAB_Labels,		&TabList,	  /* supply the correct list :) */
					CLICKTAB_Current,		0,
					CLICKTAB_CloseImage,	Objects[OBJ_CLOSEIMAGE],	/* tell clicktab to use our BOOPSI image for the close gadget */
				TAG_DONE),
			TAG_DONE),

			LAYOUT_AddChild,			IIntuition->NewObject(NULL, "button.gadget", GA_Text, "_Quit", GA_ID, OBJ_QUIT, GA_RelVerify, TRUE, TAG_DONE),
			CHILD_CacheDomain,		FALSE,

		TAG_DONE),
	TAG_DONE);
}


int main()
{
	/* track the current node */
	struct	Node			*currNode;

	/* make up a list of Tab nodes */
	IExec->NewList (&TabList);

	for (count = 0; count < NUM_NODES; count++)
	{
		IUtility->SNPrintf(TextBuff, 16, "Tab %ld", count);
		currNode = IClickTab->AllocClickTabNode (
							TNA_Text, TextBuff,
							TNA_Number, count,
							TNA_Disabled, FALSE,
							TNA_CloseGadget, TRUE,   /* this node has a close gadget */
							TAG_END);
		IExec->AddTail (&TabList, currNode);
		numTabs++;
	}

	/* we need a screen pointer for the images we will load */
	screen = IIntuition->LockPubScreen( NULL );
	
	/* Now load the images we will use for the close gadget in each tab.
	 * Here we load three images, one for the normal state of the close gadget,
	 * one for the pressed state, and the last for the disabled state. 
	 * This creates a BOOPSI image which can adapt to user interaction. 
	 * The normal and pressed images are used in the currently active tab, while
	 * the disabled image is used in the non-active tabs. By supplying the disabled 
	 * image with reduced colour intensity or in grey-scale, we can give the 
	 * impression that the active tabs close gadget has the most importance.
	 */
	Objects[OBJ_CLOSEIMAGE] = IIntuition->NewObject( NULL, "bitmap.image",
			BITMAP_SourceFile, "cancel",
			BITMAP_SelectSourceFile, "cancel_s",
			BITMAP_Screen, screen,
			BITMAP_Masking, TRUE,
		TAG_DONE );

	if ((IWindow != NULL) &&
		(ILayout != NULL) &&
		(IClickTab != NULL) &&
		(IBitMap != NULL) &&
		((AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_DONE)) != NULL))
	{
		MakeWindow();
		if (window = (struct Window*)IIntuition->IDoMethod(winObject, WM_OPEN))
		{
			uint32
				sigmask	 = 0,
				siggot		= 0,
				result		= 0;
			uint16
				code		= 0,
				CTposition;
			BOOL
				done		= FALSE;
			struct Node *node = NULL;

			CTposition = 0;

			/* set the current node pointer */
			IIntuition->GetAttrs( GAD(OBJ_CLICKTAB), CLICKTAB_CurrentNode, &currNode, TAG_DONE );

			IIntuition->GetAttr(WINDOW_SigMask, winObject, &sigmask);
			while (!done)
			{
				siggot = IExec->Wait(sigmask | SIGBREAKF_CTRL_C);

				if (siggot & SIGBREAKF_CTRL_C)
					done = TRUE;

				while ((result = IIntuition->IDoMethod(winObject, WM_HANDLEINPUT, &code)))
				{
					switch(result & WMHI_CLASSMASK)
					{
						case WMHI_CLOSEWINDOW:
							done = TRUE;
							break;

						case WMHI_GADGETUP:
							switch (result & WMHI_GADGETMASK)
							{
							case	OBJ_CLICKTAB:
								/* because our nodes have a close gadget, it is possible the user has requested
								 * to close one, so we need to check that first.
								 */
								IIntuition->GetAttrs( Objects[OBJ_CLICKTAB], CLICKTAB_NodeClosed, &currNode, TAG_DONE );
								if( currNode )
								{
									IDOS->Printf("Close gadget hit on node: %p\n", currNode );
									
									/* it appears that a close gadget was selected, and a pointer to the 
									 * node that was clicked has been read, CLICKTAB_Closed and 
									 * CLICKTAB_NodeClosed are "one-shot", which means once they have 
									 * been read once, they are cleared. This stops any looping trying to 
									 * close the same tab again. 
									 * Now we simply remove the node from the list. More complex layouts
									 * may need to do additional work. */
									 
									 /* we need to get the node to be active after this one closes */
									 struct Node *nextNode;
									 
									 DisconnectList();
									 
									 /* get the tab node to the left of this one */
									 nextNode = IExec->GetPred( currNode );
									 if( !nextNode )
									 {
									 	/* there is no lefthand tab, so get the one to the right */
									 	nextNode = IExec->GetSucc( currNode );
									 }
									 
									 IDOS->Printf("Removing node from list\n");
									 
									 IExec->Remove( currNode );
									 
									 IClickTab->FreeClickTabNode( currNode );
									 
									 if( !nextNode )
									 {
									 	IDOS->Printf("Last node closed, quitting\n");
									 	
									 	done = TRUE;
									 }
									 
									 ReconnectList( nextNode );
								}
								else
								{
									/* the user changed tabs, we could do a variety of things here */
									IIntuition->GetAttrs( GAD(OBJ_CLICKTAB), CLICKTAB_CurrentNode, &currNode, TAG_DONE );
									
									IDOS->Printf("User switched to node: %p\n", currNode );
								}
								
								break;

							case	OBJ_QUIT:
								done=TRUE;
								break;
							}
							break;

						case	WMHI_ICONIFY:
							if (IIntuition->IDoMethod(winObject, WM_ICONIFY)) window = NULL;
							break;

						case	WMHI_UNICONIFY:
							window = (struct Window*)IIntuition->IDoMethod(winObject, WM_OPEN);
							break;
					}
				}
			}
		}

        /* free any clicktab nodes */
        IClickTab->FreeClickTabList( &TabList );
        
		IIntuition->DisposeObject(winObject);
		IExec->FreeSysObject(ASOT_PORT, AppPort);
	}

	/* free the close gadget image we supplied */
	if( Objects[OBJ_CLOSEIMAGE] )
		IIntuition->DisposeObject( Objects[OBJ_CLOSEIMAGE] );
    
	/* release the default public screen */
	if( screen )
		IIntuition->UnlockPubScreen( NULL, screen );
	
	return 0;
}


/*	Function disconnects List from gadget
*/
void
DisconnectList (void)
{
	IIntuition->SetAttrs (OBJ(OBJ_CLICKTAB),
						CLICKTAB_Labels, ~0, // this was passing NULL
						TAG_DONE);
}


/*	Function reconnects List to gadget
*/
void
ReconnectList ( struct Node *currNode )
{
	ULONG total;

	IIntuition->RefreshSetGadgetAttrs (GAD(OBJ_CLICKTAB), window, NULL,
										CLICKTAB_LabelTruncate,		TRUE,
										CLICKTAB_Labels,            &TabList,
										CLICKTAB_CurrentNode,       currNode,
										TAG_DONE);
	IIntuition->GetAttrs( GAD(OBJ_CLICKTAB), CLICKTAB_Total, &total, TAG_DONE );
	IDOS->Printf("list has %lu nodes\n", total);
}
