#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include "Color.h"
#include "Screen.h"

class Shape {
public:	
	Point center;
	Color col;
	Shape();
	Shape(Point center_point, Color color);
	Point where();	
	void move(Point to, Screen* screen);
	virtual void draw(Screen* screen);
	virtual void rotate(int angle, Screen* screen);	
};

#endif
