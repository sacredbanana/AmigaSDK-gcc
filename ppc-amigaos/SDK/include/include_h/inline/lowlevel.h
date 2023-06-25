#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_LOWLEVEL_H
#define _INLINE_LOWLEVEL_H

#ifndef CLIB_LOWLEVEL_PROTOS_H
#define CLIB_LOWLEVEL_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef  LIBRARIES_LOWLEVEL_H
#include <libraries/lowlevel.h>
#endif

#ifndef LOWLEVEL_BASE_NAME
#define LOWLEVEL_BASE_NAME LowLevelBase
#endif

#define ReadJoyPort(port) ({ \
  ULONG _ReadJoyPort_port = (port); \
  ULONG _ReadJoyPort__re = \
  ({ \
  register struct Library * const __ReadJoyPort__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register ULONG __ReadJoyPort__re __asm("d0"); \
  register ULONG __ReadJoyPort_port __asm("d0") = (_ReadJoyPort_port); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__ReadJoyPort__re) \
  : "r"(__ReadJoyPort__bn), "r"(__ReadJoyPort_port) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadJoyPort__re; \
  }); \
  _ReadJoyPort__re; \
})

#define GetLanguageSelection() ({ \
  UBYTE _GetLanguageSelection__re = \
  ({ \
  register struct Library * const __GetLanguageSelection__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register UBYTE __GetLanguageSelection__re __asm("d0"); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__GetLanguageSelection__re) \
  : "r"(__GetLanguageSelection__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetLanguageSelection__re; \
  }); \
  _GetLanguageSelection__re; \
})

#define GetKey() ({ \
  ULONG _GetKey__re = \
  ({ \
  register struct Library * const __GetKey__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register ULONG __GetKey__re __asm("d0"); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__GetKey__re) \
  : "r"(__GetKey__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetKey__re; \
  }); \
  _GetKey__re; \
})

#define QueryKeys(queryArray, arraySize) ({ \
  struct KeyQuery * _QueryKeys_queryArray = (queryArray); \
  ULONG _QueryKeys_arraySize = (arraySize); \
  { \
  register struct Library * const __QueryKeys__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register struct KeyQuery * __QueryKeys_queryArray __asm("a0") = (_QueryKeys_queryArray); \
  register ULONG __QueryKeys_arraySize __asm("d1") = (_QueryKeys_arraySize); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__QueryKeys__bn), "r"(__QueryKeys_queryArray), "r"(__QueryKeys_arraySize) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddKBInt(intRoutine, intData) ({ \
  const APTR _AddKBInt_intRoutine = (intRoutine); \
  const APTR _AddKBInt_intData = (intData); \
  APTR _AddKBInt__re = \
  ({ \
  register struct Library * const __AddKBInt__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register APTR __AddKBInt__re __asm("d0"); \
  register const APTR __AddKBInt_intRoutine __asm("a0") = (_AddKBInt_intRoutine); \
  register const APTR __AddKBInt_intData __asm("a1") = (_AddKBInt_intData); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__AddKBInt__re) \
  : "r"(__AddKBInt__bn), "r"(__AddKBInt_intRoutine), "r"(__AddKBInt_intData) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddKBInt__re; \
  }); \
  _AddKBInt__re; \
})

#define RemKBInt(intHandle) ({ \
  APTR _RemKBInt_intHandle = (intHandle); \
  { \
  register struct Library * const __RemKBInt__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register APTR __RemKBInt_intHandle __asm("a1") = (_RemKBInt_intHandle); \
  __asm volatile ("jsr a6@(-66:W)" \
  : \
  : "r"(__RemKBInt__bn), "r"(__RemKBInt_intHandle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SystemControlA(tagList) ({ \
  const struct TagItem * _SystemControlA_tagList = (tagList); \
  ULONG _SystemControlA__re = \
  ({ \
  register struct Library * const __SystemControlA__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register ULONG __SystemControlA__re __asm("d0"); \
  register const struct TagItem * __SystemControlA_tagList __asm("a1") = (_SystemControlA_tagList); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__SystemControlA__re) \
  : "r"(__SystemControlA__bn), "r"(__SystemControlA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SystemControlA__re; \
  }); \
  _SystemControlA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___SystemControl(struct Library * LowLevelBase, Tag tagList, ...)
{
  return SystemControlA((const struct TagItem *) &tagList);
}

#define SystemControl(tags...) ___SystemControl(LOWLEVEL_BASE_NAME, tags)
#endif

#define AddTimerInt(intRoutine, intData) ({ \
  const APTR _AddTimerInt_intRoutine = (intRoutine); \
  const APTR _AddTimerInt_intData = (intData); \
  APTR _AddTimerInt__re = \
  ({ \
  register struct Library * const __AddTimerInt__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register APTR __AddTimerInt__re __asm("d0"); \
  register const APTR __AddTimerInt_intRoutine __asm("a0") = (_AddTimerInt_intRoutine); \
  register const APTR __AddTimerInt_intData __asm("a1") = (_AddTimerInt_intData); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__AddTimerInt__re) \
  : "r"(__AddTimerInt__bn), "r"(__AddTimerInt_intRoutine), "r"(__AddTimerInt_intData) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddTimerInt__re; \
  }); \
  _AddTimerInt__re; \
})

#define RemTimerInt(intHandle) ({ \
  APTR _RemTimerInt_intHandle = (intHandle); \
  { \
  register struct Library * const __RemTimerInt__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register APTR __RemTimerInt_intHandle __asm("a1") = (_RemTimerInt_intHandle); \
  __asm volatile ("jsr a6@(-84:W)" \
  : \
  : "r"(__RemTimerInt__bn), "r"(__RemTimerInt_intHandle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define StopTimerInt(intHandle) ({ \
  APTR _StopTimerInt_intHandle = (intHandle); \
  { \
  register struct Library * const __StopTimerInt__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register APTR __StopTimerInt_intHandle __asm("a1") = (_StopTimerInt_intHandle); \
  __asm volatile ("jsr a6@(-90:W)" \
  : \
  : "r"(__StopTimerInt__bn), "r"(__StopTimerInt_intHandle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define StartTimerInt(intHandle, timeInterval, continuous) ({ \
  APTR _StartTimerInt_intHandle = (intHandle); \
  ULONG _StartTimerInt_timeInterval = (timeInterval); \
  LONG _StartTimerInt_continuous = (continuous); \
  { \
  register struct Library * const __StartTimerInt__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register APTR __StartTimerInt_intHandle __asm("a1") = (_StartTimerInt_intHandle); \
  register ULONG __StartTimerInt_timeInterval __asm("d0") = (_StartTimerInt_timeInterval); \
  register LONG __StartTimerInt_continuous __asm("d1") = (_StartTimerInt_continuous); \
  __asm volatile ("jsr a6@(-96:W)" \
  : \
  : "r"(__StartTimerInt__bn), "r"(__StartTimerInt_intHandle), "r"(__StartTimerInt_timeInterval), "r"(__StartTimerInt_continuous) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ElapsedTime(context) ({ \
  struct EClockVal * _ElapsedTime_context = (context); \
  ULONG _ElapsedTime__re = \
  ({ \
  register struct Library * const __ElapsedTime__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register ULONG __ElapsedTime__re __asm("d0"); \
  register struct EClockVal * __ElapsedTime_context __asm("a0") = (_ElapsedTime_context); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__ElapsedTime__re) \
  : "r"(__ElapsedTime__bn), "r"(__ElapsedTime_context) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ElapsedTime__re; \
  }); \
  _ElapsedTime__re; \
})

#define AddVBlankInt(intRoutine, intData) ({ \
  const APTR _AddVBlankInt_intRoutine = (intRoutine); \
  const APTR _AddVBlankInt_intData = (intData); \
  APTR _AddVBlankInt__re = \
  ({ \
  register struct Library * const __AddVBlankInt__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register APTR __AddVBlankInt__re __asm("d0"); \
  register const APTR __AddVBlankInt_intRoutine __asm("a0") = (_AddVBlankInt_intRoutine); \
  register const APTR __AddVBlankInt_intData __asm("a1") = (_AddVBlankInt_intData); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__AddVBlankInt__re) \
  : "r"(__AddVBlankInt__bn), "r"(__AddVBlankInt_intRoutine), "r"(__AddVBlankInt_intData) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddVBlankInt__re; \
  }); \
  _AddVBlankInt__re; \
})

#define RemVBlankInt(intHandle) ({ \
  APTR _RemVBlankInt_intHandle = (intHandle); \
  { \
  register struct Library * const __RemVBlankInt__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register APTR __RemVBlankInt_intHandle __asm("a1") = (_RemVBlankInt_intHandle); \
  __asm volatile ("jsr a6@(-114:W)" \
  : \
  : "r"(__RemVBlankInt__bn), "r"(__RemVBlankInt_intHandle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetJoyPortAttrsA(portNumber, tagList) ({ \
  ULONG _SetJoyPortAttrsA_portNumber = (portNumber); \
  const struct TagItem * _SetJoyPortAttrsA_tagList = (tagList); \
  BOOL _SetJoyPortAttrsA__re = \
  ({ \
  register struct Library * const __SetJoyPortAttrsA__bn __asm("a6") = (struct Library *) (LOWLEVEL_BASE_NAME);\
  register BOOL __SetJoyPortAttrsA__re __asm("d0"); \
  register ULONG __SetJoyPortAttrsA_portNumber __asm("d0") = (_SetJoyPortAttrsA_portNumber); \
  register const struct TagItem * __SetJoyPortAttrsA_tagList __asm("a1") = (_SetJoyPortAttrsA_tagList); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__SetJoyPortAttrsA__re) \
  : "r"(__SetJoyPortAttrsA__bn), "r"(__SetJoyPortAttrsA_portNumber), "r"(__SetJoyPortAttrsA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetJoyPortAttrsA__re; \
  }); \
  _SetJoyPortAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___SetJoyPortAttrs(struct Library * LowLevelBase, ULONG portNumber, Tag tagList, ...)
{
  return SetJoyPortAttrsA(portNumber, (const struct TagItem *) &tagList);
}

#define SetJoyPortAttrs(portNumber...) ___SetJoyPortAttrs(LOWLEVEL_BASE_NAME, portNumber)
#endif

#endif /*  _INLINE_LOWLEVEL_H  */
