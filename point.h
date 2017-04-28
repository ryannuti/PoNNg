#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <stdlib.h>

class Point
{
	 private:

	 	float x;
	 	float y;
	 
	 public:
		Point();
	 	Point(float x, float y);
	    
        float getX();
        float getY();
        float dist(Point* other);
        void add(Point* b);
        void add(Point* b, float rate);
        void add(float x, float y);
        void set(float x, float y);
};

#endif

