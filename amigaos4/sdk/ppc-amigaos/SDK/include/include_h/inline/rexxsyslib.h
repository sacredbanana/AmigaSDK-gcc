#ifdef __amigaos4__
#error Include <proto/> header files, not <inline/> header files in OS4.
#endif

#ifndef _INLINE_REXXSYSLIB_H
#define _INLINE_REXXSYSLIB_H

#ifndef CLIB_REXXSYSLIB_PROTOS_H
#define CLIB_REXXSYSLIB_PROTOS_H
#endif

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  REXX_RXSLIB_H
#include <rexx/rxslib.h>
#endif
#ifndef  REXX_REXXIO_H
#include <rexx/rexxio.h>
#endif

#ifndef REXXSYSLIB_BASE_NAME
#define REXXSYSLIB_BASE_NAME RexxSysBase
#endif

#define CreateArgstring(string, length) ({ \
  CONST_STRPTR _CreateArgstring_string = (string); \
  ULONG _CreateArgstring_length = (length); \
  STRPTR _CreateArgstring__re = \
  ({ \
  register struct RxsLib * const __CreateArgstring__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register STRPTR __CreateArgstring__re __asm("d0"); \
  register CONST_STRPTR __CreateArgstring_string __asm("a0") = (_CreateArgstring_string); \
  register ULONG __CreateArgstring_length __asm("d0") = (_CreateArgstring_length); \
  __asm volatile ("jsr a6@(-126:W)" \
  : "=r"(__CreateArgstring__re) \
  : "r"(__CreateArgstring__bn), "r"(__CreateArgstring_string), "r"(__CreateArgstring_length) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateArgstring__re; \
  }); \
  _CreateArgstring__re; \
})

#define DeleteArgstring(argstring) ({ \
  STRPTR _DeleteArgstring_argstring = (argstring); \
  { \
  register struct RxsLib * const __DeleteArgstring__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register STRPTR __DeleteArgstring_argstring __asm("a0") = (_DeleteArgstring_argstring); \
  __asm volatile ("jsr a6@(-132:W)" \
  : \
  : "r"(__DeleteArgstring__bn), "r"(__DeleteArgstring_argstring) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define LengthArgstring(argstring) ({ \
  CONST_STRPTR _LengthArgstring_argstring = (argstring); \
  LONG _LengthArgstring__re = \
  ({ \
  register struct RxsLib * const __LengthArgstring__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register LONG __LengthArgstring__re __asm("d0"); \
  register CONST_STRPTR __LengthArgstring_argstring __asm("a0") = (_LengthArgstring_argstring); \
  __asm volatile ("jsr a6@(-138:W)" \
  : "=r"(__LengthArgstring__re) \
  : "r"(__LengthArgstring__bn), "r"(__LengthArgstring_argstring) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LengthArgstring__re; \
  }); \
  _LengthArgstring__re; \
})

#define CreateRexxMsg(port, extension, host) ({ \
  struct MsgPort * _CreateRexxMsg_port = (port); \
  STRPTR _CreateRexxMsg_extension = (extension); \
  STRPTR _CreateRexxMsg_host = (host); \
  struct RexxMsg * _CreateRexxMsg__re = \
  ({ \
  register struct RxsLib * const __CreateRexxMsg__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register struct RexxMsg * __CreateRexxMsg__re __asm("d0"); \
  register struct MsgPort * __CreateRexxMsg_port __asm("a0") = (_CreateRexxMsg_port); \
  register STRPTR __CreateRexxMsg_extension __asm("a1") = (_CreateRexxMsg_extension); \
  register STRPTR __CreateRexxMsg_host __asm("d0") = (_CreateRexxMsg_host); \
  __asm volatile ("jsr a6@(-144:W)" \
  : "=r"(__CreateRexxMsg__re) \
  : "r"(__CreateRexxMsg__bn), "r"(__CreateRexxMsg_port), "r"(__CreateRexxMsg_extension), "r"(__CreateRexxMsg_host) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateRexxMsg__re; \
  }); \
  _CreateRexxMsg__re; \
})

#define DeleteRexxMsg(packet) ({ \
  struct RexxMsg * _DeleteRexxMsg_packet = (packet); \
  { \
  register struct RxsLib * const __DeleteRexxMsg__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register struct RexxMsg * __DeleteRexxMsg_packet __asm("a0") = (_DeleteRexxMsg_packet); \
  __asm volatile ("jsr a6@(-150:W)" \
  : \
  : "r"(__DeleteRexxMsg__bn), "r"(__DeleteRexxMsg_packet) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define ClearRexxMsg(msgptr, count) ({ \
  struct RexxMsg * _ClearRexxMsg_msgptr = (msgptr); \
  ULONG _ClearRexxMsg_count = (count); \
  { \
  register struct RxsLib * const __ClearRexxMsg__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register struct RexxMsg * __ClearRexxMsg_msgptr __asm("a0") = (_ClearRexxMsg_msgptr); \
  register ULONG __ClearRexxMsg_count __asm("d0") = (_ClearRexxMsg_count); \
  __asm volatile ("jsr a6@(-156:W)" \
  : \
  : "r"(__ClearRexxMsg__bn), "r"(__ClearRexxMsg_msgptr), "r"(__ClearRexxMsg_count) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define FillRexxMsg(msgptr, count, mask) ({ \
  struct RexxMsg * _FillRexxMsg_msgptr = (msgptr); \
  ULONG _FillRexxMsg_count = (count); \
  ULONG _FillRexxMsg_mask = (mask); \
  BOOL _FillRexxMsg__re = \
  ({ \
  register struct RxsLib * const __FillRexxMsg__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register BOOL __FillRexxMsg__re __asm("d0"); \
  register struct RexxMsg * __FillRexxMsg_msgptr __asm("a0") = (_FillRexxMsg_msgptr); \
  register ULONG __FillRexxMsg_count __asm("d0") = (_FillRexxMsg_count); \
  register ULONG __FillRexxMsg_mask __asm("d1") = (_FillRexxMsg_mask); \
  __asm volatile ("jsr a6@(-162:W)" \
  : "=r"(__FillRexxMsg__re) \
  : "r"(__FillRexxMsg__bn), "r"(__FillRexxMsg_msgptr), "r"(__FillRexxMsg_count), "r"(__FillRexxMsg_mask) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __FillRexxMsg__re; \
  }); \
  _FillRexxMsg__re; \
})

#define IsRexxMsg(msgptr) ({ \
  struct RexxMsg * _IsRexxMsg_msgptr = (msgptr); \
  BOOL _IsRexxMsg__re = \
  ({ \
  register struct RxsLib * const __IsRexxMsg__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register BOOL __IsRexxMsg__re __asm("d0"); \
  register struct RexxMsg * __IsRexxMsg_msgptr __asm("a0") = (_IsRexxMsg_msgptr); \
  __asm volatile ("jsr a6@(-168:W)" \
  : "=r"(__IsRexxMsg__re) \
  : "r"(__IsRexxMsg__bn), "r"(__IsRexxMsg_msgptr) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __IsRexxMsg__re; \
  }); \
  _IsRexxMsg__re; \
})

#define LockRexxBase(resource) ({ \
  ULONG _LockRexxBase_resource = (resource); \
  { \
  register struct RxsLib * const __LockRexxBase__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register ULONG __LockRexxBase_resource __asm("d0") = (_LockRexxBase_resource); \
  __asm volatile ("jsr a6@(-450:W)" \
  : \
  : "r"(__LockRexxBase__bn), "r"(__LockRexxBase_resource) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define UnlockRexxBase(resource) ({ \
  ULONG _UnlockRexxBase_resource = (resource); \
  { \
  register struct RxsLib * const __UnlockRexxBase__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register ULONG __UnlockRexxBase_resource __asm("d0") = (_UnlockRexxBase_resource); \
  __asm volatile ("jsr a6@(-456:W)" \
  : \
  : "r"(__UnlockRexxBase__bn), "r"(__UnlockRexxBase_resource) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define CreateRexxHostPort(base_name) ({ \
  STRPTR _CreateRexxHostPort_base_name = (base_name); \
  struct MsgPort * _CreateRexxHostPort__re = \
  ({ \
  register struct RxsLib * const __CreateRexxHostPort__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register struct MsgPort * __CreateRexxHostPort__re __asm("d0"); \
  register STRPTR __CreateRexxHostPort_base_name __asm("a0") = (_CreateRexxHostPort_base_name); \
  __asm volatile ("jsr a6@(-480:W)" \
  : "=r"(__CreateRexxHostPort__re) \
  : "r"(__CreateRexxHostPort__bn), "r"(__CreateRexxHostPort_base_name) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __CreateRexxHostPort__re; \
  }); \
  _CreateRexxHostPort__re; \
})

#define DeleteRexxHostPort(port) ({ \
  struct MsgPort * _DeleteRexxHostPort_port = (port); \
  { \
  register struct RxsLib * const __DeleteRexxHostPort__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register struct MsgPort * __DeleteRexxHostPort_port __asm("a0") = (_DeleteRexxHostPort_port); \
  __asm volatile ("jsr a6@(-486:W)" \
  : \
  : "r"(__DeleteRexxHostPort__bn), "r"(__DeleteRexxHostPort_port) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#define GetRexxVarFromMsg(name, buffer, message) ({ \
  STRPTR _GetRexxVarFromMsg_name = (name); \
  STRPTR _GetRexxVarFromMsg_buffer = (buffer); \
  struct RexxMsg * _GetRexxVarFromMsg_message = (message); \
  LONG _GetRexxVarFromMsg__re = \
  ({ \
  register struct RxsLib * const __GetRexxVarFromMsg__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register LONG __GetRexxVarFromMsg__re __asm("d0"); \
  register STRPTR __GetRexxVarFromMsg_name __asm("a0") = (_GetRexxVarFromMsg_name); \
  register STRPTR __GetRexxVarFromMsg_buffer __asm("a1") = (_GetRexxVarFromMsg_buffer); \
  register struct RexxMsg * __GetRexxVarFromMsg_message __asm("a2") = (_GetRexxVarFromMsg_message); \
  __asm volatile ("jsr a6@(-492:W)" \
  : "=r"(__GetRexxVarFromMsg__re) \
  : "r"(__GetRexxVarFromMsg__bn), "r"(__GetRexxVarFromMsg_name), "r"(__GetRexxVarFromMsg_buffer), "r"(__GetRexxVarFromMsg_message) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __GetRexxVarFromMsg__re; \
  }); \
  _GetRexxVarFromMsg__re; \
})

#define SetRexxVarFromMsg(name, value, message) ({ \
  STRPTR _SetRexxVarFromMsg_name = (name); \
  STRPTR _SetRexxVarFromMsg_value = (value); \
  struct RexxMsg * _SetRexxVarFromMsg_message = (message); \
  LONG _SetRexxVarFromMsg__re = \
  ({ \
  register struct RxsLib * const __SetRexxVarFromMsg__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register LONG __SetRexxVarFromMsg__re __asm("d0"); \
  register STRPTR __SetRexxVarFromMsg_name __asm("a0") = (_SetRexxVarFromMsg_name); \
  register STRPTR __SetRexxVarFromMsg_value __asm("a1") = (_SetRexxVarFromMsg_value); \
  register struct RexxMsg * __SetRexxVarFromMsg_message __asm("a2") = (_SetRexxVarFromMsg_message); \
  __asm volatile ("jsr a6@(-498:W)" \
  : "=r"(__SetRexxVarFromMsg__re) \
  : "r"(__SetRexxVarFromMsg__bn), "r"(__SetRexxVarFromMsg_name), "r"(__SetRexxVarFromMsg_value), "r"(__SetRexxVarFromMsg_message) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __SetRexxVarFromMsg__re; \
  }); \
  _SetRexxVarFromMsg__re; \
})

#define LaunchRexxScript(script_name, host_port, extension, input_handle, output_handle) ({ \
  STRPTR _LaunchRexxScript_script_name = (script_name); \
  struct MsgPort * _LaunchRexxScript_host_port = (host_port); \
  STRPTR _LaunchRexxScript_extension = (extension); \
  BPTR _LaunchRexxScript_input_handle = (input_handle); \
  BPTR _LaunchRexxScript_output_handle = (output_handle); \
  struct RexxMsg * _LaunchRexxScript__re = \
  ({ \
  register struct RxsLib * const __LaunchRexxScript__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register struct RexxMsg * __LaunchRexxScript__re __asm("d0"); \
  register STRPTR __LaunchRexxScript_script_name __asm("a0") = (_LaunchRexxScript_script_name); \
  register struct MsgPort * __LaunchRexxScript_host_port __asm("a1") = (_LaunchRexxScript_host_port); \
  register STRPTR __LaunchRexxScript_extension __asm("a2") = (_LaunchRexxScript_extension); \
  register BPTR __LaunchRexxScript_input_handle __asm("d1") = (_LaunchRexxScript_input_handle); \
  register BPTR __LaunchRexxScript_output_handle __asm("d2") = (_LaunchRexxScript_output_handle); \
  __asm volatile ("jsr a6@(-504:W)" \
  : "=r"(__LaunchRexxScript__re) \
  : "r"(__LaunchRexxScript__bn), "r"(__LaunchRexxScript_script_name), "r"(__LaunchRexxScript_host_port), "r"(__LaunchRexxScript_extension), "r"(__LaunchRexxScript_input_handle), "r"(__LaunchRexxScript_output_handle) \
  : "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  __LaunchRexxScript__re; \
  }); \
  _LaunchRexxScript__re; \
})

#define FreeRexxMsg(message) ({ \
  struct RexxMsg * _FreeRexxMsg_message = (message); \
  { \
  register struct RxsLib * const __FreeRexxMsg__bn __asm("a6") = (struct RxsLib *) (REXXSYSLIB_BASE_NAME);\
  register struct RexxMsg * __FreeRexxMsg_message __asm("a0") = (_FreeRexxMsg_message); \
  __asm volatile ("jsr a6@(-510:W)" \
  : \
  : "r"(__FreeRexxMsg__bn), "r"(__FreeRexxMsg_message) \
  : "d0", "d1", "a0", "a1", "fp0", "fp1", "cc", "memory"); \
  } \
})

#endif /*  _INLINE_REXXSYSLIB_H  */
