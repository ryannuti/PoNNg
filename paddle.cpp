#include "paddle.h"

using namespace std;

Paddle::Paddle(float x)
{
	this->position = new Point(x, 0.0);
}

Point* Paddle::getPos()
{
	return this->position;
}
		
void Paddle::setY(float y)
{
	this->position->set(this->position->getX(), y + this->offset);
}

void Paddle::randOffset()
{
	this->offset = rand() % 100 / 100.0 * 70 - 35;
}
