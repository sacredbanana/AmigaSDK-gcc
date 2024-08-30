/*
 * $Id: minigl.h 533 2018-06-01 10:20:40Z sbiro $
 *
 * $Date: 2018-06-01 13:20:40 +0300 (Fri, 01 Jun 2018) $
 * $Revision: 533 $
 *
 *(C) 1999 by Hyperion
 * All rights reserved
 *
 * This file is part of the MiniGL library project
 * See the file Licence.txt for more details
 *
 */

#ifndef __MINIGL_H_INLINES
#define __MINIGL_H_INLINES

#ifndef MGLAPI
	#if defined(__GNUC__) || defined(__VBCC__)
	#define MGLAPI static inline
	#elif defined(__STORMC__)
	#define MGLAPI __inline
	#endif
#endif

#include <interfaces/minigl.h>

#ifndef GET_INSTANCE
#include <exec/interfaces.h>
#define GET_INSTANCE(self)                          \
         ((uint32)self - self->Data.NegativeSize)
#endif

#define CC mini_CurrentContext

typedef void (*_GLUfuncptr)();

#ifdef __cplusplus
extern "C" {
#endif

#include <GL/glu.h>

MGLAPI void glClipPlane(GLenum plane, GLdouble *eqn)
{
	CC->GLClipPlane(plane, eqn);
}

MGLAPI void glPolygonOffset(GLfloat factor, GLfloat units)
{
	CC->GLPolygonOffset(factor, units);
}

MGLAPI void   glTexEnviv(GLenum target, GLenum pname, GLint *param)
{
	CC->GLTexEnvi(target, pname, *(param)) ;
}

MGLAPI void   glTexEnvfv(GLenum target, GLenum pname, const GLfloat* param)
{
	CC->GLTexEnvfv(target, pname, param) ;
}

MGLAPI void glGetTexEnviv(GLenum target, GLenum pname, GLint* params)
{
	CC->GLGetTexEnviv(target, pname, params);
}


MGLAPI void glGetBooleanv( GLenum pname, GLboolean *params)
{
	CC->GLGetBooleanv(pname, params) ;
}

MGLAPI void glGetIntegerv( GLenum pname, GLint *params)
{
	CC->GLGetIntegerv(pname, params) ;
}

MGLAPI void glGetPointerv(GLenum pname, GLvoid **params)
{
	CC->GLGetPointerv(pname, params) ;
}

MGLAPI GLboolean glIsEnabled(GLenum cap)
{
   return CC->GLIsEnabled(cap);
}

MGLAPI void glAlphaFunc(GLenum func, GLclampf ref)
{
	CC->GLAlphaFunc(func, ref);
}

MGLAPI void glBegin(GLenum mode)
{
	CC->GLBegin(mode);
}

MGLAPI void glBindTexture(GLenum target, GLuint texture)
{
	CC->GLBindTexture(target, texture);
}

MGLAPI void glBlendFunc(GLenum sfactor, GLenum dfactor)
{
	CC->GLBlendFunc(sfactor, dfactor);
}

MGLAPI void glClear(GLbitfield mask)
{
	CC->GLClear(mask);
}

MGLAPI void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	CC->GLClearColor(red, green, blue, alpha);
}

MGLAPI void glClearDepth(GLclampd depth)
{
	CC->GLClearDepth(depth);
}

MGLAPI void glColor3b(GLbyte red, GLbyte green, GLbyte blue)
{
	CC->GLColor4f((GLfloat)red/255.0f,(GLfloat)green/255.0f,(GLfloat)blue/255.f, 1.0f);
}

MGLAPI void glColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
	CC->GLColor4f((GLfloat)red/255.0f,(GLfloat)green/255.0f,(GLfloat)blue/255.f, 1.0f);
}

MGLAPI void glColor3bv(const GLbyte* v)
{
	CC->GLColor4f((GLfloat)v[0]/255.0f,(GLfloat)v[1]/255.0f,(GLfloat)v[2]/255.f, 1.0f);
}

MGLAPI void glColor3ubv(const GLubyte* v)
{
	CC->GLColor4f((GLfloat)v[0]/255.0f,(GLfloat)v[1]/255.0f,(GLfloat)v[2]/255.f, 1.0f);
}

MGLAPI void glColor3s(GLshort red, GLshort green, GLshort blue)
{
	CC->GLColor4f((GLfloat)red/65535.0f,(GLfloat)green/65535.0f,(GLfloat)blue/65535.f, 1.0f);
}

MGLAPI void glColor3us(GLushort red, GLushort green, GLushort blue)
{
	CC->GLColor4f((GLfloat)red/65535.0f,(GLfloat)green/65535.0f,(GLfloat)blue/65535.f, 1.0f);
}

MGLAPI void glColor3sv(const GLshort* v)
{
	CC->GLColor4f((GLfloat)v[0]/65535.0f,(GLfloat)v[1]/65535.0f,(GLfloat)v[2]/65535.f, 1.0f);
}

MGLAPI void glColor3usv(const GLushort* v)
{
	CC->GLColor4f((GLfloat)v[0]/65535.0f,(GLfloat)v[1]/65535.0f,(GLfloat)v[2]/65535.f, 1.0f);
}

MGLAPI void glColor3i(GLint red, GLint green, GLint blue)
{
	CC->GLColor4f((GLfloat)red/429496795.0f,(GLfloat)green/429496795.0f,(GLfloat)blue/429496795.f, 1.0f);
}

MGLAPI void glColor3ui(GLuint red, GLuint green, GLuint blue)
{
	CC->GLColor4f((GLfloat)red/429496795.0f,(GLfloat)green/429496795.0f,(GLfloat)blue/429496795.f, 1.0f);
}

MGLAPI void glColor3iv(const GLint* v)
{
	CC->GLColor4f((GLfloat)v[0]/429496795.0f,(GLfloat)v[1]/429496795.0f,(GLfloat)v[2]/429496795.f, 1.0f);
}

MGLAPI void glColor3uiv(const GLuint* v)
{
	CC->GLColor4f((GLfloat)v[0]/429496795.0f,(GLfloat)v[1]/429496795.0f,(GLfloat)v[2]/429496795.f, 1.0f);
}

MGLAPI void glColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
	CC->GLColor4f((GLfloat)red,(GLfloat)green,(GLfloat)blue, 1.0f);
}

MGLAPI void glColor3fv(const GLfloat* v)
{
	CC->GLColor4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2], 1.0f);
}

MGLAPI void glColor3d(GLdouble red, GLdouble green, GLdouble blue)
{
	CC->GLColor4f((GLfloat)red,(GLfloat)green,(GLfloat)blue, 1.0f);
}

MGLAPI void glColor3dv(const GLdouble* v)
{
	CC->GLColor4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2], 1.0f);
}

MGLAPI void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha)
{
	CC->GLColor4f((GLfloat)red/255.0f,(GLfloat)green/255.0f,(GLfloat)blue/255.f,(GLfloat)alpha/255.0f);
}

MGLAPI void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
	CC->GLColor4f((GLfloat)red/255.0f,(GLfloat)green/255.0f,(GLfloat)blue/255.f,(GLfloat)alpha/255.0f);
}

MGLAPI void glColor4bv(const GLbyte* v)
{
	CC->GLColor4f((GLfloat)v[0]/255.0f,(GLfloat)v[1]/255.0f,(GLfloat)v[2]/255.f,(GLfloat)v[3]/255.0f);
}

MGLAPI void glColor4ubv(const GLubyte* v)
{
	CC->GLColor4f((GLfloat)v[0]/255.0f,(GLfloat)v[1]/255.0f,(GLfloat)v[2]/255.f,(GLfloat)v[3]/255.0f);
}

MGLAPI void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha)
{
	CC->GLColor4f((GLfloat)red/65535.0f,(GLfloat)green/65535.0f,(GLfloat)blue/65535.f,(GLfloat)alpha/65535.0f);
}

MGLAPI void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha)
{
	CC->GLColor4f((GLfloat)red/65535.0f,(GLfloat)green/65535.0f,(GLfloat)blue/65535.f,(GLfloat)alpha/65535.0f);
}

MGLAPI void glColor4sv(const GLshort* v)
{
	CC->GLColor4f((GLfloat)v[0]/65535.0f,(GLfloat)v[1]/65535.0f,(GLfloat)v[2]/65535.f,(GLfloat)v[3]/65535.0f);
}

MGLAPI void glColor4usv(const GLushort* v)
{
	CC->GLColor4f((GLfloat)v[0]/65535.0f,(GLfloat)v[1]/65535.0f,(GLfloat)v[2]/65535.f,(GLfloat)v[3]/65535.0f);
}

MGLAPI void glColor4i(GLint red, GLint green, GLint blue, GLint alpha)
{
	CC->GLColor4f((GLfloat)red/429496795.0f,(GLfloat)green/429496795.0f,(GLfloat)blue/429496795.0f,(GLfloat)alpha/429496795.0f);
}

MGLAPI void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha)
{
	CC->GLColor4f((GLfloat)red/429496795.0f,(GLfloat)green/429496795.0f,(GLfloat)blue/429496795.0f,(GLfloat)alpha/429496795.0f);
}

MGLAPI void glColor4iv(const GLint* v)
{
	CC->GLColor4f((GLfloat)v[0]/429496795.0f,(GLfloat)v[1]/429496795.0f,(GLfloat)v[2]/429496795.0f,(GLfloat)v[3]/429496795.0f);
}

MGLAPI void glColor4uiv(const GLuint* v)
{
	CC->GLColor4f((GLfloat)v[0]/429496795.0f,(GLfloat)v[1]/429496795.0f,(GLfloat)v[2]/429496795.0f,(GLfloat)v[3]/429496795.0f);
}

MGLAPI void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	CC->GLColor4f((GLfloat)red,(GLfloat)green,(GLfloat)blue,(GLfloat)alpha);
}

MGLAPI void glColor4fv(const GLfloat* v)
{
	CC->GLColor4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]);
}

MGLAPI void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha)
{
	CC->GLColor4f((GLfloat)red,(GLfloat)green,(GLfloat)blue,(GLfloat)alpha);
}

MGLAPI void glColor4dv(const GLdouble* v)
{
	CC->GLColor4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]);
}

MGLAPI void glCullFace(GLenum mode)
{
	CC->GLCullFace(mode);
}

MGLAPI void glVertex2s(GLshort x, GLshort y)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y, 0.0f, 1.0f);
}

MGLAPI void glVertex2i(GLint x, GLint y)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y, 0.0f, 1.0f);
}

MGLAPI void glVertex2f(GLfloat x, GLfloat y)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y, 0.0f, 1.0f);
}

MGLAPI void glVertex2d(GLfloat x, GLfloat y)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y, 0.0f, 1.0f);
}

MGLAPI void glVertex3s(GLshort x, GLshort y, GLshort z)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y,(GLfloat)z, 1.0f);
}

MGLAPI void glVertex3i(GLint x, GLint y, GLint z)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y,(GLfloat)z, 1.0f);
}

MGLAPI void glVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y,(GLfloat)z, 1.0f);
}

MGLAPI void glVertex3d(GLdouble x, GLdouble y, GLdouble z)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y,(GLfloat)z, 1.0f);
}

MGLAPI void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);
}

MGLAPI void glVertex4i(GLint x, GLint y, GLint z, GLint w)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);
}

MGLAPI void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);
}

MGLAPI void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	CC->GLVertex4f((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);
}

MGLAPI void glVertex2sv(const GLshort *v)
{
	CC->GLVertex4f((GLfloat)v[0],(GLfloat)v[1], 0.0f, 1.0f);
}

MGLAPI void glVertex2iv(const GLint *v)
{
	CC->GLVertex4f((GLfloat)v[0],(GLfloat)v[1], 0.0f, 1.0f);
}

MGLAPI void glVertex2fv(const GLfloat *v)
{
	CC->GLVertex4f((GLfloat)v[0],(GLfloat)v[1], 0.0f, 1.0f);
}

MGLAPI void glVertex2dv(const GLdouble *v)
{
	CC->GLVertex4f((GLfloat)v[0],(GLfloat)v[1], 0.0f, 1.0f);
}

MGLAPI void glVertex3sv(const GLshort *v)
{
	CC->GLVertex4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2], 1.0f);
}

MGLAPI void glVertex3iv(const GLint *v)
{
	CC->GLVertex4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2], 1.0f);
}

MGLAPI void glVertex3fv(const GLfloat *v)
{
	CC->GLVertex3fv(v);
}

MGLAPI void glVertex3dv(const GLdouble *v)
{
	CC->GLVertex4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2], 1.0f);
}

MGLAPI void glVertex4sv(const GLshort *v)
{
	CC->GLVertex4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]);
}

MGLAPI void glVertex4iv(const GLint *v)
{
	CC->GLVertex4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]);
}

MGLAPI void glVertex4fv(const GLfloat *v)
{
	CC->GLVertex4fv(v);
}

MGLAPI void glVertex4dv(const GLdouble *v)
{
	CC->GLVertex4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]);
}


MGLAPI void glDeleteTextures(GLsizei n, const GLuint *textures)
{
	CC->GLDeleteTextures(n, textures);
}

MGLAPI void glDepthFunc(GLenum func)
{
	CC->GLDepthFunc(func);
}

MGLAPI void glDepthMask(GLboolean flag)
{
	CC->GLDepthMask(flag);
}

MGLAPI void glDepthRange(GLclampd n, GLclampd f)
{
	CC->GLDepthRange(n, f);
}

MGLAPI void glDisable(GLenum cap)
{
	CC->SetState(cap, GL_FALSE);
}

MGLAPI void glDrawBuffer(GLenum mode)
{
	CC->GLDrawBuffer(mode);
}

MGLAPI void glEnable(GLenum cap)
{
	CC->SetState(cap, GL_TRUE);
}

MGLAPI void glEnd(void)
{
	CC->GLEnd();
}

MGLAPI void glFinish(void)
{
	CC->GLFinish();
}

MGLAPI void glFlush(void)
{
	CC->GLFlush();
}

MGLAPI void glFogf(GLenum pname, GLfloat param)
{
	CC->GLFogf(pname, param);
}

MGLAPI void glFogi(GLenum pname, GLint param)
{
	CC->GLFogf(pname,(GLfloat)param);
}

MGLAPI void glFogfv(GLenum pname, const GLfloat *param)
{
	CC->GLFogfv(pname, param);
}

MGLAPI void glFrontFace(GLenum mode)
{
	CC->GLFrontFace(mode);
}

MGLAPI void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
	CC->GLFrustum(left, right, bottom, top, zNear, zFar);
}

MGLAPI void glGenTextures(GLsizei n, GLuint *textures)
{
	CC->GLGenTextures(n, textures);
}

MGLAPI GLenum glGetError(void)
{
	return CC->GLGetError();
}

MGLAPI void glGetFloatv(GLenum pname, GLfloat *params)
{
	CC->GLGetFloatv(pname, params);
}

MGLAPI const GLubyte * glGetString(GLenum name)
{
	return CC->GLGetString(name);
}

MGLAPI void glHint(GLenum target, GLenum mode)
{
	CC->GLHint(target, mode);
}

MGLAPI void glLoadIdentity(void)
{
	CC->GLLoadIdentity();
}

MGLAPI void glLoadMatrixd(const GLdouble *m)
{
	CC->GLLoadMatrixd(m);
}

MGLAPI void glLoadMatrixf(const GLfloat *m)
{
	CC->GLLoadMatrixf(m);
}

MGLAPI void glMatrixMode(GLenum mode)
{
	CC->GLMatrixMode(mode);
}

MGLAPI void glMultMatrixd(const GLdouble *m)
{
	CC->GLMultMatrixd(m);
}

MGLAPI void glMultMatrixf(const GLfloat *m)
{
	CC->GLMultMatrixf(m);
}


MGLAPI void glNormal3f(GLfloat x, GLfloat y, GLfloat z)
{
	CC->GLNormal3f(x, y, z);
}

MGLAPI void glNormal3d(GLdouble x, GLdouble y, GLdouble z)
{
	CC->GLNormal3f((GLfloat)x,(GLfloat)y,(GLfloat)z);
}

MGLAPI void glNormal3i(GLint x, GLint y, GLint z)
{
	CC->GLNormal3f((GLfloat)x,(GLfloat)y,(GLfloat)z);
}

MGLAPI void glNormal3s(GLshort x, GLshort y, GLshort z)
{
	CC->GLNormal3f((GLfloat)x,(GLfloat)y,(GLfloat)z);
}

MGLAPI void glNormal3b(GLbyte x, GLbyte y, GLbyte z)
{
	CC->GLNormal3f((GLfloat)x,(GLfloat)y,(GLfloat)z);
}

MGLAPI void glNormal3fv(const GLfloat n[])
{
	CC->GLNormal3fv(n);
}

MGLAPI void glNormal3dv(const GLdouble n[])
{
	CC->GLNormal3f((GLfloat)n[0],(GLfloat)n[1],(GLfloat)n[2]);
}

MGLAPI void glNormal3iv(const GLint n[])
{
	CC->GLNormal3f((GLfloat)n[0],(GLfloat)n[1],(GLfloat)n[2]);
}

MGLAPI void glNormal3sv(const GLshort n[])
{
	CC->GLNormal3f((GLfloat)n[0],(GLfloat)n[1],(GLfloat)n[2]);
}

MGLAPI void glNormal3bv(const GLbyte n[])
{
	CC->GLNormal3f((GLfloat)n[0],(GLfloat)n[1],(GLfloat)n[2]);
}

MGLAPI void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar)
{
	CC->GLOrtho(left, right, bottom, top, zNear, zFar);
}

MGLAPI void glPixelStorei(GLenum pname, GLint param)
{
	CC->GLPixelStorei(pname, param);
}

MGLAPI void glPixelStoref(GLenum pname, GLfloat param)
{
	CC->GLPixelStorei(pname,(GLint)param);
}

MGLAPI void glPolygonMode(GLenum face, GLenum mode)
{
	CC->GLPolygonMode(face, mode);
}

MGLAPI void glPopMatrix(void)
{
	CC->GLPopMatrix();
}

MGLAPI void glPushMatrix(void)
{
	CC->GLPushMatrix();
}

MGLAPI void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
	CC->GLReadPixels(x, y, width, height, format, type, pixels);
}

MGLAPI void	glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	CC->GLRectf(x1, y1, x2, y2);
}

MGLAPI void	glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2)
{
	CC->GLRectf((GLfloat)x1,(GLfloat)y1,(GLfloat)x2,(GLfloat)y2);
}

MGLAPI void	glRecti(GLint x1, GLint y1, GLint x2, GLint y2)
{
	CC->GLRectf((GLfloat)x1,(GLfloat)y1,(GLfloat)x2,(GLfloat)y2);
}

MGLAPI void	glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
{
	CC->GLRectf((GLfloat)x1,(GLfloat)y1,(GLfloat)x2,(GLfloat)y2);
}

MGLAPI void	glRectsv(const GLshort *v1, const GLshort *v2)
{
	CC->GLRectf((GLfloat)v1[0],(GLfloat)v1[1],(GLfloat)v2[0],(GLfloat)v2[0]);
}

MGLAPI void	glRectiv(const GLint *v1, const GLint *v2)
{
	CC->GLRectf((GLfloat)v1[0],(GLfloat)v1[1],(GLfloat)v2[0],(GLfloat)v2[0]);
}

MGLAPI void	glRectfv(const GLfloat *v1, const GLfloat *v2)
{
	CC->GLRectf((GLfloat)v1[0],(GLfloat)v1[1],(GLfloat)v2[0],(GLfloat)v2[0]);
}

MGLAPI void	glRectdv(const GLdouble *v1, const GLdouble *v2)
{
	CC->GLRectf((GLfloat)v1[0],(GLfloat)v1[1],(GLfloat)v2[0],(GLfloat)v2[0]);
}



MGLAPI void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
	CC->GLRotatef(angle, x, y, z);
}

MGLAPI void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
	CC->GLRotatef((GLfloat)angle,(GLfloat)x,(GLfloat)y,(GLfloat)z);
}

MGLAPI void glScalef(GLfloat x, GLfloat y, GLfloat z)
{
	CC->GLScalef(x, y, z);
}

MGLAPI void glScaled(GLdouble x, GLdouble y, GLdouble z)
{
	CC->GLScalef((GLfloat)x,(GLfloat)y,(GLfloat)z);
}

MGLAPI void glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
	CC->GLScissor(x, y, width, height);
}

MGLAPI void glShadeModel(GLenum mode)
{
	CC->GLShadeModel(mode);
}

MGLAPI void glTexCoord1f(GLfloat s)
{
	CC->GLTexCoord2f(s, 0);
}

MGLAPI void glTexCoord1d(GLdouble s)
{
	CC->GLTexCoord2f((GLfloat)s,(GLfloat)0);
}

MGLAPI void glTexCoord1i(GLint s)
{
	CC->GLTexCoord2f((GLfloat)s,(GLfloat)0);
}

MGLAPI void glTexCoord2f(GLfloat s, GLfloat t)
{
	CC->GLTexCoord2f(s, t);
}

MGLAPI void glTexCoord2d(GLdouble s, GLdouble t)
{
	CC->GLTexCoord2f((GLfloat)s,(GLfloat)t);
}


MGLAPI void glTexCoord2i(GLint s, GLint t)
{
	CC->GLTexCoord2f((GLfloat)s,(GLfloat)t);
}

MGLAPI void glTexCoord2fv(const GLfloat *v)
{
	CC->GLTexCoord2f(v[0], v[1]);
}

MGLAPI void glTexCoord2iv(const GLint *v)
{
	CC->GLTexCoord2f((GLfloat)v[0], (GLfloat)v[1]);
}

MGLAPI void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r)
{
	CC->GLTexCoord2f(s, t);
}

MGLAPI void glTexCoord3fv(const GLfloat *v)
{
	CC->GLTexCoord2f(v[0], v[1]);
}


MGLAPI void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	CC->GLTexCoord4f(s, t, r, q);
}

MGLAPI void glTexCoord4fv(const GLfloat *v)
{
	CC->GLTexCoord4f(v[0], v[1], v[2], v[3]);
}

MGLAPI void glTexEnvf(GLenum target, GLenum pname, GLfloat param)
{
	CC->GLTexEnvi(target, pname,(GLint)param);
}

MGLAPI void glTexEnvi(GLenum target, GLenum pname, GLint param)
{
	CC->GLTexEnvi(target, pname, param);
}

MGLAPI void glTexGeni(GLenum coord, GLenum mode, GLint param)
{
	CC->GLTexGeni(coord, mode, param);
}

MGLAPI void glTexGenfv(GLenum coord, GLenum pname, GLfloat *params)
{
	CC->GLTexGenfv(coord, pname, params);
}

MGLAPI void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	CC->GLTexImage1D(target, level, internalformat, width, border, format, type, pixels);
}


MGLAPI void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
	CC->GLTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

MGLAPI void glTexParameteri(GLenum target, GLenum pname, GLint param)
{
	CC->GLTexParameteri(target, pname, param);
}

/*
surgeon begin: you should consider including glTexParameterf - I guess you just forgot :)
ThomasF: Yep, you're right :)
*/
MGLAPI void glTexParameterf(GLenum target, GLenum pname, GLfloat param)
{
	CC->GLTexParameteri(target, pname,(GLint)param);
}
/*
surgeon end
*/

MGLAPI void glTexParameterfv(GLenum target, GLenum pname, GLfloat *param)
{
	CC->GLTexParameterfv(target, pname, param);
}

MGLAPI void glTexParameteriv(GLenum target, GLenum pname, GLint *param)
{
	CC->GLTexParameteriv(target, pname, param);
}

MGLAPI void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
	CC->GLTexSubImage1D(target, level, xoffset, width, format, type, pixels);
}

MGLAPI void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	CC->GLTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

MGLAPI void glTranslated(GLdouble x, GLdouble y, GLdouble z)
{
	CC->GLTranslatef((GLfloat)x,(GLfloat)y,(GLfloat)z);
}

MGLAPI void glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
	CC->GLTranslatef(x, y, z);
}

MGLAPI void glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	CC->GLViewport(x, y, width, height);
}

MGLAPI void mglSetBitmap(void *bm)
{
	CC->SetBitmap(bm);
}

MGLAPI void mglDeleteContext(void)
{
	CC->DeleteContext();
	CC = 0;
}

MGLAPI void mglEnableSync(GLboolean enable)
{
	CC->EnableSync(enable);
}

MGLAPI void mglMakeCurrent(void *context)
{
	CC =(struct GLContextIFace *)context;
}

//MGLAPI void mglEnableFrameStats(GLboolean enable)
//{
//	MGLEnableFrameStats(enable);
//}

MGLAPI void mglMinTriArea(GLfloat area)
{
	CC->MinTriArea(area);
}


MGLAPI void * mglGetWindowHandle(void)
{
	return CC->GetWindowHandle();
}


MGLAPI GLboolean mglLockDisplay(void)
{
	return CC->LockDisplay();
}

MGLAPI void mglLockMode(GLenum lockMode)
{
	CC->LockMode(lockMode);
}


MGLAPI void mglResizeContext(GLsizei width, GLsizei height)
{
	CC->ResizeContext(width, height);
}

MGLAPI void mglSwitchDisplay(void)
{
	CC->SwitchDisplay();
}

MGLAPI void mglUnlockDisplay(void)
{
	CC->UnlockDisplay();
}

//MGLAPI void mglTexMemStat(GLint *Current, GLint *Peak)
//{
//	MGLTexMemStat(Current, Peak);
//}

MGLAPI void mglSetZOffset(GLfloat offset)
{
	CC->SetZOffset(offset);
}

MGLAPI void glColorTable(GLenum target, GLenum internalformat, GLint width, GLenum format, GLenum type, const GLvoid* data)
{
	CC->GLColorTable(target, internalformat, width, format, type, data);
}

MGLAPI void glColorTableEXT(GLenum target, GLenum internalformat, GLint width, GLenum format, GLenum type, const GLvoid* data)
{
	CC->GLColorTable(target, internalformat, width, format, type, data);
}



/*
** Additional functions for targetted context creation
*/

MGLAPI GLboolean mglLockBack(MGLLockInfo *info)
{
	return CC->LockBack(info);
}


/*
** Functions implementing vertex arras
*/

MGLAPI void glEnableClientState(GLenum cap)
{
	CC->GLEnableClientState(cap);
}

MGLAPI void glDisableClientState(GLenum cap)
{
	CC->GLDisableClientState(cap);
}

MGLAPI void glClientActiveTexture(GLenum texture)
{
	CC->GLClientActiveTexture(texture);
}

MGLAPI void glClientActiveTextureARB(GLenum texture)
{
	CC->GLClientActiveTexture(texture);
}

MGLAPI void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	CC->GLTexCoordPointer(size, type, stride, pointer);
}

MGLAPI void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	CC->GLColorPointer(size, type, stride, pointer);
}

MGLAPI void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
	CC->GLNormalPointer(type, stride, pointer);
}

MGLAPI void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
	CC->GLVertexPointer(size, type, stride, pointer);
}

MGLAPI void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer)
{
	CC->GLInterleavedArrays(format, stride, pointer);
}

MGLAPI void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *pointer)
{
	CC->GLDrawElements(mode, count, type, pointer);
}

MGLAPI void glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
	CC->GLDrawArrays(mode, first, count);
}

MGLAPI void glArrayElement(GLint i)
{
	CC->GLArrayElement(i);
}

MGLAPI void glLockArraysEXT(GLint first, GLsizei count)
{
	CC->GLLockArrays(first, count);
}

MGLAPI void glUnlockArraysEXT(void)
{
	CC->GLUnlockArrays();
}


MGLAPI void glPushAttrib(GLbitfield bits)
{
	CC->GLPushAttrib(bits);
}

MGLAPI void glPopAttrib(void)
{
	CC->GLPopAttrib();
}


/*
** Everything related to multitexturing
*/

MGLAPI void glActiveTextureARB(GLenum unit)
{
	CC->GLActiveTexture(unit);
}

MGLAPI void glMultiTexCoord2fARB(GLenum unit, GLfloat s, GLfloat t)
{
	CC->GLMultiTexCoord2f(unit, s, t);
}

MGLAPI void glMultiTexCoord2fvARB(GLenum unit, const GLfloat *v)
{
	CC->GLMultiTexCoord2f(unit, v[0], v[1]);
}

MGLAPI void glMultiTexCoord4fARB(GLenum unit, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	CC->GLMultiTexCoord4f(unit, s, t, r, q);
}

MGLAPI void glMultiTexCoord4fvARB(GLenum unit, const GLfloat *v)
{
	CC->GLMultiTexCoord4f(unit, v[0], v[1], v[2], v[3]);
}


/*
** Light
*/

MGLAPI void glActiveTexture(GLenum unit)
{
	CC->GLActiveTexture(unit);
}

MGLAPI void glMultiTexCoord2f(GLenum unit, GLfloat s, GLfloat t)
{
	CC->GLMultiTexCoord2f(unit, s, t);
}

MGLAPI void glMultiTexCoord2fv(GLenum unit, const GLfloat *v)
{
	CC->GLMultiTexCoord2f(unit, v[0], v[1]);
}

MGLAPI void glMultiTexCoord4f(GLenum unit, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
{
	CC->GLMultiTexCoord4f(unit, s, t, r, q);
}

MGLAPI void glMultiTexCoord4fv(GLenum unit, const GLfloat *v)
{
	CC->GLMultiTexCoord4f(unit, v[0], v[1], v[2], v[3]);
}

MGLAPI void glMaterialf(GLenum face, GLenum pname, GLfloat param)
{
	CC->GLMaterialf(face, pname, param);
}

MGLAPI void glMateriali(GLenum face, GLenum pname, GLint param)
{
	CC->GLMaterialf(face, pname,(GLfloat)param);
}

MGLAPI void glMaterialfv(GLenum face, GLenum pname, const GLfloat* params)
{
	CC->GLMaterialfv(face, pname, params);
}

MGLAPI void glMaterialiv(GLenum face, GLenum pname, const GLint* params)
{
	CC->GLMaterialiv(face, pname, params);
}

MGLAPI void glGetMaterialiv(GLenum face, GLenum value, GLint *data)
{
	CC->GLGetMaterialiv(face, value, data);
}

MGLAPI void glGetMaterialfv(GLenum face, GLenum value, GLfloat *data)
{
	CC->GLGetMaterialfv(face, value, data);
}

MGLAPI void glLightf(GLenum light, GLenum pname, GLfloat param)
{
	CC->GLLightf(light, pname, param);
}

MGLAPI void glLighti(GLenum light, GLenum pname, GLint param)
{
	CC->GLLightf(light, pname,(GLfloat)param);
}

MGLAPI void glLightfv(GLenum light, GLenum pname, const GLfloat* params)
{
	CC->GLLightfv(light, pname, params);
}

MGLAPI void glLightiv(GLenum light, GLenum pname, const GLint *params)
{
	CC->GLLightiv(light, pname, params);
}

MGLAPI void glLightModelf(GLenum pname, GLfloat param)
{
	CC->GLLightModelf(pname, param);
}

MGLAPI void glLightModeli(GLenum pname, GLint param)
{
	CC->GLLightModelf(pname,(GLfloat)param);
}

MGLAPI void glLightModelfv(GLenum pname, const GLfloat* params)
{
	CC->GLLightModelfv(pname, params);
}

MGLAPI void glLightModeliv(GLenum pname, const GLint* params)
{
	CC->GLLightModeliv(pname, params);
}

MGLAPI void glColorMaterial(GLenum face, GLenum mode)
{
	CC->GLColorMaterial(face, mode);
}

MGLAPI void glGetLightfv(GLenum light, GLenum pname, GLfloat *params)
{
	CC->GLGetLightfv(light, pname, params);
}

MGLAPI void glGetLightiv(GLenum light, GLenum pname, GLint *params)
{
	CC->GLGetLightiv(light, pname, params);
}

/*
** Other
*/

MGLAPI void mglGrabFocus(GLboolean yesno)
{
    CC->GrabFocus(yesno);
}

MGLAPI void glStencilOp(GLenum sfail, GLenum dpfail, GLenum dppass)
{
	CC->GLStencilOp(sfail, dpfail, dppass);
}

MGLAPI void glStencilFunc(GLenum func, GLint ref, GLint mask)
{
	CC->GLStencilFunc(func, ref, mask);
}

MGLAPI void glClearStencil(GLint s)
{
	CC->GLClearStencil(s);
}

MGLAPI void glStencilMask(GLuint mask)
{
	CC->GLStencilMask(mask);
}

MGLAPI void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	CC->GLColorMask(red, green, blue, alpha);
}

MGLAPI void glLineWidth(GLfloat width)
{
	CC->GLLineWidth(width);
}

MGLAPI void glPointSize(GLfloat size)
{
	CC->GLPointSize(size);
}

MGLAPI void glBitmap(GLsizei w, GLsizei h, GLfloat xbo, GLfloat ybo, GLfloat xbi, GLfloat ybi, const GLubyte *data)
{
	CC->GLBitmap(w, h, xbo, ybo, xbi, ybi, data);
}

MGLAPI void glLineStipple(GLint factor, GLushort pattern)
{
	CC->GLLineStipple(factor, pattern);
}

MGLAPI void glPolygonStipple(GLubyte *pattern)
{
	CC->GLPolygonStipple(pattern);
}

MGLAPI void glRasterPos2s(GLshort x, GLshort y)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y, 0.0f, 1.0f);
}

MGLAPI void glRasterPos2i(GLint x, GLint y)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y, 0.0f, 1.0f);
}

MGLAPI void glRasterPos2f(GLfloat x, GLfloat y)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y, 0.0f, 1.0f);
}

MGLAPI void glRasterPos2d(GLdouble x, GLdouble y)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y, 0.0f, 1.0f);
}

MGLAPI void glRasterPos3s(GLshort x, GLshort y, GLshort z)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y,(GLfloat)z, 1.0f);
}

MGLAPI void glRasterPos3i(GLint x, GLint y, GLint z)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y,(GLfloat)z, 1.0f);
}

MGLAPI void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y,(GLfloat)z, 1.0f);
}

MGLAPI void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y,(GLfloat)z, 1.0f);
}

MGLAPI void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);
}

MGLAPI void glRasterPos4i(GLint x, GLint y, GLint z, GLint w)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);
}

MGLAPI void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);
}

MGLAPI void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	CC->GLRasterPos4f((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);
}

MGLAPI void glRasterPos2sv(const GLshort *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1], 0.0f, 1.0f);
}

MGLAPI void glRasterPos2iv(const GLint *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1], 0.0f, 1.0f);
}

MGLAPI void glRasterPos2fv(const GLfloat *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1], 0.0f, 1.0f);
}

MGLAPI void glRasterPos2dv(const GLdouble *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1], 0.0f, 1.0f);
}

MGLAPI void glRasterPos3sv(const GLshort *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2], 1.0f);
}

MGLAPI void glRasterPos3iv(const GLint *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2], 1.0f);
}

MGLAPI void glRasterPos3fv(const GLfloat *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2], 1.0f);
}

MGLAPI void glRasterPos3dv(const GLdouble *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2], 1.0f);
}

MGLAPI void glRasterPos4sv(const GLshort *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]);
}

MGLAPI void glRasterPos4iv(const GLint *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]);
}

MGLAPI void glRasterPos4fv(const GLfloat *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]);
}

MGLAPI void glRasterPos4dv(const GLdouble *v)
{
	CC->GLRasterPos4f((GLfloat)v[0],(GLfloat)v[1],(GLfloat)v[2],(GLfloat)v[3]);
}

MGLAPI void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
	CC->GLDrawPixels(width, height, format, type, pixels);
}

MGLAPI void glCallList(GLuint list)
{
	CC->GLCallList(list);
}

MGLAPI void glCallLists(GLsizei n, GLenum type, const GLvoid *lists)
{
	CC->GLCallLists(n, type, lists);
}

MGLAPI void glDeleteLists(GLuint list, GLsizei range)
{
	CC->GLDeleteLists(list, range);
}

MGLAPI GLuint glGenLists(GLsizei range)
{
	return CC->GLGenLists(range);
}

MGLAPI void glNewList(GLuint list, GLenum mode)
{
	CC->GLNewList(list, mode);
}

MGLAPI void glEndList(void)
{
	CC->GLEndList();
}

MGLAPI GLboolean glIsList(GLuint list){
	return CC->GLIsList(list);
}

MGLAPI void glListBase(GLuint base){
	CC->GLListBase(base);
}

MGLAPI void glGetDoublev(GLenum pname, GLdouble *params)
{
	CC->GLGetDoublev(pname, params);
}

MGLAPI GLboolean glIsTexture(GLuint texture){
	return CC->GLIsTexture(texture);
}

MGLAPI GLboolean glAreTexturesResident(GLsizei n, GLuint* textures, GLboolean* residences)
{
	return CC->GLAreTexturesResident(n, textures, residences);
}

MGLAPI void glInitNames(){
	CC->GLInitNames();
}

MGLAPI void glLoadName(GLuint name){
	CC->GLLoadName(name);
}

MGLAPI void glPushName(GLuint name){
	CC->GLPushName(name);
}

MGLAPI void glPopName(){
	CC->GLPopName();
}

MGLAPI void glSelectBuffer(GLsizei size, GLuint *buffer){
	CC->GLSelectBuffer(size, buffer);
}

MGLAPI GLint glRenderMode(GLenum mode){
	return CC->GLRenderMode(mode);
}


MGLAPI void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params)
{
	CC->GLGetTexLevelParameterfv(target, level, pname, params);
}

MGLAPI void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params)
{
	CC->GLGetTexLevelParameteriv(target, level, pname, params);
}

/* Evaluators */
MGLAPI void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points)
{
	CC->GLMap1f(target, u1, u2, stride, order, points);
}

MGLAPI void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points)
{
	CC->GLMap1d(target, u1, u2, stride, order, points);
}

MGLAPI void glEvalCoord1f(GLfloat arg)
{
	CC->GLEvalCoord1f(arg);
}

MGLAPI void glEvalCoord1d(GLdouble arg)
{
	CC->GLEvalCoord1f((GLfloat)arg);
}

MGLAPI void glEvalCoord1fv(GLfloat *arg)
{
	CC->GLEvalCoord1f(*arg);
}

MGLAPI void glEvalCoord1dv(GLdouble *arg)
{
	CC->GLEvalCoord1f((GLfloat)*arg);
}

MGLAPI void glMapGrid1f(GLint n, GLfloat u1, GLfloat u2)
{
	CC->GLMapGrid1f(n, u1, u2);
}

MGLAPI void glMapGrid1d(GLint n, GLdouble u1, GLdouble u2)
{
	CC->GLMapGrid1f(n,(GLfloat)u1,(GLfloat)u2);
}

MGLAPI void glEvalMesh1(GLenum mode, GLint p1, GLint p2)
{
	CC->GLEvalMesh1(mode, p1, p2);
}

MGLAPI void glEvalPoint1(GLint p)
{
	CC->GLEvalPoint1(p);
}

MGLAPI void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder,
		GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points)
{
	CC->GLMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

MGLAPI void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder,
		GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points)
{
	CC->GLMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

MGLAPI void glEvalCoord2f(GLfloat u, GLfloat v)
{
	CC->GLEvalCoord2f(u, v);
}

MGLAPI void glEvalCoord2d(GLdouble u, GLdouble v)
{
	CC->GLEvalCoord2f((GLfloat)u,(GLfloat)v);
}

MGLAPI void glEvalCoord2fv(GLfloat *arg)
{
	CC->GLEvalCoord2f(arg[0], arg[1]);
}

MGLAPI void glEvalCoord2dv(GLdouble *arg)
{
	CC->GLEvalCoord2f((GLfloat)arg[0],(GLfloat)arg[1]);
}

MGLAPI void glMapGrid2f(GLint nu, GLfloat u1, GLfloat u2, GLint nv, GLfloat v1, GLfloat v2)
{
	CC->GLMapGrid2f(nu, u1, u2, nv, v1, v2);
}

MGLAPI void glMapGrid2d(GLint nu, GLdouble u1, GLdouble u2, GLint nv, GLdouble v1, GLdouble v2)
{
	CC->GLMapGrid2f(nu,(GLfloat)u1,(GLfloat)u2, nv,(GLfloat)v1,(GLfloat)v2);
}

MGLAPI void glEvalMesh2(GLenum mode, GLint p1, GLint p2, GLint q1, GLint q2)
{
	CC->GLEvalMesh2(mode, p1, p2, q1, q2);
}

MGLAPI void glEvalPoint2(GLint p, GLint q)
{
	CC->GLEvalPoint2(p, q);
}

MGLAPI void glGetMapfv(GLenum map, GLenum value, GLfloat *data)
{
	CC->GLGetMapfv(map, value, data);
}

MGLAPI void glGetMapdv(GLenum map, GLenum value, GLdouble *data)
{
	CC->GLGetMapdv(map, value, data);
}

MGLAPI void glGetMapiv(GLenum map, GLenum value, GLint *data)
{
	CC->GLGetMapiv(map, value, data);
}

MGLAPI void glPushClientAttrib(GLbitfield bits)
{
	CC->GLPushClientAttrib(bits);
}

MGLAPI void glPopClientAttrib(void)
{
	CC->GLPopClientAttrib();
}


MGLAPI void glPixelTransferi(GLenum param, GLint value)
{
	CC->GLPixelTransferf(param,(GLfloat)value);
}

MGLAPI void glPixelTransferf(GLenum param, GLfloat value)
{
	CC->GLPixelTransferf(param, value);
}

MGLAPI void glGetTexImage(GLenum target, GLint lod, GLenum format, GLenum type,
		GLvoid *pixels)
{
	CC->GLGetTexImage(target, lod, format, type, pixels);
}

MGLAPI void glCopyTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y,
								 GLsizei width,  GLint border)
{
	CC->GLCopyTexImage1D(target, level, internalFormat, x, y, width, border);
}

MGLAPI void glCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y,
								 GLsizei width, GLsizei height, GLint border)
{
	CC->GLCopyTexImage2D(target, level, internalFormat, x, y, width, height, border);
}

MGLAPI void glCopyTexSubImage1D(GLenum target, GLint level,	GLint xoffset, GLint x, GLint y,
								 GLsizei width)
{
	CC->GLCopyTexSubImage1D(target, level, xoffset, x, y, width);
}

MGLAPI void glCopyTexSubImage2D(GLenum target, GLint level,	GLint xoffset, GLint yoffset, GLint x, GLint y,
								 GLsizei width, GLsizei height)
{
	CC->GLCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

/* -------------------- Unsupported stubs -------------------- */
MGLAPI void glEdgeFlag(GLboolean edge)
{
}


MGLAPI void glReadBuffer(GLenum mode)
{
	CC->GLReadBuffer(mode);
}

MGLAPI void mglSetFrontBuffer(void *bitmap)
{
	CC->MGLSetFrontBuffer(bitmap);
}

MGLAPI void mglSetBackBuffer(void *bitmap)
{
	CC->MGLSetBackBuffer(bitmap);
}

MGLAPI GLboolean mglSetAuxBuffer(GLenum buffer, void *bitmap)
{
	return CC->MGLSetAuxBuffer(buffer, bitmap);
}

MGLAPI void glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities)
{
	/* Ignored */
}

extern void *MGLGetProcAddress(const char *name);

MGLAPI void *mglGetProcAddress(const char *name)
{
	return(void *)MGLGetProcAddress(name);
}

/* Render Targets and texture pinning */

MGLAPI void mglPinTexture(GLuint texnum)
{
	CC->PinTexture(texnum);
}

MGLAPI void mglUnpinTexture(GLuint texnum)
{
	CC->UnpinTexture(texnum);
}

MGLAPI void mglSetTextureRenderTarget(GLuint texnum)
{
	CC->SetTextureRenderTarget(texnum);
}

MGLAPI void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices)
{
	CC->GLDrawRangeElements(mode, start, end, count, type, indices);
}

MGLAPI void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex)
{
	CC->GLDrawElementsBaseVertex(mode, count, type, indices, basevertex);
}

MGLAPI void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices, GLint basevertex)
{
	CC->GLDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
}

MGLAPI void glGetClipPlane(GLenum plane, GLdouble *eqn)
{
	CC->GLGetClipPlane(plane, eqn);
}

/* Vertex Buffer Objects */

MGLAPI void glGenBuffers(GLsizei n, GLuint *buffers)
{
	CC->GLGenBuffers(n, buffers);
}

MGLAPI void glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
	CC->GLDeleteBuffers(n, buffers);
}

MGLAPI void glBindBuffer(GLenum target, GLuint buffer)
{
	CC->GLBindBuffer(target, buffer);
}

MGLAPI void glBufferSubData(GLenum target, GLint offset, GLsizei size, const GLvoid *data)
{
	CC->GLBufferSubData(target, offset, size, data);
}

MGLAPI void glBufferData(GLenum target, GLsizei size, const GLvoid *data, GLenum usage)
{
	CC->GLBufferData(target, size, data, usage);
}

MGLAPI void glGetBufferSubData(GLenum target, GLint offset, GLsizei size, GLvoid *data)
{
	CC->GLGetBufferSubData(target, offset, size, data);
}

MGLAPI void *glMapBuffer(GLenum target, GLenum access)
{
	return CC->GLMapBuffer(target, access);
}

MGLAPI void *glMapBufferRange(GLenum target, GLint offset, GLsizei length, GLbitfield access)
{
	return CC->GLMapBufferRange(target, offset, length, access);
}

MGLAPI GLboolean glUnmapBuffer(GLenum target)
{
	return CC->GLUnmapBuffer(target);
}

MGLAPI void glGetBufferParameteriv(GLenum target, GLenum value, GLint *data)
{
	CC->GLGetBufferParameteriv(target, value, data);
}

MGLAPI void glGenBuffersARB(GLsizei n, GLuint *buffers)
{
	CC->GLGenBuffers(n, buffers);
}

MGLAPI void glDeleteBuffersARB(GLsizei n, const GLuint *buffers)
{
	CC->GLDeleteBuffers(n, buffers);
}

MGLAPI void glBindBufferARB(GLenum target, GLuint buffer)
{
	CC->GLBindBuffer(target, buffer);
}

MGLAPI void glBufferSubDataARB(GLenum target, GLint offset, GLsizei size, const GLvoid *data)
{
	CC->GLBufferSubData(target, offset, size, data);
}

MGLAPI void glBufferDataARB(GLenum target, GLsizei size, const GLvoid *data, GLenum usage)
{
	CC->GLBufferData(target, size, data, usage);
}

MGLAPI void glGetBufferSubDataARB(GLenum target, GLint offset, GLsizei size, GLvoid *data)
{
	CC->GLGetBufferSubData(target, offset, size, data);
}

MGLAPI void *glMapBufferARB(GLenum target, GLenum access)
{
	return CC->GLMapBuffer(target, access);
}

MGLAPI GLboolean glUnmapBufferARB(GLenum target)
{
	return CC->GLUnmapBuffer(target);
}

MGLAPI void glGetBufferParameterivARB(GLenum target, GLenum value, GLint *data)
{
	CC->GLGetBufferParameteriv(target, value, data);
}

/* --------------------------- glu --------------------------- */
MGLAPI GLUtesselator* gluNewTess(void)
{
	return CC->GLUNewTess();
}

MGLAPI void gluDeleteTess(GLUtesselator* tess)
{
	CC->GLUDeleteTess(tess);
}

MGLAPI void gluTessProperty(GLUtesselator* tess, GLenum which, GLdouble data)
{
	CC->GLUTessProperty(tess, which, data);
}

MGLAPI void gluGetTessProperty(GLUtesselator* tess, GLenum which, GLdouble* data)
{
	CC->GLUGetTessProperty(tess, which, data);
}

MGLAPI void gluTessNormal(GLUtesselator* tess, GLdouble X, GLdouble Y, GLdouble Z)
{
	CC->GLUTessNormal(tess, X, Y, Z);
}


MGLAPI void gluTessCallback(GLUtesselator* tess, GLenum which, _GLUfuncptr CallBackFunc)
{
	CC->GLUTessCallback(tess, which, (void *)CallBackFunc);
}

MGLAPI void gluTessVertex(GLUtesselator* tess, GLdouble *location, GLvoid* data)
{
	CC->GLUTessVertex(tess, location, data);
}

MGLAPI void gluTessBeginPolygon(GLUtesselator* tess, GLvoid* data)
{
	CC->GLUTessBeginPolygon(tess, data);
}

MGLAPI void gluTessBeginContour(GLUtesselator* tess)
{
	CC->GLUTessBeginContour(tess);
}

MGLAPI void gluTessEndContour(GLUtesselator* tess)
{
	CC->GLUTessEndContour(tess);
}

MGLAPI void gluTessEndPolygon(GLUtesselator* tess)
{
	CC->GLUTessEndPolygon(tess);
}

MGLAPI void gluBeginPolygon(GLUtesselator* tess)
{
	CC->GLUBeginPolygon(tess);
}

MGLAPI void gluNextContour(GLUtesselator* tess, GLenum type)
{
	CC->GLUNextContour(tess, type);
}

MGLAPI void gluEndPolygon(GLUtesselator* tess)
{
	CC->GLUEndPolygon(tess);
}

MGLAPI const GLubyte *gluErrorString(GLenum error)
{
	return CC->GLUErrorString(error);
}


MGLAPI GLint gluScaleImage(GLenum format, GLsizei wIn, GLsizei hIn, GLenum typeIn,
		const void *dataIn, GLsizei wOut, GLsizei hOut, GLenum typeOut, GLvoid* dataOut)
{
	return CC->GLUScaleImage(format, wIn, hIn, typeIn, dataIn, wOut, hOut, typeOut, dataOut);
}

MGLAPI GLint gluBuild2DMipmapLevels(GLenum target, GLint internalFormat,
		GLsizei width, GLsizei height, GLenum format, GLenum type, GLint level,
		GLint base, GLint max, const void *data)
{
	return CC->GLUBuild2DMipmapLevels(target, internalFormat, width, height, format, type, level, base, max, data);
}

MGLAPI GLint gluBuild2DMipmaps(GLenum target, GLint internalFormat, GLsizei width,
		GLsizei height, GLenum format, GLenum type, const void *data)
{
	return CC->GLUBuild2DMipmaps(target, internalFormat, width, height, format, type, data);
}

MGLAPI void gluOrtho2D(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top)
{
	CC->GLUOrtho2D(left, right, bottom, top);
}

MGLAPI void gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
	CC->GLUPerspective(fovy, aspect, zNear, zFar);
}

MGLAPI void gluLookAt(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ,
		GLdouble centerX, GLdouble centerY, GLdouble centerZ,
		GLdouble upX, GLdouble upY, GLdouble upZ)
{
	CC->GLULookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
}

MGLAPI GLint gluProject(GLdouble objX, GLdouble objY, GLdouble objZ,
		const GLdouble *model, const GLdouble *proj, const GLint *view,
		GLdouble* winX, GLdouble* winY, GLdouble* winZ)
{
	return CC->GLUProject(objX, objY, objZ, model, proj, view, winX, winY, winZ);
}


MGLAPI GLint gluUnProject(GLdouble winX, GLdouble winY, GLdouble winZ,
		const GLdouble *model, const GLdouble *proj, const GLint *view,
		GLdouble* objX, GLdouble* objY, GLdouble* objZ)
{
	return CC->GLUUnProject(winY, winY, winZ, model, proj, view, objX, objY, objZ);
}


MGLAPI GLint gluUnProject4(GLdouble winX, GLdouble winY, GLdouble winZ,
		GLdouble clipW, const GLdouble *model, const GLdouble *proj,
		const GLint *view, GLdouble nearVal, GLdouble farVal,
		GLdouble* objX, GLdouble* objY, GLdouble* objZ, GLdouble* objW)
{
	return CC->GLUUnProject4(winX, winY, winZ, clipW, model, proj, view,
			nearVal, farVal, objX, objY, objZ, objW);
}

MGLAPI void gluPickMatrix(GLdouble x, GLdouble y, GLdouble delX, GLdouble delY, GLint *viewport)
{
	CC->GLUPickMatrix(x, y, delX, delY, viewport);
}

MGLAPI GLUquadric* gluNewQuadric(void)
{
	return CC->GLUNewQuadric();
}

MGLAPI void gluDeleteQuadric(GLUquadric* quad)
{
	CC->GLUDeleteQuadric(quad);
}


MGLAPI void  gluQuadricCallback(GLUquadric* quad, GLenum which, _GLUfuncptr CallBackFunc)
{
	CC->GLUQuadricCallback(quad, which, (void *)CallBackFunc);
}

MGLAPI void gluQuadricNormals(GLUquadric* quad, GLenum normal)
{
	CC->GLUQuadricNormals(quad, normal);
}

MGLAPI void gluQuadricTexture(GLUquadric* quad, GLboolean texture)
{
	CC->GLUQuadricTexture(quad, texture);
}

MGLAPI void gluQuadricOrientation(GLUquadric* quad, GLenum orientation)
{
	CC->GLUQuadricOrientation(quad, orientation);
}

MGLAPI void gluQuadricDrawStyle(GLUquadric* quad, GLenum draw)
{
	CC->GLUQuadricDrawStyle(quad, draw);
}


MGLAPI void gluCylinder(GLUquadric* quad, GLdouble base, GLdouble top,
		GLdouble height, GLint slices, GLint stacks)
{
	CC->GLUCylinder(quad, base, top, height, slices, stacks);
}

MGLAPI void gluDisk(GLUquadric* quad, GLdouble inner, GLdouble outer, GLint slices, GLint loops)
{
	CC->GLUDisk(quad, inner, outer, slices, loops);
}


MGLAPI void gluPartialDisk(GLUquadric* quad, GLdouble inner, GLdouble outer,
		GLint slices, GLint loops, GLdouble start, GLdouble sweep)
{
	CC->GLUPartialDisk(quad, inner, outer, slices, loops, start, sweep);
}

MGLAPI void gluSphere(GLUquadric* quad, GLdouble radius, GLint slices, GLint stacks)
{
	CC->GLUSphere(quad, radius, slices, stacks);
}

MGLAPI const GLubyte * gluGetString(GLenum name)
{
	return CC->GLUGetString(name);
}

MGLAPI GLboolean gluCheckExtension(const GLubyte *extName, const GLubyte *extString)
{
	return CC->GLUCheckExtension(extName, extString);
}

MGLAPI void gluNurbsCallbackData(GLUnurbs* r, void* userData)
{
	CC->GLUNurbsCallbackDataEXT(r,userData);
}

MGLAPI void gluBeginCurve(GLUnurbs* nurb)
{
	CC->GLUBeginCurve(nurb);
}

MGLAPI void gluBeginSurface(GLUnurbs* nurb)
{
	CC->GLUBeginSurface(nurb);
}

MGLAPI void gluBeginTrim(GLUnurbs* nurb)
{
	CC->GLUBeginTrim(nurb);
}

MGLAPI void gluDeleteNurbsRenderer(GLUnurbs* nurb)
{
	CC->GLUDeleteNurbsRenderer(nurb);
}

MGLAPI void gluEndCurve(GLUnurbs* nurb)
{
	CC->GLUEndCurve(nurb);
}

MGLAPI void gluEndSurface(GLUnurbs* nurb)
{
	CC->GLUEndSurface(nurb);
}

MGLAPI void gluEndTrim(GLUnurbs* nurb)
{
	CC->GLUEndTrim(nurb);
}

MGLAPI void gluGetNurbsProperty(GLUnurbs* nurb, GLenum property, GLfloat* data)
{
	CC->GLUGetNurbsProperty(nurb, property, data);
}

MGLAPI void gluLoadSamplingMatrices(GLUnurbs* nurb, const GLfloat *model, const GLfloat *perspective, const GLint *view)
{
	CC->GLULoadSamplingMatrices(nurb, model, perspective, view);
}

MGLAPI GLUnurbs* gluNewNurbsRenderer(void)
{
	return CC->GLUNewNurbsRenderer();
}


MGLAPI void gluNurbsCallback(GLUnurbs* nurb, GLenum which, _GLUfuncptr CallBackFunc)
{
	CC->GLUNurbsCallback(nurb, which, (void*)CallBackFunc);
}

MGLAPI void gluNurbsCallbackDataEXT(GLUnurbs* nurb, GLvoid* userData)
{
	CC->GLUNurbsCallbackDataEXT(nurb, userData);
}

MGLAPI void gluNurbsCurve(GLUnurbs* nurb, GLint knotCount, GLfloat *knots, GLint stride,
		GLfloat *control, GLint order, GLenum type)
{
	CC->GLUNurbsCurve(nurb, knotCount, knots, stride, control, order, type);
}

MGLAPI void gluNurbsProperty(GLUnurbs* nurb, GLenum property, GLfloat value)
{
	CC->GLUNurbsProperty(nurb, property, value);
}

MGLAPI void gluNurbsSurface(GLUnurbs* nurb, GLint sKnotCount, GLfloat* sKnots,
		GLint tKnotCount, GLfloat* tKnots, GLint sStride, GLint tStride,
		GLfloat* control, GLint sOrder, GLint tOrder, GLenum type)
{
	CC->GLUNurbsSurface(nurb, sKnotCount, sKnots, tKnotCount, tKnots,
			sStride, tStride, control, sOrder, tOrder, type);
}

MGLAPI void gluPwlCurve(GLUnurbs* nurb, GLint count, GLfloat* data, GLint stride, GLenum type)
{
	CC->GLUPwlCurve(nurb, count, data, stride, type);
}

MGLAPI void glGetTexParameteriv(GLenum target, GLenum value, GLint *data)
{
	CC->GLGetTexParameteriv(target, value, data);
}

MGLAPI void glGetTexParameterfv(GLenum target, GLenum value, GLfloat *data)
{
	CC->GLGetTexParameterfv(target, value, data);
}

MGLAPI void glPixelZoom(GLfloat zoomx, GLfloat zoomy)
{
	CC->GLPixelZoom(zoomx, zoomy);
}

MGLAPI void glLogicOp(GLenum opcode)
{
	CC->GLLogicOp(opcode);
}

MGLAPI void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type)
{
	CC->GLCopyPixels(x, y, width, height, type);
}

#ifdef __cplusplus
}
#endif

#endif
