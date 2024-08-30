/*
**
** Include file for the Warp3D API
** $VER: Warp3D.h 1.0 (20.05.98)
**
**
** This file is part of the Warp3D Project.
** Warp3D is copyrighted
** (C) 1998 Sam Jordan, Hans-J�rg Frieden, Thomas Frieden
**
** All rights reserved
**
** See the documentation for conditions.
**
*/
#ifndef WARP3D_WARP3D_H
#define WARP3D_WARP3D_H

#include <exec/types.h>
#include <exec/lists.h>
#include <exec/nodes.h>
#include <exec/libraries.h>
#include <utility/tagitem.h>
#include <graphics/gfx.h>
#include <graphics/displayinfo.h>

typedef short  W3D_Bool;
typedef float  W3D_Float;
typedef double W3D_Double;

struct W3DHWIFace;

#ifndef W3D_TRUE
	#define W3D_TRUE 1
#endif
#ifndef W3D_FALSE
	#define W3D_FALSE 0
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GNUC__
	#ifdef __PPC__
		#pragma pack(2)
	#endif
#elif defined(__VBCC__)
	#pragma amiga-align
#endif

enum {
	W3D_MAXMIPMAPS = 16,
	W3D_MAX_TMU    = 16         /* be prepared that this might grow */
};

typedef struct {
	W3D_Float r, g, b, a;       /* RGBA values in range [0..1] */
} W3D_Color;

typedef struct {
	W3D_Float r, g, b;          /* RGB values in range [0..1] */
} W3D_ColorRGB;

typedef struct {
	W3D_Float x, y;             /* window coordinates */
	W3D_Double z;               /* z coordinate. Double precision for 32bit
	                               zbuffers */
	W3D_Float w;                /* w coordinate. */
	W3D_Float u, v, tex3d;      /* u/v coordinates, and an additional for 3d
	                               textures */
	W3D_Color    color;         /* vertex color */
	W3D_ColorRGB spec;          /* specular lighting color */
	W3D_Float    l;             /* Lambda value for Mipmapping. Private right
	                               now */
} W3D_Vertex;

typedef struct {
	struct Node link;           /* linkage, used by Warp3D itself */
	W3D_Bool    resident;       /* TRUE, if texture is on card */
	W3D_Bool    mipmap;         /* TRUE, if mipmaps are supported */
	W3D_Bool    dirty;          /* TRUE, if texture image was changed */
	W3D_Bool    matchfmt;       /* TRUE, if srcfmt = destfmt */
	W3D_Bool    pinned;         /* TRUE if texture is pinned */
	W3D_Bool    reserved2;
	uint32      mipmapmask;     /* which mipmaps have to be generated */
	void        *texsource;     /* texture source image */
	void        *mipmaps[W3D_MAXMIPMAPS];   /* mipmap images */
	int         texfmtsrc;      /* texture format (from W3D_ATO_FORMAT) */
	uint32      *palette;       /* texture palette for chunky textures */
	void        *texdata;       /* texture data converted */
	void        *texdest;       /* texture location on card */
	int         texdestsize;    /* size of VRAM allocation */
	int         texwidth;       /* texture width in pixels */
	int         texwidthexp;    /* texture width exponent */
	int         texheight;      /* texture width in pixels */
	int         texheightexp;   /* texture width exponent */
	int         bytesperpix;    /* bytes per pixel */
	int         bytesperrow;    /* bytes per row */
	void        *driver;        /* insert driver specific data here */
} W3D_Texture;

typedef struct {
	W3D_Vertex  v1;             /* vertex */
	W3D_Texture *tex;           /* texture */
	W3D_Float   pointsize;      /* point diameter */
} W3D_Point;

typedef struct {
	W3D_Vertex  v1, v2;         /* vertices for line drawing */
	W3D_Texture *tex;           /* texture */
	W3D_Float   linewidth;      /* line width */
	W3D_Bool    st_enable;      /* stippling enable */
	uint16      st_pattern;     /* stippling pattern */
	int         st_factor;      /* stippling factor */
} W3D_Line;

typedef struct {                             /* V2 only */
	int         vertexcount;    /* Number of vertices */
	W3D_Vertex  *v;             /* An array of at least two vertices */
	W3D_Texture *tex;           /* texture */
	W3D_Float   linewidth;      /* line width */
	W3D_Bool    st_enable;      /* stippling enable */
	uint16      st_pattern;     /* stippling pattern */
	int         st_factor;      /* stippling factor */
} W3D_Lines;

typedef struct {
	W3D_Vertex  v1, v2, v3;     /* three vertices for triangle drawing */
	W3D_Texture *tex;           /* texture */
	uint8       *st_pattern;    /* stippling pattern */
} W3D_Triangle;

typedef struct {
	W3D_Vertex  *v1, *v2, *v3;  /* Three vertex POINTERS */
	W3D_Texture *tex;           /* see above */
	uint8       *st_pattern;    /* See above */
} W3D_TriangleV;

typedef struct {
	int         vertexcount;    /* number of vertices */
	W3D_Vertex  *v;             /* an array of at least 3 vertices */
	W3D_Texture *tex;           /* texture */
	uint8       *st_pattern;    /* stippling pattern */
} W3D_Triangles;

typedef struct {
	int         vertexcount;    /* number of vertices */
	W3D_Vertex  **v;            /* Pointer to an array of pointers ! */
	W3D_Texture *tex;           /* Texture */
	uint8       *st_pattern;    /* Stippling pattern */
} W3D_TrianglesV;

typedef struct {
	W3D_Float    fog_start;     /* start of fogging zone */
	W3D_Float    fog_end;       /* end of fogging area */
	W3D_Float    fog_density;   /* fog density for exp. fogging */
	W3D_ColorRGB fog_color;     /* fog color */
} W3D_Fog;

typedef struct {
	int left;                   /* left offset of clipping area */
	int top;                    /* top offset of clipping area */
	int width;                  /* width of clipping area */
	int height;                 /* height of clipping area */
} W3D_Scissor;

typedef struct {
	int16  type;                /* Type of this entry */
	int16  length;              /* Length of the entry, including this struct */
	uint32 state;               /* State longword */
} W3D_QHead;

typedef struct {
	uint8  *data;               /* Pointer to data area */
	uint32 size;                /* Size of the data block */
	uint8  *current;            /* Current insertion position */
} W3D_Queue;

#define QEMPTY(x) ( (x)->data == (x)->current )

/*
	The context structure is private, and should not be accessed in any
	way by Warp3D applications, with the following exceptions:

	The following fields are READ-ONLY:
	format, bprow, width, height, depth, drawmem
*/

typedef struct {
	void   *driver;             /* insert driver specific data here */
	void   *gfxdriver;          /* usable by the GFXdriver */
	int    drivertype;          /* driver type (3DHW / CPU) */
	void   *regbase;            /* register base */
	void   *vmembase;           /* video memory base */
	void   *zbuffer;            /* Pointer to the Z buffer */
	void   *stencilbuffer;      /* Pointer to the stencil buffer */
	uint32 state;               /* hardware state (see below) */
	struct BitMap *drawregion;  /* destination bitmap */
	uint32 supportedfmt;        /* bitmask with all supported dest fmt */
	uint32 format;              /* bitmap format (see below) */
	int    yoffset;             /* Y-Offset (for ScrollVPort-Multibuf.) */
	int    bprow;               /* bytes per row */
	int    width;               /* bitmap width */
	int    height;              /* bitmap height */
	int    depth;               /* bitmap depth */
	W3D_Bool chunky;            /* TRUE, if palettized screen mode */
	W3D_Bool destalpha;         /* TRUE, if dest alpha channel available */
	W3D_Bool zbufferalloc;      /* TRUE, is Z buffer is allocated */
	W3D_Bool stbufferalloc;     /* TRUE, is stencil buffer is allocated */
	W3D_Bool HWlocked;          /* TRUE, if 3D HW was locked */
	W3D_Bool w3dbitmap;         /* TRUE, if drawregion points to a W3D_Bitmap */
	W3D_Bool zbufferlost;       /* TRUE, if zbuffer not reallocatable */
	W3D_Bool reserved3;
	struct MinList restex;      /* A list of all resident textures, used for
	                               LRU implementation */
	struct MinList tex;         /* A list of all textures which are not on
	                               card */
	int maxtexwidth;            /* -HJF- replaced these for possible */
	int maxtexheight;           /* support of non-square textures */
	int maxtexwidthp;           /* -HJF- For hardware that has different */
	int maxtexheightp;          /* constaints in perspective mode */
	W3D_Scissor scissor;              /* scissor region */
	W3D_Fog     fog;                  /* fogging parameters */
	uint32      envsupmask;           /* Mask of supported envmodes */
	W3D_Queue   *queue;               /* queue to buffer drawings */
	void        *drawmem;             /* base address for drawing operations */
	uint32      globaltexenvmode;     /* Global texture environment mode */
	W3D_Float   globaltexenvcolor[4]; /* global texture env color */
#if 0
	struct Library *DriverBase; /* Library base of the active driver */
#else
	struct W3DHWIFace *DriverIFace;
#endif
	uint32 EnableMask;           /* Mask for enable-able states */
	uint32 DisableMask;          /* Mask for disable-able states */
	uint32 CurrentChip;          /* Chip constant */
	uint32 DriverVersion;        /* Internal driver version */
	/* --- NEW for V4 --------------------------------------------------------*/
	/* Vertex pointer */
	void   *VertexPointer;       /* Pointer to the vertex buffer array */
	int    VPStride;             /* Stride of vertex array */
	uint32 VPMode;               /* Vertex buffer format */
	uint32 VPFlags;              /* not yet used */
	/* TexCoord pointer */
	void *TexCoordPointer[W3D_MAX_TMU];
	/* Pointer to each TMU's texture coordinate array */
	int    TPStride[W3D_MAX_TMU]; /* Stride of TexCoordPointers */
	W3D_Texture *CurrentTex[W3D_MAX_TMU];
	/* Pointer to each TMU's texture object */
	int    TPVOffs[W3D_MAX_TMU];  /* Offset to V coordinate */
	int    TPWOffs[W3D_MAX_TMU];  /* Offset to W coordinate */
	int    TPFlags[W3D_MAX_TMU];  /* Flags */
	/* Color Pointer */
	void   *ColorPointer;         /* Pointer to the color array */
	int    CPStride;              /* Color pointer stride */
	uint32 CPMode;                /* Mode and color format */
	uint32 CPFlags;               /* not yet used */
	uint32 FrontFaceOrder;        /* Winding order of front facing triangles */
	void   *specialbuffer;        /* Special buffer for chip-dependant use
	                                 (like command FIFOs) */
	/* --- NEW for V5 --------------------------------------------------------*/
	/* Secondary (specular) color pointer */
	void   *SecondaryColorPointer; /* Pointer to the secondary/specular color
	                                  array */
	int    SCPStride;              /* Stride of the secondary color array */
	uint32 SCPMode;                /* Mode  and color format */
	uint32 SCPFlags;               /* Not used yet */
	/* Fog Coordinate Array */
	void   *FogCoordPointer;       /* Array of fog coordinates */
	uint32 FCPMode;                /* Mode (double/float) of fog coordinates */
	uint32 FCPStride;              /* Stride of fog coord array */
	uint32 FCPFlags;               /* Flags, not yet used */

	/* Backup for draw region pointers for the texture render target */
	struct BitMap *orig_drawregion;
	void          *orig_zbuffer;
	void          *orig_stencilbuffer;
	uint32        orig_width, orig_height;
	uint32        orig_yoffset;
	W3D_Scissor   orig_scissor;
	uint32        orig_bprow;
} W3D_Context;


typedef struct {
	int    bprow;                /* Bytes per row */
	int    width;                /* Width */
	int    height;               /* Height */
	uint32 format;               /* Destination color format */
	void   *dest;                /* Pointer to destination */
} W3D_Bitmap;

typedef struct {               /* V2 only */
	uint32 ChipID;               /* One of W3D_CHIP_??? below */
	uint32 formats;              /* Bitmask of supported formats */
	char *name;                  /* Name of the chip/driver */
	W3D_Bool swdriver;           /* W3D_TRUE -> CPU-Driver */
} W3D_Driver;

/* W3D_ScreenMode structure */
typedef struct {
	uint32     ModeID;                      /* ModeID for OpenScreen */
	uint32     Width, Height;               /* Width and Height for visible screen */
	uint32     Depth;                       /* Pixel Depth */
	char       DisplayName[DISPLAYNAMELEN]; /* readable name of this display mode */
	W3D_Driver *Driver;                     /* Matching driver for this mode */
	void       *Next;                       /* Next W3D_ScreenMode in list */
} W3D_ScreenMode;

/* Tags for W3D_CreateContext */
enum {
	W3D_CC_TAGS              = (TAG_USER+0x200000),
	W3D_CC_BITMAP            = (W3D_CC_TAGS+0), /* destination bitmap */
	W3D_CC_YOFFSET           = (W3D_CC_TAGS+1), /* y-Offset */
	W3D_CC_DRIVERTYPE        = (W3D_CC_TAGS+2), /* see below */
	W3D_CC_W3DBM             = (W3D_CC_TAGS+3), /* Use W3D_Bitmap instead of
	                                               struct BitMap */
	W3D_CC_INDIRECT          = (W3D_CC_TAGS+4), /* Indirect drawing */
	W3D_CC_GLOBALTEXENV      = (W3D_CC_TAGS+5), /* SetTexEnv is global */
	W3D_CC_DOUBLEHEIGHT      = (W3D_CC_TAGS+6), /* Drawing area has double height */
	W3D_CC_FAST              = (W3D_CC_TAGS+7), /* Allow Warp3D to modify passed
	                                               Triangle/Lines/Points */
	W3D_CC_MODEID            = (W3D_CC_TAGS+8)  /* Specify modeID to use */
};

/*
	Driver types. These are used as flags for W3D_CreateContext and as bitmask
	for W3D_CheckDriver. It is also used by W3DHW_GetDriverInfo and in the
	element 'drivertype' in the context structure
*/

enum {
	W3D_DRIVER_UNAVAILABLE   = (1<<0),  /* driver unavailable */
	W3D_DRIVER_BEST          = (1<<1),  /* use best mode */
	W3D_DRIVER_3DHW          = (1<<2),  /* use 3D-HW */
	W3D_DRIVER_CPU           = (1<<3)   /* use CPU */
};

/*
	Chip constants returned e.g. by W3D_GetDrivers. These can be
	used to identify the chip that is active/available.
	You may not, however, make any assumtions about the capabilities
	of the driver based on this constant, since some features might be
	emulated.
	Strictly for informational/internal uses.
*/

typedef enum {
	W3D_CHIP_UNKNOWN         =  1,
	W3D_CHIP_VIRGE           =  2,
	W3D_CHIP_PERMEDIA2       =  3,
	W3D_CHIP_VOODOO1         =  4,
	W3D_CHIP_OBSOLETE1       =  5,
	W3D_CHIP_OBSOLETE2       =  6,
	W3D_CHIP_RADEON          =  7,
	W3D_CHIP_AVENGER         =  8, /* Voodoo 3 */
	W3D_CHIP_NAPALM          =  9, /* Voodoo 4/5 */
	W3D_CHIP_RADEON_R200     = 10, /* R200, R280, RV280 etc */
	W3D_CHIP_RADEON_R300     = 11, /* R300, R350, R380, RV3xx etc */
	W3D_CHIP_EVERGREEN       = 12, /* Cedar, Redwood, Juniper, Cypress, Hemlock,
	                                  Caicos, Turks and Barts based RadeonHD */
	W3D_CHIP_SI              = 13  /* Southern Islands based Radeon HD and 
	                                  Radeon Rx */
} W3D_ChipTypeEnum;

/* Tags for W3D_AllocTexObj */
enum {
	W3D_ATO_TAGS             = (TAG_USER+0x201000),
	W3D_ATO_IMAGE            = (W3D_ATO_TAGS+0),    /* texture image */
	W3D_ATO_FORMAT           = (W3D_ATO_TAGS+1),    /* source format */
	W3D_ATO_WIDTH            = (W3D_ATO_TAGS+2),    /* border width */
	W3D_ATO_HEIGHT           = (W3D_ATO_TAGS+3),    /* border height */
	W3D_ATO_MIPMAP           = (W3D_ATO_TAGS+4),    /* mipmap mask */
	W3D_ATO_PALETTE          = (W3D_ATO_TAGS+5),    /* texture palette */
	W3D_ATO_MIPMAPPTRS       = (W3D_ATO_TAGS+6),    /* array of user-supplied
	                                                   mipmaps */
};
/* Possible modes for SetFrontFace */
typedef enum {
	W3D_CW                   =  0,  /* Front face is clockwise */
	W3D_CCW                  =  1   /* Front face is counter clockwise */
} W3D_FrontFaceOrderEnum;

/* possible values for W3D_ATO_FORMAT  and W3D_GetTexFmtInfo */
/* a = alpha, r = red, g = green, b = blue, l = luminance, i = intensity */
typedef enum {
	W3D_CHUNKY               =  1,  /* palettized */
	W3D_A1R5G5B5             =  2,  /* a rrrrr ggggg bbbbb */
	W3D_R5G6B5               =  3,  /* rrrrr gggggg bbbbb */
	W3D_R8G8B8               =  4,  /* rrrrrrrr gggggggg bbbbbbbb */
	W3D_A4R4G4B4             =  5,  /* aaaa rrrr gggg bbbb */
	W3D_A8R8G8B8             =  6,  /* aaaaaaaa rrrrrrrr gggggggg bbbbbbbb */
	W3D_A8                   =  7,  /* aaaaaaaa */
	W3D_L8                   =  8,  /* llllllll */
	W3D_L8A8                 =  9,  /* llllllll aaaaaaaa */
	W3D_I8                   = 10,  /* iiiiiiii */
	W3D_R8G8B8A8             = 11,  /* rrrrrrrr gggggggg bbbbbbbb aaaaaaaa */
	W3D_COMPRESSED_R5G6B5    = 12,  /* Compressed color, no alpha */
	W3D_A4_COMPRESSED_R5G6B5 = 13,  /* 4 bit alpha, compressed color */
	W3D_COMPRESSED_A8R5G6B5  = 14,  /* compressed alpha/color */
} W3D_TexFormatEnum;

/* return values of W3D_GetTexFmtInfo (bitmask) */
enum {
	W3D_TEXFMT_SUPPORTED     = (1<<0),  /* format is supported, although it may be
	                                       converted */
	W3D_TEXFMT_FAST          = (1<<16), /* format directly supported by 3D HW */
	W3D_TEXFMT_CLUTFAST      = (1<<17), /* format is directly supported on LUT8
	                                       screens */
	W3D_TEXFMT_ARGBFAST      = (1<<18), /* format is directly supported on 16/24
	                                       bit screens */
	W3D_TEXFMT_UNSUPPORTED   = (1<<1)   /* this format is unsupported, and can't
	                                       be simulated */
};

/* bitmap format flags used by CPU drivers */
enum {
	W3D_FMT_CLUT             = (1<<0),  /* chunky */
	W3D_FMT_R5G5B5           = (1<<1),  /* 0 rrrrr ggggg bbbbb */
	W3D_FMT_B5G5R5           = (1<<2),  /* 0 bbbbb ggggg rrrrr */
	W3D_FMT_R5G5B5PC         = (1<<3),  /* ggg bbbbb 0 rrrrr gg */
	W3D_FMT_B5G5R5PC         = (1<<4),  /* ggg rrrrr 0 bbbbb gg */
	W3D_FMT_R5G6B5           = (1<<5),  /* rrrrr gggggg bbbbb */
	W3D_FMT_B5G6R5           = (1<<6),  /* bbbbb gggggg rrrrr */
	W3D_FMT_R5G6B5PC         = (1<<7),  /* ggg bbbbb rrrrr ggg */
	W3D_FMT_B5G6R5PC         = (1<<8),  /* ggg rrrrr bbbbb ggg */
	W3D_FMT_R8G8B8           = (1<<9),  /* rrrrrrrr gggggggg bbbbbbbb */
	W3D_FMT_B8G8R8           = (1<<10), /* bbbbbbbb gggggggg rrrrrrrr */
	W3D_FMT_A8R8G8B8         = (1<<11), /* aaaaaaaa rrrrrrrr gggggggg bbbbbbbb */
	W3D_FMT_A8B8G8R8         = (1<<12), /* aaaaaaaa bbbbbbbb gggggggg rrrrrrrr */
	W3D_FMT_R8G8B8A8         = (1<<13), /* rrrrrrrr gggggggg bbbbbbbb aaaaaaaa */
	W3D_FMT_B8G8R8A8         = (1<<14), /* bbbbbbbb gggggggg rrrrrrrr aaaaaaaa */
};

/* possible mode values for W3D_SetState/W3D_GetState and for 'state' in the
	context structure */
typedef enum {
	W3D_AUTOTEXMANAGEMENT    =  (1<<1), /* automatic texture management */
	W3D_SYNCHRON             =  (1<<2), /* wait, until HW is idle */
	W3D_INDIRECT             =  (1<<3), /* drawing is queued until flushed */
	W3D_GLOBALTEXENV         =  (1<<4), /* SetTexEnv is global */
	W3D_DOUBLEHEIGHT         =  (1<<5), /* Drawing area is double height */
	W3D_FAST                 =  (1<<6), /* Allow Warp3D to modify passed
	                                       Triangles/Points/Lines */
	W3D_AUTOCLIP             =  (1<<7), /* clip to screen region */

	W3D_TEXMAPPING           =  (1<<8), /* texmapping state */
	W3D_PERSPECTIVE          =  (1<<9), /* perspective correction state */
	W3D_GOURAUD              = (1<<10), /* gouraud/flat shading */
	W3D_ZBUFFER              = (1<<11), /* Z-Buffer state */
	W3D_ZBUFFERUPDATE        = (1<<12), /* Z-Buffer update state */
	W3D_BLENDING             = (1<<13), /* Alpha blending state */
	W3D_FOGGING              = (1<<14), /* Fogging state */
	W3D_ANTI_POINT           = (1<<15), /* Point antialiasing state */
	W3D_ANTI_LINE            = (1<<16), /* Line antialiasing state */
	W3D_ANTI_POLYGON         = (1<<17), /* Polygon antialiasing state */
	W3D_ANTI_FULLSCREEN      = (1<<18), /* Fullscreen antialiasing state */
	W3D_DITHERING            = (1<<19), /* dithering state */
	W3D_LOGICOP              = (1<<20), /* logic operations */
	W3D_STENCILBUFFER        = (1<<21), /* stencil buffer/stencil test */
	W3D_ALPHATEST            = (1<<22), /* alpha test */
	W3D_SPECULAR             = (1<<23), /* Specular lighting */
	W3D_TEXMAPPING3D         = (1<<24), /* 3d textures */
	W3D_SCISSOR              = (1<<25), /* Scissor test enable */
	W3D_CHROMATEST           = (1<<26), /* Chroma test enable */
	W3D_CULLFACE             = (1<<27), /* Backface culling enable */

	/* New states for V5 */
	W3D_MULTITEXTURE         = (1<<28), /* Enable multitexturing and separate
	                                       blend functions */
	W3D_FOG_COORD            = (1<<29), /* Use separate fog coord array instead
                                         of first texture's w coordinates */
	W3D_LINE_STIPPLE         = (1<<30),
	W3D_POLYGON_STIPPLE      = (1<<31)
} W3D_StateFlagEnum;

/* action/result values for W3D_SetState/W3D_GetState */
enum {
	W3D_ENABLE               =   1, /* enable mode */
	W3D_ENABLED              =   1, /* mode is enabled */
	W3D_DISABLE              =   2, /* disable mode */
	W3D_DISABLED             =   2  /* mode is disabled */
};

/* mode parameters for W3D_Query */
typedef enum {
	W3D_Q_DRAW_POINT         =   1, /* point drawing */
	W3D_Q_DRAW_LINE          =   2, /* line drawing */
	W3D_Q_DRAW_TRIANGLE      =   3, /* triangle drawing */
	W3D_Q_DRAW_POINT_X       =   4, /* points with size != 1 supported */
	W3D_Q_DRAW_LINE_X        =   5, /* lines with width != 1 supported */
	W3D_Q_DRAW_LINE_ST       =   6, /* line stippling supported */
	W3D_Q_DRAW_POLY_ST       =   7, /* polygon stippling supported */
	W3D_Q_DRAW_POINT_FX      =   8, /* point drawing supports special fx */
	W3D_Q_DRAW_LINE_FX       =   9, /* line drawing supports speical fx */

/* Note: more of these below */
	W3D_Q_TEXMAPPING         =  11, /* texmapping in general */
	W3D_Q_MIPMAPPING         =  12, /* mipmapping */
	W3D_Q_BILINEARFILTER     =  13, /* bilinear filter */
	W3D_Q_MMFILTER           =  14, /* mipmap filter */
	W3D_Q_LINEAR_REPEAT      =  15, /* W3D_REPEAT for linear texmapping */
	W3D_Q_LINEAR_CLAMP_LAST  =  16, /* W3D_CLAMP_LAST for linear texmapping */
	W3D_Q_PERSPECTIVE        =  17, /* perspective correction */
	W3D_Q_PERSP_REPEAT       =  18, /* W3D_REPEAT for persp. texmapping */
	W3D_Q_PERSP_CLAMP_LAST   =  19, /* W3D_CLAMP_LAST for persp. texmapping */
	W3D_Q_ENV_REPLACE        =  20, /* texenv REPLACE */
	W3D_Q_ENV_DECAL          =  21, /* texenv DECAL */
	W3D_Q_ENV_MODULATE       =  22, /* texenv MODULATE */
	W3D_Q_ENV_BLEND          =  23, /* texenv BLEND */
	W3D_Q_WRAP_ASYM          =  24, /* texture wrapping asymetric in s and t
	                                   direction */
	W3D_Q_SPECULAR           =  25, /* Specular hiliting */
	W3D_Q_BLEND_DECAL_FOG    =  26, /* driver supports alpha blending and
	                                   decal with fog */
	W3D_Q_TEXMAPPING3D       =  27, /* driver supports 3-dimensional
	                                   (volumetric) textures */
	W3D_Q_CHROMATEST         =  28, /* driver supports chroma test */

	W3D_Q_ANISOTROPICFILTER  =  29, /* support for anisotropic filtering generally */
	W3D_Q_MAXANISOTROPY      =  30, /* degree of anisotrpic filtering supported */

	W3D_Q_FLATSHADING        =  31, /* flat shading */
	W3D_Q_GOURAUDSHADING     =  32, /* gouraud shading */

	W3D_Q_ZBUFFER            =  41, /* Z buffer in general */
	W3D_Q_ZBUFFERUPDATE      =  42, /* Z buffer update */
	W3D_Q_ZCOMPAREMODES      =  43, /* Z buffer compare modes */
	W3D_Q_DEPTH_FORMATS      =  44, /* Z buffer formats supported */
	W3D_Q_DEPTH_FORMAT       =  45, /* Default Z format unless queried on a context
	                                   with Z buffer allocated, in which case the
	                                   actual Z format is returned. These may be
	                                   queried, but not set other than by hinting.
	                                 */

	W3D_Q_ALPHATEST          =  51, /* alpha test in general */
	W3D_Q_ALPHATESTMODES     =  52, /* alpha test modes */

	W3D_Q_BLENDING           =  61, /* alpha blending */
	W3D_Q_SRCFACTORS         =  62, /* source factors */
	W3D_Q_DESTFACTORS        =  63, /* destination factors */
	W3D_Q_ONE_ONE            =  64, /* W3D_ONE / W3D_ONE supported */

	W3D_Q_FOGGING            =  71, /* fogging in general */
	W3D_Q_LINEAR             =  72, /* linear fogging */
	W3D_Q_EXPONENTIAL        =  73, /* exponential fogging */
	W3D_Q_S_EXPONENTIAL      =  74, /* square exponential fogging */
	W3D_Q_INTERPOLATED       =  75, /* interpolated fog */

	W3D_Q_ANTIALIASING       =  81, /* antialiasing in general */
	W3D_Q_ANTI_POINT         =  82, /* point antialiasing */
	W3D_Q_ANTI_LINE          =  83, /* line antialiasing */
	W3D_Q_ANTI_POLYGON       =  84, /* polygon antialiasing */
	W3D_Q_ANTI_FULLSCREEN    =  85, /* full screen antialiasing */

	W3D_Q_DITHERING          =  91, /* dithering */
	W3D_Q_PALETTECONV        =  92, /* driver can use per-texture
	                                   palettes on 8bit screens */

	W3D_Q_SCISSOR            = 101, /* scissor test */

	W3D_Q_MAXTEXWIDTH        = 111, /* max. texture border width */
	W3D_Q_MAXTEXHEIGHT       = 112, /* max. texture border height */
	W3D_Q_MAXTEXWIDTH_P      = 113, /* max. texture border width */
	W3D_Q_MAXTEXHEIGHT_P     = 114, /* max. texture border height */
	W3D_Q_RECTTEXTURES       = 115, /* rectangular texture supported */

	W3D_Q_LOGICOP            = 121, /* logical operation */

	W3D_Q_MASKING            = 131, /* color/index masking */

	W3D_Q_STENCILBUFFER      = 141, /* stencil buffer in general */
	W3D_Q_STENCIL_MASK       = 142, /* mask value */
	W3D_Q_STENCIL_FUNC       = 143, /* stencil functions */
	W3D_Q_STENCIL_SFAIL      = 144, /* stencil operation SFAIL */
	W3D_Q_STENCIL_DPFAIL     = 145, /* stencil operation DPFAIL */
	W3D_Q_STENCIL_DPPASS     = 146, /* stencil operation DPPASS */
	W3D_Q_STENCIL_WRMASK     = 147, /* stencil buffer supports write masking */

	W3D_Q_DRAW_POINT_TEX     = 160, /* point drawing supports textures */
	W3D_Q_DRAW_LINE_TEX      = 161, /* line drawing supports textures */

	W3D_Q_CULLFACE           = 162, /* driver supports backface culling */

	/* New for V5 */
	W3D_Q_NUM_TMU            = 170, /* Number of texture units */
	W3D_Q_NUM_BLEND          = 171, /* Number of blend stages */
	W3D_Q_ENV_COMBINE        = 172, /* Supports env combine functions */
	W3D_Q_ENV_ADD            = 173, /* Supports W3D_ADD environment */
	W3D_Q_ENV_SUB            = 174, /* Supports W3D_SUB environment */
	W3D_Q_ENV_CROSSBAR       = 175, /* Supports "crossbar" texture blending */
	W3D_Q_STIPPLE_LINE       = 176, /* Supports line stippling patterns */
	W3D_Q_STIPPLE_POLYGON    = 177,  /* Supports polygon stippling patterns */

	W3D_Q_LINEAR_CLAMP_COLOR = 178, /* W3D_CLAMP_BORDER_COLOR for linear texmapping */
	W3D_Q_PERSP_CLAMP_COLOR  = 179, /* W3D_CLAMP_BORDER_COLOR for persp. texmapping */
} W3D_QueryEnum;

/* For legacy software */
#define W3D_Q_LINEAR_CLAMP W3D_Q_LINEAR_CLAMP_LAST
#define W3D_Q_PERSP_CLAMP W3D_Q_PERSP_CLAMP_LAST

/* results of W3D_Query (if a result-set is expected) */
enum {
	W3D_FULLY_SUPPORTED      =  3, /* completely supported */
	W3D_PARTIALLY_SUPPORTED  =  4, /* partially supported */
	W3D_NOT_SUPPORTED        =  5  /* not supported */
};

/* blending modes used for alpha blending (the comment shows for
	which function [source or destination] the mode can be used) */
typedef enum {
	W3D_ZERO                     =  1, /* source + dest */
	W3D_ONE                      =  2, /* source + dest */
	W3D_SRC_COLOR                =  3, /* dest only */
	W3D_DST_COLOR                =  4, /* source only */
	W3D_ONE_MINUS_SRC_COLOR      =  5, /* dest only */
	W3D_ONE_MINUS_DST_COLOR      =  6, /* source only */
	W3D_SRC_ALPHA                =  7, /* source + dest */
	W3D_ONE_MINUS_SRC_ALPHA      =  8, /* source + dest */
	W3D_DST_ALPHA                =  9, /* source + dest */
	W3D_ONE_MINUS_DST_ALPHA      = 10, /* source + dest */
	W3D_SRC_ALPHA_SATURATE       = 11, /* source only */
	W3D_CONSTANT_COLOR           = 12,
	W3D_ONE_MINUS_CONSTANT_COLOR = 13,
	W3D_CONSTANT_ALPHA           = 14,
	W3D_ONE_MINUS_CONSTANT_ALPHA = 15
} W3D_BlendModeEnum;

/* texture filter. Only W3D_NEAREST and W3D_LINEAR can be used for
	magnification filters! */
typedef enum {
	W3D_NEAREST                         = 1, /* no mipmapping, no filtering */
	W3D_LINEAR                          = 2, /* no mipmapping, bilinear filtering */
	W3D_NEAREST_MIP_NEAREST             = 3, /* mipmapping, no filtering */
	W3D_NEAREST_MIP_LINEAR              = 4, /* mipmapping, bilinear filtering */
	W3D_LINEAR_MIP_NEAREST              = 5, /* filtered mipmapping, no filtering */
	W3D_LINEAR_MIP_LINEAR               = 6, /* mipmapping, trilinear filtering */

	/* anisotropic minification filters */
	W3D_ANISOTROPIC_NEAREST             = 7,
	W3D_ANISOTROPIC_LINEAR              = 8,
	W3D_ANISOTROPIC_NEAREST_MIP_NEAREST = 9,
	W3D_ANISOTROPIC_NEAREST_MIP_LINEAR  = 10
} W3D_TexFilterEnum;

/* maximum anisotropy */
typedef enum {
	W3D_ANISOTROPY_1_TO_1  = 1, /* A ratio of 1:1 will disable anisotropy */
	W3D_ANISOTROPY_2_TO_1  = 2,
	W3D_ANISOTROPY_4_TO_1  = 3,
	W3D_ANISOTROPY_8_TO_1  = 4,
	W3D_ANISOTROPY_16_TO_1 = 5
} W3D_TexAnisotropyEnum;

/* fog modes */
typedef enum {
	W3D_FOG_LINEAR         = 1, /* linear fogging */
	W3D_FOG_EXP            = 2, /* exponential fogging */
	W3D_FOG_EXP_2          = 3, /* square exponential fogging */
	W3D_FOG_INTERPOLATED   = 4  /* interpolated fogging */
} W3D_FogMethodEnum;

/* texture environment parameters */
typedef enum {
	W3D_REPLACE            = 1, /* unlit texturing */
	W3D_DECAL              = 2, /* RGB: same as W3D_REPLACE RGBA: use alpha to blend
	                               texture with primitive (lit-texturing) */
	W3D_MODULATE           = 3, /* lit-texturing by modulation */
	W3D_BLEND              = 4, /* blend with environment color */
	W3D_ADD                = 5, /* Add texture and other color (either other texture
	                               unit, or fragment color) */
	W3D_SUB                = 6, /* Subtract texture and other color) */
	W3D_OFF                = 7  /* Turn off a texture unit */
} W3D_TexEnvEnum;

/* texture wrapping parameters */
typedef enum {
	W3D_REPEAT             =  1,  /* texture is repeated */
	W3D_CLAMP_LAST         =  2,  /* texture is clamped to the last texel */
	W3D_CLAMP_COLOR        =  3   /* texture is clamped to the border color */
} W3D_TexClampEnum;

/* For legacy software */
#define W3D_CLAMP W3D_CLAMP_LAST

/* alpha test compare modes */
typedef enum {
	W3D_A_NEVER              =  1,  /* discard incoming pixel */
	W3D_A_LESS               =  2,  /* draw, if value < refvalue */
	W3D_A_GEQUAL             =  3,  /* draw, if value >= refvalue */
	W3D_A_LEQUAL             =  4,  /* draw, if value <= refvalue */
	W3D_A_GREATER            =  5,  /* draw, if value > refvalue */
	W3D_A_NOTEQUAL           =  6,  /* draw, if value != refvalue */
	W3D_A_EQUAL              =  7,  /* draw, if value == refvalue */
	W3D_A_ALWAYS             =  8   /* always draw */
} W3D_AlphaTestEnum;

/* Z buffer compare modes */
typedef enum {
	W3D_Z_NEVER              =  1,  /* discard incoming pixel */
	W3D_Z_LESS               =  2,  /* draw, if value < Z(Z_Buffer) */
	W3D_Z_GEQUAL             =  3,  /* draw, if value >= Z(Z_Buffer) */
	W3D_Z_LEQUAL             =  4,  /* draw, if value <= Z(Z_Buffer) */
	W3D_Z_GREATER            =  5,  /* draw, if value > Z(Z_Buffer) */
	W3D_Z_NOTEQUAL           =  6,  /* draw, if value != Z(Z_Buffer) */
	W3D_Z_EQUAL              =  7,  /* draw, if value == Z(Z_Buffer) */
	W3D_Z_ALWAYS             =  8   /* always draw */
} W3D_ZTestEnum;

/* logical operation modes */
typedef enum {
	W3D_LO_CLEAR             =  1,  /* dest = 0 */
	W3D_LO_AND               =  2,  /* dest = source & dest */
	W3D_LO_AND_REVERSE       =  3,  /* dest = source & !dest */
	W3D_LO_COPY              =  4,  /* dest = source */
	W3D_LO_AND_INVERTED      =  5,  /* dest = !source & dest */
	W3D_LO_NOOP              =  6,  /* dest = dest */
	W3D_LO_XOR               =  7,  /* dest = source ^ dest */
	W3D_LO_OR                =  8,  /* dest = source | dest */
	W3D_LO_NOR               =  9,  /* dest = !(source | dest) */
	W3D_LO_EQUIV             = 10,  /* dest = !(source ^ dest) */
	W3D_LO_INVERT            = 11,  /* dest = !dest */
	W3D_LO_OR_REVERSE        = 12,  /* dest = source | !dest */
	W3D_LO_COPY_INVERTED     = 13,  /* dest = !source */
	W3D_LO_OR_INVERTED       = 14,  /* dest = !source | dest */
	W3D_LO_NAND              = 15,  /* dest = !(source & dest) */
	W3D_LO_SET               = 16   /* dest = 1 */
} W3D_LogicOpEnum;

/* stencil test functions */
typedef enum {
	W3D_ST_NEVER             =  1,  /* don't draw pixel */
	W3D_ST_ALWAYS            =  2,  /* draw always */
	W3D_ST_LESS              =  3,  /* draw, if refvalue < ST */
	W3D_ST_LEQUAL            =  4,  /* draw, if refvalue <= ST */
	W3D_ST_EQUAL             =  5,  /* draw, if refvalue == ST */
	W3D_ST_GEQUAL            =  6,  /* draw, if refvalue >= ST */
	W3D_ST_GREATER           =  7,  /* draw, if refvalue > ST */
	W3D_ST_NOTEQUAL          =  8   /* draw, if refvalue != ST */
} W3D_StencilTestEnum;

/* Masks for query */
enum {
	W3D_ST_NEVER_BIT         = (1L << W3D_ST_NEVER),
	W3D_ST_ALWAYS_BIT        = (1L << W3D_ST_ALWAYS),
	W3D_ST_LESS_BIT          = (1L << W3D_ST_LESS),
	W3D_ST_LEQUAL_BIT        = (1L << W3D_ST_LEQUAL),
	W3D_ST_EQUAL_BIT         = (1L << W3D_ST_EQUAL),
	W3D_ST_GEQUAL_BIT        = (1L << W3D_ST_GEQUAL),
	W3D_ST_GREATER_BIT       = (1L << W3D_ST_GREATER),
	W3D_ST_NOTEQUAL_BIT      = (1L << W3D_ST_NOTEQUAL)
};

/* stencil test operations */
typedef enum {
	W3D_ST_KEEP              = 1,  /* keep stencil buffer value */
	W3D_ST_ZERO              = 2,  /* clear stencil buffer value */
	W3D_ST_REPLACE           = 3,  /* replace by reference value */
	W3D_ST_INCR              = 4,  /* increment */
	W3D_ST_DECR              = 5,  /* decrement */
	W3D_ST_INVERT            = 6,  /* invert bitwise */
	W3D_ST_INCR_WRAP         = 7,  /* increment with wrap */
	W3D_ST_DECR_WRAP         = 8   /* decrement with wrap */
} W3D_StencilOpEnum;

/* Masks for query */
enum {
	W3D_ST_KEEP_BIT          = (1L << W3D_ST_KEEP),
	W3D_ST_ZERO_BIT          = (1L << W3D_ST_ZERO),
	W3D_ST_REPLACE_BIT       = (1L << W3D_ST_REPLACE),
	W3D_ST_INCR_BIT          = (1L << W3D_ST_INCR),
	W3D_ST_DECR_BIT          = (1L << W3D_ST_DECR),
	W3D_ST_INVERT_BIT        = (1L << W3D_ST_INVERT),
	W3D_ST_INCR_WRAP_BIT     = (1L << W3D_ST_INCR_WRAP),
	W3D_ST_DECR_WRAP_BIT     = (1L << W3D_ST_DECR_WRAP)
};

/* chroma test modes */
typedef enum {
	W3D_CHROMATEST_NONE      = 1,      /* No chroma test */
	W3D_CHROMATEST_INCLUSIVE = 2,      /* texels in the range pass the test */
	W3D_CHROMATEST_EXCLUSIVE = 3       /* texels in the range are rejected */
} W3D_ChromaTestEnum;

/* error/status values */
typedef enum {
	W3D_SUCCESS              =   0,     /* success */
	W3D_BUSY                 =  -1,     /* graphics hardware is busy */
	W3D_ILLEGALINPUT         =  -2,     /* failure, illegal input */
	W3D_NOMEMORY             =  -3,     /* no memory available */
	W3D_NODRIVER             =  -4,     /* no hardware driver available */
	W3D_NOTEXTURE            =  -5,     /* texture is missing */
	W3D_TEXNOTRESIDENT       =  -6,     /* texture not resident */
	W3D_NOMIPMAPS            =  -7,     /* mipmaps are not supported by this
	                                       texture object */
	W3D_NOGFXMEM             =  -8,     /* no graphics memory available */
	W3D_NOTVISIBLE           =  -9,     /* drawing area not visible/ bitmap
	                                       swapped out */
	W3D_UNSUPPORTEDFILTER    = -10,     /* unsupported filter */
	W3D_UNSUPPORTEDTEXENV    = -11,     /* unsupported filter */
	W3D_UNSUPPORTEDWRAPMODE  = -12,     /* unsupported wrap mode */
	W3D_UNSUPPORTEDZCMP      = -13,     /* unsupported Z compare mode */
	W3D_UNSUPPORTEDATEST     = -14,     /* unsupported alpha test */
	W3D_UNSUPPORTEDBLEND     = -15,     /* unsupported blending function */
	W3D_UNSUPPORTEDFOG       = -16,     /* unsupported fog mode */
	W3D_UNSUPPORTEDSTATE     = -17,     /* can't enable/disable state */
	W3D_UNSUPPORTEDFMT       = -18,     /* unsupported bitmap format */
	W3D_UNSUPPORTEDTEXSIZE   = -19,     /* unsupported texture border size */
	W3D_UNSUPPORTEDLOGICOP   = -20,     /* unsupported logical operation */
	W3D_UNSUPPORTEDSTTEST    = -21,     /* unsupported stencil test */
	W3D_ILLEGALBITMAP        = -22,     /* illegal bitmap */
	W3D_NOZBUFFER            = -23,     /* Z buffer is missing/unavailable */
	W3D_NOPALETTE            = -24,     /* Palette missing for chunky
	                                       textures */
	W3D_MASKNOTSUPPORTED     = -25,     /* color/index masking not supported */
	W3D_NOSTENCILBUFFER      = -26,     /* Stencil buffer is
	                                       missing/unavailable */
	W3D_QUEUEFAILED          = -27,     /* The request can not be queued */
	W3D_UNSUPPORTEDTEXFMT    = -28,     /* Texformat unsupported */
	W3D_WARNING              = -29,     /* Parital success */
	W3D_UNSUPPORTED          = -30,     /* Requested feature is unsupported */
} W3D_ReturnValEnum;

/* Hints */
typedef enum {
	W3D_H_TEXMAPPING         = 1,       /* Quality of general texture mapping */
	W3D_H_MIPMAPPING         = 2,       /* Quality of mipmapping */
	W3D_H_BILINEARFILTER     = 3,       /* Quality of bilinear filtering */
	W3D_H_MMFILTER           = 4,       /* Quality of depth filter */
	W3D_H_PERSPECTIVE        = 5,       /* Quality of perspective correction */
	W3D_H_BLENDING           = 6,       /* Quality of alpha blending */
	W3D_H_FOGGING            = 7,       /* Quality of fogging */
	W3D_H_ANTIALIASING       = 8,       /* Quality of antialiasing */
	W3D_H_DITHERING          = 9,       /* Quality of dithering */
	W3D_H_ZBUFFER            = 10,      /* Quality of zbuffering */
	W3D_H_POINTDRAW          = 11,
} W3D_HintPropertyEnum;

/* Quality parameters */
typedef enum {
	W3D_H_FAST               = 1,       /* Low quality, fast rendering */
	W3D_H_AVERAGE            = 2,       /* Medium quality and speed */
	W3D_H_NICE               = 3        /* Best quality, low speed */
} W3D_HintQualityEnum;

/* ScreenMode Requester TagItems */
enum {
	W3D_SMR_TAGS             = (TAG_USER+0x202000),
	W3D_SMR_DRIVER           = (W3D_SMR_TAGS+0),    /* Driver to filter */
	W3D_SMR_DESTFMT          = (W3D_SMR_TAGS+1),    /* Dest Format to filter */
	W3D_SMR_TYPE             = (W3D_SMR_TAGS+2),    /* Type to filter */
	W3D_SMR_SIZEFILTER       = (W3D_SMR_TAGS+3),    /* Also filter size */
	W3D_SMR_MODEMASK         = (W3D_SMR_TAGS+4),    /* AND-Mask for modes */
};

/* BestModeID tag items */
enum {
	W3D_BMI_TAGS             = (TAG_USER+0x203000),
	W3D_BMI_DRIVER           = (W3D_BMI_TAGS+0),
	W3D_BMI_WIDTH            = (W3D_BMI_TAGS+1),
	W3D_BMI_HEIGHT           = (W3D_BMI_TAGS+2),
	W3D_BMI_DEPTH            = (W3D_BMI_TAGS+3)
};

/* Vertex Buffer defines */
enum {
	W3D_VERTEX_F_F_F         = 0,
	W3D_VERTEX_F_F_D         = 1,
	W3D_VERTEX_D_D_D         = 2
};

/* Color Buffer defines */
enum {
	W3D_COLOR_FLOAT          = (0x01<<30),
	W3D_COLOR_UBYTE          = (0x02<<30),

	W3D_CMODE_RGB            = 0x01,
	W3D_CMODE_BGR            = 0x02,
	W3D_CMODE_RGBA           = 0x04,
	W3D_CMODE_ARGB           = 0x08,
	W3D_CMODE_BGRA           = 0x10
};

/* Primitive types for W3D_DrawArray/W3D_DrawElements */
typedef enum {
	W3D_PRIMITIVE_TRIANGLES  = 0,
	W3D_PRIMITIVE_TRIFAN     = 1,
	W3D_PRIMITIVE_TRISTRIP   = 2,
	W3D_PRIMITIVE_POINTS     = 3,
	W3D_PRIMITIVE_LINES      = 4,
	W3D_PRIMITIVE_LINELOOP   = 5,
	W3D_PRIMITIVE_LINESTRIP  = 6
} W3D_PrimitiveTypeEnum;

/* Index array layout */
typedef enum {
	W3D_INDEX_UBYTE          = 0,
	W3D_INDEX_UWORD          = 1,
	W3D_INDEX_ULONG          = 2
} W3D_IndexTypeEnum;

/* TexCoordArray flags */
enum {
	W3D_TEXCOORD_NORMALIZED  = (1L<<0) /* Texture coordinates are normalized */
};

/* New for V5 - types for the fog coordinates */
enum {
	W3D_FOGCOORD_FLOAT       = 0,
	W3D_FOGCOORD_DOUBLE      = 1
};

/* Multitexture tags for W3D_SetTextureBlend */
enum {
	W3D_STB_TAGS             = (TAG_USER+0x204000),
	W3D_BLEND_STAGE          = (W3D_STB_TAGS+1),
	W3D_COLOR_ARG_A          = (W3D_STB_TAGS+2),
	W3D_COLOR_ARG_B          = (W3D_STB_TAGS+3),
	W3D_COLOR_ARG_C          = (W3D_STB_TAGS+4),
	W3D_ALPHA_ARG_A          = (W3D_STB_TAGS+5),
	W3D_ALPHA_ARG_B          = (W3D_STB_TAGS+6),
	W3D_ALPHA_ARG_C          = (W3D_STB_TAGS+7),
	W3D_COLOR_COMBINE        = (W3D_STB_TAGS+8),
	W3D_ALPHA_COMBINE        = (W3D_STB_TAGS+9),
	W3D_BLEND_FACTOR         = (W3D_STB_TAGS+10),
	W3D_COLOR_SCALE          = (W3D_STB_TAGS+11),
	W3D_ALPHA_SCALE          = (W3D_STB_TAGS+12),
	W3D_ENV_MODE             = (W3D_STB_TAGS+13)
};

/* Argument constants for W3D_SetTextureBlend */
typedef enum {
	W3D_ARG_PREVIOUS_COLOR   = 0,
	W3D_ARG_PREVIOUS_ALPHA   = 1,
	W3D_ARG_PREVIOUS         = 2,

	W3D_ARG_DIFFUSE_COLOR    = 3,
	W3D_ARG_DIFFUSE_ALPHA    = 4,
	W3D_ARG_DIFFUSE          = 5,

	W3D_ARG_TEXTURE_COLOR    = 6,
	W3D_ARG_TEXTURE_ALPHA    = 7,
	W3D_ARG_TEXTURE          = 8,

	W3D_ARG_TEXTURE0_COLOR   = 9,
	W3D_ARG_TEXTURE0_ALPHA   = 10,
	W3D_ARG_TEXTURE0         = 11,

	W3D_ARG_TEXTURE1_COLOR   = 12,
	W3D_ARG_TEXTURE1_ALPHA   = 13,
	W3D_ARG_TEXTURE1         = 14,

	W3D_ARG_TEXTURE2_COLOR   = 15,
	W3D_ARG_TEXTURE2_ALPHA   = 16,
	W3D_ARG_TEXTURE2         = 17,

	W3D_ARG_TEXTURE3_COLOR   = 18,
	W3D_ARG_TEXTURE3_ALPHA   = 19,
	W3D_ARG_TEXTURE3         = 20,

	W3D_ARG_TEXTURE4_COLOR   = 21,
	W3D_ARG_TEXTURE4_ALPHA   = 22,
	W3D_ARG_TEXTURE4         = 23,

	W3D_ARG_TEXTURE5_COLOR   = 24,
	W3D_ARG_TEXTURE5_ALPHA   = 25,
	W3D_ARG_TEXTURE5         = 26,

	W3D_ARG_TEXTURE6_COLOR   = 27,
	W3D_ARG_TEXTURE6_ALPHA   = 28,
	W3D_ARG_TEXTURE6         = 29,

	W3D_ARG_TEXTURE7_COLOR   = 30,
	W3D_ARG_TEXTURE7_ALPHA   = 31,
	W3D_ARG_TEXTURE7         = 32,

	W3D_ARG_TEXTURE8_COLOR   = 33,
	W3D_ARG_TEXTURE8_ALPHA   = 34,
	W3D_ARG_TEXTURE8         = 35,

	W3D_ARG_TEXTURE9_COLOR   = 36,
	W3D_ARG_TEXTURE9_ALPHA   = 37,
	W3D_ARG_TEXTURE9         = 38,

	W3D_ARG_TEXTURE10_COLOR  = 39,
	W3D_ARG_TEXTURE10_ALPHA  = 40,
	W3D_ARG_TEXTURE10        = 41,

	W3D_ARG_TEXTURE11_COLOR  = 42,
	W3D_ARG_TEXTURE11_ALPHA  = 43,
	W3D_ARG_TEXTURE11        = 44,

	W3D_ARG_TEXTURE12_COLOR  = 45,
	W3D_ARG_TEXTURE12_ALPHA  = 46,
	W3D_ARG_TEXTURE12        = 47,

	W3D_ARG_TEXTURE13_COLOR  = 48,
	W3D_ARG_TEXTURE13_ALPHA  = 49,
	W3D_ARG_TEXTURE13        = 50,

	W3D_ARG_TEXTURE14_COLOR  = 51,
	W3D_ARG_TEXTURE14_ALPHA  = 52,
	W3D_ARG_TEXTURE14        = 53,

	W3D_ARG_TEXTURE15_COLOR  = 54,
	W3D_ARG_TEXTURE15_ALPHA  = 55,
	W3D_ARG_TEXTURE15        = 56,

	W3D_ARG_SPECULAR_COLOR   = 57,
	W3D_ARG_SPECULAR_ALPHA   = 58,
	W3D_ARG_SPECULAR         = 59,

	W3D_ARG_FACTOR_COLOR     = 60,
	W3D_ARG_FACTOR_ALPHA     = 61,
	W3D_ARG_FACTOR           = 62,

	W3D_ARG_COMPLEMENT       = 0x80000000
} W3D_TextureBlendArgEnum;

/* Combiner arguments for W3D_SetTextureBlend */
typedef enum {
	W3D_COMBINE_DISABLED     = 0,
	W3D_COMBINE_SELECT_A     = 1,
	W3D_COMBINE_SELECT_B     = 2,
	W3D_COMBINE_SELECT_C     = 3,
	W3D_COMBINE_MODULATE     = 4,
	W3D_COMBINE_ADD          = 5,
	W3D_COMBINE_SUBTRACT     = 6,
	W3D_COMBINE_ADDSIGNED    = 7,
	W3D_COMBINE_INTERPOLATE  = 8,
	W3D_COMBINE_ACCUM        = 9,
	W3D_COMBINE_DOT3RGB      = 10,
	W3D_COMBINE_DOT3RGBA     = 11
} W3D_TextureBlendCombineEnum;

/* Format constants for the interleaved array */
typedef enum {
	W3D_VFORMAT_FOG          = (1<<0), /* Fog coordinate (1 float) */
	W3D_VFORMAT_COLOR        = (1<<1), /* primary color (4 floats RGBA) */
	W3D_VFORMAT_PACK_COLOR   = (1<<2), /* primary color (1 uint32 RGBA) */
	W3D_VFORMAT_SCOLOR       = (1<<3), /* secondary color (4 floats RGBA) */
	W3D_VFORMAT_PACK_SCOLOR  = (1<<4), /* secondary color (1 uint32 RGBA) */
	W3D_VFORMAT_TCOORD_0     = (1<<5), /* texture coordinate sets (3 floats per set, uvw) */
	W3D_VFORMAT_TCOORD_1     = (1<<6),
	W3D_VFORMAT_TCOORD_2     = (1<<7),
	W3D_VFORMAT_TCOORD_3     = (1<<8),
	W3D_VFORMAT_TCOORD_4     = (1<<9),
	W3D_VFORMAT_TCOORD_5     = (1<<10),
	W3D_VFORMAT_TCOORD_6     = (1<<11),
	W3D_VFORMAT_TCOORD_7     = (1<<12),
	W3D_VFORMAT_TCOORD_8     = (1<<13),
	W3D_VFORMAT_TCOORD_9     = (1<<14),
	W3D_VFORMAT_TCOORD_10    = (1<<15),
	W3D_VFORMAT_TCOORD_11    = (1<<16),
	W3D_VFORMAT_TCOORD_12    = (1<<17),
	W3D_VFORMAT_TCOORD_13    = (1<<18),
	W3D_VFORMAT_TCOORD_14    = (1<<19),
	W3D_VFORMAT_TCOORD_15    = (1<<20),
	W3D_VFORMAT_FOG_FACTOR   = (1<<21)
} W3D_InterleavedVertexDefFlagEnum;

/* Parameter "targets" */
typedef enum {
	W3D_STIPPLE_LINE         =  0,
	W3D_STIPPLE_LINE_FACTOR  =  1,
	W3D_STIPPLE_POLYGON      =  2,
	W3D_POINT_SIZE           =  3,
	W3D_LINE_WIDTH           =  4,
	W3D_ZFOG_START           =  5,
	W3D_ZFOG_END             =  6,
	W3D_ZFOG_DENSITY         =  7,
	W3D_FOG_MODE             =  8,
	W3D_FOG_COLOR            =  9,
	W3D_WFOG_START           = 10,
	W3D_WFOG_END             = 11,
	W3D_WFOG_DENSITY         = 12
} W3D_ParameterTargetEnum;

/* Fogging mode constants */
typedef enum {
	W3D_FOG_Z_LINEAR         = 0,
	W3D_FOG_Z_EXP            = 1,
	W3D_FOG_Z_EXP_2          = 2,
	W3D_FOG_W_LINEAR         = 3,
	W3D_FOG_W_EXP            = 4,
	W3D_FOG_W_EXP_2          = 5
} W3D_FogModeEnum;

/* Possible local buffer types */
typedef enum {
	W3D_ZUINT16_SNONE   = 0,
	W3D_ZUINT24_SUINT8  = 1,
	W3D_ZFLOAT24_SUINT8 = 2,
	W3D_ZUINT32_SNONE   = 3,
	W3D_ZFLOAT32_SNONE  = 4
} W3D_DepthBufferTypeEnum;

/* flags reported by local buffer query  */
enum {
	W3D_ZUINT16_SNONE_BIT   = (1UL<<W3D_ZUINT16_SNONE),
	W3D_ZUINT24_SUINT8_BIT  = (1UL<<W3D_ZUINT24_SUINT8),
	W3D_ZFLOAT24_SUINT8_BIT = (1UL<<W3D_ZFLOAT24_SUINT8),
	W3D_ZUINT32_SNONE_BIT   = (1UL<<W3D_ZUINT32_SNONE),
	W3D_ZFLOAT32_SNONE_BIT  = (1UL<<W3D_ZFLOAT32_SNONE)
};

#ifdef __GNUC__
	#ifdef __PPC__
		#pragma pack()
	#endif
#elif defined(__VBCC__)
	#pragma default-align
#elif defined(__SASC)
	#pragma msg 79 pop
#endif

#ifdef __cplusplus
}
#endif

#endif
