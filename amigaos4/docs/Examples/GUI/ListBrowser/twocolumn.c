;/* Execute me to compile
gcc -o twocolumn twocolumn.c -lauto
quit
;*/

#include <exec/exec.h>
#include <intuition/intuition.h>
#include <intuition/gui.h>
#include <dos/dos.h>
#include <images/label.h>
#include <classes/window.h>
#include <gadgets/layout.h>
#include <gadgets/listbrowser.h>
#include <libraries/keymap.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/intuition.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/label.h>
#include <proto/listbrowser.h>


Object *win;

struct MsgPort *AppPort;
struct List listbrowser_list;
struct ColumnInfo *columninfo = NULL;

enum
{
    OBJ_LISTBROWSER,
    OBJ_QUIT,
    OBJ_NUM
};

Object *Objects[OBJ_NUM];
#define OBJ(x) Objects[x]
#define GAD(x) (struct Gadget *)Objects[x]

#define NUMBOOLS 13

uint32 tagdatas[NUMBOOLS];

int32 tags[] =
{
    GUIA_ScreenDragging,
    GUIA_OffScreenDragging,
    GUIA_OffScreenSizing,
    GUIA_WindowPropLook,
    GUIA_WindowPropKnobColor,
    GUIA_WindowPropBorder,
    GUIA_PropKnobColor,
    GUIA_PropBorder,
    GUIA_MenuDropShadows,
    GUIA_MenuTransparency,
    GUIA_EvenRequesterButtons,
    GUIA_AutomaticEdgesContrast,
    GUIA_RealShading
};

STRPTR list_strings[] =
{
    " GUIA_ScreenDragging",
    " GUIA_OffScreenDragging",
    " GUIA_OffScreenSizing",
    " GUIA_WindowPropLook",
    " GUIA_WindowPropKnobColor",
    " GUIA_WindowPropBorder",
    " GUIA_PropKnobColor",
    " GUIA_PropBorder",
    " GUIA_MenuDropShadows",
    " GUIA_MenuTransparency",
    " GUIA_EvenRequesterButtons",
    " GUIA_AutomaticEdgesContrast ",
    " GUIA_RealShading",
    NULL
};

BOOL GetGuiData(void);
BOOL make_browserlist(struct List *, char **, uint32 *);


Object *
make_window(void)
{
    columninfo = IListBrowser->AllocLBColumnInfo(2,
        LBCIA_Column, 0,
            LBCIA_Title, " GUI Attributes",
            LBCIA_Width, 80,
        LBCIA_Column, 1,
            LBCIA_Title, " BOOL",
            LBCIA_Width, 20,
        TAG_DONE);

    return IIntuition->NewObject(NULL, "window.class",
        WA_ScreenTitle,        "ReAction Example",
        WA_Title,              "Two Column Example",
        WA_DragBar,            TRUE,
        WA_CloseGadget,        TRUE,
        WA_SizeGadget,         TRUE,
        WA_DepthGadget,        TRUE,
        WA_Activate,           TRUE,
        WA_InnerWidth,         260,
        WA_InnerHeight,        300,
        WINDOW_IconifyGadget,  TRUE,
        WINDOW_IconTitle,      "Iconified",
        WINDOW_AppPort,        AppPort,
        WINDOW_Position,       WPOS_CENTERSCREEN,
        WINDOW_Layout,         IIntuition->NewObject(NULL, "layout.gadget",
			LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
            LAYOUT_SpaceOuter,  TRUE,
            LAYOUT_AddChild,    IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
                LAYOUT_SpaceOuter,  TRUE,
                LAYOUT_BevelStyle,  BVS_GROUP,
                LAYOUT_Label,       " GUI Tags ",

                LAYOUT_AddChild, OBJ(OBJ_LISTBROWSER) = IIntuition->NewObject(NULL, "listbrowser.gadget",
                    GA_ID,                     OBJ_LISTBROWSER,
                    GA_RelVerify,              TRUE,
                    GA_TabCycle,               TRUE,
                    LISTBROWSER_AutoFit,       TRUE,
                    LISTBROWSER_Labels,        &listbrowser_list,
                    LISTBROWSER_ColumnInfo,    columninfo,
                    LISTBROWSER_ColumnTitles,  TRUE,
                    LISTBROWSER_ShowSelected,  TRUE,
                    LISTBROWSER_Striping,      LBS_ROWS,
                TAG_DONE),

                LAYOUT_AddChild, IIntuition->NewObject(NULL, "button.gadget",
					GA_Text, "_Quit",
					GA_ID, OBJ_QUIT,
					GA_RelVerify, TRUE,
                    GA_TabCycle, TRUE,
					TAG_DONE),
                CHILD_WeightedHeight,   0,

            TAG_DONE),
        TAG_END),
    TAG_DONE);
}


int main()
{
    struct Window *window;
    AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_END);
    
    if (AppPort != NULL)
    {
        if (!(GetGuiData())) goto out;
        if (make_browserlist(&listbrowser_list, list_strings, tagdatas))
        {
            win = make_window();
            if (window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN))
            {
                BOOL done = FALSE;

                uint32 sigmask = 0;
                IIntuition->GetAttr(WINDOW_SigMask, win, &sigmask);

                while (!done)
                {
                    uint32 siggot = IExec->Wait(sigmask | SIGBREAKF_CTRL_C);
                    if (siggot & SIGBREAKF_CTRL_C)
                    {
                        done = TRUE;
                    }

                    uint32 result = 0;
                    uint16 code   = 0;

                    while ((result = IIntuition->IDoMethod(win, WM_HANDLEINPUT, &code)))
                    {
                        switch(result & WMHI_CLASSMASK)
                        {
                            case WMHI_CLOSEWINDOW:
                                done = TRUE;
                                break;
                            case WMHI_GADGETUP:
                                switch (result & WMHI_GADGETMASK)
                                {
                                    case OBJ_QUIT:
                                        done = TRUE;
                                        break;
                                }
                                break;
                            case WMHI_ICONIFY:
                                if (IIntuition->IDoMethod(win, WM_ICONIFY))
                                {
                                    window = NULL;
                                }
                                break;
                            case WMHI_UNICONIFY:
                                window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN);
                                break;
                            case WMHI_RAWKEY:
                                if (code == (IECODE_UP_PREFIX | RAWKEY_TAB))
                                {
                                    IIntuition->IDoMethod(win, WM_ACTIVATEGADGET, OBJ(OBJ_LISTBROWSER));
                                }
                                break;
                        }
                    }
                }
            }

            IIntuition->DisposeObject(win);
            IListBrowser->FreeListBrowserList(&listbrowser_list);
            IListBrowser->FreeLBColumnInfo(columninfo);
        }

out:    IExec->FreeSysObject(ASOT_PORT, AppPort);
    }
}


BOOL GetGuiData()
{
    struct Screen *screen = NULL;
    int i;

    if (screen = IIntuition->LockPubScreen(NULL))
    {
        struct DrawInfo *drinfo = NULL;
        if (drinfo = IIntuition->GetScreenDrawInfo(screen))
        {
            for (i=0; i<NUMBOOLS; i++)
            {
                IIntuition->GetGUIAttrs(NULL,drinfo,
                    tags[i], &tagdatas[i],
                    TAG_END);
            }
            IIntuition->FreeScreenDrawInfo(screen, drinfo);
        }
        else
        {
            IDOS->Printf("ERROR: Couldn't get DrawInfo\n");
            IIntuition->UnlockPubScreen(0, screen);
            return(FALSE);
        }
        IIntuition->UnlockPubScreen(0, screen);
        return(TRUE);
    }
    else
    {
        IDOS->Printf("ERROR: Couldn't lock public screen\n");
        return(FALSE);
    }
}


BOOL make_browserlist(struct List *list, char **tagstring, uint32 *bools)
{
    struct Node *node;
    uint16 num = 0;
    STRPTR truefalse[] = {" FALSE"," TRUE",NULL};

    IExec->NewList(list);
    while (*tagstring)
    {
        if (node = IListBrowser->AllocListBrowserNode(2,
            LBNA_Column, 0,
                LBNCA_Text, *tagstring,
            LBNA_Column, 1,
                LBNCA_Text, truefalse[bools[num]],
            TAG_DONE))
        {
            IExec->AddTail(list, node);
        }
        else
        {
            IDOS->Printf(" AllocListBrowserNode() failed\n");
            return(FALSE);
        }
        tagstring++;
        num ++;
    }
    return(TRUE);
}

