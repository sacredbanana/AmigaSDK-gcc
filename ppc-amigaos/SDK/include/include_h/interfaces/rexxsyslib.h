#ifndef REXXSYSLIB_INTERFACE_DEF_H
#define REXXSYSLIB_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 53.23.
** Do not edit
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

#ifndef REXX_RXSLIB_H
#include <rexx/rxslib.h>
#endif
#ifndef REXX_REXXIO_H
#include <rexx/rexxio.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct RexxSysIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct RexxSysIFace *Self);
	uint32 APICALL (*Release)(struct RexxSysIFace *Self);
	APTR Expunge_UNIMPLEMENTED;
	APTR Clone_UNIMPLEMENTED;
	APTR Private1;
	APTR Private2;
	APTR Private3;
	APTR Private4;
	APTR Private5;
	APTR Private6;
	APTR Private7;
	APTR Private8;
	APTR Private9;
	APTR Private10;
	APTR Private11;
	APTR Private12;
	APTR Private13;
	APTR Private14;
	APTR Private15;
	APTR Private16;
	STRPTR APICALL (*CreateArgstring)(struct RexxSysIFace *Self, CONST_STRPTR string, ULONG length);
	VOID APICALL (*DeleteArgstring)(struct RexxSysIFace *Self, STRPTR argstring);
	LONG APICALL (*LengthArgstring)(struct RexxSysIFace *Self, CONST_STRPTR argstring);
	struct RexxMsg * APICALL (*CreateRexxMsg)(struct RexxSysIFace *Self, struct MsgPort * port, CONST_STRPTR extension, CONST_STRPTR host);
	VOID APICALL (*DeleteRexxMsg)(struct RexxSysIFace *Self, struct RexxMsg * rexxmsg);
	VOID APICALL (*ClearRexxMsg)(struct RexxSysIFace *Self, struct RexxMsg * msgptr, ULONG count);
	BOOL APICALL (*FillRexxMsg)(struct RexxSysIFace *Self, struct RexxMsg * rexxmsg, ULONG count, ULONG mask);
	BOOL APICALL (*IsRexxMsg)(struct RexxSysIFace *Self, CONST struct RexxMsg * rexxmsg);
	APTR Private17;
	APTR Private18;
	APTR Private19;
	APTR Private20;
	APTR Private21;
	APTR Private22;
	APTR Private23;
	APTR Private24;
	APTR Private25;
	APTR Private26;
	APTR Private27;
	APTR Private28;
	APTR Private29;
	APTR Private30;
	APTR Private31;
	APTR Private32;
	APTR Private33;
	APTR Private34;
	APTR Private35;
	APTR Private36;
	APTR Private37;
	APTR Private38;
	APTR Private39;
	APTR Private40;
	APTR Private41;
	APTR Private42;
	APTR Private43;
	APTR Private44;
	APTR Private45;
	APTR Private46;
	APTR Private47;
	APTR Private48;
	APTR Private49;
	APTR Private50;
	APTR Private51;
	APTR Private52;
	APTR Private53;
	APTR Private54;
	APTR Private55;
	APTR Private56;
	APTR Private57;
	APTR Private58;
	APTR Private59;
	APTR Private60;
	APTR Private61;
	APTR Private62;
	VOID APICALL (*LockRexxBase)(struct RexxSysIFace *Self, ULONG resource);
	VOID APICALL (*UnlockRexxBase)(struct RexxSysIFace *Self, ULONG resource);
	APTR Private63;
	APTR Private64;
	APTR Private65;
	struct MsgPort * APICALL (*CreateRexxHostPort)(struct RexxSysIFace *Self, CONST_STRPTR base_name);
	VOID APICALL (*DeleteRexxHostPort)(struct RexxSysIFace *Self, struct MsgPort * port);
	LONG APICALL (*GetRexxVarFromMsg)(struct RexxSysIFace *Self, CONST_STRPTR name, STRPTR buffer, struct RexxMsg * rexxmsg);
	LONG APICALL (*SetRexxVarFromMsg)(struct RexxSysIFace *Self, CONST_STRPTR name, CONST_STRPTR value, struct RexxMsg * rexxmsg);
	struct RexxMsg * APICALL (*LaunchRexxScript)(struct RexxSysIFace *Self, CONST_STRPTR script_name, struct MsgPort * host_port, CONST_STRPTR extension, BPTR input_handle, BPTR output_handle);
	VOID APICALL (*FreeRexxMsg)(struct RexxSysIFace *Self, struct RexxMsg * rexxmsg);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* REXXSYSLIB_INTERFACE_DEF_H */
