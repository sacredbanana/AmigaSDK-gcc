#ifndef LIBRARIES_SPELLCHECKER_H
#define LIBRARIES_SPELLCHECKER_H

/*
	spellchecker.library include

	Copyright © 2013 Antoine Dubourg
*/


#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#define SPELLCHECKER_NAME    "spellchecker.library"
#define SPELLCHECKER_VERSION 51

#define SCA_Dummy TAG_USER

/* DEPRECATED */
#define SCA_Levenshtein_Distance       (SCA_Dummy + 1)

#define SCA_UTF8                       (SCA_Dummy + 2)
#define SCA_Name                       (SCA_Dummy + 3)
#define SCA_Default                    (SCA_Dummy + 4)
#define SCA_WaitOpen                   (SCA_Dummy + 5)

#endif /* LIBRARIES_SPELLCHECKER_H */

