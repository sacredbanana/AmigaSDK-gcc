/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_GTLAYOUT_H
#define _PPCINLINE_GTLAYOUT_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef GTLAYOUT_BASE_NAME
#define GTLAYOUT_BASE_NAME GTLayoutBase
#endif /* !GTLAYOUT_BASE_NAME */

#define LT_NewLevelWidth(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8NR(258, LT_NewLevelWidth, \
		struct LayoutHandle *, __p0, a0, \
		STRPTR , __p1, a1, \
		APTR , __p2, a2, \
		LONG , __p3, d0, \
		LONG , __p4, d1, \
		LONG *, __p5, a3, \
		LONG *, __p6, d3, \
		LONG , __p7, d2, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_Redraw(__p0, __p1) \
	LP2NR(282, LT_Redraw, \
		struct LayoutHandle *, __p0, a0, \
		LONG , __p1, d0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_EndRefresh(__p0, __p1) \
	LP2NR(72, LT_EndRefresh, \
		struct LayoutHandle *, __p0, a0, \
		LONG , __p1, d0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_LayoutMenusA(__p0, __p1, __p2) \
	LP3(114, struct Menu *, LT_LayoutMenusA, \
		struct LayoutHandle *, __p0, a0, \
		struct NewMenu *, __p1, a1, \
		struct TagItem *, __p2, a2, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_GetAttributesA(__p0, __p1, __p2) \
	LP3(78, LONG , LT_GetAttributesA, \
		struct LayoutHandle *, __p0, a0, \
		LONG , __p1, d0, \
		struct TagItem *, __p2, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_NewA(__p0, __p1) \
	LP2NR(96, LT_NewA, \
		struct LayoutHandle *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_GetIMsg(__p0) \
	LP1(192, struct IntuiMessage *, LT_GetIMsg, \
		struct LayoutHandle *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_BuildA(__p0, __p1) \
	LP2(204, struct Window *, LT_BuildA, \
		struct LayoutHandle *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_Activate(__p0, __p1) \
	LP2NR(174, LT_Activate, \
		struct LayoutHandle *, __p0, a0, \
		LONG , __p1, d0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_LabelChars(__p0, __p1) \
	LP2(144, LONG , LT_LabelChars, \
		struct LayoutHandle *, __p0, a0, \
		STRPTR , __p1, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_SetAttributesA(__p0, __p1, __p2) \
	LP3NR(84, LT_SetAttributesA, \
		struct LayoutHandle *, __p0, a0, \
		LONG , __p1, d0, \
		struct TagItem *, __p2, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_BeginRefresh(__p0) \
	LP1NR(66, LT_BeginRefresh, \
		struct LayoutHandle *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_FindMenuCommand(__p0, __p1, __p2, __p3) \
	LP4(252, struct MenuItem *, LT_FindMenuCommand, \
		struct Menu *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		struct Gadget *, __p3, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_NewMenuTagList(__p0) \
	LP1(234, struct Menu *, LT_NewMenuTagList, \
		struct TagItem *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_CatchUpRefresh(__p0) \
	LP1NR(270, LT_CatchUpRefresh, \
		struct LayoutHandle *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_LevelWidth(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8NR(30, LT_LevelWidth, \
		struct LayoutHandle *, __p0, a0, \
		STRPTR , __p1, a1, \
		APTR , __p2, a2, \
		LONG , __p3, d0, \
		LONG , __p4, d1, \
		LONG *, __p5, a3, \
		LONG *, __p6, a5, \
		LONG , __p7, d2, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_ShowWindow(__p0, __p1) \
	LP2NR(168, LT_ShowWindow, \
		struct LayoutHandle *, __p0, a0, \
		LONG , __p1, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_HandleInput(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(60, LT_HandleInput, \
		struct LayoutHandle *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG *, __p2, a1, \
		UWORD *, __p3, a2, \
		struct Gadget **, __p4, a3, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_DeleteHandle(__p0) \
	LP1NR(36, LT_DeleteHandle, \
		struct LayoutHandle *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_LayoutA(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	LP8(108, struct Window *, LT_LayoutA, \
		struct LayoutHandle *, __p0, a0, \
		STRPTR , __p1, a1, \
		struct IBox *, __p2, a2, \
		LONG , __p3, d0, \
		LONG , __p4, d1, \
		ULONG , __p5, d2, \
		LONG , __p6, d3, \
		struct TagItem *, __p7, a3, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_RebuildTagList(__p0, __p1, __p2) \
	LP3(210, BOOL , LT_RebuildTagList, \
		struct LayoutHandle *, __p0, a0, \
		LONG , __p1, d0, \
		struct TagItem *, __p2, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_CreateHandle(__p0, __p1) \
	LP2(42, struct LayoutHandle *, LT_CreateHandle, \
		struct Screen *, __p0, a0, \
		struct TextAttr *, __p1, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_LockWindow(__p0) \
	LP1NR(150, LT_LockWindow, \
		struct Window *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_GetMenuItem(__p0, __p1) \
	LP2(246, struct MenuItem *, LT_GetMenuItem, \
		struct Menu *, __p0, a0, \
		ULONG , __p1, d0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_EndGroup(__p0) \
	LP1NR(102, LT_EndGroup, \
		struct LayoutHandle *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_UnlockWindow(__p0) \
	LP1NR(156, LT_UnlockWindow, \
		struct Window *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_Rebuild(__p0, __p1, __p2, __p3, __p4) \
	LP5(54, BOOL , LT_Rebuild, \
		struct LayoutHandle *, __p0, a0, \
		struct IBox *, __p1, a1, \
		LONG , __p2, a2, \
		LONG , __p3, d0, \
		LONG , __p4, d1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_PressButton(__p0, __p1) \
	LP2(180, BOOL , LT_PressButton, \
		struct LayoutHandle *, __p0, a0, \
		LONG , __p1, d0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_AddA(__p0, __p1, __p2, __p3, __p4) \
	LP5NR(90, LT_AddA, \
		struct LayoutHandle *, __p0, a0, \
		LONG , __p1, d0, \
		STRPTR , __p2, d1, \
		LONG , __p3, d2, \
		struct TagItem *, __p4, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_DisposeMenu(__p0) \
	LP1NR(222, LT_DisposeMenu, \
		struct Menu *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_UpdateStrings(__p0) \
	LP1NR(216, LT_UpdateStrings, \
		struct LayoutHandle *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_MenuControlTagList(__p0, __p1, __p2) \
	LP3NR(240, LT_MenuControlTagList, \
		struct Window *, __p0, a0, \
		struct Menu *, __p1, a1, \
		struct TagItem *, __p2, a2, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_Refresh(__p0) \
	LP1NR(264, LT_Refresh, \
		struct LayoutHandle *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_GetWindowUserData(__p0, __p1) \
	LP2(276, APTR , LT_GetWindowUserData, \
		struct Window *, __p0, a0, \
		APTR , __p1, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_DeleteWindowLock(__p0) \
	LP1NR(162, LT_DeleteWindowLock, \
		struct Window *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_CreateHandleTagList(__p0, __p1) \
	LP2(48, struct LayoutHandle *, LT_CreateHandleTagList, \
		struct Screen *, __p0, a0, \
		struct TagItem *, __p1, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_GetCode(__p0, __p1, __p2, __p3) \
	LP4(186, LONG , LT_GetCode, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		ULONG , __p2, d2, \
		struct Gadget *, __p3, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_NewMenuTemplate(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6(228, struct Menu *, LT_NewMenuTemplate, \
		struct Screen *, __p0, a0, \
		struct TextAttr *, __p1, a1, \
		struct Image *, __p2, a2, \
		struct Image *, __p3, a3, \
		LONG *, __p4, d0, \
		struct NewMenu *, __p5, d1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_ReplyIMsg(__p0) \
	LP1NR(198, LT_ReplyIMsg, \
		struct IntuiMessage *, __p0, a0, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LT_LabelWidth(__p0, __p1) \
	LP2(138, LONG , LT_LabelWidth, \
		struct LayoutHandle *, __p0, a0, \
		STRPTR , __p1, a1, \
		, GTLAYOUT_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define LT_MenuControlTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_MenuControlTagList(__p0, __p1, (struct TagItem *)_tags);})

#define LT_GetAttributes(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_GetAttributesA(__p0, __p1, (struct TagItem *)_tags);})

#define LT_NewMenuTags(...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_NewMenuTagList((struct TagItem *)_tags);})

#define LT_CreateHandleTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_CreateHandleTagList(__p0, (struct TagItem *)_tags);})

#define LT_SetAttributes(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_SetAttributesA(__p0, __p1, (struct TagItem *)_tags);})

#define LT_RebuildTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_RebuildTagList(__p0, __p1, (struct TagItem *)_tags);})

#define LT_LayoutMenus(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_LayoutMenusA(__p0, __p1, (struct TagItem *)_tags);})

#define LT_Add(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_AddA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#define LT_New(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_NewA(__p0, (struct TagItem *)_tags);})

#define LT_Build(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_BuildA(__p0, (struct TagItem *)_tags);})

#define LT_Layout(__p0, __p1, __p2, __p3, __p4, __p5, __p6, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LT_LayoutA(__p0, __p1, __p2, __p3, __p4, __p5, __p6, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_GTLAYOUT_H */
