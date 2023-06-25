;/* execute me to compile
gcc -o DynamicHelpHints DynamicHelpHints.c -lauto
quit
*/

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/window.h>
#include <proto/button.h>
#include <proto/string.h>
#include <proto/layout.h>
#include <proto/label.h>

#include <classes/window.h>
#include <gadgets/button.h>
#include <images/label.h>

#include <reaction/reaction_macros.h>

enum
{
    GAD_HINTINFO_TEXT = 1,
    GAD_BUTTON
};

int main( int argc, char *argv[] )
{
    Object *WinObj, *ButtonObj, *StringObj;
    struct Window *win;
    
    /* Create the window object. */
    if(( WinObj = WindowObject,
            WA_ScreenTitle, "ReAction OS4.",
            WA_Title, "Button HelpHint Example",
            WA_Width, 400,
            WA_DepthGadget, TRUE,
            WA_DragBar, TRUE,
            WA_CloseGadget, TRUE,
            WA_Activate, TRUE,
            WINDOW_Position, WPOS_CENTERSCREEN,
            /* there is no HintInfo array set up here, instead we define the 
            ** strings directly when each gadget is created (OM_NEW)
            */
            WINDOW_GadgetHelp, TRUE,
            WINDOW_ParentGroup, VLayoutObject,
                LAYOUT_SpaceOuter, TRUE,
                LAYOUT_DeferLayout, TRUE,
                LAYOUT_AddChild, HGroupObject,
                    GA_BackFill, LAYERS_BACKFILL,
                    LAYOUT_BevelStyle, BVS_GROUP,
                    LAYOUT_AddImage, LabelObject,
                        LABEL_Text, "This window is set up to allow you to hover the mouse pointer\n" \
                                    "over the button gadget and a short helpful text will be displayed.\n" \
                                    "This text can be changed dynamically by entering what you want in\n" \
                                    "the string gadget and it will change the help text accordingly.",
                    LabelEnd,
                LayoutEnd,
                LAYOUT_AddChild, ButtonObj = ButtonObject,
                    GA_ID, GAD_BUTTON,
                    GA_Text, "A button!",
                    GA_HintInfo, "The default hint info is this",
                ButtonEnd,
                CHILD_WeightedHeight, 0,
                
                LAYOUT_AddChild, StringObj = StringObject,
                    GA_ID, GAD_HINTINFO_TEXT,
                    GA_RelVerify, TRUE,
                    GA_HintInfo, "Enter the text that you want displayed\nfor the HintInfo of the button above",
                StringEnd,
                CHILD_Label, LabelObject, LABEL_Text, "Enter hintinfo text", LabelEnd,
            EndMember,
        EndWindow))
    {
        /*  Open the window. */
        if( win = (struct Window *) RA_OpenWindow(WinObj) )
        {   
            ULONG wait, signal, result, done = FALSE;
            WORD Code;
            CONST_STRPTR hintinfo;
            
            /* Obtain the window wait signal mask. */
            IIntuition->GetAttr( WINDOW_SigMask, WinObj, &signal );
            
            /* Input Event Loop */
            while( !done )
            {
                wait = IExec->Wait(signal|SIGBREAKF_CTRL_C);
                
                if (wait & SIGBREAKF_CTRL_C) done = TRUE;
                else
                while ((result = RA_HandleInput(WinObj, &Code)) != WMHI_LASTMSG)
                {
                    switch (result & WMHI_CLASSMASK)
                    {
                        case WMHI_CLOSEWINDOW:
                            done = TRUE;
                            break;
                         case WMHI_GADGETUP:
                            switch(result & WMHI_GADGETMASK)
                            {
                                case GAD_HINTINFO_TEXT:
                                    /* if the user has entered a new text for the buttons
                                    ** help text, get it, and set it
                                    */
                                    IIntuition->GetAttrs( StringObj, STRINGA_TextVal, &hintinfo, TAG_DONE );
                                    IIntuition->SetAttrs( ButtonObj, GA_HintInfo, hintinfo, TAG_DONE );
                                    break;
                            }
                            break;
                    }
                }
            }
        }
        
        /* Disposing of the window object will
         * also close the window if it is
         * already opened and it will dispose of
         * all objects attached to it.
         */
        IIntuition->DisposeObject( WinObj );
    }
    
    return RETURN_OK;
}

