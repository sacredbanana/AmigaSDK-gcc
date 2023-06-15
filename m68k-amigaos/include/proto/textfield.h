#ifndef PROTO_TEXTFIELD_H
#define PROTO_TEXTFIELD_H
#include <exec/types.h>
#include <intuition/classes.h>
#include <defines/textfield.h>
extern struct Library *TextFieldBase;
extern Class *TextFieldClass;
Class * __stdargs TEXTFIELD_GetClass(void);
char *TEXTFIELD_GetCopyright(void);
#endif
#ifndef TEXXTFIELD_INLINE_H
#include <inline/textfield.h>
#else
#include <pragmas/textfield_pragmas.h>
#endif