#ifndef LAMP_MCC_H
#define LAMP_MCC_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#define MUIC_Lamp	"Lamp.mcc"
#define LampObject	MUI_NewObject(MUIC_Lamp

#define MUIA_Lamp_Type      0x85b90001 // ISG, ULONG
#define MUIA_Lamp_Color     0x85b90002 // ISG, ULONG *
#define MUIA_Lamp_ColorType 0x85b90003 // **G, ULONG
#define MUIA_Lamp_Red       0x85b90004 // ISG, ULONG
#define MUIA_Lamp_Green     0x85b90005 // ISG, ULONG
#define MUIA_Lamp_Blue      0x85b90006 // ISG, ULONG
#define MUIA_Lamp_PenSpec   0x85b90007 // ISG, struct MUI_PenSpec*

#define MUIM_Lamp_SetRGB    0x85b90008
struct MUIP_Lamp_SetRGB { ULONG mid; ULONG red; ULONG green; ULONG blue; };

#define MUIV_Lamp_Type_Tiny          0
#define MUIV_Lamp_Type_Small         1
#define MUIV_Lamp_Type_Medium        2
#define MUIV_Lamp_Type_Big           3
#define MUIV_Lamp_Type_Huge          4
#define MUIV_Lamp_Type_Mammoth       5
#define MUIV_Lamp_Type_Gigantic      6

#define MUIV_Lamp_Type_Size(px)      ((px<5) ? 0 : (px-5))

#define MUIV_Lamp_ColorType_UserDefined 0
#define MUIV_Lamp_ColorType_Color       1
#define MUIV_Lamp_ColorType_PenSpec     2

#define MUIV_Lamp_Color_Off            0
#define MUIV_Lamp_Color_Ok             1
#define MUIV_Lamp_Color_Warning        2
#define MUIV_Lamp_Color_Error          3
#define MUIV_Lamp_Color_FatalError     4
#define MUIV_Lamp_Color_Processing     5
#define MUIV_Lamp_Color_LookingUp      6
#define MUIV_Lamp_Color_Connecting     7
#define MUIV_Lamp_Color_SendingData    8
#define MUIV_Lamp_Color_ReceivingData  9
#define MUIV_Lamp_Color_LoadingData    10
#define MUIV_Lamp_Color_SavingData     11

#endif /* LAMP_MCC_H */
