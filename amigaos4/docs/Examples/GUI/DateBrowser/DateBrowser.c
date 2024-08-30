;/* Example
gcc -o DateBrowser dateBrowser.c -lauto
quit
*/

/**
 **  DateBrowser.c -- DateBrowser class Example.
 **
 **  This code opens a window and then creates a datebrowser object.
 **  There have been no tags applied, but setting the date and day
 **  are possible. See the datebrowser.doc for more details.
 **/

/* system includes */
#define ALL_REACTION_CLASSES
#include <reaction/reaction.h>
#include <reaction/reaction_macros.h>
#include <gadgets/datebrowser.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <proto/intuition.h>
#include <proto/graphics.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/datebrowser.h>

struct Library *DateBrowserBase;
struct DateBrowserIFace *IDateBrowser;

char *DBNAME = "sys:classes/gadgets/datebrowser.gadget";

enum
{
    GID_MAIN=0,
    GID_DATEBROWSER,
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

int main(void)
{
    struct MsgPort *AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_END);

    struct Window *windows[WID_LAST];

    struct Gadget *gadgets[GID_LAST];

    Object *objects[OID_LAST];

    if (DateBrowserBase = (struct Library *)IExec->OpenLibrary(DBNAME, 51 ))
        IDateBrowser = (struct DateBrowserIFace *)IExec->GetInterface( DateBrowserBase, "main", 1L, NULL);
    else printf("Failed to open '%s'\n", DBNAME);

    /* make sure our classes opened... */
    if (!ButtonBase || !IntegerBase || !WindowBase || !LayoutBase || !DateBrowserBase )
        return(30);
    else if ( AppPort != NULL )
    {
        /* Create the window object. */
        objects[OID_MAIN] = WindowObject,
            WA_ScreenTitle, "ReAction AmigaOS 4",
            WA_Title, "ReAction DateBrowser Example",
            WA_Activate, TRUE,
            WA_DepthGadget, TRUE,
            WA_DragBar, TRUE,
            WA_CloseGadget, TRUE,
            WA_SizeGadget, TRUE,
            WINDOW_IconifyGadget, TRUE,
            WINDOW_IconTitle, "DateBrowser",
            WINDOW_AppPort, AppPort,
            WINDOW_Position, WPOS_CENTERMOUSE,
            WINDOW_ParentGroup, gadgets[GID_MAIN] = (struct Gadget *)VGroupObject,
                LAYOUT_SpaceOuter, TRUE,
                LAYOUT_DeferLayout, TRUE,

                LAYOUT_AddChild, gadgets[GID_DATEBROWSER] = (struct Gadget *)DateBrowserObject,
                    /* See the datebrowser.doc for applicable tags */
                    GA_ReadOnly, TRUE,
                IntegerEnd,

            EndGroup,
        EndWindow;

        /*  Object creation sucessful? */
        if (objects[OID_MAIN])
        {
            /*  Open the window. */
            if (windows[WID_MAIN] = (struct Window *) RA_OpenWindow(objects[OID_MAIN]))
            {
                ULONG wait, signal, app = (1L << AppPort->mp_SigBit);
                ULONG done = FALSE;
                ULONG result;
                UWORD code;

                /* Obtain the window wait signal mask. */
                IIntuition->GetAttr(WINDOW_SigMask, objects[OID_MAIN], &signal);

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
                        while ( (result = RA_HandleInput(objects[OID_MAIN], &code) ) != WMHI_LASTMSG )
                        {
                            switch (result & WMHI_CLASSMASK)
                            {
                                case WMHI_CLOSEWINDOW:
                                    windows[WID_MAIN] = NULL;
                                    done = TRUE;
                                    break;

                                case WMHI_ICONIFY:
                                    RA_Iconify(objects[OID_MAIN]);
                                    windows[WID_MAIN] = NULL;
                                    break;

                                case WMHI_UNICONIFY:
                                    windows[WID_MAIN] = (struct Window *) RA_OpenWindow(objects[OID_MAIN]);

                                    if (windows[WID_MAIN])
                                    {
                                        IIntuition->GetAttr(WINDOW_SigMask, objects[OID_MAIN], &signal);
                                    }
                                    else
                                    {
                                        done = TRUE;    // error re-opening window!
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

        IExec->FreeSysObject(ASOT_PORT, AppPort);
    }

    return(0);
}

