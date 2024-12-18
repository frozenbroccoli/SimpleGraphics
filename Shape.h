#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include "Color.h"

class Shape {
	Point center;
	Color col;
	unsigned char* screen;
public:
	Shape(Point center_point, Color color, unsigned char* screen_array);
	Point where();	
	void move(Point to);
	virtual void draw();
	virtual void rotate(int angle);	
};

#endif
