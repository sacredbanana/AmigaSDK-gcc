/* 

 SDL_gfxBlitFunc: custom blitters (part of SDL_gfx library)

 LGPL (c) A. Schiffler
 
*/

#ifndef _SDL_gfxBlitFunc_h
#define _SDL_gfxBlitFunc_h

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern    "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_video.h>

/* -------- Prototypes */

#ifdef WIN32
#ifdef BUILD_DLL
#define DLLINTERFACE __declspec(dllexport)
#else
#define DLLINTERFACE __declspec(dllimport)
#endif
#else
#define DLLINTERFACE
#endif


DLLINTERFACE int  SDL_gfxBlitRGBA(SDL_Surface * src, SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect);

DLLINTERFACE  int SDL_gfxSetAlpha(SDL_Surface * src, Uint8 a);


/* -------- Macros */

/* Define SDL macros locally as a substitute for a #include "SDL_blit.h", */

/* which doesn't work since the include file doesn't get installed.       */

/* The structure passed to the low level blit functions */
  typedef struct {
    Uint8    *s_pixels;
    int       s_width;
    int       s_height;
    int       s_skip;
    Uint8    *d_pixels;
    int       d_width;
    int       d_height;
    int       d_skip;
    void     *aux_data;
    SDL_PixelFormat *src;
    Uint8    *table;
    SDL_PixelFormat *dst;
  } SDL_gfxBlitInfo;

#define GFX_RGBA_FROM_PIXEL(pixel, fmt, r, g, b, a)				\
{									\
	r = ((pixel&fmt->Rmask)>>fmt->Rshift)<<fmt->Rloss; 		\
	g = ((pixel&fmt->Gmask)>>fmt->Gshift)<<fmt->Gloss; 		\
	b = ((pixel&fmt->Bmask)>>fmt->Bshift)<<fmt->Bloss; 		\
	a = ((pixel&fmt->Amask)>>fmt->Ashift)<<fmt->Aloss;	 	\
}

#define GFX_DISEMBLE_RGBA(buf, bpp, fmt, pixel, r, g, b, a)			   \
do {									   \
	pixel = *((Uint32 *)(buf));			   		   \
	GFX_RGBA_FROM_PIXEL(pixel, fmt, r, g, b, a);			   \
	pixel &= ~fmt->Amask;						   \
} while(0)

#define GFX_PIXEL_FROM_RGBA(pixel, fmt, r, g, b, a)				\
{									\
	pixel = ((r>>fmt->Rloss)<<fmt->Rshift)|				\
		((g>>fmt->Gloss)<<fmt->Gshift)|				\
		((b>>fmt->Bloss)<<fmt->Bshift)|				\
		((a<<fmt->Aloss)<<fmt->Ashift);				\
}

#define GFX_ASSEMBLE_RGBA(buf, bpp, fmt, r, g, b, a)			\
{									\
			Uint32 pixel;					\
									\
			GFX_PIXEL_FROM_RGBA(pixel, fmt, r, g, b, a);	\
			*((Uint32 *)(buf)) = pixel;			\
}

/* Blend the RGB values of two pixels based on a source alpha value */
#define GFX_ALPHA_BLEND(sR, sG, sB, A, dR, dG, dB)	\
do {						\
	dR = (((sR-dR)*(A))/255)+dR;		\
	dG = (((sG-dG)*(A))/255)+dG;		\
	dB = (((sB-dB)*(A))/255)+dB;		\
} while(0)

/* This is a very useful loop for optimizing blitters */

/* 4-times unrolled loop */
#define GFX_DUFFS_LOOP4(pixel_copy_increment, width)			\
{ int n = (width+3)/4;							\
	switch (width & 3) {						\
	case 0: do {	pixel_copy_increment;				\
	case 3:		pixel_copy_increment;				\
	case 2:		pixel_copy_increment;				\
	case 1:		pixel_copy_increment;				\
		} while ( --n > 0 );					\
	}								\
}

/* -------- Alpha adjustment table, modified transfer function --------  */

static const
unsigned int GFX_ALPHA_ADJUST[256] = {
 0,  /* 0 */
 15,  /* 1 */
 22,  /* 2 */
 27,  /* 3 */
 31,  /* 4 */
 35,  /* 5 */
 39,  /* 6 */
 42,  /* 7 */
 45,  /* 8 */
 47,  /* 9 */
 50,  /* 10 */
 52,  /* 11 */
 55,  /* 12 */
 57,  /* 13 */
 59,  /* 14 */
 61,  /* 15 */
 63,  /* 16 */
 65,  /* 17 */
 67,  /* 18 */
 69,  /* 19 */
 71,  /* 20 */
 73,  /* 21 */
 74,  /* 22 */
 76,  /* 23 */
 78,  /* 24 */
 79,  /* 25 */
 81,  /* 26 */
 82,  /* 27 */
 84,  /* 28 */
 85,  /* 29 */
 87,  /* 30 */
 88,  /* 31 */
 90,  /* 32 */
 91,  /* 33 */
 93,  /* 34 */
 94,  /* 35 */
 95,  /* 36 */
 97,  /* 37 */
 98,  /* 38 */
 99,  /* 39 */
 100,  /* 40 */
 102,  /* 41 */
 103,  /* 42 */
 104,  /* 43 */
 105,  /* 44 */
 107,  /* 45 */
 108,  /* 46 */
 109,  /* 47 */
 110,  /* 48 */
 111,  /* 49 */
 112,  /* 50 */
 114,  /* 51 */
 115,  /* 52 */
 116,  /* 53 */
 117,  /* 54 */
 118,  /* 55 */
 119,  /* 56 */
 120,  /* 57 */
 121,  /* 58 */
 122,  /* 59 */
 123,  /* 60 */
 124,  /* 61 */
 125,  /* 62 */
 126,  /* 63 */
 127,  /* 64 */
 128,  /* 65 */
 129,  /* 66 */
 130,  /* 67 */
 131,  /* 68 */
 132,  /* 69 */
 133,  /* 70 */
 134,  /* 71 */
 135,  /* 72 */
 136,  /* 73 */
 137,  /* 74 */
 138,  /* 75 */
 139,  /* 76 */
 140,  /* 77 */
 141,  /* 78 */
 141,  /* 79 */
 142,  /* 80 */
 143,  /* 81 */
 144,  /* 82 */
 145,  /* 83 */
 146,  /* 84 */
 147,  /* 85 */
 148,  /* 86 */
 148,  /* 87 */
 149,  /* 88 */
 150,  /* 89 */
 151,  /* 90 */
 152,  /* 91 */
 153,  /* 92 */
 153,  /* 93 */
 154,  /* 94 */
 155,  /* 95 */
 156,  /* 96 */
 157,  /* 97 */
 158,  /* 98 */
 158,  /* 99 */
 159,  /* 100 */
 160,  /* 101 */
 161,  /* 102 */
 162,  /* 103 */
 162,  /* 104 */
 163,  /* 105 */
 164,  /* 106 */
 165,  /* 107 */
 165,  /* 108 */
 166,  /* 109 */
 167,  /* 110 */
 168,  /* 111 */
 168,  /* 112 */
 169,  /* 113 */
 170,  /* 114 */
 171,  /* 115 */
 171,  /* 116 */
 172,  /* 117 */
 173,  /* 118 */
 174,  /* 119 */
 174,  /* 120 */
 175,  /* 121 */
 176,  /* 122 */
 177,  /* 123 */
 177,  /* 124 */
 178,  /* 125 */
 179,  /* 126 */
 179,  /* 127 */
 180,  /* 128 */
 181,  /* 129 */
 182,  /* 130 */
 182,  /* 131 */
 183,  /* 132 */
 184,  /* 133 */
 184,  /* 134 */
 185,  /* 135 */
 186,  /* 136 */
 186,  /* 137 */
 187,  /* 138 */
 188,  /* 139 */
 188,  /* 140 */
 189,  /* 141 */
 190,  /* 142 */
 190,  /* 143 */
 191,  /* 144 */
 192,  /* 145 */
 192,  /* 146 */
 193,  /* 147 */
 194,  /* 148 */
 194,  /* 149 */
 195,  /* 150 */
 196,  /* 151 */
 196,  /* 152 */
 197,  /* 153 */
 198,  /* 154 */
 198,  /* 155 */
 199,  /* 156 */
 200,  /* 157 */
 200,  /* 158 */
 201,  /* 159 */
 201,  /* 160 */
 202,  /* 161 */
 203,  /* 162 */
 203,  /* 163 */
 204,  /* 164 */
 205,  /* 165 */
 205,  /* 166 */
 206,  /* 167 */
 206,  /* 168 */
 207,  /* 169 */
 208,  /* 170 */
 208,  /* 171 */
 209,  /* 172 */
 210,  /* 173 */
 210,  /* 174 */
 211,  /* 175 */
 211,  /* 176 */
 212,  /* 177 */
 213,  /* 178 */
 213,  /* 179 */
 214,  /* 180 */
 214,  /* 181 */
 215,  /* 182 */
 216,  /* 183 */
 216,  /* 184 */
 217,  /* 185 */
 217,  /* 186 */
 218,  /* 187 */
 218,  /* 188 */
 219,  /* 189 */
 220,  /* 190 */
 220,  /* 191 */
 221,  /* 192 */
 221,  /* 193 */
 222,  /* 194 */
 222,  /* 195 */
 223,  /* 196 */
 224,  /* 197 */
 224,  /* 198 */
 225,  /* 199 */
 225,  /* 200 */
 226,  /* 201 */
 226,  /* 202 */
 227,  /* 203 */
 228,  /* 204 */
 228,  /* 205 */
 229,  /* 206 */
 229,  /* 207 */
 230,  /* 208 */
 230,  /* 209 */
 231,  /* 210 */
 231,  /* 211 */
 232,  /* 212 */
 233,  /* 213 */
 233,  /* 214 */
 234,  /* 215 */
 234,  /* 216 */
 235,  /* 217 */
 235,  /* 218 */
 236,  /* 219 */
 236,  /* 220 */
 237,  /* 221 */
 237,  /* 222 */
 238,  /* 223 */
 238,  /* 224 */
 239,  /* 225 */
 240,  /* 226 */
 240,  /* 227 */
 241,  /* 228 */
 241,  /* 229 */
 242,  /* 230 */
 242,  /* 231 */
 243,  /* 232 */
 243,  /* 233 */
 244,  /* 234 */
 244,  /* 235 */
 245,  /* 236 */
 245,  /* 237 */
 246,  /* 238 */
 246,  /* 239 */
 247,  /* 240 */
 247,  /* 241 */
 248,  /* 242 */
 248,  /* 243 */
 249,  /* 244 */
 249,  /* 245 */
 250,  /* 246 */
 250,  /* 247 */
 251,  /* 248 */
 251,  /* 249 */
 252,  /* 250 */
 252,  /* 251 */
 253,  /* 252 */
 253,  /* 253 */
 254,  /* 254 */
 255   /* 255 */
 };


/* --- */

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif

#endif /* _SDL_gfxBlitFunc_h */

#ifndef	PROTO_POWERSDL_GFX_H
#include	<proto/powersdl_gfx.h>
#endif
