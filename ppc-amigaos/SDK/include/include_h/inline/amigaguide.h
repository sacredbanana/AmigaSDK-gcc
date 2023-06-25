#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_AMIGAGUIDE_H
#define _INLINE_AMIGAGUIDE_H

#ifndef CLIB_AMIGAGUIDE_PROTOS_H
#define CLIB_AMIGAGUIDE_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  EXEC_PORTS_H
#include <exec/ports.h>
#endif
#ifndef  DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef  LIBRARIES_AMIGAGUIDE_H
#include <libraries/amigaguide.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef  REXX_STORAGE_H
#include <rexx/storage.h>
#endif

#ifndef AMIGAGUIDE_BASE_NAME
#define AMIGAGUIDE_BASE_NAME AmigaGuideBase
#endif

#define LockAmigaGuideBase(handle) ({ \
  APTR _LockAmigaGuideBase_handle = (handle); \
  LONG _LockAmigaGuideBase__re = \
  ({ \
  register struct Library * const __LockAmigaGuideBase__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register LONG __LockAmigaGuideBase__re __asm("d0"); \
  register APTR __LockAmigaGuideBase_handle __asm("a0") = (_LockAmigaGuideBase_handle); \
  __asm volatile ("jsr a6@(-36:W)" \
  : "=r"(__LockAmigaGuideBase__re) \
  : "r"(__LockAmigaGuideBase__bn), "r"(__LockAmigaGuideBase_handle) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LockAmigaGuideBase__re; \
  }); \
  _LockAmigaGuideBase__re; \
})

#define UnlockAmigaGuideBase(key) ({ \
  LONG _UnlockAmigaGuideBase_key = (key); \
  { \
  register struct Library * const __UnlockAmigaGuideBase__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register LONG __UnlockAmigaGuideBase_key __asm("d0") = (_UnlockAmigaGuideBase_key); \
  __asm volatile ("jsr a6@(-42:W)" \
  : \
  : "r"(__UnlockAmigaGuideBase__bn), "r"(__UnlockAmigaGuideBase_key) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define OpenAmigaGuideA(nag, tags) ({ \
  struct NewAmigaGuide * _OpenAmigaGuideA_nag = (nag); \
  struct TagItem * _OpenAmigaGuideA_tags = (tags); \
  APTR _OpenAmigaGuideA__re = \
  ({ \
  register struct Library * const __OpenAmigaGuideA__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register APTR __OpenAmigaGuideA__re __asm("d0"); \
  register struct NewAmigaGuide * __OpenAmigaGuideA_nag __asm("a0") = (_OpenAmigaGuideA_nag); \
  register struct TagItem * __OpenAmigaGuideA_tags __asm("a1") = (_OpenAmigaGuideA_tags); \
  __asm volatile ("jsr a6@(-54:W)" \
  : "=r"(__OpenAmigaGuideA__re) \
  : "r"(__OpenAmigaGuideA__bn), "r"(__OpenAmigaGuideA_nag), "r"(__OpenAmigaGuideA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenAmigaGuideA__re; \
  }); \
  _OpenAmigaGuideA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___OpenAmigaGuide(struct Library * AmigaGuideBase, struct NewAmigaGuide * nag, Tag tags, ...)
{
  return OpenAmigaGuideA(nag, (struct TagItem *) &tags);
}

#define OpenAmigaGuide(nag...) ___OpenAmigaGuide(AMIGAGUIDE_BASE_NAME, nag)
#endif

#define OpenAmigaGuideAsyncA(nag, attrs) ({ \
  struct NewAmigaGuide * _OpenAmigaGuideAsyncA_nag = (nag); \
  struct TagItem * _OpenAmigaGuideAsyncA_attrs = (attrs); \
  APTR _OpenAmigaGuideAsyncA__re = \
  ({ \
  register struct Library * const __OpenAmigaGuideAsyncA__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register APTR __OpenAmigaGuideAsyncA__re __asm("d0"); \
  register struct NewAmigaGuide * __OpenAmigaGuideAsyncA_nag __asm("a0") = (_OpenAmigaGuideAsyncA_nag); \
  register struct TagItem * __OpenAmigaGuideAsyncA_attrs __asm("d0") = (_OpenAmigaGuideAsyncA_attrs); \
  __asm volatile ("jsr a6@(-60:W)" \
  : "=r"(__OpenAmigaGuideAsyncA__re) \
  : "r"(__OpenAmigaGuideAsyncA__bn), "r"(__OpenAmigaGuideAsyncA_nag), "r"(__OpenAmigaGuideAsyncA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __OpenAmigaGuideAsyncA__re; \
  }); \
  _OpenAmigaGuideAsyncA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___OpenAmigaGuideAsync(struct Library * AmigaGuideBase, struct NewAmigaGuide * nag, Tag attrs, ...)
{
  return OpenAmigaGuideAsyncA(nag, (struct TagItem *) &attrs);
}

#define OpenAmigaGuideAsync(nag...) ___OpenAmigaGuideAsync(AMIGAGUIDE_BASE_NAME, nag)
#endif

#define CloseAmigaGuide(cl) ({ \
  APTR _CloseAmigaGuide_cl = (cl); \
  { \
  register struct Library * const __CloseAmigaGuide__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register APTR __CloseAmigaGuide_cl __asm("a0") = (_CloseAmigaGuide_cl); \
  __asm volatile ("jsr a6@(-66:W)" \
  : \
  : "r"(__CloseAmigaGuide__bn), "r"(__CloseAmigaGuide_cl) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define AmigaGuideSignal(cl) ({ \
  APTR _AmigaGuideSignal_cl = (cl); \
  ULONG _AmigaGuideSignal__re = \
  ({ \
  register struct Library * const __AmigaGuideSignal__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register ULONG __AmigaGuideSignal__re __asm("d0"); \
  register APTR __AmigaGuideSignal_cl __asm("a0") = (_AmigaGuideSignal_cl); \
  __asm volatile ("jsr a6@(-72:W)" \
  : "=r"(__AmigaGuideSignal__re) \
  : "r"(__AmigaGuideSignal__bn), "r"(__AmigaGuideSignal_cl) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AmigaGuideSignal__re; \
  }); \
  _AmigaGuideSignal__re; \
})

#define GetAmigaGuideMsg(cl) ({ \
  APTR _GetAmigaGuideMsg_cl = (cl); \
  struct AmigaGuideMsg * _GetAmigaGuideMsg__re = \
  ({ \
  register struct Library * const __GetAmigaGuideMsg__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register struct AmigaGuideMsg * __GetAmigaGuideMsg__re __asm("d0"); \
  register APTR __GetAmigaGuideMsg_cl __asm("a0") = (_GetAmigaGuideMsg_cl); \
  __asm volatile ("jsr a6@(-78:W)" \
  : "=r"(__GetAmigaGuideMsg__re) \
  : "r"(__GetAmigaGuideMsg__bn), "r"(__GetAmigaGuideMsg_cl) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetAmigaGuideMsg__re; \
  }); \
  _GetAmigaGuideMsg__re; \
})

#define ReplyAmigaGuideMsg(amsg) ({ \
  struct AmigaGuideMsg * _ReplyAmigaGuideMsg_amsg = (amsg); \
  { \
  register struct Library * const __ReplyAmigaGuideMsg__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register struct AmigaGuideMsg * __ReplyAmigaGuideMsg_amsg __asm("a0") = (_ReplyAmigaGuideMsg_amsg); \
  __asm volatile ("jsr a6@(-84:W)" \
  : \
  : "r"(__ReplyAmigaGuideMsg__bn), "r"(__ReplyAmigaGuideMsg_amsg) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define SetAmigaGuideContextA(cl, id, attrs) ({ \
  APTR _SetAmigaGuideContextA_cl = (cl); \
  ULONG _SetAmigaGuideContextA_id = (id); \
  struct TagItem * _SetAmigaGuideContextA_attrs = (attrs); \
  LONG _SetAmigaGuideContextA__re = \
  ({ \
  register struct Library * const __SetAmigaGuideContextA__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register LONG __SetAmigaGuideContextA__re __asm("d0"); \
  register APTR __SetAmigaGuideContextA_cl __asm("a0") = (_SetAmigaGuideContextA_cl); \
  register ULONG __SetAmigaGuideContextA_id __asm("d0") = (_SetAmigaGuideContextA_id); \
  register struct TagItem * __SetAmigaGuideContextA_attrs __asm("d1") = (_SetAmigaGuideContextA_attrs); \
  __asm volatile ("jsr a6@(-90:W)" \
  : "=r"(__SetAmigaGuideContextA__re) \
  : "r"(__SetAmigaGuideContextA__bn), "r"(__SetAmigaGuideContextA_cl), "r"(__SetAmigaGuideContextA_id), "r"(__SetAmigaGuideContextA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetAmigaGuideContextA__re; \
  }); \
  _SetAmigaGuideContextA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SetAmigaGuideContext(struct Library * AmigaGuideBase, APTR cl, ULONG id, Tag attrs, ...)
{
  return SetAmigaGuideContextA(cl, id, (struct TagItem *) &attrs);
}

#define SetAmigaGuideContext(cl, id...) ___SetAmigaGuideContext(AMIGAGUIDE_BASE_NAME, cl, id)
#endif

#define SendAmigaGuideContextA(cl, attrs) ({ \
  APTR _SendAmigaGuideContextA_cl = (cl); \
  struct TagItem * _SendAmigaGuideContextA_attrs = (attrs); \
  LONG _SendAmigaGuideContextA__re = \
  ({ \
  register struct Library * const __SendAmigaGuideContextA__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register LONG __SendAmigaGuideContextA__re __asm("d0"); \
  register APTR __SendAmigaGuideContextA_cl __asm("a0") = (_SendAmigaGuideContextA_cl); \
  register struct TagItem * __SendAmigaGuideContextA_attrs __asm("d0") = (_SendAmigaGuideContextA_attrs); \
  __asm volatile ("jsr a6@(-96:W)" \
  : "=r"(__SendAmigaGuideContextA__re) \
  : "r"(__SendAmigaGuideContextA__bn), "r"(__SendAmigaGuideContextA_cl), "r"(__SendAmigaGuideContextA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SendAmigaGuideContextA__re; \
  }); \
  _SendAmigaGuideContextA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SendAmigaGuideContext(struct Library * AmigaGuideBase, APTR cl, Tag attrs, ...)
{
  return SendAmigaGuideContextA(cl, (struct TagItem *) &attrs);
}

#define SendAmigaGuideContext(cl...) ___SendAmigaGuideContext(AMIGAGUIDE_BASE_NAME, cl)
#endif

#define SendAmigaGuideCmdA(cl, cmd, attrs) ({ \
  APTR _SendAmigaGuideCmdA_cl = (cl); \
  STRPTR _SendAmigaGuideCmdA_cmd = (cmd); \
  struct TagItem * _SendAmigaGuideCmdA_attrs = (attrs); \
  LONG _SendAmigaGuideCmdA__re = \
  ({ \
  register struct Library * const __SendAmigaGuideCmdA__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register LONG __SendAmigaGuideCmdA__re __asm("d0"); \
  register APTR __SendAmigaGuideCmdA_cl __asm("a0") = (_SendAmigaGuideCmdA_cl); \
  register STRPTR __SendAmigaGuideCmdA_cmd __asm("d0") = (_SendAmigaGuideCmdA_cmd); \
  register struct TagItem * __SendAmigaGuideCmdA_attrs __asm("d1") = (_SendAmigaGuideCmdA_attrs); \
  __asm volatile ("jsr a6@(-102:W)" \
  : "=r"(__SendAmigaGuideCmdA__re) \
  : "r"(__SendAmigaGuideCmdA__bn), "r"(__SendAmigaGuideCmdA_cl), "r"(__SendAmigaGuideCmdA_cmd), "r"(__SendAmigaGuideCmdA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SendAmigaGuideCmdA__re; \
  }); \
  _SendAmigaGuideCmdA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SendAmigaGuideCmd(struct Library * AmigaGuideBase, APTR cl, STRPTR cmd, Tag attrs, ...)
{
  return SendAmigaGuideCmdA(cl, cmd, (struct TagItem *) &attrs);
}

#define SendAmigaGuideCmd(cl, cmd...) ___SendAmigaGuideCmd(AMIGAGUIDE_BASE_NAME, cl, cmd)
#endif

#define SetAmigaGuideAttrsA(cl, attrs) ({ \
  APTR _SetAmigaGuideAttrsA_cl = (cl); \
  struct TagItem * _SetAmigaGuideAttrsA_attrs = (attrs); \
  LONG _SetAmigaGuideAttrsA__re = \
  ({ \
  register struct Library * const __SetAmigaGuideAttrsA__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register LONG __SetAmigaGuideAttrsA__re __asm("d0"); \
  register APTR __SetAmigaGuideAttrsA_cl __asm("a0") = (_SetAmigaGuideAttrsA_cl); \
  register struct TagItem * __SetAmigaGuideAttrsA_attrs __asm("a1") = (_SetAmigaGuideAttrsA_attrs); \
  __asm volatile ("jsr a6@(-108:W)" \
  : "=r"(__SetAmigaGuideAttrsA__re) \
  : "r"(__SetAmigaGuideAttrsA__bn), "r"(__SetAmigaGuideAttrsA_cl), "r"(__SetAmigaGuideAttrsA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetAmigaGuideAttrsA__re; \
  }); \
  _SetAmigaGuideAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___SetAmigaGuideAttrs(struct Library * AmigaGuideBase, APTR cl, Tag attrs, ...)
{
  return SetAmigaGuideAttrsA(cl, (struct TagItem *) &attrs);
}

#define SetAmigaGuideAttrs(cl...) ___SetAmigaGuideAttrs(AMIGAGUIDE_BASE_NAME, cl)
#endif

#define GetAmigaGuideAttr(d0arg, cl, storage) ({ \
  Tag _GetAmigaGuideAttr_d0arg = (d0arg); \
  APTR _GetAmigaGuideAttr_cl = (cl); \
  ULONG * _GetAmigaGuideAttr_storage = (storage); \
  LONG _GetAmigaGuideAttr__re = \
  ({ \
  register struct Library * const __GetAmigaGuideAttr__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register LONG __GetAmigaGuideAttr__re __asm("d0"); \
  register Tag __GetAmigaGuideAttr_d0arg __asm("d0") = (_GetAmigaGuideAttr_d0arg); \
  register APTR __GetAmigaGuideAttr_cl __asm("a0") = (_GetAmigaGuideAttr_cl); \
  register ULONG * __GetAmigaGuideAttr_storage __asm("a1") = (_GetAmigaGuideAttr_storage); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__GetAmigaGuideAttr__re) \
  : "r"(__GetAmigaGuideAttr__bn), "r"(__GetAmigaGuideAttr_d0arg), "r"(__GetAmigaGuideAttr_cl), "r"(__GetAmigaGuideAttr_storage) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetAmigaGuideAttr__re; \
  }); \
  _GetAmigaGuideAttr__re; \
})

#define LoadXRef(lock, name) ({ \
  BPTR _LoadXRef_lock = (lock); \
  STRPTR _LoadXRef_name = (name); \
  LONG _LoadXRef__re = \
  ({ \
  register struct Library * const __LoadXRef__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register LONG __LoadXRef__re __asm("d0"); \
  register BPTR __LoadXRef_lock __asm("a0") = (_LoadXRef_lock); \
  register STRPTR __LoadXRef_name __asm("a1") = (_LoadXRef_name); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__LoadXRef__re) \
  : "r"(__LoadXRef__bn), "r"(__LoadXRef_lock), "r"(__LoadXRef_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LoadXRef__re; \
  }); \
  _LoadXRef__re; \
})

#define ExpungeXRef() ({ \
  register struct Library * const __ExpungeXRef__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  __asm volatile ("jsr a6@(-132:W)" \
  : \
  : "r"(__ExpungeXRef__bn) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
})

#define AddAmigaGuideHostA(h, name, attrs) ({ \
  struct Hook * _AddAmigaGuideHostA_h = (h); \
  STRPTR _AddAmigaGuideHostA_name = (name); \
  struct TagItem * _AddAmigaGuideHostA_attrs = (attrs); \
  APTR _AddAmigaGuideHostA__re = \
  ({ \
  register struct Library * const __AddAmigaGuideHostA__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register APTR __AddAmigaGuideHostA__re __asm("d0"); \
  register struct Hook * __AddAmigaGuideHostA_h __asm("a0") = (_AddAmigaGuideHostA_h); \
  register STRPTR __AddAmigaGuideHostA_name __asm("d0") = (_AddAmigaGuideHostA_name); \
  register struct TagItem * __AddAmigaGuideHostA_attrs __asm("a1") = (_AddAmigaGuideHostA_attrs); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__AddAmigaGuideHostA__re) \
  : "r"(__AddAmigaGuideHostA__bn), "r"(__AddAmigaGuideHostA_h), "r"(__AddAmigaGuideHostA_name), "r"(__AddAmigaGuideHostA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddAmigaGuideHostA__re; \
  }); \
  _AddAmigaGuideHostA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ APTR ___AddAmigaGuideHost(struct Library * AmigaGuideBase, struct Hook * h, STRPTR name, Tag attrs, ...)
{
  return AddAmigaGuideHostA(h, name, (struct TagItem *) &attrs);
}

#define AddAmigaGuideHost(h, name...) ___AddAmigaGuideHost(AMIGAGUIDE_BASE_NAME, h, name)
#endif

#define RemoveAmigaGuideHostA(hh, attrs) ({ \
  APTR _RemoveAmigaGuideHostA_hh = (hh); \
  struct TagItem * _RemoveAmigaGuideHostA_attrs = (attrs); \
  LONG _RemoveAmigaGuideHostA__re = \
  ({ \
  register struct Library * const __RemoveAmigaGuideHostA__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register LONG __RemoveAmigaGuideHostA__re __asm("d0"); \
  register APTR __RemoveAmigaGuideHostA_hh __asm("a0") = (_RemoveAmigaGuideHostA_hh); \
  register struct TagItem * __RemoveAmigaGuideHostA_attrs __asm("a1") = (_RemoveAmigaGuideHostA_attrs); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__RemoveAmigaGuideHostA__re) \
  : "r"(__RemoveAmigaGuideHostA__bn), "r"(__RemoveAmigaGuideHostA_hh), "r"(__RemoveAmigaGuideHostA_attrs) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __RemoveAmigaGuideHostA__re; \
  }); \
  _RemoveAmigaGuideHostA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ LONG ___RemoveAmigaGuideHost(struct Library * AmigaGuideBase, APTR hh, Tag attrs, ...)
{
  return RemoveAmigaGuideHostA(hh, (struct TagItem *) &attrs);
}

#define RemoveAmigaGuideHost(hh...) ___RemoveAmigaGuideHost(AMIGAGUIDE_BASE_NAME, hh)
#endif

#define GetAmigaGuideString(id) ({ \
  LONG _GetAmigaGuideString_id = (id); \
  STRPTR _GetAmigaGuideString__re = \
  ({ \
  register struct Library * const __GetAmigaGuideString__bn __asm("a6") = (struct Library *) (AMIGAGUIDE_BASE_NAME);\
  register STRPTR __GetAmigaGuideString__re __asm("d0"); \
  register LONG __GetAmigaGuideString_id __asm("d0") = (_GetAmigaGuideString_id); \
  __asm volatile ("jsr a6@(-210:W)" \
  : "=r"(__GetAmigaGuideString__re) \
  : "r"(__GetAmigaGuideString__bn), "r"(__GetAmigaGuideString_id) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetAmigaGuideString__re; \
  }); \
  _GetAmigaGuideString__re; \
})

#endif /*  _INLINE_AMIGAGUIDE_H  */
