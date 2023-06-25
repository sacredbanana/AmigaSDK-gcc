#ifndef RESOURCES_DOSFILEDIRNOTIFY_H
#define RESOURCES_DOSFILEDIRNOTIFY_H
/*
**    $VER: filedirnotify.h  54.100 (07.09.2020)
**
**    DOSFileDirNotify.resource description
**
**    Copyright (C) 1985-2009 Hyperion Entertainment VOF.
**        All Rights Reserved
**
**    Copyright (c) 2010 Hyperion Entertainment CVBA.
**        All Rights Reserved.
*/

#ifndef   EXEC_NODES_H
#include <exec/libraries.h>
#endif

#ifndef EXEC_PORTS_H
#include <exec/ports.h>
#endif

#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
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

#define FDNR_NAME "DOSFileDirNotify.resource"


/****************************************************************************
 * This resource allows the dos.library notification handler process to 
 * rendezvous with the notification list and also provide statistical data 
 * for any other callers requiring this information by providing a copy of the 
 * DOS libraries internal filesystem style notification handlers notify list.
 *
 * Also this resource provided a method to globally monitor all filesystem
 * object changes that occur on all mounted volumes. 
 ****************************************************************************/

struct FDNResource
{
    struct Library  ResourceNode;


    /*
    ** Notification request list functions
    ** This resource was added in doslib 53.23 
    */
    struct List * VARARGS68K (*ObtainNotifyList)  (void);
    void          VARARGS68K (*ReleaseNotifyList) (struct List *);


    /*
    ** DOS event monitoring functions. 
    ** These vectors were added in doslib 53.81 - previously NULL pointers.
    */
    void          VARARGS68K (*AddEventHook)      (struct Hook *);
    void          VARARGS68K (*RemoveEventHook)   (struct Hook *); 


    int32         Reserved[4];
};








/****************************************************************************
 * NOTIFICATION REQUEST LIST: 
 *
 * The notification list returned is a standard exec list with a standard 
 * exec node for each active dos.library notification request.
 *
 * The list pointer is obtained by calling the ObtainNotifyList() function, 
 * at which time it will allocate a list structure and copy all active 
 * dos.library notify requests nodes and append them to the list.
 *
 * A corresponding call to the ReleaseNotifyList() function is mandatory to
 * free all the memory allocated by the ObtainNotifyList() function.
 * The same list pointer from  ObtainNotifyList() MUST be passed to the
 * ReleaseNotifyList() function call.
 *
 * The node->ln_Type is the type of notification, it is initialised with
 * the value from; notifyrequest->nr_Flags & 0xFF;
 * This represents a bitfield that may contain any combinations of the 
 * following flags;  NRF_SEND_MESSAGE, NRF_SEND_SIGNAL, NRF_CALL_HOOK,
 *                   NRF_WAIT_REPLY,   NRF_NOTIFY_INITIAL
 *
 * The node->ln_Name points to the full DOS path of the object being monitored 
 * as found from the string in; notifyrequest->nr_FullName;
 *
 ****************************************************************************
 *
 * EXAMPLE:
 *
 *  struct FDNResource *resource;
 *  struct List *list;
 *  struct Node *node;
 *  STRPTR type;
 *
 *  //resource will only open from dos 53.23+
 *  if(( resource = IExec->OpenResource(FDNR_NAME) ))
 *  {
 *      if(( list = resource->ObtainNotifyList() ))
 *      {
 *          IDOS->PutStr("The following notifications are being serviced by DOS...\n\n");
 *
 *          for(node = IExec->GetHead(list); node; node = IExec->GetSucc(node) )
 *          {
 *              if( node->ln_Type & NRF_SEND_MESSAGE )
 *                  type = "NRF_SEND_MESSAGE";
 *              else if( node->ln_Type & NRF_SEND_SIGNAL )
 *                  type = "NRF_SEND_SIGNAL ";
 *              else if( node->ln_Type & NRF_CALL_HOOK )
 *                  type = "NRF_CALL_HOOK   ";
 *              else
 *                  type = "????????????????";
 *
 *              IDOS->Printf("%s %s\n", type, node->ln_Name);
 *          }
 *          resource->ReleaseNotifyList( list );
 *      }
 *  }
 *
 ****************************************************************************/











/****************************************************************************/
/* Structure used by the dos notification handler for filesystem events.    */
/* This structure is READ-ONLY.                                             */
/****************************************************************************/

struct DosEventMsg
{
    struct Message  MN;           /* message struct */
    struct TimeVal  TV;           /* Time stamp when event message was sent  */
    CONST_STRPTR    FuncName;     /* DOS function name called to cause event */
    uint32          ProcessID;    /* PID (ProcessID) that caused the event   */
    CONST_STRPTR    TaskName;     /* Name of the task that caused the event  */
    struct MsgPort *MsgPort;      /* filesystem message port for the object  */
    int32           NHM_Action;   /* NHM_Action flags used for notify hooks  */
    CONST_STRPTR    FullName;     /* full device-centric path & object name. */
    uint32          Reserved[4];  /* reserved fields for dos expansion.      */
};
 




/****************************************************************************
 * FILESYSTEM EVENT MONITOR:
 *
 * A new feature added in dos.library 53.81 allows any program to monitor all
 * notification handler input events that are generated by various dos.library
 * API functions.
 *
 * The monitoring is performed by adding a struct Hook to the internal list
 * where the hooks h_Entry function will be called within the context of the 
 * notify handler process for EVERY DOS EVENT that modifies any filesystem 
 * object on any volume.
 *
 * The hook calling occurs just after any notifications have first been 
 * processed (if any) and just before the DosEventMsg is deleted.
 *
 * For filtering events for specific volumes, simply compare the message port
 * of the event to that of the volume you are interested in.
 *
 * The Hook function will be invoked from the DOS notify handler context with
 * the following parameters:
 *     void func(struct Hook *hook, int32 reserved, struct DosEventMsg *msg);
 *
 *
 * The DosEventMsg (shown above) is READ-ONLY.
 *
 * NOTE: It is absolutely mandatory to RemoveEventHook() your hook before
 *       your program exits, otherwise a system crash will definately result.
 *       
 *       Attempting to RemoveEventHook() an already removed hook is harmless.
 *       Attempting to RemoveEventHook() a never added hook is also harmless.
 *       
 *       Rather than checking the dos.library version and revision, simply 
 *       checking for NULL vector pointer will be sufficient if the resource
 *       opens as these two vectors were previously NULL pointers.
 *
 ****************************************************************************
 *
 * EXAMPLE:
 *
 *  struct MyHookData
 *  {
 *      struct DOSIFace *idos;
 *      BPTR             stream;
 *  };
 *
 *
 *  STATIC void ehook(struct Hook *h, int32 o UNUSED, struct DosEventMsg *m)
 *  {
 *      struct MyHookData *hd = h->h_Data;
 *  
 *      hd->idos->FPrintf(hd->stream, "%-20s %-50s %-20s PID=%lu \n", 
 *                    m->FuncName, m->FullName, m->TaskName, m->ProcessID);
 *  }
 *
 *
 *  void event_monitor(void)
 *  {
 *      struct FDNResource *resource = IExec->OpenResource(FDNR_NAME);
 *      struct Hook         HOOK;
 *      struct MyHookData   HD;
 *  
 *      if( resource )   //resource only opens from dos 53.23
 *      {
 *          if( resource->AddEventHook ) //added in dos 53.81, previously 0
 *          {
 *              HD.idos   = IDOS;
 *              HD.stream = IDOS->Output();
 *  
 *              HOOK.h_Entry = (APTR)ehook;
 *              HOOK.h_Data  = &HD;
 *  
 *              resource->AddEventHook(&HOOK);
 *  
 *              IExec->Wait(SIGBREAKF_CTRL_C);    //wait for CTRL-C to exit.
 *  
 *              resource->RemoveEventHook(&HOOK);
 *          }
 *      }
 *  }
 *
 *
 ****************************************************************************/





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

#endif /* RESOURCES_DOSFILEDIRNOTIFY_H */
