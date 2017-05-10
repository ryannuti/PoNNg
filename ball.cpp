#include <iostream>
#include "ball.h"

using namespace std;

Ball::Ball(float xv, float yv)
{
	this->position = new Point();
	this->velocity = new Point(xv, yv);
}

Point* Ball::getPos()
{
	return this->position;
}

void Ball::updatePos()
{
	this->position->add(this->velocity);
}

void Ball::accelerate(double accelRate)
{
	this->velocity->add(this->velocity, accelRate);
}

void Ball::checkWalls(float halfHeight)
{
	float y = this->position->getY();
	if(y > (halfHeight - 2) || y < (2 - halfHeight))
	{
		float dy;
		if(y > (halfHeight - 2))
		{
			dy = (halfHeight - 2) - y;
		}
		else
		{
			dy = (2 - halfHeight) - y;
		}
		this->position->set(this->position->getX(), y + dy);
		this->velocity->set(this->velocity->getX(), - this->velocity->getY());
	}
}

bool Ball::checkPaddle(Paddle* pad)
{
	Point* bot = pad->getPos();
	if(this->position->dist(bot) < 80.0)
	{
		float x = bot->getX();
		float y = bot->getY();
		Point* top = new Point(x, y + 40);
		bot = new Point(x, y - 40);
		
		return this->hitCheck(top, bot);
	}
	return false;
}
	
bool Ball::hitCheck(Point* top, Point* bot)
{
	float thisX = this->position->getX();
	float thisY = this->position->getY();
	float lastX = thisX - this->velocity->getX();
	float lastY = thisY - this->velocity->getY();
	float targetX = top->getX();
	float topY = top->getY();
	float botY = bot->getY();
	
// delete top & bot??
	if((thisX < targetX && lastX > targetX) || (thisX > targetX && lastX < targetX))
	{
		double slope = (thisY - lastY) / (thisX - lastX);
		float dx = targetX - lastX;
		
		float hitY = lastY + (slope * dx);
		
		if(hitY < topY && hitY > botY)
		{
			float dist = this->position->dist(new Point(targetX, hitY));
			float dy = thisY - lastY;
			
			double angle = M_PI_2 - fabs(atan(slope));
			
			if(dy > 0) angle *= ((topY - hitY) / 80) + 0.5;
			else angle *= ((hitY - botY) / 80) + 0.5;
			
			angle = M_PI_2 - angle;
			
			if(slope > 0) angle = - angle;
			if(dx > 0) angle += M_PI;
			
			this->position->set(targetX + dist * cos(angle), hitY + dist * sin(angle));
			
			float speed = this->velocity->magnitude();
			this->velocity->set(speed * cos(angle), speed * sin(angle));
			
			return true;
		}
	}	
	return false;
}

bool Ball::checkEnd(float halfWidth)
{
	float x = this->position->getX();
	if(x > (halfWidth - 2) || x < (2 - halfWidth))
	{
		float dx;
		if(x > (halfWidth - 2))
		{
			dx = (halfWidth - 2) - x;
		}
		else
		{
			dx = (2 - halfWidth) - x;
		}
		
		this->position->set(x + dx, this->position->getY());
		this->velocity->set(- this->velocity->getX(), this->velocity->getY());
		return true;
	}
	return false;
}
