#ifndef LIBRARIES_OWNDEVUNIT_H
#define LIBRARIES_OWNDEVUNIT_H

/*
	owndevunit.library include

	Copyright © 2003 The MorphOS Development Team, All Rights Reserved.
*/


#define ODU_NAME "OwnDevUnit.library"

#define ODUERR_LEADCHAR "\x07"

#define ODUERR_NOMEM    ODUERR_LEADCHAR "Out of memory"
#define ODUERR_NOTIMER  ODUERR_LEADCHAR "Unable to open timer.device"
#define ODUERR_BADNAME  ODUERR_LEADCHAR "Bogus device name supplied"
#define ODUERR_BADBIT   ODUERR_LEADCHAR "Bogus notify bit supplied"
#define ODUERR_UNKNOWN  ODUERR_LEADCHAR "Unknown"


#endif /* LIBRARIES_OWNDEVUNIT_H */
