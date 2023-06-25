;/* Page Example
gcc -o PageExample pageexample.c -lauto
quit
*/

/**
 **  PageExample.c -- Layout page gadget class Example.
 **
 **  This is a simple example testing some of the NEW capabilities
 **  of the clicktab and page layout gadget class. Note, the
 **  "embedded" page
 **
 **  Best viewed with TabSize = 2, or = 4.
 **/

#include <classes/window.h>
#include <gadgets/clicktab.h>
#include <images/label.h>

#include <proto/intuition.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/icon.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/listbrowser.h>
#include <proto/clicktab.h>
#include <proto/label.h>
#include <proto/string.h>
#include <proto/button.h>

enum
{
	GID_MAIN=0,
	GID_CLICKTAB,
	GID_PAGE,

	GID_ALIGN1,
	GID_ALIGN2,
	GID_ALIGN3,

	GID_PAGELAY1,
	GID_PAGELAY2,

	GID_COMPANY,
	GID_LASTNAME,
	GID_FIRSTNAME,
	GID_ADD1,
	GID_ADD2,
	GID_CITY,
	GID_STATE,
	GID_ZIPCODE,
	GID_PHONE,
	GID_FAX,

	GID_CUSTOMERS,
	GID_ORDERS,
	GID_DETAILS,
	GID_NEWORD,
	GID_EDITORD,
	GID_DELORD,

	GID_QUIT,
	GID_LAST
};

enum
{
	WID_MAIN=0,
	WID_LAST
};

enum
{
	OID_MAIN=0,
	OID_LAST
};


int main()
{
	struct Window *windows[WID_LAST];

	Object *gadgets[GID_LAST];

	Object *objects[OID_LAST];

	/* special case - reference buttonbase to make sure it autoinit! */
	if ( !WindowBase || !ButtonBase || !LayoutBase || !ClickTabBase ||
		 !StringBase || !LabelBase || !ListBrowserBase )
		return(30);

	struct MsgPort *AppPort = IExec->AllocSysObject(ASOT_PORT, TAG_DONE);

	if ( AppPort != NULL )
	{
		STRPTR tablabels[] = { "_Contacts","_Orders", NULL };

		if (tablabels)
		{
			/* Create the window object */
			objects[OID_MAIN] = IIntuition->NewObject(NULL, "window.class",
				WA_ScreenTitle, "ReAction Demo",
				WA_Title, "ReAction Page Example",
				WA_Activate, TRUE,
				WA_DepthGadget, TRUE,
				WA_DragBar, TRUE,
				WA_CloseGadget, TRUE,
				WA_SizeGadget, TRUE,
				WINDOW_IconifyGadget, TRUE,
				WINDOW_IconTitle, "Page",
				WINDOW_AppPort, AppPort,
				WINDOW_Position, WPOS_CENTERMOUSE,
				WINDOW_Layout, gadgets[GID_MAIN] = IIntuition->NewObject(NULL, "layout.gadget",
					LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
					LAYOUT_DeferLayout, TRUE,
					LAYOUT_SpaceOuter, TRUE,
					LAYOUT_SpaceInner, TRUE,

					LAYOUT_AddChild,  gadgets[GID_CLICKTAB] = IIntuition->NewObject(NULL, "clicktab.gadget",
						GA_ID, GID_CLICKTAB,
						GA_RelVerify, TRUE,
						GA_Text, tablabels,

						/* Embed the PageObject "inside" the Clicktab
						 * the clicktab's beveling will surround the page.
						 */
						CLICKTAB_PageGroup, gadgets[GID_PAGE] = IIntuition->NewObject(NULL, "page.gadget",
							/* We will defer layout/render changing pages! */
							LAYOUT_DeferLayout, TRUE,

							PAGE_Add, gadgets[GID_PAGELAY1] = IIntuition->NewObject(NULL, "layout.gadget",
								LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
								LAYOUT_SpaceOuter, TRUE,
								LAYOUT_SpaceInner, TRUE,

								LAYOUT_AddChild, gadgets[GID_COMPANY] = IIntuition->NewObject(NULL, "string.gadget",
									GA_ID, GID_COMPANY,
									GA_RelVerify, TRUE,
									GA_TabCycle, TRUE,
									STRINGA_MaxChars, 48,
									STRINGA_TextVal, "",
								TAG_DONE),
								CHILD_Label, IIntuition->NewObject(NULL, "label.image", LABEL_Text,"Company", TAG_DONE),
								CHILD_MinWidth, 200,

								LAYOUT_AddChild, gadgets[GID_ALIGN1] = IIntuition->NewObject(NULL, "layout.gadget",
									LAYOUT_AddChild, gadgets[GID_LASTNAME] = IIntuition->NewObject(NULL, "string.gadget",
										GA_ID, GID_LASTNAME,
										GA_RelVerify, TRUE,
										GA_TabCycle, TRUE,
										STRINGA_MaxChars, 48,
										STRINGA_TextVal, "",
									TAG_DONE),
									CHILD_Label, IIntuition->NewObject(NULL, "label.image", LABEL_Text,"Last", TAG_DONE),

									LAYOUT_AddChild, gadgets[GID_FIRSTNAME] = IIntuition->NewObject(NULL, "string.gadget",
										GA_ID, GID_FIRSTNAME,
										GA_RelVerify, TRUE,
										GA_TabCycle, TRUE,
										STRINGA_MaxChars, 48,
										STRINGA_TextVal, "",
									TAG_DONE),
									CHILD_Label, IIntuition->NewObject(NULL, "label.image", LABEL_Text,"First", TAG_DONE),
								TAG_DONE),
								CHILD_WeightedHeight, 0,

								LAYOUT_AddChild, gadgets[GID_ADD1] = IIntuition->NewObject(NULL, "string.gadget",
									GA_ID, GID_ADD1,
									GA_RelVerify, TRUE,
									GA_TabCycle, TRUE,
									STRINGA_MaxChars, 48,
									STRINGA_TextVal, "",
								TAG_DONE),
								CHILD_Label, IIntuition->NewObject(NULL, "label.image", LABEL_Text,"Address 1", TAG_DONE),

								LAYOUT_AddChild, gadgets[GID_ADD2] = IIntuition->NewObject(NULL, "string.gadget",
									GA_ID, GID_ADD2,
									GA_RelVerify, TRUE,
									GA_TabCycle, TRUE,
									STRINGA_MaxChars, 48,
									STRINGA_TextVal, "",
								TAG_DONE),
								CHILD_Label, IIntuition->NewObject(NULL, "label.image", LABEL_Text,"Address 2", TAG_DONE),

								LAYOUT_AddChild, gadgets[GID_ALIGN2] = IIntuition->NewObject(NULL, "layout.gadget",
									LAYOUT_AddChild, gadgets[GID_CITY] = IIntuition->NewObject(NULL, "string.gadget",
										GA_ID, GID_CITY,
										GA_RelVerify, TRUE,
										GA_TabCycle, TRUE,
										STRINGA_MaxChars, 48,
										STRINGA_TextVal, "",
									TAG_DONE),
									CHILD_Label, IIntuition->NewObject(NULL, "label.image", LABEL_Text,"City", TAG_DONE),
									CHILD_WeightedWidth, 100,

									LAYOUT_AddChild, gadgets[GID_STATE] = IIntuition->NewObject(NULL, "string.gadget",
										GA_ID, GID_STATE,
										GA_RelVerify, TRUE,
										GA_TabCycle, TRUE,
										STRINGA_MaxChars, 48,
										STRINGA_TextVal, "",
									TAG_DONE),
									CHILD_Label, IIntuition->NewObject(NULL, "label.image", LABEL_Text,"State", TAG_DONE),
									CHILD_WeightedWidth, 75,

									LAYOUT_AddChild, gadgets[GID_ZIPCODE] = IIntuition->NewObject(NULL, "string.gadget",
										GA_ID, GID_ZIPCODE,
										GA_RelVerify, TRUE,
										GA_TabCycle, TRUE,
										STRINGA_MaxChars, 24,
										STRINGA_TextVal, "",
									TAG_DONE),
									CHILD_Label, IIntuition->NewObject(NULL, "label.image", LABEL_Text,"ZipCode", TAG_DONE),
									CHILD_WeightedWidth, 25,
								TAG_DONE),
								CHILD_WeightedHeight, 0,

								LAYOUT_AddChild, gadgets[GID_ALIGN3] = IIntuition->NewObject(NULL, "layout.gadget",
									LAYOUT_BevelStyle, BVS_SBAR_VERT,
									LAYOUT_TopSpacing, 2,

									LAYOUT_AddChild, gadgets[GID_PHONE] = IIntuition->NewObject(NULL, "string.gadget",
										GA_ID, GID_PHONE,
										GA_RelVerify, TRUE,
										GA_TabCycle, TRUE,
										STRINGA_MaxChars, 48,
										STRINGA_TextVal, "",
									TAG_DONE),
									CHILD_Label, IIntuition->NewObject(NULL, "label.image", LABEL_Text,"Phone", TAG_DONE),

									LAYOUT_AddChild, gadgets[GID_FAX] = IIntuition->NewObject(NULL, "string.gadget",
										GA_ID, GID_FAX,
										GA_RelVerify, TRUE,
										GA_TabCycle, TRUE,
										STRINGA_MaxChars, 48,
										STRINGA_TextVal, "",
									TAG_DONE),
									CHILD_Label, IIntuition->NewObject(NULL, "label.image", LABEL_Text,"Fax", TAG_DONE),
								TAG_DONE),
								CHILD_WeightedHeight, 0,
							TAG_DONE),

							PAGE_Add, gadgets[GID_PAGELAY2] = IIntuition->NewObject(NULL, "layout.gadget",
								LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
								LAYOUT_SpaceOuter, TRUE,
								LAYOUT_SpaceInner, TRUE,

								LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
									LAYOUT_SpaceInner, TRUE,
									// customer
									LAYOUT_AddChild, gadgets[GID_CUSTOMERS] = IIntuition->NewObject(NULL, "listbrowser.gadget",
										GA_ID, GID_CUSTOMERS,
										GA_RelVerify, TRUE,
										LISTBROWSER_Labels, NULL,
										LISTBROWSER_ShowSelected, TRUE,
										LISTBROWSER_HorizontalProp, TRUE,
									TAG_DONE),
									CHILD_WeightedWidth, 30,

									LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
										LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
										LAYOUT_SpaceInner, TRUE,
										// orders
										LAYOUT_AddChild, gadgets[GID_ORDERS] = IIntuition->NewObject(NULL, "listbrowser.gadget",
											GA_ID, GID_ORDERS,
											GA_RelVerify, TRUE,
											LISTBROWSER_Labels, NULL,
											LISTBROWSER_ShowSelected, TRUE,
											LISTBROWSER_HorizontalProp, TRUE,
										TAG_DONE),
										// details
										LAYOUT_AddChild, gadgets[GID_DETAILS] = IIntuition->NewObject(NULL, "listbrowser.gadget",
											GA_ID, GID_DETAILS,
											GA_RelVerify, TRUE,
											LISTBROWSER_Labels, NULL,
											LISTBROWSER_ShowSelected, TRUE,
											LISTBROWSER_HorizontalProp, TRUE,
										TAG_DONE),
									TAG_DONE),
									CHILD_WeightedWidth, 70,
								TAG_DONE),

								LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
									LAYOUT_AddChild, gadgets[GID_NEWORD] = IIntuition->NewObject(NULL, "button.gadget",
										GA_ID, GID_NEWORD,
										GA_RelVerify, TRUE,
										GA_Text, "_New Order",
									TAG_DONE),

									LAYOUT_AddChild, gadgets[GID_EDITORD] = IIntuition->NewObject(NULL, "button.gadget",
										GA_ID, GID_EDITORD,
										GA_RelVerify, TRUE,
										GA_Text, "_Edit Order",
									TAG_DONE),

									LAYOUT_AddChild, gadgets[GID_DELORD] = IIntuition->NewObject(NULL, "button.gadget",
										GA_ID, GID_DELORD,
										GA_RelVerify, TRUE,
										GA_Text, "_Delete Order",
									TAG_DONE),

								TAG_DONE),
								CHILD_WeightedHeight, 0,

							TAG_DONE),

						TAG_DONE),

					TAG_DONE),

					LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
						GA_ID, GID_QUIT,
						GA_RelVerify, TRUE,
						GA_Text,"_Quit",
					TAG_DONE),
					CHILD_WeightedHeight, 0,

				TAG_DONE),
			TAG_DONE);

	 	 	/*  Object creation sucessful? */
			if (objects[OID_MAIN])
			{
				/* Set up inter-group label pagement. */
				IIntuition->SetAttrs( gadgets[GID_PAGELAY1], LAYOUT_AlignLabels,  gadgets[GID_ALIGN1], TAG_DONE);
				IIntuition->SetAttrs( gadgets[GID_ALIGN1], LAYOUT_AlignLabels, gadgets[GID_ALIGN2], TAG_DONE);
				IIntuition->SetAttrs( gadgets[GID_ALIGN2], LAYOUT_AlignLabels, gadgets[GID_ALIGN3], TAG_DONE);

				/*  Open the window. */
				if (windows[WID_MAIN] = (struct Window *) IIntuition->IDoMethod(objects[OID_MAIN], WM_OPEN))
				{
					ULONG wait, signal, app = (1L << AppPort->mp_SigBit);
					ULONG done = FALSE;
					ULONG result;
					UWORD code;

				 	/* Obtain the window wait signal mask. */
					IIntuition->GetAttr(WINDOW_SigMask, objects[OID_MAIN], &signal);

					/* Activate the first string gadget! */
					IIntuition->IDoMethod(objects[OID_MAIN], WM_ACTIVATEGADGET, gadgets[GID_COMPANY]);

					/* Input Event Loop */
					while (!done)
					{
						wait = IExec->Wait( signal | SIGBREAKF_CTRL_C | app );

						if ( wait & SIGBREAKF_CTRL_C )
						{
							done = TRUE;
						}
						else
						{
							while ( (result = IIntuition->IDoMethod(objects[OID_MAIN], WM_HANDLEINPUT, &code) ) != WMHI_LASTMSG )
							{
								switch (result & WMHI_CLASSMASK)
								{
									case WMHI_CLOSEWINDOW:
										windows[WID_MAIN] = NULL;
										done = TRUE;
										break;

									case WMHI_GADGETUP:
										switch (result & WMHI_GADGETMASK)
										{
											case GID_COMPANY:
												IDOS->Printf( "Company: %s\n", ((struct StringInfo *)(((struct Gadget*)gadgets[GID_COMPANY])->SpecialInfo))->Buffer);
												break;

											case GID_QUIT:
												done = TRUE;
												break;
										}
										break;

									case WMHI_ICONIFY:
										IIntuition->IDoMethod(objects[OID_MAIN], WM_ICONIFY);
										windows[WID_MAIN] = NULL;
										break;

									case WMHI_UNICONIFY:
										windows[WID_MAIN] = (struct Window *) IIntuition->IDoMethod(objects[OID_MAIN], WM_OPEN);

										if (windows[WID_MAIN])
										{
											IIntuition->GetAttr(WINDOW_SigMask, objects[OID_MAIN], &signal);
										}
										else
										{
											done = TRUE;	// error re-opening window!
										}
									 	break;
								}
							}
						}
					}
				}

				/* Disposing of the window object will also close the window if it is
				 * already opened, and it will dispose of the layout object attached to it.
				 */
				IIntuition->DisposeObject(objects[OID_MAIN]);
			}

		}

		IExec->FreeSysObject(ASOT_PORT, AppPort);
	}

	return(0);
}
