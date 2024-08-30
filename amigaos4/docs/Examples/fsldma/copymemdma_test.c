/*
 * copymemdma_test.c
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

struct TimerObject * fsldma_OpenTimerDevice( enum enTimerUnits nTimerUnit );
void fsldma_CloseTimerDevice( struct TimerObject *pTimerObj );
void fsldma_CopyMemDMA_Test( struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint32 lTestSize, uint8 nFillByte, BOOL bVerify );
void fsldma_CopyMemDMAPhyToPhy_Test( struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint32 lTestSize, uint8 nFillByte, BOOL bVerify );
void fsldma_CopyMemDMAPhyToVirt_Test( struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint32 lTestSize, uint8 nFillByte, BOOL bVerify );
void fsldma_CopyMemDMAVirtToPhy_Test( struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint32 lTestSize, uint8 nFillByte, BOOL bVerify );
void fsldma_Parallel_Test( struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint8 nNumberThreads, BOOL bVerify );
void fsldma_ExecCopyMem_Test( struct TimerObject *pTimerObj, uint32 lTestSize, uint8 nFillByte, BOOL bVerify );
BOOL verifyIdentical( CONST_APTR pBuffer1, APTR pBuffer2, uint32 lTestSize );

int main(int argc, char *argv[])
{
  struct ExecBase  *ExecBase = (*(struct ExecBase **)4);
  struct ExecIFace *IExec    = (struct ExecIFace *)ExecBase->MainInterface;

  // Set Verify Flag
  BOOL bVerifyTest = FALSE;
  if ( argc > 1 )
  {
    char *sVerifyArg = argv[1];
    if ( strlen(sVerifyArg) >= 2 )
    {
      if ( ('-' == sVerifyArg[0]) && ('v' == sVerifyArg[1]) )
      {
        bVerifyTest = TRUE;
      }
    }
  }

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
      // Perform Test 1: IfslDMA->CopyMemDMA(Virtual-to-Virtual)
      //
      printf("fsldma.resource Test 1: IfslDMA->CopyMemDMA(Virtual-to-Virtual):\n");
      printf("Using IfslDMA->CopyMemDMA() with normal Virtual Memory areas...\n");
      // Testing 1 Byte
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_1_BYTE,(uint8)0x01,bVerifyTest);
      // Testing 2 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_2_BYTES,(uint8)0x02,bVerifyTest);
      // Testing 4 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_4_BYTES,(uint8)0x03,bVerifyTest);
      // Testing 8 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_8_BYTES,(uint8)0x04,bVerifyTest);
      // Testing 16 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_16_BYTES,(uint8)0x05,bVerifyTest);
      // Testing 32 Byte
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_32_BYTES,(uint8)0x06,bVerifyTest);
      // Testing 64 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_64_BYTES,(uint8)0x07,bVerifyTest);
      // Testing 128 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_128_BYTES,(uint8)0x08,bVerifyTest);
      // Testing 256 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_256_BYTES,(uint8)0x09,bVerifyTest);
      // Testing 384 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_384_BYTES,(uint8)0x0A,bVerifyTest);
      // Testing 512 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_512_BYTES,(uint8)0x0B,bVerifyTest);
      // Testing 640 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_640_BYTES,(uint8)0x0C,bVerifyTest);
      // Testing 768 Bytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_768_BYTES,(uint8)0x0D,bVerifyTest);
      // Testing 1 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_1_KB,(uint8)0x0E,bVerifyTest);
      // Testing Standard Ethernet Packet transfer size [1536 Bytes]
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_ETH_PACKET,(uint8)0x0F,bVerifyTest);
      // Testing 2 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_2_KB,(uint8)0x10,bVerifyTest);
      // Testing 4 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_4_KB,(uint8)0x11,bVerifyTest);
      // Testing 8 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_8_KB,(uint8)0x12,bVerifyTest);
      // Testing 16 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_16_KB,(uint8)0x13,bVerifyTest);
      // Testing 20 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_20_KB,(uint8)0x14,bVerifyTest);
      // Testing 24 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_24_KB,(uint8)0x15,bVerifyTest);
      // Testing 32 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_32_KB,(uint8)0x16,bVerifyTest);
      // Testing 36 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_36_KB,(uint8)0x17,bVerifyTest);
      // Testing 40 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_40_KB,(uint8)0x18,bVerifyTest);
      // Testing 42 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_42_KB,(uint8)0x19,bVerifyTest);
      // Testing 46 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_46_KB,(uint8)0x1A,bVerifyTest);
      // Testing 50 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_50_KB,(uint8)0x1B,bVerifyTest);
      // Testing 52 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_52_KB,(uint8)0x1C,bVerifyTest);
      // Testing 56 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_56_KB,(uint8)0x1D,bVerifyTest);
      // Testing 60 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_60_KB,(uint8)0x1E,bVerifyTest);
      // Testing 64 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_64_KB,(uint8)0x1F,bVerifyTest);
      // Testing 128 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_128_KB,(uint8)0x20,bVerifyTest);
      // Testing 256 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_256_KB,(uint8)0x21,bVerifyTest);
      // Testing 512 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_512_KB,(uint8)0x22,bVerifyTest);
      // Testing 768 Kilobytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_768_KB,(uint8)0x23,bVerifyTest);
      // Testing 1 Megabyte
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_1_MB,(uint8)0x24,bVerifyTest);
      // Testing Maximum Optimal Block Size (64MB - 64 Bytes)
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,FSLDMA_OPTIMAL_BLKSIZE,(uint8)0x25,bVerifyTest);
      // Testing Maximum Block Size (64MB - 1 Byte)
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,FSLDMA_MAXBLOCK_SIZE,(uint8)0x26,bVerifyTest);
      // Testing 128 Megabytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_128_MB,(uint8)0x27,bVerifyTest);
      // Testing 256 Megabytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_256_MB,(uint8)0x28,bVerifyTest);
      // Testing 512 Megabytes
      fsldma_CopyMemDMA_Test(IfslDMA,pTimerObj,SIZE_512_MB,(uint8)0x29,bVerifyTest);

      //
      // Perform Test 2: IfslDMA->CopyMemDMATags(Physical-to-Physical)
      //
      printf("\nfsldma.resource Test 2: IfslDMA->CopyMemDMATags(Physical-to-Physical):\n");
      printf("Using IfslDMA->CopyMemDMATags() with cache-inhibited Physical Memory areas...\n");
      // Testing 1 Byte
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_1_BYTE,(uint8)0x01,bVerifyTest);
      // Testing 2 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_2_BYTES,(uint8)0x02,bVerifyTest);
      // Testing 4 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_4_BYTES,(uint8)0x03,bVerifyTest);
      // Testing 8 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_8_BYTES,(uint8)0x04,bVerifyTest);
      // Testing 16 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_16_BYTES,(uint8)0x05,bVerifyTest);
      // Testing 32 Byte
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_32_BYTES,(uint8)0x06,bVerifyTest);
      // Testing 64 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_64_BYTES,(uint8)0x07,bVerifyTest);
      // Testing 128 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_128_BYTES,(uint8)0x08,bVerifyTest);
      // Testing 256 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_256_BYTES,(uint8)0x09,bVerifyTest);
      // Testing 384 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_384_BYTES,(uint8)0x0A,bVerifyTest);
      // Testing 512 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_512_BYTES,(uint8)0x0B,bVerifyTest);
      // Testing 640 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_640_BYTES,(uint8)0x0C,bVerifyTest);
      // Testing 768 Bytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_768_BYTES,(uint8)0x0D,bVerifyTest);
      // Testing 1 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_1_KB,(uint8)0x0E,bVerifyTest);
      // Testing Standard Ethernet Packet transfer size [1536 Bytes]
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_ETH_PACKET,(uint8)0x0F,bVerifyTest);
      // Testing 2 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_2_KB,(uint8)0x10,bVerifyTest);
      // Testing 4 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_4_KB,(uint8)0x11,bVerifyTest);
      // Testing 8 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_8_KB,(uint8)0x12,bVerifyTest);
      // Testing 16 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_16_KB,(uint8)0x13,bVerifyTest);
      // Testing 20 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_20_KB,(uint8)0x14,bVerifyTest);
      // Testing 24 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_24_KB,(uint8)0x15,bVerifyTest);
      // Testing 32 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_32_KB,(uint8)0x16,bVerifyTest);
      // Testing 36 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_36_KB,(uint8)0x17,bVerifyTest);
      // Testing 40 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_40_KB,(uint8)0x18,bVerifyTest);
      // Testing 42 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_42_KB,(uint8)0x19,bVerifyTest);
      // Testing 46 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_46_KB,(uint8)0x1A,bVerifyTest);
      // Testing 50 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_50_KB,(uint8)0x1B,bVerifyTest);
      // Testing 52 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_52_KB,(uint8)0x1C,bVerifyTest);
      // Testing 56 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_56_KB,(uint8)0x1D,bVerifyTest);
      // Testing 60 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_60_KB,(uint8)0x1E,bVerifyTest);
      // Testing 64 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_64_KB,(uint8)0x1F,bVerifyTest);
      // Testing 128 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_128_KB,(uint8)0x20,bVerifyTest);
      // Testing 256 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_256_KB,(uint8)0x21,bVerifyTest);
      // Testing 512 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_512_KB,(uint8)0x22,bVerifyTest);
      // Testing 768 Kilobytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_768_KB,(uint8)0x23,bVerifyTest);
      // Testing 1 Megabyte
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_1_MB,(uint8)0x24,bVerifyTest);
      // Testing Maximum Optimal Block Size (64MB - 64 Bytes)
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,FSLDMA_OPTIMAL_BLKSIZE,(uint8)0x25,bVerifyTest);
      // Testing Maximum Block Size (64MB - 1 Byte)
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,FSLDMA_MAXBLOCK_SIZE,(uint8)0x26,bVerifyTest);
      // Testing 128 Megabytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_128_MB,(uint8)0x27,bVerifyTest);
      // Testing 256 Megabytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_256_MB,(uint8)0x28,bVerifyTest);
      // Testing 512 Megabytes
      fsldma_CopyMemDMAPhyToPhy_Test(IfslDMA,pTimerObj,SIZE_512_MB,(uint8)0x29,bVerifyTest);

      //
      // Perform Test 3: IfslDMA->CopyMemDMATags(Physical-to-Virtual)
      //
      printf("\nfsldma.resource Test 3: IfslDMA->CopyMemDMATags(Physical-to-Virtual):\n");
      printf("Using IfslDMA->CopyMemDMATags() with Physical Memory Source and Virtual Memory Destination...\n");
      // Testing 1 Byte
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_1_BYTE,(uint8)0x01,bVerifyTest);
      // Testing 2 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_2_BYTES,(uint8)0x02,bVerifyTest);
      // Testing 4 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_4_BYTES,(uint8)0x03,bVerifyTest);
      // Testing 8 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_8_BYTES,(uint8)0x04,bVerifyTest);
      // Testing 16 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_16_BYTES,(uint8)0x05,bVerifyTest);
      // Testing 32 Byte
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_32_BYTES,(uint8)0x06,bVerifyTest);
      // Testing 64 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_64_BYTES,(uint8)0x07,bVerifyTest);
      // Testing 128 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_128_BYTES,(uint8)0x08,bVerifyTest);
      // Testing 256 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_256_BYTES,(uint8)0x09,bVerifyTest);
      // Testing 384 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_384_BYTES,(uint8)0x0A,bVerifyTest);
      // Testing 512 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_512_BYTES,(uint8)0x0B,bVerifyTest);
      // Testing 640 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_640_BYTES,(uint8)0x0C,bVerifyTest);
      // Testing 768 Bytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_768_BYTES,(uint8)0x0D,bVerifyTest);
      // Testing 1 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_1_KB,(uint8)0x0E,bVerifyTest);
      // Testing Standard Ethernet Packet transfer size [1536 Bytes]
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_ETH_PACKET,(uint8)0x0F,bVerifyTest);
      // Testing 2 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_2_KB,(uint8)0x10,bVerifyTest);
      // Testing 4 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_4_KB,(uint8)0x11,bVerifyTest);
      // Testing 8 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_8_KB,(uint8)0x12,bVerifyTest);
      // Testing 16 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_16_KB,(uint8)0x13,bVerifyTest);
      // Testing 20 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_20_KB,(uint8)0x14,bVerifyTest);
      // Testing 24 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_24_KB,(uint8)0x15,bVerifyTest);
      // Testing 32 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_32_KB,(uint8)0x16,bVerifyTest);
      // Testing 36 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_36_KB,(uint8)0x17,bVerifyTest);
      // Testing 40 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_40_KB,(uint8)0x18,bVerifyTest);
      // Testing 42 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_42_KB,(uint8)0x19,bVerifyTest);
      // Testing 46 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_46_KB,(uint8)0x1A,bVerifyTest);
      // Testing 50 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_50_KB,(uint8)0x1B,bVerifyTest);
      // Testing 52 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_52_KB,(uint8)0x1C,bVerifyTest);
      // Testing 56 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_56_KB,(uint8)0x1D,bVerifyTest);
      // Testing 60 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_60_KB,(uint8)0x1E,bVerifyTest);
      // Testing 64 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_64_KB,(uint8)0x1F,bVerifyTest);
      // Testing 128 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_128_KB,(uint8)0x20,bVerifyTest);
      // Testing 256 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_256_KB,(uint8)0x21,bVerifyTest);
      // Testing 512 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_512_KB,(uint8)0x22,bVerifyTest);
      // Testing 768 Kilobytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_768_KB,(uint8)0x23,bVerifyTest);
      // Testing 1 Megabyte
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_1_MB,(uint8)0x24,bVerifyTest);
      // Testing Maximum Optimal Block Size (64MB - 64 Bytes)
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,FSLDMA_OPTIMAL_BLKSIZE,(uint8)0x25,bVerifyTest);
      // Testing Maximum Block Size (64MB - 1 Byte)
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,FSLDMA_MAXBLOCK_SIZE,(uint8)0x26,bVerifyTest);
      // Testing 128 Megabytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_128_MB,(uint8)0x27,bVerifyTest);
      // Testing 256 Megabytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_256_MB,(uint8)0x28,bVerifyTest);
      // Testing 512 Megabytes
      fsldma_CopyMemDMAPhyToVirt_Test(IfslDMA,pTimerObj,SIZE_512_MB,(uint8)0x29,bVerifyTest);

      //
      // Perform Test 4: IfslDMA->CopyMemDMATags(Virtual-to-Physical)
      //
      printf("\nfsldma.resource Test 4: IfslDMA->CopyMemDMATags(Virtual-to-Physical)...\n");
      printf("Using IfslDMA->CopyMemDMATags() with Virtual Memory Source and Physical Memory Destination...\n");
      // Testing 1 Byte
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_1_BYTE,(uint8)0x01,bVerifyTest);
      // Testing 2 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_2_BYTES,(uint8)0x02,bVerifyTest);
      // Testing 4 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_4_BYTES,(uint8)0x03,bVerifyTest);
      // Testing 8 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_8_BYTES,(uint8)0x04,bVerifyTest);
      // Testing 16 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_16_BYTES,(uint8)0x05,bVerifyTest);
      // Testing 32 Byte
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_32_BYTES,(uint8)0x06,bVerifyTest);
      // Testing 64 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_64_BYTES,(uint8)0x07,bVerifyTest);
      // Testing 128 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_128_BYTES,(uint8)0x08,bVerifyTest);
      // Testing 256 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_256_BYTES,(uint8)0x09,bVerifyTest);
      // Testing 384 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_384_BYTES,(uint8)0x0A,bVerifyTest);
      // Testing 512 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_512_BYTES,(uint8)0x0B,bVerifyTest);
      // Testing 640 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_640_BYTES,(uint8)0x0C,bVerifyTest);
      // Testing 768 Bytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_768_BYTES,(uint8)0x0D,bVerifyTest);
      // Testing 1 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_1_KB,(uint8)0x0E,bVerifyTest);
      // Testing Standard Ethernet Packet transfer size [1536 Bytes]
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_ETH_PACKET,(uint8)0x0F,bVerifyTest);
      // Testing 2 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_2_KB,(uint8)0x10,bVerifyTest);
      // Testing 4 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_4_KB,(uint8)0x11,bVerifyTest);
      // Testing 8 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_8_KB,(uint8)0x12,bVerifyTest);
      // Testing 16 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_16_KB,(uint8)0x13,bVerifyTest);
      // Testing 20 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_20_KB,(uint8)0x14,bVerifyTest);
      // Testing 24 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_24_KB,(uint8)0x15,bVerifyTest);
      // Testing 32 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_32_KB,(uint8)0x16,bVerifyTest);
      // Testing 36 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_36_KB,(uint8)0x17,bVerifyTest);
      // Testing 40 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_40_KB,(uint8)0x18,bVerifyTest);
      // Testing 42 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_42_KB,(uint8)0x19,bVerifyTest);
      // Testing 46 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_46_KB,(uint8)0x1A,bVerifyTest);
      // Testing 50 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_50_KB,(uint8)0x1B,bVerifyTest);
      // Testing 52 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_52_KB,(uint8)0x1C,bVerifyTest);
      // Testing 56 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_56_KB,(uint8)0x1D,bVerifyTest);
      // Testing 60 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_60_KB,(uint8)0x1E,bVerifyTest);
      // Testing 64 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_64_KB,(uint8)0x1F,bVerifyTest);
      // Testing 128 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_128_KB,(uint8)0x20,bVerifyTest);
      // Testing 256 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_256_KB,(uint8)0x21,bVerifyTest);
      // Testing 512 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_512_KB,(uint8)0x22,bVerifyTest);
      // Testing 768 Kilobytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_768_KB,(uint8)0x23,bVerifyTest);
      // Testing 1 Megabyte
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_1_MB,(uint8)0x24,bVerifyTest);
      // Testing Maximum Optimal Block Size (64MB - 64 Bytes)
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,FSLDMA_OPTIMAL_BLKSIZE,(uint8)0x25,bVerifyTest);
      // Testing Maximum Block Size (64MB - 1 Byte)
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,FSLDMA_MAXBLOCK_SIZE,(uint8)0x26,bVerifyTest);
      // Testing 128 Megabytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_128_MB,(uint8)0x27,bVerifyTest);
      // Testing 256 Megabytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_256_MB,(uint8)0x28,bVerifyTest);
      // Testing 512 Megabytes
      fsldma_CopyMemDMAVirtToPhy_Test(IfslDMA,pTimerObj,SIZE_512_MB,(uint8)0x29,bVerifyTest);

      //
      // Perform Test 5: IExec->CopyMem()
      //
      printf("\nfsldma.resource Test 5: IExec->CopyMem():\n");
      printf("Using CPU Copy on normal Virtual Memory areas...\n");
      // Testing 1 Byte
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_1_BYTE,(uint8)0x01,bVerifyTest);
      // Testing 2 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_2_BYTES,(uint8)0x02,bVerifyTest);
      // Testing 4 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_4_BYTES,(uint8)0x03,bVerifyTest);
      // Testing 8 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_8_BYTES,(uint8)0x04,bVerifyTest);
      // Testing 16 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_16_BYTES,(uint8)0x05,bVerifyTest);
      // Testing 32 Byte
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_32_BYTES,(uint8)0x06,bVerifyTest);
      // Testing 64 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_64_BYTES,(uint8)0x07,bVerifyTest);
      // Testing 128 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_128_BYTES,(uint8)0x08,bVerifyTest);
      // Testing 256 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_256_BYTES,(uint8)0x09,bVerifyTest);
      // Testing 384 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_384_BYTES,(uint8)0x0A,bVerifyTest);
      // Testing 512 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_512_BYTES,(uint8)0x0B,bVerifyTest);
      // Testing 640 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_640_BYTES,(uint8)0x0C,bVerifyTest);
      // Testing 768 Bytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_768_BYTES,(uint8)0x0D,bVerifyTest);
      // Testing 1 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_1_KB,(uint8)0x0E,bVerifyTest);
      // Testing Standard Ethernet Packet transfer size [1536 Bytes]
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_ETH_PACKET,(uint8)0x0F,bVerifyTest);
      // Testing 2 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_2_KB,(uint8)0x10,bVerifyTest);
      // Testing 4 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_4_KB,(uint8)0x11,bVerifyTest);
      // Testing 8 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_8_KB,(uint8)0x12,bVerifyTest);
      // Testing 16 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_16_KB,(uint8)0x13,bVerifyTest);
      // Testing 20 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_20_KB,(uint8)0x14,bVerifyTest);
      // Testing 24 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_24_KB,(uint8)0x15,bVerifyTest);
      // Testing 32 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_32_KB,(uint8)0x16,bVerifyTest);
      // Testing 36 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_36_KB,(uint8)0x17,bVerifyTest);
      // Testing 40 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_40_KB,(uint8)0x18,bVerifyTest);
      // Testing 42 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_42_KB,(uint8)0x19,bVerifyTest);
      // Testing 46 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_46_KB,(uint8)0x1A,bVerifyTest);
      // Testing 50 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_50_KB,(uint8)0x1B,bVerifyTest);
      // Testing 52 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_52_KB,(uint8)0x1C,bVerifyTest);
      // Testing 56 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_56_KB,(uint8)0x1D,bVerifyTest);
      // Testing 60 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_60_KB,(uint8)0x1E,bVerifyTest);
      // Testing 64 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_64_KB,(uint8)0x1F,bVerifyTest);
      // Testing 128 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_128_KB,(uint8)0x20,bVerifyTest);
      // Testing 256 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_256_KB,(uint8)0x21,bVerifyTest);
      // Testing 512 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_512_KB,(uint8)0x22,bVerifyTest);
      // Testing 768 Kilobytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_768_KB,(uint8)0x23,bVerifyTest);
      // Testing 1 Megabyte
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_1_MB,(uint8)0x24,bVerifyTest);
      // Testing Maximum Optimal Block Size (64MB - 64 Bytes)
      fsldma_ExecCopyMem_Test(pTimerObj,FSLDMA_OPTIMAL_BLKSIZE,(uint8)0x25,bVerifyTest);
      // Testing Maximum Block Size (64MB - 1 Byte)
      fsldma_ExecCopyMem_Test(pTimerObj,FSLDMA_MAXBLOCK_SIZE,(uint8)0x26,bVerifyTest);
      // Testing 128 Megabytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_128_MB,(uint8)0x27,bVerifyTest);
      // Testing 256 Megabytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_256_MB,(uint8)0x28,bVerifyTest);
      // Testing 512 Megabytes
      fsldma_ExecCopyMem_Test(pTimerObj,SIZE_512_MB,(uint8)0x29,bVerifyTest);

      //
      // Perform Test 6:
      // Parallel execution test
      //
      printf("\nfsldma.resource Test 6: Parallel execution:\n");
      printf("Using IfslDMA->CopyMemDMATags() with \"non-blocking\" mode,\n");
      printf("user Notification signals...\n");
      fsldma_Parallel_Test(IfslDMA,pTimerObj,4,bVerifyTest);

      // Close and free the timer device
      fsldma_CloseTimerDevice(pTimerObj);

      printf("\nfsldma.resource Tests complete.\n");
    }
  }
  return( 0 );
}


//
// Test IfslDMA->CopyMemDMA() [Virtual-to-Virtual]
//
void fsldma_CopyMemDMA_Test(struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint32 lTestSize, uint8 nFillByte, BOOL bVerify)
{
  CONST_APTR pSourceBuffer = NULL;
  APTR       pDestBuffer   = NULL;
  BOOL       bVerified     = TRUE; // Defaults to TRUE

  if ( (NULL == IfslDMA) || (NULL == pTimerObj) || (0 == lTestSize) ) return;

  // Allocate a block of memory for the source and destination
  pSourceBuffer = IExec->AllocVecTags(lTestSize,
                                      AVT_Type,           MEMF_SHARED,       // Memory is available to All Address spaces
                                      AVT_ClearWithValue, (uint32)nFillByte, // Fill data with supplied value before returning it
                                      TAG_END);
  if ( NULL != pSourceBuffer )
  {
    pDestBuffer = IExec->AllocVecTags(lTestSize,
                                      AVT_Type,           MEMF_SHARED, // Memory is available to All Address spaces
                                      AVT_ClearWithValue, 0,           // Clear data with (0) before returning it
                                      TAG_END);
    if ( NULL != pDestBuffer )
    {
      // Reset and start the timer
      pTimerObj->oTimeValStart.Seconds      = 0;
      pTimerObj->oTimeValStart.Microseconds = 0;
      pTimerObj->oTimeValEnd.Seconds        = 0;
      pTimerObj->oTimeValEnd.Microseconds   = 0;

      // Capture DMA Result Code
      uint32 lDMAResultCode = FSLDMA_RC_UNKNOWN; // Set the "Unknown" to start
      BOOL   bAbort         = FALSE;
      BOOL   bResult        = FALSE;

      // Call IfslDMA->CopyMemDMA() to test DMA version using virtual memory pointers
      printf("        CopyMemDMA(): Copied %ld bytes from %p to %p",lTestSize,pSourceBuffer,pDestBuffer);
      fflush(stdout);
      do
      {
        // Reset the DMA Result Code
        lDMAResultCode = FSLDMA_RC_UNKNOWN;
        // Get Start time before the copy
        pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValStart);
        // Make the DMA Call
        bResult = IfslDMA->CopyMemDMATags(pSourceBuffer,pDestBuffer,lTestSize,
                                          FSLDMA_CM_ResultCode, (uint32)&lDMAResultCode,
                                          TAG_DONE);
        // Calculate and display the elapsed time
        pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValEnd); // Get End time after the copy
        pTimerObj->pITimer->SubTime(&pTimerObj->oTimeValEnd,&pTimerObj->oTimeValStart);

        if ( FALSE == bResult )
        {
          // The DMA transaction failed to start, if a
          // problem *other* than the DMA channels being
          // BUSY, then report the failure and stop here.
          if ( FSLDMA_RC_BUSY != lDMAResultCode )
          {
            // A problem occurred starting the DMA transaction
            printf("        The DMA Transaction of %ld bytes from %p to %p failed to start! A DMA Result Code of [0x%08lx] was returned.\n",lTestSize,pSourceBuffer,pDestBuffer,lDMAResultCode);
            bAbort = TRUE;
            break;
          }
          else
          {
            // If this is just a case of all DMA Channels
            // being busy, then increment the Retry counter
            // and retry the transaction
            printf("        Retrying DMA Transaction of %ld bytes from %p to %p failed to start! A DMA Result Code of [0x%08lx] was returned.\n",lTestSize,pSourceBuffer,pDestBuffer,lDMAResultCode);
            printf("        CopyMemDMA(): Copied %ld bytes from %p to %p",lTestSize,pSourceBuffer,pDestBuffer);
            fflush(stdout);
          }
        }
      } while( FSLDMA_RC_BUSY == lDMAResultCode ); // Retry the transaction if all DMA channels are busy

      if ( FALSE == bAbort )
      {
        if ( TRUE == bVerify )
        {
          printf(" in %ld Seconds and %ld Microseconds. Verifying...",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
        }
        else
        {
          printf(" in %ld Seconds and %ld Microseconds. ",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
          bVerified = TRUE;
        }
        fflush(stdout);

        // If requested verify the result of the copy
        if ( TRUE == bVerify )
        {
          bVerified = verifyIdentical(pSourceBuffer,pDestBuffer,lTestSize);
        }
      }
      else
      {
        // IfslDMA->CopyMemDMA() returned FALSE
        bVerified = FALSE;
      }

      printf("%s\n",(TRUE == bVerified) ? "OK" : " FAILED!");

      // Free the buffers and exit.
      IExec->FreeVec(pDestBuffer);
    }
    else
    {
      // Failed to allocate destination buffer
      printf("Failed to allocated %ld Bytes for the test.\n",lTestSize);
    }
    IExec->FreeVec((APTR)pSourceBuffer);
  }
  else
  {
    // Failed to allocate source buffer
    printf("Failed to allocated %ld Bytes for the test.\n",lTestSize);
  }
}

//
// Test IfslDMA->CopyMemDMATags() with Physical-to-Physical copy
//
void fsldma_CopyMemDMAPhyToPhy_Test(struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint32 lTestSize, uint8 nFillByte, BOOL bVerify)
{
  CONST_APTR pSourceBuffer      = NULL;
  APTR       pDestBuffer        = NULL;
  CONST_APTR pPhysicalSrcBuffer = NULL;
  APTR       pPhysicalDstBuffer = NULL;
  BOOL       bVerified          = TRUE; // Defaults to TRUE

  if ( (NULL == IfslDMA) || (NULL == pTimerObj) || (0 == lTestSize) ) return;

  // Obtain the MMU Interface
  struct ExecBase *ExecBase = (*(struct ExecBase **)4);
  struct MMUIFace *IMMU = (struct MMUIFace *)IExec->GetInterface((struct Library *)ExecBase,"MMU",1,NULL);
  if ( NULL != IMMU )
  {
    // Allocate a block of memory for the source and destination
    pSourceBuffer = IExec->AllocVecTags(lTestSize,
                                        AVT_Type,              MEMF_SHARED,       // Memory is available to All Address spaces
                                        AVT_Contiguous,        TRUE,              // Memory must be a contiguous block, not a scatter/gather table
                                        AVT_Lock,              TRUE,              // Memory must not be swapped out or otherwise be made unavailable
                                        AVT_Alignment,         64,                // Memory must be Aligned to a 64 Byte boundary
                                        AVT_PhysicalAlignment, 64,                // Physical Memory must be Aligned to a 64 Byte boundary
                                        AVT_ClearWithValue,    (uint32)nFillByte, // Fill data with supplied value before returning it
                                        TAG_END);
    if ( NULL != pSourceBuffer )
    {
      pDestBuffer = IExec->AllocVecTags(lTestSize,
                                        AVT_Type,              MEMF_SHARED, // Memory is available to All Address spaces
                                        AVT_Contiguous,        TRUE,        // Memory must be a contiguous block, not a scatter/gather table
                                        AVT_Lock,              TRUE,        // Memory must not be swapped out or otherwise be made unavailable
                                        AVT_Alignment,         64,          // Memory must be Aligned to a 64 Byte boundary
                                        AVT_PhysicalAlignment, 64,          // Physical Memory must be Aligned to a 64 Byte boundary
                                        AVT_ClearWithValue,     0,          // Clear data with (0) before returning it
                                        TAG_END);
      if ( NULL != pDestBuffer )
      {
        // Enter Supervisor Mode
        APTR pUserStack = IExec->SuperState();

        // Flush out any cache for our two buffers
        //IExec->CacheClearE((APTR)pSourceBuffer,lTestSize,CACRF_ClearD);
        //IExec->CacheClearE(pDestBuffer,lTestSize,CACRF_ClearD);

        // Now set the memory attributes to prevent further cache operations
        uint32 lSrcMemAttrs = IMMU->GetMemoryAttrs((APTR)pSourceBuffer,0);
        uint32 lDstMemAttrs = IMMU->GetMemoryAttrs(pDestBuffer,0);
        IMMU->SetMemoryAttrs((APTR)pSourceBuffer,lTestSize,(lSrcMemAttrs | FSLDMA_PHYMEM_ATTRS));
        IMMU->SetMemoryAttrs(pDestBuffer,lTestSize,(lDstMemAttrs | FSLDMA_PHYMEM_ATTRS));

        // Get the Physical addresses for our two buffers
        pPhysicalSrcBuffer = IMMU->GetPhysicalAddress((APTR)pSourceBuffer);
        pPhysicalDstBuffer = IMMU->GetPhysicalAddress(pDestBuffer);

        // Return to User Mode
        if ( NULL != pUserStack ) IExec->UserState(pUserStack);

        // Reset and start the timer
        pTimerObj->oTimeValStart.Seconds      = 0;
        pTimerObj->oTimeValStart.Microseconds = 0;
        pTimerObj->oTimeValEnd.Seconds        = 0;
        pTimerObj->oTimeValEnd.Microseconds   = 0;

        // Capture DMA Result Code
        uint32 lDMAResultCode = FSLDMA_RC_UNKNOWN; // Set the "Unknown" to start
        BOOL   bAbort         = FALSE;
        BOOL   bResult        = FALSE;

        // Call IfslDMA->CopyMemDMATags() to test DMA version using physical memory pointers
        printf("        CopyMemDMA(Physical-to-Physical): Copied %ld bytes from %p to %p",lTestSize,pSourceBuffer,pDestBuffer);
        fflush(stdout);
        do
        {
          // Reset the DMA Result Code
          lDMAResultCode = FSLDMA_RC_UNKNOWN;
          // Get Start time before the copy
          pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValStart);
          // Make the DMA call
          bResult = IfslDMA->CopyMemDMATags(pPhysicalSrcBuffer,pPhysicalDstBuffer,lTestSize,
                                            FSLDMA_CM_SourceIsPhysical,      TRUE,
                                            FSLDMA_CM_DestinationIsPhysical, TRUE,
                                            FSLDMA_CM_ResultCode,            (uint32)&lDMAResultCode,
                                            TAG_DONE);
          // Calculate and display the elapsed time
          pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValEnd); // Get End time after the copy
          pTimerObj->pITimer->SubTime(&pTimerObj->oTimeValEnd,&pTimerObj->oTimeValStart);
          
          if ( FALSE == bResult )
          {
            // The DMA transaction failed to start, if a
            // problem *other* than the DMA channels being
            // BUSY, then report the failure and stop here.
            if ( FSLDMA_RC_BUSY != lDMAResultCode )
            {
              // A problem occurred starting the DMA transaction
              printf("        The DMA Transaction of %ld bytes from 0x%08lx to 0x%08lx failed to start! A DMA Result Code of [0x%08lx] was returned.\n",lTestSize,pPhysicalSrcBuffer,pPhysicalDstBuffer,lDMAResultCode);
              bAbort = TRUE;
              break;
            }
            else
            {
              // If this is just a case of all DMA Channels
              // being busy, then increment the Retry counter
              // and retry the transaction
              printf("        Retrying DMA Transaction of %ld bytes from 0x%08lx to 0x%08lx...\n",lTestSize,pPhysicalSrcBuffer,pPhysicalDstBuffer);
              printf("        CopyMemDMA(Physical-to-Physical): Copied %ld bytes from %p to %p",lTestSize,pSourceBuffer,pDestBuffer);
              fflush(stdout);
            }
          }
        } while( FSLDMA_RC_BUSY == lDMAResultCode ); // Retry the transaction if all DMA channels are busy

        if ( FALSE == bAbort )
        {
          if ( TRUE == bVerify )
          {
            printf(" in %ld Seconds and %ld Microseconds. Verifying...",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
          }
          else
          {
            printf(" in %ld Seconds and %ld Microseconds. ",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
            bVerified = TRUE;
          }
          fflush(stdout);

          // If requested verify the result of the copy
          if ( TRUE == bVerify )
          {
            bVerified = verifyIdentical(pSourceBuffer,pDestBuffer,lTestSize);
          }
        }
        else
        {
          // IfslDMA->CopyMemDMA() returned FALSE
          bVerified = FALSE;
        }

        printf("%s\n",(TRUE == bVerified) ? "OK" : " FAILED!");

        // Free the buffers and exit.
        IExec->FreeVec(pDestBuffer);
      }
      else
      {
        // Failed to allocate destination buffer
        printf("Failed to allocated %ld Bytes for the test.\n",lTestSize);
      }
      IExec->FreeVec((APTR)pSourceBuffer);
    }
    else
    {
      // Failed to allocate source buffer
      printf("Failed to allocated %ld Bytes for the test.\n",lTestSize);
    }
    IExec->DropInterface((struct Interface *)IMMU);
  }
}

//
// Test IfslDMA->CopyMemDMATags() with Physical-to-Virtual copy
//
void fsldma_CopyMemDMAPhyToVirt_Test(struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint32 lTestSize, uint8 nFillByte, BOOL bVerify)
{
  CONST_APTR pSourceBuffer      = NULL;
  APTR       pDestBuffer        = NULL;
  CONST_APTR pPhysicalSrcBuffer = NULL;
  BOOL       bVerified          = TRUE; // Defaults to TRUE

  if ( (NULL == IfslDMA) || (NULL == pTimerObj) || (0 == lTestSize) ) return;

  // Obtain the MMU Interface
  struct ExecBase *ExecBase = (*(struct ExecBase **)4);
  struct MMUIFace *IMMU = (struct MMUIFace *)IExec->GetInterface((struct Library *)ExecBase,"MMU",1,NULL);
  if ( NULL != IMMU )
  {
    // Allocate a block of memory for the source and destination
    pSourceBuffer = IExec->AllocVecTags(lTestSize,
                                        AVT_Type,              MEMF_SHARED,       // Memory is available to All Address spaces
                                        AVT_Contiguous,        TRUE,              // Memory must be a contiguous block, not a scatter/gather table
                                        AVT_Lock,              TRUE,              // Memory must not be swapped out or otherwise be made unavailable
                                        AVT_Alignment,         64,                // Memory must be Aligned to a 64 Byte boundary
                                        AVT_PhysicalAlignment, 64,                // Physical Memory must be Aligned to a 64 Byte boundary
                                        AVT_ClearWithValue,    (uint32)nFillByte, // Fill data with supplied value before returning it
                                        TAG_END);
    if ( NULL != pSourceBuffer )
    {
      pDestBuffer = IExec->AllocVecTags(lTestSize,
                                        AVT_Type,              MEMF_SHARED, // Memory is available to All Address spaces
                                        AVT_ClearWithValue,     0,          // Clear data with (0) before returning it
                                        TAG_END);
      if ( NULL != pDestBuffer )
      {
        // Enter Supervisor Mode
        APTR pUserStack = IExec->SuperState();

        // Now set the memory attributes to prevent further cache operations
        uint32 lSrcMemAttrs = IMMU->GetMemoryAttrs((APTR)pSourceBuffer,0);
        IMMU->SetMemoryAttrs((APTR)pSourceBuffer,lTestSize,(lSrcMemAttrs | FSLDMA_PHYMEM_ATTRS));

        // Get the Physical addresses for our Source buffer
        pPhysicalSrcBuffer = IMMU->GetPhysicalAddress((APTR)pSourceBuffer);

        // Return to User Mode
        if ( NULL != pUserStack ) IExec->UserState(pUserStack);

        printf("        CopyMemDMA(Physical-to-Virtual): Copied %ld bytes from %p to %p",lTestSize,pSourceBuffer,pDestBuffer);
        fflush(stdout);

        // Reset and start the timer
        pTimerObj->oTimeValStart.Seconds      = 0;
        pTimerObj->oTimeValStart.Microseconds = 0;
        pTimerObj->oTimeValEnd.Seconds        = 0;
        pTimerObj->oTimeValEnd.Microseconds   = 0;

        // Call IfslDMA->CopyMemDMATags() to test DMA version
        // using physical memory source and virtual memory destination pointers

        // Capture DMA Result Code
        uint32 lDMAResultCode = FSLDMA_RC_UNKNOWN; // Set the "Unknown" to start
        BOOL   bAbort         = FALSE;
        BOOL   bResult        = FALSE;

        // Call IfslDMA->CopyMemDMATags() to test DMA version
        // using virtual memory source and physical memory destination pointers
        do
        {
          // Reset the DMA Result Code
          lDMAResultCode = FSLDMA_RC_UNKNOWN;
          // Get Start time before the copy
          pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValStart);
          // Make the DMA call
          bResult = IfslDMA->CopyMemDMATags(pPhysicalSrcBuffer,pDestBuffer,lTestSize,
                                            FSLDMA_CM_SourceIsPhysical, TRUE,
                                            FSLDMA_CM_ResultCode,       (uint32)&lDMAResultCode,
                                            TAG_DONE);
          // Calculate and display the elapsed time
          pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValEnd); // Get End time after the copy
          pTimerObj->pITimer->SubTime(&pTimerObj->oTimeValEnd,&pTimerObj->oTimeValStart);
          
          if ( FALSE == bResult )
          {
            // The DMA transaction failed to start, if a
            // problem *other* than the DMA channels being
            // BUSY, then report the failure and stop here.
            if ( FSLDMA_RC_BUSY != lDMAResultCode )
            {
              // A problem occurred starting the DMA transaction
              printf("        The DMA Transaction of %ld bytes from 0x%08lx to %p failed to start! A DMA Result Code of [0x%08lx] was returned.\n",lTestSize,pPhysicalSrcBuffer,pDestBuffer,lDMAResultCode);
              bAbort = TRUE;
              break;
            }
            else
            {
              // If this is just a case of all DMA Channels
              // being busy, then increment the Retry counter
              // and retry the transaction
              printf("        Retrying DMA Transaction of %ld bytes from 0x%08lx to %p...\n",lTestSize,pPhysicalSrcBuffer,pDestBuffer);
              printf("        CopyMemDMA(Physical-to-Virtual): Copied %ld bytes from %p to %p",lTestSize,pSourceBuffer,pDestBuffer);
              fflush(stdout);
            }
          }
        } while( FSLDMA_RC_BUSY == lDMAResultCode ); // Retry the transaction if all DMA channels are busy

        if ( FALSE == bAbort )
        {
          if ( TRUE == bVerify )
          {
            printf(" in %ld Seconds and %ld Microseconds. Verifying...",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
          }
          else
          {
            printf(" in %ld Seconds and %ld Microseconds. ",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
            bVerified = TRUE;
          }
          fflush(stdout);

          // If requested verify the result of the copy
          if ( TRUE == bVerify )
          {
            bVerified = verifyIdentical(pSourceBuffer,pDestBuffer,lTestSize);
          }
        }
        else
        {
          // IfslDMA->CopyMemDMA() returned FALSE
          bVerified = FALSE;
        }

        printf("%s\n",(TRUE == bVerified) ? "OK" : " FAILED!");

        // Free the buffers and exit.
        IExec->FreeVec(pDestBuffer);
      }
      else
      {
        // Failed to allocate destination buffer
        printf("Failed to allocated %ld Bytes for the test.\n",lTestSize);
      }
      IExec->FreeVec((APTR)pSourceBuffer);
    }
    else
    {
      // Failed to allocate source buffer
      printf("Failed to allocated %ld Bytes for the test.\n",lTestSize);
    }
    IExec->DropInterface((struct Interface *)IMMU);
  }
}

//
// Test IfslDMA->CopyMemDMATags() with Virtual-to-Physical copy
//
void fsldma_CopyMemDMAVirtToPhy_Test(struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint32 lTestSize, uint8 nFillByte, BOOL bVerify)
{
  CONST_APTR pSourceBuffer      = NULL;
  APTR       pDestBuffer        = NULL;
  APTR       pPhysicalDstBuffer = NULL;
  BOOL       bVerified          = TRUE; // Defaults to TRUE

  if ( (NULL == IfslDMA) || (NULL == pTimerObj) || (0 == lTestSize) ) return;

  // Obtain the MMU Interface
  struct ExecBase *ExecBase = (*(struct ExecBase **)4);
  struct MMUIFace *IMMU = (struct MMUIFace *)IExec->GetInterface((struct Library *)ExecBase,"MMU",1,NULL);
  if ( NULL != IMMU )
  {
    // Allocate a block of memory for the source and destination
    pSourceBuffer = IExec->AllocVecTags(lTestSize,
                                        AVT_Type,              MEMF_SHARED,       // Memory is available to All Address spaces
                                        AVT_ClearWithValue,    (uint32)nFillByte, // Fill data with supplied value before returning it
                                        TAG_END);
    if ( NULL != pSourceBuffer )
    {
      pDestBuffer = IExec->AllocVecTags(lTestSize,
                                        AVT_Type,              MEMF_SHARED, // Memory is available to All Address spaces
                                        AVT_Contiguous,        TRUE,        // Memory must be a contiguous block, not a scatter/gather table
                                        AVT_Lock,              TRUE,        // Memory must not be swapped out or otherwise be made unavailable
                                        AVT_Alignment,         64,          // Memory must be Aligned to a 64 Byte boundary
                                        AVT_PhysicalAlignment, 64,          // Physical Memory must be Aligned to a 64 Byte boundary
                                        AVT_ClearWithValue,     0,          // Clear data with (0) before returning it
                                        TAG_END);
      if ( NULL != pDestBuffer )
      {
        // Enter Supervisor Mode
        APTR pUserStack = IExec->SuperState();

        // Flush out any cache for our Destination buffer
        //IExec->CacheClearE(pDestBuffer,lTestSize,CACRF_ClearD);

        // Now set the memory attributes to prevent further cache operations
        uint32 lDstMemAttrs = IMMU->GetMemoryAttrs(pDestBuffer,0);
        IMMU->SetMemoryAttrs(pDestBuffer,lTestSize,(lDstMemAttrs | FSLDMA_PHYMEM_ATTRS));

        // Get the Physical addresses for our Destination buffer
        pPhysicalDstBuffer = IMMU->GetPhysicalAddress(pDestBuffer);

        // Return to User Mode
        if ( NULL != pUserStack ) IExec->UserState(pUserStack);

        // Reset and start the timer
        pTimerObj->oTimeValStart.Seconds      = 0;
        pTimerObj->oTimeValStart.Microseconds = 0;
        pTimerObj->oTimeValEnd.Seconds        = 0;
        pTimerObj->oTimeValEnd.Microseconds   = 0;

        // Capture DMA Result Code
        uint32 lDMAResultCode = FSLDMA_RC_UNKNOWN; // Set the "Unknown" to start
        BOOL   bAbort         = FALSE;
        BOOL   bResult        = FALSE;

        // Call IfslDMA->CopyMemDMATags() to test DMA version
        // using virtual memory source and physical memory destination pointers
        printf("        CopyMemDMA(Virtual-to-Physical): Copied %ld bytes from %p to %p",lTestSize,pSourceBuffer,pDestBuffer);
        fflush(stdout);
        do
        {
          // Reset the DMA Result Code
          lDMAResultCode = FSLDMA_RC_UNKNOWN;
          // Get Start time before the copy
          pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValStart);
          // Make the DMA Call
          bResult = IfslDMA->CopyMemDMATags(pSourceBuffer,pPhysicalDstBuffer,lTestSize,
                                            FSLDMA_CM_DestinationIsPhysical, TRUE,
                                            FSLDMA_CM_ResultCode,            (uint32)&lDMAResultCode,
                                            TAG_DONE);
          // Calculate and display the elapsed time
          pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValEnd); // Get End time after the copy
          pTimerObj->pITimer->SubTime(&pTimerObj->oTimeValEnd,&pTimerObj->oTimeValStart);

          if ( FALSE == bResult )
          {
            // The DMA transaction failed to start, if a
            // problem *other* than the DMA channels being
            // BUSY, then report the failure and stop here.
            if ( FSLDMA_RC_BUSY != lDMAResultCode )
            {
              // A problem occurred starting the DMA transaction
              printf("        The DMA Transaction of %ld bytes from %p to 0x%08lx failed to start! A DMA Result Code of [0x%08lx] was returned.\n",lTestSize,pSourceBuffer,pPhysicalDstBuffer,lDMAResultCode);
              bAbort = TRUE;
              break;
            }
            else
            {
              // If this is just a case of all DMA Channels
              // being busy, then increment the Retry counter
              // and retry the transaction
              printf("        Retrying DMA Transaction of %ld bytes from %p to 0x%08lx...\n",lTestSize,pSourceBuffer,pPhysicalDstBuffer);
              printf("        CopyMemDMA(Virtual-to-Physical): Copied %ld bytes from %p to %p",lTestSize,pSourceBuffer,pDestBuffer);
              fflush(stdout);
            }
          }
        } while( FSLDMA_RC_BUSY == lDMAResultCode ); // Retry the transaction if all DMA channels are busy

        if ( FALSE == bAbort )
        {
          if ( TRUE == bVerify )
          {
            printf(" in %ld Seconds and %ld Microseconds. Verifying...",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
          }
          else
          {
            printf(" in %ld Seconds and %ld Microseconds. ",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
            bVerified = TRUE;
          }
          fflush(stdout);

          // If Requested verify the result of the copy
          if ( TRUE == bVerify )
          {
            bVerified = verifyIdentical(pSourceBuffer,pDestBuffer,lTestSize);
          }
        }
        else
        {
          // IfslDMA->CopyMemDMA() returned FALSE
          bVerified = FALSE;
        }

        printf("%s\n",(TRUE == bVerified) ? "OK" : " FAILED!");

        // Free the buffers and exit.
        IExec->FreeVec(pDestBuffer);
      }
      else
      {
        // Failed to allocate destination buffer
        printf("Failed to allocated %ld Bytes for the test.\n",lTestSize);
      }
      IExec->FreeVec((APTR)pSourceBuffer);
    }
    else
    {
      // Failed to allocate source buffer
      printf("Failed to allocated %ld Bytes for the test.\n",lTestSize);
    }
    IExec->DropInterface((struct Interface *)IMMU);
  }
}

//
// Test IExec->CopyMem() [always Virtual-to-Virtual]
//
void fsldma_ExecCopyMem_Test(struct TimerObject *pTimerObj, uint32 lTestSize, uint8 nFillByte, BOOL bVerify)
{
  CONST_APTR pSourceBuffer     = NULL;
  APTR       pDestBuffer       = NULL;
  BOOL       bVerified         = TRUE; // Defaults to TRUE

  if ( (NULL == pTimerObj) || (0 == lTestSize) )
    return;

  // Allocate a block of memory for the source and destination
  pSourceBuffer = IExec->AllocVecTags(lTestSize,
    AVT_Type,           MEMF_SHARED,
    AVT_ClearWithValue, (uint32)nFillByte,
    TAG_END);

  if ( NULL != pSourceBuffer )
  {
    pDestBuffer = IExec->AllocVecTags(lTestSize,AVT_Type,MEMF_SHARED,AVT_ClearWithValue,0,TAG_END);
    if ( NULL != pDestBuffer )
    {
      // Reset and start the timer
      pTimerObj->oTimeValStart.Seconds      = 0;
      pTimerObj->oTimeValStart.Microseconds = 0;
      pTimerObj->oTimeValEnd.Seconds        = 0;
      pTimerObj->oTimeValEnd.Microseconds   = 0;

      // Call IExec->CopyMem() to test DMA version using virtual memory pointers
      printf("        IExec->CopyMem(): Copied %ld bytes from 0x%lx to 0x%lx",lTestSize,pSourceBuffer,pDestBuffer);
      fflush(stdout);

      // Get Start time before the copy
      pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValStart);
      // Make the Exec->CopyMem() call
      IExec->CopyMem(pSourceBuffer,pDestBuffer,lTestSize);
      // Calculate and display the elapsed time
      pTimerObj->pITimer->GetSysTime(&pTimerObj->oTimeValEnd); // Get End time after the copy
      pTimerObj->pITimer->SubTime(&pTimerObj->oTimeValEnd,&pTimerObj->oTimeValStart);

      if ( TRUE == bVerify )
      {
        printf(" in %ld Seconds and %ld Microseconds. Verifying...",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
      }
      else
      {
        printf(" in %ld Seconds and %ld Microseconds. ",pTimerObj->oTimeValEnd.Seconds,pTimerObj->oTimeValEnd.Microseconds);
        bVerified = TRUE;
      }
      fflush(stdout);

      // If requested verify the result of the copy
      if ( TRUE == bVerify )
      {
        bVerified = verifyIdentical(pSourceBuffer,pDestBuffer,lTestSize);
      }

      printf("%s\n",(TRUE == bVerified) ? "OK" : " FAILED!");

      // Free the buffers and exit.
      IExec->FreeVec(pDestBuffer);
    }
    else
    {
      // Failed to allocate destination buffer
      printf("Failed to allocated %ld Bytes for the test.\n",lTestSize);
    }
    IExec->FreeVec((APTR)pSourceBuffer);
  }
  else
  {
    // Failed to allocate source buffer
    printf("Failed to allocated %ld Bytes for the test.\n",lTestSize);
  }
}

//
// Test Parallel Execution test
//
void fsldma_Parallel_Test(struct fslDMAIFace *IfslDMA, struct TimerObject *pTimerObj, uint8 nNumberThreads, BOOL bVerify)
{
  BOOL bVerified = TRUE; // Defaults to TRUE

  // Make sure we have good parameters to work with
  if ( (NULL == IfslDMA) || (NULL == pTimerObj) ) return;

  if ( (0 == nNumberThreads) || (nNumberThreads > 8) )
  {
    printf("nNumberThreads = %ld: Setting thread count to 8 (max). Please use a value of 1 to 8.\n",(uint32)nNumberThreads);
    fflush(stdout);
    nNumberThreads = 8;
  }

  // Setup an array of data buffers to use for testing
  CONST_APTR pSourceBuffers[nNumberThreads];
  APTR       pDestBuffers[nNumberThreads];
  CONST_APTR pPhysicalSrcBuffer[nNumberThreads];
  APTR       pPhysicalDstBuffer[nNumberThreads];
  int8       nCompletedSigBits[nNumberThreads];
  int8       nInProgressSigBits[nNumberThreads];
  int8       nErrorSigBits[nNumberThreads];
  uint32     lCompletedSigMasks[nNumberThreads];
  uint32     lInProgressSigMasks[nNumberThreads];
  uint32     lErrorSigMasks[nNumberThreads];
  uint32     lCombinedSignalMasks         = 0;
  uint32     lCombinedProgressSignalMasks = 0;
  uint32     lCombinedErrorSignalMasks    = 0;
  uint32     lAllSigsMask                 = 0;

  // Preprogram a full set of (randomly order) sizes
  // to be used for the tests. The total of all of
  // these sizes should not exceed 512 Megabytes,
  // since we need two buffers of each size and do
  // not want to use more than 1 Gigabyte of RAM
  // for this test (as all buffers may exist at once).
  //
  // Only the first "nNumberThreads" entries are used.
  // Other possible sizes are listed here:
  uint32 lTestSizes[32] = { SIZE_256_MB, SIZE_256_BYTES, SIZE_256_KB, FSLDMA_OPTIMAL_BLKSIZE,
                            SIZE_16_MB,  SIZE_512_KB,    SIZE_8_MB,   SIZE_64_KB,
                            SIZE_8_KB,   SIZE_1_MB,      SIZE_32_KB,  SIZE_3_MB,
                            SIZE_128_KB, SIZE_64_BYTES,  SIZE_16_KB,  SIZE_1_KB,
                            SIZE_384_KB, SIZE_4_MB,      SIZE_4_KB,   SIZE_9_MB,
                            SIZE_640_KB, SIZE_10_MB,     SIZE_6_MB,   SIZE_12_MB,
                            SIZE_2_MB,   SIZE_5_MB,      SIZE_768_KB, SIZE_15_MB,
                            SIZE_960_KB, SIZE_2_KB,      SIZE_7_MB,   SIZE_832_KB };

  // Obtain the MMU Interface
  struct ExecBase *ExecBase = (*(struct ExecBase **)4);
  struct MMUIFace *IMMU = (struct MMUIFace *)IExec->GetInterface((struct Library *)ExecBase,"MMU",1,NULL);
  if ( NULL != IMMU )
  {
    //
    // Allocate all the memory buffers and signals we need for the test
    //
    printf("Allocating buffers and signals for the test...\n");
    fflush(stdout);
    for( int i = 0; i < nNumberThreads; i++ )
    {
      // Allocate the buffers we need for some parallel tests
      pSourceBuffers[i] = IExec->AllocVecTags(lTestSizes[i],
                                              AVT_Type,              MEMF_SHARED, // Memory is available to All Address spaces
                                              AVT_Contiguous,        TRUE,        // Memory must be a contiguous block, not a scatter/gather table
                                              AVT_Lock,              TRUE,        // Memory must not be swapped out or otherwise be made unavailable
                                              AVT_Alignment,         64,          // Memory must be Aligned to a 64 Byte boundary
                                              AVT_PhysicalAlignment, 64,          // Physical Memory must be Aligned to a 64 Byte boundary
                                              AVT_ClearWithValue,    i,           // Fill data with a value before returning it
                                              TAG_END);

      pDestBuffers[i] = IExec->AllocVecTags(lTestSizes[i],
                                            AVT_Type,              MEMF_SHARED, // Memory is available to All Address spaces
                                            AVT_Contiguous,        TRUE,        // Memory must be a contiguous block, not a scatter/gather table
                                            AVT_Lock,              TRUE,        // Memory must not be swapped out or otherwise be made unavailable
                                            AVT_Alignment,         64,          // Memory must be Aligned to a 64 Byte boundary
                                            AVT_PhysicalAlignment, 64,          // Physical Memory must be Aligned to a 64 Byte boundary
                                            AVT_ClearWithValue,    0,           // Fill data with a value before returning it
                                            TAG_END);

      // Enter Supervisor Mode
      APTR pUserStack = IExec->SuperState();

      // Flush out any cache for our two buffers
      //IExec->CacheClearE((APTR)pSourceBuffers[i],lTestSizes[i],CACRF_ClearD);
      //IExec->CacheClearE(pDestBuffers[i],lTestSizes[i],CACRF_ClearD);

      // Now set the memory attributes to prevent further cache operations
      uint32 lSrcMemAttrs = IMMU->GetMemoryAttrs((APTR)pSourceBuffers[i],0);
      uint32 lDstMemAttrs = IMMU->GetMemoryAttrs(pDestBuffers[i],0);
      IMMU->SetMemoryAttrs((APTR)pSourceBuffers[i],lTestSizes[i],(lSrcMemAttrs | FSLDMA_PHYMEM_ATTRS));
      IMMU->SetMemoryAttrs(pDestBuffers[i],lTestSizes[i],(lDstMemAttrs | FSLDMA_PHYMEM_ATTRS));

      // Get the Physical addresses for our two buffers
      pPhysicalSrcBuffer[i] = IMMU->GetPhysicalAddress((APTR)pSourceBuffers[i]);
      pPhysicalDstBuffer[i] = IMMU->GetPhysicalAddress(pDestBuffers[i]);

      // Return to User Mode
      if ( NULL != pUserStack ) IExec->UserState(pUserStack);

      // Allocate signals to wait on
      nCompletedSigBits[i]  = IExec->AllocSignal((int8)-1);
      nInProgressSigBits[i] = IExec->AllocSignal((int8)-1);
      nErrorSigBits[i]      = IExec->AllocSignal((int8)-1);
      // Construct the signal masks we need to Wait() on later.
      // We are trusting that these masks will all be built
      // from properly allocated signals here for now, but
      // we will verify this before using them.
      lCompletedSigMasks[i]  = (uint32)(1L << nCompletedSigBits[i]);
      lInProgressSigMasks[i] = (uint32)(1L << nInProgressSigBits[i]);
      lErrorSigMasks[i]      = (uint32)(1L << nErrorSigBits[i]);
      // Add these mask values together into a combined variable for each set
      lCombinedSignalMasks         |= lCompletedSigMasks[i];
      lCombinedProgressSignalMasks |= lInProgressSigMasks[i];
      lCombinedErrorSignalMasks    |= lErrorSigMasks[i];
    }
    // Combine all the allocated signals to Wait() on
    lAllSigsMask = (lCombinedSignalMasks | lCombinedProgressSignalMasks | lCombinedErrorSignalMasks);

    // Verify we got all the memory and signals
    BOOL bGotResources = TRUE;
    for( int i = 0; i < nNumberThreads; i++ )
    {
      if (  0 == pSourceBuffers[i]     ) bGotResources = FALSE;
      if (  0 == pDestBuffers[i]       ) bGotResources = FALSE;
      if ( -1 == nCompletedSigBits[i]  ) bGotResources = FALSE;
      if ( -1 == nInProgressSigBits[i] ) bGotResources = FALSE;
      if ( -1 == nErrorSigBits[i]      ) bGotResources = FALSE;
      if ( FALSE == bGotResources )
      {
        printf("Unable to allocate all the memory and/or signals needed for this test.\n");
        fflush(stdout);
        break;
      }
    }

    // Obtain the pointer to ourselves (this Task)
    struct Task *pThisTask = IExec->FindTask(NULL);
    if ( (NULL != pThisTask) && (TRUE == bGotResources) )
    {
      // Ready for the parallel execution test

      // Capture DMA Result Code
      uint32 lDMAResultCode = FSLDMA_RC_UNKNOWN; // Set the "Unknown" to start
      BOOL   bAbort         = FALSE;
      
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
        printf("Starting DMA Transaction %ld of %ld bytes from 0x%08lx to 0x%08lx...\n",(uint32)i,lTestSizes[i],pPhysicalSrcBuffer[i],pPhysicalDstBuffer[i]);
        do
        {
          // Reset the DMA Result Code
          lDMAResultCode = FSLDMA_RC_UNKNOWN;        
          if ( FALSE == IfslDMA->CopyMemDMATags(pPhysicalSrcBuffer[i],pPhysicalDstBuffer[i],lTestSizes[i],
                                  FSLDMA_CM_SourceIsPhysical,          TRUE,
                                  FSLDMA_CM_DestinationIsPhysical,     TRUE,
                                  FSLDMA_CM_DoNotWait,                 TRUE,
                                  FSLDMA_CM_NotifyTask,                pThisTask,
                                  FSLDMA_CM_NotifySignalNumber,        nCompletedSigBits[i],
                                  FSLDMA_CM_NotifyProgessSignalNumber, nInProgressSigBits[i],
                                  FSLDMA_CM_NotifyErrorSignalNumber,   nErrorSigBits[i],
                                  FSLDMA_CM_ResultCode,                (uint32)&lDMAResultCode,
                                  TAG_DONE) )
          {
            // The DMA transaction failed to start, if a
            // problem *other* than the DMA channels being
            // BUSY, then report the failure and stop here.
            if ( FSLDMA_RC_BUSY != lDMAResultCode )
            {
              // A problem occurred starting the DMA transaction
              printf("The DMA Transaction %ld of %ld bytes from 0x%08lx to 0x%08lx failed to start! A DMA Result Code of [0x%08lx] was returned.\n",(uint32)i,lTestSizes[i],pPhysicalSrcBuffer[i],pPhysicalDstBuffer[i],lDMAResultCode);
              bAbort = TRUE;
              break;
            }
            else
            {
              // If this is just a case of all DMA Channels
              // being busy, then increment the Retry counter
              // and retry the transaction
              printf("Retrying DMA Transaction %ld of %ld bytes from 0x%08lx to 0x%08lx...\n",(uint32)i,lTestSizes[i],pPhysicalSrcBuffer[i],pPhysicalDstBuffer[i]);
            }
          }
        } while( FSLDMA_RC_BUSY == lDMAResultCode ); // Retry the transaction if all DMA channels are busy
      }

      if ( FALSE == bAbort )
      {
        // Now that we have started all the DMA transactions at once,
        // we need to Wait() on the signals that tell us each transaction
        // has been completed.
        BOOL   bStillRunning = TRUE;
        uint32 lSigReceived  = 0;
        uint32 lNumCompleted = 0;
        do
        {
          // Wait for the DMA completion/status/error signals for all "threads"
          lSigReceived = IExec->Wait( lAllSigsMask | SIGBREAKF_CTRL_C );
  
          // Now see which ones we got this time
          for( int i = 0; i < nNumberThreads; i++ )
          {
            // Check if we got a "In Progress" signal for each "thread"
            if ( lInProgressSigMasks[i] == (lSigReceived & lInProgressSigMasks[i]) )
            {
              printf("DMA Transaction %ld of %ld bytes from 0x%08lx to 0x%08lx is still going...\n",(uint32)i,lTestSizes[i],pPhysicalSrcBuffer[i],pPhysicalDstBuffer[i]);
              fflush(stdout);
            }
  
            // Check if we got a Completion signal for any "thread"
            if ( lCompletedSigMasks[i] == (lSigReceived & lCompletedSigMasks[i]) )
            {
              // If requested verify the result of the copy
              if ( TRUE == bVerify )
              {
                printf("DMA Transaction %ld of %ld bytes from 0x%08lx to 0x%08lx completely successfully. Verifying...",(uint32)i,lTestSizes[i],pPhysicalSrcBuffer[i],pPhysicalDstBuffer[i]);
                fflush(stdout);
                bVerified = verifyIdentical(pSourceBuffers[i],pDestBuffers[i],lTestSizes[i]);
                printf("%s\n",(TRUE == bVerified) ? " OK" : " FAILED!");
              }
              else
              {
                printf("DMA Transaction %ld of %ld bytes from 0x%08lx to 0x%08lx completely successfully.\n",(uint32)i,lTestSizes[i],pPhysicalSrcBuffer[i],pPhysicalDstBuffer[i]);
              }
              lNumCompleted++; // This signal completes a transaction for count it
            }
  
            // Check if we got a Error signal for any "thread"
            if ( lErrorSigMasks[i] == (lSigReceived & lErrorSigMasks[i]) )
            {
              printf("DMA Transaction %ld of %ld bytes from 0x%08lx to 0x%08lx FAILED!\n",(uint32)i,lTestSizes[i],pPhysicalSrcBuffer[i],pPhysicalDstBuffer[i]);
              lNumCompleted++; // This signal completes a transaction for count it
            }
          }
  
          // See if we got a full count of "completed" transactions
          if ( lNumCompleted == nNumberThreads ) bStillRunning = FALSE;
  
          // Finally, check if we got a Break signal from the user
          if ( SIGBREAKF_CTRL_C == (lSigReceived & SIGBREAKF_CTRL_C) )
          {
            bStillRunning = FALSE;
          }
        } while( TRUE == bStillRunning );
      }
    }

    // Make sure we free everything before we leave
    for( int i = 0; i < nNumberThreads; i++ )
    {
      if (  0 != pSourceBuffers[i]     ) IExec->FreeVec((APTR)pSourceBuffers[i]);
      if (  0 != pDestBuffers[i]       ) IExec->FreeVec(pDestBuffers[i]);
      if ( -1 != nCompletedSigBits[i]  ) IExec->FreeSignal(nCompletedSigBits[i]);
      if ( -1 != nInProgressSigBits[i] ) IExec->FreeSignal(nInProgressSigBits[i]);
      if ( -1 != nErrorSigBits[i]      ) IExec->FreeSignal(nErrorSigBits[i]);
    }

    IExec->DropInterface((struct Interface *)IMMU);
  }
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
      // Allocare a IORequest object for our Timer
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
BOOL verifyIdentical(CONST_APTR pBuffer1, APTR pBuffer2, uint32 lTestSize)
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
      for( uint32 i = 0; i < lTestCount; i++ )
      {
        if ( pSrcBuf[i] != pDstBuf[i] )
        {
          printf(" [%llx] != [%llx] ",pSrcBuf[i],pDstBuf[i]);
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
      for( uint32 i = 0; i < lTestCount; i++ )
      {
        if ( pSrcBuf[i] != pDstBuf[i] )
        {
          printf(" [%lx] != [%lx] ",pSrcBuf[i],pDstBuf[i]);
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
      for( uint32 i = 0; i < lTestCount; i++ )
      {
        if ( pSrcBuf[i] != pDstBuf[i] )
        {
          printf(" [%lx] != [%lx] ",(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
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
      for( uint32 i = 0; i < lTestSize; i++ )
      {
        if ( pSrcBuf[i] != pDstBuf[i] )
        {
          printf(" [%lx] != [%lx] ",(uint32)pSrcBuf[i],(uint32)pDstBuf[i]);
          bVerified = FALSE; // Content does not match
          break;
        }
      }
    }
  }
  return( bVerified );
}
