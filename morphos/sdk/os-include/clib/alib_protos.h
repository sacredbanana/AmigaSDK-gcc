#ifndef CLIB_ALIB_PROTOS_H
#define CLIB_ALIB_PROTOS_H

/*
	abox.lib C prototypes

	Copyright © 2002-2007 The MorphOS Development Team, All Rights Reserved.
*/


#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef DEVICES_TIMER_H
# include <devices/timer.h>
#endif

#ifndef DEVICES_KEYMAP_H
# include <devices/keymap.h>
#endif

#ifndef LIBRARIES_COMMODITIES_H
# include <libraries/commodities.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#ifndef INTUITION_CLASSES_H
# include <intuition/classes.h>
#endif

#ifndef INTUITION_CLASSUSR_H
# include <intuition/classusr.h>
#endif

#ifndef GRAPHICS_GRAPHINT_H
# include <graphics/graphint.h>
#endif

#ifndef REXX_STORAGE_H
# include <rexx/storage.h>
#endif

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#if !defined(_NO_PPCINLINE) && !defined(__MORPHOS_NODIRECTCALL)
# ifndef EMUL_EMULREGS_H
#  include <emul/emulregs.h>
# endif
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


VOID BeginIO( struct IORequest *ioReq );

#if !defined(_NO_PPCINLINE) && !defined(__MORPHOS_NODIRECTCALL)
#define BeginIO(MyIORequest) \
do { struct IORequest *_MyIORequest = (struct IORequest *)(MyIORequest); \
	REG_A1 = (ULONG) _MyIORequest; \
	REG_A6 = (ULONG) _MyIORequest->io_Device; \
	(*MyEmulHandle->EmulCallDirectOS)(-30); \
} while (0)
#endif /* !_NO_PPCINLINE && !__MORPHOS_NODIRECTCALL */

struct IORequest *CreateExtIO( CONST struct MsgPort *port, LONG ioSize );
struct MsgPort *CreatePort( CONST_STRPTR name, LONG pri );
struct IOStdReq *CreateStdIO( CONST struct MsgPort *port );
struct Task *CreateTask( CONST_STRPTR name, LONG pri, CONST APTR initPC, ULONG stackSize );
VOID DeleteExtIO( struct IORequest *ioReq );
VOID DeletePort( struct MsgPort *ioReq );
VOID DeleteStdIO( struct IOStdReq *ioReq );
VOID DeleteTask( struct Task *task );
VOID NewList( struct List *list );
APTR LibAllocPooled( APTR poolHeader, ULONG memSize );
APTR LibCreatePool( ULONG memFlags, ULONG puddleSize, ULONG threshSize );
VOID LibDeletePool( APTR poolHeader );
VOID LibFreePooled( APTR poolHeader, APTR memory, ULONG memSize );

ULONG FastRand( ULONG seed );
UWORD RangeRand( ULONG maxValue );

VOID AddTOF( struct Isrvstr *i, LONG (*p) __CLIB_PROTOTYPE((APTR args)), APTR a );
VOID RemTOF( struct Isrvstr *i );
VOID waitbeam( LONG b );

FLOAT afp( CONST_STRPTR string );
VOID arnd( LONG place, LONG exp, STRPTR string );
FLOAT dbf( ULONG exp, ULONG mant );
LONG fpa( FLOAT fnum, BYTE *string );
VOID fpbcd( FLOAT fnum, BYTE *string );

LONG TimeDelay( LONG unit, ULONG secs, ULONG microsecs );
LONG DoTimer( struct timeval *, LONG unit, LONG command );

VOID ArgArrayDone( VOID );
STRPTR *ArgArrayInit( LONG argc, CONST_STRPTR *argv );
LONG ArgInt( CONST_STRPTR *tt, CONST_STRPTR entry, LONG defaultval );
STRPTR ArgString( CONST_STRPTR *tt, CONST_STRPTR entry, CONST_STRPTR defaultstring );
CxObj *HotKey( CONST_STRPTR description, struct MsgPort *port, LONG id );
struct InputEvent *InvertString( CONST_STRPTR str, CONST struct KeyMap *km );
VOID FreeIEvents( struct InputEvent *events );

BOOL CheckRexxMsg( CONST struct RexxMsg *rexxmsg );
LONG GetRexxVar( CONST struct RexxMsg *rexxmsg, CONST_STRPTR name, STRPTR *result );
LONG SetRexxVar( struct RexxMsg *rexxmsg, CONST_STRPTR name, CONST_STRPTR value, LONG length );

ULONG CallHookA( struct Hook *hookPtr, Boopsiobject *obj, APTR message );
ULONG DoMethodA( Boopsiobject *obj, Msg message );
ULONG DoSuperMethodA( struct IClass *cl, Boopsiobject *obj, Msg message );
ULONG CoerceMethodA( struct IClass *cl, Boopsiobject *obj, Msg message );
ULONG HookEntry( struct Hook *hookPtr, Boopsiobject *obj, APTR message );

STRPTR ACrypt( STRPTR buffer, CONST_STRPTR password, CONST_STRPTR username );

LONG MakeDirAll( CONST_STRPTR path );
BPTR OpenMakeDir( CONST_STRPTR path, LONG mode );


#if !defined(_NO_PPCINLINE) && !defined(__MORPHOS_NODIRECTCALL) && !defined(__STRICT_ANSI__)

#define CallHookA(MyHook, MyObject, MyMsg) \
({ ULONG ret; \
struct Hook *_MyHook = (struct Hook *)(MyHook); \
ULONG _MyMsg = (ULONG)(MyMsg); \
ULONG _MyObject = (ULONG)(MyObject); \
	REG_A0 = (ULONG)_MyHook; \
	REG_A1 = _MyMsg; \
	REG_A2 = _MyObject; \
	ret = (*MyEmulHandle->EmulCallDirect68k)((void *)_MyHook->h_Entry); \
	ret; \
})

#define DoMethodA(MyObject, MyMsg) \
({ ULONG ret = 0; \
ULONG _MyMsg = (ULONG)(MyMsg); \
ULONG _MyObject = (ULONG)(MyObject); \
	if (_MyObject) \
	{ \
		struct IClass *_MyClass = (struct IClass *)(((ULONG *)_MyObject)[-1]); \
		REG_A0 = (ULONG)_MyClass; \
		REG_A1 = _MyMsg; \
		REG_A2 = _MyObject; \
		ret = (*MyEmulHandle->EmulCallDirect68k)((void *)_MyClass->cl_Dispatcher.h_Entry); \
	} \
	ret; \
})

#define DoSuperMethodA(MyClass, MyObject, MyMsg) \
({ ULONG ret = 0; \
struct IClass *_MyClass = (struct IClass *)(MyClass); \
ULONG _MyMsg = (ULONG)(MyMsg); \
ULONG _MyObject = (ULONG)(MyObject); \
	if (_MyClass && _MyObject) \
	{ \
		REG_A0 = (ULONG)_MyClass->cl_Super; \
		REG_A1 = _MyMsg; \
		REG_A2 = _MyObject; \
		ret = (*MyEmulHandle->EmulCallDirect68k)((void *)_MyClass->cl_Super->cl_Dispatcher.h_Entry); \
	} \
	ret; \
})

#define CoerceMethodA(MyClass, MyObject, MyMsg) \
({ ULONG ret = 0; \
struct IClass *_MyClass = (struct IClass *)(MyClass); \
ULONG _MyMsg = (ULONG)(MyMsg); \
ULONG _MyObject = (ULONG)(MyObject); \
	if (_MyClass && _MyObject) \
	{ \
		REG_A0 = (ULONG)_MyClass; \
		REG_A1 = _MyMsg; \
		REG_A2 = _MyObject; \
		ret = (*MyEmulHandle->EmulCallDirect68k)((void *)_MyClass->cl_Dispatcher.h_Entry); \
	} \
	ret; \
})

#endif /* !_NO_PPCINLINE && !__MORPHOS_NODIRECTCALL && !__STRICT_ANSI__ */


#if !defined(USE_INLINE_STDARG) || defined(__STRICT_ANSI__)

ULONG CallHook( struct Hook *hookPtr, Boopsiobject *obj, ... );
ULONG DoMethod( Boopsiobject *obj, ULONG methodID, ... );
ULONG DoSuperMethod( struct IClass *cl, Boopsiobject *obj, ULONG methodID, ... );
ULONG CoerceMethod( struct IClass *cl, Boopsiobject *obj, ULONG methodID, ... );
ULONG SetSuperAttrs( struct IClass *cl, Boopsiobject *obj, ULONG tag1, ... );
APTR DoSuperNew( struct IClass *cl, APTR obj, ... );

#else

#define CallHook(MyHook, MyObject, ...) \
({ ULONG _tags[] = { __VA_ARGS__ }; CallHookA((MyHook), (MyObject), (APTR)_tags); })

#define DoMethod(MyObject, ...) \
({ ULONG _tags[] = { __VA_ARGS__ }; DoMethodA((MyObject), (APTR)_tags); })

#define DoSuperMethod(MyClass, MyObject, ...) \
({ ULONG _tags[] = { __VA_ARGS__ }; DoSuperMethodA((MyClass), (MyObject), (APTR)_tags); })

#define CoerceMethod(MyClass, MyObject, ...) \
({ ULONG _tags[] = { __VA_ARGS__ }; CoerceMethodA((MyClass), (MyObject), (APTR)_tags); })

#define SetSuperAttrs(MyClass, MyObject, ...) \
({ ULONG _tags[] = { __VA_ARGS__ }; \
struct opSet MyopSet; \
	MyopSet.MethodID = OM_SET; \
	MyopSet.ops_AttrList = (struct TagItem*) _tags; \
	MyopSet.ops_GInfo = NULL; \
	DoSuperMethodA((MyClass), (MyObject), (APTR) &MyopSet); \
})

#define DoSuperNew(MyClass, MyObject, ...) \
({ ULONG _tags[] = { __VA_ARGS__ }; \
struct opSet MyopSet; \
	MyopSet.MethodID = OM_NEW; \
	MyopSet.ops_AttrList = (struct TagItem*) _tags; \
	MyopSet.ops_GInfo = NULL; \
	DoSuperMethodA((MyClass), (MyObject), (APTR) &MyopSet); \
})

#endif /* !USE_INLINE_STDARG || __STRICT_ANSI__ */


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_ALIB_PROTOS_H */
