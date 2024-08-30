#ifndef MCC_HTMLVIEW
#define MCC_HTMLVIEW

#include <exec/types.h>

#define MUIC_HTMLview   "HTMLview.mcc"
#define HTMLviewObject  MUI_NewObject(MUIC_HTMLview

#define HTMLview_ID(x) (0xad003000 + x)

#define MUIM_HTMLview_ExtMessage          HTMLview_ID(1)		/* Private */
#define MUIM_HTMLview_GotoURL             HTMLview_ID(2)
#define MUIM_HTMLview_Period              HTMLview_ID(3)		/* Private */
#define MUIA_HTMLview_Title               HTMLview_ID(4)
#define MUIA_HTMLview_Contents            HTMLview_ID(5)
#define MUIA_HTMLview_CurrentURL          HTMLview_ID(7)
#define MUIM_HTMLview_LoadImages          HTMLview_ID(8)		/* Private */
#define MUIM_HTMLview_AddPart             HTMLview_ID(10)	/* Private */
#define MUIM_HTMLview_DrawImages          HTMLview_ID(11)	/* Private */
#define MUIA_HTMLview_LoadHook            HTMLview_ID(12)
#define MUIM_HTMLview_Abort               HTMLview_ID(13)
#define MUIM_HTMLview_VLink               HTMLview_ID(14)
#define MUIA_HTMLview_ClickedURL          HTMLview_ID(15)
#define MUIM_HTMLview_Parsed              HTMLview_ID(16)
#define MUIM_HTMLview_PrivateGotoURL      HTMLview_ID(18)	/* Private */
#define MUIM_HTMLview_AbortAll            HTMLview_ID(19)	/* Private */
#define MUIM_HTMLview_LookupFrame         HTMLview_ID(20)	/* Private */
#define MUIA_HTMLview_Target              HTMLview_ID(21)
#define MUIA_HTMLview_FrameName           HTMLview_ID(22)	/* Private */
#define MUIA_HTMLview_MarginWidth         HTMLview_ID(23)	/* Private */
#define MUIA_HTMLview_MarginHeight        HTMLview_ID(24)	/* Private */
#define MUIM_HTMLview_Reload              HTMLview_ID(25)
#define MUIM_HTMLview_StartParser         HTMLview_ID(26)	/* Private */
#define MUIM_HTMLview_HandleEvent         HTMLview_ID(27)	/* Private */
#define MUIM_HTMLview_RemoveChildren      HTMLview_ID(28)	/* Private */
#define MUIA_HTMLview_IPC                 HTMLview_ID(29)
#define MUIA_HTMLview_DiscreteInput       HTMLview_ID(30)
#define MUIM_HTMLview_Search              HTMLview_ID(31)
#define MUIA_HTMLview_IntuiTicks          HTMLview_ID(32)	/* Private */
#define MUIA_HTMLview_Prop_HDeltaFactor   HTMLview_ID(33)
#define MUIA_HTMLview_Prop_VDeltaFactor   HTMLview_ID(34)
#define MUIA_HTMLview_Scrollbars          HTMLview_ID(35)
#define MUIM_HTMLview_StartRefreshTimer   HTMLview_ID(36)	/* Private */
#define MUIM_HTMLview_Refresh             HTMLview_ID(38)	/* Private */
#define MUIM_HTMLview_GetContextInfo      HTMLview_ID(39)
#define MUIM_HTMLview_HitTest             HTMLview_ID(40)	/* Private */
#define MUIA_HTMLview_URL                 HTMLview_ID(41)
#define MUIA_HTMLview_Qualifier           HTMLview_ID(42)
#define MUIA_HTMLview_ImageLoadHook       HTMLview_ID(44)
#define MUIM_HTMLview_AnimTick            HTMLview_ID(45)	/* Private */
#define MUIM_HTMLview_AddSingleAnim       HTMLview_ID(48)	/* Private */
#define MUIA_HTMLview_ImagesInDecodeQueue HTMLview_ID(49)
#define MUIM_HTMLview_FlushImage          HTMLview_ID(50)
#define MUIA_HTMLview_SharedData          HTMLview_ID(51)	/* Private */
#define MUIM_HTMLview_ServerRequest       HTMLview_ID(52)	/* Private */
#define MUIA_HTMLview_PageID              HTMLview_ID(53)
#define MUIM_HTMLview_PauseAnims          HTMLview_ID(54)	/* Sort of private, called  */
#define MUIM_HTMLview_ContinueAnims       HTMLview_ID(55)	/* for MUIA_Window_Activate */
#define MUIM_HTMLview_Post                HTMLview_ID(56)	/* Private, or...? */
#define MUIA_HTMLview_InstanceData        HTMLview_ID(57)	/* Very very private ;-) */

#define MUIV_HTMLview_Scrollbars_Auto      0
#define MUIV_HTMLview_Scrollbars_Yes       1
#define MUIV_HTMLview_Scrollbars_No        2
#define MUIV_HTMLview_Scrollbars_HorizAuto 3

#define MUIA_ScrollGroup_HTMLview         0xad003100

/* Structures */

struct MUIP_HTMLview_FlushImage
{
	ULONG MethodID;
	STRPTR URL;
};

#define MUIV_HTMLview_FlushImage_All           0
#define MUIV_HTMLview_FlushImage_Displayed     1
#define MUIV_HTMLview_FlushImage_Nondisplayed  2

struct MUIP_HTMLview_GetContextInfo
{
	ULONG MethodID;
	LONG X, Y;
};

struct MUIR_HTMLview_GetContextInfo
{
	STRPTR URL, Target, Img, Frame, Background;
	Object *FrameObj;
	ULONG ImageWidth, ImageHeight, ImageSize, ImageOffsetX, ImageOffsetY;
	STRPTR ImageAltText;
};

struct MUIP_HTMLview_GotoURL
{
	ULONG MethodID;
	STRPTR URL, Target;
};

struct MUIP_HTMLview_AddPart
{
	ULONG MethodID;
	STRPTR File;
};

struct MUIP_HTMLview_VLink
{
	ULONG MethodID;
	STRPTR URL;
};

struct MUIP_HTMLview_Parsed
{
	ULONG MethodID;
	ULONG Parsed;
};

struct MUIP_HTMLview_Search
{
	ULONG MethodID;
#ifdef String
	STRPTR SearchString;
#else
	STRPTR String;
#endif
	ULONG Flags;
};

#define MUIF_HTMLview_Search_CaseSensitive (1 << 0)
#define MUIF_HTMLview_Search_DOSPattern    (1 << 1)
#define MUIF_HTMLview_Search_Backwards     (1 << 2)
#define MUIF_HTMLview_Search_FromTop       (1 << 3)
#define MUIF_HTMLview_Search_Next          (1 << 4)

struct HTMLview_LoadMsg
{
	LONG lm_Type;

	union
	{
		struct { STRPTR URL; ULONG Flags; } lm_Open;
		struct { STRPTR Buffer; LONG Size; } lm_Read;
		struct { STRPTR Buffer; LONG Size; } lm_Write;
#ifndef __SASC
		struct { ; } lm_Close;
#endif
	};

	ULONG lm_PageID;
	APTR lm_Userdata;
	Object *lm_App;

	ULONG PostLength;
	STRPTR EncodingType;
};

#define MUIF_HTMLview_LoadMsg_Reload      (1 << 0)
#define MUIF_HTMLview_LoadMsg_Document    (1 << 1)
#define MUIF_HTMLview_LoadMsg_Image       (1 << 2)
#define MUIF_HTMLview_LoadMsg_Post        (1 << 3)
#define MUIF_HTMLview_LoadMsg_Script      (1 << 4)
#define MUIF_HTMLview_LoadMsg_Stylesheet  (1 << 5)
#define MUIF_HTMLview_LoadMsg_MainObject  (1 << 6)

enum
{
	HTMLview_Open = 0,
	HTMLview_Read,
	HTMLview_Close,
	HTMLview_Write
};

#endif
