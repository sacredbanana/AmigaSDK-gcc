#ifndef CLIB_INTUITION_PROTOS_H
#define CLIB_INTUITION_PROTOS_H

/*
**	$VER: intuition_protos.h 47.1 (30.11.2021)
**
**	'C' prototypes. For use with 32 bit integers only.
**
**	Copyright (C) 2019-2022 Hyperion Entertainment CVBA.
**	    Developed under license.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef  INTUITION_INTUITIONBASE_H
#include <intuition/intuitionbase.h>
#endif
#ifndef  INTUITION_CLASSES_H
#include <intuition/classes.h>
#endif
#ifndef  INTUITION_CGHOOKS_H
#include <intuition/cghooks.h>
#endif
#ifndef  INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif
/* Public functions  __stdargs OpenIntuition() and  __stdargs Intuition() are intentionally */
/* not documented. */
VOID  __stdargs OpenIntuition( VOID );
VOID  __stdargs Intuition( struct InputEvent *iEvent );
UWORD  __stdargs AddGadget( struct Window *window, struct Gadget *gadget, ULONG position );
BOOL  __stdargs ClearDMRequest( struct Window *window );
VOID  __stdargs ClearMenuStrip( struct Window *window );
VOID  __stdargs ClearPointer( struct Window *window );
BOOL  __stdargs CloseScreen( struct Screen *screen );
VOID  __stdargs CloseWindow( struct Window *window );
LONG  __stdargs CloseWorkBench( VOID );
VOID  __stdargs CurrentTime( ULONG *seconds, ULONG *micros );
BOOL  __stdargs DisplayAlert( ULONG alertNumber, CONST_STRPTR string, ULONG height );
VOID  __stdargs DisplayBeep( struct Screen *screen );
BOOL  __stdargs DoubleClick( ULONG sSeconds, ULONG sMicros, ULONG cSeconds, ULONG cMicros );
VOID  __stdargs DrawBorder( struct RastPort *rp, CONST struct Border *border, LONG leftOffset, LONG topOffset );
VOID  __stdargs DrawImage( struct RastPort *rp, CONST struct Image *image, LONG leftOffset, LONG topOffset );
VOID  __stdargs EndRequest( struct Requester *requester, struct Window *window );
struct Preferences * __stdargs GetDefPrefs( struct Preferences *preferences, LONG size );
struct Preferences * __stdargs GetPrefs( struct Preferences *preferences, LONG size );
VOID  __stdargs InitRequester( struct Requester *requester );
struct MenuItem * __stdargs ItemAddress( CONST struct Menu *menuStrip, ULONG menuNumber );
BOOL  __stdargs ModifyIDCMP( struct Window *window, ULONG flags );
VOID  __stdargs ModifyProp( struct Gadget *gadget, struct Window *window, struct Requester *requester, ULONG flags, ULONG horizPot, ULONG vertPot, ULONG horizBody, ULONG vertBody );
VOID  __stdargs MoveScreen( struct Screen *screen, LONG dx, LONG dy );
VOID  __stdargs MoveWindow( struct Window *window, LONG dx, LONG dy );
VOID  __stdargs OffGadget( struct Gadget *gadget, struct Window *window, struct Requester *requester );
VOID  __stdargs OffMenu( struct Window *window, ULONG menuNumber );
VOID  __stdargs OnGadget( struct Gadget *gadget, struct Window *window, struct Requester *requester );
VOID  __stdargs OnMenu( struct Window *window, ULONG menuNumber );
struct Screen * __stdargs OpenScreen( CONST struct NewScreen *newScreen );
struct Window * __stdargs OpenWindow( CONST struct NewWindow *newWindow );
ULONG  __stdargs OpenWorkBench( VOID );
VOID  __stdargs PrintIText( struct RastPort *rp, CONST struct IntuiText *iText, LONG left, LONG top );
VOID  __stdargs RefreshGadgets( struct Gadget *gadgets, struct Window *window, struct Requester *requester );
UWORD  __stdargs RemoveGadget( struct Window *window, struct Gadget *gadget );
/* The official calling sequence for ReportMouse is given below. */
/* Note the register order.  For the complete story, read the ReportMouse */
/* autodoc. */
VOID  __stdargs ReportMouse( LONG flag, struct Window *window );
VOID  __stdargs ReportMouse1( struct Window *window, LONG flag );
BOOL  __stdargs Request( struct Requester *requester, struct Window *window );
VOID  __stdargs ScreenToBack( struct Screen *screen );
VOID  __stdargs ScreenToFront( struct Screen *screen );
BOOL  __stdargs SetDMRequest( struct Window *window, struct Requester *requester );
BOOL  __stdargs SetMenuStrip( struct Window *window, struct Menu *menu );
VOID  __stdargs SetPointer( struct Window *window, UWORD *pointer, LONG height, LONG width, LONG xOffset, LONG yOffset );
VOID  __stdargs SetWindowTitles( struct Window *window, CONST_STRPTR windowTitle, CONST_STRPTR screenTitle );
VOID  __stdargs ShowTitle( struct Screen *screen, LONG showIt );
VOID  __stdargs SizeWindow( struct Window *window, LONG dx, LONG dy );
struct View * __stdargs ViewAddress( VOID );
struct ViewPort * __stdargs ViewPortAddress( CONST struct Window *window );
VOID  __stdargs WindowToBack( struct Window *window );
VOID  __stdargs WindowToFront( struct Window *window );
BOOL  __stdargs WindowLimits( struct Window *window, LONG widthMin, LONG heightMin, ULONG widthMax, ULONG heightMax );
/*--- start of next generation of names -------------------------------------*/
struct Preferences * __stdargs SetPrefs( CONST struct Preferences *preferences, LONG size, LONG inform );
/*--- start of next next generation of names --------------------------------*/
LONG  __stdargs IntuiTextLength( CONST struct IntuiText *iText );
BOOL  __stdargs WBenchToBack( VOID );
BOOL  __stdargs WBenchToFront( VOID );
/*--- start of next next next generation of names ---------------------------*/
BOOL  __stdargs AutoRequest( struct Window *window, CONST struct IntuiText *body, CONST struct IntuiText *posText, CONST struct IntuiText *negText, ULONG pFlag, ULONG nFlag, ULONG width, ULONG height );
VOID  __stdargs BeginRefresh( struct Window *window );
struct Window * __stdargs BuildSysRequest( struct Window *window, CONST struct IntuiText *body, CONST struct IntuiText *posText, CONST struct IntuiText *negText, ULONG flags, ULONG width, ULONG height );
VOID  __stdargs EndRefresh( struct Window *window, LONG complete );
VOID  __stdargs FreeSysRequest( struct Window *window );
/* The return codes for  __stdargs MakeScreen(),  __stdargs RemakeDisplay(), and  __stdargs RethinkDisplay() */
/* are only valid under V39 and greater.  Do not examine them when running */
/* on pre-V39 systems! */
LONG  __stdargs MakeScreen( struct Screen *screen );
LONG  __stdargs RemakeDisplay( VOID );
LONG  __stdargs RethinkDisplay( VOID );
/*--- start of next next next next generation of names ----------------------*/
APTR  __stdargs AllocRemember( struct Remember **rememberKey, ULONG size, ULONG flags );
/* Public function  __stdargs AlohaWorkbench() is intentionally not documented */
VOID  __stdargs AlohaWorkbench( LONG wbport );
VOID  __stdargs FreeRemember( struct Remember **rememberKey, LONG reallyForget );
/*--- start of 15 Nov 85 names ------------------------*/
ULONG  __stdargs LockIBase( ULONG dontknow );
VOID  __stdargs UnlockIBase( ULONG ibLock );
/*--- functions in V33 or higher (Release 1.2) ---*/
LONG  __stdargs GetScreenData( APTR buffer, ULONG size, ULONG type, CONST struct Screen *screen );
VOID  __stdargs RefreshGList( struct Gadget *gadgets, struct Window *window, struct Requester *requester, LONG numGad );
UWORD  __stdargs AddGList( struct Window *window, struct Gadget *gadget, ULONG position, LONG numGad, struct Requester *requester );
UWORD  __stdargs RemoveGList( struct Window *remPtr, struct Gadget *gadget, LONG numGad );
VOID  __stdargs ActivateWindow( struct Window *window );
VOID  __stdargs RefreshWindowFrame( struct Window *window );
BOOL  __stdargs ActivateGadget( struct Gadget *gadgets, struct Window *window, struct Requester *requester );
VOID  __stdargs NewModifyProp( struct Gadget *gadget, struct Window *window, struct Requester *requester, ULONG flags, ULONG horizPot, ULONG vertPot, ULONG horizBody, ULONG vertBody, LONG numGad );
/*--- functions in V36 or higher (Release 2.0) ---*/
LONG  __stdargs QueryOverscan( ULONG displayID, struct Rectangle *rect, LONG oScanType );
VOID  __stdargs MoveWindowInFrontOf( struct Window *window, struct Window *behindWindow );
VOID  __stdargs ChangeWindowBox( struct Window *window, LONG left, LONG top, LONG width, LONG height );
struct Hook * __stdargs SetEditHook( struct Hook *hook );
LONG  __stdargs SetMouseQueue( struct Window *window, ULONG queueLength );
VOID  __stdargs ZipWindow( struct Window *window );
/*--- public screens ---*/
struct Screen * __stdargs LockPubScreen( CONST_STRPTR name );
VOID  __stdargs UnlockPubScreen( CONST_STRPTR name, struct Screen *screen );
struct List * __stdargs LockPubScreenList( VOID );
VOID  __stdargs UnlockPubScreenList( VOID );
STRPTR  __stdargs NextPubScreen( CONST struct Screen *screen, STRPTR namebuf );
VOID  __stdargs SetDefaultPubScreen( CONST_STRPTR name );
UWORD  __stdargs SetPubScreenModes( ULONG modes );
UWORD  __stdargs PubScreenStatus( struct Screen *screen, ULONG statusFlags );

struct RastPort * __stdargs ObtainGIRPort( struct GadgetInfo *gInfo );
VOID  __stdargs ReleaseGIRPort( struct RastPort *rp );
VOID  __stdargs GadgetMouse( struct Gadget *gadget, struct GadgetInfo *gInfo, WORD *mousePoint );
VOID  __stdargs GetDefaultPubScreen( STRPTR nameBuffer );
LONG  __stdargs EasyRequestArgs( struct Window *window, CONST struct EasyStruct *easyStruct, ULONG *idcmpPtr, CONST_APTR args );
LONG  __stdargs EasyRequest( struct Window *window, CONST struct EasyStruct *easyStruct, ULONG *idcmpPtr, ... );
struct Window * __stdargs BuildEasyRequestArgs( struct Window *window, CONST struct EasyStruct *easyStruct, ULONG idcmp, CONST_APTR args );
struct Window * __stdargs BuildEasyRequest( struct Window *window, CONST struct EasyStruct *easyStruct, ULONG idcmp, ... );
LONG  __stdargs SysReqHandler( struct Window *window, ULONG *idcmpPtr, LONG waitInput );
struct Window * __stdargs OpenWindowTagList( CONST struct NewWindow *newWindow, CONST struct TagItem *tagList );
struct Window * __stdargs OpenWindowTags( CONST struct NewWindow *newWindow, ULONG tag1Type, ... );
struct Screen * __stdargs OpenScreenTagList( CONST struct NewScreen *newScreen, CONST struct TagItem *tagList );
struct Screen * __stdargs OpenScreenTags( CONST struct NewScreen *newScreen, ULONG tag1Type, ... );

/*	new Image functions */
VOID  __stdargs DrawImageState( struct RastPort *rp, CONST struct Image *image, LONG leftOffset, LONG topOffset, ULONG state, struct DrawInfo *drawInfo );
BOOL  __stdargs PointInImage( ULONG point, CONST struct Image *image );
VOID  __stdargs EraseImage( struct RastPort *rp, CONST struct Image *image, LONG leftOffset, LONG topOffset );

APTR  __stdargs NewObjectA( struct IClass *classPtr, CONST_STRPTR classID, CONST struct TagItem *tagList );
APTR  __stdargs NewObject( struct IClass *classPtr, CONST_STRPTR classID, ULONG tag1, ... );

VOID  __stdargs DisposeObject( APTR object );
ULONG  __stdargs SetAttrsA( APTR object, CONST struct TagItem *tagList );
ULONG  __stdargs SetAttrs( APTR object, ULONG tag1, ... );

ULONG  __stdargs GetAttr( ULONG attrID, APTR object, ULONG *storagePtr );

/* 	special set attribute call for gadgets */
ULONG  __stdargs SetGadgetAttrsA( struct Gadget *gadget, struct Window *window, struct Requester *requester, CONST struct TagItem *tagList );
ULONG  __stdargs SetGadgetAttrs( struct Gadget *gadget, struct Window *window, struct Requester *requester, ULONG tag1, ... );

/*	for class implementors only */
APTR  __stdargs NextObject( CONST_APTR objectPtrPtr );
struct IClass * __stdargs MakeClass( CONST_STRPTR classID, CONST_STRPTR superClassID, CONST struct IClass *superClassPtr, ULONG instanceSize, ULONG flags );
VOID  __stdargs AddClass( struct IClass *classPtr );


struct DrawInfo * __stdargs GetScreenDrawInfo( struct Screen *screen );
VOID  __stdargs FreeScreenDrawInfo( struct Screen *screen, struct DrawInfo *drawInfo );

BOOL  __stdargs ResetMenuStrip( struct Window *window, struct Menu *menu );
VOID  __stdargs RemoveClass( struct IClass *classPtr );
BOOL  __stdargs FreeClass( struct IClass *classPtr );
/*--- functions in V39 or higher (Release 3.0) ---*/
struct ScreenBuffer * __stdargs AllocScreenBuffer( struct Screen *sc, struct BitMap *bm, ULONG flags );
VOID  __stdargs FreeScreenBuffer( struct Screen *sc, struct ScreenBuffer *sb );
ULONG  __stdargs ChangeScreenBuffer( struct Screen *sc, struct ScreenBuffer *sb );
VOID  __stdargs ScreenDepth( struct Screen *screen, ULONG flags, APTR reserved );
VOID  __stdargs ScreenPosition( struct Screen *screen, ULONG flags, LONG x1, LONG y1, LONG x2, LONG y2 );
VOID  __stdargs ScrollWindowRaster( struct Window *win, LONG dx, LONG dy, LONG xMin, LONG yMin, LONG xMax, LONG yMax );
VOID  __stdargs LendMenus( struct Window *fromwindow, struct Window *towindow );
ULONG  __stdargs DoGadgetMethodA( struct Gadget *gad, struct Window *win, struct Requester *req, Msg message );
ULONG  __stdargs DoGadgetMethod( struct Gadget *gad, struct Window *win, struct Requester *req, ULONG methodID, ... );
VOID  __stdargs SetWindowPointerA( struct Window *win, CONST struct TagItem *taglist );
VOID  __stdargs SetWindowPointer( struct Window *win, ULONG tag1, ... );
BOOL  __stdargs TimedDisplayAlert( ULONG alertNumber, CONST_STRPTR string, ULONG height, ULONG time );
VOID  __stdargs HelpControl( struct Window *win, ULONG flags );
/*--- functions in V46 or higher (Release 3.1.4) ---*/
BOOL  __stdargs ShowWindow( struct Window *window, struct Window *other );
BOOL  __stdargs HideWindow( struct Window *window );
/*--- functions in V47 or higher (Release 3.2) ---*/
ULONG  __stdargs IntuitionControlA( APTR object, CONST struct TagItem *taglist );
ULONG  __stdargs IntuitionControl( APTR object, ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CLIB_INTUITION_PROTOS_H */
