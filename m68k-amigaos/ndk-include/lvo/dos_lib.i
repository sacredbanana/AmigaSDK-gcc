* Automatically generated header (sfdc 1.11f)! Do not edit!
     IFND  LVO_DOS_LIB_I
LVO_DOS_LIB_I   SET   1

_LVOOpen     EQU   -30
_LVOClose     EQU   -36
_LVORead     EQU   -42
_LVOWrite     EQU   -48
_LVOInput     EQU   -54
_LVOOutput     EQU   -60
_LVOSeek     EQU   -66
_LVODeleteFile     EQU   -72
_LVORename     EQU   -78
_LVOLock     EQU   -84
_LVOUnLock     EQU   -90
_LVODupLock     EQU   -96
_LVOExamine     EQU   -102
_LVOExNext     EQU   -108
_LVOInfo     EQU   -114
_LVOCreateDir     EQU   -120
_LVOCurrentDir     EQU   -126
_LVOIoErr     EQU   -132
_LVOCreateProc     EQU   -138
_LVOExit     EQU   -144
_LVOLoadSeg     EQU   -150
_LVOUnLoadSeg     EQU   -156
_LVODeviceProc     EQU   -174
_LVOSetComment     EQU   -180
_LVOSetProtection     EQU   -186
_LVODateStamp     EQU   -192
_LVODelay     EQU   -198
_LVOWaitForChar     EQU   -204
_LVOParentDir     EQU   -210
_LVOIsInteractive     EQU   -216
_LVOExecute     EQU   -222
_LVOAllocDosObject     EQU   -228
_LVOAllocDosObjectTagList     EQU   -228
_LVOFreeDosObject     EQU   -234
_LVODoPkt     EQU   -240
_LVODoPkt0     EQU   -240
_LVODoPkt1     EQU   -240
_LVODoPkt2     EQU   -240
_LVODoPkt3     EQU   -240
_LVODoPkt4     EQU   -240
_LVOSendPkt     EQU   -246
_LVOWaitPkt     EQU   -252
_LVOReplyPkt     EQU   -258
_LVOAbortPkt     EQU   -264
_LVOLockRecord     EQU   -270
_LVOLockRecords     EQU   -276
_LVOUnLockRecord     EQU   -282
_LVOUnLockRecords     EQU   -288
_LVOSelectInput     EQU   -294
_LVOSelectOutput     EQU   -300
_LVOFGetC     EQU   -306
_LVOFPutC     EQU   -312
_LVOUnGetC     EQU   -318
_LVOFRead     EQU   -324
_LVOFWrite     EQU   -330
_LVOFGets     EQU   -336
_LVOFPuts     EQU   -342
_LVOVFWritef     EQU   -348
_LVOVFPrintf     EQU   -354
_LVOFlush     EQU   -360
_LVOSetVBuf     EQU   -366
_LVODupLockFromFH     EQU   -372
_LVOOpenFromLock     EQU   -378
_LVOParentOfFH     EQU   -384
_LVOExamineFH     EQU   -390
_LVOSetFileDate     EQU   -396
_LVONameFromLock     EQU   -402
_LVONameFromFH     EQU   -408
_LVOSplitName     EQU   -414
_LVOSameLock     EQU   -420
_LVOSetMode     EQU   -426
_LVOExAll     EQU   -432
_LVOReadLink     EQU   -438
_LVOMakeLink     EQU   -444
_LVOChangeMode     EQU   -450
_LVOSetFileSize     EQU   -456
_LVOSetIoErr     EQU   -462
_LVOFault     EQU   -468
_LVOPrintFault     EQU   -474
_LVOErrorReport     EQU   -480
_LVOCli     EQU   -492
_LVOCreateNewProc     EQU   -498
_LVOCreateNewProcTagList     EQU   -498
_LVORunCommand     EQU   -504
_LVOGetConsoleTask     EQU   -510
_LVOSetConsoleTask     EQU   -516
_LVOGetFileSysTask     EQU   -522
_LVOSetFileSysTask     EQU   -528
_LVOGetArgStr     EQU   -534
_LVOSetArgStr     EQU   -540
_LVOFindCliProc     EQU   -546
_LVOMaxCli     EQU   -552
_LVOSetCurrentDirName     EQU   -558
_LVOGetCurrentDirName     EQU   -564
_LVOSetProgramName     EQU   -570
_LVOGetProgramName     EQU   -576
_LVOSetPrompt     EQU   -582
_LVOGetPrompt     EQU   -588
_LVOSetProgramDir     EQU   -594
_LVOGetProgramDir     EQU   -600
_LVOSystemTagList     EQU   -606
_LVOSystem     EQU   -606
_LVOAssignLock     EQU   -612
_LVOAssignLate     EQU   -618
_LVOAssignPath     EQU   -624
_LVOAssignAdd     EQU   -630
_LVORemAssignList     EQU   -636
_LVOGetDeviceProc     EQU   -642
_LVOFreeDeviceProc     EQU   -648
_LVOLockDosList     EQU   -654
_LVOUnLockDosList     EQU   -660
_LVOAttemptLockDosList     EQU   -666
_LVORemDosEntry     EQU   -672
_LVOAddDosEntry     EQU   -678
_LVOFindDosEntry     EQU   -684
_LVONextDosEntry     EQU   -690
_LVOMakeDosEntry     EQU   -696
_LVOFreeDosEntry     EQU   -702
_LVOIsFileSystem     EQU   -708
_LVOFormat     EQU   -714
_LVORelabel     EQU   -720
_LVOInhibit     EQU   -726
_LVOAddBuffers     EQU   -732
_LVOCompareDates     EQU   -738
_LVODateToStr     EQU   -744
_LVOStrToDate     EQU   -750
_LVOInternalLoadSeg     EQU   -756
_LVOInternalUnLoadSeg     EQU   -762
_LVONewLoadSeg     EQU   -768
_LVONewLoadSegTagList     EQU   -768
_LVOAddSegment     EQU   -774
_LVOFindSegment     EQU   -780
_LVORemSegment     EQU   -786
_LVOCheckSignal     EQU   -792
_LVOReadArgs     EQU   -798
_LVOFindArg     EQU   -804
_LVOReadItem     EQU   -810
_LVOStrToLong     EQU   -816
_LVOMatchFirst     EQU   -822
_LVOMatchNext     EQU   -828
_LVOMatchEnd     EQU   -834
_LVOParsePattern     EQU   -840
_LVOMatchPattern     EQU   -846
_LVOFreeArgs     EQU   -858
_LVOFilePart     EQU   -870
_LVOPathPart     EQU   -876
_LVOAddPart     EQU   -882
_LVOStartNotify     EQU   -888
_LVOEndNotify     EQU   -894
_LVOSetVar     EQU   -900
_LVOGetVar     EQU   -906
_LVODeleteVar     EQU   -912
_LVOFindVar     EQU   -918
_LVOCliInitNewcli     EQU   -930
_LVOCliInitRun     EQU   -936
_LVOWriteChars     EQU   -942
_LVOPutStr     EQU   -948
_LVOVPrintf     EQU   -954
_LVOParsePatternNoCase     EQU   -966
_LVOMatchPatternNoCase     EQU   -972
_LVOSameDevice     EQU   -984
_LVOExAllEnd     EQU   -990
_LVOSetOwner     EQU   -996
_LVOVolumeRequestHook     EQU   -1014
_LVOGetCurrentDir     EQU   -1026
_LVOPutErrStr     EQU   -1128
_LVOErrorOutput     EQU   -1134
_LVOSelectError     EQU   -1140
_LVODoShellMethodTagList     EQU   -1152
_LVOScanStackToken     EQU   -1158

     ENDC  * LVO_DOS_LIB_I