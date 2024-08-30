#ifndef SCINTILLA_MCC
#define SCINTILLA_MCC TRUE

#ifdef __cplusplus
extern "C" {
#endif

#include <Scintilla/Scintilla.h>

#define SCI_NORM 0
#define SCI_SHIFT SCMOD_SHIFT
#define SCI_CTRL SCMOD_CTRL
#define SCI_ALT SCMOD_ALT
#define SCI_CSHIFT (SCI_CTRL | SCI_SHIFT)
#define SCI_ASHIFT (SCI_ALT | SCI_SHIFT)

/*** MUI Defines ***/

#define MUIC_Scintilla	  "Scintilla.mcc"

#define ScintillaObject MUI_NewObject(MUIC_Scintilla

#ifndef SCINTILLA_PRIV

#define MUISERIALNR_NICHOLAI 0xfecc
#define TAGBASE_NICHOLAI (TAG_USER | ( MUISERIALNR_NICHOLAI << 16))
#define TAGBASE_SCINTILLA (TAGBASE_NICHOLAI | 0xa000)

#define MUIA_Scintilla_dummy (TAGBASE_SCINTILLA)

#define MUIA_Scintilla_ActiveEditor (MUIA_Scintilla_dummy + 1) /* [.SG]  BOOL */
#define MUIA_Scintilla_Notify (MUIA_Scintilla_dummy + 3) /* [..G]  BOOL */
#define MUIM_Scintilla_AutoComplete (MUIA_Scintilla_dummy + 4)
#define MUIM_Scintilla_CallTip (MUIA_Scintilla_dummy + 5)
#define MUIM_Scintilla_AutoDoc (MUIA_Scintilla_dummy + 6)
#define MUIM_Scintilla_Include (MUIA_Scintilla_dummy + 7)
#define MUIM_Scintilla_Definition (MUIA_Scintilla_dummy + 8)
#define MUIM_Scintilla_BindWithProjectIndex (MUIA_Scintilla_dummy + 35)
#define MUIM_Scintilla_ContextMenuAdd (MUIA_Scintilla_dummy + 36)
#define MUIA_Scintilla_LexerChanged (MUIA_Scintilla_dummy + 10) /* [..G]  BOOL */
#define MUIA_Scintilla_ClipUnit (MUIA_Scintilla_dummy + 32) /* [.SG]  ULONG */
#define MUIM_Scintilla_RexxCommand (MUIA_Scintilla_dummy + 33)
#define MUIA_Scintilla_ClipStripANSI (MUIA_Scintilla_dummy + 34) /* [.SG]  BOOL */

#define SCIA_ActiveEditor MUIA_Scintilla_ActiveEditor
#define SCIA_Notify MUIA_Scintilla_Notify
#define SCIM_AutoComplete MUIM_Scintilla_AutoComplete
#define SCIM_CallTip MUIM_Scintilla_CallTip
#define SCIM_AutoDoc MUIM_Scintilla_AutoDoc
#define SCIM_Include MUIM_Scintilla_Include
#define SCIM_Definition MUIM_Scintilla_Definition
#define SCIM_BindWithProjectIndex MUIM_Scintilla_BindWithProjectIndex
#define SCIA_LexerChanged MUIA_Scintilla_LexerChanged
#define SCIA_ClipUnit MUIA_Scintilla_ClipUnit
#define SCIM_RexxCommand MUIM_Scintilla_RexxCommand
#define SCIM_ContextMenuAdd MUIM_Scintilla_ContextMenuAdd
	

struct MUIP_Scintilla_Command
{
	ULONG MethodID;
	LONG iMessage;
	LONG wParam;
	LONG lParam;
};

struct MUIP_Scintilla_RexxCommand
{
	ULONG MethodID;
	struct RexxMsg *rxmsg;
	ULONG *args;
	STRPTR *resultptr;
};

struct MUIP_Scintilla_CallTip
{
	ULONG MethodID;
	ULONG mousepointer;
};

struct MUIP_Scintilla_AutoComplete
{
	ULONG MethodID;
	ULONG autopopup;
};

struct MUIP_Scintilla_BindWithProjectIndex
{ 
	ULONG MethodID;
	APTR  ProjectIndex;
}; 

struct MUIP_Scintilla_RefreshProjectIndex
{
	ULONG MethodID;
};

struct MUIP_Scintilla_ContextMenuAdd
{
	ULONG MethodID;
	APTR ContextMenu;
	ULONG x;
	ULONG y;
};

#endif

#ifdef __cplusplus
}
#endif

#endif /* SCINTILLA_MCC */
