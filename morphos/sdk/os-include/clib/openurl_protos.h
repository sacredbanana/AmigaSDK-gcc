#ifndef CLIB_OPENURL_PROTOS_H
#define CLIB_OPENURL_PROTOS_H

/*
**  $VER: openurl_protos.h 6.3 (17.4.2005)
**
**  C prototypes. For use with 32 bit integers only.
**
**  openurl.library - universal URL display and browser
**  launcher library
**
**  Written by Troels Walsted Hansen <troels@thule.no>
**  Placed in the public domain.
**
**  Developed by:
**  - Alfonso Ranieri <alforan@tin.it>
**  - Stefan Kost <ensonic@sonicpulse.de>
**
*/

#ifndef LIBRARIES_OPENURL_H
# include <libraries/openurl.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


ULONG URL_OpenA(STRPTR, struct TagItem *);

struct URL_Prefs *URL_GetPrefsA(struct TagItem *);
void URL_FreePrefsA(struct URL_Prefs *,struct TagItem *);
ULONG URL_SetPrefsA(struct URL_Prefs *,struct TagItem *);

ULONG URL_LaunchPrefsAppA(struct TagItem *);

ULONG URL_GetAttr(ULONG attr,ULONG *storage);

ULONG URL_Open ( STRPTR , Tag , ... );
struct URL_Prefs *URL_GetPrefs ( Tag , ... );
void URL_FreePrefs ( struct URL_Prefs * , Tag , ... );
ULONG URL_SetPrefs ( struct URL_Prefs * , Tag , ... );
ULONG URL_LaunchPrefsApp ( Tag , ... );

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* CLIB_OPENURL_PROTOS_H */
