#ifndef DOSLIB_STARTUP_H
#define DOSLIB_STARTUP_H

/*
**    $VER: startup.h  54.101 (13.01.2021)
**
**    dos.library application startup definitions
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifndef   DOS_DOS_H
#include <dos/dos.h>
#endif

/****************************************************************************/

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack(2)
   #endif
#elif defined(__VBCC__)
   #pragma amiga-align
#endif

/****************************************************************************/
/* Native AmigaDOS program _start() entry function definition. */


struct ExecBase; /* Forward declaration */

int32  _start( STRPTR argstring, int32 arglen, struct ExecBase *sysbase );


/****************************************************************************/
/*
 *  The following is a "bare bones" native _start() example that is the
 *  minimum required to get an AmigaDOS application up and running. 
 *
 *  Note that if you are using a CLIB style library environment, this DOS
 *  startup code is included, you would enter at the main() function instead.
 *
 *  For this stand-alone DOS startup code example;
 *    1)  Only dos.library is opened and closed.
 *    2)  Any workbench startup message is simply fetched and replied to.
 *    3)  No global library bases or interfaces are initialised.
 *    4)  No parameters are used from the workbench message or cli.
 * 
 *
 *  Mandatory Caveats;
 *    1) It is never permissable to open libraries or call any dos.library
 *       functions or perform any i/o whatsoever, directly or indirectly
 *       from this process context, before a workbench startup message
 *       has been fetched from the process structure message port. 
 *
 *    2) After replying to a workench startup message on exit, with the
 *       IExec->ReplyMsg() function, assume that all process locks and
 *       streams have gone away instantly, in other words, do nothing after
 *       the IExec->ReplyMsg() except releasing the exec interface and
 *       returning back to dos.library.
 *
 *    3) The _start() function is never to be declared as a void function.
 *
 *    4) Regardless of how a program is started, via workbench, via shell,
 *       a dos handler, or anything else, the only acceptable return codes
 *       are those from the include/dos/dos.h file.  eg;
 *          RETURN_OK    = 0  ( No problems, program exited successfully )
 *          RETURN_WARN  = 5  ( Warning only, ie; for 'IF' shell command )
 *          RETURN_ERROR = 10 ( Something failed normally )
 *          RETURN_FAIL  = 20 ( Severe failure, ie; missing system component )
 *
 *    5) A meaningfull secondary error code from dos/errors.h must always be
 *       returned when exiting with a primary code other than RETURN_OK.
 *
 *
 *  Example Code;
 *  ========================================================================
 *
 *
 *  #define __NOLIBBASE__
 *  #define __NOGLOBALIFACE__
 *  #include <proto/exec.h>
 *  #include <proto/dos.h>
 *  #include <dos/startup.h>
 *
 *
 *  int32  _start(STRPTR args UNUSED, int32 arglen UNUSED, struct ExecBase *sysbase)  
 *  {
 *     struct ExecIFace *iexec = (APTR)sysbase->MainInterface;
 *     struct WBStartup *wbmsg = NULL;
 *     struct DOSIFace  *idos;
 *     struct Library   *dosbase;
 *     struct Process   *process;
 *     int32  r2 = ERROR_INVALID_RESIDENT_LIBRARY; // failure for openlibrary 
 *     int32  rc = RETURN_FAIL;
 *
 *
 *     iexec->Obtain();
 *     process = (struct Process *) iexec->FindTask(NULL);
 *
 *     if( ! process->pr_CLI )  // if not from CLI, get startup message first. 
 *     {
 *         iexec->WaitPort(&process->pr_MsgPort);
 *         wbmsg = (struct WBStartup *) iexec->GetMsg(&process->pr_MsgPort);
 *     }
 *
 *     if(( dosbase = iexec->OpenLibrary("dos.library", 51) ))
 *     {
 *         if(( idos = (APTR)iexec->GetInterface(dosbase, "main", 1, NULL)))
 *         {
 *             if( process->pr_CLI )
 *             {
 *                 idos->PutStr("Hello World.[from cli]\n");
 *             }
 *             else
 *             {
 *                 idos->TimedDosRequesterTags(
 *                     TDR_Timeout, 15,
 *                     TDR_FormatString, "Hello World. [from workbench]",
 *                     TDR_TitleString,  "DOS Startup Test",
 *                     TDR_GadgetString, "OK",
 *                     TDR_ImageType, TDRIMAGE_INFO,
 *                     TAG_END );
 *             }
 *
 *             r2 = 0;
 *             rc = RETURN_OK;
 *
 *             iexec->DropInterface((APTR)idos);
 *         }
 *         iexec->CloseLibrary(dosbase);
 *     }
 *
 *     process->pr_Result2 = r2; // set the secondary result code. 
 *
 *     if( wbmsg )               // reply to a workbench startup message 
 *     {
 *         iexec->ReplyMsg((struct Message *)wbmsg );
 *     }
 *
 *     iexec->Release();
 *     return(rc);
 * }
 *
 ****************************************************************************
 *
 *  NOTES: 
 *  To differentiate startup methods employed by AmigaDOS, three cases need
 *  to be handled to cover all possible senarios.
 *
 *  1) CLI: Programs started from a CLI will have; process->pr_CLI != 0.
 *
 *  2) WB:  Programs started from Workbench will have; process->pr_CLI == 0
 *     and a "struct WBStartup" message will be sent to the process message
 *     port, that message will have the mn_Node.ln_Name set to NULL.
 *
 *  3) DOS: Handlers starting up will have; process->pr_CLI == 0 just like
 *     Workbench startup, however the difference being that the startup
 *     message will be a standard "struct Message" with the mn_Node.ln_Name
 *     field NOT being NULL, but instead it points to a "struct DosPacket"
 *     with the dp_Type set to the value ACTION_STARTUP.
 *
 *
 *  Generally, applications only need to check process->pr_CLI to tell how 
 *  they were started.  Handlers needs to go that extra step to make sure.
 *
 *  The SDK supplied "FSVPTool" will create example handler startup files. 
 *
 */
/****************************************************************************/

#ifdef __GNUC__
   #ifdef __PPC__
    #pragma pack()
   #endif
#elif defined(__VBCC__)
   #pragma default-align
#endif


#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

/****************************************************************************/

#endif /* DOSLIB_STARTUP_H */
