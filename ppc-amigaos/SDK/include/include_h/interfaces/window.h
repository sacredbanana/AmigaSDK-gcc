#ifndef WINDOW_INTERFACE_DEF_H
#define WINDOW_INTERFACE_DEF_H

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

#ifndef INTUITION_INTUITION_H
#include <intuition/intuition.h>
#endif
#ifndef INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct WindowIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct WindowIFace *Self);
	ULONG APICALL (*Release)(struct WindowIFace *Self);
	void APICALL (*Expunge)(struct WindowIFace *Self);
	struct Interface * APICALL (*Clone)(struct WindowIFace *Self);
	Class * APICALL (*WINDOW_GetClass)(struct WindowIFace *Self);
	void APICALL (*NewWindowPrefs)(struct WindowIFace *Self);
	ULONG APICALL (*WindowPrivate1)(struct WindowIFace *Self);
	void APICALL (*UpdateWindowPrefs)(struct WindowIFace *Self, struct Screen * screen);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* WINDOW_INTERFACE_DEF_H */
