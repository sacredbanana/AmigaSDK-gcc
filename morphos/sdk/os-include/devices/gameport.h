#ifndef DEVICES_GAMEPORT_H
#define DEVICES_GAMEPORT_H

/*
	gameport.device include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_IO_H
# include <exec/io.h>
#endif

#pragma pack(2)


#define GPD_READEVENT   (CMD_NONSTD + 0)
#define GPD_ASKCTYPE    (CMD_NONSTD + 1)
#define GPD_SETCTYPE    (CMD_NONSTD + 2)
#define GPD_ASKTRIGGER  (CMD_NONSTD + 3)
#define GPD_SETTRIGGER  (CMD_NONSTD + 4)


#define GPTB_DOWNKEYS  0
#define GPTF_DOWNKEYS  (1<<GPTB_DOWNKEYS)
#define GPTB_UPKEYS    1
#define GPTF_UPKEYS    (1<<GPTB_UPKEYS)


struct GamePortTrigger
{
	UWORD gpt_Keys;
	UWORD gpt_Timeout;
	UWORD gpt_XDelta;
	UWORD gpt_YDelta;
};


#define GPCT_ALLOCATED     -1
#define GPCT_NOCONTROLLER   0

#define GPCT_MOUSE          1
#define GPCT_RELJOYSTICK    2
#define GPCT_ABSJOYSTICK    3


#define GPDERR_SETCTYPE  1


#pragma pack()

#endif /* DEVICES_GAMEPORT_H */
