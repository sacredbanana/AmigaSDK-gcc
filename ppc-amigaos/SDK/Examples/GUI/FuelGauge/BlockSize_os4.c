;/* 
gcc -o BlockSize_OS4 BlockSize_os4.c -lauto -Wall
quit
*/


//
//  Converted to C from AmigaE source BlockSize.e
//  BlockSize.e written by Dave Noris (DaveN).
//  OS4 update changes by C.Wenzel. 2022.
//

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/dos.h>
#include <proto/utility.h>

#include <proto/fuelgauge.h>
#include <proto/window.h>
#include <proto/layout.h>
#include <proto/radiobutton.h>
#include <proto/chooser.h>
#include <proto/space.h>
#include <proto/requester.h>
#include <proto/getfile.h>
#include <proto/label.h>
#include <proto/utility.h>


#include <intuition/icclass.h>
#include <images/label.h>
#include <classes/window.h>
#include <classes/requester.h>

#include <gadgets/fuelgauge.h>
#include <gadgets/layout.h>
#include <gadgets/radiobutton.h>
#include <gadgets/chooser.h>
#include <gadgets/getfile.h>

#include <reaction/reaction_macros.h>
#include <stdarg.h>



Object *win;

struct Window *window;
struct MsgPort *AppPort;
struct List chooserlist;
struct Hook idcmphook;

enum
{
    OBJ_512,
    OBJ_1024,
    OBJ_2048,
    OBJ_4096,
    OBJ_8192,
    OBJ_16384,
    OBJ_OVER_16384,
    OBJ_ROOT_LAYOUT,
    OBJ_RESET,
    OBJ_GETFILE,
    OBJ_HIDDEN_CHOOSER,
    OBJ_RESET_2,
    OBJ_BLOCKSIZE,
    OBJ_VOL_OTHER,
    OBJ_START,
    OBJ_STOP,
    OBJ_RADIO,
    OBJ_FUEL_DONE,
    OBJ_NUM
};

enum
{
    RADIO_1, RADIO_2, RADIO_3, RADIO_4, RADIO_5, RADIO_6
};

Object *Objects[OBJ_NUM];
#define OBJ(x) Objects[x]
#define GAD(x) (struct Gadget *)Objects[x]

#define SPACE LAYOUT_AddChild, SpaceObject, End
#define FUELMAX 2000

STRPTR RadioDisplay[] =
{
    " Number of files by size",
    " Amount of the used space taken by size",
    " Kbytes wasted for present block size",
    " Percentage wasted for present block size",
    " Storage needed for files if block size used",
    " Percentage wasted if block size used",
    NULL
};

STRPTR VolOther[] =
{
    " Volume",
    " Other",
    NULL
};

typedef struct
{
    STRPTR  Name;
} Volume;

Volume *Volumes;

int16 radio_num = 0;        //  what is selected on the radio
uint32 fg_Max = FUELMAX;    //  what FUELGAUGE_Max is at the moment
uint16 NumVolumes;           //  number of volumes on computer
uint32 NumBlocksUsed;        //  blocks in use that the target says it has
uint32 BlocksDone;           //  blocks completed
uint32 filesizes[8];         //  array of files by size
uint32 filesizesblocks[8];   //  array of blocks used by each filesize
BOOL ReqSelect = FALSE;     //  was volume selected from the requester?
BOOL ReadyToStart = FALSE;  //  is it ok to start scan?
BOOL StopScan = FALSE;      //  has user clicked Stop while scanning?

BOOL MakeChooserList(struct List *);
VOID FreeChooserList(struct List *);
VOID GetVolumeList(void);
VOID FreeVolumeList(void);
STRPTR ConvertStr(BSTR);
VOID IDCMPFunc(struct Hook *,Object *,struct IntuiMessage *);
VOID GetBlockSize(void);
VOID Start(void);
VOID RecursiveScan(STRPTR, struct InfoData *);
VOID CheckForStop(void);
VOID UpdateProgressBar(int32, STRPTR);
VOID ShowResults(void);
VOID pickradio(void);
VOID ClearTargetStrings(void);
VOID ClearResults(void);
uint32 VARARGS68K MessageBox(char *, char *, ...);

// ***************************************************************


Object *
make_window(void)
{
    OBJ(OBJ_HIDDEN_CHOOSER) = ChooserObject,
        GA_ID,                  OBJ_HIDDEN_CHOOSER,
        GA_RelVerify,           TRUE,
        CHOOSER_Labels,         &chooserlist,
        CHOOSER_DropDown,       TRUE,
        CHOOSER_AutoFit,        TRUE,
        CHOOSER_Hidden,         TRUE,
        CHOOSER_MaxLabels,      NumVolumes,
        ICA_TARGET,             ICTARGET_IDCMP,
    End;  // Chooser

    return WindowObject,
        WA_ScreenTitle,        "ReAction Example",
        WA_Title,              "BlockSize",
        WA_DragBar,            TRUE,
        WA_CloseGadget,        TRUE,
        WA_SizeGadget,         TRUE,
        WA_DepthGadget,        TRUE,
        WA_Activate,           TRUE,
        WINDOW_LockHeight,     TRUE,
        WINDOW_IconifyGadget,  TRUE,
        WINDOW_IconTitle,      "Iconified",
        WINDOW_AppPort,        AppPort,
        WINDOW_IDCMPHookBits,  IDCMP_IDCMPUPDATE,
        WINDOW_IDCMPHook,      &idcmphook,
        WINDOW_Position,       WPOS_CENTERSCREEN,
        WINDOW_Layout,         OBJ(OBJ_ROOT_LAYOUT) = VLayoutObject,
            GA_ID,                 OBJ_ROOT_LAYOUT,

            LAYOUT_SpaceOuter,     TRUE,
            LAYOUT_AddChild,       HLayoutObject,
                LAYOUT_SpaceOuter,     TRUE,
                LAYOUT_EvenSize,       TRUE,
                LAYOUT_AddChild,       VLayoutObject,
                    LAYOUT_SpaceOuter,     TRUE,
                    LAYOUT_BevelStyle,     BVS_GROUP,
                    LAYOUT_Label,          " Target ",
                    LAYOUT_AddChild,       VLayoutObject,
                        LAYOUT_SpaceOuter,     TRUE,

                        LAYOUT_AddChild,       OBJ(OBJ_RESET) = LayoutObject,
                            LAYOUT_AddChild,       OBJ(OBJ_GETFILE) = GetFileObject,
                                GA_ID,                 OBJ_GETFILE,
                                GA_RelVerify,          TRUE,
                                GETFILE_ReadOnly,      TRUE,
                                GETFILE_DrawersOnly,   TRUE,
                                GETFILE_TitleText,     "Select Volume / Device / Drawer",
                            End,  // GetFile
                        End,  // Layout
                        SPACE,

                        LAYOUT_AddChild,       HLayoutObject,
                            LAYOUT_SpaceOuter,     TRUE,
                            LAYOUT_AddChild,    OBJ(OBJ_RESET_2) = HLayoutObject,

                                LAYOUT_AddChild,    OBJ(OBJ_VOL_OTHER) = RadioButtonObject,
                                    GA_ID,          OBJ_VOL_OTHER,
                                    GA_Text,        VolOther,
                                    GA_RelVerify,   TRUE,
                                End,  // RadioButton
                                CHILD_WeightedHeight,   0,
                                CHILD_WeightedWidth,   0,

                                LAYOUT_AddChild, VLayoutObject,
                                    LAYOUT_BevelStyle,  BVS_SBAR_HORIZ,
                                End,  // VLayout
                                CHILD_WeightedWidth,   0,

                                LAYOUT_AddChild,    OBJ(OBJ_BLOCKSIZE) = ButtonObject,
                                    GA_ID,          OBJ_BLOCKSIZE,
                                    GA_ReadOnly,    TRUE,
                                    GA_RelVerify,   TRUE,
                                End,  // Button
                                Label("   Block size: "),
                                CHILD_WeightedHeight,   0,

                            End,  // HLayout
                        End,  // HLayout

                        LAYOUT_AddChild,    HLayoutObject,
                            LAYOUT_AddChild,    Button("Start",OBJ_START),
                            LAYOUT_AddChild,    Button("Stop",OBJ_STOP),
                        End,  // HLayout
                        CHILD_WeightedHeight,   0,

                    End,  // VLayout
                End,  // VLayout
                LAYOUT_AddChild,    VLayoutObject,
                    LAYOUT_SpaceOuter,  TRUE,
                    LAYOUT_BevelStyle,  BVS_GROUP,
                    LAYOUT_Label,       " Display ",
                    LAYOUT_AddChild,    OBJ(OBJ_RADIO) = RadioButtonObject,
                        GA_Text,        RadioDisplay,
                        GA_ID,          OBJ_RADIO,
                        GA_RelVerify,   TRUE,
                    End,  // RadioButton
                End,  // VLayout
            End,  // HLayout

            LAYOUT_AddChild,    VLayoutObject,
                LAYOUT_SpaceOuter,  TRUE,
                LAYOUT_BevelStyle,  BVS_GROUP,
                LAYOUT_Label,       " Blocks read ",
                LAYOUT_AddChild,    OBJ(OBJ_FUEL_DONE) = FuelGaugeObject,
                    GA_ID,          OBJ_FUEL_DONE,
                    FUELGAUGE_Justification, FGJ_CENTER,
                    GA_RelVerify,   TRUE,
                End,
            End,  // VLayout
            SPACE,

            LAYOUT_AddChild,    VLayoutObject,
                LAYOUT_SpaceOuter,              TRUE,
                LAYOUT_BevelStyle,      BVS_GROUP,
                LAYOUT_Label,           " Results ",
                LAYOUT_AddChild,    OBJ(OBJ_512) = FuelGaugeObject,
                    GA_ID,          OBJ_512,
                    FUELGAUGE_Min,         0,
                    FUELGAUGE_Max,         FUELMAX,  // 1000,
                    FUELGAUGE_Percent,     FALSE,
                    FUELGAUGE_Ticks,       FALSE,
                    FUELGAUGE_Justification, FGJ_CENTER,
                    GA_Text,               "0",
                End,
                Label("512"),
                LAYOUT_AddChild,    OBJ(OBJ_1024) = FuelGaugeObject,
                    GA_ID,          OBJ_1024,
                    FUELGAUGE_Min,         0,
                    FUELGAUGE_Max,         FUELMAX,  // 1000,
                    FUELGAUGE_Percent,     FALSE,
                    FUELGAUGE_Ticks,       FALSE,
                    FUELGAUGE_Justification, FGJ_CENTER,
                    GA_Text,               "0",
                End,
                Label("1024"),
                LAYOUT_AddChild,    OBJ(OBJ_2048) = FuelGaugeObject,
                    GA_ID,          OBJ_2048,
                    FUELGAUGE_Min,         0,
                    FUELGAUGE_Max,         FUELMAX,  // 1000,
                    FUELGAUGE_Percent,     FALSE,
                    FUELGAUGE_Ticks,       FALSE,
                    FUELGAUGE_Justification, FGJ_CENTER,
                    GA_Text,               "0",
                End,
                Label("2048"),
                LAYOUT_AddChild,    OBJ(OBJ_4096) = FuelGaugeObject,
                    GA_ID,          OBJ_4096,
                    FUELGAUGE_Min,         0,
                    FUELGAUGE_Max,         FUELMAX,  // 1000,
                    FUELGAUGE_Percent,     FALSE,
                    FUELGAUGE_Ticks,       FALSE,
                    FUELGAUGE_Justification, FGJ_CENTER,
                    GA_Text,               "0",
                End,
                Label("4096"),
                LAYOUT_AddChild,    OBJ(OBJ_8192) = FuelGaugeObject,
                    GA_ID,          OBJ_8192,
                    FUELGAUGE_Min,         0,
                    FUELGAUGE_Max,         FUELMAX,  // 1000,
                    FUELGAUGE_Percent,     FALSE,
                    FUELGAUGE_Ticks,       FALSE,
                    FUELGAUGE_Justification, FGJ_CENTER,
                    GA_Text,               "0",
                End,
                Label("8192"),
                LAYOUT_AddChild,    OBJ(OBJ_16384) = FuelGaugeObject,
                    GA_ID,          OBJ_16384,
                    FUELGAUGE_Min,         0,
                    FUELGAUGE_Max,         FUELMAX,  // 1000,
                    FUELGAUGE_Percent,     FALSE,
                    FUELGAUGE_Ticks,       FALSE,
                    FUELGAUGE_Justification, FGJ_CENTER,
                    GA_Text,               "0",
                End,
                Label("16384"),
                LAYOUT_AddChild,    OBJ(OBJ_OVER_16384) = FuelGaugeObject,
                    GA_ID,          OBJ_OVER_16384,
                    FUELGAUGE_Min,         0,
                    FUELGAUGE_Max,         FUELMAX,  // 1000,
                    FUELGAUGE_Percent,     FALSE,
                    FUELGAUGE_Ticks,       FALSE,
                    FUELGAUGE_Justification, FGJ_CENTER,
                    GA_Text,               "0",
                End,
                Label(">16384"),
            End,  // VLayout
        End,   // VLayout
    End;  // WindowObject
}


int
main()
{
    BOOL ChooserOK = FALSE;

    idcmphook.h_Entry    = (HOOKFUNC)IDCMPFunc;
    idcmphook.h_SubEntry = NULL;
    idcmphook.h_Data     = NULL;

    ChooserOK = MakeChooserList(&chooserlist);
    if ((AppPort = IExec->AllocSysObjectTags(ASOT_PORT, TAG_END))  && (ChooserOK))
    {
        win = make_window();
        if (( window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN)))
        {
            uint32
                sigmask     = 0,
                siggot      = 0,
                result      = 0;
            uint16
                code        = 0;
            BOOL
                ReqVol      = FALSE,  //  was volume selected from the requester?
                done        = FALSE;

            IIntuition->GetAttr(WINDOW_SigMask, win, &sigmask);
            while (!done)
            {
                siggot = IExec->Wait(sigmask | SIGBREAKF_CTRL_C);
                if (siggot & SIGBREAKF_CTRL_C) done = TRUE;
                while ((result = IIntuition->IDoMethod(win, WM_HANDLEINPUT, &code)) != WMHI_LASTMSG)
                {
                    switch(result & WMHI_CLASSMASK)
                    {
                        case WMHI_CLOSEWINDOW:
                            done = TRUE;
                            break;
                        case WMHI_GADGETUP:
                            switch (result & WMHI_GADGETMASK)
                            {
                                case OBJ_VOL_OTHER:
                                    ReqVol = (ReqVol == 0);  // swap between TRUE and FALSE
                                    break;
                                case OBJ_GETFILE:
                                    if (ReqVol)
                                        {
                                        if (gfRequestFile(OBJ(OBJ_GETFILE), window))
                                            {
                                            ReqSelect = TRUE;
                                            GetBlockSize();   // check out selection
                                            }
                                        }
                                    else
                                        IIntuition->ActivateGadget(GAD(OBJ_HIDDEN_CHOOSER), window, NULL);
                                    break;
                                case OBJ_START:
                                    if (ReadyToStart) Start();
                                    break;
                                case OBJ_RADIO:
                                    radio_num = code;
                                    pickradio();
                                    break;
                            }
                            break;
                        case WMHI_ICONIFY:
                            if (IIntuition->IDoMethod(win, WM_ICONIFY)) window = NULL;
                            break;
                        case WMHI_UNICONIFY:
                            window = (struct Window*)IIntuition->IDoMethod(win, WM_OPEN);
                            break;
                    }
                }
            }
        }
        IIntuition->DisposeObject(win);
    }
    if (AppPort) IExec->FreeSysObject(ASOT_PORT, AppPort);
    if (ChooserOK) FreeChooserList(&chooserlist);

    return RETURN_OK;
}


void CheckForStop()
{
    uint32 result = 0;
    uint16 code   = 0;

    if ((result = IIntuition->IDoMethod(win, WM_HANDLEINPUT, &code)) != WMHI_LASTMSG)
    {
        switch(result & WMHI_CLASSMASK)
        {
            case WMHI_GADGETUP:
            {
                switch (result & WMHI_GADGETMASK)
                {
                    case OBJ_STOP:
                        StopScan = TRUE;
                        break;

                    case OBJ_RADIO:        // Does user want to see other results
                        radio_num = code;  // when the scan is in progress?
                        pickradio();
                        break;
                }
            }
        }
    }
}


void IDCMPFunc(struct Hook *hook,Object *wobj,struct IntuiMessage *Msg)
{
    struct Window *window = Msg->IDCMPWindow;
    uint32 active;

    if (Msg->Class == IDCMP_IDCMPUPDATE)
    {
        if (IUtility->GetTagData(GA_ID, 0, Msg->IAddress) == OBJ_HIDDEN_CHOOSER)
        {
            active = IUtility->GetTagData(CHOOSER_Active, -1, Msg->IAddress);
            IIntuition->SetGadgetAttrs(GAD(OBJ_GETFILE),window,NULL,
                    GETFILE_FullFile, Volumes[active].Name, TAG_END);
            ReqSelect = FALSE;
            GetBlockSize();
        }
    }
}


BOOL MakeChooserList(struct List *list)
{
    struct Node *node;
    int i;

    GetVolumeList();  // get the volume names

    IExec->NewList(list);

    for (i=0; i<NumVolumes; i++)
    {
        node = IChooser->AllocChooserNode(CNA_Text, Volumes[i].Name, TAG_END);
        if(node)
        {
            IExec->AddTail(list, node);
        }
        else
        {
            MessageBox("OK","Failed to create the Chooser List");
            FreeVolumeList();
            return(FALSE);
        }
    }
    return(TRUE);
}


void FreeChooserList(struct List *list)
{
    struct Node *node;

    while(( node = IExec->RemHead(list) ))
    {
        IChooser->FreeChooserNode(node);
    }

    FreeVolumeList();
}


VOID GetVolumeList(void)
{
    struct List *vlist = IDOS->AllocDosObjectTags(DOS_VOLUMELIST, ADO_Type,LDF_VOLUMES, ADO_AddColon,TRUE, TAG_END);
    struct Node *vnode;
    int  i;


    NumVolumes = 0;

    if( vlist )
    {
        for(vnode = IExec->GetHead(vlist); vnode; vnode = IExec->GetSucc(vnode)) 
        {
            NumVolumes ++;
        }

        Volumes = IExec->AllocVecTags((1+NumVolumes) * sizeof(Volume), 
				AVT_Type,MEMF_SHARED, AVT_ClearWithValue,0, AVT_Lock,FALSE, TAG_END );

        for(i=0, vnode = IExec->GetHead(vlist); vnode; vnode = IExec->GetSucc(vnode)) 
        {
            int32 len = 2+ IUtility->Strlen(vnode->ln_Name);

            if(( Volumes[i].Name = IExec->AllocVecTags( len, AVT_Type,MEMF_SHARED, AVT_Lock,FALSE, TAG_END )) )
            {
                IUtility->Strlcpy(Volumes[i].Name, vnode->ln_Name, len);
                i ++;
            }
        }

        IDOS->FreeDosObject(DOS_VOLUMELIST,vlist);
    }
}


void FreeVolumeList(void)
{
    int i;

    if( Volumes )
    {
        for (i=0; i<NumVolumes; i++)
        {
            IExec->FreeVec(Volumes[i].Name);
        }

        IExec->FreeVec(Volumes);
    }
    NumVolumes = 0;
    Volumes    = NULL;
}


void GetBlockSize()
{
    struct  InfoData *infod = NULL;
	struct  ExamineData *exd = NULL;
    BPTR    lock;
	TEXT    blocksizestr[8];
    STRPTR  target = 0;
    BOOL    good = FALSE;

    IIntuition->GetAttrs(OBJ(OBJ_GETFILE),GETFILE_FullFile,&target,TAG_END);

    if (!(lock = IDOS->Lock(target,ACCESS_READ)))
    {
        MessageBox("OK","Failed to get a Lock on: %s", target);
        goto done;
    }

    if (!(infod = IDOS->AllocDosObjectTags(DOS_INFODATA,TAG_END)))
    {
        MessageBox("OK","Failed to allocate an InfoData for: %s", target);
        goto done;
    }

    if (!( exd = IDOS->ExamineObjectTags(EX_LockInput,lock,TAG_END)))
    {
        MessageBox("OK","Failed to Examine: %s", target);
        goto done;
    }

    if ( EXD_IS_DIRECTORY(exd) )            //  macro from dos/dos.h
    {
        if (IDOS->Info(lock,infod))
        {
            NumBlocksUsed = infod->id_NumBlocksUsed;

            IUtility->SNPrintf (blocksizestr, sizeof(blocksizestr), "%lu", infod->id_BytesPerBlock);

            IIntuition->SetGadgetAttrs( GAD(OBJ_BLOCKSIZE), window, NULL,
                                        GA_Text, blocksizestr, TAG_END);
            if (ReqSelect)
            {
                IIntuition->SetGadgetAttrs( GAD(OBJ_FUEL_DONE), window, NULL,
                    FUELGAUGE_Percent,  FALSE,
                    FUELGAUGE_Level,    0,
                    GA_Text,            "0",  TAG_END);
            }
            else
            {
                IIntuition->SetGadgetAttrs( GAD(OBJ_FUEL_DONE), window, NULL,
                    GA_Text,            "",
                    FUELGAUGE_Percent,  TRUE,
                    FUELGAUGE_Max,      NumBlocksUsed,
                    FUELGAUGE_Level,    0, TAG_END);
            }
            ClearResults();
            ReadyToStart = TRUE;
        }
        else
        {
            MessageBox("OK","Failed to fill in the InfoData for: %s", target);
            goto done;
        }
     }
     else
     {
         MessageBox("OK","It appears that %s is not a volume or directory",target);
         goto done;
     }
     good = TRUE;

done:
    IDOS->FreeDosObject(DOS_INFODATA,infod);
    IDOS->FreeDosObject(DOS_EXAMINEDATA,exd);
    IDOS->UnLock(lock);
    if (! good) ClearTargetStrings();
}


void ClearTargetStrings()
{
    IIntuition->SetGadgetAttrs(GAD(OBJ_GETFILE),window,NULL,GETFILE_FullFile,"",TAG_END);
    IIntuition->SetGadgetAttrs(GAD(OBJ_BLOCKSIZE),window,NULL,GA_Text,"",TAG_END);
    IIntuition->SetGadgetAttrs(GAD(OBJ_FUEL_DONE),window,NULL,FUELGAUGE_Level,0,TAG_END);
    ClearResults();
    ReadyToStart = FALSE;
}


void ClearResults()
{
    int i;

    for (i=OBJ_512; i<=OBJ_OVER_16384; i++)
    {
        IIntuition->SetGadgetAttrs(GAD(i),window,NULL,
        FUELGAUGE_Level, 0,
        FUELGAUGE_Max,   FUELMAX,
        GA_Text,  "0",  TAG_END);
    }
}


void Start(void)
{
    struct InfoData *infod = NULL;
    STRPTR target;
    char textstr[1000];  //  for long path names in req mode
    BPTR lock;


    ReadyToStart = FALSE;     //  Clear the decks for action
    BlocksDone = 0;
    fg_Max = FUELMAX;

    if (StopScan)
    {
        ClearResults();       // reset FUELGAUGE_Max to FUELMAX in case fg_Max
        StopScan = FALSE;     // was greater than FUELMAX when user clicked stop
    }

    IUtility->ClearMem( filesizes, sizeof(filesizes));
    IUtility->ClearMem( filesizesblocks, sizeof(filesizesblocks));

    IIntuition->GetAttrs(OBJ(OBJ_GETFILE),GETFILE_FullFile,&target,TAG_END);

    if ((lock = IDOS->Lock(target,ACCESS_READ)) )
    {
        BPTR oldcd = IDOS->SetCurrentDir(lock);

        if ((infod = IDOS->AllocDosObjectTags(DOS_INFODATA,TAG_END)))
        {
            IDOS->Info(lock,infod);
        }

        RecursiveScan(target,infod);         //  Decks cleared, so Go

        //  **************** fill the gauge when finished ***************
        //  The difference between id_NumBlocksUsed and the number of blocks
        //  counted is usually about 1%, so here the progress fuelgauge gets
        //  filled to 100% to inform the user that the scan has finished.

        IUtility->SNPrintf (textstr, sizeof(textstr), "%lu Blocks have been used on %s",BlocksDone,target);
        UpdateProgressBar(NumBlocksUsed, textstr);      // fill to 100%

        IDOS->SetCurrentDir(oldcd);
        IDOS->UnLock(lock);
        IDOS->FreeDosObject(DOS_INFODATA,infod);
    }

    ReadyToStart = TRUE;
    return;
}


void RecursiveScan(STRPTR target, struct InfoData *infod)
{
    APTR   ctx;
    struct ExamineData *exd;
    char   textstr[20];
    uint32 numblocks, cnt =0;


    ctx = IDOS->ObtainDirContextTags(EX_StringNameInput,target,
                                     EX_DoCurrentDir,TRUE,
                                     EX_DataFields, (EXF_TYPE | EXF_NAME | EXF_SIZE),
                                     TAG_END);

    while( (exd = IDOS->ExamineDir(ctx)) ) 
    {
        if( StopScan )
        {
            break;
        }

        cnt ++;						//count objects.
        numblocks = 1;				//directories and links get 1 block.

        if EXD_IS_FILE(exd)         //  macro from dos/dos.h
        {
            numblocks = exd->FileSize / infod->id_BytesPerBlock;
 
            if (exd->FileSize <512)
            {
                filesizes[0]++;
                filesizesblocks[0] += numblocks;
            }
            else if (exd->FileSize <1024)
            {
                filesizes[1]++;
                filesizesblocks[1] += numblocks;
            }
            else if (exd->FileSize <2048)
            {
                filesizes[2]++;
                filesizesblocks[2] += numblocks;
            }
            else if (exd->FileSize <4096)
            {
                filesizes[3]++;
                filesizesblocks[3] += numblocks;
            }
            else if (exd->FileSize <8192)
            {
                filesizes[4]++;
                filesizesblocks[4] += numblocks;
            }
            else if (exd->FileSize <16384)
            {
                filesizes[5]++;
                filesizesblocks[5] += numblocks;
            }
            else
            {
                filesizes[6]++;
                filesizesblocks[6] += numblocks;
            }
     
            BlocksDone += numblocks;
        }
        else if EXD_IS_DIRECTORY(exd)           //  macro from dos/dos.h
        {
            BlocksDone += numblocks;
            filesizesblocks[7] += numblocks;

            RecursiveScan(exd->Name,infod);		//recurse.
        }

        if ( ! StopScan )     /* if stop button has not been pressed, update results sparingly. */
        {
            if( cnt > 100  )		/* only update GUI every 100th object count */
            {
				cnt = 0;
                CheckForStop();

                IUtility->SNPrintf (textstr, sizeof(textstr), "%lu", BlocksDone);
                UpdateProgressBar(BlocksDone,textstr);
                /* ShowResults();   -- only do it on leaving the directory */
            }
        }
    }

    if (( ! StopScan ) && ( ERROR_NO_MORE_ENTRIES != IDOS->IoErr() ))
    {
        MessageBox("OK","Directory scan failed error #%ld, %s", IDOS->IoErr(), target);
        StopScan = TRUE;
    }


    /*
    **  Update GUI results on leaving each directory, check for stop again also.
    */
    IUtility->SNPrintf (textstr, sizeof(textstr), "%lu", BlocksDone);
    UpdateProgressBar(BlocksDone,textstr);
    ShowResults();

    CheckForStop();

    IDOS->ReleaseDirContext(ctx);
    return;
}


void UpdateProgressBar(int32 level, STRPTR levelstr)
{
    if (ReqSelect)         // Volume was selected from requester
    {
        IIntuition->SetGadgetAttrs( GAD(OBJ_FUEL_DONE), window, NULL,
                            GA_Text, levelstr, TAG_END);
    }
    else            // Volume was selected from DOS List
    {
        IIntuition->SetGadgetAttrs( GAD(OBJ_FUEL_DONE), window, NULL,
                            FUELGAUGE_Level, level, TAG_END);
    }
}


void ShowResults(void)
{
    int i, max;

    for (i=OBJ_512; i<=OBJ_OVER_16384; i++)
    {
        if  (filesizes[i] > fg_Max)
        {
            fg_Max = fg_Max*2;     // extend the range so results fit in.

            for (max=OBJ_512; max<=OBJ_OVER_16384; max++)
            {
                IIntuition->SetGadgetAttrs( GAD(max), window, NULL,
                                FUELGAUGE_Max, fg_Max, TAG_END);
            }
        }
    }
    pickradio();
}


void pickradio()           // Radio buttons can be selected while scan
{                          // is running, to show other results.
    char textstr[20];
    int i;

    switch (radio_num)
    {
        case RADIO_1:
            for (i=OBJ_512; i<=OBJ_OVER_16384; i++)
            {
                IUtility->SNPrintf (textstr, sizeof(textstr), "%lu", filesizes[i]);
                IIntuition->SetGadgetAttrs( GAD(i), window, NULL,
                    FUELGAUGE_Percent,  FALSE,
                    FUELGAUGE_Max,      fg_Max,
                    FUELGAUGE_Level,    filesizes[i],
                    GA_Text,            textstr,
                    TAG_END);
            }
            break;
        case RADIO_2:

            //  Missing 4% to 5%  is used by directories,
            //  filesizes[7], maybe show dirs % in the
            //  progress bar when finished?
            //
            //  Perhaps using floats would be better as
            //  any result below 1% shows 0% as opposed
            //  to something like 0.35%

            for (i=OBJ_512; i<=OBJ_OVER_16384; i++)
            {
                IIntuition->SetGadgetAttrs( GAD(i), window, NULL,
                    FUELGAUGE_Percent,  TRUE,
                    FUELGAUGE_Max,      100,
                    FUELGAUGE_Level,    (filesizesblocks[i] * 100) / BlocksDone,
                    GA_Text,            "",
                    TAG_END);
            }
            break;
        case RADIO_3:
            break;
        case RADIO_4:
            break;
        case RADIO_5:
            break;
        case RADIO_6:
            break;
    }
}


uint32 VARARGS68K MessageBox(char *gadgets, char *format, ...)
{
    va_list  ap;
    int32    result = 0;

    va_startlinear (ap, format);

    Object *requester = IIntuition->NewObject(IRequester->REQUESTER_GetClass(), NULL,
            REQ_Type,               REQTYPE_INFO,
            REQ_TitleText,          "BlockSize Message",
            REQ_BodyText,           format,
            REQ_GadgetText,         gadgets,
            REQ_VarArgs,            va_getlinearva(ap, APTR),
    TAG_END);

    if (requester)
    {
        result = IIntuition->IDoMethod( requester, RM_OPENREQ, NULL, NULL, NULL );
        IIntuition->DisposeObject(requester);
    }

    va_end(ap);
    return result;
}
