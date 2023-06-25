;/* ReAction example of Opaqueness (and slider gadget) by Alex Carmona
gcc -o OpaquenessExample OpaquenessExample.c -Wall -Werror -Wextra -lauto
quit
*/

#define ALL_REACTION_CLASSES
#include <reaction/reaction.h>
#include <reaction/reaction_macros.h>
#include <intuition/intuition.h>
#include <intuition/gui.h>
#include <intuition/icclass.h>
#include <proto/intuition.h>
#include <proto/exec.h>
#include <proto/dos.h>

Object *win;
struct MsgPort *AppPort;

enum
{
    OBJ_INTEGER_1,
    OBJ_SLIDER_1,
    OBJ_INTEGER_2,
    OBJ_SLIDER_2,
    OBJ_QUIT,
    OBJ_NUM
};

Object *Objects[OBJ_NUM];
#define OBJ(x) Objects[x]
#define GAD(x) (struct Gadget *)Objects[x]

/* These structs are used to link the slider gadget and integer gadget together */
/* so that changing the value of one gadget updates the value of its counterpart */

struct TagItem slider_to_int[] = { {SLIDER_Level, INTEGER_Number}, {TAG_END, 0} };
struct TagItem int_to_slider[] = { {INTEGER_Number, SLIDER_Level}, {TAG_END, 0} };


Object *
make_window(void)
{
    return WindowObject,
        WA_ScreenTitle,         "ReAction Example",
        WA_Title,               "Opaqueness Example",
        WA_DragBar,             TRUE,
        WA_CloseGadget,         TRUE,
        WA_SizeGadget,          TRUE,
        WA_DepthGadget,         TRUE,
        WA_Activate,            TRUE,
        WA_Width,               200,
        WA_Opaqueness,          255,    /* Initial opaqueness on opening (0..255) */
        WA_OverrideOpaqueness,  TRUE,   /* Override global settings? (TRUE|FALSE) */
        WA_FadeTime,            500000, /* Duration of transition in microseconds */
        WINDOW_IconifyGadget,   TRUE,
        WINDOW_IconTitle,       "Iconified",
        WINDOW_AppPort,         AppPort,
        WINDOW_Position,        WPOS_CENTERSCREEN,
        WINDOW_Layout,          VLayoutObject,
            LAYOUT_SpaceOuter,      TRUE,

            LAYOUT_AddChild,    OBJ(OBJ_INTEGER_1) = IntegerObject,
                GA_ID,              OBJ_INTEGER_1,
                GA_RelVerify,       TRUE,
                GA_TabCycle,        TRUE,
                INTEGER_MaxChars,   3,
                INTEGER_Minimum,    10,
                INTEGER_Maximum,    100,
                INTEGER_Number,     50,
                INTEGER_SkipVal,    10,
            End, // Integer
            Label(" Fade Time (1/100s) "),

            LAYOUT_AddChild,    OBJ(OBJ_SLIDER_1) = SliderObject,
                GA_ID,              OBJ_SLIDER_1,
                GA_RelVerify,       TRUE,
                SLIDER_Min,         10,
                SLIDER_Max,         100,
                SLIDER_Level,       50,
                SLIDER_KnobDelta,   10,
                SLIDER_Orientation, SLIDER_HORIZONTAL,
                SLIDER_Ticks,       11,
                SLIDER_ShortTicks,  TRUE,
                ICA_TARGET,         OBJ(OBJ_INTEGER_1), /* link to integer gadget */
                ICA_MAP,            slider_to_int,      /* map of linked tags */
            End, // Slider

            LAYOUT_AddChild,    OBJ(OBJ_INTEGER_2) = IntegerObject,
                GA_ID,              OBJ_INTEGER_2,
                GA_RelVerify,       TRUE,
                GA_TabCycle,        TRUE,
                INTEGER_MaxChars,   3,
                INTEGER_Minimum,    55,
                INTEGER_Maximum,    255,
                INTEGER_Number,     255,
                INTEGER_SkipVal,    10,
            End, // Integer
            Label(" Opaqueness "),

            LAYOUT_AddChild,    OBJ(OBJ_SLIDER_2) = SliderObject,
                GA_ID,              OBJ_SLIDER_2,
                GA_RelVerify,       TRUE,
                SLIDER_Min,         55,
                SLIDER_Max,         255,
                SLIDER_Level,       255,
                SLIDER_KnobDelta,   10,
                SLIDER_Orientation, SLIDER_HORIZONTAL,
                SLIDER_Ticks,       21,
                SLIDER_ShortTicks,  TRUE,
                ICA_TARGET,         OBJ(OBJ_INTEGER_2), /* link to integer gadget */
                ICA_MAP,            slider_to_int,      /* map of linked tags */
            End, // Slider

            LAYOUT_AddChild,        Button("_Quit",OBJ_QUIT),
            CHILD_WeightedHeight,   0,

        End,  // VLayout
    End;  // WindowObject
} // make_window


int main()
{
    struct  Window      *window;
    struct  DrawInfo    *Dri = NULL;

    BOOL    canfade     = FALSE;
    uint32  specialfx   = 0;
    uint32  fade_time   = 50;
    uint32  opaqueness  = 255;
    uint32  delay       = 0;

    AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_END);

    /* make sure our classes opened... */

    if (!ButtonBase || !IntegerBase || !WindowBase || !LayoutBase || !IntuitionBase)
        return (30);

    if ( AppPort != NULL )
    {
        win = make_window();
        if (( window = RA_OpenWindow(win) ))
        {
            uint32  sigmask = 0,
                    siggot  = 0,
                    result  = 0;
            uint16  code    = 0;
            BOOL    done    = FALSE;

            /* These attributes have to be set after opening the window */
            /* because the sliders were created after the integers */

            IIntuition->SetGadgetAttrs(GAD(OBJ_INTEGER_1),window, NULL,
                ICA_TARGET,         OBJ(OBJ_SLIDER_1),
                ICA_MAP,            int_to_slider,
                TAG_DONE);

            IIntuition->SetGadgetAttrs(GAD(OBJ_INTEGER_2),window, NULL,
                ICA_TARGET,         OBJ(OBJ_SLIDER_2),
                ICA_MAP,            int_to_slider,
                TAG_DONE);

            IIntuition->GetAttr(WINDOW_SigMask, win, &sigmask);

            /* Check that compositing is enabled in GUI prefs */

            if (( Dri = IIntuition->GetScreenDrawInfo(window->WScreen) ))
            {
                IIntuition->GetGUIAttrs(NULL, Dri, GUIA_SpecialEffects, &specialfx, TAG_END);
                canfade = (BOOL)specialfx;
				IIntuition->FreeScreenDrawInfo(window->WScreen, Dri);
            }

            while (!done)
            {
                siggot = IExec->Wait(sigmask | SIGBREAKF_CTRL_C);
                if (siggot & SIGBREAKF_CTRL_C)
                    done = TRUE;

                while ((result = RA_HandleInput(win, &code)))
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

                                case OBJ_INTEGER_1:
                                case OBJ_SLIDER_1:
                                    if (canfade) /* we only make changes if compositing is enabled */
                                    {
                                        IIntuition->GetAttrs(GAD(OBJ_INTEGER_1), INTEGER_Number, &fade_time, TAG_DONE);
                                        IIntuition->SetAttrs( win, WA_FadeTime, fade_time * 10000, TAG_END );
                                    }
                                break;

                                case OBJ_INTEGER_2:
                                case OBJ_SLIDER_2:
                                    if (canfade) /* we only make changes if compositing is enabled */
                                    {
                                        IIntuition->GetAttrs(GAD(OBJ_INTEGER_2), INTEGER_Number, &opaqueness, TAG_DONE);
                                        IIntuition->SetAttrs( win, WA_Opaqueness, opaqueness, TAG_END );

                                        /* Calls to SetAttrs() return immediately so we add a delay to allow */
                                        /* the window to finish fading before the next call, in case the user */
                                        /* changes the opaqueness faster than the current fade_time setting. */

                                        delay = fade_time/2; // (1 tick = 2/100s)
                                        IDOS->Delay(delay);
                                    }
                                break;
                            }  // switch
                        break;

                        case WMHI_ICONIFY:
                            /* override user setting to (de)iconify instantly */
                            IIntuition->SetAttrs( win, WA_FadeTime, 0, TAG_END );
                            if (RA_Iconify(win)) window = NULL;
                        break;

                        case WMHI_UNICONIFY:
                            window = RA_OpenWindow(win);
                            /* restore previous fade_time set by user */
                            IIntuition->SetAttrs( win, WA_FadeTime, fade_time * 10000, TAG_END );
                        break;

                    } // switch
                } // while result
            } // while !done
        } // if window

        IIntuition->DisposeObject(win);
		IExec->FreeSysObject(ASOT_PORT, AppPort);

    } // if AppPort
    return (0);
} // main

