#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include "Color.h"
#include "Screen.h"

class Shape {
	Point center;
	Color col;
	Screen screen;
public:
	Shape(Point center_point, Color color, Screen screen);
	Point where();	
	void move(Point to);
	virtual void draw();
	virtual void rotate(int angle);	
};

#endif
