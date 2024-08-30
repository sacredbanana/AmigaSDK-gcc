#ifndef INTUITION_INTUITIONBASE_H
#define INTUITION_INTUITIONBASE_H

/*
	intuition.library include

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef INTUITION_INTUITION_H
# include <intuition/intuition.h>
#endif

#ifndef EXEC_INTERRUPTS_H
# include <exec/interrupts.h>
#endif

#pragma pack(2)


#define DMODECOUNT  0x0002
#define HIRESPICK   0x0000
#define LOWRESPICK  0x0001

#define EVENTMAX  10

#define RESCOUNT         2
#define HIRESGADGET      0
#define LOWRESGADGET     1

#define GADGETCOUNT      8
#define UPFRONTGADGET    0
#define DOWNBACKGADGET   1
#define SIZEGADGET       2
#define CLOSEGADGET      3
#define DRAGGADGET       4
#define SUPFRONTGADGET   5
#define SDOWNBACKGADGET  6
#define SDRAGGADGET      7


struct IntuitionBase
{
	struct Library  LibNode;

	struct View     ViewLord;

	struct Window  *ActiveWindow;
	struct Screen  *ActiveScreen;

	struct Screen  *FirstScreen;

	ULONG           Flags;
	WORD            MouseY, MouseX;

	ULONG           Seconds;
	ULONG           Micros;
};


#pragma pack()

#endif /* INTUITION_INTUITIONBASE_H */
