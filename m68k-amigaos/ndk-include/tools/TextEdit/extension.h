#ifndef TEXTEDIT_EXTENSION_H
#define TEXTEDIT_EXTENSION_H

#include <intuition/classusr.h>

struct TextEditInterface
{
    /* To be called by extension if it wants to add menus or menu items*/
	void __ASM__ (*installChangeListener)(__REG__(a0, APTR document), __REG__(a1, struct ChangeListener *listener));
	void __ASM__ (*installLeftBarHook)(__REG__(a0, APTR document), __REG__(a1, struct Hook *leftBarHook));
	STRPTR __ASM__ (*executeRexxCommand)(__REG__(a0, APTR document), __REG__(a1, STRPTR rexxCmd)); //only commands in TextEdit, not full rexx
												// and be sure to FreeVec any returned string not TRUE or FALSE
	void __ASM__ (*insertMenu)(__REG__(d0, ULONG insertPosition), __REG__(a0, struct Menu *menuSnip));
	void __ASM__ (*installTopGadget)(__REG__(a0, Object *gadget));
	void __ASM__ (*installBottomGadget)(__REG__(a0, Object *gadget));
	void __ASM__ (*installSideGadget)(__REG__(a0, Object *gadget));
	void __ASM__ (*setWindowFormatStrings)(__REG__(a0, STRPTR titleFormat), __REG__(a1, STRPTR titleModifiedFormat));
	void __ASM__ (*activateGadget)(__REG__(a0, Object *gadget));
};

#define EXTENSIONPLUGIN_VERSION 1
#define EXTENSIONPLUGINHEAD_ID		0x45585453 /* 'EXTS' identification ID */

struct Extension
{
    ULONG extensionData; // Extension can freely store data in this member
    struct TextEditInterface *tei;

    ULONG sigMask; // the signal mask for which you want the handleSignal called
	void __ASM__ (*setWindowPointer)(__REG__(a0, struct Extension *ext), __REG__(a1, struct Window *window));
	void __ASM__ (*onNewDocument)(__REG__(a0, struct Extension *ext), __REG__(a1, APTR document));
	void __ASM__ (*onCurrentDocumentChanged)(__REG__(a0, struct Extension *ext), __REG__(a1, APTR document));
	void __ASM__ (*onDisposeDocument)(__REG__(a0, struct Extension *ext), __REG__(a1, APTR document));
	BOOL __ASM__ (*handleGadgetUp)(__REG__(a0, struct Extension *ext), __REG__(d0, UWORD gadgetId));
	BOOL __ASM__ (*handleRawKey)(__REG__(a0, struct Extension *ext), __REG__(a1, struct IntuiMessage *msg));
	void __ASM__ (*handleSignal)(__REG__(a0, struct Extension *ext), __REG__(d0, ULONG signal));
	BOOL __ASM__ (*aboutToQuit)(__REG__(a0, struct Extension *ext));
	void __ASM__ (*terminate)(__REG__(a0, struct Extension *ext));
};


#endif
