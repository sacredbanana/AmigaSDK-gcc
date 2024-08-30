/* Automatically generated header (sfdc 1.11f)! Do not edit! */

#ifndef _INLINE_MHI_H
#define _INLINE_MHI_H

#ifndef _SFDC_VARARG_DEFINED
#define _SFDC_VARARG_DEFINED
#ifdef __HAVE_IPTR_ATTR__
typedef APTR _sfdc_vararg __attribute__((iptr));
#else
typedef ULONG _sfdc_vararg;
#endif /* __HAVE_IPTR_ATTR__ */
#endif /* _SFDC_VARARG_DEFINED */

APTR __MHIAllocDecoder(__reg("a6") struct Library * , __reg("a0") struct Task * task , __reg("d0") ULONG mhisignal ) = "\tjsr\t-30(a6)";
#define MHIAllocDecoder(task, mhisignal) __MHIAllocDecoder(MHIBase, (task), (mhisignal))

VOID __MHIFreeDecoder(__reg("a6") struct Library * , __reg("a3") APTR handle ) = "\tjsr\t-36(a6)";
#define MHIFreeDecoder(handle) __MHIFreeDecoder(MHIBase, (handle))

BOOL __MHIQueueBuffer(__reg("a6") struct Library * , __reg("a3") APTR handle , __reg("a0") APTR buffer , __reg("d0") ULONG size ) = "\tjsr\t-42(a6)";
#define MHIQueueBuffer(handle, buffer, size) __MHIQueueBuffer(MHIBase, (handle), (buffer), (size))

APTR __MHIGetEmpty(__reg("a6") struct Library * , __reg("a3") APTR handle ) = "\tjsr\t-48(a6)";
#define MHIGetEmpty(handle) __MHIGetEmpty(MHIBase, (handle))

UBYTE __MHIGetStatus(__reg("a6") struct Library * , __reg("a3") APTR handle ) = "\tjsr\t-54(a6)";
#define MHIGetStatus(handle) __MHIGetStatus(MHIBase, (handle))

VOID __MHIPlay(__reg("a6") struct Library * , __reg("a3") APTR handle ) = "\tjsr\t-60(a6)";
#define MHIPlay(handle) __MHIPlay(MHIBase, (handle))

VOID __MHIStop(__reg("a6") struct Library * , __reg("a3") APTR handle ) = "\tjsr\t-66(a6)";
#define MHIStop(handle) __MHIStop(MHIBase, (handle))

VOID __MHIPause(__reg("a6") struct Library * , __reg("a3") APTR handle ) = "\tjsr\t-72(a6)";
#define MHIPause(handle) __MHIPause(MHIBase, (handle))

ULONG __MHIQuery(__reg("a6") struct Library * , __reg("d1") ULONG query ) = "\tjsr\t-78(a6)";
#define MHIQuery(query) __MHIQuery(MHIBase, (query))

VOID __MHISetParam(__reg("a6") struct Library * , __reg("a3") APTR handle , __reg("d0") UWORD param , __reg("d1") ULONG value ) = "\tjsr\t-84(a6)";
#define MHISetParam(handle, param, value) __MHISetParam(MHIBase, (handle), (param), (value))

#endif /* !_INLINE_MHI_H */
