#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_UTILITY_H
#define _INLINE_UTILITY_H

#ifndef CLIB_UTILITY_PROTOS_H
#define CLIB_UTILITY_PROTOS_H
#endif

#ifndef  EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  UTILITY_DATE_H
#include <utility/date.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef  UTILITY_NAME_H
#include <utility/name.h>
#endif
#ifndef  UTILITY_DATA_STRUCTURES_H
#include <utility/data_structures.h>
#endif
#ifndef  UTILITY_RANDOM_H
#include <utility/random.h>
#endif
#ifndef  UTILITY_MESSAGE_DIGEST_H
#include <utility/message_digest.h>
#endif

#ifndef UTILITY_BASE_NAME
#define UTILITY_BASE_NAME UtilityBase
#endif

#define FindTagItem(tagVal, tagList) ({ \
  Tag _FindTagItem_tagVal = (tagVal); \
  const struct TagItem * _FindTagItem_tagList = (tagList); \
  struct TagItem * _FindTagItem__re = \
  ({ \
  register struct Library * const __FindTagItem__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct TagItem * __FindTagItem__re __asm("d0"); \
  register Tag __FindTagItem_tagVal __asm("d0") = (_FindTagItem_tagVal); \
  register const struct TagItem * __FindTagItem_tagList __asm("a0") = (_FindTagItem_tagList); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__FindTagItem__re) \
  : "r"(__FindTagItem__bn), "r"(__FindTagItem_tagVal), "r"(__FindTagItem_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindTagItem__re; \
  }); \
  _FindTagItem__re; \
})

#define GetTagData(tagValue, defaultVal, tagList) ({ \
  Tag _GetTagData_tagValue = (tagValue); \
  ULONG _GetTagData_defaultVal = (defaultVal); \
  const struct TagItem * _GetTagData_tagList = (tagList); \
  ULONG _GetTagData__re = \
  ({ \
  register struct Library * const __GetTagData__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __GetTagData__re __asm("d0"); \
  register Tag __GetTagData_tagValue __asm("d0") = (_GetTagData_tagValue); \
  register ULONG __GetTagData_defaultVal __asm("d1") = (_GetTagData_defaultVal); \
  register const struct TagItem * __GetTagData_tagList __asm("a0") = (_GetTagData_tagList); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__GetTagData__re) \
  : "r"(__GetTagData__bn), "r"(__GetTagData_tagValue), "r"(__GetTagData_defaultVal), "r"(__GetTagData_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetTagData__re; \
  }); \
  _GetTagData__re; \
})

#define PackBoolTags(initialFlags, tagList, boolMap) ({ \
  ULONG _PackBoolTags_initialFlags = (initialFlags); \
  const struct TagItem * _PackBoolTags_tagList = (tagList); \
  const struct TagItem * _PackBoolTags_boolMap = (boolMap); \
  ULONG _PackBoolTags__re = \
  ({ \
  register struct Library * const __PackBoolTags__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __PackBoolTags__re __asm("d0"); \
  register ULONG __PackBoolTags_initialFlags __asm("d0") = (_PackBoolTags_initialFlags); \
  register const struct TagItem * __PackBoolTags_tagList __asm("a0") = (_PackBoolTags_tagList); \
  register const struct TagItem * __PackBoolTags_boolMap __asm("a1") = (_PackBoolTags_boolMap); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__PackBoolTags__re) \
  : "r"(__PackBoolTags__bn), "r"(__PackBoolTags_initialFlags), "r"(__PackBoolTags_tagList), "r"(__PackBoolTags_boolMap) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PackBoolTags__re; \
  }); \
  _PackBoolTags__re; \
})

#define NextTagItem(tagListPtr) ({ \
  struct TagItem ** _NextTagItem_tagListPtr = (tagListPtr); \
  struct TagItem * _NextTagItem__re = \
  ({ \
  register struct Library * const __NextTagItem__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct TagItem * __NextTagItem__re __asm("d0"); \
  register struct TagItem ** __NextTagItem_tagListPtr __asm("a0") = (_NextTagItem_tagListPtr); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__NextTagItem__re) \
  : "r"(__NextTagItem__bn), "r"(__NextTagItem_tagListPtr) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NextTagItem__re; \
  }); \
  _NextTagItem__re; \
})

#define FilterTagChanges(changeList, originalList, apply) ({ \
  struct TagItem * _FilterTagChanges_changeList = (changeList); \
  struct TagItem * _FilterTagChanges_originalList = (originalList); \
  ULONG _FilterTagChanges_apply = (apply); \
  { \
  register struct Library * const __FilterTagChanges__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct TagItem * __FilterTagChanges_changeList __asm("a0") = (_FilterTagChanges_changeList); \
  register struct TagItem * __FilterTagChanges_originalList __asm("a1") = (_FilterTagChanges_originalList); \
  register ULONG __FilterTagChanges_apply __asm("d0") = (_FilterTagChanges_apply); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__FilterTagChanges__bn), "r"(__FilterTagChanges_changeList), "r"(__FilterTagChanges_originalList), "r"(__FilterTagChanges_apply) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define MapTags(tagList, mapList, mapType) ({ \
  struct TagItem * _MapTags_tagList = (tagList); \
  const struct TagItem * _MapTags_mapList = (mapList); \
  ULONG _MapTags_mapType = (mapType); \
  { \
  register struct Library * const __MapTags__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct TagItem * __MapTags_tagList __asm("a0") = (_MapTags_tagList); \
  register const struct TagItem * __MapTags_mapList __asm("a1") = (_MapTags_mapList); \
  register ULONG __MapTags_mapType __asm("d0") = (_MapTags_mapType); \
  __asm volatile ("jsr a6@(-60:W)" \
  : \
  : "r"(__MapTags__bn), "r"(__MapTags_tagList), "r"(__MapTags_mapList), "r"(__MapTags_mapType) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AllocateTagItems(numTags) ({ \
  ULONG _AllocateTagItems_numTags = (numTags); \
  struct TagItem * _AllocateTagItems__re = \
  ({ \
  register struct Library * const __AllocateTagItems__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct TagItem * __AllocateTagItems__re __asm("d0"); \
  register ULONG __AllocateTagItems_numTags __asm("d0") = (_AllocateTagItems_numTags); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__AllocateTagItems__re) \
  : "r"(__AllocateTagItems__bn), "r"(__AllocateTagItems_numTags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocateTagItems__re; \
  }); \
  _AllocateTagItems__re; \
})

#define CloneTagItems(tagList) ({ \
  const struct TagItem * _CloneTagItems_tagList = (tagList); \
  struct TagItem * _CloneTagItems__re = \
  ({ \
  register struct Library * const __CloneTagItems__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct TagItem * __CloneTagItems__re __asm("d0"); \
  register const struct TagItem * __CloneTagItems_tagList __asm("a0") = (_CloneTagItems_tagList); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__CloneTagItems__re) \
  : "r"(__CloneTagItems__bn), "r"(__CloneTagItems_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CloneTagItems__re; \
  }); \
  _CloneTagItems__re; \
})

#define FreeTagItems(tagList) ({ \
  struct TagItem * _FreeTagItems_tagList = (tagList); \
  { \
  register struct Library * const __FreeTagItems__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct TagItem * __FreeTagItems_tagList __asm("a0") = (_FreeTagItems_tagList); \
  __asm volatile ("jsr a6@(-78:W)" \
  : \
  : "r"(__FreeTagItems__bn), "r"(__FreeTagItems_tagList) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RefreshTagItemClones(clone, original) ({ \
  struct TagItem * _RefreshTagItemClones_clone = (clone); \
  const struct TagItem * _RefreshTagItemClones_original = (original); \
  { \
  register struct Library * const __RefreshTagItemClones__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct TagItem * __RefreshTagItemClones_clone __asm("a0") = (_RefreshTagItemClones_clone); \
  register const struct TagItem * __RefreshTagItemClones_original __asm("a1") = (_RefreshTagItemClones_original); \
  __asm volatile ("jsr a6@(-84:W)" \
  : \
  : "r"(__RefreshTagItemClones__bn), "r"(__RefreshTagItemClones_clone), "r"(__RefreshTagItemClones_original) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define TagInArray(tagValue, tagArray) ({ \
  Tag _TagInArray_tagValue = (tagValue); \
  const Tag * _TagInArray_tagArray = (tagArray); \
  BOOL _TagInArray__re = \
  ({ \
  register struct Library * const __TagInArray__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register BOOL __TagInArray__re __asm("d0"); \
  register Tag __TagInArray_tagValue __asm("d0") = (_TagInArray_tagValue); \
  register const Tag * __TagInArray_tagArray __asm("a0") = (_TagInArray_tagArray); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__TagInArray__re) \
  : "r"(__TagInArray__bn), "r"(__TagInArray_tagValue), "r"(__TagInArray_tagArray) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __TagInArray__re; \
  }); \
  _TagInArray__re; \
})

#define FilterTagItems(tagList, filterArray, logic) ({ \
  struct TagItem * _FilterTagItems_tagList = (tagList); \
  const Tag * _FilterTagItems_filterArray = (filterArray); \
  ULONG _FilterTagItems_logic = (logic); \
  ULONG _FilterTagItems__re = \
  ({ \
  register struct Library * const __FilterTagItems__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __FilterTagItems__re __asm("d0"); \
  register struct TagItem * __FilterTagItems_tagList __asm("a0") = (_FilterTagItems_tagList); \
  register const Tag * __FilterTagItems_filterArray __asm("a1") = (_FilterTagItems_filterArray); \
  register ULONG __FilterTagItems_logic __asm("d0") = (_FilterTagItems_logic); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__FilterTagItems__re) \
  : "r"(__FilterTagItems__bn), "r"(__FilterTagItems_tagList), "r"(__FilterTagItems_filterArray), "r"(__FilterTagItems_logic) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FilterTagItems__re; \
  }); \
  _FilterTagItems__re; \
})

#define CallHookPkt(hook, object, paramPacket) ({ \
  struct Hook * _CallHookPkt_hook = (hook); \
  APTR _CallHookPkt_object = (object); \
  APTR _CallHookPkt_paramPacket = (paramPacket); \
  ULONG _CallHookPkt__re = \
  ({ \
  register struct Library * const __CallHookPkt__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __CallHookPkt__re __asm("d0"); \
  register struct Hook * __CallHookPkt_hook __asm("a0") = (_CallHookPkt_hook); \
  register APTR __CallHookPkt_object __asm("a2") = (_CallHookPkt_object); \
  register APTR __CallHookPkt_paramPacket __asm("a1") = (_CallHookPkt_paramPacket); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__CallHookPkt__re) \
  : "r"(__CallHookPkt__bn), "r"(__CallHookPkt_hook), "r"(__CallHookPkt_object), "r"(__CallHookPkt_paramPacket) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CallHookPkt__re; \
  }); \
  _CallHookPkt__re; \
})

#define Amiga2Date(seconds, result) ({ \
  ULONG _Amiga2Date_seconds = (seconds); \
  struct ClockData * _Amiga2Date_result = (result); \
  { \
  register struct Library * const __Amiga2Date__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __Amiga2Date_seconds __asm("d0") = (_Amiga2Date_seconds); \
  register struct ClockData * __Amiga2Date_result __asm("a0") = (_Amiga2Date_result); \
  __asm volatile ("jsr a6@(-120:W)" \
  : \
  : "r"(__Amiga2Date__bn), "r"(__Amiga2Date_seconds), "r"(__Amiga2Date_result) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define Date2Amiga(date) ({ \
  const struct ClockData * _Date2Amiga_date = (date); \
  ULONG _Date2Amiga__re = \
  ({ \
  register struct Library * const __Date2Amiga__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __Date2Amiga__re __asm("d0"); \
  register const struct ClockData * __Date2Amiga_date __asm("a0") = (_Date2Amiga_date); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__Date2Amiga__re) \
  : "r"(__Date2Amiga__bn), "r"(__Date2Amiga_date) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Date2Amiga__re; \
  }); \
  _Date2Amiga__re; \
})

#define CheckDate(date) ({ \
  const struct ClockData * _CheckDate_date = (date); \
  ULONG _CheckDate__re = \
  ({ \
  register struct Library * const __CheckDate__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __CheckDate__re __asm("d0"); \
  register const struct ClockData * __CheckDate_date __asm("a0") = (_CheckDate_date); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__CheckDate__re) \
  : "r"(__CheckDate__bn), "r"(__CheckDate_date) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CheckDate__re; \
  }); \
  _CheckDate__re; \
})

#define SMult32(arg1, arg2) ({ \
  LONG _SMult32_arg1 = (arg1); \
  LONG _SMult32_arg2 = (arg2); \
  LONG _SMult32__re = \
  ({ \
  register struct Library * const __SMult32__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __SMult32__re __asm("d0"); \
  register LONG __SMult32_arg1 __asm("d0") = (_SMult32_arg1); \
  register LONG __SMult32_arg2 __asm("d1") = (_SMult32_arg2); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__SMult32__re) \
  : "r"(__SMult32__bn), "r"(__SMult32_arg1), "r"(__SMult32_arg2) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SMult32__re; \
  }); \
  _SMult32__re; \
})

#define UMult32(arg1, arg2) ({ \
  ULONG _UMult32_arg1 = (arg1); \
  ULONG _UMult32_arg2 = (arg2); \
  ULONG _UMult32__re = \
  ({ \
  register struct Library * const __UMult32__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __UMult32__re __asm("d0"); \
  register ULONG __UMult32_arg1 __asm("d0") = (_UMult32_arg1); \
  register ULONG __UMult32_arg2 __asm("d1") = (_UMult32_arg2); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__UMult32__re) \
  : "r"(__UMult32__bn), "r"(__UMult32_arg1), "r"(__UMult32_arg2) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __UMult32__re; \
  }); \
  _UMult32__re; \
})

#define SDivMod32(dividend, divisor) ({ \
  LONG _SDivMod32_dividend = (dividend); \
  LONG _SDivMod32_divisor = (divisor); \
  LONG _SDivMod32__re = \
  ({ \
  register struct Library * const __SDivMod32__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __SDivMod32__re __asm("d0"); \
  register LONG __SDivMod32_dividend __asm("d0") = (_SDivMod32_dividend); \
  register LONG __SDivMod32_divisor __asm("d1") = (_SDivMod32_divisor); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__SDivMod32__re) \
  : "r"(__SDivMod32__bn), "r"(__SDivMod32_dividend), "r"(__SDivMod32_divisor) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SDivMod32__re; \
  }); \
  _SDivMod32__re; \
})

#define UDivMod32(dividend, divisor) ({ \
  ULONG _UDivMod32_dividend = (dividend); \
  ULONG _UDivMod32_divisor = (divisor); \
  ULONG _UDivMod32__re = \
  ({ \
  register struct Library * const __UDivMod32__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __UDivMod32__re __asm("d0"); \
  register ULONG __UDivMod32_dividend __asm("d0") = (_UDivMod32_dividend); \
  register ULONG __UDivMod32_divisor __asm("d1") = (_UDivMod32_divisor); \
  __asm volatile ("jsr a6@(-156:W)" \
  : "=r"(__UDivMod32__re) \
  : "r"(__UDivMod32__bn), "r"(__UDivMod32_dividend), "r"(__UDivMod32_divisor) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __UDivMod32__re; \
  }); \
  _UDivMod32__re; \
})

#define Stricmp(string1, string2) ({ \
  CONST_STRPTR _Stricmp_string1 = (string1); \
  CONST_STRPTR _Stricmp_string2 = (string2); \
  LONG _Stricmp__re = \
  ({ \
  register struct Library * const __Stricmp__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __Stricmp__re __asm("d0"); \
  register CONST_STRPTR __Stricmp_string1 __asm("a0") = (_Stricmp_string1); \
  register CONST_STRPTR __Stricmp_string2 __asm("a1") = (_Stricmp_string2); \
  __asm volatile ("jsr a6@(-162:W)" \
  : "=r"(__Stricmp__re) \
  : "r"(__Stricmp__bn), "r"(__Stricmp_string1), "r"(__Stricmp_string2) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Stricmp__re; \
  }); \
  _Stricmp__re; \
})

#define Strnicmp(string1, string2, length) ({ \
  CONST_STRPTR _Strnicmp_string1 = (string1); \
  CONST_STRPTR _Strnicmp_string2 = (string2); \
  LONG _Strnicmp_length = (length); \
  LONG _Strnicmp__re = \
  ({ \
  register struct Library * const __Strnicmp__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __Strnicmp__re __asm("d0"); \
  register CONST_STRPTR __Strnicmp_string1 __asm("a0") = (_Strnicmp_string1); \
  register CONST_STRPTR __Strnicmp_string2 __asm("a1") = (_Strnicmp_string2); \
  register LONG __Strnicmp_length __asm("d0") = (_Strnicmp_length); \
  __asm volatile ("jsr a6@(-168:W)" \
  : "=r"(__Strnicmp__re) \
  : "r"(__Strnicmp__bn), "r"(__Strnicmp_string1), "r"(__Strnicmp_string2), "r"(__Strnicmp_length) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Strnicmp__re; \
  }); \
  _Strnicmp__re; \
})

#define ToUpper(character) ({ \
  ULONG _ToUpper_character = (character); \
  TEXT _ToUpper__re = \
  ({ \
  register struct Library * const __ToUpper__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register TEXT __ToUpper__re __asm("d0"); \
  register ULONG __ToUpper_character __asm("d0") = (_ToUpper_character); \
  __asm volatile ("jsr a6@(-174:W)" \
  : "=r"(__ToUpper__re) \
  : "r"(__ToUpper__bn), "r"(__ToUpper_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ToUpper__re; \
  }); \
  _ToUpper__re; \
})

#define ToLower(character) ({ \
  ULONG _ToLower_character = (character); \
  TEXT _ToLower__re = \
  ({ \
  register struct Library * const __ToLower__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register TEXT __ToLower__re __asm("d0"); \
  register ULONG __ToLower_character __asm("d0") = (_ToLower_character); \
  __asm volatile ("jsr a6@(-180:W)" \
  : "=r"(__ToLower__re) \
  : "r"(__ToLower__bn), "r"(__ToLower_character) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ToLower__re; \
  }); \
  _ToLower__re; \
})

#define ApplyTagChanges(list, changeList) ({ \
  struct TagItem * _ApplyTagChanges_list = (list); \
  const struct TagItem * _ApplyTagChanges_changeList = (changeList); \
  { \
  register struct Library * const __ApplyTagChanges__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct TagItem * __ApplyTagChanges_list __asm("a0") = (_ApplyTagChanges_list); \
  register const struct TagItem * __ApplyTagChanges_changeList __asm("a1") = (_ApplyTagChanges_changeList); \
  __asm volatile ("jsr a6@(-186:W)" \
  : \
  : "r"(__ApplyTagChanges__bn), "r"(__ApplyTagChanges_list), "r"(__ApplyTagChanges_changeList) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SMult64(arg1, arg2) ({ \
  LONG _SMult64_arg1 = (arg1); \
  LONG _SMult64_arg2 = (arg2); \
  LONG _SMult64__re = \
  ({ \
  register struct Library * const __SMult64__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __SMult64__re __asm("d0"); \
  register LONG __SMult64_arg1 __asm("d0") = (_SMult64_arg1); \
  register LONG __SMult64_arg2 __asm("d1") = (_SMult64_arg2); \
  __asm volatile ("jsr a6@(-198:W)" \
  : "=r"(__SMult64__re) \
  : "r"(__SMult64__bn), "r"(__SMult64_arg1), "r"(__SMult64_arg2) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SMult64__re; \
  }); \
  _SMult64__re; \
})

#define UMult64(arg1, arg2) ({ \
  ULONG _UMult64_arg1 = (arg1); \
  ULONG _UMult64_arg2 = (arg2); \
  ULONG _UMult64__re = \
  ({ \
  register struct Library * const __UMult64__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __UMult64__re __asm("d0"); \
  register ULONG __UMult64_arg1 __asm("d0") = (_UMult64_arg1); \
  register ULONG __UMult64_arg2 __asm("d1") = (_UMult64_arg2); \
  __asm volatile ("jsr a6@(-204:W)" \
  : "=r"(__UMult64__re) \
  : "r"(__UMult64__bn), "r"(__UMult64_arg1), "r"(__UMult64_arg2) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __UMult64__re; \
  }); \
  _UMult64__re; \
})

#define PackStructureTags(pack, packTable, tagList) ({ \
  APTR _PackStructureTags_pack = (pack); \
  const ULONG * _PackStructureTags_packTable = (packTable); \
  const struct TagItem * _PackStructureTags_tagList = (tagList); \
  ULONG _PackStructureTags__re = \
  ({ \
  register struct Library * const __PackStructureTags__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __PackStructureTags__re __asm("d0"); \
  register APTR __PackStructureTags_pack __asm("a0") = (_PackStructureTags_pack); \
  register const ULONG * __PackStructureTags_packTable __asm("a1") = (_PackStructureTags_packTable); \
  register const struct TagItem * __PackStructureTags_tagList __asm("a2") = (_PackStructureTags_tagList); \
  __asm volatile ("jsr a6@(-210:W)" \
  : "=r"(__PackStructureTags__re) \
  : "r"(__PackStructureTags__bn), "r"(__PackStructureTags_pack), "r"(__PackStructureTags_packTable), "r"(__PackStructureTags_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PackStructureTags__re; \
  }); \
  _PackStructureTags__re; \
})

#define UnpackStructureTags(pack, packTable, tagList) ({ \
  CONST_APTR _UnpackStructureTags_pack = (pack); \
  const ULONG * _UnpackStructureTags_packTable = (packTable); \
  struct TagItem * _UnpackStructureTags_tagList = (tagList); \
  ULONG _UnpackStructureTags__re = \
  ({ \
  register struct Library * const __UnpackStructureTags__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __UnpackStructureTags__re __asm("d0"); \
  register CONST_APTR __UnpackStructureTags_pack __asm("a0") = (_UnpackStructureTags_pack); \
  register const ULONG * __UnpackStructureTags_packTable __asm("a1") = (_UnpackStructureTags_packTable); \
  register struct TagItem * __UnpackStructureTags_tagList __asm("a2") = (_UnpackStructureTags_tagList); \
  __asm volatile ("jsr a6@(-216:W)" \
  : "=r"(__UnpackStructureTags__re) \
  : "r"(__UnpackStructureTags__bn), "r"(__UnpackStructureTags_pack), "r"(__UnpackStructureTags_packTable), "r"(__UnpackStructureTags_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __UnpackStructureTags__re; \
  }); \
  _UnpackStructureTags__re; \
})

#define AddNamedObject(nameSpace, object) ({ \
  struct NamedObject * _AddNamedObject_nameSpace = (nameSpace); \
  struct NamedObject * _AddNamedObject_object = (object); \
  BOOL _AddNamedObject__re = \
  ({ \
  register struct Library * const __AddNamedObject__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register BOOL __AddNamedObject__re __asm("d0"); \
  register struct NamedObject * __AddNamedObject_nameSpace __asm("a0") = (_AddNamedObject_nameSpace); \
  register struct NamedObject * __AddNamedObject_object __asm("a1") = (_AddNamedObject_object); \
  __asm volatile ("jsr a6@(-222:W)" \
  : "=r"(__AddNamedObject__re) \
  : "r"(__AddNamedObject__bn), "r"(__AddNamedObject_nameSpace), "r"(__AddNamedObject_object) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddNamedObject__re; \
  }); \
  _AddNamedObject__re; \
})

#define AllocNamedObjectA(name, tagList) ({ \
  CONST_STRPTR _AllocNamedObjectA_name = (name); \
  const struct TagItem * _AllocNamedObjectA_tagList = (tagList); \
  struct NamedObject * _AllocNamedObjectA__re = \
  ({ \
  register struct Library * const __AllocNamedObjectA__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct NamedObject * __AllocNamedObjectA__re __asm("d0"); \
  register CONST_STRPTR __AllocNamedObjectA_name __asm("a0") = (_AllocNamedObjectA_name); \
  register const struct TagItem * __AllocNamedObjectA_tagList __asm("a1") = (_AllocNamedObjectA_tagList); \
  __asm volatile ("jsr a6@(-228:W)" \
  : "=r"(__AllocNamedObjectA__re) \
  : "r"(__AllocNamedObjectA__bn), "r"(__AllocNamedObjectA_name), "r"(__AllocNamedObjectA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocNamedObjectA__re; \
  }); \
  _AllocNamedObjectA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct NamedObject * ___AllocNamedObject(struct Library * UtilityBase, CONST_STRPTR name, Tag tagList, ...)
{
  return AllocNamedObjectA(name, (const struct TagItem *) &tagList);
}

#define AllocNamedObject(name...) ___AllocNamedObject(UTILITY_BASE_NAME, name)
#endif

#define AttemptRemNamedObject(object) ({ \
  struct NamedObject * _AttemptRemNamedObject_object = (object); \
  LONG _AttemptRemNamedObject__re = \
  ({ \
  register struct Library * const __AttemptRemNamedObject__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __AttemptRemNamedObject__re __asm("d0"); \
  register struct NamedObject * __AttemptRemNamedObject_object __asm("a0") = (_AttemptRemNamedObject_object); \
  __asm volatile ("jsr a6@(-234:W)" \
  : "=r"(__AttemptRemNamedObject__re) \
  : "r"(__AttemptRemNamedObject__bn), "r"(__AttemptRemNamedObject_object) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AttemptRemNamedObject__re; \
  }); \
  _AttemptRemNamedObject__re; \
})

#define FindNamedObject(nameSpace, name, lastObject) ({ \
  struct NamedObject * _FindNamedObject_nameSpace = (nameSpace); \
  CONST_STRPTR _FindNamedObject_name = (name); \
  struct NamedObject * _FindNamedObject_lastObject = (lastObject); \
  struct NamedObject * _FindNamedObject__re = \
  ({ \
  register struct Library * const __FindNamedObject__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct NamedObject * __FindNamedObject__re __asm("d0"); \
  register struct NamedObject * __FindNamedObject_nameSpace __asm("a0") = (_FindNamedObject_nameSpace); \
  register CONST_STRPTR __FindNamedObject_name __asm("a1") = (_FindNamedObject_name); \
  register struct NamedObject * __FindNamedObject_lastObject __asm("a2") = (_FindNamedObject_lastObject); \
  __asm volatile ("jsr a6@(-240:W)" \
  : "=r"(__FindNamedObject__re) \
  : "r"(__FindNamedObject__bn), "r"(__FindNamedObject_nameSpace), "r"(__FindNamedObject_name), "r"(__FindNamedObject_lastObject) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindNamedObject__re; \
  }); \
  _FindNamedObject__re; \
})

#define FreeNamedObject(object) ({ \
  struct NamedObject * _FreeNamedObject_object = (object); \
  { \
  register struct Library * const __FreeNamedObject__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct NamedObject * __FreeNamedObject_object __asm("a0") = (_FreeNamedObject_object); \
  __asm volatile ("jsr a6@(-246:W)" \
  : \
  : "r"(__FreeNamedObject__bn), "r"(__FreeNamedObject_object) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define NamedObjectName(object) ({ \
  struct NamedObject * _NamedObjectName_object = (object); \
  STRPTR _NamedObjectName__re = \
  ({ \
  register struct Library * const __NamedObjectName__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register STRPTR __NamedObjectName__re __asm("d0"); \
  register struct NamedObject * __NamedObjectName_object __asm("a0") = (_NamedObjectName_object); \
  __asm volatile ("jsr a6@(-252:W)" \
  : "=r"(__NamedObjectName__re) \
  : "r"(__NamedObjectName__bn), "r"(__NamedObjectName_object) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NamedObjectName__re; \
  }); \
  _NamedObjectName__re; \
})

#define ReleaseNamedObject(object) ({ \
  struct NamedObject * _ReleaseNamedObject_object = (object); \
  { \
  register struct Library * const __ReleaseNamedObject__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct NamedObject * __ReleaseNamedObject_object __asm("a0") = (_ReleaseNamedObject_object); \
  __asm volatile ("jsr a6@(-258:W)" \
  : \
  : "r"(__ReleaseNamedObject__bn), "r"(__ReleaseNamedObject_object) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define RemNamedObject(object, message) ({ \
  struct NamedObject * _RemNamedObject_object = (object); \
  struct Message * _RemNamedObject_message = (message); \
  { \
  register struct Library * const __RemNamedObject__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct NamedObject * __RemNamedObject_object __asm("a0") = (_RemNamedObject_object); \
  register struct Message * __RemNamedObject_message __asm("a1") = (_RemNamedObject_message); \
  __asm volatile ("jsr a6@(-264:W)" \
  : \
  : "r"(__RemNamedObject__bn), "r"(__RemNamedObject_object), "r"(__RemNamedObject_message) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetUniqueID() ({ \
  ULONG _GetUniqueID__re = \
  ({ \
  register struct Library * const __GetUniqueID__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register ULONG __GetUniqueID__re __asm("d0"); \
  __asm volatile ("jsr a6@(-270:W)" \
  : "=r"(__GetUniqueID__re) \
  : "r"(__GetUniqueID__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetUniqueID__re; \
  }); \
  _GetUniqueID__re; \
})

#define Strlcpy(destination, source, size) ({ \
  STRPTR _Strlcpy_destination = (destination); \
  CONST_STRPTR _Strlcpy_source = (source); \
  LONG _Strlcpy_size = (size); \
  LONG _Strlcpy__re = \
  ({ \
  register struct Library * const __Strlcpy__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __Strlcpy__re __asm("d0"); \
  register STRPTR __Strlcpy_destination __asm("a0") = (_Strlcpy_destination); \
  register CONST_STRPTR __Strlcpy_source __asm("a1") = (_Strlcpy_source); \
  register LONG __Strlcpy_size __asm("d0") = (_Strlcpy_size); \
  __asm volatile ("jsr a6@(-300:W)" \
  : "=r"(__Strlcpy__re) \
  : "r"(__Strlcpy__bn), "r"(__Strlcpy_destination), "r"(__Strlcpy_source), "r"(__Strlcpy_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Strlcpy__re; \
  }); \
  _Strlcpy__re; \
})

#define Strlcat(destination, source, size) ({ \
  STRPTR _Strlcat_destination = (destination); \
  CONST_STRPTR _Strlcat_source = (source); \
  LONG _Strlcat_size = (size); \
  LONG _Strlcat__re = \
  ({ \
  register struct Library * const __Strlcat__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __Strlcat__re __asm("d0"); \
  register STRPTR __Strlcat_destination __asm("a0") = (_Strlcat_destination); \
  register CONST_STRPTR __Strlcat_source __asm("a1") = (_Strlcat_source); \
  register LONG __Strlcat_size __asm("d0") = (_Strlcat_size); \
  __asm volatile ("jsr a6@(-306:W)" \
  : "=r"(__Strlcat__re) \
  : "r"(__Strlcat__bn), "r"(__Strlcat_destination), "r"(__Strlcat_source), "r"(__Strlcat_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Strlcat__re; \
  }); \
  _Strlcat__re; \
})

#define VSNPrintf(buffer, buffer_size, format, args) ({ \
  STRPTR _VSNPrintf_buffer = (buffer); \
  LONG _VSNPrintf_buffer_size = (buffer_size); \
  CONST_STRPTR _VSNPrintf_format = (format); \
  APTR _VSNPrintf_args = (args); \
  LONG _VSNPrintf__re = \
  ({ \
  register struct Library * const __VSNPrintf__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __VSNPrintf__re __asm("d0"); \
  register STRPTR __VSNPrintf_buffer __asm("a0") = (_VSNPrintf_buffer); \
  register LONG __VSNPrintf_buffer_size __asm("d0") = (_VSNPrintf_buffer_size); \
  register CONST_STRPTR __VSNPrintf_format __asm("a1") = (_VSNPrintf_format); \
  register APTR __VSNPrintf_args __asm("a2") = (_VSNPrintf_args); \
  __asm volatile ("jsr a6@(-312:W)" \
  : "=r"(__VSNPrintf__re) \
  : "r"(__VSNPrintf__bn), "r"(__VSNPrintf_buffer), "r"(__VSNPrintf_buffer_size), "r"(__VSNPrintf_format), "r"(__VSNPrintf_args) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __VSNPrintf__re; \
  }); \
  _VSNPrintf__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SNPrintf(struct Library * UtilityBase, STRPTR buffer, LONG buffer_size, CONST_STRPTR format, ...)
{
  return VSNPrintf(buffer, buffer_size, format, (APTR) ((ULONG) &format + sizeof(CONST_STRPTR)));
}

#define SNPrintf(buffer, buffer_size, format...) ___SNPrintf(UTILITY_BASE_NAME, buffer, buffer_size, format)
#endif

#define VASPrintf(format, args) ({ \
  CONST_STRPTR _VASPrintf_format = (format); \
  APTR _VASPrintf_args = (args); \
  STRPTR _VASPrintf__re = \
  ({ \
  register struct Library * const __VASPrintf__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register STRPTR __VASPrintf__re __asm("d0"); \
  register CONST_STRPTR __VASPrintf_format __asm("a0") = (_VASPrintf_format); \
  register APTR __VASPrintf_args __asm("a1") = (_VASPrintf_args); \
  __asm volatile ("jsr a6@(-318:W)" \
  : "=r"(__VASPrintf__re) \
  : "r"(__VASPrintf__bn), "r"(__VASPrintf_format), "r"(__VASPrintf_args) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __VASPrintf__re; \
  }); \
  _VASPrintf__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ STRPTR ___ASPrintf(struct Library * UtilityBase, CONST_STRPTR format, ...)
{
  return VASPrintf(format, (APTR) ((ULONG) &format + sizeof(CONST_STRPTR)));
}

#define ASPrintf(format...) ___ASPrintf(UTILITY_BASE_NAME, format)
#endif

#define CreateSkipList(hook, max_levels) ({ \
  struct Hook * _CreateSkipList_hook = (hook); \
  LONG _CreateSkipList_max_levels = (max_levels); \
  struct SkipList * _CreateSkipList__re = \
  ({ \
  register struct Library * const __CreateSkipList__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct SkipList * __CreateSkipList__re __asm("d0"); \
  register struct Hook * __CreateSkipList_hook __asm("a0") = (_CreateSkipList_hook); \
  register LONG __CreateSkipList_max_levels __asm("d0") = (_CreateSkipList_max_levels); \
  __asm volatile ("jsr a6@(-324:W)" \
  : "=r"(__CreateSkipList__re) \
  : "r"(__CreateSkipList__bn), "r"(__CreateSkipList_hook), "r"(__CreateSkipList_max_levels) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateSkipList__re; \
  }); \
  _CreateSkipList__re; \
})

#define DeleteSkipList(list) ({ \
  struct SkipList * _DeleteSkipList_list = (list); \
  { \
  register struct Library * const __DeleteSkipList__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct SkipList * __DeleteSkipList_list __asm("a0") = (_DeleteSkipList_list); \
  __asm volatile ("jsr a6@(-330:W)" \
  : \
  : "r"(__DeleteSkipList__bn), "r"(__DeleteSkipList_list) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define InsertSkipNode(list, key, data_size) ({ \
  struct SkipList * _InsertSkipNode_list = (list); \
  APTR _InsertSkipNode_key = (key); \
  ULONG _InsertSkipNode_data_size = (data_size); \
  struct SkipNode * _InsertSkipNode__re = \
  ({ \
  register struct Library * const __InsertSkipNode__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct SkipNode * __InsertSkipNode__re __asm("d0"); \
  register struct SkipList * __InsertSkipNode_list __asm("a0") = (_InsertSkipNode_list); \
  register APTR __InsertSkipNode_key __asm("a1") = (_InsertSkipNode_key); \
  register ULONG __InsertSkipNode_data_size __asm("d0") = (_InsertSkipNode_data_size); \
  __asm volatile ("jsr a6@(-336:W)" \
  : "=r"(__InsertSkipNode__re) \
  : "r"(__InsertSkipNode__bn), "r"(__InsertSkipNode_list), "r"(__InsertSkipNode_key), "r"(__InsertSkipNode_data_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __InsertSkipNode__re; \
  }); \
  _InsertSkipNode__re; \
})

#define FindSkipNode(list, key) ({ \
  const struct SkipList * _FindSkipNode_list = (list); \
  APTR _FindSkipNode_key = (key); \
  struct SkipNode * _FindSkipNode__re = \
  ({ \
  register struct Library * const __FindSkipNode__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct SkipNode * __FindSkipNode__re __asm("d0"); \
  register const struct SkipList * __FindSkipNode_list __asm("a0") = (_FindSkipNode_list); \
  register APTR __FindSkipNode_key __asm("a1") = (_FindSkipNode_key); \
  __asm volatile ("jsr a6@(-342:W)" \
  : "=r"(__FindSkipNode__re) \
  : "r"(__FindSkipNode__bn), "r"(__FindSkipNode_list), "r"(__FindSkipNode_key) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindSkipNode__re; \
  }); \
  _FindSkipNode__re; \
})

#define RemoveSkipNode(list, key) ({ \
  struct SkipList * _RemoveSkipNode_list = (list); \
  APTR _RemoveSkipNode_key = (key); \
  LONG _RemoveSkipNode__re = \
  ({ \
  register struct Library * const __RemoveSkipNode__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __RemoveSkipNode__re __asm("d0"); \
  register struct SkipList * __RemoveSkipNode_list __asm("a0") = (_RemoveSkipNode_list); \
  register APTR __RemoveSkipNode_key __asm("a1") = (_RemoveSkipNode_key); \
  __asm volatile ("jsr a6@(-348:W)" \
  : "=r"(__RemoveSkipNode__re) \
  : "r"(__RemoveSkipNode__bn), "r"(__RemoveSkipNode_list), "r"(__RemoveSkipNode_key) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoveSkipNode__re; \
  }); \
  _RemoveSkipNode__re; \
})

#define GetFirstSkipNode(list) ({ \
  const struct SkipList * _GetFirstSkipNode_list = (list); \
  struct SkipNode * _GetFirstSkipNode__re = \
  ({ \
  register struct Library * const __GetFirstSkipNode__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct SkipNode * __GetFirstSkipNode__re __asm("d0"); \
  register const struct SkipList * __GetFirstSkipNode_list __asm("a0") = (_GetFirstSkipNode_list); \
  __asm volatile ("jsr a6@(-354:W)" \
  : "=r"(__GetFirstSkipNode__re) \
  : "r"(__GetFirstSkipNode__bn), "r"(__GetFirstSkipNode_list) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetFirstSkipNode__re; \
  }); \
  _GetFirstSkipNode__re; \
})

#define GetNextSkipNode(list, node) ({ \
  const struct SkipList * _GetNextSkipNode_list = (list); \
  const struct SkipNode * _GetNextSkipNode_node = (node); \
  struct SkipNode * _GetNextSkipNode__re = \
  ({ \
  register struct Library * const __GetNextSkipNode__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct SkipNode * __GetNextSkipNode__re __asm("d0"); \
  register const struct SkipList * __GetNextSkipNode_list __asm("a0") = (_GetNextSkipNode_list); \
  register const struct SkipNode * __GetNextSkipNode_node __asm("a1") = (_GetNextSkipNode_node); \
  __asm volatile ("jsr a6@(-360:W)" \
  : "=r"(__GetNextSkipNode__re) \
  : "r"(__GetNextSkipNode__bn), "r"(__GetNextSkipNode_list), "r"(__GetNextSkipNode_node) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetNextSkipNode__re; \
  }); \
  _GetNextSkipNode__re; \
})

#define CreateSplayTree(hook) ({ \
  struct Hook * _CreateSplayTree_hook = (hook); \
  struct SplayTree * _CreateSplayTree__re = \
  ({ \
  register struct Library * const __CreateSplayTree__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct SplayTree * __CreateSplayTree__re __asm("d0"); \
  register struct Hook * __CreateSplayTree_hook __asm("a0") = (_CreateSplayTree_hook); \
  __asm volatile ("jsr a6@(-366:W)" \
  : "=r"(__CreateSplayTree__re) \
  : "r"(__CreateSplayTree__bn), "r"(__CreateSplayTree_hook) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateSplayTree__re; \
  }); \
  _CreateSplayTree__re; \
})

#define DeleteSplayTree(st) ({ \
  struct SplayTree * _DeleteSplayTree_st = (st); \
  { \
  register struct Library * const __DeleteSplayTree__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct SplayTree * __DeleteSplayTree_st __asm("a0") = (_DeleteSplayTree_st); \
  __asm volatile ("jsr a6@(-372:W)" \
  : \
  : "r"(__DeleteSplayTree__bn), "r"(__DeleteSplayTree_st) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define InsertSplayNode(tree, key, data_size) ({ \
  struct SplayTree * _InsertSplayNode_tree = (tree); \
  APTR _InsertSplayNode_key = (key); \
  ULONG _InsertSplayNode_data_size = (data_size); \
  struct SplayNode * _InsertSplayNode__re = \
  ({ \
  register struct Library * const __InsertSplayNode__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct SplayNode * __InsertSplayNode__re __asm("d0"); \
  register struct SplayTree * __InsertSplayNode_tree __asm("a0") = (_InsertSplayNode_tree); \
  register APTR __InsertSplayNode_key __asm("a1") = (_InsertSplayNode_key); \
  register ULONG __InsertSplayNode_data_size __asm("d0") = (_InsertSplayNode_data_size); \
  __asm volatile ("jsr a6@(-378:W)" \
  : "=r"(__InsertSplayNode__re) \
  : "r"(__InsertSplayNode__bn), "r"(__InsertSplayNode_tree), "r"(__InsertSplayNode_key), "r"(__InsertSplayNode_data_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __InsertSplayNode__re; \
  }); \
  _InsertSplayNode__re; \
})

#define FindSplayNode(tree, key) ({ \
  const struct SplayTree * _FindSplayNode_tree = (tree); \
  APTR _FindSplayNode_key = (key); \
  struct SplayNode * _FindSplayNode__re = \
  ({ \
  register struct Library * const __FindSplayNode__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct SplayNode * __FindSplayNode__re __asm("d0"); \
  register const struct SplayTree * __FindSplayNode_tree __asm("a0") = (_FindSplayNode_tree); \
  register APTR __FindSplayNode_key __asm("a1") = (_FindSplayNode_key); \
  __asm volatile ("jsr a6@(-384:W)" \
  : "=r"(__FindSplayNode__re) \
  : "r"(__FindSplayNode__bn), "r"(__FindSplayNode_tree), "r"(__FindSplayNode_key) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindSplayNode__re; \
  }); \
  _FindSplayNode__re; \
})

#define RemoveSplayNode(tree, key) ({ \
  struct SplayTree * _RemoveSplayNode_tree = (tree); \
  APTR _RemoveSplayNode_key = (key); \
  LONG _RemoveSplayNode__re = \
  ({ \
  register struct Library * const __RemoveSplayNode__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __RemoveSplayNode__re __asm("d0"); \
  register struct SplayTree * __RemoveSplayNode_tree __asm("a0") = (_RemoveSplayNode_tree); \
  register APTR __RemoveSplayNode_key __asm("a1") = (_RemoveSplayNode_key); \
  __asm volatile ("jsr a6@(-390:W)" \
  : "=r"(__RemoveSplayNode__re) \
  : "r"(__RemoveSplayNode__bn), "r"(__RemoveSplayNode_tree), "r"(__RemoveSplayNode_key) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoveSplayNode__re; \
  }); \
  _RemoveSplayNode__re; \
})

#define SetMem(destination, c, length) ({ \
  APTR _SetMem_destination = (destination); \
  ULONG _SetMem_c = (c); \
  LONG _SetMem_length = (length); \
  APTR _SetMem__re = \
  ({ \
  register struct Library * const __SetMem__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register APTR __SetMem__re __asm("d0"); \
  register APTR __SetMem_destination __asm("a0") = (_SetMem_destination); \
  register ULONG __SetMem_c __asm("d0") = (_SetMem_c); \
  register LONG __SetMem_length __asm("d1") = (_SetMem_length); \
  __asm volatile ("jsr a6@(-396:W)" \
  : "=r"(__SetMem__re) \
  : "r"(__SetMem__bn), "r"(__SetMem_destination), "r"(__SetMem_c), "r"(__SetMem_length) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetMem__re; \
  }); \
  _SetMem__re; \
})

#define FindNameNC(list, name) ({ \
  struct List * _FindNameNC_list = (list); \
  CONST_STRPTR _FindNameNC_name = (name); \
  struct Node * _FindNameNC__re = \
  ({ \
  register struct Library * const __FindNameNC__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct Node * __FindNameNC__re __asm("d0"); \
  register struct List * __FindNameNC_list __asm("a0") = (_FindNameNC_list); \
  register CONST_STRPTR __FindNameNC_name __asm("a1") = (_FindNameNC_name); \
  __asm volatile ("jsr a6@(-402:W)" \
  : "=r"(__FindNameNC__re) \
  : "r"(__FindNameNC__bn), "r"(__FindNameNC_list), "r"(__FindNameNC_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindNameNC__re; \
  }); \
  _FindNameNC__re; \
})

#define Random(state) ({ \
  struct RandomState * _Random_state = (state); \
  LONG _Random__re = \
  ({ \
  register struct Library * const __Random__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register LONG __Random__re __asm("d0"); \
  register struct RandomState * __Random_state __asm("a0") = (_Random_state); \
  __asm volatile ("jsr a6@(-408:W)" \
  : "=r"(__Random__re) \
  : "r"(__Random__bn), "r"(__Random_state) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __Random__re; \
  }); \
  _Random__re; \
})

#define MessageDigest_SHA_Init(mdsha) ({ \
  struct MessageDigest_SHA * _MessageDigest_SHA_Init_mdsha = (mdsha); \
  { \
  register struct Library * const __MessageDigest_SHA_Init__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct MessageDigest_SHA * __MessageDigest_SHA_Init_mdsha __asm("a0") = (_MessageDigest_SHA_Init_mdsha); \
  __asm volatile ("jsr a6@(-414:W)" \
  : \
  : "r"(__MessageDigest_SHA_Init__bn), "r"(__MessageDigest_SHA_Init_mdsha) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define MessageDigest_SHA_Update(mdsha, data, num_bytes) ({ \
  struct MessageDigest_SHA * _MessageDigest_SHA_Update_mdsha = (mdsha); \
  APTR _MessageDigest_SHA_Update_data = (data); \
  LONG _MessageDigest_SHA_Update_num_bytes = (num_bytes); \
  { \
  register struct Library * const __MessageDigest_SHA_Update__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct MessageDigest_SHA * __MessageDigest_SHA_Update_mdsha __asm("a0") = (_MessageDigest_SHA_Update_mdsha); \
  register APTR __MessageDigest_SHA_Update_data __asm("a1") = (_MessageDigest_SHA_Update_data); \
  register LONG __MessageDigest_SHA_Update_num_bytes __asm("d0") = (_MessageDigest_SHA_Update_num_bytes); \
  __asm volatile ("jsr a6@(-420:W)" \
  : \
  : "r"(__MessageDigest_SHA_Update__bn), "r"(__MessageDigest_SHA_Update_mdsha), "r"(__MessageDigest_SHA_Update_data), "r"(__MessageDigest_SHA_Update_num_bytes) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define MessageDigest_SHA_Final(mdsha) ({ \
  struct MessageDigest_SHA * _MessageDigest_SHA_Final_mdsha = (mdsha); \
  { \
  register struct Library * const __MessageDigest_SHA_Final__bn __asm("a6") = (struct Library *) (UTILITY_BASE_NAME);\
  register struct MessageDigest_SHA * __MessageDigest_SHA_Final_mdsha __asm("a0") = (_MessageDigest_SHA_Final_mdsha); \
  __asm volatile ("jsr a6@(-426:W)" \
  : \
  : "r"(__MessageDigest_SHA_Final__bn), "r"(__MessageDigest_SHA_Final_mdsha) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_UTILITY_H  */
