#ifndef DEVICES_KEYBOARD_H
#define DEVICES_KEYBOARD_H

/*
	keyboard.device include

	Copyright � 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_IO_H
# include <exec/io.h>
#endif


#define KBD_READEVENT         (CMD_NONSTD + 0)
#define KBD_READMATRIX        (CMD_NONSTD + 1)
#define KBD_ADDRESETHANDLER   (CMD_NONSTD + 2)
#define KBD_REMRESETHANDLER   (CMD_NONSTD + 3)
#define KBD_RESETHANDLERDONE  (CMD_NONSTD + 4)


#endif /* DEVICES_KEYBOARD_H */
