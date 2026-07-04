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

#define GLAccum(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1918))(__p0, __p1, __p2))

#define GLActiveStencilFaceEXT(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1924))(__p0, __p1))

#define GLActiveTexture(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 412))(__p0, __p1))

#define GLAlphaFragmentOp1ATI(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLuint , GLuint , GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4348))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLAlphaFragmentOp2ATI(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(GLContext *, GLenum , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4354))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define GLAlphaFragmentOp3ATI(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11, __p12) \
	(((void (*)(GLContext *, GLenum , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4360))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11, __p12))

#define GLAlphaFunc(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 598))(__p0, __p1, __p2))

#define GLAreTexturesResident(__p0, __p1, __p2, __p3) \
	(((GLboolean (*)(GLContext *, GLsizei , const GLuint *, GLboolean *))*(void**)((long)(TINYGL_BASE_NAME) - 1930))(__p0, __p1, __p2, __p3))

#define GLArrayElement(__p0, __p1) \
	(((void (*)(GLContext *, GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 520))(__p0, __p1))

#define GLAttachShader(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1432))(__p0, __p1, __p2))

#define GLBegin(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 64))(__p0, __p1))

#define GLBeginFragmentShaderATI(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 4366))(__p0))

#define GLBeginQuery(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1936))(__p0, __p1, __p2))

#define GLBindAttribLocation(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLuint , const GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 1942))(__p0, __p1, __p2, __p3))

#define GLBindBuffer(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1558))(__p0, __p1, __p2))

#define GLBindFragmentShaderATI(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4372))(__p0, __p1))

#define GLBindFramebuffer(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1948))(__p0, __p1, __p2))

#define GLBindFramebufferEXT(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4486))(__p0, __p1, __p2))

#define GLBindProgramARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1954))(__p0, __p1, __p2))

#define GLBindRenderbuffer(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1960))(__p0, __p1, __p2))

#define GLBindRenderbufferEXT(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4492))(__p0, __p1, __p2))

#define GLBindTexture(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 364))(__p0, __p1, __p2))

#define GLBitmap(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLsizei , GLsizei , GLfloat , GLfloat , GLfloat , GLfloat , const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 1102))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLBlendColor(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1696))(__p0, __p1, __p2, __p3, __p4))

#define GLBlendEquation(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1690))(__p0, __p1))

#define GLBlendEquationSeparate(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1702))(__p0, __p1, __p2))

#define GLBlendFunc(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 586))(__p0, __p1, __p2))

#define GLBlendFuncSeparate(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1708))(__p0, __p1, __p2, __p3, __p4))

#define GLBlitFramebuffer(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10) \
	(((void (*)(GLContext *, GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLint , GLbitfield , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1966))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10))

#define GLBufferData(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLsizeiptr , const void *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1564))(__p0, __p1, __p2, __p3, __p4))

#define GLBufferSubData(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLintptr , GLsizeiptr , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 1570))(__p0, __p1, __p2, __p3, __p4))

#define GLCallList(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 286))(__p0, __p1))

#define GLCallLists(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLsizei , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 892))(__p0, __p1, __p2, __p3))

#define GLCheckFramebufferStatus(__p0, __p1) \
	(((GLenum (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1972))(__p0, __p1))

#define GLClampColor(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 4444))(__p0, __p1, __p2))

#define GLClear(__p0, __p1) \
	(((void (*)(GLContext *, GLbitfield ))*(void**)((long)(TINYGL_BASE_NAME) - 298))(__p0, __p1))

#define GLClearAccum(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1978))(__p0, __p1, __p2, __p3, __p4))

#define GLClearColor(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 304))(__p0, __p1, __p2, __p3, __p4))

#define GLClearColorIiEXT(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 4450))(__p0, __p1, __p2, __p3, __p4))

#define GLClearColorIuiEXT(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4456))(__p0, __p1, __p2, __p3, __p4))

#define GLClearDepth(__p0, __p1) \
	(((void (*)(GLContext *, GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 310))(__p0, __p1))

#define GLClearIndex(__p0, __p1) \
	(((void (*)(GLContext *, GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1984))(__p0, __p1))

#define GLClearStencil(__p0, __p1) \
	(((void (*)(GLContext *, GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 1228))(__p0, __p1))

#define GLClientActiveTexture(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 574))(__p0, __p1))

#define GLClipPlane(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1270))(__p0, __p1, __p2))

#define GLClose(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 646))(__p0))

#define GLColor3b(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLbyte , GLbyte , GLbyte ))*(void**)((long)(TINYGL_BASE_NAME) - 1990))(__p0, __p1, __p2, __p3))

#define GLColor3bv(__p0, __p1) \
	(((void (*)(GLContext *, const GLbyte *))*(void**)((long)(TINYGL_BASE_NAME) - 1996))(__p0, __p1))

#define GLColor3d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 2002))(__p0, __p1, __p2, __p3))

#define GLColor3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1168))(__p0, __p1))

#define GLColor3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 100))(__p0, __p1, __p2, __p3))

#define GLColor3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 112))(__p0, __p1))

#define GLColor3i(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2008))(__p0, __p1, __p2, __p3))

#define GLColor3iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2014))(__p0, __p1))

#define GLColor3s(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 2020))(__p0, __p1, __p2, __p3))

#define GLColor3sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 2026))(__p0, __p1))

#define GLColor3ub(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLubyte , GLubyte , GLubyte ))*(void**)((long)(TINYGL_BASE_NAME) - 124))(__p0, __p1, __p2, __p3))

#define GLColor3ubv(__p0, __p1) \
	(((void (*)(GLContext *, const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 136))(__p0, __p1))

#define GLColor3ui(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2032))(__p0, __p1, __p2, __p3))

#define GLColor3uiv(__p0, __p1) \
	(((void (*)(GLContext *, const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2038))(__p0, __p1))

#define GLColor3us(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLushort , GLushort , GLushort ))*(void**)((long)(TINYGL_BASE_NAME) - 2044))(__p0, __p1, __p2, __p3))

#define GLColor3usv(__p0, __p1) \
	(((void (*)(GLContext *, const GLushort *))*(void**)((long)(TINYGL_BASE_NAME) - 2050))(__p0, __p1))

#define GLColor4b(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLbyte , GLbyte , GLbyte , GLbyte ))*(void**)((long)(TINYGL_BASE_NAME) - 2056))(__p0, __p1, __p2, __p3, __p4))

#define GLColor4bv(__p0, __p1) \
	(((void (*)(GLContext *, const GLbyte *))*(void**)((long)(TINYGL_BASE_NAME) - 2062))(__p0, __p1))

#define GLColor4d(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 2068))(__p0, __p1, __p2, __p3, __p4))

#define GLColor4dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1174))(__p0, __p1))

#define GLColor4f(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 106))(__p0, __p1, __p2, __p3, __p4))

#define GLColor4fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 118))(__p0, __p1))

#define GLColor4i(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2074))(__p0, __p1, __p2, __p3, __p4))

#define GLColor4iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2080))(__p0, __p1))

#define GLColor4s(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 2086))(__p0, __p1, __p2, __p3, __p4))

#define GLColor4sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 2092))(__p0, __p1))

#define GLColor4ub(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLubyte , GLubyte , GLubyte , GLubyte ))*(void**)((long)(TINYGL_BASE_NAME) - 130))(__p0, __p1, __p2, __p3, __p4))

#define GLColor4ubv(__p0, __p1) \
	(((void (*)(GLContext *, const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 142))(__p0, __p1))

#define GLColor4ui(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2098))(__p0, __p1, __p2, __p3, __p4))

#define GLColor4uiv(__p0, __p1) \
	(((void (*)(GLContext *, const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2104))(__p0, __p1))

#define GLColor4us(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLushort , GLushort , GLushort , GLushort ))*(void**)((long)(TINYGL_BASE_NAME) - 2110))(__p0, __p1, __p2, __p3, __p4))

#define GLColor4usv(__p0, __p1) \
	(((void (*)(GLContext *, const GLushort *))*(void**)((long)(TINYGL_BASE_NAME) - 2116))(__p0, __p1))

#define GLColorFragmentOp1ATI(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLenum , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4378))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLColorFragmentOp2ATI(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10) \
	(((void (*)(GLContext *, GLenum , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4384))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10))

#define GLColorFragmentOp3ATI(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11, __p12, __p13) \
	(((void (*)(GLContext *, GLenum , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4390))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11, __p12, __p13))

#define GLColorMask(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLboolean , GLboolean , GLboolean , GLboolean ))*(void**)((long)(TINYGL_BASE_NAME) - 1282))(__p0, __p1, __p2, __p3, __p4))

#define GLColorMaterial(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 442))(__p0, __p1, __p2))

#define GLColorPointer(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 532))(__p0, __p1, __p2, __p3, __p4))

#define GLColorSubTable(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLsizei , GLsizei , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2122))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLColorTable(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLenum , GLsizei , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 1084))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLColorTableParameterfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2128))(__p0, __p1, __p2, __p3))

#define GLColorTableParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2134))(__p0, __p1, __p2, __p3))

#define GLCompileShader(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1438))(__p0, __p1))

#define GLCompressedTexImage1D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLsizei , GLint , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2140))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLCompressedTexImage2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2146))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define GLCompressedTexImage3D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2152))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define GLCompressedTexSubImage1D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLsizei , GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2158))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLCompressedTexSubImage2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2164))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define GLCompressedTexSubImage3D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2170))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11))

#define GLConvolutionFilter1D(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLenum , GLsizei , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2176))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLConvolutionFilter2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2182))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLConvolutionParameterf(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 2188))(__p0, __p1, __p2, __p3))

#define GLConvolutionParameterfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2194))(__p0, __p1, __p2, __p3))

#define GLConvolutionParameteri(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2200))(__p0, __p1, __p2, __p3))

#define GLConvolutionParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2206))(__p0, __p1, __p2, __p3))

#define GLCopyColorSubTable(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLsizei , GLint , GLint , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 2212))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLCopyColorTable(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint , GLint , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 2218))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLCopyConvolutionFilter1D(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint , GLint , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 2224))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLCopyConvolutionFilter2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint , GLint , GLsizei , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 2230))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLCopyPixels(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLint , GLint , GLsizei , GLsizei , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1384))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLCopyTexImage1D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2236))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLCopyTexImage2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLint , GLint , GLsizei , GLsizei , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 1402))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define GLCopyTexSubImage1D(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLint , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 2242))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLCopyTexSubImage2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 1408))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define GLCopyTexSubImage3D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLint , GLint , GLint , GLsizei , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 2248))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define GLCreateProgram(__p0) \
	(((GLuint (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 1468))(__p0))

#define GLCreateShader(__p0, __p1) \
	(((GLuint (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1450))(__p0, __p1))

#define GLCullFace(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 52))(__p0, __p1))

#define GLCurrentPaletteMatrixARB(__p0, __p1) \
	(((void (*)(GLContext *, GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2254))(__p0, __p1))

#define GLDeleteBuffers(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 1576))(__p0, __p1, __p2))

#define GLDeleteFragmentShaderATI(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4396))(__p0, __p1))

#define GLDeleteFramebuffers(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2260))(__p0, __p1, __p2))

#define GLDeleteLists(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 292))(__p0, __p1, __p2))

#define GLDeleteObjectARB(__p0, __p1) \
	(((void (*)(GLContext *, GLhandleARB ))*(void**)((long)(TINYGL_BASE_NAME) - 2266))(__p0, __p1))

#define GLDeleteProgram(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2272))(__p0, __p1))

#define GLDeleteProgramsARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2278))(__p0, __p1, __p2))

#define GLDeleteQueries(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2284))(__p0, __p1, __p2))

#define GLDeleteRenderbuffers(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2290))(__p0, __p1, __p2))

#define GLDeleteShader(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2296))(__p0, __p1))

#define GLDeleteTextures(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 358))(__p0, __p1, __p2))

#define GLDepthFunc(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 628))(__p0, __p1))

#define GLDepthMask(__p0, __p1) \
	(((void (*)(GLContext *, GLboolean ))*(void**)((long)(TINYGL_BASE_NAME) - 592))(__p0, __p1))

#define GLDepthRange(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 622))(__p0, __p1, __p2))

#define GLDetachShader(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2302))(__p0, __p1, __p2))

#define GLDisable(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 34))(__p0, __p1))

#define GLDisableClientState(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 514))(__p0, __p1))

#define GLDisableVertexAttribArray(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1648))(__p0, __p1))

#define GLDrawArrays(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLint , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 568))(__p0, __p1, __p2, __p3))

#define GLDrawBuffer(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1354))(__p0, __p1))

#define GLDrawBuffers(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , const GLenum *))*(void**)((long)(TINYGL_BASE_NAME) - 2308))(__p0, __p1, __p2))

#define GLDrawElements(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLsizei , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 562))(__p0, __p1, __p2, __p3, __p4))

#define GLDrawPixels(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLsizei , GLsizei , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 1300))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLDrawRangeElements(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLuint , GLuint , GLsizei , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 1396))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLEdgeFlag(__p0, __p1) \
	(((void (*)(GLContext *, GLboolean ))*(void**)((long)(TINYGL_BASE_NAME) - 184))(__p0, __p1))

#define GLEdgeFlagPointer(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2314))(__p0, __p1, __p2))

#define GLEdgeFlagv(__p0, __p1) \
	(((void (*)(GLContext *, const GLboolean *))*(void**)((long)(TINYGL_BASE_NAME) - 2320))(__p0, __p1))

#define GLEnable(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 28))(__p0, __p1))

#define GLEnableClientState(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 508))(__p0, __p1))

#define GLEnableVertexAttribArray(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1642))(__p0, __p1))

#define GLEnd(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 70))(__p0))

#define GLEndFragmentShaderATI(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 4402))(__p0))

#define GLEndList(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 280))(__p0))

#define GLEndQuery(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 2326))(__p0, __p1))

#define GLEvalCoord1d(__p0, __p1) \
	(((void (*)(GLContext *, GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 2332))(__p0, __p1))

#define GLEvalCoord1dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 2338))(__p0, __p1))

#define GLEvalCoord1f(__p0, __p1) \
	(((void (*)(GLContext *, GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 952))(__p0, __p1))

#define GLEvalCoord1fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 964))(__p0, __p1))

#define GLEvalCoord2d(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 2344))(__p0, __p1, __p2))

#define GLEvalCoord2dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 2350))(__p0, __p1))

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

#define GLFeedbackBuffer(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLsizei , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2356))(__p0, __p1, __p2, __p3))

#define GLFinish(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 2362))(__p0))

#define GLFlush(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 478))(__p0))

#define GLFogCoordPointer(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2368))(__p0, __p1, __p2, __p3))

#define GLFogCoordd(__p0, __p1) \
	(((void (*)(GLContext *, GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 2374))(__p0, __p1))

#define GLFogCoorddv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 2380))(__p0, __p1))

#define GLFogCoordf(__p0, __p1) \
	(((void (*)(GLContext *, GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 2386))(__p0, __p1))

#define GLFogCoordfv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2392))(__p0, __p1))

#define GLFogf(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1120))(__p0, __p1, __p2))

#define GLFogfv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1126))(__p0, __p1, __p2))

#define GLFogi(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2398))(__p0, __p1, __p2))

#define GLFogiv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2404))(__p0, __p1, __p2))

#define GLFramebufferRenderbuffer(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2410))(__p0, __p1, __p2, __p3, __p4))

#define GLFramebufferTexture1D(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , GLuint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2416))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLFramebufferTexture2D(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , GLuint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2422))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLFramebufferTexture3D(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , GLuint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2428))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLFramebufferTextureLayer(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLenum , GLuint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2434))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLFrontFace(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 502))(__p0, __p1))

#define GLFrustum(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 250))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLGenBuffers(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 1552))(__p0, __p1, __p2))

#define GLGenFragmentShadersATI(__p0, __p1) \
	(((GLuint (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 4408))(__p0, __p1))

#define GLGenFramebuffers(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2440))(__p0, __p1, __p2))

#define GLGenLists(__p0, __p1) \
	(((GLuint (*)(GLContext *, GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 262))(__p0, __p1))

#define GLGenProgramsARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2446))(__p0, __p1, __p2))

#define GLGenQueries(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2452))(__p0, __p1, __p2))

#define GLGenRenderbuffers(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2458))(__p0, __p1, __p2))

#define GLGenTextures(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 352))(__p0, __p1, __p2))

#define GLGenerateMipmap(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 2464))(__p0, __p1))

#define GLGetActiveAttrib(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 2470))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLGetActiveUniform(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 2476))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLGetAttachedObjectsARB(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLhandleARB , GLsizei , GLsizei *, GLhandleARB *))*(void**)((long)(TINYGL_BASE_NAME) - 2482))(__p0, __p1, __p2, __p3, __p4))

#define GLGetAttachedShaders(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLsizei , GLsizei *, GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2488))(__p0, __p1, __p2, __p3, __p4))

#define GLGetAttribLocation(__p0, __p1, __p2) \
	(((GLint (*)(GLContext *, GLuint , const GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 1630))(__p0, __p1, __p2))

#define GLGetBooleanv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLboolean *))*(void**)((long)(TINYGL_BASE_NAME) - 2494))(__p0, __p1, __p2))

#define GLGetBufferParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1582))(__p0, __p1, __p2, __p3))

#define GLGetBufferPointerv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , void **))*(void**)((long)(TINYGL_BASE_NAME) - 2500))(__p0, __p1, __p2, __p3))

#define GLGetBufferSubData(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLintptr , GLsizeiptr , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2506))(__p0, __p1, __p2, __p3, __p4))

#define GLGetClipPlane(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1492))(__p0, __p1, __p2))

#define GLGetColorTable(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2512))(__p0, __p1, __p2, __p3, __p4))

#define GLGetColorTableParameterfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2518))(__p0, __p1, __p2, __p3))

#define GLGetColorTableParameterfvSGI(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2524))(__p0, __p1, __p2, __p3))

#define GLGetColorTableParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2530))(__p0, __p1, __p2, __p3))

#define GLGetColorTableParameterivSGI(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2536))(__p0, __p1, __p2, __p3))

#define GLGetColorTableSGI(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2542))(__p0, __p1, __p2, __p3, __p4))

#define GLGetCompressedTexImage(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLint , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2548))(__p0, __p1, __p2, __p3))

#define GLGetConvolutionFilter(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2554))(__p0, __p1, __p2, __p3, __p4))

#define GLGetConvolutionFilterEXT(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2560))(__p0, __p1, __p2, __p3, __p4))

#define GLGetConvolutionParameterfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2566))(__p0, __p1, __p2, __p3))

#define GLGetConvolutionParameterfvEXT(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2572))(__p0, __p1, __p2, __p3))

#define GLGetConvolutionParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2578))(__p0, __p1, __p2, __p3))

#define GLGetConvolutionParameterivEXT(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2584))(__p0, __p1, __p2, __p3))

#define GLGetDoublev(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 898))(__p0, __p1, __p2))

#define GLGetError(__p0) \
	(((GLenum (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 1258))(__p0))

#define GLGetFloatv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 496))(__p0, __p1, __p2))

#define GLGetFramebufferAttachmentParameteriv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2590))(__p0, __p1, __p2, __p3, __p4))

#define GLGetHandleARB(__p0, __p1) \
	(((GLhandleARB (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 2596))(__p0, __p1))

#define GLGetHistogram(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLboolean , GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2602))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLGetHistogramEXT(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLboolean , GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2608))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLGetHistogramParameterfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2614))(__p0, __p1, __p2, __p3))

#define GLGetHistogramParameterfvEXT(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2620))(__p0, __p1, __p2, __p3))

#define GLGetHistogramParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2626))(__p0, __p1, __p2, __p3))

#define GLGetHistogramParameterivEXT(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2632))(__p0, __p1, __p2, __p3))

#define GLGetInfoLogARB(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLhandleARB , GLsizei , GLsizei *, GLcharARB *))*(void**)((long)(TINYGL_BASE_NAME) - 2638))(__p0, __p1, __p2, __p3, __p4))

#define GLGetIntegerv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 490))(__p0, __p1, __p2))

#define GLGetLightfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1246))(__p0, __p1, __p2, __p3))

#define GLGetLightiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2644))(__p0, __p1, __p2, __p3))

#define GLGetMapdv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1012))(__p0, __p1, __p2, __p3))

#define GLGetMapfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1018))(__p0, __p1, __p2, __p3))

#define GLGetMapiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1024))(__p0, __p1, __p2, __p3))

#define GLGetMaterialfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1516))(__p0, __p1, __p2, __p3))

#define GLGetMaterialiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2650))(__p0, __p1, __p2, __p3))

#define GLGetMinmax(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLboolean , GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2656))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLGetMinmaxEXT(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLboolean , GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2662))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLGetMinmaxParameterfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2668))(__p0, __p1, __p2, __p3))

#define GLGetMinmaxParameterfvEXT(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2674))(__p0, __p1, __p2, __p3))

#define GLGetMinmaxParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2680))(__p0, __p1, __p2, __p3))

#define GLGetMinmaxParameterivEXT(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2686))(__p0, __p1, __p2, __p3))

#define GLGetObjectParameterfvARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLhandleARB , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2692))(__p0, __p1, __p2, __p3))

#define GLGetObjectParameterivARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLhandleARB , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2698))(__p0, __p1, __p2, __p3))

#define GLGetPixelMapfv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2704))(__p0, __p1, __p2))

#define GLGetPixelMapuiv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2710))(__p0, __p1, __p2))

#define GLGetPixelMapusv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLushort *))*(void**)((long)(TINYGL_BASE_NAME) - 2716))(__p0, __p1, __p2))

#define GLGetPointerv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , void **))*(void**)((long)(TINYGL_BASE_NAME) - 1522))(__p0, __p1, __p2))

#define GLGetPolygonStipple(__p0, __p1) \
	(((void (*)(GLContext *, GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 2722))(__p0, __p1))

#define GLGetProgramEnvParameterdvARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLuint , GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 2728))(__p0, __p1, __p2, __p3))

#define GLGetProgramEnvParameterfvARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLuint , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2734))(__p0, __p1, __p2, __p3))

#define GLGetProgramInfoLog(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLsizei , GLsizei *, GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 1684))(__p0, __p1, __p2, __p3, __p4))

#define GLGetProgramLocalParameterdvARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLuint , GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 2740))(__p0, __p1, __p2, __p3))

#define GLGetProgramLocalParameterfvARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLuint , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2746))(__p0, __p1, __p2, __p3))

#define GLGetProgramStringARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 2752))(__p0, __p1, __p2, __p3))

#define GLGetProgramiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1672))(__p0, __p1, __p2, __p3))

#define GLGetProgramivARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2758))(__p0, __p1, __p2, __p3))

#define GLGetQueryObjectiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2764))(__p0, __p1, __p2, __p3))

#define GLGetQueryObjectuiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLenum , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 2770))(__p0, __p1, __p2, __p3))

#define GLGetQueryiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2776))(__p0, __p1, __p2, __p3))

#define GLGetRenderbufferParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2782))(__p0, __p1, __p2, __p3))

#define GLGetSeparableFilter(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , void *, void *, void *))*(void**)((long)(TINYGL_BASE_NAME) - 2788))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLGetSeparableFilterEXT(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , void *, void *, void *))*(void**)((long)(TINYGL_BASE_NAME) - 2794))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLGetShaderInfoLog(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLsizei , GLsizei *, GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 1678))(__p0, __p1, __p2, __p3, __p4))

#define GLGetShaderSource(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLsizei , GLsizei *, GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 2800))(__p0, __p1, __p2, __p3, __p4))

#define GLGetShaderiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1666))(__p0, __p1, __p2, __p3))

#define GLGetString(__p0, __p1) \
	(((const GLubyte *(*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 862))(__p0, __p1))

#define GLGetTexEnvfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1528))(__p0, __p1, __p2, __p3))

#define GLGetTexEnviv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1534))(__p0, __p1, __p2, __p3))

#define GLGetTexGendv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 2806))(__p0, __p1, __p2, __p3))

#define GLGetTexGenfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2812))(__p0, __p1, __p2, __p3))

#define GLGetTexGeniv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2818))(__p0, __p1, __p2, __p3))

#define GLGetTexImage(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 1204))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLGetTexLevelParameterfv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2824))(__p0, __p1, __p2, __p3, __p4))

#define GLGetTexLevelParameteriv(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLint , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1198))(__p0, __p1, __p2, __p3, __p4))

#define GLGetTexParameterIiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 4462))(__p0, __p1, __p2, __p3))

#define GLGetTexParameterIuiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 4468))(__p0, __p1, __p2, __p3))

#define GLGetTexParameterfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1540))(__p0, __p1, __p2, __p3))

#define GLGetTexParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1546))(__p0, __p1, __p2, __p3))

#define GLGetUniformLocation(__p0, __p1, __p2) \
	(((GLint (*)(GLContext *, GLuint , const GLchar *))*(void**)((long)(TINYGL_BASE_NAME) - 1624))(__p0, __p1, __p2))

#define GLGetUniformfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLint , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2830))(__p0, __p1, __p2, __p3))

#define GLGetUniformiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLint , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2836))(__p0, __p1, __p2, __p3))

#define GLGetVertexAttribPointerv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLenum , void **))*(void**)((long)(TINYGL_BASE_NAME) - 2842))(__p0, __p1, __p2, __p3))

#define GLGetVertexAttribdv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLenum , GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 2848))(__p0, __p1, __p2, __p3))

#define GLGetVertexAttribfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLenum , GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2854))(__p0, __p1, __p2, __p3))

#define GLGetVertexAttribiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLenum , GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2860))(__p0, __p1, __p2, __p3))

#define GLHint(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 484))(__p0, __p1, __p2))

#define GLHistogram(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLsizei , GLenum , GLboolean ))*(void**)((long)(TINYGL_BASE_NAME) - 2866))(__p0, __p1, __p2, __p3, __p4))

#define GLIndexMask(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2872))(__p0, __p1))

#define GLIndexPointer(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2878))(__p0, __p1, __p2, __p3))

#define GLIndexd(__p0, __p1) \
	(((void (*)(GLContext *, GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 2884))(__p0, __p1))

#define GLIndexdv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 2890))(__p0, __p1))

#define GLIndexf(__p0, __p1) \
	(((void (*)(GLContext *, GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 2896))(__p0, __p1))

#define GLIndexfv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 2902))(__p0, __p1))

#define GLIndexi(__p0, __p1) \
	(((void (*)(GLContext *, GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2908))(__p0, __p1))

#define GLIndexiv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2914))(__p0, __p1))

#define GLIndexs(__p0, __p1) \
	(((void (*)(GLContext *, GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 2920))(__p0, __p1))

#define GLIndexsv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 2926))(__p0, __p1))

#define GLIndexub(__p0, __p1) \
	(((void (*)(GLContext *, GLubyte ))*(void**)((long)(TINYGL_BASE_NAME) - 2932))(__p0, __p1))

#define GLIndexubv(__p0, __p1) \
	(((void (*)(GLContext *, const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 2938))(__p0, __p1))

#define GLInit() \
	(((GLContext *(*)(void))*(void**)((long)(TINYGL_BASE_NAME) - 640))())

#define GLInitNames(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 328))(__p0))

#define GLInterleavedArrays(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 2944))(__p0, __p1, __p2, __p3))

#define GLIsBuffer(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2950))(__p0, __p1))

#define GLIsEnabled(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 40))(__p0, __p1))

#define GLIsFramebuffer(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2956))(__p0, __p1))

#define GLIsList(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 268))(__p0, __p1))

#define GLIsProgram(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2962))(__p0, __p1))

#define GLIsProgramARB(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2968))(__p0, __p1))

#define GLIsQuery(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2974))(__p0, __p1))

#define GLIsRenderbuffer(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2980))(__p0, __p1))

#define GLIsShader(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 2986))(__p0, __p1))

#define GLIsTexture(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1192))(__p0, __p1))

#define GLLightModelf(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 472))(__p0, __p1, __p2))

#define GLLightModelfv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 466))(__p0, __p1, __p2))

#define GLLightModeli(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 460))(__p0, __p1, __p2))

#define GLLightModeliv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 2992))(__p0, __p1, __p2))

#define GLLightf(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 454))(__p0, __p1, __p2, __p3))

#define GLLightfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 448))(__p0, __p1, __p2, __p3))

#define GLLighti(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 2998))(__p0, __p1, __p2, __p3))

#define GLLightiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3004))(__p0, __p1, __p2, __p3))

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
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 346))(__p0, __p1))

#define GLLoadTransposeMatrixd(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1882))(__p0, __p1))

#define GLLoadTransposeMatrixf(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1876))(__p0, __p1))

#define GLLockArraysEXT(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 550))(__p0, __p1, __p2))

#define GLLogicOp(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 3010))(__p0, __p1))

#define GLMap1d(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLdouble , GLdouble , GLint , GLint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 994))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLMap1f(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLfloat , GLfloat , GLint , GLint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 988))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLMap2d(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10) \
	(((void (*)(GLContext *, GLenum , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1006))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10))

#define GLMap2f(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10) \
	(((void (*)(GLContext *, GLenum , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1000))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10))

#define GLMapBuffer(__p0, __p1, __p2) \
	(((void *(*)(GLContext *, GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 3016))(__p0, __p1, __p2))

#define GLMapGrid1d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 1036))(__p0, __p1, __p2, __p3))

#define GLMapGrid1f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1030))(__p0, __p1, __p2, __p3))

#define GLMapGrid2d(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLint , GLdouble , GLdouble , GLint , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 1048))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLMapGrid2f(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLint , GLfloat , GLfloat , GLint , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1042))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLMaterialf(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 436))(__p0, __p1, __p2, __p3))

#define GLMaterialfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 430))(__p0, __p1, __p2, __p3))

#define GLMateriali(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3022))(__p0, __p1, __p2, __p3))

#define GLMaterialiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3028))(__p0, __p1, __p2, __p3))

#define GLMatrixIndexPointerARB(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 3034))(__p0, __p1, __p2, __p3, __p4))

#define GLMatrixIndexubvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 3040))(__p0, __p1, __p2))

#define GLMatrixIndexuivARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 3046))(__p0, __p1, __p2))

#define GLMatrixIndexusvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLushort *))*(void**)((long)(TINYGL_BASE_NAME) - 3052))(__p0, __p1, __p2))

#define GLMatrixMode(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 190))(__p0, __p1))

#define GLMinmax(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLboolean ))*(void**)((long)(TINYGL_BASE_NAME) - 3058))(__p0, __p1, __p2, __p3))

#define GLMultMatrixd(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1054))(__p0, __p1))

#define GLMultMatrixf(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 208))(__p0, __p1))

#define GLMultTransposeMatrixd(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1894))(__p0, __p1))

#define GLMultTransposeMatrixf(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1888))(__p0, __p1))

#define GLMultiDrawArrays(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , const GLint *, const GLsizei *, GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 3064))(__p0, __p1, __p2, __p3, __p4))

#define GLMultiDrawElements(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , const GLsizei *, GLenum , const void *const *, GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 3070))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLMultiTexCoord1d(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3076))(__p0, __p1, __p2))

#define GLMultiTexCoord1dv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3082))(__p0, __p1, __p2))

#define GLMultiTexCoord1f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3088))(__p0, __p1, __p2))

#define GLMultiTexCoord1fv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 3094))(__p0, __p1, __p2))

#define GLMultiTexCoord1i(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3100))(__p0, __p1, __p2))

#define GLMultiTexCoord1iv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3106))(__p0, __p1, __p2))

#define GLMultiTexCoord1s(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3112))(__p0, __p1, __p2))

#define GLMultiTexCoord1sv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3118))(__p0, __p1, __p2))

#define GLMultiTexCoord2d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3124))(__p0, __p1, __p2, __p3))

#define GLMultiTexCoord2dv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1162))(__p0, __p1, __p2))

#define GLMultiTexCoord2f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 172))(__p0, __p1, __p2, __p3))

#define GLMultiTexCoord2fv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 178))(__p0, __p1, __p2))

#define GLMultiTexCoord2i(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3130))(__p0, __p1, __p2, __p3))

#define GLMultiTexCoord2iv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3136))(__p0, __p1, __p2))

#define GLMultiTexCoord2s(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3142))(__p0, __p1, __p2, __p3))

#define GLMultiTexCoord2sv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3148))(__p0, __p1, __p2))

#define GLMultiTexCoord3d(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3154))(__p0, __p1, __p2, __p3, __p4))

#define GLMultiTexCoord3dv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3160))(__p0, __p1, __p2))

#define GLMultiTexCoord3f(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1288))(__p0, __p1, __p2, __p3, __p4))

#define GLMultiTexCoord3fv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1294))(__p0, __p1, __p2))

#define GLMultiTexCoord3i(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3166))(__p0, __p1, __p2, __p3, __p4))

#define GLMultiTexCoord3iv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3172))(__p0, __p1, __p2))

#define GLMultiTexCoord3s(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3178))(__p0, __p1, __p2, __p3, __p4))

#define GLMultiTexCoord3sv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3184))(__p0, __p1, __p2))

#define GLMultiTexCoord4d(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3190))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLMultiTexCoord4dv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3196))(__p0, __p1, __p2))

#define GLMultiTexCoord4f(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1420))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLMultiTexCoord4fv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1426))(__p0, __p1, __p2))

#define GLMultiTexCoord4i(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3202))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLMultiTexCoord4iv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3208))(__p0, __p1, __p2))

#define GLMultiTexCoord4s(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLshort , GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3214))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLMultiTexCoord4sv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3220))(__p0, __p1, __p2))

#define GLNewList(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 274))(__p0, __p1, __p2))

#define GLNormal3b(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLbyte , GLbyte , GLbyte ))*(void**)((long)(TINYGL_BASE_NAME) - 3226))(__p0, __p1, __p2, __p3))

#define GLNormal3bv(__p0, __p1) \
	(((void (*)(GLContext *, const GLbyte *))*(void**)((long)(TINYGL_BASE_NAME) - 3232))(__p0, __p1))

#define GLNormal3d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3238))(__p0, __p1, __p2, __p3))

#define GLNormal3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1360))(__p0, __p1))

#define GLNormal3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 148))(__p0, __p1, __p2, __p3))

#define GLNormal3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 154))(__p0, __p1))

#define GLNormal3i(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3244))(__p0, __p1, __p2, __p3))

#define GLNormal3iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3250))(__p0, __p1))

#define GLNormal3s(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 1324))(__p0, __p1, __p2, __p3))

#define GLNormal3sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 1318))(__p0, __p1))

#define GLNormalPointer(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 538))(__p0, __p1, __p2, __p3))

#define GLOrtho(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 256))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLPassTexCoordATI(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLuint , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 4414))(__p0, __p1, __p2, __p3))

#define GLPassThrough(__p0, __p1) \
	(((void (*)(GLContext *, GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3256))(__p0, __p1))

#define GLPixelMapfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLsizei , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 3262))(__p0, __p1, __p2, __p3))

#define GLPixelMapuiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLsizei , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 3268))(__p0, __p1, __p2, __p3))

#define GLPixelMapusv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLsizei , const GLushort *))*(void**)((long)(TINYGL_BASE_NAME) - 3274))(__p0, __p1, __p2, __p3))

#define GLPixelStoref(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3280))(__p0, __p1, __p2))

#define GLPixelStorei(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 406))(__p0, __p1, __p2))

#define GLPixelTransferf(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1336))(__p0, __p1, __p2))

#define GLPixelTransferi(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 1330))(__p0, __p1, __p2))

#define GLPixelZoom(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1342))(__p0, __p1, __p2))

#define GLPointParameterf(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 610))(__p0, __p1, __p2))

#define GLPointParameterfv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 616))(__p0, __p1, __p2))

#define GLPointParameteri(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3286))(__p0, __p1, __p2))

#define GLPointParameteriv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3292))(__p0, __p1, __p2))

#define GLPointSize(__p0, __p1) \
	(((void (*)(GLContext *, GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 604))(__p0, __p1))

#define GLPolygonMode(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 58))(__p0, __p1, __p2))

#define GLPolygonOffset(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 580))(__p0, __p1, __p2))

#define GLPolygonStipple(__p0, __p1) \
	(((void (*)(GLContext *, const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 3298))(__p0, __p1))

#define GLPopAttrib(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 874))(__p0))

#define GLPopClientAttrib(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 1372))(__p0))

#define GLPopMatrix(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 220))(__p0))

#define GLPopName(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 340))(__p0))

#define GLPrioritizeTextures(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLsizei , const GLuint *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1486))(__p0, __p1, __p2, __p3))

#define GLProgramEnvParameter4dARB(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLuint , GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3304))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLProgramEnvParameter4dvARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLuint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3310))(__p0, __p1, __p2, __p3))

#define GLProgramEnvParameter4fARB(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLuint , GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3316))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLProgramEnvParameter4fvARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLuint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 3322))(__p0, __p1, __p2, __p3))

#define GLProgramLocalParameter4dARB(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLuint , GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3328))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLProgramLocalParameter4dvARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLuint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3334))(__p0, __p1, __p2, __p3))

#define GLProgramLocalParameter4fARB(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLenum , GLuint , GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3340))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLProgramLocalParameter4fvARB(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLuint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 3346))(__p0, __p1, __p2, __p3))

#define GLProgramStringARB(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 3352))(__p0, __p1, __p2, __p3, __p4))

#define GLPushAttrib(__p0, __p1) \
	(((void (*)(GLContext *, GLbitfield ))*(void**)((long)(TINYGL_BASE_NAME) - 868))(__p0, __p1))

#define GLPushClientAttrib(__p0, __p1) \
	(((void (*)(GLContext *, GLbitfield ))*(void**)((long)(TINYGL_BASE_NAME) - 1366))(__p0, __p1))

#define GLPushMatrix(__p0) \
	(((void (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 214))(__p0))

#define GLPushName(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 334))(__p0, __p1))

#define GLRasterPos2d(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3358))(__p0, __p1, __p2))

#define GLRasterPos2dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3364))(__p0, __p1))

#define GLRasterPos2f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1090))(__p0, __p1, __p2))

#define GLRasterPos2fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1306))(__p0, __p1))

#define GLRasterPos2i(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3370))(__p0, __p1, __p2))

#define GLRasterPos2iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3376))(__p0, __p1))

#define GLRasterPos2s(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3382))(__p0, __p1, __p2))

#define GLRasterPos2sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3388))(__p0, __p1))

#define GLRasterPos3d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3394))(__p0, __p1, __p2, __p3))

#define GLRasterPos3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3400))(__p0, __p1))

#define GLRasterPos3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1108))(__p0, __p1, __p2, __p3))

#define GLRasterPos3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1312))(__p0, __p1))

#define GLRasterPos3i(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3406))(__p0, __p1, __p2, __p3))

#define GLRasterPos3iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3412))(__p0, __p1))

#define GLRasterPos3s(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3418))(__p0, __p1, __p2, __p3))

#define GLRasterPos3sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3424))(__p0, __p1))

#define GLRasterPos4d(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3430))(__p0, __p1, __p2, __p3, __p4))

#define GLRasterPos4dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3436))(__p0, __p1))

#define GLRasterPos4f(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3442))(__p0, __p1, __p2, __p3, __p4))

#define GLRasterPos4fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 3448))(__p0, __p1))

#define GLRasterPos4i(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3454))(__p0, __p1, __p2, __p3, __p4))

#define GLRasterPos4iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3460))(__p0, __p1))

#define GLRasterPos4s(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3466))(__p0, __p1, __p2, __p3, __p4))

#define GLRasterPos4sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3472))(__p0, __p1))

#define GLReadBuffer(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1252))(__p0, __p1))

#define GLReadPixels(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , void *))*(void**)((long)(TINYGL_BASE_NAME) - 1180))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLRectd(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3478))(__p0, __p1, __p2, __p3, __p4))

#define GLRectdv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, const GLdouble *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 934))(__p0, __p1, __p2))

#define GLRectf(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 916))(__p0, __p1, __p2, __p3, __p4))

#define GLRectfv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, const GLfloat *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 922))(__p0, __p1, __p2))

#define GLRecti(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3484))(__p0, __p1, __p2, __p3, __p4))

#define GLRectiv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, const GLint *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 928))(__p0, __p1, __p2))

#define GLRects(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3490))(__p0, __p1, __p2, __p3, __p4))

#define GLRectsv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, const GLshort *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3496))(__p0, __p1, __p2))

#define GLRenderMode(__p0, __p1) \
	(((GLint (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 316))(__p0, __p1))

#define GLRenderbufferStorage(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLsizei , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 3502))(__p0, __p1, __p2, __p3, __p4))

#define GLRenderbufferStorageMultisample(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLenum , GLsizei , GLenum , GLsizei , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 3508))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLResetHistogram(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 3514))(__p0, __p1))

#define GLResetMinmax(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 3520))(__p0, __p1))

#define GLRotated(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3526))(__p0, __p1, __p2, __p3, __p4))

#define GLRotatef(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 226))(__p0, __p1, __p2, __p3, __p4))

#define GLSampleCoverage(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLboolean ))*(void**)((long)(TINYGL_BASE_NAME) - 3532))(__p0, __p1, __p2))

#define GLSampleMapATI(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLuint , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 4420))(__p0, __p1, __p2, __p3))

#define GLScaled(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3538))(__p0, __p1, __p2, __p3))

#define GLScalef(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 238))(__p0, __p1, __p2, __p3))

#define GLScissor(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLint , GLsizei , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 880))(__p0, __p1, __p2, __p3, __p4))

#define GLSecondaryColor3b(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLbyte , GLbyte , GLbyte ))*(void**)((long)(TINYGL_BASE_NAME) - 3544))(__p0, __p1, __p2, __p3))

#define GLSecondaryColor3bv(__p0, __p1) \
	(((void (*)(GLContext *, const GLbyte *))*(void**)((long)(TINYGL_BASE_NAME) - 3550))(__p0, __p1))

#define GLSecondaryColor3d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3556))(__p0, __p1, __p2, __p3))

#define GLSecondaryColor3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3562))(__p0, __p1))

#define GLSecondaryColor3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3568))(__p0, __p1, __p2, __p3))

#define GLSecondaryColor3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 3574))(__p0, __p1))

#define GLSecondaryColor3i(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3580))(__p0, __p1, __p2, __p3))

#define GLSecondaryColor3iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3586))(__p0, __p1))

#define GLSecondaryColor3s(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3592))(__p0, __p1, __p2, __p3))

#define GLSecondaryColor3sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3598))(__p0, __p1))

#define GLSecondaryColor3ub(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLubyte , GLubyte , GLubyte ))*(void**)((long)(TINYGL_BASE_NAME) - 3604))(__p0, __p1, __p2, __p3))

#define GLSecondaryColor3ubv(__p0, __p1) \
	(((void (*)(GLContext *, const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 3610))(__p0, __p1))

#define GLSecondaryColor3ui(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLuint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 3616))(__p0, __p1, __p2, __p3))

#define GLSecondaryColor3uiv(__p0, __p1) \
	(((void (*)(GLContext *, const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 3622))(__p0, __p1))

#define GLSecondaryColor3us(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLushort , GLushort , GLushort ))*(void**)((long)(TINYGL_BASE_NAME) - 3628))(__p0, __p1, __p2, __p3))

#define GLSecondaryColor3usv(__p0, __p1) \
	(((void (*)(GLContext *, const GLushort *))*(void**)((long)(TINYGL_BASE_NAME) - 3634))(__p0, __p1))

#define GLSecondaryColorPointer(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 3640))(__p0, __p1, __p2, __p3, __p4))

#define GLSelectBuffer(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLsizei , GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 322))(__p0, __p1, __p2))

#define GLSeparableFilter2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((void (*)(GLContext *, GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const void *, const void *))*(void**)((long)(TINYGL_BASE_NAME) - 3646))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define GLSetFragmentShaderConstantATI(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 4426))(__p0, __p1, __p2))

#define GLShadeModel(__p0, __p1) \
	(((void (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 46))(__p0, __p1))

#define GLShaderSource(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLsizei , const GLchar *const *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1456))(__p0, __p1, __p2, __p3, __p4))

#define GLStencilFunc(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1210))(__p0, __p1, __p2, __p3))

#define GLStencilFuncSeparate(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 3652))(__p0, __p1, __p2, __p3, __p4))

#define GLStencilFuncSeparateATI(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 3658))(__p0, __p1, __p2, __p3, __p4))

#define GLStencilMask(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1222))(__p0, __p1))

#define GLStencilMaskSeparate(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLenum , GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 3664))(__p0, __p1, __p2))

#define GLStencilOp(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 1216))(__p0, __p1, __p2, __p3))

#define GLStencilOpSeparate(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLenum , GLenum , GLenum , GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 3670))(__p0, __p1, __p2, __p3, __p4))

#define GLTexCoord1d(__p0, __p1) \
	(((void (*)(GLContext *, GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3676))(__p0, __p1))

#define GLTexCoord1dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1498))(__p0, __p1))

#define GLTexCoord1f(__p0, __p1) \
	(((void (*)(GLContext *, GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3682))(__p0, __p1))

#define GLTexCoord1fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 3688))(__p0, __p1))

#define GLTexCoord1i(__p0, __p1) \
	(((void (*)(GLContext *, GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3694))(__p0, __p1))

#define GLTexCoord1iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3700))(__p0, __p1))

#define GLTexCoord1s(__p0, __p1) \
	(((void (*)(GLContext *, GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3706))(__p0, __p1))

#define GLTexCoord1sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3712))(__p0, __p1))

#define GLTexCoord2d(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3718))(__p0, __p1, __p2))

#define GLTexCoord2dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1156))(__p0, __p1))

#define GLTexCoord2f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 160))(__p0, __p1, __p2))

#define GLTexCoord2fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 166))(__p0, __p1))

#define GLTexCoord2i(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3724))(__p0, __p1, __p2))

#define GLTexCoord2iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1264))(__p0, __p1))

#define GLTexCoord2s(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3730))(__p0, __p1, __p2))

#define GLTexCoord2sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3736))(__p0, __p1))

#define GLTexCoord3d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3742))(__p0, __p1, __p2, __p3))

#define GLTexCoord3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1504))(__p0, __p1))

#define GLTexCoord3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1276))(__p0, __p1, __p2, __p3))

#define GLTexCoord3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 3748))(__p0, __p1))

#define GLTexCoord3i(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3754))(__p0, __p1, __p2, __p3))

#define GLTexCoord3iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3760))(__p0, __p1))

#define GLTexCoord3s(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3766))(__p0, __p1, __p2, __p3))

#define GLTexCoord3sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3772))(__p0, __p1))

#define GLTexCoord4d(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3778))(__p0, __p1, __p2, __p3, __p4))

#define GLTexCoord4dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1510))(__p0, __p1))

#define GLTexCoord4f(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3784))(__p0, __p1, __p2, __p3, __p4))

#define GLTexCoord4fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 3790))(__p0, __p1))

#define GLTexCoord4i(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3796))(__p0, __p1, __p2, __p3, __p4))

#define GLTexCoord4iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3802))(__p0, __p1))

#define GLTexCoord4s(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3808))(__p0, __p1, __p2, __p3, __p4))

#define GLTexCoord4sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3814))(__p0, __p1))

#define GLTexCoordPointer(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 544))(__p0, __p1, __p2, __p3, __p4))

#define GLTexEnvf(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 388))(__p0, __p1, __p2, __p3))

#define GLTexEnvfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1390))(__p0, __p1, __p2, __p3))

#define GLTexEnvi(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 382))(__p0, __p1, __p2, __p3))

#define GLTexEnviv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3820))(__p0, __p1, __p2, __p3))

#define GLTexGend(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3826))(__p0, __p1, __p2, __p3))

#define GLTexGendv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3832))(__p0, __p1, __p2, __p3))

#define GLTexGenf(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3838))(__p0, __p1, __p2, __p3))

#define GLTexGenfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 424))(__p0, __p1, __p2, __p3))

#define GLTexGeni(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 418))(__p0, __p1, __p2, __p3))

#define GLTexGeniv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3844))(__p0, __p1, __p2, __p3))

#define GLTexImage1D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLsizei , GLint , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 1474))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8))

#define GLTexImage2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLsizei , GLsizei , GLint , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 370))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define GLTexImage3D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 3850))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10))

#define GLTexParameterIiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 4474))(__p0, __p1, __p2, __p3))

#define GLTexParameterIuiv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 4480))(__p0, __p1, __p2, __p3))

#define GLTexParameterf(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 400))(__p0, __p1, __p2, __p3))

#define GLTexParameterfv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 1906))(__p0, __p1, __p2, __p3))

#define GLTexParameteri(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 394))(__p0, __p1, __p2, __p3))

#define GLTexParameteriv(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLenum , GLenum , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 1900))(__p0, __p1, __p2, __p3))

#define GLTexSubImage1D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLsizei , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 1480))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7))

#define GLTexSubImage2D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 376))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9))

#define GLTexSubImage3D(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11) \
	(((void (*)(GLContext *, GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLenum , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 3856))(__p0, __p1, __p2, __p3, __p4, __p5, __p6, __p7, __p8, __p9, __p10, __p11))

#define GLTranslated(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3862))(__p0, __p1, __p2, __p3))

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

#define GLUnmapBuffer(__p0, __p1) \
	(((GLboolean (*)(GLContext *, GLenum ))*(void**)((long)(TINYGL_BASE_NAME) - 3868))(__p0, __p1))

#define GLUseProgram(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1654))(__p0, __p1))

#define GLValidateProgram(__p0, __p1) \
	(((void (*)(GLContext *, GLuint ))*(void**)((long)(TINYGL_BASE_NAME) - 1462))(__p0, __p1))

#define GLVertex2d(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3874))(__p0, __p1, __p2))

#define GLVertex2dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3880))(__p0, __p1))

#define GLVertex2f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3886))(__p0, __p1, __p2))

#define GLVertex2fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 3892))(__p0, __p1))

#define GLVertex2i(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3898))(__p0, __p1, __p2))

#define GLVertex2iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3904))(__p0, __p1))

#define GLVertex2s(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3910))(__p0, __p1, __p2))

#define GLVertex2sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3916))(__p0, __p1))

#define GLVertex3d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3922))(__p0, __p1, __p2, __p3))

#define GLVertex3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1144))(__p0, __p1))

#define GLVertex3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 76))(__p0, __p1, __p2, __p3))

#define GLVertex3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 88))(__p0, __p1))

#define GLVertex3i(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3928))(__p0, __p1, __p2, __p3))

#define GLVertex3iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3934))(__p0, __p1))

#define GLVertex3s(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3940))(__p0, __p1, __p2, __p3))

#define GLVertex3sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3946))(__p0, __p1))

#define GLVertex4d(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3952))(__p0, __p1, __p2, __p3, __p4))

#define GLVertex4dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 1150))(__p0, __p1))

#define GLVertex4f(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 82))(__p0, __p1, __p2, __p3, __p4))

#define GLVertex4fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 94))(__p0, __p1))

#define GLVertex4i(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 3958))(__p0, __p1, __p2, __p3, __p4))

#define GLVertex4iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 3964))(__p0, __p1))

#define GLVertex4s(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 3970))(__p0, __p1, __p2, __p3, __p4))

#define GLVertex4sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 3976))(__p0, __p1))

#define GLVertexAttrib1d(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 3982))(__p0, __p1, __p2))

#define GLVertexAttrib1dv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 3988))(__p0, __p1, __p2))

#define GLVertexAttrib1f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 3994))(__p0, __p1, __p2))

#define GLVertexAttrib1fv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 4000))(__p0, __p1, __p2))

#define GLVertexAttrib1s(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 4006))(__p0, __p1, __p2))

#define GLVertexAttrib1sv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 4012))(__p0, __p1, __p2))

#define GLVertexAttrib2d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 4018))(__p0, __p1, __p2, __p3))

#define GLVertexAttrib2dv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 4024))(__p0, __p1, __p2))

#define GLVertexAttrib2f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 4030))(__p0, __p1, __p2, __p3))

#define GLVertexAttrib2fv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 4036))(__p0, __p1, __p2))

#define GLVertexAttrib2s(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLuint , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 4042))(__p0, __p1, __p2, __p3))

#define GLVertexAttrib2sv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 4048))(__p0, __p1, __p2))

#define GLVertexAttrib3d(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 4054))(__p0, __p1, __p2, __p3, __p4))

#define GLVertexAttrib3dv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 4060))(__p0, __p1, __p2))

#define GLVertexAttrib3f(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 4066))(__p0, __p1, __p2, __p3, __p4))

#define GLVertexAttrib3fv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 4072))(__p0, __p1, __p2))

#define GLVertexAttrib3s(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLuint , GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 4078))(__p0, __p1, __p2, __p3, __p4))

#define GLVertexAttrib3sv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 4084))(__p0, __p1, __p2))

#define GLVertexAttrib4Nbv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLbyte *))*(void**)((long)(TINYGL_BASE_NAME) - 4090))(__p0, __p1, __p2))

#define GLVertexAttrib4Niv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 4096))(__p0, __p1, __p2))

#define GLVertexAttrib4Nsv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 4102))(__p0, __p1, __p2))

#define GLVertexAttrib4Nub(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLuint , GLubyte , GLubyte , GLubyte , GLubyte ))*(void**)((long)(TINYGL_BASE_NAME) - 4108))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLVertexAttrib4Nubv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 4114))(__p0, __p1, __p2))

#define GLVertexAttrib4Nuiv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 4120))(__p0, __p1, __p2))

#define GLVertexAttrib4Nusv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLushort *))*(void**)((long)(TINYGL_BASE_NAME) - 4126))(__p0, __p1, __p2))

#define GLVertexAttrib4bv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLbyte *))*(void**)((long)(TINYGL_BASE_NAME) - 4132))(__p0, __p1, __p2))

#define GLVertexAttrib4d(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLuint , GLdouble , GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 4138))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLVertexAttrib4dv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 4144))(__p0, __p1, __p2))

#define GLVertexAttrib4f(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLuint , GLfloat , GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 4150))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLVertexAttrib4fv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 4156))(__p0, __p1, __p2))

#define GLVertexAttrib4iv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 4162))(__p0, __p1, __p2))

#define GLVertexAttrib4s(__p0, __p1, __p2, __p3, __p4, __p5) \
	(((void (*)(GLContext *, GLuint , GLshort , GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 4168))(__p0, __p1, __p2, __p3, __p4, __p5))

#define GLVertexAttrib4sv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 4174))(__p0, __p1, __p2))

#define GLVertexAttrib4ubv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 4180))(__p0, __p1, __p2))

#define GLVertexAttrib4uiv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 4186))(__p0, __p1, __p2))

#define GLVertexAttrib4usv(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLuint , const GLushort *))*(void**)((long)(TINYGL_BASE_NAME) - 4192))(__p0, __p1, __p2))

#define GLVertexAttribPointer(__p0, __p1, __p2, __p3, __p4, __p5, __p6) \
	(((void (*)(GLContext *, GLuint , GLint , GLenum , GLboolean , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 1636))(__p0, __p1, __p2, __p3, __p4, __p5, __p6))

#define GLVertexBlendARB(__p0, __p1) \
	(((void (*)(GLContext *, GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 4198))(__p0, __p1))

#define GLVertexPointer(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 526))(__p0, __p1, __p2, __p3, __p4))

#define GLViewport(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLint , GLsizei , GLsizei ))*(void**)((long)(TINYGL_BASE_NAME) - 1912))(__p0, __p1, __p2, __p3, __p4))


#define GLWeightPointerARB(__p0, __p1, __p2, __p3, __p4) \
	(((void (*)(GLContext *, GLint , GLenum , GLsizei , const void *))*(void**)((long)(TINYGL_BASE_NAME) - 4204))(__p0, __p1, __p2, __p3, __p4))

#define GLWeightbvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLbyte *))*(void**)((long)(TINYGL_BASE_NAME) - 4210))(__p0, __p1, __p2))

#define GLWeightdvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 4216))(__p0, __p1, __p2))

#define GLWeightfvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 4222))(__p0, __p1, __p2))

#define GLWeightivARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 4228))(__p0, __p1, __p2))

#define GLWeightsvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 4234))(__p0, __p1, __p2))

#define GLWeightubvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLubyte *))*(void**)((long)(TINYGL_BASE_NAME) - 4240))(__p0, __p1, __p2))

#define GLWeightuivARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLuint *))*(void**)((long)(TINYGL_BASE_NAME) - 4246))(__p0, __p1, __p2))

#define GLWeightusvARB(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , const GLushort *))*(void**)((long)(TINYGL_BASE_NAME) - 4252))(__p0, __p1, __p2))

#define GLWindowPos2d(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 4258))(__p0, __p1, __p2))

#define GLWindowPos2dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 4264))(__p0, __p1))

#define GLWindowPos2f(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 1096))(__p0, __p1, __p2))

#define GLWindowPos2fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 4270))(__p0, __p1))

#define GLWindowPos2i(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 4276))(__p0, __p1, __p2))

#define GLWindowPos2iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 4282))(__p0, __p1))

#define GLWindowPos2s(__p0, __p1, __p2) \
	(((void (*)(GLContext *, GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 4288))(__p0, __p1, __p2))

#define GLWindowPos2sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 4294))(__p0, __p1))

#define GLWindowPos3d(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLdouble , GLdouble , GLdouble ))*(void**)((long)(TINYGL_BASE_NAME) - 4300))(__p0, __p1, __p2, __p3))

#define GLWindowPos3dv(__p0, __p1) \
	(((void (*)(GLContext *, const GLdouble *))*(void**)((long)(TINYGL_BASE_NAME) - 4306))(__p0, __p1))

#define GLWindowPos3f(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLfloat , GLfloat , GLfloat ))*(void**)((long)(TINYGL_BASE_NAME) - 4312))(__p0, __p1, __p2, __p3))

#define GLWindowPos3fv(__p0, __p1) \
	(((void (*)(GLContext *, const GLfloat *))*(void**)((long)(TINYGL_BASE_NAME) - 4318))(__p0, __p1))

#define GLWindowPos3i(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLint , GLint , GLint ))*(void**)((long)(TINYGL_BASE_NAME) - 4324))(__p0, __p1, __p2, __p3))

#define GLWindowPos3iv(__p0, __p1) \
	(((void (*)(GLContext *, const GLint *))*(void**)((long)(TINYGL_BASE_NAME) - 4330))(__p0, __p1))

#define GLWindowPos3s(__p0, __p1, __p2, __p3) \
	(((void (*)(GLContext *, GLshort , GLshort , GLshort ))*(void**)((long)(TINYGL_BASE_NAME) - 4336))(__p0, __p1, __p2, __p3))

#define GLWindowPos3sv(__p0, __p1) \
	(((void (*)(GLContext *, const GLshort *))*(void**)((long)(TINYGL_BASE_NAME) - 4342))(__p0, __p1))

#define TGLEnableNewExtensions(__p0, __p1) \
	(((void (*)(GLContext *, unsigned int ))*(void**)((long)(TINYGL_BASE_NAME) - 4432))(__p0, __p1))

#define TGLGetContextVersion(__p0) \
	(((unsigned int (*)(GLContext *))*(void**)((long)(TINYGL_BASE_NAME) - 4504))(__p0))

#define TGLGetContexts() \
	(((void *(*)(void))*(void**)((long)(TINYGL_BASE_NAME) - 634))())

#define TGLGetProcAddress(__p0, __p1) \
	(((void *(*)(GLContext **, const char *))*(void**)((long)(TINYGL_BASE_NAME) - 4438))(__p0, __p1))

#define TGLSetContextVersion(__p0, __p1) \
	(((void (*)(GLContext *, unsigned int ))*(void**)((long)(TINYGL_BASE_NAME) - 4498))(__p0, __p1))

#endif /* !_PPCINLINE_TINYGL_H */
