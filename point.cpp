#include "point.h"

using namespace std;


Point::Point()
{
	this->x = 0.0;
	this->y = 0.0;
}

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}


float Point::getX() 
{ 
	return this->x;
}

float Point::getY() 
{ 
	return this->y;
}

float Point::dist(Point* other)
{
	float xd = this->x - other->x;
	float yd = this->y - other->y;
	return sqrt(xd*xd + yd*yd);
}

void Point::add(Point* b)
{
	this->x += b->x;
	this->y += b->y;
}

void Point::add(Point* b, float change)
{
	float mag = magnitude();
	this->x *= (mag + change) / mag;
	this->y *= (mag + change) / mag;
}

void Point::add(float x, float y)
{
	this->x += x;
	this->y += y;
}

void Point::set(float x, float y)
{
	this->x = x;
	this->y = y;
}

float Point::magnitude()
{
	return sqrt(this->x * this->x + this->y * this->y);
}

