#ifndef _GLUT_H_
#define _GLUT_H_

#include <stdlib.h>
#include <stdio.h>

#include <mgl/glutcontext.h>

#include <classes/requester.h>

#ifdef __cplusplus
extern "C" {
#endif
extern void displayWarningReq(struct Window *window, struct Screen *screen,
						const char *title, const char *message, ULONG reqImage);
#ifdef __cplusplus
}
#endif

extern struct GlutIFace *__glut_current_context;

MGLAPI void glutInit(int *argc, char **argv)
{
	__glut_current_context->GLUTInit(argc, argv);
}

MGLAPI void glutInitWindowSize(int width, int height)
{
	__glut_current_context->GLUTInitWindowSize(width, height);
}

MGLAPI void glutInitWindowPosition(int x, int y)
{
	__glut_current_context->GLUTInitWindowPosition(x, y);
}

MGLAPI void glutInitDisplayMode(unsigned int mode)
{
	__glut_current_context->GLUTInitDisplayMode(mode);
}

MGLAPI int glutCreateWindow(const char *name)
{
	int res;
	GLUTcontext ctx = (GLUTcontext)GET_INSTANCE(__glut_current_context);
	
	res = __glut_current_context->GLUTCreateWindow(name);
	if (res == -1)
	{
        displayWarningReq(NULL, NULL, "Fatal Error",
									  "Could not create an OpenGL window/context.",
									  REQIMAGE_ERROR);
		exit(0);
	}

	mglMakeCurrent(ctx->__glutContext);

	return res;
}

MGLAPI void glutDestroyWindow(int window)
{
	__glut_current_context->GLUTDestroyWindow(window);

	mglMakeCurrent(NULL);
}

MGLAPI void glutPostRedisplay(void)
{
	__glut_current_context->GLUTPostRedisplay();
}

MGLAPI void glutSwapBuffers(void)
{
	__glut_current_context->GLUTSwapBuffers();
}

MGLAPI void glutPositionWindow(int x, int y)
{
	__glut_current_context->GLUTPositionWindow(x, y);
}

MGLAPI void glutReshapeWindow(int width, int height)
{
	__glut_current_context->GLUTReshapeWindow(width, height);
}

MGLAPI void glutFullScreen(void)
{
	__glut_current_context->GLUTFullScreen();
}

MGLAPI void glutPushWindow(void)
{
	__glut_current_context->GLUTPushWindow();
}

MGLAPI void glutPopWindow(void)
{
	__glut_current_context->GLUTPopWindow();
}

MGLAPI void glutShowWindow()
{
	__glut_current_context->GLUTShowWindow();
}

MGLAPI void glutHideWindow()
{
	__glut_current_context->GLUTHideWindow();
}

MGLAPI void glutIconifyWindow()
{
	__glut_current_context->GLUTIconifyWindow();
}

MGLAPI void glutSetWindowTitle(char *name)
{
	__glut_current_context->GLUTSetWindowTitle(name);
}

MGLAPI void glutSetIconTitle(char *name)
{
	__glut_current_context->GLUTSetIconTitle(name);
}

MGLAPI void glutMainLoop(void)
{
	__glut_current_context->GLUTMainLoop();
}

MGLAPI void glutDisplayFunc(void (*func)(void))
{
	__glut_current_context->GLUTDisplayFunc(func);
}

MGLAPI void glutReshapeFunc(void (*func)(int width, int height))
{
	__glut_current_context->GLUTReshapeFunc(func);
}

MGLAPI void glutKeyboardFunc(void (*func)(unsigned char key, int x, int y))
{
	__glut_current_context->GLUTKeyboardFunc(func);
}

MGLAPI void glutMouseFunc(void (*func)(int button, int state, int x, int y))
{
	__glut_current_context->GLUTMouseFunc(func);
}

MGLAPI void glutMotionFunc(void (*func)(int x, int y))
{
	__glut_current_context->GLUTMotionFunc(func);
}

MGLAPI void glutPassiveMotionFunc(void (*func)(int x, int y))
{
	__glut_current_context->GLUTPassiveMotionFunc(func);
}

MGLAPI void glutVisibilityFunc(void (*func)(int state))
{
	__glut_current_context->GLUTVisibilityFunc(func);
}

MGLAPI void glutEntryFunc(void (*func)(int state))
{
	__glut_current_context->GLUTEntryFunc(func);
}

MGLAPI void glutSpecialFunc(void (*func)(int key, int x, int y))
{
	__glut_current_context->GLUTSpecialFunc(func);
}

MGLAPI void glutIdleFunc(void (*func)(void))
{
	__glut_current_context->GLUTIdleFunc(func);
}

MGLAPI int glutGet(GLenum state)
{
	return __glut_current_context->GLUTGet(state);
}

MGLAPI void glutKeyboardUpFunc(void (*func)(unsigned char key, int x, int y))
{
	__glut_current_context->GLUTKeyboardUpFunc(func);
}

MGLAPI void glutSpecialUpFunc(void (*func)(int key, int x, int y))
{
	__glut_current_context->GLUTSpecialUpFunc(func);
}

MGLAPI void glutIgnoreKeyRepeat(int ignore)
{
	__glut_current_context->GLUTIgnoreKeyRepeat(ignore);
}

MGLAPI void glutBitmapCharacter(void* fontID, int character )
{
	__glut_current_context->GLUTBitmapCharacter(fontID, character);
}

MGLAPI void glutBitmapString(void* fontID, const unsigned char *string )
{
	__glut_current_context->GLUTBitmapString(fontID, string);
}

MGLAPI int glutBitmapWidth(void* fontID, int character )
{
	return __glut_current_context->GLUTBitmapWidth(fontID, character);
}

MGLAPI int glutBitmapLength(void* fontID, const unsigned char* string )
{
	return __glut_current_context->GLUTBitmapLength(fontID, string);
}

MGLAPI int glutBitmapHeight(void* fontID )
{
	return __glut_current_context->GLUTBitmapHeight(fontID);
}

MGLAPI void glutStrokeCharacter(void* fontID, int character )
{
	__glut_current_context->GLUTStrokeCharacter(fontID, character);
}

MGLAPI void glutStrokeString(void* fontID, const unsigned char *string )
{
	__glut_current_context->GLUTStrokeString(fontID, string);
}

MGLAPI int glutStrokeWidth(void* fontID, int character )
{
	return __glut_current_context->GLUTStrokeWidth(fontID, character);
}

MGLAPI int glutStrokeLength(void* fontID, const unsigned char* string )
{
	return __glut_current_context->GLUTStrokeLength(fontID, string);
}

MGLAPI GLfloat glutStrokeHeight(void* fontID )
{
	return __glut_current_context->GLUTStrokeHeight(fontID);
}

MGLAPI void glutGameModeString(const char* string)
{
	__glut_current_context->GLUTGameModeString(string);
}

MGLAPI int glutEnterGameMode()
{
	int res;
    GLUTcontext ctx = (GLUTcontext)GET_INSTANCE(__glut_current_context);
	res = __glut_current_context->GLUTEnterGameMode();
	
	if (res == -1)
    {
        displayWarningReq(NULL, NULL, "Fatal Error",
									  "Could not create an OpenGL context.",
									  REQIMAGE_ERROR);
		exit(0);
	}

	mglMakeCurrent(ctx->__glutContext);

	return res;
}

MGLAPI void glutLeaveGameMode()
{
	__glut_current_context->GLUTLeaveGameMode();

	mglMakeCurrent(NULL);
}

MGLAPI int glutGameModeGet(GLenum eWhat)
{
	return __glut_current_context->GLUTGameModeGet(eWhat);
}

/*
 * Geometry functions
 */
MGLAPI void   glutWireCube( GLdouble size )
{
	__glut_current_context->GLUTWireCube(size);
}

MGLAPI void   glutSolidCube( GLdouble size )
{
	__glut_current_context->GLUTSolidCube(size);
}

MGLAPI void   glutWireSphere( GLdouble radius, GLint slices, GLint stacks )
{
	__glut_current_context->GLUTWireSphere(radius, slices, stacks);
}

MGLAPI void   glutSolidSphere( GLdouble radius, GLint slices, GLint stacks )
{
	__glut_current_context->GLUTSolidSphere(radius, slices, stacks);
}

MGLAPI void   glutWireCone( GLdouble base, GLdouble height, GLint slices, GLint stacks )
{
	__glut_current_context->GLUTWireCone(base, height, slices, stacks);
}

MGLAPI void   glutSolidCone( GLdouble base, GLdouble height, GLint slices, GLint stacks )
{
	__glut_current_context->GLUTSolidCone(base, height, slices, stacks);
}

MGLAPI void   glutWireTorus( GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings )
{
	__glut_current_context->GLUTWireTorus(innerRadius, outerRadius, sides, rings);
}

MGLAPI void   glutSolidTorus( GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings )
{
	__glut_current_context->GLUTSolidTorus(innerRadius, outerRadius, sides, rings);
}

MGLAPI void   glutWireDodecahedron()
{
	__glut_current_context->GLUTWireDodecahedron();
}

MGLAPI void   glutSolidDodecahedron()
{
	__glut_current_context->GLUTSolidDodecahedron();
}

MGLAPI void   glutWireOctahedron()
{
	__glut_current_context->GLUTWireOctahedron();
}

MGLAPI void   glutSolidOctahedron()
{
	__glut_current_context->GLUTSolidOctahedron();
}

MGLAPI void   glutWireTetrahedron()
{
	__glut_current_context->GLUTWireTetrahedron();
}

MGLAPI void   glutSolidTetrahedron()
{
	__glut_current_context->GLUTSolidTetrahedron();
}

MGLAPI void   glutWireIcosahedron()
{
	__glut_current_context->GLUTWireIcosahedron();
}

MGLAPI void   glutSolidIcosahedron()
{
	__glut_current_context->GLUTSolidIcosahedron();
}

MGLAPI void   glutWireRhombicDodecahedron()
{
	__glut_current_context->GLUTWireRhombicDodecahedron();
}

MGLAPI void   glutSolidRhombicDodecahedron()
{
	__glut_current_context->GLUTSolidRhombicDodecahedron();
}

MGLAPI void   glutWireSierpinskiSponge ( int num_levels, GLdouble offset[3], GLdouble scale )
{
	__glut_current_context->GLUTWireSierpinskiSponge(num_levels, offset, scale);
}

MGLAPI void   glutSolidSierpinskiSponge ( int num_levels, GLdouble offset[3], GLdouble scale )
{
	__glut_current_context->GLUTSolidSierpinskiSponge(num_levels, offset, scale);
}

MGLAPI void   glutWireCylinder( GLdouble radius, GLdouble height, GLint slices, GLint stacks)
{
	__glut_current_context->GLUTWireCylinder(radius, height, slices, stacks);
}

MGLAPI void   glutSolidCylinder( GLdouble radius, GLdouble height, GLint slices, GLint stacks)
{
	__glut_current_context->GLUTSolidCylinder(radius, height, slices, stacks);
}

MGLAPI void glutWireTeapot(GLdouble size)
{
	__glut_current_context->GLUTWireTeapot(size);
}

MGLAPI void glutSolidTeapot(GLdouble size)
{
	__glut_current_context->GLUTSolidTeapot(size);
}

MGLAPI void glutSetOption(GLenum eWhat, int value)
{
	__glut_current_context->GLUTSetOption(eWhat, value);
}

MGLAPI int glutDeviceGet(GLenum eWhat)
{
	return __glut_current_context->GLUTDeviceGet(eWhat);
}

MGLAPI int glutGetModifiers()
{
	return __glut_current_context->GLUTGetModifiers();
}

MGLAPI int glutLayerGet(GLenum eWhat)
{
	return __glut_current_context->GLUTLayerGet(eWhat);
}

MGLAPI void glutEstablishOverlay()
{
	__glut_current_context->GLUTEstablishOverlay();
}

MGLAPI void glutRemoveOverlay()
{
	__glut_current_context->GLUTRemoveOverlay();
}

MGLAPI void glutUseLayer( GLenum layer )
{
	__glut_current_context->GLUTUseLayer(layer);
}

MGLAPI void glutPostOverlayRedisplay()
{
	__glut_current_context->GLUTPostOverlayRedisplay();
}

MGLAPI void glutPostWindowOverlayRedisplay( int ID )
{
	__glut_current_context->GLUTPostWindowOverlayRedisplay(ID);
}

MGLAPI void glutShowOverlay()
{
	__glut_current_context->GLUTShowOverlay();
}

MGLAPI void glutHideOverlay()
{
	__glut_current_context->GLUTHideOverlay();
}

MGLAPI void glutTimerFunc(unsigned int msecs, void (*func)(int value), int value)
{
	__glut_current_context->GLUTTimerFunc(msecs, func, value);
}

MGLAPI void glutCloseFunc(void (*func)(void))
{
	__glut_current_context->GLUTCloseFunc(func);
}

// Deprecated, but in for compatibility
MGLAPI void glutWMCloseFunc(void (*func)(void))
{
	__glut_current_context->GLUTCloseFunc(func);
}

/*
 * Get a pointer to an OpenGL/GLU/GLUT function (usually used to get functions belonging to
 * extensions). The actual function is implemented in the link-library libglut.a
 */
typedef void (*GLUTproc)();
GLUTproc glutGetProcAddress( const char *procName );

MGLAPI void glutReportErrors()
{
    GLenum error;
    while( ( error = glGetError() ) != GL_NO_ERROR )
		printf( "GL error: %s", gluErrorString( error ) );
}

MGLAPI int glutExtensionSupported(const char* extension )
{
	return __glut_current_context->GLUTExtensionSupported(extension);
}

MGLAPI void glutSetKeyRepeat(int repeatMode)
{
	__glut_current_context->GLUTSetKeyRepeat(repeatMode);
}

MGLAPI void glutForceJoystickFunc()
{
	__glut_current_context->GLUTForceJoystickFunc();
}

MGLAPI void glutSetColor(int nColor, GLfloat red, GLfloat green, GLfloat blue)
{
	__glut_current_context->GLUTSetColor(nColor, red, green, blue);
}

MGLAPI GLfloat glutGetColor(int color, int component)
{
	return __glut_current_context->GLUTGetColor(color, component);
}

MGLAPI void glutCopyColormap(int window)
{
	__glut_current_context->GLUTCopyColormap(window);
}

MGLAPI void glutWarpPointer( int x, int y )
{
	__glut_current_context->GLUTWarpPointer(x, y);
}

MGLAPI void glutSpaceballMotionFunc( void (* callback)( int, int, int ) )
{
	__glut_current_context->GLUTSpaceballMotionFunc(callback);
}

MGLAPI void glutSpaceballRotateFunc( void (* callback)( int, int, int ) )
{
	__glut_current_context->GLUTSpaceballRotateFunc(callback);
}

MGLAPI void glutSpaceballButtonFunc( void (* callback)( int, int ) )
{
	__glut_current_context->GLUTSpaceballButtonFunc(callback);
}

MGLAPI void glutButtonBoxFunc( void (* callback)( int, int ) )
{
	__glut_current_context->GLUTButtonBoxFunc(callback);
}

MGLAPI void glutDialsFunc( void (* callback)( int, int ) )
{
	__glut_current_context->GLUTDialsFunc(callback);
}

MGLAPI void glutTabletMotionFunc( void (* callback)( int, int ) )
{
	__glut_current_context->GLUTTabletMotionFunc(callback);
}

MGLAPI void glutTabletButtonFunc( void (* callback)( int, int, int, int ) )
{
	__glut_current_context->GLUTTabletButtonFunc(callback);
}

MGLAPI void glutOverlayDisplayFunc( void (* callback)( void ) )
{
	__glut_current_context->GLUTOverlayDisplayFunc(callback);
}

MGLAPI void glutJoystickFunc( void (* callback)( unsigned int, int, int, int ), int pollInterval )
{
	__glut_current_context->GLUTJoystickFunc(callback, pollInterval);
}

#endif //_GLUT_H_
