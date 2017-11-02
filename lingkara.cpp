
#include<GL\freeglut.h>
#include<GL\glut.h>
#include<iostream>


using namespace std;

void init();
void tampilan();
void lingkaran();

int layar_x, layar_y;
int window_x = 400, window_y = 400;
char *judul = "Lingkaran";

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
	lingkaran();
	glutSwapBuffers();
}
void lingkaran()
{
	int xc, yc, r;
	r = 50;
	xc = 100;
	yc = 200;
	int p = 1 - r;
	int x = 0;
	int y = r;

	glBegin(GL_POINTS);

	while (x <= y) {
		x++;
		if (p < 0) {
			p += 2 * x + 1; 
		}
		else {
			y--;
			p += 2 * (x - y) + 1;
		}
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc - y);
		glVertex2i(xc + y, yc + x);
		glVertex2i(xc - y, yc + x);
		glVertex2i(xc + y, yc - x);
		glVertex2i(xc - y, yc - x);
	}

	glEnd();
	glFlush();
}