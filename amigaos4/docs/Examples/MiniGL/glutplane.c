
/* Copyright (c) Mark J. Kilgard, 1994. */

/* This program is freely distributable without licensing fees 
   and is provided without guarantee or warrantee expressed or 
   implied. This program is -not- in the public domain. */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define random rand
#define srandom srand

#include <math.h>
#include <GL/glut.h>

/* Minimum stack space */
static USED const char *stack = "$STACK:65535"; 

/* Some <math.h> files do not define M_PI... */
#ifndef M_PI
#define M_PI 3.14159265
#endif
#ifndef M_PI_2
#define M_PI_2 1.57079632
#endif

GLboolean moving = GL_FALSE;

#define MAX_PLANES 90

struct {
  float speed;          /* zero speed means not flying */
  GLfloat red, green, blue;
  float theta;
  float x, y, z, angle;
} planes[MAX_PLANES];

#define v3f glVertex3f  /* v3f was the short IRIS GL name for
                           glVertex3f */

void
draw(void)
{
  GLfloat red, green, blue;
  int i;

  glClear(GL_DEPTH_BUFFER_BIT);
  /* paint black to blue smooth shaded polygon for background */
  glDisable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
  glBegin(GL_POLYGON);
  glColor3f(0.0, 0.0, 0.0);
  v3f(-20, 20, -19);
  v3f(20, 20, -19);
  glColor3f(0.0, 0.0, 1.0);
  v3f(20, -20, -19);
  v3f(-20, -20, -19);
  glEnd();
  /* paint planes */
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_FLAT);
  for (i = 0; i < MAX_PLANES; i++)
    if (planes[i].speed != 0.0) {
      glPushMatrix();
      glTranslatef(planes[i].x, planes[i].y, planes[i].z);
      glRotatef(290.0, 1.0, 0.0, 0.0);
      glRotatef(planes[i].angle, 0.0, 0.0, 1.0);
      glScalef(1.0 / 3.0, 1.0 / 4.0, 1.0 / 4.0);
      glTranslatef(0.0, -4.0, -1.5);
      glBegin(GL_TRIANGLE_STRIP);
      /* left wing */
      v3f(-7.0, 0.0, 2.0);
      v3f(-1.0, 0.0, 3.0);
      glColor3f(red = planes[i].red, green = planes[i].green,
        blue = planes[i].blue);
      v3f(-1.0, 7.0, 3.0);
      /* left side */
      glColor3f(0.6 * red, 0.6 * green, 0.6 * blue);
      v3f(0.0, 0.0, 0.0);
      v3f(0.0, 8.0, 0.0);
      /* right side */
      v3f(1.0, 0.0, 3.0);
      v3f(1.0, 7.0, 3.0);
      /* final tip of right wing */
      glColor3f(red, green, blue);
      v3f(7.0, 0.0, 2.0);
      glEnd();
      glPopMatrix();
    }
  glutSwapBuffers();
}

void
tick_per_plane(int i)
{
  float theta = planes[i].theta += planes[i].speed;
  planes[i].z = -9 + 4 * cos(theta);
  planes[i].x = 4 * sin(2 * theta);
  planes[i].y = sin(theta / 3.4) * 3;
  planes[i].angle = ((atan(2.0) + M_PI_2) * sin(theta) - M_PI_2) * 180 / M_PI;
  if (planes[i].speed < 0.0)
    planes[i].angle += 180;
}

void
add_plane(void)
{
  int i;

  for (i = 0; i < MAX_PLANES; i++)
    if (planes[i].speed == 0) {

#define SET_COLOR(r,g,b) \
	planes[i].red=r; planes[i].green=g; planes[i].blue=b;

      switch (random() % 6) {
      case 0:
        SET_COLOR(1.0, 0.0, 0.0);  /* red */
        break;
      case 1:
        SET_COLOR(1.0, 1.0, 1.0);  /* white */
        break;
      case 2:
        SET_COLOR(0.0, 1.0, 0.0);  /* green */
        break;
      case 3:
        SET_COLOR(1.0, 0.0, 1.0);  /* magenta */
        break;
      case 4:
        SET_COLOR(1.0, 1.0, 0.0);  /* yellow */
        break;
      case 5:
        SET_COLOR(0.0, 1.0, 1.0);  /* cyan */
        break;
      }
      planes[i].speed = ((float) (random() % 20)) * 0.001 + 0.02;
      if (random() & 0x1)
        planes[i].speed *= -1;
      planes[i].theta = ((float) (random() % 257)) * 0.1111;
      tick_per_plane(i);
      if (!moving)
        glutPostRedisplay();
      return;
    }
}

void
remove_plane(void)
{
  int i;

  for (i = MAX_PLANES - 1; i >= 0; i--)
    if (planes[i].speed != 0) {
      planes[i].speed = 0;
      if (!moving)
        glutPostRedisplay();
      return;
    }
}

void
tick(void)
{
  int i;

  for (i = 0; i < MAX_PLANES; i++)
    if (planes[i].speed != 0.0)
      tick_per_plane(i);
}

void
animate(void)
{
  tick();
  glutPostRedisplay();
}

void
visible(int state)
{
  if (state == GLUT_VISIBLE) {
    if (moving)
      glutIdleFunc(animate);
  } else {
    if (moving)
      glutIdleFunc(NULL);
  }
}

void
myReshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 20);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/* ARGSUSED1 */
void
keyboard(unsigned char ch, int x, int y)
{
  switch (ch) {
  case ' ':
    if (!moving) {
      tick();
      glutPostRedisplay();
    }
    break;
  case 27:             /* ESC */
    exit(0);
    break;
  case 'a':
  	add_plane();
  	break;
  case 'r':
  	remove_plane();
  	break;
  case 't':
  	if (moving == GL_TRUE) moving = GL_FALSE;
  	else moving = GL_TRUE;
  	break;
  }
}

#define ADD_PLANE	1
#define REMOVE_PLANE	2
#define MOTION_ON	3
#define MOTION_OFF	4
#define QUIT		5
/*
void
menu(int item)
{
  switch (item) {
  case ADD_PLANE:
    add_plane();
    break;
  case REMOVE_PLANE:
    remove_plane();
    break;
  case MOTION_ON:
    moving = GL_TRUE;
    glutChangeToMenuEntry(3, "Motion off", MOTION_OFF);
    glutIdleFunc(animate);
    break;
  case MOTION_OFF:
    moving = GL_FALSE;
    glutChangeToMenuEntry(3, "Motion", MOTION_ON);
    glutIdleFunc(NULL);
    break;
  case QUIT:
    exit(0);
    break;
  }
}
*/
int
main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitWindowSize(800, 800);
  /* use multisampling if available */
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH/* | GLUT_MULTISAMPLE*/);
  glutCreateWindow("glutplane");
  glutDisplayFunc(draw);
  glutKeyboardFunc(keyboard);
  glutVisibilityFunc(visible);
  glutIdleFunc(animate);
  /* setup OpenGL state */
  glClearDepth(1.0);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 20);
  glMatrixMode(GL_MODELVIEW);
  /* add three initial random planes */
  srandom(getpid());
  add_plane();
  add_plane();
  add_plane();
  /* start event processing */
  myReshape(800,800);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
