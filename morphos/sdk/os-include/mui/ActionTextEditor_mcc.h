#ifndef MUI_ACTIONTEXTEDITOR_MCC_H
#define MUI_ACTIONTEXTEDITOR_MCC_H

/*
 * ActionTextEditor.mcc - TextEditor subclass that submits on Return
 *
 * MUIA_ActionTextEditor_SubmitHook
 *   A Hook called when the user presses Return (qualifier 32768) and the
 *   gadget has text. Right Shift + Return inserts a newline via the
 *   superclass, the same as TextEditor.mcc.
 */

#ifndef LIBRARIES_MUI_H
#include <libraries/mui.h>
#endif

#define MUIC_ActionTextEditor "ActionTextEditor.mcc"

#define ActionTextEditor_Dummy (0xbd000000UL)
#define MUIA_ActionTextEditor_SubmitHook (ActionTextEditor_Dummy + 0x02)

#if defined(__AROS__) && !defined(NO_INLINE_STDARG)
#define ActionTextEditorObject MUIOBJMACRO_START(MUIC_ActionTextEditor)
#else
#define ActionTextEditorObject MUI_NewObject(MUIC_ActionTextEditor
#endif

#endif /* MUI_ACTIONTEXTEDITOR_MCC_H */
