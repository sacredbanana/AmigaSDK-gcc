#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_NIPC_H
#define _INLINE_NIPC_H

#ifndef CLIB_NIPC_PROTOS_H
#define CLIB_NIPC_PROTOS_H
#endif

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif
#ifndef  UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#ifndef  ENVOY_NIPC_H
#include <envoy/nipc.h>
#endif

#ifndef NIPC_BASE_NAME
#define NIPC_BASE_NAME NIPCBase
#endif

#define AddRoute(network, gateway, hops, ttl) ({ \
  ULONG _AddRoute_network = (network); \
  ULONG _AddRoute_gateway = (gateway); \
  ULONG _AddRoute_hops = (hops); \
  ULONG _AddRoute_ttl = (ttl); \
  BOOL _AddRoute__re = \
  ({ \
  register struct Library * const __AddRoute__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register BOOL __AddRoute__re __asm("d0"); \
  register ULONG __AddRoute_network __asm("d0") = (_AddRoute_network); \
  register ULONG __AddRoute_gateway __asm("d1") = (_AddRoute_gateway); \
  register ULONG __AddRoute_hops __asm("d2") = (_AddRoute_hops); \
  register ULONG __AddRoute_ttl __asm("d3") = (_AddRoute_ttl); \
  __asm volatile ("jsr a6@(-42:W)" \
  : "=r"(__AddRoute__re) \
  : "r"(__AddRoute__bn), "r"(__AddRoute_network), "r"(__AddRoute_gateway), "r"(__AddRoute_hops), "r"(__AddRoute_ttl) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AddRoute__re; \
  }); \
  _AddRoute__re; \
})

#define DeleteRoute(network) ({ \
  ULONG _DeleteRoute_network = (network); \
  APTR _DeleteRoute__re = \
  ({ \
  register struct Library * const __DeleteRoute__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register APTR __DeleteRoute__re __asm("d0"); \
  register ULONG __DeleteRoute_network __asm("d0") = (_DeleteRoute_network); \
  __asm volatile ("jsr a6@(-48:W)" \
  : "=r"(__DeleteRoute__re) \
  : "r"(__DeleteRoute__bn), "r"(__DeleteRoute_network) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DeleteRoute__re; \
  }); \
  _DeleteRoute__re; \
})

#define AllocTransactionA(tags) ({ \
  struct TagItem * _AllocTransactionA_tags = (tags); \
  struct Transaction * _AllocTransactionA__re = \
  ({ \
  register struct Library * const __AllocTransactionA__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Transaction * __AllocTransactionA__re __asm("d0"); \
  register struct TagItem * __AllocTransactionA_tags __asm("a0") = (_AllocTransactionA_tags); \
  __asm volatile ("jsr a6@(-114:W)" \
  : "=r"(__AllocTransactionA__re) \
  : "r"(__AllocTransactionA__bn), "r"(__AllocTransactionA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocTransactionA__re; \
  }); \
  _AllocTransactionA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Transaction * ___AllocTransaction(struct Library * NIPCBase, Tag tags, ...)
{
  return AllocTransactionA((struct TagItem *) &tags);
}

#define AllocTransaction(tags...) ___AllocTransaction(NIPC_BASE_NAME, tags)
#endif

#define FreeTransaction(transaction) ({ \
  struct Transaction * _FreeTransaction_transaction = (transaction); \
  APTR _FreeTransaction__re = \
  ({ \
  register struct Library * const __FreeTransaction__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register APTR __FreeTransaction__re __asm("d0"); \
  register struct Transaction * __FreeTransaction_transaction __asm("a1") = (_FreeTransaction_transaction); \
  __asm volatile ("jsr a6@(-120:W)" \
  : "=r"(__FreeTransaction__re) \
  : "r"(__FreeTransaction__bn), "r"(__FreeTransaction_transaction) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FreeTransaction__re; \
  }); \
  _FreeTransaction__re; \
})

#define CreateEntityA(tags) ({ \
  struct TagItem * _CreateEntityA_tags = (tags); \
  struct Entity * _CreateEntityA__re = \
  ({ \
  register struct Library * const __CreateEntityA__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Entity * __CreateEntityA__re __asm("d0"); \
  register struct TagItem * __CreateEntityA_tags __asm("a0") = (_CreateEntityA_tags); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__CreateEntityA__re) \
  : "r"(__CreateEntityA__bn), "r"(__CreateEntityA_tags) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateEntityA__re; \
  }); \
  _CreateEntityA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ struct Entity * ___CreateEntity(struct Library * NIPCBase, Tag tags, ...)
{
  return CreateEntityA((struct TagItem *) &tags);
}

#define CreateEntity(tags...) ___CreateEntity(NIPC_BASE_NAME, tags)
#endif

#define DeleteEntity(entity) ({ \
  struct Entity * _DeleteEntity_entity = (entity); \
  { \
  register struct Library * const __DeleteEntity__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Entity * __DeleteEntity_entity __asm("a0") = (_DeleteEntity_entity); \
  __asm volatile ("jsr a6@(-132:W)" \
  : \
  : "r"(__DeleteEntity__bn), "r"(__DeleteEntity_entity) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FindEntity(hostname, entityname, src_entity, detailerror) ({ \
  STRPTR _FindEntity_hostname = (hostname); \
  STRPTR _FindEntity_entityname = (entityname); \
  struct Entity * _FindEntity_src_entity = (src_entity); \
  ULONG * _FindEntity_detailerror = (detailerror); \
  struct Entity * _FindEntity__re = \
  ({ \
  register struct Library * const __FindEntity__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Entity * __FindEntity__re __asm("d0"); \
  register STRPTR __FindEntity_hostname __asm("a0") = (_FindEntity_hostname); \
  register STRPTR __FindEntity_entityname __asm("a1") = (_FindEntity_entityname); \
  register struct Entity * __FindEntity_src_entity __asm("a2") = (_FindEntity_src_entity); \
  register ULONG * __FindEntity_detailerror __asm("a3") = (_FindEntity_detailerror); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__FindEntity__re) \
  : "r"(__FindEntity__bn), "r"(__FindEntity_hostname), "r"(__FindEntity_entityname), "r"(__FindEntity_src_entity), "r"(__FindEntity_detailerror) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FindEntity__re; \
  }); \
  _FindEntity__re; \
})

#define LoseEntity(entity) ({ \
  struct Entity * _LoseEntity_entity = (entity); \
  { \
  register struct Library * const __LoseEntity__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Entity * __LoseEntity_entity __asm("a0") = (_LoseEntity_entity); \
  __asm volatile ("jsr a6@(-144:W)" \
  : \
  : "r"(__LoseEntity__bn), "r"(__LoseEntity_entity) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define DoTransaction(dest_entity, src_entity, transaction) ({ \
  struct Entity * _DoTransaction_dest_entity = (dest_entity); \
  struct Entity * _DoTransaction_src_entity = (src_entity); \
  struct Transaction * _DoTransaction_transaction = (transaction); \
  BOOL _DoTransaction__re = \
  ({ \
  register struct Library * const __DoTransaction__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register BOOL __DoTransaction__re __asm("d0"); \
  register struct Entity * __DoTransaction_dest_entity __asm("a0") = (_DoTransaction_dest_entity); \
  register struct Entity * __DoTransaction_src_entity __asm("a1") = (_DoTransaction_src_entity); \
  register struct Transaction * __DoTransaction_transaction __asm("a2") = (_DoTransaction_transaction); \
  __asm volatile ("jsr a6@(-150:W)" \
  : "=r"(__DoTransaction__re) \
  : "r"(__DoTransaction__bn), "r"(__DoTransaction_dest_entity), "r"(__DoTransaction_src_entity), "r"(__DoTransaction_transaction) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __DoTransaction__re; \
  }); \
  _DoTransaction__re; \
})

#define BeginTransaction(dest_entity, src_entity, transaction) ({ \
  struct Entity * _BeginTransaction_dest_entity = (dest_entity); \
  struct Entity * _BeginTransaction_src_entity = (src_entity); \
  struct Transaction * _BeginTransaction_transaction = (transaction); \
  BOOL _BeginTransaction__re = \
  ({ \
  register struct Library * const __BeginTransaction__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register BOOL __BeginTransaction__re __asm("d0"); \
  register struct Entity * __BeginTransaction_dest_entity __asm("a0") = (_BeginTransaction_dest_entity); \
  register struct Entity * __BeginTransaction_src_entity __asm("a1") = (_BeginTransaction_src_entity); \
  register struct Transaction * __BeginTransaction_transaction __asm("a2") = (_BeginTransaction_transaction); \
  __asm volatile ("jsr a6@(-156:W)" \
  : "=r"(__BeginTransaction__re) \
  : "r"(__BeginTransaction__bn), "r"(__BeginTransaction_dest_entity), "r"(__BeginTransaction_src_entity), "r"(__BeginTransaction_transaction) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __BeginTransaction__re; \
  }); \
  _BeginTransaction__re; \
})

#define GetTransaction(entity) ({ \
  struct Entity * _GetTransaction_entity = (entity); \
  struct Transaction * _GetTransaction__re = \
  ({ \
  register struct Library * const __GetTransaction__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Transaction * __GetTransaction__re __asm("d0"); \
  register struct Entity * __GetTransaction_entity __asm("a0") = (_GetTransaction_entity); \
  __asm volatile ("jsr a6@(-162:W)" \
  : "=r"(__GetTransaction__re) \
  : "r"(__GetTransaction__bn), "r"(__GetTransaction_entity) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetTransaction__re; \
  }); \
  _GetTransaction__re; \
})

#define ReplyTransaction(transaction) ({ \
  struct Transaction * _ReplyTransaction_transaction = (transaction); \
  { \
  register struct Library * const __ReplyTransaction__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Transaction * __ReplyTransaction_transaction __asm("a1") = (_ReplyTransaction_transaction); \
  __asm volatile ("jsr a6@(-168:W)" \
  : \
  : "r"(__ReplyTransaction__bn), "r"(__ReplyTransaction_transaction) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CheckTransaction(transaction) ({ \
  struct Transaction * _CheckTransaction_transaction = (transaction); \
  BOOL _CheckTransaction__re = \
  ({ \
  register struct Library * const __CheckTransaction__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register BOOL __CheckTransaction__re __asm("d0"); \
  register struct Transaction * __CheckTransaction_transaction __asm("a1") = (_CheckTransaction_transaction); \
  __asm volatile ("jsr a6@(-174:W)" \
  : "=r"(__CheckTransaction__re) \
  : "r"(__CheckTransaction__bn), "r"(__CheckTransaction_transaction) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CheckTransaction__re; \
  }); \
  _CheckTransaction__re; \
})

#define AbortTransaction(transaction) ({ \
  struct Transaction * _AbortTransaction_transaction = (transaction); \
  { \
  register struct Library * const __AbortTransaction__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Transaction * __AbortTransaction_transaction __asm("a1") = (_AbortTransaction_transaction); \
  __asm volatile ("jsr a6@(-180:W)" \
  : \
  : "r"(__AbortTransaction__bn), "r"(__AbortTransaction_transaction) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define WaitTransaction(transaction) ({ \
  struct Transaction * _WaitTransaction_transaction = (transaction); \
  { \
  register struct Library * const __WaitTransaction__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Transaction * __WaitTransaction_transaction __asm("a1") = (_WaitTransaction_transaction); \
  __asm volatile ("jsr a6@(-186:W)" \
  : \
  : "r"(__WaitTransaction__bn), "r"(__WaitTransaction_transaction) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define WaitEntity(entity) ({ \
  struct Entity * _WaitEntity_entity = (entity); \
  { \
  register struct Library * const __WaitEntity__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Entity * __WaitEntity_entity __asm("a0") = (_WaitEntity_entity); \
  __asm volatile ("jsr a6@(-192:W)" \
  : \
  : "r"(__WaitEntity__bn), "r"(__WaitEntity_entity) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetEntityName(entity, string, maxlen) ({ \
  struct Entity * _GetEntityName_entity = (entity); \
  STRPTR _GetEntityName_string = (string); \
  ULONG _GetEntityName_maxlen = (maxlen); \
  BOOL _GetEntityName__re = \
  ({ \
  register struct Library * const __GetEntityName__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register BOOL __GetEntityName__re __asm("d0"); \
  register struct Entity * __GetEntityName_entity __asm("a0") = (_GetEntityName_entity); \
  register STRPTR __GetEntityName_string __asm("a1") = (_GetEntityName_string); \
  register ULONG __GetEntityName_maxlen __asm("d0") = (_GetEntityName_maxlen); \
  __asm volatile ("jsr a6@(-198:W)" \
  : "=r"(__GetEntityName__re) \
  : "r"(__GetEntityName__bn), "r"(__GetEntityName_entity), "r"(__GetEntityName_string), "r"(__GetEntityName_maxlen) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetEntityName__re; \
  }); \
  _GetEntityName__re; \
})

#define GetHostName(entity, string, maxlen) ({ \
  struct Entity * _GetHostName_entity = (entity); \
  STRPTR _GetHostName_string = (string); \
  ULONG _GetHostName_maxlen = (maxlen); \
  BOOL _GetHostName__re = \
  ({ \
  register struct Library * const __GetHostName__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register BOOL __GetHostName__re __asm("d0"); \
  register struct Entity * __GetHostName_entity __asm("a0") = (_GetHostName_entity); \
  register STRPTR __GetHostName_string __asm("a1") = (_GetHostName_string); \
  register ULONG __GetHostName_maxlen __asm("d0") = (_GetHostName_maxlen); \
  __asm volatile ("jsr a6@(-204:W)" \
  : "=r"(__GetHostName__re) \
  : "r"(__GetHostName__bn), "r"(__GetHostName_entity), "r"(__GetHostName_string), "r"(__GetHostName_maxlen) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetHostName__re; \
  }); \
  _GetHostName__re; \
})

#define NIPCInquiryA(hook, maxTime, maxResponses, tagList) ({ \
  struct Hook * _NIPCInquiryA_hook = (hook); \
  ULONG _NIPCInquiryA_maxTime = (maxTime); \
  ULONG _NIPCInquiryA_maxResponses = (maxResponses); \
  struct TagItem * _NIPCInquiryA_tagList = (tagList); \
  BOOL _NIPCInquiryA__re = \
  ({ \
  register struct Library * const __NIPCInquiryA__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register BOOL __NIPCInquiryA__re __asm("d0"); \
  register struct Hook * __NIPCInquiryA_hook __asm("a0") = (_NIPCInquiryA_hook); \
  register ULONG __NIPCInquiryA_maxTime __asm("d0") = (_NIPCInquiryA_maxTime); \
  register ULONG __NIPCInquiryA_maxResponses __asm("d1") = (_NIPCInquiryA_maxResponses); \
  register struct TagItem * __NIPCInquiryA_tagList __asm("a1") = (_NIPCInquiryA_tagList); \
  __asm volatile ("jsr a6@(-210:W)" \
  : "=r"(__NIPCInquiryA__re) \
  : "r"(__NIPCInquiryA__bn), "r"(__NIPCInquiryA_hook), "r"(__NIPCInquiryA_maxTime), "r"(__NIPCInquiryA_maxResponses), "r"(__NIPCInquiryA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NIPCInquiryA__re; \
  }); \
  _NIPCInquiryA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ BOOL ___NIPCInquiry(struct Library * NIPCBase, struct Hook * hook, ULONG maxTime, ULONG maxResponses, Tag tagList, ...)
{
  return NIPCInquiryA(hook, maxTime, maxResponses, (struct TagItem *) &tagList);
}

#define NIPCInquiry(hook, maxTime, maxResponses...) ___NIPCInquiry(NIPC_BASE_NAME, hook, maxTime, maxResponses)
#endif

#define PingEntity(pingtarget, maxTime) ({ \
  struct Entity * _PingEntity_pingtarget = (pingtarget); \
  ULONG _PingEntity_maxTime = (maxTime); \
  ULONG _PingEntity__re = \
  ({ \
  register struct Library * const __PingEntity__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register ULONG __PingEntity__re __asm("d0"); \
  register struct Entity * __PingEntity_pingtarget __asm("a0") = (_PingEntity_pingtarget); \
  register ULONG __PingEntity_maxTime __asm("d0") = (_PingEntity_maxTime); \
  __asm volatile ("jsr a6@(-216:W)" \
  : "=r"(__PingEntity__re) \
  : "r"(__PingEntity__bn), "r"(__PingEntity_pingtarget), "r"(__PingEntity_maxTime) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __PingEntity__re; \
  }); \
  _PingEntity__re; \
})

#define GetEntityAttrsA(entity, tagList) ({ \
  struct Entity * _GetEntityAttrsA_entity = (entity); \
  struct TagItem * _GetEntityAttrsA_tagList = (tagList); \
  ULONG _GetEntityAttrsA__re = \
  ({ \
  register struct Library * const __GetEntityAttrsA__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register ULONG __GetEntityAttrsA__re __asm("d0"); \
  register struct Entity * __GetEntityAttrsA_entity __asm("a0") = (_GetEntityAttrsA_entity); \
  register struct TagItem * __GetEntityAttrsA_tagList __asm("a1") = (_GetEntityAttrsA_tagList); \
  __asm volatile ("jsr a6@(-222:W)" \
  : "=r"(__GetEntityAttrsA__re) \
  : "r"(__GetEntityAttrsA__bn), "r"(__GetEntityAttrsA_entity), "r"(__GetEntityAttrsA_tagList) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetEntityAttrsA__re; \
  }); \
  _GetEntityAttrsA__re; \
})

#ifndef NO_INLINE_STDARG
static __inline__ ULONG ___GetEntityAttrs(struct Library * NIPCBase, struct Entity * entity, Tag tagList, ...)
{
  return GetEntityAttrsA(entity, (struct TagItem *) &tagList);
}

#define GetEntityAttrs(entity...) ___GetEntityAttrs(NIPC_BASE_NAME, entity)
#endif

#define SetEntityAttrsA(entity, tagList) ({ \
  struct Entity * _SetEntityAttrsA_entity = (entity); \
  struct TagItem * _SetEntityAttrsA_tagList = (tagList); \
  { \
  register struct Library * const __SetEntityAttrsA__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct Entity * __SetEntityAttrsA_entity __asm("a0") = (_SetEntityAttrsA_entity); \
  register struct TagItem * __SetEntityAttrsA_tagList __asm("a1") = (_SetEntityAttrsA_tagList); \
  __asm volatile ("jsr a6@(-228:W)" \
  : \
  : "r"(__SetEntityAttrsA__bn), "r"(__SetEntityAttrsA_entity), "r"(__SetEntityAttrsA_tagList) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#ifndef NO_INLINE_STDARG
static __inline__ VOID ___SetEntityAttrs(struct Library * NIPCBase, struct Entity * entity, Tag tagList, ...)
{
  SetEntityAttrsA(entity, (struct TagItem *) &tagList);
}

#define SetEntityAttrs(entity...) ___SetEntityAttrs(NIPC_BASE_NAME, entity)
#endif

#define AllocNIPCBuff(entries) ({ \
  ULONG _AllocNIPCBuff_entries = (entries); \
  struct NIPCBuff * _AllocNIPCBuff__re = \
  ({ \
  register struct Library * const __AllocNIPCBuff__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct NIPCBuff * __AllocNIPCBuff__re __asm("d0"); \
  register ULONG __AllocNIPCBuff_entries __asm("d0") = (_AllocNIPCBuff_entries); \
  __asm volatile ("jsr a6@(-234:W)" \
  : "=r"(__AllocNIPCBuff__re) \
  : "r"(__AllocNIPCBuff__bn), "r"(__AllocNIPCBuff_entries) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocNIPCBuff__re; \
  }); \
  _AllocNIPCBuff__re; \
})

#define AllocNIPCBuffEntry() ({ \
  struct NIPCBuffEntry * _AllocNIPCBuffEntry__re = \
  ({ \
  register struct Library * const __AllocNIPCBuffEntry__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct NIPCBuffEntry * __AllocNIPCBuffEntry__re __asm("d0"); \
  __asm volatile ("jsr a6@(-240:W)" \
  : "=r"(__AllocNIPCBuffEntry__re) \
  : "r"(__AllocNIPCBuffEntry__bn) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __AllocNIPCBuffEntry__re; \
  }); \
  _AllocNIPCBuffEntry__re; \
})

#define CopyNIPCBuff(src_buff, dest_buff, offset, length) ({ \
  struct NIPCBuff * _CopyNIPCBuff_src_buff = (src_buff); \
  struct NIPCBuff * _CopyNIPCBuff_dest_buff = (dest_buff); \
  ULONG _CopyNIPCBuff_offset = (offset); \
  ULONG _CopyNIPCBuff_length = (length); \
  ULONG _CopyNIPCBuff__re = \
  ({ \
  register struct Library * const __CopyNIPCBuff__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register ULONG __CopyNIPCBuff__re __asm("d0"); \
  register struct NIPCBuff * __CopyNIPCBuff_src_buff __asm("a0") = (_CopyNIPCBuff_src_buff); \
  register struct NIPCBuff * __CopyNIPCBuff_dest_buff __asm("a1") = (_CopyNIPCBuff_dest_buff); \
  register ULONG __CopyNIPCBuff_offset __asm("d0") = (_CopyNIPCBuff_offset); \
  register ULONG __CopyNIPCBuff_length __asm("d1") = (_CopyNIPCBuff_length); \
  __asm volatile ("jsr a6@(-246:W)" \
  : "=r"(__CopyNIPCBuff__re) \
  : "r"(__CopyNIPCBuff__bn), "r"(__CopyNIPCBuff_src_buff), "r"(__CopyNIPCBuff_dest_buff), "r"(__CopyNIPCBuff_offset), "r"(__CopyNIPCBuff_length) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CopyNIPCBuff__re; \
  }); \
  _CopyNIPCBuff__re; \
})

#define CopyToNIPCBuff(src_data, dest_buff, length) ({ \
  UBYTE * _CopyToNIPCBuff_src_data = (src_data); \
  struct NIPCBuff * _CopyToNIPCBuff_dest_buff = (dest_buff); \
  ULONG _CopyToNIPCBuff_length = (length); \
  ULONG _CopyToNIPCBuff__re = \
  ({ \
  register struct Library * const __CopyToNIPCBuff__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register ULONG __CopyToNIPCBuff__re __asm("d0"); \
  register UBYTE * __CopyToNIPCBuff_src_data __asm("a0") = (_CopyToNIPCBuff_src_data); \
  register struct NIPCBuff * __CopyToNIPCBuff_dest_buff __asm("a1") = (_CopyToNIPCBuff_dest_buff); \
  register ULONG __CopyToNIPCBuff_length __asm("d0") = (_CopyToNIPCBuff_length); \
  __asm volatile ("jsr a6@(-252:W)" \
  : "=r"(__CopyToNIPCBuff__re) \
  : "r"(__CopyToNIPCBuff__bn), "r"(__CopyToNIPCBuff_src_data), "r"(__CopyToNIPCBuff_dest_buff), "r"(__CopyToNIPCBuff_length) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CopyToNIPCBuff__re; \
  }); \
  _CopyToNIPCBuff__re; \
})

#define CopyFromNIPCBuffer(src_buff, dest_data, length) ({ \
  struct NIPCBuff * _CopyFromNIPCBuffer_src_buff = (src_buff); \
  UBYTE * _CopyFromNIPCBuffer_dest_data = (dest_data); \
  ULONG _CopyFromNIPCBuffer_length = (length); \
  ULONG _CopyFromNIPCBuffer__re = \
  ({ \
  register struct Library * const __CopyFromNIPCBuffer__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register ULONG __CopyFromNIPCBuffer__re __asm("d0"); \
  register struct NIPCBuff * __CopyFromNIPCBuffer_src_buff __asm("a0") = (_CopyFromNIPCBuffer_src_buff); \
  register UBYTE * __CopyFromNIPCBuffer_dest_data __asm("a1") = (_CopyFromNIPCBuffer_dest_data); \
  register ULONG __CopyFromNIPCBuffer_length __asm("d0") = (_CopyFromNIPCBuffer_length); \
  __asm volatile ("jsr a6@(-258:W)" \
  : "=r"(__CopyFromNIPCBuffer__re) \
  : "r"(__CopyFromNIPCBuffer__bn), "r"(__CopyFromNIPCBuffer_src_buff), "r"(__CopyFromNIPCBuffer_dest_data), "r"(__CopyFromNIPCBuffer_length) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CopyFromNIPCBuffer__re; \
  }); \
  _CopyFromNIPCBuffer__re; \
})

#define FreeNIPCBuff(buff) ({ \
  struct NIPCBuff * _FreeNIPCBuff_buff = (buff); \
  { \
  register struct Library * const __FreeNIPCBuff__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct NIPCBuff * __FreeNIPCBuff_buff __asm("a0") = (_FreeNIPCBuff_buff); \
  __asm volatile ("jsr a6@(-264:W)" \
  : \
  : "r"(__FreeNIPCBuff__bn), "r"(__FreeNIPCBuff_buff) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FreeNIPCBuffEntry(entry) ({ \
  struct NIPCBuffEntry * _FreeNIPCBuffEntry_entry = (entry); \
  { \
  register struct Library * const __FreeNIPCBuffEntry__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct NIPCBuffEntry * __FreeNIPCBuffEntry_entry __asm("a0") = (_FreeNIPCBuffEntry_entry); \
  __asm volatile ("jsr a6@(-270:W)" \
  : \
  : "r"(__FreeNIPCBuffEntry__bn), "r"(__FreeNIPCBuffEntry_entry) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define NIPCBuffLength(buff) ({ \
  struct NIPCBuff * _NIPCBuffLength_buff = (buff); \
  ULONG _NIPCBuffLength__re = \
  ({ \
  register struct Library * const __NIPCBuffLength__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register ULONG __NIPCBuffLength__re __asm("d0"); \
  register struct NIPCBuff * __NIPCBuffLength_buff __asm("a0") = (_NIPCBuffLength_buff); \
  __asm volatile ("jsr a6@(-276:W)" \
  : "=r"(__NIPCBuffLength__re) \
  : "r"(__NIPCBuffLength__bn), "r"(__NIPCBuffLength_buff) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __NIPCBuffLength__re; \
  }); \
  _NIPCBuffLength__re; \
})

#define AppendNIPCBuff(first, second) ({ \
  struct NIPCBuff * _AppendNIPCBuff_first = (first); \
  struct NIPCBuff * _AppendNIPCBuff_second = (second); \
  { \
  register struct Library * const __AppendNIPCBuff__bn __asm("a6") = (struct Library *) (NIPC_BASE_NAME);\
  register struct NIPCBuff * __AppendNIPCBuff_first __asm("a0") = (_AppendNIPCBuff_first); \
  register struct NIPCBuff * __AppendNIPCBuff_second __asm("a1") = (_AppendNIPCBuff_second); \
  __asm volatile ("jsr a6@(-282:W)" \
  : \
  : "r"(__AppendNIPCBuff__bn), "r"(__AppendNIPCBuff_first), "r"(__AppendNIPCBuff_second) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_NIPC_H  */
