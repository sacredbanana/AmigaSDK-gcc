/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_CONSOLE_H
#define _INLINE_CONSOLE_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

struct InputEvent * __CDInputHandler(__reg("a6") struct Library * , __reg("a0") CONST struct InputEvent * events , __reg("a1") struct Library * consoleDevice ) = "\tjsr\t-42(a6)";
#define CDInputHandler(events, consoleDevice) __CDInputHandler(ConsoleDeviceBase, (events), (consoleDevice))

LONG __RawKeyConvert(__reg("a6") struct Library * , __reg("a0") CONST struct InputEvent * events , __reg("a1") STRPTR buffer , __reg("d1") LONG length , __reg("a2") CONST struct KeyMap * keyMap ) = "\tjsr\t-48(a6)";
#define RawKeyConvert(events, buffer, length, keyMap) __RawKeyConvert(ConsoleDeviceBase, (events), (buffer), (length), (keyMap))

#endif /* !_INLINE_CONSOLE_H */
