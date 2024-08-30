/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_KEYMAP_H
#define _INLINE_KEYMAP_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

VOID __SetKeyMapDefault(__reg("a6") struct Library * , __reg("a0") struct KeyMap * keyMap ) = "\tjsr\t-30(a6)";
#define SetKeyMapDefault(keyMap) __SetKeyMapDefault(KeymapBase, (keyMap))

struct KeyMap * __AskKeyMapDefault(__reg("a6") struct Library * ) = "\tjsr\t-36(a6)";
#define AskKeyMapDefault() __AskKeyMapDefault(KeymapBase)

WORD __MapRawKey(__reg("a6") struct Library * , __reg("a0") CONST struct InputEvent * event , __reg("a1") STRPTR buffer , __reg("d1") WORD length , __reg("a2") CONST struct KeyMap * keyMap ) = "\tjsr\t-42(a6)";
#define MapRawKey(event, buffer, length, keyMap) __MapRawKey(KeymapBase, (event), (buffer), (length), (keyMap))

LONG __MapANSI(__reg("a6") struct Library * , __reg("a0") CONST_STRPTR string , __reg("d0") LONG count , __reg("a1") STRPTR buffer , __reg("d1") LONG length , __reg("a2") CONST struct KeyMap * keyMap ) = "\tjsr\t-48(a6)";
#define MapANSI(string, count, buffer, length, keyMap) __MapANSI(KeymapBase, (string), (count), (buffer), (length), (keyMap))

#endif /* !_INLINE_KEYMAP_H */
