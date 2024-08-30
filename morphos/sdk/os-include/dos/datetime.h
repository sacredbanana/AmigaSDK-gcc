#ifndef DOS_DATETIME_H
#define DOS_DATETIME_H

/*
	dos.library date/time include

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef DOS_DOS_H
# include <dos/dos.h>
#endif

#pragma pack(2)


struct DateTime
{
	struct DateStamp  dat_Stamp;
	UBYTE             dat_Format;
	UBYTE             dat_Flags;
	UBYTE            *dat_StrDay;
	UBYTE            *dat_StrDate;
	UBYTE            *dat_StrTime;
};


#define LEN_DATSTRING  16


#define DTB_SUBST   0
#define DTF_SUBST   (1<<DTB_SUBST)
#define DTB_FUTURE  1
#define DTF_FUTURE  (1<<DTB_FUTURE)


#define FORMAT_DOS  0
#define FORMAT_INT  1
#define FORMAT_USA  2
#define FORMAT_CDN  3
#define FORMAT_MAX  FORMAT_CDN
#define FORMAT_DEF  4


#pragma pack()

#endif /* DOS_DATETIME_H */
