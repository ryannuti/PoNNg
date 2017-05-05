#include <time.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ball.h"
#include "paddle.h"

using namespace std;

int windowHeight = 500;
int windowWidth = 800;

Ball* ball;
Paddle** paddles = new Paddle*[2];

void initGame()
{
	double angle = (rand() % 90 + 135.0) * M_PI / 180;
	ball = new Ball(5 * cos(angle), 5 * sin(angle));
	paddles[0] = new Paddle(- windowWidth / 2.0 + 10);
	paddles[1] = new Paddle(windowWidth / 2.0 - 10);
}

void update()
{
	ball->updatePos();

	paddles[0]->setY(ball->getPos()->getY());
	// if(training)
		paddles[1]->setY(ball->getPos()->getY());
	// else
		// AI
	
	
	if(ball->checkPaddle(paddles[0]))
	{
		paddles[0]->randOffset();
	// generate new AI problem
	}
	
	// if
	ball->checkPaddle(paddles[1]);
	// training
	
	ball->checkWalls(windowHeight / 2.0);
	
	// if
	ball->checkEnd(windowWidth / 2.0);
	// reset ball
	// training
	
	glutPostRedisplay();
}

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
		for(int i = 0; i < 2; i++)
		{
			int x = (int) paddles[i]->getPos()->getX();
			int y = (int) paddles[i]->getPos()->getY();
			glVertex2i(x, y - 40);
			glVertex2i(x, y + 40);
		}
	glEnd();

    glutSwapBuffers();
    
}

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	float halfWidth = windowWidth / 2.0;
	float halfHeight = windowHeight / 2.0;
	gluOrtho2D (-halfWidth, halfWidth, -halfHeight, halfHeight);
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
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Test");

	init2D(0.0, 0.0, 0.0);
	
	initGame();

	glutDisplayFunc(renderScene);

	glutIdleFunc(update);

	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 1;
}

