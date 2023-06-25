/*
 * stress_dma_test.c
 *
 * Copyright 2021 Trevor Dickinson. All rights reserved.
 *
 * This file is part of ExecSG.
 * Licensed under the ExecSG license.
 * See the LICENSING file for details.
 *
 * :ts=4
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <exec/exec.h>
#include <exec/types.h>
#include <devices/timer.h>
#include <proto/exec.h>
#include <proto/timer.h>
#include <exec/memory.h>
#include <interfaces/exec.h>
#include <dos/dos.h>
#include <proto/utility.h>

#include <resources/fsldma.h>
#include <interfaces/fsldma.h>

// Timer Object structure
//  for use with fsldma_OpenTimerDevice()
//  and fsldma_CloseTimerDevice()
struct TimerObject
{
    struct MsgPort     *pTimerMsgPort;
    struct TimeRequest *pTimerIOReq;
    struct Library     *pTimerBase;
    struct TimerIFace  *pITimer;
    struct TimeVal     oTimeValStart; // TimeVal structure for storing the start time of the transfer
    struct TimeVal     oTimeValEnd;   // TimeVal structure for storing the end time of the transfer
};

#define SIZE_1_BYTE    (uint32)1

#define SIZE_2_BYTES   (uint32)(2 * SIZE_1_BYTE)
#define SIZE_4_BYTES   (uint32)(4 * SIZE_1_BYTE)
#define SIZE_8_BYTES   (uint32)(8 * SIZE_1_BYTE)
#define SIZE_16_BYTES  (uint32)(16 * SIZE_1_BYTE)

#define SIZE_32_BYTES  (uint32)(32 * SIZE_1_BYTE)
#define SIZE_64_BYTES  (uint32)(64 * SIZE_1_BYTE)
#define SIZE_128_BYTES (uint32)(128 * SIZE_1_BYTE)
#define SIZE_256_BYTES (uint32)(256 * SIZE_1_BYTE)

#define SIZE_384_BYTES (uint32)(384 * SIZE_1_BYTE)
#define SIZE_512_BYTES (uint32)(512 * SIZE_1_BYTE)
#define SIZE_640_BYTES (uint32)(640 * SIZE_1_BYTE)
#define SIZE_768_BYTES (uint32)(768 * SIZE_1_BYTE)

#define SIZE_1_KB   (uint32)1024
#define SIZE_2_KB   (uint32)(2 * SIZE_1_KB)
#define SIZE_4_KB   (uint32)(4 * SIZE_1_KB)
#define SIZE_8_KB   (uint32)(8 * SIZE_1_KB)

#define SIZE_16_KB  (uint32)(16 * SIZE_1_KB)
#define SIZE_20_KB  (uint32)(20 * SIZE_1_KB)
#define SIZE_24_KB  (uint32)(24 * SIZE_1_KB)
#define SIZE_32_KB  (uint32)(32 * SIZE_1_KB)
#define SIZE_36_KB  (uint32)(36 * SIZE_1_KB)
#define SIZE_40_KB  (uint32)(40 * SIZE_1_KB)
#define SIZE_42_KB  (uint32)(42 * SIZE_1_KB)
#define SIZE_46_KB  (uint32)(46 * SIZE_1_KB)
#define SIZE_50_KB  (uint32)(50 * SIZE_1_KB)
#define SIZE_52_KB  (uint32)(52 * SIZE_1_KB)
#define SIZE_56_KB  (uint32)(56 * SIZE_1_KB)
#define SIZE_60_KB  (uint32)(60 * SIZE_1_KB)
#define SIZE_64_KB  (uint32)(64 * SIZE_1_KB)
#define SIZE_128_KB (uint32)(128 * SIZE_1_KB)

#define SIZE_256_KB (uint32)(256 * SIZE_1_KB)
#define SIZE_384_KB (uint32)(384 * SIZE_1_KB)
#define SIZE_512_KB (uint32)(512 * SIZE_1_KB)
#define SIZE_640_KB (uint32)(640 * SIZE_1_KB)

#define SIZE_768_KB (uint32)(768 * SIZE_1_KB)
#define SIZE_832_KB (uint32)(832 * SIZE_1_KB)
#define SIZE_896_KB (uint32)(896 * SIZE_1_KB)
#define SIZE_960_KB (uint32)(960 * SIZE_1_KB)

#define SIZE_1_MB   (uint32)(1024 * SIZE_1_KB)
#define SIZE_2_MB   (uint32)(2 * SIZE_1_MB)
#define SIZE_3_MB   (uint32)(3 * SIZE_1_MB)
#define SIZE_4_MB   (uint32)(4 * SIZE_1_MB)

#define SIZE_5_MB   (uint32)(5 * SIZE_1_MB)
#define SIZE_6_MB   (uint32)(6 * SIZE_1_MB)
#define SIZE_7_MB   (uint32)(7 * SIZE_1_MB)
#define SIZE_8_MB   (uint32)(8 * SIZE_1_MB)

#define SIZE_9_MB   (uint32)(9 * SIZE_1_MB)
#define SIZE_10_MB  (uint32)(10 * SIZE_1_MB)
#define SIZE_11_MB  (uint32)(11 * SIZE_1_MB)
#define SIZE_12_MB  (uint32)(12 * SIZE_1_MB)

#define SIZE_13_MB  (uint32)(13 * SIZE_1_MB)
#define SIZE_14_MB  (uint32)(14 * SIZE_1_MB)
#define SIZE_15_MB  (uint32)(15 * SIZE_1_MB)
#define SIZE_16_MB  (uint32)(16 * SIZE_1_MB)

#define SIZE_24_MB  (uint32)(24 * SIZE_1_MB)
#define SIZE_32_MB  (uint32)(32 * SIZE_1_MB)
#define SIZE_64_MB  (uint32)(64 * SIZE_1_MB)
#define SIZE_128_MB (uint32)(128 * SIZE_1_MB)

#define SIZE_256_MB (uint32)(256 * SIZE_1_MB)
#define SIZE_384_MB (uint32)(384 * SIZE_1_MB)
#define SIZE_512_MB (uint32)(512 * SIZE_1_MB)
#define SIZE_640_MB (uint32)(640 * SIZE_1_MB)

#define SIZE_768_MB (uint32)(768 * SIZE_1_MB)
#define SIZE_896_MB (uint32)(896 * SIZE_1_MB)
#define SIZE_960_MB (uint32)(960 * SIZE_1_MB)
#define SIZE_1_GB   (uint32)(1024 * SIZE_1_MB)

#define SIZE_ETH_PACKET (uint32)1536 // Standard Ethernet frame rounded up to be a multiple of 64 Bit (8 Bytes)

// Define a structure to hold the shared DMA Transaction data for each thread
typedef struct dma_trans_data
{
  APTR                mxTransactionLock;
  struct Task        *pSignalTask;
  struct Hook        *pNotifyHook;
  uint32              lNotifyHookFlags;
  uint32              lTransactionId;
  uint32              lTransferLength;
  uint32              lThreadNumber;
  CONST_APTR          pSourceBuffer;
  APTR                pDestBuffer;
  CONST_APTR          pPhysicalSrcBuffer;
  APTR                pPhysicalDstBuffer;
  struct TimerObject *pTimerObj;          // Reference Timer object (shared - do not free)
  struct TimeVal      oTimeValStart;      // TimeVal structure for storing the start time of the transfer
  struct TimeVal      oTimeValEnd;        // TimeVal structure for storing the end time of the transfer
  uint32              lTimeOutCounter;
  BOOL                bReceivedCompleted;
  BOOL                bReceivedInProgress;
  BOOL                bReceivedError;
  BOOL                bAlreadyReported;
  BOOL                bVerified;
} DMA_TRANSDATA;

struct TimerObject * fsldma_OpenTimerDevice( enum enTimerUnits nTimerUnit );
void fsldma_CloseTimerDevice( struct TimerObject *pTimerObj );
void fsldma_Parallel_Test( struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint8 nNumberThreads, uint32 lNumberOfRuns, BOOL bWithVerify );
BOOL verifyIdentical( CONST_APTR pBuffer1, APTR pBuffer2, uint32 lTestSize, BOOL bAlterAfterVerify );

// Global pointer to ourselves (this Task)
struct Task *pGLThisTask = NULL;

int main(int argc, char *argv[])
{
  struct ExecBase     *ExecBase    = (*(struct ExecBase **)4);
  struct ExecIFace    *IExec       = (struct ExecIFace *)ExecBase->MainInterface;

  //printf("argc = %ld, argv = %p\n",(uint32)argc,argv);
  //for( int c = 0; c < argc; c++ )
  //{
  //  printf("argc[%ld] = %s\n",(uint32)c,argv[c]);
  //}

  // Set the number of test runs
  uint32 lNumberOfTestRuns = 10; // Default to 10
  if ( argc >= 2 )
  {
    // If the first positional argument does not start with
    // a '-' then attempt to read it as the "Number of test runs"
    char *sPossibleDash = argv[1];
    if ( '-' != sPossibleDash[0] )
    {
      // Convert the first argument to a number value
      // (for Number of Test Runs)
      lNumberOfTestRuns = (uint32)atol(argv[1]);
    }
  }

  // Set the number of threads
  uint8 nNumberOfThreads = 8; // Default to 8 (One for each DMA Channel)
  if ( argc >= 3 )
  {
    // If the second positional argument does not start with
    // a '-' then attempt to read it as the "Number of threads"
    char *sPossibleDash = argv[2];
    if ( '-' != sPossibleDash[0] )
    {
      // Convert the first argument to a number value
      // (for Number of Threads)
      nNumberOfThreads = (uint8)atoi(argv[2]);
    }
  }

  // Set Verify Flag
  BOOL bVerifyTest = FALSE;
  // Scan args for 'enable verify' flag
  for( int c = 0; c < argc; c++ )
  {
    char *sVerifyArg = argv[c];
    if ( strlen(sVerifyArg) >= 2 )
    {
      if ( ('-' == sVerifyArg[0]) && ('v' == sVerifyArg[1]) )
      {
        bVerifyTest = TRUE;
        break;
      }
    }
  }

  printf("Command line args passed in:\nNumber of Test Runs = %lu\nNumber of Threads = %lu\nVerify Mode is %s\n",
         lNumberOfTestRuns,(uint32)nNumberOfThreads,(TRUE == bVerifyTest) ? "Enabled" : "Disabled");

  // Obtain the Global pointer to ourselves (this Task)
  pGLThisTask = IExec->FindTask(NULL);

  // Obtain the fsldma.resource
  struct fslDMAIFace *IfslDMA = IExec->OpenResource(FSLDMA_NAME);
  if ( NULL != IfslDMA )
  {
    // Verify we are running the required kernel
    struct Library *execLibNode = &ExecBase->LibNode;
    if ( !LIB_IS_AT_LEAST(execLibNode,54,41) )
    {
      // We are not running the minimum needed kernel version. Abort.
      printf("This program requires kernel version 54.41 or newer. Aborted test.\n");
      return( 1 );
    }

    // Timer object structure populated by fsldma_OpenTimerDevice()
    struct TimerObject *pTimerObj = NULL;

    pTimerObj = fsldma_OpenTimerDevice(UNIT_MICROHZ);
    if ( NULL != pTimerObj )
    {
      //
      // Parallel execution test (Multiple runs)
      //
      printf("\nfsldma.resource Test: Parallel execution:\n");
      printf("Using IfslDMA->CopyMemDMATags() with \"non-blocking\" mode,\n");
      printf("user Notification signals...\n");

      fsldma_Parallel_Test(IfslDMA,pTimerObj,nNumberOfThreads,lNumberOfTestRuns,bVerifyTest);

      // Close and free the timer device
      fsldma_CloseTimerDevice(pTimerObj);

      printf("\nfsldma.resource Tests complete.\n");
    }
  }
  return( 0 );
}

//
// Test Parallel Execution test
//
void fsldma_Parallel_Test(struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint8 nNumberThreads, uint32 lNumberOfRuns, BOOL bWithVerify)
{
  // Make sure we have good parameters to work with
  if ( (NULL == IfslDMA) || (NULL == pTimerObj) ) return;

  // Preprogram a full set of (randomly order) sizes
  // to be used for the tests. The total of all of
  // these sizes should not exceed 512 Megabytes,
  // since we need two buffers of each size and do
  // not want to use more than 1 Gigabyte of RAM
  // for this test (as all buffers may exist at once).
  //
  // Only the first "nNumberThreads" entries are used.
  // Other possible sizes are listed here:
  uint32 lTestSizes[64] =
  {
    SIZE_64_KB,     SIZE_128_KB,    SIZE_256_KB,    SIZE_384_KB,
    SIZE_16_BYTES,  SIZE_32_BYTES,  SIZE_64_BYTES,  SIZE_128_BYTES,
    SIZE_256_MB,    SIZE_2_MB,      SIZE_3_MB,      SIZE_4_MB,
    SIZE_1_BYTE,    SIZE_2_BYTES,   SIZE_4_BYTES,   SIZE_8_BYTES,
    SIZE_256_KB,    SIZE_384_BYTES, SIZE_512_BYTES, SIZE_640_BYTES,
    SIZE_768_BYTES, SIZE_1_KB,      SIZE_2_KB,      SIZE_4_KB,
    SIZE_8_KB,      SIZE_16_KB,     SIZE_20_KB,     SIZE_24_KB,
    SIZE_32_KB,     SIZE_36_KB,     SIZE_40_KB,     SIZE_42_KB,
    SIZE_10_MB,     SIZE_32_KB,     SIZE_12_MB,     SIZE_512_KB,
    SIZE_46_KB,     SIZE_50_KB,     SIZE_52_KB,     SIZE_56_KB,
    SIZE_60_KB,     SIZE_512_KB,    SIZE_640_KB,    SIZE_768_KB,
    SIZE_832_KB,    SIZE_896_KB,    SIZE_960_KB,    SIZE_1_MB,
    SIZE_32_MB,     SIZE_64_MB,     SIZE_64_BYTES,  SIZE_ETH_PACKET,
    SIZE_6_MB,      SIZE_7_MB,      SIZE_8_MB,      SIZE_384_KB,
    SIZE_14_MB,     SIZE_64_KB,     SIZE_16_MB,     SIZE_32_BYTES,
    SIZE_128_KB,    SIZE_8_MB,      SIZE_5_MB,      FSLDMA_OPTIMAL_BLKSIZE
  };
  uint32 lNumTestSizeEntries = ((uint32)sizeof(lTestSizes) / sizeof(uint32));
  uint32 lDefaultSizeIndex   = (lNumTestSizeEntries - 1);
  printf("lTestSizes[] has %lu entries\n",lNumTestSizeEntries);
  uint32 lTotalTestSizes = 0;
  for( uint32 s = 0; s < lNumTestSizeEntries; s++ )
  {
    //printf("lTestSizes[%ld] = %lu\n",s,lTestSizes[s]);
    lTotalTestSizes += lTestSizes[s];
  }
  printf("lTotalTestSizes = [%lu] x 2 buffers = [%lu]\n",lTotalTestSizes,lTotalTestSizes * 2);

  // If the number of threads is passed in as zero(0), then set it to default at 8
  if ( 0 == nNumberThreads ) nNumberThreads = 8;
  // If the number of threads exceeds the number of Test Size entries
  // then set it to the number of test size entries (max)
  if ( nNumberThreads > lNumTestSizeEntries ) nNumberThreads = lNumTestSizeEntries;

  // Setup an array of data structures to use for testing
  struct dma_trans_data *pDMATransData[nNumberThreads];

  // Clear all data pointers
  for( int i = 0; i < nNumberThreads; i++ )
  {
    pDMATransData[i] = 0;
  }

  // Counters for total verified and failed verified
  uint32 lTotalTransactionsVerified = 0;
  uint32 lTotalFailedToMatch        = 0;

  // "Total Time" structure
  struct TimeVal oTotalTaskTime;
  oTotalTaskTime.Seconds      = 0;
  oTotalTaskTime.Microseconds = 0;

  // Obtain the MMU Interface
  struct ExecBase *ExecBase = (*(struct ExecBase **)4);
  struct MMUIFace *IMMU = (struct MMUIFace *)IExec->GetInterface((struct Library *)ExecBase,"MMU",1,NULL);
  if ( NULL != IMMU )
  {
    //
    // Allocate all the memory buffers and signals we need for the test
    //
    BOOL   bGotResources = TRUE;
    uint32 lRandomSizeIndex = 0;

    printf("Allocating buffers and signals for the test...\n");
    for( int i = 0; i < nNumberThreads; i++ )
    {
      // Allocate a DMA Transaction Data structure for this thread
      pDMATransData[i] = IExec->AllocVecTags(sizeof(struct dma_trans_data),
                                              AVT_Type,           MEMF_SHARED, // Memory is available to All Address spaces
                                              AVT_ClearWithValue, 0,           // Clear data before returning it
                                              TAG_END);
      if ( NULL != pDMATransData[i] )
      {
        // Allocate a Mutex Object for this thread
        pDMATransData[i]->mxTransactionLock = IExec->AllocSysObjectTags(ASOT_MUTEX,ASOMUTEX_Recursive,FALSE,TAG_DONE);

        // Set the Task to be Signaled to This Task
        pDMATransData[i]->pSignalTask = pGLThisTask;

        // Allocate a Notify Hook Object for this thread
        pDMATransData[i]->pNotifyHook = (struct Hook *)IExec->AllocSysObjectTags(ASOT_HOOK,
                                                                  ASOHOOK_Entry, notifyHookFunction,       // Pointer to the notifyHookFunction()
                                                                  ASOHOOK_Data,  (uint32)pDMATransData[i], // Pointer to the DMA Transaction Data structure
                                                                  TAG_DONE);
        // Set Notify Flags for this thread
        //pDMATransData[i]->lNotifyHookFlags = FSLDMA_NF_ALL;    // Request "Complete", "In Progress" and "Error" notifications
        pDMATransData[i]->lNotifyHookFlags = FSLDMA_NF_COMMON; // Request "Complete" and "Error" notifications only

        // Clear the DMA Transaction Id
        pDMATransData[i]->lTransactionId = 0;

        // Set a 'random' DMA transfer length
        // Use an entry from the test sizes table
        printf("Using Random Size Index of [%ld] for [%lu] in Length\n",(uint32)lRandomSizeIndex,(uint32)lTestSizes[lRandomSizeIndex]);
        pDMATransData[i]->lTransferLength = (uint32)lTestSizes[lRandomSizeIndex];
        // Increment the Test Size Index for the next run
        lRandomSizeIndex++;
        if ( lRandomSizeIndex >= lNumTestSizeEntries ) lRandomSizeIndex = 0;

        // Set the Thread number to this thread
        pDMATransData[i]->lThreadNumber = (uint32)i;

        // Allocate the buffers we need for this thread
        printf("Allocating source buffer of [%lu] in length...\n",pDMATransData[i]->lTransferLength);
        pDMATransData[i]->pSourceBuffer = IExec->AllocVecTags(pDMATransData[i]->lTransferLength,
                                                              AVT_Type,              MEMF_SHARED, // Memory is available to All Address spaces
                                                              AVT_Contiguous,        TRUE,        // Memory must be a contiguous block, not a scatter/gather table
                                                              AVT_Lock,              TRUE,        // Memory must not be swapped out or otherwise be made unavailable
                                                              AVT_Alignment,         64,          // Memory must be Aligned to a 64 Byte boundary
                                                              AVT_PhysicalAlignment, 64,          // Physical Memory must be Aligned to a 64 Byte boundary
                                                              AVT_ClearWithValue,    (0xB3 + i),  // Fill data with a value before returning it
                                                              TAG_END);

        printf("Allocating destination buffer of [%lu] in length...\n",pDMATransData[i]->lTransferLength);
        pDMATransData[i]->pDestBuffer = IExec->AllocVecTags(pDMATransData[i]->lTransferLength,
                                                            AVT_Type,              MEMF_SHARED, // Memory is available to All Address spaces
                                                            AVT_Contiguous,        TRUE,        // Memory must be a contiguous block, not a scatter/gather table
                                                            AVT_Lock,              TRUE,        // Memory must not be swapped out or otherwise be made unavailable
                                                            AVT_Alignment,         64,          // Memory must be Aligned to a 64 Byte boundary
                                                            AVT_PhysicalAlignment, 64,          // Physical Memory must be Aligned to a 64 Byte boundary
                                                            AVT_ClearWithValue,    0,           // Fill data with a value before returning it
                                                            TAG_END);

        //  Obtain the Physical Addresses of the Source and Destination buffer for this thread
        if ( (NULL != pDMATransData[i]->pSourceBuffer) & (NULL != pDMATransData[i]->pDestBuffer) )
        {
          // Enter Supervisor Mode
          APTR pUserStack = IExec->SuperState();

          // Flush out any cache for our two buffers
          //IExec->CacheClearE((APTR)pDMATransData[i]->pSourceBuffer,pDMATransData[i]->lTransferLength,CACRF_ClearD);
          //IExec->CacheClearE(pDMATransData[i]->pDestBuffer,pDMATransData[i]->lTransferLength,CACRF_ClearD);

          // Now set the memory attributes to prevent further cache operations
          uint32 lSrcMemAttrs = IMMU->GetMemoryAttrs((APTR)pDMATransData[i]->pSourceBuffer,0);
          uint32 lDstMemAttrs = IMMU->GetMemoryAttrs(pDMATransData[i]->pDestBuffer,0);
          IMMU->SetMemoryAttrs((APTR)pDMATransData[i]->pSourceBuffer,pDMATransData[i]->lTransferLength,(lSrcMemAttrs | FSLDMA_PHYMEM_ATTRS));
          IMMU->SetMemoryAttrs(pDMATransData[i]->pDestBuffer,pDMATransData[i]->lTransferLength,(lDstMemAttrs | FSLDMA_PHYMEM_ATTRS));

          // Get the Physical addresses for our two buffers
          pDMATransData[i]->pPhysicalSrcBuffer = IMMU->GetPhysicalAddress((APTR)pDMATransData[i]->pSourceBuffer);
          pDMATransData[i]->pPhysicalDstBuffer = IMMU->GetPhysicalAddress(pDMATransData[i]->pDestBuffer);

          // Return to User Mode
          if ( NULL != pUserStack ) IExec->UserState(pUserStack);
        }

        // Store the pointer to the "global" timer device
        pDMATransData[i]->pTimerObj = pTimerObj;

        // Reset the timer values for this thread
        pDMATransData[i]->oTimeValStart.Seconds      = 0;
        pDMATransData[i]->oTimeValStart.Microseconds = 0;
        pDMATransData[i]->oTimeValEnd.Seconds        = 0;
        pDMATransData[i]->oTimeValEnd.Microseconds   = 0;

        // Clear the TimeOut counter
        pDMATransData[i]->lTimeOutCounter            = 0;

        // Clear the remaining flags
        pDMATransData[i]->bReceivedCompleted  = FALSE;
        pDMATransData[i]->bReceivedInProgress = FALSE;
        pDMATransData[i]->bReceivedError      = FALSE;
        pDMATransData[i]->bAlreadyReported    = FALSE;
        pDMATransData[i]->bVerified           = FALSE;
      }

      // Finally verify we got all the resources we needed or this thread
      if ( NULL == pDMATransData[i]->mxTransactionLock  ) bGotResources = FALSE;
      if ( NULL == pDMATransData[i]->pSignalTask        ) bGotResources = FALSE;
      if ( NULL == pDMATransData[i]->pNotifyHook        ) bGotResources = FALSE;
      if ( NULL == pDMATransData[i]->pSourceBuffer      ) bGotResources = FALSE;
      if ( NULL == pDMATransData[i]->pDestBuffer        ) bGotResources = FALSE;
      if ( NULL == pDMATransData[i]->pPhysicalSrcBuffer ) bGotResources = FALSE;
      if ( NULL == pDMATransData[i]->pPhysicalDstBuffer ) bGotResources = FALSE;

      if ( FALSE == bGotResources )
      {
        // We failed to obtain something, so stop here
        printf("Unable to allocate all the resources needed for this test.\n");
        break;
      }
    }

    if ( (NULL != pGLThisTask) && (TRUE == bGotResources) )
    {
      // Ready for the parallel execution test
      BOOL bAbort = FALSE;

      // Clear counters
      uint32 lNumStarted   = 0;
      uint32 lNumRetried   = 0;
      uint32 lNumCompleted = 0;
      uint32 lNumFailed    = 0;
      uint32 lNumTimedOut  = 0;
      
      // Capture DMA Result Code
      uint32 lDMAResultCode = FSLDMA_RC_UNKNOWN; // Set the "Unknown" to start

      // Reset and start the timer
      pTimerObj->oTimeValStart.Seconds      = 0;
      pTimerObj->oTimeValStart.Microseconds = 0;
      pTimerObj->oTimeValEnd.Seconds        = 0;
      pTimerObj->oTimeValEnd.Microseconds   = 0;
      // Pull the current time (Start the timer for the test runs)
      pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValStart);

      // Setup multiple runs of the parallel execution test
      for( int r = 0; r < lNumberOfRuns; r++ )
      {
        // First call the fsldma.resource's CopyMemDMATags() function
        // once for every "thread" and start a DMA transaction on a
        // different set of memory buffers.
        for( int i = 0; i < nNumberThreads; i++ )
        {
          // We call CopyMemDMATags() passing in the
          // normal source, destination and size values
          // (using a different set each call).
          //
          // We also ask the fsldma.resource not to wait,
          // but return immediately and then send the
          // designated signals to our task when the
          // transaction is completed.
          lNumStarted++;
          printf("Starting DMA Transaction %ld of %lu bytes from 0x%08lx to 0x%08lx...\n",i,pDMATransData[i]->lTransferLength,pDMATransData[i]->pPhysicalSrcBuffer,pDMATransData[i]->pPhysicalDstBuffer);
          // Clear and start the timer values for this thread
          pDMATransData[i]->oTimeValStart.Seconds      = 0;
          pDMATransData[i]->oTimeValStart.Microseconds = 0;
          pDMATransData[i]->oTimeValEnd.Seconds        = 0;
          pDMATransData[i]->oTimeValEnd.Microseconds   = 0;
          // Pull the current time (Start the timer for the test runs)
          pTimerObj->pITimer->GetSysTime(&pDMATransData[i]->oTimeValStart);
          // Call the DMA Resource function
          do
          {
            // Reset the DMA Result code
            lDMAResultCode = FSLDMA_RC_UNKNOWN;
            if ( FALSE == IfslDMA->CopyMemDMATags(pDMATransData[i]->pPhysicalSrcBuffer,pDMATransData[i]->pPhysicalDstBuffer,pDMATransData[i]->lTransferLength,
                                                  FSLDMA_CM_SourceIsPhysical,          TRUE,
                                                  FSLDMA_CM_DestinationIsPhysical,     TRUE,
                                                  FSLDMA_CM_DoNotWait,                 TRUE,
                                                  FSLDMA_CM_NotifyHook,                pDMATransData[i]->pNotifyHook,
                                                  FSLDMA_CM_NotifyHookFlags,           pDMATransData[i]->lNotifyHookFlags,
                                                  FSLDMA_CM_ResultCode,                (uint32)&lDMAResultCode,
                                                  TAG_DONE) )
            {
              // The DMA transaction failed to start, if a
              // problem *other* than the DMA channels being
              // BUSY, then report the failure and stop here.
              if ( FSLDMA_RC_BUSY != lDMAResultCode )
              {
                // A problem occurred starting the DMA transaction
                printf("The DMA Transaction %ld of %lu bytes from 0x%08lx to 0x%08lx failed to start! A DMA Result Code of [0x%08lx] was returned.\n",i,pDMATransData[i]->lTransferLength,pDMATransData[i]->pPhysicalSrcBuffer,pDMATransData[i]->pPhysicalDstBuffer,lDMAResultCode);
                bAbort = TRUE;
                break;
              }
              else
              {
                // If this is just a case of all DMA Channels
                // being busy, then increment the Retry counter
                // and retry the transaction
                printf("The DMA Transaction %ld of %lu bytes from 0x%08lx to 0x%08lx was returned with all DMA Channel busy, retrying...\n",i,pDMATransData[i]->lTransferLength,pDMATransData[i]->pPhysicalSrcBuffer,pDMATransData[i]->pPhysicalDstBuffer);
                lNumRetried++;
              }
            }
          } while( FSLDMA_RC_BUSY == lDMAResultCode ); // Retry the transaction if all DMA channels are busy
        }

        if ( FALSE == bAbort )
        {
          // Now that we have started all the DMA transactions at once,
          // we need to Wait() on the signals that tell us each transaction
          // has been completed.
          BOOL bStillRunning    = TRUE;
          uint32 lSigReceived   = 0;
          uint32 lNumReceived   = 0;
          uint32 lWaitOnSignals = (SIGBREAKF_CTRL_D | SIGBREAKF_CTRL_C);
          do
          {
            // Wait for the DMA completion/status/error signals for all "threads"
            lSigReceived = IExec->Wait( lWaitOnSignals );

            // Check each DMA Transaction Data structure to see which ones
            // are reporting an event
            for( int c = 0; c < nNumberThreads; c++ )
            {
              // Clear the previous Transaction ID and Thread Number values
              uint32 lTransID          = 0;
              uint32 lThreadNum        = 0;
              uint32 lTransSize        = 0;
              BOOL   bOutputInProgress = FALSE;
              BOOL   bOutputCompleted  = FALSE;
              BOOL   bOutputError      = FALSE;

              // Read and Update the DMA Transaction Data
              struct dma_trans_data *pSignaledDMATransData = pDMATransData[c];
              if ( NULL != pSignaledDMATransData )
              {
                // Obtain Mutex Lock and update the shared data
                IExec->MutexObtain(pSignaledDMATransData->mxTransactionLock);
                // If this thread has not already reported completion (or error)
                // Update it and report as needed
                if ( FALSE == pSignaledDMATransData->bAlreadyReported )
                {
                  bOutputInProgress = pSignaledDMATransData->bReceivedInProgress;
                  bOutputCompleted  = pSignaledDMATransData->bReceivedCompleted;
                  bOutputError      = pSignaledDMATransData->bReceivedError;
                  lTransID          = pSignaledDMATransData->lTransactionId;
                  lThreadNum        = pSignaledDMATransData->lThreadNumber;
                  lTransSize        = pSignaledDMATransData->lTransferLength;
                  // If either 'Completed' or 'Error' was set, then
                  // mark this transaction as "Already Reported"
                  if ( (TRUE == bOutputCompleted) || (TRUE == bOutputError) )
                  {
                    pSignaledDMATransData->bAlreadyReported = TRUE;
                    // Count this thread as received
                    lNumReceived++;
                  }
                }
                // Release the Mutex lock on this DMA Transaction Data
                IExec->MutexRelease(pSignaledDMATransData->mxTransactionLock);
              }

              // Output any events found
              if ( TRUE == bOutputCompleted )
              {
                // Received a "Completed" signal
                printf("Received a \"Completed\" signal for DMA Transaction [0x%08x] of Length [%lu] for Thread [%ld].\n",lTransID,lTransSize,lThreadNum);
                // Also increment the number of completed
                lNumCompleted++;
              }
              else if ( TRUE == bOutputError )
              {
                // Received an "In Progress" signal
                printf("Received an \"In Progress\" signal for DMA Transaction [0x%08x] of Length [%lu] for Thread [%ld]...\n",lTransID,lTransSize,lThreadNum);
                // Also increment the number of failures
                lNumFailed++;
              }
              else if ( TRUE == bOutputInProgress )
              {
                // Received an "Error" signal
                printf("Received a \"Error\" signal for DMA Transaction [0x%08x] of Length [%lu] for Thread [%ld]!\n",lTransID,lTransSize,lThreadNum);
              }
            }

            // Check that we got responses from all the threads
            // (reads DMA Transactions) we started
            printf("Checking lNumReceived[%lu] == nNumberThreads[%lu] for Test Run [%lu]\n",lNumReceived,nNumberThreads,r);
            if ( lNumReceived == nNumberThreads )
            {
              bStillRunning = FALSE;
            }

            // Do more stuff *while* the data is being copied...
            if ( TRUE == bStillRunning )
            {
              printf("Doing other stuff while waiting...\n");

              // Finally, check if we got a Break signal from the user
              // just in case we want to quit out early for some reason
              if ( SIGBREAKF_CTRL_C == (lSigReceived & SIGBREAKF_CTRL_C) )
              {
                printf("Received an \"User break\" signal, ending.\n");
                bStillRunning = FALSE;
              }
            }
          } while( TRUE == bStillRunning );

          // We have completed one set of threads, so clear the status of the
          for( int y = 0; y < nNumberThreads; y++ )
          {
            struct dma_trans_data *pCompletedDMATransData = pDMATransData[y];
            if ( NULL != pCompletedDMATransData )
            {
              // Obtain Mutex Lock and update the shared data
              IExec->MutexObtain(pCompletedDMATransData->mxTransactionLock);
              // If Verify mode is enabled, then compare the source and destination data for this thread
              if ( TRUE == bWithVerify )
              {
                pCompletedDMATransData->bVerified = verifyIdentical(pCompletedDMATransData->pSourceBuffer,pCompletedDMATransData->pDestBuffer,pCompletedDMATransData->lTransferLength,TRUE);
                printf("DMA Transaction [0x%08lx] %s\n",pCompletedDMATransData->lTransactionId,(pCompletedDMATransData->bVerified == TRUE) ? "was verify OK" : "failed!",pCompletedDMATransData->lTransferLength);
                if ( TRUE == pCompletedDMATransData->bVerified )
                {
                  lTotalTransactionsVerified++; // Increment the Total count of "Verifed OK"
                }
                else
                {
                  lTotalFailedToMatch++; // Increment the Total count of "Failed to Match"
                  // Since we had a failure here, then output the entire DMA Transaction data structure for review
                  printf(" APTR                mxTransactionLock   = %p\n",pCompletedDMATransData->mxTransactionLock);
                  printf(" struct Task        *pSignalTask         = %p\n",pCompletedDMATransData->pSignalTask);
                  printf(" struct Hook        *pNotifyHook         = %p\n",pCompletedDMATransData->pNotifyHook);
                  printf(" uint32              lNotifyHookFlags    = %lu\n",pCompletedDMATransData->lNotifyHookFlags);
                  printf(" uint32              lTransactionId      = 0x%08lx\n",pCompletedDMATransData->lTransactionId);
                  printf(" uint32              lTransferLength     = %lu\n",pCompletedDMATransData->lTransferLength);
                  printf(" uint32              lThreadNumber       = %lu\n",pCompletedDMATransData->lThreadNumber);
                  printf(" CONST_APTR          pSourceBuffer       = %p\n",pCompletedDMATransData->pSourceBuffer);
                  printf(" APTR                pDestBuffer         = %p\n",pCompletedDMATransData->pDestBuffer);
                  printf(" CONST_APTR          pPhysicalSrcBuffer  = %p\n",pCompletedDMATransData->pPhysicalSrcBuffer);
                  printf(" APTR                pPhysicalDstBuffer  = %p\n",pCompletedDMATransData->pPhysicalDstBuffer);
                  printf(" struct TimerObject *pTimerObj           = %p\n",pCompletedDMATransData->pTimerObj);
                  printf(" struct TimeVal      oTimeValStart       = %lu.%lu\n",pCompletedDMATransData->oTimeValStart.Seconds,pCompletedDMATransData->oTimeValStart.Microseconds);
                  printf(" struct TimeVal      oTimeValEnd         = %lu.%lu\n",pCompletedDMATransData->oTimeValEnd.Seconds,pCompletedDMATransData->oTimeValEnd.Microseconds);
                  printf(" uint32              lTimeOutCounter     = %lu\n",pCompletedDMATransData->lTimeOutCounter);
                  printf(" BOOL                bReceivedCompleted  = %s\n",(TRUE == pCompletedDMATransData->bReceivedCompleted) ? "TRUE" : "FALSE");
                  printf(" BOOL                bReceivedInProgress = %s\n",(TRUE == pCompletedDMATransData->bReceivedInProgress) ? "TRUE" : "FALSE");
                  printf(" BOOL                bReceivedError      = %s\n",(TRUE == pCompletedDMATransData->bReceivedError) ? "TRUE" : "FALSE");
                  printf(" BOOL                bAlreadyReported    = %s\n",(TRUE == pCompletedDMATransData->bAlreadyReported) ? "TRUE" : "FALSE");
                  printf(" BOOL                bVerified           = %s\n",(TRUE == pCompletedDMATransData->bVerified) ? "TRUE" : "FALSE");
                }
              }

              // Gather the completion times for each thread
              if ( (0 == pCompletedDMATransData->oTimeValEnd.Seconds) && (0 == pCompletedDMATransData->oTimeValEnd.Microseconds) )
              {
                // This tasks appears to have timed out, increment the Timed Out total
                lNumTimedOut++;
              }
              else
              {
                // Calculate the amount of time that was spent of this task (thread)
                pTimerObj->pITimer->SubTime(&pCompletedDMATransData->oTimeValEnd,&pCompletedDMATransData->oTimeValStart);
                // Add that to our Total Task time value
                pTimerObj->pITimer->AddTime(&oTotalTaskTime,&pCompletedDMATransData->oTimeValEnd);
              }

              // Clear out the old time values before the next run
              pCompletedDMATransData->oTimeValStart.Seconds      = 0;
              pCompletedDMATransData->oTimeValStart.Microseconds = 0;
              pCompletedDMATransData->oTimeValEnd.Seconds        = 0;
              pCompletedDMATransData->oTimeValEnd.Microseconds   = 0;

              // Reset the DMA Transaction Data
              pCompletedDMATransData->lTransactionId      = 0;
              pCompletedDMATransData->bReceivedInProgress = FALSE;
              pCompletedDMATransData->bReceivedCompleted  = FALSE;
              pCompletedDMATransData->bReceivedError      = FALSE;
              pCompletedDMATransData->bAlreadyReported    = FALSE;
              // Release the Mutex lock on this DMA Transaction Data
              IExec->MutexRelease(pCompletedDMATransData->mxTransactionLock);
            }
          }
        }
        else
        {
          break; // Abort was set so stop the test runs and cleanup
        }
        // Continue to the next Run
      }
      // Output the total results of all the runs
      uint32 lTotalTransactions = (lNumCompleted + lNumFailed + lNumTimedOut);
      printf("%lu DMA Transactions processed in %lu seconds and %lu microseconds.\n",lTotalTransactions,oTotalTaskTime.Seconds,oTotalTaskTime.Microseconds);
      printf("%lu DMA Transactions started, %lu succeeded with %lu retries, %lu failed and %lu timed out.\n",lNumStarted,lNumCompleted,lNumRetried,lNumFailed,lNumTimedOut);
      printf("%lu DMA Transactions were verified correct, %lu failed to match.\n",lTotalTransactionsVerified,lTotalFailedToMatch);
      // Pull the current time (calculate the time it took to run)
      pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValEnd);
      pTimerObj->pITimer->SubTime(&pTimerObj->oTimeValEnd,&pTimerObj->oTimeValStart);
      printf("Total time to run all tests was %lu seconds and %lu microseconds.\n",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
    }

    // Make sure we free everything before we leave
    // Free each thread's DMA Transaction data
    for( int i = 0; i < nNumberThreads; i++ )
    {
      struct dma_trans_data *pDMATransDataToFree = pDMATransData[i];
      if ( NULL != pDMATransDataToFree )
      {
        // Free the attached objects for this DMA Transaction Data structure
        if ( NULL != pDMATransDataToFree->mxTransactionLock ) IExec->FreeSysObject(ASOT_MUTEX,pDMATransDataToFree->mxTransactionLock);
        if ( NULL != pDMATransDataToFree->pNotifyHook       ) IExec->FreeSysObject(ASOT_HOOK,pDMATransDataToFree->pNotifyHook);
        if ( NULL != pDMATransDataToFree->pSourceBuffer     ) IExec->FreeVec((APTR)pDMATransDataToFree->pSourceBuffer);
        if ( NULL != pDMATransDataToFree->pDestBuffer       ) IExec->FreeVec((APTR)pDMATransDataToFree->pDestBuffer);
        // Now free the DMA Transaction Data structure itself
        IExec->FreeVec((APTR)pDMATransDataToFree);
      }
    }

    IExec->DropInterface((struct Interface *)IMMU);
  }
}

//
// Handle Notification Hook calls
//
uint32 notifyHookFunction(struct Hook *hook, uint32 lDMATransactionID, uint32 lNotifyFlag)
{
  if ( NULL != hook )
  {
    struct Task *pSignalTask = NULL;
    struct dma_trans_data *pNotifiedDMATransData = (struct dma_trans_data *)hook->h_Data;
    if ( NULL != pNotifiedDMATransData )
    {
      // Obtain Mutex Lock and update the shared data
      IExec->MutexObtain(pNotifiedDMATransData->mxTransactionLock);
      // Pull the current time (Timestamp the event)
      struct TimerObject *pSharedTimerObj = pNotifiedDMATransData->pTimerObj;
      if ( NULL != pSharedTimerObj )
      {
        pSharedTimerObj->pITimer->GetSysTime(&pNotifiedDMATransData->oTimeValEnd);
      }
      pNotifiedDMATransData->lTransactionId = lDMATransactionID;
      pSignalTask = pNotifiedDMATransData->pSignalTask;
      // Determine which Notify signal was sent
      switch( lNotifyFlag )
      {
        case FSLDMA_NF_INPROGRESS:
        {
          pNotifiedDMATransData->bReceivedInProgress = TRUE;
        }
        break;

        case FSLDMA_NF_COMPLETE:
        {
          pNotifiedDMATransData->bReceivedCompleted = TRUE;
        }
        break;

        case FSLDMA_NF_ERROR:
        {
          pNotifiedDMATransData->bReceivedError = TRUE;
        }
        break;

        default: { } break;
      }
      // Release the Mutex Lock
      IExec->MutexRelease(pNotifiedDMATransData->mxTransactionLock);
    }

    // Signal the main task that an event has occurred
    if ( NULL != pSignalTask )
    {
      IExec->Signal(pSignalTask,SIGBREAKF_CTRL_D);
    }
  }
  return( 0 );
}

struct TimerObject * fsldma_OpenTimerDevice(enum enTimerUnits nTimerUnit)
{
  struct TimerObject *pNewTimerObj = NULL;
  pNewTimerObj = (struct TimerObject *)IExec->AllocVecTags(sizeof(struct TimerObject),AVT_Type,MEMF_SHARED,AVT_ClearWithValue,0,TAG_END);

  if ( NULL != pNewTimerObj )
  {
    // Allocate a MsgPort for our Timer
    pNewTimerObj->pTimerMsgPort = IExec->AllocSysObjectTags(ASOT_PORT,TAG_END);
    if ( NULL != pNewTimerObj->pTimerMsgPort )
    {
      // Allocate a IORequest object for our Timer
      pNewTimerObj->pTimerIOReq = (struct TimeRequest *)IExec->AllocSysObjectTags(ASOT_IOREQUEST,
                                                                                  ASOIOR_ReplyPort,pNewTimerObj->pTimerMsgPort,
                                                                                  ASOIOR_Size,sizeof(struct TimeRequest),
                                                                                  TAG_END);
      if ( NULL != pNewTimerObj->pTimerIOReq )
      {
        // Open the Timer Device (return of zero(0) == success)
        if ( 0 == IExec->OpenDevice(TIMERNAME,nTimerUnit,(struct IORequest *)pNewTimerObj->pTimerIOReq,0) )
        {
          // Obtain the TimerBase from our initialized TimerRequest structure
          pNewTimerObj->pTimerBase = (struct Library *)pNewTimerObj->pTimerIOReq->Request.io_Device;
          if ( NULL != pNewTimerObj->pTimerBase )
          {
            // Obtain the Interface to the Timer library
            pNewTimerObj->pITimer = (struct TimerIFace *)IExec->GetInterface(pNewTimerObj->pTimerBase,"main",1,NULL);
            if ( NULL != pNewTimerObj->pITimer )
            {
              // Success - Our timer device and timer library interface is open
            }
            else
            {
              // Failed to obtain the TimerIFace - Call fsldma_CloseTimerDevice() to cleanup
              fsldma_CloseTimerDevice(pNewTimerObj);
            }
          }
          else
          {
            // Failed to obtain the pTimerBase - Call fsldma_CloseTimerDevice() to cleanup
            fsldma_CloseTimerDevice(pNewTimerObj);
          }
        }
        else
        {
          // Failed to Open the Timer Device library - Call fsldma_CloseTimerDevice() to cleanup
          fsldma_CloseTimerDevice(pNewTimerObj);
        }
      }
      else
      {
        // Failed to Allocate the Timer IO Request - Call fsldma_CloseTimerDevice() to cleanup
        fsldma_CloseTimerDevice(pNewTimerObj);
      }
    }
    else
    {
      // Failed to Allocate the Timer Msg Port - Call fsldma_CloseTimerDevice() to cleanup
      fsldma_CloseTimerDevice(pNewTimerObj);
    }
  }

  return( pNewTimerObj );
}


void fsldma_CloseTimerDevice(struct TimerObject *pTimerObj)
{
  if ( NULL != pTimerObj )
  {
    // Free the Timer Interface
    if ( NULL != pTimerObj->pITimer )
    {
      IExec->DropInterface((struct Interface *)pTimerObj->pITimer);
      pTimerObj->pITimer = NULL;
    }

    // Free the TimerBase (Clear any pending Timer Event Messages before closing)
    if ( NULL != pTimerObj->pTimerBase )
    {
      if ( NULL != pTimerObj->pTimerIOReq )
      {
        // Now we can close the timer device
        IExec->CloseDevice((struct IORequest *)pTimerObj->pTimerIOReq);
      }
      pTimerObj->pTimerBase = NULL;
    }

    // Free the Timer IO Request object
    if ( NULL != pTimerObj->pTimerIOReq )
    {
      IExec->FreeSysObject(ASOT_IOREQUEST,(struct IORequest *)pTimerObj->pTimerIOReq);
      pTimerObj->pTimerIOReq = NULL;
    }

    // Free the Timer Msg Port
    if ( NULL != pTimerObj->pTimerMsgPort )
    {
      IExec->FreeSysObject(ASOT_PORT,pTimerObj->pTimerMsgPort);
      pTimerObj->pTimerMsgPort = NULL;
    }

    // Free the Timer Object itself
    IExec->FreeVec(pTimerObj);
    pTimerObj = NULL;
  }
}

//
// Our verify data routine
//
BOOL verifyIdentical(CONST_APTR pBuffer1, APTR pBuffer2, uint32 lTestSize, BOOL bAlterAfterVerify)
{
  BOOL bVerified = TRUE;
  if ( (NULL != pBuffer1) && (NULL != pBuffer2) && (lTestSize > 0) )
  {
    // Determine the fastest verify method we can use
    if ( 0 == (lTestSize % 8) )
    {
      // We are divisible by 8 bytes,
      // so use a 64-Bit test loop
      uint64 *pSrcBuf = (uint64 *)pBuffer1;
      uint64 *pDstBuf = (uint64 *)pBuffer2;
      uint32 lTestCount = (lTestSize / 8);
      printf("Attempting to verify %lu bytes [in %lu 64-Bit blocks] of [%p] and [%p]...",lTestSize,lTestCount,pBuffer1,pBuffer2);
      fflush(stdout);
      for( uint32 i = 0; i < lTestCount; i++ )
      {
        //printf("64-Bit Check: %lu of %lu for [%llx] == [%llx]\n",i,lTestCount,pSrcBuf[i],pDstBuf[i]);
        if ( pSrcBuf[i] == pDstBuf[i] )
        {
          // The block matches, check if the source and destination data should also be altered (for the next time run)
          if ( TRUE == bAlterAfterVerify )
          {
            pSrcBuf[i] = (pSrcBuf[i] + (uint64)0x01); // Increment the source data
            pDstBuf[i] = (uint64)0x0;                 // Clear the destination data
          }
        }
        else
        {
          // The block did not match, so report the error and stop here
          printf(" 64-Bit Check: [%llx] != [%llx] ",pSrcBuf[i],pDstBuf[i]);
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
    else if ( 0 == (lTestSize % 4) )
    {
      // We are divisible by 4 bytes,
      // so use a 32-Bit test loop
      uint32 *pSrcBuf = (uint32 *)pBuffer1;
      uint32 *pDstBuf = (uint32 *)pBuffer2;
      uint32 lTestCount = (lTestSize / 4);
      printf("Attempting to verify %lu bytes [in %lu 32-Bit blocks] of [%p] and [%p]...",lTestSize,lTestCount,pBuffer1,pBuffer2);
      fflush(stdout);
      for( uint32 i = 0; i < lTestCount; i++ )
      {
        //printf("32-Bit Check: %lu of %lu for [%lx] == [%lx]\n",i,lTestCount,pSrcBuf[i],pDstBuf[i]);
        if ( pSrcBuf[i] == pDstBuf[i] )
        {
          // The block matches, check if the source and destination data should also be altered (for the next time run)
          if ( TRUE == bAlterAfterVerify )
          {
            pSrcBuf[i] = (pSrcBuf[i] + (uint32)0x01); // Increment the source data
            pDstBuf[i] = (uint32)0x0;                 // Clear the destination data
          }
        }
        else
        {
          // The block did not match, so report the error and stop here
          printf(" 32-Bit Check: [%lx] != [%lx] ",pSrcBuf[i],pDstBuf[i]);
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
    else if ( 0 == (lTestSize % 2) )
    {
      // We are divisible by 2 bytes,
      // so use a 16-Bit test loop
      uint16 *pSrcBuf = (uint16 *)pBuffer1;
      uint16 *pDstBuf = (uint16 *)pBuffer2;
      uint32 lTestCount = (lTestSize / 2);
      printf("Attempting to verify %lu bytes [in %lu 16-Bit blocks] of [%p] and [%p]...",lTestSize,lTestCount,pBuffer1,pBuffer2);
      fflush(stdout);
      for( uint32 i = 0; i < lTestCount; i++ )
      {
        //printf("16-Bit Check: %lu of %lu for [%lx] == [%lx]\n",i,lTestCount,(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
        if ( pSrcBuf[i] == pDstBuf[i] )
        {
          // The block matches, check if the source and destination data should also be altered (for the next time run)
          if ( TRUE == bAlterAfterVerify )
          {
            pSrcBuf[i] = (pSrcBuf[i] + (uint16)0x01); // Increment the source data
            pDstBuf[i] = (uint16)0x0;                 // Clear the destination data
          }
        }
        else
        {
          // The block did not match, so report the error and stop here
          printf(" 16-Bit Check: [%lx] != [%lx] ",(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
    else
    {
      // Otherwise use a 8-Bit test loop
      uint8 *pSrcBuf = (uint8 *)pBuffer1;
      uint8 *pDstBuf = (uint8 *)pBuffer2;
      printf("Attempting to verify %lu bytes [in %lu 8-Bit blocks] of [%p] and [%p]...",lTestSize,lTestSize,pBuffer1,pBuffer2);
      fflush(stdout);
      for( uint32 i = 0; i < lTestSize; i++ )
      {
        //printf("8-Bit Check: %lu of %lu for [%lx] == [%lx]\n",i,lTestSize,(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
        if ( pSrcBuf[i] == pDstBuf[i] )
        {
          // The block matches, check if the source and destination data should also be altered (for the next time run)
          if ( TRUE == bAlterAfterVerify )
          {
            pSrcBuf[i] = (pSrcBuf[i] + (uint8)0x01); // Increment the source data
            pDstBuf[i] = (uint8)0x0;                 // Clear the destination data
          }
        }
        else
        {
          // The block did not match, so report the error and stop here
          printf(" 8-Bit Check: [%lx] != [%lx] ",(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
  }
  return( bVerified );
}
