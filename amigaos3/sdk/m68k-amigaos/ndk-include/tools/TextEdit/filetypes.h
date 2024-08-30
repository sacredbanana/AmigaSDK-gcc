#ifndef TEXTEDIT_FILETYPE_H
#define TEXTEDIT_FILETYPE_H

#include <intuition/classusr.h>
#include <gadgets/texteditor.h>

#include <tools/textedit/plugin.h>

struct EditorSettings {
	UWORD Version;
	BOOL HasLineNumbers:1;
	BOOL CutCopyLineWhenNoSel:1;
	BOOL AutoIndent:1;
    UWORD TabKeyPolicy:2;
//	BOOL ReplaceTabsOnPaste:1;
    ULONG WrapColumn;
	UBYTE WordWrapMode;
	UBYTE IndentationWidth;
	UBYTE TabWidth;
	UBYTE IndentUsing;
};

#define FILETYPEPLUGINHEAD_ID		0x46545950 /* 'FTYP' identification ID */
#define FILETYPEPLUGIN_VERSION	2

struct Filetype {
	struct MinNode Node;
	struct EditorSettings *WorkingCopy;
	ULONG menuNumber;
	struct MenuItem *menuitem;
	UWORD Version;
	CONST_STRPTR name; // localized GUI visible name
	STRPTR typeName; // name used for prefs files etc
	STRPTR autoFileTypes; // newline separated list of deficon names that will match
    struct EditorSettings *editorSettings;
	void __ASM__ (*installChangeListener)(__REG__(a0, APTR document), __REG__(a1, struct ChangeListener *listener));
	STRPTR __ASM__ (*executeRexxCommand)(__REG__(a0, APTR document), __REG__(a1, STRPTR rexxCmd)); //only commands in TextEdit, not full rexx
                                                // and be sure to FreeVec any returned string not TRUE or FALSE
	ULONG pluginData;
	void __ASM__ (*terminate)(__REG__(a0, struct Filetype *fType));

	/* implement this pointer if you want to do syntax highlighting
	 * See texteditor.h and apidocs of texteditor.gadget for more details */
	struct Hook *highlighterHook;

	/* The following functions needs to be filled in if the filetype provides extra
	 * pages in the filetype options requester.
	 * Any gadget should have a gadget ID higher than 1000 so as not to conflict with
	 * other gadgets int the preferences window.
	 */
	Object * __ASM__ (*settingsGadget)(__REG__(a0, struct Filetype *fType), __REG__(d0, ULONG i));
	STRPTR __ASM__ (*settingsTitle)(__REG__(a0, struct Filetype *fType), __REG__(d0, ULONG i));
	BOOL __ASM__ (*loadSettings)(__REG__(a0, struct IFFHandle *iff), __REG__(a1, struct ContextNode *cn), __REG__(a2, struct Filetype * fType));
	BOOL __ASM__ (*saveSettings)(__REG__(a0, struct IFFHandle *iff), __REG__(a1, struct ContextNode *cn), __REG__(a2, struct Filetype * fType));
	void __ASM__ (*setSettingsFromGUI)(__REG__(a0, struct Filetype *fType));
	void __ASM__ (*setGUIFromSettings)(__REG__(a0, struct Filetype *fType), __REG__(a1, struct Window *window));
	void __ASM__ (*processGadgetUp)(__REG__(a0, struct Filetype *fType), __REG__(d0, UWORD gadgetID), __REG__(a1, struct Window *window));
	void __ASM__ (*applySettings)(__REG__(a0, struct Filetype *fType));
	void __ASM__ (*disposeGadgets)(__REG__(a0, struct Filetype *fType));
	void __ASM__ (*assignedToDocument)(__REG__(a0, struct Filetype *fType), __REG__(a1, APTR document));
	void __ASM__ (*unassignedFromDocument)(__REG__(a0, struct Filetype *fType), __REG__(a1, APTR document));
};


#endif
