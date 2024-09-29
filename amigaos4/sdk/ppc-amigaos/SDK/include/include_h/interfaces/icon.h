#ifndef ICON_INTERFACE_DEF_H
#define ICON_INTERFACE_DEF_H

/*
** This file was machine generated by idltool 52.6.
** Do not edit
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
#endif

#ifndef WORKBENCH_WORKBENCH_H
#include <workbench/workbench.h>
#endif
#ifndef DATATYPES_PICTURECLASS_H
#include <datatypes/pictureclass.h>
#endif

#ifdef __cplusplus
#ifdef __USE_AMIGAOS_NAMESPACE__
namespace AmigaOS {
#endif
extern "C" {
#endif

struct IconIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct IconIFace *Self);
	ULONG APICALL (*Release)(struct IconIFace *Self);
	void APICALL (*Expunge)(struct IconIFace *Self);
	struct Interface * APICALL (*Clone)(struct IconIFace *Self);
	APTR Private1;
	APTR Private2;
	APTR Private3;
	APTR Private4;
	VOID APICALL (*FreeFreeList)(struct IconIFace *Self, struct FreeList * freelist);
	APTR Private5;
	APTR Private6;
	BOOL APICALL (*AddFreeList)(struct IconIFace *Self, struct FreeList * freelist, CONST_APTR mem, ULONG size);
	struct DiskObject * APICALL (*GetDiskObject)(struct IconIFace *Self, CONST_STRPTR name);
	BOOL APICALL (*PutDiskObject)(struct IconIFace *Self, CONST_STRPTR name, CONST struct DiskObject * diskobj);
	VOID APICALL (*FreeDiskObject)(struct IconIFace *Self, struct DiskObject * diskobj);
	STRPTR APICALL (*FindToolType)(struct IconIFace *Self, STRPTR * toolTypeArray, CONST_STRPTR typeName);
	BOOL APICALL (*MatchToolValue)(struct IconIFace *Self, CONST_STRPTR typeString, CONST_STRPTR value);
	STRPTR APICALL (*BumpRevision)(struct IconIFace *Self, STRPTR newname, CONST_STRPTR oldname);
	APTR APICALL (*FreeAlloc)(struct IconIFace *Self, struct FreeList * freelist, ULONG len, ULONG type);
	struct DiskObject * APICALL (*GetDefDiskObject)(struct IconIFace *Self, LONG type);
	BOOL APICALL (*PutDefDiskObject)(struct IconIFace *Self, CONST struct DiskObject * diskObject);
	struct DiskObject * APICALL (*GetDiskObjectNew)(struct IconIFace *Self, CONST_STRPTR name);
	BOOL APICALL (*DeleteDiskObject)(struct IconIFace *Self, CONST_STRPTR name);
	BOOL APICALL (*FreeFree)(struct IconIFace *Self, struct FreeList * fl, APTR address);
	struct DiskObject * APICALL (*DupDiskObjectA)(struct IconIFace *Self, CONST struct DiskObject * diskObject, CONST struct TagItem * tags);
	struct DiskObject * APICALL (*DupDiskObject)(struct IconIFace *Self, CONST struct DiskObject * diskObject, ...);
	ULONG APICALL (*IconControlA)(struct IconIFace *Self, struct DiskObject * icon, CONST struct TagItem * tags);
	ULONG APICALL (*IconControl)(struct IconIFace *Self, struct DiskObject * icon, ...);
	VOID APICALL (*DrawIconStateA)(struct IconIFace *Self, struct RastPort * rp, CONST struct DiskObject * icon, CONST_STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, CONST struct TagItem * tags);
	VOID APICALL (*DrawIconState)(struct IconIFace *Self, struct RastPort * rp, CONST struct DiskObject * icon, CONST_STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, ...);
	BOOL APICALL (*GetIconRectangleA)(struct IconIFace *Self, struct RastPort * rp, CONST struct DiskObject * icon, CONST_STRPTR label, struct Rectangle * rect, CONST struct TagItem * tags);
	BOOL APICALL (*GetIconRectangle)(struct IconIFace *Self, struct RastPort * rp, CONST struct DiskObject * icon, CONST_STRPTR label, struct Rectangle * rect, ...);
	struct DiskObject * APICALL (*NewDiskObject)(struct IconIFace *Self, LONG type);
	struct DiskObject * APICALL (*GetIconTagList)(struct IconIFace *Self, CONST_STRPTR name, CONST struct TagItem * tags);
	struct DiskObject * APICALL (*GetIconTags)(struct IconIFace *Self, CONST_STRPTR name, ...);
	BOOL APICALL (*PutIconTagList)(struct IconIFace *Self, CONST_STRPTR name, CONST struct DiskObject * icon, CONST struct TagItem * tags);
	BOOL APICALL (*PutIconTags)(struct IconIFace *Self, CONST_STRPTR name, CONST struct DiskObject * icon, ...);
	BOOL APICALL (*LayoutIconA)(struct IconIFace *Self, struct DiskObject * icon, struct Screen * screen, CONST struct TagItem * tags);
	BOOL APICALL (*LayoutIcon)(struct IconIFace *Self, struct DiskObject * icon, struct Screen * screen, ...);
	VOID APICALL (*ChangeToSelectedIconColor)(struct IconIFace *Self, struct ColorRegister * cr);
	STRPTR APICALL (*BumpRevisionLength)(struct IconIFace *Self, STRPTR newname, CONST_STRPTR oldname, uint32 maxlength);
};

#ifdef __cplusplus
}
#ifdef __USE_AMIGAOS_NAMESPACE__
}
#endif
#endif

#endif /* ICON_INTERFACE_DEF_H */