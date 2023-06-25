#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glext.h>

#include <proto/timer.h>
#include <proto/graphics.h>
#include <proto/exec.h>


#include <math.h>
#include <string.h>

GLubyte *pixels;
GLint pixels_width, pixels_height;

#ifdef MGL_HAS_NO_SPE_NEWLIB
	#define double float
#endif

double fFrameTimes = 0;
double fFrameTimesSwap = 0;
int iFramesDrawn = 0;

GLfloat zoomx = 1.0;
GLfloat zoomy = 1.0;

/* Minimum stack space */
static USED const char *stack = "$STACK:65535"; 

GLubyte *LoadPPM(char *name, GLint *w, GLint *h)
{

	int i;
	unsigned long x,y;
	FILE *f;
	GLubyte *where;

	f = fopen(name, "rb");

	if (!f)
	{
		printf("PPM open failed\n");
		*w = 0; *h=0;
		return NULL;
	}
	i = fscanf(f, "P6\n");
	if(fgetc(f) == '#'){
		while(fgetc(f) != '\n' && !ferror(f)){
			;
		}
		if(ferror(f)){
			printf("PPM open failed\n");
			*w = 0; *h=0;
			return NULL;
		}
	}
	else{
		fseek(f, -1, SEEK_CUR);
	}
	i += fscanf(f,"%ld %ld\n255\n", &x, &y);

	if (i!= 2)
	{
		printf("Error scanning PPM header\n");
		fclose(f);
		*w = 0; *h = 0;
		return NULL;
	}

	*w = x;
	*h = y;

	where = malloc(x*y*3);
	if (!where)
	{
		printf("Error out of Memory\n");
		fclose(f);
		*w = 0; *h = 0;
		return NULL;
	}

	i = fread(where, 1, x*y*3, f);
	fclose(f);

	if (i != x*y*3)
	{
		printf("Error while reading file\n");
		free(where);
		*w = 0; *h = 0;
		return NULL;
	}

	return where;
}



void
oneFrame(void)
{
	int start, end;
	start = glutGet(GLUT_ELAPSED_TIME);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(20, 10);
	glDrawPixels(pixels_width, pixels_height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

	GLenum err = glGetError();
	if (err != GL_NO_ERROR)
	{
		mglUnlockDisplay();
		printf("Error: %s\n", gluErrorString(err));
	}

	end = glutGet(GLUT_ELAPSED_TIME);

	iFramesDrawn++;

	fFrameTimes += (double)(end - start);
	glutSwapBuffers();

	end = glutGet(GLUT_ELAPSED_TIME);
	fFrameTimesSwap += (double)(end - start);


}

void
display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void
myReshape(int width, int height)
{
   glViewport( 0, 0, width, height );
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   glOrtho( 0.0, width, 0.0, height, 0.0, 2.0 );
   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();
}


void
myinit(int w, int h)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	myReshape(w, h);
	/* glShadeModel(GL_FLAT); */
	glDisable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

/* ARGSUSED1 */
void
keys(unsigned char c, int x, int y)
{
	if (c == 27)
	{
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
	}
	else if (c == '+')
	{
		zoomx += 0.1;
		zoomy += 0.1;
		glPixelZoom(zoomx, zoomy);
	}
	else if (c == '-')
	{
		zoomx -= 0.1;
		zoomy -= 0.1;
		glPixelZoom(zoomx, zoomy);
	}

}

int main(int argc, char *argv[])
{
	GLint width=640; GLint height=480;
	int i;
	char *name = 0;
	GLenum sync = GL_FALSE;

	glutInit(&argc, argv);

	for (i=1; i<argc; i++)
	{
		if (0 == strcasecmp(argv[i], "-width"))
		{
			i++;
			width = atoi(argv[i]);
		}
		if (0 == strcasecmp(argv[i], "-height"))
		{
			i++;
			height = atoi(argv[i]);
		}
		if (0 == strcasecmp(argv[i], "-map"))
		{
			i++;
			name = argv[i];
		}
		if (0 == strcasecmp(argv[i], "-sync"))
		{
			i++;
			sync = GL_TRUE;
		}
	}

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow(argv[0]);


	mglEnableSync(sync);

	pixels = LoadPPM("data/wall.ppm", &pixels_width, &pixels_height);

	if ( pixels )
	{
		glClearColor(0.1, 0.0, 0.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDisable(GL_CULL_FACE);
		glDisable(GL_BLEND);

		myinit(width, height);

		glutIdleFunc(oneFrame);
		glutKeyboardFunc(keys);
		glutMainLoop();
	}
	else
	{
		printf("Can't find texture %s\n", name);
	}


	return 0;             /* ANSI C requires main to return int. */
}

