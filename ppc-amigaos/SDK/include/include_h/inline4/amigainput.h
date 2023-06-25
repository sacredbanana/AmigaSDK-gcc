#ifndef INLINE4_AMIGAINPUT_H
#define INLINE4_AMIGAINPUT_H

/*
** This file was auto generated by idltool 53.28.
**
** It provides compatibility to OS3 style library
** calls by substituting functions.
**
** Do not edit manually.
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef AMIGAINPUT_AMIGAINPUT_H
#include <amigainput/amigainput.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif
#include <interfaces/amigainput.h>

/* Inline macros for Interface "main" */
#define AIN_GetError(ctx) IAIN->AIN_GetError((ctx))
#define AIN_GetErrorString(error_code) IAIN->AIN_GetErrorString((error_code))
#define AIN_CreateContext(api_version, tags) IAIN->AIN_CreateContext((api_version), (tags))
#define AIN_DeleteContext(ctx) IAIN->AIN_DeleteContext((ctx))
#define AIN_EnumDevices(ctx, enumfunc, user_data) IAIN->AIN_EnumDevices((ctx), (enumfunc), (user_data))
#define AIN_Query(ctx, device_id, qParameter, qArg, result, result_length) IAIN->AIN_Query((ctx), (device_id), (qParameter), (qArg), (result), (result_length))
#define AIN_ObtainDevice(ctx, device_id) IAIN->AIN_ObtainDevice((ctx), (device_id))
#define AIN_ReleaseDevice(ctx, handle) IAIN->AIN_ReleaseDevice((ctx), (handle))
#define AIN_SetDeviceParameter(ctx, handle, dParameter, dArg) IAIN->AIN_SetDeviceParameter((ctx), (handle), (dParameter), (dArg))
#define AIN_GetEvent(ctx) IAIN->AIN_GetEvent((ctx))
#define AIN_FreeEvent(ctx, event) IAIN->AIN_FreeEvent((ctx), (event))
#define AIN_ReadDevice(ctx, handle, data) IAIN->AIN_ReadDevice((ctx), (handle), (data))
#define AIN_Set(ctx, tags) IAIN->AIN_Set((ctx), (tags))
#define AIN_RequestDevice(ctx, tags) IAIN->AIN_RequestDevice((ctx), (tags))
#define AIN_FreeRequest(ctx, result) IAIN->AIN_FreeRequest((ctx), (result))

#endif /* INLINE4_AMIGAINPUT_H */
