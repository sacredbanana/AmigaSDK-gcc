

/* A simple example of Intuition's menuclass usage */
/* with dynamic localization of menu strings       */

/* Compile: gcc -o MenuClassLocalize MenuClassLocalize.c -lauto */


#define __USE_INLINE__
#include <clib/macros.h>
#include <dos/dos.h>
#include <intuition/menuclass.h>
#include <reaction/reaction_macros.h>
#include <classes/window.h>
#include <gadgets/layout.h>
#include <gadgets/button.h>
#include <images/bitmap.h>
#include <diskfont/diskfonttag.h>
#include <libraries/locale.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/diskfont.h>
#include <proto/locale.h>
#include <proto/utility.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/button.h>
#include <proto/bitmap.h>
#include <string.h>


/* String IDs from NotePad's .cd file
 */
#define MSG_MENU_PROJECT     0
#define MSG_PROJECT_NEW      1
#define MSG_PROJECT_OPEN     2
#define MSG_PROJECT_INSERT   3
#define MSG_PROJECT_SAVE     4
#define MSG_PROJECT_SAVEAS   5
#define MSG_PROJECT_PRINT    6
#define MSG_PROJECT_ABOUT    7
#define MSG_PROJECT_ICONIFY  8
#define MSG_PROJECT_QUIT     9
#define MSG_MENU_EDIT       10
#define MSG_EDIT_CUT        11
#define MSG_EDIT_COPY       12
#define MSG_EDIT_PASTE      13
#define MSG_EDIT_ERASE      14
#define MSG_EDIT_UNDO       15
#define MSG_EDIT_REDO       16
#define MSG_COUNT           17


/* Default strings from NotePad's .cd file
 */
const CONST_STRPTR MenuStrings[] =
{
   "Project",
   "N\0New",
   "O\0Open...",
   " \0Insert...",
   "S\0Save",
   " \0Save As...",
   "P\0Print...",
   " \0About...",
   "I\0Iconify",
   "Q\0Quit",
   "Edit",
   "X\0Cut",
   "C\0Copy",
   "V\0Paste",
   " \0Erase",
   "U\0Undo",
   "Z\0Redo"
};


enum
{
   MID_PROJECT = 1,  /* Zero is an invalid value for a menu ID */
   MID_NEW,
   MID_OPEN,
   MID_INSERT,
   MID_SAVE,
   MID_SAVEAS,
   MID_PRINT,
   MID_ICONIFY,
   MID_ABOUT,
   MID_QUIT,
   MID_EDIT,
   MID_CUT,
   MID_COPY,
   MID_PASTE,
   MID_ERASE,
   MID_UNDO,
   MID_REDO
};


static void DisplayLanguage(struct Window *, Object *, struct Catalog *, STRPTR, uint32);
static struct Image *MenuImage(STRPTR, struct Screen *);


static CONST_STRPTR StringHookFunction(struct Hook *hook, Object *menuobj, struct MenuStringMessage *msg)
{
   return (GetCatalogStr(msg->Catalog,msg->StringID,MenuStrings[msg->StringID]));
}


int main(void)
{
   Object *windowobj, *layoutobj, *displayobj;
   Object *menustripobj = NULL;
   Object *obj;
   struct Screen *scr;
   struct Window *win;
   struct MsgPort *port;
   struct Catalog *catalog;
   struct Hook stringhook;
   uint32 charset;
   uint32 waitmask, input, id;
   uint16 code;
   TEXT buffer[128], language[64] = "";
   STRPTR label;
   BOOL done = FALSE;

   if (!((IntuitionBase->lib_Version > 54) ||
         ((IntuitionBase->lib_Version == 54) &&
          (IntuitionBase->lib_Revision >= 6))))
   {
      Printf("This program requires at least version 54.6 of intuition.library.\n");
      return (RETURN_ERROR);
   }

   port = AllocSysObject(ASOT_PORT,NULL);

   catalog = OpenCatalog(NULL,"Sys/notepad.catalog",
                         OC_BuiltInCodeSet, 4, /* ISO-8859-1 */
                         OC_PreferExternal, TRUE,
                         TAG_END);

   charset = catalog? catalog->cat_CodeSet: 4;

   if ((scr = LockPubScreen("Workbench")) != NULL)
   {
      /* Initialize the string hook for localization.
       */
      memset(&stringhook,0,sizeof(struct Hook));
      stringhook.h_Entry = (HOOKFUNC)StringHookFunction;

      /* Build the whole menu tree. By assigning an ID
       * also to the menu title objects, we allow the
       * user to ask for help on them as well, instead
       * of only being able to do so on the menu items.
       */
      menustripobj = MStrip,
         MA_StringHook, &stringhook,
         MA_Catalog, catalog,
         MA_CharSet, charset,
         MA_MinStringID, 0,
         MA_MaxStringID, MSG_COUNT - 1,

         MA_AddChild, MTitle(MSG_MENU_PROJECT),
            MA_ID, MID_PROJECT,
            MA_AddChild, MItem(MSG_PROJECT_NEW),
               MA_ID, MID_NEW,
               MA_Image, MenuImage("new",scr),
            MEnd,

            MA_AddChild, MItem(MSG_PROJECT_OPEN),
               MA_ID, MID_OPEN,
               MA_Image, MenuImage("open",scr),
            MEnd,

            MA_AddChild, MItem(MSG_PROJECT_INSERT),
               MA_ID, MID_INSERT,
               MA_Image, MenuImage("insert_text",scr),
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem(MSG_PROJECT_SAVE),
               MA_ID, MID_SAVE,
               MA_Image, MenuImage("save",scr),
            MEnd,

            MA_AddChild, MItem(MSG_PROJECT_SAVEAS),
               MA_ID, MID_SAVEAS,
               MA_Image, MenuImage("saveas",scr),
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem(MSG_PROJECT_PRINT),
               MA_ID, MID_PRINT,
               MA_Image, MenuImage("print",scr),
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem(MSG_PROJECT_ICONIFY),
               MA_ID, MID_ICONIFY,
               MA_Image, MenuImage("iconify",scr),
            MEnd,

            MA_AddChild, MItem(MSG_PROJECT_ABOUT),
               MA_ID, MID_ABOUT,
               MA_Image, MenuImage("info",scr),
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem(MSG_PROJECT_QUIT),
               MA_ID, MID_QUIT,
               MA_Image, MenuImage("quit",scr),
            MEnd,
         MEnd,

         MA_AddChild, MTitle(MSG_MENU_EDIT),
            MA_ID, MID_EDIT,
            MA_AddChild, MItem(MSG_EDIT_CUT),
               MA_ID, MID_CUT,
               MA_Image, MenuImage("cut",scr),
            MEnd,

            MA_AddChild, MItem(MSG_EDIT_COPY),
               MA_ID, MID_COPY,
               MA_Image, MenuImage("copy",scr),
            MEnd,

            MA_AddChild, MItem(MSG_EDIT_PASTE),
               MA_ID, MID_PASTE,
               MA_Image, MenuImage("paste",scr),
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem(MSG_EDIT_ERASE),
               MA_ID, MID_ERASE,
               MA_Image, MenuImage("del",scr),
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem(MSG_EDIT_UNDO),
               MA_ID, MID_UNDO,
               MA_Image, MenuImage("undo",scr),
            MEnd,

            MA_AddChild, MItem(MSG_EDIT_REDO),
               MA_ID, MID_REDO,
               MA_Image, MenuImage("redo",scr),
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
         GA_Underscore, 0,
      ButtonEnd,
      CHILD_WeightedHeight, 0,

      LAYOUT_AddChild, HGroupObject,
         LAYOUT_EvenSize, TRUE,
         LAYOUT_AddChild, ButtonObject,
            GA_ID, 1,
            GA_RelVerify, TRUE,
            GA_Text, "Update localization",
         ButtonEnd,
         CHILD_WeightedWidth, 0,

         LAYOUT_AddChild, ButtonObject,
            GA_ID, 2,
            GA_RelVerify, TRUE,
            GA_Text, "Quit test",
         ButtonEnd,
         CHILD_WeightedWidth, 0,
      EndGroup,
      CHILD_WeightedHeight, 0,
      CHILD_MinWidth, 450,
   EndGroup;

   windowobj = WindowObject,
      WA_PubScreenName, "Workbench",
      WA_IDCMP, IDCMP_CLOSEWINDOW |
                IDCMP_GADGETUP |
                IDCMP_MENUPICK |
                IDCMP_MENUHELP,
      WA_Activate, TRUE,
      WA_CloseGadget, TRUE,
      WA_Title, "BOOPSI menu class: dynamic localization test",
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

   if (windowobj)
   {
      DisplayLanguage(NULL,displayobj,catalog,language,sizeof(language));

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
                     if (catalog)
                        CloseCatalog(catalog);
                     catalog = OpenCatalog(NULL,"Sys/notepad.catalog",
                                           OC_BuiltInCodeSet, 4, /* ISO-8859-1 */
                                           OC_PreferExternal, TRUE,
                                           TAG_END);
                     charset = catalog? catalog->cat_CodeSet: 4;

                     DisplayLanguage(NULL,displayobj,catalog,language,sizeof(language));

                     win = RA_OpenWindow(windowobj);
                     GetAttr(WINDOW_SigMask,windowobj,&waitmask);

                     if (win)
                        SetAttrs(menustripobj,MA_Catalog,catalog,MA_CharSet,charset,TAG_END);
                     else
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
                           if (((uint32)label >= 0) && ((uint32)label <= (MSG_COUNT - 1)))
                              label = (STRPTR)GetCatalogStr(catalog,(uint32)label,MenuStrings[(uint32)label]);
                           if (label[1] == '\0')
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
                           if (((uint32)label >= 0) && ((uint32)label <= (MSG_COUNT - 1)))
                              label = (STRPTR)GetCatalogStr(catalog,(uint32)label,MenuStrings[(uint32)label]);
                           if (label[1] == '\0')
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
                           if (catalog)
                              CloseCatalog(catalog);
                           catalog = OpenCatalog(NULL,"Sys/notepad.catalog",
                                                 OC_BuiltInCodeSet, 4, /* ISO-8859-1 */
                                                 OC_PreferExternal, TRUE,
                                                 TAG_END);
                           charset = catalog? catalog->cat_CodeSet: 4;

                           SetAttrs(menustripobj,MA_Catalog,catalog,MA_CharSet,charset,TAG_END);

                           DisplayLanguage(win,displayobj,catalog,language,sizeof(language));
                           break;

                        case 2:
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

   if (catalog)
      CloseCatalog(catalog);

   if (port)
      FreeSysObject(ASOT_PORT,port);

   return (RETURN_OK);
}

static void DisplayLanguage(struct Window *win, Object *gadget, struct Catalog *catalog, STRPTR language, uint32 langsize)
{
   TEXT buffer[128];
   CONST_STRPTR charsetname;
   STRPTR dotpos;
   struct Locale *locale;

   if (catalog)
   {
      charsetname = (CONST_STRPTR)ObtainCharsetInfo(DFCS_NUMBER,catalog->cat_CodeSet,DFCS_NAME);

      if (win && (Stricmp(language,catalog->cat_Language) == 0))
         SNPrintf(buffer,sizeof(buffer),"Already using %s catalog (charset %s)",catalog->cat_Language,charsetname);
      else
         SNPrintf(buffer,sizeof(buffer),"Now using %s catalog (charset %s)",catalog->cat_Language,charsetname);

      Strlcpy(language,catalog->cat_Language,langsize);
   }
   else
   {
      locale = OpenLocale(NULL);
      SNPrintf(buffer,sizeof(buffer),"No catalog found for %s, using built-in strings",locale->loc_LanguageName);
      if ((dotpos = strchr(buffer,'.')) != NULL)
         *dotpos = ' ';
      CloseLocale(locale);

      language[0] = '\0';
   }

   if (win)
      SetGadgetAttrs((struct Gadget *)gadget,win,NULL,GA_Text,buffer,TAG_END);
   else
      SetAttrs(gadget,GA_Text,buffer,TAG_END);
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

