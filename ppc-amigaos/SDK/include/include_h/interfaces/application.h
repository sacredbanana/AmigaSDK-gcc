#ifndef APPLICATION_INTERFACE_DEF_H
#define APPLICATION_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 52.6.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef LIBRARIES_APPLICATION_H
#include <libraries/application.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct ApplicationIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct ApplicationIFace *Self);
	uint32 APICALL (*Release)(struct ApplicationIFace *Self);
	void APICALL (*Expunge)(struct ApplicationIFace *Self);
	struct Interface * APICALL (*Clone)(struct ApplicationIFace *Self);
	BOOL APICALL (*SetAppLibAttrsA)(struct ApplicationIFace *Self, struct TagItem * tags);
	BOOL APICALL (*SetAppLibAttrs)(struct ApplicationIFace *Self, ...);
	BOOL APICALL (*GetAppLibAttrsA)(struct ApplicationIFace *Self, struct TagItem * tags);
	BOOL APICALL (*GetAppLibAttrs)(struct ApplicationIFace *Self, ...);
	uint32 APICALL (*RegisterApplicationA)(struct ApplicationIFace *Self, CONST_STRPTR appName, struct TagItem * tags);
	uint32 APICALL (*RegisterApplication)(struct ApplicationIFace *Self, CONST_STRPTR appName, ...);
	BOOL APICALL (*UnregisterApplicationA)(struct ApplicationIFace *Self, uint32 appID, struct TagItem * tags);
	BOOL APICALL (*UnregisterApplication)(struct ApplicationIFace *Self, uint32 appID, ...);
	BOOL APICALL (*SetApplicationAttrsA)(struct ApplicationIFace *Self, uint32 appID, struct TagItem * tags);
	BOOL APICALL (*SetApplicationAttrs)(struct ApplicationIFace *Self, uint32 appID, ...);
	BOOL APICALL (*GetApplicationAttrsA)(struct ApplicationIFace *Self, uint32 appID, struct TagItem * tags);
	BOOL APICALL (*GetApplicationAttrs)(struct ApplicationIFace *Self, uint32 appID, ...);
	uint32 APICALL (*FindApplicationA)(struct ApplicationIFace *Self, struct TagItem * tags);
	uint32 APICALL (*FindApplication)(struct ApplicationIFace *Self, ...);
	BOOL APICALL (*LockApplicationIcon)(struct ApplicationIFace *Self, uint32 appID);
	void APICALL (*UnlockApplicationIcon)(struct ApplicationIFace *Self, uint32 appID);
	struct MinList * APICALL (*GetApplicationList)(struct ApplicationIFace *Self);
	void APICALL (*FreeApplicationList)(struct ApplicationIFace *Self, struct MinList * list);
	BOOL APICALL (*SendApplicationMsg)(struct ApplicationIFace *Self, uint32 senderAppID, uint32 receiverAppID, struct ApplicationMsg * msg, uint32 msgType);
	uint32 APICALL (*NotifyA)(struct ApplicationIFace *Self, uint32 appID, struct TagItem * tags);
	uint32 APICALL (*Notify)(struct ApplicationIFace *Self, uint32 appID, ...);
};

struct PrefsObjectsIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct PrefsObjectsIFace *Self);
	uint32 APICALL (*Release)(struct PrefsObjectsIFace *Self);
	void APICALL (*Expunge)(struct PrefsObjectsIFace *Self);
	struct Interface * APICALL (*Clone)(struct PrefsObjectsIFace *Self);
	uint32 APICALL (*BeginDeserialization)(struct PrefsObjectsIFace *Self, struct ALPOGetProcInfo * info);
	PrefsObject * APICALL (*PrefsBaseObjectA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsBaseObject)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsStringA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsString)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsNumberA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsNumber)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsDateA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsDate)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsBinaryA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsBinary)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsDictionaryA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsDictionary)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsArrayA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsArray)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	BOOL APICALL (*DictSetObjectForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, PrefsObject * obj, CONST_STRPTR key);
	PrefsObject * APICALL (*DictGetObjectForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, CONST_STRPTR key);
	CONST_STRPTR APICALL (*DictGetStringForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, CONST_STRPTR key, CONST_STRPTR defStr);
	int32 APICALL (*DictGetIntegerForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, CONST_STRPTR key, int32 defInt);
	BOOL APICALL (*DictGetBoolForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, CONST_STRPTR key, BOOL defBool);
	int32 APICALL (*DictGetOptionForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, CONST_STRPTR key, CONST_STRPTR * optionsTable, int32 defaultOption);
	uint32 APICALL (*ReadPrefsA)(struct PrefsObjectsIFace *Self, PrefsObject * dict, struct TagItem * tags);
	uint32 APICALL (*ReadPrefs)(struct PrefsObjectsIFace *Self, PrefsObject * dict, ...);
	uint32 APICALL (*WritePrefsA)(struct PrefsObjectsIFace *Self, PrefsObject * dict, struct TagItem * tags);
	uint32 APICALL (*WritePrefs)(struct PrefsObjectsIFace *Self, PrefsObject * dict, ...);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* APPLICATION_INTERFACE_DEF_H */
