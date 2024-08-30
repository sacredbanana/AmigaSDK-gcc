/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_DEVICEIO_H
#define _PPCINLINE_DEVICEIO_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef DEVICEIO_BASE_NAME
#define DEVICEIO_BASE_NAME DeviceIOBase
#endif /* !DEVICEIO_BASE_NAME */

#define DIO_WriteBytes(__p0, __p1, __p2, __p3, __p4) \
	(((LONG (*)(void *, struct DeviceIO *, DBLCK , UBYTE *, UWORD , UWORD ))*(void**)((long)(DEVICEIO_BASE_NAME) - 148))((void*)(DEVICEIO_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define DIO_CleanupDeviceIO(__p0) \
	(((VOID (*)(void *, struct DeviceIO *))*(void**)((long)(DEVICEIO_BASE_NAME) - 76))((void*)(DEVICEIO_BASE_NAME), __p0))

#define DIO_Dump(__p0) \
	(((VOID (*)(void *, struct DeviceIO *))*(void**)((long)(DEVICEIO_BASE_NAME) - 190))((void*)(DEVICEIO_BASE_NAME), __p0))

#define DIO_SetAbort(__p0, __p1) \
	(((VOID (*)(void *, struct DeviceIO *, BOOL ))*(void**)((long)(DEVICEIO_BASE_NAME) - 184))((void*)(DEVICEIO_BASE_NAME), __p0, __p1))

#define DIO_QueryDeviceIOA(__p0, __p1) \
	(((VOID (*)(void *, struct DeviceIO *, struct TagItem *))*(void**)((long)(DEVICEIO_BASE_NAME) - 82))((void*)(DEVICEIO_BASE_NAME), __p0, __p1))

#define DIO_FlushIOCache(__p0) \
	(((LONG (*)(void *, struct DeviceIO *))*(void**)((long)(DEVICEIO_BASE_NAME) - 124))((void*)(DEVICEIO_BASE_NAME), __p0))

#define DIO_AllocateBlocksV(__p0, __p1) \
	(((UBYTE *(*)(void *, struct DeviceIO *, ULONG ))*(void**)((long)(DEVICEIO_BASE_NAME) - 160))((void*)(DEVICEIO_BASE_NAME), __p0, __p1))

#define DIO_ReadBytes(__p0, __p1, __p2, __p3, __p4) \
	(((LONG (*)(void *, struct DeviceIO *, DBLCK , UBYTE *, UWORD , UWORD ))*(void**)((long)(DEVICEIO_BASE_NAME) - 136))((void*)(DEVICEIO_BASE_NAME), __p0, __p1, __p2, __p3, __p4))

#define DIO_FreeBlocksV(__p0, __p1) \
	(((VOID (*)(void *, struct DeviceIO *, APTR ))*(void**)((long)(DEVICEIO_BASE_NAME) - 172))((void*)(DEVICEIO_BASE_NAME), __p0, __p1))

#define DIO_SetIOCache(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, struct DeviceIO *, ULONG , ULONG , BOOL ))*(void**)((long)(DEVICEIO_BASE_NAME) - 118))((void*)(DEVICEIO_BASE_NAME), __p0, __p1, __p2, __p3))

#define DIO_WriteProtection(__p0) \
	(((LONG (*)(void *, struct DeviceIO *))*(void**)((long)(DEVICEIO_BASE_NAME) - 94))((void*)(DEVICEIO_BASE_NAME), __p0))

#define DIO_SetDeviceIOA(__p0, __p1) \
	(((LONG (*)(void *, struct DeviceIO *, CONST struct TagItem *))*(void**)((long)(DEVICEIO_BASE_NAME) - 88))((void*)(DEVICEIO_BASE_NAME), __p0, __p1))

#define DIO_Update(__p0) \
	(((VOID (*)(void *, struct DeviceIO *))*(void**)((long)(DEVICEIO_BASE_NAME) - 100))((void*)(DEVICEIO_BASE_NAME), __p0))

#define DIO_AllocateBlocks(__p0, __p1) \
	(((UBYTE *(*)(void *, struct DeviceIO *, ULONG ))*(void**)((long)(DEVICEIO_BASE_NAME) - 154))((void*)(DEVICEIO_BASE_NAME), __p0, __p1))

#define DIO_InitDeviceIOA(__p0, __p1) \
	(((struct DeviceIO *(*)(void *, CONST_STRPTR , CONST struct TagItem *))*(void**)((long)(DEVICEIO_BASE_NAME) - 70))((void*)(DEVICEIO_BASE_NAME), __p0, __p1))

#define DIO_WriteBlocks(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, struct DeviceIO *, DBLCK , UBYTE *, ULONG ))*(void**)((long)(DEVICEIO_BASE_NAME) - 142))((void*)(DEVICEIO_BASE_NAME), __p0, __p1, __p2, __p3))

#define DIO_ReadBlocks(__p0, __p1, __p2, __p3) \
	(((LONG (*)(void *, struct DeviceIO *, DBLCK , UBYTE *, ULONG ))*(void**)((long)(DEVICEIO_BASE_NAME) - 130))((void*)(DEVICEIO_BASE_NAME), __p0, __p1, __p2, __p3))

#define DIO_FlushBlocks(__p0, __p1, __p2) \
	(((LONG (*)(void *, struct DeviceIO *, ULONG , ULONG ))*(void**)((long)(DEVICEIO_BASE_NAME) - 196))((void*)(DEVICEIO_BASE_NAME), __p0, __p1, __p2))

#define DIO_Abort(__p0) \
	(((BOOL (*)(void *, struct DeviceIO *))*(void**)((long)(DEVICEIO_BASE_NAME) - 178))((void*)(DEVICEIO_BASE_NAME), __p0))

#define DIO_MotorOFF(__p0) \
	(((VOID (*)(void *, struct DeviceIO *))*(void**)((long)(DEVICEIO_BASE_NAME) - 106))((void*)(DEVICEIO_BASE_NAME), __p0))

#define DIO_IsDiskPresent(__p0) \
	(((UBYTE (*)(void *, struct DeviceIO *))*(void**)((long)(DEVICEIO_BASE_NAME) - 112))((void*)(DEVICEIO_BASE_NAME), __p0))

#define DIO_FreeBlocks(__p0, __p1) \
	(((VOID (*)(void *, struct DeviceIO *, APTR ))*(void**)((long)(DEVICEIO_BASE_NAME) - 166))((void*)(DEVICEIO_BASE_NAME), __p0, __p1))

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define DIO_SetDeviceIO(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DIO_SetDeviceIOA(__p0, (CONST struct TagItem *)_tags);})

#define DIO_QueryDeviceIO(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DIO_QueryDeviceIOA(__p0, (struct TagItem *)_tags);})

#define DIO_InitDeviceIO(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DIO_InitDeviceIOA(__p0, (CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_DEVICEIO_H */
