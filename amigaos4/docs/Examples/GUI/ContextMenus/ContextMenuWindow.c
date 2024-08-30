

/* A simple example of Intuition's window context menus */

/* Compile: gcc -o ContextMenuWindow ContextMenuWindow.c -lauto */


#define __USE_INLINE__
#include <clib/macros.h>
#include <graphics/rpattr.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <proto/intuition.h>
#include <proto/gadtools.h>
#include <proto/utility.h>
#include <stdlib.h>
#include <string.h>


enum
{
   ITEM_Rows1 = 101,
   ITEM_Rows2,
   ITEM_Rows3,
   ITEM_Rows4,
   ITEM_Rows5,

   ITEM_Columns1 = 201,
   ITEM_Columns2,
   ITEM_Columns3,
   ITEM_Columns4,
   ITEM_Columns5,

   ITEM_Quit
};

enum
{
   ITEM_Red = 1,
   ITEM_Yellow,
   ITEM_Green,
   ITEM_Blue,
   ITEM_BlackBorder,
   ITEM_WhiteBorder,
   ITEM_ShowBorder
};

struct ColorItem
{
   struct Rectangle OuterRect;
   struct Rectangle ColorRect;
   uint32 InnerColor;
   uint32 BorderColor;
   BOOL HasBorder;
};

struct GlobalData
{
   struct ColorItem *ColorItems;
   uint32 Columns, Rows;
   struct Menu *ContextMenu;
};


const CONST_STRPTR Header[2] =
{
   "Click RMB over a color box to bring up its context menu.",
   "Use the window's regular menu to change the number of boxes.",
};


static BOOL AllocColorItems(struct GlobalData *gd, uint32 columns, uint32 rows)
{
   struct ColorItem *ci;
   uint32 i, count, prevcount;

   count = columns * rows;

   ci = AllocVecTags(count * sizeof(struct ColorItem), AVT_ClearWithValue, 0, TAG_END);

   if (ci == NULL)
      return (FALSE);

   if (gd->ColorItems)
      prevcount = gd->Columns * gd->Rows;
   else
      prevcount = 0;

   for (i = 0; i < count; i++)
   {
      if (i < prevcount)
      {
         ci[i].InnerColor = gd->ColorItems[i].InnerColor;
         ci[i].BorderColor = gd->ColorItems[i].BorderColor;
         ci[i].HasBorder = gd->ColorItems[i].HasBorder;
      }
      else
      {
         ci[i].InnerColor = ITEM_Red + rand() % 4;
         ci[i].BorderColor = ITEM_BlackBorder + rand() % 2;
         ci[i].HasBorder = (rand() & 1)? TRUE: FALSE;
      }
   }

   if (gd->ColorItems)
      FreeVec(gd->ColorItems);

   gd->ColorItems = ci;
   gd->Columns = columns;
   gd->Rows = rows;

   return (TRUE);
}

static void LayoutColorItems(struct GlobalData *gd, int32 left, int32 top, uint32 width, uint32 height)
{
   uint32 x, y, cwidth, cheight;
   uint32 i, count, owidth, oheight;
   int32 rowtop;
   struct ColorItem *ci;

   cwidth = width / (gd->Columns * 2);
   cheight = height / (gd->Rows * 2);

   ci = gd->ColorItems;

   for (y = 0; y < gd->Rows; y++)
   {
      rowtop = top + (height * y) / gd->Rows;

      for (x = 0; x < gd->Columns; x++)
      {
         ci->OuterRect.MinX = left + (width * x) / gd->Columns;
         if (x > 0)
            ci[-1].OuterRect.MaxX = ci->OuterRect.MinX - 1;
         if (x == (gd->Columns - 1))
            ci->OuterRect.MaxX = left + width - 1;

         ci->OuterRect.MinY = rowtop;
         if (y > 0)
            ci[-gd->Columns].OuterRect.MaxY = ci->OuterRect.MinY - 1;
         if (y == (gd->Rows - 1))
            ci->OuterRect.MaxY = top + height - 1;

         ci += 1;
      }
   }

   ci = gd->ColorItems;
   count = gd->Columns * gd->Rows;

   for (i = 0; i < count; i++)
   {
      owidth = ci->OuterRect.MaxX - ci->OuterRect.MinX + 1;
      oheight = ci->OuterRect.MaxY - ci->OuterRect.MinY + 1;

      ci->ColorRect.MinX = ci->OuterRect.MinX + (owidth - cwidth) / 2;
      ci->ColorRect.MaxX = ci->ColorRect.MinX + cwidth - 1;
      ci->ColorRect.MinY = ci->OuterRect.MinY + (oheight - cheight) / 2;
      ci->ColorRect.MaxY = ci->ColorRect.MinY + cheight - 1;

      ci += 1;
   }
}

static void LayoutWindow(struct GlobalData *gd, struct Window *window)
{
   uint32 left, top, width, height;

   left = window->BorderLeft;
   top = window->BorderTop + 4 * window->RPort->TxHeight + 1;
   width = window->GZZWidth;
   height = window->GZZHeight - 4 * window->RPort->TxHeight - 1;

   LayoutColorItems(gd,left,top,width,height);
};

static void DrawColorItem(struct Window *window, struct ColorItem *coloritem)
{
   struct Rectangle *orect, *crect;
   uint32 innercolor, bordercolor, bsize = 0;

   switch (coloritem->InnerColor)
   {
      case ITEM_Red:
         innercolor = 0xFFEF3F3F;
         break;

      case ITEM_Yellow:
         innercolor = 0xFFE0E03F;
         break;

      case ITEM_Green:
         innercolor = 0xFF3FD03F;
         break;

      case ITEM_Blue:
         innercolor = 0xFF3F3FEF;
         break;
   }

   switch (coloritem->BorderColor)
   {
      case ITEM_BlackBorder:
         bordercolor = 0xFF000000;
         break;

      case ITEM_WhiteBorder:
         bordercolor = 0xFFEFEFEF;
         break;
   }

   orect = &coloritem->OuterRect;
   crect = &coloritem->ColorRect;

   EraseRect(window->RPort,orect->MinX,orect->MinY,orect->MaxX,crect->MinY - 1);
   EraseRect(window->RPort,orect->MinX,crect->MinY,crect->MinX - 1,crect->MaxY);
   EraseRect(window->RPort,crect->MaxX + 1,crect->MinY,orect->MaxX,crect->MaxY);
   EraseRect(window->RPort,orect->MinX,crect->MaxY + 1,orect->MaxX,orect->MaxY);

   if (coloritem->HasBorder)
   {
      bsize = 3;

      SetRPAttrs(window->RPort,RPTAG_APenColor,bordercolor,TAG_END);
      RectFill(window->RPort,crect->MinX,crect->MinY,crect->MaxX,crect->MinY + bsize - 1);
      RectFill(window->RPort,crect->MinX,crect->MinY,crect->MinX + bsize - 1,crect->MaxY);
      RectFill(window->RPort,crect->MinX,crect->MaxY - bsize - 1,crect->MaxX,crect->MaxY);
      RectFill(window->RPort,crect->MaxX - bsize - 1,crect->MinY,crect->MaxX,crect->MaxY);
   }

   SetRPAttrs(window->RPort,RPTAG_APenColor,innercolor,TAG_END);
   RectFill(window->RPort,crect->MinX + bsize,crect->MinY + bsize,crect->MaxX - bsize,crect->MaxY - bsize);
}

static void RenderWindow(struct GlobalData *gd, struct Window *window)
{
   struct DrawInfo *dri;
   struct TextExtent te;
   struct ColorItem *ci;
   int32 left, top, tleft;
   uint32 pen = 1, len, fit, width, twidth, theight, i, count;

   if ((dri = GetScreenDrawInfo(window->WScreen)) != NULL)
   {
      pen = dri->dri_Pens[TEXTPEN];
      FreeScreenDrawInfo(window->WScreen,dri);
   }

   left = window->BorderLeft;
   top = window->BorderTop;
   width = window->GZZWidth;

   theight = window->RPort->TxHeight;

   SetABPenDrMd(window->RPort,0,0,JAM2);
   RectFill(window->RPort,left,top,left + width - 1,top + theight - 1);

   top += theight;

   for (i = 0; i < 2; i++)
   {
      SetAPen(window->RPort,pen);
      len = strlen(Header[i]);
      fit = TextFit(window->RPort,Header[i],len,&te,NULL,1,width,theight);
      tleft = left - te.te_Extent.MinX;
      twidth = te.te_Extent.MaxX - te.te_Extent.MinX + 1;
      if (fit == len)
         tleft += (width - twidth) / 2;
      Move(window->RPort,tleft,top - te.te_Extent.MinY);
      Text(window->RPort,Header[i],fit);

      SetAPen(window->RPort,0);
      if ((tleft + te.te_Extent.MinX) > left)
         RectFill(window->RPort,left,top,tleft + te.te_Extent.MinX - 1,top + theight - 1);
      if ((tleft + te.te_Extent.MaxX) < (left + width - 1))
         RectFill(window->RPort,tleft + te.te_Extent.MaxX + 1,top,left + width - 1,top + theight - 1);

      top += theight;
   }

   RectFill(window->RPort,left,top,left + width - 1,top + theight - 1);

   top += theight;

   SetAPen(window->RPort,pen);
   RectFill(window->RPort,left,top,left + width - 1,top);

   ci = gd->ColorItems;
   count = gd->Columns * gd->Rows;

   for (i = 0; i < count; i++)
      DrawColorItem(window,&ci[i]);
}

static struct MenuItem *FindMenuItem(struct Menu *strip, uint32 id)
{
   struct MenuItem *mi, *si;

   while (strip)
   {
      mi = strip->FirstItem;

      while (mi)
      {
         if ((uint32)GTMENUITEM_USERDATA(mi) == id)
            return (mi);

         si = mi->SubItem;

         while (si)
         {
            if ((uint32)GTMENUITEM_USERDATA(si) == id)
               return (si);
            si = si->NextItem;
         }

         mi = mi->NextItem;
      }

      strip = strip->NextMenu;
   }

   return (NULL);
}

static uint32 ContextMenuHookFunction(struct Hook *hook, struct Window *window, struct ContextMenuMsg *msg)
{
   struct GlobalData *gd = hook->h_Data;
   struct ColorItem *ci;
   struct Rectangle *crect;
   struct MenuItem *item;
   uint32 i, j, count;

   if (gd->ContextMenu == NULL)
      return (0);

   if (msg->State == CM_QUERY)
   {
      count = gd->Columns * gd->Rows;

      for (i = 0; i < count; i++)
      {
         ci = &gd->ColorItems[i];
         crect = &ci->ColorRect;

         if ((window->MouseX >= crect->MinX) && (window->MouseY >= crect->MinY) &&
             (window->MouseX <= crect->MaxX) && (window->MouseY <= crect->MaxY))
         {
            for (j = ITEM_Red; j <= ITEM_Blue; j++)
            {
               item = FindMenuItem(gd->ContextMenu,j);
               if (j == ci->InnerColor)
                  item->Flags |= CHECKED;
               else
                  item->Flags &= ~CHECKED;
            }

            for (j = ITEM_BlackBorder; j <= ITEM_WhiteBorder; j++)
            {
               item = FindMenuItem(gd->ContextMenu,j);
               if (j == ci->BorderColor)
                  item->Flags |= CHECKED;
               else
                  item->Flags &= ~CHECKED;
            }

            item = FindMenuItem(gd->ContextMenu,ITEM_ShowBorder);
            if (ci->HasBorder)
               item->Flags |= CHECKED;
            else
               item->Flags &= ~CHECKED;

            msg->Menu = gd->ContextMenu;
            msg->Context = ci;

            break;
         }
      }
   }

   return (0);
}


int main(void)
{
   struct Screen *scr;
   struct Window *win = NULL;
   struct IntuiMessage *imsg;
   APTR iaddress, vi = NULL;
   uint32 minwidth;
   uint32 class;
   uint32 columns = 3, rows = 3;
   uint16 code;
   BOOL done = FALSE;
   struct TextExtent te;
   struct Menu *menustrip = NULL;
   struct Menu *win_contextmenu = NULL;
   struct MenuItem *item;
   struct Hook cmhook;
   struct GlobalData globaldata;
   struct NewMenu newmenu[] =
   {
      NM_TITLE, "Project", NULL, 0, 0L, NULL,
       NM_ITEM, "Rows",      NULL, 0,                0UL, NULL,
        NM_SUB, "1",         NULL, CHECKIT,           ~1, (APTR)ITEM_Rows1,
        NM_SUB, "2",         NULL, CHECKIT,           ~2, (APTR)ITEM_Rows2,
        NM_SUB, "3",         NULL, CHECKIT | CHECKED, ~4, (APTR)ITEM_Rows3,
        NM_SUB, "4",         NULL, CHECKIT,           ~8, (APTR)ITEM_Rows4,
        NM_SUB, "5",         NULL, CHECKIT,          ~16, (APTR)ITEM_Rows5,
       NM_ITEM, "Columns",   NULL, 0,                0UL, NULL,
        NM_SUB, "1",         NULL, CHECKIT,           ~1, (APTR)ITEM_Columns1,
        NM_SUB, "2",         NULL, CHECKIT,           ~2, (APTR)ITEM_Columns2,
        NM_SUB, "3",         NULL, CHECKIT | CHECKED, ~4, (APTR)ITEM_Columns3,
        NM_SUB, "4",         NULL, CHECKIT,           ~8, (APTR)ITEM_Columns4,
        NM_SUB, "5",         NULL, CHECKIT,          ~16, (APTR)ITEM_Columns5,
       NM_ITEM, NM_BARLABEL, NULL, 0,                0UL, NULL,
       NM_ITEM, "Quit",      "Q",  0,                0UL, (APTR)ITEM_Quit,
      NM_END
   };
   struct NewMenu win_newcontextmenu[] =
   {
      NM_TITLE, "Color box menu", NULL, 0,                    0UL, NULL,
       NM_ITEM, "Inner color",    NULL, 0,                    0UL, NULL,
        NM_SUB, "Red",            NULL, CHECKIT,               ~1, (APTR)ITEM_Red,
        NM_SUB, "Yellow",         NULL, CHECKIT,               ~2, (APTR)ITEM_Yellow,
        NM_SUB, "Green",          NULL, CHECKIT,               ~4, (APTR)ITEM_Green,
        NM_SUB, "Blue",           NULL, CHECKIT,               ~8, (APTR)ITEM_Blue,
       NM_ITEM, "Border color",   NULL, 0,                    0UL, NULL,
        NM_SUB, "Black",          NULL, CHECKIT,               ~1, (APTR)ITEM_BlackBorder,
        NM_SUB, "White",          NULL, CHECKIT,               ~2, (APTR)ITEM_WhiteBorder,
       NM_ITEM, NM_BARLABEL,      NULL, 0,                    0UL, NULL,
       NM_ITEM, "Show border?",   NULL, CHECKIT | MENUTOGGLE, 0UL, (APTR)ITEM_ShowBorder,
      NM_END
   };

   if (!((IntuitionBase->lib_Version > 54) ||
         ((IntuitionBase->lib_Version == 54) &&
          (IntuitionBase->lib_Revision >= 6))))
   {
      Printf("This program requires at least version 54.6 of intuition.library.\n");
      return (RETURN_ERROR);
   }

   srand(time(NULL));

   memset(&globaldata,0,sizeof(struct GlobalData));

   if (!AllocColorItems(&globaldata,columns,rows))
      return (RETURN_FAIL);

   if ((scr = LockPubScreen("Workbench")) != NULL)
   {
      if ((vi = GetVisualInfoA(scr,NULL)) != NULL)
      {
         if ((menustrip = CreateMenusA(newmenu,NULL)) != NULL)
         {
            if (!LayoutMenus(menustrip,vi,GTMN_NewLookMenus,TRUE,TAG_END))
            {
               FreeMenus(menustrip);
               menustrip = NULL;
            }
         }

         if ((win_contextmenu = CreateMenusA(win_newcontextmenu,NULL)) != NULL)
         {
            if (!LayoutMenus(win_contextmenu,vi,GTMN_NewLookMenus,TRUE,TAG_END))
            {
               FreeMenus(win_contextmenu);
               win_contextmenu = NULL;
            }
         }

         globaldata.ContextMenu = win_contextmenu;

         memset(&cmhook,0,sizeof(struct Hook));
         cmhook.h_Entry = (HOOKFUNC)ContextMenuHookFunction;
         cmhook.h_Data = &globaldata;

         TextExtent(&scr->RastPort,Header[0],strlen(Header[0]),&te);
         minwidth = te.te_Width;
         TextExtent(&scr->RastPort,Header[1],strlen(Header[1]),&te);
         if (te.te_Width > minwidth)
            minwidth = te.te_Width;
         minwidth += scr->WBorLeft + scr->WBorRight + 16;

         win = OpenWindowTags(NULL,WA_PubScreen,scr,
                                   WA_Left,(scr->Width - MAX(640,minwidth)) / 2,
                                   WA_Top,(scr->Height - 480) / 2,
                                   WA_Width,MAX(640,minwidth),
                                   WA_Height,480,
                                   WA_MinWidth,minwidth,
                                   WA_MinHeight,320,
                                   WA_MaxWidth,-1,
                                   WA_MaxHeight,-1,
                                   WA_CloseGadget,TRUE,
                                   WA_Title,"Window context menu test",
                                   WA_DragBar,TRUE,
                                   WA_DepthGadget,TRUE,
                                   WA_SizeGadget,TRUE,
                                   WA_SizeBBottom,TRUE,
                                   WA_Activate,TRUE,
                                   WA_NoCareRefresh,TRUE,
                                   WA_IDCMP,IDCMP_CLOSEWINDOW |
                                            IDCMP_MENUPICK |
                                            IDCMP_NEWSIZE,
                                   WA_NewLookMenus,TRUE,
                                   WA_ContextMenuHook,&cmhook,
                                   TAG_END);
      }
   }

   if (win)
   {
      if (menustrip)
         SetMenuStrip(win,menustrip);

      SetFont(win->RPort,scr->RastPort.Font);

      LayoutWindow(&globaldata,win);
      RenderWindow(&globaldata,win);

      while (!done)
      {
         Wait(1 << win->UserPort->mp_SigBit);

         while (imsg = (struct IntuiMessage *)GetMsg(win->UserPort))
         {
            class = imsg->Class;
            code = imsg->Code;
            iaddress = imsg->IAddress;

            if (class == IDCMP_CLOSEWINDOW)
            {
               done = TRUE;
            }
            else if (class == IDCMP_MENUPICK)
            {
               struct TagItem *tags = ((struct ExtIntuiMessage *)imsg)->eim_TagList;
               uint32 menutype;

               menutype = GetTagData(IMTAG_MenuType,IMT_DEFAULT,tags);

               if ((menutype == IMT_CONTEXT_WINDOW) && (iaddress == win_contextmenu))
               {
                  struct ColorItem *ci;
                  uint32 item_id;

                  ci = (struct ColorItem *)GetTagData(IMTAG_MenuContext,0,tags);

                  item = ItemAddress(iaddress,code);

                  while (item)
                  {
                     item_id = (uint32)GTMENUITEM_USERDATA(item);

                     if ((item_id >= ITEM_Red) && (item_id <= ITEM_Blue))
                        ci->InnerColor = item_id;
                     else if ((item_id == ITEM_BlackBorder) || (item_id == ITEM_WhiteBorder))
                        ci->BorderColor = item_id;
                     else if (item_id == ITEM_ShowBorder)
                        ci->HasBorder = ((item->Flags & CHECKED) != 0);

                     item = ItemAddress(iaddress,item->NextSelect);
                  }

                  DrawColorItem(win,ci);
               }
               else if (menutype == IMT_DEFAULT)
               {
                  uint32 item_id;

                  item = ItemAddress(iaddress,code);

                  while (item)
                  {
                     item_id = (uint32)GTMENUITEM_USERDATA(item);

                     if ((item_id >= ITEM_Rows1) && (item_id <= ITEM_Rows5))
                        rows = item_id - ITEM_Rows1 + 1;
                     else if ((item_id >= ITEM_Columns1) && (item_id <= ITEM_Columns5))
                        columns = item_id - ITEM_Columns1 + 1;
                     else if (item_id == ITEM_Quit)
                        done = TRUE;

                     if ((rows != globaldata.Rows) || (columns != globaldata.Columns))
                     {
                        if (AllocColorItems(&globaldata,columns,rows))
                        {
                           LayoutWindow(&globaldata,win);
                           RenderWindow(&globaldata,win);
                        }

                        rows = globaldata.Rows;
                        columns = globaldata.Columns;
                     }

                     item = ItemAddress(iaddress,item->NextSelect);
                  }
               }
            }
            else if (class == IDCMP_NEWSIZE)
            {
               LayoutWindow(&globaldata,win);
               RenderWindow(&globaldata,win);
            }

            ReplyMsg((struct Message *)imsg);
         }
      }

      if (menustrip) ClearMenuStrip(win);

      CloseWindow(win);
   }

   if (win_contextmenu)
      FreeMenus(win_contextmenu);

   if (menustrip)
      FreeMenus(menustrip);

   if (vi)
      FreeVisualInfo(vi);

   if (scr)
      UnlockPubScreen(NULL,scr);

   FreeVec(globaldata.ColorItems);

   return (RETURN_OK);
}

