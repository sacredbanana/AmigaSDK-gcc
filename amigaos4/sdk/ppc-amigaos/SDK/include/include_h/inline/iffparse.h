#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_IFFPARSE_H
#define _INLINE_IFFPARSE_H

#ifndef CLIB_IFFPARSE_PROTOS_H
#define CLIB_IFFPARSE_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  LIBRARIES_IFFPARSE_H
#include <libraries/iffparse.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifndef IFFPARSE_BASE_NAME
#define IFFPARSE_BASE_NAME IFFParseBase
#endif

#define AllocIFF() ({ \
  struct IFFHandle * _AllocIFF__re = \
  ({ \
  register struct Library * const __AllocIFF__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct IFFHandle * __AllocIFF__re __asm("d0"); \
  __asm volatile ("jsr a6@(-30:W)" \
  : "=r"(__AllocIFF__re) \
  : "r"(__AllocIFF__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocIFF__re; \
  }); \
  _AllocIFF__re; \
})

#define OpenIFF(iff, rwMode) ({ \
  struct IFFHandle * _OpenIFF_iff = (iff); \
  LONG _OpenIFF_rwMode = (rwMode); \
  LONG _OpenIFF__re = \
  ({ \
  register struct Library * const __OpenIFF__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __OpenIFF__re __asm("d0"); \
  register struct IFFHandle * __OpenIFF_iff __asm("a0") = (_OpenIFF_iff); \
  register LONG __OpenIFF_rwMode __asm("d0") = (_OpenIFF_rwMode); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__OpenIFF__re) \
  : "r"(__OpenIFF__bn), "r"(__OpenIFF_iff), "r"(__OpenIFF_rwMode) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenIFF__re; \
  }); \
  _OpenIFF__re; \
})

#define ParseIFF(iff, control) ({ \
  struct IFFHandle * _ParseIFF_iff = (iff); \
  LONG _ParseIFF_control = (control); \
  LONG _ParseIFF__re = \
  ({ \
  register struct Library * const __ParseIFF__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __ParseIFF__re __asm("d0"); \
  register struct IFFHandle * __ParseIFF_iff __asm("a0") = (_ParseIFF_iff); \
  register LONG __ParseIFF_control __asm("d0") = (_ParseIFF_control); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__ParseIFF__re) \
  : "r"(__ParseIFF__bn), "r"(__ParseIFF_iff), "r"(__ParseIFF_control) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ParseIFF__re; \
  }); \
  _ParseIFF__re; \
})

#define CloseIFF(iff) ({ \
  struct IFFHandle * _CloseIFF_iff = (iff); \
  { \
  register struct Library * const __CloseIFF__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct IFFHandle * __CloseIFF_iff __asm("a0") = (_CloseIFF_iff); \
  __asm volatile ("jsr a6@(-48:W)" \
  : \
  : "r"(__CloseIFF__bn), "r"(__CloseIFF_iff) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FreeIFF(iff) ({ \
  struct IFFHandle * _FreeIFF_iff = (iff); \
  { \
  register struct Library * const __FreeIFF__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct IFFHandle * __FreeIFF_iff __asm("a0") = (_FreeIFF_iff); \
  __asm volatile ("jsr a6@(-54:W)" \
  : \
  : "r"(__FreeIFF__bn), "r"(__FreeIFF_iff) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ReadChunkBytes(iff, buf, numBytes) ({ \
  struct IFFHandle * _ReadChunkBytes_iff = (iff); \
  APTR _ReadChunkBytes_buf = (buf); \
  LONG _ReadChunkBytes_numBytes = (numBytes); \
  LONG _ReadChunkBytes__re = \
  ({ \
  register struct Library * const __ReadChunkBytes__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __ReadChunkBytes__re __asm("d0"); \
  register struct IFFHandle * __ReadChunkBytes_iff __asm("a0") = (_ReadChunkBytes_iff); \
  register APTR __ReadChunkBytes_buf __asm("a1") = (_ReadChunkBytes_buf); \
  register LONG __ReadChunkBytes_numBytes __asm("d0") = (_ReadChunkBytes_numBytes); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__ReadChunkBytes__re) \
  : "r"(__ReadChunkBytes__bn), "r"(__ReadChunkBytes_iff), "r"(__ReadChunkBytes_buf), "r"(__ReadChunkBytes_numBytes) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadChunkBytes__re; \
  }); \
  _ReadChunkBytes__re; \
})

#define WriteChunkBytes(iff, buf, numBytes) ({ \
  struct IFFHandle * _WriteChunkBytes_iff = (iff); \
  CONST_APTR _WriteChunkBytes_buf = (buf); \
  LONG _WriteChunkBytes_numBytes = (numBytes); \
  LONG _WriteChunkBytes__re = \
  ({ \
  register struct Library * const __WriteChunkBytes__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __WriteChunkBytes__re __asm("d0"); \
  register struct IFFHandle * __WriteChunkBytes_iff __asm("a0") = (_WriteChunkBytes_iff); \
  register CONST_APTR __WriteChunkBytes_buf __asm("a1") = (_WriteChunkBytes_buf); \
  register LONG __WriteChunkBytes_numBytes __asm("d0") = (_WriteChunkBytes_numBytes); \
  __asm volatile ("jsr a6@(-66:W)" \
  : "=r"(__WriteChunkBytes__re) \
  : "r"(__WriteChunkBytes__bn), "r"(__WriteChunkBytes_iff), "r"(__WriteChunkBytes_buf), "r"(__WriteChunkBytes_numBytes) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WriteChunkBytes__re; \
  }); \
  _WriteChunkBytes__re; \
})

#define ReadChunkRecords(iff, buf, bytesPerRecord, numRecords) ({ \
  struct IFFHandle * _ReadChunkRecords_iff = (iff); \
  APTR _ReadChunkRecords_buf = (buf); \
  LONG _ReadChunkRecords_bytesPerRecord = (bytesPerRecord); \
  LONG _ReadChunkRecords_numRecords = (numRecords); \
  LONG _ReadChunkRecords__re = \
  ({ \
  register struct Library * const __ReadChunkRecords__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __ReadChunkRecords__re __asm("d0"); \
  register struct IFFHandle * __ReadChunkRecords_iff __asm("a0") = (_ReadChunkRecords_iff); \
  register APTR __ReadChunkRecords_buf __asm("a1") = (_ReadChunkRecords_buf); \
  register LONG __ReadChunkRecords_bytesPerRecord __asm("d0") = (_ReadChunkRecords_bytesPerRecord); \
  register LONG __ReadChunkRecords_numRecords __asm("d1") = (_ReadChunkRecords_numRecords); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__ReadChunkRecords__re) \
  : "r"(__ReadChunkRecords__bn), "r"(__ReadChunkRecords_iff), "r"(__ReadChunkRecords_buf), "r"(__ReadChunkRecords_bytesPerRecord), "r"(__ReadChunkRecords_numRecords) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ReadChunkRecords__re; \
  }); \
  _ReadChunkRecords__re; \
})

#define WriteChunkRecords(iff, buf, bytesPerRecord, numRecords) ({ \
  struct IFFHandle * _WriteChunkRecords_iff = (iff); \
  CONST_APTR _WriteChunkRecords_buf = (buf); \
  LONG _WriteChunkRecords_bytesPerRecord = (bytesPerRecord); \
  LONG _WriteChunkRecords_numRecords = (numRecords); \
  LONG _WriteChunkRecords__re = \
  ({ \
  register struct Library * const __WriteChunkRecords__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __WriteChunkRecords__re __asm("d0"); \
  register struct IFFHandle * __WriteChunkRecords_iff __asm("a0") = (_WriteChunkRecords_iff); \
  register CONST_APTR __WriteChunkRecords_buf __asm("a1") = (_WriteChunkRecords_buf); \
  register LONG __WriteChunkRecords_bytesPerRecord __asm("d0") = (_WriteChunkRecords_bytesPerRecord); \
  register LONG __WriteChunkRecords_numRecords __asm("d1") = (_WriteChunkRecords_numRecords); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__WriteChunkRecords__re) \
  : "r"(__WriteChunkRecords__bn), "r"(__WriteChunkRecords_iff), "r"(__WriteChunkRecords_buf), "r"(__WriteChunkRecords_bytesPerRecord), "r"(__WriteChunkRecords_numRecords) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __WriteChunkRecords__re; \
  }); \
  _WriteChunkRecords__re; \
})

#define PushChunk(iff, type, id, size) ({ \
  struct IFFHandle * _PushChunk_iff = (iff); \
  LONG _PushChunk_type = (type); \
  LONG _PushChunk_id = (id); \
  LONG _PushChunk_size = (size); \
  LONG _PushChunk__re = \
  ({ \
  register struct Library * const __PushChunk__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __PushChunk__re __asm("d0"); \
  register struct IFFHandle * __PushChunk_iff __asm("a0") = (_PushChunk_iff); \
  register LONG __PushChunk_type __asm("d0") = (_PushChunk_type); \
  register LONG __PushChunk_id __asm("d1") = (_PushChunk_id); \
  register LONG __PushChunk_size __asm("d2") = (_PushChunk_size); \
  __asm volatile ("jsr a6@(-84:W)" \
  : "=r"(__PushChunk__re) \
  : "r"(__PushChunk__bn), "r"(__PushChunk_iff), "r"(__PushChunk_type), "r"(__PushChunk_id), "r"(__PushChunk_size) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PushChunk__re; \
  }); \
  _PushChunk__re; \
})

#define PopChunk(iff) ({ \
  struct IFFHandle * _PopChunk_iff = (iff); \
  LONG _PopChunk__re = \
  ({ \
  register struct Library * const __PopChunk__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __PopChunk__re __asm("d0"); \
  register struct IFFHandle * __PopChunk_iff __asm("a0") = (_PopChunk_iff); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__PopChunk__re) \
  : "r"(__PopChunk__bn), "r"(__PopChunk_iff) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PopChunk__re; \
  }); \
  _PopChunk__re; \
})

#define EntryHandler(iff, type, id, position, handler, object) ({ \
  struct IFFHandle * _EntryHandler_iff = (iff); \
  LONG _EntryHandler_type = (type); \
  LONG _EntryHandler_id = (id); \
  LONG _EntryHandler_position = (position); \
  struct Hook * _EntryHandler_handler = (handler); \
  APTR _EntryHandler_object = (object); \
  LONG _EntryHandler__re = \
  ({ \
  register struct Library * const __EntryHandler__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __EntryHandler__re __asm("d0"); \
  register struct IFFHandle * __EntryHandler_iff __asm("a0") = (_EntryHandler_iff); \
  register LONG __EntryHandler_type __asm("d0") = (_EntryHandler_type); \
  register LONG __EntryHandler_id __asm("d1") = (_EntryHandler_id); \
  register LONG __EntryHandler_position __asm("d2") = (_EntryHandler_position); \
  register struct Hook * __EntryHandler_handler __asm("a1") = (_EntryHandler_handler); \
  register APTR __EntryHandler_object __asm("a2") = (_EntryHandler_object); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__EntryHandler__re) \
  : "r"(__EntryHandler__bn), "r"(__EntryHandler_iff), "r"(__EntryHandler_type), "r"(__EntryHandler_id), "r"(__EntryHandler_position), "r"(__EntryHandler_handler), "r"(__EntryHandler_object) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __EntryHandler__re; \
  }); \
  _EntryHandler__re; \
})

#define ExitHandler(iff, type, id, position, handler, object) ({ \
  struct IFFHandle * _ExitHandler_iff = (iff); \
  LONG _ExitHandler_type = (type); \
  LONG _ExitHandler_id = (id); \
  LONG _ExitHandler_position = (position); \
  struct Hook * _ExitHandler_handler = (handler); \
  APTR _ExitHandler_object = (object); \
  LONG _ExitHandler__re = \
  ({ \
  register struct Library * const __ExitHandler__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __ExitHandler__re __asm("d0"); \
  register struct IFFHandle * __ExitHandler_iff __asm("a0") = (_ExitHandler_iff); \
  register LONG __ExitHandler_type __asm("d0") = (_ExitHandler_type); \
  register LONG __ExitHandler_id __asm("d1") = (_ExitHandler_id); \
  register LONG __ExitHandler_position __asm("d2") = (_ExitHandler_position); \
  register struct Hook * __ExitHandler_handler __asm("a1") = (_ExitHandler_handler); \
  register APTR __ExitHandler_object __asm("a2") = (_ExitHandler_object); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__ExitHandler__re) \
  : "r"(__ExitHandler__bn), "r"(__ExitHandler_iff), "r"(__ExitHandler_type), "r"(__ExitHandler_id), "r"(__ExitHandler_position), "r"(__ExitHandler_handler), "r"(__ExitHandler_object) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ExitHandler__re; \
  }); \
  _ExitHandler__re; \
})

#define PropChunk(iff, type, id) ({ \
  struct IFFHandle * _PropChunk_iff = (iff); \
  LONG _PropChunk_type = (type); \
  LONG _PropChunk_id = (id); \
  LONG _PropChunk__re = \
  ({ \
  register struct Library * const __PropChunk__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __PropChunk__re __asm("d0"); \
  register struct IFFHandle * __PropChunk_iff __asm("a0") = (_PropChunk_iff); \
  register LONG __PropChunk_type __asm("d0") = (_PropChunk_type); \
  register LONG __PropChunk_id __asm("d1") = (_PropChunk_id); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__PropChunk__re) \
  : "r"(__PropChunk__bn), "r"(__PropChunk_iff), "r"(__PropChunk_type), "r"(__PropChunk_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PropChunk__re; \
  }); \
  _PropChunk__re; \
})

#define PropChunks(iff, propArray, numPairs) ({ \
  struct IFFHandle * _PropChunks_iff = (iff); \
  const LONG * _PropChunks_propArray = (propArray); \
  LONG _PropChunks_numPairs = (numPairs); \
  LONG _PropChunks__re = \
  ({ \
  register struct Library * const __PropChunks__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __PropChunks__re __asm("d0"); \
  register struct IFFHandle * __PropChunks_iff __asm("a0") = (_PropChunks_iff); \
  register const LONG * __PropChunks_propArray __asm("a1") = (_PropChunks_propArray); \
  register LONG __PropChunks_numPairs __asm("d0") = (_PropChunks_numPairs); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__PropChunks__re) \
  : "r"(__PropChunks__bn), "r"(__PropChunks_iff), "r"(__PropChunks_propArray), "r"(__PropChunks_numPairs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PropChunks__re; \
  }); \
  _PropChunks__re; \
})

#define StopChunk(iff, type, id) ({ \
  struct IFFHandle * _StopChunk_iff = (iff); \
  LONG _StopChunk_type = (type); \
  LONG _StopChunk_id = (id); \
  LONG _StopChunk__re = \
  ({ \
  register struct Library * const __StopChunk__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __StopChunk__re __asm("d0"); \
  register struct IFFHandle * __StopChunk_iff __asm("a0") = (_StopChunk_iff); \
  register LONG __StopChunk_type __asm("d0") = (_StopChunk_type); \
  register LONG __StopChunk_id __asm("d1") = (_StopChunk_id); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__StopChunk__re) \
  : "r"(__StopChunk__bn), "r"(__StopChunk_iff), "r"(__StopChunk_type), "r"(__StopChunk_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __StopChunk__re; \
  }); \
  _StopChunk__re; \
})

#define StopChunks(iff, propArray, numPairs) ({ \
  struct IFFHandle * _StopChunks_iff = (iff); \
  const LONG * _StopChunks_propArray = (propArray); \
  LONG _StopChunks_numPairs = (numPairs); \
  LONG _StopChunks__re = \
  ({ \
  register struct Library * const __StopChunks__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __StopChunks__re __asm("d0"); \
  register struct IFFHandle * __StopChunks_iff __asm("a0") = (_StopChunks_iff); \
  register const LONG * __StopChunks_propArray __asm("a1") = (_StopChunks_propArray); \
  register LONG __StopChunks_numPairs __asm("d0") = (_StopChunks_numPairs); \
  __asm volatile ("jsr a6@(-132:W)" \
  : "=r"(__StopChunks__re) \
  : "r"(__StopChunks__bn), "r"(__StopChunks_iff), "r"(__StopChunks_propArray), "r"(__StopChunks_numPairs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __StopChunks__re; \
  }); \
  _StopChunks__re; \
})

#define CollectionChunk(iff, type, id) ({ \
  struct IFFHandle * _CollectionChunk_iff = (iff); \
  LONG _CollectionChunk_type = (type); \
  LONG _CollectionChunk_id = (id); \
  LONG _CollectionChunk__re = \
  ({ \
  register struct Library * const __CollectionChunk__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __CollectionChunk__re __asm("d0"); \
  register struct IFFHandle * __CollectionChunk_iff __asm("a0") = (_CollectionChunk_iff); \
  register LONG __CollectionChunk_type __asm("d0") = (_CollectionChunk_type); \
  register LONG __CollectionChunk_id __asm("d1") = (_CollectionChunk_id); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__CollectionChunk__re) \
  : "r"(__CollectionChunk__bn), "r"(__CollectionChunk_iff), "r"(__CollectionChunk_type), "r"(__CollectionChunk_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CollectionChunk__re; \
  }); \
  _CollectionChunk__re; \
})

#define CollectionChunks(iff, propArray, numPairs) ({ \
  struct IFFHandle * _CollectionChunks_iff = (iff); \
  const LONG * _CollectionChunks_propArray = (propArray); \
  LONG _CollectionChunks_numPairs = (numPairs); \
  LONG _CollectionChunks__re = \
  ({ \
  register struct Library * const __CollectionChunks__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __CollectionChunks__re __asm("d0"); \
  register struct IFFHandle * __CollectionChunks_iff __asm("a0") = (_CollectionChunks_iff); \
  register const LONG * __CollectionChunks_propArray __asm("a1") = (_CollectionChunks_propArray); \
  register LONG __CollectionChunks_numPairs __asm("d0") = (_CollectionChunks_numPairs); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__CollectionChunks__re) \
  : "r"(__CollectionChunks__bn), "r"(__CollectionChunks_iff), "r"(__CollectionChunks_propArray), "r"(__CollectionChunks_numPairs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CollectionChunks__re; \
  }); \
  _CollectionChunks__re; \
})

#define StopOnExit(iff, type, id) ({ \
  struct IFFHandle * _StopOnExit_iff = (iff); \
  LONG _StopOnExit_type = (type); \
  LONG _StopOnExit_id = (id); \
  LONG _StopOnExit__re = \
  ({ \
  register struct Library * const __StopOnExit__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __StopOnExit__re __asm("d0"); \
  register struct IFFHandle * __StopOnExit_iff __asm("a0") = (_StopOnExit_iff); \
  register LONG __StopOnExit_type __asm("d0") = (_StopOnExit_type); \
  register LONG __StopOnExit_id __asm("d1") = (_StopOnExit_id); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__StopOnExit__re) \
  : "r"(__StopOnExit__bn), "r"(__StopOnExit_iff), "r"(__StopOnExit_type), "r"(__StopOnExit_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __StopOnExit__re; \
  }); \
  _StopOnExit__re; \
})

#define FindProp(iff, type, id) ({ \
  const struct IFFHandle * _FindProp_iff = (iff); \
  LONG _FindProp_type = (type); \
  LONG _FindProp_id = (id); \
  struct StoredProperty * _FindProp__re = \
  ({ \
  register struct Library * const __FindProp__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct StoredProperty * __FindProp__re __asm("d0"); \
  register const struct IFFHandle * __FindProp_iff __asm("a0") = (_FindProp_iff); \
  register LONG __FindProp_type __asm("d0") = (_FindProp_type); \
  register LONG __FindProp_id __asm("d1") = (_FindProp_id); \
  __asm volatile ("jsr a6@(-156:W)" \
  : "=r"(__FindProp__re) \
  : "r"(__FindProp__bn), "r"(__FindProp_iff), "r"(__FindProp_type), "r"(__FindProp_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindProp__re; \
  }); \
  _FindProp__re; \
})

#define FindCollection(iff, type, id) ({ \
  const struct IFFHandle * _FindCollection_iff = (iff); \
  LONG _FindCollection_type = (type); \
  LONG _FindCollection_id = (id); \
  struct CollectionItem * _FindCollection__re = \
  ({ \
  register struct Library * const __FindCollection__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct CollectionItem * __FindCollection__re __asm("d0"); \
  register const struct IFFHandle * __FindCollection_iff __asm("a0") = (_FindCollection_iff); \
  register LONG __FindCollection_type __asm("d0") = (_FindCollection_type); \
  register LONG __FindCollection_id __asm("d1") = (_FindCollection_id); \
  __asm volatile ("jsr a6@(-162:W)" \
  : "=r"(__FindCollection__re) \
  : "r"(__FindCollection__bn), "r"(__FindCollection_iff), "r"(__FindCollection_type), "r"(__FindCollection_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindCollection__re; \
  }); \
  _FindCollection__re; \
})

#define FindPropContext(iff) ({ \
  const struct IFFHandle * _FindPropContext_iff = (iff); \
  struct ContextNode * _FindPropContext__re = \
  ({ \
  register struct Library * const __FindPropContext__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct ContextNode * __FindPropContext__re __asm("d0"); \
  register const struct IFFHandle * __FindPropContext_iff __asm("a0") = (_FindPropContext_iff); \
  __asm volatile ("jsr a6@(-168:W)" \
  : "=r"(__FindPropContext__re) \
  : "r"(__FindPropContext__bn), "r"(__FindPropContext_iff) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindPropContext__re; \
  }); \
  _FindPropContext__re; \
})

#define CurrentChunk(iff) ({ \
  const struct IFFHandle * _CurrentChunk_iff = (iff); \
  struct ContextNode * _CurrentChunk__re = \
  ({ \
  register struct Library * const __CurrentChunk__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct ContextNode * __CurrentChunk__re __asm("d0"); \
  register const struct IFFHandle * __CurrentChunk_iff __asm("a0") = (_CurrentChunk_iff); \
  __asm volatile ("jsr a6@(-174:W)" \
  : "=r"(__CurrentChunk__re) \
  : "r"(__CurrentChunk__bn), "r"(__CurrentChunk_iff) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CurrentChunk__re; \
  }); \
  _CurrentChunk__re; \
})

#define ParentChunk(contextNode) ({ \
  const struct ContextNode * _ParentChunk_contextNode = (contextNode); \
  struct ContextNode * _ParentChunk__re = \
  ({ \
  register struct Library * const __ParentChunk__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct ContextNode * __ParentChunk__re __asm("d0"); \
  register const struct ContextNode * __ParentChunk_contextNode __asm("a0") = (_ParentChunk_contextNode); \
  __asm volatile ("jsr a6@(-180:W)" \
  : "=r"(__ParentChunk__re) \
  : "r"(__ParentChunk__bn), "r"(__ParentChunk_contextNode) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __ParentChunk__re; \
  }); \
  _ParentChunk__re; \
})

#define AllocLocalItem(type, id, ident, dataSize) ({ \
  LONG _AllocLocalItem_type = (type); \
  LONG _AllocLocalItem_id = (id); \
  LONG _AllocLocalItem_ident = (ident); \
  LONG _AllocLocalItem_dataSize = (dataSize); \
  struct LocalContextItem * _AllocLocalItem__re = \
  ({ \
  register struct Library * const __AllocLocalItem__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct LocalContextItem * __AllocLocalItem__re __asm("d0"); \
  register LONG __AllocLocalItem_type __asm("d0") = (_AllocLocalItem_type); \
  register LONG __AllocLocalItem_id __asm("d1") = (_AllocLocalItem_id); \
  register LONG __AllocLocalItem_ident __asm("d2") = (_AllocLocalItem_ident); \
  register LONG __AllocLocalItem_dataSize __asm("d3") = (_AllocLocalItem_dataSize); \
  __asm volatile ("jsr a6@(-186:W)" \
  : "=r"(__AllocLocalItem__re) \
  : "r"(__AllocLocalItem__bn), "r"(__AllocLocalItem_type), "r"(__AllocLocalItem_id), "r"(__AllocLocalItem_ident), "r"(__AllocLocalItem_dataSize) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocLocalItem__re; \
  }); \
  _AllocLocalItem__re; \
})

#define LocalItemData(localItem) ({ \
  const struct LocalContextItem * _LocalItemData_localItem = (localItem); \
  APTR _LocalItemData__re = \
  ({ \
  register struct Library * const __LocalItemData__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register APTR __LocalItemData__re __asm("d0"); \
  register const struct LocalContextItem * __LocalItemData_localItem __asm("a0") = (_LocalItemData_localItem); \
  __asm volatile ("jsr a6@(-192:W)" \
  : "=r"(__LocalItemData__re) \
  : "r"(__LocalItemData__bn), "r"(__LocalItemData_localItem) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LocalItemData__re; \
  }); \
  _LocalItemData__re; \
})

#define SetLocalItemPurge(localItem, purgeHook) ({ \
  struct LocalContextItem * _SetLocalItemPurge_localItem = (localItem); \
  const struct Hook * _SetLocalItemPurge_purgeHook = (purgeHook); \
  { \
  register struct Library * const __SetLocalItemPurge__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct LocalContextItem * __SetLocalItemPurge_localItem __asm("a0") = (_SetLocalItemPurge_localItem); \
  register const struct Hook * __SetLocalItemPurge_purgeHook __asm("a1") = (_SetLocalItemPurge_purgeHook); \
  __asm volatile ("jsr a6@(-198:W)" \
  : \
  : "r"(__SetLocalItemPurge__bn), "r"(__SetLocalItemPurge_localItem), "r"(__SetLocalItemPurge_purgeHook) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FreeLocalItem(localItem) ({ \
  struct LocalContextItem * _FreeLocalItem_localItem = (localItem); \
  { \
  register struct Library * const __FreeLocalItem__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct LocalContextItem * __FreeLocalItem_localItem __asm("a0") = (_FreeLocalItem_localItem); \
  __asm volatile ("jsr a6@(-204:W)" \
  : \
  : "r"(__FreeLocalItem__bn), "r"(__FreeLocalItem_localItem) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FindLocalItem(iff, type, id, ident) ({ \
  const struct IFFHandle * _FindLocalItem_iff = (iff); \
  LONG _FindLocalItem_type = (type); \
  LONG _FindLocalItem_id = (id); \
  LONG _FindLocalItem_ident = (ident); \
  struct LocalContextItem * _FindLocalItem__re = \
  ({ \
  register struct Library * const __FindLocalItem__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct LocalContextItem * __FindLocalItem__re __asm("d0"); \
  register const struct IFFHandle * __FindLocalItem_iff __asm("a0") = (_FindLocalItem_iff); \
  register LONG __FindLocalItem_type __asm("d0") = (_FindLocalItem_type); \
  register LONG __FindLocalItem_id __asm("d1") = (_FindLocalItem_id); \
  register LONG __FindLocalItem_ident __asm("d2") = (_FindLocalItem_ident); \
  __asm volatile ("jsr a6@(-210:W)" \
  : "=r"(__FindLocalItem__re) \
  : "r"(__FindLocalItem__bn), "r"(__FindLocalItem_iff), "r"(__FindLocalItem_type), "r"(__FindLocalItem_id), "r"(__FindLocalItem_ident) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindLocalItem__re; \
  }); \
  _FindLocalItem__re; \
})

#define StoreLocalItem(iff, localItem, position) ({ \
  struct IFFHandle * _StoreLocalItem_iff = (iff); \
  struct LocalContextItem * _StoreLocalItem_localItem = (localItem); \
  LONG _StoreLocalItem_position = (position); \
  LONG _StoreLocalItem__re = \
  ({ \
  register struct Library * const __StoreLocalItem__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __StoreLocalItem__re __asm("d0"); \
  register struct IFFHandle * __StoreLocalItem_iff __asm("a0") = (_StoreLocalItem_iff); \
  register struct LocalContextItem * __StoreLocalItem_localItem __asm("a1") = (_StoreLocalItem_localItem); \
  register LONG __StoreLocalItem_position __asm("d0") = (_StoreLocalItem_position); \
  __asm volatile ("jsr a6@(-216:W)" \
  : "=r"(__StoreLocalItem__re) \
  : "r"(__StoreLocalItem__bn), "r"(__StoreLocalItem_iff), "r"(__StoreLocalItem_localItem), "r"(__StoreLocalItem_position) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __StoreLocalItem__re; \
  }); \
  _StoreLocalItem__re; \
})

#define StoreItemInContext(iff, localItem, contextNode) ({ \
  struct IFFHandle * _StoreItemInContext_iff = (iff); \
  struct LocalContextItem * _StoreItemInContext_localItem = (localItem); \
  struct ContextNode * _StoreItemInContext_contextNode = (contextNode); \
  { \
  register struct Library * const __StoreItemInContext__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct IFFHandle * __StoreItemInContext_iff __asm("a0") = (_StoreItemInContext_iff); \
  register struct LocalContextItem * __StoreItemInContext_localItem __asm("a1") = (_StoreItemInContext_localItem); \
  register struct ContextNode * __StoreItemInContext_contextNode __asm("a2") = (_StoreItemInContext_contextNode); \
  __asm volatile ("jsr a6@(-222:W)" \
  : \
  : "r"(__StoreItemInContext__bn), "r"(__StoreItemInContext_iff), "r"(__StoreItemInContext_localItem), "r"(__StoreItemInContext_contextNode) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define InitIFF(iff, flags, streamHook) ({ \
  struct IFFHandle * _InitIFF_iff = (iff); \
  LONG _InitIFF_flags = (flags); \
  const struct Hook * _InitIFF_streamHook = (streamHook); \
  { \
  register struct Library * const __InitIFF__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct IFFHandle * __InitIFF_iff __asm("a0") = (_InitIFF_iff); \
  register LONG __InitIFF_flags __asm("d0") = (_InitIFF_flags); \
  register const struct Hook * __InitIFF_streamHook __asm("a1") = (_InitIFF_streamHook); \
  __asm volatile ("jsr a6@(-228:W)" \
  : \
  : "r"(__InitIFF__bn), "r"(__InitIFF_iff), "r"(__InitIFF_flags), "r"(__InitIFF_streamHook) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define InitIFFasDOS(iff) ({ \
  struct IFFHandle * _InitIFFasDOS_iff = (iff); \
  { \
  register struct Library * const __InitIFFasDOS__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct IFFHandle * __InitIFFasDOS_iff __asm("a0") = (_InitIFFasDOS_iff); \
  __asm volatile ("jsr a6@(-234:W)" \
  : \
  : "r"(__InitIFFasDOS__bn), "r"(__InitIFFasDOS_iff) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define InitIFFasClip(iff) ({ \
  struct IFFHandle * _InitIFFasClip_iff = (iff); \
  { \
  register struct Library * const __InitIFFasClip__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct IFFHandle * __InitIFFasClip_iff __asm("a0") = (_InitIFFasClip_iff); \
  __asm volatile ("jsr a6@(-240:W)" \
  : \
  : "r"(__InitIFFasClip__bn), "r"(__InitIFFasClip_iff) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OpenClipboard(unitNumber) ({ \
  LONG _OpenClipboard_unitNumber = (unitNumber); \
  struct ClipboardHandle * _OpenClipboard__re = \
  ({ \
  register struct Library * const __OpenClipboard__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct ClipboardHandle * __OpenClipboard__re __asm("d0"); \
  register LONG __OpenClipboard_unitNumber __asm("d0") = (_OpenClipboard_unitNumber); \
  __asm volatile ("jsr a6@(-246:W)" \
  : "=r"(__OpenClipboard__re) \
  : "r"(__OpenClipboard__bn), "r"(__OpenClipboard_unitNumber) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenClipboard__re; \
  }); \
  _OpenClipboard__re; \
})

#define CloseClipboard(clipHandle) ({ \
  struct ClipboardHandle * _CloseClipboard_clipHandle = (clipHandle); \
  { \
  register struct Library * const __CloseClipboard__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register struct ClipboardHandle * __CloseClipboard_clipHandle __asm("a0") = (_CloseClipboard_clipHandle); \
  __asm volatile ("jsr a6@(-252:W)" \
  : \
  : "r"(__CloseClipboard__bn), "r"(__CloseClipboard_clipHandle) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GoodID(id) ({ \
  LONG _GoodID_id = (id); \
  LONG _GoodID__re = \
  ({ \
  register struct Library * const __GoodID__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __GoodID__re __asm("d0"); \
  register LONG __GoodID_id __asm("d0") = (_GoodID_id); \
  __asm volatile ("jsr a6@(-258:W)" \
  : "=r"(__GoodID__re) \
  : "r"(__GoodID__bn), "r"(__GoodID_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GoodID__re; \
  }); \
  _GoodID__re; \
})

#define GoodType(type) ({ \
  LONG _GoodType_type = (type); \
  LONG _GoodType__re = \
  ({ \
  register struct Library * const __GoodType__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register LONG __GoodType__re __asm("d0"); \
  register LONG __GoodType_type __asm("d0") = (_GoodType_type); \
  __asm volatile ("jsr a6@(-264:W)" \
  : "=r"(__GoodType__re) \
  : "r"(__GoodType__bn), "r"(__GoodType_type) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GoodType__re; \
  }); \
  _GoodType__re; \
})

#define IDtoStr(id, buf) ({ \
  LONG _IDtoStr_id = (id); \
  STRPTR _IDtoStr_buf = (buf); \
  STRPTR _IDtoStr__re = \
  ({ \
  register struct Library * const __IDtoStr__bn __asm("a6") = (struct Library *) (IFFPARSE_BASE_NAME);\
  register STRPTR __IDtoStr__re __asm("d0"); \
  register LONG __IDtoStr_id __asm("d0") = (_IDtoStr_id); \
  register STRPTR __IDtoStr_buf __asm("a0") = (_IDtoStr_buf); \
  __asm volatile ("jsr a6@(-270:W)" \
  : "=r"(__IDtoStr__re) \
  : "r"(__IDtoStr__bn), "r"(__IDtoStr_id), "r"(__IDtoStr_buf) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IDtoStr__re; \
  }); \
  _IDtoStr__re; \
})

#endif /*  _INLINE_IFFPARSE_H  */
