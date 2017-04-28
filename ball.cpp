#include "ball.h"

using namespace std;

Ball::Ball()
{
	this->position = new Point();
	this->velocity = new Point();
}

Point* Ball::getPos()
{
	return this->position;
}
	
void Ball::hitCheck(Point d, Point dv)
{
	
}

void Ball::updatePos()
{
	this->position->add(this->velocity);
}

void Ball::accelerate()
{
	this->velocity->add(this->velocity, accelRate);
}
