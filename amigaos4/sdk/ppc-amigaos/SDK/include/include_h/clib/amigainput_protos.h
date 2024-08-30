#ifndef CLIB_AMIGAINPUT_PROTOS_H
#define CLIB_AMIGAINPUT_PROTOS_H

/*
**    $Id: amigainput_protos.h,v 1.8 2010-01-31 01:28:55 ssolie Exp $
**
**    C prototypes. For use with 32 bit integers only.
**
**    Copyright (C) 1985-2005 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/


#ifndef   AMIGAINPUT_AMIGAINPUT_H
#include <amigainput/amigainput.h>
#endif
#ifndef   UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifdef __amigaos4__
#error Include <proto/> header files, not <clib/> header files in OS4.
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif /* __cplusplus */


ULONG AIN_GetError( APTR ctx );
STRPTR AIN_GetErrorString( ULONG error_code );
APTR AIN_CreateContext( ULONG api_version, struct TagItem *tags );
APTR AIN_CreateContextTags( ULONG api_version, ... );
VOID AIN_DeleteContext( APTR ctx );
BOOL AIN_EnumDevices( APTR ctx, APTR enumfunc, APTR user_data );
BOOL AIN_Query( APTR ctx, AIN_DeviceID device_id, ULONG qParameter, ULONG qArg, APTR result, ULONG result_length );
AIN_DeviceHandle *AIN_ObtainDevice( APTR ctx, AIN_DeviceID device_id );
VOID AIN_ReleaseDevice( APTR ctx, AIN_DeviceHandle *handle );
BOOL AIN_SetDeviceParameter( APTR ctx, AIN_DeviceHandle *handle, ULONG dParameter, ULONG dArg );
AIN_InputEvent *AIN_GetEvent( APTR ctx );
VOID AIN_FreeEvent( APTR ctx, AIN_InputEvent *event );
BOOL AIN_ReadDevice( APTR ctx, AIN_DeviceHandle *handle, APTR *data );
BOOL AIN_Set( APTR ctx, struct TagItem *tags );


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif /* __cplusplus */

#endif /* CLIB_AMIGAINPUT_PROTOS_H */
