#ifndef GRAPHICS_SPRITE_H
#define GRAPHICS_SPRITE_H

/*
	graphics sprite definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#pragma pack(2)


#define SPRITE_ATTACHED  0x80

struct SimpleSprite
{
	UWORD *posctldata;
	UWORD  height;
	UWORD  x, y;
	UWORD  num;
};

struct ExtSprite
{
	struct SimpleSprite es_SimpleSprite;
	UWORD               es_wordwidth;
	UWORD               es_flags;
};


/* AllocSpriteDataA() tag options */
#define SPRITEA_Width          0x81000000
#define SPRITEA_XReplication   0x81000002
#define SPRITEA_YReplication   0x81000004
#define SPRITEA_OutputHeight   0x81000006
#define SPRITEA_Attached       0x81000008
#define SPRITEA_OldDataFormat  0x8100000A

/* new v50 defines */
#define SPRITEA_ViewPort 0x81000020     /* viewport this sprite is going to be used with */


/* GetExtSprite() tag options */

#define GSTAG_SPRITE_NUM       0x82000020
#define GSTAG_ATTACHED         0x82000022
#define GSTAG_SOFTSPRITE       0x82000024

#define GSTAG_SCANDOUBLED      0x83000000


#pragma pack()

#endif /* GRAPHICS_SPRITE_H */
