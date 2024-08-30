#ifndef CLASSES_REQUESTER_H
#define CLASSES_REQUESTER_H
/*
**  $VER: requester.h 54.16 (22.08.2022)
**
**  requester.class definitions
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**      All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

/*****************************************************************************/

#ifndef   REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/*****************************************************************************/

/* Attributes defined by the requester.gadget class */
#define REQ_Dummy       (REACTION_Dummy + 0x45000)
#define REQS_Dummy      (REQ_Dummy + 0x100)
#define REQI_Dummy      (REQ_Dummy + 0x200)
#define REQP_Dummy      (REQ_Dummy + 0x300)

#define REQ_Type        (REQ_Dummy+1)
    /* (ULONG) Type of requester. See definitions below.
       (default: REQTYPE_INFO) (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQ_TitleText   (REQ_Dummy+2)
    /* (UBYTE *) Title text of the requester (default: None)
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQ_BodyText    (REQ_Dummy+3)
    /* (UBYTE *) Body text of the requester (default: None)
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQ_GadgetText  (REQ_Dummy+4)
    /* (UBYTE *) Gadget text(s) for the requester
       (default: " _Ok | _Cancel ") (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQ_ReturnCode  (REQ_Dummy+5)
    /* (ULONG) Last return code of the requester (default: 0)
       (OM_GET) */

#define REQ_TabSize     (REQ_Dummy+6) /* NOT IMPLEMENTED YET */
    /* (ULONG) Tab size to use when formatting the bodytext (default: 8)
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQ_Image       (REQ_Dummy+7)
    /* (struct Image *) alternative requester image or one of
       constants below.  (V50) */

#define REQ_VarArgs     (REQ_Dummy+8)
    /* (APTR) Varargs data array to supply data for RawDoFmt() when
       format specifiers are to be used in REQ_BodyText text string.
       (V50) */

#define REQ_EvenButtons (REQ_Dummy+9)
    /* (BOOL) If TRUE, the requester buttons will be evenly sized
       (default: FALSE) (OM_NEW, OM_SET, RM_OPENREQ) (V50) */

#define REQ_WrapBorder  (REQ_Dummy+10)
    /* (WORD) Wordwrap bodytext after 'n' chars. Defaults to 72. (V50) */

#define REQ_TimeOutSecs (REQ_Dummy+11)
    /* (ULONG) Requester timeout seconds. Defaults to 0 (no timeout).
       (OM_NEW, OM_SET, RM_OPENREQ) (V51.5) */

#define REQ_IDCMP_Ptr   (REQ_Dummy+12)
    /* (ULONG *) Pointer to an ULONG with IDCMP flags that specify which
       IDCMP flags should terminate the requester with result -1.
       In this case the ULONG will contain the IDCMP flag that
       caused the termination, otherwise it will contain 0.
       Caution: Currently only IDCMP_DISKINSERTED is supported.
       Defaults to NULL which means no extra IDCMP flags shall
       be monitored.
       (OM_NEW, OM_SET, RM_OPENREQ) (V51.5) */

#define REQ_Inactive    (REQ_Dummy+13)
    /* (BOOL) If TRUE, the requester window will not be activated.
       You should e.g. set this value to TRUE when your requester has
       keyboard shortcuts and may appear when the user didnt expect
       it, otherwise the user can accidently select an option of the
       requester when he is currently typing something.
       (default: FALSE) (OM_NEW, OM_SET, RM_OPENREQ) (V51.8) */

#define REQ_CharSet     (REQ_Dummy+14)
    /* (ULONG) Character set for the requester's text and gadgets.
       Defaults to 0, meaning no character set is required.
       (OM_NEW, OM_SET, OM_GET, RM_OPENREQ) (V51.11) */

#define REQ_StayOnTop   (REQ_Dummy+15)
    /* (BOOL) Stop the requester from being depth arranged and lost
       in a window stack. (OM_SET, RM_OPENREQ) (V53.16) */
       
#define REQ_ForceFocus  (REQ_Dummy+16)
    /* (BOOL) Force the requester window to hold focus and to stop
       the requester being lost in the window stack. */
       
/* Default requester images. V50 */
enum
{
    REQIMAGE_DEFAULT,
    REQIMAGE_INFO,
    REQIMAGE_WARNING,
    REQIMAGE_ERROR,
    REQIMAGE_QUESTION,
    REQIMAGE_INSERTDISK
};

/**********************************
* integer request type attributes *
**********************************/

#define REQI_Minimum    (REQI_Dummy+1)
    /* (LONG) Minimum allowed value (default: MININT) (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQI_Maximum    (REQI_Dummy+2)
    /* (LONG) Maximum allowed value (default: MAXINT)
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQI_Invisible  (REQI_Dummy+3) /* NOT IMPLEMENTED YET */
    /* (BOOL) Integer input will be echoed with '.' and not what the user
       actually types (default: FALSE) (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQI_Number     (REQI_Dummy+4)
    /* (LONG) Number to show in gadget (default: 0)
       (OM_NEW, OM_SET, OM_GET, RM_OPENREQ) */

#define REQI_Arrows     (REQI_Dummy+5)
    /* (BOOL) Show arrows to the right of the integer gadget (default: FALSE)
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQI_MaxChars   (REQI_Dummy+6)
    /* (UWORD) Maximum number of characters for the number (including negative
       sign). (default: 10) (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQI_MinText    (REQI_Dummy+7)
#define REQI_MaxText    (REQI_Dummy+8)
    /* (STRPTR) Allows to localize the "Min: ", "Max: " labels (IS). V50 */

#define REQI_Mark       (REQI_Dummy+9)
    /* (BOOL) The number in the integer gadget should be marked ready
       for editing. (default: FALSE) (OM_NEW) */

#define REQI_ReturnEnds (REQI_Dummy+10 )
    /* (BOOL) When the user presses Return or Enter to confirm the number,
       this now completes the requester. (default: FALSE) (OM_NEW) */

/*********************************
* string request type attributes *
*********************************/

#define REQS_AllowEmpty    (REQS_Dummy+1)
    /* (BOOL) Allow empty string to be accepted. (default: FALSE)
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQS_Invisible     (REQI_Invisible) /* NOT IMPLEMENTED YET */
    /* (BOOL) String input will be echoed with '.' and not what the user
       actually types (default: FALSE) (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQS_Buffer        (REQS_Dummy+2)
    /* (UBYTE *) Buffer used in the string gadget. MUST be provided.
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQS_ShowDefault   (REQS_Dummy+3)
    /* (BOOL) Show content of REQS_Buffer in string gadget. (default: TRUE)
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQS_MaxChars      (REQS_Dummy+4)
    /* (ULONG) Maximum number of characters in string gadget. Must not be
       larger than size of REQS_Buffer - 1. (default: 127)
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQS_ChooserArray  (REQS_Dummy+5)
    /* (UBYTE **) An array of strings that will be added to a chooser gadget
       to the right of the string gadget.
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQS_ChooserActive (REQS_Dummy+6)
    /* (ULONG) The current active entry among the strings passed in
       using REQS_ChooserOptions.  (default: 0)
       (OM_NEW, OM_SET, OM_GET, RM_OPENREQ) */

#define REQS_Mark          (REQS_Dummy+7)
    /* (BOOL) the text in the string gadget should be marked ready
       for editing. (default: FALSE)
       (OM_NEW) */

#define REQS_ReturnEnds    (REQS_Dummy+8)
    /* (BOOL) When the user presses Return or Enter to confirm the string,
       this now completes the requester. (default: FALSE) (OM_NEW) */

/**********************************
* progress window type attributes *
**********************************/

#define REQP_Total         (REQP_Dummy+1)
    /* (ULONG) Total number of levels for the progressbar. (default: 100)
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQP_Current       (REQP_Dummy+2)
    /* (ULONG) The current level of the progressbar. (default: 0)
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQP_AbortText     REQ_GadgetText
    /* (UBYTE *) Text to be put into the gadget that will abort the progressbar.
       If not present, no gadget will be created.
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQP_ProgressText  REQ_BodyText
    /* (UBYTE *) Text to be shown over the progressbar.
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQP_OpenInactive  (REQP_Dummy+3)
    /* (BOOL) Open window inactive if ta_Data is TRUE.
       (OM_NEW, RM_OPENREQ) */

#define REQP_NoText        (REQP_Dummy+4)
    /* (BOOL)  No text-gadget in progressbar if ti_Data is TRUE
       (OM_NEW, RM_OPENREQ) */

#define REQP_Dynamic       (REQP_Dummy+5)
    /* (BOOL)  TRUE if the pb should size automatically when
       a too long progresstext is set. Default is TRUE.
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQP_CenterWindow  (REQP_Dummy+6)
    /* (struct Window *) The progressbar is centered over this window.
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQP_LastPosition  (REQP_Dummy+7)
    /* (BOOL) Open progressbar on the same place the last was. Default is TRUE.
       (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQP_Percent       (REQP_Dummy+8)
    /* (BOOL) Render numeric percentage display.
       (OM_NEW, RM_OPENREQ) */

#define REQP_Ticks         (REQP_Dummy+9)
    /* (WORD) If present, how many tick marks
       (OM_NEW, RM_OPENREQ) */

#define REQP_ShortTicks    (REQP_Dummy+10)
    /* (BOOL) Enable small intermediate tick marks.
       (OM_NEW, RM_OPENREQ) */

/*****************************************************************************/

/*
 * requester.class methods
 */
#define RM_OPENREQ         (0x650001L)

/* The RM_OPENREQ method should be called whenever you want to open
 * a requester.
 */

struct orRequest
{
    ULONG           MethodID;  /* RM_OPENREQ */
    struct TagItem *or_Attrs;  /* List of tag attributes */
    struct Window  *or_Window; /* Reference window for requester. */
    struct Screen  *or_Screen; /* Reference screen for requester.
                                * REQUIRED if or_Window is
                                * not supplied
                                */
};

/* The REQ_Type must be used to set what type of requester you
 * want to use. Here are the definitions:
 */
#define REQTYPE_INFO     0 /* Normal information/query requester like
                            * EasyRequest()
                            */
#define REQTYPE_INTEGER  1 /* Get an integer from the user */
#define REQTYPE_STRING   2 /* Get a string from the user */
#define REQTYPE_PROGRESS 3 /* Progressbar window (NOT IMPLEMENTED YET) */

/* Useful macros */
#ifndef RequesterObject
#if defined (__amigaos4__) && !defined(__USE_INLINE__)
   #define OpenRequester(obj, win) IIntuition->IDoMethod(obj, RM_OPENREQ, NULL, win, NULL, TAG_DONE)
   #define RequesterObject         IIntuition->NewObject(IRequester->REQUESTER_GetClass(), NULL
#else
   #if defined (__amigaos4__)
      #define OpenRequester(obj, win) IDoMethod(obj, RM_OPENREQ, NULL, win, NULL, TAG_DONE)
   #else
      #define OpenRequester(obj, win)  DoMethod(obj, RM_OPENREQ, NULL, win, NULL, TAG_DONE)
   #endif
   #define RequesterObject  NewObject(REQUESTER_GetClass(), NULL
#endif
#endif

/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* CLASSES_REQUESTER_H */
