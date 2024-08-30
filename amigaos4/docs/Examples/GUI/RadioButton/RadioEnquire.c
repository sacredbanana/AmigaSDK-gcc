;/* RadioEnquire Example
gcc -o RadioEnquire RadioEnquire.c -lauto
quit
*/

#include <exec/exec.h>
#include <intuition/intuition.h>
#include <dos/dos.h>
#include <expansion/expansion.h>

#include <classes/window.h>

#include <gadgets/layout.h>
#include <gadgets/radiobutton.h>

#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/expansion.h>

#include <proto/window.h>
#include <proto/layout.h>
#include <proto/radiobutton.h>
#include <proto/button.h>

#include <reaction/reaction_macros.h>

#include <string.h>
#include <stdio.h>

Object *win = NULL;

struct MsgPort *AppPort = NULL;
struct Library *ExpansionBase = NULL;
struct ExpansionIFace *IExpansion = NULL;

char computer[30];
char Imemory[30];
char extensions[30];

enum
{
    OBJ_RADIO,
    OBJ_OUTPUT,
    OBJ_QUIT,
    OBJ_NUM
};

Object *Objects[OBJ_NUM];
#define OBJ(x) Objects[x]
#define GAD(x) (struct Gadget *)Objects[x]

STRPTR radio[] =
{
    " Computer"," Installed Memory"," Extensions",NULL
};

#define SPACE LAYOUT_AddChild, SpaceObject, End

void GetComputerInfo(struct Window *);
BOOL startup(void);
void shutdown(void);


Object *
make_window(void)
{
    return IIntuition->NewObject(NULL, "window.class",
        WA_ScreenTitle,        "ReAction Example",
        WA_Title,              "Radio",
        WA_DragBar,            TRUE,
        WA_CloseGadget,        TRUE,
        WA_SizeGadget,         TRUE,
        WA_DepthGadget,        TRUE,
        WA_Activate,           TRUE,
        WINDOW_IconifyGadget,  TRUE,
        WINDOW_IconTitle,      "Iconified",
        WINDOW_AppPort,        AppPort,
        WINDOW_Position,       WPOS_CENTERSCREEN,
        WINDOW_Layout,         IIntuition->NewObject(NULL, "layout.gadget",
            LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
            LAYOUT_SpaceOuter, TRUE,
            LAYOUT_AddChild,   IIntuition->NewObject(NULL, "layout.gadget",
                LAYOUT_AddChild,   IIntuition->NewObject(NULL, "layout.gadget",
                    LAYOUT_Orientation, LAYOUT_ORIENT_VERT,
                    LAYOUT_SpaceOuter,  TRUE,
                    LAYOUT_BevelStyle,  BVS_GROUP,
                    LAYOUT_Label,       " System Info ",

                    LAYOUT_AddChild,    OBJ(OBJ_RADIO) = IIntuition->NewObject(NULL, "radiobutton.gadget",
                        GA_ID,          OBJ_RADIO,
                        GA_Text,        radio,
                        GA_RelVerify,   TRUE,
                    TAG_END),

                TAG_END),
            TAG_END),

            LAYOUT_AddChild,    OBJ(OBJ_OUTPUT) = IIntuition->NewObject(NULL, "button.gadget",
                GA_ID,          OBJ_OUTPUT,
                GA_ReadOnly,    TRUE,
            TAG_END),
            CHILD_WeightedHeight,   0,

            LAYOUT_AddChild,    IIntuition->NewObject(NULL, "button.gadget",
                GA_ID, OBJ_QUIT,
                GA_Text, "_Quit",
                GA_RelVerify, TRUE,
            TAG_END),
            CHILD_WeightedHeight,   0,

        TAG_END),
    TAG_END);
}


int main()
{
    struct Window *window = NULL;

	/* make sure our classes opened... */
	if (!IButton || !IRadioButton || !IWindow || !ILayout)
		return RETURN_FAIL;

    if (startup() == FALSE)
    {
        IDOS->Printf("Failed to open a library\n");
        shutdown();
        return(10);
    }

    if (AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_END))
    {
        win = make_window();
        if (window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN))
        {
            uint32 sigmask = 0;
            uint32 result  = 0;
            uint16 code    = 0;
            BOOL done      = FALSE;

            GetComputerInfo(window);
            IIntuition->GetAttr(WINDOW_SigMask, win, &sigmask);
            while (!done)
            {
                uint32 siggot = IExec->Wait(sigmask | SIGBREAKF_CTRL_C);
                if (siggot & SIGBREAKF_CTRL_C) done = TRUE;
                while ((result = IIntuition->IDoMethod(win, WM_HANDLEINPUT, &code)) != WMHI_LASTMSG)
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
                                case OBJ_RADIO:
                                    switch(code)
                                    {
                                        case 0:
                                            IIntuition->SetGadgetAttrs( GAD(OBJ_OUTPUT), window, NULL,
                                                GA_Text, computer, TAG_END);
                                            break;
                                        case 1:
                                            IIntuition->SetGadgetAttrs( GAD(OBJ_OUTPUT), window, NULL,
                                                GA_Text, Imemory, TAG_END);
                                            break;
                                        case 2:
                                            IIntuition->SetGadgetAttrs( GAD(OBJ_OUTPUT), window, NULL,
                                                GA_Text, extensions, TAG_END);
                                            break;
                                    }
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
    shutdown();
}


void GetComputerInfo(struct Window *window)
{
    CONST_STRPTR machine;
    CONST_STRPTR extras;
    uint32 InstalledMem;

    IExpansion->GetMachineInfoTags(GMIT_MachineString, &machine,
                                   GMIT_MemorySize, &InstalledMem,
                                   GMIT_Extensions, &extras,
                                        TAG_END);
    strlcpy(computer, machine, sizeof(computer));
    strlcpy(extensions, extras, sizeof(extensions));
    snprintf(Imemory, sizeof(Imemory), "%d", InstalledMem);

    IIntuition->SetGadgetAttrs( GAD(OBJ_OUTPUT), window, NULL,
                                GA_Text, computer, TAG_END);
}


BOOL startup(void)
{
    BOOL retval = FALSE;

    ExpansionBase = IExec->OpenLibrary("expansion.library", 50);
    IExpansion = (struct ExpansionIFace *) IExec->GetInterface(ExpansionBase, "main", 1, NULL);
    if (IExpansion != NULL)
    {
        retval = TRUE;
    }

    return(retval);
}


void shutdown(void)
{
    IExec->DropInterface( (struct Interface *) IExpansion );
    IExec->CloseLibrary( ExpansionBase );
}
