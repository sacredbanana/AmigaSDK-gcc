#ifndef CLASSES_REQUESTER_H
#define CLASSES_REQUESTER_H

/*
	requester.class definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef REACTION_REACTION_H
# include <reaction/reaction.h>
#endif

#pragma pack(2)


/* Attributes defined by requester.gadget */

#define REQ_Dummy   (REACTION_Dummy + 0x45000)
#define REQS_Dummy  (REQ_Dummy + 0x100)
#define REQI_Dummy  (REQ_Dummy + 0x200)
#define REQP_Dummy  (REQ_Dummy + 0x300)

#define REQ_Type            (REQ_Dummy + 1)
#define REQ_TitleText       (REQ_Dummy + 2)
#define REQ_BodyText        (REQ_Dummy + 3)
#define REQ_GadgetText      (REQ_Dummy + 4)
#define REQ_ReturnCode      (REQ_Dummy + 5)
#define REQ_TabSize         (REQ_Dummy + 6)


/* Integer-request type attributes */

#define REQI_Minimum        (REQI_Dummy + 1)
#define REQI_Maximum        (REQI_Dummy + 2)
#define REQI_Invisible      (REQI_Dummy + 3)
#define REQI_Number         (REQI_Dummy + 4)
#define REQI_Arrows         (REQI_Dummy + 5)
#define REQI_MaxChars       (REQI_Dummy + 6)


/* String-request type attributes */

#define REQS_AllowEmpty     (REQS_Dummy + 1)
#define REQS_Invisible      (REQI_Invisible)
#define REQS_Buffer         (REQS_Dummy + 2)
#define REQS_ShowDefault    (REQS_Dummy + 3)
#define REQS_MaxChars       (REQS_Dummy + 4)
#define REQS_ChooserArray   (REQS_Dummy + 5)
#define REQS_ChooserActive  (REQS_Dummy + 6)


/* Progress-window type attributes */

#define REQP_Total          (REQP_Dummy + 1)
#define REQP_Current        (REQP_Dummy + 2)
#define REQP_AbortText      (REQ_GadgetText)
#define REQP_ProgressText   (REQ_BodyText)
#define REQP_OpenInactive   (REQP_Dummy + 3)
#define REQP_NoText         (REQP_Dummy + 4)
#define REQP_Dynamic        (REQP_Dummy + 5)
#define REQP_CenterWindow   (REQP_Dummy + 6)
#define REQP_LastPosition   (REQP_Dummy + 7)
#define REQP_Percent        (REQP_Dummy + 8)
#define REQP_Ticks          (REQP_Dummy + 9)
#define REQP_ShortTicks     (REQP_Dummy + 10)


/* requester.class methods */

#define RM_OPENREQ  (0x650001L)


struct orRequest
{
	ULONG            MethodID;
	struct TagItem  *or_Attrs;
	struct Window   *or_Window;
	struct Screen   *or_Screen;
};


/* REQ_Type definitions */

#define REQTYPE_INFO      0
#define REQTYPE_INTEGER   1
#define REQTYPE_STRING    2
#define REQTYPE_PROGRESS  3


/* Useful macros */

#ifndef RequesterObject
# define OpenRequester(obj, win)  DoMethod(obj, RM_OPENREQ, NULL, win, NULL, TAG_DONE)
# define RequesterObject          NewObject(REQUESTER_GetClass(), NULL
#endif


#pragma pack()

#endif /* CLASSES_REQUESTER_H */
