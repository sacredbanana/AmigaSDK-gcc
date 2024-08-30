#ifndef GRAPHICS_REGIONS_H
#define GRAPHICS_REGIONS_H

/*
	graphics region definitions

	Copyright © 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef GRAPHICS_GFX_H
# include <graphics/gfx.h>
#endif

#pragma pack(2)


struct RegionRectangle
{
	struct RegionRectangle *Next, *Prev;
	struct Rectangle        bounds;
};

struct Region
{
	struct Rectangle        bounds;
	struct RegionRectangle *RegionRectangle;
};


#pragma pack()

#endif /* GRAPHICS_REGIONS_H */
