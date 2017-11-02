
#include<GL\freeglut.h>
#include<GL\glut.h>
#include<iostream>


using namespace std;

void init();
void tampilan();
void bersenham();

int layar_x, layar_y;
int window_x = 400, window_y = 400;
char *judul = "Algoritma Bersenham";

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	int layar_x = (glutGet(GLUT_SCREEN_WIDTH) - window_x) / 2;
	int layar_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_y) / 2;
	glutInitWindowSize(window_x, window_y);
	glutInitWindowPosition(layar_x, layar_y);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(judul);

	init();
	glutDisplayFunc(tampilan);
	glutMainLoop();
}

void init()
{
	glClearColor(0, 0, 0, 0);
	glColor3f(3.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}
void tampilan()
{
	glClear(GL_COLOR_BUFFER_BIT);
	bersenham();
	glutSwapBuffers();
}
void bersenham()
{
	int x, y, xa,xb,ya,yb;
	xa = 10;
	xb = 20;
	ya = 10;
	yb = 30;
	int dx = abs(xb - xa), dy = abs(yb - ya);
	int p = 2 * dy - dx, xend;
	int duady = 2 * dy, duadydx = 2 * (dy - dx);
	
	if (xa>xb)
	{
		x = xb; y = yb; xend = xa;
	}
	else
	{
		x = xa; y = ya; xend = xb;
	}
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	while (x<xend)
	{
		x++;
		if (p<0)
			p += duady;
		else
		{
			y++;
			p += duadydx;
		}
		glBegin(GL_POINTS);
		glVertex2i(x, y);
	}
	glEnd();
	glFlush();
}