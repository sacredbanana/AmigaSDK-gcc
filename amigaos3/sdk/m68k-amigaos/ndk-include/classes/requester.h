#ifndef CLASSES_REQUESTER_H
#define CLASSES_REQUESTER_H
/*
**	$VER: requester.h 47.9 (16.11.2021)
**
**	requester.class definitions
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

/*****************************************************************************/

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif

/*****************************************************************************/

/* Attributes defined by the requester.gadget class
 */
#define REQ_Dummy				(REACTION_Dummy + 0x45000)
#define REQS_Dummy				(REQ_Dummy + 0x100)
#define REQI_Dummy				(REQ_Dummy + 0x200)
#define REQP_Dummy				(REQ_Dummy + 0x300)

#define	REQ_Type				(REQ_Dummy+1)
	/* (ULONG) Type of requester. See definitions below.
			(default: REQTYPE_INFO) (OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQ_TitleText			(REQ_Dummy+2)
	/* (STRPTR) Title text of the requester (default: None)
				(OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQ_BodyText			(REQ_Dummy+3)
	/* (STRPTR) Body text of the requester (default: None)
				(OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQ_GadgetText			(REQ_Dummy+4)
	/* (STRPTR) Gadget text(s) for the requester
			(default: " _Ok | _Cancel ") (OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQ_ReturnCode			(REQ_Dummy+5)
	/* (ULONG) Last return code of the requester (default: 0)
				(OM_GET) */

#define	REQ_TabSize				(REQ_Dummy+6) /* NOT IMPLEMENTED YET */
	/* (ULONG) Tab size to use when formatting the bodytext (default: 8)
				(OM_NEW, OM_SET, RM_OPENREQ) */

#define REQ_Image			(REQ_Dummy+7)
	/* (struct Image *) alternative requester image or one of
				constants below.  (V47) */

#define REQ_VarArgs			(REQ_Dummy+8)
	/* (APTR) Varargs data array to supply data for RawDoFmt() when
	format specifiers are to be used in REQ_BodyText text string.
	(V47) */

#define REQ_EvenButtons			(REQ_Dummy+9) // OS4ONLY

#define REQ_WrapBorder			(REQ_Dummy+10) // OS4ONLY

#define REQ_TimeOutSecs			(REQ_Dummy+11) // OS4ONLY

#define REQ_IDCMP_Ptr			(REQ_Dummy+12) // OS4ONLY

#define REQ_Inactive			(REQ_Dummy+13) // OS4ONLY

#define REQ_CharSet			(REQ_Dummy+14) // OS4ONLY

#define REQ_StayOnTop			(REQ_Dummy+15) // OS4ONLY

#define REQ_ForceFocus			(REQ_Dummy+16) // OS4ONLY

/* Default requester images. V47 */
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

#define REQI_Minimum 			(REQI_Dummy+1)
	/* (LONG) Minimum allowed value (default: MININT) (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQI_Maximum 			(REQI_Dummy+2)
	/* (LONG) Maximum allowed value (default: MAXINT) (OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQI_Invisible			(REQI_Dummy+3) /* NOT IMPLEMENTED YET */
	/* (BOOL) Integer input will be echoed with '.' and not what the user
			actually types (default: FALSE) (OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQI_Number				(REQI_Dummy+4)
	/* (LONG) Number to show in gadget (default: 0)
			(OM_NEW, OM_SET, OM_GET, RM_OPENREQ) */

#define	REQI_Arrows				(REQI_Dummy+5)
	/* (BOOL) Show arrows to the right of the integer gadget (default: FALSE)
			(OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQI_MaxChars			(REQI_Dummy+6)
	/* (UWORD) Maximum number of characters for the number (including negative
			sign). (default: 10) (OM_NEW, OM_SET, RM_OPENREQ) */

#define REQI_MinText			(REQI_Dummy+7) // OS4ONLY

#define REQI_MaxText			(REQI_Dummy+8) // OS4ONLY

#define REQI_Mark			(REQI_Dummy+9) // OS4ONLY

#define REQI_ReturnEnds			(REQI_Dummy+10) // OS4ONLY

/*********************************
* string request type attributes *
*********************************/

#define	REQS_AllowEmpty 		(REQS_Dummy+1)
	/* (BOOL) Allow empty string to be accepted. (default: FALSE)
			(OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQS_Invisible			(REQI_Invisible) /* NOT IMPLEMENTED YET */
	/* (BOOL) String input will be echoed with '.' and not what the user
			actually types (default: FALSE) (OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQS_Buffer				(REQS_Dummy+2)
	/* (STRPTR) Buffer used in the string gadget. MUST be provided.
			(OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQS_ShowDefault		(REQS_Dummy+3)
	/* (BOOL) Show content of REQS_Buffer in string gadget. (default: TRUE)
			(OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQS_MaxChars			(REQS_Dummy+4)
	/* (ULONG) Maximum number of characters in string gadget. Must not be
			larger than size of REQS_Buffer - 1. (default: 127)
			(OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQS_ChooserArray		(REQS_Dummy+5)
	/* (STRPTR *) An array of strings that will be added to a chooser gadget
			to the right of the string gadget.
			(OM_NEW, OM_SET, RM_OPENREQ) */

#define	REQS_ChooserActive		(REQS_Dummy+6)
	/* (ULONG) The current active entry among the strings passed in
			using REQS_ChooserOptions.  (default: 0)
			(OM_NEW, OM_SET, OM_GET, RM_OPENREQ) */

#define REQS_Mark			(REQS_Dummy+7) // OS4ONLY

#define REQS_ReturnEnds			(REQS_Dummy+8) // OS4ONLY

/**********************************
* progress window type attributes *
**********************************/

#define REQP_Total				(REQP_Dummy+1)
	/* (ULONG) Total number of levels for the progressbar. (default: 100)
			(OM_NEW, OM_SET, RM_OPENREQ) */
#define REQP_Current			(REQP_Dummy+2)
	/* (ULONG) The current level of the progressbar. (default: 0)
			(OM_NEW, OM_SET, RM_OPENREQ) */
#define REQP_AbortText			REQ_GadgetText
	/* (STRPTR) Text to be put into the gadget that will abort the progressbar.
			If not present, no gadget will be created.
			(OM_NEW, OM_SET, RM_OPENREQ) */
#define REQP_ProgressText		REQ_BodyText
	/* (STRPTR) Text to be shown over the progressbar.
			(OM_NEW, OM_SET, RM_OPENREQ) */
#define REQP_OpenInactive		(REQP_Dummy+3)
	/* (BOOL) Open window inactive if ta_Data is TRUE.
			(OM_NEW, RM_OPENREQ) */
#define REQP_NoText				(REQP_Dummy+4)
	/* (BOOL)  No text-gadget in progressbar if ti_Data is TRUE
			(OM_NEW, RM_OPENREQ) */
#define REQP_Dynamic			(REQP_Dummy+5)
	/* (BOOL)  TRUE if the pb should size automatically when
		a too long progresstext is set. Default is TRUE.
		(OM_NEW, OM_SET, RM_OPENREQ) */
#define REQP_CenterWindow		(REQP_Dummy+6)
	/* (struct Window *) The progressbar is centered over this window.
		(OM_NEW, OM_SET, RM_OPENREQ) */
#define REQP_LastPosition		(REQP_Dummy+7)
	/* (BOOL) Open progressbar on the same place the last was. Default is TRUE.
		(OM_NEW, OM_SET, RM_OPENREQ) */
#define REQP_Percent			(REQP_Dummy+8)
	/* (BOOL) Render numeric percentage display.
		(OM_NEW, RM_OPENREQ) */
#define REQP_Ticks				(REQP_Dummy+9)
	/* (WORD) If present, how many tick marks
		(OM_NEW, RM_OPENREQ) */
#define REQP_ShortTicks			(REQP_Dummy+10)
	/* (BOOL) Enable small intermediate tick marks.
		(OM_NEW, RM_OPENREQ) */

/*****************************************************************************/

/*
 * requester.class methods
 */
#define RM_OPENREQ		(0x650001L)

/* The RM_OPENREQ method should be called whenever you want to open
 * a requester.
 */

struct orRequest
{
	ULONG MethodID;				/* RM_OPENREQ */
	struct TagItem *or_Attrs;	/* List of tag attributes */
	struct Window *or_Window;	/* Reference window for requester. */
	struct Screen *or_Screen;	/* Reference screen for requester.
					Until V47, this was required if or_Window was not supplied */
};

/* The REQ_Type must be used to set what type of requester you
 * want to use. Here are the definitions:
 */
#define REQTYPE_INFO		0		/* Normal information/query requester like EasyRequest() */
#define REQTYPE_INTEGER		1		/* Get an integer from the user */
#define REQTYPE_STRING		2		/* Get a string from the user */
#define REQTYPE_PROGRESS	3		/* Progressbar window (NOT IMPLEMENTED YET) */

/* Useful macros */
#ifndef RequesterObject
#define OpenRequester(obj, win)	DoMethod(obj, RM_OPENREQ, NULL, win, NULL, TAG_DONE)
#define RequesterObject			NewObject(REQUESTER_GetClass(), NULL
#endif

#endif /* CLASSES_REQUESTER_H */
