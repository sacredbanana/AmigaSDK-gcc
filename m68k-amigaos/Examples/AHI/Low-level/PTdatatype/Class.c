/*
**  Q&D Protracker DataType
**
**      Written by Martin Blom, based on the AIFF DataType by
**  Olaf `Olsen' Barthel <olsen@sourcery.han.de>
**  Public domain
**
*/

extern void KPrintF(char *fmt,...);
extern void __asm SlaveProcEntry(void);

#include "Data.h"

/* Our PlayerFunc() */

void __asm __saveds __interrupt PlayerFunc(
    register __a0 struct Hook *me,
    register __a2 struct AHIAudioCtrl *AudioCtrl,
    register __a1 void *unused)
{
  struct ObjectData *ObjectData=me->h_Data;

  mt_music(&ObjectData->ptdata);
}


  /* ClassDispatch():
   *
   *  The class dispatcher routine.
   */

Object * LIBENT
ClassDispatch(REG(a0) Class *class,REG(a2) Object *object,REG(a1) Msg msg)
{
  struct  ClassBase *ClassBase = (struct ClassBase *) class->cl_UserData;
  Object  *Result = NULL;
  struct  ObjectData *ObjectData=NULL;
  struct MsgPort *replyport;

  replyport = CreateMsgPort();

  if(replyport == NULL)
  {
    return NULL;
  }

    // What message is it?

  switch(msg->MethodID)
  {
      // Create a new instance

    case OM_NEW:
    {
      BOOL success=FALSE;
      BPTR File=NULL;

      if(Result = (Object *)DoSuperMethodA(class,object,msg))
      {

        if(ObjectData = (struct ObjectData *) AllocVec(sizeof(struct ObjectData), MEMF_CLEAR))
        {
            // Fill in the remaining information

          SetDTAttrs(Result,NULL,NULL,
            DTA_ObjName,    GetTagData(DTA_Name,NULL,((struct opSet *)msg)->ops_AttrList),
            DTA_UserData,   ObjectData,
            SDTA_Cycles,    1,
            TAG_DONE);

          ObjectData->PlayerHook.h_Entry=(ULONG (*)()) PlayerFunc;
          ObjectData->PlayerHook.h_Data=ObjectData;

          Forbid();
          if(ObjectData->Slave = CreateNewProcTags(
              NP_Entry,     &SlaveProcEntry,
              NP_Name,      ClassBase->LibNode.lib_Node.ln_Name,
              TAG_DONE))
          {
            ObjectData->Slave->pr_Task.tc_UserData = ClassBase;
          }
          Permit();

          if(ObjectData->Slave)
          {
            GetDTAttrs(Result,
                DTA_Handle,&File,
                TAG_DONE);
            if(File)
            {
              LONG size;

              Seek(File, 0, OFFSET_END);
              size = Seek(File, 0, OFFSET_BEGINNING);
              if(ObjectData->ptdata.ptd_ModuleAddress=AllocVec(size, MEMF_PUBLIC))
              {
                if(Read(File, ObjectData->ptdata.ptd_ModuleAddress, size) == size)
                {
                    // Check if known module format
                  if(*((ULONG *) ObjectData->ptdata.ptd_ModuleAddress+(1080/4)) == MKID)
                  {
                    ObjectData->Message.mn_ReplyPort = replyport;
                    ObjectData->Command = COMMAND_INIT;
                    PutMsg(&ObjectData->Slave->pr_MsgPort,
                           (struct Message *) ObjectData);
                    WaitPort(replyport);
                    GetMsg(replyport);

                    if(ObjectData->Command != COMMAND_ERROR)
                    {
                      success=TRUE;
                    }
                  }
                }
              }
            }
          }
        }
      }

      if(!success)
      {
        CoerceMethod(class,Result,OM_DISPOSE);
        Result = NULL;
      }
      break;
    }


    case GM_GOACTIVE:
    case DTM_TRIGGER:
      {
        GetDTAttrs(object,
          DTA_UserData, &ObjectData,
          TAG_DONE);
        if(ObjectData)
        {
          ObjectData->Message.mn_ReplyPort = replyport;
          ObjectData->Command = COMMAND_START;
          PutMsg(&ObjectData->Slave->pr_MsgPort,
                 (struct Message *) ObjectData);
          WaitPort(replyport);
          GetMsg(replyport);
        }
      }
      Result = (Object *)DoSuperMethodA(class,object,msg);
      break;



    case OM_DISPOSE:
      GetDTAttrs(object,
        DTA_UserData, &ObjectData,
        TAG_DONE);
      if(ObjectData)
      {
        SetDTAttrs(object,NULL,NULL,
          DTA_UserData, NULL,
          TAG_DONE);

        ObjectData->Message.mn_ReplyPort = replyport;
        ObjectData->Command = COMMAND_END;
        PutMsg(&ObjectData->Slave->pr_MsgPort,
               (struct Message *) ObjectData);
        WaitPort(replyport);
        GetMsg(replyport);

        ObjectData->Command = COMMAND_QUIT;
        PutMsg(&ObjectData->Slave->pr_MsgPort,
               (struct Message *) ObjectData);
        WaitPort(replyport);
        GetMsg(replyport);

        FreeVec(ObjectData->ptdata.ptd_ModuleAddress);
        FreeVec(ObjectData);
      }
      Result = (Object *)DoSuperMethodA(class,object,msg);
      break;

      // Let the superclass handle the rest

    default:

      Result = (Object *)DoSuperMethodA(class,object,msg);

      break;
  }

  DeleteMsgPort(replyport);
  return(Result);
}


void LIBENT
SlaveEntry(REG(a6) struct ClassBase *ClassBase)
{
  struct Process    *proc;
  BOOL quit = FALSE;

  proc = (struct Process *)FindTask(NULL);

  while(! quit)
  {
    struct ObjectData *ObjectData;

    WaitPort(&proc->pr_MsgPort);
    ObjectData = (struct ObjectData *) GetMsg(&proc->pr_MsgPort);

    switch(ObjectData->Command)
    {
      case COMMAND_INIT:
      {
        char prefs[40]="0 0";
        int offset;
        LONG audiomode, freq;

        ObjectData->ptdata.ptd_AHIBase = AHIBase;

          // Get desired audio mode and frequency

        GetVar( "ENV:DataTypes/Protracker", prefs, sizeof prefs, NULL );
        offset=StrToLong(prefs,&audiomode);
        if(offset  != -1)
        {
          if(StrToLong(&prefs[offset],&freq) != -1)
          {
            if(ObjectData->ptdata.ptd_AudioCtrl=AHI_AllocAudio(
                AHIA_AudioID,audiomode,
                AHIA_MixFreq,freq,
                AHIA_Channels,4,
                AHIA_Sounds,1,
                AHIA_PlayerFunc,&ObjectData->PlayerHook,
                AHIA_PlayerFreq,50<<16,
                AHIA_MinPlayerFreq,(32*2/5)<<16,
                AHIA_MaxPlayerFreq,(255*2/5)<<16,
                TAG_DONE))
            {
              if(mt_init(&ObjectData->ptdata))
              {
                ObjectData->ModInitialized=TRUE;
              }
            }
          }
        }
        if(! ObjectData->ModInitialized)
        {
          ObjectData->Command = COMMAND_ERROR;
        }
        ReplyMsg((struct Message *) ObjectData);
        break;
      }

      case COMMAND_START:
        ReplyMsg((struct Message *) ObjectData);    // Don't block!
        if(ObjectData->ModInitialized)
        {
          mt_start(&ObjectData->ptdata);

        }
        break;

      case COMMAND_END:
        ReplyMsg((struct Message *) ObjectData);    // Don't block!
        if(ObjectData->ModInitialized)
        {
          mt_end(&ObjectData->ptdata);
        }
        break;

      case COMMAND_QUIT:
        AHI_FreeAudio(ObjectData->ptdata.ptd_AudioCtrl);
        ObjectData->Slave = NULL;
        quit = TRUE;
        ReplyMsg((struct Message *) ObjectData);
        break;
    }
  }
}
