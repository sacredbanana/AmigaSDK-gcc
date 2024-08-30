;/* execute me to compile
gcc -o WheelGrad WheelGrad.c -lauto -gstabs -Wall
quit
*/

/*
COPYRIGHT: Unless otherwise noted, all files are Copyright (c) 1992-1999
Amiga, Inc.  All rights reserved.

DISCLAIMER: This software is provided "as is".  No representations or
warranties are made with respect to the accuracy, reliability, performance,
currentness, or operation of this software, and all use is at your own risk.
Neither Amiga nor the authors assume any responsibility or liability
whatsoever with respect to your use of this software.
*/

/* WheelGrad.c - simple example of colorwheel and gradient slider
 *
 * Puts up a colorwheel and gradient slider and changes the gradient slider
 * color based on where the colorwheel knob is moved.
 */

#include <exec/types.h>
#include <intuition/intuition.h>
#include <intuition/intuitionbase.h>
#include <intuition/screens.h>
#include <graphics/displayinfo.h>
#include <intuition/gadgetclass.h>
#include <gadgets/colorwheel.h>
#include <gadgets/gradientslider.h>

#define ALL_REACTION_CLASSES
#include <reaction/reaction.h>
#include <reaction/reaction_macros.h>

#include <proto/intuition.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <proto/graphics.h>
#include <proto/colorwheel.h>

#include <stdio.h>

enum
{
    GID_WHEEL,
    GID_LAST
};

/****************************************************************************/


#define MAXGRADPENS 4


/****************************************************************************/

struct Library              *ColorWheelBase;
struct ColorWheelIFace      *IColorWheel;
struct Library              *GradientSliderBase;
struct GradientSliderIFace  *IGradientSlider;


/****************************************************************************/


int main(VOID)
{
    Object               *mainobject;
    struct Screen        *screen;
    struct Window        *window;
    struct Gadget        *wheel;
    struct Gadget        *slider;
    struct ColorWheelRGB  rgb;
    struct ColorWheelHSB  hsb;
    ULONG                 colortable[3];
    WORD                  pens[16];
    WORD                  numPens;
    WORD                  i;

    ColorWheelBase     = IExec->OpenLibrary("gadgets/colorwheel.gadget",51);
    GradientSliderBase = IExec->OpenLibrary("gadgets/gradientslider.gadget",51);


    if (ColorWheelBase && GradientSliderBase)
    {
        IColorWheel = (struct ColorWheelIFace *)        IExec->GetInterface( ColorWheelBase, "main", 1, NULL );
        IGradientSlider = (struct GradientSliderIFace *)IExec->GetInterface( GradientSliderBase, "main", 1, NULL );

        if ((screen = IIntuition->LockPubScreen( NULL )))
        {
            /* get the RGB components of color 0 */
            IGraphics->GetRGB32(screen->ViewPort.ColorMap,0,1,colortable);
            rgb.cw_Red   = colortable[0];
            rgb.cw_Green = colortable[1];
            rgb.cw_Blue  = colortable[2];

            /* now convert the RGB values to HSB, and max out B component */
            IColorWheel->ConvertRGBToHSB(&rgb,&hsb);
            hsb.cw_Brightness = 0xffffffff;

            numPens = 0;
            while (numPens < MAXGRADPENS)
            {
                hsb.cw_Brightness = 0xffffffff - ((0xffffffff / MAXGRADPENS) * numPens);
                IColorWheel->ConvertHSBToRGB(&hsb,&rgb);

                pens[numPens] = IGraphics->ObtainPen(screen->ViewPort.ColorMap,-1,
                                 rgb.cw_Red,rgb.cw_Green,rgb.cw_Blue,PEN_EXCLUSIVE);

                if (pens[numPens] == -1)
                    break;

                numPens++;
            }
            pens[numPens] = ~0;

            if ((mainobject = WindowObject,
                    WA_CustomScreen, screen,
                    WA_IDCMP,        IDCMP_CLOSEWINDOW | IDCMP_MOUSEMOVE,
                    WA_SizeGadget,   TRUE,
                    WA_DragBar,      TRUE,
                    WA_CloseGadget,  TRUE,
                    WA_Activate,     TRUE,
                    WINDOW_ParentGroup, HGroupObject,
                        LAYOUT_SpaceOuter, TRUE,
                        LAYOUT_DeferLayout, TRUE,
                        LAYOUT_Inverted, TRUE,
                        LAYOUT_AddChild, slider = (struct Gadget *)GradientObject,
                            GRAD_PenArray, pens,
                            PGA_Freedom,   LORIENT_VERT,
                        SliderEnd,
                        LAYOUT_AddChild, wheel = (struct Gadget *)ColorWheelObject,
                            GA_ID,                GID_WHEEL,
                            GA_RelVerify,         TRUE,
                            WHEEL_Red,            colortable[0],
                            WHEEL_Green,          colortable[1],
                            WHEEL_Blue,           colortable[2],
                            WHEEL_Screen,         screen,
                            WHEEL_GradientSlider, slider,
                            GA_FollowMouse,       TRUE,
                            GA_Previous,          slider,
                        ColorWheelEnd,
                    EndGroup,
                EndWindow))
            {

                /* open the window */
                if ((window = (struct Window *)RA_OpenWindow( mainobject )))
                {
                    ULONG wait, signal;
                    ULONG result, done = FALSE;
                    UWORD code;

                    /* Obtain the window wait signal mask. */
                    IIntuition->GetAttr(WINDOW_SigMask, mainobject, &signal);

                    /* Input event loop */
                    while (!done)
                    {
                        wait = IExec->Wait(signal);

                        while( (result = RA_HandleInput(mainobject, &code) ) != WMHI_LASTMSG )
                        {
                            switch ( result & WMHI_CLASSMASK )
                            {
                                case WMHI_CLOSEWINDOW:
                                    done = TRUE;
                                    window = NULL;
                                    break;

                                case WMHI_GADGETUP:
                                    switch (result & WMHI_GADGETMASK)
                                    {

                                        case GID_WHEEL:
                                        {
                                            /* Change gradient slider color each time
                                             * colorwheel knob is moved.  This is one
                                             * method you can use.
                                             */

                                            /* Query the colorwheel */
                                            IIntuition->GetAttr(WHEEL_HSB, (Object*)wheel, (uint32*)&hsb);

                                            i = 0;
                                            while (i < numPens)
                                            {
                                                hsb.cw_Brightness = 0xffffffff - ((0xffffffff / numPens) * i);
                                                IColorWheel->ConvertHSBToRGB(&hsb,&rgb);

                                                IGraphics->SetRGB32(&screen->ViewPort,pens[i],rgb.cw_Red,rgb.cw_Green,rgb.cw_Blue);
                                                i++;
                                            }
                                            break;
                                        }
                                    }
                                    break;
                            }
                        }
                    }
                    /* Get rid of the gadgets */
                    //IIntuition->DisposeObject(wheel);
                    //IIntuition->DisposeObject(slider);
                    IIntuition->DisposeObject(mainobject);
                }

            }

            /* Always release the pens */
            while (numPens > 0)
            {
                numPens--;
                IGraphics->ReleasePen(screen->ViewPort.ColorMap,pens[numPens]);
            }

            IIntuition->UnlockPubScreen( NULL, screen );
        }

        IExec->DropInterface( (struct Interface *)IGradientSlider );
        IExec->CloseLibrary(GradientSliderBase);
        IExec->DropInterface( (struct Interface *)IColorWheel );
        IExec->CloseLibrary(ColorWheelBase);


    }
    else
        IDOS->Printf("Error opening a gadget\n");


    return 0;

}
