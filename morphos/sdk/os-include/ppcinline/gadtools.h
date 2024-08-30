/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_GADTOOLS_H
#define _PPCINLINE_GADTOOLS_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef GADTOOLS_BASE_NAME
#define GADTOOLS_BASE_NAME GadToolsBase
#endif /* !GADTOOLS_BASE_NAME */

#define GT_RefreshWindow(__p0, __p1) \
	LP2NR(84, GT_RefreshWindow, \
		struct Window *, __p0, a0, \
		struct Requester *, __p1, a1, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GT_BeginRefresh(__p0) \
	LP1NR(90, GT_BeginRefresh, \
		struct Window *, __p0, a0, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateGadgetA(__p0, __p1, __p2, __p3) \
	LP4(30, struct Gadget *, CreateGadgetA, \
		ULONG , __p0, d0, \
		struct Gadget *, __p1, a0, \
		CONST struct NewGadget *, __p2, a1, \
		CONST struct TagItem *, __p3, a2, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GetVisualInfoA(__p0, __p1) \
	LP2(126, APTR , GetVisualInfoA, \
		struct Screen *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GT_PostFilterIMsg(__p0) \
	LP1(108, struct IntuiMessage *, GT_PostFilterIMsg, \
		struct IntuiMessage *, __p0, a1, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define DrawBevelBoxA(__p0, __p1, __p2, __p3, __p4, __p5) \
	LP6NR(120, DrawBevelBoxA, \
		struct RastPort *, __p0, a0, \
		LONG , __p1, d0, \
		LONG , __p2, d1, \
		LONG , __p3, d2, \
		LONG , __p4, d3, \
		CONST struct TagItem *, __p5, a1, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LayoutMenuItemsA(__p0, __p1, __p2) \
	LP3(60, BOOL , LayoutMenuItemsA, \
		struct MenuItem *, __p0, a0, \
		APTR , __p1, a1, \
		CONST struct TagItem *, __p2, a2, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GT_ReplyIMsg(__p0) \
	LP1NR(78, GT_ReplyIMsg, \
		struct IntuiMessage *, __p0, a1, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define LayoutMenusA(__p0, __p1, __p2) \
	LP3(66, BOOL , LayoutMenusA, \
		struct Menu *, __p0, a0, \
		APTR , __p1, a1, \
		CONST struct TagItem *, __p2, a2, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateContext(__p0) \
	LP1(114, struct Gadget *, CreateContext, \
		struct Gadget **, __p0, a0, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateMenusA(__p0, __p1) \
	LP2(48, struct Menu *, CreateMenusA, \
		CONST struct NewMenu *, __p0, a0, \
		CONST struct TagItem *, __p1, a1, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeGadgets(__p0) \
	LP1NR(36, FreeGadgets, \
		struct Gadget *, __p0, a0, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeMenus(__p0) \
	LP1NR(54, FreeMenus, \
		struct Menu *, __p0, a0, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GT_EndRefresh(__p0, __p1) \
	LP2NR(96, GT_EndRefresh, \
		struct Window *, __p0, a0, \
		LONG , __p1, d0, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define FreeVisualInfo(__p0) \
	LP1NR(132, FreeVisualInfo, \
		APTR , __p0, a0, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GT_GetGadgetAttrsA(__p0, __p1, __p2, __p3) \
	LP4(174, LONG , GT_GetGadgetAttrsA, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		CONST struct TagItem *, __p3, a3, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GT_SetGadgetAttrsA(__p0, __p1, __p2, __p3) \
	LP4NR(42, GT_SetGadgetAttrsA, \
		struct Gadget *, __p0, a0, \
		struct Window *, __p1, a1, \
		struct Requester *, __p2, a2, \
		CONST struct TagItem *, __p3, a3, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GT_GetIMsg(__p0) \
	LP1(72, struct IntuiMessage *, GT_GetIMsg, \
		struct MsgPort *, __p0, a0, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define GT_FilterIMsg(__p0) \
	LP1(102, struct IntuiMessage *, GT_FilterIMsg, \
		CONST struct IntuiMessage *, __p0, a1, \
		, GADTOOLS_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define GT_GetGadgetAttrs(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GT_GetGadgetAttrsA(__p0, __p1, __p2, (CONST struct TagItem *)_tags);})

#define DrawBevelBox(__p0, __p1, __p2, __p3, __p4, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	DrawBevelBoxA(__p0, __p1, __p2, __p3, __p4, (CONST struct TagItem *)_tags);})

#define LayoutMenuItems(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LayoutMenuItemsA(__p0, __p1, (CONST struct TagItem *)_tags);})

#define LayoutMenus(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	LayoutMenusA(__p0, __p1, (CONST struct TagItem *)_tags);})

#define GT_SetGadgetAttrs(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GT_SetGadgetAttrsA(__p0, __p1, __p2, (CONST struct TagItem *)_tags);})

#define CreateMenus(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CreateMenusA(__p0, (CONST struct TagItem *)_tags);})

#define CreateGadget(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CreateGadgetA(__p0, __p1, __p2, (CONST struct TagItem *)_tags);})

#define GetVisualInfo(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	GetVisualInfoA(__p0, (CONST struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_GADTOOLS_H */
