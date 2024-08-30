#ifndef INTUITION_INTUIMESSAGECLASS_H
#define INTUITION_INTUIMESSAGECLASS_H

/*
	intuition gadget class definitions (V51)

	Copyright © 2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

/*
** Introduced in intuition.library 51. All attributes are *G*. Pointers valid
** until the message is replied.
** Every struct IntuiMessage * can be treated as an Object *
*/

#define IMSGA_Dummy             (TAG_USER + 0x60000)
#define IMSGA_Class             (IMSGA_Dummy + 1) /* ULONG */
#define IMSGA_Code              (IMSGA_Dummy + 3) /* ULONG */
#define IMSGA_Qualifier         (IMSGA_Dummy + 4) /* ULONG */
#define IMSGA_IAddress          (IMSGA_Dummy + 5) /* ULONG */
#define IMSGA_MouseX            (IMSGA_Dummy + 6) /* LONG */
#define IMSGA_MouseY            (IMSGA_Dummy + 7) /* LONG */
#define IMSGA_Seconds           (IMSGA_Dummy + 8) /* ULONG */
#define IMSGA_Micros            (IMSGA_Dummy + 9) /* ULONG */
#define IMSGA_IDCMPWindow       (IMSGA_Dummy + 10) /* struct Window * */
#define IMSGA_RawMouseX         (IMSGA_Dummy + 11) /* LONG, raw, unaccelerated delta */
#define IMSGA_RawMouseY         (IMSGA_Dummy + 12) /* LONG */
#define IMSGA_UCS4              (IMSGA_Dummy + 13) /* ULONG, UCS4 */


#define IMSGM_NewCopy           0x600
/* Allocates a new copy of the IntuiMessage in question. You may use the
** object after the original object has been replied. Delete the copy with
** the DisposeObject() call. Returns Object * */

#endif /* INTUITION_INTUIMESSAGECLASS_H */
