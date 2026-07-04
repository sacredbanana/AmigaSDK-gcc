#ifndef HYPERLINK_MCC_H
#define HYPERLINK_MCC_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

#define MUIC_Hyperlink	"Hyperlink.mcc"
#define HyperlinkObject	MUI_NewObject(MUIC_Hyperlink

#define MUIA_Hyperlink_URI      0xfed10033 // STRPTR, ISG
#define MUIA_Hyperlink_HoverTip 0xfed10036 // STRPTR, **G

#define MUIA_Hyperlink_Text     MUIA_Text_Contents
#define MUIA_Hyperlink_SetMax   MUIA_Text_SetMax

#define MUIM_Hyperlink_Follow   0xfed10034
struct  MUIP_Hyperlink_Follow { ULONG MethodID; };

#define MUIM_Hyperlink_Copy     0xfed10035
struct  MUIP_Hyperlink_Copy   { ULONG MethodID; ULONG CliboardUnit; };

#define MUIM_Hyperlink_Encode   0xfed10037
struct  MUIP_Hyperlink_Encode { ULONG MethodID; CONST_STRPTR InputString; UBYTE *OutputBuffer; };

#define MUIM_Hyperlink_Decode   0xfed10038
struct  MUIP_Hyperlink_Decode { ULONG MethodID; CONST_STRPTR InputString; UBYTE *OutputBuffer; };

#define MUIV_Hyperlink_Encode_Count (NULL)

#endif /* HYPERLINK_MCC_H */
