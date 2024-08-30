#ifndef	TINYGL_GLU
#define	TINYGL_GLU

#include <tgl/gl.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Boolean */
#define GLU_FALSE                          0
#define GLU_TRUE                           1

/* ErrorCode */
#define GLU_INVALID_ENUM                   100900
#define GLU_INVALID_VALUE                  100901
#define GLU_OUT_OF_MEMORY                  100902
#define GLU_INVALID_OPERATION              100904

#define GLU_ERROR                          100103
#define GLU_NO_ERROR                       GL_NO_ERROR

/* TessCallback */
#define GLU_TESS_BEGIN                     100100
#define GLU_BEGIN                          100100
#define GLU_TESS_VERTEX                    100101
#define GLU_VERTEX                         100101
#define GLU_TESS_END                       100102
#define GLU_END                            100102
#define GLU_TESS_ERROR                     100103
#define GLU_TESS_EDGE_FLAG                 100104
#define GLU_EDGE_FLAG                      100104
#define GLU_TESS_COMBINE                   100105
#define GLU_TESS_BEGIN_DATA                100106
#define GLU_TESS_VERTEX_DATA               100107
#define GLU_TESS_END_DATA                  100108
#define GLU_TESS_ERROR_DATA                100109
#define GLU_TESS_EDGE_FLAG_DATA            100110
#define GLU_TESS_COMBINE_DATA              100111

/* TessContour */
#define GLU_CW                             100120
#define GLU_CCW                            100121
#define GLU_INTERIOR                       100122
#define GLU_EXTERIOR                       100123
#define GLU_UNKNOWN                        100124

/* TessProperty */
#define GLU_TESS_WINDING_RULE              100140
#define GLU_TESS_BOUNDARY_ONLY             100141
#define GLU_TESS_TOLERANCE                 100142

/* TessError */
#define GLU_TESS_ERROR1                    100151
#define GLU_TESS_ERROR2                    100152
#define GLU_TESS_ERROR3                    100153
#define GLU_TESS_ERROR4                    100154
#define GLU_TESS_ERROR5                    100155
#define GLU_TESS_ERROR6                    100156
#define GLU_TESS_ERROR7                    100157
#define GLU_TESS_ERROR8                    100158
#define GLU_TESS_MISSING_BEGIN_POLYGON     100151
#define GLU_TESS_MISSING_BEGIN_CONTOUR     100152
#define GLU_TESS_MISSING_END_POLYGON       100153
#define GLU_TESS_MISSING_END_CONTOUR       100154
#define GLU_TESS_COORD_TOO_LARGE           100155
#define GLU_TESS_NEED_COMBINE_CALLBACK     100156

/* TessWinding */
#define GLU_TESS_WINDING_ODD               100130
#define GLU_TESS_WINDING_NONZERO           100131
#define GLU_TESS_WINDING_POSITIVE          100132
#define GLU_TESS_WINDING_NEGATIVE          100133
#define GLU_TESS_WINDING_ABS_GEQ_TWO       100134

/* QuadricDrawStyle */
#define GLU_POINT                          100010
#define GLU_LINE                           100011
#define GLU_FILL                           100012
#define GLU_SILHOUETTE                     100013

/* QuadricNormal */
#define GLU_SMOOTH                         100000
#define GLU_FLAT                           100001
#define GLU_NONE                           100002

/* QuadricOrientation */
#define GLU_OUTSIDE                        100020
#define GLU_INSIDE                         100021


#ifdef __cplusplus
class GLUnurbs;
class GLUquadric;
class GLUtesselator;
#else
typedef struct GLUnurbs GLUnurbs;
typedef struct GLUquadric GLUquadric;
typedef struct GLUtesselator GLUtesselator;
#endif

typedef GLUnurbs GLUnurbsObj;
typedef GLUquadric GLUquadricObj;
typedef GLUtesselator GLUtesselatorObj;
typedef GLUtesselator GLUtriangulatorObj;

#define GLU_TESS_MAX_COORD 1.0e150

#ifndef GLAPIENTRY
#define GLAPIENTRY
#endif

#ifndef GLAPIENTRYP
#define GLAPIENTRYP GLAPIENTRY *
#endif

typedef void (GLAPIENTRY *_GLUfuncptr)();

void gluBeginPolygon (GLUtesselator* tess);
void gluDeleteTess (GLUtesselator* tess);
void gluEndPolygon (GLUtesselator* tess);
void gluGetTessProperty (GLUtesselator* tess, GLenum which, GLdouble* data);
struct GLUtesselator* gluNewTess (void);
void gluNextContour (GLUtesselator* tess, GLenum type);

void gluTessBeginContour (GLUtesselator* tess);
void gluTessBeginPolygon (GLUtesselator* tess, GLvoid* data);
void gluTessCallback (GLUtesselator* tess, GLenum which, _GLUfuncptr CallBackFunc);
void gluTessEndContour (GLUtesselator* tess);
void gluTessEndPolygon (GLUtesselator* tess);
void gluTessNormal (GLUtesselator* tess, GLdouble valueX, GLdouble valueY, GLdouble valueZ);
void gluTessProperty (GLUtesselator* tess, GLenum which, GLdouble data);
void gluTessVertex (GLUtesselator* tess, GLdouble *location, GLvoid* data);

void gluCylinder (GLUquadric* quad, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);
void gluSphere (GLUquadric* quad, GLdouble radius, GLint slices, GLint stacks);
GLUquadric* gluNewQuadric (void);
void gluQuadricTexture (GLUquadric* quad, GLboolean texture);
void gluQuadricOrientation (GLUquadric* quad, GLenum orientation);
void gluQuadricDrawStyle(GLUquadricObj * quadObject, GLenum drawStyle);
void gluQuadricNormals(GLUquadricObj * quadObject, GLenum normals);

void gluDeleteQuadric (GLUquadric* quad);
void gluCylinder (GLUquadric* quad, GLdouble base, GLdouble top, GLdouble height, GLint slices, GLint stacks);
void gluDisk (GLUquadric* quad, GLdouble inner, GLdouble outer, GLint slices, GLint loops);
void gluPartialDisk(GLUquadricObj * qobj, GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops, GLdouble startAngle, GLdouble sweepAngle);

GLint gluProject (GLdouble objX, GLdouble objY, GLdouble objZ,const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble* winX,GLdouble* winY, GLdouble* winZ);
GLint gluUnProject (GLdouble winX, GLdouble winY, GLdouble winZ, const GLdouble *model, const GLdouble *proj, const GLint *view, GLdouble* objX, GLdouble* objY, GLdouble* objZ);

GLint gluBuild2DMipmaps(GLenum target, GLint components, GLsizei width, GLsizei height, GLenum format,GLenum type, void *data);
GLint gluScaleImage(GLenum format, GLsizei widthin, GLsizei heightin,GLenum typein, const void *datain,GLsizei widthout, GLsizei heightout,GLenum typeout, void *dataout);

/* GLU functions built into tinygl.library */

#ifdef _NO_PPCINLINE

void gluPerspective(GLfloat fovy, GLfloat aspect,GLfloat zNear, GLfloat zFar);
void gluPickMatrix(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLint viewport[4]);

void gluLookAt(GLfloat cx, GLfloat cy, GLfloat cz,
               GLfloat ox, GLfloat oy, GLfloat oz,
               GLfloat ux, GLfloat uy, GLfloat uz);

void gluOrtho2D(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top);

const GLubyte *gluErrorString(GLenum error);

#else

void GLUPerspective(GLContext *context, GLfloat fovy, GLfloat aspect,GLfloat zNear, GLfloat zFar);
void GLUPickMatrix(GLContext *c, GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLint viewport[4]);

void GLULookAt(GLContext *context, GLfloat cx, GLfloat cy, GLfloat cz,
                                   GLfloat ox, GLfloat oy, GLfloat oz,
                                   GLfloat ux, GLfloat uy, GLfloat uz);

#define	gluLookAt(ex, ey, ez, cx, cy, cz, ux, uy, uz) GLULookAt( __tglContext , ex, ey, ez, cx, cy, cz, ux, uy, uz)
#define	gluPerspective(fovy, aspect, znear, zfar) GLUPerspective( __tglContext , fovy, aspect, znear, zfar)
#define gluPickMatrix(x, y, width, height, viewport) GLUPickMatrix( __tglContext, x, y, width, height, viewport )
#define	gluOrtho2D(left, right, bottom, top) glOrtho(left, right, bottom, top, -1.0, 1.0)

/* dummy added by Yomgui */
#define gluErrorString(x) (GLubyte *)"<gluErrorString() not implemented>"

#endif /* _NO_PPCINLINE */

#ifdef __cplusplus
}
#endif

#endif /* TINYGL_GLU */

