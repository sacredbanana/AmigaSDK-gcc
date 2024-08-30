;/* String Example
gcc -o TellRawKey tellrawkey.c -lauto
quit
*/

/**
 **  TellRawKey.c -- String class Example.
 **
 **  This is a simple example testing some of the capabilities of the
 **  String gadget class.
 **
 **  This code opens a window and then creates one String gadgets which
 **  is read only and shows the code of the pressed key on the keyboard. 
 **
 **/

// system includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALL_REACTION_CLASSES
#include <reaction/reaction.h>
#include <reaction/reaction_macros.h>

#include <proto/intuition.h>
#include <proto/exec.h>

enum
{
    GID_MAIN=0,
    GID_STRING1,
    GID_STRING2,
    GID_DOWN,
    GID_UP,
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


#define SMAX 24

TEXT initialstring[16] = "";

int main(void)
{
    struct MsgPort *AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_END);

    struct Window *windows[WID_LAST];

    struct Gadget *gadgets[GID_LAST];

    Object *objects[OID_LAST];

    /* make sure our classes opened... */
    if (!ButtonBase || !StringBase || !WindowBase || !LayoutBase)
        return(30);

    else if ( AppPort != NULL )
    {


        // Create the window object.
        objects[OID_MAIN] = WindowObject,
            WA_ScreenTitle, "ReAction OS4.0",
            WA_Title, "RawKey Values",
            WA_Activate, TRUE,
            WA_DepthGadget, TRUE,
            WA_DragBar, TRUE,
            WA_CloseGadget, TRUE,
            WA_SizeGadget, TRUE,
            WINDOW_IconifyGadget, TRUE,
            WINDOW_IconTitle, "String",
            WINDOW_AppPort, AppPort,
            WINDOW_Position, WPOS_CENTERMOUSE,
            WINDOW_ParentGroup, gadgets[GID_MAIN] = (struct Gadget*)VGroupObject,
                LAYOUT_SpaceOuter, TRUE,
                LAYOUT_DeferLayout, TRUE,
                LAYOUT_AddChild, gadgets[GID_STRING1] = (struct Gadget*)StringObject,
                    GA_ID, GID_STRING1,
                    GA_ReadOnly, TRUE,
                    GA_RelVerify, TRUE,
                    GA_TabCycle, TRUE,
                    STRINGA_MinVisible, 10,
                    STRINGA_MaxChars, SMAX,
                StringEnd,
                CHILD_NominalSize, TRUE,
                CHILD_Label, LabelObject, LABEL_Text, "String _1", LabelEnd,
                LAYOUT_AddChild, ButtonObject,
                    GA_ID, GID_QUIT,
                    GA_RelVerify, TRUE,
                    GA_Text,"Quit",
                ButtonEnd,
                CHILD_WeightedHeight, 0,
            EndGroup,
        EndWindow;

        //  Object creation sucessful?

        if (objects[OID_MAIN])
        {
            //  Open the window.

            if (windows[WID_MAIN] = (struct Window *) RA_OpenWindow(objects[OID_MAIN]))
            {
                ULONG wait, signal, app = (1L << AppPort->mp_SigBit);
                ULONG done = FALSE;
                ULONG result;
                UWORD code;

                // Obtain the window wait signal mask.

                IIntuition->GetAttr(WINDOW_SigMask, objects[OID_MAIN], &signal);

                // Input Event Loop

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

                                case WMHI_GADGETUP:
                                    switch (result & WMHI_GADGETMASK)
                                    {

                                        case GID_QUIT:
                                            done = TRUE;
                                            break;
                                    }
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

                                case WMHI_RAWKEY:
                                    snprintf( initialstring, 16, "%d", code );
                                    IIntuition->SetGadgetAttrs( gadgets[GID_STRING1], windows[WID_MAIN], NULL, STRINGA_TextVal, initialstring, TAG_DONE );
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

    return(0);
}

