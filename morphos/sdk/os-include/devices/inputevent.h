#ifndef DEVICES_INPUTEVENT_H
#define DEVICES_INPUTEVENT_H

/*
	input.device event definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef DEVICES_TIMER_H
# include <devices/timer.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif

#pragma pack(2)


#define IECLASS_NULL            0x00
#define IECLASS_RAWKEY          0x01
#define IECLASS_RAWMOUSE        0x02
#define IECLASS_EVENT           0x03
#define IECLASS_POINTERPOS      0x04

#define IECLASS_TIMER           0x06
#define IECLASS_GADGETDOWN      0x07
#define IECLASS_GADGETUP        0x08
#define IECLASS_REQUESTER       0x09
#define IECLASS_MENULIST        0x0A
#define IECLASS_CLOSEWINDOW     0x0B
#define IECLASS_SIZEWINDOW      0x0C
#define IECLASS_REFRESHWINDOW   0x0D
#define IECLASS_NEWPREFS        0x0E
#define IECLASS_DISKREMOVED     0x0F
#define IECLASS_DISKINSERTED    0x10
#define IECLASS_ACTIVEWINDOW    0x11
#define IECLASS_INACTIVEWINDOW  0x12
#define IECLASS_NEWPOINTERPOS   0x13
#define IECLASS_MENUHELP        0x14
#define IECLASS_CHANGEWINDOW    0x15
#ifndef IECLASS_NEWMOUSE
#define IECLASS_NEWMOUSE        0x16
#endif /* IECLASS_NEWMOUSE */
#define IECLASS_MAX             0x16


#define IESUBCLASS_COMPATIBLE   0x00
#define IESUBCLASS_PIXEL        0x01
#define IESUBCLASS_TABLET       0x02
#define IESUBCLASS_NEWTABLET    0x03
#define IESUBCLASS_TOUCHPAD     0x04

struct IEPointerPixel
{
	struct Screen *iepp_Screen;
	struct
	{
		WORD X;
		WORD Y;
	}              iepp_Position;
};

struct IEPointerTablet
{
	struct
	{
		UWORD X;
		UWORD Y;
	}            iept_Range;
	struct
	{
		UWORD X;
		UWORD Y;
	}            iept_Value;

	WORD         iept_Pressure;
};


struct IENewTablet
{
	struct Hook *ient_CallBack;

	UWORD ient_ScaledX, ient_ScaledY;
	UWORD ient_ScaledXFraction, ient_ScaledYFraction;

	ULONG ient_TabletX, ient_TabletY;

	ULONG ient_RangeX, ient_RangeY;

	struct TagItem *ient_TagList;
};


#define IECODE_UP_PREFIX        0x80
#define IECODE_KEY_CODE_FIRST   0x00
#define IECODE_KEY_CODE_LAST    0x77
#define IECODE_COMM_CODE_FIRST  0x78
#define IECODE_COMM_CODE_LAST   0x7F

#define IECODE_C0_FIRST         0x00
#define IECODE_C0_LAST          0x1F
#define IECODE_ASCII_FIRST      0x20
#define IECODE_ASCII_LAST       0x7E
#define IECODE_ASCII_DEL        0x7F
#define IECODE_C1_FIRST         0x80
#define IECODE_C1_LAST          0x9F
#define IECODE_LATIN1_FIRST     0xA0
#define IECODE_LATIN1_LAST      0xFF

#define IECODE_LBUTTON          0x68
#define IECODE_RBUTTON          0x69
#define IECODE_MBUTTON          0x6A
#define IECODE_NOBUTTON         0xFF

#define IECODE_NEWACTIVE        0x01
#define IECODE_NEWSIZE          0x02
#define IECODE_REFRESH          0x03

#define IECODE_REQSET           0x01
#define IECODE_REQCLEAR         0x00


#define IEQUALIFIER_LSHIFT          0x0001
#define IEQUALIFIER_RSHIFT          0x0002
#define IEQUALIFIER_CAPSLOCK        0x0004
#define IEQUALIFIER_CONTROL         0x0008
#define IEQUALIFIER_LALT            0x0010
#define IEQUALIFIER_RALT            0x0020
#define IEQUALIFIER_LCOMMAND        0x0040
#define IEQUALIFIER_RCOMMAND        0x0080
#define IEQUALIFIER_NUMERICPAD      0x0100
#define IEQUALIFIER_REPEAT          0x0200
#define IEQUALIFIER_INTERRUPT       0x0400
#define IEQUALIFIER_MULTIBROADCAST  0x0800
#define IEQUALIFIER_MIDBUTTON       0x1000
#define IEQUALIFIER_RBUTTON         0x2000
#define IEQUALIFIER_LEFTBUTTON      0x4000
#define IEQUALIFIER_RELATIVEMOUSE   0x8000

#define IEQUALIFIERB_LSHIFT         0
#define IEQUALIFIERB_RSHIFT         1
#define IEQUALIFIERB_CAPSLOCK       2
#define IEQUALIFIERB_CONTROL        3
#define IEQUALIFIERB_LALT           4
#define IEQUALIFIERB_RALT           5
#define IEQUALIFIERB_LCOMMAND       6
#define IEQUALIFIERB_RCOMMAND       7
#define IEQUALIFIERB_NUMERICPAD     8
#define IEQUALIFIERB_REPEAT         9
#define IEQUALIFIERB_INTERRUPT      10
#define IEQUALIFIERB_MULTIBROADCAST 11
#define IEQUALIFIERB_MIDBUTTON      12
#define IEQUALIFIERB_RBUTTON        13
#define IEQUALIFIERB_LEFTBUTTON     14
#define IEQUALIFIERB_RELATIVEMOUSE  15

/*
 * NewMouse events.
 */
#ifndef NM_WHEEL_UP
#define NM_WHEEL_UP      0x7a
#endif
#ifndef NM_WHEEL_DOWN
#define NM_WHEEL_DOWN    0x7b
#endif
#ifndef NM_WHEEL_LEFT
#define NM_WHEEL_LEFT    0x7c
#endif
#ifndef NM_WHEEL_RIGHT
#define NM_WHEEL_RIGHT   0x7d
#endif
#ifndef NM_BUTTON_FOURTH
#define NM_BUTTON_FOURTH 0x7e
#endif

struct InputEvent
{
	struct  InputEvent *ie_NextEvent;
	UBYTE               ie_Class;
	UBYTE               ie_SubClass;
	UWORD               ie_Code;
	UWORD               ie_Qualifier;

	union
	{
		struct
		{
			WORD  ie_x;
			WORD  ie_y;
		}    ie_xy;

		APTR ie_addr;


		struct
		{
			UBYTE ie_prev1DownCode;
			UBYTE ie_prev1DownQual;
			UBYTE ie_prev2DownCode;
			UBYTE ie_prev2DownQual;
		}    ie_dead;


	}                   ie_position;

	struct timeval      ie_TimeStamp;
};

#define ie_X              ie_position.ie_xy.ie_x
#define ie_Y              ie_position.ie_xy.ie_y
#define ie_EventAddress   ie_position.ie_addr
#define ie_Prev1DownCode  ie_position.ie_dead.ie_prev1DownCode
#define ie_Prev1DownQual  ie_position.ie_dead.ie_prev1DownQual
#define ie_Prev2DownCode  ie_position.ie_dead.ie_prev2DownCode
#define ie_Prev2DownQual  ie_position.ie_dead.ie_prev2DownQual

#pragma pack()

#endif /* DEVICES_INPUTEVENT_H */
