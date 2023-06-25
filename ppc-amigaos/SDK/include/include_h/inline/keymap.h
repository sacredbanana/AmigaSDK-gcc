#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_KEYMAP_H
#define _INLINE_KEYMAP_H

#ifndef CLIB_KEYMAP_PROTOS_H
#define CLIB_KEYMAP_PROTOS_H
#endif

#ifndef  DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef  LIBRARIES_KEYMAP_H
#include <libraries/keymap.h>
#endif

#ifndef KEYMAP_BASE_NAME
#define KEYMAP_BASE_NAME KeymapBase
#endif

#define SetKeyMapDefault(keyMap) ({ \
  const struct KeyMap * _SetKeyMapDefault_keyMap = (keyMap); \
  { \
  register struct Library * const __SetKeyMapDefault__bn __asm("a6") = (struct Library *) (KEYMAP_BASE_NAME);\
  register const struct KeyMap * __SetKeyMapDefault_keyMap __asm("a0") = (_SetKeyMapDefault_keyMap); \
  __asm volatile ("jsr a6@(-30:W)" \
  : \
  : "r"(__SetKeyMapDefault__bn), "r"(__SetKeyMapDefault_keyMap) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AskKeyMapDefault() ({ \
  struct KeyMap * _AskKeyMapDefault__re = \
  ({ \
  register struct Library * const __AskKeyMapDefault__bn __asm("a6") = (struct Library *) (KEYMAP_BASE_NAME);\
  register struct KeyMap * __AskKeyMapDefault__re __asm("d0"); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__AskKeyMapDefault__re) \
  : "r"(__AskKeyMapDefault__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AskKeyMapDefault__re; \
  }); \
  _AskKeyMapDefault__re; \
})

#define MapRawKey(event, buffer, length, keyMap) ({ \
  const struct InputEvent * _MapRawKey_event = (event); \
  STRPTR _MapRawKey_buffer = (buffer); \
  LONG _MapRawKey_length = (length); \
  const struct KeyMap * _MapRawKey_keyMap = (keyMap); \
  WORD _MapRawKey__re = \
  ({ \
  register struct Library * const __MapRawKey__bn __asm("a6") = (struct Library *) (KEYMAP_BASE_NAME);\
  register WORD __MapRawKey__re __asm("d0"); \
  register const struct InputEvent * __MapRawKey_event __asm("a0") = (_MapRawKey_event); \
  register STRPTR __MapRawKey_buffer __asm("a1") = (_MapRawKey_buffer); \
  register LONG __MapRawKey_length __asm("d1") = (_MapRawKey_length); \
  register const struct KeyMap * __MapRawKey_keyMap __asm("a2") = (_MapRawKey_keyMap); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__MapRawKey__re) \
  : "r"(__MapRawKey__bn), "r"(__MapRawKey_event), "r"(__MapRawKey_buffer), "r"(__MapRawKey_length), "r"(__MapRawKey_keyMap) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __MapRawKey__re; \
  }); \
  _MapRawKey__re; \
})

#define MapANSI(string, count, buffer, length, keyMap) ({ \
  CONST_STRPTR _MapANSI_string = (string); \
  LONG _MapANSI_count = (count); \
  STRPTR _MapANSI_buffer = (buffer); \
  LONG _MapANSI_length = (length); \
  const struct KeyMap * _MapANSI_keyMap = (keyMap); \
  LONG _MapANSI__re = \
  ({ \
  register struct Library * const __MapANSI__bn __asm("a6") = (struct Library *) (KEYMAP_BASE_NAME);\
  register LONG __MapANSI__re __asm("d0"); \
  register CONST_STRPTR __MapANSI_string __asm("a0") = (_MapANSI_string); \
  register LONG __MapANSI_count __asm("d0") = (_MapANSI_count); \
  register STRPTR __MapANSI_buffer __asm("a1") = (_MapANSI_buffer); \
  register LONG __MapANSI_length __asm("d1") = (_MapANSI_length); \
  register const struct KeyMap * __MapANSI_keyMap __asm("a2") = (_MapANSI_keyMap); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__MapANSI__re) \
  : "r"(__MapANSI__bn), "r"(__MapANSI_string), "r"(__MapANSI_count), "r"(__MapANSI_buffer), "r"(__MapANSI_length), "r"(__MapANSI_keyMap) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __MapANSI__re; \
  }); \
  _MapANSI__re; \
})

#define OpenKeyMapHandleA(filename, taglist) ({ \
  STRPTR _OpenKeyMapHandleA_filename = (filename); \
  struct TagItem * _OpenKeyMapHandleA_taglist = (taglist); \
  APTR _OpenKeyMapHandleA__re = \
  ({ \
  register struct Library * const __OpenKeyMapHandleA__bn __asm("a6") = (struct Library *) (KEYMAP_BASE_NAME);\
  register APTR __OpenKeyMapHandleA__re __asm("d0"); \
  register STRPTR __OpenKeyMapHandleA_filename __asm("a0") = (_OpenKeyMapHandleA_filename); \
  register struct TagItem * __OpenKeyMapHandleA_taglist __asm("a1") = (_OpenKeyMapHandleA_taglist); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__OpenKeyMapHandleA__re) \
  : "r"(__OpenKeyMapHandleA__bn), "r"(__OpenKeyMapHandleA_filename), "r"(__OpenKeyMapHandleA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenKeyMapHandleA__re; \
  }); \
  _OpenKeyMapHandleA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___OpenKeyMapHandle(struct Library * KeymapBase, STRPTR filename, Tag taglist, ...)
{
  return OpenKeyMapHandleA(filename, (struct TagItem *) &taglist);
}

#define OpenKeyMapHandle(filename...) ___OpenKeyMapHandle(KEYMAP_BASE_NAME, filename)
#endif

#define CloseKeyMapHandle(handle) ({ \
  APTR _CloseKeyMapHandle_handle = (handle); \
  { \
  register struct Library * const __CloseKeyMapHandle__bn __asm("a6") = (struct Library *) (KEYMAP_BASE_NAME);\
  register APTR __CloseKeyMapHandle_handle __asm("a0") = (_CloseKeyMapHandle_handle); \
  __asm volatile ("jsr a6@(-60:W)" \
  : \
  : "r"(__CloseKeyMapHandle__bn), "r"(__CloseKeyMapHandle_handle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainKeyMapInfoA(handle, taglist) ({ \
  APTR _ObtainKeyMapInfoA_handle = (handle); \
  struct TagItem * _ObtainKeyMapInfoA_taglist = (taglist); \
  ULONG _ObtainKeyMapInfoA__re = \
  ({ \
  register struct Library * const __ObtainKeyMapInfoA__bn __asm("a6") = (struct Library *) (KEYMAP_BASE_NAME);\
  register ULONG __ObtainKeyMapInfoA__re __asm("d0"); \
  register APTR __ObtainKeyMapInfoA_handle __asm("a0") = (_ObtainKeyMapInfoA_handle); \
  register struct TagItem * __ObtainKeyMapInfoA_taglist __asm("a1") = (_ObtainKeyMapInfoA_taglist); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__ObtainKeyMapInfoA__re) \
  : "r"(__ObtainKeyMapInfoA__bn), "r"(__ObtainKeyMapInfoA_handle), "r"(__ObtainKeyMapInfoA_taglist) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ObtainKeyMapInfoA__re; \
  }); \
  _ObtainKeyMapInfoA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___ObtainKeyMapInfo(struct Library * KeymapBase, APTR handle, Tag taglist, ...)
{
  return ObtainKeyMapInfoA(handle, (struct TagItem *) &taglist);
}

#define ObtainKeyMapInfo(handle...) ___ObtainKeyMapInfo(KEYMAP_BASE_NAME, handle)
#endif

#define ReleaseKeyMapInfoA(handle, taglist) ({ \
  APTR _ReleaseKeyMapInfoA_handle = (handle); \
  struct TagItem * _ReleaseKeyMapInfoA_taglist = (taglist); \
  { \
  register struct Library * const __ReleaseKeyMapInfoA__bn __asm("a6") = (struct Library *) (KEYMAP_BASE_NAME);\
  register APTR __ReleaseKeyMapInfoA_handle __asm("a0") = (_ReleaseKeyMapInfoA_handle); \
  register struct TagItem * __ReleaseKeyMapInfoA_taglist __asm("a1") = (_ReleaseKeyMapInfoA_taglist); \
  __asm volatile ("jsr a6@(-72:W)" \
  : \
  : "r"(__ReleaseKeyMapInfoA__bn), "r"(__ReleaseKeyMapInfoA_handle), "r"(__ReleaseKeyMapInfoA_taglist) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___ReleaseKeyMapInfo(struct Library * KeymapBase, APTR handle, Tag taglist, ...)
{
  ReleaseKeyMapInfoA(handle, (struct TagItem *) &taglist);
}

#define ReleaseKeyMapInfo(handle...) ___ReleaseKeyMapInfo(KEYMAP_BASE_NAME, handle)
#endif

#define ObtainRawKeyInfoA(taglist) ({ \
  struct TagItem * _ObtainRawKeyInfoA_taglist = (taglist); \
  { \
  register struct Library * const __ObtainRawKeyInfoA__bn __asm("a6") = (struct Library *) (KEYMAP_BASE_NAME);\
  register struct TagItem * __ObtainRawKeyInfoA_taglist __asm("a0") = (_ObtainRawKeyInfoA_taglist); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__ObtainRawKeyInfoA__bn), "r"(__ObtainRawKeyInfoA_taglist) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___ObtainRawKeyInfo(struct Library * KeymapBase, Tag taglist, ...)
{
  ObtainRawKeyInfoA((struct TagItem *) &taglist);
}

#define ObtainRawKeyInfo(tags...) ___ObtainRawKeyInfo(KEYMAP_BASE_NAME, tags)
#endif

#endif /*  _INLINE_KEYMAP_H  */
