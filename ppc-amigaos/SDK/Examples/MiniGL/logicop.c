/*
 * Small test program to demonstrate Logic Ops.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

/* Minimum stack space */
static USED const char *stack = "$STACK:65535";

GLboolean doubleBuffer;
GLenum lop = GL_COPY;

#define LOP(X) \
	lop = X; \
	glutSetWindowTitle(#X); \
	glutPostRedisplay(); \
	break;

/* ARGSUSED1 */
static void
Key(unsigned char key, int x, int y)
{

	switch (key) {
		case 27:
			exit(0);
		case '1': LOP(GL_CLEAR);
		case '2': LOP(GL_AND);
		case '3': LOP(GL_AND_REVERSE);
		case '4': LOP(GL_COPY);
		case '5': LOP(GL_AND_INVERTED);
		case '6': LOP(GL_NOOP);
		case '7': LOP(GL_XOR);
		case '8': LOP(GL_OR);
		case '9': LOP(GL_NOR);
		case '0': LOP(GL_INVERT);
		case 'q': LOP(GL_OR_REVERSE);
		case 'w': LOP(GL_COPY_INVERTED);
		case 'e': LOP(GL_OR_INVERTED);
		case 'r': LOP(GL_NAND);
		case 't': LOP(GL_SET);
  }
}

static void Draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glDisable(GL_COLOR_LOGIC_OP);

  /* red triangle */
  glColor3ub(200, 200, 0);
  glBegin(GL_POLYGON);
  glVertex3i(-4, -4, 0);
  glVertex3i(4, -4, 0);
  glVertex3i(0, 4, 0);
  glEnd();


  glColor3ub(100, 0, 200);
  glBegin(GL_POLYGON);
  glVertex3i(2, 2, 0);
  glVertex3i(-2, 2, 0);
  glVertex3i(-2, -2, 0);
  glVertex3i(2, -2, 0);
  glEnd();

  glEnable(GL_COLOR_LOGIC_OP);
  glLogicOp(lop);
  /* white square */
  glColor3ub(100, 200, 200);
  glBegin(GL_POLYGON);
  glVertex3i(3, 3, 0);
  glVertex3i(-3, 3, 0);
  glVertex3i(-3, -3, 0);
  glVertex3i(3, -3, 0);
  glEnd();

  glDisable(GL_COLOR_LOGIC_OP);

  if (doubleBuffer) {
    glutSwapBuffers();
  } else {
    glFlush();
  }
}

static void Args(int argc, char **argv)
{
  GLint i;

  doubleBuffer = GL_TRUE;
  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-sb") == 0) {
      doubleBuffer = GL_FALSE;
    } else if (strcmp(argv[i], "-db") == 0) {
      doubleBuffer = GL_TRUE;
    }
  }
}

int main(int argc, char **argv)
{
  GLenum type;

  glutInit(&argc, argv);
  Args(argc, argv);

  type = GLUT_RGB | GLUT_STENCIL;
  type |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;
  glutInitDisplayMode(type);
  glutCreateWindow("LogicOp Test");

  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClearStencil(0);
  glStencilMask(1);
  glEnable(GL_COLOR_LOGIC_OP);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
  glMatrixMode(GL_MODELVIEW);

  glutKeyboardFunc(Key);
  glutDisplayFunc(Draw);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}

