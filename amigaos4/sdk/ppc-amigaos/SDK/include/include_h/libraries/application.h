#ifndef LIBRARIES_APPLICATION_H
#define LIBRARIES_APPLICATION_H

/*
**    $VER: application.h 54.16 (22.08.2022)
**
**    Structure and method definitions for application.library
**
**    Copyright (C) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved
*/

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif

#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

/******************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

/******************************************************************************/
/* *************************** application tags ***************************** */
/******************************************************************************/

typedef uint32 PrefsObject;


/**** iconType in struct ApplicationIconInfo ****/
enum enAppIconTypes
{
	APPICONT_None        = 0, // no icon ("invisible" application)
	APPICONT_ProgramIcon = 1, // the application's .info is used
	APPICONT_CustomIcon  = 2, // custom icon is used
	APPICONT_Docky       = 3  // application docky
};


/**** tags for RegisterApplication ****/
enum enRegisterApplicationTags
{
	REGAPP_UniqueApplication    = TAG_USER +  1, // BOOL (default: FALSE)
	REGAPP_LoadPrefs            = TAG_USER + 10, // BOOL (default: FALSE)
	REGAPP_SavePrefs            = TAG_USER + 11, // BOOL (default: FALSE)
	REGAPP_CustomPrefsFileName  = TAG_USER + 12, // STRPTR (sets automatically REGAPP_UsesPrefs to TRUE)
	REGAPP_ENVDir               = TAG_USER + 13, // STRPTR (default: NULL)
	REGAPP_CustomPrefsBaseName  = TAG_USER + 14, // STRPTR (sets automatically REGAPP_UsesPrefs to TRUE)
	REGAPP_WBStartup            = TAG_USER + 20, // struct WBStartup *
	REGAPP_FileLock             = TAG_USER + 21, // BPTR
	REGAPP_FileName             = TAG_USER + 22, // STRPTR
	REGAPP_URLIdentifier        = TAG_USER + 23, // STRPTR
	REGAPP_NoIcon               = TAG_USER + 30, // BOOL (default: FALSE)
	REGAPP_Hidden               = TAG_USER + 31, // BOOL (default: FALSE)
	REGAPP_AppIconInfo          = TAG_USER + 32, // struct ApplicationIconInfo *  (default: APPICONT_ProgramIcon)
	REGAPP_AppNotifications     = TAG_USER + 33, // BOOL (default: FALSE)
	REGAPP_BlankerNotifications = TAG_USER + 34, // BOOL (default: FALSE)
	REGAPP_IdenticalNameCounter = TAG_USER + 35, // BOOL (default: TRUE)
	REGAPP_AllowsBlanker        = TAG_USER + 40, // BOOL (default: TRUE)
	REGAPP_NeedsGameMode        = TAG_USER + 41, // BOOL (default: FALSE)
	
	REGAPP_HasPrefsWindow       = TAG_USER + 42, // BOOL (default: FALSE)
	REGAPP_HasIconifyFeature    = TAG_USER + 43, // BOOL (default: FALSE)
	REGAPP_CanCreateNewDocs     = TAG_USER + 44, // BOOL (default: FALSE)
	REGAPP_CanPrintDocs         = TAG_USER + 45, // BOOL (default: FALSE)

    REGAPP_Description          = TAG_USER + 50  // STRPTR (V53.2)
};

/**** tags for UnregisterApplication ****/
enum enUnregisterApplicationTags
{
	UNREGAPP_WaitForUnlock      =  TAG_USER + 1  // BOOL (default: TRUE)
};

/**** tags for FindApplication ****/
enum enFindApplicationTags
{
	FINDAPP_Name          =  TAG_USER + 1, // STRPTR
	FINDAPP_FileName      =  TAG_USER + 2, // STRPTR
	FINDAPP_AppIdentifier =  TAG_USER + 3  // STRPTR
};

/**** tags for SetApplicationAttrs & GetApplicationAttrs ****/
enum enApplicationAttrsTags
{
	APPATTR_Port                 =  TAG_USER +  1, // struct MsgPort * (get only)
	APPATTR_FileName             =  TAG_USER +  2, // STRPTR           (get only)
	APPATTR_Name                 =  TAG_USER +  3, // STRPTR           (get only)
	APPATTR_URLIdentifier        =  TAG_USER +  4, // STRPTR           (get only)
	APPATTR_AppIdentifier        =  TAG_USER +  5, // STRPTR           (get only)
	APPATTR_Hidden               =  TAG_USER +  6, // BOOL
	APPATTR_IconType             =  TAG_USER +  7, // struct ApplicationIconInfo *
	APPATTR_UniqueApplication    =  TAG_USER +  8, // BOOL             (get only)
	APPATTR_SavePrefs            =  TAG_USER +  9, // BOOL
	APPATTR_AppNotifications     =  TAG_USER + 10, // BOOL
	APPATTR_BlankerNotifications =  TAG_USER + 11, // BOOL
	APPATTR_MainPrefsDict        =  TAG_USER + 12, // PrefsObject *
	APPATTR_AllowsBlanker        =  TAG_USER + 13, // BOOL
	APPATTR_NeedsGameMode        =  TAG_USER + 14, // BOOL
	APPATTR_AppIdentifierCounter =  TAG_USER + 15, // BOOL             (get only)
	APPATTR_FlushPrefs           =  TAG_USER + 16, // NULL             (set only)
	APPATTR_LastUsedDocsArray    =  TAG_USER + 17, // PrefsObject *    (get only, a copied array is returned -> release afterwards!)
	APPATTR_ClearLastUsedDocs    =  TAG_USER + 18, // BOOL             (set only)
	
	APPATTR_HasPrefsWindow       =  TAG_USER + 19, // BOOL
	APPATTR_HasIconifyFeature    =  TAG_USER + 20, // BOOL
	APPATTR_CanCreateNewDocs     =  TAG_USER + 21, // BOOL
	APPATTR_CanPrintDocs         =  TAG_USER + 22, // BOOL
	
	APPATTR_AppOpenedDocument    =  TAG_USER + 50,  // STRPTR          (set only)

    APPATTR_Description          =  TAG_USER + 60  // STRPTR           (get only) (V53.2)
};

/**** tags for GetAppLibAttrs ****/
enum enAppLibAttrsTags
{
	APPLIBATTR_LastUsedAppsArray    = TAG_USER +  1, // PrefsObject *  (get only, a copied array is returned -> release afterwards!)
	APPLIBATTR_LastUsedAppsMaxCount = TAG_USER +  2, // uint32
	APPLIBATTR_ClearLastUsedApps    = TAG_USER +  3, // BOOL           (set only)
	APPLIBATTR_LastUsedDocsArray    = TAG_USER + 10, // PrefsObject *  (get only, a copied array is returned -> release afterwards!)
	APPLIBATTR_LastUsedDocsMaxCount = TAG_USER + 11, // uint32
	APPLIBATTR_ClearLastUsedDocs    = TAG_USER + 12, // BOOL           (set only)
	APPLIBATTR_BlankerIsAllowed     = TAG_USER + 50, // BOOL           (get only)
	APPLIBATTR_GameModeIsActive     = TAG_USER + 51  // BOOL           (get only)
};

/**** keys for last used applications/documents dictionary entries ****/
#define LUA_BASE_KEY          "LastUsedApplications"
#define LUA_OPENDATE_KEY      "openDate"
#define LUA_APPIDENTIFIER_KEY "appIdentifier"
#define LUA_APPNAME_KEY       "appName"
#define LUA_APPPATH_KEY       "appPath"

#define LUD_BASE_KEY          "LastUsedDocuments"
#define LUD_OPENDATE_KEY      "openDate"
#define LUD_DOCPATH_KEY       "docPath"
#define LUD_APPIDENTIFIER_KEY "appIdentifier"
#define LUD_APPPATH_KEY       "appPath"

/******************************************************************************/
/* ************************** application structs *************************** */
/******************************************************************************/

struct ApplicationIconInfo
{
	int32 iconType; // enum enAppIconType
	union
	{
		struct DiskObject *customIcon; // for APPICONT_CustomIcon
		struct Library *dockyBase;     // for APPICONT_Docky
		uint32 reserved[8];
	} info;
};

struct ApplicationNode
{
	struct MinNode node;
	uint32 appID;
	STRPTR name;
};


/******************************************************************************/
/* *********************** application message system *********************** */
/******************************************************************************/

enum enApplicationMsgType
{
	// --- app notifications
	APPLIBMT_AppRegister            =    1, // - (this message is always broadcast)
	APPLIBMT_AppUnregister          =    2, // - (this message is always broadcast)
	APPLIBMT_AppWantsChangeIconType =    3, // - (this message is always broadcast)
	APPLIBMT_AppDidChangeIconType   =    4, // - (this message is always broadcast)
	APPLIBMT_AppDidChangeHidden     =    5, // - (this message is always broadcast)
	APPLIBMT_LastAppDocChange       =    6, // - (this message is always broadcast)

	// --- messages usually sent to single applications
	APPLIBMT_Quit                   =  100, // -
	APPLIBMT_ForceQuit              =  101, // - Don't ask to save changed documents
	APPLIBMT_Hide                   =  102, // -
	APPLIBMT_Unhide                 =  103, // -
	APPLIBMT_ToFront                =  104, // -
	APPLIBMT_Unique                 =  105, // -

	APPLIBMT_OpenPrefs              =  200, // -
	APPLIBMT_ReloadPrefs            =  201, // -

	APPLIBMT_NewBlankDoc            =  300, // -
	APPLIBMT_OpenDoc                =  301, // struct AppLibOpenPrintDocMsg *
	APPLIBMT_PrintDoc               =  302, // struct AppLibOpenPrintDocMsg *

	// --- blanker notifications
	APPLIBMT_BlankerAllow           =  400, // - (this message is always broadcast)
	APPLIBMT_BlankerDisallow        =  401, // - (this message is always broadcast)
	APPLIBMT_BlankerBlank           =  402, // - (this message is always broadcast)
	APPLIBMT_BlankerMonitorOff      =  403, // - (this message is always broadcast)
	APPLIBMT_BlankerUnBlank         =  404, // - (this message is always broadcast)

	APPLIBMT_ConfirmClose           =  470, // -

	// --- messages always sent to all applications
	APPLIBMT_GameModeEntered        =  500, // - (this message is always broadcast)
	APPLIBMT_GameModeLeft           =  501, // - (this message is always broadcast)

    // --- custom notification
	APPLIBMT_CustomMsg              = 9999  // - Allows applications to send/receive customs msgs
};

struct ApplicationMsg
{
	struct Message msg;
	uint32 senderAppID; // the application (or 0 [no app]) which sent this message
	uint32 type;        // enum enAppLibMessageType
};

struct ApplicationOpenPrintDocMsg
{
	struct ApplicationMsg almsg;
	STRPTR fileName;
};

struct ApplicationCustomMsg
{
	struct ApplicationMsg almsg;
	STRPTR customMsg;
};

enum enNotifyTags
{
    APPNOTIFY_Title          = TAG_USER + 1,  // CONST_STRPTR
    APPNOTIFY_Update         = TAG_USER + 2,  // BOOL (default: FALSE)
    APPNOTIFY_Pri            = TAG_USER + 3,  // uint32 (default: 0)
    APPNOTIFY_PubScreenName  = TAG_USER + 4,  // CONST_STRPTR
    APPNOTIFY_ImageFile      = TAG_USER + 5,  // CONST_STRPTR
    APPNOTIFY_BackMsg        = TAG_USER + 6,  // CONST_STRPTR
    APPNOTIFY_CloseOnDC      = TAG_USER + 7,  // BOOL
    APPNOTIFY_Text           = TAG_USER + 8,  // CONST_STRPTR
    APPNOTIFY_ImageVertAlign = TAG_USER + 9,  // uint32 (default: 0=TOP)
    APPNOTIFY_LogOnly        = TAG_USER + 10, // BOOL (default: FALSE)
    APPNOTIFY_SoundFile      = TAG_USER + 11, // CONST_STRPTR (FileName)
    APPNOTIFY_ConfirmClose   = TAG_USER + 12, // BOOL (default: FALSE)
    APPNOTIFY_IconFile       = TAG_USER + 13  // CONST_STRPTR (FileName)
};

/**** return codes for Notify ****/
#define APPNOTIFY_OK_MSGQUEUED                 0
#define APPNOTIFY_OK_APPREGISTERED             1
#define APPNOTIFY_ERROR_OUTOFMEM              10
#define APPNOTIFY_ERROR_TOOMANYMESSAGESQUEUED 20
#define APPNOTIFY_ERROR_APPALREADYREGISTERED  30
#define APPNOTIFY_ERROR_NOAPPNAME             40
#define APPNOTIFY_ERROR_APPNOTALLOWED         50
#define APPNOTIFY_ERROR_APPNOTREGISTERED      60
#define APPNOTIFY_ERROR_GAMEMODEACTIVE        70
#define APPNOTIFY_ERROR_TAGS                 100
#define APPNOTIFY_ERROR_TIMEOUT              110
#define APPNOTIFY_ERROR_SERVERNOTRUNNING     120
#define APPNOTIFY_ERROR_GENERIC              300

/**** return strings for Notify from the ARexx interface ****/
#define APPNOTIFY_OK_MSGQUEUED_STR                "OK, MSG QUEUED"
#define APPNOTIFY_OK_APPREGISTERED_STR            "OK, APP REGISTERED"
#define APPNOTIFY_OK_APPUNREGISTERED_STR          "OK, APP UNREGISTERED"
#define APPNOTIFY_ERROR_OUTOFMEM_STR              "ERROR: OUT OF MEMORY"
#define APPNOTIFY_ERROR_TOOMANYMESSAGESQUEUED_STR "ERROR: TOO MANY MESSAGES QUEUED"
#define APPNOTIFY_ERROR_APPALREADYREGISTERED_STR  "ERROR: APP ALREADY REGISTERED"
#define APPNOTIFY_ERROR_NOAPPNAME_STR             "ERROR: NO APP NAME"
#define APPNOTIFY_ERROR_APPNOTALLOWED_STR         "ERROR: APP NOT ALLOWED"
#define APPNOTIFY_ERROR_APPNOTREGISTERED_STR      "ERROR: APP NOT REGISTERED"
#define APPNOTIFY_ERROR_GAMEMODEACTIVE_STR        "ERROR: GAME MODE ACTIVE"
#define APPNOTIFY_ERROR_TAGS_STR                  "ERROR: WRONG TAGS"
#define APPNOTIFY_ERROR_TIMEOUT_STR               "ERROR: TIMEOUT"
#define APPNOTIFY_ERROR_SERVERNOTRUNNING_STR      "ERROR: SERVER NOT RUNNING"
#define APPNOTIFY_ERROR_GENERIC_STR               "ERROR: GENERIC ERROR"


/******************************************************************************/
/* *************************** PrefsObjects system ************************** */
/******************************************************************************/

#define TAGBUFFER_SIZE 150

enum enALPOEncodings
{
	ALPOENC_ISO8859 = 0, // currently only partly supported (for encoding only)
	ALPOENC_UTF8,
	//ALPOENC_UTF16  // currently not supported
	// further encodings are not planned
};

struct ALPOGetProcInfo
{
	int32 (*getChProc)(struct ALPOGetProcInfo *pi);
	int32 (*unGetChProc)(int32 c, struct ALPOGetProcInfo *pi);
	APTR basePtr;
	APTR handlePtr;
	STRPTR key_otag; // must have a size of at least TAGBUFFER_SIZE

	uint32 encoding;  // enum enALPOEncodings
};

struct ALPOPutProcInfo
{
	void (*putChProc)(int32 c, struct ALPOPutProcInfo *pi);
	APTR basePtr;
	APTR handlePtr;
	int32 tabDepth;  // set to 0

	uint32 encoding; // enum enALPOEncodings
};

struct ALPOString
{
	STRPTR string;
	uint32 length;
};

// --------------

enum enALPOType
{
	ALPOT_None       = 0,
	ALPOT_String     = 1,
	ALPOT_Number     = 2,
	ALPOT_Date       = 3,
	ALPOT_Binary     = 4,
	ALPOT_Array      = 5,
	ALPOT_Dictionary = 6
};

enum enALPOErrorFlags
{
	ALPOEF_INTERNAL_ERROR     = 0x00000001,
	ALPOEF_UNKNOWN_METHOD     = 0x00000002,
	ALPOEF_MISSING_OBJECT     = 0x00000004,
	ALPOEF_IMPOSSIBLE_OP      = 0x00000008,
	ALPOEF_WRONG_OBJECTTYPE   = 0x00000010,
	ALPOEF_ILLEGAL_PARAMETER  = 0x00000020,
	ALPOEF_MEMORY             = 0x00000040,
	ALPOEF_NOTFOUND           = 0x00000080,
	ALPOEF_DUPLICATE          = 0x00000100,
	ALPOEF_DESERIALIZATION    = 0x00000200,
	ALPOEF_READTAG            = 0x00000400,
	ALPOEF_READDATA           = 0x00000800,
	ALPOEF_WRONG_OTAG         = 0x00001000,
	ALPOEF_WRONG_CTAG         = 0x00002000,
	ALPOEF_WRONG_SERDATA      = 0x00004000,
	ALPOEF_FILEERROR          = 0x00008000,
	ALPOEF_XMLERROR           = 0x00010000,
	ALPOEF_WRONG_OBJECT       = 0x00020000
};

/*
** *** ID Scheme ********************************************************
**                 A B                                                   *
**     1         : n b ALPO_Alloc                                        *
**  1000 -  1999 : n c Alloc Object Methods without Param                *
**  2000         : n b ALPO_Release                                      *
**  2001         : n b ALPO_Copy                                         *
**  2002         : n b ALPO_Retain                                       *
**  2003 -  9999 : n b Other Base Methods without Param                  *
** 10000 - 19999 : n c Object Methods without Param (clear, free, ...)   *
** 20000         : p b ALPO_Identifiy                                    *
** 20001         : p b ALPO_Serialize                                    *
** 20002         : p b ALPO_Deserialize                                  *
** 20003         : p b ALPO_GetRetainCount                               *
** 20004 - 29999 : p b Other Base Methods with Param                     *
** 30000 - 39999 : p c Alloc Object Methods with Param                   *
** 40000 - 49999 : p c Object Methods with Param                         *
**                                                                       *
** A) n: no param               B) b: base methods                       *
**    p: with param                c: custom object methods              *
**                                                                       *
** **********************************************************************
*/


enum enALPOBaseMethods
{
	ALPO_Alloc                 = TAG_USER +     1, // -
	ALPO_AllocWithString       = TAG_USER +     2, // STRPTR
	ALPO_Release               = TAG_USER +  2000, // -
	ALPO_Copy                  = TAG_USER +  2001, // -
	ALPO_Retain                = TAG_USER +  2002, // -
	
	ALPO_Identify              = TAG_USER + 20000, // uint32 *
	ALPO_Serialize             = TAG_USER + 20001, // struct ALPOPutProcInfo *
	ALPO_Deserialize           = TAG_USER + 20002, // struct ALPOGetProcInfo *
	ALPO_GetRetainCount        = TAG_USER + 20003, // int32 *

	ALPO_SetWithString         = TAG_USER + 20004, // STRPTR
	ALPO_GetAsString           = TAG_USER + 20005, // struct ALPOString *
	//ALPO_SetMemoryPool         = TAG_USER + 20006, // void *pool // TODO
	//ALPO_CopyUsingMemoryPool   = TAG_USER + 20007  // void *pool // TODO
};

// --- PrefsString

struct ALPOUniString
{
	uint32 *string;
	uint32 length;
};

enum enALPOStringMethods
{
	ALPOSTR_AllocSetString     = TAG_USER + 30000, // STRPTR
	ALPOSTR_AllocSetUniString  = TAG_USER + 30001, // struct ALPOUniString *

	ALPOSTR_Clear              = TAG_USER + 10000, // -

	ALPOSTR_GetLength          = TAG_USER + 40000, // int32 *
	
	ALPOSTR_SetString          = TAG_USER + 40001, // STRPTR
	ALPOSTR_GetString          = TAG_USER + 40002, // STRPTR *
	
	ALPOSTR_SetUniString       = TAG_USER + 40003, // struct ALPOUniString *
	ALPOSTR_GetUniString       = TAG_USER + 40004  // struct ALPOUniString *
};

// --- PrefsNumber

enum enALPONumberTypes
{
	ALPONUMT_None   = 0,
	ALPONUMT_Long   = 1,
	ALPONUMT_Bool   = 2,
	ALPONUMT_Double = 3
};

enum enALPONumberMethods
{
	ALPONUM_AllocSetLong       = TAG_USER + 30000, // int32
	ALPONUM_AllocSetBool       = TAG_USER + 30001, // BOOL
	ALPONUM_AllocSetDouble     = TAG_USER + 30002, // double *

	ALPONUM_GetType            = TAG_USER + 40000, // int32 *
	ALPONUM_ConvertToType      = TAG_USER + 40030, // int32
	
	ALPONUM_SetLong            = TAG_USER + 40001, // int32
	ALPONUM_GetLong            = TAG_USER + 40002, // int32 *
		
	ALPONUM_SetBool            = TAG_USER + 40011, // BOOL
	ALPONUM_GetBool            = TAG_USER + 40012, // BOOL *
	
	ALPONUM_SetDouble          = TAG_USER + 40021, // double *
	ALPONUM_GetDouble          = TAG_USER + 40022  // double *
};

// --- PrefsDate
enum enALPODateMethods
{
	ALPODAT_AllocSetTimeVal    = TAG_USER + 30000, // struct TimeVal *
	ALPODAT_AllocSetCTime      = TAG_USER + 30001, // c_time

	ALPODAT_SetCurrentTime     = TAG_USER + 10000, // -
	
	ALPODAT_SetTimeVal         = TAG_USER + 40000, // struct TimeVal *
	ALPODAT_GetTimeVal         = TAG_USER + 40001, // struct TimeVal *
	
	ALPODAT_SetSecsSince1978   = TAG_USER + 40002, // uint32
	ALPODAT_GetSecsSince1978   = TAG_USER + 40003, // uint32 *
	
	ALPODAT_SetClockData       = TAG_USER + 40004, // struct ClockData *
	ALPODAT_GetClockData       = TAG_USER + 40005, // struct ClockData *

	ALPODAT_SetDateStamp       = TAG_USER + 40006, // struct DateStamp *
	ALPODAT_GetDateStamp       = TAG_USER + 40007, // struct DateStamp *
};

// --- PrefsBinary

struct ALPOBinData
{
	uint8 *data;
	int32 size;
};

enum enALPOBinaryMethods
{
	ALPOBIN_AllocWithSize      = TAG_USER + 30000, // int32
	ALPOBIN_AllocWithData      = TAG_USER + 30001, // struct ALPOBinData *

	ALPOBIN_ClearData          = TAG_USER + 10000, // -
	
	ALPOBIN_GetData            = TAG_USER + 40001, // uint8 **
	ALPOBIN_GetSize            = TAG_USER + 40003, // int32 *
	ALPOBIN_GetDataStruct      = TAG_USER + 40002, // struct ALPOBinData *
	ALPOBIN_SetData            = TAG_USER + 40004  // struct ALPOBinData *
};

// --- PrefsDictionary, PrefsArray

struct ALPOObjIndex
{
	PrefsObject *obj;
	int32 index;
};

// --- PrefsDictionary

struct ALPOObjKey
{
	PrefsObject *obj;
	STRPTR key;
};

struct ALPOObjKeyIndex
{
	PrefsObject *obj;
	STRPTR key;
	int32 index;
};

enum enALPODictionaryMethods
{
	ALPODICT_Clear                = TAG_USER + 10000, // -
	ALPODICT_SortAscending        = TAG_USER + 10001, // -
	ALPODICT_SortDescending       = TAG_USER + 10002, // -
	ALPODICT_GetCount             = TAG_USER + 40000, // int32 *

	ALPODICT_SetObjForKey         = TAG_USER + 40010, // struct ALPOObjKey *
	ALPODICT_GetObjForKey         = TAG_USER + 40011, // struct ALPOObjKey *
	ALPODICT_RemoveObjForKey      = TAG_USER + 40012, // STRPTR
	ALPODICT_ReplaceObjForKey     = TAG_USER + 40013, // struct ALPOObjKey *
	ALPODICT_GetObjAndIndexForKey = TAG_USER + 40014, // struct ALPOObjKeyIndex *

	ALPODICT_GetObjAtIndex        = TAG_USER + 40020, // struct ALPOObjIndex *
	ALPODICT_RemoveObjAtIndex     = TAG_USER + 40021, // int32
	ALPODICT_ReplaceObjAtIndex    = TAG_USER + 40022, // struct ALPOObjIndex *
	ALPODICT_GetObjAndKeyAtIndex  = TAG_USER + 40023, // struct ALPOObjKeyIndex *
	ALPODICT_InsertObjAtIndex     = TAG_USER + 40024, // struct ALPOObjKeyIndex *
	
	ALPODICT_RemoveObj            = TAG_USER + 40030, // PrefsObject *
	ALPODICT_GetKeyAndIndexForObj = TAG_USER + 40031, // struct ALPOObjKeyIndex *
};

// --- PrefsArray

enum enALPOArrayMethods
{
	ALPOARR_Clear              = TAG_USER + 10000, // -
	ALPOARR_GetCount           = TAG_USER + 40001, // int32 *

	ALPOARR_AddObj             = TAG_USER + 40010, // PrefsObject *
	
	ALPOARR_InsertObjAtIndex   = TAG_USER + 40011, // struct ALPOObjIndex *
	ALPOARR_GetObjAtIndex      = TAG_USER + 40012, // struct ALPOObjIndex *
	ALPOARR_RemoveObjAtIndex   = TAG_USER + 40013, // int32
	ALPOARR_ReplaceObjAtIndex  = TAG_USER + 40014, // struct ALPOObjIndex *
	
	ALPOARR_RemoveObj          = TAG_USER + 40015, // PrefsObject *
	ALPOARR_GetIndexForObj     = TAG_USER + 40016  // struct ALPOObjIndex *
};


// --- ReadPrefs() tags
enum enALPOReadPrefsTags
{
	READPREFS_AppID            =    TAG_USER +  1, // uint32
	READPREFS_FileName         =    TAG_USER +  2, // STRPTR
	READPREFS_GetProcInfo      =    TAG_USER +  3, // struct ALPOGetProcInfo *
	READPREFS_ReadENV          =    TAG_USER + 10, // BOOL (default: TRUE)
	READPREFS_ReadENVARC       =    TAG_USER + 11  // BOOL (default: TRUE, done if ReadENV failed)
};

// --- WritePrefs() tags
enum enALPOWritePrefsTags
{
	WRITEPREFS_AppID           =    TAG_USER +  1, // uint32
	WRITEPREFS_FileName        =    TAG_USER +  2, // STRPTR
	WRITEPREFS_PutProcInfo     =    TAG_USER +  3, // struct ALPOPutProcInfo *
	WRITEPREFS_WriteENV        =    TAG_USER + 10, // BOOL (default: TRUE)
	WRITEPREFS_WriteENVARC     =    TAG_USER + 11  // BOOL (default: FALSE)
};


/******************************************************************************/


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/******************************************************************************/

#endif    /*  LIBRARIES_APPLICATION_H  */
