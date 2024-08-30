#ifndef RESOURCES_MISC_H
#define RESOURCES_MISC_H

/*
	misc.resource include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef EXEC_LIBRARIES_H
# include <exec/libraries.h>
#endif


#define MR_SERIALPORT    0
#define MR_SERIALBITS    1
#define MR_PARALLELPORT  2
#define MR_PARALLELBITS  3


#define MR_ALLOCMISCRESOURCE  (LIB_BASE)
#define MR_FREEMISCRESOURCE   (LIB_BASE - LIB_VECTSIZE)


#define MISCNAME  "misc.resource"


#endif /* RESOURCES_MISC_H */
