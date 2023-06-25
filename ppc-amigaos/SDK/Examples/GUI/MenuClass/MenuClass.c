

/* A simple example of Intuition's menuclass usage */

/* Compile: gcc -o MenuClass MenuClass.c -lauto */


#define __USE_INLINE__
#include <clib/macros.h>
#include <dos/dos.h>
#include <intuition/menuclass.h>
#include <reaction/reaction_macros.h>
#include <classes/window.h>
#include <gadgets/layout.h>
#include <gadgets/button.h>
#include <images/bitmap.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/diskfont.h>
#include <proto/utility.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/button.h>
#include <proto/bitmap.h>
#include <string.h>


enum
{
   MID_PROJECT = 1,  /* Zero is an invalid value for a menu ID */
   MID_OPEN,
   MID_SAVE,
   MID_SAVEAS,
   MID_ICONIFY,
   MID_ABOUT,
   MID_QUIT,

   MID_EXTRAS,
   MID_SUBMENU,
   MID_TOGGLEIMAGE,
   MID_SHOWMENU,
   MID_HIDEMENU,
   MID_SHOWITEMS,
   MID_HIDEITEMS,

   MID_AUTO_BASE = 1000
};


static struct Image *MenuImage(STRPTR, struct Screen *);


int main(void)
{
   Object *windowobj, *layoutobj, *displayobj;
   Object *menustripobj = NULL;
   Object *project_menuobj, *parent, *obj;
   Object *showmenu_itemobj, *hidemenu_itemobj;
   Object *showitems_itemobj, *hideitems_itemobj;
   Object *imageobj[2];
   struct TTextAttr *tta = NULL;
   struct DrawInfo *dri;
   struct Screen *scr;
   struct Window *win;
   struct MsgPort *port;
   uint32 which_image = 0;
   uint32 waitmask, input, id = MID_AUTO_BASE;
   uint16 code;
   TEXT buffer[128];
   STRPTR label;
   BOOL hidden;
   BOOL done = FALSE;

   if (!((IntuitionBase->lib_Version > 54) ||
         ((IntuitionBase->lib_Version == 54) &&
          (IntuitionBase->lib_Revision >= 6))))
   {
      Printf("This program requires at least version 54.6 of intuition.library.\n");
      return (RETURN_ERROR);
   }

   port = AllocSysObject(ASOT_PORT,NULL);

   if ((scr = LockPubScreen("Workbench")) != NULL)
   {
      /* Load a couple of images, to be freed manually
       * on program termination.
       */
      imageobj[0] = (Object *)MenuImage("flaggreen",scr);
      imageobj[1] = (Object *)MenuImage("flagyellow",scr);

      /* Try defining slightly bigger version of the
       * Workbench screen's current font, to be used
       * as the font for a menu item.
       */
      if ((dri = GetScreenDrawInfo(scr)) != NULL)
      {
         tta = ObtainTTextAttr(dri->dri_Font);
         if (tta)
            tta->tta_YSize += 10;
         FreeScreenDrawInfo(scr,dri);
      }

      /* Build the whole menu tree. By assigning an ID
       * also to the menu title objects, we allow the
       * user to ask for help on them as well, instead
       * of only being able to do so on the menu items.
       *
       * Also, for the sake of this example, we assign
       * automatically generated non-zero IDs to some
       * items we don't need to properly identify when
       * they get selected.
       */
      menustripobj = MStrip,
         MA_AddChild, MTitle("Project"),
            MA_ID, MID_PROJECT,
            MA_AddChild, MItem("O|Open..."),
               MA_ID, MID_OPEN,
               MA_Image, MenuImage("open",scr),
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem("S|Save"),
               MA_ID, MID_SAVE,
               MA_Image, MenuImage("save",scr),
            MEnd,

            MA_AddChild, MItem("A|Save as..."),
               MA_ID, MID_SAVEAS,
               MA_Image, MenuImage("saveas",scr),
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem("I|Iconify"),
               MA_ID, MID_ICONIFY,
               MA_Image, MenuImage("iconify",scr),
            MEnd,

            MA_AddChild, MItem("?|About..."),
               MA_ID, MID_ABOUT,
               MA_Image, MenuImage("info",scr),
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem("Q|Quit"),
               MA_ID, MID_QUIT,
               MA_Image, MenuImage("quit",scr),
            MEnd,
         MEnd,

         MA_AddChild, MTitle("Extras"),
            MA_ID, MID_EXTRAS,
            MA_AddChild, MItem("Sub-menu example"),
               MA_ID, MID_SUBMENU,
               MA_AddChild, MItem("As you can"),
                  MA_ID, id++,
               MEnd,
               MA_AddChild, MItem("see from"),
                  MA_ID, id++,
                  MA_AddChild, MItem("this example,"),
                     MA_ID, id++,
                  MEnd,
                  MA_AddChild, MItem("there is"),
                     MA_ID, id++,
                     MA_AddChild, MItem("virtually no"),
                        MA_ID, id++,
                     MEnd,
                     MA_AddChild, MItem("limit to"),
                        MA_ID, id++,
                        MA_AddChild, MItem("how many sub-menu"),
                           MA_ID, id++,
                        MEnd,
                        MA_AddChild, MItem("levels you can"),
                           MA_ID, id++,
                           MA_AddChild, MItem("have with"),
                              MA_ID, id++,
                           MEnd,
                           MA_AddChild, MItem("Intuition"),
                              MA_ID, id++,
                              MA_AddChild, MItem("when using its new"),
                                 MA_ID, id++,
                              MEnd,
                              MA_AddChild, MItem("BOOPSI menu class."),
                                 MA_ID, id++,
                                 MA_TextAttr, tta,
                              MEnd,
                           MEnd,
                        MEnd,
                     MEnd,
                  MEnd,
               MEnd,
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem("Toggle this image"),
               MA_ID, MID_TOGGLEIMAGE,
               MA_Image, imageobj[which_image],
               MA_FreeImage, FALSE,
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem("Show Project menu"),
               MA_ID, MID_SHOWMENU,
               MA_Hidden, TRUE,
            MEnd,

            MA_AddChild, MItem("Hide Project menu"),
               MA_ID, MID_HIDEMENU,
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem("Show dummy items"),
               MA_ID, MID_SHOWITEMS,
               MA_Hidden, TRUE,
            MEnd,

            MA_AddChild, MItem("Hide dummy items"),
               MA_ID, MID_HIDEITEMS,
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem("Dummy item #1"),
               MA_ID, id++,
            MEnd,

            MA_AddChild, MItem("Dummy item #2"),
               MA_ID, id++,
            MEnd,

            MA_AddChild, MItem("Dummy item #3"),
               MA_ID, id++,
            MEnd,
         MEnd,
      MEnd;

      UnlockPubScreen(NULL,scr);
   }

   layoutobj = VGroupObject,
      LAYOUT_DeferLayout, TRUE,
      LAYOUT_SpaceOuter, TRUE,
      LAYOUT_FixedVert, FALSE,
      LAYOUT_AddChild, displayobj = ButtonObject,
         GA_ReadOnly, TRUE,
      ButtonEnd,
      CHILD_WeightedHeight, 0,

      LAYOUT_AddChild, HGroupObject,
         LAYOUT_EvenSize, TRUE,
         LAYOUT_HorizAlignment, LALIGN_CENTER,
         LAYOUT_AddChild, ButtonObject,
            GA_ID, 1,
            GA_RelVerify, TRUE,
            GA_Text, "Quit test",
         ButtonEnd,
         CHILD_WeightedWidth, 0,
      EndGroup,
      CHILD_WeightedHeight, 0,
      CHILD_MinWidth, 350,
   EndGroup;

   windowobj = WindowObject,
      WA_PubScreenName, "Workbench",
      WA_IDCMP, IDCMP_CLOSEWINDOW |
                IDCMP_GADGETUP |
                IDCMP_MENUPICK |
                IDCMP_MENUHELP,
      WA_Activate, TRUE,
      WA_CloseGadget, TRUE,
      WA_Title, "BOOPSI menu class test",
      WA_DragBar, TRUE,
      WA_DepthGadget, TRUE,
      WA_SizeGadget, TRUE,
      WA_MenuHelp, TRUE,

      WINDOW_Position, WPOS_CENTERSCREEN,
      WINDOW_IconifyGadget, port? TRUE: FALSE,
      WINDOW_PopupGadget, TRUE,
      WINDOW_JumpScreensMenu, TRUE,
      WINDOW_AppPort, port,
      WINDOW_ParentGroup, layoutobj,
      WINDOW_MenuStrip, menustripobj,
   WindowEnd;

   if (menustripobj)
   {
      project_menuobj = (Object *)IDoMethod(menustripobj,MM_FINDID,0,MID_PROJECT);
      showmenu_itemobj = (Object *)IDoMethod(menustripobj,MM_FINDID,0,MID_SHOWMENU);
      hidemenu_itemobj = (Object *)IDoMethod(menustripobj,MM_FINDID,0,MID_HIDEMENU);
      showitems_itemobj = (Object *)IDoMethod(menustripobj,MM_FINDID,0,MID_SHOWITEMS);
      hideitems_itemobj = (Object *)IDoMethod(menustripobj,MM_FINDID,0,MID_HIDEITEMS);
   }

   if (windowobj)
   {
      if ((win = RA_OpenWindow(windowobj)) != NULL)
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

                  case WMHI_ICONIFY:
                     RA_Iconify(windowobj);
                     break;

                  case WMHI_UNICONIFY:
                     win = RA_OpenWindow(windowobj);
                     GetAttr(WINDOW_SigMask,windowobj,&waitmask);
                     if (win == NULL)
                        done = TRUE;
                     break;

                  case WMHI_JUMPSCREEN:
                     RA_CloseWindow(windowobj);
                     win = RA_OpenWindow(windowobj);
                     GetAttr(WINDOW_SigMask,windowobj,&waitmask);
                     if (win)
                        ScreenToFront(win->WScreen);
                     else
                        done = TRUE;
                     break;

                  case WMHI_MENUPICK:

                     id = NO_MENU_ID;

                     while ((id = IDoMethod(menustripobj,MM_NEXTSELECT,0,id)) != NO_MENU_ID)
                     {
                        obj = (Object *)IDoMethod(menustripobj,MM_FINDID,0,id);

                        if (obj != NULL)
                        {
                           GetAttr(MA_Label,obj,(uint32 *)&label);
                           if (strchr(label,'|'))
                              label += 2;
                           SNPrintf(buffer,sizeof(buffer),"Menu selection: \"%s\"",label);
                           SetGadgetAttrs((struct Gadget *)displayobj,win,NULL,GA_Text,buffer,TAG_END);
                        }

                        switch (id)
                        {
                           case MID_ICONIFY:
                              RA_Iconify(windowobj);
                              break;

                           case MID_QUIT:
                              done = TRUE;
                              break;

                           case MID_TOGGLEIMAGE:
                              which_image = 1 - which_image;
                              SetAttrs(obj,MA_Image,imageobj[which_image],TAG_END);
                              break;

                           case MID_SHOWMENU:
                           case MID_HIDEMENU:
                              hidden = (id == MID_HIDEMENU);
                              if (showmenu_itemobj != NULL)
                                 SetAttrs(showmenu_itemobj,MA_Hidden,!hidden,TAG_END);
                              if (hidemenu_itemobj != NULL)
                                 SetAttrs(hidemenu_itemobj,MA_Hidden,hidden,TAG_END);
                              if (project_menuobj != NULL)
                                 SetAttrs(project_menuobj,MA_Hidden,hidden,TAG_END);
                              break;

                           case MID_SHOWITEMS:
                           case MID_HIDEITEMS:
                              hidden = (id == MID_HIDEITEMS);
                              if (showitems_itemobj != NULL)
                                 SetAttrs(showitems_itemobj,MA_Hidden,!hidden,TAG_END);
                              if (hideitems_itemobj != NULL)
                                 SetAttrs(hideitems_itemobj,MA_Hidden,hidden,TAG_END);

                              GetAttr(MA_Parent,showitems_itemobj,(uint32 *)&parent);
                              obj = hideitems_itemobj;

                              while ((obj = (Object *)IDoMethod(parent,MM_NEXTCHILD,0,obj)) != NULL)
                                 SetAttrs(obj,MA_Hidden,hidden,TAG_END);
                              break;
                        }
                     }

                     break;

                  case WMHI_MENUHELP:

                     GetAttr(MA_MenuHelpID,menustripobj,&id);

                     if (id != NO_MENU_ID)
                     {
                        obj = (Object *)IDoMethod(menustripobj,MM_FINDID,0,id);

                        if (obj != NULL)
                        {
                           GetAttr(MA_Label,obj,(uint32 *)&label);
                           if (strchr(label,'|'))
                              label += 2;
                           SNPrintf(buffer,sizeof(buffer),"Help requested for: \"%s\"",label);
                           SetGadgetAttrs((struct Gadget *)displayobj,win,NULL,GA_Text,buffer,TAG_END);
                        }
                     }
                     else
                     {
                        Strlcpy(buffer,"HELP requested while no menu or item was selected",sizeof(buffer));
                        SetGadgetAttrs((struct Gadget *)displayobj,win,NULL,GA_Text,buffer,TAG_END);
                     }

                     break;

                  case WMHI_GADGETUP:

                     switch (id = (input & WMHI_GADGETMASK))
                     {
                        case 1:
                           done = TRUE;
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

   if (menustripobj)
      DisposeObject(menustripobj);

   if (imageobj[0])
      DisposeObject(imageobj[0]);

   if (imageobj[1])
      DisposeObject(imageobj[1]);

   if (tta)
      FreeTTextAttr(tta);

   if (port)
      FreeSysObject(ASOT_PORT,port);

   return (RETURN_OK);
}

static struct Image *MenuImage(STRPTR name, struct Screen *screen)
{
   struct Image *i = NULL;
   APTR prev_win;
   BPTR dir, prev_dir;
   STRPTR name_s, name_g;
   uint32 len;

   len = strlen(name);

   name_s = AllocVecTags(len + 3 + len + 3,TAG_END);

   if (name_s)
   {
      name_g = name_s + len + 3;

      strcpy(name_s,name);
      strcat(name_s,"_s");

      strcpy(name_g,name);
      strcat(name_g,"_g");

      prev_win = SetProcWindow((APTR)-1);  /* Disable requesters */

      dir = Lock("TBIMAGES:",SHARED_LOCK);

      SetProcWindow(prev_win);             /* Re-enable requesters */

      if (dir != ZERO)
      {
         prev_dir = SetCurrentDir(dir);

         i = (struct Image *)NewObject(NULL,"bitmap.image",BITMAP_SourceFile, name,
                                                           BITMAP_SelectSourceFile, name_s,
                                                           BITMAP_DisabledSourceFile, name_g,
                                                           BITMAP_Screen, screen,
                                                           BITMAP_Masking, TRUE,
                                                           TAG_END);

         if (i)
            SetAttrs((Object *)i,IA_Height,i->Height + 2,TAG_END);

         SetCurrentDir(prev_dir);

         UnLock(dir);
      }

      FreeVec(name_s);
   }

   return (i);
}

