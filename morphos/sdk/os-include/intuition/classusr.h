#ifndef INTUITION_CLASSUSR_H
#define INTUITION_CLASSUSR_H

/*
	intuition class user definitions

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#pragma pack(2)

/*
	NOTE: Please note that in order to allow Objective-C compatibility, we
	had to rename Object to Boopsiobject in our includes. When not building
	in Obj-C mode, Boopsiobject gets typedef'ed to Object for backwards
	compatibility with C sources.
*/

typedef ULONG Boopsiobject;

#if !defined(__OBJC__) 
typedef Boopsiobject Object;
#endif

typedef UBYTE *ClassID;

typedef struct _Msg_
{
	ULONG MethodID;
} *Msg;


#define ROOTCLASS      "rootclass"
#define IMAGECLASS     "imageclass"
#define FRAMEICLASS    "frameiclass"
#define SYSICLASS      "sysiclass"
#define FILLRECTCLASS  "fillrectclass"
#define GADGETCLASS    "gadgetclass"
#define PROPGCLASS     "propgclass"
#define STRGCLASS      "strgclass"
#define BUTTONGCLASS   "buttongclass"
#define FRBUTTONCLASS  "frbuttonclass"
#define GROUPGCLASS    "groupgclass"
#define ICCLASS        "icclass"
#define MODELCLASS     "modelclass"
#define ITEXTICLASS    "itexticlass"
#define POINTERCLASS   "pointerclass"


#define OM_Dummy      (0x100)
#define OM_NEW        (OM_Dummy + 1)
#define OM_DISPOSE    (OM_Dummy + 2)
#define OM_SET        (OM_Dummy + 3)
#define OM_GET        (OM_Dummy + 4)
#define OM_ADDTAIL    (OM_Dummy + 5)
#define OM_REMOVE     (OM_Dummy + 6)
#define OM_NOTIFY     (OM_Dummy + 7)
#define OM_UPDATE     (OM_Dummy + 8)
#define OM_ADDMEMBER  (OM_Dummy + 9)
#define OM_REMMEMBER  (OM_Dummy + 10)

/* This increases the BOOPSI object's usage counter. If you create a new object,
** and send it an OM_RETAIN, you will need to call OM_RELEASE (or OM_DISPOSE!)
** twice for the object to be disposed. This implies that OM_DISPOSE and
** OM_RELEASE are interchangeable.
** NOTE: the same rules apply to MUI objects - they accept OM_RETAIN/OM_RELEASE
** and MUI_DisposeObject is interchangeable with an OM_RETAIN
*/
#define OM_RETAIN     (OM_Dummy + 11)
#define OM_RELEASE    (OM_Dummy + 12)


struct opSet
{
	ULONG              MethodID;
	struct TagItem    *ops_AttrList;
	struct GadgetInfo *ops_GInfo;
};

struct opUpdate
{
	ULONG              MethodID;
	struct TagItem    *opu_AttrList;
	struct GadgetInfo *opu_GInfo;
	ULONG              opu_Flags;
};

#define OPUF_INTERIM  (1<<0)

struct opGet
{
	ULONG  MethodID;
	ULONG  opg_AttrID;
	ULONG *opg_Storage;
};

struct opAddTail
{
	ULONG        MethodID;
	struct List *opat_List;
};

struct opMember
{
	ULONG         MethodID;
	Boopsiobject *opam_Object;
};


#define opAddMember  opMember


#pragma pack()

#endif /* INTUITION_CLASSUSR_H */
