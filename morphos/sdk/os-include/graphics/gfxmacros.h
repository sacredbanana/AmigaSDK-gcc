#ifndef GRAPHICS_GFXMACROS_H
#define GRAPHICS_GFXMACROS_H

/*
	graphics macro definitions

	Copyright � 2002 The MorphOS Development Team, All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
# include <exec/types.h>
#endif

#ifndef  GRAPHICS_RASTPORT_H
# include <graphics/rastport.h>
#endif

#ifndef  GRAPHICS_GFXBASE_H
# include <graphics/gfxbase.h>
#endif

#ifndef  HARDWARE_CUSTOM_H
# include <hardware/custom.h>
#endif

#ifndef  HARDWARE_DMABITS_H
# include <hardware/dmabits.h>
#endif


#ifdef OLD_GRAPHICS_GFXMACROS_H

#define ON_DISPLAY              custom.dmacon = BITSET | DMAF_RASTER;
#define OFF_DISPLAY             custom.dmacon = BITCLR | DMAF_RASTER;
#define ON_SPRITE               custom.dmacon = BITSET | DMAF_SPRITE;
#define OFF_SPRITE              custom.dmacon = BITCLR | DMAF_SPRITE;

#define ON_VBLANK               custom.intena = BITSET | INTF_VERTB;
#define OFF_VBLANK              custom.intena = BITCLR | INTF_VERTB;

#define SetDrPt(w,p)            { (w)->LinePtrn = p; (w)->Flags |= FRST_DOT; (w)->linpatcnt = 15; }
#define SetAfPt(w,p,n)          { (w)->AreaPtrn = p; (w)->AreaPtSz = n; }

#define SetOPen(w,c)            { (w)->AOlPen = c; (w)->Flags |= AREAOUTLINE; }
#define SetWrMsk(w,m)           { (w)->Mask = m; }

#define SafeSetOutlinePen(w,c)  { if (GfxBase->LibNode.lib_Version<39) { (w)->AOlPen = c; (w)->Flags |= AREAOUTLINE; } else SetOutlinePen(w,c); }
#define SafeSetWriteMask(w,m)   { if (GfxBase->LibNode.lib_Version<39) { (w)->Mask = (m); } else SetWriteMask(w,m); }

#define GetOPen(rp)             GetOutlinePen(rp)

#define BNDRYOFF(w)             { (w)->Flags &= ~AREAOUTLINE; }

#define CINIT(c,n)              UCopperListInit(c,n);
#define CMOVE(c,a,b)            { CMove(c,&a,b); CBump(c); }
#define CWAIT(c,a,b)            { CWait(c,a,b); CBump(c); }
#define CEND(c)                 { CWAIT(c,10000,255); }

#define DrawCircle(rp,cx,cy,r)  DrawEllipse(rp,cx,cy,r,r);
#define AreaCircle(rp,cx,cy,r)  AreaEllipse(rp,cx,cy,r,r);

#else /* OLD_GRAPHICS_GFXMACROS_H */

#define ON_DISPLAY              custom.dmacon = BITSET | DMAF_RASTER
#define OFF_DISPLAY             custom.dmacon = BITCLR | DMAF_RASTER
#define ON_SPRITE               custom.dmacon = BITSET | DMAF_SPRITE
#define OFF_SPRITE              custom.dmacon = BITCLR | DMAF_SPRITE

#define ON_VBLANK               custom.intena = BITSET | INTF_VERTB
#define OFF_VBLANK              custom.intena = BITCLR | INTF_VERTB


#define SetDrPt(w,p)            do { (w)->LinePtrn = (p); (w)->Flags |= FRST_DOT; (w)->linpatcnt = 15; } while (0)
#define SetAfPt(w,p,n)          do { (w)->AreaPtrn = p; (w)->AreaPtSz = n; } while (0)

#define SetOPen(w,c)            do { (w)->AOlPen = c; (w)->Flags |= AREAOUTLINE; } while (0)
#define SetWrMsk(w,m)           do { (w)->Mask = m; } while (0)

#define SafeSetOutlinePen(w,c)  do { if (GfxBase->LibNode.lib_Version < 39) SetOPen(w,c); else SetOutlinePen(w,c); } while (0)
#define SafeSetWriteMask(w,m)   do { if (GfxBase->LibNode.lib_Version < 39) SetWrMsk(w,m); else SetWriteMask(w,m); } while (0)

#define GetOPen(rp)             GetOutlinePen(rp)

#define BNDRYOFF(w)             do { (w)->Flags &= ~AREAOUTLINE; } while (0)

#define CINIT(c,n)              UCopperListInit(c,n)
#define CMOVE(c,a,b)            do { CMove(c,&a,b); CBump(c); } while (0)
#define CWAIT(c,a,b)            do { CWait(c,a,b); CBump(c); } while (0)
#define CEND(c)                 do { CWAIT(c,10000,255); } while (0)

#define DrawCircle(rp,cx,cy,r)  DrawEllipse(rp,cx,cy,r,r)
#define AreaCircle(rp,cx,cy,r)  AreaEllipse(rp,cx,cy,r,r)

#endif /* OLD_GRAPHICS_GFXMACROS_H */


#endif /* GRAPHICS_GFXMACROS_H */
