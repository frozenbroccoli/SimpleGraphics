#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"
#include "Color.h"
#include "Screen.h"

class Shape {
public:	
	virtual Point where() = 0;
	virtual void move(int horizontal, int vertical) = 0;
	virtual void move(Point to) = 0;
	virtual void rotate(double delta_angle) = 0;
	virtual void draw(Screen* screen, Color color) = 0;
};

#endif

