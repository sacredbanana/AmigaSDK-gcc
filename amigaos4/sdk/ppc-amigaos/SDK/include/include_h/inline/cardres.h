#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_CARDRES_H
#define _INLINE_CARDRES_H

#ifndef CLIB_CARDRES_PROTOS_H
#define CLIB_CARDRES_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_RESIDENT_H
#include <exec/resident.h>
#endif
#ifndef  RESOURCES_CARD_H
#include <resources/card.h>
#endif

#ifndef CARDRES_BASE_NAME
#define CARDRES_BASE_NAME CardResource
#endif

#define OwnCard(handle) ({ \
  struct CardHandle * _OwnCard_handle = (handle); \
  struct CardHandle * _OwnCard__re = \
  ({ \
  register struct Library * const __OwnCard__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register struct CardHandle * __OwnCard__re __asm("d0"); \
  register struct CardHandle * __OwnCard_handle __asm("a1") = (_OwnCard_handle); \
  __asm volatile ("jsr a6@(-6:W)" \
  : "=r"(__OwnCard__re) \
  : "r"(__OwnCard__bn), "r"(__OwnCard_handle) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OwnCard__re; \
  }); \
  _OwnCard__re; \
})

#define ReleaseCard(handle, flags) ({ \
  struct CardHandle * _ReleaseCard_handle = (handle); \
  ULONG _ReleaseCard_flags = (flags); \
  { \
  register struct Library * const __ReleaseCard__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register struct CardHandle * __ReleaseCard_handle __asm("a1") = (_ReleaseCard_handle); \
  register ULONG __ReleaseCard_flags __asm("d0") = (_ReleaseCard_flags); \
  __asm volatile ("jsr a6@(-12:W)" \
  : \
  : "r"(__ReleaseCard__bn), "r"(__ReleaseCard_handle), "r"(__ReleaseCard_flags) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetCardMap() ({ \
  struct CardMemoryMap * _GetCardMap__re = \
  ({ \
  register struct Library * const __GetCardMap__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register struct CardMemoryMap * __GetCardMap__re __asm("d0"); \
  __asm volatile ("jsr a6@(-18:W)" \
  : "=r"(__GetCardMap__re) \
  : "r"(__GetCardMap__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetCardMap__re; \
  }); \
  _GetCardMap__re; \
})

#define BeginCardAccess(handle) ({ \
  struct CardHandle * _BeginCardAccess_handle = (handle); \
  BOOL _BeginCardAccess__re = \
  ({ \
  register struct Library * const __BeginCardAccess__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register BOOL __BeginCardAccess__re __asm("d0"); \
  register struct CardHandle * __BeginCardAccess_handle __asm("a1") = (_BeginCardAccess_handle); \
  __asm volatile ("jsr a6@(-24:W)" \
  : "=r"(__BeginCardAccess__re) \
  : "r"(__BeginCardAccess__bn), "r"(__BeginCardAccess_handle) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __BeginCardAccess__re; \
  }); \
  _BeginCardAccess__re; \
})

#define EndCardAccess(handle) ({ \
  struct CardHandle * _EndCardAccess_handle = (handle); \
  BOOL _EndCardAccess__re = \
  ({ \
  register struct Library * const __EndCardAccess__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register BOOL __EndCardAccess__re __asm("d0"); \
  register struct CardHandle * __EndCardAccess_handle __asm("a1") = (_EndCardAccess_handle); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__EndCardAccess__re) \
  : "r"(__EndCardAccess__bn), "r"(__EndCardAccess_handle) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __EndCardAccess__re; \
  }); \
  _EndCardAccess__re; \
})

#define ReadCardStatus() ({ \
  UBYTE _ReadCardStatus__re = \
  ({ \
  register struct Library * const __ReadCardStatus__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register UBYTE __ReadCardStatus__re __asm("d0"); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__ReadCardStatus__re) \
  : "r"(__ReadCardStatus__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadCardStatus__re; \
  }); \
  _ReadCardStatus__re; \
})

#define CardResetRemove(handle, flag) ({ \
  struct CardHandle * _CardResetRemove_handle = (handle); \
  ULONG _CardResetRemove_flag = (flag); \
  BOOL _CardResetRemove__re = \
  ({ \
  register struct Library * const __CardResetRemove__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register BOOL __CardResetRemove__re __asm("d0"); \
  register struct CardHandle * __CardResetRemove_handle __asm("a1") = (_CardResetRemove_handle); \
  register ULONG __CardResetRemove_flag __asm("d0") = (_CardResetRemove_flag); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__CardResetRemove__re) \
  : "r"(__CardResetRemove__bn), "r"(__CardResetRemove_handle), "r"(__CardResetRemove_flag) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CardResetRemove__re; \
  }); \
  _CardResetRemove__re; \
})

#define CardMiscControl(handle, control_bits) ({ \
  struct CardHandle * _CardMiscControl_handle = (handle); \
  ULONG _CardMiscControl_control_bits = (control_bits); \
  UBYTE _CardMiscControl__re = \
  ({ \
  register struct Library * const __CardMiscControl__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register UBYTE __CardMiscControl__re __asm("d0"); \
  register struct CardHandle * __CardMiscControl_handle __asm("a1") = (_CardMiscControl_handle); \
  register ULONG __CardMiscControl_control_bits __asm("d1") = (_CardMiscControl_control_bits); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__CardMiscControl__re) \
  : "r"(__CardMiscControl__bn), "r"(__CardMiscControl_handle), "r"(__CardMiscControl_control_bits) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CardMiscControl__re; \
  }); \
  _CardMiscControl__re; \
})

#define CardAccessSpeed(handle, nanoseconds) ({ \
  struct CardHandle * _CardAccessSpeed_handle = (handle); \
  ULONG _CardAccessSpeed_nanoseconds = (nanoseconds); \
  ULONG _CardAccessSpeed__re = \
  ({ \
  register struct Library * const __CardAccessSpeed__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register ULONG __CardAccessSpeed__re __asm("d0"); \
  register struct CardHandle * __CardAccessSpeed_handle __asm("a1") = (_CardAccessSpeed_handle); \
  register ULONG __CardAccessSpeed_nanoseconds __asm("d0") = (_CardAccessSpeed_nanoseconds); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__CardAccessSpeed__re) \
  : "r"(__CardAccessSpeed__bn), "r"(__CardAccessSpeed_handle), "r"(__CardAccessSpeed_nanoseconds) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CardAccessSpeed__re; \
  }); \
  _CardAccessSpeed__re; \
})

#define CardProgramVoltage(handle, voltage) ({ \
  struct CardHandle * _CardProgramVoltage_handle = (handle); \
  ULONG _CardProgramVoltage_voltage = (voltage); \
  LONG _CardProgramVoltage__re = \
  ({ \
  register struct Library * const __CardProgramVoltage__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register LONG __CardProgramVoltage__re __asm("d0"); \
  register struct CardHandle * __CardProgramVoltage_handle __asm("a1") = (_CardProgramVoltage_handle); \
  register ULONG __CardProgramVoltage_voltage __asm("d0") = (_CardProgramVoltage_voltage); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__CardProgramVoltage__re) \
  : "r"(__CardProgramVoltage__bn), "r"(__CardProgramVoltage_handle), "r"(__CardProgramVoltage_voltage) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CardProgramVoltage__re; \
  }); \
  _CardProgramVoltage__re; \
})

#define CardResetCard(handle) ({ \
  struct CardHandle * _CardResetCard_handle = (handle); \
  BOOL _CardResetCard__re = \
  ({ \
  register struct Library * const __CardResetCard__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register BOOL __CardResetCard__re __asm("d0"); \
  register struct CardHandle * __CardResetCard_handle __asm("a1") = (_CardResetCard_handle); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__CardResetCard__re) \
  : "r"(__CardResetCard__bn), "r"(__CardResetCard_handle) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CardResetCard__re; \
  }); \
  _CardResetCard__re; \
})

#define CopyTuple(handle, buffer, tuplecode, size) ({ \
  const struct CardHandle * _CopyTuple_handle = (handle); \
  UBYTE * _CopyTuple_buffer = (buffer); \
  ULONG _CopyTuple_tuplecode = (tuplecode); \
  ULONG _CopyTuple_size = (size); \
  BOOL _CopyTuple__re = \
  ({ \
  register struct Library * const __CopyTuple__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register BOOL __CopyTuple__re __asm("d0"); \
  register const struct CardHandle * __CopyTuple_handle __asm("a1") = (_CopyTuple_handle); \
  register UBYTE * __CopyTuple_buffer __asm("a0") = (_CopyTuple_buffer); \
  register ULONG __CopyTuple_tuplecode __asm("d1") = (_CopyTuple_tuplecode); \
  register ULONG __CopyTuple_size __asm("d0") = (_CopyTuple_size); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__CopyTuple__re) \
  : "r"(__CopyTuple__bn), "r"(__CopyTuple_handle), "r"(__CopyTuple_buffer), "r"(__CopyTuple_tuplecode), "r"(__CopyTuple_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CopyTuple__re; \
  }); \
  _CopyTuple__re; \
})

#define DeviceTuple(tuple_data, storage) ({ \
  const UBYTE * _DeviceTuple_tuple_data = (tuple_data); \
  struct DeviceTData * _DeviceTuple_storage = (storage); \
  ULONG _DeviceTuple__re = \
  ({ \
  register struct Library * const __DeviceTuple__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register ULONG __DeviceTuple__re __asm("d0"); \
  register const UBYTE * __DeviceTuple_tuple_data __asm("a0") = (_DeviceTuple_tuple_data); \
  register struct DeviceTData * __DeviceTuple_storage __asm("a1") = (_DeviceTuple_storage); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__DeviceTuple__re) \
  : "r"(__DeviceTuple__bn), "r"(__DeviceTuple_tuple_data), "r"(__DeviceTuple_storage) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DeviceTuple__re; \
  }); \
  _DeviceTuple__re; \
})

#define IfAmigaXIP(handle) ({ \
  const struct CardHandle * _IfAmigaXIP_handle = (handle); \
  struct Resident * _IfAmigaXIP__re = \
  ({ \
  register struct Library * const __IfAmigaXIP__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register struct Resident * __IfAmigaXIP__re __asm("d0"); \
  register const struct CardHandle * __IfAmigaXIP_handle __asm("a2") = (_IfAmigaXIP_handle); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__IfAmigaXIP__re) \
  : "r"(__IfAmigaXIP__bn), "r"(__IfAmigaXIP_handle) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IfAmigaXIP__re; \
  }); \
  _IfAmigaXIP__re; \
})

#define CardForceChange() ({ \
  BOOL _CardForceChange__re = \
  ({ \
  register struct Library * const __CardForceChange__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register BOOL __CardForceChange__re __asm("d0"); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__CardForceChange__re) \
  : "r"(__CardForceChange__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CardForceChange__re; \
  }); \
  _CardForceChange__re; \
})

#define CardChangeCount() ({ \
  ULONG _CardChangeCount__re = \
  ({ \
  register struct Library * const __CardChangeCount__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register ULONG __CardChangeCount__re __asm("d0"); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__CardChangeCount__re) \
  : "r"(__CardChangeCount__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CardChangeCount__re; \
  }); \
  _CardChangeCount__re; \
})

#define CardInterface() ({ \
  ULONG _CardInterface__re = \
  ({ \
  register struct Library * const __CardInterface__bn __asm("a6") = (struct Library *) (CARDRES_BASE_NAME);\
  register ULONG __CardInterface__re __asm("d0"); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__CardInterface__re) \
  : "r"(__CardInterface__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CardInterface__re; \
  }); \
  _CardInterface__re; \
})

#endif /*  _INLINE_CARDRES_H  */
