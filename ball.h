#ifndef BALL_H
#define BALL_H

#include "point.h"
#include "paddle.h"


class Ball
{

private:

	
	Point* position;
    Point* velocity;    
    
    
public:

	Ball(float xv, float yv);

	Point* getPos();

	void updatePos();
	
	void accelerate(double accelRate);
	
	void checkWalls(float halfHeight);

	bool checkPaddle(Paddle* pad);
		
	bool hitCheck(Point* top, Point* bot);

	bool checkEnd(float halfWidth);

};

#endif
