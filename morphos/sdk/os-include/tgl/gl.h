#ifndef GL_H
#define GL_H

#include <stddef.h>
#include <inttypes.h>

/*
 * The following constants come from Mesa
 */

#define GL_VERSION_1_1 1

#ifdef __cplusplus
extern "C" {
#endif

enum {
	/* Boolean values */
	GL_FALSE			= 0,
	GL_TRUE				= 1,

	/* Data types */
	GL_BYTE				= 0x1400,
	GL_UNSIGNED_BYTE		= 0x1401,
	GL_SHORT			= 0x1402,
	GL_UNSIGNED_SHORT		= 0x1403,
	GL_INT				= 0x1404,
	GL_UNSIGNED_INT			= 0x1405,
	GL_FLOAT			= 0x1406,
	GL_DOUBLE			= 0x140A,
	GL_2_BYTES			= 0x1407,
	GL_3_BYTES			= 0x1408,
	GL_4_BYTES			= 0x1409,

	/* Primitives */
	GL_POINTS			= 0x0000,
	GL_LINES			= 0x0001,
	GL_LINE_LOOP			= 0x0002,
	GL_LINE_STRIP			= 0x0003,
	GL_TRIANGLES			= 0x0004,
	GL_TRIANGLE_STRIP		= 0x0005,
	GL_TRIANGLE_FAN			= 0x0006,
	GL_QUADS			= 0x0007,
	GL_QUAD_STRIP			= 0x0008,
	GL_POLYGON			= 0x0009,
	GL_EDGE_FLAG			= 0x0B43,

	/* Vertex Arrays */
	GL_VERTEX_ARRAY			= 0x8074,
	GL_NORMAL_ARRAY			= 0x8075,
	GL_COLOR_ARRAY			= 0x8076,
	GL_INDEX_ARRAY			= 0x8077,
	GL_TEXTURE_COORD_ARRAY		= 0x8078,
	GL_EDGE_FLAG_ARRAY		= 0x8079,
	GL_VERTEX_ARRAY_SIZE		= 0x807A,
	GL_VERTEX_ARRAY_TYPE		= 0x807B,
	GL_VERTEX_ARRAY_STRIDE		= 0x807C,
	GL_VERTEX_ARRAY_COUNT		= 0x807D,
	GL_NORMAL_ARRAY_TYPE		= 0x807E,
	GL_NORMAL_ARRAY_STRIDE		= 0x807F,
	GL_NORMAL_ARRAY_COUNT		= 0x8080,
	GL_COLOR_ARRAY_SIZE		= 0x8081,
	GL_COLOR_ARRAY_TYPE		= 0x8082,
	GL_COLOR_ARRAY_STRIDE		= 0x8083,
	GL_COLOR_ARRAY_COUNT		= 0x8084,
	GL_INDEX_ARRAY_TYPE		= 0x8085,
	GL_INDEX_ARRAY_STRIDE		= 0x8086,
	GL_INDEX_ARRAY_COUNT		= 0x8087,
	GL_TEXTURE_COORD_ARRAY_SIZE	= 0x8088,
	GL_TEXTURE_COORD_ARRAY_TYPE	= 0x8089,
	GL_TEXTURE_COORD_ARRAY_STRIDE	= 0x808A,
	GL_TEXTURE_COORD_ARRAY_COUNT	= 0x808B,
	GL_EDGE_FLAG_ARRAY_STRIDE	= 0x808C,
	GL_EDGE_FLAG_ARRAY_COUNT	= 0x808D,
	GL_VERTEX_ARRAY_POINTER		= 0x808E,
	GL_NORMAL_ARRAY_POINTER		= 0x808F,
	GL_COLOR_ARRAY_POINTER		= 0x8090,
	GL_INDEX_ARRAY_POINTER		= 0x8091,
	GL_TEXTURE_COORD_ARRAY_POINTER	= 0x8092,
	GL_EDGE_FLAG_ARRAY_POINTER	= 0x8093,
        GL_V2F				= 0x2A20,
	GL_V3F				= 0x2A21,
	GL_C4UB_V2F			= 0x2A22,
	GL_C4UB_V3F			= 0x2A23,
	GL_C3F_V3F			= 0x2A24,
	GL_N3F_V3F			= 0x2A25,
	GL_C4F_N3F_V3F			= 0x2A26,
	GL_T2F_V3F			= 0x2A27,
	GL_T4F_V4F			= 0x2A28,
	GL_T2F_C4UB_V3F			= 0x2A29,
	GL_T2F_C3F_V3F			= 0x2A2A,
	GL_T2F_N3F_V3F			= 0x2A2B,
	GL_T2F_C4F_N3F_V3F		= 0x2A2C,
	GL_T4F_C4F_N3F_V4F		= 0x2A2D,

	GL_MAX_ELEMENTS_VERTICES = 0x80E8,
	GL_MAX_ELEMENTS_INDICES  = 0x80E9,


	/* Matrix Mode */
	GL_MATRIX_MODE			= 0x0BA0,
	GL_MODELVIEW			= 0x1700,
	GL_PROJECTION			= 0x1701,
	GL_TEXTURE			= 0x1702,

	/* Points */
	GL_POINT_SMOOTH			= 0x0B10,
	GL_POINT_SIZE			= 0x0B11,
	GL_POINT_SIZE_GRANULARITY 	= 0x0B13,
	GL_POINT_SIZE_RANGE		= 0x0B12,

	/* Lines */
	GL_LINE_SMOOTH			= 0x0B20,
	GL_LINE_STIPPLE			= 0x0B24,
	GL_LINE_STIPPLE_PATTERN		= 0x0B25,
	GL_LINE_STIPPLE_REPEAT		= 0x0B26,
	GL_LINE_WIDTH			= 0x0B21,
	GL_LINE_WIDTH_GRANULARITY	= 0x0B23,
	GL_LINE_WIDTH_RANGE		= 0x0B22,

	/* Polygons */
	GL_POINT			= 0x1B00,
	GL_LINE				= 0x1B01,
	GL_FILL				= 0x1B02,
	GL_CCW				= 0x0901,
	GL_CW				= 0x0900,
	GL_FRONT			= 0x0404,
	GL_BACK				= 0x0405,
	GL_CULL_FACE			= 0x0B44,
	GL_CULL_FACE_MODE		= 0x0B45,
	GL_POLYGON_SMOOTH		= 0x0B41,
	GL_POLYGON_STIPPLE		= 0x0B42,
	GL_FRONT_FACE			= 0x0B46,
	GL_POLYGON_MODE			= 0x0B40,
	GL_POLYGON_OFFSET_FACTOR	= 0x3038,
	GL_POLYGON_OFFSET_UNITS		= 0x2A00,
	GL_POLYGON_OFFSET_POINT		= 0x2A01,
	GL_POLYGON_OFFSET_LINE		= 0x2A02,
	GL_POLYGON_OFFSET_FILL		= 0x8037,

	/* Display Lists */
	GL_COMPILE			= 0x1300,
	GL_COMPILE_AND_EXECUTE		= 0x1301,
	GL_LIST_BASE			= 0x0B32,
	GL_LIST_INDEX			= 0x0B33,
	GL_LIST_MODE			= 0x0B30,

	/* Depth buffer */
	GL_NEVER			= 0x0200,
	GL_LESS				= 0x0201,
	GL_GEQUAL			= 0x0206,
	GL_LEQUAL			= 0x0203,
	GL_GREATER			= 0x0204,
	GL_NOTEQUAL			= 0x0205,
	GL_EQUAL			= 0x0202,
	GL_ALWAYS			= 0x0207,
	GL_DEPTH_TEST			= 0x0B71,
	GL_DEPTH_BITS			= 0x0D56,
	GL_DEPTH_CLEAR_VALUE		= 0x0B73,
	GL_DEPTH_FUNC			= 0x0B74,
	GL_DEPTH_RANGE			= 0x0B70,
	GL_DEPTH_WRITEMASK		= 0x0B72,
	GL_DEPTH_COMPONENT		= 0x1902,

	/* Lighting */
	GL_LIGHTING			= 0x0B50,
	GL_LIGHT0			= 0x4000,
	GL_LIGHT1			= 0x4001,
	GL_LIGHT2			= 0x4002,
	GL_LIGHT3			= 0x4003,
	GL_LIGHT4			= 0x4004,
	GL_LIGHT5			= 0x4005,
	GL_LIGHT6			= 0x4006,
	GL_LIGHT7			= 0x4007,
	GL_SPOT_EXPONENT		= 0x1205,
	GL_SPOT_CUTOFF			= 0x1206,
	GL_CONSTANT_ATTENUATION		= 0x1207,
	GL_LINEAR_ATTENUATION		= 0x1208,
	GL_QUADRATIC_ATTENUATION	= 0x1209,
	GL_AMBIENT			= 0x1200,
	GL_DIFFUSE			= 0x1201,
	GL_SPECULAR			= 0x1202,
	GL_SHININESS			= 0x1601,
	GL_EMISSION			= 0x1600,
	GL_POSITION			= 0x1203,
	GL_SPOT_DIRECTION		= 0x1204,
	GL_AMBIENT_AND_DIFFUSE		= 0x1602,
	GL_COLOR_INDEXES		= 0x1603,
	GL_LIGHT_MODEL_TWO_SIDE		= 0x0B52,
	GL_LIGHT_MODEL_LOCAL_VIEWER	= 0x0B51,
	GL_LIGHT_MODEL_AMBIENT		= 0x0B53,
	GL_FRONT_AND_BACK		= 0x0408,
	GL_SHADE_MODEL			= 0x0B54,
	GL_FLAT				= 0x1D00,
	GL_SMOOTH			= 0x1D01,
	GL_COLOR_MATERIAL		= 0x0B57,
	GL_COLOR_MATERIAL_FACE		= 0x0B55,
	GL_COLOR_MATERIAL_PARAMETER	= 0x0B56,
	GL_NORMALIZE			= 0x0BA1,

	/* User clipping planes */
	GL_CLIP_PLANE0			= 0x3000,
	GL_CLIP_PLANE1			= 0x3001,
	GL_CLIP_PLANE2			= 0x3002,
	GL_CLIP_PLANE3			= 0x3003,
	GL_CLIP_PLANE4			= 0x3004,
	GL_CLIP_PLANE5			= 0x3005,

	/* Accumulation buffer */
	GL_ACCUM_RED_BITS		= 0x0D58,
	GL_ACCUM_GREEN_BITS		= 0x0D59,
	GL_ACCUM_BLUE_BITS		= 0x0D5A,
	GL_ACCUM_ALPHA_BITS		= 0x0D5B,
	GL_ACCUM_CLEAR_VALUE		= 0x0B80,
	GL_ACCUM			= 0x0100,
	GL_ADD				= 0x0104,
	GL_LOAD				= 0x0101,
	GL_MULT				= 0x0103,
	GL_RETURN			= 0x0102,

	/* Alpha testing */
	GL_ALPHA_TEST			= 0x0BC0,
	GL_ALPHA_TEST_REF		= 0x0BC2,
	GL_ALPHA_TEST_FUNC		= 0x0BC1,

	/* multisampling */

	GL_MULTISAMPLE			= 0x809D,

	/* Blend equations */
	GL_FUNC_ADD			= 0x8006,
	GL_MIN				= 0x8007,
	GL_MAX				= 0x8008,
	GL_FUNC_SUBTRACT		= 0x800A,
	GL_FUNC_REVERSE_SUBTRACT	= 0x800B,

	/* Blending */
	GL_BLEND			= 0x0BE2,
	GL_BLEND_SRC			= 0x0BE1,
	GL_BLEND_SRC_RGB		= 0x80C9,
	GL_BLEND_SRC_ALPHA		= 0x80CB,
	GL_BLEND_DST			= 0x0BE0,
	GL_BLEND_DST_RGB		= 0x80C8,
	GL_BLEND_DST_ALPHA		= 0x80CA,
	GL_BLEND_EQUATION		= 0x8009,
	GL_BLEND_EQUATION_RGB		= 0x8009,
	GL_BLEND_EQUATION_ALPHA		= 0x883D,
	GL_ZERO				= 0,
	GL_ONE				= 1,
	GL_SRC_COLOR			= 0x0300,
	GL_ONE_MINUS_SRC_COLOR		= 0x0301,
	GL_DST_COLOR			= 0x0306,
	GL_ONE_MINUS_DST_COLOR		= 0x0307,
	GL_SRC_ALPHA			= 0x0302,
	GL_ONE_MINUS_SRC_ALPHA		= 0x0303,
	GL_DST_ALPHA			= 0x0304,
	GL_ONE_MINUS_DST_ALPHA		= 0x0305,
	GL_SRC_ALPHA_SATURATE		= 0x0308,
	GL_CONSTANT_COLOR		= 0x8001,
	GL_ONE_MINUS_CONSTANT_COLOR	= 0x8002,
	GL_CONSTANT_ALPHA		= 0x8003,
	GL_ONE_MINUS_CONSTANT_ALPHA	= 0x8004,

	/* Render Mode */
	GL_FEEDBACK			= 0x1C01,
	GL_RENDER			= 0x1C00,
	GL_SELECT			= 0x1C02,

	/* Feedback */
	GL_2D				= 0x0600,
	GL_3D				= 0x0601,
	GL_3D_COLOR			= 0x0602,
	GL_3D_COLOR_TEXTURE		= 0x0603,
	GL_4D_COLOR_TEXTURE		= 0x0604,
	GL_POINT_TOKEN			= 0x0701,
	GL_LINE_TOKEN			= 0x0702,
	GL_LINE_RESET_TOKEN		= 0x0707,
	GL_POLYGON_TOKEN		= 0x0703,
	GL_BITMAP_TOKEN			= 0x0704,
	GL_DRAW_PIXEL_TOKEN		= 0x0705,
	GL_COPY_PIXEL_TOKEN		= 0x0706,
	GL_PASS_THROUGH_TOKEN		= 0x0700,

	/* Fog */
	GL_FOG				= 0x0B60,
	GL_FOG_MODE			= 0x0B65,
	GL_FOG_DENSITY			= 0x0B62,
	GL_FOG_COLOR			= 0x0B66,
	GL_FOG_INDEX			= 0x0B61,
	GL_FOG_START			= 0x0B63,
	GL_FOG_END			= 0x0B64,
	GL_LINEAR			= 0x2601,
	GL_EXP				= 0x0800,
	GL_EXP2				= 0x0801,

	/* Logic Ops */
	GL_LOGIC_OP			= 0x0BF1,
	GL_LOGIC_OP_MODE		= 0x0BF0,
	GL_CLEAR			= 0x1500,
	GL_SET				= 0x150F,
	GL_COPY				= 0x1503,
	GL_COPY_INVERTED		= 0x150C,
	GL_NOOP				= 0x1505,
	GL_INVERT			= 0x150A,
	GL_AND				= 0x1501,
	GL_NAND				= 0x150E,
	GL_OR				= 0x1507,
	GL_NOR				= 0x1508,
	GL_XOR				= 0x1506,
	GL_EQUIV			= 0x1509,
	GL_AND_REVERSE			= 0x1502,
	GL_AND_INVERTED			= 0x1504,
	GL_OR_REVERSE			= 0x150B,
	GL_OR_INVERTED			= 0x150D,

	/* Stencil */
	GL_STENCIL_TEST			= 0x0B90,
	GL_STENCIL_WRITEMASK		= 0x0B98,
	GL_STENCIL_BITS			= 0x0D57,
	GL_STENCIL_FUNC			= 0x0B92,
	GL_STENCIL_VALUE_MASK		= 0x0B93,
	GL_STENCIL_REF			= 0x0B97,
	GL_STENCIL_FAIL			= 0x0B94,
	GL_STENCIL_PASS_DEPTH_PASS	= 0x0B96,
	GL_STENCIL_PASS_DEPTH_FAIL	= 0x0B95,
	GL_STENCIL_CLEAR_VALUE		= 0x0B91,
	GL_STENCIL_INDEX		= 0x1901,
	GL_KEEP				= 0x1E00,
	GL_REPLACE			= 0x1E01,
	GL_INCR				= 0x1E02,
	GL_DECR				= 0x1E03,

	/* GL_EXT_stencil_wrap */
	GL_INCR_WRAP        = 0x8507,
	GL_DECR_WRAP        = 0x8508,


	/* Buffers, Pixel Drawing/Reading */
	GL_NONE				= 0,
	GL_LEFT				= 0x0406,
	GL_RIGHT			= 0x0407,
	/*GL_FRONT			= 0x0404, */
	/*GL_BACK			= 0x0405, */
	/*GL_FRONT_AND_BACK		= 0x0408, */
	GL_FRONT_LEFT			= 0x0400,
	GL_FRONT_RIGHT			= 0x0401,
	GL_BACK_LEFT			= 0x0402,
	GL_BACK_RIGHT			= 0x0403,
	GL_AUX0				= 0x0409,
	GL_AUX1				= 0x040A,
	GL_AUX2				= 0x040B,
	GL_AUX3				= 0x040C,
	GL_COLOR_INDEX			= 0x1900,
	GL_RED				= 0x1903,
	GL_GREEN			= 0x1904,
	GL_BLUE				= 0x1905,
	GL_ALPHA			= 0x1906,
	GL_LUMINANCE			= 0x1909,
	GL_LUMINANCE_ALPHA		= 0x190A,
	GL_ALPHA_BITS			= 0x0D55,
	GL_RED_BITS			= 0x0D52,
	GL_GREEN_BITS			= 0x0D53,
	GL_BLUE_BITS			= 0x0D54,
	GL_INDEX_BITS			= 0x0D51,
	GL_SUBPIXEL_BITS		= 0x0D50,
	GL_AUX_BUFFERS			= 0x0C00,
	GL_READ_BUFFER			= 0x0C02,
	GL_DRAW_BUFFER			= 0x0C01,
	GL_DOUBLEBUFFER			= 0x0C32,
	GL_STEREO			= 0x0C33,
	GL_BITMAP			= 0x1A00,
	GL_COLOR			= 0x1800,
	GL_DEPTH			= 0x1801,
	GL_STENCIL			= 0x1802,
	GL_DITHER			= 0x0BD0,
	GL_RGB				= 0x1907,
	GL_RGBA				= 0x1908,

	/* Implementation limits */
	GL_MAX_LIST_NESTING		= 0x0B31,
	GL_MAX_ATTRIB_STACK_DEPTH	= 0x0D35,
	GL_MAX_MODELVIEW_STACK_DEPTH	= 0x0D36,
	GL_MAX_NAME_STACK_DEPTH		= 0x0D37,
	GL_MAX_PROJECTION_STACK_DEPTH	= 0x0D38,
	GL_MAX_TEXTURE_STACK_DEPTH	= 0x0D39,
	GL_MAX_EVAL_ORDER		= 0x0D30,
	GL_MAX_LIGHTS			= 0x0D31,
	GL_MAX_CLIP_PLANES		= 0x0D32,
	GL_MAX_TEXTURE_SIZE		= 0x0D33,
	GL_MAX_PIXEL_MAP_TABLE		= 0x0D34,
	GL_MAX_VIEWPORT_DIMS		= 0x0D3A,
	GL_MAX_CLIENT_ATTRIB_STACK_DEPTH= 0x0D3B,

	/* Gets */
	GL_ATTRIB_STACK_DEPTH		= 0x0BB0,
	GL_COLOR_CLEAR_VALUE		= 0x0C22,
	GL_COLOR_WRITEMASK		= 0x0C23,
	GL_CURRENT_INDEX		= 0x0B01,
	GL_CURRENT_COLOR		= 0x0B00,
	GL_CURRENT_NORMAL		= 0x0B02,
	GL_CURRENT_RASTER_COLOR		= 0x0B04,
	GL_CURRENT_RASTER_DISTANCE	= 0x0B09,
	GL_CURRENT_RASTER_INDEX		= 0x0B05,
	GL_CURRENT_RASTER_POSITION	= 0x0B07,
	GL_CURRENT_RASTER_TEXTURE_COORDS = 0x0B06,
	GL_CURRENT_RASTER_POSITION_VALID = 0x0B08,
	GL_CURRENT_TEXTURE_COORDS	= 0x0B03,
	GL_INDEX_CLEAR_VALUE		= 0x0C20,
	GL_INDEX_MODE			= 0x0C30,
	GL_INDEX_WRITEMASK		= 0x0C21,
	GL_MODELVIEW_MATRIX		= 0x0BA6,
	GL_MODELVIEW_STACK_DEPTH	= 0x0BA3,
	GL_NAME_STACK_DEPTH		= 0x0D70,
	GL_PROJECTION_MATRIX		= 0x0BA7,
	GL_PROJECTION_STACK_DEPTH	= 0x0BA4,
	GL_RENDER_MODE			= 0x0C40,
	GL_RGBA_MODE			= 0x0C31,
	GL_TEXTURE_MATRIX		= 0x0BA8,
	GL_TEXTURE_STACK_DEPTH		= 0x0BA5,
	GL_TRANSPOSE_MODELVIEW_MATRIX	= 0x84E3,
	GL_TRANSPOSE_PROJECTION_MATRIX	= 0x84E4,
	GL_TRANSPOSE_TEXTURE_MATRIX	= 0x84E5,
	GL_VIEWPORT			= 0x0BA2,

	/* Evaluators */
	GL_AUTO_NORMAL			= 0x0D80,
	GL_MAP1_COLOR_4			= 0x0D90,
	GL_MAP1_GRID_DOMAIN		= 0x0DD0,
	GL_MAP1_GRID_SEGMENTS		= 0x0DD1,
	GL_MAP1_INDEX			= 0x0D91,
	GL_MAP1_NORMAL			= 0x0D92,
	GL_MAP1_TEXTURE_COORD_1		= 0x0D93,
	GL_MAP1_TEXTURE_COORD_2		= 0x0D94,
	GL_MAP1_TEXTURE_COORD_3		= 0x0D95,
	GL_MAP1_TEXTURE_COORD_4		= 0x0D96,
	GL_MAP1_VERTEX_3		= 0x0D97,
	GL_MAP1_VERTEX_4		= 0x0D98,
	GL_MAP2_COLOR_4			= 0x0DB0,
	GL_MAP2_GRID_DOMAIN		= 0x0DD2,
	GL_MAP2_GRID_SEGMENTS		= 0x0DD3,
	GL_MAP2_INDEX			= 0x0DB1,
	GL_MAP2_NORMAL			= 0x0DB2,
	GL_MAP2_TEXTURE_COORD_1		= 0x0DB3,
	GL_MAP2_TEXTURE_COORD_2		= 0x0DB4,
	GL_MAP2_TEXTURE_COORD_3		= 0x0DB5,
	GL_MAP2_TEXTURE_COORD_4		= 0x0DB6,
	GL_MAP2_VERTEX_3		= 0x0DB7,
	GL_MAP2_VERTEX_4		= 0x0DB8,
	GL_COEFF			= 0x0A00,
	GL_DOMAIN			= 0x0A02,
	GL_ORDER			= 0x0A01,

	/* Hints */
	GL_FOG_HINT			= 0x0C54,
	GL_LINE_SMOOTH_HINT		= 0x0C52,
	GL_PERSPECTIVE_CORRECTION_HINT	= 0x0C50,
	GL_POINT_SMOOTH_HINT		= 0x0C51,
	GL_POLYGON_SMOOTH_HINT		= 0x0C53,
	GL_DONT_CARE			= 0x1100,
	GL_FASTEST			= 0x1101,
	GL_NICEST			= 0x1102,

	/* TinyGL custom hints */

	TGL_RECTANGULAR_TEXTURES_HINT	= 0x1103,
	TGL_LOWQUALITY_TEXTURES_HINT	= 0x1104,
	TGL_CORRECT_NORMALS_HINT	 	= 0x1105,

	/* Scissor box */
	GL_SCISSOR_TEST			= 0x0C11,
	GL_SCISSOR_BOX			= 0x0C10,

	/* Pixel Mode / Transfer */
	GL_MAP_COLOR			= 0x0D10,
	GL_MAP_STENCIL			= 0x0D11,
	GL_INDEX_SHIFT			= 0x0D12,
	GL_INDEX_OFFSET			= 0x0D13,
	GL_RED_SCALE			= 0x0D14,
	GL_RED_BIAS			= 0x0D15,
	GL_GREEN_SCALE			= 0x0D18,
	GL_GREEN_BIAS			= 0x0D19,
	GL_BLUE_SCALE			= 0x0D1A,
	GL_BLUE_BIAS			= 0x0D1B,
	GL_ALPHA_SCALE			= 0x0D1C,
	GL_ALPHA_BIAS			= 0x0D1D,
	GL_DEPTH_SCALE			= 0x0D1E,
	GL_DEPTH_BIAS			= 0x0D1F,
	GL_PIXEL_MAP_S_TO_S_SIZE	= 0x0CB1,
	GL_PIXEL_MAP_I_TO_I_SIZE	= 0x0CB0,
	GL_PIXEL_MAP_I_TO_R_SIZE	= 0x0CB2,
	GL_PIXEL_MAP_I_TO_G_SIZE	= 0x0CB3,
	GL_PIXEL_MAP_I_TO_B_SIZE	= 0x0CB4,
	GL_PIXEL_MAP_I_TO_A_SIZE	= 0x0CB5,
	GL_PIXEL_MAP_R_TO_R_SIZE	= 0x0CB6,
	GL_PIXEL_MAP_G_TO_G_SIZE	= 0x0CB7,
	GL_PIXEL_MAP_B_TO_B_SIZE	= 0x0CB8,
	GL_PIXEL_MAP_A_TO_A_SIZE	= 0x0CB9,
	GL_PIXEL_MAP_S_TO_S		= 0x0C71,
	GL_PIXEL_MAP_I_TO_I		= 0x0C70,
	GL_PIXEL_MAP_I_TO_R		= 0x0C72,
	GL_PIXEL_MAP_I_TO_G		= 0x0C73,
	GL_PIXEL_MAP_I_TO_B		= 0x0C74,
	GL_PIXEL_MAP_I_TO_A		= 0x0C75,
	GL_PIXEL_MAP_R_TO_R		= 0x0C76,
	GL_PIXEL_MAP_G_TO_G		= 0x0C77,
	GL_PIXEL_MAP_B_TO_B		= 0x0C78,
	GL_PIXEL_MAP_A_TO_A		= 0x0C79,
	GL_PACK_ALIGNMENT		= 0x0D05,
	GL_PACK_LSB_FIRST		= 0x0D01,
	GL_PACK_ROW_LENGTH		= 0x0D02,
	GL_PACK_SKIP_PIXELS		= 0x0D04,
	GL_PACK_SKIP_ROWS		= 0x0D03,
	GL_PACK_SWAP_BYTES		= 0x0D00,
	GL_UNPACK_ALIGNMENT		= 0x0CF5,
	GL_UNPACK_LSB_FIRST		= 0x0CF1,
	GL_UNPACK_ROW_LENGTH		= 0x0CF2,
	GL_UNPACK_SKIP_PIXELS		= 0x0CF4,
	GL_UNPACK_SKIP_ROWS		= 0x0CF3,
	GL_UNPACK_SWAP_BYTES		= 0x0CF0,
	GL_ZOOM_X			= 0x0D16,
	GL_ZOOM_Y			= 0x0D17,

	/* Texture mapping */
	GL_TEXTURE_ENV			= 0x2300,
	GL_TEXTURE_ENV_MODE		= 0x2200,
	GL_TEXTURE_1D			= 0x0DE0,
	GL_TEXTURE_2D			= 0x0DE1,
	GL_TEXTURE_WRAP_S		= 0x2802,
	GL_TEXTURE_WRAP_T		= 0x2803,
	GL_TEXTURE_WRAP_R		= 0x8072,
	GL_TEXTURE_MAG_FILTER		= 0x2800,
	GL_TEXTURE_MIN_FILTER		= 0x2801,
	GL_TEXTURE_ENV_COLOR		= 0x2201,
	GL_TEXTURE_GEN_S		= 0x0C60,
	GL_TEXTURE_GEN_T		= 0x0C61,
	GL_TEXTURE_GEN_MODE		= 0x2500,
	GL_TEXTURE_BORDER_COLOR		= 0x1004,
	GL_TEXTURE_WIDTH		= 0x1000,
	GL_TEXTURE_HEIGHT		= 0x1001,
	GL_TEXTURE_BORDER		= 0x1005,
	GL_TEXTURE_COMPONENTS		= 0x1003,
	GL_NEAREST_MIPMAP_NEAREST	= 0x2700,
	GL_NEAREST_MIPMAP_LINEAR	= 0x2702,
	GL_LINEAR_MIPMAP_NEAREST	= 0x2701,
	GL_LINEAR_MIPMAP_LINEAR		= 0x2703,
	GL_OBJECT_LINEAR		= 0x2401,
	GL_OBJECT_PLANE			= 0x2501,
	GL_EYE_LINEAR			= 0x2400,
	GL_EYE_PLANE			= 0x2502,
	GL_SPHERE_MAP			= 0x2402,
	GL_DECAL			= 0x2101,
	GL_MODULATE			= 0x2100,
	GL_NEAREST			= 0x2600,
	GL_REPEAT			= 0x2901,
	GL_CLAMP			= 0x2900,
	GL_S				= 0x2000,
	GL_T				= 0x2001,
	GL_R				= 0x2002,
	GL_Q				= 0x2003,
	GL_TEXTURE_GEN_R		= 0x0C62,
	GL_TEXTURE_GEN_Q		= 0x0C63,

	GL_TEXTURE_BINDING_1D	= 0x8068,
	GL_TEXTURE_BINDING_2D	= 0x8069,

	GL_PROXY_TEXTURE_1D		= 0x8063,
	GL_PROXY_TEXTURE_2D		= 0x8064,
	GL_TEXTURE_PRIORITY		= 0x8066,
	GL_TEXTURE_RESIDENT		= 0x8067,
	GL_TEXTURE_1D_BINDING		= 0x8068,
	GL_TEXTURE_2D_BINDING		= 0x8069,

	/* Internal texture formats */
	GL_ALPHA4			= 0x803B,
	GL_ALPHA8			= 0x803C,
	GL_ALPHA12			= 0x803D,
	GL_ALPHA16			= 0x803E,
	GL_LUMINANCE4			= 0x803F,
	GL_LUMINANCE8			= 0x8040,
	GL_LUMINANCE12			= 0x8041,
	GL_LUMINANCE16			= 0x8042,
	GL_LUMINANCE4_ALPHA4		= 0x8043,
	GL_LUMINANCE6_ALPHA2		= 0x8044,
	GL_LUMINANCE8_ALPHA8		= 0x8045,
	GL_LUMINANCE12_ALPHA4		= 0x8046,
	GL_LUMINANCE12_ALPHA12		= 0x8047,
	GL_LUMINANCE16_ALPHA16		= 0x8048,
	GL_INTENSITY			= 0x8049,
	GL_INTENSITY4			= 0x804A,
	GL_INTENSITY8			= 0x804B,
	GL_INTENSITY12			= 0x804C,
	GL_INTENSITY16			= 0x804D,
	GL_R3_G3_B2			= 0x2A10,
	GL_RGB4				= 0x804F,
	GL_RGB5				= 0x8050,
	GL_RGB8				= 0x8051,
	GL_RGB10			= 0x8052,
	GL_RGB12			= 0x8053,
	GL_RGB16			= 0x8054,
	GL_RGBA2			= 0x8055,
	GL_RGBA4			= 0x8056,
	GL_RGB5_A1			= 0x8057,
	GL_RGBA8			= 0x8058,
	GL_RGB10_A2			= 0x8059,
	GL_RGBA12			= 0x805A,
	GL_RGBA16			= 0x805B,
	GL_DEPTH_COMPONENT32F = 0x8CAC,
	GL_DEPTH_COMPONENT32 = 0x81A7,
	GL_DEPTH_COMPONENT24 = 0x81A6,
	GL_DEPTH_COMPONENT16 = 0x81A5,
	GL_DEPTH_COMPONENT32_ARB = 0x81A7,
	GL_DEPTH_COMPONENT24_ARB = 0x81A6,
	GL_DEPTH_COMPONENT16_ARB = 0x81A5,
	

	GL_UNSIGNED_SHORT_5_6_5			= 0x8363,
	GL_UNSIGNED_SHORT_5_6_5_REV		= 0x8364,
	GL_UNSIGNED_SHORT_4_4_4_4		= 0x8033,
	GL_UNSIGNED_SHORT_4_4_4_4_REV	= 0x8365,
	GL_UNSIGNED_SHORT_5_5_5_1		= 0x8034,
	GL_UNSIGNED_SHORT_1_5_5_5_REV	= 0x8366,
	GL_UNSIGNED_INT_8_8_8_8			= 0x8035,
	GL_UNSIGNED_INT_8_8_8_8_REV		= 0x8367,

	/* Utility */
	GL_VENDOR			= 0x1F00,
	GL_RENDERER			= 0x1F01,
	GL_VERSION			= 0x1F02,
	GL_EXTENSIONS			= 0x1F03,

	/* Errors */
	GL_INVALID_VALUE		= 0x0501,
	GL_INVALID_ENUM			= 0x0500,
	GL_INVALID_OPERATION		= 0x0502,
	GL_STACK_OVERFLOW		= 0x0503,
	GL_STACK_UNDERFLOW		= 0x0504,
	GL_OUT_OF_MEMORY		= 0x0505,

	/*
	 * 1.0 Extensions
	 */
        /* GL_EXT_blend_minmax and GL_EXT_blend_color */
	GL_CONSTANT_COLOR_EXT		= 0x8001,
	GL_ONE_MINUS_CONSTANT_COLOR_EXT	= 0x8002,
	GL_CONSTANT_ALPHA_EXT		= 0x8003,
	GL_ONE_MINUS_CONSTANT_ALPHA_EXT	= 0x8004,
	GL_BLEND_EQUATION_EXT		= 0x8009,
	GL_MIN_EXT			= 0x8007,
	GL_MAX_EXT			= 0x8008,
	GL_FUNC_ADD_EXT			= 0x8006,
	GL_FUNC_SUBTRACT_EXT		= 0x800A,
	GL_FUNC_REVERSE_SUBTRACT_EXT	= 0x800B,
	GL_BLEND_COLOR_EXT		= 0x8005,

	/* GL_EXT_polygon_offset */
        GL_POLYGON_OFFSET_EXT           = 0x8037,
        GL_POLYGON_OFFSET_FACTOR_EXT    = 0x8038,
        GL_POLYGON_OFFSET_BIAS_EXT      = 0x8039,

	/* GL_EXT_vertex_array */
	GL_VERTEX_ARRAY_EXT		= 0x8074,
	GL_NORMAL_ARRAY_EXT		= 0x8075,
	GL_COLOR_ARRAY_EXT		= 0x8076,
	GL_INDEX_ARRAY_EXT		= 0x8077,
	GL_TEXTURE_COORD_ARRAY_EXT	= 0x8078,
	GL_EDGE_FLAG_ARRAY_EXT		= 0x8079,
	GL_VERTEX_ARRAY_SIZE_EXT	= 0x807A,
	GL_VERTEX_ARRAY_TYPE_EXT	= 0x807B,
	GL_VERTEX_ARRAY_STRIDE_EXT	= 0x807C,
	GL_VERTEX_ARRAY_COUNT_EXT	= 0x807D,
	GL_NORMAL_ARRAY_TYPE_EXT	= 0x807E,
	GL_NORMAL_ARRAY_STRIDE_EXT	= 0x807F,
	GL_NORMAL_ARRAY_COUNT_EXT	= 0x8080,
	GL_COLOR_ARRAY_SIZE_EXT		= 0x8081,
	GL_COLOR_ARRAY_TYPE_EXT		= 0x8082,
	GL_COLOR_ARRAY_STRIDE_EXT	= 0x8083,
	GL_COLOR_ARRAY_COUNT_EXT	= 0x8084,
	GL_INDEX_ARRAY_TYPE_EXT		= 0x8085,
	GL_INDEX_ARRAY_STRIDE_EXT	= 0x8086,
	GL_INDEX_ARRAY_COUNT_EXT	= 0x8087,
	GL_TEXTURE_COORD_ARRAY_SIZE_EXT	= 0x8088,
	GL_TEXTURE_COORD_ARRAY_TYPE_EXT	= 0x8089,
	GL_TEXTURE_COORD_ARRAY_STRIDE_EXT= 0x808A,
	GL_TEXTURE_COORD_ARRAY_COUNT_EXT= 0x808B,
	GL_EDGE_FLAG_ARRAY_STRIDE_EXT	= 0x808C,
	GL_EDGE_FLAG_ARRAY_COUNT_EXT	= 0x808D,
	GL_VERTEX_ARRAY_POINTER_EXT	= 0x808E,
	GL_NORMAL_ARRAY_POINTER_EXT	= 0x808F,
	GL_COLOR_ARRAY_POINTER_EXT	= 0x8090,
	GL_INDEX_ARRAY_POINTER_EXT	= 0x8091,
	GL_TEXTURE_COORD_ARRAY_POINTER_EXT= 0x8092,
	GL_EDGE_FLAG_ARRAY_POINTER_EXT	= 0x8093,

	GL_NO_ERROR = 0,

	/* GL_EXT_multitexture */
	GL_TEXTURE0_EXT                         = 0x83C6,
	GL_TEXTURE1_EXT                         = 0x83C7,
	GL_TEXTURE0_ARB							= 0x84C0,
	GL_TEXTURE1_ARB							= 0x84C1,
	GL_TEXTURE2_ARB							= 0x84C2,
	GL_TEXTURE3_ARB							= 0x84C3,
	GL_TEXTURE4_ARB							= 0x84C4,
	GL_TEXTURE5_ARB							= 0x84C5,
	GL_TEXTURE6_ARB							= 0x84C6,
	GL_TEXTURE7_ARB							= 0x84C7,

	GL_TEXTURE0								= 0x84C0,
	GL_TEXTURE1								= 0x84C1,
	GL_TEXTURE2								= 0x84C2,
	GL_TEXTURE3								= 0x84C3,
	GL_TEXTURE4								= 0x84C4,
	GL_TEXTURE5								= 0x84C5,
	GL_TEXTURE6								= 0x84C6,
	GL_TEXTURE7								= 0x84C7,


	GL_MAX_TEXTURE_UNITS_ARB				= 0x84E2,

	/* GL_EXT_shared_texture_palette */

	GL_SHARED_TEXTURE_PALETTE_EXT           = 0x81FB,

	/* GL_EXT_color_table */

	GL_COLOR_TABLE				            = 0x80D0,
	GL_COLOR_INDEX8_EXT			            = 0x80E5,

	/* point parameters extension */

	GL_POINT_SIZE_MIN_EXT		   			= 0x8126,
	GL_POINT_SIZE_MAX_EXT		   			= 0x8127,
	GL_POINT_FADE_THRESHOLD_SIZE_EXT   		= 0x8128,
	GL_DISTANCE_ATTENUATION_EXT	   			= 0x8129,

	GL_ABGR_EXT								= 0x8000,

	GL_CLAMP_TO_EDGE						= 0x812F,

    /* texture_cube_map */
	GL_NORMAL_MAP							= 0x8511,
	GL_REFLECTION_MAP						= 0x8512,
	GL_REFLECTION_MAP_ARB					= 0x8512,
	GL_TEXTURE_CUBE_MAP						= 0x8513,
	GL_TEXTURE_CUBE_MAP_ARB					= 0x8513,
	GL_TEXTURE_CUBE_MAP_EXT					= 0x8513,
	GL_TEXTURE_BINDING_CUBE_MAP				= 0x8514,
	GL_TEXTURE_CUBE_MAP_POSITIVE_X			= 0x8515,
	GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB		= 0x8515,
	GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT		= 0x8515,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X			= 0x8516,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB		= 0x8516,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT		= 0x8516,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y			= 0x8517,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB		= 0x8517,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT		= 0x8517,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y			= 0x8518,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB		= 0x8518,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT		= 0x8518,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z			= 0x8519,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB		= 0x8519,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT		= 0x8519,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z			= 0x851A,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB		= 0x851A,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT		= 0x851A,
	GL_PROXY_TEXTURE_CUBE_MAP				= 0x851B,
	GL_MAX_CUBE_MAP_TEXTURE_SIZE			= 0x851C,

	GL_TEXTURE_BASE_LEVEL					= 0x813C,
	GL_TEXTURE_MAX_LEVEL					= 0x813D,

	/* GL_EXT_Clip_volume_hint */

	CLIP_VOLUME_CLIPPING_HINT_EXT   		= 0x80f0,

	GL_TEXTURE_BINDING_3D					= 0x806A,

	GL_TEXTURE_MAX_ANISOTROPY_EXT			= 0x84FE,
	GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT		= 0x84FF,

	/* texture_env_combine */
	GL_COMBINE								= 0x8570,
	GL_COMBINE_RGB							= 0x8571,
	GL_COMBINE_ALPHA						= 0x8572,
	GL_SOURCE0_RGB							= 0x8580,
	GL_SOURCE1_RGB							= 0x8581,
	GL_SOURCE2_RGB							= 0x8582,
	GL_SOURCE0_ALPHA						= 0x8588,
	GL_SOURCE1_ALPHA						= 0x8589,
	GL_SOURCE2_ALPHA						= 0x858A,
	GL_OPERAND0_RGB							= 0x8590,
	GL_OPERAND1_RGB							= 0x8591,
	GL_OPERAND2_RGB							= 0x8592,
	GL_OPERAND0_ALPHA						= 0x8598,
	GL_OPERAND1_ALPHA						= 0x8599,
	GL_OPERAND2_ALPHA						= 0x859A,
	GL_RGB_SCALE							= 0x8573,
	GL_ADD_SIGNED							= 0x8574,
	GL_INTERPOLATE							= 0x8575,
	GL_SUBTRACT								= 0x84E7,
	GL_CONSTANT								= 0x8576,
	GL_PRIMARY_COLOR						= 0x8577,
	GL_PREVIOUS								= 0x8578,
	/* texture_env_dot3 */
	GL_DOT3_RGB								= 0x86AE,
	GL_DOT3_RGBA							= 0x86AF,
	GL_DOT3_RGB_EXT							= 0x8740,
	GL_DOT3_RGBA_EXT						= 0x8741,

	/* shaders */

	GL_VERTEX_PROGRAM_ARB             		= 0x8620,
	GL_VERTEX_PROGRAM_NV              		= 0x8620,
	GL_FRAGMENT_PROGRAM_ARB           		= 0x8804,
	GL_FRAGMENT_PROGRAM_NV           		= 0x8804,
	GL_GEOMETRY_PROGRAM_NV					= 0x8C26,
	GL_VERTEX_STATE_PROGRAM_NV				= 0x8621,
	
	GL_MODELVIEW_PROJECTION_NV				= 0x8629,
	GL_IDENTITY_NV							= 0x862A,
	GL_INVERSE_NV							= 0x862B,
	GL_TRANSPOSE_NV                   		= 0x862C,
	GL_INVERSE_TRANSPOSE_NV           		= 0x862D,
	GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV 		= 0x862E,
	GL_MAX_TRACK_MATRICES_NV         		= 0x862F,
	GL_MATRIX0_NV                    		= 0x8630,
	GL_MATRIX1_NV                     		= 0x8631,
	GL_MATRIX2_NV                     		= 0x8632,
	GL_MATRIX3_NV                     		= 0x8633,
	GL_MATRIX4_NV                     		= 0x8634,
	GL_MATRIX5_NV                     		= 0x8635,
	GL_MATRIX6_NV                     		= 0x8636,
	GL_MATRIX7_NV                     		= 0x8637,
	
	GL_VERTEX_ATTRIB_ARRAY_ENABLED   		= 0x8622,
	GL_VERTEX_ATTRIB_ARRAY_SIZE       		= 0x8623,
	GL_VERTEX_ATTRIB_ARRAY_STRIDE     		= 0x8624,
	GL_VERTEX_ATTRIB_ARRAY_TYPE       		= 0x8625,
	GL_CURRENT_VERTEX_ATTRIB          		= 0x8626,
	GL_VERTEX_PROGRAM_POINT_SIZE      		= 0x8642,
	GL_VERTEX_ATTRIB_ARRAY_POINTER    		= 0x8645,

	GL_MAX_VERTEX_ATTRIBS             		= 0x8869,
	GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 		= 0x886A,
	GL_MAX_TEXTURE_IMAGE_UNITS        		= 0x8872,
	GL_FRAGMENT_SHADER                		= 0x8B30,
	GL_VERTEX_SHADER                 		= 0x8B31,
	GL_GEOMETRY_SHADER                		= 0x8DD9,

	GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 		= 0x8B49,
	GL_MAX_VERTEX_UNIFORM_COMPONENTS  		= 0x8B4A,
	GL_MAX_VARYING_FLOATS             		= 0x8B4B,
	GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 		= 0x8B4C,
	GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 	= 0x8B4D,
	GL_SHADER_TYPE                    		= 0x8B4F,

	GL_DELETE_STATUS                  		= 0x8B80,
	GL_COMPILE_STATUS                 		= 0x8B81,
	GL_LINK_STATUS                    		= 0x8B82,
	GL_VALIDATE_STATUS                		= 0x8B83,
	GL_INFO_LOG_LENGTH                		= 0x8B84,
	GL_ATTACHED_SHADERS              		= 0x8B85,
	GL_ACTIVE_UNIFORMS                		= 0x8B86,
	GL_ACTIVE_UNIFORM_MAX_LENGTH      		= 0x8B87,
	GL_SHADER_SOURCE_LENGTH           		= 0x8B88,
	GL_ACTIVE_ATTRIBUTES              		= 0x8B89,
	GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    		= 0x8B8A,
	GL_FRAGMENT_SHADER_DERIVATIVE_HINT 		= 0x8B8B,
	GL_SHADING_LANGUAGE_VERSION       		= 0x8B8C,
	GL_CURRENT_PROGRAM                		= 0x8B8D,

	GL_SAMPLER_1D                     		= 0x8B5D,
	GL_SAMPLER_2D                     		= 0x8B5E,
	GL_SAMPLER_3D                     		= 0x8B5F,
	GL_SAMPLER_CUBE                   		= 0x8B60,
	GL_SAMPLER_1D_SHADOW             		= 0x8B61,
	GL_SAMPLER_2D_SHADOW              		= 0x8B62,
	GL_SAMPLER_1D_ARRAY               		= 0x8DC0,
	GL_SAMPLER_2D_ARRAY               		= 0x8DC1,
	GL_SAMPLER_1D_ARRAY_SHADOW        		= 0x8DC3,
	GL_SAMPLER_2D_ARRAY_SHADOW       		= 0x8DC4,
	GL_INT_SAMPLER_1D                 		= 0x8DC9,
	GL_INT_SAMPLER_2D                 		= 0x8DCA,
	GL_INT_SAMPLER_3D                 		= 0x8DCB,
	GL_INT_SAMPLER_CUBE               		= 0x8DCC,
	GL_INT_SAMPLER_1D_ARRAY           		= 0x8DCE,
	GL_INT_SAMPLER_2D_ARRAY          		= 0x8DCF,
	GL_UNSIGNED_INT_SAMPLER_1D        		= 0x8DD1,
	GL_UNSIGNED_INT_SAMPLER_2D        		= 0x8DD2,
	GL_UNSIGNED_INT_SAMPLER_3D        		= 0x8DD3,
	GL_UNSIGNED_INT_SAMPLER_CUBE      		= 0x8DD4,
	GL_UNSIGNED_INT_SAMPLER_1D_ARRAY  		= 0x8DD6,
	GL_UNSIGNED_INT_SAMPLER_2D_ARRAY  		= 0x8DD7,
	GL_SAMPLER_CUBE_SHADOW            		= 0x8DC5,
	GL_SAMPLER_2D_RECT                		= 0x8B63,
	GL_SAMPLER_2D_RECT_SHADOW         		= 0x8B64,
	GL_SAMPLER_BUFFER                 		= 0x8DC2,
	GL_INT_SAMPLER_BUFFER             		= 0x8DD0,
	GL_UNSIGNED_INT_SAMPLER_BUFFER    		= 0x8DD8,

	GL_FLOAT_VEC2                     		= 0x8B50,
	GL_FLOAT_VEC3                     		= 0x8B51,
	GL_FLOAT_VEC4                     		= 0x8B52,
	GL_INT_VEC2                       		= 0x8B53,
	GL_INT_VEC3                       		= 0x8B54,
	GL_INT_VEC4                       		= 0x8B55,
	GL_BOOL                           		= 0x8B56,
	GL_BOOL_VEC2                      		= 0x8B57,
	GL_BOOL_VEC3                      		= 0x8B58,
	GL_BOOL_VEC4                      		= 0x8B59,
	GL_FLOAT_MAT2                     		= 0x8B5A,
	GL_FLOAT_MAT3                     		= 0x8B5B,
	GL_FLOAT_MAT4                     		= 0x8B5C,
	GL_FLOAT_MAT2x3                   		= 0x8B65,
	GL_FLOAT_MAT2x4                   		= 0x8B66,
	GL_FLOAT_MAT3x2                   		= 0x8B67,
	GL_FLOAT_MAT3x4                  		= 0x8B68,
	GL_FLOAT_MAT4x2                  		= 0x8B69,
	GL_FLOAT_MAT4x3                   		= 0x8B6A,
	GL_UNSIGNED_INT_VEC2              		= 0x8DC6,
	GL_UNSIGNED_INT_VEC3              		= 0x8DC7,
	GL_UNSIGNED_INT_VEC4              		= 0x8DC8,

	GL_SEPARATE_ATTRIBS            		    = 0x8C8D,
	GL_INTERLEAVED_ATTRIBS            		= 0x8C8C,
	
	GL_PROGRAM_ERROR_STRING_ARB       		= 0x8874,
	GL_PROGRAM_FORMAT_ASCII_ARB       		= 0x8875,
	GL_PROGRAM_FORMAT_ARB             		= 0x8876,

	/* Buffers */

	GL_BUFFER_SIZE                    		= 0x8764,
	GL_BUFFER_USAGE                   		= 0x8765,
	GL_QUERY_COUNTER_BITS             		= 0x8864,
	GL_CURRENT_QUERY                  		= 0x8865,
	GL_QUERY_RESULT                   		= 0x8866,
	GL_QUERY_RESULT_AVAILABLE         		= 0x8867,
	GL_ARRAY_BUFFER                   		= 0x8892,
	GL_ELEMENT_ARRAY_BUFFER           		= 0x8893,
	GL_ARRAY_BUFFER_BINDING           		= 0x8894,
	GL_ELEMENT_ARRAY_BUFFER_BINDING   		= 0x8895,
	GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING	= 0x889F,
	GL_READ_ONLY                     		= 0x88B8,
	GL_WRITE_ONLY                     		= 0x88B9,
	GL_READ_WRITE                     		= 0x88BA,
	GL_BUFFER_ACCESS                  		= 0x88BB,
	GL_BUFFER_MAPPED                  		= 0x88BC,
	GL_BUFFER_MAP_POINTER             		= 0x88BD,
	GL_STREAM_DRAW                    		= 0x88E0,
	GL_STREAM_READ                    		= 0x88E1,
	GL_STREAM_COPY                    		= 0x88E2,
	GL_STATIC_DRAW                    		= 0x88E4,
	GL_STATIC_READ                    		= 0x88E5,
	GL_STATIC_COPY                    		= 0x88E6,
	GL_DYNAMIC_DRAW                   		= 0x88E8,
	GL_DYNAMIC_READ                   		= 0x88E9,
	GL_DYNAMIC_COPY                   		= 0x88EA,

	GL_ARRAY_BUFFER_ARB               		= 0x8892,
	GL_ELEMENT_ARRAY_BUFFER_ARB       		= 0x8893,
	GL_ARRAY_BUFFER_BINDING_ARB       		= 0x8894,
	GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB		= 0x8895,
	GL_VERTEX_ARRAY_BUFFER_BINDING_ARB		= 0x8896,
	GL_NORMAL_ARRAY_BUFFER_BINDING_ARB		= 0x8897,
	GL_COLOR_ARRAY_BUFFER_BINDING_ARB		= 0x8898,
	GL_INDEX_ARRAY_BUFFER_BINDING_ARB		= 0x8899,
	GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB = 0x889A,
	GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB   = 0x889B,
	GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB = 0x889C,
	GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB = 0x889D,
	GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB		= 0x889E,
	GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB = 0x889F,
	GL_READ_ONLY_ARB                  		= 0x88B8,
	GL_WRITE_ONLY_ARB                 		= 0x88B9,
	GL_READ_WRITE_ARB                 		= 0x88BA,
	GL_BUFFER_ACCESS_ARB              		= 0x88BB,
	GL_BUFFER_MAPPED_ARB              		= 0x88BC,
	GL_BUFFER_MAP_POINTER_ARB         		= 0x88BD,
	GL_STREAM_DRAW_ARB                		= 0x88E0,
	GL_STREAM_READ_ARB                		= 0x88E1,
	GL_STREAM_COPY_ARB                		= 0x88E2,
	GL_STATIC_DRAW_ARB                		= 0x88E4,
	GL_STATIC_READ_ARB                		= 0x88E5,
	GL_STATIC_COPY_ARB                	 	= 0x88E6,
	GL_DYNAMIC_DRAW_ARB               		= 0x88E8,
	GL_DYNAMIC_READ_ARB               		= 0x88E9,
	GL_DYNAMIC_COPY_ARB               		= 0x88EA,

	/* Compressed textures */

	GL_COMPRESSED_RGB_S3TC_DXT1_EXT   		= 0x83F0,
	GL_COMPRESSED_RGBA_S3TC_DXT1_EXT  		= 0x83F1,
	GL_COMPRESSED_RGBA_S3TC_DXT3_EXT  		= 0x83F2,
	GL_COMPRESSED_RGBA_S3TC_DXT5_EXT  		= 0x83F3,
	GL_RGB_S3TC								= 0x83A0,
	GL_RGB4_S3TC							= 0x83A1,

};

enum {
	GL_CURRENT_BIT		= 0x00000001,
	GL_POINT_BIT		= 0x00000002,
	GL_LINE_BIT		= 0x00000004,
	GL_POLYGON_BIT		= 0x00000008,
	GL_POLYGON_STIPPLE_BIT	= 0x00000010,
	GL_PIXEL_MODE_BIT	= 0x00000020,
	GL_LIGHTING_BIT		= 0x00000040,
	GL_FOG_BIT		= 0x00000080,
	GL_DEPTH_BUFFER_BIT	= 0x00000100,
	GL_ACCUM_BUFFER_BIT	= 0x00000200,
	GL_STENCIL_BUFFER_BIT	= 0x00000400,
	GL_VIEWPORT_BIT		= 0x00000800,
	GL_TRANSFORM_BIT	= 0x00001000,
	GL_ENABLE_BIT		= 0x00002000,
	GL_COLOR_BUFFER_BIT	= 0x00004000,
	GL_HINT_BIT		= 0x00008000,
	GL_EVAL_BIT		= 0x00010000,
	GL_LIST_BIT		= 0x00020000,
	GL_TEXTURE_BIT		= 0x00040000,
	GL_SCISSOR_BIT		= 0x00080000,
	GL_ALL_ATTRIB_BITS	= 0x000fffff
};

#define GL_CLIENT_PIXEL_STORE_BIT  0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_ALL_CLIENT_ATTRIB_BITS  0xFFFFFFFF
#define GL_CLIENT_ALL_ATTRIB_BITS  0xFFFFFFFF


/* some types */

typedef int            GLenum;
typedef void           GLvoid;
typedef unsigned char  GLboolean;
typedef signed char    GLbyte;   /* 1-byte signed */
typedef char           GLchar;   /* 1-byte char */
typedef char           GLcharARB; /* 1-byte char */
typedef short          GLshort;  /* 2-byte signed */
typedef int            GLint;    /* 4-byte signed */
typedef unsigned char  GLubyte;  /* 1-byte unsigned */
typedef unsigned short GLushort; /* 2-byte unsigned */
typedef unsigned int   GLuint;   /* 4-byte unsigned */
typedef unsigned long int GLuint64; /* 8-byte unsigned */
typedef unsigned long int GLuint64EXT; /* 8-byte unsigned */
typedef float          GLfloat;  /* single precision float */
typedef double         GLdouble; /* double precision float */
typedef float          GLclampf;
typedef double         GLclampd;
typedef int            GLsizei;
typedef	unsigned int   GLbitfield;
typedef unsigned short GLhalfARB;
typedef ptrdiff_t      GLintptr;
typedef ptrdiff_t      GLsizeiptr;
typedef ptrdiff_t      GLintptrARB;
typedef ptrdiff_t      GLsizeiptrARB;
typedef GLuint64       GLbitfield64;
typedef unsigned int   GLhandleARB;
typedef unsigned short GLhalfNV;

/* functions */

#ifndef _tgl_zgl_h_
typedef	struct _GLContext
{
	int dummy;
} GLContext;
#endif


#ifdef _NO_PPCINLINE

void glEnable(int code);
void glDisable(int code);
GLboolean glIsEnabled(GLenum cap);

void glShadeModel(int mode);
void glCullFace(int mode);
void glPolygonMode(int face,int mode);

void glBegin(int type);
void glEnd(void);

#define PROTO_GL1(name) \
void gl ## name ## 1f(GLfloat); \
void gl ## name ## 1d(GLdouble); \
void gl ## name ## 1fv(const GLfloat *); \
void gl ## name ## 1dv(const GLdouble *);

#define PROTO_GL2(name) \
void gl ## name ## 2f(GLfloat, GLfloat); \
void gl ## name ## 2d(GLdouble, GLdouble); \
void gl ## name ## 2fv(const GLfloat *); \
void gl ## name ## 2dv(const GLdouble *);

#define PROTO_GL3(name) \
void gl ## name ## 3f(GLfloat, GLfloat, GLfloat); \
void gl ## name ## 3d(GLdouble, GLdouble, GLdouble); \
void gl ## name ## 3fv(const GLfloat *); \
void gl ## name ## 3dv(const GLdouble *);

#define PROTO_GL4(name) \
void gl ## name ## 4f(GLfloat, GLfloat, GLfloat, GLfloat); \
void gl ## name ## 4d(GLdouble, GLdouble, GLdouble, GLdouble); \
void gl ## name ## 4fv(const GLfloat *); \
void gl ## name ## 4dv(const GLdouble *);

PROTO_GL2(Vertex)
PROTO_GL3(Vertex)
PROTO_GL4(Vertex)
void glVertex2s(GLshort x, GLshort y);
void glVertex2i(GLint x, GLint y);
void glVertex2sv(const GLshort *v);

PROTO_GL3(Color)
PROTO_GL4(Color)
void glColor4ub(GLubyte r, GLubyte g, GLubyte b, GLubyte a);
void glColor3ub(GLubyte r, GLubyte g, GLubyte b);
void glColor4ubv(const GLubyte *v);
void glColor3ubv(const GLubyte *v);

PROTO_GL3(Normal)
void glNormal3sv(const GLshort *v);
void glNormal3s(const GLshort x, GLshort y, GLshort z);

PROTO_GL2(TexCoord)
PROTO_GL3(TexCoord)
void glTexCoord1dv(const GLdouble *v);
void glTexCoord2dv(const GLdouble *v);
void glTexCoord3dv(const GLdouble *v);
void glTexCoord4dv(const GLdouble *v);
void glTexCoord2iv(const GLint *v);

void glEdgeFlag(GLboolean flag);

/* matrix */
void glMatrixMode(int mode);
void glLoadMatrixf(const GLfloat *m);
void glLoadMatrixd(const GLdouble *m);
void glLoadTransposeMatrixf(const GLfloat *m);
void glLoadTransposeMatrixd(const GLdouble *m);
void glLoadIdentity(void);
void glMultMatrixf(const GLfloat *m);
void glMultMatrixd(const GLdouble *m);
void glMultTransposeMatrixf(const GLfloat *m);
void glMultTransposeMatrixd(const GLdouble *m);
void glPushMatrix(void);
void glPopMatrix(void);
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glTranslatef(GLfloat x, GLfloat y, GLfloat z);
void glScalef(GLfloat x, GLfloat y, GLfloat z);

void glViewport(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
void glFrustum(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);

/* lists */
unsigned int glGenLists(int range);
int glIsList(unsigned int list);
void glNewList(unsigned int list,int mode);
void glEndList(void);
void glCallList(unsigned int list);
void glCallLists(GLsizei n, GLenum type, GLvoid *lists);
void glListBase(GLuint base);

void glDeleteLists(GLint list, GLsizei range);

/* clear */
void glClear(GLbitfield mask);
void glClearColor(GLclampf r, GLclampf g, GLclampf b, GLclampf a);
void glClearDepth(GLclampf depth);

/* selection */
int glRenderMode(int mode);
void glSelectBuffer(int size, unsigned int *buf);

void glInitNames(void);
void glPushName(unsigned int name);
void glPopName(void);
void glLoadName(unsigned int name);

/* textures */
void glGenTextures(GLsizei n, GLuint *textures);
void glDeleteTextures(GLsizei n, const GLuint *textures);
void glBindTexture(GLenum target, GLuint texture);
void glTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei border, GLenum format, GLenum type, const GLvoid *pixels);
void glTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei border, GLenum format, GLenum type, const GLvoid *pixels);
void glGetTexImage(GLenum tex, GLint lod, GLint format, GLenum type, GLvoid *dest);

void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid *pixels);

void glCopyTexImage2D( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border );
void glCopyTexSubImage2D( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height );

void glTexEnvi(int target, int pname,int param);
void glTexEnvf(int target, int pname,float param);
void glTexEnvfv(int target, int pname, const GLfloat *param);
void glGetTexEnvfv(int target, int pname, GLfloat *param);

void glGetTexEnviv(int target, int pname, GLint *param);
void glTexParameteri(int target, int pname, int param);
void glTexParameterf(int target, int pname, float param);
void glGetTexParameterfv(int target, int pname, float *param);
void glGetTexParameteriv(int target, int pname, int *param);
void glPixelStorei(int pname,int param);
void glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities);


/* lighting */

void glMaterialfv(int face,int pname, const GLfloat *v);
void glGetMaterialfv(int face,int pname, GLfloat *v);
void glMaterialf(int mode,int type,float v);
void glColorMaterial(int mode,int type);

void glLightfv(int light,int type, const GLfloat *v);
void glLightf(int light,int type,float v);
void glLightModeli(int pname,int param);
void glLightModelf(int pname,float param);
void glLightModelfv(int pname, const GLfloat *param);

/* misc */

void glFlush(void);
void glHint(int target,int mode);
void glGetIntegerv(int pname,int *params);
void glGetFloatv(int pname, float *v);
void glGetDoublev(int pname, double *v);
void glGetPointerv(int pname, void **v);
void glGetTexLevelParameteriv(GLenum target, GLint lod, GLenum pname, GLint *params);
void glGetLightfv(GLenum light, GLenum pname, GLfloat *v);

void glFrontFace(int mode);

GLbyte *glGetString(GLenum tag);

/* opengl 1.2 arrays */
void glEnableClientState(GLenum array);
void glDisableClientState(GLenum array);
void glArrayElement(GLint i);
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer);
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);

void glDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid *indices);
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid *indices);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);

void glLockArraysEXT(GLint first, GLint count);
void glUnlockArraysEXT(void);


/* opengl 1.2 polygon offset */
void glPolygonOffset(GLfloat factor, GLfloat units);

/* blending */
void glBlendColor(GLclampf, GLclampf, GLclampf, GLclampf);
void glBlendEquation(GLenum);
void glBlendEquationSeparate(GLenum, GLenum);
void glBlendFunc(GLenum, GLenum);
void glBlendFuncSeparate(GLenum, GLenum, GLenum, GLenum);

void glOrtho(float,float,float,float,float,float);

void glDepthFunc(GLenum func);
void glDepthMask(GLboolean mask);
void glDepthRange(GLclampf near, GLclampf far);

void glAlphaFunc(GLenum func, GLclampf ref);

int GLAInitializeContextWindowed(GLContext *context, void *w);
void GLADestroyContextWindowed(GLContext *context);
void GLADestroyContextBitMap(GLContext *context);
void GLASwapBuffers(GLContext *c);

/* multitexture extension */

void glActiveTextureARB(GLenum unit);
void glMultiTexCoord2fARB(GLenum unit, GLfloat s, GLfloat t);
void glMultiTexCoord3fARB(GLenum unit, GLfloat s, GLfloat t, GLfloat r);
void glMultiTexCoord4fARB(GLenum unit, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord2fvARB(GLenum unit, const GLfloat *v);
void glMultiTexCoord3fvARB(GLenum unit, const GLfloat *v);
void glMultiTexCoord4fvARB(GLenum unit, const GLfloat *v);
void glMultiTexCoord2dvARB(GLenum unit, const GLdouble *v);
void glMultiTexCoord3dvARB(GLenum unit, const GLdouble *v);
void glClientActiveTextureARB(GLenum unit);

/* OpenGL 2 multitexture */

void glActiveTexture(GLenum unit);
void glMultiTexCoord2f(GLenum unit, GLfloat s, GLfloat t);
void glMultiTexCoord3f(GLenum unit, GLfloat s, GLfloat t, GLfloat r);
void glMultiTexCoord4f(GLenum unit, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord2fv(GLenum unit, const GLfloat *v);
void glMultiTexCoord3fv(GLenum unit, const GLfloat *v);
void glMultiTexCoord4fv(GLenum unit, const GLfloat *v);
void glMultiTexCoord2dv(GLenum unit, const GLdouble *v);
void glMultiTexCoord3dv(GLenum unit, const GLdouble *v);
void glClientActiveTexture(GLenum unit);

/* point parameter extension */

void glPointSize(GLfloat  size);
void glPointParameterfEXT(GLenum pname, GLfloat param);
void glPointParameterfvEXT(GLenum pname, const GLfloat *params);

/* texGen */

void glTexGeni(GLenum coord, GLenum pname, GLint val);
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat *val);

/* push/pop attrib */

void glPushAttrib(GLbitfield mask);
void glPushClientAttrib(GLbitfield mask);
void glPopAttrib(void);
void glPopClientAttrib(void);

/* scissor */

void glScissor(GLint left, GLint bottom, GLsizei width, GLsizei height);

/* line width */

void glLineWidth(GLfloat width);

/* rect */

void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void glRectfv(const GLfloat *v1, const GLfloat *v2);
void glRectdv(const GLdouble *v1, const GLdouble *v2);
void glRectiv(const GLint *v1, const GLint *v2);

/* evaluators */

void glEvalPoint1(GLint i);
void glEvalPoint2(GLint i, GLint j);
void glEvalCoord1f(GLfloat u);
void glEvalCoord2f(GLfloat u, GLfloat v);
void glEvalCoord1fv(const GLfloat *u);
void glEvalCoord2fv(const GLfloat *u);
void glEvalMesh1(GLenum mode, GLint p1, GLint p2);
void glEvalMesh2(GLenum mode, GLint p1, GLint p2, GLint q1, GLint q2);

void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
void glGetMapdv(GLenum target, GLenum query, GLdouble *v);
void glGetMapfv(GLenum target, GLenum query, GLfloat *v);
void glGetMapiv(GLenum target, GLenum query, GLint *v);
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);

/* COLOR_INDEX based textures support */

void glColorTable(GLenum target, GLenum internalformat, GLint width, GLenum format, GLenum type, GLvoid *data);

/* raster functions */

void glRasterPos2f(GLfloat x, GLfloat y);
void glRasterPos2fv(const GLfloat *v);
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
void glRasterPos3fv(const GLfloat *v);
void glWindowPos2f(GLfloat x, GLfloat y);
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bits);
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *data);

void glPixelZoom(GLfloat x, GLfloat y);
void glPixelTransferi(GLenum param, GLint value);
void glPixelTransferf(GLenum param, GLfloat value);

/* fog */

void glFogf(GLenum pname, GLfloat param);
void glFogfv(GLenum pname, const GLfloat *param);

/* drawbuffer */

void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *data);
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void glReadBuffer(GLenum buffer);
void glDrawBuffer(GLenum buffer);

void glColorMask(GLboolean r, GLboolean g, GLboolean b, GLboolean a);

/* stencil */

void glStencilFunc(GLenum func, GLint ref, GLuint mask);
void glStencilOp(GLenum sfail, GLenum dpfail, GLenum dppass);
void glStencilMask(GLuint mask);
void glClearStencil(GLint s);

/* clip planes */

void glClipPlane(GLenum plane, GLdouble equation[ 4 ]);
void glGetClipPlane(GLenum plane, GLdouble equation[ 4 ]);

/* misc */

int glIsTexture(GLuint texture);
GLenum glGetError(void);
void glLineStipple(GLint factor, GLushort pattern);

void *TGLGetContexts(void);

GLContext *GLInit(void);
void GLClose(GLContext *context);

#else

void GLEnable(GLContext	*context, int code);
void GLDisable(GLContext *context, int code);
GLboolean GLIsEnabled(GLContext *context, GLenum cap);

void GLShadeModel(GLContext	*context, int mode);
void GLCullFace(GLContext *context, int mode);
void GLPolygonMode(GLContext *context, int face,int mode);

void GLBegin(GLContext *context, int type);
void GLEnd(GLContext *context);


#define PROTO_GL1(name) \
void GL ## name ## 1f(GLContext	*context, GLfloat); \
/*void gl ## name ## 1d(GLContext *context, GLdouble);*/ \
void GL ## name ## 1fv(GLContext *context, const GLfloat *); \
void GL ## name ## 1dv(GLContext *context, const GLdouble *);

#define PROTO_GL2(name) \
void GL ## name ## 2f(GLContext	*context, GLfloat, GLfloat); \
/*void gl ## name ## 2d(GLdouble, GLdouble);*/ \
void GL ## name ## 2fv(GLContext *context, const GLfloat *); \
/*void GL ## name ## 2dv(GLContext *context, const GLdouble *); */

#define PROTO_GL3(name) \
void GL ## name ## 3f(GLContext	*context, GLfloat, GLfloat, GLfloat); \
/*void gl ## name ## 3d(double, GLdouble, GLdouble);*/ \
void GL ## name ## 3fv(GLContext *context, const GLfloat *); \
/*void GL ## name ## 3dv(GLContext *context, GLdouble *); */

#define PROTO_GL4(name) \
void GL ## name ## 4f(GLContext	*context, GLfloat, GLfloat, GLfloat, GLfloat); \
/*void gl ## name ## 4d(double, GLdouble, GLdouble, GLdouble);*/ \
void GL ## name ## 4fv(GLContext *context, const GLfloat *); \
/*void GL ## name ## 4dv(GLContext *context, const GLdouble *);*/

PROTO_GL3(Vertex)
PROTO_GL4(Vertex)
void GLVertex3dv(GLContext *context, const GLdouble *v);
void GLVertex4dv(GLContext *context, const GLdouble *v);

PROTO_GL3(Color)
PROTO_GL4(Color)
void GLColor4ub(GLContext *context, GLubyte r, GLubyte g, GLubyte b, GLubyte a);
void GLColor3ub(GLContext *context, GLubyte r, GLubyte g, GLubyte b);
void GLColor4ubv(GLContext *context, const GLubyte *v);
void GLColor4dv(GLContext *context, const GLdouble *v);
void GLColor3ubv(GLContext *context, const GLubyte *v);
void GLColor3dv(GLContext *context, const GLdouble *v);

PROTO_GL3(Normal)
void GLNormal3sv(GLContext *context, const GLshort *v);
void GLNormal3dv(GLContext *context, const GLdouble *v);
void GLNormal3s(GLContext *context, const GLshort x, GLshort y, GLshort z);

PROTO_GL2(TexCoord)
PROTO_GL3(TexCoord)
void GLTexCoord1dv(GLContext *context, const GLdouble *v);
void GLTexCoord2dv(GLContext *context, const GLdouble *v);
void GLTexCoord3dv(GLContext *context, const GLdouble *v);
void GLTexCoord4dv(GLContext *context, const GLdouble *v);
void GLTexCoord2iv(GLContext *context, const GLint *v);

void GLEdgeFlag(GLContext *context, GLboolean flag);

/* matrix */
void GLMatrixMode(GLContext *context, int mode);
void GLLoadMatrixf(GLContext *context, const GLfloat *m);
void GLLoadMatrixd(GLContext *context, const GLdouble *m);
void GLLoadTransposeMatrixf(GLContext *context, const GLfloat *m);
void GLLoadTransposeMatrixd(GLContext *context, const GLdouble *m);
void GLLoadIdentity(GLContext *context);
void GLMultMatrixf(GLContext *context, const GLfloat *m);
void GLMultMatrixd(GLContext *context, const GLdouble *m);
void GLMultTransposeMatrixf(GLContext *context, const GLfloat *m);
void GLMultTransposeMatrixd(GLContext *context, const GLdouble *m);
void GLPushMatrix(GLContext	*context);
void GLPopMatrix(GLContext *context);
void GLRotatef(GLContext *context, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void GLTranslatef(GLContext	*context, GLfloat x, GLfloat y, GLfloat z);
void GLScalef(GLContext	*context, GLfloat x, GLfloat y, GLfloat z);

void GLViewport(GLContext *context, GLfloat x, GLfloat y, GLfloat width, GLfloat height);
void GLFrustum(GLContext *context, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);

/* lists */
unsigned int GLGenLists(GLContext *context, int range);
int GLIsList(GLContext *context, unsigned int list);
void GLNewList(GLContext *context, unsigned int list,int mode);
void GLEndList(GLContext *context);
void GLCallList(GLContext *context, unsigned int list);
void GLCallLists(GLContext *c, GLsizei n, GLenum type, GLvoid   *lists);
void GLListBase(GLContext *c, GLuint base);

void GLDeleteLists(GLContext *context, GLint list, GLsizei range);

/* clear */
void GLClear(GLContext *context, GLbitfield mask);
void GLClearColor(GLContext	*context, GLclampf r, GLclampf g, GLclampf b, GLclampf a);
void GLClearDepth(GLContext *context, GLclampf depth);

/* selection */
int GLRenderMode(GLContext *context, int mode);
void GLSelectBuffer(GLContext *context, int size, unsigned int *buf);

void GLInitNames(GLContext *context);
void GLPushName(GLContext *context, unsigned int name);
void GLPopName(GLContext *context);
void GLLoadName(GLContext *context, unsigned int name);

/* textures */
void GLGenTextures(GLContext *context, GLsizei n, GLuint *textures);
void GLDeleteTextures(GLContext	*context, GLsizei n, const GLuint *textures);
void GLBindTexture(GLContext *context, GLenum target, GLuint texture);
void GLTexImage2D(GLContext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei border, GLenum format, GLenum type, const GLvoid *pixels);
void GLTexImage1D(GLContext *context, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei border, GLenum format, GLenum type, const GLvoid *pixels);
void GLGetTexImage(GLContext *context, GLenum   tex, GLint lod, GLint format, GLenum type, GLvoid   *dest);

void GLTexSubImage2D(GLContext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
void GLTexSubImage1D(GLContext *context, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid *pixels);

void GLCopyTexImage2D( GLContext *context, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border );
void GLCopyTexSubImage2D( GLContext *context, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height );

void GLTexEnvi(GLContext *context, GLenum target, GLenum pname, GLint param);
void GLTexEnvf(GLContext *context, GLenum target, GLenum pname, GLfloat param);
void GLTexEnvfv(GLContext *context, GLenum target, GLenum pname, const GLfloat *param);
void GLGetTexEnvfv(GLContext *context, GLenum target, GLenum pname, GLfloat *param);
void GLGetTexEnviv(GLContext *context, GLenum target, GLenum pname, GLint *param);
void GLTexParameteri(GLContext *context, int target, int pname, int param);
void GLTexParameterf(GLContext *context, int target, int pname, float param);
void GLGetTexParameterfv(GLContext *context, int target, int pname, float *param);
void GLGetTexParameteriv(GLContext *context, int target, int pname, int *param);
void GLPixelStorei(GLContext *context, int pname,int param);
void GLPrioritizeTextures(GLContext *context, GLsizei n, const GLuint *textures, const GLclampf *priorities);

/* lighting */

void GLMaterialfv(GLContext *context, int mode,int type, const GLfloat *v);
void GLGetMaterialfv(GLContext *context, int mode,int type, GLfloat *v);
void GLMaterialf(GLContext *context, int mode,int type,float v);
void GLColorMaterial(GLContext *context, int mode,int type);

void GLLightfv(GLContext *context, int light,int type, const GLfloat *v);
void GLLightf(GLContext	*context, int light,int type,float v);
void GLLightModeli(GLContext *context, int pname,int param);
void GLLightModelf(GLContext *context, int pname,float param);
void GLLightModelfv(GLContext *context, int pname, const GLfloat *param);

/* misc */

void GLFlush(GLContext *context);
void GLHint(GLContext *context, int target,int mode);
void GLGetIntegerv(GLContext *context, int pname,int *params);
void GLGetFloatv(GLContext *context, int pname, float *v);
void GLGetDoublev(GLContext *context, int pname, double *v);
void GLGetPointerv(GLContext *context, int pname, void **v);
void GLGetTexLevelParameteriv(GLContext   *c, GLenum target, GLint lod, GLenum pname, GLint *params);
void GLGetLightfv(GLContext *c, GLenum light, GLenum pname, GLfloat *v);

void GLFrontFace(GLContext *context, int mode);

GLbyte	*GLGetString(GLContext *context, GLenum	  tag);

/* opengl 1.2 arrays */

void GLEnableClientState(GLContext *context, GLenum array);
void GLDisableClientState(GLContext *context, GLenum array);
void GLArrayElement(GLContext *context, GLint i);
void GLVertexPointer(GLContext *context, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void GLColorPointer(GLContext *context, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void GLNormalPointer(GLContext *context, GLenum type, GLsizei stride, const GLvoid *pointer);
void GLTexCoordPointer(GLContext *context, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);

void GLDrawElements(GLContext *context, GLenum mode, GLsizei count, GLenum type, GLvoid *indices);
void GLDrawRangeElements(GLContext *context, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid *indices);
void GLDrawArrays(GLContext *context, GLenum mode, GLint first, GLsizei count);

void GLLockArraysEXT(GLContext *context, GLint first, GLint count);
void GLUnlockArraysEXT(GLContext *context);

/* opengl 1.2 polygon offset */
void GLPolygonOffset(GLContext *context, GLfloat factor, GLfloat units);

/* blending */
void GLBlendColor(GLContext *context, GLclampf, GLclampf, GLclampf, GLclampf);
void GLBlendEquation(GLContext *context, GLenum);
void GLBlendEquationSeparate(GLContext *context, GLenum, GLenum);
void GLBlendFunc(GLContext *context, GLenum, GLenum);
void GLBlendFuncSeparate(GLContext *context, GLenum, GLenum, GLenum, GLenum);

void GLOrtho(GLContext *context, float,float,float,float,float,float);

void GLDepthFunc(GLContext *context, GLenum func);
void GLDepthMask(GLContext *context, GLboolean mask);
void GLDepthRange(GLContext	*context, GLclampf near, GLclampf far);

void GLAlphaFunc(GLContext *context, GLenum	  func, GLclampf ref);

int GLAInitializeContextWindowed(GLContext *context, void *w);
void GLADestroyContextWindowed(GLContext *context);
void GLADestroyContextBitMap(GLContext *context);
void GLASwapBuffers(GLContext *c);

/* multitexture extension */

void GLActiveTextureARB(GLContext *context, GLenum unit);
void GLMultiTexCoord2fARB(GLContext *context, GLenum unit, GLfloat s, GLfloat t);
void GLMultiTexCoord3fARB(GLContext *context, GLenum unit, GLfloat s, GLfloat t, GLfloat r);
void GLMultiTexCoord4fARB(GLContext *context, GLenum unit, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void GLMultiTexCoord2fvARB(GLContext *context, GLenum unit, const GLfloat *v);
void GLMultiTexCoord3fvARB(GLContext *context, GLenum unit, const GLfloat *v);
void GLMultiTexCoord4fvARB(GLContext *context, GLenum unit, const GLfloat *v);
void GLMultiTexCoord2dvARB(GLContext *context, GLenum unit, const GLdouble *v);
void GLMultiTexCoord3dvARB(GLContext *context, GLenum unit, const GLdouble *v);
void GLClientActiveTextureARB(GLContext	 *context, GLenum unit);

/* OpenGL 2 multitexture */

void GLActiveTexture(GLContext *context, GLenum unit);
void GLMultiTexCoord2f(GLContext *context, GLenum unit, GLfloat s, GLfloat t);
void GLMultiTexCoord3f(GLContext *context, GLenum unit, GLfloat s, GLfloat t, GLfloat r);
void GLMultiTexCoord4f(GLContext *context, GLenum unit, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void GLMultiTexCoord2fv(GLContext *context, GLenum unit, const GLfloat *v);
void GLMultiTexCoord3fv(GLContext *context, GLenum unit, const GLfloat *v);
void GLMultiTexCoord4fv(GLContext *context, GLenum unit, const GLfloat *v);
void GLMultiTexCoord2dv(GLContext *context, GLenum unit, const GLdouble *v);
void GLMultiTexCoord3dv(GLContext *context, GLenum unit, const GLdouble *v);
void GLClientActiveTexture(GLContext *context, GLenum unit);

/* point parameter extension */

void GLPointSize(GLContext *context, GLfloat  size);
void GLPointParameterfEXT(GLContext *context, GLenum pname, GLfloat param);
void GLPointParameterfvEXT(GLContext *context, GLenum pname, const GLfloat *params);

/* texGen */

void GLTexGeni(GLContext *context, GLenum coord, GLenum pname, GLint val);
void GLTexGenfv(GLContext *context, GLenum coord, GLenum pname, const GLfloat *val);

/* push/pop attrib */

void GLPushAttrib(GLContext *context, GLbitfield mask);
void GLPushClientAttrib(GLContext *context, GLbitfield mask);
void GLPopAttrib(GLContext *context);
void GLPopClientAttrib(GLContext*context);

/* scissor */

void GLScissor(GLContext *context, GLint left, GLint bottom, GLsizei width, GLsizei height);

/* line width */

void GLLineWidth(GLContext *context, GLfloat width);

/* rect */

void GLRectf(GLContext *context, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void GLRectfv(GLContext *context, GLfloat *v1, GLfloat	*v2);
void GLRectdv(GLContext *context, GLdouble *v1, GLdouble *v2);
void GLRectiv(GLContext *context, GLint  *v1, GLint *v2);

/* evaluators */

void GLEvalPoint1(GLContext *c, GLint i);
void GLEvalPoint2(GLContext *c, GLint i, GLint j);
void GLEvalCoord1f(GLContext *c, GLfloat u);
void GLEvalCoord2f(GLContext *c, GLfloat u, GLfloat v);
void GLEvalCoord1fv(GLContext *c, const GLfloat *u);
void GLEvalCoord2fv(GLContext *c, const GLfloat *u);
void GLEvalMesh1(GLContext *c, GLenum mode, GLint p1, GLint p2);
void GLEvalMesh2(GLContext *c, GLenum mode, GLint p1, GLint p2, GLint q1, GLint q2);

void GLMap1f(GLContext *c, GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
void GLMap1d(GLContext *c, GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
void GLMap2f(GLContext *c, GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
void GLMap2d(GLContext *c, GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
void GLGetMapdv(GLContext *c, GLenum target, GLenum query, GLdouble *v);
void GLGetMapfv(GLContext *c, GLenum target, GLenum query, GLfloat *v);
void GLGetMapiv(GLContext *c, GLenum target, GLenum query, GLint *v);
void GLMapGrid1f(GLContext *c, GLint un, GLfloat u1, GLfloat u2);
void GLMapGrid1d(GLContext *c, GLint un, GLdouble u1, GLdouble u2);
void GLMapGrid2f(GLContext *c, GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
void GLMapGrid2d(GLContext *c, GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);

/* COLOR_INDEX based textures support */

void GLColorTable(GLContext *context, GLenum target, GLenum internalformat, GLint width, GLenum format, GLenum type, GLvoid *data);

/* raster functions */

void GLRasterPos2f(GLContext *context, GLfloat x, GLfloat y);
void GLRasterPos2fv(GLContext *context, const GLfloat *v);
void GLRasterPos3f(GLContext *context, GLfloat x, GLfloat y, GLfloat z);
void GLRasterPos3fv(GLContext *context, const GLfloat *v);
void GLWindowPos2f(GLContext *context, GLfloat x, GLfloat y);
void GLBitmap(GLContext	*context, GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bits);
void GLDrawPixels(GLContext *context, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *data);

void GLPixelZoom(GLContext *context, GLfloat x, GLfloat y);
void GLPixelTransferi(GLContext *context, GLenum param, GLint value);
void GLPixelTransferf(GLContext *context, GLenum param, GLfloat value);

/* fog */

void GLFogf(GLContext *context, GLenum pname, GLfloat param);
void GLFogfv(GLContext *context, GLenum pname, const GLfloat *param);

/* drawbuffer */

void GLReadPixels(GLContext *c, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *data);
void GLCopyPixels(GLContext *c, GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void GLReadBuffer(GLContext *c, GLenum buffer);
void GLDrawBuffer(GLContext *c, GLenum buffer);

void GLColorMask(GLContext *c, GLboolean r, GLboolean g, GLboolean b, GLboolean a);

/* stencil */

void GLStencilFunc(GLContext *context, GLenum func, GLint ref, GLuint mask);
void GLStencilOp(GLContext *context, GLenum sfail, GLenum dpfail, GLenum dppass);
void GLStencilMask(GLContext *context, GLuint mask);
void GLClearStencil(GLContext *context, GLint s);

/* clip planes */

void GLClipPlane(GLContext *context, GLenum plane, GLdouble equation[ 4 ]);
void GLGetClipPlane(GLContext *context, GLenum plane, GLdouble equation[ 4 ]);

/* shaders */

void GLAttachShader(GLContext *context,	GLuint program,	GLuint shader);
void GLCompileShader(GLContext *context, GLuint	shader);
void GLLinkProgram(GLContext *context, GLuint program);
void GLUseProgram(GLContext *context, GLuint program);
GLuint GLCreateShader(GLContext *context, GLenum shaderType);
GLuint GLCreateProgram(GLContext *context);
void GLShaderSource(GLContext *context, GLuint shader, GLsizei count, const GLchar **string, const GLint *length);
void GLValidateProgram(GLContext *context, GLuint program);

void GLUniform1f(GLContext *context, GLint location, GLfloat v);
void GLUniform2f(GLContext *context, GLint location, GLfloat v1, GLfloat v2);
void GLUniform3f(GLContext *context, GLint location, GLfloat v1, GLfloat v2, GLfloat v3);
void GLUniform4f(GLContext *context, GLint location, GLfloat v1, GLfloat v2, GLfloat v3, GLfloat v4);
void GLUniform1i(GLContext *context, GLint location, GLint v);
void GLUniform2i(GLContext *context, GLint location, GLint v1, GLint v2);
void GLUniform3i(GLContext *context, GLint location, GLint v1, GLint v2, GLint v3);
void GLUniform4i(GLContext *context, GLint location, GLint v1, GLint v2, GLint v3, GLint v4);
void GLUniform1ui(GLContext *context, GLint location, GLuint v);
void GLUniform2ui(GLContext *context, GLint location, GLuint v1, GLuint v2);
void GLUniform3ui(GLContext *context, GLint location, GLuint v1, GLuint v2, GLuint v3);
void GLUniform4ui(GLContext *context, GLint location, GLuint v1, GLuint v2, GLuint v3, GLuint v4);

void GLUniform1fv(GLContext *context, GLint location, GLsizei count, const GLfloat *value);
void GLUniform2fv(GLContext *context, GLint location, GLsizei count, const GLfloat *value);
void GLUniform3fv(GLContext *context, GLint location, GLsizei count, const GLfloat *value);
void GLUniform4fv(GLContext *context, GLint location, GLsizei count, const GLfloat *value);
void GLUniform1iv(GLContext *context, GLint location, GLsizei count, const GLint *value);
void GLUniform2iv(GLContext *context, GLint location, GLsizei count, const GLint *value);
void GLUniform3iv(GLContext *context, GLint location, GLsizei count, const GLint *value);
void GLUniform4iv(GLContext *context, GLint location, GLsizei count, const GLint *value);
void GLUniform1uiv(GLContext *context, GLint location, GLsizei count, const GLuint *value);
void GLUniform2uiv(GLContext *context, GLint location, GLsizei count, const GLuint *value);
void GLUniform3uiv(GLContext *context, GLint location, GLsizei count, const GLuint *value);
void GLUniform4uiv(GLContext *context, GLint location, GLsizei count, const GLuint *value);

void GLUniformMatrix2fv(GLContext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat *v);
void GLUniformMatrix2x3fv(GLContext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat *v);
void GLUniformMatrix2x4fv(GLContext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat *v);
void GLUniformMatrix3fv(GLContext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat *v);
void GLUniformMatrix3x2fv(GLContext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat *v);
void GLUniformMatrix3x4fv(GLContext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat *v);
void GLUniformMatrix4fv(GLContext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat *v);
void GLUniformMatrix4x2fv(GLContext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat *v);
void GLUniformMatrix4x3fv(GLContext *context, GLint location, GLsizei count, GLboolean transpose, const GLfloat *v);

GLint GLGetUniformLocation(GLContext *context, GLuint program, const char *name);
GLint GLGetAttribLocation(GLContext *context, GLuint program, const GLchar *name);
void GLVertexAttribPointer(GLContext *context, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
void GLEnableVertexAttribArray(GLContext *context, GLuint index);
void GLDisableVertexAttribArray(GLContext *context, GLuint index);

void GLGetShaderiv(GLContext *context, GLuint shader, GLenum pname, GLint *params);
void GLGetProgramiv(GLContext *context, GLuint program, GLenum pname, GLint *params);

void GLGetProgramInfoLog(GLContext *context, GLuint program, GLsizei maxlength, GLsizei *length, GLchar *infolog);
void GLGetShaderInfoLog(GLContext *context, GLuint shader, GLsizei maxlength, GLsizei *length, GLchar *infolog);

/* Buffers */

void GLGenBuffers(GLContext *context, GLuint num, GLuint *out);
void GLBufferData(GLContext *context, GLenum target, GLsizei size, const GLvoid * data, GLenum usage);
void GLBufferSubData(GLContext *context, GLenum target, GLintptr offset, GLsizei size, const GLvoid * data);
void GLBindBuffer(GLContext *context, GLenum target, GLuint buffer);
void GLDeleteBuffers(GLContext *context, GLsizei n, const GLuint *buffers);
void GLGetBufferParameteriv(GLContext *context,	GLenum target, GLenum value, GLint * data);

/* misc */

int GLIsTexture(GLContext *c, GLuint texture);
GLenum GLGetError(GLContext *c);
void GLLineStipple(GLContext *c, GLint factor, GLushort pattern);

void *TGLGetContexts(void);

GLContext *GLInit(void);
void GLClose(GLContext *context);

/*
 Real interface functions.
*/

extern GLContext *__tglContext;

#define glAlphaFunc(func, ref) GLAlphaFunc(__tglContext, func, ref)
#define glArrayElement(i) GLArrayElement(__tglContext, i)
#define glBegin(mode) GLBegin(__tglContext, mode)
#define glEnd() GLEnd(__tglContext)

#define glTexGeni(coord,mode,map) GLTexGeni(__tglContext, coord, mode, map)
#define glTexGenfv(coord,mode,map) GLTexGenfv(__tglContext, coord, mode, map)
#define glTexGenf(coord,mode,map) GLTexGeni(__tglContext, coord, mode, (GLenum)map)

#define glBindTexture(target, texture) GLBindTexture(__tglContext, target, texture)

#define glBlendColor(red, green, blue, alpha) GLBlendColor(__tglContext, red, green, blue, alpha)
#define glBlendEquation(mode) GLBlendEquation(__tglContext, mode)
#define glBlendEquationSeparate(modeRGB, modeAlpha) GLBlendEquationSeparate(__tglContext, modeRGB, modeAlpha)
#define glBlendFunc(sfactor, dfactor) GLBlendFunc(__tglContext, sfactor, dfactor)
#define glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) GLBlendFuncSeparate(__tglContext, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha)

#define glClear(mask) GLClear(__tglContext, mask)

#define glClearColor(red, green, blue, alpha) GLClearColor(__tglContext, red, green, blue, alpha)

#define glClearDepth(depth) GLClearDepth(__tglContext, depth)

#define glColorPointer(size, type, stride, pointer) GLColorPointer(__tglContext, size, type, stride, pointer)

#define glCullFace(mode) GLCullFace(__tglContext, mode)

#define glDeleteTextures(n, textures) GLDeleteTextures(__tglContext, n, textures)

#define glDepthFunc(func) GLDepthFunc(__tglContext, func)

#define glDepthMask(flag) GLDepthMask(__tglContext, flag)

#define glEnable(cap) GLEnable(__tglContext, cap)

#define glDisable(cap) GLDisable(__tglContext, cap)

#define glDisableClientState(cap) GLDisableClientState(__tglContext, cap)

#define glEnableClientState(cap) GLEnableClientState(__tglContext, cap)

#define glDrawBuffer(mode) GLDrawBuffer(__tglContext, mode)
#define glFlush() GLFlush(__tglContext)

#define glFogf(pname, param) GLFogf(__tglContext, pname, param)
#define glFogfv(pname, param) GLFogfv(__tglContext, pname, param)
#define glFogi(pname, param) GLFogf(__tglContext,pname, (GLfloat)param)

#define glFrontFace(mode) GLFrontFace(__tglContext, mode)

#define glFrustum(left, right, bottom, top, zNear, zFar) GLFrustum(__tglContext, left, right, bottom, top, zNear, zFar)

#define glGenTextures(n, textures) GLGenTextures(__tglContext, n, textures)

#define glGetError() GLGetError(__tglContext)

#define glGetBooleanv(pname, params) GLGetBooleanv(__tglContext, pname, params)

#define glGetDoublev(pname, params) GLGetDoublev(__tglContext, pname, params)

#define glGetFloatv(pname, params) GLGetFloatv(__tglContext, pname, params)

#define glGetTexLevelParameteriv(target, lod,pname, params) GLGetTexLevelParameteriv(__tglContext, target, lod, pname, params)

#define glGetIntegerv(pname, params) GLGetIntegerv(__tglContext, pname, params)

#define glGetPointerv(pname, params) GLGetPointerv(__tglContext, pname, params)

#define glGetString(name) GLGetString(__tglContext, name)

#define glGetLightfv(light, pname, v) GLGetLightfv(__tglContext, light, pname, v)

#define glHint(target, mode) GLHint(__tglContext, target, mode)

#define glIsEnabled(cap) GLIsEnabled(__tglContext, cap)

#define glLoadIdentity() GLLoadIdentity(__tglContext)

#define glLoadMatrixf(m) GLLoadMatrixf(__tglContext, m)

#define glLoadMatrixd(m) GLLoadMatrixd(__tglContext, m)

#define glLoadTransposeMatrixf(m) GLLoadTransposeMatrixf(__tglContext, m)

#define glLoadTransposeMatrixd(m) GLLoadTransposeMatrixd(__tglContext, m)

#define glMatrixMode(mode) GLMatrixMode(__tglContext, mode)

#define glMultMatrixd(m) GLMultMatrixd(__tglContext, m)

#define glMultMatrixf(m) GLMultMatrixf(__tglContext, m)

#define glMultTransposeMatrixd(m) GLMultTransposeMatrixd(__tglContext, m)

#define glMultTransposeMatrixf(m) GLMultTransposeMatrixf(__tglContext, m)

#define glOrtho(left, right, bottom, top, zNear, zFar) GLOrtho(__tglContext, left, right, bottom, top, zNear, zFar)

#define glPixelStorei(pname, param) GLPixelStorei(__tglContext, pname, param)

#define glPixelStoref(pname, param) GLPixelStorei(__tglContext, pname, (int)(param))

#define glPolygonMode(face, mode) GLPolygonMode(__tglContext, face, mode)

#define glPolygonOffset(factor, units) GLPolygonOffset(__tglContext, factor, units)

#define glPushMatrix() GLPushMatrix(__tglContext)

#define glPopMatrix() GLPopMatrix(__tglContext)

#define glRotatef(angle, x, y, z) GLRotatef(__tglContext, (angle), (x), (y), (z))

#define glScaled(x, y, z) GLScalef(__tglContext, (GLfloat)(x), (GLfloat)(y), (GLfloat)(z))

#define glScalef(x, y, z) GLScalef(__tglContext, x, y, z)

#define glScissor(x, y, w, h) GLScissor(__tglContext, x, y, w, h)

#define glShadeModel(mode) GLShadeModel(__tglContext, mode)

#define glEdgeFlag(flag) GLEdgeFlag(__tglContext, flag);

#define glTexCoord2f(s, t) GLTexCoord2f(__tglContext, s, t)
#define glTexCoord3f(s, t, r) GLTexCoord3f(__tglContext, s, t, r)
#define glTexCoord2i(s, t) GLTexCoord2f(__tglContext, (int)(s), (int)(t))

#define glTexCoord2fv(v) GLTexCoord2fv(__tglContext, v)
#define glTexCoord2iv(v) GLTexCoord2iv(__tglContext, v)
#define glTexCoord1dv(v) GLTexCoord1dv(__tglContext, v)
#define glTexCoord2dv(v) GLTexCoord2dv(__tglContext, v)
#define glTexCoord3dv(v) GLTexCoord3dv(__tglContext, v)
#define glTexCoord4dv(v) GLTexCoord4dv(__tglContext, v)
#define glTexCoord4f(s, t, r, q) GLMultiTexCoord4fARB(__tglContext, GL_TEXTURE0_ARB, s, t, r, q)
#define glTexCoord4fv(v) GLTexCoord4fv(__tglContext, v)

#define glTexCoordPointer(size, type, stride, pointer) GLTexCoordPointer(__tglContext, size, type, stride, pointer)

#define glTexImage2D(target, level, internal, width, height, border, format, type, pixels) GLTexImage2D(__tglContext, target, level, internal, width, height, border, format, type, pixels)
#define glTexImage1D(target, level, internal, width, border, format, type, pixels) GLTexImage1D(__tglContext, target, level, internal, width, border, format, type, pixels)

#define glCopyTexImage2D( target, level, internalformat, x, y, width, height, border ) GLCopyTexImage2D( __tglContext, target, level, internalformat, x, y, width, height, border )
#define glCopyTexSubImage2D( target, level, xoffset, yoffset, x, y, width, height ) GLCopyTexSubImage2D( __tglContext, target, level, xoffset, yoffset, x, y, width, height)

#define	glGetTexImage(target, level, format, type, dest)  GLGetTexImage(__tglContext, target, level, format, type, dest)

#define glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels) GLTexSubImage2D(__tglContext, target, level, xoffset, yoffset, width, height, format, type, pixels)
#define glTexSubImage1D(target, level, xoffset, width, format, type, pixels) GLTexSubImage1D(__tglContext, target, level, xoffset, width, format, type, pixels)

#define glPrioritizeTextures(n, textures, priorities) GLPrioritizeTextures(__tglContext, n, textures, priorities)

#define glTranslatef(x, y, z) GLTranslatef(__tglContext, x, y, z)

#define glViewport(x, y, width, height) GLViewport(__tglContext, x, y, width, height)

#define	glVertex2d(x,y)   GLVertex3f(__tglContext, (float)(x), (float)(y), 0.0f)
#define	glVertex2s(x,y)   GLVertex3f(__tglContext, (float)(x), (float)(y), 0.0f)
#define	glVertex3d(x,y,z) GLVertex3f(__tglContext, (float)(x), (float)(y), (float)(z))

#define glVertex4f(x,y,z,w) GLVertex4f(__tglContext, x, y, z, w)
#define glVertex3f(x,y,z)   GLVertex3f(__tglContext, x, y, z)
#define glVertex2f(x,y)     GLVertex3f(__tglContext, x, y, 0.0f)
#define glVertex2i(x,y)     GLVertex3f(__tglContext, (GLfloat)(x), (GLfloat)(y), 0.0f)

#define glVertex4fv(v) GLVertex4fv(__tglContext, v)
#define glVertex4dv(v) GLVertex4dv(__tglContext, v)
#define glVertex3fv(v) GLVertex3fv(__tglContext, v)
#define glVertex3dv(v) GLVertex3dv(__tglContext, v)
#define glVertex2fv(v) GLVertex3f(__tglContext, ((v)[0]), (v)[1], 0.0f)
#define glVertex2dv(v) GLVertex3f(__tglContext, ((v)[0]), (v)[1], 0.0f)
#define glVertex2sv(v) GLVertex3f(__tglContext, ((v)[0]), (v)[1], 0.0f)

#define glVertexPointer(size, type, stride, pointer) GLVertexPointer(__tglContext, size, type, stride, pointer)

#define glDepthRange(n,f) GLDepthRange(__tglContext, n,f)

#define glLockArraysEXT(f,c) GLLockArraysEXT(__tglContext, f, c)
#define glUnlockArraysEXT() GLUnlockArraysEXT(__tglContext)

#define glColor4f(red, green, blue, alpha) GLColor4f(__tglContext, red, green, blue, alpha)

#define glColor4fv(v)               GLColor4fv(__tglContext, v)
#define glColor4dv(v)               GLColor4dv(__tglContext, v)
#define glColor3f(red, green, blue) GLColor3f(__tglContext, red, green, blue)
#define glColor3fv(v)               GLColor3fv(__tglContext, v)
#define glColor3dv(v)               GLColor3dv(__tglContext, v)
#define glColor4ub(r, g, b, a)      GLColor4ub(__tglContext, r, g, b, a)
#define glColor4ubv(v)              GLColor4ubv(__tglContext, v)
#define glColor3ub(r, g, b)         GLColor3ub(__tglContext, r, g, b)
#define glColor3ubv(v)              GLColor3ubv(__tglContext, v)

#define glNormal3f(x,y,z) GLNormal3f(__tglContext, x, y, z)
#define glNormal3s(x,y,z) GLNormal3s(__tglContext, x, y, z)
#define glNormal3fv(a)    GLNormal3fv(__tglContext, a)
#define glNormal3dv(a)    GLNormal3dv(__tglContext, a)
#define glNormal3sv(a)    GLNormal3sv(__tglContext, a)

#define glTexEnvf(target, pname, param)  GLTexEnvf(__tglContext, target, pname, param)
#define glTexEnvi(target, pname, param)  GLTexEnvi(__tglContext, target, pname, (GLint)param)
#define glTexEnviv(target, pname, param) GLTexEnvi(__tglContext, target, pname, *(param))
#define glTexEnvfv(target, pname, param) GLTexEnvfv(__tglContext, target, pname, param)
#define glGetTexEnvfv(target, pname, param) GLGetTexEnvfv(__tglContext, target, pname, param)
#define glGetTexEnviv(target, pname, param) GLGetTexEnviv(__tglContext, target, pname, param)

#define glTexParameteri(target, pname, param) GLTexParameteri(__tglContext, target, pname, param)

#define glTexParameterf(target, pname, param) GLTexParameterf(__tglContext, target, pname, param)

#define glTexParameteriv(target, pname, param) GLTexParameteri(__tglContext, target, pname, *(param))

#define glTexParameterfv(target, pname, param) GLTexParameteri(__tglContext, target, pname, (GLint)*(param))
#define glGetTexParameterfv(target, pname, param) GLGetTexParameterfv(__tglContext, target, pname, param)
#define glGetTexParameteriv(target, pname, param) GLGetTexParameteriv(__tglContext, target, pname, param)

#define glTexCoordPointer(size, type, stride, pointer) GLTexCoordPointer(__tglContext, size, type, stride, pointer)

#define glNormalPointer(type, stride, pointer) GLNormalPointer(__tglContext, type, stride, pointer)

#define glColorPointer(size, type, stride, pointer) GLColorPointer(__tglContext, size, type, stride, pointer)

#define glVertexPointer(size, type, stride, pointer) GLVertexPointer(__tglContext, size, type, stride, pointer)

#define glDrawElements(mode, count, type, indices) GLDrawElements(__tglContext, mode, count, type, indices)
#define glDrawRangeElements(mode, start, end, count, type, indices) GLDrawRangeElements(__tglContext, mode, start, end, count, type, indices)

#define glDrawArrays(mode, first, count) GLDrawArrays(__tglContext, mode, first, count)

#define glMaterialfv(mode, type,v)  GLMaterialfv(__tglContext, mode, type, v)
#define glGetMaterialfv(mode, type,v)  GLGetMaterialfv(__tglContext, mode, type, v)
#define glMaterialf(mode,type,v)    GLMaterialf(__tglContext, mode, type, v)
#define glColorMaterial(mode, type)	GLColorMaterial(__tglContext, mode,type)

#define glLightfv(light, type, v)    GLLightfv(__tglContext, light, type, v)
#define glLightf(light, type, v)     GLLightf(__tglContext, light, type, v)
#define glLightModeli(pname, param)  GLLightModeli(__tglContext, pname, param)
#define glLightModelf(pname, param)  GLLightModelf(__tglContext, pname, param)
#define glLightModelfv(pname, param) GLLightModelfv(__tglContext, pname, param)


#define glGenLists(range)           GLGenLists(__tglContext, range)
#define	glDeleteLists(list, range)  GLDeleteLists(__tglContext, list, range)
#define glIsList(list)              GLIsList(__tglContext,  list)
#define glNewList(list, mode)       GLNewList(__tglContext, list, mode)
#define glEndList()                 GLEndList(__tglContext)
#define glCallList(list)            GLCallList(__tglContext, list)
#define	glListBase(base)            GLListBase(__tglContext, base)
#define	glCallLists(n, type, lists) GLCallLists(__tglContext, n, type, lists)

#define glRenderMode(mode)       GLRenderMode(__tglContext, mode)
#define glSelectBuffer(size,buf) GLSelectBuffer(__tglContext, size,buf)
#define glInitNames()            GLInitNames(__tglContext)
#define glPushName(name)         GLPushName(__tglContext, name)
#define glPopName()              GLPopName(__tglContext)
#define glLoadName(name)         GLLoadName(__tglContext, name)

int	InitTinyGL(void);
void	QuitTinyGL(void);

#define	glAInitializeContextWindowed(w) GLAInitializeContextWindowed(__tglContext, w)
#define	glADestroyContextWindowed()     GLADestroyContextWindowed(__tglContext)
#define	glAInitializeContextScreen(w)   GLAInitializeContextScreen(__tglContext, w)
#define	glADestroyContextScreen()       GLADestroyContextScreen(__tglContext)
#define	glAInitializeContextBitMap(w)   GLAInitializeContextBitMap(__tglContext, w)
#define	glADestroyContextBitMap()       GLADestroyContextBitMap(__tglContext)
#define	glASwapBuffers()                  GLASwapBuffers(__tglContext)

/* multitexture extensions */

#define glActiveTextureARB(unit)         GLActiveTextureARB(__tglContext, unit)
#define glMultiTexCoord2fARB(a, s, t)    GLMultiTexCoord2fARB(__tglContext, a, s, t)
#define glMultiTexCoord3fARB(a, s, t, r) GLMultiTexCoord3fARB(__tglContext, a, s, t, r)
#define glMultiTexCoord4fARB(a, s, t, r, q) GLMultiTexCoord4fARB(__tglContext, a, s, t, r, q)
#define glMultiTexCoord2fvARB(a, v)      GLMultiTexCoord2fvARB(__tglContext, a, v)
#define glMultiTexCoord3fvARB(a, v)      GLMultiTexCoord3fvARB(__tglContext, a, v)
#define glMultiTexCoord4fvARB(a, v)      GLMultiTexCoord4fvARB(__tglContext, a, v)
#define	glClientActiveTextureARB(u)      GLClientActiveTextureARB(__tglContext, u)

/* OpenGL 2 multitexture */

#define glActiveTexture(unit)         GLActiveTextureARB(__tglContext, unit)
#define glMultiTexCoord2f(a, s, t)    GLMultiTexCoord2fARB(__tglContext, a, s, t)
#define glMultiTexCoord3f(a, s, t, r) GLMultiTexCoord3fARB(__tglContext, a, s, t, r)
#define glMultiTexCoord4f(a, s, t, r, q) GLMultiTexCoord4fARB(__tglContext, a, s, t, r, q)
#define glMultiTexCoord2fv(a, v)      GLMultiTexCoord2fvARB(__tglContext, a, v)
#define glMultiTexCoord3fv(a, v)      GLMultiTexCoord3fvARB(__tglContext, a, v)
#define glMultiTexCoord4fv(a, v)      GLMultiTexCoord4fvARB(__tglContext, a, v)
#define	glClientActiveTexture(u)      GLClientActiveTextureARB(__tglContext, u)

/* point parameters extension */

#define	glPointSize(size)                    GLPointSize(__tglContext, size)
#define	glPointParameterfEXT(pname, param)   GLPointParameterf(__tglContext, pname, param)
#define	glPointParameterfvEXT(pname, params) GLPointParameterfvEXT(__tglContext, pname, params)

/* push/pop attrib */

#define	glPushAttrib(mask)       GLPushAttrib(__tglContext, mask)
#define	glPushClientAttrib(mask) GLPushClientAttrib(__tglContext, mask)
#define	glPopAttrib()            GLPopAttrib(__tglContext)
#define	glPopClientAttrib()      GLPopClientAttrib(__tglContext)

/* line width */

#define	glLineWidth(width) GLLineWidth(__tglContext, width)

/* rect */

#define	glRectf(x1,y1,x2,y2) GLRectf(__tglContext, x1,y1,x2,y2)
#define	glRectd(x1,y1,x2,y2) GLRectf(__tglContext, (GLfloat)(x1),(GLfloat)(y1),(GLfloat)(x2),(GLfloat)(y2))
#define	glRecti(x1,y1,x2,y2) GLRectf(__tglContext, (GLfloat)(x1),(GLfloat)(y1),(GLfloat)(x2),(GLfloat)(y2))
#define	glRectfv(v1, v2)     GLRectfv(__tglContext, v1, v2)
#define	glRectiv(v1, v2)     GLRectiv(__tglContext, v1, v2)
#define	glRectdv(v1, v2)     GLRectdv(__tglContext, v1, v2)

/* evaluators */

#define	glEvalPoint1(i)               GLEvalPoint1(__tglContext, i)
#define	glEvalPoint2(i,j)             GLEvalPoint2(__tglContext, i, j)
#define	glEvalCoord1f(u)              GLEvalCoord1f(__tglContext, u)
#define	glEvalCoord2f(u,v)            GLEvalCoord2f(__tglContext, u, v)
#define	glEvalCoord1fv(u)             GLEvalCoord1fv(__tglContext, u)
#define	glEvalCoord2fv(u)             GLEvalCoord2fv(__tglContext, u)
#define	glEvalMesh1(mode,p1,p2)       GLEvalMesh1(__tglContext, mode, p1, p2)
#define	glEvalMesh2(mode,p1,p2,q1,q2) GLEvalMesh2(__tglContext, mode, p1, p2, q1, q2)

#define	glMap1f(target, u1, u2, stride, order, points) GLMap1f(__tglContext, target, u1, u2, stride, order, points)
#define	glMap1d(target, u1, u2, stride, order, points) GLMap1d(__tglContext, target, u1, u2, stride, order, points)
#define	glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points) GLMap2f(__tglContext,  target,  u1,  u2,  ustride,  uorder,  v1,  v2,  vstride,  vorder,   points)
#define	glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points) GLMap2d(__tglContext,  target,  u1,  u2,  ustride,  uorder,  v1,  v2,  vstride,  vorder,   points)
#define	glGetMapdv(target, query, v)      GLGetMapdv(__tglContext, target, query, v)
#define	glGetMapfv(target, quary, v)      GLGetMapfv(__tglContext, target, query, v)
#define glGetMapiv(target, query, v)      GLGetMapiv(__tglContext, target, query, v)
#define	glMapGrid1f(un, u1, u2)           GLMapGrid1f(__tglContext, un, u1, u2)
#define	glMapGrid1d(un, u1, u2)           GLMapGrid1d(__tglContext, un, u1, u2)
#define	glMapGrid2f(un, u1, u2,vn,v1,v2)  GLMapGrid2f(__tglContext, un, u1, u2, vn, v1, v2)
#define	glMapGrid2d(un, u1, u2, vn,v1,v2) GLMapGrid2d(__tglContext, un, u1, u2, vn, v1, v2)

/* color_index textures */

#define	glColorTable(target, internalformat, width, format, type, data)  GLColorTable(__tglContext, target, internalformat, width, format, type, data)

/* raster functions */

#define	glRasterPos2f(x, y)    GLRasterPos2f(__tglContext, x, y)
#define	glRasterPos2fv(v)      GLRasterPos2fv(__tglContext, v)
#define	glRasterPos3fv(v)      GLRasterPos3fv(__tglContext, v)
#define	glRasterPos3f(x, y, z) GLRasterPos3f(__tglContext, x, y, z)
#define	glRasterPos3d(x, y, z) GLRasterPos3f(__tglContext, (GLdouble)x, (GLdouble)y, (GLdouble)z)
#define	glRasterPos2i(x, y)    GLRasterPos2f(__tglContext, (GLfloat)(x), (GLfloat)(y))
#define	glWindowPos2f(x, y)    GLWindowPos2f(__tglContext, x, y)
#define	glBitmap(width,height,xorig,yorig,xmove,ymove,bits) GLBitmap(__tglContext, width,height,xorig,yorig,xmove,ymove,bits)
#define	glDrawPixels(width, height, format, type, pixels) GLDrawPixels(__tglContext, width, height, format, type, pixels)

#define glPixelZoom(x, y)   GLPixelZoom(__tglContext, x, y)
#define glPixelTransferi(p,v) GLPixelTransferi(__tglContext, p, v)
#define glPixelTransferf(p,v) GLPixelTransferf(__tglContext, p, v)
/* stencil */

#define	glStencilFunc(func, ref, mask)     GLStencilFunc(__tglContext, func, ref, mask)
#define	glStencilOp(sfail, dpfail, dppass) GLStencilOp(__tglContext, sfail, dpfail, dppass)
#define	glStencilMask(mask)                GLStencilMask(__tglContext, mask)
#define	glClearStencil(s)                  GLClearStencil(__tglContext, s)

#define glColorMask(r, g, b, a) GLColorMask(__tglContext, r, g, b, a)

/* added by LouiSe */

#define glRenderMode(mode)        GLRenderMode(__tglContext, mode)
#define glRotated(angle, x, y, z) GLRotatef(__tglContext, angle, (GLdouble)x, (GLdouble)y, (GLdouble)z)
#define glTranslated(x, y, z)     GLTranslatef(__tglContext, (GLdouble)x, (GLdouble)y, (GLdouble)z)
#define glVertex3i(x,y,z)         GLVertex3f(__tglContext, (GLint)x, (GLint)y, (GLint)z)
#define glVertex3s(x,y,z)         GLVertex3f(__tglContext, (GLshort)x, (GLshort)y, (GLshort)z)
#define glVertex4d(x,y,z,w)       GLVertex4f(__tglContext, (GLdouble)x,(GLdouble)y,(GLdouble)z,(GLdouble)w)
#define glVertex4i(x,y,z,w)       GLVertex4f(__tglContext, (GLint)x, (GLint)y, (GLint)z, (GLint)w)
#define glVertex4s(x,y,z,w)       GLVertex4f(__tglContext, (GLshort)x, (GLshort)y, (GLshort)z, (GLshort)w)
#define glVertex2iv(v)            GLVertex3f(__tglContext, ((v)[0]), (v)[1], 0.0f)
#define glVertex3iv(v)            GLVertex3f(__tglContext, ((v)[0]), (v)[1], (v)[2])
#define glNormal3d(x,y,z)         GLNormal3f(__tglContext, (GLdouble)x,(GLdouble)y,(GLdouble)z)
#define glColor3d(red,green,blue) GLColor3f(__tglContext, (GLfloat)red, (GLfloat)green, (GLfloat)blue)
#define glTexCoord1d(s)           GLTexCoord2f(__tglContext, s, 0.0f)
#define glTexCoord1f(s)           GLTexCoord2f(__tglContext, s, 0.0f)
#define glTexCoord2d(s, t)        GLTexCoord2f(__tglContext, s, t)

#define	glRasterPos2d(x, y)                GLRasterPos2f(__tglContext, (GLdouble)(x), (GLdouble)(y))
#define	glRects(x1, y1, x2, y2)            GLRectf(__tglContext, (GLshort)(x1), (GLshort)(y1), (GLshort)(x2), (GLshort)(y2))
#define glLighti(light, type, v)           GLLightf(__tglContext,light,type,(GLint)v)
#define glMateriali(mode, type, v)         GLMaterialf(__tglContext, mode, type, (GLint)v)
#define glTexGend(coord, mode, map)        GLTexGeni(__tglContext, coord, mode, (GLenum)map)
#define glColor4d(red, green, blue, alpha) GLColor4f(__tglContext, red, green, blue, alpha)

#define	glIsTexture(texture) GLIsTexture(__tglContext, texture)

#define glClipPlane(plane, equ) GLClipPlane(__tglContext, plane, equ)
#define glGetClipPlane(plane, equ) GLGetClipPlane(__tglContext, plane, equ)

#define glLineStipple(factor, pattern) GLLineStipple(__tglContext, factor, pattern)

#define GL_BGR  0x80E0
#define GL_BGRA 0x80E1

/* shaders */

#define glAttachShader(program,	shader) GLAttachShader(__tglContext, program, shader)
#define glCompileShader(shader) GLCompileShader(__tglContext, shader)
#define glLinkProgram(program) GLLinkProgram(__tglContext, program)
#define glUseProgram(program) GLUseProgram(__tglContext, program)
#define glCreateShader(shaderType) GLCreateShader(__tglContext, shaderType)
#define glCreateProgram() GLCreateProgram(__tglContext)
#define glShaderSource(shader, count, string, length) GLShaderSource(__tglContext, shader, count, string, length)
#define glValidateProgram(program) GLValidateProgram(__tglContext, program)

#define glUniform1f(location, v) GLUniform1f(__tglContext, location, v)
#define glUniform2f(location, v1, v2) GLUniform2f(__tglContext, location, v1, v2)
#define glUniform3f(location, v1, v2, v3) GLUniform3f(__tglContext, location, v1, v2, v3)
#define glUniform4f(location, v1, v2, v3, v4) GLUniform4f(__tglContext, location, v1, v2, v3, v4)
#define glUniform1i(location, v) GLUniform1i(__tglContext, location, v)
#define glUniform2i(location, v1, v2) GLUniform2i(__tglContext, location, v1, v2)
#define glUniform3i(location, v1, v2, v3) GLUniform3i(__tglContext, location, v1, v2, v3)
#define glUniform4i(location, v1, v2, v3, v4) GLUniform4i(__tglContext, location, v1, v2, v3, v4)
#define glUniform1ui(location, v) GLUniform1ui(__tglContext, location, v)
#define glUniform2ui(location, v1, v2) GLUniform2ui(__tglContext, location, v1, v2)
#define glUniform3ui(location, v1, v2, v3) GLUniform3ui(__tglContext, location, v1, v2, v3)
#define glUniform4ui(location, v1, v2, v3, v4) GLUniform4ui(__tglContext, location, v1, v2, v3, v4)

#define glUniform1fv(location, count, value) GLUniform1fv(__tglContext, location, count, value)
#define glUniform1iv(location, count, value) GLUniform1iv(__tglContext, location, count, value)
#define glUniform1uiv(location, count, value) GLUniform1uiv(__tglContext, location, count, value)
#define glUniform2fv(location, count, value) GLUniform2fv(__tglContext, location, count, value)
#define glUniform2iv(location, count, value) GLUniform2iv(__tglContext, location, count, value)
#define glUniform2uiv(location, count, value) GLUniform2uiv(__tglContext, location, count, value)
#define glUniform3fv(location, count, value) GLUniform3fv(__tglContext, location, count, value)
#define glUniform3iv(location, count, value) GLUniform3iv(__tglContext, location, count, value)
#define glUniform3uiv(location, count, value) GLUniform3uiv(__tglContext, location, count, value)
#define glUniform4fv(location, count, value) GLUniform4fv(__tglContext, location, count, value)
#define glUniform4iv(location, count, value) GLUniform4iv(__tglContext, location, count, value)
#define glUniform4uiv(location, count, value) GLUniform4uiv(__tglContext, location, count, value)

#define glUniformMatrix2fv(location, count, transpose, v) GLUniformMatrix2fv(__tglContext, location, count, transpose, v)
#define glUniformMatrix2x3fv(location, count, transpose, v) GLUniformMatrix2x3fv(__tglContext, location, count, transpose, v)
#define glUniformMatrix2x4fv(location, count, transpose, v) GLUniformMatrix2x4fv(__tglContext, location, count, transpose, v)
#define glUniformMatrix3fv(location, count, transpose, v) GLUniformMatrix3fv(__tglContext, location, count, transpose, v)
#define glUniformMatrix3x2fv(location, count, transpose, v) GLUniformMatrix3x2fv(__tglContext, location, count, transpose, v)
#define glUniformMatrix3x4fv(location, count, transpose, v) GLUniformMatrix3x4fv(__tglContext, location, count, transpose, v)
#define glUniformMatrix4fv(location, count, transpose, v) GLUniformMatrix4fv(__tglContext, location, count, transpose, v)
#define glUniformMatrix4x2fv(location, count, transpose, v) GLUniformMatrix4x2fv(__tglContext, location, count, transpose, v)
#define glUniformMatrix4x3fv(location, count, transpose, v) GLUniformMatrix4x3fv(__tglContext, location, count, transpose, v)

#define glGetUniformLocation(program, name) GLGetUniformLocation(__tglContext, program, name)
#define glGetAttribLocation(program, name) GLGetAttribLocation(__tglContext, program, name)
#define glVertexAttribPointer(index, size, type, normalized, stride, pointer) GLVertexAttribPointer(__tglContext, index, size, type, normalized, stride, pointer)
#define glEnableVertexAttribArray(index) GLEnableVertexAttribArray(__tglContext, index)
#define glDisableVertexAttribArray(index) GLDisableVertexAttribArray(__tglContext, index)

#define glGenBuffers(num, out) GLGenBuffers(__tglContext, num, out)
#define glGenBuffersARB(num, out) GLGenBuffers(__tglContext, num, out)
#define	glBufferData(target, size, data, usage) GLBufferData(__tglContext, target, size, data, usage)
#define	glBufferDataARB(target, size, data, usage) GLBufferData(__tglContext, target, size, data, usage)
#define glBufferSubData(target, offset, size, data) GLBufferSubData(__tglContext, target, offset, size, data)
#define glBufferSubDataARB(target, offset, size, data) GLBufferSubData(__tglContext, target, offset, size, data)
#define glBindBuffer(target, buffer) GLBindBuffer(__tglContext, target, buffer)
#define glBindBufferARB(target, buffer) GLBindBuffer(__tglContext, target, buffer)
#define glDeleteBuffers(n, buffers) GLDeleteBuffers(__tglContext, n, buffers)
#define glDeleteBuffersARB(n, buffers) GLDeleteBuffers(__tglContext, n, buffers)
#define glGetBufferParameteriv(target, value, data) GLGetBufferParameteriv(__tglContext, target, value, data)
#define glGetBufferParameterivARB(target, value, data) GLGetBufferParameteriv(__tglContext, target, value, data)

#define glGetShaderiv(shader, pname, params) GLGetShaderiv(__tglContext, shader, pname, params)
#define glGetProgramiv(shader, pname, params) GLGetProgramiv(__tglContext, shader, pname, params)
#define glGetProgramInfoLog(program, maxlength, length, infolog) GLGetProgramInfoLog(__tglContext, program, maxlength, length, infolog)
#define glGetShaderInfoLog(shader, maxlength, length, infolog) GLGetShaderInfoLog(__tglContext, shader, maxlength, length, infolog)

/* */

#define	glReadPixels(x, y, width, height, format, type, data) GLReadPixels(__tglContext, x, y, width, height, format, type, data)
#define glCopyPixels(x, y, width, height, type) GLCopyPixels(__tglContext, x, y, width, height, type)

#define glReadBuffer(mode) GLReadBuffer(__tglContext, mode)

/* added by Yomgui for blender */

#define glPolygonStipple(x)
#define glLogicOp(x)
#define glColor4b(r, g, b, a) GLColor4ub(__tglContext, (GLubyte)r, (GLubyte)g, (GLubyte)b, (GLubyte)a)
#define glRasterPos2s(x, y)   GLRasterPos2f(__tglContext, (GLshort)(x), (GLshort)(y))

#define GL_COLOR_LOGIC_OP 0x0BF2

/* some dummy functions */

#define	glIndexi(a)
#define	glutSetColor(a, b, c, d)
#define glFinish()

#endif /* _NO_PPCINLINE */

#ifdef __cplusplus
}
#endif

#endif /* GL_H */

