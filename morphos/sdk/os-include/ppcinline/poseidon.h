/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_POSEIDON_H
#define _PPCINLINE_POSEIDON_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef POSEIDON_BASE_NAME
#define POSEIDON_BASE_NAME PsdBase
#endif /* !POSEIDON_BASE_NAME */

#define psdAddStringChunk(__p0, __p1, __p2) \
	LP3(522, BOOL , psdAddStringChunk, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		STRPTR , __p2, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdRemClass(__p0) \
	LP1NR(216, psdRemClass, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAllocDevice(__p0) \
	LP1(90, APTR , psdAllocDevice, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAllocRTIsoHandlerA(__p0, __p1) \
	LP2(558, APTR , psdAllocRTIsoHandlerA, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdUnlockDevice(__p0) \
	LP1NR(114, psdUnlockDevice, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdOpenStreamA(__p0, __p1) \
	LP2(432, APTR , psdOpenStreamA, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdWaitPipe(__p0) \
	LP1(180, LONG , psdWaitPipe, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdClaimAppBindingA(__p0) \
	LP1(270, APTR , psdClaimAppBindingA, \
		struct TagItem *, __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdFindEndpointA(__p0, __p1, __p2) \
	LP3(402, APTR , psdFindEndpointA, \
		APTR , __p0, a0, \
		APTR , __p1, a2, \
		struct TagItem *, __p2, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdRemEventHandler(__p0) \
	LP1NR(288, psdRemEventHandler, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAbortPipe(__p0) \
	LP1NR(174, psdAbortPipe, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdRemCfgForm(__p0) \
	LP1(336, BOOL , psdRemCfgForm, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAddEventHandler(__p0, __p1) \
	LP2(282, APTR , psdAddEventHandler, \
		struct MsgPort *, __p0, a1, \
		ULONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdParseCfg() \
	LP0NR(360, psdParseCfg, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdRemCfgChunk(__p0, __p1) \
	LP2(348, BOOL , psdRemCfgChunk, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSaveCfgToDisk(__p0, __p1) \
	LP2(480, BOOL , psdSaveCfgToDisk, \
		STRPTR , __p0, a1, \
		LONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetNextDevice(__p0) \
	LP1(126, APTR , psdGetNextDevice, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdLoadCfgFromDisk(__p0) \
	LP1(474, BOOL , psdLoadCfgFromDisk, \
		STRPTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdLockReadPBase() \
	LP0NR(48, psdLockReadPBase, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSetDeviceConfig(__p0, __p1) \
	LP2(204, BOOL , psdSetDeviceConfig, \
		APTR , __p0, a1, \
		ULONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdFindInterfaceA(__p0, __p1, __p2) \
	LP3(396, APTR , psdFindInterfaceA, \
		APTR , __p0, a0, \
		APTR , __p1, a2, \
		struct TagItem *, __p2, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdEnumerateHardware(__p0) \
	LP1(84, APTR , psdEnumerateHardware, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdLockReadDevice(__p0) \
	LP1NR(102, psdLockReadDevice, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdUnlockPBase() \
	LP0NR(54, psdUnlockPBase, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSendPipe(__p0, __p1, __p2) \
	LP3NR(168, psdSendPipe, \
		APTR , __p0, a1, \
		APTR , __p1, a0, \
		ULONG , __p2, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdUnbindAll() \
	LP0NR(366, psdUnbindAll, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAllocPipe(__p0, __p1, __p2) \
	LP3(144, APTR , psdAllocPipe, \
		APTR , __p0, a0, \
		struct MsgPort *, __p1, a1, \
		APTR , __p2, a2, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdHubReleaseDevBinding(__p0) \
	LP1NR(504, psdHubReleaseDevBinding, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAddErrorMsgA(__p0, __p1, __p2, __p3) \
	LP4(240, APTR , psdAddErrorMsgA, \
		ULONG , __p0, d0, \
		STRPTR , __p1, a0, \
		STRPTR , __p2, a1, \
		APTR , __p3, a2, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdClassScan() \
	LP0NR(222, psdClassScan, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdMatchStringChunk(__p0, __p1, __p2) \
	LP3(528, BOOL , psdMatchStringChunk, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		STRPTR , __p2, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSetAltInterface(__p0, __p1) \
	LP2(258, BOOL , psdSetAltInterface, \
		APTR , __p0, a1, \
		APTR , __p1, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAddClass(__p0, __p1) \
	LP2(210, APTR , psdAddClass, \
		STRPTR , __p0, a1, \
		ULONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdPipeSetup(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(156, psdPipeSetup, \
		APTR , __p0, a1, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		ULONG , __p3, d2, \
		ULONG , __p4, d3, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdStartRTIso(__p0) \
	LP1(570, LONG , psdStartRTIso, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdFreeVec(__p0) \
	LP1NR(36, psdFreeVec, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdFindDescriptorA(__p0, __p1, __p2) \
	LP3(546, APTR , psdFindDescriptorA, \
		APTR , __p0, a0, \
		APTR , __p1, a2, \
		struct TagItem *, __p2, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetPipeActual(__p0) \
	LP1(186, ULONG , psdGetPipeActual, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAddCfgEntry(__p0, __p1) \
	LP2(342, APTR , psdAddCfgEntry, \
		APTR , __p0, a0, \
		APTR , __p1, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSendEvent(__p0, __p1, __p2) \
	LP3NR(294, psdSendEvent, \
		ULONG , __p0, d0, \
		APTR , __p1, a0, \
		APTR , __p2, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdDelayMS(__p0) \
	LP1NR(66, psdDelayMS, \
		ULONG , __p0, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSuspendBindings(__p0) \
	LP1(600, BOOL , psdSuspendBindings, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetClsCfg(__p0) \
	LP1(378, APTR , psdGetClsCfg, \
		STRPTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdDoHubMethodA(__p0, __p1, __p2) \
	LP3(552, APTR , psdDoHubMethodA, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		APTR , __p2, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdRemErrorMsg(__p0) \
	LP1NR(246, psdRemErrorMsg, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetStringDescriptor(__p0, __p1) \
	LP2(198, STRPTR , psdGetStringDescriptor, \
		APTR , __p0, a1, \
		ULONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdEnumerateDevice(__p0) \
	LP1(120, APTR , psdEnumerateDevice, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdStreamWrite(__p0, __p1, __p2) \
	LP3(450, LONG , psdStreamWrite, \
		APTR , __p0, a1, \
		APTR , __p1, a0, \
		LONG , __p2, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdCalculatePower(__p0) \
	LP1NR(468, psdCalculatePower, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdCopyStrFmtA(__p0, __p1) \
	LP2(408, STRPTR , psdCopyStrFmtA, \
		STRPTR , __p0, a0, \
		APTR , __p1, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdReleaseAppBinding(__p0) \
	LP1(276, APTR , psdReleaseAppBinding, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdDebugSemaphores() \
	LP0NR(486, psdDebugSemaphores, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSetClsCfg(__p0, __p1) \
	LP2(372, BOOL , psdSetClsCfg, \
		STRPTR , __p0, a0, \
		APTR , __p1, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdResumeBindings(__p0) \
	LP1(606, BOOL , psdResumeBindings, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdResumeDevice(__p0) \
	LP1(594, BOOL , psdResumeDevice, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdCloseStream(__p0) \
	LP1NR(438, psdCloseStream, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdLockWriteDevice(__p0) \
	LP1NR(108, psdLockWriteDevice, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdFindCfgForm(__p0, __p1) \
	LP2(324, APTR , psdFindCfgForm, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetCfgChunk(__p0, __p1) \
	LP2(354, APTR , psdGetCfgChunk, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAllocVec(__p0) \
	LP1(30, APTR , psdAllocVec, \
		ULONG , __p0, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdHubReleaseIfBinding(__p0) \
	LP1NR(510, psdHubReleaseIfBinding, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdNumToStr(__p0, __p1, __p2) \
	LP3(228, STRPTR , psdNumToStr, \
		ULONG , __p0, d0, \
		LONG , __p1, d1, \
		STRPTR , __p2, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdCheckPipe(__p0) \
	LP1(426, APTR , psdCheckPipe, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdBorrowLocksWait(__p0, __p1) \
	LP2(582, ULONG , psdBorrowLocksWait, \
		struct Task *, __p0, a1, \
		ULONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetForcedBinding(__p0, __p1) \
	LP2(420, STRPTR , psdGetForcedBinding, \
		STRPTR , __p0, a0, \
		STRPTR , __p1, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdStreamFlush(__p0) \
	LP1(456, LONG , psdStreamFlush, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetAttrsA(__p0, __p1, __p2) \
	LP3(132, LONG , psdGetAttrsA, \
		ULONG , __p0, d0, \
		APTR , __p1, a0, \
		struct TagItem *, __p2, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdFreePipe(__p0) \
	LP1(150, APTR , psdFreePipe, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetStringChunk(__p0, __p1) \
	LP2(534, STRPTR , psdGetStringChunk, \
		APTR , __p0, a0, \
		ULONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdFreeRTIsoHandler(__p0) \
	LP1NR(564, psdFreeRTIsoHandler, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdFindDeviceA(__p0, __p1) \
	LP2(264, APTR , psdFindDeviceA, \
		APTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdRemHardware(__p0) \
	LP1NR(78, psdRemHardware, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdCopyStr(__p0) \
	LP1(60, STRPTR , psdCopyStr, \
		STRPTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAddHardware(__p0, __p1) \
	LP2(72, APTR , psdAddHardware, \
		STRPTR , __p0, a0, \
		ULONG , __p1, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdStopRTIso(__p0) \
	LP1(576, LONG , psdStopRTIso, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetPipeError(__p0) \
	LP1(192, LONG , psdGetPipeError, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetUsbDevCfg(__p0, __p1, __p2) \
	LP3(390, APTR , psdGetUsbDevCfg, \
		STRPTR , __p0, a0, \
		STRPTR , __p1, a2, \
		STRPTR , __p2, a3, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSetForcedBinding(__p0, __p1, __p2) \
	LP3(414, BOOL , psdSetForcedBinding, \
		STRPTR , __p0, a2, \
		STRPTR , __p1, a0, \
		STRPTR , __p2, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdHubClassScan(__p0) \
	LP1NR(492, psdHubClassScan, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdWriteCfg(__p0) \
	LP1(318, APTR , psdWriteCfg, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdReleaseDevBinding(__p0) \
	LP1NR(300, psdReleaseDevBinding, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSetAttrsA(__p0, __p1, __p2) \
	LP3(138, LONG , psdSetAttrsA, \
		ULONG , __p0, d0, \
		APTR , __p1, a0, \
		struct TagItem *, __p2, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdLockWritePBase() \
	LP0NR(42, psdLockWritePBase, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdDoPipe(__p0, __p1, __p2) \
	LP3(162, LONG , psdDoPipe, \
		APTR , __p0, a1, \
		APTR , __p1, a0, \
		ULONG , __p2, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdOnlineReport(__p0) \
	LP1(540, STRPTR , psdOnlineReport, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdHubClaimAppBindingA(__p0) \
	LP1(498, APTR , psdHubClaimAppBindingA, \
		struct TagItem *, __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdNextCfgForm(__p0) \
	LP1(330, APTR , psdNextCfgForm, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSafeRawDoFmtA(__p0, __p1, __p2, __p3) \
	LP4NR(252, psdSafeRawDoFmtA, \
		STRPTR , __p0, a0, \
		ULONG , __p1, d0, \
		STRPTR , __p2, a1, \
		APTR , __p3, a2, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSetUsbDevCfg(__p0, __p1, __p2, __p3) \
	LP4(384, BOOL , psdSetUsbDevCfg, \
		STRPTR , __p0, a0, \
		STRPTR , __p1, a2, \
		STRPTR , __p2, a3, \
		APTR , __p3, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSpawnSubTask(__p0, __p1, __p2) \
	LP3(234, struct Task *, psdSpawnSubTask, \
		STRPTR , __p0, a0, \
		APTR , __p1, a1, \
		APTR , __p2, a2, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdStreamRead(__p0, __p1, __p2) \
	LP3(444, LONG , psdStreamRead, \
		APTR , __p0, a1, \
		APTR , __p1, a0, \
		LONG , __p2, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdReleaseIfBinding(__p0) \
	LP1NR(306, psdReleaseIfBinding, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdReadCfg(__p0, __p1) \
	LP2(312, BOOL , psdReadCfg, \
		APTR , __p0, a0, \
		APTR , __p1, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdAllocCfgForm(__p0) \
	LP1(516, APTR , psdAllocCfgForm, \
		ULONG , __p0, d0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdFreeDevice(__p0) \
	LP1NR(96, psdFreeDevice, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdSuspendDevice(__p0) \
	LP1(588, BOOL , psdSuspendDevice, \
		APTR , __p0, a0, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define psdGetStreamError(__p0) \
	LP1(462, LONG , psdGetStreamError, \
		APTR , __p0, a1, \
		, POSEIDON_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define psdSetAttrs(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdSetAttrsA(__p0, __p1, (struct TagItem *)_tags);})

#define psdFindDescriptor(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdFindDescriptorA(__p0, __p1, (struct TagItem *)_tags);})

#define psdFindDevice(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdFindDeviceA(__p0, (struct TagItem *)_tags);})

#define psdAllocRTIsoHandler(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdAllocRTIsoHandlerA(__p0, (struct TagItem *)_tags);})

#define psdOpenStream(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdOpenStreamA(__p0, (struct TagItem *)_tags);})

#define psdClaimAppBinding(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdClaimAppBindingA((struct TagItem *)_tags);})

#define psdFindEndpoint(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdFindEndpointA(__p0, __p1, (struct TagItem *)_tags);})

#define psdFindInterface(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdFindInterfaceA(__p0, __p1, (struct TagItem *)_tags);})

#define psdDoHubMethod(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdDoHubMethodA(__p0, __p1, (APTR )_tags);})

#define psdAddErrorMsg(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdAddErrorMsgA(__p0, __p1, __p2, (APTR )_tags);})

#define psdCopyStrFmt(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdCopyStrFmtA(__p0, (APTR )_tags);})

#define psdSafeRawDoFmt(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdSafeRawDoFmtA(__p0, __p1, __p2, (APTR )_tags);})

#define psdGetAttrs(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	psdGetAttrsA(__p0, __p1, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_POSEIDON_H */
