/*
* License Applicability. Except to the extent portions of this file are
* made subject to an alternative license as permitted in the SGI Free
* Software License B, Version 1.1 (the "License"), the contents of this
* file are subject only to the provisions of the License. You may not use
* this file except in compliance with the License. You may obtain a copy
* of the License at Silicon Graphics, Inc., attn: Legal Services, 1600
* Amphitheatre Parkway, Mountain View, CA 94043-1351, or at:
*
* http://oss.sgi.com/projects/FreeB
*
* Note that, as provided in the License, the Software is distributed on an
* "AS IS" basis, with ALL EXPRESS AND IMPLIED WARRANTIES AND CONDITIONS
* DISCLAIMED, INCLUDING, WITHOUT LIMITATION, ANY IMPLIED WARRANTIES AND
* CONDITIONS OF MERCHANTABILITY, SATISFACTORY QUALITY, FITNESS FOR A
* PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
*
* Original Code. The Original Code is: OpenGL Sample Implementation,
* Version 1.2.1, released January 26, 2000, developed by Silicon Graphics,
* Inc. The Original Code is Copyright (c) 1991-2000 Silicon Graphics, Inc.
* Copyright in any portions created by third parties is as indicated
* elsewhere herein. All Rights Reserved.
*
* Additional Notice Provisions: The application programming interfaces
* established by SGI in conjunction with the Original Code are The
* OpenGL(R) Graphics System: A Specification (Version 1.2.1), released
* April 1, 1999; The OpenGL(R) Graphics System Utility Library (Version
* 1.3), released November 4, 1998; and OpenGL(R) Graphics with the X
* Window System(R) (Version 1.3), released October 19, 1998. This software
* was created using the OpenGL(R) version 1.2.1 Sample Implementation
* published by SGI, but has not been independently verified as being
* compliant with the OpenGL(R) version 1.2.1 Specification.
*
*/

/*  bezcurve.c
*  This program uses evaluators to draw a Bezier curve.
*/
#include <GL/glut.h>
#include <stdlib.h>

/* Apps that use the GLU NURBS functions often need a bit more stack space.
* Allocate a bit more stack. */
static USED const char *stack = "$STACK:65535";

GLfloat ctrlpoints[4][3] = {
	{ -4.0, -4.0, 0.0}, { -2.0, 4.0, 0.0},
	{2.0, -4.0, 0.0}, {4.0, 4.0, 0.0}
};

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
}

void display(void)
{
	int i;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 30; i++) {
			glEvalCoord1f((GLfloat) i/30.0);
		}
	glEnd();
	/* The following code displays the control points as dots. */
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
		for (i = 0; i < 4; i++) {
			glVertex3fv(&ctrlpoints[i][0]);
		}
	glEnd();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) {
		glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w, 5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
	}
	else {
		glOrtho(-5.0*(GLfloat)w/(GLfloat)h, 5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 27:
			exit(0);
			break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc (keyboard);
	glutMainLoop();
	return 0;
}
