#include <GL/glut.h>
#include <GL/gl.h>

/* Minimum stack space */
static USED const char *stack = "$STACK:65535"; 


GLfloat lightPos[] = {1.0, 1.0, 1.0, 0.0};
GLfloat lightDiffuse[] = {0.3, 1.0, 0.3, 1.0};
GLfloat anglex = 0.0;
GLfloat angley = 0.0;

GLdouble clipPlane[] = {0.2, 1.0, -0.4, 0.0};

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glClipPlane(GL_CLIP_PLANE0, clipPlane);
	glEnable(GL_CLIP_PLANE0);

	glPushMatrix();
	glRotatef(anglex, 0.0, 1.0, 0.0);
	glRotatef(angley, 1.0, 0.0, 0.0);

	glutSolidCube(1.0);

	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);

	glutSwapBuffers();
}

void init(void)
{
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 1.0, 0.1, 10.0);
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0.0, 0.0, 3.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0);
}

void keyboard(unsigned char c, int x, int y)
{
	switch (c)
	{
		case 27:
			exit(0);
		case 'r':
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(0.0, 0.0, -3.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0);
			glutPostRedisplay();
			break;
		case 'n':
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(0.0, 0.0, 3.0,   0.0, 0.0, 0.0,   0.0, 1.0, 0.0);
			glutPostRedisplay();
			break;		
	}
}

void idle(void)
{

}

void passiveMotion(int x, int y)
{
	anglex = (GLfloat)x;
	angley = (GLfloat)y;
	glutPostRedisplay();
}

void motion(int x, int y)
{
	clipPlane[3] = (GLdouble)x/1000.0;
	glutPostRedisplay();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("Cube");
	glutDisplayFunc(display);

	init();

	glutKeyboardFunc(keyboard);
	glutPassiveMotionFunc(passiveMotion);
	glutMotionFunc(motion);
	glutMainLoop();

	return 0;

}
