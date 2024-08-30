#ifndef UTILITY_NAME_H
#define UTILITY_NAME_H

/*
	utility.library namespace defines

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


struct NamedObject
{
	APTR no_Object;
};


#define ANO_NameSpace  4000
#define ANO_UserSpace  4001
#define ANO_Priority   4002
#define ANO_Flags      4003

#define NSB_NODUPS  0
#define NSB_CASE    1

#define NSF_NODUPS  (1<<NSB_NODUPS)
#define NSF_CASE    (1<<NSB_CASE)


#pragma pack()

#endif /* UTILITY_NAME_H */
