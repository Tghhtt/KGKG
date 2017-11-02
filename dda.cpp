
#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

using namespace std;

void init();
void tampilan();
void dda();

int layar_x, layar_y;
int window_x = 400, window_y = 400;
char *judul = "Algoritma DDA";

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	int layar_x = (glutGet(GLUT_SCREEN_WIDTH) - window_x) / 2;
	int layar_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_y) / 2;
	glutInitWindowSize(window_x, window_y);
	glutInitWindowPosition(layar_x, layar_y);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE );
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
	dda();
	glutSwapBuffers();
}
void dda()
{
	int x1, y1, x2, y2, x, y, dx, dy, steps, x_inc, y_inc;
	x1 = 1;
	y1 = 1;
	x2 = 200;
	y2 = 200;
	x = x1;
	y = y1; 
	dx = x2 - x1;
	dy = y2 - y1;

	if(abs(dx) > abs(dy))
	{
		steps = abs(dx);
	}
	else steps = abs(dy);

	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	glBegin(GL_POINTS);
	glVertex2f(round(x), round(y));
	for(int k = 0; k < steps; k++) {
		x += x_inc;
		y += y_inc;
		glVertex2f(round(x), round(y));
	}

		glEnd();
		glFlush();
	}
