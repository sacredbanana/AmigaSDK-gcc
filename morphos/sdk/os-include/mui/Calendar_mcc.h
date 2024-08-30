#ifndef CALENDAR_MCC_H
#define CALENDAR_MCC_H

/*
 *  Calendar.mcc
 *
 *  Copyright © 2016 Guido Mersmann <geit@geit.de>
 *  All rights reserved.
 *
 *  $Id: Calendar_mcc.h,v 1.5 2017/05/02 16:24:23 geit Exp $
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#pragma pack(2)

#define MUIC_Calendar  "Calendar.mcc"
#define CalendarObject MUI_NewObject(MUIC_Calendar

/* Attributes */

#define TAGBASE_Calendar                     ( (TAG_USER | (0xfde0 << 16) ) + 0x8200 )
#define MUIA_Calendar_Changed                (TAGBASE_Calendar + 0)
#define MUIA_Calendar_Day                    (TAGBASE_Calendar + 1)
#define MUIA_Calendar_Month                  (TAGBASE_Calendar + 2)
#define MUIA_Calendar_Year                   (TAGBASE_Calendar + 3)

#define MUIA_Calendar_ShowTitle              (TAGBASE_Calendar + 4)
#define MUIA_Calendar_ShowYear               (TAGBASE_Calendar + 5)
#define MUIA_Calendar_Mode                   (TAGBASE_Calendar + 6)
#define MUIA_Calendar_Compact                (TAGBASE_Calendar + 7)
#define MUIA_Calendar_PeekOver               (TAGBASE_Calendar + 8)

/* Values */

#define MUIV_Calendar_Mode_None      0  /* no user side interaction possible */
#define MUIV_Calendar_Mode_Days      1  /* day can be modified by user */
#define MUIV_Calendar_Mode_Full      2  /* year, month and day can be modified by user */
#define MUIV_Calendar_Mode_MonthYear 3  /* year and month can be changed by user */

/* Methods */

#define MUIM_Calendar_ReadSystemDate          (TAGBASE_Calendar + 0)
#define MUIM_Calendar_GetDaysInMonth          (TAGBASE_Calendar + 1)

struct MUIP_Calendar_ReadSystemDate    { IPTR MethodID; };
struct MUIP_Calendar_GetDaysInMonth    { IPTR MethodID; IPTR Month; IPTR Year; };


#pragma pack()

#endif /* CALENDAR_MCC_H */
