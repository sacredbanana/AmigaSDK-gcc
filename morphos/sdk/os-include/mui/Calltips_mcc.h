#ifndef __Calltips_MCC_H_
#define __Calltips_MCC_H_

#define MUISERIALNR_PTERMC 0xfecf

#define MUIC_Calltips  "Calltips.mcc"
#define CalltipsObject MUI_NewObject(MUIC_Calltips

#define TAGBASE_Calltips                     ((TAG_USER | (MUISERIALNR_PTERMC << 16)) + 4100)

#define MUIM_Calltips_SetRectangle (TAGBASE_Calltips + 0)
struct MUIP_Calltips_SetRectangle { ULONG id; LONG MinX; LONG MinY; LONG MaxX; LONG MaxY;};

#define MUIM_Calltips_ParentSetup   (TAGBASE_Calltips + 1)
#define MUIM_Calltips_ParentCleanup (TAGBASE_Calltips + 2)
#define MUIM_Calltips_ParentShow    (TAGBASE_Calltips + 3)
#define MUIM_Calltips_ParentHide    (TAGBASE_Calltips + 4)
#define MUIM_Calltips_ParentWindowArranged (TAGBASE_Calltips + 5)

/*
** struct Rect32 *, Coordinates of an area for which to show the window, relative to the window bounds
** of the caller's window. Can also be set via a method
*/
#define MUIA_Calltips_Rectangle  (TAGBASE_Calltips + 0)

/*
** Sets a layout policy to one of the predefine dones
*/
#define MUIA_Calltips_Layout (TAGBASE_Calltips + 1)

#define MUIV_Calltips_Layout_Exact          0

#if 0 // unimplemented!
/* Start at the right end of the rectangle, if no space, show below the rectangle */
#define MUIV_Calltips_Layout_RightThenBelow 1
/* Start below the rectangle, if no space then show above the rectangle */
#define MUIV_Calltips_Layout_BelowThenAbove 2
#endif

/*
** Object that wants to have a Calltips
*/
#define MUIA_Calltips_Source (TAGBASE_Calltips + 2)

/*
** If TRUE, the outer calltip group's _mleft will be substracted from the calltips rectangle
** Defaults to TRUE
*/
#define MUIA_Calltips_MarginLeft (TAGBASE_Calltips + 4)

/*
** If TRUE, the outer calltip group's _mtop will be substracted from the calltips rectangle
** Defaults to TRUE
*/
#define MUIA_Calltips_MarginTop (TAGBASE_Calltips + 5)


#endif

