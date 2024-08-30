
/* Copyright (c) Mark J. Kilgard, 1997. */

/* This program is freely distributable without licensing fees 
   and is provided without guarantee or warrantee expressed or 
   implied. This program is -not- in the public domain. */

/* This program was requested by Patrick Earl; hopefully someone else
   will write the equivalent Direct3D immediate mode program. */

/* This particular demo shows how to use MiniGL without GLUT. It also shows
 * how to use glDrawBuffer and glFlush without mglSwitchDisplay()
 */
#include <GL/gl.h>
#include <stdlib.h>
#include <proto/intuition.h>

/* Minimum stack space */
static USED const char *stack = "$STACK:65535"; 

GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  /* Red diffuse light. */
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */
GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
  {-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
  {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, -1.0} };
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
  {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
  {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };
GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */

GLfloat angle = 0.0;

void
drawBox(void)
{
  int i;
  
  static float colors[6][3] =
  {
  	{1.0, 0.0, 0.0},
  	{0.0, 1.0, 0.0},
  	{0.0, 0.0, 1.0},
  	{1.0, 0.0, 1.0},
  	{0.0, 1.0, 1.0},
  	{1.0, 1.0, 1.0}
  };

  for (i = 0; i < 6; i++) {
/*  	
    glBegin(GL_QUADS);
    glNormal3fv(&n[i][0]);
    glVertex3fv(&v[faces[i][0]][0]);
    glVertex3fv(&v[faces[i][1]][0]);
    glVertex3fv(&v[faces[i][2]][0]);
    glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
*/
	glEnableClientState(GL_VERTEX_ARRAY);
    glNormal3fv(&n[i][0]);
    glVertexPointer(3, GL_FLOAT, 0, v);
    glColor3fv(&colors[i][0]);
    
    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, faces[i]);

  }
}

void
display(void)
{
  glClearColor(0.4, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glPushMatrix();
   glRotatef(angle, 1.0, 0.0, 0.0);
  drawBox();
  glPopMatrix();
}

#include <proto/exec.h>

void
init(void)
{
  /* Setup cube vertex data. */
  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

  /* Enable a single OpenGL light. */
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	
  /* Use depth buffering for hidden surface elimination. */
  glEnable(GL_DEPTH_TEST);

  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 40.0,
    /* aspect ratio */ 1.0,
    /* Z near */ 1.0, /* Z far */ 10.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0.0, 0.0, 5.0,  /* eye is at (0,0,5) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.);      /* up is in positive Y direction */

  /* Adjust cube position to be asthetic angle. */
  glTranslatef(0.0, 0.0, -1.0);
  glRotatef(60.0, 1.0, 0.0, 0.0);
  glRotatef(-20, 0.0, 0.0, 1.0);
}

void 
idle(void)
{ 	
    angle += 0.1;
    if (angle > 360.0)
       angle = 0.0;
  
}

struct Interface *getInterface(char *libname)
{
	struct Library *lib;
	
	lib = IExec->OpenLibrary(libname, 0);
	if (lib)
		return IExec->GetInterface(lib, "main", 1, NULL);
	
	return 0;
}

void dropInterface(struct Interface *iface)
{
	if (iface)
	{
		struct Library *lib = iface->Data.LibBase;
		IExec->DropInterface(iface);
		IExec->CloseLibrary(lib);
	}
}

int
main(int argc, char **argv)
{
	struct MiniGLIFace *IMiniGL = 0;
	IMiniGL = (struct MiniGLIFace *)getInterface("minigl.library");
	if (!IMiniGL)
		return 20;

	struct GLContextIFace *IGL = IMiniGL->CreateContextTags(
			MGLCC_Width,		640,
			MGLCC_Height,		480,
			MGLCC_Windowed,		TRUE,
			MGLCC_CloseGadget,	TRUE,			
			MGLCC_Buffers, 		2,
			MGLCC_PixelDepth,	16,
			TAG_DONE);
	if (IGL)
	{
		mglMakeCurrent(IGL);
		mglLockMode(MGL_LOCK_SMART);
		init();

		BOOL bRun = TRUE;
		
		struct Window *win = mglGetWindowHandle();
		if (!IIntuition->ModifyIDCMP(win, IDCMP_CLOSEWINDOW))
			bRun = FALSE;

		
		glDrawBuffer(GL_FRONT);

		while (bRun)
		{
			struct IntuiMessage *imsg;

			display();
			idle();
			
			glFlush();
			mglUnlockDisplay();
			
			glDrawBuffer(GL_BACK);
			display();
			glDrawBuffer(GL_FRONT);
			
			struct Window *win = mglGetWindowHandle();

			while ((imsg = (struct IntuiMessage *)IExec->GetMsg(win->UserPort)))
			{
				if (imsg->Class == IDCMP_CLOSEWINDOW)
					bRun = FALSE;
				IExec->ReplyMsg((struct Message *)imsg);
			}
		}
		
		mglDeleteContext();
	}
	
	dropInterface((struct Interface *)IMiniGL);
	
	return 0;
}
