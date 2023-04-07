#ifndef PRAGMAS_INTUITION_PRAGMAS_H
#define PRAGMAS_INTUITION_PRAGMAS_H

/*
**	$VER: intuition_pragmas.h 47.1 (30.11.2021)
**
**	Lattice 'C', Aztec 'C', SAS/C and DICE format pragma files.
*/

#ifndef CLIB_INTUITION_PROTOS_H
#include <clib/intuition_protos.h>
#endif /* CLIB_INTUITION_PROTOS_H */

/* "intuition.library" */
/* Public functions OpenIntuition() and Intuition() are intentionally */
/* not documented. */
#pragma libcall IntuitionBase OpenIntuition 1e 00
#pragma libcall IntuitionBase Intuition 24 801
#pragma libcall IntuitionBase AddGadget 2a 09803
#pragma libcall IntuitionBase ClearDMRequest 30 801
#pragma libcall IntuitionBase ClearMenuStrip 36 801
#pragma libcall IntuitionBase ClearPointer 3c 801
#pragma libcall IntuitionBase CloseScreen 42 801
#pragma libcall IntuitionBase CloseWindow 48 801
#pragma libcall IntuitionBase CloseWorkBench 4e 00
#pragma libcall IntuitionBase CurrentTime 54 9802
#pragma libcall IntuitionBase DisplayAlert 5a 18003
#pragma libcall IntuitionBase DisplayBeep 60 801
#pragma libcall IntuitionBase DoubleClick 66 321004
#pragma libcall IntuitionBase DrawBorder 6c 109804
#pragma libcall IntuitionBase DrawImage 72 109804
#pragma libcall IntuitionBase EndRequest 78 9802
#pragma libcall IntuitionBase GetDefPrefs 7e 0802
#pragma libcall IntuitionBase GetPrefs 84 0802
#pragma libcall IntuitionBase InitRequester 8a 801
#pragma libcall IntuitionBase ItemAddress 90 0802
#pragma libcall IntuitionBase ModifyIDCMP 96 0802
#pragma libcall IntuitionBase ModifyProp 9c 43210A9808
#pragma libcall IntuitionBase MoveScreen a2 10803
#pragma libcall IntuitionBase MoveWindow a8 10803
#pragma libcall IntuitionBase OffGadget ae A9803
#pragma libcall IntuitionBase OffMenu b4 0802
#pragma libcall IntuitionBase OnGadget ba A9803
#pragma libcall IntuitionBase OnMenu c0 0802
#pragma libcall IntuitionBase OpenScreen c6 801
#pragma libcall IntuitionBase OpenWindow cc 801
#pragma libcall IntuitionBase OpenWorkBench d2 00
#pragma libcall IntuitionBase PrintIText d8 109804
#pragma libcall IntuitionBase RefreshGadgets de A9803
#pragma libcall IntuitionBase RemoveGadget e4 9802
/* The official calling sequence for ReportMouse is given below. */
/* Note the register order.  For the complete story, read the ReportMouse */
/* autodoc. */
#pragma libcall IntuitionBase ReportMouse ea 8002
#pragma libcall IntuitionBase ReportMouse1 ea 0802
#pragma libcall IntuitionBase Request f0 9802
#pragma libcall IntuitionBase ScreenToBack f6 801
#pragma libcall IntuitionBase ScreenToFront fc 801
#pragma libcall IntuitionBase SetDMRequest 102 9802
#pragma libcall IntuitionBase SetMenuStrip 108 9802
#pragma libcall IntuitionBase SetPointer 10e 32109806
#pragma libcall IntuitionBase SetWindowTitles 114 A9803
#pragma libcall IntuitionBase ShowTitle 11a 0802
#pragma libcall IntuitionBase SizeWindow 120 10803
#pragma libcall IntuitionBase ViewAddress 126 00
#pragma libcall IntuitionBase ViewPortAddress 12c 801
#pragma libcall IntuitionBase WindowToBack 132 801
#pragma libcall IntuitionBase WindowToFront 138 801
#pragma libcall IntuitionBase WindowLimits 13e 3210805
/*--- start of next generation of names -------------------------------------*/
#pragma libcall IntuitionBase SetPrefs 144 10803
/*--- start of next next generation of names --------------------------------*/
#pragma libcall IntuitionBase IntuiTextLength 14a 801
#pragma libcall IntuitionBase WBenchToBack 150 00
#pragma libcall IntuitionBase WBenchToFront 156 00
/*--- start of next next next generation of names ---------------------------*/
#pragma libcall IntuitionBase AutoRequest 15c 3210BA9808
#pragma libcall IntuitionBase BeginRefresh 162 801
#pragma libcall IntuitionBase BuildSysRequest 168 210BA9807
#pragma libcall IntuitionBase EndRefresh 16e 0802
#pragma libcall IntuitionBase FreeSysRequest 174 801
/* The return codes for MakeScreen(), RemakeDisplay(), and RethinkDisplay() */
/* are only valid under V39 and greater.  Do not examine them when running */
/* on pre-V39 systems! */
#pragma libcall IntuitionBase MakeScreen 17a 801
#pragma libcall IntuitionBase RemakeDisplay 180 00
#pragma libcall IntuitionBase RethinkDisplay 186 00
/*--- start of next next next next generation of names ----------------------*/
#pragma libcall IntuitionBase AllocRemember 18c 10803
/* Public function AlohaWorkbench() is intentionally not documented */
#pragma libcall IntuitionBase AlohaWorkbench 192 801
#pragma libcall IntuitionBase FreeRemember 198 0802
/*--- start of 15 Nov 85 names ------------------------*/
#pragma libcall IntuitionBase LockIBase 19e 001
#pragma libcall IntuitionBase UnlockIBase 1a4 801
/*--- functions in V33 or higher (Release 1.2) ---*/
#pragma libcall IntuitionBase GetScreenData 1aa 910804
#pragma libcall IntuitionBase RefreshGList 1b0 0A9804
#pragma libcall IntuitionBase AddGList 1b6 A109805
#pragma libcall IntuitionBase RemoveGList 1bc 09803
#pragma libcall IntuitionBase ActivateWindow 1c2 801
#pragma libcall IntuitionBase RefreshWindowFrame 1c8 801
#pragma libcall IntuitionBase ActivateGadget 1ce A9803
#pragma libcall IntuitionBase NewModifyProp 1d4 543210A9809
/*--- functions in V36 or higher (Release 2.0) ---*/
#pragma libcall IntuitionBase QueryOverscan 1da 09803
#pragma libcall IntuitionBase MoveWindowInFrontOf 1e0 9802
#pragma libcall IntuitionBase ChangeWindowBox 1e6 3210805
#pragma libcall IntuitionBase SetEditHook 1ec 801
#pragma libcall IntuitionBase SetMouseQueue 1f2 0802
#pragma libcall IntuitionBase ZipWindow 1f8 801
/*--- public screens ---*/
#pragma libcall IntuitionBase LockPubScreen 1fe 801
#pragma libcall IntuitionBase UnlockPubScreen 204 9802
#pragma libcall IntuitionBase LockPubScreenList 20a 00
#pragma libcall IntuitionBase UnlockPubScreenList 210 00
#pragma libcall IntuitionBase NextPubScreen 216 9802
#pragma libcall IntuitionBase SetDefaultPubScreen 21c 801
#pragma libcall IntuitionBase SetPubScreenModes 222 001
#pragma libcall IntuitionBase PubScreenStatus 228 0802

#pragma libcall IntuitionBase ObtainGIRPort 22e 801
#pragma libcall IntuitionBase ReleaseGIRPort 234 801
#pragma libcall IntuitionBase GadgetMouse 23a A9803
/* system private and not to be used by applications: */
#pragma libcall IntuitionBase GetDefaultPubScreen 246 801
#pragma libcall IntuitionBase EasyRequestArgs 24c BA9804
#if defined(__SASC_60)
#pragma tagcall IntuitionBase EasyRequest 24c BA9804
#endif /* __SASC_60 */
#pragma libcall IntuitionBase BuildEasyRequestArgs 252 B09804
#if defined(__SASC_60)
#pragma tagcall IntuitionBase BuildEasyRequest 252 B09804
#endif /* __SASC_60 */
#pragma libcall IntuitionBase SysReqHandler 258 09803
#pragma libcall IntuitionBase OpenWindowTagList 25e 9802
#if defined(__SASC_60)
#pragma tagcall IntuitionBase OpenWindowTags 25e 9802
#endif /* __SASC_60 */
#pragma libcall IntuitionBase OpenScreenTagList 264 9802
#if defined(__SASC_60)
#pragma tagcall IntuitionBase OpenScreenTags 264 9802
#endif /* __SASC_60 */

/*	new Image functions */
#pragma libcall IntuitionBase DrawImageState 26a A2109806
#pragma libcall IntuitionBase PointInImage 270 8002
#pragma libcall IntuitionBase EraseImage 276 109804

#pragma libcall IntuitionBase NewObjectA 27c A9803
#if defined(__SASC_60)
#pragma tagcall IntuitionBase NewObject 27c A9803
#endif /* __SASC_60 */

#pragma libcall IntuitionBase DisposeObject 282 801
#pragma libcall IntuitionBase SetAttrsA 288 9802
#if defined(__SASC_60)
#pragma tagcall IntuitionBase SetAttrs 288 9802
#endif /* __SASC_60 */

#pragma libcall IntuitionBase GetAttr 28e 98003

/* 	special set attribute call for gadgets */
#pragma libcall IntuitionBase SetGadgetAttrsA 294 BA9804
#if defined(__SASC_60)
#pragma tagcall IntuitionBase SetGadgetAttrs 294 BA9804
#endif /* __SASC_60 */

/*	for class implementors only */
#pragma libcall IntuitionBase NextObject 29a 801
#pragma libcall IntuitionBase MakeClass 2a6 10A9805
#pragma libcall IntuitionBase AddClass 2ac 801


#pragma libcall IntuitionBase GetScreenDrawInfo 2b2 801
#pragma libcall IntuitionBase FreeScreenDrawInfo 2b8 9802

#pragma libcall IntuitionBase ResetMenuStrip 2be 9802
#pragma libcall IntuitionBase RemoveClass 2c4 801
#pragma libcall IntuitionBase FreeClass 2ca 801
/* Six spare vectors */
/*--- (6 function slots reserved here) ---*/
/*--- functions in V39 or higher (Release 3.0) ---*/
#pragma libcall IntuitionBase AllocScreenBuffer 300 09803
#pragma libcall IntuitionBase FreeScreenBuffer 306 9802
#pragma libcall IntuitionBase ChangeScreenBuffer 30c 9802
#pragma libcall IntuitionBase ScreenDepth 312 90803
#pragma libcall IntuitionBase ScreenPosition 318 43210806
#pragma libcall IntuitionBase ScrollWindowRaster 31e 543210907
#pragma libcall IntuitionBase LendMenus 324 9802
#pragma libcall IntuitionBase DoGadgetMethodA 32a BA9804
#if defined(__SASC_60)
#pragma tagcall IntuitionBase DoGadgetMethod 32a BA9804
#endif /* __SASC_60 */
#pragma libcall IntuitionBase SetWindowPointerA 330 9802
#if defined(__SASC_60)
#pragma tagcall IntuitionBase SetWindowPointer 330 9802
#endif /* __SASC_60 */
#pragma libcall IntuitionBase TimedDisplayAlert 336 918004
#pragma libcall IntuitionBase HelpControl 33c 0802
/*--- functions in V46 or higher (Release 3.1.4) ---*/
#pragma libcall IntuitionBase ShowWindow 342 9802
#pragma libcall IntuitionBase HideWindow 348 801
/*--- functions in V47 or higher (Release 3.2) ---*/
/*--- (61 function slots reserved here) ---*/
#pragma libcall IntuitionBase IntuitionControlA 4bc 9802
#if defined(__SASC_60)
#pragma tagcall IntuitionBase IntuitionControl 4bc 9802
#endif /* __SASC_60 */

#endif /* PRAGMAS_INTUITION_PRAGMAS_H */
