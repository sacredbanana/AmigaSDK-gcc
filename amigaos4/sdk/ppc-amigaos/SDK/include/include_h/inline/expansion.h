#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_EXPANSION_H
#define _INLINE_EXPANSION_H

#ifndef CLIB_EXPANSION_PROTOS_H
#define CLIB_EXPANSION_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  LIBRARIES_CONFIGVARS_H
#include <libraries/configvars.h>
#endif
#ifndef  DOS_FILEHANDLER_H
#include <dos/filehandler.h>
#endif

#ifndef EXPANSION_BASE_NAME
#define EXPANSION_BASE_NAME ExpansionBase
#endif

#define AddConfigDev(configDev) ({ \
  struct ConfigDev * _AddConfigDev_configDev = (configDev); \
  { \
  register struct ExpansionBase * const __AddConfigDev__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register struct ConfigDev * __AddConfigDev_configDev __asm("a0") = (_AddConfigDev_configDev); \
  __asm volatile ("jsr a6@(-30:W)" \
  : \
  : "r"(__AddConfigDev__bn), "r"(__AddConfigDev_configDev) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AddBootNode(bootPri, flags, deviceNode, configDev) ({ \
  LONG _AddBootNode_bootPri = (bootPri); \
  ULONG _AddBootNode_flags = (flags); \
  struct DeviceNode * _AddBootNode_deviceNode = (deviceNode); \
  struct ConfigDev * _AddBootNode_configDev = (configDev); \
  BOOL _AddBootNode__re = \
  ({ \
  register struct ExpansionBase * const __AddBootNode__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register BOOL __AddBootNode__re __asm("d0"); \
  register LONG __AddBootNode_bootPri __asm("d0") = (_AddBootNode_bootPri); \
  register ULONG __AddBootNode_flags __asm("d1") = (_AddBootNode_flags); \
  register struct DeviceNode * __AddBootNode_deviceNode __asm("a0") = (_AddBootNode_deviceNode); \
  register struct ConfigDev * __AddBootNode_configDev __asm("a1") = (_AddBootNode_configDev); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__AddBootNode__re) \
  : "r"(__AddBootNode__bn), "r"(__AddBootNode_bootPri), "r"(__AddBootNode_flags), "r"(__AddBootNode_deviceNode), "r"(__AddBootNode_configDev) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddBootNode__re; \
  }); \
  _AddBootNode__re; \
})

#define AllocBoardMem(slotSpec) ({ \
  ULONG _AllocBoardMem_slotSpec = (slotSpec); \
  { \
  register struct ExpansionBase * const __AllocBoardMem__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register ULONG __AllocBoardMem_slotSpec __asm("d0") = (_AllocBoardMem_slotSpec); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__AllocBoardMem__bn), "r"(__AllocBoardMem_slotSpec) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AllocConfigDev() ({ \
  struct ConfigDev * _AllocConfigDev__re = \
  ({ \
  register struct ExpansionBase * const __AllocConfigDev__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register struct ConfigDev * __AllocConfigDev__re __asm("d0"); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__AllocConfigDev__re) \
  : "r"(__AllocConfigDev__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocConfigDev__re; \
  }); \
  _AllocConfigDev__re; \
})

#define AllocExpansionMem(numSlots, slotAlign) ({ \
  ULONG _AllocExpansionMem_numSlots = (numSlots); \
  ULONG _AllocExpansionMem_slotAlign = (slotAlign); \
  APTR _AllocExpansionMem__re = \
  ({ \
  register struct ExpansionBase * const __AllocExpansionMem__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register APTR __AllocExpansionMem__re __asm("d0"); \
  register ULONG __AllocExpansionMem_numSlots __asm("d0") = (_AllocExpansionMem_numSlots); \
  register ULONG __AllocExpansionMem_slotAlign __asm("d1") = (_AllocExpansionMem_slotAlign); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__AllocExpansionMem__re) \
  : "r"(__AllocExpansionMem__bn), "r"(__AllocExpansionMem_numSlots), "r"(__AllocExpansionMem_slotAlign) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocExpansionMem__re; \
  }); \
  _AllocExpansionMem__re; \
})

#define ConfigBoard(board, configDev) ({ \
  APTR _ConfigBoard_board = (board); \
  struct ConfigDev * _ConfigBoard_configDev = (configDev); \
  { \
  register struct ExpansionBase * const __ConfigBoard__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register APTR __ConfigBoard_board __asm("a0") = (_ConfigBoard_board); \
  register struct ConfigDev * __ConfigBoard_configDev __asm("a1") = (_ConfigBoard_configDev); \
  __asm volatile ("jsr a6@(-60:W)" \
  : \
  : "r"(__ConfigBoard__bn), "r"(__ConfigBoard_board), "r"(__ConfigBoard_configDev) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ConfigChain(baseAddr) ({ \
  APTR _ConfigChain_baseAddr = (baseAddr); \
  { \
  register struct ExpansionBase * const __ConfigChain__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register APTR __ConfigChain_baseAddr __asm("a0") = (_ConfigChain_baseAddr); \
  __asm volatile ("jsr a6@(-66:W)" \
  : \
  : "r"(__ConfigChain__bn), "r"(__ConfigChain_baseAddr) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FindConfigDev(oldConfigDev, manufacturer, product) ({ \
  const struct ConfigDev * _FindConfigDev_oldConfigDev = (oldConfigDev); \
  LONG _FindConfigDev_manufacturer = (manufacturer); \
  LONG _FindConfigDev_product = (product); \
  struct ConfigDev * _FindConfigDev__re = \
  ({ \
  register struct ExpansionBase * const __FindConfigDev__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register struct ConfigDev * __FindConfigDev__re __asm("d0"); \
  register const struct ConfigDev * __FindConfigDev_oldConfigDev __asm("a0") = (_FindConfigDev_oldConfigDev); \
  register LONG __FindConfigDev_manufacturer __asm("d0") = (_FindConfigDev_manufacturer); \
  register LONG __FindConfigDev_product __asm("d1") = (_FindConfigDev_product); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__FindConfigDev__re) \
  : "r"(__FindConfigDev__bn), "r"(__FindConfigDev_oldConfigDev), "r"(__FindConfigDev_manufacturer), "r"(__FindConfigDev_product) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindConfigDev__re; \
  }); \
  _FindConfigDev__re; \
})

#define FreeBoardMem(startSlot, slotSpec) ({ \
  ULONG _FreeBoardMem_startSlot = (startSlot); \
  ULONG _FreeBoardMem_slotSpec = (slotSpec); \
  { \
  register struct ExpansionBase * const __FreeBoardMem__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register ULONG __FreeBoardMem_startSlot __asm("d0") = (_FreeBoardMem_startSlot); \
  register ULONG __FreeBoardMem_slotSpec __asm("d1") = (_FreeBoardMem_slotSpec); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__FreeBoardMem__bn), "r"(__FreeBoardMem_startSlot), "r"(__FreeBoardMem_slotSpec) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FreeConfigDev(configDev) ({ \
  struct ConfigDev * _FreeConfigDev_configDev = (configDev); \
  { \
  register struct ExpansionBase * const __FreeConfigDev__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register struct ConfigDev * __FreeConfigDev_configDev __asm("a0") = (_FreeConfigDev_configDev); \
  __asm volatile ("jsr a6@(-84:W)" \
  : \
  : "r"(__FreeConfigDev__bn), "r"(__FreeConfigDev_configDev) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FreeExpansionMem(startSlot, numSlots) ({ \
  ULONG _FreeExpansionMem_startSlot = (startSlot); \
  ULONG _FreeExpansionMem_numSlots = (numSlots); \
  { \
  register struct ExpansionBase * const __FreeExpansionMem__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register ULONG __FreeExpansionMem_startSlot __asm("d0") = (_FreeExpansionMem_startSlot); \
  register ULONG __FreeExpansionMem_numSlots __asm("d1") = (_FreeExpansionMem_numSlots); \
  __asm volatile ("jsr a6@(-90:W)" \
  : \
  : "r"(__FreeExpansionMem__bn), "r"(__FreeExpansionMem_startSlot), "r"(__FreeExpansionMem_numSlots) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ReadExpansionByte(board, offset) ({ \
  const APTR _ReadExpansionByte_board = (board); \
  ULONG _ReadExpansionByte_offset = (offset); \
  UBYTE _ReadExpansionByte__re = \
  ({ \
  register struct ExpansionBase * const __ReadExpansionByte__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register UBYTE __ReadExpansionByte__re __asm("d0"); \
  register const APTR __ReadExpansionByte_board __asm("a0") = (_ReadExpansionByte_board); \
  register ULONG __ReadExpansionByte_offset __asm("d0") = (_ReadExpansionByte_offset); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__ReadExpansionByte__re) \
  : "r"(__ReadExpansionByte__bn), "r"(__ReadExpansionByte_board), "r"(__ReadExpansionByte_offset) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadExpansionByte__re; \
  }); \
  _ReadExpansionByte__re; \
})

#define ReadExpansionRom(board, configDev) ({ \
  const APTR _ReadExpansionRom_board = (board); \
  struct ConfigDev * _ReadExpansionRom_configDev = (configDev); \
  { \
  register struct ExpansionBase * const __ReadExpansionRom__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register const APTR __ReadExpansionRom_board __asm("a0") = (_ReadExpansionRom_board); \
  register struct ConfigDev * __ReadExpansionRom_configDev __asm("a1") = (_ReadExpansionRom_configDev); \
  __asm volatile ("jsr a6@(-102:W)" \
  : \
  : "r"(__ReadExpansionRom__bn), "r"(__ReadExpansionRom_board), "r"(__ReadExpansionRom_configDev) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemConfigDev(configDev) ({ \
  struct ConfigDev * _RemConfigDev_configDev = (configDev); \
  { \
  register struct ExpansionBase * const __RemConfigDev__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register struct ConfigDev * __RemConfigDev_configDev __asm("a0") = (_RemConfigDev_configDev); \
  __asm volatile ("jsr a6@(-108:W)" \
  : \
  : "r"(__RemConfigDev__bn), "r"(__RemConfigDev_configDev) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define WriteExpansionByte(board, offset, byte) ({ \
  APTR _WriteExpansionByte_board = (board); \
  ULONG _WriteExpansionByte_offset = (offset); \
  ULONG _WriteExpansionByte_byte = (byte); \
  { \
  register struct ExpansionBase * const __WriteExpansionByte__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register APTR __WriteExpansionByte_board __asm("a0") = (_WriteExpansionByte_board); \
  register ULONG __WriteExpansionByte_offset __asm("d0") = (_WriteExpansionByte_offset); \
  register ULONG __WriteExpansionByte_byte __asm("d1") = (_WriteExpansionByte_byte); \
  __asm volatile ("jsr a6@(-114:W)" \
  : \
  : "r"(__WriteExpansionByte__bn), "r"(__WriteExpansionByte_board), "r"(__WriteExpansionByte_offset), "r"(__WriteExpansionByte_byte) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ObtainConfigBinding() ({ \
  register struct ExpansionBase * const __ObtainConfigBinding__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  __asm volatile ("jsr a6@(-120:W)" \
  : \
  : "r"(__ObtainConfigBinding__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define ReleaseConfigBinding() ({ \
  register struct ExpansionBase * const __ReleaseConfigBinding__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  __asm volatile ("jsr a6@(-126:W)" \
  : \
  : "r"(__ReleaseConfigBinding__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define SetCurrentBinding(currentBinding, bindingSize) ({ \
  struct CurrentBinding * _SetCurrentBinding_currentBinding = (currentBinding); \
  ULONG _SetCurrentBinding_bindingSize = (bindingSize); \
  { \
  register struct ExpansionBase * const __SetCurrentBinding__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register struct CurrentBinding * __SetCurrentBinding_currentBinding __asm("a0") = (_SetCurrentBinding_currentBinding); \
  register ULONG __SetCurrentBinding_bindingSize __asm("d0") = (_SetCurrentBinding_bindingSize); \
  __asm volatile ("jsr a6@(-132:W)" \
  : \
  : "r"(__SetCurrentBinding__bn), "r"(__SetCurrentBinding_currentBinding), "r"(__SetCurrentBinding_bindingSize) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetCurrentBinding(currentBinding, bindingSize) ({ \
  const struct CurrentBinding * _GetCurrentBinding_currentBinding = (currentBinding); \
  ULONG _GetCurrentBinding_bindingSize = (bindingSize); \
  ULONG _GetCurrentBinding__re = \
  ({ \
  register struct ExpansionBase * const __GetCurrentBinding__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register ULONG __GetCurrentBinding__re __asm("d0"); \
  register const struct CurrentBinding * __GetCurrentBinding_currentBinding __asm("a0") = (_GetCurrentBinding_currentBinding); \
  register ULONG __GetCurrentBinding_bindingSize __asm("d0") = (_GetCurrentBinding_bindingSize); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__GetCurrentBinding__re) \
  : "r"(__GetCurrentBinding__bn), "r"(__GetCurrentBinding_currentBinding), "r"(__GetCurrentBinding_bindingSize) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetCurrentBinding__re; \
  }); \
  _GetCurrentBinding__re; \
})

#define MakeDosNode(parmPacket) ({ \
  const APTR _MakeDosNode_parmPacket = (parmPacket); \
  struct DeviceNode * _MakeDosNode__re = \
  ({ \
  register struct ExpansionBase * const __MakeDosNode__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register struct DeviceNode * __MakeDosNode__re __asm("d0"); \
  register const APTR __MakeDosNode_parmPacket __asm("a0") = (_MakeDosNode_parmPacket); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__MakeDosNode__re) \
  : "r"(__MakeDosNode__bn), "r"(__MakeDosNode_parmPacket) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __MakeDosNode__re; \
  }); \
  _MakeDosNode__re; \
})

#define AddDosNode(bootPri, flags, deviceNode) ({ \
  LONG _AddDosNode_bootPri = (bootPri); \
  ULONG _AddDosNode_flags = (flags); \
  struct DeviceNode * _AddDosNode_deviceNode = (deviceNode); \
  BOOL _AddDosNode__re = \
  ({ \
  register struct ExpansionBase * const __AddDosNode__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
  register BOOL __AddDosNode__re __asm("d0"); \
  register LONG __AddDosNode_bootPri __asm("d0") = (_AddDosNode_bootPri); \
  register ULONG __AddDosNode_flags __asm("d1") = (_AddDosNode_flags); \
  register struct DeviceNode * __AddDosNode_deviceNode __asm("a0") = (_AddDosNode_deviceNode); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__AddDosNode__re) \
  : "r"(__AddDosNode__bn), "r"(__AddDosNode_bootPri), "r"(__AddDosNode_flags), "r"(__AddDosNode_deviceNode) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddDosNode__re; \
  }); \
  _AddDosNode__re; \
})


#define GetMachineInfo(tagList) ({ \
  struct TagItem * _GetMachineInfo_tagList = (tagList); \
  { \
    register struct ExpansionBase * const __GetMachineInfo__bn __asm("a6") = (struct ExpansionBase *) (EXPANSION_BASE_NAME);\
    register struct TagItem *__GetMachineInfo_tagList __asm("a0") = (_GetMachineInfo_tagList); \
    __asm volatile ("jsr a6@(-168:W)" \
      : \
      : "r"(__GetMachineInfo__bn),  "r"(__GetMachineInfo_tagList) \
      : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_EXPANSION_H  */
