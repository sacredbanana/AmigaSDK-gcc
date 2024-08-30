/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_WB_H
#define _PPCINLINE_WB_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef WB_BASE_NAME
#define WB_BASE_NAME WorkbenchBase
#endif /* !WB_BASE_NAME */

#define RemoveAppMenuItem(__p0) \
	LP1(78, BOOL , RemoveAppMenuItem, \
		struct AppMenuItem *, __p0, a0, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateDrawerA(__p0, __p1) \
	(((BOOL (*)(CONST_STRPTR , const struct TagItem *, void *))*(void**)((long)(WB_BASE_NAME) - 154))(__p0, __p1, (void*)(WB_BASE_NAME)))

#define OpenWorkbenchObjectA(__p0, __p1) \
	LP2(96, BOOL , OpenWorkbenchObjectA, \
		STRPTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AppWindowRelease() \
	(((VOID (*)(void *))*(void**)((long)(WB_BASE_NAME) - 142))((void*)(WB_BASE_NAME)))

#define AppWindowObtain(__p0) \
	(((struct AppWindow *(*)(struct Window *, void *))*(void**)((long)(WB_BASE_NAME) - 136))(__p0, (void*)(WB_BASE_NAME)))

#define AddAppMenuItemA(__p0, __p1, __p2, __p3, __p4) \
	LP5(72, struct AppMenuItem *, AddAppMenuItemA, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		UBYTE *, __p2, a0, \
		struct MsgPort *, __p3, a1, \
		struct TagItem *, __p4, a2, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ChangeWorkbenchSelectionA(__p0, __p1, __p2) \
	LP3(126, BOOL , ChangeWorkbenchSelectionA, \
		STRPTR , __p0, a0, \
		struct Hook *, __p1, a1, \
		struct TagItem *, __p2, a2, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddAppWindowDropZoneA(__p0, __p1, __p2, __p3) \
	LP4(114, struct AppWindowDropZone *, AddAppWindowDropZoneA, \
		struct AppWindow *, __p0, a0, \
		ULONG , __p1, d0, \
		ULONG , __p2, d1, \
		struct TagItem *, __p3, a1, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemoveAppWindow(__p0) \
	LP1(54, BOOL , RemoveAppWindow, \
		struct AppWindow *, __p0, a0, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WBInfo(__p0, __p1, __p2) \
	LP3NR(90, WBInfo, \
		BPTR , __p0, a0, \
		STRPTR , __p1, a1, \
		struct Screen *, __p2, a2, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define ManageDesktopObjectA(__p0, __p1, __p2) \
	(((BOOL (*)(CONST_STRPTR , LONG , const struct TagItem *, void *))*(void**)((long)(WB_BASE_NAME) - 148))(__p0, __p1, __p2, (void*)(WB_BASE_NAME)))

#define MakeWorkbenchObjectVisibleA(__p0, __p1) \
	LP2(132, BOOL , MakeWorkbenchObjectVisibleA, \
		STRPTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddAppIconA(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	LP7(60, struct AppIcon *, AddAppIconA, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		UBYTE *, __p2, a0, \
		struct MsgPort *, __p3, a1, \
		BPTR , __p4, a2, \
		struct DiskObject *, __p5, a3, \
		struct TagItem *, __p6, a4, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define RemoveAppIcon(__p0) \
	LP1(66, BOOL , RemoveAppIcon, \
		struct AppIcon *, __p0, a0, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define WorkbenchControlA(__p0, __p1) \
	LP2(108, BOOL , WorkbenchControlA, \
		STRPTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define AddAppWindowA(__p0, __p1, __p2, __p3, __p4) \
	LP5(48, struct AppWindow *, AddAppWindowA, \
		ULONG , __p0, d0, \
		ULONG , __p1, d1, \
		struct Window *, __p2, a0, \
		struct MsgPort *, __p3, a1, \
		struct TagItem *, __p4, a2, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CloseWorkbenchObjectA(__p0, __p1) \
	LP2(102, BOOL , CloseWorkbenchObjectA, \
		STRPTR , __p0, a0, \
		struct TagItem *, __p1, a1, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#define CreateIconA(__p0, __p1) \
	(((BOOL (*)(CONST_STRPTR , const struct TagItem *, void *))*(void**)((long)(WB_BASE_NAME) - 160))(__p0, __p1, (void*)(WB_BASE_NAME)))

#define RemoveAppWindowDropZone(__p0, __p1) \
	LP2(120, BOOL , RemoveAppWindowDropZone, \
		struct AppWindow *, __p0, a0, \
		struct AppWindowDropZone *, __p1, a1, \
		, WB_BASE_NAME, 0, 0, 0, 0, 0, 0)

#if defined(USE_INLINE_STDARG) && !defined(__STRICT_ANSI__)

#include <stdarg.h>

#define CloseWorkbenchObject(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CloseWorkbenchObjectA(__p0, (struct TagItem *)_tags);})

#define MakeWorkbenchObjectVisible(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	MakeWorkbenchObjectVisibleA(__p0, (struct TagItem *)_tags);})

#define CreateDrawerTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CreateDrawerA(__p0, (const struct TagItem *)_tags);})

#define WorkbenchControl(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	WorkbenchControlA(__p0, (struct TagItem *)_tags);})

#define CreateIconTags(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	CreateIconA(__p0, (const struct TagItem *)_tags);})

#define AddAppWindow(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AddAppWindowA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#define OpenWorkbenchObject(__p0, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	OpenWorkbenchObjectA(__p0, (struct TagItem *)_tags);})

#define AddAppWindowDropZone(__p0, __p1, __p2, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AddAppWindowDropZoneA(__p0, __p1, __p2, (struct TagItem *)_tags);})

#define AddAppMenuItem(__p0, __p1, __p2, __p3, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AddAppMenuItemA(__p0, __p1, __p2, __p3, (struct TagItem *)_tags);})

#define ChangeWorkbenchSelection(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ChangeWorkbenchSelectionA(__p0, __p1, (struct TagItem *)_tags);})

#define ManageDesktopObjectTags(__p0, __p1, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	ManageDesktopObjectA(__p0, __p1, (const struct TagItem *)_tags);})

#define AddAppIcon(__p0, __p1, __p2, __p3, __p4, __p5, ...) \
	({ULONG _tags[] = { __VA_ARGS__ }; \
	AddAppIconA(__p0, __p1, __p2, __p3, __p4, __p5, (struct TagItem *)_tags);})

#endif

#endif /* !_PPCINLINE_WB_H */
