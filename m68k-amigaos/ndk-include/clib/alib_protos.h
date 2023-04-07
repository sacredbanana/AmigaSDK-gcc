#ifndef  CLIB_ALIB_PROTOS_H
#define  CLIB_ALIB_PROTOS_H

/*
**	$VER: alib_protos.h 47.2 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef  DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef  DEVICES_KEYMAP_H
#include <devices/keymap.h>
#endif
#ifndef  LIBRARIES_COMMODITIES_H
#include <libraries/commodities.h>
#endif
#ifndef  UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
#ifndef  GRAPHICS_GRAPHINT_H
#include <graphics/graphint.h>
#endif
#ifndef  REXX_STORAGE_H
#include <rexx/storage.h>
#endif

/*  Exec support functions */

VOID  __stdargs BeginIO( struct IORequest *ioReq );
struct IORequest * __stdargs CreateExtIO( CONST struct MsgPort *port, LONG ioSize );
struct MsgPort * __stdargs CreatePort( CONST_STRPTR name, LONG pri );
struct IOStdReq * __stdargs CreateStdIO( CONST struct MsgPort *port );
struct Task * __stdargs CreateTask( CONST_STRPTR name, LONG pri, APTR initPC, ULONG stackSize );
VOID  __stdargs DeleteExtIO( struct IORequest *ioReq );
VOID  __stdargs DeletePort( struct MsgPort *ioReq );
VOID  __stdargs DeleteStdIO( struct IOStdReq *ioReq );
VOID  __stdargs DeleteTask( struct Task *task );
VOID  __stdargs NewList( struct List *list );
APTR  __stdargs LibAllocPooled( APTR poolHeader, ULONG memSize );
APTR  __stdargs LibCreatePool( ULONG memFlags, ULONG puddleSize, ULONG threshSize );
VOID  __stdargs LibDeletePool( APTR poolHeader );
VOID  __stdargs LibFreePooled( APTR poolHeader, APTR memory, ULONG memSize );

/* Assorted functions in amiga.lib */

ULONG  __stdargs FastRand( ULONG seed );
UWORD  __stdargs RangeRand( ULONG maxValue );

/* Graphics support functions in amiga.lib */

VOID  __stdargs AddTOF( struct Isrvstr *i, LONG (*p)(APTR args), APTR a );
VOID  __stdargs RemTOF( struct Isrvstr *i );
VOID  __stdargs waitbeam( LONG b );

/* math support functions in amiga.lib */

FLOAT  __stdargs afp( CONST_STRPTR string );
VOID  __stdargs arnd( LONG place, LONG exponent, STRPTR string );
FLOAT  __stdargs dbf( ULONG exponent_base10, ULONG mant );
LONG  __stdargs fpa( FLOAT fnum, STRPTR string );
VOID  __stdargs fpbcd( FLOAT fnum, STRPTR string );

/* Timer support functions in amiga.lib (V36 and higher only) */

LONG  __stdargs TimeDelay( LONG unit, ULONG secs, ULONG microsecs );
LONG  __stdargs DoTimer( TimeVal_Type *tv, LONG unit, LONG command );

/*  Commodities functions in amiga.lib (V36 and higher only) */

VOID  __stdargs ArgArrayDone( VOID );
STRPTR * __stdargs ArgArrayInit( LONG argc, CONST_STRPTR *argv );
LONG  __stdargs ArgInt( CONST_STRPTR *tt, CONST_STRPTR entry, LONG defaultval );
STRPTR  __stdargs ArgString( CONST_STRPTR *tt, CONST_STRPTR entry, CONST_STRPTR defaultstring );
CxObj * __stdargs HotKey( CONST_STRPTR description, struct MsgPort *port, LONG id );
struct InputEvent * __stdargs InvertString( CONST_STRPTR str, CONST struct KeyMap *km );
VOID  __stdargs FreeIEvents( struct InputEvent *events );

/* Commodities Macros */

/* CxObj * __stdargs CxCustom(LONG(*)(),LONG id)(A0,D0) */
/* CxObj * __stdargs CxDebug(LONG id)(D0) */
/* CxObj * __stdargs CxFilter(STRPTR description)(A0) */
/* CxObj * __stdargs CxSender(struct MsgPort *port,LONG id)(A0,D0) */
/* CxObj * __stdargs CxSignal(struct Task *task,LONG signal)(A0,D0) */
/* CxObj * __stdargs CxTranslate(struct InputEvent *ie)(A0) */

/*  ARexx support functions in amiga.lib */

BOOL  __stdargs CheckRexxMsg( CONST struct RexxMsg *rexxmsg );
LONG  __stdargs GetRexxVar( CONST struct RexxMsg *rexxmsg, CONST_STRPTR name, STRPTR *result );
LONG  __stdargs SetRexxVar( struct RexxMsg *rexxmsg, CONST_STRPTR name, CONST_STRPTR value, LONG length );

/*  Intuition hook and boopsi support functions in amiga.lib. */
/*  These functions do not require any particular ROM revision */
/*  to operate correctly, though they deal with concepts first introduced */
/*  in V36.  These functions would work with compatibly-implemented */
/*  hooks or objects under V34. */

ULONG  __stdargs CallHookA( struct Hook *hookPtr, Object *obj, APTR message );
ULONG  __stdargs CallHook( struct Hook *hookPtr, Object *obj, ... );
ULONG  __stdargs DoMethodA( Object *obj, Msg message );
ULONG  __stdargs DoMethod( Object *obj, ULONG methodID, ... );
ULONG  __stdargs DoSuperMethodA( struct IClass *cl, Object *obj, Msg message );
ULONG  __stdargs DoSuperMethod( struct IClass *cl, Object *obj, ULONG methodID, ... );
ULONG  __stdargs CoerceMethodA( struct IClass *cl, Object *obj, Msg message );
ULONG  __stdargs CoerceMethod( struct IClass *cl, Object *obj, ULONG methodID, ... );
ULONG  __stdargs HookEntry( struct Hook *hookPtr, Object *obj, APTR message );
ULONG  __stdargs SetSuperAttrs( struct IClass *cl, Object *obj, ULONG tag1, ... );

/*  Network-support functions in amiga.lib. */
/*   __stdargs ACrypt() first appeared in later V39 versions of amiga.lib, but */
/*  operates correctly under V37 and up. */

STRPTR  __stdargs ACrypt( STRPTR buffer, CONST_STRPTR password, CONST_STRPTR username );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* CLIB_ALIB_PROTOS_H */
