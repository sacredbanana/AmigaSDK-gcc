/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_CARD_H
#define _INLINE_CARD_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

struct CardHandle * __OwnCard(__reg("a6") struct Library * , __reg("a1") struct CardHandle * handle ) = "\tjsr\t-6(a6)";
#define OwnCard(handle) __OwnCard(CardResourceBase, (handle))

VOID __ReleaseCard(__reg("a6") struct Library * , __reg("a1") struct CardHandle * handle , __reg("d0") ULONG flags ) = "\tjsr\t-12(a6)";
#define ReleaseCard(handle, flags) __ReleaseCard(CardResourceBase, (handle), (flags))

struct CardMemoryMap * __GetCardMap(__reg("a6") struct Library * ) = "\tjsr\t-18(a6)";
#define GetCardMap() __GetCardMap(CardResourceBase)

BOOL __BeginCardAccess(__reg("a6") struct Library * , __reg("a1") struct CardHandle * handle ) = "\tjsr\t-24(a6)";
#define BeginCardAccess(handle) __BeginCardAccess(CardResourceBase, (handle))

BOOL __EndCardAccess(__reg("a6") struct Library * , __reg("a1") struct CardHandle * handle ) = "\tjsr\t-30(a6)";
#define EndCardAccess(handle) __EndCardAccess(CardResourceBase, (handle))

UBYTE __ReadCardStatus(__reg("a6") struct Library * ) = "\tjsr\t-36(a6)";
#define ReadCardStatus() __ReadCardStatus(CardResourceBase)

BOOL __CardResetRemove(__reg("a6") struct Library * , __reg("a1") struct CardHandle * handle , __reg("d0") ULONG flag ) = "\tjsr\t-42(a6)";
#define CardResetRemove(handle, flag) __CardResetRemove(CardResourceBase, (handle), (flag))

UBYTE __CardMiscControl(__reg("a6") struct Library * , __reg("a1") struct CardHandle * handle , __reg("d1") UBYTE control_bits ) = "\tjsr\t-48(a6)";
#define CardMiscControl(handle, control_bits) __CardMiscControl(CardResourceBase, (handle), (control_bits))

ULONG __CardAccessSpeed(__reg("a6") struct Library * , __reg("a1") struct CardHandle * handle , __reg("d0") ULONG nanoseconds ) = "\tjsr\t-54(a6)";
#define CardAccessSpeed(handle, nanoseconds) __CardAccessSpeed(CardResourceBase, (handle), (nanoseconds))

LONG __CardProgramVoltage(__reg("a6") struct Library * , __reg("a1") struct CardHandle * handle , __reg("d0") ULONG voltage ) = "\tjsr\t-60(a6)";
#define CardProgramVoltage(handle, voltage) __CardProgramVoltage(CardResourceBase, (handle), (voltage))

BOOL __CardResetCard(__reg("a6") struct Library * , __reg("a1") struct CardHandle * handle ) = "\tjsr\t-66(a6)";
#define CardResetCard(handle) __CardResetCard(CardResourceBase, (handle))

BOOL __CopyTuple(__reg("a6") struct Library * , __reg("a1") struct CardHandle * handle , __reg("a0") UBYTE * buffer , __reg("d1") ULONG tuplecode , __reg("d0") ULONG size ) = "\tjsr\t-72(a6)";
#define CopyTuple(handle, buffer, tuplecode, size) __CopyTuple(CardResourceBase, (handle), (buffer), (tuplecode), (size))

ULONG __DeviceTuple(__reg("a6") struct Library * , __reg("a0") CONST UBYTE * tuple_data , __reg("a1") struct DeviceTData * storage ) = "\tjsr\t-78(a6)";
#define DeviceTuple(tuple_data, storage) __DeviceTuple(CardResourceBase, (tuple_data), (storage))

struct Resident * __IfAmigaXIP(__reg("a6") struct Library * , __reg("a2") struct CardHandle * handle ) = "\tjsr\t-84(a6)";
#define IfAmigaXIP(handle) __IfAmigaXIP(CardResourceBase, (handle))

BOOL __CardForceChange(__reg("a6") struct Library * ) = "\tjsr\t-90(a6)";
#define CardForceChange() __CardForceChange(CardResourceBase)

ULONG __CardChangeCount(__reg("a6") struct Library * ) = "\tjsr\t-96(a6)";
#define CardChangeCount() __CardChangeCount(CardResourceBase)

ULONG __CardInterface(__reg("a6") struct Library * ) = "\tjsr\t-102(a6)";
#define CardInterface() __CardInterface(CardResourceBase)

#endif /* !_INLINE_CARD_H */
