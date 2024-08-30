#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_CONSOLE_H
#define _INLINE_CONSOLE_H

#ifndef CLIB_CONSOLE_PROTOS_H
#define CLIB_CONSOLE_PROTOS_H
#endif

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  DEVICES_INPUTEVENT_H
#include <devices/inputevent.h>
#endif
#ifndef  DEVICES_KEYMAP_H
#include <devices/keymap.h>
#endif

#ifndef CONSOLE_BASE_NAME
#define CONSOLE_BASE_NAME ConsoleDevice
#endif

#define CDInputHandler(events, consoleDevice) ({ \
  const struct InputEvent * _CDInputHandler_events = (events); \
  struct Library * _CDInputHandler_consoleDevice = (consoleDevice); \
  struct InputEvent * _CDInputHandler__re = \
  ({ \
  register struct Device * const __CDInputHandler__bn __asm("a6") = (struct Device *) (CONSOLE_BASE_NAME);\
  register struct InputEvent * __CDInputHandler__re __asm("d0"); \
  register const struct InputEvent * __CDInputHandler_events __asm("a0") = (_CDInputHandler_events); \
  register struct Library * __CDInputHandler_consoleDevice __asm("a1") = (_CDInputHandler_consoleDevice); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__CDInputHandler__re) \
  : "r"(__CDInputHandler__bn), "r"(__CDInputHandler_events), "r"(__CDInputHandler_consoleDevice) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CDInputHandler__re; \
  }); \
  _CDInputHandler__re; \
})

#define RawKeyConvert(events, buffer, length, keyMap) ({ \
  const struct InputEvent * _RawKeyConvert_events = (events); \
  STRPTR _RawKeyConvert_buffer = (buffer); \
  LONG _RawKeyConvert_length = (length); \
  const struct KeyMap * _RawKeyConvert_keyMap = (keyMap); \
  LONG _RawKeyConvert__re = \
  ({ \
  register struct Device * const __RawKeyConvert__bn __asm("a6") = (struct Device *) (CONSOLE_BASE_NAME);\
  register LONG __RawKeyConvert__re __asm("d0"); \
  register const struct InputEvent * __RawKeyConvert_events __asm("a0") = (_RawKeyConvert_events); \
  register STRPTR __RawKeyConvert_buffer __asm("a1") = (_RawKeyConvert_buffer); \
  register LONG __RawKeyConvert_length __asm("d1") = (_RawKeyConvert_length); \
  register const struct KeyMap * __RawKeyConvert_keyMap __asm("a2") = (_RawKeyConvert_keyMap); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__RawKeyConvert__re) \
  : "r"(__RawKeyConvert__bn), "r"(__RawKeyConvert_events), "r"(__RawKeyConvert_buffer), "r"(__RawKeyConvert_length), "r"(__RawKeyConvert_keyMap) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RawKeyConvert__re; \
  }); \
  _RawKeyConvert__re; \
})

#endif /*  _INLINE_CONSOLE_H  */
