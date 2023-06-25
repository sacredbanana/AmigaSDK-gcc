#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_NONVOLATILE_H
#define _INLINE_NONVOLATILE_H

#ifndef CLIB_NONVOLATILE_PROTOS_H
#define CLIB_NONVOLATILE_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_LISTS_H
#include <exec/lists.h>
#endif
#ifndef  LIBRARIES_NONVOLATILE_H
#include <libraries/nonvolatile.h>
#endif

#ifndef NONVOLATILE_BASE_NAME
#define NONVOLATILE_BASE_NAME NVBase
#endif

#define GetCopyNV(appName, itemName, killRequesters) ({ \
  CONST_STRPTR _GetCopyNV_appName = (appName); \
  CONST_STRPTR _GetCopyNV_itemName = (itemName); \
  LONG _GetCopyNV_killRequesters = (killRequesters); \
  APTR _GetCopyNV__re = \
  ({ \
  register struct Library * const __GetCopyNV__bn __asm("a6") = (struct Library *) (NONVOLATILE_BASE_NAME);\
  register APTR __GetCopyNV__re __asm("d0"); \
  register CONST_STRPTR __GetCopyNV_appName __asm("a0") = (_GetCopyNV_appName); \
  register CONST_STRPTR __GetCopyNV_itemName __asm("a1") = (_GetCopyNV_itemName); \
  register LONG __GetCopyNV_killRequesters __asm("d1") = (_GetCopyNV_killRequesters); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__GetCopyNV__re) \
  : "r"(__GetCopyNV__bn), "r"(__GetCopyNV_appName), "r"(__GetCopyNV_itemName), "r"(__GetCopyNV_killRequesters) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetCopyNV__re; \
  }); \
  _GetCopyNV__re; \
})

#define FreeNVData(data) ({ \
  APTR _FreeNVData_data = (data); \
  { \
  register struct Library * const __FreeNVData__bn __asm("a6") = (struct Library *) (NONVOLATILE_BASE_NAME);\
  register APTR __FreeNVData_data __asm("a0") = (_FreeNVData_data); \
  __asm volatile ("jsr a6@(-36:W)" \
  : \
  : "r"(__FreeNVData__bn), "r"(__FreeNVData_data) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define StoreNV(appName, itemName, data, length, killRequesters) ({ \
  CONST_STRPTR _StoreNV_appName = (appName); \
  CONST_STRPTR _StoreNV_itemName = (itemName); \
  const APTR _StoreNV_data = (data); \
  ULONG _StoreNV_length = (length); \
  LONG _StoreNV_killRequesters = (killRequesters); \
  UWORD _StoreNV__re = \
  ({ \
  register struct Library * const __StoreNV__bn __asm("a6") = (struct Library *) (NONVOLATILE_BASE_NAME);\
  register UWORD __StoreNV__re __asm("d0"); \
  register CONST_STRPTR __StoreNV_appName __asm("a0") = (_StoreNV_appName); \
  register CONST_STRPTR __StoreNV_itemName __asm("a1") = (_StoreNV_itemName); \
  register const APTR __StoreNV_data __asm("a2") = (_StoreNV_data); \
  register ULONG __StoreNV_length __asm("d0") = (_StoreNV_length); \
  register LONG __StoreNV_killRequesters __asm("d1") = (_StoreNV_killRequesters); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__StoreNV__re) \
  : "r"(__StoreNV__bn), "r"(__StoreNV_appName), "r"(__StoreNV_itemName), "r"(__StoreNV_data), "r"(__StoreNV_length), "r"(__StoreNV_killRequesters) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __StoreNV__re; \
  }); \
  _StoreNV__re; \
})

#define DeleteNV(appName, itemName, killRequesters) ({ \
  CONST_STRPTR _DeleteNV_appName = (appName); \
  CONST_STRPTR _DeleteNV_itemName = (itemName); \
  LONG _DeleteNV_killRequesters = (killRequesters); \
  BOOL _DeleteNV__re = \
  ({ \
  register struct Library * const __DeleteNV__bn __asm("a6") = (struct Library *) (NONVOLATILE_BASE_NAME);\
  register BOOL __DeleteNV__re __asm("d0"); \
  register CONST_STRPTR __DeleteNV_appName __asm("a0") = (_DeleteNV_appName); \
  register CONST_STRPTR __DeleteNV_itemName __asm("a1") = (_DeleteNV_itemName); \
  register LONG __DeleteNV_killRequesters __asm("d1") = (_DeleteNV_killRequesters); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__DeleteNV__re) \
  : "r"(__DeleteNV__bn), "r"(__DeleteNV_appName), "r"(__DeleteNV_itemName), "r"(__DeleteNV_killRequesters) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DeleteNV__re; \
  }); \
  _DeleteNV__re; \
})

#define GetNVInfo(killRequesters) ({ \
  LONG _GetNVInfo_killRequesters = (killRequesters); \
  struct NVInfo * _GetNVInfo__re = \
  ({ \
  register struct Library * const __GetNVInfo__bn __asm("a6") = (struct Library *) (NONVOLATILE_BASE_NAME);\
  register struct NVInfo * __GetNVInfo__re __asm("d0"); \
  register LONG __GetNVInfo_killRequesters __asm("d1") = (_GetNVInfo_killRequesters); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__GetNVInfo__re) \
  : "r"(__GetNVInfo__bn), "r"(__GetNVInfo_killRequesters) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetNVInfo__re; \
  }); \
  _GetNVInfo__re; \
})

#define GetNVList(appName, killRequesters) ({ \
  CONST_STRPTR _GetNVList_appName = (appName); \
  LONG _GetNVList_killRequesters = (killRequesters); \
  struct MinList * _GetNVList__re = \
  ({ \
  register struct Library * const __GetNVList__bn __asm("a6") = (struct Library *) (NONVOLATILE_BASE_NAME);\
  register struct MinList * __GetNVList__re __asm("d0"); \
  register CONST_STRPTR __GetNVList_appName __asm("a0") = (_GetNVList_appName); \
  register LONG __GetNVList_killRequesters __asm("d1") = (_GetNVList_killRequesters); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__GetNVList__re) \
  : "r"(__GetNVList__bn), "r"(__GetNVList_appName), "r"(__GetNVList_killRequesters) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetNVList__re; \
  }); \
  _GetNVList__re; \
})

#define SetNVProtection(appName, itemName, mask, killRequesters) ({ \
  CONST_STRPTR _SetNVProtection_appName = (appName); \
  CONST_STRPTR _SetNVProtection_itemName = (itemName); \
  LONG _SetNVProtection_mask = (mask); \
  LONG _SetNVProtection_killRequesters = (killRequesters); \
  BOOL _SetNVProtection__re = \
  ({ \
  register struct Library * const __SetNVProtection__bn __asm("a6") = (struct Library *) (NONVOLATILE_BASE_NAME);\
  register BOOL __SetNVProtection__re __asm("d0"); \
  register CONST_STRPTR __SetNVProtection_appName __asm("a0") = (_SetNVProtection_appName); \
  register CONST_STRPTR __SetNVProtection_itemName __asm("a1") = (_SetNVProtection_itemName); \
  register LONG __SetNVProtection_mask __asm("d2") = (_SetNVProtection_mask); \
  register LONG __SetNVProtection_killRequesters __asm("d1") = (_SetNVProtection_killRequesters); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__SetNVProtection__re) \
  : "r"(__SetNVProtection__bn), "r"(__SetNVProtection_appName), "r"(__SetNVProtection_itemName), "r"(__SetNVProtection_mask), "r"(__SetNVProtection_killRequesters) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetNVProtection__re; \
  }); \
  _SetNVProtection__re; \
})

#endif /*  _INLINE_NONVOLATILE_H  */
