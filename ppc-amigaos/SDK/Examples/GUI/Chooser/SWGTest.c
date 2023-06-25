;/*
gcc -o SWGTest SWGTest.c -lauto
quit
*/

/* Scroll wheel gadget test */


#define __USE_INLINE__
#include <intuition/icclass.h>
#include <reaction/reaction_macros.h>
#include <classes/window.h>
#include <gadgets/layout.h>
#include <gadgets/button.h>
#include <gadgets/chooser.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/button.h>
#include <proto/chooser.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>


struct Library *WindowBase, *LayoutBase, *ButtonBase, *ChooserBase;

struct WindowIFace *IWindow;
struct LayoutIFace *ILayout;
struct ButtonIFace *IButton;
struct ChooserIFace *IChooser;

struct TagItem MapChooserButton[] = { { CHOOSER_Selected, BUTTON_Integer }, { TAG_END, 0UL } };


int main(void)
{
   Object *windowobj, *layoutobj, *chooserobj, *buttonobj;
   struct Window *win;
   register ULONG input, id, done = FALSE;
   ULONG waitmask;
   UWORD code;
   STRPTR chooserlabels[] = { "First item", "Second item", "Third item", "Fourth item", NULL };

   WindowBase = OpenLibrary("window.class",52);
   LayoutBase = OpenLibrary("Gadgets/layout.gadget",52);
   ButtonBase = OpenLibrary("Gadgets/button.gadget",0);
   ChooserBase = OpenLibrary("Gadgets/chooser.gadget",52);

   IWindow = (struct WindowIFace *)GetInterface(WindowBase,"main",1,NULL);
   ILayout = (struct LayoutIFace *)GetInterface(LayoutBase,"main",1,NULL);
   IButton = (struct ButtonIFace *)GetInterface(ButtonBase,"main",1,NULL);
   IChooser = (struct ChooserIFace *)GetInterface(ChooserBase,"main",1,NULL);

   if (IWindow && ILayout && IButton && IChooser)
   {
      windowobj = WindowObject,
         WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_GADGETUP,
         WA_Activate, TRUE,
         WA_DepthGadget, TRUE,
         WA_CloseGadget, TRUE,
         WA_DragBar, TRUE,
         WA_SizeGadget, TRUE,
         WA_Title, "Test",
         WINDOW_Position, WPOS_CENTERSCREEN,
         WINDOW_ParentGroup, layoutobj = VGroupObject,
            LAYOUT_DeferLayout, TRUE,
            LAYOUT_SpaceOuter, TRUE,
            LAYOUT_AddChild, chooserobj = ChooserObject,
               GA_ID, 0,
               GA_RelVerify, TRUE,
               CHOOSER_LabelArray, chooserlabels,
            ChooserEnd,
            CHILD_WeightedHeight, 0,

            LAYOUT_AddChild, buttonobj = ButtonObject,
               GA_ID, 1,
               GA_ReadOnly, TRUE,
               BUTTON_Integer, 0,
            ButtonEnd,
         EndGroup,
      WindowEnd;

      if (windowobj)
      {
         SetAttrs(chooserobj,ICA_TARGET,buttonobj,ICA_MAP,MapChooserButton,TAG_END);

         if (win = (struct Window *)RA_OpenWindow(windowobj))
         {
            GetAttr(WINDOW_SigMask,windowobj,&waitmask);

            /* Event handling */

            while (!done)
            {
               Wait(waitmask);

               while ((input = RA_HandleInput(windowobj,&code)) != WMHI_LASTMSG)
               {
                  switch (input & WMHI_CLASSMASK)
                  {
                     case WMHI_CLOSEWINDOW:
                        done = TRUE;
                        break;

                     case WMHI_GADGETUP:

                        switch (id = (input & WMHI_GADGETMASK))
                        {
                           case 0:
                              /* Test to see if we receive a meaningful code */
                              Printf("Chooser selected, code == %ld\n",code);
                              break;
                        }

                        break;
                  }
               }
            }

            RA_CloseWindow(windowobj);
         }

         DisposeObject(windowobj);
      }
   }

   DropInterface((struct Interface *)IChooser);
   DropInterface((struct Interface *)IButton);
   DropInterface((struct Interface *)ILayout);
   DropInterface((struct Interface *)IWindow);

   CloseLibrary(ChooserBase);
   CloseLibrary(ButtonBase);
   CloseLibrary(LayoutBase);
   CloseLibrary(WindowBase);

   return (0L);
}


