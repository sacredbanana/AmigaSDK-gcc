#ifndef PRAGMA_DATATYPES_LIB_H
#define PRAGMA_DATATYPES_LIB_H

/*
**	$VER: datatypes_lib.h 47.1 (30.11.2021)
**
**	Aztec 'C', Maxon 'C' and StormC format pragma files.
*/

#ifndef CLIB_DATATYPES_PROTOS_H
#include <clib/datatypes_protos.h>
#endif /* CLIB_DATATYPES_PROTOS_H */

/* "datatypes.library" */
/*--- functions in V40 or higher (Release 3.1) ---*/
/* ARexx function host entry point */

/* Public entries */

#pragma amicall(DataTypesBase, 0x24, ObtainDataTypeA(d0,a0,a1))
#if defined(__STORM__)
#pragma tagcall(DataTypesBase, 0x24, ObtainDataType(d0,a0,a1))
#endif /* __STORM__ */
#pragma amicall(DataTypesBase, 0x2a, ReleaseDataType(a0))
#pragma amicall(DataTypesBase, 0x30, NewDTObjectA(d0,a0))
#if defined(__STORM__)
#pragma tagcall(DataTypesBase, 0x30, NewDTObject(d0,a0))
#endif /* __STORM__ */
#pragma amicall(DataTypesBase, 0x36, DisposeDTObject(a0))
#pragma amicall(DataTypesBase, 0x3c, SetDTAttrsA(a0,a1,a2,a3))
#if defined(__STORM__)
#pragma tagcall(DataTypesBase, 0x3c, SetDTAttrs(a0,a1,a2,a3))
#endif /* __STORM__ */
#pragma amicall(DataTypesBase, 0x42, GetDTAttrsA(a0,a2))
#if defined(__STORM__)
#pragma tagcall(DataTypesBase, 0x42, GetDTAttrs(a0,a2))
#endif /* __STORM__ */
#pragma amicall(DataTypesBase, 0x48, AddDTObject(a0,a1,a2,d0))
#pragma amicall(DataTypesBase, 0x4e, RefreshDTObjectA(a0,a1,a2,a3))
#if defined(__STORM__)
#pragma tagcall(DataTypesBase, 0x4e, RefreshDTObjects(a0,a1,a2,a3))
#endif /* __STORM__ */
#if defined(__STORM__)
#pragma tagcall(DataTypesBase, 0x4e, RefreshDTObject(a0,a1,a2,a3))
#endif /* __STORM__ */
#pragma amicall(DataTypesBase, 0x54, DoAsyncLayout(a0,a1))
#pragma amicall(DataTypesBase, 0x5a, DoDTMethodA(a0,a1,a2,a3))
#if defined(__STORM__)
#pragma tagcall(DataTypesBase, 0x5a, DoDTMethod(a0,a1,a2,a3))
#endif /* __STORM__ */
#pragma amicall(DataTypesBase, 0x60, RemoveDTObject(a0,a1))
#pragma amicall(DataTypesBase, 0x66, GetDTMethods(a0))
#pragma amicall(DataTypesBase, 0x6c, GetDTTriggerMethods(a0))
#pragma amicall(DataTypesBase, 0x72, PrintDTObjectA(a0,a1,a2,a3))
#if defined(__STORM__)
#pragma tagcall(DataTypesBase, 0x72, PrintDTObject(a0,a1,a2,a3))
#endif /* __STORM__ */
#pragma amicall(DataTypesBase, 0x8a, GetDTString(d0))
/*--- (19 function slots reserved here) ---*/
/*--- functions in V45 or higher ---*/
#pragma amicall(DataTypesBase, 0x102, FindMethod(a0,a1))
#pragma amicall(DataTypesBase, 0x108, FindTriggerMethod(a0,a1,d0))
#pragma amicall(DataTypesBase, 0x10e, CopyDTMethods(a0,a1,a2))
#pragma amicall(DataTypesBase, 0x114, CopyDTTriggerMethods(a0,a1,a2))
#pragma amicall(DataTypesBase, 0x11a, FreeDTMethods(a0))
#pragma amicall(DataTypesBase, 0x120, GetDTTriggerMethodDataFlags(d0))
#pragma amicall(DataTypesBase, 0x126, SaveDTObjectA(a0,a1,a2,a3,d0,d1,a4))
#if defined(__STORM__)
#pragma tagcall(DataTypesBase, 0x126, SaveDTObject(a0,a1,a2,a3,d0,d1,a4))
#endif /* __STORM__ */
#pragma amicall(DataTypesBase, 0x12c, StartDragSelect(a0))
/*--- (3 function slots reserved here) ---*/

#endif /* PRAGMA_DATATYPES_LIB_H */
