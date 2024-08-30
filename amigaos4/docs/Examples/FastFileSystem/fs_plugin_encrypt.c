/*
 * $Id: fs_plugin_encrypt.c,v 1.1 2008-09-15 13:14:20 sarcher Exp $
 *
 * :ts=4
 *
 * Amiga ROM file system reimplementation
 * Copyright © 2001-2005 by Olaf Barthel
 * All Rights Reserved
 */

#include <exec/memory.h>

#include <dos/dosextens.h>
#include <dos/rdargs.h>

/****************************************************************************/

#define __NOLIBBASE__
#include <proto/exec.h>
#include <proto/dos.h>

/****************************************************************************/

extern struct Library *SysBase;
extern struct Library *DOSBase;

/****************************************************************************/

#if defined(__amigaos4__)
extern struct ExecIFace *	IExec;
extern struct DOSIFace *	IDOS;
#endif /* __amigaos4__ */

/****************************************************************************/

#if defined(__amigaos4__)
#ifdef Flush
#undef Flush
#endif /* Flush */

#define Flush(fh) FFlush(fh)

#endif /* __amigaos4__ */

/****************************************************************************/

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/****************************************************************************/

#include "fs_plugin_encrypt_rev.h"
STRPTR version_tag = VERSTAG;

/****************************************************************************/

#include "compiler.h"
#include "filesystem_plugin.h"
#include "fs_blowfish.h"
#include "fs_md5.h"

/****************************************************************************/

typedef LONG *	NUMBER;
typedef LONG	SWITCH;
typedef STRPTR	KEY;

/****************************************************************************/

/*#define DEBUG*/
#include "assert.h"

/****************************************************************************/

#define OK 0
#define NOT !
#define CANNOT !

/****************************************************************************/

struct TransformContext
{
	struct FSPluginHook		tc_PluginHook;
	struct blowfish_context	tc_BlowfishContext;
	LONG					tc_BytesPerBlock;
	STRPTR					tc_DeviceName;
	LONG					tc_UnitNumber;
	PLUGIN_QUAD				tc_FirstSector;
	PLUGIN_QUAD				tc_LastSector;
};

/****************************************************************************/

VOID transformation_setup(struct TransformContext *tc, struct FSPluginSetupMsg *fspm);
VOID transformation_read(struct TransformContext *tc, struct FSPluginReadTransformMsg *fspm);
VOID transformation_write(struct TransformContext *tc, struct FSPluginWriteTransformMsg *fspm);
LONG ASM transformation_hook_func(REG(a0, struct Hook *hook), REG(a2, APTR unused), REG(a1, LONG *fspm));
LONG get_password(STRPTR prompt, UBYTE *buffer, LONG max_buffer_size);

/****************************************************************************/

#if defined(__GNUC__)

#if defined(__amigaos4__)
#define VAR_ARGS __attribute__((linearvarargs))
#else
#define VAR_ARGS
#endif /* __amigaos4__ */

#if defined(Printf)
#undef Printf
#endif /* Printf */

#define Printf Local_Printf

STATIC VAR_ARGS LONG
Local_Printf(STRPTR format,...)
{
	va_list args;
	LONG result;

	#if defined(__amigaos4__)
	{
		va_startlinear(args,format);
		result = VPrintf(format,va_getlinearva(args, APTR));
		va_end(args);
	}
	#else
	{
		va_start(args,format);
		result = VPrintf(format,args);
		va_end(args);
	}
	#endif /* __amigaos4__ */

	return(result);
}

#endif /* __GNUC__ */

/****************************************************************************/

VOID
transformation_setup(struct TransformContext * tc,struct FSPluginSetupMsg * fspm)
{
	tc->tc_BytesPerBlock	= fspm->fspm_BytesPerBlock;
	tc->tc_DeviceName		= fspm->fspm_DeviceName;
	tc->tc_UnitNumber		= fspm->fspm_UnitNumber;
	tc->tc_FirstSector		= fspm->fspm_FirstSector;
	tc->tc_LastSector		= fspm->fspm_LastSector;
}

/****************************************************************************/

VOID
transformation_read(struct TransformContext * tc,struct FSPluginReadTransformMsg *fspm)
{
	struct blowfish_data * from;
	struct blowfish_data * to;
	struct blowfish_data state;
	struct blowfish_data saved_state;
	LONG i;

	from	= fspm->fspm_SourceData;
	to		= fspm->fspm_DestinationData;

	state.left	= fspm->fspm_Offset ^ 0x55555555;
	state.right	= fspm->fspm_Offset ^ 0xAAAAAAAA;

	for(i = 0 ; i < tc->tc_BytesPerBlock / (LONG)sizeof(*from) ; i++)
	{
		saved_state = (*from);

		blowfish_decrypt(&tc->tc_BlowfishContext,from++,to);

		to->left	^= state.left;
		to->right	^= state.right;

		to++;

		state = saved_state;
	}
}

/****************************************************************************/

VOID
transformation_write(struct TransformContext * tc,struct FSPluginWriteTransformMsg *fspm)
{
	struct blowfish_data * from;
	struct blowfish_data * to;
	struct blowfish_data saved_state;
	struct blowfish_data state;
	LONG i;

	from	= fspm->fspm_SourceData;
	to		= fspm->fspm_DestinationData;

	state.left	= fspm->fspm_Offset ^ 0x55555555;
	state.right	= fspm->fspm_Offset ^ 0xAAAAAAAA;

	for(i = 0 ; i < tc->tc_BytesPerBlock / (LONG)sizeof(*from) ; i++)
	{
		saved_state.left	= from->left	^ state.left;
		saved_state.right	= from->right	^ state.right;

		blowfish_encrypt(&tc->tc_BlowfishContext,&saved_state,to);

		state.left	= to->left;
		state.right	= to->right;

		from++;
		to++;
	}
}

/****************************************************************************/

LONG ASM
transformation_hook_func(
	REG(a0,struct Hook *	hook),
    REG(a2,APTR				unused),
    REG(a1,LONG *			fspm))
{
	struct TransformContext * tc = hook->h_Data;
	LONG result;

	ENTER();

	switch(*fspm)
	{
		case fspm_setup:

			SHOWMSG("fspm_setup");

			transformation_setup(tc,(struct FSPluginSetupMsg *)fspm);
			result = OK;
			break;

		case fspm_cleanup:

			SHOWMSG("fspm_cleanup");

			result = OK;
			break;

		case fspm_read_transform:

			SHOWMSG("fspm_read_transform");

			transformation_read(tc,(struct FSPluginReadTransformMsg *)fspm);
			result = OK;
			break;

		case fspm_write_transform:

			SHOWMSG("fspm_write_transform");

			transformation_write(tc,(struct FSPluginWriteTransformMsg *)fspm);
			result = OK;
			break;

		default:

			D(("unknown plugin code %ld",*fspm));

			result = ERROR_ACTION_NOT_KNOWN;
			break;
	}

	RETURN(result);
	return(result);
}

/****************************************************************************/

LONG
get_password(STRPTR prompt,UBYTE * buffer,LONG max_buffer_size)
{
	BPTR input_stream;
	LONG result = -1;
	LONG len;

	input_stream = Input();

	if(CANNOT SetMode(input_stream,DOSTRUE))
	{
		UBYTE error_string[80];

		Fault(IoErr(),NULL,error_string,sizeof(error_string));

		Printf("Could not switch console to single character mode (%s).\n",error_string);
		goto out;
	}

	Printf("%s: ",prompt);
	Flush(Output());

	len = 0;

	while(TRUE)
	{
		if(CheckSignal(SIGBREAKF_CTRL_C))
		{
			len = -1;
			break;
		}

		if(WaitForChar(input_stream,TICKS_PER_SECOND / 2))
		{
			UBYTE c;

			if(Read(input_stream,&c,1) == 1)
			{
				if(c == '\003')
				{
					len = -1;
					break;
				}
				else if (c == '\r' || c == '\n')
				{
					break;
				}
				else if (((c >= ' ' && c < 127) || (c >= 160)) && len < max_buffer_size)
				{
					buffer[len++] = c;
				}
			}
		}
	}

	Printf("\n");

	SetMode(input_stream,DOSFALSE);

	result = len;

 out:

	return(result);
}

/****************************************************************************/

int
main(int argc,char ** argv)
{
	struct
	{
		KEY		Device;
		NUMBER	NumBlocks;
		SWITCH	Quiet;
	} args;

	struct TagItem tags[2];
	UBYTE prompt[256];
	UBYTE password[56];
	LONG password_len;
	struct md5_context md5;
	UBYTE digest[16];
	struct TransformContext * tc = NULL;
	struct RDArgs * rda = NULL;
	struct MsgPort * mp;
	BOOL debug_enabled = FALSE;
	ULONG signals;
	BOOL done;
	int result = RETURN_ERROR;

	SETPROGRAMNAME(argv[0]);
	SETDEBUGLEVEL(0);

	if(((struct Library *)SysBase)->lib_Version < 37)
	{
		STRPTR message = "This program requires Kickstart 2.04 or higher.\n";

		Write(Output(),message,strlen(message));
		goto out;
	}

	memset(&args,0,sizeof(args));

	rda = ReadArgs("DEVICE/A,BLOCKS/K/N,QUIET/S",(LONG *)&args,NULL);
	if(rda == NULL)
	{
		PrintFault(IoErr(),argv[0]);
		goto out;
	}

	mp = DeviceProc(args.Device);
	if(mp == NULL)
	{
		Printf("'%s' not found.\n",args.Device);
		goto out;
	}

	tc = AllocVec(sizeof(*tc),MEMF_ANY|MEMF_PUBLIC|MEMF_CLEAR);
	if(tc == NULL)
	{
		Printf("Not enough memory to set up encryption for '%s'.\n",args.Device);
		goto out;
	}

	strcpy(prompt,"Please enter the password for '");
	strcat(prompt,args.Device);
	strcat(prompt,"' and press [Return] when finished");

	md5_init(&md5);

	/* Read the password without revealing it on the screen. */
	password_len = get_password(prompt,password,sizeof(password));
	if(password_len < 0)
		goto out;

	/* Knot the password into a message digest, then drop the password. */
	md5_update(&md5,password,password_len);
	memset(password,0,sizeof(password));

	md5_final(&md5,digest);

	/* Initialize the encryption with the digest result. */
	blowfish_init(&tc->tc_BlowfishContext,digest,sizeof(digest));
	memset(digest,0,sizeof(digest));

	tc->tc_PluginHook.fsp_VersionTag	= version_tag;
	tc->tc_PluginHook.fsp_Version		= PLUGIN_API_VERSION;
	tc->tc_PluginHook.fsp_Revision		= PLUGIN_API_REVISION;

	#if defined(__MORPHOS__)
	{
		tc->tc_PluginHook.fsp_Hook.h_Entry		= (HOOKFUNC)hookfuncentry;
		tc->tc_PluginHook.fsp_Hook.h_SubEntry	= (HOOKFUNC)transformation_hook_func;
	}
	#else
	{
		tc->tc_PluginHook.fsp_Hook.h_Entry		= (HOOKFUNC)transformation_hook_func;
		tc->tc_PluginHook.fsp_Hook.h_SubEntry	= (HOOKFUNC)NULL;
	}
	#endif /* __MORPHOS__ */

	tc->tc_PluginHook.fsp_Hook.h_Data	= tc;
	tc->tc_PluginHook.fsp_Type			= fspt_block_transform;

	if(args.NumBlocks != NULL && (*args.NumBlocks) > 1)
	{
		tags[0].ti_Tag	= FSPA_NumTransformBlocks;
		tags[0].ti_Data	= (*args.NumBlocks);
		tags[1].ti_Tag	= TAG_END;

		tc->tc_PluginHook.fsp_Options = tags;
	}

	if(CANNOT DoPkt(mp,ACTION_ADD_PLUGIN,(LONG)&tc->tc_PluginHook,	0,0,0,0))
	{
		UBYTE error_message[80];

		Fault(IoErr(),NULL,error_message,sizeof(error_message));

		Printf("Could not install encryption on '%s' (%s).\n",args.Device,error_message);
		goto out;
	}

	if(CANNOT Inhibit(args.Device,DOSTRUE))
	{
		UBYTE error_message[80];

		Fault(IoErr(),NULL,error_message,sizeof(error_message));

		Printf("Could not restart file system on '%s' (%s).\n",args.Device,error_message);
		goto out;
	}

	Delay(TICKS_PER_SECOND);
	Inhibit(args.Device,DOSFALSE);

	if(NOT args.Quiet)
		Printf("Encryption on '%s' installed; ^C to remove.\n",args.Device);

	do
	{
		done = FALSE;

		signals = Wait(SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_E);

		if(signals & SIGBREAKF_CTRL_C)
			done = TRUE;

		if(signals & SIGBREAKF_CTRL_E)
		{
			debug_enabled ^= TRUE;

			if(debug_enabled)
				SETDEBUGLEVEL(2);
			else
				SETDEBUGLEVEL(0);
		}
	}
	while(NOT done);

	DoPkt(mp,ACTION_REMOVE_PLUGIN,(LONG)&tc->tc_PluginHook,	0,0,0,0);

	Inhibit(args.Device,DOSTRUE);
	Delay(TICKS_PER_SECOND);
	Inhibit(args.Device,DOSFALSE);

	if(NOT args.Quiet)
		Printf("Encryption on '%s' removed.\n",args.Device);

	result = RETURN_OK;

 out:

	FreeVec(tc);

	FreeArgs(rda);

	return(result);
}
