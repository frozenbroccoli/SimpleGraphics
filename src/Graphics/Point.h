#ifndef POINT_H
#define POINT_H

#include "Screen.h"
#include "Color.h"

class Point {
public:
	int x;
	int y;
	Color color;
	Point();
	Point(int x_coord, int y_coord, Color col);
	void draw(Screen* screen);
};

#endif
