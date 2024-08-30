#ifndef INTUITION_ICCLASS_H
#define INTUITION_ICCLASS_H

/*
	intuition interconnection class definitions

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef UTILITY_TAGITEM_H
# include <utility/tagitem.h>
#endif


#define ICM_Dummy      (0x0401)
#define ICM_SETLOOP    (ICM_Dummy + 1)
#define ICM_CLEARLOOP  (ICM_Dummy + 2)
#define ICM_CHECKLOOP  (ICM_Dummy + 3)


#define ICA_Dummy       (TAG_USER + 0x40000)
#define ICA_TARGET      (ICA_Dummy + 1)
#define ICA_MAP         (ICA_Dummy + 2)
#define ICSPECIAL_CODE  (ICA_Dummy + 3)


#define ICTARGET_IDCMP  (~0L)


#endif /* INTUITION_ICCLASS_H */
