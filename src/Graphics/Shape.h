#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include "Color.h"
#include "Screen.h"

class Shape {
public:	
	Point center;
	Shape();
	Shape(Point center_point);
	Point where();	
	virtual void move(Point to);
	virtual void draw(Screen* screen);
	virtual void rotate(double delta_angle);	
};

#endif
