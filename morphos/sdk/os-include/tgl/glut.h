#ifndef GLUT_H
#define GLUT_H

#include <tgl/gl.h>
#include <tgl/glu.h>
#include <tgl/gla.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Mouse buttons */
#define GLUT_LEFT_BUTTON   0
#define GLUT_MIDDLE_BUTTON 1
#define GLUT_RIGHT_BUTTON  2

/* Mouse button state */
#define GLUT_DOWN          0
#define GLUT_UP            1

/* function keys */
#define GLUT_KEY_F1        1
#define GLUT_KEY_F2        2
#define GLUT_KEY_F3        3
#define GLUT_KEY_F4        4
#define GLUT_KEY_F5        5
#define GLUT_KEY_F6        6
#define GLUT_KEY_F7        7
#define GLUT_KEY_F8        8
#define GLUT_KEY_F9        9
#define GLUT_KEY_F10       10
#define GLUT_KEY_F11       11
#define GLUT_KEY_F12       12
/* directional keys */
#define GLUT_KEY_LEFT      100
#define GLUT_KEY_UP        101
#define GLUT_KEY_RIGHT     102
#define GLUT_KEY_DOWN      103
#define GLUT_KEY_PAGE_UP   104
#define GLUT_KEY_PAGE_DOWN 105
#define GLUT_KEY_HOME      106
#define GLUT_KEY_END       107
#define GLUT_KEY_INSERT    108

/* Entry/exit  state */
#define GLUT_LEFT          0
#define GLUT_ENTERED       1

/* Visibility state */
#define GLUT_NOT_VISIBLE   0
#define GLUT_VISIBLE       1

/* Display mode bit masks. */
#define GLUT_RGB           0
#define GLUT_RGBA          GLUT_RGB
#define GLUT_INDEX         1
#define GLUT_SINGLE        0
#define GLUT_DOUBLE        2
#define GLUT_ACCUM         4
#define GLUT_ALPHA         8
#define GLUT_DEPTH         16
#define GLUT_STENCIL       32
#define GLUT_MULTISAMPLE   128
#define GLUT_STEREO        256
#define GLUT_LUMINANCE     512

/* glutGet parameters */
#define GLUT_WINDOW_X            100
#define GLUT_WINDOW_Y            101
#define GLUT_WINDOW_WIDTH        102
#define GLUT_WINDOW_HEIGHT       103
#define GLUT_WINDOW_DEPTH_SIZE   106
#define GLUT_WINDOW_DOUBLEBUFFER 115
#define GLUT_WINDOW_PARENT       117
#define GLUT_WINDOW_NUM_CHILDREN 118
#define GLUT_SCREEN_WIDTH        200
#define GLUT_SCREEN_HEIGHT       201
#define GLUT_SCREEN_WIDTH_MM     202
#define GLUT_SCREEN_HEIGHT_MM    203
#define GLUT_INIT_WINDOW_X       500
#define GLUT_INIT_WINDOW_Y       501
#define GLUT_INIT_WINDOW_WIDTH   502
#define GLUT_INIT_WINDOW_HEIGHT  503
#define GLUT_ELAPSED_TIME        700

/* glutGetModifiers return mask */
#define GLUT_ACTIVE_SHIFT        1
#define GLUT_ACTIVE_CTRL         2
#define GLUT_ACTIVE_ALT          4

/* Stroke font constants (use these in GLUT program) */
#define GLUT_STROKE_ROMAN      ((void*)0)
#define GLUT_STROKE_MONO_ROMAN ((void*)1)

/* Bitmap font constants (use these in GLUT program) */
#define GLUT_BITMAP_9_BY_15        ((void*)2)
#define GLUT_BITMAP_8_BY_13        ((void*)3)
#define GLUT_BITMAP_TIMES_ROMAN_10 ((void*)4)
#define GLUT_BITMAP_TIMES_ROMAN_24 ((void*)5)
#define GLUT_BITMAP_HELVETICA_10   ((void*)6)
#define GLUT_BITMAP_HELVETICA_12   ((void*)7)
#define GLUT_BITMAP_HELVETICA_18   ((void*)8)


#ifdef _NO_PPCINLINE

void glutInit(int *argcp, char **argv);
void glutInitWindowPosition(int x, int y);
void glutInitWindowSize(int width, int height);
int glutCreateWindow(char *name);
void glutFullScreen(void);
void glutSetWindow(int win);
int glutGetWindow(void);
void glutDestroyWindow(int win);
void glutSwapBuffers(void);
void glutMainLoop(void);
void glutPostRedisplay(void);
void glutDisplayFunc(void (*func)(void));
void glutReshapeFunc(void (*func)(int width, int height));
void glutIdleFunc(void (*func)(void));
void glutKeyboardFunc(void (*func)(unsigned char key, int x, int y));
void glutKeyboardUpFunc (void (*func)(unsigned char key, int x, int y));
void glutMouseFunc(void (*func)(int button, int state, int x, int y));
void glutMotionFunc(void (*func)(int x, int y));
void glutPassiveMotionFunc(void (*func)(int x, int y));
void glutSpecialFunc(void (*func)(int key, int x, int y));
void glutSpecialUpFunc(void (*func)(int key, int x, int y));
void glutTimerFunc(int time, void (*func)(int value), int value);
void glutEntryFunc(void (*func)(int state));
void glutVisibilityFunc(void (*func)(int state));
void glutShowWindow(void);
void glutHideWindow(void);
void glutPositionWindow(int x, int y);
void glutReshapeWindow(int width, int height);
int	glutGet(GLenum state);
int	glutGetModifiers(void);

void *glutGetWindowHandle(GLContext *c);

void glutInitDisplayMode(unsigned int mode);

#else

/* API Calls */
void GLUTInit(GLContext *context, int *argcp, char **argv);
void GLUTInitWindowPosition(GLContext *context, int x, int y);
void GLUTInitWindowSize(GLContext *context, int width, int height);
int GLUTCreateWindow(GLContext *context, char *name);
void GLUTFullScreen(GLContext *context);
void GLUTSetWindow(GLContext *context, int win);
int GLUTGetWindow(GLContext *context);
void GLUTDestroyWindow(GLContext *context, int win);
void GLUTSwapBuffers(GLContext *context);
void GLUTMainLoop(GLContext *context);
void GLUTPostRedisplay(GLContext *context);
void GLUTDisplayFunc(GLContext *context, void (*func)(void));
void GLUTReshapeFunc(GLContext *context, void (*func)(int width, int height));
void GLUTIdleFunc(GLContext *context, void (*func)(void));
void GLUTKeyboardFunc(GLContext *context, void (*func)(unsigned char key, int x, int y));
void GLUTKeyboardUpFunc (GLContext *context, void (*func)(unsigned char key, int x, int y));
void GLUTMouseFunc(GLContext *context, void (*func)(int button, int state, int x, int y));
void GLUTMotionFunc(GLContext *context, void (*func)(int x, int y));
void GLUTPassiveMotionFunc(GLContext *context, void (*func)(int x, int y));
void GLUTSpecialFunc(GLContext *context, void (*func)(int key, int x, int y));
void GLUTSpecialUpFunc(GLContext *context, void (*func)(int key, int x, int y));
void GLUTTimerFunc(GLContext *context, int time, void (*func)(int value), int value);
void GLUTEntryFunc(GLContext *context, void (*func)(int state));
void GLUTVisibilityFunc(GLContext  *context, void (*func)(int state));
void GLUTShowWindow(GLContext *context);
void GLUTHideWindow(GLContext *context);
void GLUTPositionWindow(GLContext *context, int x, int y);
void GLUTReshapeWindow(GLContext *context, int width, int height);
int	GLUTGet(GLContext *context, GLenum state);
int	GLUTGetModifiers(GLContext *context);

void *GLUTGetWindowHandle(GLContext *c);



/* Not implemented */
void GLUTInitDisplayMode(GLContext *context, unsigned int mode);

#define	glutInit(argc, argv)              GLUTInit(__tglContext, argc, argv)
#define	glutInitWindowPosition(x, y)      GLUTInitWindowPosition(__tglContext, x, y)
#define	glutInitWindowSize(width, height) GLUTInitWindowSize(__tglContext, width, height)
#define	glutCreateWindow(name)            GLUTCreateWindow(__tglContext, name)
#define	glutFullScreen()                  GLUTFullScreen(__tglContext)
#define	glutSetWindow(win)                GLUTSetWindow(__tglContext, win)
#define	glutGetWindow()                   GLUTGetWindow(__tglContext)
#define	glutDestroyWindow(win)            GLUTDestroyWindow(__tglContext, win)
#define	glutSwapBuffers()                 GLUTSwapBuffers(__tglContext)
#define	glutMainLoop()                    GLUTMainLoop(__tglContext)
#define	glutPostRedisplay()               GLUTPostRedisplay(__tglContext)
#define	glutDisplayFunc(func)             GLUTDisplayFunc(__tglContext, func)
#define	glutReshapeFunc(func)             GLUTReshapeFunc(__tglContext, func )
#define	glutIdleFunc(func)                GLUTIdleFunc(__tglContext, func)
#define	glutKeyboardFunc(func)            GLUTKeyboardFunc(__tglContext, func)
#define	glutKeyboardUpFunc(func)          GLUTKeyboardUpFunc(__tglContext, func)
#define	glutMouseFunc(func)               GLUTMouseFunc(__tglContext, func)
#define	glutMotionFunc(func)              GLUTMotionFunc(__tglContext, func)
#define glutPassiveMotionFunc(func)       GLUTPassiveMotionFunc(__tglContext, func)
#define glutSpecialFunc(func)             GLUTSpecialFunc(__tglContext, func)
#define glutSpecialUpFunc(func)           GLUTSpecialUpFunc(__tglContext, func)
#define glutVisibilityFunc(func)          GLUTVisibilityFunc(__tglContext, func)
#define	glutTimerFunc(time, func, val)    GLUTTimerFunc(__tglContext, time, func, val)
#define	glutEntryFunc(func)               GLUTEntryFunc(__tglContext, func)
#define	glutShowWindow()                  GLUTShowWindow(__tglContext)
#define	glutHideWindow()                  GLUTHideWindow(__tglContext)
#define	glutPositionWindow(x, y)          GLUTPositionWindow(__tglContext, x, y)
#define	glutReshapeWindow(w, h)           GLUTReshapeWindow(__tglContext, w, h)
#define	glutGet(state)                    GLUTGet(__tglContext, state)
#define	glutInitDisplayMode(mode)         GLUTInitDisplayMode(__tglContext, mode)
#define	glutGetModifiers()                GLUTGetModifiers(__tglContext)
#define	glutGetWindowHandle()             GLUTGetWindowHandle(__tglContext)

#endif /* _NO_PPCINLINE */

/* functions which reside in libtinyglut.a linked library */

void glutBitmapCharacter(void *font, int character);
int glutBitmapWidth(void *font, int character);
void glutStrokeCharacter(void *font, int character);
int glutStrokeWidth(void *font, int character);
int glutBitmapLength(void *font, const unsigned char *string);
int glutStrokeLength(void *font, const unsigned char *string);

void glutWireSphere(GLdouble radius, GLint slices, GLint stacks);
void glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
void glutWireCone(GLdouble base, GLdouble height,GLint slices, GLint stacks);
void glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
void glutWireCube(GLdouble size);
void glutSolidCube(GLdouble size);
void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings);
void glutSolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings);
void glutWireDodecahedron(void);
void glutSolidDodecahedron(void);
void glutWireOctahedron(void);
void glutSolidOctahedron(void);
void glutWireIcosahedron(void);
void glutSolidIcosahedron(void);
void glutWireTetrahedron(void);
void glutSolidTetrahedron(void);

void glutSolidTeapot(GLdouble scale);
void glutWireTeapot(GLdouble scale);

#ifdef __cplusplus
}
#endif

#endif /* GLUT_H */

