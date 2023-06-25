;/*  To compile:
gcc -o TabTest TabTest.c -lauto
quit
*/

/*	To try adding the ClickTab AFTER the window object is laid out,
**	enable this definition.
*/
#define		ADD_AFTER_LAYOUT

#include <dos/dos.h>
#include <images/bitmap.h>
#include <classes/window.h>
#include <gadgets/clicktab.h>

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/dos.h>
#include <proto/clicktab.h>
#include <proto/bitmap.h>
#include <proto/utility.h>


//	Forward references (function prototypes)
void	AddTab (void);
void	ChangeTab (void);
void	RemoveTab (void);
void	DisableGadget (void);
void	DisconnectList (void);
void	ReconnectList (struct Node *currNode);

struct	IntuitionIFace	*IIntuition;
struct	Library			*WindowBase;
struct	WindowIFace		*IWindow;
struct	Library			*LayoutBase;
struct	LayoutIFace		*ILayout;
struct	Library			*ClickTabBase;
struct	ClickTabIFace	*IClickTab;
struct	Library			*BitMapBase;
struct	BitMapIFace		*IBitMap;
		Class			*ClickTabClass;
struct	MsgPort			*AppPort;
struct	Window			*window = NULL;
struct	List			TabList;

enum
{
	OBJ_DISK,
	OBJ_BUT_1,
	OBJ_BUT_2,
	OBJ_BUT_3,
	OBJ_BUT_4,
	OBJ_CLICKTAB,
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
#ifndef	ADD_AFTER_LAYOUT
				LAYOUT_DeferLayout, TRUE,
				LAYOUT_AddChild,		OBJ(OBJ_CLICKTAB) = IIntuition->NewObject(NULL, "clicktab.gadget",
					GA_ID,				OBJ_CLICKTAB,
					GA_RelVerify,		TRUE,
					CLICKTAB_Labels,	&TabList,	/* supply the correct list :) */
					CLICKTAB_Current,	0,
					GA_Disabled,		disabled,
				TAG_DONE),
#endif		//	def	ADD_AFTER_LAYOUT
			TAG_DONE),
			LAYOUT_AddChild,		IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_AddChild,	IIntuition->NewObject(NULL, "button.gadget", GA_Text, "_Add Tab", GA_ID, OBJ_BUT_1, GA_RelVerify, TRUE, TAG_DONE),
				LAYOUT_AddChild,	IIntuition->NewObject(NULL, "button.gadget", GA_Text, "_Chg Text", GA_ID, OBJ_BUT_2, GA_RelVerify, TRUE, TAG_DONE),
				LAYOUT_AddChild,	IIntuition->NewObject(NULL, "button.gadget", GA_Text, "_Rem Tab", GA_ID, OBJ_BUT_3, GA_RelVerify, TRUE, TAG_DONE),
				LAYOUT_AddChild,	IIntuition->NewObject(NULL, "button.gadget", GA_Text, "En/Disable", GA_ID, OBJ_BUT_4, GA_RelVerify, TRUE, TAG_DONE),
			TAG_DONE),			// HLayout

			LAYOUT_AddChild,		IIntuition->NewObject(NULL, "button.gadget", GA_Text, "_Quit", GA_ID, OBJ_QUIT, GA_RelVerify, TRUE, TAG_DONE),
			CHILD_CacheDomain,		FALSE,

		TAG_DONE),
	TAG_DONE);

#ifdef	ADD_AFTER_LAYOUT		// try adding afterwards

	IIntuition->SetAttrs( GAD(OBJ_CLICKTABLAYOUT), LAYOUT_AddChild,
		Objects[OBJ_CLICKTAB] = IIntuition->NewObject(NULL, "clicktab.gadget",
		 		GA_ID,				OBJ_CLICKTAB,
		 		GA_RelVerify,		TRUE,
				CLICKTAB_Labels,	&TabList,
				CLICKTAB_Current,	0,
				CLICKTAB_LabelTruncate, TRUE,
				/* the following attribute over-rides the GUI prefs settings */
				CLICKTAB_EvenSize,  FALSE,
				GA_Disabled,		disabled,
			TAG_DONE),
		TAG_DONE);

	if (GAD(OBJ_CLICKTAB) == NULL)
	{
		IDOS->Printf("couldn't create Tab Object\n");
	}

#endif		//	#ifndef	ADD_AFTER_LAYOUT
}


int
main()
{
	/* track the current node */
	struct	Node			*currNode;

//	make up a list of Tab nodes
	IExec->NewList (&TabList);

	for (count = 0; count < NUM_NODES; count++)
	{
		IUtility->SNPrintf(TextBuff, 16, "Tab %ld", count);
		currNode = IClickTab->AllocClickTabNode (
							TNA_Text, TextBuff,
							TNA_Number, count,
							TNA_Disabled, FALSE,
							TAG_END);
		IExec->AddTail (&TabList, currNode);
		numTabs++;
	}

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
#ifdef	ADD_AFTER_LAYOUT
//	add the ClickTab object now that we have a Window
			CTposition = IIntuition->AddGadget (window, GAD(OBJ_CLICKTAB), ~0);
			ILayout->RethinkLayout (GAD(OBJ_CLICKTAB), window, NULL, TRUE);
#endif		//	def	ADD_AFTER_LAYOUT

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
								IIntuition->GetAttrs( GAD(OBJ_CLICKTAB), CLICKTAB_CurrentNode, &currNode, TAG_DONE );
								break;

							case	OBJ_BUT_1:
								AddTab ();
								break;

							case	OBJ_BUT_2:
								ChangeTab ();
								break;

							case	OBJ_BUT_3:
								RemoveTab (  );
								break;

							case	OBJ_BUT_4:
								DisableGadget ();
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

		IIntuition->DisposeObject(winObject);
		IExec->FreeSysObject(ASOT_PORT, AppPort);
	}

	return 0;
}

/*	Function adds a Tab to the List
*/
void
AddTab (void)
{
	struct Node *currNode = NULL, *node;

	if (numTabs >= MAX_NODES)
	{
		IDOS->Printf("Too many nodes\n");
		return;
	}

	/* get the current node, we'll insert the new one after this */
	IIntuition->GetAttrs( GAD(OBJ_CLICKTAB), CLICKTAB_CurrentNode, &currNode, TAG_DONE );

	DisconnectList ();
	IUtility->SNPrintf(TextBuff, 16, "New %ld", numTabs);

	if ((node = IClickTab->AllocClickTabNode (
							TNA_Text,	TextBuff,
							TNA_Number,	numTabs,
							TAG_END)
			) != NULL)
	{
		/* if no active node, add it to the head */
		if( IsListEmpty( &TabList ) )
		{
			IExec->AddTail( &TabList, node );
		}
		else
		{
			IExec->Insert (&TabList, node, currNode);
		}
	}

	ReconnectList (node?node:currNode);

	numTabs++;
}

/*	Function Changes a Tab in the List. We only attempt to change the Tab label,
**	ie the text in the label.
*/
void
ChangeTab (void)
{
	struct Node *currNode;
	STRPTR text;

	IIntuition->GetAttrs( GAD(OBJ_CLICKTAB), CLICKTAB_CurrentNode, &currNode, TAG_DONE );

	if( currNode )
	{
		IClickTab->GetClickTabNodeAttrs( currNode, TNA_Text, &text, TAG_DONE );

		DisconnectList ();
		IUtility->SNPrintf(TextBuff, 16, "Changed");

		IClickTab->SetClickTabNodeAttrs (currNode,
										TNA_Text,	TextBuff,
										TAG_END);
		ReconnectList (currNode);
	}
}

/*	Function Removes a Tab from the List. What happens is that the tab is removed,
**	leaving a hole in the gadget.
*/
void
RemoveTab (void)
{
	struct Node *currNode;

	IIntuition->GetAttrs( GAD(OBJ_CLICKTAB), CLICKTAB_CurrentNode, &currNode, TAG_DONE );

	if( currNode )
	{
		struct Node *nextNode;

		/* which is to become the active one?
		** we'll first try the next tab, if that doesn't exist,
		** we'll try the previous one, and if that fails, it'll
		** be the only one left
		*/
		if( currNode->ln_Succ && currNode != TabList.lh_TailPred )
		{
			nextNode = currNode->ln_Succ;
		}
		else if( currNode->ln_Pred && currNode != TabList.lh_Head )
		{
			nextNode = currNode->ln_Pred;
		}
		else
		{
			nextNode = TabList.lh_Head;
		}

		DisconnectList ();

		IExec->Remove (currNode);

		/* don't forget to free the clicktab node after its removal! */
		IClickTab->FreeClickTabNode( currNode );

		--numTabs;

		ReconnectList (nextNode );

	}

}

/*	Function toggles Enable/Disable state of gadget (working)
*/
void
DisableGadget (void)
{
	int32	select = currTab;

	disabled = !disabled;
	IIntuition->SetAttrs (OBJ(OBJ_CLICKTAB),
					GA_Disabled, disabled,
					TAG_END);

	if (disabled)
	{
		select = -1;
	}
	IIntuition->RefreshSetGadgetAttrs (GAD(OBJ_CLICKTAB), window, NULL,
							CLICKTAB_Current,	select,
							TAG_DONE);
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
