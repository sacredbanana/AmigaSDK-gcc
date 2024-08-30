#ifndef LIBRARIES_MATHLIBRARY_H
#define LIBRARIES_MATHLIBRARY_H

/*
	mathXXX.library include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif

#pragma pack(2)


struct MathIEEEBase
{
	struct Library   MathIEEEBase_LibNode;
	UBYTE            MathIEEEBase_reserved[18];
	LONG           (*MathIEEEBase_TaskOpenLib)(VOID);
	LONG           (*MathIEEEBase_TaskCloseLib)(VOID);
};


#pragma pack()

#endif /* LIBRARIES_MATHLIBRARY_H */
