#ifndef DOS_DOSTAGS_H
#define DOS_DOSTAGS_H
/*
**    $VER: dostags.h  54.103 (26.12.2021)
**
**    Tag definitions for all Dos routines using tags
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF and Amiga, Inc.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
**
*/

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
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

/*****************************************************************************/
/* definitions for the System() call.
 */

#define SYS_Dummy               (TAG_USER + 32)

#define SYS_CommandRunMode      (SYS_Dummy + 0)
    /* (BOOLEAN) - PRIVATE Internal SHELL tag to identify "run" command. */

#define SYS_Input               (SYS_Dummy + 1)
    /* (BPTR) - specifies the input filehandle  */

#define SYS_Output              (SYS_Dummy + 2)
    /* (BPTR) - specifies the output filehandle */

#define SYS_Asynch              (SYS_Dummy + 3)
    /* (BOOLEAN) - run asynch, close input/output on exit(!) */

#define SYS_UserShell           (SYS_Dummy + 4)
    /* (BOOLEAN) - send to user shell instead of boot shell */

#define SYS_CustomShell         (SYS_Dummy + 5)
    /* (STRPTR) - send to a specific shell (data is name) */

#define SYS_Error               (SYS_Dummy + 6)
    /* (BPTR) - specifies the error output filehandle (New for V50) */ 

#define SYS_ExecuteInputStream  (SYS_Dummy + 7)
    /* (BOOLEAN) - instead of reading the 'command' string parameter, 
     *             reads commands from the input filehandle instead. (V53.45)
     */


/*****************************************************************************/
/* definitions for the (V51.96) GetDiskInfo() call.
 */

#define GDI_Dummy                   (TAG_USER+500)

#define GDI_StringNameInput         (GDI_Dummy+1)
    /* (STRPTR) - pointer to a string identifier for the handler. 
     * Identify the handler by the volume: device: or assignment: name.
     * This function will use the current directory if there is no ":"
     * within the string specification.  
     */

#define GDI_FileHandleInput         (GDI_Dummy+2)
    /* (BPTR) - BCPL pointer to a FileHandle to identify the handler */
 
#define GDI_LockInput              (GDI_Dummy+3)
    /* (BPTR) - BCPL pointer to a Lock to identify the handler. */
#define GDI_FileLockInput           GDI_LockInput 

#define GDI_MsgPortInput            (GDI_Dummy+4)
    /* (struct MsgPort *) - Pointer to the handlers message port */

#define GDI_VolumeRequired          (GDI_Dummy+10)
    /* (int32) - TRUE for ACTION_INFO, FALSE for ACTION_HANDLER_INFO */

#define GDI_InfoData                (GDI_Dummy+11)
    /* (struct InfoData *) - Pointer to an InfoData structure */

#define GDI_ShowRequesters          (GDI_Dummy+12)
    /* (boolean) - TRUE to allow requesters to appear, defaults to FALSE */
 

/*****************************************************************************/
/* definitions for the (V53.59) ObtainConsoleDataTags() call.
 */

#define OCD_Dummy                   (TAG_USER+600)

#define OCD_FileHandleInput         (OCD_Dummy+1)
    /* (BPTR) - BCPL pointer to a FileHandle for a console window. */

#define OCD_MsgPortInput            (OCD_Dummy+2)
    /* (struct MsgPort *) - Pointer to a console message port. */




/****************************************************************************/
/*  Tags for AsyncIO().  
 */ 

#define  AIO_Dummy                (TAG_USER+700)

#define  AIO_ReadFileHandle       (AIO_Dummy+1)
     /* (BPTR) - BCPL pointer to an open filehandle which is used to
        Read() data from the file it represents.
        If the AIO_WriteFileHandle is also specified, a copy operation
        is performed. */

#define  AIO_WriteFileHandle      (AIO_Dummy+2)
     /* (BPTR) - BCPL pointer to an open filehandle which is used to
        Write() data to the file it represents.
        If the AIO_ReadFileHandle is also specified, a copy operation
        is performed. */

#define  AIO_Buffer               (AIO_Dummy+3)
     /* (APTR) - Mandatory pointer to the user supplied buffer.  */

#define  AIO_Length               (AIO_Dummy+4)
     /* (uint32) - Mandatory number of bytes of data to be read or written
        from/to the buffer area. */

#define  AIO_Result               (AIO_Dummy+5)
     /* (int64 *) - Optional pointer to a 64 bit integer that will return
        the value from the message->Result.  */

#define  AIO_IoErr                (AIO_Dummy+6)
     /* (int32 *) -- Optional pointer to a 32 bit integer that will be
        set to the error code from the message->IoErr if an error occurs. */

#define  AIO_Priority             (AIO_Dummy+7)
     /* (int8) - Optional priority for the async process.
        This must be a value between -128 and +127.   Defaults to 0. */

#define  AIO_UserData             (AIO_Dummy+8)
     /* (APTR) - A user value that is placed in the message
        AsyncInfoMsg->UserData and passed as a hook function argument. */

#define  AIO_ExtraUserData        (AIO_Dummy+9)
     /* (APTR) -- A second user value that is placed in the message
        AsyncInfoMsg->ExtraUserData.  */

#define  AIO_AbortFileHandle      (AIO_Dummy+10)
     /* (BPTR) - A BCPL pointer to an open filehandle that had/has
        performed an AsyncIO() operation. (Otherwise harmless.) */

#define  AIO_NotifyHook           (AIO_Dummy+11)
     /* (struct Hook *) - Optional pointer to a persistant struct Hook.
        The hook will be called at end of the transfer.  */

#define  AIO_NotifyPort           (AIO_Dummy+12)
     /* (struct MsgPort *) - Optional pointer to a messageport.
        This port will receives an AsyncInfoMsg at end of the transfer. */

#define  AIO_NotifyFlag            (AIO_Dummy+13)
     /* (int32 *) - Optional pointer to a 32 bit integer to be used
        as a flag. The value will be set to FALSE upon entry and
        changed to DOSTRUE at the end of the transfer. */

#define  AIO_NotifyUpdateHook      (AIO_Dummy+14)
     /* (struct Hook *) - Optional pointer to a persistant struct Hook.
        The hook structure will NOT be copied.
        The hook is called once before, once after, and at each transfer. */

#define  AIO_NotifyUpdateTicks     (AIO_Dummy+15)
     /* (uint32) - Optional maximum period in 'ticks' that must elapse
        before the update hook will be called again. */

#define  AIO_ReadHook              (AIO_Dummy+16)
     /* (struct Hook *) - Optional pointer to a persistant struct Hook.
        The hook structure will NOT be copied.
        The hook is called instead of the IDOS->Read() function. */

#define  AIO_WriteHook             (AIO_Dummy+17)
     /* (struct Hook *) - Optional pointer to a persistant struct Hook.
        The hook structure will NOT be copied.
        The hook is called instead of the IDOS->Write() function. */

#define  AIO_NotifyCounter         (AIO_Dummy+18)
     /* (int32 *) -- Optional pointer to a 32 bit integer to be used
        a counter to indicate how many processes are still in action.
        It will be incremented upon startup, decremented upon ending. */

#define  AIO_ProcessName           (AIO_Dummy+19)
     /* (STRPTR) -- Optional name for the async process,
        this will be passed to CreateNewProc() via the NP_Name tag.  */




/*****************************************************************************/
/* definitions for the CreateNewProc() call;
 * you MUST specify one of NP_Seglist or NP_Entry. All others are optional.
 * NOTE: NP_Error was not actually implemented in DOS until V50 
 */

#define NP_Dummy            (TAG_USER + 1000)

#define NP_Seglist          (NP_Dummy + 1)
    /* (BPTR) - seglist of code to run for the process  */

#define NP_FreeSeglist      (NP_Dummy + 2)
    /* (int32) - free seglist on exit, only valid for NP_Seglist.
                 Default is FALSE. */

#define NP_Start            (NP_Dummy + 3)
#define NP_Entry            NP_Start
    /* (APTR) - entry point to run for the new process.  */
    /* Added alias for old source code, NP_Entry name changed to
    ** remove confusion with NP_EntryCode which wasn't reported until V54.
    */

#define NP_Input            (NP_Dummy + 4)
    /* (BPTR) - filehandle, default is Open("NIL:"...) */

#define NP_Output           (NP_Dummy + 5)
    /* (BPTR) - filehandle, default is Open("NIL:"...) */

#define NP_CloseInput       (NP_Dummy + 6)
    /* (int32) - close input filehandle on exit, default TRUE */

#define NP_CloseOutput      (NP_Dummy + 7)
    /* (int32) - close output filehandle on exit, default TRUE */

#define NP_Error            (NP_Dummy + 8)
    /* (BPTR) - filehandle, default is NULL (V50) */

#define NP_CloseError       (NP_Dummy + 9)
    /* (int32) - close error filehandle on exit, default FALSE (V50) */

#define NP_CurrentDir       (NP_Dummy + 10)
    /* (BPTR) - lock, default is parent's current dir  */

#define NP_StackSize        (NP_Dummy + 11)
    /* (uint32) - stacksize for process */

#define NP_Name             (NP_Dummy + 12)
    /* (STRPTR) - name for process, default "New Process"*/

#define NP_Priority         (NP_Dummy + 13)
    /* (int32) - priority, (-128 to +127), default same as parent */

#define NP_ConsolePort      (NP_Dummy + 14)
#define NP_ConsoleTask       NP_ConsolePort   /* old compatibility */
    /* (struct MsgPort *), consoletask, default same as parent */

#define NP_WindowPtr        (NP_Dummy + 15)
    /* (APTR) - window ptr, default is same as parent  */

#define NP_ProgramDir       (NP_Dummy + 16)
    /* (BPTR) - home program directory, default current progdir  */

#define NP_CopyVars         (NP_Dummy + 17)
    /* (int32) - boolean to copy local vars, default TRUE */

#define NP_Cli              (NP_Dummy + 18)
    /* (int32) - create cli structure, default FALSE */

#define NP_Path             (NP_Dummy + 19)
    /* (BPTR) - struct PathNode chain, default is copy of parents path, 
     *          only valid if a cli process! 
     */

#define NP_CommandName      (NP_Dummy + 20)
    /* (STRPTR) - commandname, valid only for CLI */

#define NP_Arguments        (NP_Dummy + 21)
    /* (STRPTR) - arguments passed with str in a0, length in d0.
     * (copied and freed on exit.) Default is 0-length NULL ptr.
     * You must NEVER use NP_Arguments with a NP_Input of NULL. 
     */

#define NP_unused1          (NP_Dummy + 22)
    /* never implemented */

#define NP_unused2          (NP_Dummy + 23)
    /* not used */

#define NP_ExitCode         (NP_Dummy + 24)
    /* (void (*)(int32,int32)) - code to be called on process exit, just before cleanup */

#define NP_ExitData         (NP_Dummy + 25)
    /* (int32) - optional argument for NP_ExitCode function - default 0 */

#define NP_UserData         (NP_Dummy + 26)
    /* (int32) - optional value to install into task->tc_UserData. */

#define NP_Child            (NP_Dummy + 27)
    /* (int32) - boolean flag to nominate this new process as a dependant child 
     * of the parent. (V50) 
     */

#define NP_NotifyOnDeathMessage        (NP_Dummy+28)
    /* (struct DeathMessage *) - Specify an initialised death message 
     * structure to ReplyMsg() to, upon death of this process.
     * Defaults to none.  (V51.53)
     */

#define NP_NotifyOnDeathSigTask        (NP_Dummy+29)
    /* (struct Task *) - Specify the task or process to signal upon 
     * death of this process. Specify NULL for the parent of this child process.
     * Defaults to no signalling, if this tag is not specified. (V51.53)
     */

#define NP_NotifyOnDeathSignalBit      (NP_Dummy+30)
    /* (int32) - A value (0-31) for the signal bit number to send to the task
     * NP_NotifyOnDeathSigTask, upon death of this process. 
     * Defaults to SIGB_CHILD if not specified.  (See; exec/tasks.h) 
     */

#define NP_LocalVars                   (NP_Dummy+31)
    /* (STRPTR *) - Paired array of string pointers representing a 
     * list of local variables to add to the new process, array must be 
     * arranged as;  Name1,Value1, Name2,Value2, Name3,Value3, NULL;
     * Default NULL. (V51.70)
     */

#define NP_EntryCode                   (NP_Dummy+32)
    /* (void (*)(int32,int32)) - code to be called on process startup,
       just before internalRunCommand() */

#define NP_EntryData                   (NP_Dummy+33)
    /* (int32) - optional argument for NP_EntryCode function, default 0 */

#define NP_FinalCode                   (NP_Dummy+34)
    /* (void (*)(int32,int32)) - code to be called on process exit, just before cleanup */

#define NP_FinalData                   (NP_Dummy+35)
    /* (int32) - optional argument for NP_FinalCode function, default 0 */

#define NP_LocalAlias                  (NP_Dummy+36)
    /* (STRPTR *) - Paired array of string pointers to represent a list of
     * local aliases to add to the new process, array must be arranged as;  
     *    Alias1,Value1, Alias2,Value2, Alias3,Value3, NULL;
     * Default NULL. (Added V52.5)
     */

#define NP_LockStack                    (NP_Dummy+37)
    /* (int32) - Boolean tag to cause exec to lock the stack in place,
     * specifying TRUE will prevent the stack frame being swapped out.
     * Default FALSE   (Added V52.10) 
     */

#define NP_OwnerUID                     (NP_Dummy+38)
    /* (uint32) - Specify the pr_UID value for the new process. (Added 52.18) */

#define NP_OwnerGID                     (NP_Dummy+39)
    /* (uint32) - Specify the pr_GID value for the new process. (Added 52.18) */



/*****************************************************************************/
/* tags for AllocDosObject()
 */

#define ADO_Dummy        (TAG_USER + 2000)

#define ADO_TermCharStr	 (ADO_Dummy + 0)   
    /* Added for FReadLine() V53.19 
     */

/* Obsolete tags +1...+5 have been moved to obsolete.h */

#define ADO_AddedSize   (ADO_Dummy + 6)
    /* Size of additional buffer to allocate over and above the 
     * base structure size required by the flag DOS_xxxxx .  (V50)
     */
#define ADO_Strlen       ADO_AddedSize


#define ADO_Flags        (ADO_Dummy + 7)
    /* Generic 32 bit flags for those allocations that
     * require initialisation of a specific flags field. (V50) 
     */
#define ADO_DOSType       ADO_Flags           /* alias V51 */
#define ADO_TermChar      ADO_Flags           /* alias V51 */
#define ADO_Type          ADO_Flags           /* alias V52 */
#define ADO_Vectors       ADO_Flags           /* alias V53 */


#define ADO_Mask         (ADO_Dummy + 8)
    /* Generic 32 bit mask for those allocations that
     * require initialisation of a specific bitmask. (V50) 
     */
#define ADO_AddColon      ADO_Mask            /* alias V53 */


#define ADO_Name         (ADO_Dummy + 9)
    /* Generic STRPTR Name. (V52) */


#define ADO_NotifyName    ADO_Name      /* alias V52 */
    /* Name of the volume, directory or file to monitor and produce
     * notification messages for. (V51) 
     */

#define ADO_NotifyUserData    (ADO_Dummy + 10)
    /* User data to be stored in a NotifyRequest. (V51) */

#define ADO_NotifyMethod      (ADO_Dummy + 11)
    /* Notification method; must be one of NRF_SEND_MESSAGE,
     * NRF_SEND_SIGNAL or NRF_CALL_HOOK. (V51) 
     */

#define ADO_NotifyPort        (ADO_Dummy + 12)
    /* MsgPort to send notification messages to; this is used
     * for the NRF_SEND_MESSAGE notification method. (V51) 
     */

#define ADO_NotifyTask        (ADO_Dummy + 13)
    /* Task to send a notification signal to; this is used for
     * the NRF_SEND_SIGNAL notification method. (V51) 
     */

#define ADO_NotifySignalNumber    (ADO_Dummy + 14)
    /* The signal number (0..31) to use when sending a notification
     * signal; this is used for the NRF_SEND_SIGNAL notification
     * method. (V51) 
     */

#define ADO_NotifyHook        (ADO_Dummy + 15)
    /* The hook to call when a notification is required; this is
     * used for the NRF_CALL_HOOK method. (V51) 
     */

#define ADO_NotifyWaitReply   (ADO_Dummy + 16)
    /* Selects if the further notification messages should be sent
     * unless the last message has been replied. (V51) 
     */

#define ADO_NotifyInitial     (ADO_Dummy + 17)
    /* Selects if the notification should be sent immediately after
     * it was requested. (V51) 
     */

#define ADO_Size              (ADO_Dummy + 18)
    /* Specify allocation size that is larger than the default. (V51) */

#define ADO_DOSMethodOnly     (ADO_Dummy + 19)
    /* Force the dos.library to service the notify request, and exclude
     * the filesystem routines even if they are available. (V52.33) 
     */

#define ADO_ExamineData_NameSize      (ADO_Dummy + 20)
    /* Selects the size of the name buffer for DOS_EXAMINEDATA. (V51) */

#define ADO_ExamineData_CommentSize   (ADO_Dummy + 21)
    /* Selects the size of the comment buffer for DOS_EXAMINEDATA (V51) */

#define ADO_ExamineData_LinkSize      (ADO_Dummy + 22)
    /* Selects the size of the link name buffer for DOS_EXAMINEDATA. (V51) */

#define ADO_ExamineDir_Context        (ADO_Dummy + 23)
    /* Used by filesystems and DOS to pass an ExamineContext. (V51.104) */

#define ADO_ExamineData_Source        (ADO_Dummy + 24)
    /* Source ExamineData tag for copying content into allocation. (V54.35) */



/*****************************************************************************/
/* definitions for the (V50) AddSegmentTagList() call
 */

#define AS_Dummy          (TAG_USER+3000)

#define AS_SegmentList    (AS_Dummy+1)
    /* (BPTR) - Segment list, as returned by the LoadSeg() function */

#define AS_Entry          (AS_Dummy+2)
    /* (APTR) - Address of a function which implements the command */




/****************************************************************************/
/* Tags for TimedDosRequester() 
 */

#define TDR_Dummy                (TAG_USER + 3500)

#define TDR_IDCMP_Ptr            (TDR_Dummy+1)
    /* (uint32 *) - [OPTIONAL] Pointer to a longword initialised with the
       IDCMP flags that you want to terminate the requester on.  
       (Default; NULL)  */

#define TDR_Timeout              (TDR_Dummy+2)
    /* (int32) - [OPTIONAL] Value in seconds to wait before requester
       will close without intervention.  A timeout will only occur with
       values > 0.
       It is recommended that timouts less than 10 seconds be
       avoided whenever possible, to be user-friendly. (Default; 0) */

#define TDR_Window               (TDR_Dummy+3)
    /* (struct Window *) [OPTIONAL] 
       - A pointer to an (over-riding) reference window pointer.
       Normally, you would not need to specify this tag.
       
       However, if you are calling this function from a task, 
       then the default process window will not be available and
       you would normally finish up having the requester rendered
       on the default public screen instead, (usually workbench)
       therefore you can use this tag to force it to use your 
       own specified window,this will work from both a task or 
       a process. 
       (Default; proc->pr_WindowPtr, or WB screen from a task)  */

#define TDR_EasyStruct           (TDR_Dummy+4)
    /* (struct EasyStruct *) [OPTIONAL]
       - Pointer to your own private struct EasyStruct that has
       already been initialised.   (Default; internally allocated)  */

#define TDR_FormatString         (TDR_Dummy+5)
    /* (STRPTR) [OPTIONAL]
       - The format string using RawDoFmt style specifiers that match
       the number of argument array entries.
       If this tag is present, it will override a formatstring that
       may have already been supplied with a private TDR_EasyStruct. */

#define TDR_TitleString          (TDR_Dummy+6)
    /* (STRPTR) [OPTIONAL]
       - The title string for the requester.
       If this tag is present, it will override a title string that
       may have already been supplied with a private TDR_EasyStruct.  */

#define TDR_GadgetString         (TDR_Dummy+7)
    /* (STRPTR) [OPTIONAL]
       - The string spec for the gadgets/text for the requester.
       If this tag is present, it will override a Gadget string 
       that may have been supplied with a private TDR_EasyStruct.  */

#define TDR_ImageType            (TDR_Dummy+8)
    /* (uint32) - The visual style of this request. This argument has
       currently no effect before IPrefs is running, but should always
       be specified to indicate the style of request this is directed
       for.   (Default; TDRIMAGE_DEFAULT)
       The values for this tag are defined below.  */
enum 
{
    TDRIMAGE_DEFAULT,
    TDRIMAGE_INFO,
    TDRIMAGE_WARNING,
    TDRIMAGE_ERROR,
    TDRIMAGE_QUESTION,
    TDRIMAGE_INSERTDISK
};

#define TDR_ArgArray             (TDR_Dummy+9)
    /* (APTR) [OPTIONAL]
       - A pointer to a completely initialised argument array with
       the number of entries that correspond to the RawDoFmt()
       format specifiers.

       Do not use this tag if you want to specify up to the first
       10 arguments individually with the following TDR_Arg# tags. */

#define TDR_Inactive             (TDR_Dummy+10)
    /* (int32; Boolean) - Boolean value to specify the requester should
       not be activated to avoid its stealing the users input focus.
       You should set this to TRUE when the gadgets of your requester
       contain keyboard shortcuts and its possible that the user is
       currently typing text in another application (otherwise the
       user could answer the requester by accident). This tag has
       currently no effect before IPrefs is running, keyboard shortcuts
       also won't work before either.  (Default; FALSE) */

#define TDR_CharSet              (TDR_Dummy+11)
    /* (uint32) - Character set for the requester's text and gadgets.
       Defaults to 0, meaning the charset of the screen font which
       will be the current system default charset in most cases.
       This tag has currently no effect before IPrefs is running.
       The tag value is based on the IANA MIBenum value for charsets.
       See the autodoc for diskfont.library/ObtainCharsetInfo().
       TDR_CharSet should be set by localized applications that want
       to display localized requesters, they tell locale.library in
       OpenCatalog() that it shall not convert the catalog charset to
       current system default charset and use the value of 
       Catalog->cat_CodeSet for the TDR_CharSet.    (Default; 0) */

#define TDR_NonBlocking          (TDR_Dummy+12)
    /* (int32; Boolean) - [OPTIONAL] switch to prevent this function from
       attempting any disk based I/O whatsoever.
       This makes the function safe to call at any time from handlers
       and filesystems and in some cases performing dospacket I/O from
       a task context.
       This tag will effectively bypass the use of any reaction components
       that may cause blocking issues and re-apply the original dos.library
       code that only calls the intuition library EasyRequest() function, 
       as if it was never patched by "IPrefs". (Default; FALSE) */

#define TDR_Arg1            (TDR_Dummy+20)
#define TDR_Arg2            (TDR_Dummy+21)
#define TDR_Arg3            (TDR_Dummy+22)
#define TDR_Arg4            (TDR_Dummy+23)
#define TDR_Arg5            (TDR_Dummy+24)
#define TDR_Arg6            (TDR_Dummy+25)
#define TDR_Arg7            (TDR_Dummy+26)
#define TDR_Arg8            (TDR_Dummy+27)
#define TDR_Arg9            (TDR_Dummy+28)
#define TDR_Arg10           (TDR_Dummy+29)




/*****************************************************************************/
/* Definitions for the (V50) GetSegListInfo() call,  classes first.
 */

#define GSLI_Dummy          (TAG_USER+4000)
 
#define GSLI_NATIVE         (GSLI_Dummy+1)   
#define GSLI_Native         (GSLI_Dummy+1)  
    /* (struct PseudoSegList **) - if PPC executable.
     * this only means it's native and executable,
     * it does NOT imply any particular type of executable. 
     */

#define GSLI_68KHUNK        (GSLI_Dummy+5)
    /* (BPTR *) - seglist, if old 68K HUNK style seglist.*/

#define GSLI_68KOVLAY       (GSLI_Dummy+6)
    /* (BPTR *) - seglist, if old 68K OVERLAY seglist.   */


/*------ Misc tags follow ------*/

#define GSLI_PSData         (GSLI_Dummy+2)
#define GSLI_Data           (GSLI_Dummy+2)  /* old synonym */
    /* (APTR *) - ptr to ps_Data of a struct pseudoseglist. */ 

#define GSLI_68KPS          (GSLI_Dummy+3)
    /* (struct PseudoSeglist **) - if 68K pseudoseglist*/ 

#define GSLI_ElfHandle      (GSLI_Dummy+4) 
    /* (Elf32_Handle *) - if Elf32 style pseudoseglist. */

#define GSLI_68KFileSize    (GSLI_Dummy+7)
    /* (uint32 *) - size of the 68K binary load file. 51.58  */

#define GSLI_68KFileXsum    (GSLI_Dummy+8)
    /* (uint32 *) - 32 bit xsum of the 68K binary load file. 51.58 */

#define GSLI_HeaderSize     (GSLI_Dummy+9)
    /* (uint32 *) - byte size of the DOS allocated segment header. 51.99 */

#define GSLI_SegmentSize    (GSLI_Dummy+10)
    /* (uint32 *) - byte size of the entire segment allocation.  52.13  */
  
#define GSLI_VersionString  (GSLI_Dummy+11)
    /* (STRPTR *) - returns a "$VER:" version string in a seglist. 52.18 */

#define GSLI_ResidentVersionString	 (GSLI_Dummy+12)
    /* (STRPTR *) - returns Resident->rt_IDString version string. 53.21 */

#define GSLI_ResidentStruct	 (GSLI_Dummy+13)
    /* (struct Resident **) - returns a pointer to a struct Resident. 53.70 */

#define GSLI_SectionData     (GSLI_Dummy+14)
    /* (APTR *) - returns a pointer to the section data. 54.40 */

#define GSLI_SectionSize     (GSLI_Dummy+15)
    /* (uint32 *) - returns the size of GSLI_SectionData.  54.40 */

#define GSLI_NextSegment     (GSLI_Dummy+16)
    /* (BPTR *) - returns the next segment BPTR.         54.49 */

#define GSLI_IdentKey        (GSLI_Dummy+17)
    /* (uint32 *) - returns the ikey value of a segment.   54.50 */

#define GSLI_ResidentMatchWord (GSLI_Dummy+18)
    /* (uint16) - Specify the rt_MatchWord comparison value for a custom
       Resident struct scan.  Defaults to RTC_MATCHWORD if unspecified. 54.120 */


/****************************************************************************/
/* Tags for DosControl() 
 */

#define DC_Dummy                (TAG_USER + 5000)

#define DC_WildStarW            (DC_Dummy+1)
    /*  (int32) - Boolean, Write to the default WildStar switch. */
    /*  Default is FALSE. */

#define DC_WildStarR            (DC_Dummy+2)
    /* (int32 *) - Obtain the state of WildStar switch. */

#define DC_FHBufferW            (DC_Dummy+3)
    /* (int32) - Writes the size in bytes for all FileHandle buffers. */
    /* The default value for V50 DOS is 8000 bytes.  */

#define DC_FHBufferR            (DC_Dummy+4)
    /* (int32 *) - Obtain the size in bytes for FH Buffers. */

#define DC_WarnPostTimeW        (DC_Dummy+5)
    /* (int32) - Write the number of seconds to post warning for.  */
    /* Default posting time is currently 120 seconds. */

#define DC_WarnPostTimeR        (DC_Dummy+6)
    /* (int32 *) - Obtain the value for WarnPostTime.  */

#define DC_WarnWaitTimeW        (DC_Dummy+7)
    /* (int32) - Write the number of seconds to wait between warnings. */
    /* Default wait time is currently 5 seconds.  */

#define DC_WarnWaitTimeR        (DC_Dummy+8)
    /* (int32 *) - Obtain the value for WarnWaitTime. */

#define DC_MinProcStackW        (DC_Dummy+9)
    /* (int32) - Write the number of bytes to enforce as min proc stack */

#define DC_MinProcStackR        (DC_Dummy+10)
    /* (int32 *) - Obtain the value for MinProcStack. */

#define DC_AssignMountW         (DC_Dummy+11)
    /* (int32) - Write to the default AssignMount switch. */

#define DC_AssignMountR         (DC_Dummy+12)
    /* (int32 *) - Obtain the state of the AssignMount switch. */

#define DC_BootCliFontSizeW     (DC_Dummy+13)
    /* (int32) - Write the boot cli font size. TOPAZ_SIXTY or TOPAZ_EIGHTY */

#define DC_BootCliFontSizeR     (DC_Dummy+14)
    /* (int32 *) - Obtain the size of the boot cli font size. */

#define DC_Reload68KApplistW    (DC_Dummy+15)
    /* (int32) - DOSTRUE will cause DEVS:applications.dos config file to 
                 reload from disk. 51.58 */

#define DC_unused1R             (DC_Dummy+16)  
    /* pad tag for DC_Reload68KApplistR slot */

#define DC_BootCliCloseGadgetW  (DC_Dummy+17)
    /* (int32) - DOSTRUE will cause the boot cli to have a close gadget. 52.8 */

#define DC_BootCliCloseGadgetR  (DC_Dummy+18)
    /* (int32 *) - Obtain the state of the boot cli close gadget switch. 52.8 */

#define DC_LocaleBaseW          (DC_Dummy+19)
    /* (struct LocaleBase *) - Write the locale base pointer for DOS to access. V54 */

#define DC_LocaleBaseR          (DC_Dummy+20)
    /* (struct LocaleBase **) - Obtain the locale base pointer value from DOS. V54 */

#define DC_PetuniaHookW         (DC_Dummy+21)
    /* (struct Hook *) - Write the petunia emulator hook value for DOS to call. 54.50 */

#define DC_PetuniaHookR         (DC_Dummy+22)
    /* (struct Hook **) - Obtain DOS' Petunia emulator hook pointer.  54.50 */

#define DC_AddLoadSegHookW      (DC_Dummy+23)
    /* (struct Hook *) - Add this hook to LoadSeg() callback hook list. 54.50 */
 
#define DC_RemLoadSegHookW      (DC_Dummy+24)
    /* (struct Hook *) - Remove this hook from the LoadSeg() callback hook list. 54.50 */



/****************************************************************************/
/* Tags for ReadLineItem() 
 */

#define RLI_Dummy                (TAG_USER + 5500)

#define RLI_FileHandleInput      (RLI_Dummy+1)
    /* (BPTR) - Read with FGetC() from this filehandle.
       Default is FGetC(Input()); */

#define RLI_CSourceInput         (RLI_Dummy+2)
    /* (struct CSource *) - Read from this CSource stream.
       Default is FGetC(Input()); */


#define RLI_EscapeChars          (RLI_Dummy+10)
    /* (STRPTR) - Nul-terminated string of one or more characters
       to be recognised as escape characters.  
       This may be an empty string "" or NULL, for none.
       Defaults to "*".  */

#define RLI_MultiLine            (RLI_Dummy+11)
    /* (int32; boolean) - Enable Multi-line processing.
       Defaults to FALSE.  */

#define RLI_CommentChars         (RLI_Dummy+12)
    /* (STRPTR) - Nul-terminated string of one or more characters
       to be used as a comment marker.
       This may be an empty string "" or NULL, for none.
       Defaults to "".  */

#define RLI_Substitute_N         (RLI_Dummy+13)
    /* (int32) - Boolean, Substitute quoted escaped "N" to the hex
       char 0x0a.   Only works when RLI_EscapeChars is not "" or NULL.
       Defaults to TRUE.  */

#define RLI_Substitute_E         (RLI_Dummy+14)
    /* (int32) - Boolean, Substitute quoted escaped "E" to the hex
       char 0x1b.   Only works when RLI_EscapeChars is not "" or NULL.
       Defaults to TRUE.  */




/*****************************************************************************/
/* definitions for the (V53) LockTagList() call
 */

#define LK_Dummy          (TAG_USER+5750)

#define LK_Name           (LK_Dummy+1)
    /* (STRPTR) - Name of object to lock. */

#define LK_Mode           (LK_Dummy+2)
    /* (int32) - Access mode; SHARED_LOCK or EXCLUSIVE_LOCK */

#define LK_InfoMask       (LK_Dummy+3)
    /* (uint32 *) - pointer to info mask storage area. */

#define LK_SoftLinks      (LK_Dummy+4)
    /* (uint32 *) - pointer to softlink count storage area. */

#define LK_ResolveSL      (LK_Dummy+5)
    /* (int32) - Boolean switch to control softlink resolution. */
 
#define LK_ResolveMA      (LK_Dummy+6)
    /* (int32) - Boolean switch to control multi-assign resolution. 54.21 */
 




/****************************************************************************/
/* Tags for SetFileHandleAttr() 
 */

#define FH_Dummy               (TAG_USER + 6000)

#define FH_BufferSize          (FH_Dummy + 1)
#define FH_UserBuffer          (FH_Dummy + 2)
#define FH_BufferMode          (FH_Dummy + 3)
#define FH_Locking             (FH_Dummy + 4)
#define FH_EndStream           (FH_Dummy + 5)



/****************************************************************************/
/* Tags for SetOwnerInfo(), GetOwnerInfo(). 
 */

#define OI_Dummy               (TAG_USER + 6200)

#define OI_StringNameInput     (OI_Dummy + 1)
    /*  (STRPTR) - Pointer to a string identifying a filesystem object.
        This tag is mutually exclusive with OI_Process. */
#define OI_StringName  OI_StringNameInput
  
#define OI_ProcessInput        (OI_Dummy + 2)
    /*  (struct Process *) - Pointer to a process structure,
        or NULL for this process, to identify a process.
        This tag is mutually exclusive with OI_StringName. */
#define OI_Process     OI_ProcessInput

#define OI_OwnerUID            (OI_Dummy + 10)
    /*  GetOwnerInfo(), Pointer to a uint32 sized storage area.
        Returns the value of the objects UID field.
        -
        SetOwnerInfo() - uint32 value.
        Sets the value of an objects UID field. */

#define OI_OwnerGID            (OI_Dummy + 11)
    /*  GetOwnerInfo() - Pointer to a uint32 sized storage area.
        Returns the value of the objects GID field.
        -
        SetOwnerInfo() - uint32 value.
        Sets the value of an objects GID field. */





/****************************************************************************/
/* Common tags for ExamineObject() and ObtainDirContext().  
 */ 

#define  EX_Dummy                (TAG_USER+6500)

#define  EX_StringNameInput      (EX_Dummy+1)
#define  EX_StringName           (EX_Dummy+1)         /* alias */
    /*   (STRPTR) - Pointer to a nul-terminated string name to
         identify the filesystem object required.  */

#define  EX_FileHandleInput      (EX_Dummy+2)
#define  EX_FileHandle           (EX_Dummy+2)         /* alias */
    /*   (BPTR) - BCPL pointer to a FileHandle.
         Identify the parent directory from the stream pointed to by
         an open FileHandle.  */

#define  EX_LockInput            (EX_Dummy+3)
#define  EX_FileLockInput        (EX_Dummy+3)         /* alias */
#define  EX_DirLockInput         (EX_Dummy+3)         /* alias */
#define  EX_FileLock             (EX_Dummy+3)         /* alias */
#define  EX_DirLock              (EX_Dummy+3)         /* alias */
    /*   (BPTR) - BCPL pointer to a Lock.
         Identify the filesystem object by this lock.
         The lock is always passed directly throught to the filesystem. */


/*
 * The following is only for use with ExamineObject(). (Added 54.54+) 
 */
#define  EX_RawStringNameInput   (EX_Dummy+4)
#define  EX_RawStringName        (EX_Dummy+4)         /* alias */
    /*   (STRPTR) - Pointer to a nul-terminated string name to identify
         the filesystem object to be examined.  */




/*
 * The following are used only with ObtainDirContext() when 
 * preparing a context for ExamineDir(). 
 */

#define  EX_DataFields           (EX_Dummy+10)
    /*  (uint32) - A bitmask to indicate which items of data are to be
        filled in by the filesystem for the ExamineData structures. */

#define  EX_MatchFunc            (EX_Dummy+11)
    /*  (struct Hook *) - Pointer to a custom Hook structure which has the
        h_Entry function pointer set to a filtering function. 
        (Default = NULL) for the internal filter to be used instead. */

#define  EX_MatchString          (EX_Dummy+12)
    /* (STRPTR) - A pointer to a pre-parsed pattern string. (Default=NULL)
       If this field is NULL then all entries will be returned from the 
       internal filter function.  */

#define  EX_DoCurrentDir          (EX_Dummy+13)
    /*  (BOOLEAN) - Set TRUE if you wish DOS to make the reference to 
        the specified directory the current directory. (Default=FALSE) */

#define  EX_ResetContext          (EX_Dummy+14)
    /*  (APTR) - Pointer to a previous context for which a change of any
        parameter/s are required.  (Default = NULL) */




/****************************************************************************/
/* Tags for FileSystemAttr() 
 */

#define FSA_Dummy                    (TAG_USER + 9000)

#define FSA_StringNameInput          (FSA_Dummy+1)
    /* (STRPTR) - Identify the filesystem by this name reference. */

#define FSA_FileHandleInput          (FSA_Dummy+2)
    /* (BPTR) - Identify the filesystem by this FileHandle. */

#define FSA_LockInput                (FSA_Dummy+3)
    /* (BPTR) - Identify the filesystem by this Lock. */
#define FSA_FileLockInput             FSA_LockInput

#define FSA_MsgPortInput             (FSA_Dummy+4)
    /* (struct MsgPort *)  Identify the filesystem by this message port.
     *  NOTE: This tag was added in dos.library 51.96
     */

#define FSA_ShowRequesters           (FSA_Dummy+8)
    /* (boolean) - TRUE to allow requesters to appear, defaults to FALSE */
 

#define FSA_MaxFileNameLengthR       (FSA_Dummy+10)
    /* (uint32 *) - Obtain the maximum filename length. (including \0) */  

#define FSA_MaxFileNameLengthW       (FSA_Dummy+11)
    /* (uint32) - Set the maximum filename length. (including \0) */  

#define FSA_VersionNumberR           (FSA_Dummy+12)
    /* (uint32 *) - Obtain the version/rev number for the filesystem. */

#define FSA_DOSTypeR                 (FSA_Dummy+13)
    /* (uint32 *) - Obtain the dostype identifier for the filesystem. */

#define FSA_ActivityFlushTimeoutR    (FSA_Dummy+14)
    /* (uint32 *) - Obtain the mS (1000th second) before a flush while active occurs. */

#define FSA_ActivityFlushTimeoutW    (FSA_Dummy+15)
    /* (uint32) - Set the mS (1000th second) before a flush while active occurs. */

#define FSA_InactivityFlushTimeoutR  (FSA_Dummy+16)
    /* (uint32 *) - Obtain the mS (1000th second) before a flush when inactive occurs. */

#define FSA_InactivityFlushTimeoutW  (FSA_Dummy+17)
    /* (uint32) - Set the mS (1000th second) before a flush when inactive occurs. */

#define FSA_MaxRecycledEntriesR      (FSA_Dummy+18)
    /* (uint32 *) - Obtain the number of recycled entries supported. */

#define FSA_MaxRecycledEntriesW      (FSA_Dummy+19)
    /* (uint32) - Set the number of recycled entries supported. */

#define FSA_HasRecycledEntriesR      (FSA_Dummy+20)
    /* (int32 *) - Obtain boolean value if the filesystem supports recycled entries. */

#define FSA_VersionStringR           (FSA_Dummy+21)
    /* (STRPTR) - Obtain a copy of the version string for the filesystem. */

#define FSA_VersionStringR_BufSize   (FSA_Dummy+22)
    /* (uint32) - Sub tag to specify the space provided for FSA_VersionStringR. */

#define FSA_VersionStringR_Len    FSA_VersionStringR_BufSize  /* compatibility alias */

#define FSA_MaxFileSizeR             (FSA_Dummy+24)
    /* (uint64 *) - Obtain the maximum file size the filesystem supports. */

/*
**  NOTE: (FSA_Dummy+25) to (FSA_Dummy+200) are exclusively reserved for DOS.
**  No private tags for FileSystemAttr() are to be implemented in this range.
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

#endif /* DOS_DOSTAGS_H */
