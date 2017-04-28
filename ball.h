#ifndef BALL_H
#define BALL_H

#include "point.h"



class Ball
{

private:

	
	Point* position;
    Point* velocity;

	static const float accelRate = 0.01;    
    
    
public:

	Ball();

	Point* getPos();
		
	void hitCheck(Point d, Point dv);

	void updatePos();
	
	void accelerate();

};

#endif
