#ifndef URLTEXT_MCC_H
#define URLTEXT_MCC_H

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

#ifdef USE_HYPERLINK_MCC

#ifndef HYPERLINK_MCC_H
#include <mui/Hyperlink_mcc.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#define MUIC_Urltext	"Hyperlink.mcc"
#define UrltextObject	MUI_NewObject(MUIC_Urltext
#define URLTEXT_MCC_FALLBACK(_x, _y) _x

#else

#define MUIC_Urltext	"Urltext.mcc"
#define UrltextObject	MUI_NewObject(MUIC_Urltext
#define URLTEXT_MCC_FALLBACK(_x, _y) _y

#ifndef USE_OBSOLETE_URLTEXT_MCC
#error Urltext.mcc is now obsolete
#endif

#endif

#define MUIA_Urltext_Url          URLTEXT_MCC_FALLBACK(MUIA_Hyperlink_URI,0xFEC900D0)
#define MUIA_Urltext_Text         URLTEXT_MCC_FALLBACK(MUIA_Text_Contents,0xFEC900D1)
#define MUIA_Urltext_SetMax       URLTEXT_MCC_FALLBACK(MUIA_Text_SetMax,0xFEC900D7)
#define MUIA_Urltext_Active       URLTEXT_MCC_FALLBACK(TAG_IGNORE,0xFEC900D2)
#define MUIA_Urltext_Visited      URLTEXT_MCC_FALLBACK(TAG_IGNORE,0xFEC900D3)
#define MUIA_Urltext_Underline    URLTEXT_MCC_FALLBACK(TAG_IGNORE,0xFEC900D4)
#define MUIA_Urltext_FallBack     URLTEXT_MCC_FALLBACK(TAG_IGNORE,0xFEC900D5)
#define MUIA_Urltext_DoVisitedPen URLTEXT_MCC_FALLBACK(TAG_IGNORE,0xFEC900D6)
#define MUIA_Urltext_DoOpenURL    URLTEXT_MCC_FALLBACK(TAG_IGNORE,0xFEC900D8)
#define MUIA_Urltext_NoMenu         URLTEXT_MCC_FALLBACK(TAG_IGNORE,0xFEC900D9)
#define MUIA_Urltext_NoOpenURLPrefs URLTEXT_MCC_FALLBACK(TAG_IGNORE,0xFEC900DC

#define MUIM_Urltext_OpenURL URLTEXT_MCC_FALLBACK(MUIM_Hyperlink_Follow,0xFEC900C9)
struct MUIP_Urltext_OpenURL { ULONG MethodID; ULONG Flags; };
#define MUIM_Urltext_Copy URLTEXT_MCC_FALLBACK(MUIM_Hyperlink_Copy,0xFEC900CA)
struct MUIP_Urltext_Copy { ULONG MethodID; ULONG ClipboardUnit; };

#endif /* URLTEXT_MCC_H */
