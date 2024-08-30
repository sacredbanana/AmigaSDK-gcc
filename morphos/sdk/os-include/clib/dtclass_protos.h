#ifndef CLIB_DTCLASS_PROTOS_H
#define CLIB_DTCLASS_PROTOS_H

/*
	dtclass C prototypes

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef  INTUITION_CLASSES_H
# include <intuition/classes.h>
#endif

#ifndef  INTUITION_CLASSUSR_H
# include <intuition/classusr.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

Class *ObtainEngine( VOID );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_DTCLASS_PROTOS_H */
