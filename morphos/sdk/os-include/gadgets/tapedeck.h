#ifndef GADGETS_TAPEDECK_H
#define GADGETS_TAPEDECK_H

/*
	tapedeck.gadget definitions (V45)

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#define TDECK_Dummy         (TAG_USER + 0x05000000)
#define TDECK_Mode          (TDECK_Dummy + 1)
#define TDECK_Paused        (TDECK_Dummy + 2)
#define TDECK_Tape          (TDECK_Dummy + 3)

#define TDECK_Frames        (TDECK_Dummy + 11)
#define TDECK_CurrentFrame  (TDECK_Dummy + 12)


/* TDECK_Mode values */

#define BUT_REWIND   0
#define BUT_PLAY     1
#define BUT_FORWARD  2
#define BUT_STOP     3
#define BUT_PAUSE    4
#define BUT_BEGIN    5
#define BUT_FRAME    6
#define BUT_END      7


#endif /* GADGETS_TAPEDECK_H */
