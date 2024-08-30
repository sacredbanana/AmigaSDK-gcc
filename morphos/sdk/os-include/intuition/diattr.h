#ifndef INTUITION_DIATTR_H
#define INTUITION_DIATTR_H

/*
	intuition getdrawinfoattr definitions (V50)

	Copyright © 2002-2008 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef INTUITION_SCREENS_H
# include <intuition/screens.h>
#endif


#define GDIA_Color        0x00100000
#define GDIA_Pen          0x00200000
#define GDIA_Version      0x00300000
#define GDIA_DirectColor  0x00400000
#define GDIA_NumPens      0x00500000
#define GDIA_Font         0x00600000
#define GDIA_Depth        0x00700000
#define GDIA_ResolutionX  0x00800000
#define GDIA_ResolutionY  0x00900000
#define GDIA_CheckMark    0x00A00000
#define GDIA_MenuKey      0x00B00000


#define DRIPEN_DETAIL         DETAILPEN
#define DRIPEN_BLOCK          BLOCKPEN
#define DRIPEN_TEXT           TEXTPEN
#define DRIPEN_SHINE          SHINEPEN
#define DRIPEN_SHADOW         SHADOWPEN
#define DRIPEN_FILL           FILLPEN
#define DRIPEN_FILLTEXT       FILLTEXTPEN
#define DRIPEN_BACKGROUND     BACKGROUNDPEN
#define DRIPEN_HIGHLIGHTTEXT  HIGHLIGHTTEXTPEN
#define DRIPEN_BARDETAIL      BARDETAILPEN
#define DRIPEN_BARBLOCK       BARBLOCKPEN
#define DRIPEN_BARTRIM        BARTRIMPEN


#define DRIPEN_HALFSHINE                      0x000C
#define DRIPEN_HALFSHADOW                     0x000D
#define DRIPEN_NUMDRIPENS                     0x000E


#endif /* INTUITION_DIATTR_H */
