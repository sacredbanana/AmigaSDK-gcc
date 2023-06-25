

/* A simple example of Intuition's gadget context menus */

/* Compile: gcc -o ContextMenuGadget ContextMenuGadget.c -lauto */


#define __USE_INLINE__
#include <clib/macros.h>
#include <dos/dos.h>
#include <libraries/asl.h>
#include <intuition/menuclass.h>
#include <reaction/reaction_macros.h>
#include <classes/window.h>
#include <gadgets/layout.h>
#include <gadgets/button.h>
#include <images/bitmap.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/asl.h>
#include <proto/graphics.h>
#include <proto/layers.h>
#include <proto/intuition.h>
#include <proto/utility.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/button.h>
#include <proto/bitmap.h>
#include <string.h>


#define DISPLAY_Dummy    (REACTION_Dummy + 0x39000)
#define DISPLAY_FileName (DISPLAY_Dummy + 1)
#define DISPLAY_Aspect   (DISPLAY_Dummy + 2)


struct DisplayData
{
   struct Image *Frame;
   struct Image *BitMapImage;
   TEXT FileName[1024];
   uint32 BitMapWidth;
   uint32 BitMapHeight;
   uint32 AspectRatio;
   struct IBox GadgetBox;
   struct IBox DisplayBox;
   struct Hook *Backfill;
   struct Region *Region;
   Object *ContextMenu;
};


static uint32 DisplayGadgetDispatcher(Class *class, struct Gadget *gad, Msg msg)
{
   struct DisplayData *dd;
   struct TagItem *ti, *tptr;
   struct DrawInfo *dri = NULL;
   struct IBox *box;
   struct TextExtent te;
   struct gpDomain *gpd;
   struct gpLayout *gpl;
   struct gpRender *gpr;
   struct gpHitTest *gpht;
   struct gpInput *gpi;
   struct gpQuery *gpq;
   struct gpMenuEvent *gpme;
   struct TagItem tags[2] = { { 0, 0 }, { TAG_END, 0 } };
   struct Hook *prevbackfill = NULL;
   struct Region *prevregion = NULL;
   struct FileRequester *requester;
   CONST_STRPTR nopic_string = "No picture";
   BOOL redraw, updating = FALSE;
   int32 xoff, yoff;
   uint32 width, height;
   uint32 id, state, result = 0;

   enum
   {
      GMID_LOADPICTURE = 101,  /* Zero is an invalid value for a menu ID */
      GMID_ASPECT,
      GMID_ASPECT_IGNORE,
      GMID_ASPECT_FIT,
      GMID_ASPECT_FILL,
      GMID_CLEAR
   };

   switch (msg->MethodID)
   {
      case OM_NEW:
         result = IDoSuperMethodA(class,(Object *)gad,msg);

         if (result)
         {
            dd = INST_DATA(class,result);

            dd->Frame = (struct Image *)NewObject(NULL,"frameiclass",IA_FrameType,FRAME_DISPLAY,
                                                                     IA_EdgesOnly,TRUE,
                                                                     TAG_END);

            dd->Region = NewRegion();

            dd->ContextMenu = MStrip,
                                 MA_AddChild, MTitle("Display gadget"),
                                    MA_AddChild, MItem("Load picture..."),
                                       MA_ID, GMID_LOADPICTURE,
                                    MEnd,

                                    MA_AddChild, MItem("Aspect ratio"),
                                       MA_ID, GMID_ASPECT,
                                       MA_AddChild, MItem("Ignore"),
                                          MA_ID, GMID_ASPECT_IGNORE,
                                          MA_MX, ~1,
                                       MEnd,

                                       MA_AddChild, MItem("Fit picture"),
                                          MA_ID, GMID_ASPECT_FIT,
                                          MA_MX, ~2,
                                          MA_Selected, TRUE,
                                       MEnd,

                                       MA_AddChild, MItem("Fill box"),
                                          MA_ID, GMID_ASPECT_FILL,
                                          MA_MX, ~4,
                                       MEnd,
                                    MEnd,

                                    MA_AddChild, MItem("Clear"),
                                       MA_ID, GMID_CLEAR,
                                    MEnd,
                                 MEnd,
                              MEnd;

            if (!(dd->Frame && dd->Region && dd->ContextMenu))
            {
               CoerceMethod(class,(Object *)result,OM_DISPOSE);
               result = 0;
            }

            dd->AspectRatio = 1;
         }

         break;

      case OM_DISPOSE:
         dd = INST_DATA(class,gad);
         DisposeObject((Object *)dd->BitMapImage);
         DisposeObject((Object *)dd->Frame);
         if (dd->Region)
            DisposeRegion(dd->Region);
         DisposeObject(dd->ContextMenu);
         result = IDoSuperMethodA(class,(Object *)gad,msg);
         break;

      case OM_SET:
      case OM_UPDATE:
         dd = INST_DATA(class,gad);

         result = IDoSuperMethodA(class,(Object *)gad,msg);

         redraw = FALSE;

         tptr = ((struct opSet *)msg)->ops_AttrList;

         while ((ti = NextTagItem(&tptr)) != NULL)
         {
            switch (ti->ti_Tag)
            {
               case REACTION_BackFill:
               case GA_BackFill:
                  dd->Backfill = (struct Hook *)ti->ti_Data;
                  break;

               case DISPLAY_FileName:
                  if (dd->BitMapImage)
                     DisposeObject((Object *)dd->BitMapImage);

                  if (ti->ti_Data)
                  {
                     if (dd->FileName != (STRPTR)ti->ti_Data)
                        Strlcpy(dd->FileName,(STRPTR)ti->ti_Data,sizeof(dd->FileName));

                     dd->BitMapImage = (struct Image *)BitMapObject,
                                          BITMAP_Screen, ((struct opSet *)msg)->ops_GInfo->gi_Screen,
                                          BITMAP_SourceFile, dd->FileName,
                                          IA_Scalable, TRUE,
                                       BitMapEnd;
                  }
                  else
                  {
                     *(STRPTR)FilePart(dd->FileName) = '\0';
                     dd->BitMapImage = NULL;
                  }

                  if (dd->BitMapImage)
                  {
                     GetAttr(BITMAP_Width,(Object *)dd->BitMapImage,&dd->BitMapWidth);
                     GetAttr(BITMAP_Height,(Object *)dd->BitMapImage,&dd->BitMapHeight);
                  }
                  else
                  {
                     dd->BitMapWidth = dd->BitMapHeight = 0;
                  }

                  redraw = TRUE;
                  break;

               case DISPLAY_Aspect:

                  if ((ti->ti_Data <= 2) && (ti->ti_Data != dd->AspectRatio))
                  {
                     dd->AspectRatio = ti->ti_Data;
                     redraw = TRUE;
                  }

                  break;
            }
         }

         if (redraw)
         {
            result = 0;

            if (((struct opSet *)msg)->ops_GInfo != NULL)
               DoRender((Object *)gad,((struct opSet *)msg)->ops_GInfo,GREDRAW_UPDATE);
            else
               result = 1;
         }

         break;

      case OM_GET:
         dd = INST_DATA(class,gad);

         result = IDoSuperMethodA(class,(Object *)gad,msg);

         switch (((struct opGet *)msg)->opg_AttrID)
         {
            case DISPLAY_FileName:
               *(((struct opGet *)msg)->opg_Storage) = (uint32)dd->FileName;
               result = 1;
               break;

            case DISPLAY_Aspect:
               *(((struct opGet *)msg)->opg_Storage) = dd->AspectRatio;
               result = 1;
               break;
         }

         break;

      case GM_QUERY:
         gpq = (struct gpQuery *)msg;

         dd = INST_DATA(class,gad);

         if (gpq->gpq_Type == GMQ_CONTEXTMENU)
         {
            /* Put the context menu's options in sync
             * with the gadget's current state.
             */
            id = GMID_ASPECT_IGNORE + dd->AspectRatio;

            IDoMethod(dd->ContextMenu,MM_SETSTATE,0,id,MS_CHECKED,MS_CHECKED);

            state = (dd->BitMapImage == NULL)? MS_DISABLED: 0;

            IDoMethod(dd->ContextMenu,MM_SETSTATE,0,GMID_ASPECT,MS_DISABLED,state);
            IDoMethod(dd->ContextMenu,MM_SETSTATE,0,GMID_CLEAR,MS_DISABLED,state);

            /* Pass back the context menu's address.
             */
            *gpq->gpq_Data = (uint32)dd->ContextMenu;

            result = GMR_NOREUSE;
         }

         break;

      case GM_MENUPICK:
         gpme = (struct gpMenuEvent *)msg;

         id = NO_MENU_ID;

         while ((id = IDoMethod(gpme->gpme_MenuAddress,MM_NEXTSELECT,0,id)) != NO_MENU_ID)
         {
            switch (id)
            {
               case GMID_LOADPICTURE:
                  requester = AllocAslRequest(ASL_FileRequest,NULL);

                  if (requester)
                  {
                     BOOL res;
                     TEXT buffer[1024];
                     STRPTR filename;

                     GetAttr(DISPLAY_FileName,(Object *)gad,(uint32 *)&filename);

                     Strlcpy(buffer,filename,sizeof(buffer));
                     *PathPart(buffer) = '\0';

                     res = AslRequestTags(requester,
                                          ASLFR_Window,gpme->gpme_Window,
                                          ASLFR_SleepWindow,TRUE,
                                          ASLFR_TitleText,"Load picture",
                                          ASLFR_InitialDrawer,buffer,
                                          ASLFR_InitialFile,FilePart(filename),
                                          ASLFR_RejectIcons,TRUE,
                                          TAG_END);

                     if (res)
                     {
                        Strlcpy(buffer,requester->fr_Drawer,sizeof(buffer));
                        AddPart(buffer,requester->fr_File,sizeof(buffer));
                     }

                     FreeAslRequest(requester);

                     if (res)
                     {
                        tags[0].ti_Tag = DISPLAY_FileName;
                        tags[0].ti_Data = (uint32)buffer;
                        SetGadgetAttrsA(gad,gpme->gpme_Window,NULL,tags);
                     }
                  }

                  break;

               case GMID_ASPECT_IGNORE:
               case GMID_ASPECT_FIT:
               case GMID_ASPECT_FILL:
                  tags[0].ti_Tag = DISPLAY_Aspect;
                  tags[0].ti_Data = id - GMID_ASPECT_IGNORE;
                  SetGadgetAttrsA(gad,gpme->gpme_Window,NULL,tags);
                  break;

               case GMID_CLEAR:
                  tags[0].ti_Tag = DISPLAY_FileName;
                  tags[0].ti_Data = (uint32)NULL;
                  SetGadgetAttrsA(gad,gpme->gpme_Window,NULL,tags);
                  break;
            }
         }

         break;

      case GM_DOMAIN:
         gpd = (struct gpDomain *)msg;

         if ((gpd->gpd_Which == GDOMAIN_MINIMUM) ||
             (gpd->gpd_Which == GDOMAIN_NOMINAL))
         {
            TextExtent(gpd->gpd_RPort,nopic_string,strlen(nopic_string),&te);
            gpd->gpd_Domain.Width = 16 + te.te_Extent.MaxX - te.te_Extent.MinX + 1;
            if (gpd->gpd_Domain.Width < 204)
               gpd->gpd_Domain.Width = 204;
            gpd->gpd_Domain.Height = 204;
         }
         else  /* GDOMAIN_MAXIMUM */
         {
            gpd->gpd_Domain.Width = gpd->gpd_Domain.Height = 16383;
         }

         result = 1;

         break;

      case GM_LAYOUT:
         gpl = (struct gpLayout *)msg;

         dd = INST_DATA(class,gad);

         box = &(dd->GadgetBox);

         GadgetBox(gad,gpl->gpl_GInfo,GBD_GINFO,0UL,box);

         SetAttrs((Object *)dd->Frame,IA_Left,box->Left,
                                      IA_Top,box->Top,
                                      IA_Width,box->Width,
                                      IA_Height,box->Height,
                                      TAG_END);

         dd->DisplayBox.Left = box->Left + 2;
         dd->DisplayBox.Top = box->Top + 2;
         dd->DisplayBox.Width = box->Width - 4;
         dd->DisplayBox.Height = box->Height - 4;

         result = 1;

         break;

      case GM_EXTENT:
         result = GMR_FULLHBOX;
         break;

      case GM_RENDER:
         gpr = (struct gpRender *)msg;

         dd = INST_DATA(class,gad);

         if (gpr->gpr_Redraw == GREDRAW_REDRAW)
         {
            prevbackfill = InstallLayerHook(gpr->gpr_RPort->Layer,dd->Backfill);

            DrawImageState(gpr->gpr_RPort,dd->Frame,0,0,IDS_NORMAL,gpr->gpr_GInfo->gi_DrInfo);
         }

         SetAPen(gpr->gpr_RPort,gpr->gpr_GInfo->gi_DrInfo->dri_Pens[BACKGROUNDPEN]);

         if (dd->BitMapImage)
         {
            width = (dd->BitMapWidth * dd->DisplayBox.Height) / dd->BitMapHeight;
            height = (dd->BitMapHeight * dd->DisplayBox.Width) / dd->BitMapWidth;

            if (dd->AspectRatio == 1)
            {
               /* Fit the picture in the box so
                * it is completely visible.
                */
               if (width < dd->DisplayBox.Width)
                  height = dd->DisplayBox.Height;
               else
                  width = dd->DisplayBox.Width;
            }
            else if (dd->AspectRatio == 2)
            {
               /* Cover the whole box with the
                * picture, possibly cutting off
                * one or both of its sides.
                */
               if (width > dd->DisplayBox.Width)
                  height = dd->DisplayBox.Height;
               else
                  width = dd->DisplayBox.Width;
            }
            else
            {
               /* Ignore the aspect and just stretch
                * the picture to the size of the box.
                */
               width = dd->DisplayBox.Width;
               height = dd->DisplayBox.Height;
            }

            xoff = ((int32)dd->DisplayBox.Width - (int32)width) / 2;
            yoff = ((int32)dd->DisplayBox.Height - (int32)height) / 2;

            if (xoff > 0)
            {
               RectFill(gpr->gpr_RPort,dd->DisplayBox.Left,dd->DisplayBox.Top,
                                       dd->DisplayBox.Left + xoff - 1,
                                       dd->DisplayBox.Top + dd->DisplayBox.Height - 1);

               RectFill(gpr->gpr_RPort,dd->DisplayBox.Left + xoff + width - 1,dd->DisplayBox.Top,
                                       dd->DisplayBox.Left + dd->DisplayBox.Width - 1,
                                       dd->DisplayBox.Top + dd->DisplayBox.Height - 1);
            }

            if (yoff > 0)
            {
               RectFill(gpr->gpr_RPort,dd->DisplayBox.Left,dd->DisplayBox.Top,
                                       dd->DisplayBox.Left + dd->DisplayBox.Width - 1,
                                       dd->DisplayBox.Top + yoff - 1);

               RectFill(gpr->gpr_RPort,dd->DisplayBox.Left,dd->DisplayBox.Top + yoff + height - 1,
                                       dd->DisplayBox.Left + dd->DisplayBox.Width - 1,
                                       dd->DisplayBox.Top + dd->DisplayBox.Height - 1);
            }

            if ((xoff < 0) || (yoff < 0))
            {
               struct Rectangle rect;

               rect.MinX = dd->DisplayBox.Left;
               rect.MinY = dd->DisplayBox.Top;
               rect.MaxX = rect.MinX + dd->DisplayBox.Width - 1;
               rect.MaxY = rect.MinY + dd->DisplayBox.Height - 1;

               ClearRegion(dd->Region);
               OrRectRegion(dd->Region,&rect);

               if (gpr->gpr_RPort->Layer->Flags & LAYERUPDATING)
               {
                  EndUpdate(gpr->gpr_RPort->Layer,FALSE);
                  updating = TRUE;
               }

               prevregion = InstallClipRegion(gpr->gpr_RPort->Layer,dd->Region);
            }

            SetAttrs((Object *)dd->BitMapImage,IA_Width,width,
                                               IA_Height,height,
                                               TAG_END);

            DrawImageState(gpr->gpr_RPort,dd->BitMapImage,
                           dd->DisplayBox.Left + xoff,dd->DisplayBox.Top + yoff,
                           IDS_NORMAL,gpr->gpr_GInfo->gi_DrInfo);

            if ((xoff < 0) || (yoff < 0))
            {
               InstallClipRegion(gpr->gpr_RPort->Layer,prevregion);
               if (updating)
                  BeginUpdate(gpr->gpr_RPort->Layer);
            }
         }
         else
         {
            RectFill(gpr->gpr_RPort,dd->DisplayBox.Left,dd->DisplayBox.Top,
                                    dd->DisplayBox.Left + dd->DisplayBox.Width - 1,
                                    dd->DisplayBox.Top + dd->DisplayBox.Height - 1);

            TextExtent(gpr->gpr_RPort,nopic_string,strlen(nopic_string),&te);

            width = te.te_Extent.MaxX - te.te_Extent.MinX + 1;
            height = te.te_Height;

            xoff = dd->DisplayBox.Left + (dd->DisplayBox.Width - width) / 2 - te.te_Extent.MinX;
            yoff = dd->DisplayBox.Top + (dd->DisplayBox.Height - height) / 2 - te.te_Extent.MinY;

            Move(gpr->gpr_RPort,xoff,yoff);
            SetABPenDrMd(gpr->gpr_RPort,gpr->gpr_GInfo->gi_DrInfo->dri_Pens[TEXTPEN],0,JAM1);

            Text(gpr->gpr_RPort,nopic_string,strlen(nopic_string));
         }

         if (gpr->gpr_Redraw == GREDRAW_REDRAW)
         {
            InstallLayerHook(gpr->gpr_RPort->Layer,prevbackfill);
         }

         break;

      default:
         result = IDoSuperMethodA(class,(Object *)gad,msg);
   }

   return (result);
}

static Class *MakeDisplayGadgetClass(void)
{
   Class *class;

   class = MakeClass(NULL,"gadgetclass",NULL,sizeof(struct DisplayData),0UL);

   if (class != NULL)
      class->cl_Dispatcher.h_Entry = (HOOKFUNC)DisplayGadgetDispatcher;

   return (class);
}

static void FreeDisplayGadgetClass(Class *class)
{
   if (class != NULL)
      FreeClass(class);
}


int main(void)
{
   Class *displaygclass;
   Object *windowobj, *layoutobj, *displayobj;
   Object *menustripobj = NULL;
   struct Screen *scr;
   struct Window *win;
   struct Menu *menuaddress;
   struct MsgPort *port;
   uint32 menutype = IMT_DEFAULT;
   uint32 waitmask, input, id;
   uint16 code;
   APTR menucontext;
   BOOL done = FALSE;

   enum
   {
      MID_ICONIFY = 1,  /* Zero is an invalid value for a menu ID */
      MID_QUIT
   };

   if (!((IntuitionBase->lib_Version > 54) ||
         ((IntuitionBase->lib_Version == 54) &&
          (IntuitionBase->lib_Revision >= 6))))
   {
      Printf("This program requires at least version 54.6 of intuition.library.\n");
      return (RETURN_ERROR);
   }

   if (WindowBase->lib_Version < 54)
   {
      Printf("This program requires at least version 54 of window.class.\n");
      return (RETURN_ERROR);
   }

   if (LayoutBase->lib_Version < 54)
   {
      Printf("This program requires at least version 54 of layout.gadget.\n");
      return (RETURN_ERROR);
   }

   displaygclass = MakeDisplayGadgetClass();

   if (displaygclass == NULL)
   {
      Printf("Failed to set up custom gadget class.\n");
      return (RETURN_FAIL);
   }

   port = AllocSysObject(ASOT_PORT,NULL);

   if ((scr = LockPubScreen("Workbench")) != NULL)
   {
      /* Build the program's menu tree.
       */
      menustripobj = MStrip,
         MA_AddChild, MTitle("Project"),
            MA_AddChild, MItem("I|Iconify"),
               MA_ID, MID_ICONIFY,
            MEnd,

            MA_AddChild, MSeparator,
            MEnd,

            MA_AddChild, MItem("Q|Quit"),
               MA_ID, MID_QUIT,
            MEnd,
         MEnd,
      MEnd;

      UnlockPubScreen(NULL,scr);
   }

   layoutobj = VGroupObject,
      LAYOUT_DeferLayout, TRUE,
      LAYOUT_SpaceOuter, TRUE,
      LAYOUT_AddChild, ButtonObject,
         GA_ReadOnly, TRUE,
         GA_Text, "Click RMB over display gadget to bring up its context menu",
         BUTTON_BevelStyle, BVS_NONE,
         BUTTON_Transparent, TRUE,
      ButtonEnd,
      CHILD_WeightedHeight, 0,

      LAYOUT_AddChild, displayobj = NewObject(displaygclass,NULL,
         GA_ID, 1234,
      TAG_END),

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
                IDCMP_MENUPICK,
      WA_Activate, TRUE,
      WA_CloseGadget, TRUE,
      WA_Title, "Gadget context menu test",
      WA_DragBar, TRUE,
      WA_DepthGadget, TRUE,
      WA_SizeGadget, TRUE,
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

   if (port)
      FreeSysObject(ASOT_PORT,port);

   FreeDisplayGadgetClass(displaygclass);

   return (RETURN_OK);
}


