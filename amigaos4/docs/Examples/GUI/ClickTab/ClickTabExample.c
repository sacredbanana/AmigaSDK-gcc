;/* Execute me to compile:
gcc -o ClickTabExample ClickTabExample.c -lauto
quit
*/

#include <dos/dos.h>
#include <intuition/intuition.h>
#include <classes/window.h>
#include <gadgets/layout.h>
#include <gadgets/clicktab.h>

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/clicktab.h>


#define OBJ(x) Objects[x]
#define GAD(x) (struct Gadget *)Objects[x]


Object *win;

struct MsgPort *AppPort;

enum
{
    OBJ_CLICKTAB_1,
    OBJ_CLICKTAB_2,
    OBJ_QUIT,
    OBJ_NUM
};

Object *Objects[OBJ_NUM];

STRPTR PageLabels_1[] = {"Tab 1", "Tab 2", "Tab 3", NULL};
STRPTR PageLabels_2[] = {"Tab 3a", "Tab 3b", NULL};

struct Hook newprefshook;


VOID prefshookfunc( struct Hook *me, APTR winobj, APTR reserved )
{
	IExec->DebugPrintF("new prefs hook called\n");
}


Object *
make_window(void)
{
	/* create hook */
	newprefshook.h_Entry = (HOOKFUNC)prefshookfunc;
	newprefshook.h_SubEntry = NULL;
	newprefshook.h_Data = NULL;

    Object
            *page1 = NULL,
            *page2 = NULL,
            *page3 = NULL,
            *page3a = NULL,
            *page3b = NULL;

        //  Some CHILD_WeightedHeight tags have been left
        //  out to demonstrate the effects of the tag.

    page1 = IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_Orientation,   LAYOUT_ORIENT_VERT,
                LAYOUT_BevelStyle,    BVS_GROUP,
                LAYOUT_Label,         "Page One",
                LAYOUT_AddChild,      IIntuition->NewObject(NULL, "button.gadget", GA_Text, "Button One", TAG_DONE),
                CHILD_WeightedHeight, 0,
                LAYOUT_AddChild,      IIntuition->NewObject(NULL, "button.gadget", GA_Text, "Button Two", TAG_DONE),
                CHILD_WeightedHeight, 0,
            TAG_DONE);

    page2 = IIntuition->NewObject(NULL, "layout.gadget",
				LAYOUT_Orientation,   LAYOUT_ORIENT_VERT,
                LAYOUT_BevelStyle,  BVS_GROUP,
                LAYOUT_Label,       "Page Two",
                LAYOUT_AddChild,    IIntuition->NewObject(NULL, "button.gadget", GA_Text, "Button Three", TAG_DONE),
                LAYOUT_AddChild,    IIntuition->NewObject(NULL, "button.gadget", GA_Text, "Button Four", TAG_DONE),
            TAG_DONE);

    page3a = IIntuition->NewObject(NULL, "layout.gadget",
				 LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
                 LAYOUT_AddChild,   IIntuition->NewObject(NULL, "layout.gadget",
                     LAYOUT_AddChild,    IIntuition->NewObject(NULL, "button.gadget", GA_Text, "Button Five", TAG_DONE),
                     LAYOUT_AddChild,    IIntuition->NewObject(NULL, "button.gadget", GA_Text, "Button Six", TAG_DONE),
                 TAG_DONE),
                 CHILD_WeightedHeight, 0,
             TAG_DONE);

    page3b = IIntuition->NewObject(NULL, "layout.gadget",
				 LAYOUT_Orientation,   LAYOUT_ORIENT_VERT,
                 LAYOUT_AddChild, IIntuition->NewObject(NULL, "layout.gadget",
                     LAYOUT_AddChild,    IIntuition->NewObject(NULL, "button.gadget", GA_Text, "Button Seven", TAG_DONE),
                     LAYOUT_AddChild,    IIntuition->NewObject(NULL, "button.gadget", GA_Text, "Button Eight", TAG_DONE),
                 TAG_DONE),
                 CHILD_WeightedHeight, 0,
             TAG_DONE);

    page3 = OBJ(OBJ_CLICKTAB_2) = IIntuition->NewObject(NULL, "clicktab.gadget",
                GA_Text,             PageLabels_2,
                CLICKTAB_Current,    0,
                CLICKTAB_PageGroup,  IIntuition->NewObject(NULL, "page.gadget",
                    PAGE_Add,        page3a,
                    PAGE_Add,        page3b,
                TAG_DONE),
            TAG_DONE);

    OBJ(OBJ_CLICKTAB_1) = IIntuition->NewObject(NULL, "clicktab.gadget",
        GA_Text,            PageLabels_1,
        CLICKTAB_Current,   0,
        CLICKTAB_PageGroup, IIntuition->NewObject(NULL, "page.gadget",
            PAGE_Add,       page1,
            PAGE_Add,       page2,
            PAGE_Add,       page3,
        TAG_DONE),
    TAG_DONE);

    return IIntuition->NewObject(NULL, "window.class",
        WA_ScreenTitle,        "ReAction Example",
        WA_Title,              "ClickTab Example",
        WA_DragBar,            TRUE,
        WA_CloseGadget,        TRUE,
        WA_SizeGadget,         TRUE,
        WA_DepthGadget,        TRUE,
        WA_Activate,           TRUE,
        WINDOW_IconifyGadget,  TRUE,
        WINDOW_IconTitle,      "Iconified",
        WINDOW_AppPort,        AppPort,
        WINDOW_NewPrefsHook,   &newprefshook,
        WINDOW_Position,       WPOS_CENTERSCREEN,
        WINDOW_Layout,         IIntuition->NewObject(NULL, "layout.gadget",
			LAYOUT_Orientation,    LAYOUT_ORIENT_VERT,

            LAYOUT_AddChild,       OBJ(OBJ_CLICKTAB_1),

            LAYOUT_AddChild,       IIntuition->NewObject(NULL, "button.gadget", GA_Text, "_Quit", GA_ID, OBJ_QUIT, GA_RelVerify, TRUE, TAG_DONE),
            CHILD_WeightedHeight,  0,

        TAG_DONE),
    TAG_DONE);
}


int
main( int argc, char **argv )
{
    struct Window *window;

    if (AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_DONE))
    {
        win = make_window();
        if (window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN))
        {
            uint32
                sigmask     = 0,
                siggot      = 0,
                result      = 0;
            uint16
                code        = 0;
            BOOL
                done        = FALSE;

            IIntuition->GetAttr(WINDOW_SigMask, win, &sigmask);
            while (!done)
            {
                siggot = IExec->Wait(sigmask | SIGBREAKF_CTRL_C);
                if (siggot & SIGBREAKF_CTRL_C) done = TRUE;
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
                                    done=TRUE;
                                    break;
                            }
                            break;
                        case WMHI_ICONIFY:
                            if (IIntuition->IDoMethod(win, WM_ICONIFY)) window = NULL;
                            break;
                        case WMHI_UNICONIFY:
                            window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN);
                            break;
                    }
                }
            }
        }

        IIntuition->DisposeObject(win);
        IExec->FreeSysObject(ASOT_PORT, AppPort);
    }
    
    return 0;
}
