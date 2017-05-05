#ifndef PADDLE_H
#define PADDLE_H

#include "point.h"



class Paddle
{

private:

	Point* position;
	float offset;
    
public:

	Paddle(float x);

	Point* getPos();
		
	void setY(float y);
	
	void randOffset();

};

#endif
