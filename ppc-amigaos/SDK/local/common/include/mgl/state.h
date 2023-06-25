/*
 * $Id$
 *
 * $Date$
 * $Revision$
 *
 * (C) 1999 by Hyperion
 * All rights reserved
 *
 * This file is part of the MiniGL library project
 * See the file Licence.txt for more details
 *
 */

#ifndef STATE_H_
#define STATE_H_

#include "mgl/mgltypes.h"

/* General state record */
struct GLstate
{
	uint32 bits;
};

/* State records for different state groups */

/* COLOR_BUFFER_BIT */
struct GLcolor_buffer_state
{
	struct GLstate	state;

	GLuint			ClearColor;
	W3D_Color		ClearColorRec;
	GLenum			BlendSrc;
	GLenum			BlendDst;
	GLboolean		WriteMaskRed;
	GLboolean		WriteMaskGreen;
	GLboolean		WriteMaskBlue;
	GLboolean		WriteMaskAlpha;

	GLenum			DrawBuffer;
	GLenum			ReadBuffer;

	GLenum			LogicOpMode;

	GLenum			AlphaTestFunc;
	GLclampf		AlphaTestRef;
};


/* CURRENT_BIT */
struct GLcurrent_state
{
	struct GLstate	state;

	MGLColor		CurrentColor;
	MGLNormal		CurrentNormal;
	GLfloat			CurrentFogDepth;

	GLfloat			CurTexS[MAX_TEXTURE_UNITS];
	GLfloat			CurTexT[MAX_TEXTURE_UNITS];
	GLfloat			CurTexQ[MAX_TEXTURE_UNITS];
	GLboolean   	CurTexQValid[MAX_TEXTURE_UNITS];

	MGLPosition 	RasterPos;
	GLfloat			RasterDistance;
	W3D_Color		RasterColor;
	struct MGLTexCoordSet_t
					RasterTexCoords[MAX_TEXTURE_UNITS];
	GLboolean		RasterRhwValid[MAX_TEXTURE_UNITS];
	GLboolean		RasterPosValid;
};


/* DEPTH_BUFFER_BIT */
struct GLdepth_buffer_state
{
	struct GLstate	state;

	W3D_Double		ClearDepth;
	GLboolean		DepthWriteMask;
	GLfloat			ZOffset;

	GLenum			DepthFunc;

};


/* ENABLE_BIT */
struct GLenable_state
{
	struct GLstate	state;
													/* Also affected by this bit */
	GLboolean   	AlphaTest;						/* COLOR_BUFFER_BIT */
	GLboolean   	Blend;							/* COLOR_BUFFER_BIT */
	GLboolean   	Dither;							/* COLOR_BUFFER_BIT */
	GLboolean   	Fog;							/* FOG_BIT */
	GLboolean   	ScissorTest;					/* SCISSOR_BIT */
	GLboolean   	CullFace;						/* POLYGON_BIT */
	GLboolean		PolygonSmooth;					/* POLYGON_BIT */
	GLboolean		PolygonStipple;					/* POLYGON_BIT */
	GLboolean		PolygonOffsetFill;				/* POLYGON_BIT */
	GLboolean   	DepthTest;						/* DEPTH_BUFFER_BIT */
	GLboolean   	ZOffset;						/* MGL specific, DEPTH_BIT */
	GLboolean   	PointSmooth;					/* POINT_BIT */
	GLboolean		LineSmooth;						/* LINE_BIT */
	GLboolean		LineStipple;					/* LINE_BIT */
	GLboolean   	Texture1D[MAX_TEXTURE_UNITS];	/* TEXTURE_BIT */
	GLboolean   	Texture2D[MAX_TEXTURE_UNITS];	/* TEXTURE_BIT */
	GLboolean		TexGenS[MAX_TEXTURE_UNITS];		/* TEXTURE_BIT */
	GLboolean		TexGenT[MAX_TEXTURE_UNITS];		/* TEXTURE_BIT */
	GLboolean		TexGenQ[MAX_TEXTURE_UNITS];		/* TEXTURE_BIT */
	GLboolean		TexGen;							/* OR of all TexGenX */
	GLboolean		Lighting;						/* LIGHTING_BIT */
	GLboolean		ColorMaterial;					/* LIGHTING_BIT */
	GLboolean		Light[MGL_MAX_LIGHTS];			/* LIGHTING_BIT */
	GLboolean		ClipPlane[MGL_MAX_CLIPPLANES];	/* TRANSFORM_BIT */
	GLboolean		StencilTest;					/* STENCIL_BUFFER_BIT */
	GLboolean		Map1[MGL_NUM_EVALUATORS];		/* EVAL_BIT */
	GLboolean		Map2[MGL_NUM_EVALUATORS];		/* EVAL_BIT */
	GLboolean		AutoNormal;						/* EVAL_BIT */
	GLboolean		ColorLogicOp;					/* COLOR_BUFFER_BIT */
};


/* FOG_BIT */
struct GLfog_state
{
	struct GLstate	state;

	GLenum		CurrentFogSource;

	GLdouble    FogStart;
	GLdouble    FogEnd;
	GLdouble	FogDensity; // For Z-Fog only
	GLenum	 	FogMode;
	MGLColor	FogColor;
};


/* HINT_BIT */
struct GLhint_state
{
	struct GLstate	state;
};


/* LIGHTING_BIT */
struct GLlighting_state
{
	struct GLstate	state;

	GLenum			ShadeModel;
	MGLColor		LightModelAmbient;
	GLboolean		LightModelLocalViewer;
	GLboolean		LightModelTwoSide;
	GLenum			LightModelColorControl;
	GLenum			ColorMaterialParameter;
	GLenum			ColorMaterialFace;
	GLmaterial		Material[2];

	GLlight			Light[MGL_MAX_LIGHTS];
	GLint			MaxLight;						/* Max enabled light */
};


/* LINE_BIT */
struct GLline_state
{
	struct GLstate	state;

	GLfloat			LineWidth;
};



/* POINT_BIT */
struct GLpoint_state
{
	struct GLstate	state;

	GLfloat			PointSize;
};


/* POLYGON_BIT */
struct GLpolygon_state
{
	struct GLstate	state;

	GLenum			CullFace;
	GLenum			FrontFace;
	GLfloat			PolygonOffsetFactor;
	GLfloat			PolygonOffsetUnits;
	GLint 			PolygonModeFront;
	GLint			PolygonModeBack;
};


/* POLYGON_STIPPLE_BIT */
struct GLpolygon_stipple_state
{
	struct GLstate	state;

	GLuint			pattern[32];
};


/* SCISSOR_BIT */
struct GLscissor_state
{
	struct GLstate	state;

	GLint			x;
	GLint			y;
	GLsizei			w;
	GLsizei			h;
};


/* STENCIL_BUFFER_BIT */
struct GLstencil_buffer_state
{
	struct GLstate	state;

	GLint		ClearStencil;

};


/* TEXTURE_BIT */
struct GLtexture_state
{
	struct GLstate	state;

	GLint			ActiveTexture;
	GLint			MaxTextureUnit;	/* Used as an upper bound for enabled texture
									 * units, for speed reasons (hclip.c). This
									 * is -1 for no texture unit enabled
									 */

	GLenum			TextureEnv[MAX_TEXTURE_UNITS];
	GLenum			MinFilter;
	GLenum			MagFilter;
	GLint       MaxAnisotropy;
	GLenum			WrapS;
	GLenum			WrapT;
	GLenum			colorCombine[MAX_TEXTURE_UNITS];
	GLenum			alphaCombine[MAX_TEXTURE_UNITS];
	GLenum			colorSource[3][MAX_TEXTURE_UNITS];
	GLenum			alphaSource[3][MAX_TEXTURE_UNITS];
	GLenum			colorOperand[3][MAX_TEXTURE_UNITS];
	GLenum			alphaOperand[3][MAX_TEXTURE_UNITS];
	GLuint			colorScale[MAX_TEXTURE_UNITS];
	GLuint			alphaScale[MAX_TEXTURE_UNITS];
	W3D_Color		envColor[MAX_TEXTURE_UNITS];

	GLtexgen		TexGenS[MAX_TEXTURE_UNITS];
	GLtexgen		TexGenT[MAX_TEXTURE_UNITS];
	GLtexgen		TexGenQ[MAX_TEXTURE_UNITS];

	GLint			CurrentBinding[MAX_TEXTURE_UNITS];
};


/* TRANSFORM_BIT */
struct GLtransform_state
{
	struct GLstate	state;

	GLint		MaxClipPlane;
	GLclipplane	UserClipPlane[MGL_MAX_CLIPPLANES];
	GLuint      CurrentMatrixMode;
};


/* VIEWPORT_BIT */
struct GLviewport_state
{
	struct GLstate	state;

	GLint			x;
	GLint			y;
	GLsizei			w;
	GLsizei			h;
	GLdouble		near;
	GLdouble		far;
};


/* CLIENT_VERTEX_ARRAY_BIT */
struct GLvertex_array_state
{
	struct GLstate	state;

	GLbitfield      ClientState;        /* Current client state mask */
	GLarray         TexCoordArray[MAX_TEXTURE_UNITS];
	GLarray         ColorArray;         /* Current arrays */
	GLarray			NormalArray;
	GLarray         VertexArray;
	GLuint			ClientActiveTexture;

	DrawElementsFn  DrawElementsHook;   /* Function pointers. These will depend on the state */
	DrawArraysFn    DrawArraysHook;
};


/* CLIENT_PIXEL_STORE_BIT */
struct GLpixel_store_state
{
	struct GLstate	state;

	GLpixel_store	pack;
	GLpixel_store	unpack;
};

/* PIXEL_BIT */
struct GLpixel_state
{
	struct GLstate	state;

	GLboolean		map_color;
	GLboolean		map_stencil;
	GLfloat			alpha_scale;
	GLfloat			blue_scale;
	GLfloat			green_scale;
	GLfloat			red_scale;
	GLfloat			depth_scale;
	GLfloat			alpha_bias;
	GLfloat			blue_bias;
	GLfloat			green_bias;
	GLfloat			red_bias;
	GLfloat			depth_bias;
	GLfloat			zoom_x;
	GLfloat			zoom_y;
	GLboolean		pixel_state_neutral; // indicates that all scale bias and zoom values are at their default states
};


/* EVAL_BIT */
struct GLeval_state
{
	struct GLstate	state;

	GLevalgrid		u1;				/* Domain for one-dimensional grid */
	GLevalgrid		u2, v2;			/* Domains for two-dimensional grid */

	GLboolean		EnableSummary;	/* True if any map is enabled */
};


#endif /*STATE_H_*/
