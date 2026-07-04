#ifndef BUSY_MCC_H
#define BUSY_MCC_H

/* Busy.mcc include
** Copyright © 2017 MorphOS Development Team
*/

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

#define MUIC_Busy   "Busy.mcc"
#define BusyObject  MUI_NewObject(MUIC_Busy

#define BusyBar	BusyObject, MUIA_Busy_Speed, MUIV_Busy_Speed_User, End

/* methods */
#define MUIM_Busy_Move 0x80020001
struct MUIP_Busy_Move { ULONG MethodID; };

/* attributes */
#define MUIA_Busy_Speed      0x80020049
#define MUIA_Busy_ShowHideIH 0x800200a9

/* special values */
#define MUIV_Busy_Speed_Off  0
#define MUIV_Busy_Speed_User (-1)

#endif /* BUSY_MCC_H */
