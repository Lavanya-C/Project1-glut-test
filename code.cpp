#include<GL/glut.h>
#include<stdlib.h>

void display()
{
	GLfloat vertices[3][2] = { 0.0,0.0,25.0,50.0,50.0,0.0 };
	int j, k;
	int rand();
	GLfloat p[2] = { 7.5,5.0 };
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.0, 1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
		for (k = 0; k < 2000; k++)
		{
			j = rand() % 3;
			p[0] = (p[0] + vertices[j][0]) / 2.0;
			p[1] = (p[1] + vertices[j][1]) / 2.0;
			glVertex2fv(p);
		}
	glEnd();
	glFinish();
}

void init()
{
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(0.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 55.0, 0.0, 55.0);
	glMatrixMode(GL_MODELVIEW);
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(700, 700);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Random");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}