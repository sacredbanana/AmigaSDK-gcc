/** A simple demo that uses glutTimerFunc().
 *
 * Draws an animated triangle.
 *
 * by Hans de Ruiter
 */

#include <GL/glut.h>

/* Minimum stack space */
static USED const char *stack = "$STACK:65535"; 

#define WIDTH 640
#define HEIGHT 480

#define TIMERMSECS 33
#define ROTSTEP 3.2f

static GLfloat rot = 0.0f;

static void reshape(GLsizei w, GLsizei h);

static void init(int w, int h)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
	reshape(w, h);

	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

static void animate(int value)
{
	rot += ROTSTEP;
	
	glutTimerFunc(TIMERMSECS, animate, 0);
	glutPostRedisplay();
}

static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(0.0f,0.0f,-3.0f);
	glRotatef(rot, 0.0, 0.0, 1.0);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, -1.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, -1.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 1.0, 0.0);
	glEnd();

    glutSwapBuffers();
    glFlush();
}

static void key(unsigned char k, int x, int y)
{
  switch (k) {
  case 27:  /* Escape */
    exit(0);
    break;
  default:
    return;
  }
  glutPostRedisplay();
}

static void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*  Main Loop
 *  Open window with initial window size, title bar,
 *  RGBA display mode, and handle input events.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (WIDTH, HEIGHT);
    glutCreateWindow (argv[0]);
	init(WIDTH, HEIGHT);
    glutDisplayFunc(display);
	glutKeyboardFunc(key);
    glutReshapeFunc(reshape);
	glutPostRedisplay();
    glutTimerFunc(TIMERMSECS, animate, 0);
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}
