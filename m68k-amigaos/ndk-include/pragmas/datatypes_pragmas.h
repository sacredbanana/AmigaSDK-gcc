#ifndef PRAGMAS_DATATYPES_PRAGMAS_H
#define PRAGMAS_DATATYPES_PRAGMAS_H

/*
**	$VER: datatypes_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_DATATYPES_PROTOS_H
#include <clib/datatypes_protos.h>
#endif /* CLIB_DATATYPES_PROTOS_H */

/* "datatypes.library" */
/*--- functions in V40 or higher (Release 3.1) ---*/
/* ARexx function host entry point */

/* Public entries */

#pragma libcall DataTypesBase ObtainDataTypeA 24 98003
#if defined(__SASC_60)
#pragma tagcall DataTypesBase ObtainDataType 24 98003
#endif /* __SASC_60 */
#pragma libcall DataTypesBase ReleaseDataType 2a 801
#pragma libcall DataTypesBase NewDTObjectA 30 8002
#if defined(__SASC_60)
#pragma tagcall DataTypesBase NewDTObject 30 8002
#endif /* __SASC_60 */
#pragma libcall DataTypesBase DisposeDTObject 36 801
#pragma libcall DataTypesBase SetDTAttrsA 3c BA9804
#if defined(__SASC_60)
#pragma tagcall DataTypesBase SetDTAttrs 3c BA9804
#endif /* __SASC_60 */
#pragma libcall DataTypesBase GetDTAttrsA 42 A802
#if defined(__SASC_60)
#pragma tagcall DataTypesBase GetDTAttrs 42 A802
#endif /* __SASC_60 */
#pragma libcall DataTypesBase AddDTObject 48 0A9804
#pragma libcall DataTypesBase RefreshDTObjectA 4e BA9804
#if defined(__SASC_60)
#pragma tagcall DataTypesBase RefreshDTObjects 4e BA9804
#endif /* __SASC_60 */
#if defined(__SASC_60)
#pragma tagcall DataTypesBase RefreshDTObject 4e BA9804
#endif /* __SASC_60 */
#pragma libcall DataTypesBase DoAsyncLayout 54 9802
#pragma libcall DataTypesBase DoDTMethodA 5a BA9804
#if defined(__SASC_60)
#pragma tagcall DataTypesBase DoDTMethod 5a BA9804
#endif /* __SASC_60 */
#pragma libcall DataTypesBase RemoveDTObject 60 9802
#pragma libcall DataTypesBase GetDTMethods 66 801
#pragma libcall DataTypesBase GetDTTriggerMethods 6c 801
#pragma libcall DataTypesBase PrintDTObjectA 72 BA9804
#if defined(__SASC_60)
#pragma tagcall DataTypesBase PrintDTObject 72 BA9804
#endif /* __SASC_60 */
#pragma libcall DataTypesBase GetDTString 8a 001
/*--- (19 function slots reserved here) ---*/
/*--- functions in V45 or higher ---*/
#pragma libcall DataTypesBase FindMethod 102 9802
#pragma libcall DataTypesBase FindTriggerMethod 108 09803
#pragma libcall DataTypesBase CopyDTMethods 10e A9803
#pragma libcall DataTypesBase CopyDTTriggerMethods 114 A9803
#pragma libcall DataTypesBase FreeDTMethods 11a 801
#pragma libcall DataTypesBase GetDTTriggerMethodDataFlags 120 001
#pragma libcall DataTypesBase SaveDTObjectA 126 C10BA9807
#if defined(__SASC_60)
#pragma tagcall DataTypesBase SaveDTObject 126 C10BA9807
#endif /* __SASC_60 */
#pragma libcall DataTypesBase StartDragSelect 12c 801
/*--- (3 function slots reserved here) ---*/

#endif /* PRAGMAS_DATATYPES_PRAGMAS_H */
