#include <time.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ball.h"

using namespace std;

float windowSize = 500;

Ball* ball = new Ball();

void renderScene()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glColor3f(1.0, 1.0, 1.0);
	
	Point* p = ball->getPos();
	int x = (int) p->getX();
	int y = (int) p->getY();

	glBegin(GL_POINTS);
		glVertex2i(x, y);
		
		glVertex2i(x-1, y);
		glVertex2i(x+1, y);
		glVertex2i(x, y-1);
		glVertex2i(x, y+1);
		
		glVertex2i(x-2, y);
		glVertex2i(x+2, y);
		glVertex2i(x, y-2);
		glVertex2i(x, y+2);
		
		glVertex2i(x-1, y-1);
		glVertex2i(x+1, y+1);
		glVertex2i(x+1, y-1);
		glVertex2i(x-1, y+1);
		
	glEnd();
	
	
	
	glBegin(GL_LINES);
		glVertex2i(-windowSize/2 + 10, -windowSize/2 + 10);
		glVertex2i(-windowSize/2 + 10, -windowSize/2 + 100);
		glVertex2i(windowSize/2 - 10, windowSize/2 - 10);
		glVertex2i(windowSize/2 - 10, windowSize/2 - 100);
	glEnd();

    glutSwapBuffers();
    
}

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	float halfScr = windowSize / 2.0;
	gluOrtho2D (-halfScr, halfScr, -halfScr, halfScr);
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'w':
			
		break;
		case 'a':

		break;
		case 's':

		break;
		case 'd':

		break;
		default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	srand (static_cast <unsigned> (time(0)));
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(windowSize, windowSize);
	glutCreateWindow("Test");

	init2D(0.0, 0.0, 0.0);

	glutDisplayFunc(renderScene);

	glutIdleFunc(renderScene);

	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 1;
}

