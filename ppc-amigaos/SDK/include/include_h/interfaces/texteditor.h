#ifndef TEXTEDITOR_INTERFACE_DEF_H
#define TEXTEDITOR_INTERFACE_DEF_H

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

struct TextEditorIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct TextEditorIFace *Self);
	ULONG APICALL (*Release)(struct TextEditorIFace *Self);
	void APICALL (*Expunge)(struct TextEditorIFace *Self);
	struct Interface * APICALL (*Clone)(struct TextEditorIFace *Self);
	Class * APICALL (*TEXTEDITOR_GetClass)(struct TextEditorIFace *Self);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* TEXTEDITOR_INTERFACE_DEF_H */
