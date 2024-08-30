/*
 * $Id: config.h 530 2018-05-04 18:11:52Z dmuessener $
 *
 * $Date: 2018-05-04 21:11:52 +0300 (Fri, 04 May 2018) $
 * $Revision: 530 $
 *
 * (C) 1999 by Hyperion
 * All rights reserved
 *
 * This file is part of the MiniGL library project
 * See the file Licence.txt for more details
 *
 */

#ifndef __GLCONFIG_H
#define __GLCONFIG_H

// Stack sizes of the different matrix stacks
#define MGL_MODELVIEW_STACK_SIZE   40
#define MGL_PROJECTION_STACK_SIZE  10
#define MGL_TEXTURE_STACK_SIZE     10

// Stack size for attribute stack
#define MGL_ATTRIB_STACK_SIZE 30

// Stack size for the name stack
#define NAME_STACK_SIZE 40

// define this to make mglLockMode available
#define AUTOMATIC_LOCKING_ENABLE 1
#define PREFER_SMART_LOCK 1

// Define this is you don't want the ability to log GL calls
#define NLOGGING 1

// Define if you don't want debugging
#define GLNDEBUG 1

// Define if you don't want the compatibility macros
#ifndef __VBCC__
#define NO_GL_MACROS 1
#endif

// Define if you want to use inline functions for compatibility.
// Only valid if NO_GL_MACROS is also defined
#ifndef __VBCC__
#define USE_GL_INLINES 1
#endif

// Define if you don't want to check if the bitmaps allocated for
// screen buffering are cybergraphics bitmaps
#define NCGXDEBUG 1

// define if you don't want to draw anything
// #define NODRAW

// Maximum number of vertices a primitive can have
// Raise this value if needed, but this *should* really be enough.
#define MGL_MAXVERTS 2048

// Maximum number of texture units
#define MAX_TEXTURE_UNITS	4

// Define if you want OpenGL lighting to be compiled
#define MGL_USE_LIGHTING

// Maximum number of Lights
#define MGL_MAX_LIGHTS			8

// Maximum number of supported user clipplanes
#define MGL_MAX_CLIPPLANES		6

// Maximum order of evaluation
#define MGL_MAX_EVAL_ORDER		20

// Use exact squareroot function
#define MGL_USE_EXACT_SQRT  0

// Implement compiled vertex arrays (buggy and incomplete)
#define MGL_COMPILED_VERTEX_ARRAYS 1

// Speedup hack for Quake 3
#define QUAKE3_HACK 1

// Compile for yet unreleased Warp3D extensions
#define MGL_NEW_WARP3D  1

// Number of AUX buffers
#define MGL_MAX_AUX_BUFFERS	4

// Compile for performance profiling (use this for debug builds only)
//#define MGL_PROFILING

// Implement S3TC texture compressionn
#define MGL_TEXTURE_COMPRESSION 1

// Compile with Altivec support
#define MGL_USE_ALTIVEC 1

// Enable A1222 SPE compilation
// (usually you'd put this in your makefile)
// #define MGL_TABOR

// Create afull native SPE build for use with native SPE client programs
// by disabling the PPC-ABI -> SPE-ABI bridge code
// (usually you'd put this in your makefile)
// #define MGL_TABOR_NO_ABI_BRIDGE

// Define this if you don't link against a SPE compiled newlib.
// (usually you'd put this in your makefile)
// #define MGL_HAS_NO_SPE_NEWLIB

// Disable Altivec compile for A1222
#ifdef MGL_TABOR
	#undef MGL_USE_ALTIVEC
	#undef MGL_TEXTURE_COMPRESSION
	//#undef PREFER_SMART_LOCK
#else
	#undef MGL_TABOR_NO_ABI_BRIDGE
	#undef MGL_HAS_NO_SPE_NEWLIB
#endif

#endif
