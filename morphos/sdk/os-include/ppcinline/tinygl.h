/* Automatically generated header! Do not edit! */

#ifndef _PPCINLINE_TINYGL_H
#define _PPCINLINE_TINYGL_H

#ifndef __PPCINLINE_MACROS_H
#include <ppcinline/macros.h>
#endif /* !__PPCINLINE_MACROS_H */

#ifndef TINYGL_BASE_NAME
#define TINYGL_BASE_NAME TinyGLBase
#endif /* !TINYGL_BASE_NAME */

#define GLADestroyContext(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 1234))(__p0))

#define GLADestroyContextBitMap(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 1078))(__p0))

#define GLADestroyContextScreen(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 1066))(__p0))

#define GLADestroyContextWindowed(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 844))(__p0))

#define GLAInitializeContext(__p0, __p1) \
	(((int (*)(GLContext *, struct TagItem *))*(void**)((long)(TINYGL_BASE_NAME) - 1240))(__p0, __p1))

#define GLAInitializeContextBitMap(__p0, __p1) \
	(((int (*)(GLContext *, void *))*(void**)((long)(TINYGL_BASE_NAME) - 1072))(__p0, __p1))

#define GLAInitializeContextScreen(__p0, __p1) \
	(((int (*)(GLContext *, void *))*(void**)((long)(TINYGL_BASE_NAME) - 1060))(__p0, __p1))

#define GLAInitializeContextWindowed(__p0, __p1) \
	(((int (*)(GLContext *, void *))*(void**)((long)(TINYGL_BASE_NAME) - 838))(__p0, __p1))

#define GLAReinitializeContextWindowed(__p0, __p1) \
	(((int (*)(GLContext *, void *))*(void**)((long)(TINYGL_BASE_NAME) - 1186))(__p0, __p1))

#define GLASetAttr(__p0, __p1, __p2) \
	(((void (*)(GLContext *, unsigned int , unsigned int ))*(void**)((long)(TINYGL_BASE_NAME) - 1414))(__p0, __p1, __p2))

#define GLASetSync(__p0, __p1) \
	(((void (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 1132))(__p0, __p1))

#define GLASwapBuffers(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 850))(__p0))

#define GLActiveTextureARB(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 412))(__p0, __p1))

#define GLAlphaFunc(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLclampf ))*(void**)((long)(TINYGL_BASE_NAME) - 598))(__p0, __p1, __p2))

#define GLArrayElement(__p0, __p1) \
	(((void (*)(GLContext *, GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 520))(__p0, __p1))

#define GLAttachShader(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1432))(__p0, __p1, __p2))

#define GLBegin(__p0, __p1) \
	(((void (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 64))(__p0, __p1))

#define GLBindBuffer(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1558))(__p0, __p1, __p2))

#define GLBindTexture(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 364))(__p0, __p1, __p2))

#define GLBitmap(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLsizei , GLsizei , GLfloat , GLfloat , GLfloat , GLfloat , const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 1102))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLBlendColor(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLclampf , GLclampf , GLclampf , GLclampf ))*(void**)((long)(TINYGL_BASE_NAME) - 1696))(__p0, __p1, __p2, __p3, __p4))

#define GLBlendEquation(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1690))(__p0, __p1))

#define GLBlendEquationSeparate(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1702))(__p0, __p1, __p2))

#define GLBlendFunc(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 586))(__p0, __p1, __p2))

#define GLBlendFuncSeparate(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1708))(__p0, __p1, __p2, __p3, __p4))

#define GLBufferData(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLsizei , const GLvoid *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1564))(__p0, __p1, __p2, __p3, __p4))

#define GLBufferSubData(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLintptr , GLsizei , const GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 1570))(__p0, __p1, __p2, __p3, __p4))

#define GLCallList(__p0, __p1) \
	(((void (*)(GLContext *, unsigned int ))*(void**)((long)(TINYGL_BASE_NAME) - 286))(__p0, __p1))

#define GLCallLists(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLsizei , GLenum , GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 892))(__p0, __p1, __p2, __p3))

#define GLClear(__p0, __p1) \
	(((void (*)(GLContext *, GLbitfield ))*(void**)((long)(TINYGL_BASE_NAME) - 298))(__p0, __p1))

#define GLClearColor(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLclampf , GLclampf , GLclampf , GLclampf ))*(void**)((long)(TINYGL_BASE_NAME) - 304))(__p0, __p1, __p2, __p3, __p4))

#define GLClearDepth(__p0, __p1) \
	(((void (*)(GLContext *, GLclampf ))*(void**)((long)(TINYGL_BASE_NAME) - 310))(__p0, __p1))

#define GLClearStencil(__p0, __p1) \
	(((void (*)(GLContext *, GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 1228))(__p0, __p1))

#define GLClientActiveTextureARB(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 574))(__p0, __p1))

#define GLClipPlane(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1270))(__p0, __p1, __p2))

#define GLClose(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 646))(__p0))

#define GLColor3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1168))(__p0, __p1))

#define GLColor3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 100))(__p0, __p1, __p2, __p3))

#define GLColor3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 112))(__p0, __p1))

#define GLColor3ub(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLubyte , GLubyte , GLubyte ))*(void**)((long)(TINYGL_BASE_NAME) - 124))(__p0, __p1, __p2, __p3))

#define GLColor3ubv(__p0, __p1) \
	(((void (*)(GLContext *, const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 136))(__p0, __p1))

#define GLColor4dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1174))(__p0, __p1))

#define GLColor4f(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 106))(__p0, __p1, __p2, __p3, __p4))

#define GLColor4fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 118))(__p0, __p1))

#define GLColor4ub(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLubyte , GLubyte , GLubyte , GLubyte ))*(void**)((long)(TINYGL_BASE_NAME) - 130))(__p0, __p1, __p2, __p3, __p4))

#define GLColor4ubv(__p0, __p1) \
	(((void (*)(GLContext *, const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 142))(__p0, __p1))

#define GLColorMask(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLboolean , GLboolean , GLboolean , GLboolean ))*(void**)((long)(TINYGL_BASE_NAME) - 1282))(__p0, __p1, __p2, __p3, __p4))

#define GLColorMaterial(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 442))(__p0, __p1, __p2))

#define GLColorPointer(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLenum , GLsizei , const GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 532))(__p0, __p1, __p2, __p3, __p4))

#define GLColorTable(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint , GLenum , GLenum , GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 1084))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLCompileShader(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1438))(__p0, __p1))

#define GLCopyPixels(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLint , GLint , GLsizei , GLsizei , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1384))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLCopyTexImage2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLsizei , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 1402))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define GLCopyTexSubImage2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 1408))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define GLCreateProgram(__p0) \
	(((GLuint (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 1468))(__p0))

#define GLCreateShader(__p0, __p1) \
	(((GLuint (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1450))(__p0, __p1))

#define GLCullFace(__p0, __p1) \
	(((void (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 52))(__p0, __p1))

#define GLDeleteBuffers(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 1576))(__p0, __p1, __p2))

#define GLDeleteLists(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 292))(__p0, __p1, __p2))

#define GLDeleteTextures(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 358))(__p0, __p1, __p2))

#define GLDepthFunc(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 628))(__p0, __p1))

#define GLDepthMask(__p0, __p1) \
	(((void (*)(GLContext *, GLboolean ))*(void**)((long)(TINYGL_BASE_NAME) - 592))(__p0, __p1))

#define GLDepthRange(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLclampf , GLclampf ))*(void**)((long)(TINYGL_BASE_NAME) - 622))(__p0, __p1, __p2))

#define GLDisable(__p0, __p1) \
	(((void (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 34))(__p0, __p1))

#define GLDisableClientState(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 514))(__p0, __p1))

#define GLDisableVertexAttribArray(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1648))(__p0, __p1))

#define GLDrawArrays(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLint , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 568))(__p0, __p1, __p2, __p3))

#define GLDrawBuffer(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1354))(__p0, __p1))

#define GLDrawElements(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLsizei , GLenum , GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 562))(__p0, __p1, __p2, __p3, __p4))

#define GLDrawPixels(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLsizei , GLsizei , GLenum , GLenum , const GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 1300))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLDrawRangeElements(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLuint , GLuint , GLsizei , GLenum , GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 1396))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLEdgeFlag(__p0, __p1) \
	(((void (*)(GLContext *, GLboolean ))*(void**)((long)(TINYGL_BASE_NAME) - 184))(__p0, __p1))

#define GLEnable(__p0, __p1) \
	(((void (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 28))(__p0, __p1))

#define GLEnableClientState(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 508))(__p0, __p1))

#define GLEnableVertexAttribArray(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1642))(__p0, __p1))

#define GLEnd(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 70))(__p0))

#define GLEndList(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 280))(__p0))

#define GLEvalCoord1f(__p0, __p1) \
	(((void (*)(GLContext *, GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 952))(__p0, __p1))

#define GLEvalCoord1fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 964))(__p0, __p1))

#define GLEvalCoord2f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 958))(__p0, __p1, __p2))

#define GLEvalCoord2fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 970))(__p0, __p1))

#define GLEvalMesh1(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 976))(__p0, __p1, __p2, __p3))

#define GLEvalMesh2(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 982))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLEvalPoint1(__p0, __p1) \
	(((void (*)(GLContext *, GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 940))(__p0, __p1))

#define GLEvalPoint2(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 946))(__p0, __p1, __p2))

#define GLFlush(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 478))(__p0))

#define GLFogf(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1120))(__p0, __p1, __p2))

#define GLFogfv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1126))(__p0, __p1, __p2))

#define GLFrontFace(__p0, __p1) \
	(((void (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 502))(__p0, __p1))

#define GLFrustum(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 250))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLGenBuffers(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 1552))(__p0, __p1, __p2))

#define GLGenLists(__p0, __p1) \
	(((unsigned int (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 262))(__p0, __p1))

#define GLGenTextures(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 352))(__p0, __p1, __p2))

#define GLGetAttribLocation(__p0, __p1, __p2) \
	(((GLint (*)(GLContext *, GLuint , const GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 1630))(__p0, __p1, __p2))

#define GLGetBufferParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1582))(__p0, __p1, __p2, __p3))

#define GLGetClipPlane(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1492))(__p0, __p1, __p2))

#define GLGetDoublev(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , double *))*(void**)((long)(TINYGL_BASE_NAME) - 898))(__p0, __p1, __p2))

#define GLGetError(__p0) \
	(((GLenum (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 1258))(__p0))

#define GLGetFloatv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , float *))*(void**)((long)(TINYGL_BASE_NAME) - 496))(__p0, __p1, __p2))

#define GLGetIntegerv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , int *))*(void**)((long)(TINYGL_BASE_NAME) - 490))(__p0, __p1, __p2))

#define GLGetLightfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1246))(__p0, __p1, __p2, __p3))

#define GLGetMapdv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1012))(__p0, __p1, __p2, __p3))

#define GLGetMapfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1018))(__p0, __p1, __p2, __p3))

#define GLGetMapiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1024))(__p0, __p1, __p2, __p3))

#define GLGetMaterialfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, int , int , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1516))(__p0, __p1, __p2, __p3))

#define GLGetPointerv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , void **))*(void**)((long)(TINYGL_BASE_NAME) - 1522))(__p0, __p1, __p2))

#define GLGetProgramInfoLog(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLsizei , GLsizei *, GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 1684))(__p0, __p1, __p2, __p3, __p4))

#define GLGetProgramiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1672))(__p0, __p1, __p2, __p3))

#define GLGetShaderInfoLog(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLsizei , GLsizei *, GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 1678))(__p0, __p1, __p2, __p3, __p4))

#define GLGetShaderiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1666))(__p0, __p1, __p2, __p3))

#define GLGetString(__p0, __p1) \
	(((GLbyte *(*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 862))(__p0, __p1))

#define GLGetTexEnvfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1528))(__p0, __p1, __p2, __p3))

#define GLGetTexEnviv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1534))(__p0, __p1, __p2, __p3))

#define GLGetTexImage(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLenum , GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 1204))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLGetTexLevelParameteriv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1198))(__p0, __p1, __p2, __p3, __p4))

#define GLGetTexParameterfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, int , int , float *))*(void**)((long)(TINYGL_BASE_NAME) - 1540))(__p0, __p1, __p2, __p3))

#define GLGetTexParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, int , int , int *))*(void**)((long)(TINYGL_BASE_NAME) - 1546))(__p0, __p1, __p2, __p3))

#define GLGetUniformLocation(__p0, __p1, __p2) \
	(((GLint (*)(GLContext *, GLuint , const char *))*(void**)((long)(TINYGL_BASE_NAME) - 1624))(__p0, __p1, __p2))

#define GLHint(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 484))(__p0, __p1, __p2))

#define GLInit() \
	(((GLContext *(*)(void))*(void**)((long)(TINYGL_BASE_NAME) - 640))())

#define GLInitNames(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 328))(__p0))

#define GLIsEnabled(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 40))(__p0, __p1))

#define GLIsList(__p0, __p1) \
	(((int (*)(GLContext *, unsigned int ))*(void**)((long)(TINYGL_BASE_NAME) - 268))(__p0, __p1))

#define GLIsTexture(__p0, __p1) \
	(((int (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1192))(__p0, __p1))

#define GLLightModelf(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , float ))*(void**)((long)(TINYGL_BASE_NAME) - 472))(__p0, __p1, __p2))

#define GLLightModelfv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 466))(__p0, __p1, __p2))

#define GLLightModeli(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 460))(__p0, __p1, __p2))

#define GLLightf(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, int , int , float ))*(void**)((long)(TINYGL_BASE_NAME) - 454))(__p0, __p1, __p2, __p3))

#define GLLightfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, int , int , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 448))(__p0, __p1, __p2, __p3))

#define GLLineStipple(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLushort ))*(void**)((long)(TINYGL_BASE_NAME) - 1378))(__p0, __p1, __p2))

#define GLLineWidth(__p0, __p1) \
	(((void (*)(GLContext *, GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 910))(__p0, __p1))

#define GLLinkProgram(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1444))(__p0, __p1))

#define GLListBase(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 886))(__p0, __p1))

#define GLLoadIdentity(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 202))(__p0))

#define GLLoadMatrixd(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1138))(__p0, __p1))

#define GLLoadMatrixf(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 196))(__p0, __p1))

#define GLLoadName(__p0, __p1) \
	(((void (*)(GLContext *, unsigned int ))*(void**)((long)(TINYGL_BASE_NAME) - 346))(__p0, __p1))

#define GLLoadTransposeMatrixd(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1882))(__p0, __p1))

#define GLLoadTransposeMatrixf(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1876))(__p0, __p1))

#define GLLockArraysEXT(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 550))(__p0, __p1, __p2))

#define GLMap1d(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLdouble , GLdouble , GLint , GLint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 994))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLMap1f(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLfloat , GLfloat , GLint , GLint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 988))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLMap2d(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10) \
	(((void (*)(GLContext *, GLenum , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1006))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10))

#define GLMap2f(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10) \
	(((void (*)(GLContext *, GLenum , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1000))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10))

#define GLMapGrid1d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 1036))(__p0, __p1, __p2, __p3))

#define GLMapGrid1f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1030))(__p0, __p1, __p2, __p3))

#define GLMapGrid2d(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLint , GLdouble , GLdouble , GLint , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 1048))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLMapGrid2f(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLint , GLfloat , GLfloat , GLint , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1042))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLMaterialf(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, int , int , float ))*(void**)((long)(TINYGL_BASE_NAME) - 436))(__p0, __p1, __p2, __p3))

#define GLMaterialfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, int , int , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 430))(__p0, __p1, __p2, __p3))

#define GLMatrixMode(__p0, __p1) \
	(((void (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 190))(__p0, __p1))

#define GLMultMatrixd(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1054))(__p0, __p1))

#define GLMultMatrixf(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 208))(__p0, __p1))

#define GLMultTransposeMatrixd(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1894))(__p0, __p1))

#define GLMultTransposeMatrixf(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1888))(__p0, __p1))

#define GLMultiTexCoord2dvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1162))(__p0, __p1, __p2))

#define GLMultiTexCoord2fARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 172))(__p0, __p1, __p2, __p3))

#define GLMultiTexCoord2fvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 178))(__p0, __p1, __p2))

#define GLMultiTexCoord3fARB(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1288))(__p0, __p1, __p2, __p3, __p4))

#define GLMultiTexCoord3fvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1294))(__p0, __p1, __p2))

#define GLMultiTexCoord4fARB(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1420))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLMultiTexCoord4fvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1426))(__p0, __p1, __p2))

#define GLNewList(__p0, __p1, __p2) \
	(((void (*)(GLContext *, unsigned int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 274))(__p0, __p1, __p2))

#define GLNormal3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1360))(__p0, __p1))

#define GLNormal3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 148))(__p0, __p1, __p2, __p3))

#define GLNormal3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 154))(__p0, __p1))

#define GLNormal3s(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, const GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 1324))(__p0, __p1, __p2, __p3))

#define GLNormal3sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 1318))(__p0, __p1))

#define GLNormalPointer(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLsizei , const GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 538))(__p0, __p1, __p2, __p3))

#define GLOrtho(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, float , float , float , float , float , float ))*(void**)((long)(TINYGL_BASE_NAME) - 256))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLPixelStorei(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 406))(__p0, __p1, __p2))

#define GLPixelTransferf(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1336))(__p0, __p1, __p2))

#define GLPixelTransferi(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 1330))(__p0, __p1, __p2))

#define GLPixelZoom(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1342))(__p0, __p1, __p2))

#define GLPointParameterfEXT(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 610))(__p0, __p1, __p2))

#define GLPointParameterfvEXT(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 616))(__p0, __p1, __p2))

#define GLPointSize(__p0, __p1) \
	(((void (*)(GLContext *, GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 604))(__p0, __p1))

#define GLPolygonMode(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 58))(__p0, __p1, __p2))

#define GLPolygonOffset(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 580))(__p0, __p1, __p2))

#define GLPopAttrib(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 874))(__p0))

#define GLPopClientAttrib(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 1372))(__p0))

#define GLPopMatrix(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 220))(__p0))

#define GLPopName(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 340))(__p0))

#define GLPrioritizeTextures(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLsizei , const GLuint *, const GLclampf *))*(void**)((long)(TINYGL_BASE_NAME) - 1486))(__p0, __p1, __p2, __p3))

#define GLPushAttrib(__p0, __p1) \
	(((void (*)(GLContext *, GLbitfield ))*(void**)((long)(TINYGL_BASE_NAME) - 868))(__p0, __p1))

#define GLPushClientAttrib(__p0, __p1) \
	(((void (*)(GLContext *, GLbitfield ))*(void**)((long)(TINYGL_BASE_NAME) - 1366))(__p0, __p1))

#define GLPushMatrix(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 214))(__p0))

#define GLPushName(__p0, __p1) \
	(((void (*)(GLContext *, unsigned int ))*(void**)((long)(TINYGL_BASE_NAME) - 334))(__p0, __p1))

#define GLRasterPos2f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1090))(__p0, __p1, __p2))

#define GLRasterPos2fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1306))(__p0, __p1))

#define GLRasterPos3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1108))(__p0, __p1, __p2, __p3))

#define GLRasterPos3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1312))(__p0, __p1))

#define GLReadBuffer(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1252))(__p0, __p1))

#define GLReadPixels(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 1180))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLRectdv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLdouble *, GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 934))(__p0, __p1, __p2))

#define GLRectf(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 916))(__p0, __p1, __p2, __p3, __p4))

#define GLRectfv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat *, GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 922))(__p0, __p1, __p2))

#define GLRectiv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint *, GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 928))(__p0, __p1, __p2))

#define GLRenderMode(__p0, __p1) \
	(((int (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 316))(__p0, __p1))

#define GLRotatef(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 226))(__p0, __p1, __p2, __p3, __p4))

#define GLScalef(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 238))(__p0, __p1, __p2, __p3))

#define GLScissor(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLint , GLsizei , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 880))(__p0, __p1, __p2, __p3, __p4))

#define GLSelectBuffer(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , unsigned int *))*(void**)((long)(TINYGL_BASE_NAME) - 322))(__p0, __p1, __p2))

#define GLShadeModel(__p0, __p1) \
	(((void (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 46))(__p0, __p1))

#define GLShaderSource(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLsizei , const GLchar **, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1456))(__p0, __p1, __p2, __p3, __p4))

#define GLStencilFunc(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1210))(__p0, __p1, __p2, __p3))

#define GLStencilMask(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1222))(__p0, __p1))

#define GLStencilOp(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1216))(__p0, __p1, __p2, __p3))

#define GLTexCoord1dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1498))(__p0, __p1))

#define GLTexCoord2dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1156))(__p0, __p1))

#define GLTexCoord2f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 160))(__p0, __p1, __p2))

#define GLTexCoord2fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 166))(__p0, __p1))

#define GLTexCoord2iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1264))(__p0, __p1))

#define GLTexCoord3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1504))(__p0, __p1))

#define GLTexCoord3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1276))(__p0, __p1, __p2, __p3))

#define GLTexCoord4dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1510))(__p0, __p1))

#define GLTexCoordPointer(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLenum , GLsizei , const GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 544))(__p0, __p1, __p2, __p3, __p4))

#define GLTexEnvf(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 388))(__p0, __p1, __p2, __p3))

#define GLTexEnvfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1390))(__p0, __p1, __p2, __p3))

#define GLTexEnvi(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 382))(__p0, __p1, __p2, __p3))

#define GLTexGenfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 424))(__p0, __p1, __p2, __p3))

#define GLTexGeni(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 418))(__p0, __p1, __p2, __p3))

#define GLTexImage1D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 1474))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define GLTexImage2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 370))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define GLTexParameterf(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, int , int , float ))*(void**)((long)(TINYGL_BASE_NAME) - 400))(__p0, __p1, __p2, __p3))

#define GLTexParameteri(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, int , int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 394))(__p0, __p1, __p2, __p3))

#define GLTexSubImage1D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLsizei , GLenum , GLenum , GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 1480))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLTexSubImage2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 376))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define GLTranslatef(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 232))(__p0, __p1, __p2, __p3))

#define GLULookAt(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 658))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define GLUPerspective(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 652))(__p0, __p1, __p2, __p3, __p4))

#define GLUPickMatrix(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1348))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLUTCreateWindow(__p0, __p1) \
	(((int (*)(GLContext *, char *))*(void**)((long)(TINYGL_BASE_NAME) - 682))(__p0, __p1))

#define GLUTDestroyWindow(__p0, __p1) \
	(((void (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 706))(__p0, __p1))

#define GLUTDisplayFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(void)))*(void**)((long)(TINYGL_BASE_NAME) - 730))(__p0, __p1))

#define GLUTEntryFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(int state)))*(void**)((long)(TINYGL_BASE_NAME) - 772))(__p0, __p1))

#define GLUTFullScreen(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 688))(__p0))

#define GLUTGet(__p0, __p1) \
	(((int (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 802))(__p0, __p1))

#define GLUTGetModifiers(__p0) \
	(((int (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 826))(__p0))

#define GLUTGetWindow(__p0) \
	(((int (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 700))(__p0))

#define GLUTGetWindowHandle(__p0) \
	(((void *(*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 856))(__p0))

#define GLUTHideWindow(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 784))(__p0))

#define GLUTIdleFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(void)))*(void**)((long)(TINYGL_BASE_NAME) - 742))(__p0, __p1))

#define GLUTInit(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int *, char **))*(void**)((long)(TINYGL_BASE_NAME) - 664))(__p0, __p1, __p2))

#define GLUTInitDisplayMode(__p0, __p1) \
	(((void (*)(GLContext *, unsigned int ))*(void**)((long)(TINYGL_BASE_NAME) - 808))(__p0, __p1))

#define GLUTInitWindowPosition(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 670))(__p0, __p1, __p2))

#define GLUTInitWindowSize(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 676))(__p0, __p1, __p2))

#define GLUTKeyboardFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(unsigned char key, int x, int y)))*(void**)((long)(TINYGL_BASE_NAME) - 748))(__p0, __p1))

#define GLUTKeyboardUpFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(unsigned char key, int x, int y)))*(void**)((long)(TINYGL_BASE_NAME) - 754))(__p0, __p1))

#define GLUTMainLoop(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 718))(__p0))

#define GLUTMotionFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(int x, int y)))*(void**)((long)(TINYGL_BASE_NAME) - 766))(__p0, __p1))

#define GLUTMouseFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(int button, int state, int x, int y)))*(void**)((long)(TINYGL_BASE_NAME) - 760))(__p0, __p1))

#define GLUTPassiveMotionFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(int x, int y)))*(void**)((long)(TINYGL_BASE_NAME) - 832))(__p0, __p1))

#define GLUTPositionWindow(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 790))(__p0, __p1, __p2))

#define GLUTPostRedisplay(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 724))(__p0))

#define GLUTReshapeFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(int width, int height)))*(void**)((long)(TINYGL_BASE_NAME) - 736))(__p0, __p1))

#define GLUTReshapeWindow(__p0, __p1, __p2) \
	(((void (*)(GLContext *, int , int ))*(void**)((long)(TINYGL_BASE_NAME) - 796))(__p0, __p1, __p2))

#define GLUTSetWindow(__p0, __p1) \
	(((void (*)(GLContext *, int ))*(void**)((long)(TINYGL_BASE_NAME) - 694))(__p0, __p1))

#define GLUTShowWindow(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 778))(__p0))

#define GLUTSpecialFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(int key, int x, int y)))*(void**)((long)(TINYGL_BASE_NAME) - 814))(__p0, __p1))

#define GLUTSpecialUpFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(int key, int x, int y)))*(void**)((long)(TINYGL_BASE_NAME) - 904))(__p0, __p1))

#define GLUTSwapBuffers(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 712))(__p0))

#define GLUTTimerFunc(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, int , void (*)(int value), int ))*(void**)((long)(TINYGL_BASE_NAME) - 820))(__p0, __p1, __p2, __p3))

#define GLUTVisibilityFunc(__p0, __p1) \
	(((void (*)(GLContext *, void (*)(int state)))*(void**)((long)(TINYGL_BASE_NAME) - 1114))(__p0, __p1))

#define GLUniform1f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1588))(__p0, __p1, __p2))

#define GLUniform1fv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1738))(__p0, __p1, __p2, __p3))

#define GLUniform1i(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 1714))(__p0, __p1, __p2))

#define GLUniform1iv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1720))(__p0, __p1, __p2, __p3))

#define GLUniform1ui(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1726))(__p0, __p1, __p2))

#define GLUniform1uiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 1732))(__p0, __p1, __p2, __p3))

#define GLUniform2f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1594))(__p0, __p1, __p2, __p3))

#define GLUniform2fv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1768))(__p0, __p1, __p2, __p3))

#define GLUniform2i(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 1744))(__p0, __p1, __p2, __p3))

#define GLUniform2iv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1750))(__p0, __p1, __p2, __p3))

#define GLUniform2ui(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1756))(__p0, __p1, __p2, __p3))

#define GLUniform2uiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 1762))(__p0, __p1, __p2, __p3))

#define GLUniform3f(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1600))(__p0, __p1, __p2, __p3, __p4))

#define GLUniform3fv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1798))(__p0, __p1, __p2, __p3))

#define GLUniform3i(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 1774))(__p0, __p1, __p2, __p3, __p4))

#define GLUniform3iv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1780))(__p0, __p1, __p2, __p3))

#define GLUniform3ui(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1786))(__p0, __p1, __p2, __p3, __p4))

#define GLUniform3uiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 1792))(__p0, __p1, __p2, __p3))

#define GLUniform4f(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLint , GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1606))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLUniform4fv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1612))(__p0, __p1, __p2, __p3))

#define GLUniform4i(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLint , GLint , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 1804))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLUniform4iv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1810))(__p0, __p1, __p2, __p3))

#define GLUniform4ui(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLint , GLuint , GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1816))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLUniform4uiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 1822))(__p0, __p1, __p2, __p3))

#define GLUniformMatrix2fv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLsizei , GLboolean , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1828))(__p0, __p1, __p2, __p3, __p4))

#define GLUniformMatrix2x3fv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLsizei , GLboolean , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1834))(__p0, __p1, __p2, __p3, __p4))

#define GLUniformMatrix2x4fv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLsizei , GLboolean , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1840))(__p0, __p1, __p2, __p3, __p4))

#define GLUniformMatrix3fv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLsizei , GLboolean , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1846))(__p0, __p1, __p2, __p3, __p4))

#define GLUniformMatrix3x2fv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLsizei , GLboolean , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1852))(__p0, __p1, __p2, __p3, __p4))

#define GLUniformMatrix3x4fv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLsizei , GLboolean , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1858))(__p0, __p1, __p2, __p3, __p4))

#define GLUniformMatrix4fv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLsizei , GLboolean , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1618))(__p0, __p1, __p2, __p3, __p4))

#define GLUniformMatrix4x2fv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLsizei , GLboolean , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1864))(__p0, __p1, __p2, __p3, __p4))

#define GLUniformMatrix4x3fv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLsizei , GLboolean , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1870))(__p0, __p1, __p2, __p3, __p4))

#define GLUnlockArraysEXT(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 556))(__p0))

#define GLUseProgram(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1654))(__p0, __p1))

#define GLValidateProgram(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1462))(__p0, __p1))

#define GLVertex3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1144))(__p0, __p1))

#define GLVertex3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 76))(__p0, __p1, __p2, __p3))

#define GLVertex3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 88))(__p0, __p1))

#define GLVertex4dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1150))(__p0, __p1))

#define GLVertex4f(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 82))(__p0, __p1, __p2, __p3, __p4))

#define GLVertex4fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 94))(__p0, __p1))

#define GLVertexAttribPointer(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLuint , GLint , GLenum , GLboolean , GLsizei , const GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 1636))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLVertexPointer(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLenum , GLsizei , const GLvoid *))*(void**)((long)(TINYGL_BASE_NAME) - 526))(__p0, __p1, __p2, __p3, __p4))

#define GLViewport(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 244))(__p0, __p1, __p2, __p3, __p4))

#define GLWindowPos2f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1096))(__p0, __p1, __p2))

#define TGLGetContexts() \
	(((void *(*)(void))*(void**)((long)(TINYGL_BASE_NAME) - 634))())

#endif /* !_PPCINLINE_TINYGL_H */
