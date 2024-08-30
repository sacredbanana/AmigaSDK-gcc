#ifndef INTUITION_CLASSES_H
#define INTUITION_CLASSES_H

/*
	intuition class definitions

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#ifndef UTILITY_HOOKS_H
# include <utility/hooks.h>
#endif

#ifndef INTUITION_CLASSUSR_H
# include <intuition/classusr.h>
#endif

#pragma pack(2)


typedef
struct IClass
{
	struct Hook    cl_Dispatcher;    /* pointer to the class' Dispatcher */
	ULONG          cl_Reserved;      /* must be 0 */
	struct IClass *cl_Super;         /* pointer to the class's Super class, that is the class it inherits from */
	ClassID        cl_ID;

	UWORD          cl_InstOffset;    /* offset and size of the instance data for this class */ 
	UWORD          cl_InstSize;

	ULONG          cl_UserData;      /* class' private data of choice */
	ULONG          cl_SubclassCount; /* number of direct subclasses */
	ULONG          cl_ObjectCount;   /* number of instances */
	ULONG          cl_Flags;
} Boopsiclass;

#if !defined(__OBJC__) 
typedef Boopsiclass Class;
#endif


#define CLF_INLIST  0x00000001L      /* set if the class is in the public class list */

/* returns the instance data for the given class and object */
#define INST_DATA(cl,o)      ((void *)(((UBYTE *)o)+cl->cl_InstOffset))

/* returns the size of instance data */
#define SIZEOF_INSTANCE(cl)  ((cl)->cl_InstOffset+(cl)->cl_InstSize+sizeof(struct _Object))

/* Instance data of the root class, preceeding the object. Might grow from
** the beginning, so the o_Class offset will always stay the same relatively to
** the pointer returned by NewObject() */
struct _Object
{
	struct MinNode  o_Node;        /* do NOT use */
	struct IClass  *o_Class;
};

#define _OBJ(o)           ((struct _Object *)(o))

#define BASEOBJECT(_obj)  ((Boopsiobject *)(_OBJ(_obj)+1))

#define _OBJECT(o)        (_OBJ(o)-1)

#define OCLASS(o)         ((_OBJECT(o))->o_Class)


struct ClassLibrary
{
	struct Library  cl_Lib;
	UWORD           cl_Pad;
	Boopsiclass    *cl_Class;
};


#pragma pack()

#endif /* INTUITION_CLASSES_H */
