#ifndef _LIBINTL_H
#define _LIBINTL_H

#include <locale.h>

#ifdef __cplusplus
extern "C" {
#endif

__stdargs char * gettext (const char * msgid);
__stdargs char * dgettext (const char * domainname,const char * msgid);
__stdargs char * dcgettext (const char * domainname, const char* msgid,int category);

__stdargs char * textdomain (const char * domainname);
__stdargs char * bindtextdomain (const char * domainname, const char * dirname);

#ifdef __cplusplus
}
#endif

#endif // _LIBINTL_H
