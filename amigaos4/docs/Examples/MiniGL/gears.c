#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glext.h>

#include <proto/timer.h>
#include <proto/graphics.h>
#include <proto/exec.h>


#include <math.h>
#include <string.h>

/* Minimum stack space */
static USED const char *stack = "$STACK:65535";

/* Some <math.h> files do not define M_PI... */
#ifndef M_PI
#define M_PI 3.14159265
#endif
#include <stdio.h>

/* For portability... */
#undef fcos
#undef fsin
#undef fsqrt
#ifdef MGL_HAS_NO_SPE_NEWLIB
	#define fcos  spe_cos
	#define fsin  spe_sin
	#define fsqrt spe_sqrt
	#define double float
#else
	#define fcos  cos
	#define fsin  sin
	#define fsqrt sqrt
#endif

static double dNear = 1.0;
static double dFar = 2000;
static int poo = 0;

int iShowFlags = 1;
double fFrameTimes = 0;
double fFrameTimesSwap = 0;
int iFramesDrawn = 0;

int iGearList1 = 0;
int iGearList2 = 0;

typedef struct {
	float fRad, fWid;
} Profile;

void createGear(int nt, float wd, float ir, float or, float tp, float tip, int ns, Profile * ip);

int iCircleSubdivision;
#define MIN_SUBDIV 30

GLboolean bEnvMap   = GL_TRUE;
GLboolean bUseLists = GL_FALSE;
GLboolean bAnimate  = GL_TRUE;
GLboolean bShowFPS  = GL_FALSE;

GLubyte *loadPPMImage(char *name, GLint *w, GLint *h)
{
	int i;
	unsigned long x,y;
	FILE *f;
	GLubyte *where;

	f = fopen(name, "rb");

	if (!f) {
		printf("PPM open failed\n");
		*w = 0; *h=0;
		return NULL;
	}
	i = fscanf(f, "P6\n");
	if (fgetc(f) == '#') {
		while(fgetc(f) != '\n' && !ferror(f)) {
			;
		}
		if (ferror(f)) {
			printf("PPM open failed\n");
			*w = 0; *h=0;
			return NULL;
		}
	}
	else {
		fseek(f, -1, SEEK_CUR);
	}
	i += fscanf(f,"%ld %ld\n255\n", &x, &y);

	if (i!= 2) {
		printf("Error scanning PPM header\n");
		fclose(f);
		*w = 0; *h = 0;
		return NULL;
	}

	*w = x;
	*h = y;

	where = malloc(x*y*3);
	if (!where) {
		printf("Error out of Memory\n");
		fclose(f);
		*w = 0; *h = 0;
		return NULL;
	}

	i = fread(where, 1, x*y*3, f);
	fclose(f);

	if (i != x*y*3) {
		printf("Error while reading file\n");
		free(where);
		*w = 0; *h = 0;
		return NULL;
	}

	return where;
}

GLboolean initTexture(char *name)
{
	GLubyte *tmap;
	GLint x,y;

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glPixelStorei(GL_PACK_ALIGNMENT, 1);

	if (!name) {
		tmap = loadPPMImage("data/chrome.ppm",&x, &y);
	}
	else {
		tmap = loadPPMImage(name, &x, &y);
	}

	if (!tmap) {
		return GL_FALSE;
	}

	glBindTexture(GL_TEXTURE_2D, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, tmap);
	free(tmap);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

	return GL_TRUE;
}



Profile aGearProfile[] =
{
	{0.000, 0.0},
	{0.300, 7.0},
	{0.340, 0.4},
	{0.550, 0.64},
	{0.600, 0.4},
	{0.950, 1.0}
};

float a1 = 27.0;
float a2 = 67.0;
float a3 = 47.0;
float a4 = 87.0;
float i1 = 1.2;
float i2 = 3.1;
float i3 = 2.3;
float i4 = 1.1;

void doclear(void)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-3.0, 3.0, -3.0, 3.0);

	glDepthFunc(GL_ALWAYS);
	glDisable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.3f);
		glVertex3f(0.0f, 0.0f, -1.0f);
		glVertex3f(0.0f, 3.0f, -1.0f);
		glVertex3f(3.0f, 3.0f, -1.0f);
		glVertex3f(3.0f, 0.0f, -1.0f);
	glEnd();


	glDepthFunc(GL_LESS);
	glEnable(GL_TEXTURE_2D);

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void makeGear1(void)
{
	createGear(
		40,
		0.4, 2.0, 1.1,
		0.8, 0.4,
		sizeof(aGearProfile) / sizeof(Profile), aGearProfile
	);
}

void makeGear2(void)
{
	createGear(
		36,
		0.4, 2.0, 1.1,
		0.7, 0.2,
		sizeof(aGearProfile) / sizeof(Profile), aGearProfile
	);
}

void createGearLists(void)
{
	iGearList1 = glGenLists (2);
	if (iGearList1 > 0) {
		iGearList2 = iGearList1 + 1;
		glNewList(iGearList1, GL_COMPILE);
			makeGear1();
		glEndList();
		glNewList(iGearList2, GL_COMPILE);
			makeGear2();
		glEndList();
	}
}

void oneFrame(void)
{

#if 1
	int start, end;
	start = glutGet(GLUT_ELAPSED_TIME);
#endif

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

#if 1
	if (iShowFlags & 1) {
		glColor3f(1.0, 0.0, 1.0);
		glPushMatrix();
			glTranslatef(0.0, 0.0, -4.0);
			glRotatef(a3, 1.0, 1.0, 1.0);
			glRotatef(a4, 0.0, 0.0, -1.0);
			glTranslatef(0.14, 0.2, 0.0);
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			if (bUseLists) {
				glCallList(iGearList1);
			}
			else {
				makeGear1();
			}
		glPopMatrix();
	}

	if (iShowFlags & 2) {
		glPushMatrix();
			glTranslatef(0.1, 0.2, -3.8);
			glRotatef(a2, -4.0, 2.0, -1.0);
			glRotatef(a1, 1.0, -3.0, 1.0);
			glTranslatef(0.0, -0.2, 0.0);
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glColor3f(1.0, 0.8, 0.0);
			if (bUseLists) {
				glCallList(iGearList2);
			}
			else {
				makeGear2();
			}
		glPopMatrix();
	}

	if (bAnimate) {
		a1 += i1;
		if (a1 > 360.0) {
			a1 -= 360.0;
		}
		if (a1 < 0.0) {
			a1 -= 360.0;
		}
		a2 += i2;
		if (a2 > 360.0) {
			a2 -= 360.0;
		}
		if (a2 < 0.0) {
			a2 -= 360.0;
		}
		a3 += i3;
		if (a3 > 360.0) {
			a3 -= 360.0;
		}
		if (a3 < 0.0) {
			a3 -= 360.0;
		}
		a4 += i4;
		if (a4 > 360.0) {
			a4 -= 360.0;
		}
		if (a4 < 0.0) {
			a4 -= 360.0;
		}
	}

	end = glutGet(GLUT_ELAPSED_TIME);

	iFramesDrawn++;

	fFrameTimes += (double)(end - start);
#endif
	glutSwapBuffers();

	end = glutGet(GLUT_ELAPSED_TIME);
	fFrameTimesSwap += (double)(end - start);


#if 0
	if (bShowFPS)
	{
		float fps;
		char buffer[30];

		fps = 1000000.f / (float)(end.tv_micro);
		#ifdef MGL_HAS_NO_SPE_NEWLIB
			sprintf(buffer, "%d", (int)fps);
		#else
			sprintf(buffer, "%f", fps);
		#endif

		IGraphics->SetAPen(mini_CurrentContext->w3dWindow->RPort, 2);
		IGraphics->SetDrMd(mini_CurrentContext->w3dWindow->RPort, JAM1);
		IGraphics->Move(mini_CurrentContext->w3dWindow->RPort, mini_CurrentContext->w3dWindow->BorderRight+10,
						mini_CurrentContext->w3dWindow->BorderTop+10);
		IGraphics->Text(mini_CurrentContext->w3dWindow->RPort, buffer, strlen(buffer));
	}
#endif
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void myReshape(int w, int h)
{
	glViewport(0, -40, w, h+40);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, dNear, dFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void myinit(int w, int h)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	myReshape(w, h);
	/* glShadeModel(GL_FLAT); */
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	createGearLists();
}

/* ARGSUSED1 */
void myKeyboardCallback(unsigned char c, int x, int y)
{
	switch (c) {
		case 27:
			#ifdef MGL_HAS_NO_SPE_NEWLIB
				printf("%d frames drawn, for a total of %d milliseconds\n", iFramesDrawn, (int)fFrameTimes);
				printf("Took approximately %d milliseconds per frame\n", (int)(fFrameTimes/(double)iFramesDrawn));
				printf("Avarage FPS: %d\n", (int)((double)1000.0/(fFrameTimes/(double)iFramesDrawn)));
				printf("Took approximately %d milliseconds per frame (with swap)\n", (int)(fFrameTimesSwap/(double)iFramesDrawn));
				printf("Avarage FPS (with swap): %d\n", (int)((double)1000.0/(fFrameTimesSwap/(double)iFramesDrawn)));
			#else
				printf("%d frames drawn, for a total of %f milliseconds\n", iFramesDrawn, fFrameTimes);
				printf("Took approximately %f milliseconds per frame\n", fFrameTimes/(double)iFramesDrawn);
				printf("Avarage FPS: %f\n", (double)1000.0/(fFrameTimes/(double)iFramesDrawn));
				printf("Took approximately %f milliseconds per frame (with swap)\n", fFrameTimesSwap/(double)iFramesDrawn);
				printf("Avarage FPS (with swap): %f\n", (double)1000.0/(fFrameTimesSwap/(double)iFramesDrawn));
			#endif
			exit(0);
			break;

		case '0':
		case '1':
		case '2':
		case '3':
			iShowFlags = c - '0';
			break;

		case 'f':
			bShowFPS = !bShowFPS;
			break;

		case 't':
			if ( (bAnimate = !bAnimate) ) {
				printf("Enabling animation\n");
			}
			else {
				printf("Disabling animation\n");
			}
			break;

		case 'l':
			if ( (bUseLists = !bUseLists) ) {
				printf("Switching to glCallList() rendering\n");
			}
			else {
				printf("Switching to direct rendering\n");
			}
			break;

		case 'e':
			if ( (bEnvMap = !bEnvMap) ) {
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_TEXTURE_GEN_S);
				glEnable(GL_TEXTURE_GEN_T);
				printf("Enabling texture coordinate generation\n");
			}
			else {
				glDisable(GL_TEXTURE_2D);
				glDisable(GL_TEXTURE_GEN_S);
				glDisable(GL_TEXTURE_GEN_T);

				printf("Disabling texture coordinate generation\n");
			}
			break;

		case 'o':
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			break;

		case 'p':
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			break;

		default:
			break;
	}

}

int main(int argc, char *argv[])
{
	GLint width=512; GLint height=512;
	int i;
	char *name = 0;
	GLenum sync   = GL_FALSE;
	GLenum fbmode = GLUT_DOUBLE;

	glutInit(&argc, argv);

	for (i=1; i<argc; i++) {
		if (0 == strcasecmp(argv[i], "-width")) {
			i++;
			width = atoi(argv[i]);
		}
		if (0 == strcasecmp(argv[i], "-height")) {
			i++;
			height = atoi(argv[i]);
		}
		if (0 == strcasecmp(argv[i], "-envmap")) {
			i++;
			name = argv[i];
		}
		if (0 == strcasecmp(argv[i], "-sync")) {
			i++;
			sync = GL_TRUE;
		}
		if (0 == strcasecmp(argv[i], "-sbf")) {
			i++;
			fbmode = GLUT_SINGLE;
		}
	}

	glutInitDisplayMode(fbmode | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow(argv[0]);

	mglEnableSync(sync);

	if ( initTexture(name) ) {
		glClearColor(0.1, 0.0, 0.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDisable(GL_CULL_FACE);

//		glEnable(GL_CULL_FACE);
//		glFrontFace(GL_CW);
//		glCullFace(GL_BACK);

		glHint(MGL_W_ONE_HINT, GL_FASTEST);

		{
			GLint maxAnisotropy = 0;
			glGetIntegerv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
			printf("Max supported anisotropy :%d\n", maxAnisotropy);
		}

		myinit(width, height);

//		mglLockMode(MGL_LOCK_MANUAL);
		glutIdleFunc(oneFrame);
		glutKeyboardFunc(myKeyboardCallback);
		glutMainLoop();
	}
	else {
		printf("Can't find texture %s\n", name);
	}

	return 0;             /* ANSI C requires main to return int. */
}

/**********************************************************************************************************************/

void gearFlatFace(float ir, float or, float wd);
void gearInside(float w1, float w2, float fRad);
void gearOutside(float w1, float w2, float fRad);
void gearToothSide(int nt, float ir, float or, float tp, float tip, float wd);

void createGear(int nt, float wd, float ir, float or, float tp, float tip, int ns, Profile * ip)
{
	/**
	* nt - number of teeth
	* wd - width of gear at teeth
	* ir - inside radius absolute scale
	* or - radius at outside of wheel (tip of tooth) ratio of ir
	* tp - ratio of tooth in slice of circle (0..1] (1 = teeth are touching at base)
	* tip - ratio of tip of tooth (0..tp] (cant be wider that base of tooth)
	* ns - number of elements in wheel width profile
	* *ip - list of float pairs {start radius, width, ...} (width is ratio to wd)
	*
	*/

	/* gear lying on xy plane, z for width. all normals calulated
	(normalized) */

	float prev;
	int k, t;

	/* estimat # times to divide circle */
	if (nt <= 0) {
		iCircleSubdivision = MIN_SUBDIV;
	}
	else {
		/* lowest multiple of number of teeth */
		iCircleSubdivision = nt;
		while (iCircleSubdivision < MIN_SUBDIV) {
			iCircleSubdivision += nt;
		}
	}

	/* --- draw wheel face --- */

	/* draw horzontal, vertical faces for each section. if first
	section radius not zero, use wd for 0.. first if ns == 0
	use wd for whole face. last width used to edge.  */

	if (ns <= 0) {
		gearFlatFace(0.0, ir, wd);
	}
	else {
		/* draw first flat_face, then continue in loop */
		if (ip[0].fRad > 0.0) {
			gearFlatFace(0.0, ip[0].fRad * ir, wd);
			prev = wd;
			t = 0;
		} else {
			gearFlatFace(0.0, ip[1].fRad * ir, ip[0].fWid * wd);
			prev = ip[0].fWid;
			t = 1;
		}
		for (k = t; k < ns; k++) {
			if (prev < ip[k].fWid) {
				gearInside(prev * wd, ip[k].fWid * wd, ip[k].fRad * ir);
			}
			else {
				gearOutside(prev * wd, ip[k].fWid * wd, ip[k].fRad * ir);
			}
			prev = ip[k].fWid;
			/* - draw to edge of wheel, add final face if needed - */
			if (k == ns - 1) {
				gearFlatFace(ip[k].fRad * ir, ir, ip[k].fWid * wd);

				/* now draw side to match tooth rim */
				if (ip[k].fWid < 1.0) {
					gearInside(ip[k].fWid * wd, wd, ir);
				}
				else {
					gearOutside(ip[k].fWid * wd, wd, ir);
				}
			} else {
				gearFlatFace(ip[k].fRad * ir, ip[k + 1].fRad * ir, ip[k].fWid * wd);
			}
		}
	}

	/* --- tooth side faces --- */
	gearToothSide(nt, ir, or, tp, tip, wd);

	/* --- tooth hill surface --- */
}

void gearToothSide(int nt, float ir, float or, float tp, float tip, float wd)
{
	float i;
	float end = 2.0 * M_PI / nt;
	float x[6], y[6];
	float s[3], c[3];

	or = or * ir;         /* or is really a ratio of ir */
	for (i = 0; i < 2.0 * M_PI - end / 4.0; i += end) {

		c[0] = fcos(i);
		s[0] = fsin(i);
		c[1] = fcos(i + end * (0.5 - tip / 2));
		s[1] = fsin(i + end * (0.5 - tip / 2));
		c[2] = fcos(i + end * (0.5 + tp / 2));
		s[2] = fsin(i + end * (0.5 + tp / 2));

		x[0] = ir * c[0];
		y[0] = ir * s[0];
		x[5] = ir * fcos(i + end);
		y[5] = ir * fsin(i + end);
		/* ---treat veritices 1,4 special to match strait edge of
			face */
		x[1] = x[0] + (x[5] - x[0]) * (0.5 - tp / 2);
		y[1] = y[0] + (y[5] - y[0]) * (0.5 - tp / 2);
		x[4] = x[0] + (x[5] - x[0]) * (0.5 + tp / 2);
		y[4] = y[0] + (y[5] - y[0]) * (0.5 + tp / 2);
		x[2] = or * fcos(i + end * (0.5 - tip / 2));
		y[2] = or * fsin(i + end * (0.5 - tip / 2));
		x[3] = or * fcos(i + end * (0.5 + tip / 2));
		y[3] = or * fsin(i + end * (0.5 + tip / 2));

		/* draw face trapezoids as 2 tmesh */
		glNormal3f(0.0, 0.0, 1.0);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(x[2], y[2], wd / 2);
			glVertex3f(x[1], y[1], wd / 2);
			glVertex3f(x[3], y[3], wd / 2);
			glVertex3f(x[4], y[4], wd / 2);
		glEnd();

		glNormal3f(0.0, 0.0, -1.0);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(x[2], y[2], -wd / 2);
			glVertex3f(x[1], y[1], -wd / 2);
			glVertex3f(x[3], y[3], -wd / 2);
			glVertex3f(x[4], y[4], -wd / 2);
		glEnd();

		/* draw inside rim pieces */
		glNormal3f(c[0], s[0], 0.0);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(x[0], y[0], -wd / 2);
			glVertex3f(x[1], y[1], -wd / 2);
			glVertex3f(x[0], y[0], wd / 2);
			glVertex3f(x[1], y[1], wd / 2);
		glEnd();

		/* draw up hill side */
		{
			float a, b, n;
			/* calculate normal of face */
			a = x[2] - x[1];
			b = y[2] - y[1];
			n = 1.0 / fsqrt(a * a + b * b);
			a = a * n;
			b = b * n;
			glNormal3f(b, -a, 0.0);
		}
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(x[1], y[1], -wd / 2);
			glVertex3f(x[2], y[2], -wd / 2);
			glVertex3f(x[1], y[1], wd / 2);
			glVertex3f(x[2], y[2], wd / 2);
		glEnd();
		/* draw top of hill */
		glNormal3f(c[1], s[1], 0.0);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(x[2], y[2], -wd / 2);
			glVertex3f(x[3], y[3], -wd / 2);
			glVertex3f(x[2], y[2], wd / 2);
			glVertex3f(x[3], y[3], wd / 2);
		glEnd();

		/* draw down hill side */
		{
			float a, b, c;
			/* calculate normal of face */
			a = x[4] - x[3];
			b = y[4] - y[3];
			c = 1.0 / fsqrt(a * a + b * b);
			a = a * c;
			b = b * c;
			glNormal3f(b, -a, 0.0);
		}
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(x[3], y[3], -wd / 2);
			glVertex3f(x[4], y[4], -wd / 2);
			glVertex3f(x[3], y[3], wd / 2);
			glVertex3f(x[4], y[4], wd / 2);
		glEnd();
		/* inside rim part */
		glNormal3f(c[2], s[2], 0.0);
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(x[4], y[4], -wd / 2);
			glVertex3f(x[5], y[5], -wd / 2);
			glVertex3f(x[4], y[4], wd / 2);
			glVertex3f(x[5], y[5], wd / 2);
		glEnd();
	}
}

void gearFlatFace(float ir, float or, float wd)
{
	int i;
	float w;

	/* draw each face (top & bottom ) * */
	if (poo) {
		#ifdef MGL_HAS_NO_SPE_NEWLIB
			printf("Face  : %d..%d fWid=%d\n", (int)ir, (int)or, (int)wd);
		#else
			printf("Face  : %f..%f fWid=%f\n", ir, or, wd);
		#endif
	}
	if (wd == 0.0) {
		return;
	}
	for (w = wd / 2; w > -wd; w -= wd) {
		if (w > 0.0) {
			glNormal3f(0.0, 0.0, 1.0);
		}
		else {
			glNormal3f(0.0, 0.0, -1.0);
		}
		if (ir == 0.0) {
			/* draw as t-fan */
			glBegin(GL_TRIANGLE_FAN);
				glVertex3f(0.0, 0.0, w);  /* center */
				glVertex3f(or, 0.0, w);
				for (i = 1; i < iCircleSubdivision; i++) {
					glVertex3f(
						fcos(2.0 * M_PI * i / (float)iCircleSubdivision) * or,
						fsin(2.0 * M_PI * i / (float)iCircleSubdivision) * or,
						w
					);
				}
				glVertex3f(or, 0.0, w);
			glEnd();
		}
		else {
			/* draw as tmesh */
			glBegin(GL_TRIANGLE_STRIP);
				glVertex3f(or, 0.0, w);
				glVertex3f(ir, 0.0, w);
				for (i = 1; i < iCircleSubdivision; i++) {
					glVertex3f(
						fcos(2.0 * M_PI * i / (float)iCircleSubdivision) * or,
						fsin(2.0 * M_PI * i / (float)iCircleSubdivision) * or,
						w
					);
					glVertex3f(
						fcos(2.0 * M_PI * i / (float)iCircleSubdivision) * ir,
						fsin(2.0 * M_PI * i / (float)iCircleSubdivision) * ir,
						w
					);
				}
				glVertex3f(or, 0.0, w);
				glVertex3f(ir, 0.0, w);
			glEnd();
		}
	}
}

void gearInside(float w1, float w2, float fRad)
{
	int i, j;
	float c, s;
	if (poo) {
		#ifdef MGL_HAS_NO_SPE_NEWLIB
			printf("Inside: fWid=%d..%d fRad=%d\n", (int)w1, (int)w2, (int)fRad);
		#else
			printf("Inside: fWid=%f..%f fRad=%f\n", w1, w2, fRad);
		#endif
	}
	if (w1 == w2) {
		return;
	}
	w1 = w1 / 2;
	w2 = w2 / 2;
	for (j = 0; j < 2; j++) {
		if (j == 1) {
			w1 = -w1;
			w2 = -w2;
		}
		glBegin(GL_TRIANGLE_STRIP);
			glNormal3f(-1.0, 0.0, 0.0);
			glVertex3f(fRad, 0.0, w1);
			glVertex3f(fRad, 0.0, w2);
			for (i = 1; i < iCircleSubdivision; i++) {
				c = fcos(2.0 * M_PI * i / iCircleSubdivision);
				s = fsin(2.0 * M_PI * i / iCircleSubdivision);
				glNormal3f(-c, -s, 0.0);
				glVertex3f(c * fRad, s * fRad, w1);
				glVertex3f(c * fRad, s * fRad, w2);
			}
			glNormal3f(-1.0, 0.0, 0.0);
			glVertex3f(fRad, 0.0, w1);
			glVertex3f(fRad, 0.0, w2);
		glEnd();
	}
}

void gearOutside(float w1, float w2, float fRad)
{
	int i, j;
	float c, s;
	if (poo) {
		#ifdef MGL_HAS_NO_SPE_NEWLIB
			printf("Outsid: fWid=%d..%d fRad=%d\n", (int)w1, (int)w2, (int)fRad);
		#else
			printf("Outsid: fWid=%f..%f fRad=%f\n", w1, w2, fRad);
		#endif
	}
	if (w1 == w2) {
		return;
	}
	w1 = w1 / 2;
	w2 = w2 / 2;
	for (j = 0; j < 2; j++) {
		if (j == 1) {
			w1 = -w1;
			w2 = -w2;
		}
		glBegin(GL_TRIANGLE_STRIP);
			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f(fRad, 0.0, w1);
			glVertex3f(fRad, 0.0, w2);
			for (i = 1; i < iCircleSubdivision; i++) {
				c = fcos(2.0 * M_PI * i / iCircleSubdivision);
				s = fsin(2.0 * M_PI * i / iCircleSubdivision);
				glNormal3f(c, s, 0.0);
				glVertex3f(c * fRad, s * fRad, w1);
				glVertex3f(c * fRad, s * fRad, w2);
			}
			glNormal3f(1.0, 0.0, 0.0);
			glVertex3f(fRad, 0.0, w1);
			glVertex3f(fRad, 0.0, w2);
		glEnd();
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(fRad, 0.0, w1);
			glVertex3f(fRad, 0.0, w2);
			glVertex3f(fRad, 0.0, w1);
			glVertex3f(fRad, 0.0, w2);
		glEnd();
	}
}

